// File Line: 22
// RVA: 0xC81960
void __fastcall hkCpuThreadPoolCinfo::hkCpuThreadPoolCinfo(
        hkCpuThreadPoolCinfo *this,
        void (__fastcall *workerFunction)(void *))
{
  this->m_workerFunction = workerFunction;
  *(_QWORD *)&this->m_numThreads = 1i64;
  this->m_timerBufferPerThreadAllocation = 0;
  this->m_hardwareThreadIds.m_data = 0i64;
  this->m_hardwareThreadIds.m_size = 0;
  this->m_hardwareThreadIds.m_capacityAndFlags = 0x80000000;
  this->m_threadName = "HavokWorkerThread";
}

// File Line: 30
// RVA: 0xC81930
void __fastcall hkCpuThreadPool::SharedThreadData::SharedThreadData(hkCpuThreadPool::SharedThreadData *this)
{
  hkSemaphore::hkSemaphore(&this->m_workerThreadFinished, 0, 12, 0);
  this->m_gcThreadMemoryOnCompletion.m_bool = 0;
}

// File Line: 35
// RVA: 0xC818E0
void __fastcall hkCpuThreadPool::WorkerThreadData::WorkerThreadData(hkCpuThreadPool::WorkerThreadData *this)
{
  hkThread::hkThread(&this->m_thread);
  hkSemaphore::hkSemaphore(&this->m_semaphore, 0, 1, 0);
  this->m_killThread = 0;
  this->m_threadId = -1;
  this->m_sharedThreadData = 0i64;
}

// File Line: 44
// RVA: 0xC811C0
void __fastcall hkCpuThreadPool::hkCpuThreadPool(hkCpuThreadPool *this, hkCpuThreadPoolCinfo *ci)
{
  hkCpuThreadPool::WorkerThreadData *m_workerThreads; // rbx
  int i; // edi
  int m_numThreads; // ebx
  int v7; // r13d
  __int64 v8; // rbp
  __int64 v9; // r12
  int v10; // edi
  bool *p_m_killThread; // rbx
  hkHardwareInfo info; // [rsp+70h] [rbp+8h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  m_workerThreads = this->m_workerThreads;
  this->vfptr = (hkBaseObjectVtbl *)&hkCpuThreadPool::`vftable;
  for ( i = 11; i >= 0; --i )
    hkCpuThreadPool::WorkerThreadData::WorkerThreadData(m_workerThreads++);
  hkCpuThreadPool::SharedThreadData::SharedThreadData(&this->m_sharedThreadData);
  this->m_isRunning.m_bool = 0;
  this->m_threadName = ci->m_threadName;
  this->m_stackSize = ci->m_stackSize;
  this->m_sharedThreadData.m_workerFunction = ci->m_workerFunction;
  this->m_sharedThreadData.m_timerBufferAllocation = ci->m_timerBufferPerThreadAllocation;
  m_numThreads = ci->m_numThreads;
  if ( m_numThreads >= 12 )
    m_numThreads = 11;
  this->m_sharedThreadData.m_numThreads = m_numThreads;
  hkGetHardwareInfo(&info);
  v7 = info.m_numThreads;
  v8 = 0i64;
  v9 = m_numThreads;
  if ( m_numThreads > 0 )
  {
    v10 = 1;
    p_m_killThread = &this->m_workerThreads[0].m_killThread;
    do
    {
      *((_DWORD *)p_m_killThread - 2) = v10;
      *(_WORD *)p_m_killThread = 0;
      *((_QWORD *)p_m_killThread - 4) = &this->m_sharedThreadData;
      *((_QWORD *)p_m_killThread + 4) = 0i64;
      if ( ci->m_hardwareThreadIds.m_size <= 0 )
        *((_DWORD *)p_m_killThread - 1) = v10 % v7;
      else
        *((_DWORD *)p_m_killThread - 1) = ci->m_hardwareThreadIds.m_data[v8];
      hkThread::startThread(
        (hkThread *)(p_m_killThread - 24),
        &result,
        (unsigned int (__fastcall *)(void *))hkCpuThreadPool::threadMain,
        p_m_killThread - 32,
        this->m_threadName,
        this->m_stackSize);
      ++v8;
      ++v10;
      p_m_killThread += 72;
    }
    while ( v8 < v9 );
  }
  hkReferencedObject::setLockMode(LOCK_MODE_AUTO);
}

// File Line: 100
// RVA: 0xC81780
void *__fastcall hkCpuThreadPool::threadMain(__int64 *v)
{
  __int64 v1; // rdi
  hkMonitorStream *Value; // rax
  HANDLE CurrentThread; // rax
  hkMonitorStream *v5; // rax
  __int64 v6; // rcx
  hkMemorySystem *Instance; // rax
  hkWorkerThreadContext v9; // [rsp+20h] [rbp-88h] BYREF

  v1 = *v;
  hkWorkerThreadContext::hkWorkerThreadContext(&v9, *((_DWORD *)v + 6));
  v[8] = (__int64)&v9;
  if ( *(int *)(v1 + 28) > 0 )
  {
    Value = (hkMonitorStream *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    hkMonitorStream::resize(Value, *(_DWORD *)(v1 + 28));
  }
  v[6] = *(_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v[7] = *((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
  CurrentThread = GetCurrentThread();
  SetThreadIdealProcessor(CurrentThread, *((_DWORD *)v + 7));
  hkSemaphore::acquire((hkSemaphore *)v + 5);
  while ( !*((_BYTE *)v + 32) )
  {
    if ( *((_BYTE *)v + 33) )
    {
      v5 = (hkMonitorStream *)TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      hkMonitorStream::reset(v5);
      v6 = *((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
      *((_BYTE *)v + 33) = 0;
      v[7] = v6;
    }
    (*(void (__fastcall **)(_QWORD))v1)(*(_QWORD *)(v1 + 8));
    v[7] = *((_QWORD *)TlsGetValue(hkMonitorStream__m_instance.m_slotID) + 1);
    if ( *(_BYTE *)(v1 + 32) )
    {
      Instance = hkMemorySystem::getInstance();
      Instance->vfptr->garbageCollectThread(Instance, &v9.m_memoryRouter);
    }
    hkSemaphore::release((hkSemaphore *)(v1 + 16), 1);
    hkSemaphore::acquire((hkSemaphore *)v + 5);
  }
  hkWorkerThreadContext::~hkWorkerThreadContext(&v9);
  return 0i64;
}

// File Line: 198
// RVA: 0xC81320
void __fastcall hkCpuThreadPool::~hkCpuThreadPool(hkCpuThreadPool *this)
{
  int v2; // ebx
  int v3; // ebp
  hkSemaphore *p_m_semaphore; // rsi
  int v5; // esi
  void **p_m_workLoad; // rbx

  this->vfptr = (hkBaseObjectVtbl *)&hkCpuThreadPool::`vftable;
  hkCpuThreadPool::waitForCompletion(this);
  v2 = 0;
  v3 = 0;
  if ( this->m_sharedThreadData.m_numThreads > 0 )
  {
    p_m_semaphore = &this->m_workerThreads[0].m_semaphore;
    do
    {
      LOBYTE(p_m_semaphore[-1].m_semaphore) = 1;
      hkSemaphore::release(p_m_semaphore, 1);
      ++v3;
      p_m_semaphore += 9;
    }
    while ( v3 < this->m_sharedThreadData.m_numThreads );
    if ( this->m_sharedThreadData.m_numThreads > 0 )
    {
      do
      {
        hkThread::joinThread((hkThread *)((char *)&this->m_workerThreads[0].m_thread + 64 * v2 + 8 * v2));
        ++v2;
      }
      while ( v2 < this->m_sharedThreadData.m_numThreads );
    }
  }
  hkReferencedObject::setLockMode(LOCK_MODE_NONE);
  hkSemaphore::~hkSemaphore(&this->m_sharedThreadData.m_workerThreadFinished);
  v5 = 11;
  p_m_workLoad = &this->m_sharedThreadData.m_workLoad;
  do
  {
    p_m_workLoad -= 9;
    hkSemaphore::~hkSemaphore((hkSemaphore *)p_m_workLoad + 4);
    hkThread::~hkThread((hkThread *)p_m_workLoad);
    --v5;
  }
  while ( v5 >= 0 );
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
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
  char *v2; // rbx
  int m_numThreads; // eax
  _SYSTEM_INFO SystemInfo; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  v2 = (char *)this + 72 * this->m_sharedThreadData.m_numThreads;
  *((_QWORD *)v2 + 2) = &this->m_sharedThreadData;
  m_numThreads = this->m_sharedThreadData.m_numThreads;
  *((_WORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 10) = m_numThreads + 1;
  GetSystemInfo(&SystemInfo);
  *((_DWORD *)v2 + 11) = *((_DWORD *)v2 + 10) % (signed int)SystemInfo.dwNumberOfProcessors;
  hkThread::startThread(
    (hkThread *)(v2 + 24),
    &result,
    (unsigned int (__fastcall *)(void *))hkCpuThreadPool::threadMain,
    v2 + 16,
    this->m_threadName,
    this->m_stackSize);
  ++this->m_sharedThreadData.m_numThreads;
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
  int m_numThreads; // ebx
  int v3; // ebx
  hkSemaphore *v4; // rdi

  this->m_isRunning.m_bool = 1;
  m_numThreads = this->m_sharedThreadData.m_numThreads;
  this->m_sharedThreadData.m_workLoad = workLoad;
  v3 = m_numThreads - 1;
  if ( v3 >= 0 )
  {
    v4 = &this->m_workerThreads[0].m_semaphore + 8 * v3 + v3;
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
  int i; // edi

  if ( this->m_isRunning.m_bool )
  {
    for ( i = 0; i < this->m_sharedThreadData.m_numThreads; ++i )
      hkSemaphore::acquire(&this->m_sharedThreadData.m_workerThreadFinished);
    this->m_isRunning.m_bool = 0;
    this->m_sharedThreadData.m_gcThreadMemoryOnCompletion.m_bool = 0;
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
void __fastcall hkCpuThreadPool::appendTimerData(
        hkCpuThreadPool *this,
        hkArrayBase<hkTimerData> *timerDataOut,
        hkMemoryAllocator *alloc)
{
  int v3; // esi
  char **p_m_monitorStreamEnd; // rdi
  hkTimerData *v8; // rcx

  v3 = 0;
  if ( this->m_sharedThreadData.m_numThreads > 0 )
  {
    p_m_monitorStreamEnd = &this->m_workerThreads[0].m_monitorStreamEnd;
    do
    {
      if ( timerDataOut->m_size == (timerDataOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(alloc, (const void **)&timerDataOut->m_data, 16);
      ++v3;
      p_m_monitorStreamEnd += 9;
      v8 = &timerDataOut->m_data[timerDataOut->m_size++];
      v8->m_streamBegin = *(p_m_monitorStreamEnd - 10);
      v8->m_streamEnd = *(p_m_monitorStreamEnd - 9);
    }
    while ( v3 < this->m_sharedThreadData.m_numThreads );
  }
}

// File Line: 332
// RVA: 0xC815C0
void __fastcall hkCpuThreadPool::clearTimerData(hkCpuThreadPool *this)
{
  int v1; // r8d
  char **p_m_monitorStreamEnd; // rax
  char *v3; // rdx

  v1 = 0;
  if ( this->m_sharedThreadData.m_numThreads > 0 )
  {
    p_m_monitorStreamEnd = &this->m_workerThreads[0].m_monitorStreamEnd;
    do
    {
      v3 = *(p_m_monitorStreamEnd - 1);
      *((_BYTE *)p_m_monitorStreamEnd - 23) = 1;
      ++v1;
      *p_m_monitorStreamEnd = v3;
      p_m_monitorStreamEnd += 9;
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

  v2 = numThreads;
  if ( numThreads >= 12 )
    v2 = 11;
  while ( this->m_sharedThreadData.m_numThreads < v2 )
    hkCpuThreadPool::addThread(this);
  while ( this->m_sharedThreadData.m_numThreads > v2 )
    hkCpuThreadPool::removeThread(this);
}

