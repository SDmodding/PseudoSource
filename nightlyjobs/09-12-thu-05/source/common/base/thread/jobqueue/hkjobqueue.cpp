// File Line: 68
// RVA: 0xC63470
void __fastcall hkJobQueueHwSetup::hkJobQueueHwSetup(hkJobQueueHwSetup *this)
{
  hkJobQueueHwSetup *v1; // rbx
  int v2; // eax
  hkHardwareInfo info; // [rsp+30h] [rbp+8h]

  this->m_threadIdsSharingCaches.m_data = 0i64;
  this->m_threadIdsSharingCaches.m_size = 0;
  this->m_threadIdsSharingCaches.m_capacityAndFlags = 2147483648;
  this->m_cellRules = 1;
  v1 = this;
  hkGetHardwareInfo(&info);
  v2 = info.m_numThreads;
  v1->m_spuSchedulePolicy = 0;
  v1->m_numCpuThreads = v2;
  v1->m_noSpu.m_bool = 1;
}

// File Line: 83
// RVA: 0xC64C90
__int64 __fastcall defaultPopDispatchFunc(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntry *jobOut)
{
  return queue->m_jobFuncs[(unsigned __int8)jobIn->m_jobType.m_storage].m_popJobFunc(queue, data, jobIn, jobOut);
}

// File Line: 88
// RVA: 0xC64CB0
__int64 __fastcall defaultFinishDispatchFunc(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntryInput *newJobCreatedOut)
{
  return queue->m_jobFuncs[(unsigned __int8)jobIn->m_jobType.m_storage].m_finishJobFunc(
           queue,
           data,
           jobIn,
           newJobCreatedOut);
}

// File Line: 97
// RVA: 0xC64CD0
__int64 __fastcall hkDefaultPopJobFunc(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntry *jobOut)
{
  return 0i64;
}

// File Line: 106
// RVA: 0xC64CE0
signed __int64 __fastcall hkDefaultFinishJobFunc(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntryInput *newJobCreatedOut)
{
  return 1i64;
}

// File Line: 119
// RVA: 0xC634C0
void __fastcall hkJobQueue::hkJobQueue(hkJobQueue *this, hkJobQueueCinfo *cinfo)
{
  hkJobQueueCinfo *v2; // r14
  hkJobQueue *v3; // rbx
  _QWORD **v4; // rax
  __int64 v5; // rax
  hkJobQueue::DynamicData *v6; // rbp
  hkQueue<hkpRigidBody *> *v7; // rdi
  signed int v8; // esi
  int v9; // er9
  signed int v10; // edx
  __int64 v11; // r8
  signed __int64 v12; // rcx

  v2 = cinfo;
  v3 = this;
  hkCriticalSection::hkCriticalSection(&this->m_criticalSection, 0);
  v3->m_numJobTypes = v2->m_maxNumJobTypes;
  hkJobQueueHwSetup::hkJobQueueHwSetup(&v3->m_hwSetup);
  v3->m_customJobSetup.m_data = 0i64;
  v3->m_customJobSetup.m_size = 0;
  v3->m_customJobSetup.m_capacityAndFlags = 2147483648;
  v3->m_externalJobProfiler = 0i64;
  TlsSetValue(hkThreadNumber.m_slotID, 0i64);
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 672i64);
  v6 = (hkJobQueue::DynamicData *)v5;
  if ( v5 )
  {
    v7 = (hkQueue<hkpRigidBody *> *)(v5 + 64);
    v8 = 24;
    do
    {
      hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(v7);
      ++v7;
      --v8;
    }
    while ( v8 >= 0 );
  }
  else
  {
    v6 = 0i64;
  }
  v3->m_data = v6;
  v3->m_queryRulesAreUpdated.m_bool = 0;
  v6->m_outOfMemory.m_bool = 0;
  v3->m_data->m_waitPolicy = 0;
  hkJobQueueHwSetup::operator=(&v3->m_hwSetup, &v2->m_jobQueueHwSetup);
  v3->m_data->m_masterThreadFinishingFlags = 0;
  v9 = 0;
  v10 = 1;
  if ( v3->m_numJobTypes > 0 )
  {
    v11 = 0i64;
    v12 = (signed __int64)v3->m_jobFuncs;
    do
    {
      *(_DWORD *)(v12 + 8) = 0;
      *(_QWORD *)v12 = 0i64;
      *(_QWORD *)(v12 + 16) = hkDefaultPopJobFunc;
      *(_QWORD *)(v12 + 24) = hkDefaultFinishJobFunc;
      ++v9;
      v3->m_data->m_numActiveJobs[v11] = 0;
      v12 += 32i64;
      v3->m_data->m_masterThreadFinishingFlags |= v10;
      v10 = __ROL4__(v10, 1);
      ++v11;
    }
    while ( v9 < v3->m_numJobTypes );
  }
  v3->m_numQueueSemaphores = 0;
  v3->m_threadPool = 0i64;
  v3->m_popJobFunc = defaultPopDispatchFunc;
  v3->m_finishJobFunc = defaultFinishDispatchFunc;
  v3->m_queueSemaphores[0] = 0i64;
  v3->m_queueSemaphores[1] = 0i64;
  v3->m_queueSemaphores[2] = 0i64;
  v3->m_queueSemaphores[3] = 0i64;
  v3->m_queueSemaphores[4] = 0i64;
  hkJobQueue::updateJobQueryRules(v3);
}

// File Line: 188
// RVA: 0xC63680
void __fastcall hkJobQueue::~hkJobQueue(hkJobQueue *this)
{
  hkJobQueue::DynamicData *v1; // rsi
  hkJobQueue *v2; // rbp
  hkQueue<hkJobQueue::JobQueueEntry> *v3; // rbx
  signed int v4; // edi
  _QWORD **v5; // rax
  hkSemaphore **v6; // rbx
  signed __int64 v7; // rsi
  hkSemaphore *v8; // rdi
  _QWORD **v9; // rax
  int v10; // eax

  v1 = this->m_data;
  v2 = this;
  if ( v1 )
  {
    v3 = &v1->m_jobQueue[25];
    v4 = 24;
    do
    {
      --v3;
      hkQueue<hkJobQueue::JobQueueEntry>::~hkQueue<hkJobQueue::JobQueueEntry>(v3);
      --v4;
    }
    while ( v4 >= 0 );
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkJobQueue::DynamicData *, signed __int64))(*v5[11] + 16i64))(v5[11], v1, 672i64);
  }
  if ( v2->m_queryRulesAreUpdated.m_bool )
  {
    v6 = v2->m_queueSemaphores;
    v7 = 5i64;
    do
    {
      v8 = *v6;
      if ( *v6 )
      {
        hkSemaphore::~hkSemaphore(*v6);
        v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v9[11] + 16i64))(v9[11], v8, 8i64);
      }
      ++v6;
      --v7;
    }
    while ( v7 );
  }
  v10 = v2->m_customJobSetup.m_capacityAndFlags;
  v2->m_customJobSetup.m_size = 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_customJobSetup.m_data,
      12 * (v10 & 0x3FFFFFFF));
  v2->m_customJobSetup.m_data = 0i64;
  v2->m_customJobSetup.m_capacityAndFlags = 2147483648;
  hkJobQueueHwSetup::~hkJobQueueHwSetup(&v2->m_hwSetup);
  DeleteCriticalSection(&v2->m_criticalSection.m_section);
}

// File Line: 216
// RVA: 0xC637B0
void __fastcall hkJobQueue::registerJobWithCpuThread(hkJobQueue *this, hkJobType jobType, char subType, int threadId)
{
  int v4; // eax
  int v5; // edi
  char v6; // si
  hkJobType v7; // ebp
  hkJobQueue *v8; // r14
  signed __int64 v9; // r10
  hkJobQueue::CustomJobTypeSetup *v10; // rax
  signed int *v11; // rbx
  __int64 v12; // rdx
  signed __int64 v13; // r8

  v4 = this->m_customJobSetup.m_size;
  v5 = threadId;
  v6 = subType;
  v7 = jobType;
  v8 = this;
  if ( v4 < 1 || (v9 = 0i64, v4 <= 0) )
  {
LABEL_8:
    v11 = (signed int *)&this->m_customJobSetup;
    if ( this->m_customJobSetup.m_size == (this->m_customJobSetup.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 12);
    v12 = v11[2];
    v13 = *(_QWORD *)v11 + 12 * v12;
    v11[2] = v12 + 1;
    *(_DWORD *)v13 = v7;
    *(_BYTE *)(v13 + 4) = v6;
    *(_DWORD *)(v13 + 8) = v5;
    hkJobQueue::updateJobQueryRules(v8);
  }
  else
  {
    v10 = this->m_customJobSetup.m_data;
    while ( v10->m_jobType != jobType || v10->m_jobSubType != subType || v10->m_threadId != threadId )
    {
      ++v9;
      ++v10;
      if ( v9 >= this->m_customJobSetup.m_size )
        goto LABEL_8;
    }
  }
}

// File Line: 239
// RVA: 0xC63A20
void __fastcall hkJobQueue::updateJobQueryRules(hkJobQueue *this)
{
  int v1; // ebp
  hkJobQueue *v2; // rbx
  int v3; // ecx
  signed int v4; // esi
  int v5; // edi
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  char *v9; // rax
  int i; // er11
  int v11; // er9
  __int64 v12; // r8
  int v13; // edx
  signed __int64 v14; // rcx
  int j; // er8
  int v16; // edx
  char *v17; // rcx
  int k; // edx
  char v19; // al
  int l; // eax
  int m; // edx
  char v22; // al
  int n; // er11
  signed __int64 v24; // r10
  signed __int64 v25; // r8
  char v26; // dl
  __int64 v27; // rcx
  __int64 v28; // r8
  char *v29; // r9
  char *v30; // rdx
  int v31; // er8
  signed int v32; // ecx
  int v33; // er14
  char *v34; // rax
  __int64 v35; // rsi
  hkSemaphore **v36; // rdi
  hkSemaphore *v37; // rbp
  _QWORD **v38; // rax
  int v39; // edi
  signed __int64 v40; // r14
  hkSemaphore **v41; // rsi
  _QWORD **v42; // rax
  hkSemaphore *v43; // rax
  hkSemaphore *v44; // rax

  v1 = this->m_hwSetup.m_threadIdsSharingCaches.m_size;
  v2 = this;
  v3 = this->m_customJobSetup.m_size;
  v4 = 1;
  v2->m_numCustomJobs = v3;
  if ( !v1 )
    v1 = 1;
  if ( v2->m_hwSetup.m_noSpu.m_bool )
    v2->m_cpuCacheQueuesBegin = 0;
  else
    v2->m_cpuCacheQueuesBegin = v2->m_numJobTypes;
  v5 = v2->m_cpuCacheQueuesBegin;
  v6 = v5 + v1 + v3;
  v2->m_cpuCustomQueuesBegin = v5 + v1;
  v2->m_cpuTypesQueuesBegin = v6;
  for ( v2->m_numJobQueues = v2->m_numJobTypes + v6; v5 < v2->m_cpuCustomQueuesBegin; ++v5 )
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(
      (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v2->m_data + 8 * (3i64 * v5 + 8)),
      128);
  v2->m_cpuSemaphoreBegin = v2->m_cpuCacheQueuesBegin;
  v2->m_directMapSemaphoreEnd = v2->m_cpuTypesQueuesBegin;
  v7 = v2->m_hwSetup.m_threadIdsSharingCaches.m_size == 0;
  if ( v2->m_hwSetup.m_threadIdsSharingCaches.m_size > 0 )
  {
    v8 = 0;
    if ( v2->m_hwSetup.m_numCpuThreads > 0 )
    {
      v9 = v2->m_cpuThreadIndexToSemaphoreIndex;
      do
      {
        *v9 = -1;
        ++v8;
        ++v9;
      }
      while ( v8 < v2->m_hwSetup.m_numCpuThreads );
    }
    for ( i = 0; i < v2->m_hwSetup.m_threadIdsSharingCaches.m_size; ++i )
    {
      v11 = 0;
      if ( v2->m_hwSetup.m_threadIdsSharingCaches.m_data[i].m_size > 0 )
      {
        v12 = 0i64;
        do
        {
          ++v11;
          ++v12;
          v2->m_cpuThreadIndexToSemaphoreIndex[v2->m_hwSetup.m_threadIdsSharingCaches.m_data[i].m_data[v12 - 1]] = LOBYTE(v2->m_cpuCacheQueuesBegin) + i;
        }
        while ( v11 < v2->m_hwSetup.m_threadIdsSharingCaches.m_data[i].m_size );
      }
    }
    v7 = v2->m_hwSetup.m_threadIdsSharingCaches.m_size == 0;
  }
  if ( v7 )
  {
    v13 = 0;
    if ( v2->m_hwSetup.m_numCpuThreads > 0 )
    {
      v14 = (signed __int64)v2->m_cpuThreadIndexToSemaphoreIndex;
      do
      {
        ++v13;
        *(_BYTE *)(++v14 - 1) = v2->m_cpuCacheQueuesBegin;
      }
      while ( v13 < v2->m_hwSetup.m_numCpuThreads );
    }
  }
  for ( j = 0; j < v1; *v17 = -1 )
  {
    v16 = 0;
    v17 = &v2->m_nextQueueToGet[j + v2->m_cpuCacheQueuesBegin][1];
    for ( v2->m_nextQueueToGet[j + v2->m_cpuCacheQueuesBegin][0] = LOBYTE(v2->m_cpuCacheQueuesBegin) + j;
          v16 < v2->m_hwSetup.m_threadIdsSharingCaches.m_size;
          ++v16 )
    {
      if ( j != v16 )
        *(++v17 - 1) = LOBYTE(v2->m_cpuCacheQueuesBegin) + v16;
    }
    for ( k = 0; k < v2->m_numJobTypes; *(v17 - 1) = LOBYTE(v2->m_cpuTypesQueuesBegin) + v19 )
    {
      v19 = k++;
      ++v17;
    }
    if ( v2->m_hwSetup.m_cellRules == PPU_CAN_TAKE_SPU_TASKS )
    {
      for ( l = 0; l < v2->m_numJobTypes; ++v17 )
        *v17 = l++;
    }
    for ( m = 0; m < v2->m_numCustomJobs; *(v17 - 1) = LOBYTE(v2->m_cpuCustomQueuesBegin) + v22 )
    {
      v22 = m++;
      ++v17;
    }
    ++j;
  }
  for ( n = 0; n < v2->m_numCustomJobs; *v29 = -1 )
  {
    v24 = (signed __int64)v2 + 8 * n;
    v25 = n;
    *(_DWORD *)(v24 + 84) = v2->m_customJobSetup.m_data[v25].m_jobType;
    v2->m_customJobs[n].m_jobSubType = v2->m_customJobSetup.m_data[v25].m_jobSubType;
    v26 = LOBYTE(v2->m_cpuCustomQueuesBegin) + n;
    *(_BYTE *)(v24 + 89) = v26;
    v27 = v2->m_customJobSetup.m_data[v25].m_threadId;
    v28 = v2->m_cpuThreadIndexToSemaphoreIndex[v27];
    v2->m_cpuThreadIndexToSemaphoreIndex[v27] = v26;
    LODWORD(v27) = n + v2->m_cpuCustomQueuesBegin;
    v29 = &v2->m_nextQueueToGet[(signed int)v27][1];
    v2->m_nextQueueToGet[(signed int)v27][0] = LOBYTE(v2->m_cpuCustomQueuesBegin) + n;
    if ( v2->m_nextQueueToGet[v28][0] != -1 )
    {
      v30 = v2->m_nextQueueToGet[v28];
      do
      {
        v31 = *v30;
        if ( v31 != *(unsigned __int8 *)(v24 + 89) )
          *v29++ = v31;
        ++v30;
      }
      while ( *v30 != -1 );
    }
    ++n;
  }
  v32 = v2->m_hwSetup.m_numCpuThreads;
  v33 = v2->m_cpuTypesQueuesBegin;
  v2->m_masterThreadQueue = v2->m_cpuThreadIndexToSemaphoreIndex[0];
  if ( v32 > 1 )
  {
    v34 = &v2->m_cpuThreadIndexToSemaphoreIndex[1];
    while ( *v34 != v2->m_cpuThreadIndexToSemaphoreIndex[0] )
    {
      ++v4;
      ++v34;
      if ( v4 >= v32 )
        goto LABEL_48;
    }
    v2->m_cpuThreadIndexToSemaphoreIndex[0] = v33++;
  }
LABEL_48:
  if ( v2->m_queryRulesAreUpdated.m_bool )
  {
    v35 = v2->m_cpuCacheQueuesBegin;
    if ( (signed int)v35 < v2->m_numQueueSemaphores )
    {
      v36 = &v2->m_queueSemaphores[v35];
      do
      {
        v37 = *v36;
        if ( *v36 )
        {
          hkSemaphore::~hkSemaphore(*v36);
          v38 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v38[11] + 16i64))(v38[11], v37, 8i64);
        }
        *v36 = 0i64;
        LODWORD(v35) = v35 + 1;
        ++v36;
      }
      while ( (signed int)v35 < v2->m_numQueueSemaphores );
    }
  }
  v2->m_numQueueSemaphores = v33;
  v39 = 0;
  if ( v33 > 0 )
  {
    v40 = 25i64;
    v41 = v2->m_queueSemaphores;
    do
    {
      v2->m_data->m_numActiveJobs[v40] = 0;
      if ( v39 >= v2->m_cpuCacheQueuesBegin )
      {
        v42 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v43 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v42[11] + 8i64))(v42[11], 8i64);
        if ( v43 )
          hkSemaphore::hkSemaphore(v43, 0, 1000, 0);
        else
          v44 = 0i64;
        *v41 = v44;
      }
      ++v39;
      ++v40;
      ++v41;
    }
    while ( v39 < v2->m_numQueueSemaphores );
  }
  v2->m_queryRulesAreUpdated.m_bool = 1;
}

// File Line: 461
// RVA: 0xC63FA0
void __fastcall hkJobQueue::setQueueCapacityForJobType(hkJobQueue *this, hkJobType jobType, int queueCapacity)
{
  hkJobType v3; // ebx
  int v4; // er12
  hkJobQueue *v5; // rbp
  hkJobQueue::DynamicData *v6; // rdi
  int v7; // er14
  char *v8; // r15
  signed __int64 v9; // rbx
  int v10; // eax
  int v11; // eax
  int v12; // edi
  _QWORD **v13; // rax
  hkJobQueue::JobQueueEntry *v14; // rax
  hkJobQueue::JobQueueEntry *v15; // r13
  hkJobQueue::JobQueueEntry *v16; // rcx
  int v17; // er8
  signed int v18; // esi
  __int64 v19; // rdx
  int v20; // edi
  __int64 v21; // rcx
  hkJobQueue::JobQueueEntry *v22; // rdx
  hkJobQueue::JobQueueEntry *v23; // rcx
  int v24; // er8
  int v25; // eax
  int v26; // esi
  hkJobQueue::JobQueueEntry *v27; // rdi
  _QWORD **v28; // rax
  int i; // ebx
  char dynamicDataStorage; // [rsp+20h] [rbp-2D8h]
  hkJobQueue::DynamicData *v31; // [rsp+300h] [rbp+8h]
  int v32; // [rsp+308h] [rbp+10h]

  v3 = jobType;
  v4 = queueCapacity;
  v5 = this;
  v6 = hkJobQueue::lockQueue(this, &dynamicDataStorage);
  v31 = v6;
  hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(
    (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v6
                                         + 8
                                         * (v3 + v5->m_cpuTypesQueuesBegin + 2 * (v3 + v5->m_cpuTypesQueuesBegin + 4i64))),
    v4);
  v7 = 0;
  if ( v5->m_numCustomJobs > 0 )
  {
    v8 = &v5->m_customJobs[0].m_queueId;
    do
    {
      v9 = (unsigned __int8)*v8;
      v10 = v6->m_jobQueue[(unsigned __int8)*v8].m_capacity;
      if ( v10 < v4 )
      {
        v11 = 2 * v10;
        v12 = v4;
        if ( v11 >= v4 )
          v12 = v11;
        v32 = v12;
        v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (hkJobQueue::JobQueueEntry *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v13[11] + 8i64))(
                                             v13[11],
                                             (unsigned int)(v12 << 8));
        v6 = v31;
        v15 = v14;
        if ( v14 )
        {
          v16 = v31->m_jobQueue[v9].m_data;
          if ( v16 )
          {
            v17 = v31->m_jobQueue[v9].m_elementsInUse;
            if ( v17 )
            {
              v18 = v31->m_jobQueue[v9].m_tail;
              v19 = v31->m_jobQueue[v9].m_head;
              if ( v18 > (signed int)v19 )
              {
                v24 = v17 << 8;
                v22 = &v16[v19];
                v23 = v14;
              }
              else
              {
                v20 = v31->m_jobQueue[v9].m_capacity - v19;
                hkString::memCpy(v14, &v16[v19], v20 << 8);
                v21 = v20;
                v6 = v31;
                v22 = v31->m_jobQueue[v9].m_data;
                v23 = &v15[v21];
                v24 = v18 << 8;
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
      v8 += 8;
    }
    while ( v7 < v5->m_numCustomJobs );
  }
  for ( i = v5->m_cpuCacheQueuesBegin; i < v5->m_cpuCustomQueuesBegin; ++i )
    hkQueue<hkJobQueue::JobQueueEntry>::setCapacity(
      (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v6 + 8 * (i + 2 * (i + 4i64))),
      v4);
  hkJobQueue::unlockQueue(&v5->m_criticalSection.m_section);
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
  bool v2; // r14
  hkJobQueue *v3; // rbp
  hkJobQueue::JobStatus result; // eax
  __int64 v5; // rsi
  const char *v6; // rbx
  _QWORD *v7; // rax
  _QWORD *v8; // rdi
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  hkExternalJobProfiler *v11; // rcx
  hkJobQueue::JobStatus v12; // eax
  hkExternalJobProfiler *v13; // rcx
  hkJobQueue::JobStatus v14; // ebx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  hkJobQueue::JobQueueEntry job; // [rsp+20h] [rbp-118h]

  v2 = addTimers;
  v3 = this;
  result = hkJobQueue::getNextJob(this, &job, 0);
  if ( result == GOT_NEXT_JOB )
  {
    do
    {
      v5 = (unsigned __int8)job.m_jobType.m_storage;
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
      v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v8 = v7;
      if ( v2 )
      {
        v9 = v7[1];
        if ( v9 < v7[3] )
        {
          *(_QWORD *)v9 = v6;
          v10 = __rdtsc();
          *(_DWORD *)(v9 + 8) = v10;
          v8[1] = v9 + 16;
        }
      }
      v11 = v3->m_externalJobProfiler;
      if ( v11 )
        v11->vfptr->onStartJob(v11, (hkJobType)v5, (unsigned __int8)job.m_jobSubType);
      v12 = (*(unsigned int (__fastcall **)(hkJobQueue *, hkJobQueue::JobQueueEntry *))(*((_QWORD *)&v3->m_criticalSection.m_section.DebugInfo
                                                                                        + 4 * (v5 + 11))
                                                                                      + 8i64
                                                                                      * (unsigned __int8)job.m_jobSubType))(
              v3,
              &job);
      v13 = v3->m_externalJobProfiler;
      v14 = v12;
      if ( v13 )
        v13->vfptr->onEndJob(v13, (hkJobType)v5);
      if ( v2 )
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
    result = v14;
  }
  return result;
}

// File Line: 648
// RVA: 0xC64C00
__int64 __fastcall hkJobQueue::getQueueIndexForJob(hkJobQueue *this, hkJob *job)
{
  __int64 v2; // r11
  int v3; // er10
  __int64 v4; // r9
  char *v5; // r8

  v2 = this->m_numCustomJobs;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
    return this->m_cpuTypesQueuesBegin + (unsigned int)(unsigned __int8)job->m_jobType.m_storage;
  v5 = &this->m_customJobs[0].m_jobSubType;
  while ( job->m_jobType.m_storage != *(v5 - 4) || job->m_jobSubType != *v5 )
  {
    ++v4;
    ++v3;
    v5 += 8;
    if ( v4 >= v2 )
      return this->m_cpuTypesQueuesBegin + (unsigned int)(unsigned __int8)job->m_jobType.m_storage;
  }
  return (unsigned __int8)this->m_customJobs[v3].m_queueId;
}

// File Line: 686
// RVA: 0xC64C60
hkJobQueue::DynamicData *__fastcall hkJobQueue::lockQueue(hkJobQueue *this, char *dynamicDataStorage)
{
  hkJobQueue *v2; // rbx

  v2 = this;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  return v2->m_data;
}

// File Line: 706
// RVA: 0xC64C80
void __stdcall hkJobQueue::unlockQueue(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}

// File Line: 722
// RVA: 0xC645A0
hkJobQueue::JobStatus __fastcall hkJobQueue::getNextJob(hkJobQueue *this, hkJobQueue::JobQueueEntry *job, hkJobQueue::WaitStatus waitStatus)
{
  return hkJobQueue::finishJobAndGetNextJob(this, 0i64, job, waitStatus);
}

// File Line: 727
// RVA: 0xC64A10
void __fastcall hkJobQueue::releaseOneWaitingThread(hkJobQueue *this, hkJobQueue::DynamicData *data)
{
  __int64 v2; // r8
  __int64 v3; // rbx
  char v4; // di
  hkJobQueue::DynamicData *v5; // rbp
  hkJobQueue *v6; // rsi
  __int64 v7; // r9
  unsigned __int16 *v8; // r10
  int *v9; // r11
  __int64 v10; // rcx
  __int64 v11; // r8
  int *v12; // rdx
  __int64 v13; // rdx
  __int64 v14; // rax
  unsigned __int16 *v15; // rcx

  v2 = this->m_cpuSemaphoreBegin;
  v3 = this->m_directMapSemaphoreEnd;
  v4 = 0;
  v5 = data;
  v6 = this;
  v7 = v2;
  if ( v2 < v3 )
  {
    v8 = &data->m_numThreadsWaiting[v2];
    v9 = &data->m_jobQueue[v2].m_elementsInUse;
    do
    {
      if ( *v9 )
      {
        v4 = 1;
        if ( *v8 )
          goto $releaseSemaphore;
      }
      ++v7;
      LODWORD(v2) = v2 + 1;
      ++v8;
      v9 += 6;
    }
    while ( v7 < v3 );
  }
  v10 = (signed int)v2;
  v11 = v6->m_numJobQueues;
  if ( v10 >= v11 )
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
      if ( v10 >= v11 )
        goto LABEL_10;
    }
  }
  v2 = v6->m_cpuSemaphoreBegin;
  v13 = v6->m_numQueueSemaphores;
  v14 = v2;
  if ( v2 < v13 )
  {
    v15 = &v5->m_numThreadsWaiting[v2];
    while ( !*v15 )
    {
      ++v14;
      LODWORD(v2) = v2 + 1;
      ++v15;
      if ( v14 >= v13 )
        return;
    }
$releaseSemaphore:
    --v5->m_numThreadsWaiting[(signed int)v2];
    hkSemaphore::release(v6->m_queueSemaphores[(signed int)v2], 1);
  }
}

// File Line: 806
// RVA: 0xC64B20
void __fastcall hkJobQueue::checkQueueAndReleaseOneWaitingThread(hkJobQueue *this, int queueIndex, hkJobQueue::DynamicData *data)
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
void __fastcall hkJobQueue::addJobQueueLocked(hkJobQueue *this, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *job, hkJobQueue::JobPriority priority)
{
  hkJobQueue::DynamicData *v4; // rsi
  hkJobQueue::JobPriority v5; // ebx
  hkJobQueue::JobQueueEntry *v6; // rdi
  hkJobQueue *v7; // rbp
  int v8; // er14
  hkQueue<hkJobQueue::JobQueueEntry> *v9; // rcx

  v4 = data;
  v5 = priority;
  v6 = job;
  v7 = this;
  v8 = hkJobQueue::getQueueIndexForJob(this, (hkJob *)&job->m_jobSubType);
  v9 = (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v4 + 8 * (v8 + 2 * (v8 + 4i64)));
  if ( v5 )
    hkQueue<hkJobQueue::JobQueueEntry>::enqueue(v9, v6);
  else
    hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(v9, v6);
  hkJobQueue::checkQueueAndReleaseOneWaitingThread(v7, v8, v4);
}

// File Line: 843
// RVA: 0xC644B0
void __fastcall hkJobQueue::addJob(hkJobQueue *this, hkJobQueue::JobQueueEntry *job, hkJobQueue::JobPriority priority)
{
  hkJobQueue::JobQueueEntry *v3; // rsi
  hkJobQueue::JobPriority v4; // edi
  hkJobQueue *v5; // rbp
  hkJobQueue::DynamicData *v6; // rax
  char dynamicDataStorage; // [rsp+20h] [rbp-2A8h]

  v3 = job;
  v4 = priority;
  v5 = this;
  v6 = hkJobQueue::lockQueue(this, &dynamicDataStorage);
  hkJobQueue::addJobQueueLocked(v5, v6, v3, v4);
  hkJobQueue::unlockQueue(&v5->m_criticalSection.m_section);
}

// File Line: 856
// RVA: 0xC64460
void __fastcall hkJobQueue::addJob(hkJobQueue *this, hkJob *job, hkJobQueue::JobPriority priority)
{
  hkJobQueue::JobPriority v3; // ebx
  hkJobQueue *v4; // rdi
  char dst; // [rsp+20h] [rbp-108h]

  v3 = priority;
  v4 = this;
  hkString::memCpy(&dst, job, job->m_size);
  hkJobQueue::addJob(v4, (hkJobQueue::JobQueueEntry *)&dst, v3);
}

// File Line: 865
// RVA: 0xC63890
void __fastcall hkJobQueue::addJobBatch(hkJobQueue *this, hkArrayBase<hkJob *> *jobs, hkJobQueue::JobPriority priority)
{
  hkJobQueue *v3; // rbp
  hkJobQueue::JobPriority v4; // er12
  hkArrayBase<hkJob *> *v5; // r15
  _QWORD *v6; // r9
  _QWORD *v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  int v10; // esi
  hkJobQueue::DynamicData *v11; // rdi
  __int64 v12; // r14
  int v13; // eax
  int v14; // ebx
  _QWORD *v15; // rax
  _QWORD *v16; // rcx
  _QWORD *v17; // r8
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  hkJobQueue::JobQueueEntry dst; // [rsp+20h] [rbp-3B8h]
  char dynamicDataStorage; // [rsp+120h] [rbp-2B8h]

  v3 = this;
  v4 = priority;
  v5 = jobs;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtAddJobBatch";
    v8 = __rdtsc();
    v9 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v9 - 8) = v8;
    v6[1] = v9;
  }
  v10 = 0;
  v11 = hkJobQueue::lockQueue(v3, &dynamicDataStorage);
  if ( v5->m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkString::memCpy(&dst, v5->m_data[v12], v5->m_data[v12]->m_size);
      v13 = hkJobQueue::getQueueIndexForJob(v3, (hkJob *)&dst.m_jobSubType);
      v14 = v13;
      if ( v4 )
        hkQueue<hkJobQueue::JobQueueEntry>::enqueue(
          (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11 + 8 * (v13 + 2 * (v13 + 4i64))),
          &dst);
      else
        hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(
          (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11 + 8 * (v13 + 2 * (v13 + 4i64))),
          &dst);
      hkJobQueue::checkQueueAndReleaseOneWaitingThread(v3, v14, v11);
      ++v10;
      ++v12;
    }
    while ( v10 < v5->m_size );
  }
  hkJobQueue::unlockQueue(&v3->m_criticalSection.m_section);
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = (_QWORD *)v15[1];
  v17 = v15;
  if ( (unsigned __int64)v16 < v15[3] )
  {
    *v16 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v16 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v17[1] = v19;
  }
}

// File Line: 899
// RVA: 0xC63E90
void __fastcall hkJobQueue::setWaitPolicy(hkJobQueue *this, hkJobQueue::WaitPolicy waitPolicy)
{
  hkJobQueue::WaitPolicy v2; // ebx
  hkJobQueue *v3; // rdi
  hkJobQueue::DynamicData *v4; // rax
  char dynamicDataStorage; // [rsp+20h] [rbp-2A8h]

  v2 = waitPolicy;
  v3 = this;
  v4 = hkJobQueue::lockQueue(this, &dynamicDataStorage);
  v3->m_data->m_waitPolicy = v2;
  if ( v2 == WAIT_UNTIL_ALL_WORK_COMPLETE )
    hkJobQueue::releaseWaitingThreads(v3, v4);
  hkJobQueue::unlockQueue(&v3->m_criticalSection.m_section);
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
  int v2; // ebx
  hkJobQueue *v3; // rdi
  hkJobQueue::DynamicData *v4; // rax
  __int64 v5; // rdx
  unsigned __int16 v6; // cx
  char dynamicDataStorage; // [rsp+20h] [rbp-2A8h]

  v2 = flags;
  v3 = this;
  v4 = hkJobQueue::lockQueue(this, &dynamicDataStorage);
  v3->m_data->m_masterThreadFinishingFlags = v2;
  v5 = v3->m_cpuThreadIndexToSemaphoreIndex[0];
  v6 = v4->m_numThreadsWaiting[v5];
  if ( v6 )
  {
    v4->m_numThreadsWaiting[v5] = v6 - 1;
    hkSemaphore::release(v3->m_queueSemaphores[v3->m_cpuThreadIndexToSemaphoreIndex[0]], 1);
  }
  hkJobQueue::unlockQueue(&v3->m_criticalSection.m_section);
}

// File Line: 1086
// RVA: 0xC65190
signed __int64 __fastcall hkJobQueue::findJobInternal(hkJobQueue *this, int queueIndexOfNewJob, hkJobQueue::DynamicData *data, hkJobQueue::WaitStatus waitStatus, hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue *v5; // rdi
  hkJobQueue::WaitStatus v6; // er12
  hkJobQueue::DynamicData *v7; // rbx
  int v8; // ebp
  int v9; // eax
  char *v10; // rdx
  int v11; // esi
  signed __int64 v12; // r14
  signed __int64 result; // rax
  int v14; // er15
  char *v15; // rcx
  __int128 *v16; // rdx
  signed __int64 v17; // rax
  __int128 v18; // xmm0
  int v19; // eax
  __int64 v20; // r9
  __int64 v21; // r10
  int v22; // edx
  int v23; // er8
  int v24; // er11
  int *v25; // rcx
  unsigned __int64 v26; // rax
  int v27; // er9
  int v28; // er8
  int v29; // ecx
  __int64 i; // rdx
  signed int v31; // eax
  signed int v32; // eax
  bool v33; // si
  __int64 v34; // rax
  signed __int64 v35; // rcx
  unsigned __int16 v36; // ax
  __int64 v37; // rsi
  _QWORD *v38; // r9
  unsigned __int64 v39; // r8
  unsigned __int64 v40; // rax
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  char Dst; // [rsp+20h] [rbp-128h]
  unsigned __int8 v46; // [rsp+21h] [rbp-127h]

  v5 = this;
  v6 = waitStatus;
  v7 = data;
  v8 = queueIndexOfNewJob;
  if ( (unsigned int)TlsGetValue(hkThreadNumber.m_slotID) )
    v9 = v5->m_cpuThreadIndexToSemaphoreIndex[(signed int)TlsGetValue(hkThreadNumber.m_slotID)];
  else
    v9 = v5->m_masterThreadQueue;
  v10 = v5->m_nextQueueToGet[v9];
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
      v12 = (signed __int64)&v7->m_numActiveJobs[12 * v11];
      if ( v7->m_jobQueue[v11].m_elementsInUse )
        break;
      v11 = *v10;
      if ( v11 < 0 )
        goto LABEL_7;
    }
    v14 = *(_DWORD *)(v12 + 76);
    v15 = &Dst;
    v16 = (__int128 *)(*(_QWORD *)(v12 + 64) + ((signed __int64)*(signed int *)(v12 + 76) << 8));
    if ( ((unsigned __int8)&Dst | *(_BYTE *)(v12 + 64)) & 0xF )
    {
      memmove(&Dst, v16, 0x100ui64);
    }
    else
    {
      v17 = 2i64;
      do
      {
        v18 = *v16;
        v15 += 128;
        v16 += 8;
        *((_OWORD *)v15 - 8) = v18;
        *((_OWORD *)v15 - 7) = *(v16 - 7);
        *((_OWORD *)v15 - 6) = *(v16 - 6);
        *((_OWORD *)v15 - 5) = *(v16 - 5);
        *((_OWORD *)v15 - 4) = *(v16 - 4);
        *((_OWORD *)v15 - 3) = *(v16 - 3);
        *((_OWORD *)v15 - 2) = *(v16 - 2);
        *((_OWORD *)v15 - 1) = *(v16 - 1);
        --v17;
      }
      while ( v17 );
    }
    v19 = v14 + 1;
    if ( v14 + 1 == *(_DWORD *)(v12 + 72) )
      v19 = 0;
    --*(_DWORD *)(v12 + 84);
    *(_DWORD *)(v12 + 76) = v19;
    if ( v5->m_popJobFunc(v5, v7, (hkJobQueue::JobQueueEntry *)&Dst, jobOut) == 1 )
    {
      hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(
        (hkQueue<hkJobQueue::JobQueueEntry> *)(v12 + 64),
        (hkJobQueue::JobQueueEntry *)&Dst);
      hkJobQueue::checkQueueAndReleaseOneWaitingThread(v5, v11, v7);
    }
    ++v7->m_numActiveJobs[v46];
  }
  if ( v8 != -1 && v8 != v11 )
    hkJobQueue::checkQueueAndReleaseOneWaitingThread(v5, v8, v7);
  if ( v11 >= 0 )
  {
    hkJobQueue::unlockQueue(&v5->m_criticalSection.m_section);
    return 0i64;
  }
  v20 = v5->m_cpuSemaphoreBegin;
  v21 = v5->m_directMapSemaphoreEnd;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  if ( v20 >= v21 )
    goto LABEL_53;
  if ( v21 - v20 >= 2 )
  {
    v25 = &v7->m_jobQueue[v20 + 1].m_elementsInUse;
    v26 = ((unsigned __int64)(v21 - v20 - 2) >> 1) + 1;
    v20 += 2 * v26;
    do
    {
      v22 += *(v25 - 6);
      v23 += *v25;
      v25 += 12;
      --v26;
    }
    while ( v26 );
  }
  if ( v20 < v21 )
    v24 = v7->m_jobQueue[v20].m_elementsInUse;
  if ( !(v23 + v22 + v24) )
  {
LABEL_53:
    v27 = v5->m_numJobTypes;
    v28 = 0;
    v29 = 0;
    for ( i = 0i64; v29 < v27; v28 |= v32 )
    {
      if ( v7->m_numActiveJobs[i] > 0 || (v31 = 0, v7->m_jobQueue[i + v5->m_cpuTypesQueuesBegin].m_elementsInUse) )
        v31 = 1;
      v32 = v31 << v29++;
      ++i;
    }
    v33 = v28 == 0;
    if ( !(v28 & v7->m_masterThreadFinishingFlags) )
    {
      if ( !(unsigned int)TlsGetValue(hkThreadNumber.m_slotID) )
      {
        if ( !v33 )
        {
LABEL_39:
          hkJobQueue::unlockQueue(&v5->m_criticalSection.m_section);
          return 2i64;
        }
LABEL_38:
        hkJobQueue::releaseWaitingThreads(v5, v7);
        goto LABEL_39;
      }
      v34 = v5->m_cpuThreadIndexToSemaphoreIndex[0];
      v35 = (signed __int64)&v7->m_numActiveJobs[v34];
      v36 = v7->m_numThreadsWaiting[v34];
      if ( v36 )
      {
        *(_WORD *)(v35 + 50) = v36 - 1;
        hkSemaphore::release(v5->m_queueSemaphores[v5->m_cpuThreadIndexToSemaphoreIndex[0]], 1);
      }
    }
    if ( v33 && v7->m_waitPolicy != 1 )
      goto LABEL_38;
  }
  if ( v6 == 1 )
  {
    hkJobQueue::unlockQueue(&v5->m_criticalSection.m_section);
    result = 1i64;
  }
  else
  {
    v37 = v5->m_cpuThreadIndexToSemaphoreIndex[(signed int)TlsGetValue(hkThreadNumber.m_slotID)];
    ++v7->m_numThreadsWaiting[v37];
    hkJobQueue::unlockQueue(&v5->m_criticalSection.m_section);
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = v38[1];
    if ( v39 < v38[3] )
    {
      *(_QWORD *)v39 = "TtNoJobAvailable";
      v40 = __rdtsc();
      *(_DWORD *)(v39 + 8) = v40;
      v38[1] = v39 + 16;
    }
    hkSemaphore::acquire(v5->m_queueSemaphores[v37]);
    v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v42 = (_QWORD *)v41[1];
    if ( (unsigned __int64)v42 < v41[3] )
    {
      *v42 = "Et";
      v43 = __rdtsc();
      v44 = (signed __int64)(v42 + 2);
      *(_DWORD *)(v44 - 8) = v43;
      v41[1] = v44;
    }
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 1222
// RVA: 0xC645C0
void __fastcall hkJobQueue::finishJob(hkJobQueue *this, hkJobQueue::JobQueueEntry *oldJob, hkJobQueue::FinishJobFlag flag)
{
  hkJobQueue *v3; // rdi
  hkJobQueue::FinishJobFlag v4; // er14
  hkJobQueue::JobQueueEntry *v5; // rbp
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  hkJobQueue::DynamicData *v11; // rbx
  int v12; // eax
  int v13; // esi
  _QWORD *v14; // rax
  _QWORD *v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  signed __int64 v18; // rcx
  int v19; // [rsp+20h] [rbp-3B8h]
  hkJob job; // [rsp+30h] [rbp-3A8h]
  char dynamicDataStorage; // [rsp+130h] [rbp-2A8h]

  v3 = this;
  v4 = flag;
  v5 = oldJob;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtfinishJob";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = hkJobQueue::lockQueue(v3, &dynamicDataStorage);
  if ( !(unsigned int)v3->m_finishJobFunc(v3, v11, v5, (hkJobQueue::JobQueueEntryInput *)&v19) )
  {
    v12 = hkJobQueue::getQueueIndexForJob(v3, &job);
    v13 = v12;
    if ( v19 )
      hkQueue<hkJobQueue::JobQueueEntry>::enqueue(
        (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11 + 8 * (v12 + 2 * (v12 + 4i64))),
        (hkJobQueue::JobQueueEntry *)&job);
    else
      hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(
        (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v11 + 8 * (v12 + 2 * (v12 + 4i64))),
        (hkJobQueue::JobQueueEntry *)&job);
    hkJobQueue::checkQueueAndReleaseOneWaitingThread(v3, v13, v11);
  }
  if ( v4 == FINISH_FLAG_NORMAL )
    --v11->m_numActiveJobs[(unsigned __int8)v5->m_jobType.m_storage];
  hkJobQueue::unlockQueue(&v3->m_criticalSection.m_section);
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  v16 = v14;
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v17 = __rdtsc();
    v18 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v18 - 8) = v17;
    v16[1] = v18;
  }
}

// File Line: 1313
// RVA: 0xC64730
__int64 __fastcall hkJobQueue::finishJobAndGetNextJob(hkJobQueue *this, hkJobQueue::JobQueueEntry *oldJob, hkJobQueue::JobQueueEntry *jobOut, hkJobQueue::WaitStatus waitStatus)
{
  hkJobQueue *v4; // rdi
  hkJobQueue::WaitStatus v5; // er14
  hkJobQueue::JobQueueEntry *v6; // r15
  hkJobQueue::JobQueueEntry *v7; // rsi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkJobQueue::DynamicData *v13; // rax
  int v14; // ebp
  hkJobQueue::DynamicData *v15; // rbx
  hkQueue<hkJobQueue::JobQueueEntry> *v16; // rcx
  hkJobQueue::JobStatus v17; // ebx
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  int v23; // [rsp+30h] [rbp-3C8h]
  hkJob job; // [rsp+40h] [rbp-3B8h]
  char dynamicDataStorage; // [rsp+140h] [rbp-2B8h]

  v4 = this;
  v5 = waitStatus;
  v6 = jobOut;
  v7 = oldJob;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtGetNextJob";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  do
  {
    v13 = hkJobQueue::lockQueue(v4, &dynamicDataStorage);
    v14 = -1;
    v15 = v13;
    if ( v7 )
    {
      if ( !(unsigned int)v4->m_finishJobFunc(v4, v13, v7, (hkJobQueue::JobQueueEntryInput *)&v23) )
      {
        v14 = hkJobQueue::getQueueIndexForJob(v4, &job);
        v16 = (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v15 + 8 * (v14 + 2i64 * v14 + 8));
        if ( v23 )
          hkQueue<hkJobQueue::JobQueueEntry>::enqueue(v16, (hkJobQueue::JobQueueEntry *)&job);
        else
          hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(v16, (hkJobQueue::JobQueueEntry *)&job);
      }
      --v15->m_numActiveJobs[(unsigned __int8)v7->m_jobType.m_storage];
      v7 = 0i64;
    }
    v17 = hkJobQueue::findJobInternal(v4, v14, v15, v5, v6);
  }
  while ( v17 == -1 );
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v21 - 8) = v20;
    v18[1] = v21;
  }
  return v17;
}

// File Line: 1420
// RVA: 0xC64420
void __fastcall hkJobQueue::registerJobHandler(hkJobQueue *this, hkJobType jobId, hkJobQueue::hkJobHandlerFuncs *jobHandlerFuncs)
{
  this->m_jobFuncs[jobId] = *jobHandlerFuncs;
}

// File Line: 1428
// RVA: 0xC64890
__int64 __fastcall hkJobQueue::finishAddAndGetNextJob(hkJobQueue *this, hkJobType oldJobType, hkJobQueue::JobPriority priority, hkJobQueue::JobQueueEntry *jobInOut, hkJobQueue::WaitStatus waitStatus)
{
  hkJobQueue *v5; // r14
  hkJobQueue::JobQueueEntry *jobOut; // rbx
  hkJobQueue::JobPriority v7; // er12
  __int64 v8; // r13
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r9
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  char v14; // di
  hkJobQueue::DynamicData *v15; // rax
  int v16; // ebp
  hkJobQueue::DynamicData *v17; // rsi
  hkQueue<hkJobQueue::JobQueueEntry> *v18; // rcx
  hkJobQueue::JobStatus v19; // esi
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  char dynamicDataStorage; // [rsp+30h] [rbp-2C8h]

  v5 = this;
  jobOut = jobInOut;
  v7 = priority;
  v8 = oldJobType;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtGetNextJob";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = 1;
  do
  {
    v15 = hkJobQueue::lockQueue(v5, &dynamicDataStorage);
    v16 = -1;
    v17 = v15;
    if ( v14 )
    {
      --v15->m_numActiveJobs[v8];
      v16 = hkJobQueue::getQueueIndexForJob(v5, (hkJob *)&jobOut->m_jobSubType);
      v18 = (hkQueue<hkJobQueue::JobQueueEntry> *)((char *)v17 + 8 * (v16 + 2i64 * v16 + 8));
      if ( v7 )
        hkQueue<hkJobQueue::JobQueueEntry>::enqueue(v18, jobOut);
      else
        hkQueue<hkJobQueue::JobQueueEntry>::enqueueInFront(v18, jobOut);
      v14 = 0;
    }
    v19 = hkJobQueue::findJobInternal(v5, v16, v17, waitStatus, jobOut);
  }
  while ( v19 == -1 );
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v20[1] = v23;
  }
  return v19;
}

// File Line: 1471
// RVA: 0xC64B60
void __fastcall hkJobQueue::releaseWaitingThreads(hkJobQueue *this, hkJobQueue::DynamicData *data)
{
  hkJobQueue *v2; // r14
  int v3; // ebp
  hkSemaphore **v4; // rdi
  unsigned __int16 *v5; // rsi
  int v6; // ebx

  v2 = this;
  v3 = 0;
  if ( this->m_numQueueSemaphores > 0 )
  {
    v4 = this->m_queueSemaphores;
    v5 = data->m_numThreadsWaiting;
    do
    {
      v6 = *v5;
      for ( *v5 = 0; v6 > 0; --v6 )
        hkSemaphore::release(*v4, 1);
      ++v3;
      ++v5;
      ++v4;
    }
    while ( v3 < v2->m_numQueueSemaphores );
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

