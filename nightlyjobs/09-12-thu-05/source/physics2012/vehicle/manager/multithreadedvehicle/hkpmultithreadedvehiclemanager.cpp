// File Line: 19
// RVA: 0xE2BD70
void __fastcall hkpMultithreadedVehicleManager::stepVehiclesSynchronously(
        hkpMultithreadedVehicleManager *this,
        hkpWorld *world,
        hkStepInfo *updatedStepInfo,
        hkJobThreadPool *threadPool,
        hkJobQueue *jobQueue,
        int numJobs)
{
  int m_size; // ebx
  hkLifoAllocator *Value; // rcx
  hkpVehicleInstance **m_cur; // rax
  int v13; // r8d
  char *v14; // rdx
  int v15; // ebx
  char *v16; // rdi
  signed int v17; // ebx
  hkLifoAllocator *v18; // rax
  int v19; // r8d
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> activeVehicles; // [rsp+30h] [rbp-38h] BYREF
  void *p; // [rsp+40h] [rbp-28h]
  int v22; // [rsp+48h] [rbp-20h]

  m_size = this->m_registeredVehicles.m_size;
  activeVehicles.m_data = 0i64;
  activeVehicles.m_size = 0;
  activeVehicles.m_capacityAndFlags = 0x80000000;
  v22 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpVehicleInstance **)Value->m_cur;
    v13 = (8 * m_size + 127) & 0xFFFFFF80;
    v14 = (char *)m_cur + v13;
    if ( v13 > Value->m_slabSize || v14 > Value->m_end )
      m_cur = (hkpVehicleInstance **)hkLifoAllocator::allocateFromNewSlab(Value, v13);
    else
      Value->m_cur = v14;
  }
  else
  {
    m_cur = 0i64;
  }
  activeVehicles.m_data = m_cur;
  p = m_cur;
  activeVehicles.m_capacityAndFlags = m_size | 0x80000000;
  hkpVehicleManager::getActiveVehicles(this, &activeVehicles);
  v15 = activeVehicles.m_size;
  if ( activeVehicles.m_size )
  {
    if ( v15 >= hkpMultithreadedVehicleManager::getMultithreadSpeedupThreshold(&activeVehicles) )
      hkpMultithreadedVehicleManager::stepVehicleArraySynchronously(
        &activeVehicles,
        world,
        updatedStepInfo,
        threadPool,
        jobQueue,
        numJobs);
    else
      hkpVehicleManager::stepVehicleArray(&activeVehicles, updatedStepInfo);
    v15 = activeVehicles.m_size;
  }
  v16 = (char *)p;
  if ( p == activeVehicles.m_data )
    v15 = 0;
  activeVehicles.m_size = v15;
  v17 = (8 * v22 + 127) & 0xFFFFFF80;
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (v17 + 15) & 0xFFFFFFF0;
  if ( v17 > v18->m_slabSize || &v16[v19] != v18->m_cur || v18->m_firstNonLifoEnd == v16 )
    hkLifoAllocator::slowBlockFree(v18, v16, v19);
  else
    v18->m_cur = v16;
  activeVehicles.m_size = 0;
  if ( activeVehicles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      activeVehicles.m_data,
      8 * activeVehicles.m_capacityAndFlags);
}

// File Line: 39
// RVA: 0xE2BF20
void __fastcall hkpMultithreadedVehicleManager::stepVehicleArraySynchronously(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles,
        hkpWorld *world,
        hkStepInfo *updatedStepInfo,
        hkJobThreadPool *threadPool,
        hkJobQueue *jobQueue,
        int numJobs)
{
  int BufferSize; // edi
  hkLifoAllocator *Value; // rax
  char *buffer; // rbx
  int v13; // edi
  char *v14; // rdx
  hkLifoAllocator *v15; // rax
  int v16; // r8d

  BufferSize = hkpMultithreadedVehicleManager::getBufferSize(vehicles);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  buffer = (char *)Value->m_cur;
  v13 = (BufferSize + 127) & 0xFFFFFF80;
  v14 = &buffer[v13];
  if ( v13 > Value->m_slabSize || v14 > Value->m_end )
    buffer = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v13);
  else
    Value->m_cur = v14;
  hkpMultithreadedVehicleManager::updateBeforeCollisionDetection(vehicles);
  if ( hkpMultithreadedVehicleManager::buildAndAddJobs(vehicles, world, updatedStepInfo, numJobs, jobQueue, buffer) )
  {
    hkpWorld::lockReadOnly(world);
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))threadPool->vfptr[5].__first_virtual_table_function__)(
      threadPool,
      jobQueue,
      20i64);
    hkJobQueue::processAllJobs(jobQueue, 1);
    ((void (__fastcall *)(hkJobThreadPool *))threadPool->vfptr[2].__vecDelDtor)(threadPool);
    hkpWorld::unlockReadOnly(world);
    hkpMultithreadedVehicleManager::stepVehiclesUsingJobResults(vehicles, updatedStepInfo, buffer);
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
__int64 __fastcall hkpMultithreadedVehicleManager::getBufferSize(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles)
{
  return ((16 * vehicles->m_size + 15) & 0xFFFFFFF0) + ((624 * vehicles->m_size + 15) & 0xFFFFFFF0);
}

// File Line: 91
// RVA: 0xE2C090
void __fastcall hkpMultithreadedVehicleManager::updateBeforeCollisionDetection(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles)
{
  __int64 m_size; // rsi
  __int64 i; // rbx

  m_size = vehicles->m_size;
  for ( i = 0i64; i < m_size; ++i )
    hkpVehicleInstance::updateBeforeCollisionDetection(vehicles->m_data[i]);
}

// File Line: 100
// RVA: 0xE2C0E0
void __fastcall hkpMultithreadedVehicleManager::buildVehicleCommand(
        hkpVehicleWheelCollide *wheelCollide,
        hkpVehicleInstance *vehicle,
        hkpVehicleCommand *commandStorage,
        hkpVehicleJobResults *outputStorage)
{
  int v7; // ebp
  char v8; // bl
  __int64 v9; // rcx

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
        v9 = *(_QWORD *)(*(_QWORD *)&wheelCollide[1].m_memSizeAndFlags + 96i64 * v8);
        (*(void (__fastcall **)(__int64, hkpVehicleInstance *))(*(_QWORD *)v9 + 88i64))(v9, vehicle);
        ++v8;
      }
      while ( v8 < v7 );
      commandStorage->m_jobResults = outputStorage;
    }
  }
  else
  {
    (*(void (__fastcall **)(_QWORD, hkpVehicleInstance *))(**(_QWORD **)&wheelCollide[1].m_memSizeAndFlags + 88i64))(
      *(_QWORD *)&wheelCollide[1].m_memSizeAndFlags,
      vehicle);
    commandStorage->m_jobResults = outputStorage;
  }
}

// File Line: 129
// RVA: 0xE2C180
__int64 __fastcall hkpMultithreadedVehicleManager::buildAndAddJobs(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles,
        hkpWorld *world,
        hkStepInfo *updatedStepInfo,
        int numJobs,
        hkJobQueue *jobQueue,
        void *buffer)
{
  __int64 m_size; // rbp
  hkpVehicleCommand *m_commandStorage; // r12
  hkpVehicleJobResults *m_outputStorage; // rsi
  int v11; // r15d
  __int64 v12; // rbx
  hkpVehicleCommand *v13; // rdi
  int v14; // edi
  int v16; // ebp
  int v17; // esi
  int i; // ecx
  hkpVehicleInstance **m_data; // rax
  int v20; // ebx
  hkpMultithreadedVehicleManager::VehicleCommandBatch commandBatch; // [rsp+20h] [rbp-88h] BYREF
  hkpVehicleIntegrateJob v22; // [rsp+30h] [rbp-78h] BYREF

  hkpMultithreadedVehicleManager::getVehicleBatchFromBuffer(vehicles, buffer, &commandBatch);
  m_size = vehicles->m_size;
  m_commandStorage = commandBatch.m_commandStorage;
  m_outputStorage = commandBatch.m_outputStorage;
  v11 = 0;
  v12 = 0i64;
  v13 = commandBatch.m_commandStorage;
  if ( m_size > 0 )
  {
    v11 = vehicles->m_size;
    do
    {
      hkpMultithreadedVehicleManager::buildVehicleCommand(
        vehicles->m_data[v12]->m_wheelCollide,
        vehicles->m_data[v12],
        v13,
        m_outputStorage);
      ++v12;
      ++v13;
      ++m_outputStorage;
    }
    while ( v12 < m_size );
  }
  v14 = v11;
  if ( numJobs < v11 )
    v14 = numJobs;
  if ( !v14 )
    return 0i64;
  v16 = 0;
  v17 = 0;
  for ( i = v11 % v14; v17 < v14; i = v11 % v14 )
  {
    v22.m_size = 64;
    *(_WORD *)&v22.m_jobSubType = 4352;
    v22.m_stepInfo = *updatedStepInfo;
    m_data = vehicles->m_data;
    v22.m_jobSpuType.m_storage = 2;
    v20 = v11 / v14 + (v17 < i);
    v22.m_threadAffinity = -1;
    v22.m_vehicleArrayPtr = &m_data[v16];
    v22.m_commandArray = m_commandStorage;
    v22.m_numCommands = v20;
    hkpVehicleIntegrateJob::setRunsOnSpuOrPpu(&v22);
    hkJobQueue::addJob(jobQueue, &v22, JOB_HIGH_PRIORITY);
    ++v17;
    v16 += v20;
    m_commandStorage += v20;
  }
  return (unsigned int)v14;
}

// File Line: 202
// RVA: 0xE2C2F0
void __fastcall hkpMultithreadedVehicleManager::getVehicleBatchFromBuffer(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles,
        hkpVehicleCommand *vehicleBuffer,
        hkpMultithreadedVehicleManager::VehicleCommandBatch *commandBatch)
{
  int m_size; // eax

  m_size = vehicles->m_size;
  commandBatch->m_commandStorage = vehicleBuffer;
  commandBatch->m_outputStorage = (hkpVehicleJobResults *)((char *)vehicleBuffer
                                                         + ((16 * m_size + 15) & 0xFFFFFFFFFFFFFFF0ui64));
}

// File Line: 215
// RVA: 0xE2C310
void __fastcall hkpMultithreadedVehicleManager::stepVehiclesUsingJobResults(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles,
        hkStepInfo *stepInfo,
        hkpVehicleCommand *buffer)
{
  __int64 m_size; // rbp
  hkpVehicleCommand *m_commandStorage; // rdi
  __int64 i; // rbx
  hkpMultithreadedVehicleManager::VehicleCommandBatch commandBatch; // [rsp+20h] [rbp-18h] BYREF

  hkpMultithreadedVehicleManager::getVehicleBatchFromBuffer(vehicles, buffer, &commandBatch);
  m_size = vehicles->m_size;
  m_commandStorage = commandBatch.m_commandStorage;
  for ( i = 0i64; i < m_size; ++m_commandStorage )
    hkpVehicleJobResults::applyForcesFromStep(m_commandStorage->m_jobResults, vehicles->m_data[i++]);
}

// File Line: 233
// RVA: 0xE2C390
__int64 __fastcall hkpMultithreadedVehicleManager::getMultithreadSpeedupThreshold(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *vehicles)
{
  __int64 result; // rax

  result = 6i64;
  if ( (*vehicles->m_data)->m_wheelCollide->m_type.m_storage != 2 )
    return 12i64;
  return result;
}

