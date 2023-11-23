// File Line: 19
// RVA: 0x14BD0E0
__int64 dynamic_initializer_for__gTaskFunctionDecl_PoseTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(&gTaskFunctionDecl_PoseTask, &gTaskFunctionDeclData_PoseTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_PoseTask__);
}

// File Line: 33
// RVA: 0x39C580
void __fastcall PoseTask(
        int worker_id,
        UFG::qMemoryStreamer *memoryStreamer,
        unsigned int *taskParamsRemote,
        void *param1)
{
  __int64 v4; // rax
  __int64 v6; // r8
  __int64 v7; // r9
  __int64 v8; // rcx
  __int64 v10; // rax
  hkQsTransformf **v11; // r10
  void *v12; // r14
  char *v13; // r9
  unsigned int v14; // edx
  unsigned int v15; // ecx
  __int64 v16; // rax
  unsigned int v17; // eax
  __int64 v18; // rax
  _QWORD *v19; // rcx
  unsigned int v20; // xmm0_4
  unsigned int v21; // xmm1_4
  unsigned int v22; // xmm0_4
  unsigned int v23; // xmm1_4
  PoseEvaluator v24; // [rsp+30h] [rbp-2258h] BYREF
  char *stream_name; // [rsp+50h] [rbp-2238h]
  __int64 v26; // [rsp+58h] [rbp-2230h]
  int v27; // [rsp+60h] [rbp-2228h]
  void *local_mem; // [rsp+68h] [rbp-2220h]
  char v29; // [rsp+153h] [rbp-2135h] BYREF
  char *v30; // [rsp+1E0h] [rbp-20A8h]
  __int64 v31; // [rsp+1E8h] [rbp-20A0h]
  int v32; // [rsp+1F0h] [rbp-2098h]
  void *v33; // [rsp+1F8h] [rbp-2090h]
  char v34[8077]; // [rsp+2E3h] [rbp-1FA5h] BYREF

  v4 = *((_QWORD *)taskParamsRemote + 7);
  v6 = *((_QWORD *)taskParamsRemote + 8);
  v7 = 0i64;
  if ( v4 )
    v7 = v4;
  v8 = 0i64;
  if ( v6 )
    v8 = v6;
  if ( v4 )
    *((_QWORD *)taskParamsRemote + 7) = v7;
  if ( v6 )
    *((_QWORD *)taskParamsRemote + 8) = v8;
  v10 = taskParamsRemote[20];
  v11 = (hkQsTransformf **)*((_QWORD *)taskParamsRemote + 9);
  v12 = (void *)*((_QWORD *)taskParamsRemote + 15);
  v31 = 0i64;
  v13 = (char *)v11 + ((8 * v10 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v30 = "<unassigned>";
  v32 = 0;
  v33 = (void *)((unsigned __int64)v34 & 0xFFFFFFFFFFFFFF80ui64);
  v14 = 0;
  if ( (_DWORD)v10 )
  {
    do
    {
      v15 = v14;
      v16 = v14++;
      v11[v16] = (hkQsTransformf *)&v13[taskParamsRemote[21] * v15];
    }
    while ( v14 < taskParamsRemote[20] );
  }
  v17 = taskParamsRemote[20];
  v24.mMemoryStreamer = memoryStreamer;
  v24.mScratchBuffers.mStackDepth = v17;
  v24.mScratchBuffers.mStackSize = v17;
  v24.mScratchBuffers.mStack = v11;
  PoseEvaluator::EvaluatePoseModelSpace(
    &v24,
    (PoseRecipe *)taskParamsRemote,
    (hkQsTransformf *)((unsigned __int64)v34 & 0xFFFFFFFFFFFFFF80ui64),
    (UFG::qVector3 *)(taskParamsRemote + 23),
    (UFG::qVector3 *)(taskParamsRemote + 26));
  v18 = *(_QWORD *)taskParamsRemote;
  stream_name = "<unassigned>";
  v26 = 0i64;
  v27 = 0;
  v19 = (_QWORD *)((unsigned __int64)&v29 & 0xFFFFFFFFFFFFFF80ui64);
  local_mem = v19;
  *v19 = v18;
  v19[1] = *((_QWORD *)taskParamsRemote + 1);
  v19[2] = *((_QWORD *)taskParamsRemote + 2);
  v19[3] = *((_QWORD *)taskParamsRemote + 3);
  v19[4] = *((_QWORD *)taskParamsRemote + 4);
  v19[5] = *((_QWORD *)taskParamsRemote + 5);
  v19[6] = *((_QWORD *)taskParamsRemote + 6);
  v19[7] = *((_QWORD *)taskParamsRemote + 7);
  v19[8] = *((_QWORD *)taskParamsRemote + 8);
  v19[9] = *((_QWORD *)taskParamsRemote + 9);
  *((_DWORD *)v19 + 20) = taskParamsRemote[20];
  *((_DWORD *)v19 + 21) = taskParamsRemote[21];
  *((_DWORD *)v19 + 22) = taskParamsRemote[22];
  v20 = taskParamsRemote[24];
  v21 = taskParamsRemote[25];
  *((_DWORD *)v19 + 23) = taskParamsRemote[23];
  *((_DWORD *)v19 + 24) = v20;
  *((_DWORD *)v19 + 25) = v21;
  v22 = taskParamsRemote[27];
  v23 = taskParamsRemote[28];
  *((_DWORD *)v19 + 26) = taskParamsRemote[26];
  *((_DWORD *)v19 + 27) = v22;
  *((_DWORD *)v19 + 28) = v23;
  v19[15] = *((_QWORD *)taskParamsRemote + 15);
  UFG::qMemoryStreamer::BeginRawWritePlat(memoryStreamer, stream_name, local_mem, 0x80ui64, taskParamsRemote, 0x80ui64);
  UFG::qMemoryStreamer::BeginRawWritePlat(memoryStreamer, v30, v33, 0x1F80ui64, v12, 48i64 * *taskParamsRemote);
}

// File Line: 225
// RVA: 0x3A1C20
char *__fastcall PoseTaskRingBuffer::AllocAndAssignDependents(
        PoseTaskRingBuffer *this,
        unsigned int bufferSize,
        UFG::qTask *task)
{
  PoseTaskRingBuffer::RingElement *mFirst; // rdi
  UFG::qTask *mTask; // rdx
  unsigned int v8; // ecx

  if ( (this->mLastElement + 1) % 0x30 == this->mFirstElement )
  {
    mFirst = this->mFirst;
    mTask = this->mFirst->mTask;
    if ( mTask )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, mTask);
      mFirst->mTask = 0i64;
    }
    v8 = this->mFirstElement + 1;
    this->mFirst = this->mFirst->mNext;
    this->mFirstElement = v8 % 0x30;
  }
  PoseTaskRingBuffer::AllocFromRingBuffer(this, bufferSize, task);
  PoseTaskRingBuffer::AssignDependencies(this);
  return this->mLast->mBuffer;
}

// File Line: 239
// RVA: 0x3A1CE0
char *__fastcall PoseTaskRingBuffer::AllocAndSyncDependents(PoseTaskRingBuffer *this, unsigned int bufferSize)
{
  PoseTaskRingBuffer::RingElement *mFirst; // rdi
  UFG::qTask *mTask; // rdx
  unsigned int v6; // ecx

  if ( (this->mLastElement + 1) % 0x30 == this->mFirstElement )
  {
    mFirst = this->mFirst;
    mTask = this->mFirst->mTask;
    if ( mTask )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, mTask);
      mFirst->mTask = 0i64;
    }
    v6 = this->mFirstElement + 1;
    this->mFirst = this->mFirst->mNext;
    this->mFirstElement = v6 % 0x30;
  }
  PoseTaskRingBuffer::AllocFromRingBuffer(this, bufferSize, 0i64);
  PoseTaskRingBuffer::SyncDependencies(this);
  return this->mLast->mBuffer;
}

// File Line: 261
// RVA: 0x3A1D90
void __fastcall PoseTaskRingBuffer::AllocFromRingBuffer(
        PoseTaskRingBuffer *this,
        unsigned int bufferSize,
        UFG::qTask *task)
{
  PoseTaskRingBuffer::RingElement *mLast; // r10
  char *mBuffer; // r11
  __int64 mLastElement; // rax
  PoseTaskRingBuffer::RingElement *v7; // r8
  PoseTaskRingBuffer::RingElement *v8; // rax

  mLast = this->mLast;
  if ( mLast )
    mBuffer = mLast->mBuffer;
  else
    mBuffer = this->mBuffer;
  mLastElement = this->mLastElement;
  if ( &mBuffer[bufferSize] > &this->mBuffer[(unsigned __int64)this->mBufferSize] )
    mBuffer = this->mBuffer;
  v7 = &this->mElements[mLastElement];
  this->mLast = v7;
  this->mLastElement = ((int)mLastElement + 1) % 0x30u;
  v7->mNext = 0i64;
  this->mLast->mBuffer = mBuffer;
  this->mLast->mSize = bufferSize;
  this->mLast->mTask = task;
  v8 = this->mLast;
  if ( mLast )
    mLast->mNext = v8;
  else
    this->mFirst = v8;
}

// File Line: 294
// RVA: 0x3A24A0
void __fastcall PoseTaskRingBuffer::AssignDependencies(PoseTaskRingBuffer *this)
{
  PoseTaskRingBuffer::RingElement *mLast; // rdx
  PoseTaskRingBuffer::RingElement *mFirst; // rbx
  char *i; // rdi
  char *mBuffer; // rcx

  mLast = this->mLast;
  mFirst = this->mFirst;
  for ( i = mLast->mBuffer; mFirst != mLast; mLast = this->mLast )
  {
    if ( mFirst->mTask )
    {
      mBuffer = mFirst->mBuffer;
      if ( i >= mBuffer && i < &mBuffer[mFirst->mSize] )
        UFG::qTaskManager::AddDependent(&UFG::gTaskManager, mLast->mTask, mFirst->mTask);
    }
    mFirst = mFirst->mNext;
  }
}

// File Line: 315
// RVA: 0x3B0150
void __fastcall PoseTaskRingBuffer::SyncDependencies(PoseTaskRingBuffer *this)
{
  PoseTaskRingBuffer::RingElement *mLast; // rax
  PoseTaskRingBuffer::RingElement *mFirst; // rbx
  char *mBuffer; // rsi
  char *v5; // rcx
  unsigned int mFirstElement; // ecx

  mLast = this->mLast;
  mFirst = this->mFirst;
  mBuffer = mLast->mBuffer;
  if ( this->mFirst != mLast )
  {
    do
    {
      v5 = mFirst->mBuffer;
      if ( mBuffer >= v5 && mBuffer < &v5[mFirst->mSize] )
      {
        if ( mFirst->mTask )
        {
          UFG::qTaskManager::Sync(&UFG::gTaskManager, mFirst->mTask);
          mFirst->mTask = 0i64;
        }
        if ( mFirst == this->mFirst )
        {
          mFirstElement = this->mFirstElement;
          this->mFirst = this->mFirst->mNext;
          this->mFirstElement = (mFirstElement + 1) % 0x30;
        }
      }
      mFirst = mFirst->mNext;
    }
    while ( mFirst != this->mLast );
  }
}

// File Line: 385
// RVA: 0x3AAA80
void PoseTaskSubmission::Init(void)
{
  UFG::allocator::free_link *v0; // rbx

  v0 = UFG::qMalloc(0x628ui64, UFG::gGlobalNewName, 0i64);
  if ( v0 )
  {
    v0->mNext = 0i64;
    v0[1].mNext = 0i64;
    v0[2].mNext = 0i64;
    LODWORD(v0[3].mNext) = 0x20000;
    v0[196].mNext = 0i64;
    v0[2].mNext = UFG::qMalloc(0x20000ui64, "PoseTaskRingBuffer", 0i64);
    PoseTaskSubmission::sRingBuffer = (PoseTaskRingBuffer *)v0;
  }
  else
  {
    PoseTaskSubmission::sRingBuffer = 0i64;
  }
}

// File Line: 391
// RVA: 0x3A6A90
void PoseTaskSubmission::Destroy(void)
{
  PoseTaskRingBuffer *v0; // rdi

  v0 = PoseTaskSubmission::sRingBuffer;
  if ( PoseTaskSubmission::sRingBuffer )
  {
    operator delete[](PoseTaskSubmission::sRingBuffer->mBuffer);
    v0->mBuffer = 0i64;
    operator delete[](v0);
  }
  PoseTaskSubmission::sRingBuffer = 0i64;
}

// File Line: 398
// RVA: 0x3A2B40
void PoseTaskSubmission::BeginFrame(void)
{
  PoseTaskRingBuffer *v0; // rax

  v0 = PoseTaskSubmission::sRingBuffer;
  PoseTaskSubmission::sRingBuffer->mFirst = 0i64;
  v0->mLast = 0i64;
  *(_QWORD *)&v0->mFirstElement = 0i64;
  ++PoseTaskSubmission::sFrameIndex;
}

// File Line: 430
// RVA: 0x3B0010
UFG::qTask *__fastcall PoseTaskSubmission::SubmitTask(PoseTaskInputParams *input)
{
  char *v2; // rax
  UFG::qTask *v3; // rbx
  _QWORD *v4; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // rdx
  char *mAddress; // r8
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax

  ++PoseTaskSubmission::sTotalTasksSubmitted;
  v2 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
  v3 = (UFG::qTask *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = v2;
    *((_QWORD *)v2 + 1) = v2;
    v4 = v2 + 16;
    *v4 = v4;
    v4[1] = v4;
    mSpuElf = gTaskFunctionDeclData_PoseTask.mSpuElf;
    mTaskFunctionSPU = gTaskFunctionDeclData_PoseTask.mTaskFunctionSPU;
    mTaskFunctionPPU = gTaskFunctionDeclData_PoseTask.mTaskFunctionPPU;
    mTaskFunctionOffload = gTaskFunctionDeclData_PoseTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_PoseTask.mCurrentSPUEnabled )
    {
      mSpuElf = 0i64;
      mTaskFunctionSPU = 0i64;
      mTaskFunctionOffload = 0i64;
    }
    v3->mTaskGroup = 0i64;
    v3->mFlags = 2;
    v3->mSyncVars.i64 = 0i64;
    v3->mSyncVars.v.mDependents = 0i64;
    v3->mFunctionDeclData = &gTaskFunctionDeclData_PoseTask;
    if ( mSpuElf )
      mAddress = mSpuElf->mAddress;
    else
      mAddress = 0i64;
    v3->mSPUElfAddress = mAddress;
    v3->mSPUFunction = mTaskFunctionSPU;
    v3->mPPUFunction = mTaskFunctionPPU;
    v3->mParam0 = input;
    v3->mParam1 = 0i64;
    v3->mParam2 = 0i64;
    v3->mParam3 = 0i64;
    if ( mTaskFunctionOffload )
    {
      v3->mFlags = 130;
      v3->mOffloadThread = 0;
    }
  }
  mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
  mPrev = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  mPrev->mNext = v3;
  v3->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
  v3->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
  mSingleFrameTasks->mNode.mPrev = v3;
  v3->mFlags &= 0xFFFFFFF1;
  v3->mFlags |= 1u;
  input->mScratchBuffer = PoseTaskRingBuffer::AllocAndAssignDependents(
                            PoseTaskSubmission::sRingBuffer,
                            input->mBufferSize,
                            v3);
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v3);
  return v3;
}

// File Line: 447
// RVA: 0x3A77A0
void __fastcall PoseTaskSubmission::ExecuteLocalTask(PoseTaskInputParams *input)
{
  char *v2; // rax
  __int64 mBufferCount; // rdx
  __int64 v4; // rcx
  hkQsTransformf **v5; // r9
  unsigned int v6; // eax
  hkQsTransformf *mOutputTransforms; // r8
  PoseEvaluator v8; // [rsp+30h] [rbp-28h] BYREF

  ++PoseTaskSubmission::sTotalTasksSubmitted;
  v2 = PoseTaskRingBuffer::AllocAndSyncDependents(PoseTaskSubmission::sRingBuffer, input->mBufferSize);
  mBufferCount = input->mBufferCount;
  v4 = 0i64;
  v5 = (hkQsTransformf **)v2;
  if ( (_DWORD)mBufferCount )
  {
    do
    {
      *(_QWORD *)&v2[8 * v4] = &v2[((8 * mBufferCount + 15) & 0xFFFFFFFFFFFFFFF0ui64)
                                 + (unsigned int)(v4 * input->mBufferStride)];
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < input->mBufferCount );
  }
  v6 = input->mBufferCount;
  mOutputTransforms = input->mOutputTransforms;
  v8.mScratchBuffers.mStack = v5;
  v8.mScratchBuffers.mStackDepth = v6;
  v8.mScratchBuffers.mStackSize = v6;
  v8.mMemoryStreamer = 0i64;
  PoseEvaluator::EvaluatePoseModelSpace(
    &v8,
    &input->mRecipe,
    mOutputTransforms,
    &input->mOutputModelSpaceAABBMin,
    &input->mOutputModelSpaceAABBMax);
}

