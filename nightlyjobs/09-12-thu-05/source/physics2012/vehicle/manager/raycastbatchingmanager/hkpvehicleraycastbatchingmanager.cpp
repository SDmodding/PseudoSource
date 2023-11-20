// File Line: 21
// RVA: 0xE301D0
__int64 __fastcall hkpVehicleRayCastBatchingManager::getBufferSize(hkpVehicleRayCastBatchingManager *this, int numJobs, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  signed __int64 v3; // rbp
  int v4; // er10
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v5; // rsi
  int v6; // er11
  int v7; // er14
  signed __int64 v8; // rbx
  hkpVehicleInstance **v9; // r9
  unsigned __int64 v10; // r8
  hkpVehicleInstance *v11; // rax

  v3 = activeVehicles->m_size;
  v4 = 0;
  v5 = activeVehicles;
  v6 = 0;
  v7 = 0;
  v8 = 0i64;
  if ( v3 >= 2 )
  {
    v9 = activeVehicles->m_data;
    v10 = ((unsigned __int64)(v3 - 2) >> 1) + 1;
    v8 = 2 * v10;
    do
    {
      v11 = *v9;
      v9 += 2;
      v4 += (unsigned __int8)v11->m_data->m_numWheels;
      v6 += (unsigned __int8)(*(v9 - 1))->m_data->m_numWheels;
      --v10;
    }
    while ( v10 );
  }
  if ( v8 < v3 )
    v7 = (unsigned __int8)v5->m_data[v8]->m_data->m_numWheels;
  return (((_DWORD)v3 + 15) & 0xFFFFFFF0)
       + ((16 * numJobs + 15) & 0xFFFFFFF0)
       + ((96 * (v6 + v4 + v7) + 15) & 0xFFFFFFF0)
       + ((112 * (v6 + v4 + v7) + 15) & 0xFFFFFFF0);
}

// File Line: 40
// RVA: 0xE307E0
void __fastcall hkpVehicleRayCastBatchingManager::getRaycastBatchFromBuffer(hkpVehicleRayCastBatchingManager *this, void *raycastBuffer, int numJobs, hkpVehicleRayCastBatchingManager::RaycastBatch *raycastBatch, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int v5; // er10
  hkpShapeRayCastCommand *v6; // r15
  signed __int64 v7; // rbp
  int v8; // er11
  int v9; // esi
  signed __int64 v10; // rbx
  hkpVehicleInstance **v11; // r8
  unsigned __int64 v12; // rdx
  hkpVehicleInstance *v13; // rax
  int v14; // esi
  hkpWorldRayCastOutput *v15; // rdx
  char *v16; // rdx

  v5 = 0;
  v6 = (hkpShapeRayCastCommand *)raycastBuffer;
  v7 = activeVehicles->m_size;
  v8 = 0;
  v9 = 0;
  v10 = 0i64;
  if ( v7 >= 2 )
  {
    v11 = activeVehicles->m_data;
    v12 = ((unsigned __int64)(v7 - 2) >> 1) + 1;
    v10 = 2 * v12;
    do
    {
      v13 = *v11;
      v11 += 2;
      v5 += (unsigned __int8)v13->m_data->m_numWheels;
      v8 += (unsigned __int8)(*(v11 - 1))->m_data->m_numWheels;
      --v12;
    }
    while ( v12 );
  }
  if ( v10 < v7 )
    v9 = (unsigned __int8)activeVehicles->m_data[v10]->m_data->m_numWheels;
  v14 = v8 + v5 + v9;
  raycastBatch->m_commandStorage = v6;
  v15 = (hkpWorldRayCastOutput *)((char *)v6 + ((112 * v14 + 15) & 0xFFFFFFFFFFFFFFF0ui64));
  raycastBatch->m_outputStorage = v15;
  v16 = (char *)v15 + ((96 * v14 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
  raycastBatch->m_index = v16;
  raycastBatch->m_jobHeaders = (hkpCollisionQueryJobHeader *)&v16[((signed int)v7 + 15) & 0xFFFFFFFFFFFFFFF0ui64];
}

// File Line: 68
// RVA: 0xE302A0
__int64 __fastcall hkpVehicleRayCastBatchingManager::buildAndAddCastJobs(hkpVehicleRayCastBatchingManager *this, hkpWorld *world, int filterSize, int numJobs, hkJobQueue *jobQueue, hkSemaphore *semaphore, void *buffer, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v8; // r12
  __int64 v9; // rbx
  int v10; // er13
  hkpShapeRayCastCommand *v11; // r8
  hkpWorldRayCastOutput *v12; // r14
  int v13; // esi
  hkpShapeRayCastCommand *v14; // rbp
  __int64 v15; // r15
  char *v16; // rbx
  __int64 v17; // rdi
  int v18; // eax
  int v19; // edi
  int v21; // eax
  hkpCollisionQueryJobHeader *v22; // rsi
  int v23; // ebp
  int v24; // er13
  int i; // er12
  int v26; // ebx
  hkpCollisionFilter *v27; // [rsp+30h] [rbp-B8h]
  hkpVehicleRayCastBatchingManager::RaycastBatch raycastBatch; // [rsp+38h] [rbp-B0h]
  hkpShapeRayCastJob v29; // [rsp+60h] [rbp-88h]
  hkpWorld *v30; // [rsp+F8h] [rbp+10h]
  unsigned int v31; // [rsp+100h] [rbp+18h]
  int v32; // [rsp+108h] [rbp+20h]
  hkpShapeRayCastCommand *activeVehiclesa; // [rsp+128h] [rbp+40h]

  v32 = numJobs;
  v31 = filterSize;
  v30 = world;
  v8 = activeVehicles;
  v9 = activeVehicles->m_size;
  v10 = numJobs;
  v27 = world->m_collisionFilter;
  hkpVehicleRayCastBatchingManager::getRaycastBatchFromBuffer(this, buffer, numJobs, &raycastBatch, activeVehicles);
  v11 = raycastBatch.m_commandStorage;
  v12 = raycastBatch.m_outputStorage;
  v13 = 0;
  activeVehiclesa = raycastBatch.m_commandStorage;
  v14 = raycastBatch.m_commandStorage;
  v15 = v9;
  if ( (signed int)v9 > 0 )
  {
    v16 = raycastBatch.m_index;
    v17 = 0i64;
    do
    {
      v18 = ((__int64 (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, hkpCollisionFilter *, _QWORD, hkpShapeRayCastCommand *, hkpWorldRayCastOutput *))v8->m_data[v17]->m_wheelCollide->vfptr[6].__vecDelDtor)(
              v8->m_data[v17]->m_wheelCollide,
              v8->m_data[v17],
              v27,
              v31,
              v14,
              v12);
      if ( v18 <= 0 )
      {
        *v16 = 0;
      }
      else
      {
        v13 += v18;
        *v16 = v18;
        v14 += v18;
        v12 += v18;
      }
      ++v17;
      ++v16;
      --v15;
    }
    while ( v15 );
    v10 = v32;
    v11 = raycastBatch.m_commandStorage;
  }
  v19 = v13;
  if ( v10 < v13 )
    v19 = v10;
  if ( !v19 )
    return 0i64;
  v21 = v13;
  v22 = raycastBatch.m_jobHeaders;
  v23 = 0;
  v24 = v21 % v19;
  for ( i = v21 / v19; v23 < v19; activeVehiclesa += v26 )
  {
    v29.m_size = 80;
    v29.m_threadAffinity = -1;
    v29.m_collisionInput = v30->m_collisionInput;
    v26 = i + (v23 < v24);
    *(_WORD *)&v29.m_jobSubType = 768;
    v29.m_jobDoneFlag = 0i64;
    v29.m_jobSpuType.m_storage = 1;
    v29.m_sharedJobHeaderOnPpu = v22;
    v29.m_numCommandsPerTask = 90;
    v29.m_semaphore = semaphore;
    v29.m_commandArray = v11;
    v29.m_numCommands = i + (v23 < v24);
    v22->m_openJobs = ((signed int)(v26 - 1 + ((unsigned __int64)(-1240768329i64 * (v26 - 1)) >> 32)) >> 6)
                    + ((unsigned int)(v26 - 1 + ((unsigned __int64)(-1240768329i64 * (v26 - 1)) >> 32)) >> 31)
                    + 1;
    hkpShapeRayCastJob::setRunsOnSpuOrPpu(&v29);
    hkJobQueue::addJob(jobQueue, (hkJob *)&v29.m_jobSubType, JOB_LOW_PRIORITY);
    v11 = &activeVehiclesa[v26];
    ++v23;
    ++v22;
  }
  return (unsigned int)v19;
}

// File Line: 156
// RVA: 0xE304E0
void __usercall hkpVehicleRayCastBatchingManager::stepVehiclesUsingCastResults(hkpVehicleRayCastBatchingManager *this@<rcx>, hkStepInfo *updatedStepInfo@<rdx>, int numJobs@<r8d>, void *buffer@<r9>, hkStepInfo *a5@<rbx>, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v6; // rsi
  __int64 v7; // rbx
  hkpShapeRayCastCommand *v8; // r14
  hkLifoAllocator *v9; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v10; // rdi
  unsigned __int64 v11; // rcx
  signed int v12; // ecx
  __int64 v13; // rdx
  int v14; // ecx
  hkpVehicleInstance *v15; // r13
  int v16; // ebx
  int v17; // er9
  hkpVehicleWheelCollide *v18; // r12
  unsigned __int8 v19; // bl
  int v20; // er15
  signed __int64 v21; // rsi
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // er8
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *array; // [rsp+28h] [rbp-31h]
  int v26; // [rsp+30h] [rbp-29h]
  int v27; // [rsp+34h] [rbp-25h]
  void *p; // [rsp+38h] [rbp-21h]
  int v29; // [rsp+40h] [rbp-19h]
  __int64 v30; // [rsp+48h] [rbp-11h]
  int v31; // [rsp+50h] [rbp-9h]
  hkResult result; // [rsp+54h] [rbp-5h]
  unsigned __int64 v33; // [rsp+58h] [rbp-1h]
  __int64 v34; // [rsp+60h] [rbp+7h]
  hkpVehicleRayCastBatchingManager::RaycastBatch raycastBatch; // [rsp+68h] [rbp+Fh]
  hkStepInfo *stepInfo; // [rsp+C0h] [rbp+67h]
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v37; // [rsp+D8h] [rbp+7Fh]

  stepInfo = a5;
  v6 = v37;
  v7 = v37->m_size;
  hkpVehicleRayCastBatchingManager::getRaycastBatchFromBuffer(this, buffer, numJobs, &raycastBatch, v37);
  v8 = raycastBatch.m_commandStorage;
  v27 = 2147483648;
  array = 0i64;
  v26 = 0;
  v29 = 16;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)v9->m_cur;
  v11 = (unsigned __int64)&v10[16];
  if ( v9->m_slabSize < 1536 || (void *)v11 > v9->m_end )
    v10 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(v9, 1536);
  else
    v9->m_cur = (void *)v11;
  v12 = -2147483632;
  v13 = 0i64;
  array = v10;
  p = v10;
  v34 = v7;
  v27 = -2147483632;
  v30 = 0i64;
  if ( (signed int)v7 <= 0 )
    goto LABEL_34;
  while ( 1 )
  {
    v14 = v12 & 0x3FFFFFFF;
    v15 = v6->m_data[v13];
    v33 = 8 * v13;
    v16 = (unsigned __int8)v15->m_data->m_numWheels;
    if ( v14 >= v16 )
    {
      result.m_enum = 0;
    }
    else
    {
      v17 = (unsigned __int8)v15->m_data->m_numWheels;
      if ( v16 < 2 * v14 )
        v17 = 2 * v14;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v17, 96);
      v10 = array;
      v13 = v30;
    }
    v26 = v16;
    v18 = v15->m_wheelCollide;
    v19 = 0;
    v31 = (unsigned __int8)v15->m_data->m_numWheels;
    if ( v31 > 0 )
    {
      while ( 1 )
      {
        v20 = (unsigned __int8)raycastBatch.m_index[v13];
        if ( raycastBatch.m_index[v13] && v8->m_numResultsOut )
        {
          v21 = (char)v19;
          ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpWorldRayCastOutput *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v18->vfptr[7].__first_virtual_table_function__)(
            v18,
            v15,
            v19,
            v8->m_results,
            &v10[v21]);
        }
        else
        {
          v21 = (char)v19;
          ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v18->vfptr[8].__vecDelDtor)(
            v18,
            v15,
            v19,
            &v10[v21]);
        }
        ((void (__fastcall *)(hkpVehicleWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v18->vfptr[5].__first_virtual_table_function__)(
          v18,
          v15,
          v19,
          &array[v21]);
        if ( v20 )
          ++v8;
        v10 = array;
        if ( (char)++v19 >= v31 )
          break;
        v13 = v30;
      }
      v6 = v37;
    }
    hkpVehicleInstance::stepVehicleUsingWheelCollideOutput(v6->m_data[v33 / 8], stepInfo, v10);
    v13 = v30 + 1;
    v30 = v13;
    if ( v13 >= v34 )
      break;
    v12 = v27;
    v10 = array;
  }
  v10 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)p;
  if ( p == array )
LABEL_34:
    v26 = 0;
  v22 = (96 * v29 + 127) & 0xFFFFFF80;
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (v22 + 15) & 0xFFFFFFF0;
  if ( v22 > v23->m_slabSize || (char *)v10 + v24 != v23->m_cur || v23->m_firstNonLifoEnd == v10 )
    hkLifoAllocator::slowBlockFree(v23, v10, v24);
  else
    v23->m_cur = v10;
  v26 = 0;
  if ( v27 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      96 * (v27 & 0x3FFFFFFF));
}

