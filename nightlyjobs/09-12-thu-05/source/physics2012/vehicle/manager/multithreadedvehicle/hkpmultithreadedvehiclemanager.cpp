// File Line: 19
// RVA: 0xE2BD70
void __fastcall hkpMultithreadedVehicleManager::stepVehiclesSynchronously(hkpMultithreadedVehicleManager *this, hkpWorld *world, hkStepInfo *updatedStepInfo, hkJobThreadPool *threadPool, hkJobQueue *jobQueue, int numJobs)
{
  int v6; // ebx
  hkJobThreadPool *v7; // rbp
  hkStepInfo *v8; // rdi
  hkpWorld *v9; // r14
  hkpMultithreadedVehicleManager *v10; // rsi
  LPVOID v11; // rax
  hkLifoAllocator *v12; // rcx
  hkpVehicleInstance **v13; // rax
  int v14; // er8
  char *v15; // rdx
  int v16; // ebx
  char *v17; // rdi
  signed int v18; // ebx
  hkLifoAllocator *v19; // rax
  int v20; // er8
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> activeVehicles; // [rsp+30h] [rbp-38h]
  void *p; // [rsp+40h] [rbp-28h]
  int v23; // [rsp+48h] [rbp-20h]

  v6 = this->m_registeredVehicles.m_size;
  v7 = threadPool;
  v8 = updatedStepInfo;
  v9 = world;
  v10 = this;
  activeVehicles.m_data = 0i64;
  activeVehicles.m_size = 0;
  activeVehicles.m_capacityAndFlags = 2147483648;
  v23 = v6;
  if ( v6 )
  {
    v11 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkLifoAllocator *)v11;
    v13 = (hkpVehicleInstance **)*((_QWORD *)v11 + 3);
    v14 = (8 * v6 + 127) & 0xFFFFFF80;
    v15 = (char *)v13 + v14;
    if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      v13 = (hkpVehicleInstance **)hkLifoAllocator::allocateFromNewSlab(v12, v14);
    else
      v12->m_cur = v15;
  }
  else
  {
    v13 = 0i64;
  }
  activeVehicles.m_data = v13;
  p = v13;
  activeVehicles.m_capacityAndFlags = v6 | 0x80000000;
  hkpVehicleManager::getActiveVehicles((hkpVehicleManager *)&v10->vfptr, &activeVehicles);
  v16 = activeVehicles.m_size;
  if ( activeVehicles.m_size )
  {
    if ( v16 >= hkpMultithreadedVehicleManager::getMultithreadSpeedupThreshold(&activeVehicles) )
      hkpMultithreadedVehicleManager::stepVehicleArraySynchronously(&activeVehicles, v9, v8, v7, jobQueue, numJobs);
    else
      hkpVehicleManager::stepVehicleArray(&activeVehicles, v8);
    v16 = activeVehicles.m_size;
  }
  v17 = (char *)p;
  if ( p == activeVehicles.m_data )
    v16 = 0;
  activeVehicles.m_size = v16;
  v18 = (8 * v23 + 127) & 0xFFFFFF80;
  v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (v18 + 15) & 0xFFFFFFF0;
  if ( v18 > v19->m_slabSize || &v17[v20] != v19->m_cur || v19->m_firstNonLifoEnd == v17 )
    hkLifoAllocator::slowBlockFree(v19, v17, v20);
  else
    v19->m_cur = v17;
  activeVehicles.m_size = 0;
  if ( activeVehicles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      activeVehicles.m_data,
      8 * activeVehicles.m_capacityAndFlags);
}

// File Line: 39
// RVA: 0xE2BF20
void __fastcall hkpMultithreadedVehicleManager::stepVehicleArraySynchronously(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles, hkpWorld *world, hkStepInfo *updatedStepInfo, hkJobThreadPool *threadPool, hkJobQueue *jobQueue, int numJobs)
{
  hkJobThreadPool *v6; // r15
  hkStepInfo *v7; // r12
  hkpWorld *v8; // r14
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v9; // rbp
  int v10; // edi
  hkLifoAllocator *v11; // rax
  char *buffer; // rbx
  int v13; // edi
  char *v14; // rdx
  hkLifoAllocator *v15; // rax
  int v16; // er8

  v6 = threadPool;
  v7 = updatedStepInfo;
  v8 = world;
  v9 = vehicles;
  v10 = hkpMultithreadedVehicleManager::getBufferSize(vehicles);
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  buffer = (char *)v11->m_cur;
  v13 = (v10 + 127) & 0xFFFFFF80;
  v14 = &buffer[v13];
  if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    buffer = (char *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
  else
    v11->m_cur = v14;
  hkpMultithreadedVehicleManager::updateBeforeCollisionDetection(v9);
  if ( hkpMultithreadedVehicleManager::buildAndAddJobs(v9, v8, v7, numJobs, jobQueue, buffer) )
  {
    hkpWorld::lockReadOnly(v8);
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))v6->vfptr[5].__first_virtual_table_function__)(
      v6,
      jobQueue,
      20i64);
    hkJobQueue::processAllJobs(jobQueue, 1);
    ((void (__fastcall *)(hkJobThreadPool *))v6->vfptr[2].__vecDelDtor)(v6);
    hkpWorld::unlockReadOnly(v8);
    hkpMultithreadedVehicleManager::stepVehiclesUsingJobResults(v9, v7, buffer);
  }
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v15->m_slabSize || &buffer[v16] != v15->m_cur || v15->m_firstNonLifoEnd == buffer )
    hkLifoAllocator::slowBlockFree(v15, buffer, v16);
  else
    v15->m_cur = buffer;
}

// File Line: 82
// RVA: 0xE2C060
__int64 __fastcall hkpMultithreadedVehicleManager::getBufferSize(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles)
{
  return ((16 * vehicles->m_size + 15) & 0xFFFFFFF0) + ((624 * vehicles->m_size + 15) & 0xFFFFFFF0);
}

// File Line: 91
// RVA: 0xE2C090
void __fastcall hkpMultithreadedVehicleManager::updateBeforeCollisionDetection(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles)
{
  __int64 v1; // rsi
  __int64 v2; // rbx
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *i; // rdi

  v1 = vehicles->m_size;
  v2 = 0i64;
  for ( i = vehicles; v2 < v1; ++v2 )
    hkpVehicleInstance::updateBeforeCollisionDetection(i->m_data[v2]);
}

// File Line: 100
// RVA: 0xE2C0E0
void __fastcall hkpMultithreadedVehicleManager::buildVehicleCommand(hkpVehicleWheelCollide *wheelCollide, hkpVehicleInstance *vehicle, hkpVehicleCommand *commandStorage, hkpVehicleJobResults *outputStorage)
{
  hkpVehicleJobResults *v4; // rsi
  hkpVehicleCommand *v5; // r14
  hkpVehicleWheelCollide *v6; // rdi
  signed int v7; // ebp
  char v8; // bl
  __int64 v9; // rcx

  v4 = outputStorage;
  v5 = commandStorage;
  v6 = wheelCollide;
  if ( wheelCollide->m_type.m_storage == 2 )
  {
    v7 = *(_DWORD *)&wheelCollide[1].m_alreadyUsed.m_bool;
    v8 = 0;
    if ( v7 <= 0 )
    {
      commandStorage->m_jobResults = outputStorage;
    }
    else
    {
      do
      {
        v9 = *(_QWORD *)(*(_QWORD *)&v6[1].m_memSizeAndFlags + 96i64 * v8);
        (*(void (__fastcall **)(__int64, hkpVehicleInstance *))(*(_QWORD *)v9 + 88i64))(v9, vehicle);
        ++v8;
      }
      while ( v8 < v7 );
      v5->m_jobResults = v4;
    }
  }
  else
  {
    (*(void (__fastcall **)(_QWORD, hkpVehicleInstance *))(**(_QWORD **)&wheelCollide[1].m_memSizeAndFlags + 88i64))(
      *(_QWORD *)&wheelCollide[1].m_memSizeAndFlags,
      vehicle);
    v5->m_jobResults = v4;
  }
}

// File Line: 129
// RVA: 0xE2C180
__int64 __fastcall hkpMultithreadedVehicleManager::buildAndAddJobs(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles, hkpWorld *world, hkStepInfo *updatedStepInfo, int numJobs, hkJobQueue *jobQueue, void *buffer)
{
  int v6; // er13
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v7; // r14
  __int64 v8; // rbp
  hkpVehicleCommand *v9; // r12
  hkpVehicleJobResults *v10; // rsi
  int v11; // er15
  __int64 v12; // rbx
  hkpVehicleCommand *v13; // rdi
  int v14; // edi
  int v16; // ebp
  int v17; // esi
  int v18; // ecx
  int i; // er13
  hkpVehicleInstance **v20; // rax
  int v21; // ebx
  hkpMultithreadedVehicleManager::VehicleCommandBatch commandBatch; // [rsp+20h] [rbp-88h]
  hkpVehicleIntegrateJob v23; // [rsp+30h] [rbp-78h]
  __m128i *v24; // [rsp+C0h] [rbp+18h]

  v24 = (__m128i *)updatedStepInfo;
  v6 = numJobs;
  v7 = vehicles;
  hkpMultithreadedVehicleManager::getVehicleBatchFromBuffer(vehicles, buffer, &commandBatch);
  v8 = v7->m_size;
  v9 = commandBatch.m_commandStorage;
  v10 = commandBatch.m_outputStorage;
  v11 = 0;
  v12 = 0i64;
  v13 = commandBatch.m_commandStorage;
  if ( v8 > 0 )
  {
    v11 = v7->m_size;
    do
    {
      hkpMultithreadedVehicleManager::buildVehicleCommand(v7->m_data[v12]->m_wheelCollide, v7->m_data[v12], v13, v10);
      ++v12;
      ++v13;
      ++v10;
    }
    while ( v12 < v8 );
  }
  v14 = v11;
  if ( v6 < v11 )
    v14 = v6;
  if ( !v14 )
    return 0i64;
  v16 = 0;
  v17 = 0;
  v18 = v11 % v14;
  for ( i = v11 / v14; v17 < v14; v18 = v11 % v14 )
  {
    v23.m_size = 64;
    *(_WORD *)&v23.m_jobSubType = 4352;
    _mm_store_si128((__m128i *)&v23.m_stepInfo, *v24);
    v20 = v7->m_data;
    v23.m_jobSpuType.m_storage = 2;
    v21 = i + (v17 < v18);
    v23.m_threadAffinity = -1;
    v23.m_vehicleArrayPtr = &v20[v16];
    v23.m_commandArray = v9;
    v23.m_numCommands = i + (v17 < v18);
    hkpVehicleIntegrateJob::setRunsOnSpuOrPpu(&v23);
    hkJobQueue::addJob(jobQueue, (hkJob *)&v23.m_jobSubType, 0);
    ++v17;
    v16 += v21;
    v9 += v21;
  }
  return (unsigned int)v14;
}

// File Line: 202
// RVA: 0xE2C2F0
void __fastcall hkpMultithreadedVehicleManager::getVehicleBatchFromBuffer(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles, void *vehicleBuffer, hkpMultithreadedVehicleManager::VehicleCommandBatch *commandBatch)
{
  int v3; // eax

  v3 = vehicles->m_size;
  commandBatch->m_commandStorage = (hkpVehicleCommand *)vehicleBuffer;
  commandBatch->m_outputStorage = (hkpVehicleJobResults *)((char *)vehicleBuffer
                                                         + ((16 * v3 + 15) & 0xFFFFFFFFFFFFFFF0ui64));
}

// File Line: 215
// RVA: 0xE2C310
void __fastcall hkpMultithreadedVehicleManager::stepVehiclesUsingJobResults(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles, hkStepInfo *stepInfo, void *buffer)
{
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v3; // rsi
  __int64 v4; // rbp
  hkpVehicleCommand *v5; // rdi
  __int64 i; // rbx
  hkpMultithreadedVehicleManager::VehicleCommandBatch commandBatch; // [rsp+20h] [rbp-18h]

  v3 = vehicles;
  hkpMultithreadedVehicleManager::getVehicleBatchFromBuffer(vehicles, buffer, &commandBatch);
  v4 = v3->m_size;
  v5 = commandBatch.m_commandStorage;
  for ( i = 0i64; i < v4; ++v5 )
    hkpVehicleJobResults::applyForcesFromStep(v5->m_jobResults, v3->m_data[i++]);
}

// File Line: 233
// RVA: 0xE2C390
signed __int64 __fastcall hkpMultithreadedVehicleManager::getMultithreadSpeedupThreshold(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles)
{
  signed __int64 result; // rax

  result = 6i64;
  if ( (*vehicles->m_data)->m_wheelCollide->m_type.m_storage != 2 )
    result = 12i64;
  return result;
}

