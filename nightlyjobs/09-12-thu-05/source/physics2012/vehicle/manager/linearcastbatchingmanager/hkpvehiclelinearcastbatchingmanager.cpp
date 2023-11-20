// File Line: 21
// RVA: 0xE2EF20
void __fastcall hkpVehicleLinearCastBatchingManager::getTotalNumCommands(hkpVehicleLinearCastBatchingManager *this, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles, int *numCommands, int *numWheels)
{
  int v4; // ebx
  int *v5; // r14
  int *v6; // r15
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v7; // rsi
  __int64 v8; // rdi
  int v9; // eax

  v4 = 0;
  v5 = numWheels;
  v6 = numCommands;
  *numCommands = 0;
  *numWheels = 0;
  v7 = activeVehicles;
  if ( activeVehicles->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = ((__int64 (*)(void))v7->m_data[v8]->m_wheelCollide->vfptr[6].__vecDelDtor)();
      ++v4;
      ++v8;
      *v6 += v9;
      *v5 += (unsigned __int8)v7->m_data[v8 - 1]->m_data->m_numWheels;
    }
    while ( v4 < v7->m_size );
  }
}

// File Line: 34
// RVA: 0xE2E9C0
__int64 __fastcall hkpVehicleLinearCastBatchingManager::getBufferSize(hkpVehicleLinearCastBatchingManager *this, int numJobs, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int v3; // ebx
  int numWheels; // [rsp+38h] [rbp+10h]
  int numCommands; // [rsp+48h] [rbp+20h]

  v3 = numJobs;
  hkpVehicleLinearCastBatchingManager::getTotalNumCommands(this, activeVehicles, &numCommands, &numWheels);
  return ((16 * v3 + 15) & 0xFFFFFFF0)
       + (((numCommands << 6) + 15) & 0xFFFFFFF0)
       + ((112 * numWheels + 15) & 0xFFFFFFF0)
       + ((80 * numCommands + 15) & 0xFFFFFFF0);
}

// File Line: 50
// RVA: 0xE2EFB0
void __fastcall hkpVehicleLinearCastBatchingManager::getLinearCastBatchFromBuffer(hkpVehicleLinearCastBatchingManager *this, void *buffer, int numJobs, hkpVehicleLinearCastBatchingManager::LinearCastBatch *batchOut, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkpCollidable *v5; // rbx
  hkpVehicleLinearCastBatchingManager::LinearCastBatch *v6; // rdi
  int v7; // ecx
  int v8; // eax
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // rbx
  int numWheels; // [rsp+38h] [rbp+10h]
  int numCommands; // [rsp+48h] [rbp+20h]

  v5 = (hkpCollidable *)buffer;
  v6 = batchOut;
  hkpVehicleLinearCastBatchingManager::getTotalNumCommands(this, activeVehicles, &numCommands, &numWheels);
  v7 = numCommands;
  v8 = 112 * numWheels + 15;
  v6->m_collidableStorage = v5;
  v9 = (unsigned __int64)v5 + (v8 & 0xFFFFFFFFFFFFFFF0ui64);
  v6->m_commandStorage = (hkpPairLinearCastCommand *)v9;
  v10 = ((80 * v7 + 15) & 0xFFFFFFFFFFFFFFF0ui64) + v9;
  v6->m_outputStorage = (hkpRootCdPoint *)v10;
  v6->m_jobHeaders = (hkpCollisionQueryJobHeader *)(v10 + (((v7 << 6) + 15) & 0xFFFFFFFFFFFFFFF0ui64));
}

// File Line: 73
// RVA: 0xE2EA30
__int64 __fastcall hkpVehicleLinearCastBatchingManager::buildAndAddCastJobs(hkpVehicleLinearCastBatchingManager *this, hkpWorld *world, int filterSize, int numJobs, hkJobQueue *jobQueue, hkSemaphore *semaphore, void *buffer, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v8; // r13
  __int64 v9; // rbx
  hkpPairLinearCastCommand *v10; // rcx
  hkpCollidable *v11; // r14
  hkpRootCdPoint *v12; // r12
  int v13; // esi
  __int64 v14; // rdi
  hkpPairLinearCastCommand *v15; // r15
  hkpVehicleInstance *v16; // rbx
  int v17; // eax
  int v18; // edi
  int v20; // eax
  hkpCollisionQueryJobHeader *v21; // rsi
  int v22; // er14
  int v23; // edx
  int i; // er13
  hkpProcessCollisionInput *v25; // rax
  int v26; // ebx
  __int64 v27; // [rsp+30h] [rbp-89h]
  hkpCollisionFilter *v28; // [rsp+38h] [rbp-81h]
  hkpVehicleLinearCastBatchingManager::LinearCastBatch batchOut; // [rsp+40h] [rbp-79h]
  hkpPairLinearCastJob v30; // [rsp+60h] [rbp-59h]
  hkpWorld *v31; // [rsp+108h] [rbp+4Fh]
  int v32; // [rsp+118h] [rbp+5Fh]
  int v33; // [rsp+118h] [rbp+5Fh]
  hkpPairLinearCastCommand *activeVehiclesa; // [rsp+138h] [rbp+7Fh]

  v32 = numJobs;
  v31 = world;
  v8 = activeVehicles;
  v9 = activeVehicles->m_size;
  v28 = world->m_collisionFilter;
  hkpVehicleLinearCastBatchingManager::getLinearCastBatchFromBuffer(this, buffer, numJobs, &batchOut, activeVehicles);
  v10 = batchOut.m_commandStorage;
  v11 = batchOut.m_collidableStorage;
  v12 = batchOut.m_outputStorage;
  v13 = 0;
  v14 = 0i64;
  activeVehiclesa = batchOut.m_commandStorage;
  v15 = batchOut.m_commandStorage;
  v27 = v9;
  if ( (signed int)v9 > 0 )
  {
    do
    {
      v16 = v8->m_data[v14];
      v17 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, hkpCollisionFilter *, hkpCollidable *, hkpPairLinearCastCommand *, hkpRootCdPoint *))v16->m_wheelCollide->vfptr[7].__vecDelDtor)(
              v16->m_wheelCollide,
              v8->m_data[v14++],
              v28,
              v11,
              v15,
              v12);
      v13 += v17;
      v15 += v17;
      v11 += (unsigned __int8)v16->m_data->m_numWheels;
      v12 += v17;
    }
    while ( v14 < v27 );
    v10 = batchOut.m_commandStorage;
  }
  v18 = v13;
  if ( v32 < v13 )
    v18 = v32;
  if ( !v18 )
    return 0i64;
  v20 = v13;
  v21 = batchOut.m_jobHeaders;
  v22 = 0;
  v23 = v20 % v18;
  v33 = v20 % v18;
  for ( i = v20 / v18; v22 < v18; activeVehiclesa += v26 )
  {
    v30.m_size = 96;
    v25 = v31->m_collisionInput;
    v30.m_commandArray = v10;
    v30.m_collisionInput = v25;
    *(_WORD *)&v30.m_jobSubType = 515;
    v26 = i + (v22 < v23);
    v30.m_jobSpuType.m_storage = 2;
    v30.m_threadAffinity = -1;
    v30.m_jobDoneFlag = 0i64;
    v30.m_sharedJobHeaderOnPpu = v21;
    v30.m_tolerance = 0.0;
    v30.m_numCommandsPerTask = 128;
    v30.m_semaphore = semaphore;
    v30.m_numCommands = v26;
    v30.m_maxExtraPenetration = 0.00000011920929;
    v30.m_iterativeLinearCastEarlyOutDistance = 0.0099999998;
    v30.m_iterativeLinearCastMaxIterations = 10;
    v21->m_openJobs = (v26 - 1) / 128 + 1;
    hkpPairLinearCastJob::setRunsOnSpuOrPpu(&v30);
    hkJobQueue::addJob(jobQueue, (hkJob *)&v30.m_jobSubType, JOB_LOW_PRIORITY);
    ++v22;
    ++v21;
    v10 = &activeVehiclesa[v26];
    v23 = v33;
  }
  return (unsigned int)v18;
}

// File Line: 157
// RVA: 0xE2EC30
void __usercall hkpVehicleLinearCastBatchingManager::stepVehiclesUsingCastResults(hkpVehicleLinearCastBatchingManager *this@<rcx>, hkStepInfo *updatedStepInfo@<rdx>, int numJobs@<r8d>, void *buffer@<r9>, hkStepInfo *a5@<rbx>, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *a6@<rdi>, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v7; // rsi
  __int64 v8; // rbx
  hkpPairLinearCastCommand *v9; // r12
  hkLifoAllocator *v10; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v11; // rdi
  unsigned __int64 v12; // rcx
  signed int v13; // ecx
  __int64 v14; // r13
  int v15; // ecx
  hkpVehicleInstance *v16; // r14
  int v17; // er15
  int v18; // er9
  unsigned __int8 v19; // si
  hkpVehicleWheelCollide *i; // rbx
  __int64 v21; // rax
  hkBaseObjectVtbl *v22; // r10
  signed __int64 v23; // rdi
  int v24; // eax
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // er8
  hkResult result; // [rsp+28h] [rbp-21h]
  __int64 v29; // [rsp+30h] [rbp-19h]
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *array; // [rsp+38h] [rbp-11h]
  int v31; // [rsp+40h] [rbp-9h]
  int v32; // [rsp+44h] [rbp-5h]
  void *p; // [rsp+48h] [rbp-1h]
  int v34; // [rsp+50h] [rbp+7h]
  hkpVehicleLinearCastBatchingManager::LinearCastBatch batchOut; // [rsp+58h] [rbp+Fh]
  hkStepInfo *stepInfo; // [rsp+B0h] [rbp+67h]
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v37; // [rsp+C8h] [rbp+7Fh]
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v38; // [rsp+C8h] [rbp+7Fh]

  stepInfo = a5;
  v7 = v37;
  v8 = v37->m_size;
  v38 = a6;
  hkpVehicleLinearCastBatchingManager::getLinearCastBatchFromBuffer(this, buffer, numJobs, &batchOut, v7);
  v9 = batchOut.m_commandStorage;
  array = 0i64;
  v31 = 0;
  v32 = 2147483648;
  v34 = 16;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)v10->m_cur;
  v12 = (unsigned __int64)&v11[16];
  if ( v10->m_slabSize < 1536 || (void *)v12 > v10->m_end )
    v11 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(v10, 1536);
  else
    v10->m_cur = (void *)v12;
  v13 = -2147483632;
  array = v11;
  p = v11;
  v14 = 0i64;
  v29 = v8;
  v32 = -2147483632;
  if ( (signed int)v8 <= 0 )
    goto LABEL_29;
  while ( 1 )
  {
    v15 = v13 & 0x3FFFFFFF;
    v16 = v7->m_data[v14];
    v17 = (unsigned __int8)v16->m_data->m_numWheels;
    if ( v15 >= v17 )
    {
      result.m_enum = 0;
    }
    else
    {
      v18 = (unsigned __int8)v16->m_data->m_numWheels;
      if ( v17 < 2 * v15 )
        v18 = 2 * v15;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 96);
    }
    v19 = 0;
    v31 = v17;
    for ( i = v16->m_wheelCollide; v19 < v17; v9 += v24 )
    {
      v21 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, _QWORD, hkpPairLinearCastCommand *))i->vfptr[7].__first_virtual_table_function__)(
              i,
              v19,
              v9);
      v22 = i->vfptr;
      if ( v21 )
      {
        v23 = v19;
        ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, __int64, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *, _QWORD))v22[8].__first_virtual_table_function__)(
          i,
          v16,
          v19,
          v21,
          &array[v23],
          *(_QWORD *)&result.m_enum);
      }
      else
      {
        v23 = v19;
        ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v22[9].__vecDelDtor)(
          i,
          v16,
          v19,
          &array[v23]);
      }
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
  v11 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)p;
  if ( p == array )
LABEL_29:
    v31 = 0;
  v25 = (96 * v34 + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)v11 + v27 != v26->m_cur || v26->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v26, v11, v27);
  else
    v26->m_cur = v11;
  v31 = 0;
  if ( v32 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      96 * (v32 & 0x3FFFFFFF));
}

