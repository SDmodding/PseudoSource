// File Line: 17
// RVA: 0xCE4400
void __fastcall hkgpJobQueue::hkgpJobQueue(hkgpJobQueue *this, int numThreads)
{
  __int64 v2; // rsi
  hkgpJobQueue *v3; // rbx
  _QWORD **v4; // rax
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
  int v18; // er9
  int v19; // edx
  __int64 i; // rdi
  _QWORD **v21; // rax
  hkThread *v22; // rax
  hkThread *v23; // rax
  hkThread *v24; // rcx
  hkHardwareInfo info; // [rsp+58h] [rbp+10h]

  this->m_threads.m_capacityAndFlags = -2147483640;
  this->m_threads.m_data = this->m_threads.m_storage;
  this->m_threads.m_size = 0;
  LODWORD(v2) = numThreads;
  this->m_jobs.m_data = 0i64;
  this->m_jobs.m_size = 0;
  this->m_jobs.m_capacityAndFlags = 2147483648;
  v3 = this;
  if ( numThreads <= 0 )
  {
    hkGetHardwareInfo(&info);
    LODWORD(v2) = info;
  }
  v3->m_numPendings = 0;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkCriticalSection *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 40i64);
  if ( v5 )
    hkCriticalSection::hkCriticalSection(v5, 0);
  else
    v6 = 0i64;
  v3->m_jobsLock = v6;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 8i64);
  if ( v8 )
    hkSemaphore::hkSemaphore(v8, 0, 1000, 0);
  else
    v9 = 0i64;
  v3->m_newJobEvent = v9;
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 8i64);
  if ( v11 )
    hkSemaphore::hkSemaphore(v11, 0, 1000, 0);
  else
    v12 = 0i64;
  v3->m_endJobEvent = v12;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 8i64);
  if ( v14 )
    hkSemaphore::hkSemaphore(v14, 0, 1000, 0);
  else
    v15 = 0i64;
  v3->m_endThreadEvent = v15;
  v16 = v3->m_threads.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < (signed int)v2 )
  {
    v17 = 2 * v16;
    v18 = v2;
    if ( (signed int)v2 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve((hkResult *)&info, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v18, 8);
  }
  v19 = v2 - v3->m_threads.m_size;
  if ( v19 > 0 )
    memset(&v3->m_threads.m_data[v3->m_threads.m_size], 0, 8i64 * v19);
  v3->m_threads.m_size = v2;
  if ( (signed int)v2 > 1 )
  {
    v2 = (signed int)v2;
    for ( i = 0i64; i < v2; ++i )
    {
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v22 = (hkThread *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 16i64);
      if ( v22 )
      {
        hkThread::hkThread(v22);
        v24 = v23;
      }
      else
      {
        v24 = 0i64;
      }
      v3->m_threads.m_data[i] = v24;
      hkThread::startThread(
        v3->m_threads.m_data[i],
        (hkResult *)&info,
        hkgpJobQueue::threadStart,
        v3,
        &customWorldMapCaption,
        0);
    }
  }
}

// File Line: 46
// RVA: 0xCE4620
void __fastcall hkgpJobQueue::~hkgpJobQueue(hkgpJobQueue *this)
{
  hkgpJobQueue *v1; // rbx
  int i; // esi
  int j; // edi
  int v4; // edi
  __int64 v5; // rsi
  hkThread *v6; // rbp
  _QWORD **v7; // rax
  hkSemaphore *v8; // rdi
  _QWORD **v9; // rax
  hkSemaphore *v10; // rdi
  _QWORD **v11; // rax
  hkSemaphore *v12; // rdi
  _QWORD **v13; // rax
  hkCriticalSection *v14; // rdi
  _QWORD **v15; // rax
  int v16; // er8
  int v17; // er8

  v1 = this;
  if ( this->m_threads.m_size > 1 )
  {
    EnterCriticalSection(&this->m_jobsLock->m_section);
    for ( i = 0; i < v1->m_threads.m_size; ++v1->m_jobs.m_size )
    {
      if ( v1->m_jobs.m_size == (v1->m_jobs.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_jobs, 8);
      ++i;
      v1->m_jobs.m_data[v1->m_jobs.m_size] = (hkgpJobQueue::IJob *)1;
    }
    LeaveCriticalSection(&v1->m_jobsLock->m_section);
    hkSemaphore::release(v1->m_newJobEvent, v1->m_threads.m_size);
    hkgpJobQueue::waitForCompletion(v1);
    for ( j = 0; j < v1->m_threads.m_size; ++j )
      hkSemaphore::acquire(v1->m_endThreadEvent);
  }
  v4 = 0;
  if ( v1->m_threads.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v1->m_threads.m_data[v5];
      if ( v6 )
      {
        hkThread::~hkThread(v1->m_threads.m_data[v5]);
        v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkThread *, signed __int64))(*v7[11] + 16i64))(v7[11], v6, 16i64);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v1->m_threads.m_size );
  }
  v8 = v1->m_newJobEvent;
  if ( v8 )
  {
    hkSemaphore::~hkSemaphore(v8);
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v9[11] + 16i64))(v9[11], v8, 8i64);
  }
  v10 = v1->m_endJobEvent;
  if ( v10 )
  {
    hkSemaphore::~hkSemaphore(v1->m_endJobEvent);
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v11[11] + 16i64))(v11[11], v10, 8i64);
  }
  v12 = v1->m_endThreadEvent;
  if ( v12 )
  {
    hkSemaphore::~hkSemaphore(v1->m_endThreadEvent);
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v13[11] + 16i64))(v13[11], v12, 8i64);
  }
  v14 = v1->m_jobsLock;
  if ( v14 )
  {
    DeleteCriticalSection(&v1->m_jobsLock->m_section);
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkCriticalSection *, signed __int64))(*v15[11] + 16i64))(v15[11], v14, 40i64);
  }
  v16 = v1->m_jobs.m_capacityAndFlags;
  v1->m_jobs.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_jobs.m_data,
      8 * v16);
  v1->m_jobs.m_data = 0i64;
  v1->m_jobs.m_capacityAndFlags = 2147483648;
  v17 = v1->m_threads.m_capacityAndFlags;
  v1->m_threads.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_threads.m_data,
      8 * v17);
  v1->m_threads.m_capacityAndFlags = 2147483648;
  v1->m_threads.m_data = 0i64;
}

// File Line: 74
// RVA: 0xCE48E0
void __fastcall hkgpJobQueue::push(hkgpJobQueue *this, hkgpJobQueue::IJob *job)
{
  hkgpJobQueue::IJob *v2; // rdi
  hkgpJobQueue *v3; // rsi

  v2 = job;
  v3 = this;
  if ( this->m_threads.m_size <= 1 )
  {
    job->vfptr->run(job);
    v2->vfptr->__vecDelDtor(v2, 1u);
  }
  else
  {
    EnterCriticalSection(&this->m_jobsLock->m_section);
    if ( v3->m_jobs.m_size == (v3->m_jobs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_jobs, 8);
    v3->m_jobs.m_data[v3->m_jobs.m_size++] = v2;
    LeaveCriticalSection(&v3->m_jobsLock->m_section);
    hkSemaphore::release(v3->m_newJobEvent, 1);
  }
}

// File Line: 91
// RVA: 0xCE4880
void __fastcall hkgpJobQueue::waitForCompletion(hkgpJobQueue *this)
{
  hkgpJobQueue *v1; // rbx
  bool v2; // di

  v1 = this;
  if ( this->m_threads.m_size > 1 )
  {
    while ( 1 )
    {
      EnterCriticalSection(&v1->m_jobsLock->m_section);
      v2 = v1->m_numPendings || v1->m_jobs.m_size;
      LeaveCriticalSection(&v1->m_jobsLock->m_section);
      if ( !v2 )
        break;
      hkSemaphore::acquire(v1->m_endJobEvent);
    }
  }
}

// File Line: 114
// RVA: 0xCE4990
void __fastcall hkgpJobQueue::threadMain(hkgpJobQueue *this)
{
  hkgpJobQueue *v1; // rbx
  hkgpJobQueue::IJob *v2; // rdi

  v1 = this;
  while ( 1 )
  {
    hkSemaphore::acquire(v1->m_newJobEvent);
    v2 = 0i64;
    EnterCriticalSection(&v1->m_jobsLock->m_section);
    if ( v1->m_jobs.m_size )
    {
      v2 = v1->m_jobs.m_data[v1->m_jobs.m_size - 1];
      ++v1->m_numPendings;
      if ( --v1->m_jobs.m_size )
        hkSemaphore::release(v1->m_newJobEvent, 1);
    }
    LeaveCriticalSection(&v1->m_jobsLock->m_section);
    if ( v2 )
    {
      if ( v2 != (hkgpJobQueue::IJob *)1 )
      {
        v2->vfptr->run(v2);
        v2->vfptr->__vecDelDtor(v2, 1u);
      }
      EnterCriticalSection(&v1->m_jobsLock->m_section);
      --v1->m_numPendings;
      if ( v1->m_jobs.m_size )
        hkSemaphore::release(v1->m_newJobEvent, 1);
      LeaveCriticalSection(&v1->m_jobsLock->m_section);
      hkSemaphore::release(v1->m_endJobEvent, 1);
      if ( v2 == (hkgpJobQueue::IJob *)1 )
        break;
    }
  }
  hkSemaphore::release(v1->m_endJobEvent, 1);
  hkSemaphore::release(v1->m_endThreadEvent, 1);
}

// File Line: 149
// RVA: 0xCE4A90
void *__fastcall hkgpJobQueue::threadStart(void *arg)
{
  hkgpJobQueue *v1; // rbx
  hkMemorySystem *v2; // rax
  hkMemorySystem *v3; // rax
  hkMemoryRouter memoryRouter; // [rsp+20h] [rbp-88h]
  hkResult result; // [rsp+B8h] [rbp+10h]

  v1 = (hkgpJobQueue *)arg;
  hkMemoryRouter::hkMemoryRouter(&memoryRouter);
  v2 = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkMemoryRouter *, const char *, signed __int64))v2->vfptr->threadInit)(
    v2,
    &memoryRouter,
    "hkgpJobsQueue",
    3i64);
  hkBaseSystem::initThread(&result, &memoryRouter);
  hkgpJobQueue::threadMain(v1);
  hkBaseSystem::quitThread(&result);
  v3 = hkMemorySystem::getInstance();
  ((void (__fastcall *)(hkMemorySystem *, hkMemoryRouter *, signed __int64))v3->vfptr->threadQuit)(
    v3,
    &memoryRouter,
    3i64);
  hkMemoryAllocator::~hkMemoryAllocator((hkMemoryAllocator *)&memoryRouter.m_stack.vfptr);
  return 0i64;
}

