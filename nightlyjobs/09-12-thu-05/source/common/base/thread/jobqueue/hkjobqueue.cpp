// File Line: 68
// RVA: 0xC63470
void __fastcall hkJobQueueHwSetup::hkJobQueueHwSetup(hkJobQueueHwSetup *this)
{
  int m_numThreads; // eax
  hkHardwareInfo info; // [rsp+30h] [rbp+8h] BYREF

  this->m_threadIdsSharingCaches.m_data = 0i64;
  this->m_threadIdsSharingCaches.m_size = 0;
  this->m_threadIdsSharingCaches.m_capacityAndFlags = 0x80000000;
  this->m_cellRules = PPU_CANNOT_TAKE_SPU_TASKS;
  hkGetHardwareInfo(&info);
  m_numThreads = info.m_numThreads;
  this->m_spuSchedulePolicy = SEMAPHORE_WAIT_OR_SWITCH_ELF;
  this->m_numCpuThreads = m_numThreads;
  this->m_noSpu.m_bool = 1;
}

// File Line: 83
// RVA: 0xC64C90
__int64 __fastcall defaultPopDispatchFunc(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntry *jobOut)
{
  return ((__int64 (__fastcall *)(hkJobQueue *, hkJobQueue::DynamicData *, hkJobQueue::JobQueueEntry *, hkJobQueue::JobQueueEntry *))queue->m_jobFuncs[(unsigned __int8)jobIn->m_jobType.m_storage].m_popJobFunc)(
           queue,
           data,
           jobIn,
           jobOut);
}

// File Line: 88
// RVA: 0xC64CB0
__int64 __fastcall defaultFinishDispatchFunc(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreatedOut)
{
  return ((__int64 (__fastcall *)(hkJobQueue *, hkJobQueue::DynamicData *, hkJobQueue::JobQueueEntry *, hkJobQueue::JobQueueEntryInput *))queue->m_jobFuncs[(unsigned __int8)jobIn->m_jobType.m_storage].m_finishJobFunc)(
           queue,
           data,
           jobIn,
           newJobCreatedOut);
}

// File Line: 97
// RVA: 0xC64CD0
__int64 __fastcall hkDefaultPopJobFunc(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntry *jobOut)
{
  return 0i64;
}

// File Line: 106
// RVA: 0xC64CE0
__int64 __fastcall hkDefaultFinishJobFunc(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreatedOut)
{
  return 1i64;
}

// File Line: 119
// RVA: 0xC634C0
void __fastcall hkJobQueue::hkJobQueue(hkJobQueue *this, hkJobQueueCinfo *cinfo)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  hkJobQueue::DynamicData *v6; // rbp
  hkQueue<hkpRigidBody *> *v7; // rdi
  int i; // esi
  int v9; // r9d
  int v10; // edx
  __int64 v11; // r8
  hkJobQueue::hkJobHandlerFuncs *m_jobFuncs; // rcx

  hkCriticalSection::hkCriticalSection(&this->m_criticalSection, 0);
  this->m_numJobTypes = cinfo->m_maxNumJobTypes;
  hkJobQueueHwSetup::hkJobQueueHwSetup(&this->m_hwSetup);
  this->m_customJobSetup.m_data = 0i64;
  this->m_customJobSetup.m_size = 0;
  this->m_customJobSetup.m_capacityAndFlags = 0x80000000;
  this->m_externalJobProfiler = 0i64;
  TlsSetValue(hkThreadNumber.m_slotID, 0i64);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 672i64);
  v6 = (hkJobQueue::DynamicData *)v5;
  if ( v5 )
  {
    v7 = (hkQueue<hkpRigidBody *> *)(v5 + 64);
    for ( i = 24; i >= 0; --i )
      hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v7++);
  }
  else
  {
    v6 = 0i64;
  }
  this->m_data = v6;
  this->m_queryRulesAreUpdated.m_bool = 0;
  v6->m_outOfMemory.m_bool = 0;
  this->m_data->m_waitPolicy = WAIT_UNTIL_ALL_WORK_COMPLETE;
  hkJobQueueHwSetup::operator=(&this->m_hwSetup, &cinfo->m_jobQueueHwSetup);
  this->m_data->m_masterThreadFinishingFlags = 0;
  v9 = 0;
  v10 = 1;
  if ( this->m_numJobTypes > 0 )
  {
    v11 = 0i64;
    m_jobFuncs = this->m_jobFuncs;
    do
    {
      m_jobFuncs->m_numProcessJobFuncs = 0;
      m_jobFuncs->m_processJobFuncs = 0i64;
      m_jobFuncs->m_popJobFunc = hkDefaultPopJobFunc;
      m_jobFuncs->m_finishJobFunc = hkDefaultFinishJobFunc;
      ++v9;
      this->m_data->m_numActiveJobs[v11] = 0;
      ++m_jobFuncs;
      this->m_data->m_masterThreadFinishingFlags |= v10;
      v10 = __ROL4__(v10, 1);
      ++v11;
    }
    while ( v9 < this->m_numJobTypes );
  }
  this->m_numQueueSemaphores = 0;
  this->m_threadPool = 0i64;
  this->m_popJobFunc = defaultPopDispatchFunc;
  this->m_finishJobFunc = defaultFinishDispatchFunc;
  this->m_queueSemaphores[0] = 0i64;
  this->m_queueSemaphores[1] = 0i64;
  this->m_queueSemaphores[2] = 0i64;
  this->m_queueSemaphores[3] = 0i64;
  this->m_queueSemaphores[4] = 0i64;
  hkJobQueue::updateJobQueryRules(this);
}

// File Line: 188
// RVA: 0xC63680
void __fastcall hkJobQueue::~hkJobQueue(hkJobQueue *this)
{
  hkJobQueue::DynamicData *m_data; // rsi
  hkQueue<hkJobQueue::JobQueueEntry> *v3; // rbx
  int i; // edi
  _QWORD **Value; // rax
  hkSemaphore **m_queueSemaphores; // rbx
  __int64 v7; // rsi
  hkSemaphore *v8; // rdi
  _QWORD **v9; // rax
  int m_capacityAndFlags; // eax

  m_data = this->m_data;
  if ( m_data )
  {
    v3 = &m_data->m_jobQueue[25];
    for ( i = 24; i >= 0; --i )
      hkQueue<hkJobQueue::JobQueueEntry>::~hkQueue<hkJobQueue::JobQueueEntry>(--v3);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkJobQueue::DynamicData *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_data,
      672i64);
  }
  if ( this->m_queryRulesAreUpdated.m_bool )
  {
    m_queueSemaphores = this->m_queueSemaphores;
    v7 = 5i64;
    do
    {
      v8 = *m_queueSemaphores;
      if ( *m_queueSemaphores )
      {
        hkSemaphore::~hkSemaphore(*m_queueSemaphores);
        v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*v9[11] + 16i64))(v9[11], v8, 8i64);
      }
      ++m_queueSemaphores;
      --v7;
    }
    while ( v7 );
  }
  m_capacityAndFlags = this->m_customJobSetup.m_capacityAndFlags;
  this->m_customJobSetup.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_customJobSetup.m_data,
      12 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_customJobSetup.m_data = 0i64;
  this->m_customJobSetup.m_capacityAndFlags = 0x80000000;
  hkJobQueueHwSetup::~hkJobQueueHwSetup(&this->m_hwSetup);
  DeleteCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 216
// RVA: 0xC637B0
void __fastcall hkJobQueue::registerJobWithCpuThread(hkJobQueue *this, hkJobType jobType, char subType, int threadId)
{
  __int64 v8; // r10
  hkJobQueue::CustomJobTypeSetup *m_data; // rax
  hkArray<hkJobQueue::CustomJobTypeSetup,hkContainerHeapAllocator> *p_m_customJobSetup; // rbx
  __int64 m_size; // rdx
  __int64 v12; // r8

  if ( this->m_customJobSetup.m_size < 1 )
  {
LABEL_8:
    p_m_customJobSetup = &this->m_customJobSetup;
    if ( this->m_customJobSetup.m_size == (this->m_customJobSetup.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_customJobSetup->m_data, 12);
    m_size = p_m_customJobSetup->m_size;
    v12 = (__int64)&p_m_customJobSetup->m_data[m_size];
    p_m_customJobSetup->m_size = m_size + 1;
    *(_DWORD *)v12 = jobType;
    *(_BYTE *)(v12 + 4) = subType;
    *(_DWORD *)(v12 + 8) = threadId;
    hkJobQueue::updateJobQueryRules(this);
  }
  else
  {
    v8 = 0i64;
    m_data = this->m_customJobSetup.m_data;
    while ( m_data->m_jobType != jobType || m_data->m_jobSubType != subType || m_data->m_threadId != threadId )
    {
      ++v8;
      ++m_data;
      if ( v8 >= this->m_customJobSetup.m_size )
        goto LABEL_8;
    }
  }
}

// File Line: 239
// RVA: 0xC63A20
void __fastcall hkJobQueue::updateJobQueryRules(hkJobQueue *this)
{
  int m_size; // ebp
  int v3; // ecx
  int v4; // esi
  int m_cpuCacheQueuesBegin; // edi
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  char *m_cpuThreadIndexToSemaphoreIndex; // rax
  int i; // r11d
  int v11; // r9d
  __int64 v12; // r8
  int v13; // edx
  char *v14; // rcx
  int j; // r8d
  int v16; // edx
  char *v17; // rcx
  int k; // edx
  char v19; // al
  int m; // eax
  int n; // edx
  char v22; // al
  int ii; // r11d
  _RTL_CRITICAL_SECTION_DEBUG **v24; // r10
  __int64 v25; // r8
  char v26; // dl
  __int64 m_threadId; // rcx
  __int64 v28; // r8
  char *v29; // r9
  char *v30; // rdx
  int v31; // r8d
  int m_numCpuThreads; // ecx
  int m_cpuTypesQueuesBegin; // r14d
  char *v34; // rax
  __int64 v35; // rsi
  hkSemaphore **v36; // rdi
  hkSemaphore *v37; // rbp
  _QWORD **Value; // rax
  int v39; // edi
  __int64 v40; // r14
  hkSemaphore **m_queueSemaphores; // rsi
  _QWORD **v42; // rax
  hkSemaphore *v43; // rax
  hkSemaphore *v44; // rax

  m_size = this->m_hwSetup.m_threadIdsSharingCaches.m_size;
  v3 = this->m_customJobSetup.m_size;
  v4 = 1;
  this->m_numCustomJobs = v3;
  if ( !m_size )
    m_size = 1;
  if ( this->m_hwSetup.m_noSpu.m_bool )
    this->m_cpuCacheQueuesBegin = 0;
  else
    this->m_cpuCacheQueuesBegin = this->m_numJobTypes;
  m_cpuCacheQueuesBegin = this->m_cpuCacheQueuesBegin;
  v6 = m_cpuCacheQueuesBegin + m_size + v3;
  this->m_cpuCustomQueuesBegin = m_cpuCacheQueuesBegin + m_size;
  this->m_cpuTypesQueuesBegin = v6;
  this->m_numJobQueues = this->m_numJobTypes + v6;
  while ( m_cpuCacheQueuesBegin < this->m_cpuCustomQueuesBegin )
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(&this->m_data->m_jobQueue[m_cpuCacheQueuesBegin++], 128);
  this->m_cpuSemaphoreBegin = this->m_cpuCacheQueuesBegin;
  this->m_directMapSemaphoreEnd = this->m_cpuTypesQueuesBegin;
  v7 = this->m_hwSetup.m_threadIdsSharingCaches.m_size == 0;
  if ( this->m_hwSetup.m_threadIdsSharingCaches.m_size > 0 )
  {
    v8 = 0;
    if ( this->m_hwSetup.m_numCpuThreads > 0 )
    {
      m_cpuThreadIndexToSemaphoreIndex = this->m_cpuThreadIndexToSemaphoreIndex;
      do
      {
        *m_cpuThreadIndexToSemaphoreIndex = -1;
        ++v8;
        ++m_cpuThreadIndexToSemaphoreIndex;
      }
      while ( v8 < this->m_hwSetup.m_numCpuThreads );
    }
    for ( i = 0; i < this->m_hwSetup.m_threadIdsSharingCaches.m_size; ++i )
    {
      v11 = 0;
      if ( this->m_hwSetup.m_threadIdsSharingCaches.m_data[i].m_size > 0 )
      {
        v12 = 0i64;
        do
        {
          ++v11;
          this->m_cpuThreadIndexToSemaphoreIndex[this->m_hwSetup.m_threadIdsSharingCaches.m_data[i].m_data[v12++]] = LOBYTE(this->m_cpuCacheQueuesBegin) + i;
        }
        while ( v11 < this->m_hwSetup.m_threadIdsSharingCaches.m_data[i].m_size );
      }
    }
    v7 = this->m_hwSetup.m_threadIdsSharingCaches.m_size == 0;
  }
  if ( v7 )
  {
    v13 = 0;
    if ( this->m_hwSetup.m_numCpuThreads > 0 )
    {
      v14 = this->m_cpuThreadIndexToSemaphoreIndex;
      do
      {
        ++v13;
        *v14++ = this->m_cpuCacheQueuesBegin;
      }
      while ( v13 < this->m_hwSetup.m_numCpuThreads );
    }
  }
  for ( j = 0; j < m_size; *v17 = -1 )
  {
    v16 = 0;
    v17 = &this->m_nextQueueToGet[j][27 * this->m_cpuCacheQueuesBegin + 1];
    for ( this->m_nextQueueToGet[j][27 * this->m_cpuCacheQueuesBegin] = LOBYTE(this->m_cpuCacheQueuesBegin) + j;
          v16 < this->m_hwSetup.m_threadIdsSharingCaches.m_size;
          ++v16 )
    {
      if ( j != v16 )
        *v17++ = LOBYTE(this->m_cpuCacheQueuesBegin) + v16;
    }
    for ( k = 0; k < this->m_numJobTypes; *(v17 - 1) = LOBYTE(this->m_cpuTypesQueuesBegin) + v19 )
    {
      v19 = k++;
      ++v17;
    }
    if ( this->m_hwSetup.m_cellRules == PPU_CAN_TAKE_SPU_TASKS )
    {
      for ( m = 0; m < this->m_numJobTypes; ++v17 )
        *v17 = m++;
    }
    for ( n = 0; n < this->m_numCustomJobs; *(v17 - 1) = LOBYTE(this->m_cpuCustomQueuesBegin) + v22 )
    {
      v22 = n++;
      ++v17;
    }
    ++j;
  }
  for ( ii = 0; ii < this->m_numCustomJobs; *v29 = -1 )
  {
    v24 = &this->m_criticalSection.m_section.DebugInfo + ii;
    v25 = ii;
    *((_DWORD *)v24 + 21) = this->m_customJobSetup.m_data[v25].m_jobType;
    *((_BYTE *)v24 + 88) = this->m_customJobSetup.m_data[v25].m_jobSubType;
    v26 = LOBYTE(this->m_cpuCustomQueuesBegin) + ii;
    *((_BYTE *)v24 + 89) = v26;
    m_threadId = this->m_customJobSetup.m_data[v25].m_threadId;
    v28 = this->m_cpuThreadIndexToSemaphoreIndex[m_threadId];
    this->m_cpuThreadIndexToSemaphoreIndex[m_threadId] = v26;
    LODWORD(m_threadId) = ii + this->m_cpuCustomQueuesBegin;
    v29 = &this->m_nextQueueToGet[(int)m_threadId][1];
    this->m_nextQueueToGet[(int)m_threadId][0] = LOBYTE(this->m_cpuCustomQueuesBegin) + ii;
    if ( this->m_nextQueueToGet[v28][0] != -1 )
    {
      v30 = this->m_nextQueueToGet[v28];
      do
      {
        v31 = *v30;
        if ( v31 != *((unsigned __int8 *)v24 + 89) )
          *v29++ = v31;
        ++v30;
      }
      while ( *v30 != -1 );
    }
    ++ii;
  }
  m_numCpuThreads = this->m_hwSetup.m_numCpuThreads;
  m_cpuTypesQueuesBegin = this->m_cpuTypesQueuesBegin;
  this->m_masterThreadQueue = this->m_cpuThreadIndexToSemaphoreIndex[0];
  if ( m_numCpuThreads > 1 )
  {
    v34 = &this->m_cpuThreadIndexToSemaphoreIndex[1];
    while ( *v34 != this->m_cpuThreadIndexToSemaphoreIndex[0] )
    {
      ++v4;
      ++v34;
      if ( v4 >= m_numCpuThreads )
        goto LABEL_48;
    }
    this->m_cpuThreadIndexToSemaphoreIndex[0] = m_cpuTypesQueuesBegin++;
  }
LABEL_48:
  if ( this->m_queryRulesAreUpdated.m_bool )
  {
    v35 = this->m_cpuCacheQueuesBegin;
    if ( (int)v35 < this->m_numQueueSemaphores )
    {
      v36 = &this->m_queueSemaphores[v35];
      do
      {
        v37 = *v36;
        if ( *v36 )
        {
          hkSemaphore::~hkSemaphore(*v36);
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*Value[11] + 16i64))(Value[11], v37, 8i64);
        }
        *v36 = 0i64;
        LODWORD(v35) = v35 + 1;
        ++v36;
      }
      while ( (int)v35 < this->m_numQueueSemaphores );
    }
  }
  this->m_numQueueSemaphores = m_cpuTypesQueuesBegin;
  v39 = 0;
  if ( m_cpuTypesQueuesBegin > 0 )
  {
    v40 = 25i64;
    m_queueSemaphores = this->m_queueSemaphores;
    do
    {
      this->m_data->m_numActiveJobs[v40] = 0;
      if ( v39 >= this->m_cpuCacheQueuesBegin )
      {
        v42 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v43 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v42[11] + 8i64))(v42[11], 8i64);
        if ( v43 )
          hkSemaphore::hkSemaphore(v43, 0, 1000, 0);
        else
          v44 = 0i64;
        *m_queueSemaphores = v44;
      }
      ++v39;
      ++v40;
      ++m_queueSemaphores;
    }
    while ( v39 < this->m_numQueueSemaphores );
  }
  this->m_queryRulesAreUpdated.m_bool = 1;
}

// File Line: 461
// RVA: 0xC63FA0
void __fastcall hkJobQueue::setQueueCapacityForJobType(hkJobQueue *this, hkJobType jobType, int queueCapacity)
{
  hkJobQueue::DynamicData *v6; // rdi
  int v7; // r14d
  char *p_m_queueId; // r15
  __int64 v9; // rbx
  int m_capacity; // eax
  int v11; // eax
  int v12; // edi
  _QWORD **Value; // rax
  hkJobQueue::JobQueueEntry *v14; // rax
  hkJobQueue::JobQueueEntry *v15; // r13
  hkJobQueue::JobQueueEntry *m_data; // rcx
  int m_elementsInUse; // r8d
  int m_tail; // esi
  __int64 m_head; // rdx
  int v20; // edi
  __int64 v21; // rcx
  hkJobQueue::JobQueueEntry *v22; // rdx
  hkJobQueue::JobQueueEntry *v23; // rcx
  unsigned int v24; // r8d
  int v25; // eax
  int v26; // esi
  hkJobQueue::JobQueueEntry *v27; // rdi
  _QWORD **v28; // rax
  int i; // ebx
  char dynamicDataStorage[672]; // [rsp+20h] [rbp-2D8h] BYREF
  hkJobQueue::DynamicData *v31; // [rsp+300h] [rbp+8h]
  int v32; // [rsp+308h] [rbp+10h]

  v6 = hkJobQueue::lockQueue(this, dynamicDataStorage);
  v31 = v6;
  hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(
    (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v6->m_jobQueue
                                         + 16 * jobType
                                         + 16 * this->m_cpuTypesQueuesBegin
                                         + 8 * jobType
                                         + 8 * this->m_cpuTypesQueuesBegin),
    queueCapacity);
  v7 = 0;
  if ( this->m_numCustomJobs > 0 )
  {
    p_m_queueId = &this->m_customJobs[0].m_queueId;
    do
    {
      v9 = (unsigned __int8)*p_m_queueId;
      m_capacity = v6->m_jobQueue[(unsigned __int8)*p_m_queueId].m_capacity;
      if ( m_capacity < queueCapacity )
      {
        v11 = 2 * m_capacity;
        v12 = queueCapacity;
        if ( v11 >= queueCapacity )
          v12 = v11;
        v32 = v12;
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (hkJobQueue::JobQueueEntry *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(
                                             Value[11],
                                             (unsigned int)(v12 << 8));
        v6 = v31;
        v15 = v14;
        if ( v14 )
        {
          m_data = v31->m_jobQueue[v9].m_data;
          if ( m_data )
          {
            m_elementsInUse = v31->m_jobQueue[v9].m_elementsInUse;
            if ( m_elementsInUse )
            {
              m_tail = v31->m_jobQueue[v9].m_tail;
              m_head = v31->m_jobQueue[v9].m_head;
              if ( m_tail > (int)m_head )
              {
                v24 = m_elementsInUse << 8;
                v22 = &m_data[m_head];
                v23 = v14;
              }
              else
              {
                v20 = v31->m_jobQueue[v9].m_capacity - m_head;
                hkString::memCpy(v14, &m_data[m_head], v20 << 8);
                v21 = v20;
                v6 = v31;
                v22 = v31->m_jobQueue[v9].m_data;
                v23 = &v15[v21];
                v24 = m_tail << 8;
              }
              hkString::memCpy(v23, v22, v24);
            }
            v25 = v6->m_jobQueue[v9].m_elementsInUse;
            v6->m_jobQueue[v9].m_head = 0;
            v6->m_jobQueue[v9].m_tail = v25;
          }
        }
        v26 = v6->m_jobQueue[v9].m_capacity;
        if ( v26 )
        {
          v27 = v6->m_jobQueue[v9].m_data;
          v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkJobQueue::JobQueueEntry *, _QWORD))(*v28[11] + 16i64))(
            v28[11],
            v27,
            (unsigned int)(v26 << 8));
          v6 = v31;
        }
        v6->m_jobQueue[v9].m_data = v15;
        v6->m_jobQueue[v9].m_capacity = v32;
      }
      ++v7;
      p_m_queueId += 8;
    }
    while ( v7 < this->m_numCustomJobs );
  }
  for ( i = this->m_cpuCacheQueuesBegin; i < this->m_cpuCustomQueuesBegin; ++i )
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(
      (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v6->m_jobQueue + 16 * i + 8 * i),
      queueCapacity);
  hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
}

// File Line: 486
// RVA: 0xC641B0
void __fastcall hkJobQueue::setQueueCapacityForCpuCache(hkJobQueue *this, int queueCapacity)
{
  ;
}

// File Line: 496
// RVA: 0xC64A00
void __fastcall hkJobQueue::setExternalProfiler(hkJobQueue *this, hkExternalJobProfiler *p)
{
  this->m_externalJobProfiler = p;
}

// File Line: 501
// RVA: 0xC641C0
hkJobQueue::JobStatus __fastcall hkJobQueue::processAllJobs(hkJobQueue *this, bool addTimers)
{
  hkJobQueue::JobStatus result; // eax
  __int64 m_storage; // rsi
  const char *v6; // rbx
  _QWORD *Value; // rax
  _QWORD *v8; // rdi
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  hkExternalJobProfiler *m_externalJobProfiler; // rcx
  hkJobQueue::JobStatus v12; // eax
  hkExternalJobProfiler *v13; // rcx
  hkJobQueue::JobStatus v14; // ebx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  hkJobQueue::JobQueueEntry job; // [rsp+20h] [rbp-118h] BYREF

  result = hkJobQueue::getNextJob(this, &job, WAIT_FOR_NEXT_JOB);
  if ( result == GOT_NEXT_JOB )
  {
    do
    {
      m_storage = (unsigned __int8)job.m_jobType.m_storage;
      switch ( job.m_jobType.m_storage )
      {
        case 0:
        case 1:
        case 0x12:
          v6 = "TtPhysics 2012";
          break;
        case 2:
          v6 = "TtCollision Query";
          break;
        case 3:
          v6 = "TtRayCast Query";
          break;
        case 4:
          v6 = "TtAnimation Sample and Combine";
          break;
        case 5:
          v6 = "TtAnimation Sample and Blend";
          break;
        case 6:
          v6 = "TtAnimation Mapping";
          break;
        case 7:
          v6 = "TtBehavior";
          break;
        case 8:
          v6 = "TtCloth";
          break;
        case 9:
        case 0xA:
          v6 = "TtPathfinding Jobs";
          break;
        case 0xB:
          v6 = "TtAI Dynamic Jobs";
          break;
        case 0xC:
          v6 = "TtLocalSteering Jobs";
          break;
        case 0xD:
          v6 = "TtAI Generation";
          break;
        case 0xE:
          v6 = "TtDestruction";
          break;
        case 0x10:
          v6 = "TtCharacter Proxy";
          break;
        case 0x11:
          v6 = "TtVehicle";
          break;
        case 0x13:
          v6 = "TtUserJob";
          break;
        default:
          v6 = "TtOther";
          break;
      }
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v8 = Value;
      if ( addTimers )
      {
        v9 = Value[1];
        if ( v9 < Value[3] )
        {
          *(_QWORD *)v9 = v6;
          v10 = __rdtsc();
          *(_DWORD *)(v9 + 8) = v10;
          v8[1] = v9 + 16;
        }
      }
      m_externalJobProfiler = this->m_externalJobProfiler;
      if ( m_externalJobProfiler )
        m_externalJobProfiler->vfptr->onStartJob(
          m_externalJobProfiler,
          (hkJobType)m_storage,
          (unsigned __int8)job.m_jobSubType);
      v12 = this->m_jobFuncs[m_storage].m_processJobFuncs[(unsigned __int8)job.m_jobSubType](this, &job);
      v13 = this->m_externalJobProfiler;
      v14 = v12;
      if ( v13 )
        v13->vfptr->onEndJob(v13, (hkJobType)m_storage);
      if ( addTimers )
      {
        v15 = v8[1];
        if ( v15 < v8[3] )
        {
          *(_QWORD *)v15 = "Et";
          v16 = __rdtsc();
          *(_DWORD *)(v15 + 8) = v16;
          v8[1] = v15 + 16;
        }
      }
    }
    while ( v14 == GOT_NEXT_JOB );
    return v14;
  }
  return result;
}

// File Line: 648
// RVA: 0xC64C00
__int64 __fastcall hkJobQueue::getQueueIndexForJob(hkJobQueue *this, hkJob *job)
{
  __int64 m_numCustomJobs; // r11
  int v3; // r10d
  __int64 v4; // r9
  char *i; // r8

  m_numCustomJobs = this->m_numCustomJobs;
  v3 = 0;
  v4 = 0i64;
  if ( m_numCustomJobs <= 0 )
    return this->m_cpuTypesQueuesBegin + (unsigned int)(unsigned __int8)job->m_jobType.m_storage;
  for ( i = &this->m_customJobs[0].m_jobSubType; job->m_jobType.m_storage != *(i - 4) || job->m_jobSubType != *i; i += 8 )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_numCustomJobs )
      return this->m_cpuTypesQueuesBegin + (unsigned int)(unsigned __int8)job->m_jobType.m_storage;
  }
  return (unsigned __int8)this->m_customJobs[v3].m_queueId;
}

// File Line: 686
// RVA: 0xC64C60
hkJobQueue::DynamicData *__fastcall hkJobQueue::lockQueue(hkJobQueue *this, char *dynamicDataStorage)
{
  EnterCriticalSection(&this->m_criticalSection.m_section);
  return this->m_data;
}

// File Line: 706
// RVA: 0xC64C80
// attributes: thunk
void __stdcall hkJobQueue::unlockQueue(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

// File Line: 722
// RVA: 0xC645A0
hkJobQueue::JobStatus __fastcall hkJobQueue::getNextJob(
        hkJobQueue *this,
        hkJobQueue::JobQueueEntry *job,
        hkJobQueue::WaitStatus waitStatus)
{
  return hkJobQueue::finishJobAndGetNextJob(this, 0i64, job, waitStatus);
}

// File Line: 727
// RVA: 0xC64A10
void __fastcall hkJobQueue::releaseOneWaitingThread(hkJobQueue *this, hkJobQueue::DynamicData *data)
{
  __int64 m_cpuSemaphoreBegin; // r8
  __int64 m_directMapSemaphoreEnd; // rbx
  char v4; // di
  __int64 v7; // r9
  unsigned __int16 *v8; // r10
  int *p_m_elementsInUse; // r11
  __int64 v10; // rcx
  __int64 m_numJobQueues; // r8
  int *v12; // rdx
  __int64 m_numQueueSemaphores; // rdx
  __int64 v14; // rax
  unsigned __int16 *i; // rcx

  m_cpuSemaphoreBegin = this->m_cpuSemaphoreBegin;
  m_directMapSemaphoreEnd = this->m_directMapSemaphoreEnd;
  v4 = 0;
  v7 = m_cpuSemaphoreBegin;
  if ( m_cpuSemaphoreBegin < m_directMapSemaphoreEnd )
  {
    v8 = &data->m_numThreadsWaiting[m_cpuSemaphoreBegin];
    p_m_elementsInUse = &data->m_jobQueue[m_cpuSemaphoreBegin].m_elementsInUse;
    do
    {
      if ( *p_m_elementsInUse )
      {
        v4 = 1;
        if ( *v8 )
          goto $releaseSemaphore;
      }
      ++v7;
      LODWORD(m_cpuSemaphoreBegin) = m_cpuSemaphoreBegin + 1;
      ++v8;
      p_m_elementsInUse += 6;
    }
    while ( v7 < m_directMapSemaphoreEnd );
  }
  v10 = (int)m_cpuSemaphoreBegin;
  m_numJobQueues = this->m_numJobQueues;
  if ( v10 >= m_numJobQueues )
  {
LABEL_10:
    if ( !v4 )
      return;
  }
  else
  {
    v12 = &data->m_jobQueue[v10].m_elementsInUse;
    while ( !*v12 )
    {
      ++v10;
      v12 += 6;
      if ( v10 >= m_numJobQueues )
        goto LABEL_10;
    }
  }
  m_cpuSemaphoreBegin = this->m_cpuSemaphoreBegin;
  m_numQueueSemaphores = this->m_numQueueSemaphores;
  v14 = m_cpuSemaphoreBegin;
  if ( m_cpuSemaphoreBegin < m_numQueueSemaphores )
  {
    for ( i = &data->m_numThreadsWaiting[m_cpuSemaphoreBegin]; !*i; ++i )
    {
      ++v14;
      LODWORD(m_cpuSemaphoreBegin) = m_cpuSemaphoreBegin + 1;
      if ( v14 >= m_numQueueSemaphores )
        return;
    }
$releaseSemaphore:
    --data->m_numThreadsWaiting[(int)m_cpuSemaphoreBegin];
    hkSemaphore::release(this->m_queueSemaphores[(int)m_cpuSemaphoreBegin], 1);
  }
}

// File Line: 806
// RVA: 0xC64B20
void __fastcall hkJobQueue::checkQueueAndReleaseOneWaitingThread(
        hkJobQueue *this,
        int queueIndex,
        hkJobQueue::DynamicData *data)
{
  __int64 v3; // r9
  __int16 *v4; // rdx
  __int16 v5; // ax

  if ( queueIndex < this->m_numQueueSemaphores
    && (v3 = queueIndex, v4 = &data->m_numActiveJobs[queueIndex], (v5 = v4[25]) != 0) )
  {
    v4[25] = v5 - 1;
    hkSemaphore::release(this->m_queueSemaphores[v3], 1);
  }
  else
  {
    hkJobQueue::releaseOneWaitingThread(this, data);
  }
}

// File Line: 825
// RVA: 0xC64520
void __fastcall hkJobQueue::addJobQueueLocked(
        hkJobQueue *this,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *job,
        hkJobQueue::JobPriority priority)
{
  int QueueIndexForJob; // r14d
  hkQueue<hkJobQueue::JobQueueEntry> *v9; // rcx

  QueueIndexForJob = hkJobQueue::getQueueIndexForJob(this, job);
  v9 = (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)data->m_jobQueue + 16 * QueueIndexForJob + 8 * QueueIndexForJob);
  if ( priority )
    hkQueue<hkJobQueue::JobQueueEntry>::enqueue(v9, job);
  else
    hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(v9, job);
  hkJobQueue::checkQueueAndReleaseOneWaitingThread(this, QueueIndexForJob, data);
}

// File Line: 843
// RVA: 0xC644B0
void __fastcall hkJobQueue::addJob(hkJobQueue *this, hkJobQueue::JobQueueEntry *job, hkJobQueue::JobPriority priority)
{
  hkJobQueue::DynamicData *v6; // rax
  char dynamicDataStorage[672]; // [rsp+20h] [rbp-2A8h] BYREF

  v6 = hkJobQueue::lockQueue(this, dynamicDataStorage);
  hkJobQueue::addJobQueueLocked(this, v6, job, priority);
  hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
}

// File Line: 856
// RVA: 0xC64460
void __fastcall hkJobQueue::addJob(hkJobQueue *this, hkJob *job, hkJobQueue::JobPriority priority)
{
  hkJobQueue::JobQueueEntry dst; // [rsp+20h] [rbp-108h] BYREF

  hkString::memCpy(&dst, job, job->m_size);
  hkJobQueue::addJob(this, &dst, priority);
}

// File Line: 865
// RVA: 0xC63890
void __fastcall hkJobQueue::addJobBatch(hkJobQueue *this, hkArrayBase<hkJob *> *jobs, hkJobQueue::JobPriority priority)
{
  _QWORD *Value; // r9
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  _QWORD *v9; // rcx
  int v10; // esi
  hkJobQueue::DynamicData *v11; // rdi
  __int64 v12; // r14
  int QueueIndexForJob; // eax
  int v14; // ebx
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkJobQueue::JobQueueEntry dst; // [rsp+20h] [rbp-3B8h] BYREF
  char dynamicDataStorage[672]; // [rsp+120h] [rbp-2B8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtAddJobBatch";
    v8 = __rdtsc();
    v9 = v7 + 2;
    *((_DWORD *)v9 - 2) = v8;
    Value[1] = v9;
  }
  v10 = 0;
  v11 = hkJobQueue::lockQueue(this, dynamicDataStorage);
  if ( jobs->m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkString::memCpy(&dst, jobs->m_data[v12], jobs->m_data[v12]->m_size);
      QueueIndexForJob = hkJobQueue::getQueueIndexForJob(this, &dst);
      v14 = QueueIndexForJob;
      if ( priority )
        hkQueue<hkJobQueue::JobQueueEntry>::enqueue(
          (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11->m_jobQueue + 16 * QueueIndexForJob + 8 * QueueIndexForJob),
          &dst);
      else
        hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(
          (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11->m_jobQueue + 16 * QueueIndexForJob + 8 * QueueIndexForJob),
          &dst);
      hkJobQueue::checkQueueAndReleaseOneWaitingThread(this, v14, v11);
      ++v10;
      ++v12;
    }
    while ( v10 < jobs->m_size );
  }
  hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = v16 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v17[1] = v19;
  }
}

// File Line: 899
// RVA: 0xC63E90
void __fastcall hkJobQueue::setWaitPolicy(hkJobQueue *this, hkJobQueue::WaitPolicy waitPolicy)
{
  hkJobQueue::DynamicData *v4; // rax
  char dynamicDataStorage[672]; // [rsp+20h] [rbp-2A8h] BYREF

  v4 = hkJobQueue::lockQueue(this, dynamicDataStorage);
  this->m_data->m_waitPolicy = waitPolicy;
  if ( waitPolicy == WAIT_UNTIL_ALL_WORK_COMPLETE )
    hkJobQueue::releaseWaitingThreads(this, v4);
  hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
}

// File Line: 913
// RVA: 0xC63EF0
__int64 __fastcall hkJobQueue::getWaitPolicy(hkJobQueue *this)
{
  return (unsigned int)this->m_data->m_waitPolicy;
}

// File Line: 919
// RVA: 0xC63F00
__int64 __fastcall hkJobQueue::getMasterThreadFinishingFlags(hkJobQueue *this)
{
  return (unsigned int)this->m_data->m_masterThreadFinishingFlags;
}

// File Line: 925
// RVA: 0xC63F10
void __fastcall hkJobQueue::setMasterThreadFinishingFlags(hkJobQueue *this, int flags)
{
  hkJobQueue::DynamicData *v4; // rax
  __int64 v5; // rdx
  unsigned __int16 v6; // cx
  char dynamicDataStorage[672]; // [rsp+20h] [rbp-2A8h] BYREF

  v4 = hkJobQueue::lockQueue(this, dynamicDataStorage);
  this->m_data->m_masterThreadFinishingFlags = flags;
  v5 = this->m_cpuThreadIndexToSemaphoreIndex[0];
  v6 = v4->m_numThreadsWaiting[v5];
  if ( v6 )
  {
    v4->m_numThreadsWaiting[v5] = v6 - 1;
    hkSemaphore::release(this->m_queueSemaphores[this->m_cpuThreadIndexToSemaphoreIndex[0]], 1);
  }
  hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
}

// File Line: 1086
// RVA: 0xC65190
__int64 __fastcall hkJobQueue::findJobInternal(
        hkJobQueue *this,
        int queueIndexOfNewJob,
        hkJobQueue::DynamicData *data,
        hkJobQueue::WaitStatus waitStatus,
        hkJobQueue::JobQueueEntry *jobOut)
{
  int m_masterThreadQueue; // eax
  char *v10; // rdx
  int v11; // esi
  char *v12; // r14
  int v14; // r15d
  hkJobQueue::JobQueueEntry *p_Dst; // rcx
  __int128 *v16; // rdx
  __int64 v17; // rax
  __int128 v18; // xmm0
  int v19; // eax
  __int64 m_cpuSemaphoreBegin; // r9
  __int64 m_directMapSemaphoreEnd; // r10
  int v22; // edx
  int v23; // r8d
  int m_elementsInUse; // r11d
  int *p_m_elementsInUse; // rcx
  unsigned __int64 v26; // rax
  int m_numJobTypes; // r9d
  int v28; // r8d
  int v29; // ecx
  __int64 i; // rdx
  int v31; // eax
  int v32; // eax
  bool v33; // si
  __int16 *v34; // rcx
  __int16 v35; // ax
  __int64 v36; // rsi
  _QWORD *Value; // r9
  unsigned __int64 v38; // r8
  unsigned __int64 v39; // rax
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  _QWORD *v43; // rcx
  hkJobQueue::JobQueueEntry Dst; // [rsp+20h] [rbp-128h] BYREF

  if ( (unsigned int)TlsGetValue(hkThreadNumber.m_slotID) )
    m_masterThreadQueue = this->m_cpuThreadIndexToSemaphoreIndex[(int)TlsGetValue(hkThreadNumber.m_slotID)];
  else
    m_masterThreadQueue = this->m_masterThreadQueue;
  v10 = this->m_nextQueueToGet[m_masterThreadQueue];
  v11 = *v10;
  if ( v11 < 0 )
  {
LABEL_7:
    v11 = -1;
  }
  else
  {
    while ( 1 )
    {
      ++v10;
      v12 = (char *)data + 24 * v11;
      if ( *((_DWORD *)v12 + 21) )
        break;
      v11 = *v10;
      if ( v11 < 0 )
        goto LABEL_7;
    }
    v14 = *((_DWORD *)v12 + 19);
    p_Dst = &Dst;
    v16 = (__int128 *)(*((_QWORD *)v12 + 8) + ((__int64)v14 << 8));
    if ( (((unsigned __int8)&Dst | (unsigned __int8)v12[64]) & 0xF) != 0 )
    {
      memmove(&Dst, v16, 0x100ui64);
    }
    else
    {
      v17 = 2i64;
      do
      {
        v18 = *v16;
        p_Dst = (hkJobQueue::JobQueueEntry *)((char *)p_Dst + 128);
        v16 += 8;
        *(_OWORD *)&p_Dst[-1].m_data[112] = v18;
        *(_OWORD *)&p_Dst[-1].m_data[128] = *(v16 - 7);
        *(_OWORD *)&p_Dst[-1].m_data[144] = *(v16 - 6);
        *(_OWORD *)&p_Dst[-1].m_data[160] = *(v16 - 5);
        *(_OWORD *)&p_Dst[-1].m_data[176] = *(v16 - 4);
        *(_OWORD *)&p_Dst[-1].m_data[192] = *(v16 - 3);
        *(_OWORD *)&p_Dst[-1].m_data[208] = *(v16 - 2);
        *(_OWORD *)&p_Dst[-1].m_data[224] = *(v16 - 1);
        --v17;
      }
      while ( v17 );
    }
    v19 = v14 + 1;
    if ( v14 + 1 == *((_DWORD *)v12 + 18) )
      v19 = 0;
    --*((_DWORD *)v12 + 21);
    *((_DWORD *)v12 + 19) = v19;
    if ( this->m_popJobFunc(this, data, &Dst, jobOut) == DO_NOT_POP_QUEUE_ENTRY )
    {
      hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront((hkQueue<hkJobQueue::JobQueueEntry> *)(v12 + 64), &Dst);
      hkJobQueue::checkQueueAndReleaseOneWaitingThread(this, v11, data);
    }
    ++data->m_numActiveJobs[(unsigned __int8)Dst.m_jobType.m_storage];
  }
  if ( queueIndexOfNewJob != -1 && queueIndexOfNewJob != v11 )
    hkJobQueue::checkQueueAndReleaseOneWaitingThread(this, queueIndexOfNewJob, data);
  if ( v11 >= 0 )
  {
    hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
    return 0i64;
  }
  m_cpuSemaphoreBegin = this->m_cpuSemaphoreBegin;
  m_directMapSemaphoreEnd = this->m_directMapSemaphoreEnd;
  v22 = 0;
  v23 = 0;
  m_elementsInUse = 0;
  if ( m_cpuSemaphoreBegin >= m_directMapSemaphoreEnd )
    goto LABEL_30;
  if ( m_directMapSemaphoreEnd - m_cpuSemaphoreBegin >= 2 )
  {
    p_m_elementsInUse = &data->m_jobQueue[m_cpuSemaphoreBegin + 1].m_elementsInUse;
    v26 = ((unsigned __int64)(m_directMapSemaphoreEnd - m_cpuSemaphoreBegin - 2) >> 1) + 1;
    m_cpuSemaphoreBegin += 2 * v26;
    do
    {
      v22 += *(p_m_elementsInUse - 6);
      v23 += *p_m_elementsInUse;
      p_m_elementsInUse += 12;
      --v26;
    }
    while ( v26 );
  }
  if ( m_cpuSemaphoreBegin < m_directMapSemaphoreEnd )
    m_elementsInUse = data->m_jobQueue[m_cpuSemaphoreBegin].m_elementsInUse;
  if ( !(v23 + v22 + m_elementsInUse) )
  {
LABEL_30:
    m_numJobTypes = this->m_numJobTypes;
    v28 = 0;
    v29 = 0;
    for ( i = 0i64; v29 < m_numJobTypes; v28 |= v32 )
    {
      if ( data->m_numActiveJobs[i] > 0 || (v31 = 0, data->m_jobQueue[i + this->m_cpuTypesQueuesBegin].m_elementsInUse) )
        v31 = 1;
      v32 = v31 << v29++;
      ++i;
    }
    v33 = v28 == 0;
    if ( (v28 & data->m_masterThreadFinishingFlags) == 0 )
    {
      if ( !(unsigned int)TlsGetValue(hkThreadNumber.m_slotID) )
      {
        if ( !v33 )
        {
LABEL_39:
          hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
          return 2i64;
        }
LABEL_38:
        hkJobQueue::releaseWaitingThreads(this, data);
        goto LABEL_39;
      }
      v34 = &data->m_numActiveJobs[this->m_cpuThreadIndexToSemaphoreIndex[0]];
      v35 = v34[25];
      if ( v35 )
      {
        v34[25] = v35 - 1;
        hkSemaphore::release(this->m_queueSemaphores[this->m_cpuThreadIndexToSemaphoreIndex[0]], 1);
      }
    }
    if ( v33 && data->m_waitPolicy != WAIT_INDEFINITELY )
      goto LABEL_38;
  }
  if ( waitStatus == DO_NOT_WAIT_FOR_NEXT_JOB )
  {
    hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
    return 1i64;
  }
  else
  {
    v36 = this->m_cpuThreadIndexToSemaphoreIndex[(int)TlsGetValue(hkThreadNumber.m_slotID)];
    ++data->m_numThreadsWaiting[v36];
    hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v38 = Value[1];
    if ( v38 < Value[3] )
    {
      *(_QWORD *)v38 = "TtNoJobAvailable";
      v39 = __rdtsc();
      *(_DWORD *)(v38 + 8) = v39;
      Value[1] = v38 + 16;
    }
    hkSemaphore::acquire(this->m_queueSemaphores[v36]);
    v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v41 = (_QWORD *)v40[1];
    if ( (unsigned __int64)v41 < v40[3] )
    {
      *v41 = "Et";
      v42 = __rdtsc();
      v43 = v41 + 2;
      *((_DWORD *)v43 - 2) = v42;
      v40[1] = v43;
    }
    return 0xFFFFFFFFi64;
  }
}

// File Line: 1222
// RVA: 0xC645C0
void __fastcall hkJobQueue::finishJob(
        hkJobQueue *this,
        hkJobQueue::JobQueueEntry *oldJob,
        hkJobQueue::FinishJobFlag flag)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  hkJobQueue::DynamicData *v11; // rbx
  int QueueIndexForJob; // eax
  int v13; // esi
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  _QWORD *v18; // rcx
  int v19[4]; // [rsp+20h] [rbp-3B8h] BYREF
  hkJobQueue::JobQueueEntry job; // [rsp+30h] [rbp-3A8h] BYREF
  char dynamicDataStorage[672]; // [rsp+130h] [rbp-2A8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtfinishJob";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  v11 = hkJobQueue::lockQueue(this, dynamicDataStorage);
  if ( this->m_finishJobFunc(this, v11, oldJob, (hkJobQueue::JobQueueEntryInput *)v19) == JOB_CREATED )
  {
    QueueIndexForJob = hkJobQueue::getQueueIndexForJob(this, &job);
    v13 = QueueIndexForJob;
    if ( v19[0] )
      hkQueue<hkJobQueue::JobQueueEntry>::enqueue(
        (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11->m_jobQueue + 16 * QueueIndexForJob + 8 * QueueIndexForJob),
        &job);
    else
      hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(
        (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11->m_jobQueue + 16 * QueueIndexForJob + 8 * QueueIndexForJob),
        &job);
    hkJobQueue::checkQueueAndReleaseOneWaitingThread(this, v13, v11);
  }
  if ( flag == FINISH_FLAG_NORMAL )
    --v11->m_numActiveJobs[(unsigned __int8)oldJob->m_jobType.m_storage];
  hkJobQueue::unlockQueue(&this->m_criticalSection.m_section);
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  v16 = v14;
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v17 = __rdtsc();
    v18 = v15 + 2;
    *((_DWORD *)v18 - 2) = v17;
    v16[1] = v18;
  }
}

// File Line: 1313
// RVA: 0xC64730
__int64 __fastcall hkJobQueue::finishJobAndGetNextJob(
        hkJobQueue *this,
        hkJobQueue::JobQueueEntry *oldJob,
        hkJobQueue::JobQueueEntry *jobOut,
        hkJobQueue::WaitStatus waitStatus)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkJobQueue::DynamicData *v13; // rax
  int QueueIndexForJob; // ebp
  hkJobQueue::DynamicData *v15; // rbx
  hkQueue<hkJobQueue::JobQueueEntry> *v16; // rcx
  hkJobQueue::JobStatus JobInternal; // ebx
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  int v23[4]; // [rsp+30h] [rbp-3C8h] BYREF
  hkJobQueue::JobQueueEntry job; // [rsp+40h] [rbp-3B8h] BYREF
  char dynamicDataStorage[672]; // [rsp+140h] [rbp-2B8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtGetNextJob";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  do
  {
    v13 = hkJobQueue::lockQueue(this, dynamicDataStorage);
    QueueIndexForJob = -1;
    v15 = v13;
    if ( oldJob )
    {
      if ( this->m_finishJobFunc(this, v13, oldJob, (hkJobQueue::JobQueueEntryInput *)v23) == JOB_CREATED )
      {
        QueueIndexForJob = hkJobQueue::getQueueIndexForJob(this, &job);
        v16 = (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v15->m_jobQueue
                                                   + 16 * QueueIndexForJob
                                                   + 8 * QueueIndexForJob);
        if ( v23[0] )
          hkQueue<hkJobQueue::JobQueueEntry>::enqueue(v16, &job);
        else
          hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(v16, &job);
      }
      --v15->m_numActiveJobs[(unsigned __int8)oldJob->m_jobType.m_storage];
      oldJob = 0i64;
    }
    JobInternal = hkJobQueue::findJobInternal(this, QueueIndexForJob, v15, waitStatus, jobOut);
  }
  while ( JobInternal == JOB_INVALID );
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
  return (unsigned int)JobInternal;
}

// File Line: 1420
// RVA: 0xC64420
void __fastcall hkJobQueue::registerJobHandler(
        hkJobQueue *this,
        hkJobType jobId,
        hkJobQueue::hkJobHandlerFuncs *jobHandlerFuncs)
{
  this->m_jobFuncs[jobId] = *jobHandlerFuncs;
}

// File Line: 1428
// RVA: 0xC64890
__int64 __fastcall hkJobQueue::finishAddAndGetNextJob(
        hkJobQueue *this,
        hkJobType oldJobType,
        hkJobQueue::JobPriority priority,
        hkJobQueue::JobQueueEntry *jobInOut,
        hkJobQueue::WaitStatus waitStatus)
{
  __int64 v8; // r13
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r9
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  char v14; // di
  hkJobQueue::DynamicData *v15; // rax
  int QueueIndexForJob; // ebp
  hkJobQueue::DynamicData *v17; // rsi
  hkQueue<hkJobQueue::JobQueueEntry> *v18; // rcx
  hkJobQueue::JobStatus JobInternal; // esi
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  char dynamicDataStorage[672]; // [rsp+30h] [rbp-2C8h] BYREF

  v8 = oldJobType;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtGetNextJob";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = 1;
  do
  {
    v15 = hkJobQueue::lockQueue(this, dynamicDataStorage);
    QueueIndexForJob = -1;
    v17 = v15;
    if ( v14 )
    {
      --v15->m_numActiveJobs[v8];
      QueueIndexForJob = hkJobQueue::getQueueIndexForJob(this, jobInOut);
      v18 = (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v17->m_jobQueue + 16 * QueueIndexForJob
                                                                           + 8 * QueueIndexForJob);
      if ( priority )
        hkQueue<hkJobQueue::JobQueueEntry>::enqueue(v18, jobInOut);
      else
        hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(v18, jobInOut);
      v14 = 0;
    }
    JobInternal = hkJobQueue::findJobInternal(this, QueueIndexForJob, v17, waitStatus, jobInOut);
  }
  while ( JobInternal == JOB_INVALID );
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = v21 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v20[1] = v23;
  }
  return (unsigned int)JobInternal;
}

// File Line: 1471
// RVA: 0xC64B60
void __fastcall hkJobQueue::releaseWaitingThreads(hkJobQueue *this, hkJobQueue::DynamicData *data)
{
  int v3; // ebp
  hkSemaphore **m_queueSemaphores; // rdi
  unsigned __int16 *m_numThreadsWaiting; // rsi
  int v6; // ebx

  v3 = 0;
  if ( this->m_numQueueSemaphores > 0 )
  {
    m_queueSemaphores = this->m_queueSemaphores;
    m_numThreadsWaiting = data->m_numThreadsWaiting;
    do
    {
      v6 = *m_numThreadsWaiting;
      for ( *m_numThreadsWaiting = 0; v6 > 0; --v6 )
        hkSemaphore::release(*m_queueSemaphores, 1);
      ++v3;
      ++m_numThreadsWaiting;
      ++m_queueSemaphores;
    }
    while ( v3 < this->m_numQueueSemaphores );
  }
}

// File Line: 1489
// RVA: 0xC649E0
void __fastcall hkJobQueue::setNumRunningSpus(hkJobQueue *this, int numSpus)
{
  ;
}

// File Line: 1501
// RVA: 0xC649F0
__int64 __fastcall hkJobQueue::setSpuSchedulingPolicy(hkJobQueue *this, hkJobQueueHwSetup::SpuSchedulePolicy policy)
{
  return (unsigned int)this->m_hwSetup.m_spuSchedulePolicy;
}

