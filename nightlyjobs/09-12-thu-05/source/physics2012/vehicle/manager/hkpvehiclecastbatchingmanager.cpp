// File Line: 21
// RVA: 0xE2E6D0
void __fastcall hkpVehicleCastBatchingManager::addVehicle(hkpVehicleCastBatchingManager *this, hkpVehicleInstance *vehicle)
{
  hkpVehicleInstance *v2; // rbx
  hkpVehicleCastBatchingManager *v3; // rdi

  v2 = vehicle;
  v3 = this;
  hkpVehicleManager::addVehicle((hkpVehicleManager *)&this->vfptr, vehicle);
  v3->m_totalNumWheels += (unsigned __int8)v2->m_data->m_numWheels;
}

// File Line: 28
// RVA: 0xE2E710
void __fastcall hkpVehicleCastBatchingManager::removeVehicle(hkpVehicleCastBatchingManager *this, hkpVehicleInstance *vehicle)
{
  hkpVehicleInstance *v2; // rbx
  hkpVehicleCastBatchingManager *v3; // rdi

  v2 = vehicle;
  v3 = this;
  hkpVehicleManager::removeVehicle((hkpVehicleManager *)&this->vfptr, vehicle);
  v3->m_totalNumWheels -= (unsigned __int8)v2->m_data->m_numWheels;
}

// File Line: 36
// RVA: 0xE2E950
void __fastcall hkpVehicleCastBatchingManager::updateBeforeCollisionDetection(hkpVehicleCastBatchingManager *this, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  __int64 v2; // rsi
  __int64 v3; // rbx
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *i; // rdi

  v2 = activeVehicles->m_size;
  v3 = 0i64;
  for ( i = activeVehicles; v3 < v2; ++v3 )
    hkpVehicleInstance::updateBeforeCollisionDetection(i->m_data[v3]);
}

// File Line: 46
// RVA: 0xE2E750
void __fastcall hkpVehicleCastBatchingManager::stepVehiclesSynchronously(hkpVehicleCastBatchingManager *this, hkpWorld *world, hkStepInfo *updatedStepInfo, hkJobThreadPool *threadPool, hkJobQueue *jobQueue, int numJobs, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  hkpWorld *v7; // r12
  hkJobThreadPool *v8; // r13
  hkpVehicleCastBatchingManager *v9; // r14
  int v10; // ebp
  hkLifoAllocator *v11; // rax
  char *v12; // rsi
  int v13; // ebp
  char *v14; // rcx
  _QWORD **v15; // rax
  hkSemaphore *v16; // rax
  hkSemaphore *v17; // rax
  hkSemaphore *v18; // rbx
  hkBaseObjectVtbl *v19; // rdi
  unsigned int v20; // eax
  unsigned int v21; // edi
  _QWORD **v22; // rax
  hkLifoAllocator *v23; // rax
  int v24; // er8
  hkStepInfo *v25; // [rsp+80h] [rbp+18h]

  v25 = updatedStepInfo;
  v7 = world;
  v8 = threadPool;
  v9 = this;
  ((void (__fastcall *)(hkpVehicleCastBatchingManager *, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))this->vfptr[3].__first_virtual_table_function__)(
    this,
    activeVehicles);
  v10 = ((__int64 (__fastcall *)(hkpVehicleCastBatchingManager *, _QWORD, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))v9->vfptr[4].__vecDelDtor)(
          v9,
          (unsigned int)numJobs,
          activeVehicles);
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (char *)v11->m_cur;
  v13 = (v10 + 127) & 0xFFFFFF80;
  v14 = &v12[v13];
  if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    v12 = (char *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
  else
    v11->m_cur = v14;
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(v15[11], 8i64);
  if ( v16 )
  {
    hkSemaphore::hkSemaphore(v16, 0, 1000, 0);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = v9->vfptr;
  v20 = hkpVehicleCastBatchingManager::getStandardFilterSize(v7);
  v21 = ((__int64 (__fastcall *)(hkpVehicleCastBatchingManager *, hkpWorld *, _QWORD, _QWORD, hkJobQueue *, hkSemaphore *, char *, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))v19[4].__first_virtual_table_function__)(
          v9,
          v7,
          v20,
          (unsigned int)numJobs,
          jobQueue,
          v18,
          v12,
          activeVehicles);
  if ( v21 )
  {
    hkpWorld::lockReadOnly(v7);
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))v8->vfptr[5].__first_virtual_table_function__)(
      v8,
      jobQueue,
      20i64);
    hkJobQueue::processAllJobs(jobQueue, 0);
    ((void (__fastcall *)(hkJobThreadPool *))v8->vfptr[2].__vecDelDtor)(v8);
    hkSemaphore::acquire(v18);
    hkpWorld::unlockReadOnly(v7);
  }
  if ( v18 )
  {
    hkSemaphore::~hkSemaphore(v18);
    v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, signed __int64))(*v22[11] + 16i64))(v22[11], v18, 8i64);
  }
  ((void (__fastcall *)(hkpVehicleCastBatchingManager *, hkStepInfo *, _QWORD, char *, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))v9->vfptr[5].__vecDelDtor)(
    v9,
    v25,
    v21,
    v12,
    activeVehicles);
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v23->m_slabSize || &v12[v24] != v23->m_cur || v23->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v23, v12, v24);
  else
    v23->m_cur = v12;
}

// File Line: 78
// RVA: 0xE2E9A0
signed __int64 __fastcall hkpVehicleCastBatchingManager::getStandardFilterSize(hkpWorld *world)
{
  signed __int64 result; // rax

  result = 0i64;
  if ( world->m_collisionFilter->m_type.m_storage == 2 )
    result = 272i64;
  return result;
}

