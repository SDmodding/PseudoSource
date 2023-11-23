// File Line: 21
// RVA: 0xE301D0
__int64 __fastcall hkpVehicleRayCastBatchingManager::getBufferSize(
        hkpVehicleRayCastBatchingManager *this,
        int numJobs,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  __int64 m_size; // rbp
  int v4; // r10d
  int v6; // r11d
  int m_numWheels; // r14d
  __int64 v8; // rbx
  hkpVehicleInstance **m_data; // r9
  unsigned __int64 v10; // r8
  hkpVehicleInstance *v11; // rax

  m_size = activeVehicles->m_size;
  v4 = 0;
  v6 = 0;
  m_numWheels = 0;
  v8 = 0i64;
  if ( m_size >= 2 )
  {
    m_data = activeVehicles->m_data;
    v10 = ((unsigned __int64)(m_size - 2) >> 1) + 1;
    v8 = 2 * v10;
    do
    {
      v11 = *m_data;
      m_data += 2;
      v4 += (unsigned __int8)v11->m_data->m_numWheels;
      v6 += (unsigned __int8)(*(m_data - 1))->m_data->m_numWheels;
      --v10;
    }
    while ( v10 );
  }
  if ( v8 < m_size )
    m_numWheels = (unsigned __int8)activeVehicles->m_data[v8]->m_data->m_numWheels;
  return (((_DWORD)m_size + 15) & 0xFFFFFFF0)
       + ((16 * numJobs + 15) & 0xFFFFFFF0)
       + ((96 * (v6 + v4 + m_numWheels) + 15) & 0xFFFFFFF0)
       + ((112 * (v6 + v4 + m_numWheels) + 15) & 0xFFFFFFF0);
}

// File Line: 40
// RVA: 0xE307E0
void __fastcall hkpVehicleRayCastBatchingManager::getRaycastBatchFromBuffer(
        hkpVehicleRayCastBatchingManager *this,
        hkpShapeRayCastCommand *raycastBuffer,
        int numJobs,
        hkpVehicleRayCastBatchingManager::RaycastBatch *raycastBatch,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int v5; // r10d
  __int64 m_size; // rbp
  int v8; // r11d
  int m_numWheels; // esi
  __int64 v10; // rbx
  hkpVehicleInstance **m_data; // r8
  unsigned __int64 v12; // rdx
  hkpVehicleInstance *v13; // rax
  int v14; // esi
  hkpWorldRayCastOutput *v15; // rdx
  char *v16; // rdx

  v5 = 0;
  m_size = activeVehicles->m_size;
  v8 = 0;
  m_numWheels = 0;
  v10 = 0i64;
  if ( m_size >= 2 )
  {
    m_data = activeVehicles->m_data;
    v12 = ((unsigned __int64)(m_size - 2) >> 1) + 1;
    v10 = 2 * v12;
    do
    {
      v13 = *m_data;
      m_data += 2;
      v5 += (unsigned __int8)v13->m_data->m_numWheels;
      v8 += (unsigned __int8)(*(m_data - 1))->m_data->m_numWheels;
      --v12;
    }
    while ( v12 );
  }
  if ( v10 < m_size )
    m_numWheels = (unsigned __int8)activeVehicles->m_data[v10]->m_data->m_numWheels;
  v14 = v8 + v5 + m_numWheels;
  raycastBatch->m_commandStorage = raycastBuffer;
  v15 = (hkpWorldRayCastOutput *)((char *)raycastBuffer + ((112 * v14 + 15) & 0xFFFFFFFFFFFFFFF0ui64));
  raycastBatch->m_outputStorage = v15;
  v16 = (char *)v15 + ((96 * v14 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  raycastBatch->m_index = v16;
  raycastBatch->m_jobHeaders = (hkpCollisionQueryJobHeader *)&v16[((int)m_size + 15) & 0xFFFFFFFFFFFFFFF0ui64];
}

// File Line: 68
// RVA: 0xE302A0
__int64 __fastcall hkpVehicleRayCastBatchingManager::buildAndAddCastJobs(
        hkpVehicleRayCastBatchingManager *this,
        hkpWorld *world,
        unsigned int filterSize,
        int numJobs,
        hkJobQueue *jobQueue,
        hkSemaphore *semaphore,
        void *buffer,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  __int64 m_size; // rbx
  int v10; // r13d
  hkpShapeRayCastCommand *m_commandStorage; // r8
  hkpWorldRayCastOutput *m_outputStorage; // r14
  int v13; // esi
  hkpShapeRayCastCommand *v14; // rbp
  __int64 v15; // r15
  char *m_index; // rbx
  __int64 v17; // rdi
  int v18; // eax
  int v19; // edi
  int v21; // eax
  hkpCollisionQueryJobHeader *m_jobHeaders; // rsi
  int v23; // ebp
  int v24; // r13d
  int i; // r12d
  int v26; // ebx
  hkpCollisionFilter *m_collisionFilter; // [rsp+30h] [rbp-B8h]
  hkpVehicleRayCastBatchingManager::RaycastBatch raycastBatch; // [rsp+38h] [rbp-B0h] BYREF
  hkpShapeRayCastJob v29; // [rsp+60h] [rbp-88h] BYREF
  hkpShapeRayCastCommand *activeVehiclesa; // [rsp+128h] [rbp+40h]

  m_size = activeVehicles->m_size;
  v10 = numJobs;
  m_collisionFilter = world->m_collisionFilter;
  hkpVehicleRayCastBatchingManager::getRaycastBatchFromBuffer(this, buffer, numJobs, &raycastBatch, activeVehicles);
  m_commandStorage = raycastBatch.m_commandStorage;
  m_outputStorage = raycastBatch.m_outputStorage;
  v13 = 0;
  activeVehiclesa = raycastBatch.m_commandStorage;
  v14 = raycastBatch.m_commandStorage;
  v15 = m_size;
  if ( (int)m_size > 0 )
  {
    m_index = raycastBatch.m_index;
    v17 = 0i64;
    do
    {
      v18 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, hkpCollisionFilter *, _QWORD, hkpShapeRayCastCommand *, hkpWorldRayCastOutput *))activeVehicles->m_data[v17]->m_wheelCollide->vfptr[6].__vecDelDtor)(
              activeVehicles->m_data[v17]->m_wheelCollide,
              activeVehicles->m_data[v17],
              m_collisionFilter,
              filterSize,
              v14,
              m_outputStorage);
      if ( v18 <= 0 )
      {
        *m_index = 0;
      }
      else
      {
        v13 += v18;
        *m_index = v18;
        v14 += v18;
        m_outputStorage += v18;
      }
      ++v17;
      ++m_index;
      --v15;
    }
    while ( v15 );
    v10 = numJobs;
    m_commandStorage = raycastBatch.m_commandStorage;
  }
  v19 = v13;
  if ( v10 < v13 )
    v19 = v10;
  if ( !v19 )
    return 0i64;
  v21 = v13;
  m_jobHeaders = raycastBatch.m_jobHeaders;
  v23 = 0;
  v24 = v21 % v19;
  for ( i = v21 / v19; v23 < v19; activeVehiclesa = m_commandStorage )
  {
    v29.m_size = 80;
    v29.m_threadAffinity = -1;
    v29.m_collisionInput = world->m_collisionInput;
    v26 = i + (v23 < v24);
    *(_WORD *)&v29.m_jobSubType = 768;
    v29.m_jobDoneFlag = 0i64;
    v29.m_jobSpuType.m_storage = 1;
    v29.m_sharedJobHeaderOnPpu = m_jobHeaders;
    v29.m_numCommandsPerTask = 90;
    v29.m_semaphore = semaphore;
    v29.m_commandArray = m_commandStorage;
    v29.m_numCommands = v26;
    m_jobHeaders->m_openJobs = ((int)((unsigned __int64)(3054198967i64 * (v26 - 1)) >> 32) >> 6)
                             + ((unsigned int)((unsigned __int64)(3054198967i64 * (v26 - 1)) >> 32) >> 31)
                             + 1;
    hkpShapeRayCastJob::setRunsOnSpuOrPpu(&v29);
    hkJobQueue::addJob(jobQueue, &v29, JOB_LOW_PRIORITY);
    m_commandStorage = &activeVehiclesa[v26];
    ++v23;
    ++m_jobHeaders;
  }
  return (unsigned int)v19;
}

// File Line: 156
// RVA: 0xE304E0
void __fastcall hkpVehicleRayCastBatchingManager::stepVehiclesUsingCastResults(
        hkpVehicleRayCastBatchingManager *this,
        hkStepInfo *updatedStepInfo,
        int numJobs,
        void *buffer,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkStepInfo *v5; // rbx
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v6; // rdi
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v7; // rsi
  __int64 m_size; // rbx
  hkpShapeRayCastCommand *m_commandStorage; // r14
  hkLifoAllocator *Value; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *m_cur; // rdi
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v12; // rcx
  int v13; // ecx
  __int64 v14; // rdx
  int v15; // ecx
  hkpVehicleInstance *v16; // r13
  int m_numWheels; // ebx
  int v18; // r9d
  hkpVehicleWheelCollide *m_wheelCollide; // r12
  unsigned __int8 v20; // bl
  int v21; // r15d
  __int64 v22; // rsi
  signed int v23; // ebx
  hkLifoAllocator *v24; // rax
  int v25; // r8d
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *array; // [rsp+28h] [rbp-31h] BYREF
  int v27; // [rsp+30h] [rbp-29h]
  int v28; // [rsp+34h] [rbp-25h]
  void *p; // [rsp+38h] [rbp-21h]
  int v30; // [rsp+40h] [rbp-19h]
  __int64 v31; // [rsp+48h] [rbp-11h]
  int v32; // [rsp+50h] [rbp-9h]
  hkResult result; // [rsp+54h] [rbp-5h] BYREF
  unsigned __int64 v34; // [rsp+58h] [rbp-1h]
  __int64 v35; // [rsp+60h] [rbp+7h]
  hkpVehicleRayCastBatchingManager::RaycastBatch raycastBatch; // [rsp+68h] [rbp+Fh] BYREF
  hkStepInfo *stepInfo; // [rsp+C0h] [rbp+67h]
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v38; // [rsp+D8h] [rbp+7Fh]
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v39; // [rsp+D8h] [rbp+7Fh]

  stepInfo = v5;
  v7 = v38;
  m_size = v38->m_size;
  v39 = v6;
  hkpVehicleRayCastBatchingManager::getRaycastBatchFromBuffer(this, buffer, numJobs, &raycastBatch, v7);
  m_commandStorage = raycastBatch.m_commandStorage;
  v28 = 0x80000000;
  array = 0i64;
  v27 = 0;
  v30 = 16;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)Value->m_cur;
  v12 = m_cur + 16;
  if ( Value->m_slabSize < 1536 || v12 > Value->m_end )
    m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(Value, 1536);
  else
    Value->m_cur = v12;
  v13 = -2147483632;
  v14 = 0i64;
  array = m_cur;
  p = m_cur;
  v35 = m_size;
  v28 = -2147483632;
  v31 = 0i64;
  if ( (int)m_size <= 0 )
    goto LABEL_24;
  while ( 1 )
  {
    v15 = v13 & 0x3FFFFFFF;
    v16 = v7->m_data[v14];
    v34 = 8 * v14;
    m_numWheels = (unsigned __int8)v16->m_data->m_numWheels;
    if ( v15 >= m_numWheels )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v18 = (unsigned __int8)v16->m_data->m_numWheels;
      if ( m_numWheels < 2 * v15 )
        v18 = 2 * v15;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v18, 96);
      m_cur = array;
      v14 = v31;
    }
    v27 = m_numWheels;
    m_wheelCollide = v16->m_wheelCollide;
    v20 = 0;
    v32 = (unsigned __int8)v16->m_data->m_numWheels;
    if ( v32 > 0 )
    {
      while ( 1 )
      {
        v21 = (unsigned __int8)raycastBatch.m_index[v14];
        if ( raycastBatch.m_index[v14] && m_commandStorage->m_numResultsOut )
        {
          v22 = (char)v20;
          ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpWorldRayCastOutput *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))m_wheelCollide->vfptr[7].__first_virtual_table_function__)(
            m_wheelCollide,
            v16,
            v20,
            m_commandStorage->m_results,
            &m_cur[v22]);
        }
        else
        {
          v22 = (char)v20;
          ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))m_wheelCollide->vfptr[8].__vecDelDtor)(
            m_wheelCollide,
            v16,
            v20,
            &m_cur[v22]);
        }
        ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))m_wheelCollide->vfptr[5].__first_virtual_table_function__)(
          m_wheelCollide,
          v16,
          v20,
          &array[v22]);
        if ( v21 )
          ++m_commandStorage;
        m_cur = array;
        if ( (char)++v20 >= v32 )
          break;
        v14 = v31;
      }
      v7 = v39;
    }
    hkpVehicleInstance::stepVehicleUsingWheelCollideOutput(v7->m_data[v34 / 8], stepInfo, m_cur);
    v14 = v31 + 1;
    v31 = v14;
    if ( v14 >= v35 )
      break;
    v13 = v28;
    m_cur = array;
  }
  m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)p;
  if ( p == array )
LABEL_24:
    v27 = 0;
  v23 = (96 * v30 + 127) & 0xFFFFFF80;
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (v23 + 15) & 0xFFFFFFF0;
  if ( v23 > v24->m_slabSize || (char *)m_cur + v25 != v24->m_cur || v24->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v24, (char *)m_cur, v25);
  else
    v24->m_cur = m_cur;
  v27 = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 96 * (v28 & 0x3FFFFFFF));
}

