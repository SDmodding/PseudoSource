// File Line: 21
// RVA: 0xE2E6D0
void __fastcall hkpVehicleCastBatchingManager::addVehicle(
        hkpVehicleCastBatchingManager *this,
        hkpVehicleInstance *vehicle)
{
  hkpVehicleManager::addVehicle(this, vehicle);
  this->m_totalNumWheels += (unsigned __int8)vehicle->m_data->m_numWheels;
}

// File Line: 28
// RVA: 0xE2E710
void __fastcall hkpVehicleCastBatchingManager::removeVehicle(
        hkpVehicleCastBatchingManager *this,
        hkpVehicleInstance *vehicle)
{
  hkpVehicleManager::removeVehicle(this, vehicle);
  this->m_totalNumWheels -= (unsigned __int8)vehicle->m_data->m_numWheels;
}

// File Line: 36
// RVA: 0xE2E950
void __fastcall hkpVehicleCastBatchingManager::updateBeforeCollisionDetection(
        hkpVehicleCastBatchingManager *this,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  __int64 m_size; // rsi
  __int64 i; // rbx

  m_size = activeVehicles->m_size;
  for ( i = 0i64; i < m_size; ++i )
    hkpVehicleInstance::updateBeforeCollisionDetection(activeVehicles->m_data[i]);
}

// File Line: 46
// RVA: 0xE2E750
void __fastcall hkpVehicleCastBatchingManager::stepVehiclesSynchronously(
        hkpVehicleCastBatchingManager *this,
        hkpWorld *world,
        hkStepInfo *updatedStepInfo,
        hkJobThreadPool *threadPool,
        hkJobQueue *jobQueue,
        unsigned int numJobs,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int v10; // ebp
  hkLifoAllocator *Value; // rax
  char *m_cur; // rsi
  int v13; // ebp
  char *v14; // rcx
  _QWORD **v15; // rax
  hkSemaphore *v16; // rax
  hkSemaphore *v17; // rax
  hkSemaphore *v18; // rbx
  hkBaseObjectVtbl *vfptr; // rdi
  unsigned int StandardFilterSize; // eax
  unsigned int v21; // edi
  _QWORD **v22; // rax
  hkLifoAllocator *v23; // rax
  int v24; // r8d

  ((void (__fastcall *)(hkpVehicleCastBatchingManager *, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))this->vfptr[3].__first_virtual_table_function__)(
    this,
    activeVehicles);
  v10 = ((__int64 (__fastcall *)(hkpVehicleCastBatchingManager *, _QWORD, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))this->vfptr[4].__vecDelDtor)(
          this,
          numJobs,
          activeVehicles);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v13 = (v10 + 127) & 0xFFFFFF80;
  v14 = &m_cur[v13];
  if ( v13 > Value->m_slabSize || v14 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v13);
  else
    Value->m_cur = v14;
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (hkSemaphore *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v15[11] + 8i64))(v15[11], 8i64);
  if ( v16 )
  {
    hkSemaphore::hkSemaphore(v16, 0, 1000, 0);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  vfptr = this->vfptr;
  StandardFilterSize = hkpVehicleCastBatchingManager::getStandardFilterSize(world);
  v21 = ((__int64 (__fastcall *)(hkpVehicleCastBatchingManager *, hkpWorld *, _QWORD, _QWORD, hkJobQueue *, hkSemaphore *, char *, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))vfptr[4].__first_virtual_table_function__)(
          this,
          world,
          StandardFilterSize,
          numJobs,
          jobQueue,
          v18,
          m_cur,
          activeVehicles);
  if ( v21 )
  {
    hkpWorld::lockReadOnly(world);
    ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))threadPool->vfptr[5].__first_virtual_table_function__)(
      threadPool,
      jobQueue,
      20i64);
    hkJobQueue::processAllJobs(jobQueue, 0);
    ((void (__fastcall *)(hkJobThreadPool *))threadPool->vfptr[2].__vecDelDtor)(threadPool);
    hkSemaphore::acquire(v18);
    hkpWorld::unlockReadOnly(world);
  }
  if ( v18 )
  {
    hkSemaphore::~hkSemaphore(v18);
    v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkSemaphore *, __int64))(*v22[11] + 16i64))(v22[11], v18, 8i64);
  }
  ((void (__fastcall *)(hkpVehicleCastBatchingManager *, hkStepInfo *, _QWORD, char *, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *))this->vfptr[5].__vecDelDtor)(
    this,
    updatedStepInfo,
    v21,
    m_cur,
    activeVehicles);
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v23->m_slabSize || &m_cur[v24] != v23->m_cur || v23->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v23, m_cur, v24);
  else
    v23->m_cur = m_cur;
}

// File Line: 78
// RVA: 0xE2E9A0
__int64 __fastcall hkpVehicleCastBatchingManager::getStandardFilterSize(hkpWorld *world)
{
  __int64 result; // rax

  result = 0i64;
  if ( world->m_collisionFilter->m_type.m_storage == 2 )
    return 272i64;
  return result;
}

