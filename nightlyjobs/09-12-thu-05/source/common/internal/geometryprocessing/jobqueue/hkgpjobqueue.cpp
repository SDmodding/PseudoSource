// File Line: 17
// RVA: 0xCE4400
void __fastcall hkgpJobQueue::hkgpJobQueue(hkgpJobQueue *this, int numThreads)
{
  int m_numThreads; // esi
  _QWORD **Value; // rax
  hkCriticalSection *v5; // rax
  hkCriticalSection *v6; // rax
  _QWORD **v7; // rax
  hkSemaphore *v8; // rax
  hkSemaphore *v9; // rax
  _QWORD **v10; // rax
  hkSemaphore *v11; // rax
  hkSemaphore *v12; // rax
  _QWORD **v13; // rax
  hkSemaphore *v14; // rax
  hkSemaphore *v15; // rax
  int v16; // eax
  int v17; // eax
  int v18; // r9d
  int v19; // edx
  __int64 i; // rdi
  _QWORD **v21; // rax
  hkThread *v22; // rax
  hkThread *v23; // rax
  hkThread *v24; // rcx
  hkHardwareInfo info; // [rsp+58h] [rbp+10h] BYREF

  this->m_threads.m_capacityAndFlags = -2147483640;
  this->m_threads.m_data = this->m_threads.m_storage;
  this->m_threads.m_size = 0;
  m_numThreads = numThreads;
  this->m_jobs.m_data = 0i64;
  this->m_jobs.m_size = 0;
  this->m_jobs.m_capacityAndFlags = 0x80000000;
  if ( numThreads <= 0 )
  {
    hkGetHardwareInfo(&info);
    m_numThreads = info.m_numThreads;
  }
  this->m_numPendings = 0;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v5 )
    hkCriticalSection::hkCriticalSection(v5, 0);
  else
    v6 = 0i64;
  this->m_jobsLock = v6;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v7[11] + 8i64))(v7[11], 8i64);
  if ( v8 )
    hkSemaphore::hkSemaphore(v8, 0, 1000, 0);
  else
    v9 = 0i64;
  this->m_newJobEvent = v9;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 8i64);
  if ( v11 )
    hkSemaphore::hkSemaphore(v11, 0, 1000, 0);
  else
    v12 = 0i64;
  this->m_endJobEvent = v12;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 8i64);
  if ( v14 )
    hkSemaphore::hkSemaphore(v14, 0, 1000, 0);
  else
    v15 = 0i64;
  this->m_endThreadEvent = v15;
  v16 = this->m_threads.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < m_numThreads )
  {
    v17 = 2 * v16;
    v18 = m_numThreads;
    if ( m_numThreads < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(
      (hkResult *)&info,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_threads.m_data,
      v18,
      8);
  }
  v19 = m_numThreads - this->m_threads.m_size;
  if ( v19 > 0 )
    memset(&this->m_threads.m_data[this->m_threads.m_size], 0, 8i64 * v19);
  this->m_threads.m_size = m_numThreads;
  if ( m_numThreads > 1 )
  {
    for ( i = 0i64;
          i < m_numThreads;
          hkThread::startThread(
            this->m_threads.m_data[i++],
            (hkResult *)&info,
            (unsigned int (__fastcall *)(void *))hkgpJobQueue::threadStart,
            this,
            &customCaption,
            0) )
    {
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v22 = (hkThread *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 16i64);
      if ( v22 )
      {
        hkThread::hkThread(v22);
        v24 = v23;
      }
      else
      {
        v24 = 0i64;
      }
      this->m_threads.m_data[i] = v24;
    }
  }
}

// File Line: 46
// RVA: 0xCE4620
void __fastcall hkgpJobQueue::~hkgpJobQueue(hkgpJobQueue *this)
{
  int i; // esi
  int j; // edi
  int v4; // edi
  __int64 v5; // rsi
  hkThread *v6; // rbp
  _QWORD **Value; // rax
  hkSemaphore *m_newJobEvent; // rdi
  _QWORD **v9; // rax
  hkSemaphore *m_endJobEvent; // rdi
  _QWORD **v11; // rax
  hkSemaphore *m_endThreadEvent; // rdi
  _QWORD **v13; // rax
  hkCriticalSection *m_jobsLock; // rdi
  _QWORD **v15; // rax
  int m_capacityAndFlags; // r8d
  int v17; // r8d

  if ( this->m_threads.m_size > 1 )
  {
    EnterCriticalSection(&this->m_jobsLock->m_section);
    for ( i = 0; i < this->m_threads.m_size; ++this->m_jobs.m_size )
    {
      if ( this->m_jobs.m_size == (this->m_jobs.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_jobs.m_data, 8);
      ++i;
      this->m_jobs.m_data[this->m_jobs.m_size] = (hkgpJobQueue::IJob *)1;
    }
    LeaveCriticalSection(&this->m_jobsLock->m_section);
    hkSemaphore::release(this->m_newJobEvent, this->m_threads.m_size);
    hkgpJobQueue::waitForCompletion(this);
    for ( j = 0; j < this->m_threads.m_size; ++j )
      hkSemaphore::acquire(this->m_endThreadEvent);
  }
  v4 = 0;
  if ( this->m_threads.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = this->m_threads.m_data[v5];
      if ( v6 )
      {
        hkThread::~hkThread(this->m_threads.m_data[v5]);
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkThread *, __int64))(*Value[11] + 16i64))(Value[11], v6, 16i64);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_threads.m_size );
  }
  m_newJobEvent = this->m_newJobEvent;
  if ( m_newJobEvent )
  {
    hkSemaphore::~hkSemaphore(m_newJobEvent);
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*v9[11] + 16i64))(v9[11], m_newJobEvent, 8i64);
  }
  m_endJobEvent = this->m_endJobEvent;
  if ( m_endJobEvent )
  {
    hkSemaphore::~hkSemaphore(this->m_endJobEvent);
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*v11[11] + 16i64))(v11[11], m_endJobEvent, 8i64);
  }
  m_endThreadEvent = this->m_endThreadEvent;
  if ( m_endThreadEvent )
  {
    hkSemaphore::~hkSemaphore(this->m_endThreadEvent);
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*v13[11] + 16i64))(v13[11], m_endThreadEvent, 8i64);
  }
  m_jobsLock = this->m_jobsLock;
  if ( m_jobsLock )
  {
    DeleteCriticalSection(&this->m_jobsLock->m_section);
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, __int64))(*v15[11] + 16i64))(v15[11], m_jobsLock, 40i64);
  }
  m_capacityAndFlags = this->m_jobs.m_capacityAndFlags;
  this->m_jobs.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_jobs.m_data,
      8 * m_capacityAndFlags);
  this->m_jobs.m_data = 0i64;
  this->m_jobs.m_capacityAndFlags = 0x80000000;
  v17 = this->m_threads.m_capacityAndFlags;
  this->m_threads.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_threads.m_data,
      8 * v17);
  this->m_threads.m_capacityAndFlags = 0x80000000;
  this->m_threads.m_data = 0i64;
}

// File Line: 74
// RVA: 0xCE48E0
void __fastcall hkgpJobQueue::push(hkgpJobQueue *this, hkgpJobQueue::IJob *job)
{
  if ( this->m_threads.m_size <= 1 )
  {
    job->vfptr->run(job);
    job->vfptr->__vecDelDtor(job, 1i64);
  }
  else
  {
    EnterCriticalSection(&this->m_jobsLock->m_section);
    if ( this->m_jobs.m_size == (this->m_jobs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_jobs.m_data, 8);
    this->m_jobs.m_data[this->m_jobs.m_size++] = job;
    LeaveCriticalSection(&this->m_jobsLock->m_section);
    hkSemaphore::release(this->m_newJobEvent, 1);
  }
}

// File Line: 91
// RVA: 0xCE4880
void __fastcall hkgpJobQueue::waitForCompletion(hkgpJobQueue *this)
{
  bool v2; // di

  if ( this->m_threads.m_size > 1 )
  {
    while ( 1 )
    {
      EnterCriticalSection(&this->m_jobsLock->m_section);
      v2 = this->m_numPendings || this->m_jobs.m_size;
      LeaveCriticalSection(&this->m_jobsLock->m_section);
      if ( !v2 )
        break;
      hkSemaphore::acquire(this->m_endJobEvent);
    }
  }
}

// File Line: 114
// RVA: 0xCE4990
void __fastcall hkgpJobQueue::threadMain(hkgpJobQueue *this)
{
  hkgpJobQueue::IJob *v2; // rdi

  while ( 1 )
  {
    hkSemaphore::acquire(this->m_newJobEvent);
    v2 = 0i64;
    EnterCriticalSection(&this->m_jobsLock->m_section);
    if ( this->m_jobs.m_size )
    {
      v2 = this->m_jobs.m_data[this->m_jobs.m_size - 1];
      ++this->m_numPendings;
      if ( --this->m_jobs.m_size )
        hkSemaphore::release(this->m_newJobEvent, 1);
    }
    LeaveCriticalSection(&this->m_jobsLock->m_section);
    if ( v2 )
    {
      if ( v2 != (hkgpJobQueue::IJob *)1 )
      {
        v2->vfptr->run(v2);
        v2->vfptr->__vecDelDtor(v2, 1u);
      }
      EnterCriticalSection(&this->m_jobsLock->m_section);
      --this->m_numPendings;
      if ( this->m_jobs.m_size )
        hkSemaphore::release(this->m_newJobEvent, 1);
      LeaveCriticalSection(&this->m_jobsLock->m_section);
      hkSemaphore::release(this->m_endJobEvent, 1);
      if ( v2 == (hkgpJobQueue::IJob *)1 )
        break;
    }
  }
  hkSemaphore::release(this->m_endJobEvent, 1);
  hkSemaphore::release(this->m_endThreadEvent, 1);
}

// File Line: 149
// RVA: 0xCE4A90
void *__fastcall hkgpJobQueue::threadStart(hkgpJobQueue *arg)
{
  hkMemorySystem *Instance; // rax
  hkMemorySystem *v3; // rax
  hkMemoryRouter memoryRouter; // [rsp+20h] [rbp-88h] BYREF
  hkResult result; // [rsp+B8h] [rbp+10h] BYREF

  hkMemoryRouter::hkMemoryRouter(&memoryRouter);
  Instance = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkMemoryRouter *, const char *, __int64))Instance->vfptr->threadInit)(
    Instance,
    &memoryRouter,
    "hkgpJobsQueue",
    3i64);
  hkBaseSystem::initThread(&result, &memoryRouter);
  hkgpJobQueue::threadMain(arg);
  hkBaseSystem::quitThread(&result);
  v3 = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkMemoryRouter *, __int64))v3->vfptr->threadQuit)(v3, &memoryRouter, 3i64);
  hkMemoryAllocator::~hkMemoryAllocator(&memoryRouter.m_stack);
  return 0i64;
}

