// File Line: 19
// RVA: 0x14BD0E0
__int64 dynamic_initializer_for__gTaskFunctionDecl_PoseTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(&gTaskFunctionDecl_PoseTask, &gTaskFunctionDeclData_PoseTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_PoseTask__);
}

// File Line: 33
// RVA: 0x39C580
void __fastcall PoseTask(int worker_id, UFG::qMemoryStreamer *memoryStreamer, void *taskParamsRemote, void *param1)
{
  __int64 v4; // rax
  unsigned int *v5; // rsi
  __int64 v6; // r8
  __int64 v7; // r9
  __int64 v8; // rcx
  UFG::qMemoryStreamer *v9; // rbp
  __int64 v10; // rax
  hkQsTransformf **v11; // r10
  void *v12; // r14
  unsigned __int64 v13; // r9
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
  PoseEvaluator v24; // [rsp+30h] [rbp-2258h]
  char *stream_name; // [rsp+50h] [rbp-2238h]
  __int64 v26; // [rsp+58h] [rbp-2230h]
  int v27; // [rsp+60h] [rbp-2228h]
  void *local_mem; // [rsp+68h] [rbp-2220h]
  char v29; // [rsp+153h] [rbp-2135h]
  char *v30; // [rsp+1E0h] [rbp-20A8h]
  __int64 v31; // [rsp+1E8h] [rbp-20A0h]
  int v32; // [rsp+1F0h] [rbp-2098h]
  void *v33; // [rsp+1F8h] [rbp-2090h]
  char v34; // [rsp+2E3h] [rbp-1FA5h]

  v4 = *((_QWORD *)taskParamsRemote + 7);
  v5 = (unsigned int *)taskParamsRemote;
  v6 = *((_QWORD *)taskParamsRemote + 8);
  v7 = 0i64;
  if ( v4 )
    v7 = v4;
  v8 = 0i64;
  if ( v6 )
    v8 = v6;
  v9 = memoryStreamer;
  if ( v4 )
    *((_QWORD *)v5 + 7) = v7;
  if ( v6 )
    *((_QWORD *)v5 + 8) = v8;
  v10 = v5[20];
  v11 = (hkQsTransformf **)*((_QWORD *)v5 + 9);
  v12 = (void *)*((_QWORD *)v5 + 15);
  v31 = 0i64;
  v13 = (unsigned __int64)v11 + ((8 * v10 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  v30 = "<unassigned>";
  v32 = 0;
  v33 = (void *)((unsigned __int64)&v34 & 0xFFFFFFFFFFFFFF80ui64);
  v14 = 0;
  if ( (_DWORD)v10 )
  {
    do
    {
      v15 = v14;
      v16 = v14++;
      v11[v16] = (hkQsTransformf *)(v13 + v5[21] * v15);
    }
    while ( v14 < v5[20] );
  }
  v17 = v5[20];
  v24.mMemoryStreamer = v9;
  v24.mScratchBuffers.mStackDepth = v17;
  v24.mScratchBuffers.mStackSize = v17;
  v24.mScratchBuffers.mStack = v11;
  PoseEvaluator::EvaluatePoseModelSpace(
    &v24,
    (PoseRecipe *)v5,
    (hkQsTransformf *)((unsigned __int64)&v34 & 0xFFFFFFFFFFFFFF80ui64),
    (UFG::qVector3 *)(v5 + 23),
    (UFG::qVector3 *)(v5 + 26));
  v18 = *(_QWORD *)v5;
  stream_name = "<unassigned>";
  v26 = 0i64;
  v27 = 0;
  v19 = (_QWORD *)((unsigned __int64)&v29 & 0xFFFFFFFFFFFFFF80ui64);
  local_mem = v19;
  *v19 = v18;
  v19[1] = *((_QWORD *)v5 + 1);
  v19[2] = *((_QWORD *)v5 + 2);
  v19[3] = *((_QWORD *)v5 + 3);
  v19[4] = *((_QWORD *)v5 + 4);
  v19[5] = *((_QWORD *)v5 + 5);
  v19[6] = *((_QWORD *)v5 + 6);
  v19[7] = *((_QWORD *)v5 + 7);
  v19[8] = *((_QWORD *)v5 + 8);
  v19[9] = *((_QWORD *)v5 + 9);
  *((_DWORD *)v19 + 20) = v5[20];
  *((_DWORD *)v19 + 21) = v5[21];
  *((_DWORD *)v19 + 22) = v5[22];
  v20 = v5[24];
  v21 = v5[25];
  *((_DWORD *)v19 + 23) = v5[23];
  *((_DWORD *)v19 + 24) = v20;
  *((_DWORD *)v19 + 25) = v21;
  v22 = v5[27];
  v23 = v5[28];
  *((_DWORD *)v19 + 26) = v5[26];
  *((_DWORD *)v19 + 27) = v22;
  *((_DWORD *)v19 + 28) = v23;
  v19[15] = *((_QWORD *)v5 + 15);
  UFG::qMemoryStreamer::BeginRawWritePlat(v9, stream_name, local_mem, 0x80ui64, v5, 0x80ui64);
  UFG::qMemoryStreamer::BeginRawWritePlat(v9, v30, v33, 0x1F80ui64, v12, 48i64 * *v5);
}

// File Line: 225
// RVA: 0x3A1C20
char *__fastcall PoseTaskRingBuffer::AllocAndAssignDependents(PoseTaskRingBuffer *this, unsigned int bufferSize, UFG::qTask *task)
{
  unsigned int v3; // ebp
  UFG::qTask *v4; // rsi
  PoseTaskRingBuffer *v5; // rbx
  PoseTaskRingBuffer::RingElement *v6; // rdi
  UFG::qTask *v7; // rdx
  unsigned int v8; // ecx

  v3 = bufferSize;
  v4 = task;
  v5 = this;
  if ( (this->mLastElement + 1) % 0x30 == this->mFirstElement )
  {
    v6 = this->mFirst;
    v7 = this->mFirst->mTask;
    if ( v7 )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v7);
      v6->mTask = 0i64;
    }
    v8 = v5->mFirstElement + 1;
    v5->mFirst = v5->mFirst->mNext;
    v5->mFirstElement = v8 % 0x30;
  }
  PoseTaskRingBuffer::AllocFromRingBuffer(v5, v3, v4);
  PoseTaskRingBuffer::AssignDependencies(v5);
  return v5->mLast->mBuffer;
}

// File Line: 239
// RVA: 0x3A1CE0
char *__fastcall PoseTaskRingBuffer::AllocAndSyncDependents(PoseTaskRingBuffer *this, unsigned int bufferSize)
{
  unsigned int v2; // esi
  PoseTaskRingBuffer *v3; // rbx
  PoseTaskRingBuffer::RingElement *v4; // rdi
  UFG::qTask *v5; // rdx
  unsigned int v6; // ecx

  v2 = bufferSize;
  v3 = this;
  if ( (this->mLastElement + 1) % 0x30 == this->mFirstElement )
  {
    v4 = this->mFirst;
    v5 = this->mFirst->mTask;
    if ( v5 )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v5);
      v4->mTask = 0i64;
    }
    v6 = v3->mFirstElement + 1;
    v3->mFirst = v3->mFirst->mNext;
    v3->mFirstElement = v6 % 0x30;
  }
  PoseTaskRingBuffer::AllocFromRingBuffer(v3, v2, 0i64);
  PoseTaskRingBuffer::SyncDependencies(v3);
  return v3->mLast->mBuffer;
}

// File Line: 261
// RVA: 0x3A1D90
void __fastcall PoseTaskRingBuffer::AllocFromRingBuffer(PoseTaskRingBuffer *this, unsigned int bufferSize, UFG::qTask *task)
{
  PoseTaskRingBuffer::RingElement *v3; // r10
  UFG::qTask *v4; // rdi
  char *v5; // r11
  char *v6; // rax
  bool v7; // cf
  bool v8; // zf
  __int64 v9; // rax
  PoseTaskRingBuffer::RingElement *v10; // r8
  PoseTaskRingBuffer::RingElement *v11; // rax

  v3 = this->mLast;
  v4 = task;
  if ( v3 )
    v5 = v3->mBuffer;
  else
    v5 = this->mBuffer;
  v6 = &this->mBuffer[this->mBufferSize];
  v7 = &v5[bufferSize] < v6;
  v8 = &v5[bufferSize] == v6;
  v9 = this->mLastElement;
  if ( !v7 && !v8 )
    v5 = this->mBuffer;
  v10 = (PoseTaskRingBuffer::RingElement *)((char *)this + 32 * (v9 + 1));
  this->mLast = v10;
  this->mLastElement = ((signed int)v9 + 1) % 0x30u;
  v10->mNext = 0i64;
  this->mLast->mBuffer = v5;
  this->mLast->mSize = bufferSize;
  this->mLast->mTask = v4;
  v11 = this->mLast;
  if ( v3 )
    v3->mNext = v11;
  else
    this->mFirst = v11;
}

// File Line: 294
// RVA: 0x3A24A0
void __fastcall PoseTaskRingBuffer::AssignDependencies(PoseTaskRingBuffer *this)
{
  PoseTaskRingBuffer::RingElement *v1; // rdx
  PoseTaskRingBuffer::RingElement *v2; // rbx
  PoseTaskRingBuffer *v3; // rsi
  unsigned __int64 i; // rdi
  char *v5; // rcx

  v1 = this->mLast;
  v2 = this->mFirst;
  v3 = this;
  for ( i = (unsigned __int64)v1->mBuffer; v2 != v1; v1 = v3->mLast )
  {
    if ( v2->mTask )
    {
      v5 = v2->mBuffer;
      if ( i >= (unsigned __int64)v5 && i < (unsigned __int64)&v5[v2->mSize] )
        UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v1->mTask, v2->mTask);
    }
    v2 = v2->mNext;
  }
}

// File Line: 315
// RVA: 0x3B0150
void __fastcall PoseTaskRingBuffer::SyncDependencies(PoseTaskRingBuffer *this)
{
  PoseTaskRingBuffer::RingElement *v1; // rax
  PoseTaskRingBuffer::RingElement *v2; // rbx
  PoseTaskRingBuffer *v3; // rdi
  unsigned __int64 v4; // rsi
  char *v5; // rcx
  unsigned int v6; // ecx

  v1 = this->mLast;
  v2 = this->mFirst;
  v3 = this;
  v4 = (unsigned __int64)v1->mBuffer;
  if ( this->mFirst != v1 )
  {
    do
    {
      v5 = v2->mBuffer;
      if ( v4 >= (unsigned __int64)v5 && v4 < (unsigned __int64)&v5[v2->mSize] )
      {
        if ( v2->mTask )
        {
          UFG::qTaskManager::Sync(&UFG::gTaskManager, v2->mTask);
          v2->mTask = 0i64;
        }
        if ( v2 == v3->mFirst )
        {
          v6 = v3->mFirstElement;
          v3->mFirst = v3->mFirst->mNext;
          v3->mFirstElement = (v6 + 1) % 0x30;
        }
      }
      v2 = v2->mNext;
    }
    while ( v2 != v3->mLast );
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
  PoseTaskInputParams *v1; // rdi
  char *v2; // rax
  UFG::qTask *v3; // rbx
  _QWORD *v4; // rax
  UFG::qSpuElf *v5; // rax
  void (__fastcall *v6)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rcx
  void (__fastcall *v7)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *v8)(void *, void *, void *, void *); // rdx
  char *v9; // r8
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v10; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v11; // rax

  v1 = input;
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
    v5 = gTaskFunctionDeclData_PoseTask.mSpuElf;
    v6 = gTaskFunctionDeclData_PoseTask.mTaskFunctionSPU;
    v7 = gTaskFunctionDeclData_PoseTask.mTaskFunctionPPU;
    v8 = gTaskFunctionDeclData_PoseTask.mTaskFunctionOffload;
    if ( !gTaskFunctionDeclData_PoseTask.mCurrentSPUEnabled )
    {
      v5 = 0i64;
      v6 = 0i64;
      v8 = 0i64;
    }
    v3->mTaskGroup = 0i64;
    v3->mFlags = 2;
    v3->mSyncVars.i64 = 0i64;
    v3->mSyncVars.v.mDependents = 0i64;
    v3->mFunctionDeclData = &gTaskFunctionDeclData_PoseTask;
    if ( v5 )
      v9 = v5->mAddress;
    else
      v9 = 0i64;
    v3->mSPUElfAddress = v9;
    v3->mSPUFunction = v6;
    v3->mPPUFunction = v7;
    v3->mParam0 = v1;
    v3->mParam1 = 0i64;
    v3->mParam2 = 0i64;
    v3->mParam3 = 0i64;
    if ( v8 )
    {
      v3->mFlags = 130;
      v3->mOffloadThread = 0;
    }
  }
  v10 = UFG::gTaskManager.mSingleFrameTasks;
  v11 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
  v11->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v3->mPrev;
  v3->mPrev = v11;
  v3->mNext = &v10->mNode;
  v10->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v3->mPrev;
  v3->mFlags &= 0xFFFFFFF1;
  v3->mFlags |= 1u;
  v1->mScratchBuffer = PoseTaskRingBuffer::AllocAndAssignDependents(
                         PoseTaskSubmission::sRingBuffer,
                         v1->mBufferSize,
                         v3);
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v3);
  return v3;
}

// File Line: 447
// RVA: 0x3A77A0
void __fastcall PoseTaskSubmission::ExecuteLocalTask(PoseTaskInputParams *input)
{
  PoseTaskInputParams *v1; // rbx
  char *v2; // rax
  __m128 *v3; // xmm4_8
  __int64 v4; // rdx
  __int64 v5; // rcx
  hkQsTransformf **v6; // r9
  unsigned int v7; // eax
  hkQsTransformf *v8; // r8
  PoseEvaluator v9; // [rsp+30h] [rbp-28h]

  ++PoseTaskSubmission::sTotalTasksSubmitted;
  v1 = input;
  v2 = PoseTaskRingBuffer::AllocAndSyncDependents(PoseTaskSubmission::sRingBuffer, input->mBufferSize);
  v4 = v1->mBufferCount;
  v5 = 0i64;
  v6 = (hkQsTransformf **)v2;
  if ( (_DWORD)v4 )
  {
    do
    {
      *(_QWORD *)&v2[8 * v5] = &v2[((8 * v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64) + (unsigned int)(v5 * v1->mBufferStride)];
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < v1->mBufferCount );
  }
  v7 = v1->mBufferCount;
  v8 = v1->mOutputTransforms;
  v9.mScratchBuffers.mStack = v6;
  v9.mScratchBuffers.mStackDepth = v7;
  v9.mScratchBuffers.mStackSize = v7;
  v9.mMemoryStreamer = 0i64;
  PoseEvaluator::EvaluatePoseModelSpace(
    &v9,
    &v1->mRecipe,
    v8,
    &v1->mOutputModelSpaceAABBMin,
    v3,
    &v1->mOutputModelSpaceAABBMax);
}

