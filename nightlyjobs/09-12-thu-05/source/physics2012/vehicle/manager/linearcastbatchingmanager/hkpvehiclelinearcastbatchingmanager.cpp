// File Line: 21
// RVA: 0xE2EF20
void __fastcall hkpVehicleLinearCastBatchingManager::getTotalNumCommands(
        hkpVehicleLinearCastBatchingManager *this,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles,
        int *numCommands,
        int *numWheels)
{
  int v4; // ebx
  __int64 v8; // rdi
  hkpVehicleWheelCollide *m_wheelCollide; // rcx

  v4 = 0;
  *numCommands = 0;
  *numWheels = 0;
  if ( activeVehicles->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_wheelCollide = activeVehicles->m_data[v8]->m_wheelCollide;
      ++v4;
      ++v8;
      *numCommands += ((__int64 (__fastcall *)(hkpVehicleWheelCollide *))m_wheelCollide->vfptr[6].__vecDelDtor)(m_wheelCollide);
      *numWheels += (unsigned __int8)activeVehicles->m_data[v8 - 1]->m_data->m_numWheels;
    }
    while ( v4 < activeVehicles->m_size );
  }
}

// File Line: 34
// RVA: 0xE2E9C0
__int64 __fastcall hkpVehicleLinearCastBatchingManager::getBufferSize(
        hkpVehicleLinearCastBatchingManager *this,
        int numJobs,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int numWheels; // [rsp+38h] [rbp+10h] BYREF
  int numCommands; // [rsp+48h] [rbp+20h] BYREF

  hkpVehicleLinearCastBatchingManager::getTotalNumCommands(this, activeVehicles, &numCommands, &numWheels);
  return ((16 * numJobs + 15) & 0xFFFFFFF0)
       + (((numCommands << 6) + 15) & 0xFFFFFFF0)
       + ((112 * numWheels + 15) & 0xFFFFFFF0)
       + ((80 * numCommands + 15) & 0xFFFFFFF0);
}

// File Line: 50
// RVA: 0xE2EFB0
void __fastcall hkpVehicleLinearCastBatchingManager::getLinearCastBatchFromBuffer(
        hkpVehicleLinearCastBatchingManager *this,
        hkpCollidable *buffer,
        int numJobs,
        hkpVehicleLinearCastBatchingManager::LinearCastBatch *batchOut,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int v7; // ecx
  int v8; // eax
  hkpPairLinearCastCommand *v9; // rbx
  hkpRootCdPoint *v10; // rbx
  int numWheels; // [rsp+38h] [rbp+10h] BYREF
  int numCommands; // [rsp+48h] [rbp+20h] BYREF

  hkpVehicleLinearCastBatchingManager::getTotalNumCommands(this, activeVehicles, &numCommands, &numWheels);
  v7 = numCommands;
  v8 = 112 * numWheels + 15;
  batchOut->m_collidableStorage = buffer;
  v9 = (hkpPairLinearCastCommand *)((char *)buffer + (v8 & 0xFFFFFFFFFFFFFFF0ui64));
  batchOut->m_commandStorage = v9;
  v10 = (hkpRootCdPoint *)((char *)v9 + ((80 * v7 + 15) & 0xFFFFFFFFFFFFFFF0ui64));
  batchOut->m_outputStorage = v10;
  batchOut->m_jobHeaders = (hkpCollisionQueryJobHeader *)((char *)v10 + (((v7 << 6) + 15) & 0xFFFFFFFFFFFFFFF0ui64));
}

// File Line: 73
// RVA: 0xE2EA30
__int64 __fastcall hkpVehicleLinearCastBatchingManager::buildAndAddCastJobs(
        hkpVehicleLinearCastBatchingManager *this,
        hkpWorld *world,
        int filterSize,
        int numJobs,
        hkJobQueue *jobQueue,
        hkSemaphore *semaphore,
        void *buffer,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  __int64 m_size; // rbx
  hkpPairLinearCastCommand *m_commandStorage; // rcx
  hkpCollidable *m_collidableStorage; // r14
  hkpRootCdPoint *m_outputStorage; // r12
  int v13; // esi
  __int64 v14; // rdi
  hkpPairLinearCastCommand *v15; // r15
  hkpVehicleInstance *v16; // rbx
  int v17; // eax
  int v18; // edi
  int v20; // eax
  hkpCollisionQueryJobHeader *m_jobHeaders; // rsi
  int v22; // r14d
  int v23; // edx
  int i; // r13d
  hkpProcessCollisionInput *m_collisionInput; // rax
  int v26; // ebx
  __int64 v27; // [rsp+30h] [rbp-89h]
  hkpCollisionFilter *m_collisionFilter; // [rsp+38h] [rbp-81h]
  hkpVehicleLinearCastBatchingManager::LinearCastBatch batchOut; // [rsp+40h] [rbp-79h] BYREF
  hkpPairLinearCastJob v30; // [rsp+60h] [rbp-59h] BYREF
  int v33; // [rsp+118h] [rbp+5Fh]
  hkpPairLinearCastCommand *activeVehiclesa; // [rsp+138h] [rbp+7Fh]

  m_size = activeVehicles->m_size;
  m_collisionFilter = world->m_collisionFilter;
  hkpVehicleLinearCastBatchingManager::getLinearCastBatchFromBuffer(this, buffer, numJobs, &batchOut, activeVehicles);
  m_commandStorage = batchOut.m_commandStorage;
  m_collidableStorage = batchOut.m_collidableStorage;
  m_outputStorage = batchOut.m_outputStorage;
  v13 = 0;
  v14 = 0i64;
  activeVehiclesa = batchOut.m_commandStorage;
  v15 = batchOut.m_commandStorage;
  v27 = m_size;
  if ( (int)m_size > 0 )
  {
    do
    {
      v16 = activeVehicles->m_data[v14];
      v17 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, hkpCollisionFilter *, hkpCollidable *, hkpPairLinearCastCommand *, hkpRootCdPoint *))v16->m_wheelCollide->vfptr[7].__vecDelDtor)(
              v16->m_wheelCollide,
              v16,
              m_collisionFilter,
              m_collidableStorage,
              v15,
              m_outputStorage);
      ++v14;
      v13 += v17;
      v15 += v17;
      m_collidableStorage += (unsigned __int8)v16->m_data->m_numWheels;
      m_outputStorage += v17;
    }
    while ( v14 < v27 );
    m_commandStorage = batchOut.m_commandStorage;
  }
  v18 = v13;
  if ( numJobs < v13 )
    v18 = numJobs;
  if ( !v18 )
    return 0i64;
  v20 = v13;
  m_jobHeaders = batchOut.m_jobHeaders;
  v22 = 0;
  v23 = v20 % v18;
  v33 = v20 % v18;
  for ( i = v20 / v18; v22 < v18; activeVehiclesa = m_commandStorage )
  {
    v30.m_size = 96;
    m_collisionInput = world->m_collisionInput;
    v30.m_commandArray = m_commandStorage;
    v30.m_collisionInput = m_collisionInput;
    *(_WORD *)&v30.m_jobSubType = 515;
    v26 = i + (v22 < v23);
    v30.m_jobSpuType.m_storage = 2;
    v30.m_threadAffinity = -1;
    v30.m_jobDoneFlag = 0i64;
    v30.m_sharedJobHeaderOnPpu = m_jobHeaders;
    v30.m_tolerance = 0.0;
    v30.m_numCommandsPerTask = 128;
    v30.m_semaphore = semaphore;
    v30.m_numCommands = v26;
    v30.m_maxExtraPenetration = 0.00000011920929;
    v30.m_iterativeLinearCastEarlyOutDistance = 0.0099999998;
    v30.m_iterativeLinearCastMaxIterations = 10;
    m_jobHeaders->m_openJobs = (v26 - 1) / 128 + 1;
    hkpPairLinearCastJob::setRunsOnSpuOrPpu(&v30);
    hkJobQueue::addJob(jobQueue, &v30, JOB_LOW_PRIORITY);
    ++v22;
    ++m_jobHeaders;
    m_commandStorage = &activeVehiclesa[v26];
    v23 = v33;
  }
  return (unsigned int)v18;
}

// File Line: 157
// RVA: 0xE2EC30
void __fastcall hkpVehicleLinearCastBatchingManager::stepVehiclesUsingCastResults(
        hkpVehicleLinearCastBatchingManager *this,
        hkStepInfo *updatedStepInfo,
        int numJobs,
        void *buffer,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkStepInfo *v5; // rbx
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v6; // rdi
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v7; // rsi
  __int64 m_size; // rbx
  hkpPairLinearCastCommand *m_commandStorage; // r12
  hkLifoAllocator *Value; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *m_cur; // rdi
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v12; // rcx
  int v13; // ecx
  __int64 v14; // r13
  int v15; // ecx
  hkpVehicleInstance *v16; // r14
  int m_numWheels; // r15d
  int v18; // r9d
  unsigned __int8 v19; // si
  hkpVehicleWheelCollide *i; // rbx
  __int64 v21; // rax
  hkBaseObjectVtbl *vfptr; // r10
  __int64 v23; // rdi
  int v24; // eax
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // r8d
  hkResult result; // [rsp+28h] [rbp-21h] BYREF
  __int64 v29; // [rsp+30h] [rbp-19h]
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *array; // [rsp+38h] [rbp-11h] BYREF
  int v31; // [rsp+40h] [rbp-9h]
  int v32; // [rsp+44h] [rbp-5h]
  void *p; // [rsp+48h] [rbp-1h]
  int v34; // [rsp+50h] [rbp+7h]
  hkpVehicleLinearCastBatchingManager::LinearCastBatch batchOut; // [rsp+58h] [rbp+Fh] BYREF
  hkStepInfo *stepInfo; // [rsp+B0h] [rbp+67h]
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v37; // [rsp+C8h] [rbp+7Fh]
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v38; // [rsp+C8h] [rbp+7Fh]

  stepInfo = v5;
  v7 = v37;
  m_size = v37->m_size;
  v38 = v6;
  hkpVehicleLinearCastBatchingManager::getLinearCastBatchFromBuffer(this, buffer, numJobs, &batchOut, v7);
  m_commandStorage = batchOut.m_commandStorage;
  array = 0i64;
  v31 = 0;
  v32 = 0x80000000;
  v34 = 16;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)Value->m_cur;
  v12 = m_cur + 16;
  if ( Value->m_slabSize < 1536 || v12 > Value->m_end )
    m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(Value, 1536);
  else
    Value->m_cur = v12;
  v13 = -2147483632;
  array = m_cur;
  p = m_cur;
  v14 = 0i64;
  v29 = m_size;
  v32 = -2147483632;
  if ( (int)m_size <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    v15 = v13 & 0x3FFFFFFF;
    v16 = v7->m_data[v14];
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
    }
    v19 = 0;
    v31 = m_numWheels;
    for ( i = v16->m_wheelCollide; v19 < m_numWheels; m_commandStorage += v24 )
    {
      v21 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, _QWORD, hkpPairLinearCastCommand *))i->vfptr[7].__first_virtual_table_function__)(
              i,
              v19,
              m_commandStorage);
      vfptr = i->vfptr;
      v23 = v19;
      if ( v21 )
        ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, __int64, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *, hkResultEnum))vfptr[8].__first_virtual_table_function__)(
          i,
          v16,
          v19,
          v21,
          &array[v23],
          result.m_enum);
      else
        ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))vfptr[9].__vecDelDtor)(
          i,
          v16,
          v19,
          &array[v23]);
      ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))i->vfptr[5].__first_virtual_table_function__)(
        i,
        v16,
        v19,
        &array[v23]);
      v24 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, _QWORD))i->vfptr[6].__first_virtual_table_function__)(
              i,
              v19++);
    }
    v7 = v38;
    hkpVehicleInstance::stepVehicleUsingWheelCollideOutput(v38->m_data[v14++], stepInfo, array);
    if ( v14 >= v29 )
      break;
    v13 = v32;
  }
  m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)p;
  if ( p == array )
LABEL_19:
    v31 = 0;
  v25 = (96 * v34 + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)m_cur + v27 != v26->m_cur || v26->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v26, (char *)m_cur, v27);
  else
    v26->m_cur = m_cur;
  v31 = 0;
  if ( v32 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 96 * (v32 & 0x3FFFFFFF));
}

