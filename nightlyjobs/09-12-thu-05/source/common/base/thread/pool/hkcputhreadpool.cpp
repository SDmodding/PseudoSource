// File Line: 22
// RVA: 0xC81960
void __fastcall hkCpuThreadPoolCinfo::hkCpuThreadPoolCinfo(hkCpuThreadPoolCinfo *this, void (__fastcall *workerFunction)(void *))
{
  this->m_workerFunction = workerFunction;
  *(_QWORD *)&this->m_numThreads = 1i64;
  this->m_timerBufferPerThreadAllocation = 0;
  this->m_hardwareThreadIds.m_data = 0i64;
  this->m_hardwareThreadIds.m_size = 0;
  this->m_hardwareThreadIds.m_capacityAndFlags = 2147483648;
  this->m_threadName = "HavokWorkerThread";
}

// File Line: 30
// RVA: 0xC81930
void __fastcall hkCpuThreadPool::SharedThreadData::SharedThreadData(hkCpuThreadPool::SharedThreadData *this)
{
  hkCpuThreadPool::SharedThreadData *v1; // rbx

  v1 = this;
  hkSemaphore::hkSemaphore(&this->m_workerThreadFinished, 0, 12, 0);
  v1->m_gcThreadMemoryOnCompletion.m_bool = 0;
}

// File Line: 35
// RVA: 0xC818E0
void __fastcall hkCpuThreadPool::WorkerThreadData::WorkerThreadData(hkCpuThreadPool::WorkerThreadData *this)
{
  hkCpuThreadPool::WorkerThreadData *v1; // rbx

  v1 = this;
  hkThread::hkThread(&this->m_thread);
  hkSemaphore::hkSemaphore(&v1->m_semaphore, 0, 1, 0);
  v1->m_killThread = 0;
  v1->m_threadId = -1;
  v1->m_sharedThreadData = 0i64;
}

// File Line: 44
// RVA: 0xC811C0
void __fastcall hkCpuThreadPool::hkCpuThreadPool(hkCpuThreadPool *this, hkCpuThreadPoolCinfo *ci)
{
  hkCpuThreadPoolCinfo *v2; // r14
  hkCpuThreadPool *v3; // rsi
  hkCpuThreadPool::WorkerThreadData *v4; // rbx
  signed int v5; // edi
  signed int v6; // ebx
  int v7; // er13
  __int64 v8; // rbp
  __int64 v9; // r12
  signed int v10; // edi
  signed __int64 v11; // rbx
  hkHardwareInfo info; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v2 = ci;
  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = this->m_workerThreads;
  this->vfptr = (hkBaseObjectVtbl *)&hkCpuThreadPool::`vftable';
  v5 = 11;
  do
  {
    hkCpuThreadPool::WorkerThreadData::WorkerThreadData(v4);
    ++v4;
    --v5;
  }
  while ( v5 >= 0 );
  hkCpuThreadPool::SharedThreadData::SharedThreadData(&v3->m_sharedThreadData);
  v3->m_isRunning.m_bool = 0;
  v3->m_threadName = v2->m_threadName;
  v3->m_stackSize = v2->m_stackSize;
  v3->m_sharedThreadData.m_workerFunction = v2->m_workerFunction;
  v3->m_sharedThreadData.m_timerBufferAllocation = v2->m_timerBufferPerThreadAllocation;
  v6 = v2->m_numThreads;
  if ( v6 >= 12 )
    v6 = 11;
  v3->m_sharedThreadData.m_numThreads = v6;
  hkGetHardwareInfo(&info);
  v7 = info.m_numThreads;
  v8 = 0i64;
  v9 = v6;
  if ( v6 > 0 )
  {
    v10 = 1;
    v11 = (signed __int64)&v3->m_workerThreads[0].m_killThread;
    do
    {
      *(_DWORD *)(v11 - 8) = v10;
      *(_WORD *)v11 = 0;
      *(_QWORD *)(v11 - 32) = (char *)v3 + 880;
      *(_QWORD *)(v11 + 32) = 0i64;
      if ( v2->m_hardwareThreadIds.m_size <= 0 )
        *(_DWORD *)(v11 - 4) = v10 % v7;
      else
        *(_DWORD *)(v11 - 4) = v2->m_hardwareThreadIds.m_data[v8];
      hkThread::startThread(
        (hkThread *)(v11 - 24),
        &result,
        hkCpuThreadPool::threadMain,
        (void *)(v11 - 32),
        v3->m_threadName,
        v3->m_stackSize);
      ++v8;
      ++v10;
      v11 += 72i64;
    }
    while ( v8 < v9 );
  }
  hkReferencedObject::setLockMode(LOCK_MODE_AUTO);
}

// File Line: 100
// RVA: 0xC81780
void *__fastcall hkCpuThreadPool::threadMain(void *v)
{
  __int64 v1; // rdi
  void *v2; // rbx
  hkMonitorStream *v3; // rax
  HANDLE v4; // rax
  hkMonitorStream *v5; // rax
  __int64 v6; // rcx
  hkMemorySystem *v7; // rax
  hkWorkerThreadContext v9; // [rsp+20h] [rbp-88h]

  v1 = *(_QWORD *)v;
  v2 = v;
  hkWorkerThreadContext::hkWorkerThreadContext(&v9, *((_DWORD *)v + 6));
  *((_QWORD *)v2 + 8) = &v9;
  if ( *(_DWORD *)(v1 + 28) > 0 )
  {
    v3 = (hkMonitorStream *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    hkMonitorStream::resize(v3, *(_DWORD *)(v1 + 28));
  }
  *((_QWORD *)v2 + 6) = *(_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  *((_QWORD *)v2 + 7) = *((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
  v4 = GetCurrentThread();
  SetThreadIdealProcessor(v4, *((_DWORD *)v2 + 7));
  hkSemaphore::acquire((hkSemaphore *)v2 + 5);
  while ( !*((_BYTE *)v2 + 32) )
  {
    if ( *((_BYTE *)v2 + 33) )
    {
      v5 = (hkMonitorStream *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      hkMonitorStream::reset(v5);
      v6 = *((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
      *((_BYTE *)v2 + 33) = 0;
      *((_QWORD *)v2 + 7) = v6;
    }
    (*(void (__fastcall **)(_QWORD))v1)(*(_QWORD *)(v1 + 8));
    *((_QWORD *)v2 + 7) = *((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
    if ( *(_BYTE *)(v1 + 32) )
    {
      v7 = hkMemorySystem::getInstance();
      v7->vfptr->garbageCollectThread(v7, &v9.m_memoryRouter);
    }
    hkSemaphore::release((hkSemaphore *)(v1 + 16), 1);
    hkSemaphore::acquire((hkSemaphore *)v2 + 5);
  }
  hkWorkerThreadContext::~hkWorkerThreadContext(&v9);
  return 0i64;
}

// File Line: 198
// RVA: 0xC81320
void __fastcall hkCpuThreadPool::~hkCpuThreadPool(hkCpuThreadPool *this)
{
  hkCpuThreadPool *v1; // rdi
  int v2; // ebx
  int v3; // ebp
  hkSemaphore *v4; // rsi
  signed int v5; // esi
  signed __int64 v6; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkCpuThreadPool::`vftable';
  hkCpuThreadPool::waitForCompletion(this);
  v2 = 0;
  v3 = 0;
  if ( v1->m_sharedThreadData.m_numThreads > 0 )
  {
    v4 = &v1->m_workerThreads[0].m_semaphore;
    do
    {
      LOBYTE(v4[-1].m_semaphore) = 1;
      hkSemaphore::release(v4, 1);
      ++v3;
      v4 += 9;
    }
    while ( v3 < v1->m_sharedThreadData.m_numThreads );
    if ( v1->m_sharedThreadData.m_numThreads > 0 )
    {
      do
      {
        hkThread::joinThread((hkThread *)(&v1->vfptr + v2 + 8i64 * v2 + 3));
        ++v2;
      }
      while ( v2 < v1->m_sharedThreadData.m_numThreads );
    }
  }
  hkReferencedObject::setLockMode(0);
  hkSemaphore::~hkSemaphore(&v1->m_sharedThreadData.m_workerThreadFinished);
  v5 = 11;
  v6 = (signed __int64)&v1->m_sharedThreadData.m_workLoad;
  do
  {
    v6 -= 72i64;
    hkSemaphore::~hkSemaphore((hkSemaphore *)(v6 + 32));
    hkThread::~hkThread((hkThread *)v6);
    --v5;
  }
  while ( v5 >= 0 );
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 218
// RVA: 0xC81680
void __fastcall hkCpuThreadPool::gcThreadMemoryOnNextCompletion(hkCpuThreadPool *this)
{
  this->m_sharedThreadData.m_gcThreadMemoryOnCompletion.m_bool = 1;
}

// File Line: 223
// RVA: 0xC81690
void __fastcall hkCpuThreadPool::addThread(hkCpuThreadPool *this)
{
  hkCpuThreadPool *v1; // rdi
  char *v2; // rbx
  int v3; // eax
  _SYSTEM_INFO SystemInfo; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v1 = this;
  v2 = (char *)this + 72 * this->m_sharedThreadData.m_numThreads;
  *((_QWORD *)v2 + 2) = (char *)this + 880;
  v3 = this->m_sharedThreadData.m_numThreads;
  *((_WORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 10) = v3 + 1;
  GetSystemInfo(&SystemInfo);
  *((_DWORD *)v2 + 11) = *((_DWORD *)v2 + 10) % (signed int)SystemInfo.dwNumberOfProcessors;
  hkThread::startThread(
    (hkThread *)(v2 + 24),
    &result,
    hkCpuThreadPool::threadMain,
    v2 + 16,
    v1->m_threadName,
    v1->m_stackSize);
  ++v1->m_sharedThreadData.m_numThreads;
}

// File Line: 264
// RVA: 0xC81730
void __fastcall hkCpuThreadPool::removeThread(hkCpuThreadPool *this)
{
  char *v1; // rbx

  v1 = (char *)this + 72 * --this->m_sharedThreadData.m_numThreads;
  v1[48] = 1;
  hkSemaphore::release((hkSemaphore *)v1 + 7, 1);
  hkThread::joinThread((hkThread *)(v1 + 24));
}

// File Line: 285
// RVA: 0xC81410
void __fastcall hkCpuThreadPool::processWorkLoad(hkCpuThreadPool *this, void *workLoad)
{
  int v2; // ebx
  int v3; // ebx
  hkSemaphore *v4; // rdi

  this->m_isRunning.m_bool = 1;
  v2 = this->m_sharedThreadData.m_numThreads;
  this->m_sharedThreadData.m_workLoad = workLoad;
  v3 = v2 - 1;
  if ( v3 >= 0 )
  {
    v4 = (hkSemaphore *)(&this->vfptr + v3 + 8i64 * v3 + 7);
    do
    {
      hkSemaphore::release(v4, 1);
      v4 -= 9;
      --v3;
    }
    while ( v3 >= 0 );
  }
}

// File Line: 300
// RVA: 0xC81480
void __fastcall hkCpuThreadPool::waitForCompletion(hkCpuThreadPool *this)
{
  hkCpuThreadPool *v1; // rbx
  int v2; // edi

  v1 = this;
  if ( this->m_isRunning.m_bool )
  {
    v2 = 0;
    if ( this->m_sharedThreadData.m_numThreads > 0 )
    {
      do
      {
        hkSemaphore::acquire(&v1->m_sharedThreadData.m_workerThreadFinished);
        ++v2;
      }
      while ( v2 < v1->m_sharedThreadData.m_numThreads );
    }
    v1->m_isRunning.m_bool = 0;
    v1->m_sharedThreadData.m_gcThreadMemoryOnCompletion.m_bool = 0;
  }
}

// File Line: 315
// RVA: 0xC814F0
_BOOL8 __fastcall hkCpuThreadPool::isProcessing(hkCpuThreadPool *this)
{
  return this->m_isRunning.m_bool != 0;
}

// File Line: 321
// RVA: 0xC81510
void __fastcall hkCpuThreadPool::appendTimerData(hkCpuThreadPool *this, hkArrayBase<hkTimerData> *timerDataOut, hkMemoryAllocator *alloc)
{
  int v3; // esi
  hkMemoryAllocator *v4; // r14
  hkArrayBase<hkTimerData> *v5; // rbx
  hkCpuThreadPool *v6; // rbp
  char **v7; // rdi
  hkTimerData *v8; // rcx

  v3 = 0;
  v4 = alloc;
  v5 = timerDataOut;
  v6 = this;
  if ( this->m_sharedThreadData.m_numThreads > 0 )
  {
    v7 = &this->m_workerThreads[0].m_monitorStreamEnd;
    do
    {
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(v4, v5, 16);
      ++v3;
      v7 += 9;
      v8 = &v5->m_data[v5->m_size++];
      v8->m_streamBegin = *(v7 - 10);
      v8->m_streamEnd = *(v7 - 9);
    }
    while ( v3 < v6->m_sharedThreadData.m_numThreads );
  }
}

// File Line: 332
// RVA: 0xC815C0
void __fastcall hkCpuThreadPool::clearTimerData(hkCpuThreadPool *this)
{
  int v1; // er8
  char **v2; // rax
  char *v3; // rdx

  v1 = 0;
  if ( this->m_sharedThreadData.m_numThreads > 0 )
  {
    v2 = &this->m_workerThreads[0].m_monitorStreamEnd;
    do
    {
      v3 = *(v2 - 1);
      *((_BYTE *)v2 - 23) = 1;
      ++v1;
      *v2 = v3;
      v2 += 9;
    }
    while ( v1 < this->m_sharedThreadData.m_numThreads );
  }
}

// File Line: 342
// RVA: 0xC81600
__int64 __fastcall hkCpuThreadPool::getNumThreads(hkCpuThreadPool *this)
{
  return (unsigned int)this->m_sharedThreadData.m_numThreads;
}

// File Line: 348
// RVA: 0xC81610
void __fastcall hkCpuThreadPool::setNumThreads(hkCpuThreadPool *this, int numThreads)
{
  int v2; // edi
  hkCpuThreadPool *i; // rbx

  v2 = numThreads;
  if ( numThreads >= 12 )
    v2 = 11;
  for ( i = this; i->m_sharedThreadData.m_numThreads < v2; hkCpuThreadPool::addThread(i) )
    ;
  while ( i->m_sharedThreadData.m_numThreads > v2 )
    hkCpuThreadPool::removeThread(i);
}

