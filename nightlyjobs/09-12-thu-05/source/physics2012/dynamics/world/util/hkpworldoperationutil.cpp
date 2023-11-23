// File Line: 86
// RVA: 0xD7DBF0
void __fastcall hkpWorldOperationUtil::updateEntityBP(hkpWorld *world, hkpEntity *entity)
{
  hkpShape *m_shape; // rax
  __m128i v5; // xmm4
  __m128i v6; // xmm2
  __m128i v7; // xmm3
  int m_broadPhaseQuerySize; // esi
  __m128i v9; // xmm4
  unsigned int v10; // eax
  __m128i v11; // xmm3
  __m128i v12; // xmm4
  __m128i v13; // xmm2
  unsigned int v14; // xmm0_4
  __m128i v15; // xmm3
  __m128i v16; // xmm3
  hkLifoAllocator *Value; // rcx
  hkpBroadPhaseHandlePair *m_cur; // rax
  int v19; // edx
  char *v20; // r8
  int v21; // esi
  hkLifoAllocator *v22; // rcx
  hkpBroadPhaseHandlePair *v23; // rax
  int v24; // edx
  char *v25; // r8
  hkpBroadPhase *m_broadPhase; // rcx
  int m_size; // edx
  hkpCollisionFilter *m_collisionFilter; // r9
  hkpCollidableCollidableFilter *v29; // r9
  char *v30; // rsi
  signed int v31; // ebx
  hkLifoAllocator *v32; // rax
  int v33; // r8d
  int v34; // eax
  char *v35; // rsi
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  bool v39; // zf
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> operation; // [rsp+30h] [rbp-19h] BYREF
  void *p; // [rsp+40h] [rbp-9h]
  int v42; // [rsp+48h] [rbp-1h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+50h] [rbp+7h] BYREF
  void *v44; // [rsp+60h] [rbp+17h]
  int v45; // [rsp+68h] [rbp+1Fh]
  __int64 v46; // [rsp+70h] [rbp+27h] BYREF
  unsigned int v47; // [rsp+78h] [rbp+2Fh]
  __int64 v48; // [rsp+80h] [rbp+37h]
  unsigned int v49; // [rsp+88h] [rbp+3Fh]
  hkpTypedBroadPhaseHandle *p_m_broadPhaseHandle; // [rsp+B0h] [rbp+67h] BYREF
  hkpEntity *entityBatch; // [rsp+B8h] [rbp+6Fh] BYREF

  entityBatch = entity;
  if ( world->m_criticalOperationsLockCount )
  {
    *(_QWORD *)&operation.m_size = entity;
    LOBYTE(operation.m_data) = 3;
    hkpWorld::queueOperation(world, (hkWorldOperation::BaseOperation *)&operation);
  }
  else
  {
    m_shape = entity->m_collidable.m_shape;
    world->m_criticalOperationsLockCount = 1;
    if ( m_shape )
    {
      if ( entity->m_collidable.m_boundingVolumeData.m_min[0] > entity->m_collidable.m_boundingVolumeData.m_max[0] )
        hkpEntityAabbUtil::entityBatchRecalcAabb(world->m_collisionInput, &entityBatch, 1i64);
      v5 = (__m128i)*(unsigned int *)entity->m_collidable.m_boundingVolumeData.m_expansionMin;
      v6 = _mm_cvtsi32_si128(entity->m_collidable.m_boundingVolumeData.m_min[1]);
      v7 = _mm_cvtsi32_si128(entity->m_collidable.m_boundingVolumeData.m_min[0]);
      m_broadPhaseQuerySize = world->m_broadPhaseQuerySize;
      newPairs.m_data = 0i64;
      newPairs.m_size = 0;
      newPairs.m_capacityAndFlags = 0x80000000;
      v9 = _mm_unpacklo_epi16(_mm_unpacklo_epi8(v5, (__m128i)0i64), (__m128i)0i64);
      v45 = m_broadPhaseQuerySize;
      v10 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v9, 255));
      v11 = _mm_sub_epi32(
              _mm_unpacklo_epi32(
                _mm_unpacklo_epi32(v7, _mm_cvtsi32_si128(entity->m_collidable.m_boundingVolumeData.m_min[2])),
                _mm_unpacklo_epi32(v6, _mm_cvtsi32_si128(0))),
              _mm_slli_epi32(v9, v10));
      v12 = (__m128i)*(unsigned int *)entity->m_collidable.m_boundingVolumeData.m_expansionMax;
      v13 = _mm_cvtsi32_si128(entity->m_collidable.m_boundingVolumeData.m_max[1]);
      v14 = _mm_shuffle_epi32(v11, 170).m128i_u32[0];
      v46 = v11.m128i_i64[0];
      v15 = _mm_cvtsi32_si128(entity->m_collidable.m_boundingVolumeData.m_max[0]);
      v47 = v14;
      v16 = _mm_add_epi32(
              _mm_unpacklo_epi32(
                _mm_unpacklo_epi32(v15, _mm_cvtsi32_si128(entity->m_collidable.m_boundingVolumeData.m_max[2])),
                _mm_unpacklo_epi32(v13, _mm_cvtsi32_si128(0))),
              _mm_slli_epi32(_mm_unpacklo_epi16(_mm_unpacklo_epi8(v12, (__m128i)0i64), (__m128i)0i64), v10));
      v48 = v16.m128i_i64[0];
      v49 = _mm_shuffle_epi32(v16, 170).m128i_u32[0];
      if ( m_broadPhaseQuerySize )
      {
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkpBroadPhaseHandlePair *)Value->m_cur;
        v19 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
        v20 = (char *)m_cur + v19;
        if ( v19 > Value->m_slabSize || v20 > Value->m_end )
          m_cur = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(Value, v19);
        else
          Value->m_cur = v20;
      }
      else
      {
        m_cur = 0i64;
      }
      newPairs.m_data = m_cur;
      v44 = m_cur;
      newPairs.m_capacityAndFlags = m_broadPhaseQuerySize | 0x80000000;
      v21 = world->m_broadPhaseQuerySize;
      operation.m_data = 0i64;
      operation.m_size = 0;
      operation.m_capacityAndFlags = 0x80000000;
      v42 = v21;
      if ( v21 )
      {
        v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v23 = (hkpBroadPhaseHandlePair *)v22->m_cur;
        v24 = (16 * v21 + 127) & 0xFFFFFF80;
        v25 = (char *)v23 + v24;
        if ( v24 > v22->m_slabSize || v25 > v22->m_end )
          v23 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v22, v24);
        else
          v22->m_cur = v25;
      }
      else
      {
        v23 = 0i64;
      }
      m_broadPhase = world->m_broadPhase;
      operation.m_data = v23;
      p = v23;
      operation.m_capacityAndFlags = v21 | 0x80000000;
      p_m_broadPhaseHandle = &entity->m_collidable.m_broadPhaseHandle;
      ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle **, __int64 *, __int64, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))m_broadPhase->vfptr[6].__vecDelDtor)(
        m_broadPhase,
        &p_m_broadPhaseHandle,
        &v46,
        1i64,
        &newPairs,
        &operation);
      m_size = operation.m_size;
      if ( operation.m_size + newPairs.m_size > 0 )
      {
        hkpTypedBroadPhaseDispatcher::removeDuplicates(&newPairs, &operation);
        hkpTypedBroadPhaseDispatcher::removePairs(
          world->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)operation.m_data,
          operation.m_size);
        m_collisionFilter = world->m_collisionFilter;
        if ( m_collisionFilter )
          v29 = &m_collisionFilter->hkpCollidableCollidableFilter;
        else
          v29 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          world->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v29);
        m_size = operation.m_size;
      }
      v30 = (char *)p;
      if ( p == operation.m_data )
        m_size = 0;
      operation.m_size = m_size;
      v31 = (16 * v42 + 127) & 0xFFFFFF80;
      v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (v31 + 15) & 0xFFFFFFF0;
      if ( v31 > v32->m_slabSize || &v30[v33] != v32->m_cur || v32->m_firstNonLifoEnd == v30 )
        hkLifoAllocator::slowBlockFree(v32, v30, v33);
      else
        v32->m_cur = v30;
      operation.m_size = 0;
      if ( operation.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          operation.m_data,
          16 * operation.m_capacityAndFlags);
      v34 = newPairs.m_size;
      v35 = (char *)v44;
      operation.m_data = 0i64;
      if ( v44 == newPairs.m_data )
        v34 = 0;
      operation.m_capacityAndFlags = 0x80000000;
      newPairs.m_size = v34;
      v36 = (16 * v45 + 127) & 0xFFFFFF80;
      v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (v36 + 15) & 0xFFFFFFF0;
      if ( v36 > v37->m_slabSize || &v35[v38] != v37->m_cur || v37->m_firstNonLifoEnd == v35 )
        hkLifoAllocator::slowBlockFree(v37, v35, v38);
      else
        v37->m_cur = v35;
      newPairs.m_size = 0;
      if ( newPairs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          newPairs.m_data,
          16 * newPairs.m_capacityAndFlags);
    }
    v39 = world->m_criticalOperationsLockCount-- == 1;
    if ( v39 && !world->m_blockExecutingPendingOperations.m_bool )
    {
      if ( world->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(world);
      if ( world->m_pendingOperationQueueCount == 1 )
      {
        if ( world->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(world);
      }
    }
  }
}

// File Line: 152
// RVA: 0xD7D890
void __fastcall hkpWorldOperationUtil::addEntityBP(hkpWorld *world, hkpEntity *entity)
{
  int m_broadPhaseQuerySize; // ebx
  hkLifoAllocator *Value; // rcx
  hkpTypedBroadPhaseHandlePair *m_cur; // rax
  int v7; // edx
  char *v8; // r8
  hkpProcessCollisionInput *m_collisionInput; // rcx
  hkpBroadPhase *m_broadPhase; // rcx
  int v11; // eax
  hkpCollisionFilter *m_collisionFilter; // rcx
  hkpCollidableCollidableFilter *v13; // r9
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+30h] [rbp-40h] BYREF
  int numNewPairs; // [rsp+38h] [rbp-38h]
  int v20; // [rsp+3Ch] [rbp-34h]
  void *p; // [rsp+40h] [rbp-30h]
  int v22; // [rsp+48h] [rbp-28h]
  __int128 v23[2]; // [rsp+50h] [rbp-20h] BYREF
  hkpEntity *entityBatch; // [rsp+98h] [rbp+28h] BYREF

  entityBatch = entity;
  if ( entity->m_collidable.m_shape )
  {
    m_broadPhaseQuerySize = world->m_broadPhaseQuerySize;
    v20 = 0x80000000;
    v22 = m_broadPhaseQuerySize;
    newPairs = 0i64;
    numNewPairs = 0;
    if ( m_broadPhaseQuerySize )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkpTypedBroadPhaseHandlePair *)Value->m_cur;
      v7 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
      v8 = (char *)m_cur + v7;
      if ( v7 > Value->m_slabSize || v8 > Value->m_end )
        m_cur = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
      else
        Value->m_cur = v8;
    }
    else
    {
      m_cur = 0i64;
    }
    m_collisionInput = world->m_collisionInput;
    newPairs = m_cur;
    v20 = m_broadPhaseQuerySize | 0x80000000;
    p = m_cur;
    hkpEntityAabbUtil::entityBatchRecalcAabb(m_collisionInput, &entityBatch, 1i64);
    m_broadPhase = world->m_broadPhase;
    v23[0] = *(_OWORD *)entityBatch->m_collidable.m_boundingVolumeData.m_min;
    v23[1] = *(_OWORD *)entityBatch->m_collidable.m_boundingVolumeData.m_max;
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, __int128 *, hkpTypedBroadPhaseHandlePair **, _BYTE))m_broadPhase->vfptr[3].__vecDelDtor)(
      m_broadPhase,
      &entity->m_collidable.m_broadPhaseHandle,
      v23,
      &newPairs,
      0);
    v11 = numNewPairs;
    if ( numNewPairs > 0 )
    {
      m_collisionFilter = world->m_collisionFilter;
      v13 = &m_collisionFilter->hkpCollidableCollidableFilter;
      if ( !m_collisionFilter )
        v13 = 0i64;
      hkpTypedBroadPhaseDispatcher::addPairs(world->m_broadPhaseDispatcher, newPairs, numNewPairs, v13);
      v11 = numNewPairs;
    }
    v14 = (char *)p;
    if ( p == newPairs )
      v11 = 0;
    numNewPairs = v11;
    v15 = (16 * v22 + 127) & 0xFFFFFF80;
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (v15 + 15) & 0xFFFFFFF0;
    if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
      hkLifoAllocator::slowBlockFree(v16, v14, v17);
    else
      v16->m_cur = v14;
    numNewPairs = 0;
    if ( v20 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, newPairs, 16 * v20);
  }
}

// File Line: 178
// RVA: 0xD7DFF0
void __fastcall hkpWorldOperationUtil::addPhantomBP(hkpWorld *world, hkpPhantom *phantom)
{
  int m_broadPhaseQuerySize; // ebx
  hkLifoAllocator *Value; // rcx
  hkpTypedBroadPhaseHandlePair *m_cur; // rax
  int v7; // edx
  char *v8; // r8
  bool v9; // zf
  hkBaseObjectVtbl *vfptr; // rax
  bool v11; // bl
  int v12; // eax
  hkpCollisionFilter *m_collisionFilter; // rcx
  hkpCollidableCollidableFilter *v14; // r9
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // r8d
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+30h] [rbp-48h] BYREF
  int numNewPairs; // [rsp+38h] [rbp-40h]
  int v21; // [rsp+3Ch] [rbp-3Ch]
  void *p; // [rsp+40h] [rbp-38h]
  int v23; // [rsp+48h] [rbp-30h]
  hkAabb aabb; // [rsp+50h] [rbp-28h] BYREF

  m_broadPhaseQuerySize = world->m_broadPhaseQuerySize;
  v21 = 0x80000000;
  newPairs = 0i64;
  numNewPairs = 0;
  v23 = m_broadPhaseQuerySize;
  if ( m_broadPhaseQuerySize )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpTypedBroadPhaseHandlePair *)Value->m_cur;
    v7 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
    v8 = (char *)m_cur + v7;
    if ( v7 > Value->m_slabSize || v8 > Value->m_end )
      m_cur = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
    else
      Value->m_cur = v8;
  }
  else
  {
    m_cur = 0i64;
  }
  v9 = phantom->m_collidable.m_broadPhaseHandle.m_type == 3;
  newPairs = m_cur;
  p = m_cur;
  vfptr = phantom->vfptr;
  v21 = m_broadPhaseQuerySize | 0x80000000;
  v11 = v9;
  ((void (__fastcall *)(hkpPhantom *, hkAabb *))vfptr[3].__first_virtual_table_function__)(phantom, &aabb);
  ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkAabb *, hkpTypedBroadPhaseHandlePair **, bool))world->m_broadPhase->vfptr[2].__first_virtual_table_function__)(
    world->m_broadPhase,
    &phantom->m_collidable.m_broadPhaseHandle,
    &aabb,
    &newPairs,
    v11);
  hkpPhantom::setBoundingVolumeData(phantom, &aabb);
  v12 = numNewPairs;
  if ( numNewPairs )
  {
    m_collisionFilter = world->m_collisionFilter;
    v14 = &m_collisionFilter->hkpCollidableCollidableFilter;
    if ( !m_collisionFilter )
      v14 = 0i64;
    hkpTypedBroadPhaseDispatcher::addPairs(world->m_broadPhaseDispatcher, newPairs, numNewPairs, v14);
    v12 = numNewPairs;
  }
  v15 = (char *)p;
  if ( p == newPairs )
    v12 = 0;
  numNewPairs = v12;
  v16 = (16 * v23 + 127) & 0xFFFFFF80;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v18 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v17->m_slabSize || &v15[v18] != v17->m_cur || v17->m_firstNonLifoEnd == v15 )
    hkLifoAllocator::slowBlockFree(v17, v15, v18);
  else
    v17->m_cur = v15;
  numNewPairs = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, newPairs, 16 * v21);
}

// File Line: 200
// RVA: 0xD81CA0
hkpSimulationIsland *__fastcall findSmallSparseActiveIsland(
        hkpWorld *world,
        hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *islands,
        int islandSizeAddon,
        hkpSimulationIsland *islandToIgnore)
{
  signed int m_minDesiredIslandSize; // ebx
  int v6; // eax
  __int64 v7; // rcx
  hkpSimulationIsland **i; // r8
  hkpSimulationIsland *result; // rax
  int m_numConstraints; // edx

  m_minDesiredIslandSize = world->m_minDesiredIslandSize;
  if ( islandSizeAddon >= m_minDesiredIslandSize )
    return 0i64;
  if ( !world->m_wantSimulationIslands.m_bool )
    return 0i64;
  v6 = islands->m_size - 1;
  v7 = v6;
  if ( v6 < 0 )
    return 0i64;
  for ( i = &islands->m_data[v6]; ; --i )
  {
    result = *i;
    if ( islandToIgnore != *i )
    {
      m_numConstraints = result->m_numConstraints;
      if ( (*((_BYTE *)result + 50) & 0xC) != 0 )
      {
        if ( result->m_entities.m_size > m_numConstraints )
          m_numConstraints = result->m_entities.m_size;
        if ( islandSizeAddon + m_numConstraints < m_minDesiredIslandSize )
          break;
      }
    }
    if ( --v7 < 0 )
      return 0i64;
  }
  *((_BYTE *)result + 49) &= ~8u;
  *((_BYTE *)result + 49) |= 4u;
  return result;
}

// File Line: 231
// RVA: 0xD7E310
void __fastcall hkpWorldOperationUtil::addEntitySI(
        hkpWorld *world,
        hkpEntity *entity,
        hkpEntityActivation initialActivationState)
{
  bool v3; // zf
  bool v6; // bp
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_activeSimulationIslands; // rdi
  hkpSimulationIsland *SmallSparseActiveIsland; // rax
  _QWORD **Value; // rax
  hkpSimulationIsland *v10; // rax
  hkpSimulationIsland *v11; // rax
  hkpSimulationIsland *v12; // rbx
  __int16 m_size; // ax

  v3 = entity->m_motion.m_type.m_storage == 5;
  entity->m_world = world;
  if ( v3 )
  {
    hkpSimulationIsland::internalAddEntity(world->m_fixedIsland, entity);
    return;
  }
  if ( world->m_wantSimulationIslands.m_bool )
  {
    v6 = initialActivationState == HK_ENTITY_ACTIVATION_DO_ACTIVATE;
    if ( initialActivationState == HK_ENTITY_ACTIVATION_DO_ACTIVATE )
    {
      p_m_activeSimulationIslands = &world->m_activeSimulationIslands;
      SmallSparseActiveIsland = findSmallSparseActiveIsland(world, &world->m_activeSimulationIslands, 4, 0i64);
      if ( SmallSparseActiveIsland )
      {
        hkpSimulationIsland::internalAddEntity(SmallSparseActiveIsland, entity);
        return;
      }
    }
    else
    {
      p_m_activeSimulationIslands = &world->m_inactiveSimulationIslands;
    }
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 184i64);
    if ( v10 )
    {
      hkpSimulationIsland::hkpSimulationIsland(v10, world);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    *((_BYTE *)v12 + 50) &= 0xF3u;
    *((_BYTE *)v12 + 50) = v6 & 3 | *((_BYTE *)v12 + 50) & 0xFC | (4 * (v6 & 3));
    m_size = p_m_activeSimulationIslands->m_size;
    v12->m_storageIndex = m_size;
    v12->m_splitCheckFrameCounter = m_size;
    if ( p_m_activeSimulationIslands->m_size == (p_m_activeSimulationIslands->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_activeSimulationIslands->m_data,
        8);
    p_m_activeSimulationIslands->m_data[p_m_activeSimulationIslands->m_size++] = v12;
  }
  else
  {
    v12 = *world->m_activeSimulationIslands.m_data;
  }
  hkpSimulationIsland::internalAddEntity(v12, entity);
  v12->m_splitCheckFrameCounter = entity->m_uid;
}

// File Line: 289
// RVA: 0xD7DA50
void __fastcall hkpWorldOperationUtil::removeEntityBP(hkpWorld *world, hkpEntity *entity)
{
  int m_broadPhaseQuerySize; // edi
  hkLifoAllocator *Value; // rcx
  hkpTypedBroadPhaseHandlePair *m_cur; // rax
  int v7; // edx
  char *v8; // r8
  hkpBroadPhase *m_broadPhase; // rcx
  int v10; // eax
  char *v11; // rdi
  signed int v12; // ebx
  hkLifoAllocator *v13; // rax
  int v14; // r8d
  hkpTypedBroadPhaseHandlePair *deletedPairs; // [rsp+30h] [rbp-28h] BYREF
  int numDeletedPairs; // [rsp+38h] [rbp-20h]
  int v17; // [rsp+3Ch] [rbp-1Ch]
  void *p; // [rsp+40h] [rbp-18h]
  int v19; // [rsp+48h] [rbp-10h]
  hkpEntity *v20; // [rsp+68h] [rbp+10h] BYREF

  v20 = entity;
  if ( entity->m_collidable.m_shape )
  {
    ((void (__fastcall *)(hkpSimulation *, hkpEntity **, __int64, hkpWorld *, int))world->m_simulation->vfptr[6].__vecDelDtor)(
      world->m_simulation,
      &v20,
      1i64,
      world,
      1);
    m_broadPhaseQuerySize = world->m_broadPhaseQuerySize;
    v17 = 0x80000000;
    deletedPairs = 0i64;
    numDeletedPairs = 0;
    v19 = m_broadPhaseQuerySize;
    if ( m_broadPhaseQuerySize )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkpTypedBroadPhaseHandlePair *)Value->m_cur;
      v7 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
      v8 = (char *)m_cur + v7;
      if ( v7 > Value->m_slabSize || v8 > Value->m_end )
        m_cur = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
      else
        Value->m_cur = v8;
    }
    else
    {
      m_cur = 0i64;
    }
    m_broadPhase = world->m_broadPhase;
    deletedPairs = m_cur;
    p = m_cur;
    v17 = m_broadPhaseQuerySize | 0x80000000;
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkpTypedBroadPhaseHandlePair **))m_broadPhase->vfptr[4].__vecDelDtor)(
      m_broadPhase,
      &entity->m_collidable.m_broadPhaseHandle,
      &deletedPairs);
    v10 = numDeletedPairs;
    if ( numDeletedPairs > 0 )
    {
      hkpTypedBroadPhaseDispatcher::removePairs(world->m_broadPhaseDispatcher, deletedPairs, numDeletedPairs);
      v10 = numDeletedPairs;
    }
    v11 = (char *)p;
    if ( p == deletedPairs )
      v10 = 0;
    numDeletedPairs = v10;
    v12 = (16 * v19 + 127) & 0xFFFFFF80;
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (v12 + 15) & 0xFFFFFFF0;
    if ( v12 > v13->m_slabSize || &v11[v14] != v13->m_cur || v13->m_firstNonLifoEnd == v11 )
      hkLifoAllocator::slowBlockFree(v13, v11, v14);
    else
      v13->m_cur = v11;
    numDeletedPairs = 0;
    if ( v17 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, deletedPairs, 16 * v17);
  }
}

// File Line: 310
// RVA: 0xD7E1A0
void __fastcall hkpWorldOperationUtil::removePhantomBP(hkpWorld *world, hkpPhantom *phantom)
{
  int m_broadPhaseQuerySize; // ebx
  hkLifoAllocator *Value; // rcx
  hkpTypedBroadPhaseHandlePair *m_cur; // rax
  int v7; // edx
  char *v8; // r8
  hkpBroadPhase *m_broadPhase; // rcx
  int v10; // eax
  char *v11; // rdi
  signed int v12; // ebx
  hkLifoAllocator *v13; // rax
  int v14; // r8d
  hkpTypedBroadPhaseHandlePair *deletedPairs; // [rsp+20h] [rbp-28h] BYREF
  int numDeletedPairs; // [rsp+28h] [rbp-20h]
  int v17; // [rsp+2Ch] [rbp-1Ch]
  void *p; // [rsp+30h] [rbp-18h]
  int v19; // [rsp+38h] [rbp-10h]

  m_broadPhaseQuerySize = world->m_broadPhaseQuerySize;
  v17 = 0x80000000;
  deletedPairs = 0i64;
  numDeletedPairs = 0;
  v19 = m_broadPhaseQuerySize;
  if ( m_broadPhaseQuerySize )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpTypedBroadPhaseHandlePair *)Value->m_cur;
    v7 = (16 * m_broadPhaseQuerySize + 127) & 0xFFFFFF80;
    v8 = (char *)m_cur + v7;
    if ( v7 > Value->m_slabSize || v8 > Value->m_end )
      m_cur = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
    else
      Value->m_cur = v8;
  }
  else
  {
    m_cur = 0i64;
  }
  m_broadPhase = world->m_broadPhase;
  deletedPairs = m_cur;
  p = m_cur;
  v17 = m_broadPhaseQuerySize | 0x80000000;
  ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkpTypedBroadPhaseHandlePair **))m_broadPhase->vfptr[4].__vecDelDtor)(
    m_broadPhase,
    &phantom->m_collidable.m_broadPhaseHandle,
    &deletedPairs);
  v10 = numDeletedPairs;
  if ( numDeletedPairs )
  {
    hkpTypedBroadPhaseDispatcher::removePairs(world->m_broadPhaseDispatcher, deletedPairs, numDeletedPairs);
    v10 = numDeletedPairs;
  }
  v11 = (char *)p;
  if ( p == deletedPairs )
    v10 = 0;
  numDeletedPairs = v10;
  v12 = (16 * v19 + 127) & 0xFFFFFF80;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v13->m_slabSize || &v11[v14] != v13->m_cur || v13->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v13, v11, v14);
  else
    v13->m_cur = v11;
  numDeletedPairs = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, deletedPairs, 16 * v17);
}

// File Line: 328
// RVA: 0xD7E450
void __fastcall hkpWorldOperationUtil::removeEntitySI(hkpWorld *world, hkpEntity *entity)
{
  hkpSimulationIsland *m_simulationIsland; // rbx

  m_simulationIsland = entity->m_simulationIsland;
  entity->m_world = 0i64;
  hkpSimulationIsland::internalRemoveEntity(m_simulationIsland, entity);
  if ( m_simulationIsland->m_storageIndex != 0xFFFF && !m_simulationIsland->m_entities.m_size )
  {
    if ( world->m_wantSimulationIslands.m_bool )
    {
      hkpWorldOperationUtil::removeIsland(world, m_simulationIsland);
      m_simulationIsland->vfptr->__vecDelDtor(m_simulationIsland, 1u);
    }
  }
}

// File Line: 362
// RVA: 0xD805F0
void __fastcall hkpWorldOperationUtil::removeAttachedActionsFromFixedIsland(
        hkpWorld *world,
        hkpEntity *entity,
        hkArray<hkpAction *,hkContainerHeapAllocator> *actionsToBeMoved)
{
  int v3; // ebp
  __int64 v7; // r14
  hkpAction *v8; // rbx
  hkpSimulationIsland *m_fixedIsland; // r15

  v3 = 0;
  if ( entity->m_actions.m_size )
  {
    v7 = 0i64;
    do
    {
      v8 = entity->m_actions.m_data[v7];
      if ( v8->m_island == world->m_fixedIsland )
      {
        if ( actionsToBeMoved->m_size == (actionsToBeMoved->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&actionsToBeMoved->m_data, 8);
        actionsToBeMoved->m_data[actionsToBeMoved->m_size++] = v8;
        hkReferencedObject::addReference(v8);
        hkpSimulationIsland::removeAction(world->m_fixedIsland, v8);
        *((_BYTE *)world->m_fixedIsland + 49) = *((_BYTE *)world->m_fixedIsland + 49) & 0xCF | 0x10;
        m_fixedIsland = world->m_fixedIsland;
        EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
        if ( m_fixedIsland->m_dirtyListIndex == 0xFFFF )
        {
          m_fixedIsland->m_dirtyListIndex = world->m_dirtySimulationIslands.m_size;
          if ( world->m_dirtySimulationIslands.m_size == (world->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&world->m_dirtySimulationIslands.m_data,
              8);
          world->m_dirtySimulationIslands.m_data[world->m_dirtySimulationIslands.m_size++] = m_fixedIsland;
        }
        LeaveCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
      }
      ++v3;
      ++v7;
    }
    while ( v3 < entity->m_actions.m_size );
  }
}

// File Line: 394
// RVA: 0xD80740
void __fastcall hkpWorldOperationUtil::removeAttachedActionsFromDynamicIsland(
        hkpWorld *world,
        hkpEntity *entity,
        hkArray<hkpAction *,hkContainerHeapAllocator> *actionsToBeMoved)
{
  hkpSimulationIsland *m_simulationIsland; // rbp
  int v7; // r14d
  __int64 v8; // r12
  hkpAction *v9; // rbx
  int v10; // edx
  char *v11; // r9
  __int64 v12; // rax
  char *v13; // [rsp+20h] [rbp-B8h] BYREF
  int v14; // [rsp+28h] [rbp-B0h]
  int v15; // [rsp+2Ch] [rbp-ACh]
  char v16; // [rsp+30h] [rbp-A8h] BYREF

  m_simulationIsland = entity->m_simulationIsland;
  v7 = 0;
  if ( entity->m_actions.m_size )
  {
    v8 = 0i64;
    do
    {
      v9 = entity->m_actions.m_data[v8];
      v14 = 0;
      v13 = &v16;
      v15 = -2147483632;
      v9->vfptr[2].__vecDelDtor(v9, (unsigned int)&v13);
      v10 = 0;
      if ( v14 <= 0 )
      {
LABEL_8:
        if ( actionsToBeMoved->m_size == (actionsToBeMoved->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&actionsToBeMoved->m_data, 8);
        actionsToBeMoved->m_data[actionsToBeMoved->m_size++] = v9;
        hkReferencedObject::addReference(v9);
        hkpSimulationIsland::removeAction(m_simulationIsland, v9);
        *((_BYTE *)m_simulationIsland + 49) &= ~0x20u;
        *((_BYTE *)m_simulationIsland + 49) |= 0x10u;
        EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
        if ( m_simulationIsland->m_dirtyListIndex == 0xFFFF )
        {
          m_simulationIsland->m_dirtyListIndex = world->m_dirtySimulationIslands.m_size;
          if ( world->m_dirtySimulationIslands.m_size == (world->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&world->m_dirtySimulationIslands.m_data,
              8);
          world->m_dirtySimulationIslands.m_data[world->m_dirtySimulationIslands.m_size++] = m_simulationIsland;
        }
        LeaveCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
        v11 = v13;
      }
      else
      {
        v11 = v13;
        v12 = (__int64)v13;
        while ( *(_BYTE *)(*(_QWORD *)v12 + 352i64) == 5 || *(hkpEntity **)v12 == entity )
        {
          ++v10;
          v12 += 8i64;
          if ( v10 >= v14 )
            goto LABEL_8;
        }
      }
      v14 = 0;
      if ( v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v11, 8 * v15);
      ++v7;
      ++v8;
    }
    while ( v7 < entity->m_actions.m_size );
  }
}

// File Line: 449
// RVA: 0xD80930
void __fastcall hkpWorldOperationUtil::addActionsToEntitysIsland(
        hkpWorld *world,
        hkpEntity *entity,
        hkArray<hkpAction *,hkContainerHeapAllocator> *actionsToBeMoved)
{
  hkpSimulationIsland *m_simulationIsland; // r12
  int v5; // ebp
  int v6; // r8d
  __int64 v9; // r14
  hkpSimulationIsland *m_fixedIsland; // rcx
  hkpAction *v11; // rdi
  int v12; // edx
  int v13; // esi
  __int64 v14; // rdi
  hkpEntity *v15; // rcx
  char *v16; // [rsp+20h] [rbp-B8h] BYREF
  int v17; // [rsp+28h] [rbp-B0h]
  int v18; // [rsp+2Ch] [rbp-ACh]
  char v19; // [rsp+30h] [rbp-A8h] BYREF

  m_simulationIsland = entity->m_simulationIsland;
  v5 = 0;
  v6 = -2147483632;
  v16 = &v19;
  v17 = 0;
  v18 = -2147483632;
  if ( actionsToBeMoved->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      m_fixedIsland = world->m_fixedIsland;
      v11 = actionsToBeMoved->m_data[v9];
      if ( m_simulationIsland == m_fixedIsland )
      {
        hkpSimulationIsland::addAction(m_fixedIsland, v11);
        hkReferencedObject::removeReference(v11);
      }
      else
      {
        hkpSimulationIsland::addAction(m_simulationIsland, v11);
        hkReferencedObject::removeReference(v11);
        v17 = 0;
        v11->vfptr[2].__vecDelDtor(v11, (unsigned int)&v16);
        v12 = v17;
        v13 = 0;
        if ( v17 > 0 )
        {
          v14 = 0i64;
          do
          {
            v15 = *(hkpEntity **)&v16[v14];
            if ( v15 != entity
              && v15->m_motion.m_type.m_storage != 5
              && entity->m_motion.m_type.m_storage != 5
              && v15->m_simulationIsland != entity->m_simulationIsland )
            {
              hkpWorldOperationUtil::mergeIslands(v15->m_world, *(hkpEntity **)&v16[v14], entity);
              v12 = v17;
            }
            ++v13;
            v14 += 8i64;
          }
          while ( v13 < v12 );
        }
      }
      ++v5;
      ++v9;
    }
    while ( v5 < actionsToBeMoved->m_size );
    v6 = v18;
  }
  v17 = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v16, 8 * v6);
}

// File Line: 499
// RVA: 0xD7EF50
void __fastcall hkpWorldOperationUtil::removeIsland(hkpWorld *world, hkpSimulationIsland *island)
{
  if ( (*((_BYTE *)island + 50) & 3) != 0 )
  {
    world->m_activeSimulationIslands.m_data[island->m_storageIndex] = world->m_activeSimulationIslands.m_data[world->m_activeSimulationIslands.m_size - 1];
    world->m_activeSimulationIslands.m_data[island->m_storageIndex]->m_storageIndex = island->m_storageIndex;
    --world->m_activeSimulationIslands.m_size;
  }
  else
  {
    world->m_inactiveSimulationIslands.m_data[island->m_storageIndex] = world->m_inactiveSimulationIslands.m_data[world->m_inactiveSimulationIslands.m_size - 1];
    world->m_inactiveSimulationIslands.m_data[island->m_storageIndex]->m_storageIndex = island->m_storageIndex;
    --world->m_inactiveSimulationIslands.m_size;
  }
  hkpWorldOperationUtil::removeIslandFromDirtyList(world, island);
}

// File Line: 523
// RVA: 0xD7E4C0
void __fastcall hkpWorldOperationUtil::addConstraintToCriticalLockedIsland(
        hkpWorld *world,
        hkpConstraintInstance *constraint)
{
  hkpWorldConstraintUtil::addConstraint(world, constraint);
  if ( world->m_constraintListeners.m_size )
    hkpWorldCallbackUtil::fireConstraintAdded(world, constraint);
  if ( constraint->m_listeners.m_size )
    hkpConstraintCallbackUtil::fireConstraintAdded(constraint);
}

// File Line: 550
// RVA: 0xD7E510
void __fastcall hkpWorldOperationUtil::removeConstraintFromCriticalLockedIsland(
        hkpWorld *world,
        hkpConstraintInstance *constraint)
{
  if ( world->m_constraintListeners.m_size )
    hkpWorldCallbackUtil::fireConstraintRemoved(world, constraint);
  if ( constraint->m_listeners.m_size )
    hkpConstraintCallbackUtil::fireConstraintRemoved(constraint);
  hkpWorldConstraintUtil::removeConstraint(constraint);
}

// File Line: 577
// RVA: 0xD7E550
hkpConstraintInstance *__fastcall hkpWorldOperationUtil::addConstraintImmediately(
        hkpWorld *world,
        hkpConstraintInstance *constraint,
        hkpWorldOperationUtil::FireCallbacks fireCallbacks)
{
  bool v6; // zf

  ++world->m_criticalOperationsLockCount;
  hkpWorldConstraintUtil::addConstraint(world, constraint);
  if ( fireCallbacks )
  {
    if ( world->m_constraintListeners.m_size )
      hkpWorldCallbackUtil::fireConstraintAdded(world, constraint);
    if ( constraint->m_listeners.m_size )
      hkpConstraintCallbackUtil::fireConstraintAdded(constraint);
  }
  v6 = world->m_criticalOperationsLockCount-- == 1;
  if ( v6 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 && world->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(world);
  }
  return constraint;
}

// File Line: 629
// RVA: 0xD7E5F0
void __fastcall hkpWorldOperationUtil::removeConstraintImmediately(
        hkpWorld *world,
        hkpConstraintInstance *constraint,
        hkpWorldOperationUtil::FireCallbacks fireCallbacks)
{
  hkpConstraintOwner *m_owner; // rax
  bool v6; // zf

  m_owner = constraint->m_owner;
  BYTE1(m_owner[1].m_constraintInfo.m_maxSizeOfSchema) &= ~2u;
  BYTE1(m_owner[1].m_constraintInfo.m_maxSizeOfSchema) |= 1u;
  if ( world->m_criticalOperationsLockCount )
  {
    if ( fireCallbacks )
    {
      if ( world->m_constraintListeners.m_size )
        hkpWorldCallbackUtil::fireConstraintRemoved(world, constraint);
      if ( constraint->m_listeners.m_size )
        hkpConstraintCallbackUtil::fireConstraintRemoved(constraint);
    }
    hkpWorldConstraintUtil::removeConstraint(constraint);
  }
  else
  {
    world->m_criticalOperationsLockCount = 1;
    if ( fireCallbacks && world->m_constraintListeners.m_size )
      hkpWorldCallbackUtil::fireConstraintRemoved(world, constraint);
    hkpWorldConstraintUtil::removeConstraint(constraint);
    v6 = world->m_criticalOperationsLockCount-- == 1;
    if ( v6 && !world->m_blockExecutingPendingOperations.m_bool )
    {
      if ( world->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(world);
      if ( world->m_pendingOperationQueueCount == 1 && world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(world);
    }
  }
}

// File Line: 679
// RVA: 0xD81D20
void __fastcall findInactiveGroups(
        hkUnionFind *checker,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        hkpWorld *world,
        int numGroups,
        hkFixedArray<int> *isActive)
{
  int v5; // r11d
  __int64 i; // r10
  __int64 v8; // r9
  __int64 v9; // r10
  hkpEntity *v10; // r8
  int v11; // eax
  int v12; // r8d
  char v13; // al
  int v14; // eax
  int v15; // r8d

  v5 = 0;
  for ( i = 0i64; i < numGroups; isActive->m_data.m_storage[i - 1] = 0 )
    ++i;
  if ( entities->m_size > 0 )
  {
    v8 = 0i64;
    v9 = 0i64;
    do
    {
      v10 = entities->m_data[v9];
      v11 = v10->m_motion.m_deactivationNumInactiveFrames[1];
      if ( (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v11 >> 14 )
        v11 >>= 7;
      v12 = v10->m_motion.m_deactivationNumInactiveFrames[0];
      v13 = v11 & 0x7F;
      if ( (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v12 >> 14 )
        v12 >>= 7;
      v14 = v13 & 0x7F;
      v15 = v12 & 0x7F;
      if ( v15 > v14 )
        v14 = v15;
      if ( v14 <= 5 )
        isActive->m_data.m_storage[checker->m_parents->m_data.m_storage[v8]] = 1;
      ++v5;
      ++v9;
      ++v8;
    }
    while ( v5 < entities->m_size );
  }
}

// File Line: 702
// RVA: 0xD81E10
void __fastcall identifyDeactivatedSubgroups(
        hkUnionFind *checker,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        hkpWorld *world,
        hkArray<int,hkContainerHeapAllocator> *groupsSizes,
        hkFixedArray<signed char> *groupSparse)
{
  __int64 m_size; // r15
  hkLifoAllocator *Value; // rcx
  __int64 m_cur; // rax
  int v12; // edx
  void *v13; // r10
  __int64 v14; // rsi
  __int64 v15; // r11
  __int64 v16; // rcx
  int v17; // ebx
  int v18; // r10d
  __int64 v19; // rdi
  hkpEntity *v20; // r9
  int v21; // r8d
  int v22; // r9d
  char v23; // r8
  int v24; // r8d
  int v25; // r9d
  __int64 v26; // r8
  __int64 v27; // rbx
  int *m_storage; // rdi
  signed int v29; // ebx
  hkLifoAllocator *v30; // rax
  int v31; // r8d
  hkFixedArray<int> rindex; // [rsp+20h] [rbp-38h] BYREF

  m_size = groupsSizes->m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v12 = (4 * m_size + 127) & 0xFFFFFF80;
  v13 = (void *)(m_cur + v12);
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v12);
  else
    Value->m_cur = v13;
  v14 = 0i64;
  rindex.m_data.m_storage = (int *)m_cur;
  rindex.m_size.m_storage = m_size;
  v15 = m_size;
  v16 = 0i64;
  if ( (int)m_size > 0 )
  {
    do
    {
      *(_DWORD *)(m_cur + 4 * v16) = 0;
      m_cur = (__int64)rindex.m_data.m_storage;
      ++v16;
    }
    while ( v16 < m_size );
  }
  v17 = 0;
  v18 = 1;
  if ( entities->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = entities->m_data[v14];
      v21 = v20->m_motion.m_deactivationNumInactiveFrames[1];
      if ( (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v21 >> 14 )
        v21 >>= 7;
      v22 = v20->m_motion.m_deactivationNumInactiveFrames[0];
      v23 = v21 & 0x7F;
      if ( (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v22 >> 14 )
        v22 >>= 7;
      v24 = v23 & 0x7F;
      v25 = v22 & 0x7F;
      if ( v25 > v24 )
        v24 = v25;
      if ( v24 <= 5 )
      {
        *(_DWORD *)(m_cur + 4i64 * checker->m_parents->m_data.m_storage[v19]) = 1;
        m_cur = (__int64)rindex.m_data.m_storage;
      }
      ++v17;
      ++v14;
      ++v19;
    }
    while ( v17 < entities->m_size );
  }
  v26 = 1i64;
  *groupSparse->m_data.m_storage = 1;
  if ( (int)m_size > 0 )
  {
    v27 = -m_cur;
    do
    {
      if ( *(int *)((char *)rindex.m_data.m_storage + v27 + m_cur) )
      {
        *(_DWORD *)m_cur = 0;
      }
      else
      {
        *(_DWORD *)m_cur = v18++;
        groupSparse->m_data.m_storage[v26++] = 0;
      }
      m_cur += 4i64;
      --v15;
    }
    while ( v15 );
  }
  if ( v18 <= (int)m_size )
    hkUnionFind::reindex(checker, &rindex, (unsigned int)v18, groupsSizes);
  else
    *groupSparse->m_data.m_storage = 0;
  m_storage = rindex.m_data.m_storage;
  v29 = (4 * rindex.m_size.m_storage + 127) & 0xFFFFFF80;
  v30 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v31 = (v29 + 15) & 0xFFFFFFF0;
  if ( v29 > v30->m_slabSize || (char *)m_storage + v31 != v30->m_cur || v30->m_firstNonLifoEnd == m_storage )
    hkLifoAllocator::slowBlockFree(v30, (char *)m_storage, v31);
  else
    v30->m_cur = m_storage;
}

// File Line: 750
// RVA: 0xD82030
void __fastcall findInactiveGroupsAndEstimateSolverSize(
        hkUnionFind *checker,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        int numGroups,
        hkFixedArray<int> *isActive,
        hkFixedArray<int> *sizes,
        char *deactivationNumInactiveFramesSelectFlag)
{
  int v6; // r10d
  __int64 v9; // rbx
  __int64 v10; // rdi
  hkpEntity *v11; // r9
  int v12; // eax
  __int64 v13; // r11
  int v14; // r8d
  char v15; // al
  int v16; // eax
  int v17; // r8d
  int m_size; // edx

  v6 = 0;
  if ( entities->m_size > 0 )
  {
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      v11 = entities->m_data[v10];
      v12 = v11->m_motion.m_deactivationNumInactiveFrames[1];
      v13 = checker->m_parents->m_data.m_storage[v9];
      if ( (unsigned __int8)deactivationNumInactiveFramesSelectFlag[1] == v12 >> 14 )
        v12 >>= 7;
      v14 = v11->m_motion.m_deactivationNumInactiveFrames[0];
      v15 = v12 & 0x7F;
      if ( (unsigned __int8)*deactivationNumInactiveFramesSelectFlag == v14 >> 14 )
        v14 >>= 7;
      v16 = v15 & 0x7F;
      v17 = v14 & 0x7F;
      if ( v17 > v16 )
        v16 = v17;
      if ( v16 <= 5 )
        isActive->m_data.m_storage[v13] = 1;
      m_size = v11->m_constraintsMaster.m_size;
      if ( !v11->m_constraintsMaster.m_size )
        m_size = 1;
      ++v6;
      ++v10;
      sizes->m_data.m_storage[v13] += m_size;
      ++v9;
    }
    while ( v6 < entities->m_size );
  }
}

// File Line: 773
// RVA: 0xD82140
void __fastcall estimateSolverSize(
        hkUnionFind *checker,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        int numGroups,
        hkFixedArray<int> *isActive,
        hkFixedArray<int> *sizes)
{
  int v5; // r8d
  __int64 v8; // r10
  __int64 v9; // r11
  hkpEntity *v10; // rdx
  __int64 v11; // rcx
  int m_size; // edx

  v5 = 0;
  if ( entities->m_size > 0 )
  {
    v8 = 0i64;
    v9 = 0i64;
    do
    {
      ++v9;
      ++v8;
      v10 = entities->m_data[v9 - 1];
      v11 = checker->m_parents->m_data.m_storage[v8 - 1];
      isActive->m_data.m_storage[v11] = 1;
      m_size = v10->m_constraintsMaster.m_size;
      if ( m_size < 1 )
        m_size = 1;
      ++v5;
      sizes->m_data.m_storage[v11] += m_size;
    }
    while ( v5 < entities->m_size );
  }
}

// File Line: 791
// RVA: 0xD821D0
void __fastcall mergeSmallSubgroups(
        hkpWorld *world,
        hkUnionFind *checker,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        hkArray<int,hkContainerHeapAllocator> *groupsSizes,
        hkFixedArray<signed char> *groupSparse)
{
  __int64 m_size; // rbx
  hkLifoAllocator *Value; // rax
  char *m_cur; // r15
  int v10; // esi
  char *v11; // r9
  hkLifoAllocator *v12; // rax
  int *v13; // rdx
  char *v14; // rcx
  unsigned int v15; // ebp
  __int64 v16; // r14
  __int64 v17; // rcx
  __int64 v18; // r12
  int v19; // esi
  __int64 v20; // r11
  __int64 v21; // rbx
  hkpEntity *v22; // r9
  int v23; // edx
  __int64 v24; // r10
  int v25; // r8d
  char v26; // dl
  int v27; // edx
  int v28; // r8d
  int v29; // ecx
  int v30; // r8d
  __int64 v31; // r9
  __int64 v32; // r10
  hkpEntity *v33; // rdx
  __int64 v34; // rcx
  int v35; // eax
  __int64 i; // rcx
  int *m_storage; // r9
  __int64 v38; // rax
  __int64 v39; // rcx
  int *v40; // r8
  int *v41; // rsi
  int v42; // edx
  __int64 v43; // rdi
  int v44; // ebx
  __int64 v45; // r10
  int *v46; // rcx
  signed __int64 v47; // r11
  signed int m_minDesiredIslandSize; // r9d
  int v49; // eax
  int *v50; // rdi
  signed int v51; // ebx
  hkLifoAllocator *v52; // rax
  int v53; // r8d
  hkLifoAllocator *v54; // rax
  int v55; // r8d
  int v56; // [rsp+20h] [rbp-78h]
  __int64 v57; // [rsp+28h] [rbp-70h]
  __int64 v58; // [rsp+28h] [rbp-70h]
  char *v59; // [rsp+30h] [rbp-68h]
  int *v60; // [rsp+38h] [rbp-60h]
  __int64 v61; // [rsp+40h] [rbp-58h]
  int *v62; // [rsp+48h] [rbp-50h]
  hkFixedArray<int> rindex; // [rsp+50h] [rbp-48h] BYREF

  m_size = groupsSizes->m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v10 = (4 * m_size + 127) & 0xFFFFFF80;
  v56 = v10;
  v59 = m_cur;
  v11 = &m_cur[v10];
  if ( v10 > Value->m_slabSize || v11 > Value->m_end )
  {
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
    v59 = m_cur;
  }
  else
  {
    Value->m_cur = v11;
  }
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (int *)v12->m_cur;
  v14 = (char *)v13 + v10;
  if ( v10 > v12->m_slabSize || v14 > v12->m_end )
    v13 = (int *)hkLifoAllocator::allocateFromNewSlab(v12, v10);
  else
    v12->m_cur = v14;
  v15 = 0;
  rindex.m_data.m_storage = v13;
  rindex.m_size.m_storage = m_size;
  v16 = m_size;
  v57 = m_size;
  v17 = 0i64;
  if ( (int)m_size > 0 )
  {
    do
    {
      rindex.m_data.m_storage[v17++] = 0;
      *(_DWORD *)&m_cur[4 * v17 - 4] = 0;
    }
    while ( v17 < m_size );
  }
  v18 = 1i64;
  if ( world->m_wantDeactivation.m_bool )
  {
    v19 = 0;
    if ( entities->m_size > 0 )
    {
      v20 = 0i64;
      v21 = 0i64;
      do
      {
        v22 = entities->m_data[v21];
        v23 = v22->m_motion.m_deactivationNumInactiveFrames[1];
        v24 = checker->m_parents->m_data.m_storage[v20];
        if ( (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v23 >> 14 )
          v23 >>= 7;
        v25 = v22->m_motion.m_deactivationNumInactiveFrames[0];
        v26 = v23 & 0x7F;
        if ( (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v25 >> 14 )
          v25 >>= 7;
        v27 = v26 & 0x7F;
        v28 = v25 & 0x7F;
        if ( v28 > v27 )
          v27 = v28;
        if ( v27 <= 5 )
          rindex.m_data.m_storage[v24] = 1;
        v29 = v22->m_constraintsMaster.m_size;
        if ( !v22->m_constraintsMaster.m_size )
          v29 = 1;
        ++v19;
        ++v21;
        *(_DWORD *)&m_cur[4 * v24] += v29;
        ++v20;
      }
      while ( v19 < entities->m_size );
      v16 = v57;
    }
  }
  else
  {
    v30 = 0;
    if ( entities->m_size > 0 )
    {
      v31 = 0i64;
      v32 = 0i64;
      do
      {
        ++v32;
        ++v31;
        v33 = entities->m_data[v32 - 1];
        v34 = checker->m_parents->m_data.m_storage[v31 - 1];
        rindex.m_data.m_storage[v34] = 1;
        v35 = v33->m_constraintsMaster.m_size;
        if ( !v33->m_constraintsMaster.m_size )
          v35 = 1;
        ++v30;
        *(_DWORD *)&m_cur[v34 * 4] += v35;
      }
      while ( v30 < entities->m_size );
      v16 = m_size;
    }
  }
  for ( i = 0i64; i < v16; ++i )
  {
    if ( !rindex.m_data.m_storage[i] )
      *(_DWORD *)&m_cur[4 * i] = -1;
  }
  m_storage = rindex.m_data.m_storage;
  v38 = 0i64;
  v62 = rindex.m_data.m_storage;
  if ( v16 > 0 )
  {
    v39 = v16;
    v40 = rindex.m_data.m_storage;
    v60 = rindex.m_data.m_storage;
    v41 = (int *)m_cur;
    v61 = v16;
    do
    {
      v42 = *v41;
      if ( *v41 != -2 )
      {
        v43 = v38;
        v44 = v15;
        v58 = v38 + 1;
        ++v15;
        groupSparse->m_data.m_storage[v38] = 0;
        *v40 = v44;
        if ( v42 >= 0 )
        {
          v45 = v18;
          if ( v18 < v16 )
          {
            v46 = v41 + 1;
            v47 = (char *)m_storage - m_cur;
            do
            {
              m_minDesiredIslandSize = world->m_minDesiredIslandSize;
              if ( v42 + 10 >= m_minDesiredIslandSize )
                break;
              v49 = *v46;
              if ( *v46 >= 0 && v49 + v42 < m_minDesiredIslandSize )
              {
                v42 += v49;
                groupSparse->m_data.m_storage[v43] = 1;
                *(int *)((char *)v46 + v47) = v44;
                *v46 = -2;
              }
              ++v45;
              ++v46;
            }
            while ( v45 < v16 );
            m_cur = v59;
            v40 = v60;
            v39 = v61;
            m_storage = v62;
          }
        }
        v38 = v58;
      }
      ++v40;
      ++v41;
      ++v18;
      --v39;
      v60 = v40;
      v61 = v39;
    }
    while ( v39 );
  }
  hkUnionFind::reindex(checker, &rindex, v15, groupsSizes);
  v50 = rindex.m_data.m_storage;
  v51 = (4 * rindex.m_size.m_storage + 127) & 0xFFFFFF80;
  v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v53 = (v51 + 15) & 0xFFFFFFF0;
  if ( v51 > v52->m_slabSize || (char *)v50 + v53 != v52->m_cur || v52->m_firstNonLifoEnd == v50 )
    hkLifoAllocator::slowBlockFree(v52, (char *)v50, v53);
  else
    v52->m_cur = v50;
  v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v55 = (v56 + 15) & 0xFFFFFFF0;
  if ( v56 > v54->m_slabSize || &m_cur[v55] != v54->m_cur || v54->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v54, m_cur, v55);
  else
    v54->m_cur = m_cur;
}

// File Line: 876
// RVA: 0xD7EFD0
void __fastcall hkpWorldOperationUtil::splitSimulationIsland(
        hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *currentIsland,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *world,
        hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *newIslandsOut,
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *oldEntitiesOut)
{
  int m_size; // ebx
  hkpSimulationIsland *v5; // r13
  hkLifoAllocator *Value; // rax
  int *m_cur; // r9
  int v11; // edx
  char *v12; // rcx
  int v13; // r8d
  int v14; // ebx
  hkLifoAllocator *v15; // rax
  _BYTE *v16; // rsi
  signed int v17; // edx
  _BYTE *v18; // rcx
  __int64 v19; // r12
  __int64 v20; // rsi
  hkLifoAllocator *v21; // rax
  __int64 v22; // r9
  int v23; // edx
  void *v24; // rcx
  __int64 v25; // rdi
  __int64 v26; // r10
  __int64 v27; // rax
  int v28; // r11d
  __int64 v29; // rbx
  hkpEntity *v30; // r8
  int v31; // edx
  int v32; // r8d
  char v33; // dl
  int v34; // edx
  int v35; // r8d
  __int64 v36; // r8
  _BYTE *v37; // rdx
  __int64 v38; // r11
  signed int v39; // ebx
  hkLifoAllocator *v40; // rax
  int v41; // r8d
  int *v42; // rdi
  signed int v43; // ebx
  hkLifoAllocator *v44; // rax
  int v45; // r8d
  __int64 v46; // rbx
  hkLifoAllocator *v47; // rax
  char *v48; // r14
  int v49; // r15d
  char *v50; // rcx
  hkLifoAllocator *v51; // rax
  int *v52; // rdx
  char *v53; // rcx
  __int64 v54; // r11
  __int64 v55; // rcx
  int v56; // esi
  __int64 v57; // r10
  __int64 v58; // rbx
  unsigned __int16 *v59; // r9
  int v60; // edx
  __int64 v61; // rdi
  int v62; // r8d
  char v63; // dl
  int v64; // edx
  int v65; // r8d
  int v66; // ecx
  int v67; // r10d
  __int64 v68; // r8
  __int64 v69; // r9
  hkpEntity *v70; // rdx
  __int64 v71; // rcx
  int v72; // eax
  __int64 j; // rcx
  hkResultEnum m_enum; // ecx
  __int64 v75; // r9
  __int64 v76; // rbx
  int *v77; // r8
  int *v78; // r15
  _BYTE *v79; // r13
  int v80; // edx
  int v81; // edi
  _BYTE *v82; // rsi
  __int64 v83; // r10
  int *v84; // rcx
  signed int v85; // r9d
  int v86; // eax
  int *v87; // rdi
  signed int v88; // ebx
  hkLifoAllocator *v89; // rax
  int v90; // r8d
  hkLifoAllocator *v91; // rax
  int v92; // r8d
  __int64 v93; // rbx
  hkLifoAllocator *v94; // rax
  char *v95; // rcx
  hkLifoAllocator *v96; // rax
  int *v97; // rdx
  char *v98; // rcx
  __int64 v99; // r11
  __int64 v100; // rcx
  int v101; // esi
  __int64 v102; // r10
  __int64 v103; // rbx
  unsigned __int16 *v104; // r9
  int v105; // edx
  __int64 v106; // rdi
  int v107; // r8d
  char v108; // dl
  int v109; // edx
  int v110; // r8d
  int v111; // ecx
  int v112; // r10d
  __int64 v113; // r8
  __int64 v114; // r9
  hkpEntity *v115; // rdx
  __int64 v116; // rcx
  int v117; // eax
  __int64 i; // rcx
  __int64 v119; // r9
  __int64 v120; // rbx
  int *v121; // r8
  int *v122; // r15
  _BYTE *v123; // r13
  int v124; // edx
  int v125; // edi
  _BYTE *v126; // rsi
  __int64 v127; // r10
  int *v128; // rcx
  signed int m_minDesiredIslandSize; // r9d
  int v130; // eax
  int v131; // eax
  char v132; // dl
  __int64 v133; // rbx
  hkLifoAllocator *v134; // rax
  _QWORD *v135; // r12
  __int32 v136; // edx
  char *v137; // rcx
  bool v138; // zf
  __int64 v139; // rdi
  __int64 v140; // rsi
  _QWORD **v141; // rax
  hkpSimulationIsland *v142; // rax
  __int64 v143; // rax
  __int64 v144; // rbx
  char v145; // al
  int v146; // r9d
  int *m_data; // rdx
  int *v148; // rdi
  int *v149; // rax
  __int64 v150; // r10
  __int64 v151; // rbx
  __int64 v152; // r8
  unsigned __int16 *v153; // rdx
  int v154; // r9d
  int v155; // ecx
  unsigned int v156; // r10d
  unsigned int v157; // r11d
  __int64 v158; // rax
  int m_maxSizeOfSchema; // r12d
  _WORD *v160; // rax
  __int64 v161; // rdi
  int v162; // eax
  _WORD *v163; // rax
  int v164; // ecx
  hkpAction **v165; // r12
  hkpSimulationIsland *m_fixedIsland; // r14
  __int64 v167; // rax
  __int64 v168; // rsi
  __int64 v169; // r15
  hkpAction *v170; // rdi
  hkpAction *v171; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  hkpSimulationIsland *v173; // rbx
  int v174; // edx
  __int64 v175; // rcx
  __int64 v176; // r14
  hkpAgentNnTrack *v177; // rsi
  int v178; // r15d
  __int64 v179; // r12
  hkpAgentNnEntry *v180; // rdi
  hkpAgentNnEntry *v181; // rbx
  hkpSimulationIsland *v182; // rdx
  hkpAgentNnTrack *v183; // rcx
  char *v184; // r14
  __int64 k; // rsi
  __int64 v186; // rbx
  char v187; // al
  int v188; // eax
  __int64 v189; // rcx
  __int16 v190; // cx
  int v191; // r15d
  int v192; // ecx
  __int64 v193; // r12
  hkpAgentNnEntry *v194; // r14
  int m_storage_low; // eax
  hkpAgentNnEntry *v196; // rbx
  unsigned __int64 v197; // rdi
  __int64 v198; // rdx
  hkpAgentNnTrack *v199; // rcx
  _QWORD **v200; // rax
  hkInplaceArray<hkpAgentNnSector *,1,hkContainerHeapAllocator> *p_m_sectors; // rdx
  int m_capacityAndFlags; // r8d
  unsigned int v203; // ecx
  int v204; // eax
  int v205; // edi
  hkInplaceArray<hkpAgentNnSector *,1,hkContainerHeapAllocator> *v206; // rdx
  int v207; // r9d
  unsigned int v208; // ecx
  int v209; // eax
  hkResultEnum v210; // r8d
  char *v211; // rbx
  __int64 *v212; // rdx
  __int64 v213; // rax
  char v214; // cl
  hkLifoAllocator *v215; // rax
  int v216; // r8d
  hkLifoAllocator *v217; // rax
  int v218; // r8d
  int *v219; // rdi
  signed int v220; // ebx
  hkLifoAllocator *v221; // rax
  int v222; // r8d
  int v223; // [rsp+30h] [rbp-C0h]
  __int32 v224; // [rsp+30h] [rbp-C0h]
  _BYTE *v225; // [rsp+38h] [rbp-B8h]
  hkFixedArray<int> p; // [rsp+40h] [rbp-B0h] BYREF
  int v227; // [rsp+50h] [rbp-A0h]
  int v228; // [rsp+54h] [rbp-9Ch]
  __int64 v229; // [rsp+58h] [rbp-98h] BYREF
  int *v230; // [rsp+60h] [rbp-90h]
  void *m_storage; // [rsp+68h] [rbp-88h]
  hkResult v232[2]; // [rsp+70h] [rbp-80h] BYREF
  hkResult v233[2]; // [rsp+78h] [rbp-78h] BYREF
  hkpAgentNnTrack *p_m_narrowphaseAgentTrack; // [rsp+80h] [rbp-70h]
  unsigned __int64 p_m_midphaseAgentTrack; // [rsp+88h] [rbp-68h]
  hkResult result; // [rsp+90h] [rbp-60h] BYREF
  hkUnionFind checkConnectivityOut; // [rsp+98h] [rbp-58h] BYREF
  hkFixedArray<int> parents; // [rsp+B0h] [rbp-40h] BYREF
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+C0h] [rbp-30h] BYREF
  char v240; // [rsp+D0h] [rbp-20h] BYREF
  char *v241; // [rsp+150h] [rbp+60h] BYREF
  int v242; // [rsp+158h] [rbp+68h]
  int v243; // [rsp+15Ch] [rbp+6Ch]
  char v244; // [rsp+160h] [rbp+70h] BYREF
  hkpSimulationIsland *vars0; // [rsp+230h] [rbp+140h]
  hkpWorld *retaddr; // [rsp+238h] [rbp+148h]

  m_size = currentIsland[6].m_size;
  v5 = (hkpSimulationIsland *)currentIsland;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (int *)Value->m_cur;
  v11 = (4 * m_size + 127) & 0xFFFFFF80;
  v12 = (char *)m_cur + v11;
  if ( v11 > Value->m_slabSize || v12 > Value->m_end )
    m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
  else
    Value->m_cur = v12;
  v13 = v5->m_entities.m_size;
  parents.m_data.m_storage = m_cur;
  parents.m_size.m_storage = m_size;
  hkUnionFind::hkUnionFind(&checkConnectivityOut, &parents, v13);
  if ( hkpSimulationIsland::isFullyConnected(v5, &checkConnectivityOut) )
  {
    *((_BYTE *)v5 + 49) &= 0xF3u;
    goto LABEL_276;
  }
  elementsPerGroup.m_data = (int *)&v240;
  elementsPerGroup.m_capacityAndFlags = -2147483616;
  elementsPerGroup.m_size = 0;
  hkUnionFind::assignGroups(&checkConnectivityOut, &result, &elementsPerGroup);
  v14 = elementsPerGroup.m_size;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = v15->m_cur;
  v17 = (v14 + 128) & 0xFFFFFF80;
  result.m_enum = v17;
  v225 = v16;
  v18 = &v16[v17];
  if ( v17 > v15->m_slabSize || v18 > v15->m_end )
  {
    v16 = (_BYTE *)hkLifoAllocator::allocateFromNewSlab(v15, v17);
    v225 = v16;
  }
  else
  {
    v15->m_cur = v18;
  }
  v19 = 1i64;
  if ( (*((_BYTE *)v5 + 49) & 0xC) == 0 )
  {
    if ( !HIDWORD(world[17].m_data) )
    {
      hkString::memSet(v16, 0, elementsPerGroup.m_size + 1);
      goto LABEL_159;
    }
    v93 = elementsPerGroup.m_size;
    v94 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v48 = (char *)v94->m_cur;
    v49 = (4 * v93 + 127) & 0xFFFFFF80;
    v223 = v49;
    v95 = &v48[v49];
    if ( v49 > v94->m_slabSize || v95 > v94->m_end )
      v48 = (char *)hkLifoAllocator::allocateFromNewSlab(v94, v49);
    else
      v94->m_cur = v95;
    v96 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v97 = (int *)v96->m_cur;
    v98 = (char *)v97 + v49;
    if ( v49 > v96->m_slabSize || v98 > v96->m_end )
      v97 = (int *)hkLifoAllocator::allocateFromNewSlab(v96, v49);
    else
      v96->m_cur = v98;
    p.m_data.m_storage = v97;
    p.m_size.m_storage = v93;
    v99 = v93;
    v100 = 0i64;
    if ( (int)v93 > 0 )
    {
      do
      {
        p.m_data.m_storage[v100++] = 0;
        *(_DWORD *)&v48[4 * v100 - 4] = 0;
      }
      while ( v100 < v93 );
    }
    if ( BYTE5(world[20].m_data) )
    {
      v101 = 0;
      if ( v5->m_entities.m_size > 0 )
      {
        v102 = 0i64;
        v103 = 0i64;
        do
        {
          v104 = (unsigned __int16 *)v5->m_entities.m_data[v103];
          v105 = v104[178];
          v106 = checkConnectivityOut.m_parents->m_data.m_storage[v102];
          if ( (unsigned __int8)retaddr->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v105 >> 14 )
            v105 >>= 7;
          v107 = v104[177];
          v108 = v105 & 0x7F;
          if ( (unsigned __int8)retaddr->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v107 >> 14 )
            v107 >>= 7;
          v109 = v108 & 0x7F;
          v110 = v107 & 0x7F;
          if ( v110 > v109 )
            v109 = v110;
          if ( v109 <= 5 )
            p.m_data.m_storage[v106] = 1;
          v111 = v104[128];
          if ( !v104[128] )
            v111 = 1;
          ++v101;
          ++v103;
          *(_DWORD *)&v48[4 * v106] += v111;
          ++v102;
        }
        while ( v101 < v5->m_entities.m_size );
      }
    }
    else
    {
      v112 = 0;
      if ( v5->m_entities.m_size > 0 )
      {
        v113 = 0i64;
        v114 = 0i64;
        do
        {
          ++v114;
          ++v113;
          v115 = v5->m_entities.m_data[v114 - 1];
          v116 = checkConnectivityOut.m_parents->m_data.m_storage[v113 - 1];
          p.m_data.m_storage[v116] = 1;
          v117 = v115->m_constraintsMaster.m_size;
          if ( !v115->m_constraintsMaster.m_size )
            v117 = 1;
          ++v112;
          *(_DWORD *)&v48[v116 * 4] += v117;
        }
        while ( v112 < v5->m_entities.m_size );
      }
    }
    for ( i = 0i64; i < v99; ++i )
    {
      if ( !p.m_data.m_storage[i] )
        *(_DWORD *)&v48[4 * i] = -1;
    }
    m_enum = HK_SUCCESS;
    v119 = 0i64;
    m_storage = p.m_data.m_storage;
    if ( v99 <= 0 )
      goto LABEL_99;
    v120 = v99;
    v121 = p.m_data.m_storage;
    v230 = p.m_data.m_storage;
    v122 = (int *)v48;
    v123 = p.m_data.m_storage;
    *(_QWORD *)&v233[0].m_enum = v99;
    do
    {
      v124 = *v122;
      if ( *v122 != -2 )
      {
        v125 = m_enum;
        v126 = &v225[v119];
        ++m_enum;
        ++v119;
        *v126 = 0;
        *v121 = v125;
        *(_QWORD *)&v232[0].m_enum = v119;
        if ( v124 >= 0 )
        {
          v127 = v19;
          if ( v19 < v99 )
          {
            v128 = v122 + 1;
            do
            {
              m_minDesiredIslandSize = retaddr->m_minDesiredIslandSize;
              if ( v124 + 10 >= m_minDesiredIslandSize )
                break;
              v130 = *v128;
              if ( *v128 >= 0 && v130 + v124 < m_minDesiredIslandSize )
              {
                *v126 = 1;
                *(int *)((char *)v128 + v123 - v48) = v125;
                v124 += v130;
                *v128 = -2;
              }
              ++v127;
              ++v128;
            }
            while ( v127 < v99 );
            v121 = v230;
            m_enum = v232[0].m_enum;
            v119 = *(_QWORD *)&v232[0].m_enum;
            v120 = *(_QWORD *)&v233[0].m_enum;
            v123 = m_storage;
          }
        }
      }
      ++v121;
      ++v122;
      ++v19;
      --v120;
      v230 = v121;
      *(_QWORD *)&v233[0].m_enum = v120;
    }
    while ( v120 );
    goto LABEL_98;
  }
  if ( !BYTE5(world[20].m_data) )
  {
    v46 = elementsPerGroup.m_size;
    v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v48 = (char *)v47->m_cur;
    v49 = (4 * v46 + 127) & 0xFFFFFF80;
    v223 = v49;
    v50 = &v48[v49];
    if ( v49 > v47->m_slabSize || v50 > v47->m_end )
      v48 = (char *)hkLifoAllocator::allocateFromNewSlab(v47, v49);
    else
      v47->m_cur = v50;
    v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v52 = (int *)v51->m_cur;
    v53 = (char *)v52 + v49;
    if ( v49 > v51->m_slabSize || v53 > v51->m_end )
      v52 = (int *)hkLifoAllocator::allocateFromNewSlab(v51, v49);
    else
      v51->m_cur = v53;
    p.m_data.m_storage = v52;
    p.m_size.m_storage = v46;
    v54 = v46;
    v55 = 0i64;
    if ( (int)v46 > 0 )
    {
      do
      {
        p.m_data.m_storage[v55++] = 0;
        *(_DWORD *)&v48[4 * v55 - 4] = 0;
      }
      while ( v55 < v46 );
    }
    if ( BYTE5(world[20].m_data) )
    {
      v56 = 0;
      if ( v5->m_entities.m_size > 0 )
      {
        v57 = 0i64;
        v58 = 0i64;
        do
        {
          v59 = (unsigned __int16 *)v5->m_entities.m_data[v58];
          v60 = v59[178];
          v61 = checkConnectivityOut.m_parents->m_data.m_storage[v57];
          if ( (unsigned __int8)retaddr->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v60 >> 14 )
            v60 >>= 7;
          v62 = v59[177];
          v63 = v60 & 0x7F;
          if ( (unsigned __int8)retaddr->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v62 >> 14 )
            v62 >>= 7;
          v64 = v63 & 0x7F;
          v65 = v62 & 0x7F;
          if ( v65 > v64 )
            v64 = v65;
          if ( v64 <= 5 )
            p.m_data.m_storage[v61] = 1;
          v66 = v59[128];
          if ( !v59[128] )
            v66 = 1;
          ++v56;
          ++v58;
          *(_DWORD *)&v48[4 * v61] += v66;
          ++v57;
        }
        while ( v56 < v5->m_entities.m_size );
      }
    }
    else
    {
      v67 = 0;
      if ( v5->m_entities.m_size > 0 )
      {
        v68 = 0i64;
        v69 = 0i64;
        do
        {
          ++v69;
          ++v68;
          v70 = v5->m_entities.m_data[v69 - 1];
          v71 = checkConnectivityOut.m_parents->m_data.m_storage[v68 - 1];
          p.m_data.m_storage[v71] = 1;
          v72 = v70->m_constraintsMaster.m_size;
          if ( !v70->m_constraintsMaster.m_size )
            v72 = 1;
          ++v67;
          *(_DWORD *)&v48[v71 * 4] += v72;
        }
        while ( v67 < v5->m_entities.m_size );
      }
    }
    for ( j = 0i64; j < v54; ++j )
    {
      if ( !p.m_data.m_storage[j] )
        *(_DWORD *)&v48[4 * j] = -1;
    }
    m_enum = HK_SUCCESS;
    v75 = 0i64;
    m_storage = p.m_data.m_storage;
    if ( v54 <= 0 )
      goto LABEL_99;
    v76 = v54;
    v77 = p.m_data.m_storage;
    v230 = p.m_data.m_storage;
    v78 = (int *)v48;
    v79 = p.m_data.m_storage;
    *(_QWORD *)&v233[0].m_enum = v54;
    do
    {
      v80 = *v78;
      if ( *v78 != -2 )
      {
        v81 = m_enum++;
        v82 = &v225[v75++];
        *v82 = 0;
        *(_QWORD *)&v232[0].m_enum = v75;
        *v77 = v81;
        if ( v80 >= 0 )
        {
          v83 = v19;
          if ( v19 < v54 )
          {
            v84 = v78 + 1;
            do
            {
              v85 = retaddr->m_minDesiredIslandSize;
              if ( v80 + 10 >= v85 )
                break;
              v86 = *v84;
              if ( *v84 >= 0 && v86 + v80 < v85 )
              {
                *v82 = 1;
                *(int *)((char *)v84 + v79 - v48) = v81;
                v80 += v86;
                *v84 = -2;
              }
              ++v83;
              ++v84;
            }
            while ( v83 < v54 );
            v77 = v230;
            m_enum = v232[0].m_enum;
            v75 = *(_QWORD *)&v232[0].m_enum;
            v76 = *(_QWORD *)&v233[0].m_enum;
            v79 = m_storage;
          }
        }
      }
      ++v77;
      ++v78;
      ++v19;
      --v76;
      v230 = v77;
      *(_QWORD *)&v233[0].m_enum = v76;
    }
    while ( v76 );
LABEL_98:
    v5 = vars0;
    v49 = v223;
LABEL_99:
    hkUnionFind::reindex(&checkConnectivityOut, &p, (unsigned int)m_enum, &elementsPerGroup);
    v87 = p.m_data.m_storage;
    v88 = (4 * p.m_size.m_storage + 127) & 0xFFFFFF80;
    v89 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v90 = (v88 + 15) & 0xFFFFFFF0;
    if ( v88 > v89->m_slabSize || (char *)v87 + v90 != v89->m_cur || v89->m_firstNonLifoEnd == v87 )
      hkLifoAllocator::slowBlockFree(v89, (char *)v87, v90);
    else
      v89->m_cur = v87;
    v91 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v92 = (v49 + 15) & 0xFFFFFFF0;
    if ( v49 > v91->m_slabSize || &v48[v92] != v91->m_cur || v91->m_firstNonLifoEnd == v48 )
    {
      hkLifoAllocator::slowBlockFree(v91, v48, v92);
      newIslandsOut = currentIsland;
      oldEntitiesOut = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)world;
      v16 = v225;
    }
    else
    {
      oldEntitiesOut = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)world;
      v16 = v225;
      v91->m_cur = v48;
      newIslandsOut = currentIsland;
    }
    goto LABEL_159;
  }
  v20 = elementsPerGroup.m_size;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (__int64)v21->m_cur;
  v23 = (4 * v20 + 127) & 0xFFFFFF80;
  v24 = (void *)(v22 + v23);
  if ( v23 > v21->m_slabSize || v24 > v21->m_end )
    v22 = hkLifoAllocator::allocateFromNewSlab(v21, v23);
  else
    v21->m_cur = v24;
  v25 = 0i64;
  p.m_data.m_storage = (int *)v22;
  p.m_size.m_storage = v20;
  v26 = v20;
  v27 = 0i64;
  if ( (int)v20 > 0 )
  {
    do
    {
      *(_DWORD *)(v22 + 4 * v27) = 0;
      v22 = (__int64)p.m_data.m_storage;
      ++v27;
    }
    while ( v27 < v20 );
  }
  v28 = 0;
  if ( v5->m_entities.m_size > 0 )
  {
    v29 = 0i64;
    do
    {
      v30 = v5->m_entities.m_data[v25];
      v31 = v30->m_motion.m_deactivationNumInactiveFrames[1];
      if ( (unsigned __int8)retaddr->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v31 >> 14 )
        v31 >>= 7;
      v32 = v30->m_motion.m_deactivationNumInactiveFrames[0];
      v33 = v31 & 0x7F;
      if ( (unsigned __int8)retaddr->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v32 >> 14 )
        v32 >>= 7;
      v34 = v33 & 0x7F;
      v35 = v32 & 0x7F;
      if ( v35 > v34 )
        v34 = v35;
      if ( v34 <= 5 )
      {
        *(_DWORD *)(v22 + 4i64 * checkConnectivityOut.m_parents->m_data.m_storage[v29]) = 1;
        v22 = (__int64)p.m_data.m_storage;
      }
      ++v28;
      ++v25;
      ++v29;
    }
    while ( v28 < v5->m_entities.m_size );
    oldEntitiesOut = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)world;
  }
  v36 = 1i64;
  *v225 = 1;
  if ( (int)v20 > 0 )
  {
    v37 = v225 + 1;
    v38 = -v22;
    do
    {
      if ( *(int *)((char *)p.m_data.m_storage + v38 + v22) )
      {
        *(_DWORD *)v22 = 0;
      }
      else
      {
        *(_DWORD *)v22 = v36;
        *v37 = 0;
        v36 = (unsigned int)(v36 + 1);
        ++v37;
      }
      v22 += 4i64;
      --v26;
    }
    while ( v26 );
  }
  if ( (int)v36 <= (int)v20 )
  {
    hkUnionFind::reindex(&checkConnectivityOut, &p, v36, &elementsPerGroup);
    v42 = p.m_data.m_storage;
    v43 = (4 * p.m_size.m_storage + 127) & 0xFFFFFF80;
    v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v45 = (v43 + 15) & 0xFFFFFFF0;
    if ( v43 > v44->m_slabSize || (char *)v42 + v45 != v44->m_cur || v44->m_firstNonLifoEnd == v42 )
      hkLifoAllocator::slowBlockFree(v44, (char *)v42, v45);
    else
      v44->m_cur = v42;
    v16 = v225;
  }
  else
  {
    v16 = v225;
    *v225 = 0;
    v39 = (4 * p.m_size.m_storage + 127) & 0xFFFFFF80;
    v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v41 = (v39 + 15) & 0xFFFFFFF0;
    if ( v39 > v40->m_slabSize
      || (char *)p.m_data.m_storage + v41 != v40->m_cur
      || v40->m_firstNonLifoEnd == p.m_data.m_storage )
    {
      hkLifoAllocator::slowBlockFree(v40, (char *)p.m_data.m_storage, v41);
    }
    else
    {
      v40->m_cur = p.m_data.m_storage;
    }
  }
  if ( elementsPerGroup.m_size == 1 )
    goto LABEL_268;
LABEL_159:
  v131 = hkUnionFind::moveBiggestGroupToIndexZero(&checkConnectivityOut, &elementsPerGroup);
  v132 = *v16;
  *v16 = v16[v131];
  v16[v131] = v132;
  v133 = elementsPerGroup.m_size;
  v232[0] = (hkResult)elementsPerGroup.m_size;
  v233[0] = *(hkResult *)elementsPerGroup.m_data;
  v224 = v5->m_entities.m_size;
  if ( elementsPerGroup.m_size != 1 )
  {
    v134 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v135 = v134->m_cur;
    v136 = (8 * v133 + 127) & 0xFFFFFF80;
    v233[0].m_enum = v136;
    m_storage = v135;
    v137 = (char *)v135 + v136;
    if ( v136 > v134->m_slabSize || v137 > v134->m_end )
    {
      v135 = (_QWORD *)hkLifoAllocator::allocateFromNewSlab(v134, v136);
      m_storage = v135;
    }
    else
    {
      v134->m_cur = v137;
    }
    v138 = *v16 == 0;
    v139 = 1i64;
    v140 = v133;
    *((_BYTE *)v5 + 49) ^= (*((_BYTE *)v5 + 49) ^ (4 * !v138)) & 0xC;
    *v135 = v5;
    if ( v133 > 1 )
    {
      do
      {
        v141 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v142 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v141[11] + 8i64))(
                                        v141[11],
                                        184i64);
        if ( v142 )
        {
          hkpSimulationIsland::hkpSimulationIsland(v142, retaddr);
          v144 = v143;
        }
        else
        {
          v144 = 0i64;
        }
        *(_BYTE *)(v144 + 50) &= 0xF5u;
        *(_BYTE *)(v144 + 50) |= 5u;
        v145 = (*(_BYTE *)(v144 + 49) ^ (4 * (v225[v139] != 0))) & 0xC;
        *(_BYTE *)(v144 + 50) = *(_BYTE *)(v144 + 50) & 0xCF | 0x10;
        *(_BYTE *)(v144 + 49) ^= v145;
        *(_WORD *)(v144 + 44) = newIslandsOut->m_size;
        if ( newIslandsOut->m_size == (newIslandsOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&newIslandsOut->m_data, 8);
        newIslandsOut->m_data[newIslandsOut->m_size++] = (hkpSimulationIsland *)v144;
        v135[v139] = v144;
        v146 = elementsPerGroup.m_data[v139];
        if ( (*(_DWORD *)(v144 + 108) & 0x3FFFFFFF) >= v146 )
          v232[0].m_enum = HK_SUCCESS;
        else
          hkArrayUtil::_reserve(v232, &hkContainerHeapAllocator::s_alloc, (const void **)(v144 + 96), v146, 8);
        ++v139;
      }
      while ( v139 < v140 );
      v5 = vars0;
      oldEntitiesOut = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)world;
    }
    m_data = (int *)v5->m_entities.m_data;
    v148 = (int *)v5->m_entities.m_size;
    v230 = m_data;
    if ( oldEntitiesOut )
    {
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v5->m_entities,
        oldEntitiesOut);
      v149 = elementsPerGroup.m_data;
      v5->m_entities.m_size = 0;
      if ( (v5->m_entities.m_capacityAndFlags & 0x3FFFFFFF) < *v149 )
        hkArrayUtil::_reserve(v232, &hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_entities.m_data, *v149, 8);
      m_data = v230;
    }
    else
    {
      v5->m_entities.m_size = 0;
    }
    v150 = 0i64;
    *(_QWORD *)&v232[0].m_enum = 0i64;
    p.m_data.m_storage = v148;
    if ( (int)v148 > 0 )
    {
      do
      {
        v151 = *(_QWORD *)&m_data[2 * v150];
        v152 = v135[parents.m_data.m_storage[v150]];
        *(_QWORD *)(v151 + 296) = v152;
        *(_WORD *)(v151 + 244) = *(_WORD *)(v152 + 104);
        *(_QWORD *)(*(_QWORD *)(v152 + 96) + 8i64 * (int)(*(_DWORD *)(v152 + 104))++) = v151;
        if ( v5 != (hkpSimulationIsland *)v152 )
        {
          v153 = *(unsigned __int16 **)(v151 + 248);
          v154 = 0;
          if ( *(_WORD *)(v151 + 256) )
          {
            do
            {
              v155 = v153[18];
              v156 = v153[19];
              v157 = v153[20];
              --v5->m_numConstraints;
              v158 = *(_QWORD *)v153;
              m_maxSizeOfSchema = v5->m_constraintInfo.m_maxSizeOfSchema;
              v138 = *(_QWORD *)(*(_QWORD *)v153 + 96i64) == 0i64;
              HIDWORD(p_m_narrowphaseAgentTrack) = v155;
              p_m_midphaseAgentTrack = __PAIR64__(v157, v156);
              if ( !v138 )
              {
                v5->m_constraintInfo.m_sizeOfSchemas -= v155;
                v5->m_constraintInfo.m_numSolverResults -= v156;
                v5->m_constraintInfo.m_numSolverElemTemps -= v157;
                v160 = *(_WORD **)(v158 + 96);
                v160[19] -= v156;
                v160[20] -= v157;
                v160[18] -= v155;
              }
              ++*(_DWORD *)(v152 + 40);
              *(_QWORD *)(*(_QWORD *)v153 + 16i64) = v152;
              v161 = *(_QWORD *)v153;
              if ( *(_QWORD *)(*(_QWORD *)v153 + 96i64) )
              {
                v162 = v155;
                if ( *(_DWORD *)(v152 + 16) > m_maxSizeOfSchema )
                  m_maxSizeOfSchema = *(_DWORD *)(v152 + 16);
                if ( m_maxSizeOfSchema > v155 )
                  v162 = m_maxSizeOfSchema;
                *(_DWORD *)(v152 + 20) += v155;
                *(_DWORD *)(v152 + 24) += v156;
                *(_DWORD *)(v152 + 28) += v157;
                *(_DWORD *)(v152 + 16) = v162;
                v163 = *(_WORD **)(v161 + 96);
                v163[19] += v156;
                v163[20] += v157;
                v163[18] += v155;
                v164 = *(unsigned __int16 *)(*(_QWORD *)(v161 + 96) + 36i64);
                if ( *(_DWORD *)(v152 + 16) > v164 )
                  v164 = *(_DWORD *)(v152 + 16);
                *(_DWORD *)(v152 + 16) = v164;
              }
              ++v154;
              v153 += 32;
            }
            while ( v154 < *(unsigned __int16 *)(v151 + 256) );
            v150 = *(_QWORD *)&v232[0].m_enum;
            v135 = m_storage;
          }
          m_data = v230;
        }
        *(_QWORD *)&v232[0].m_enum = ++v150;
      }
      while ( v150 < (__int64)p.m_data.m_storage );
    }
    v165 = v5->m_actions.m_data;
    m_fixedIsland = retaddr->m_fixedIsland;
    v167 = v5->m_actions.m_size;
    v5->m_actions.m_size = 0;
    v168 = 0i64;
    v169 = v167;
    if ( (int)v167 > 0 )
    {
      do
      {
        v170 = v165[v168];
        if ( v170 )
        {
          v171 = v165[v168];
          v241 = &v244;
          vfptr = v170->vfptr;
          v173 = 0i64;
          v242 = 0;
          v243 = -2147483632;
          vfptr[2].__vecDelDtor(v171, (unsigned int)&v241);
          v174 = 0;
          if ( v242 > 0 )
          {
            v175 = (__int64)v241;
            do
            {
              v173 = *(hkpSimulationIsland **)(*(_QWORD *)v175 + 296i64);
              if ( v173 != m_fixedIsland )
                break;
              ++v174;
              v175 += 8i64;
            }
            while ( v174 < v242 );
          }
          v242 = 0;
          if ( v243 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v241, 8 * v243);
          v241 = 0i64;
          v243 = 0x80000000;
          v170->m_island = v173;
          if ( v173->m_actions.m_size == (v173->m_actions.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v173->m_actions.m_data, 8);
          v173->m_actions.m_data[v173->m_actions.m_size++] = v170;
        }
        ++v168;
      }
      while ( v168 < v169 );
      v5 = vars0;
    }
    hkpWorld::lockForIslandSplit(retaddr, v5);
    p_m_narrowphaseAgentTrack = &v5->m_narrowphaseAgentTrack;
    p_m_midphaseAgentTrack = (unsigned __int64)&v5->m_midphaseAgentTrack;
    if ( 8 * (v224 - v233[0].m_enum) >= v224 )
    {
      for ( k = 0i64; k < 2; ++k )
      {
        v186 = (__int64)*(&p_m_narrowphaseAgentTrack + k);
        v187 = *(_BYTE *)(v186 + 2);
        *(_QWORD *)&p.m_size.m_storage = &v229;
        v227 = 0;
        v228 = -2147483647;
        LOWORD(p.m_data.m_storage) = 960;
        BYTE2(p.m_data.m_storage) = v187;
        v188 = *(_DWORD *)(v186 + 16);
        if ( v188 == 1 )
        {
          v189 = **(_QWORD **)(v186 + 8);
          v227 = 1;
          v229 = v189;
          *(_DWORD *)(v186 + 16) = 0;
        }
        else if ( v188 > 1 )
        {
          hkArrayUtil::_reserve(v233, &hkContainerHeapAllocator::s_alloc, (const void **)&p.m_size, 2, 8);
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&p.m_size,
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(v186 + 8));
        }
        v190 = (__int16)p.m_data.m_storage;
        v191 = 0;
        LOWORD(p.m_data.m_storage) = *(_WORD *)v186;
        *(_WORD *)v186 = v190;
        v192 = v227;
        if ( v227 > 0 )
        {
          v193 = 0i64;
          do
          {
            ++v191;
            v194 = *(hkpAgentNnEntry **)(v193 + *(_QWORD *)&p.m_size.m_storage);
            m_storage_low = LOWORD(p.m_data.m_storage);
            v196 = v194;
            if ( v191 != v192 )
              m_storage_low = 960;
            v197 = (unsigned __int64)v194 + m_storage_low;
            if ( (unsigned __int64)v194 < v197 )
            {
              do
              {
                v198 = *(_QWORD *)(&v196->m_collidable[0][2].m_broadPhaseHandle.m_type
                                 + v196->m_collidable[0]->m_ownerOffset);
                if ( *(_WORD *)(v198 + 44) == 0xFFFF )
                  v198 = *(_QWORD *)(&v196->m_collidable[1][2].m_broadPhaseHandle.m_type
                                   + v196->m_collidable[1]->m_ownerOffset);
                v199 = (hkpAgentNnTrack *)(v198 + 120);
                if ( !k )
                  v199 = (hkpAgentNnTrack *)(v198 + 152);
                hkAgentNnMachine_CopyAndRelinkAgentEntry(v199, v196);
                v196 = (hkpAgentNnEntry *)((char *)v196 + (unsigned __int8)v196->m_size);
              }
              while ( (unsigned __int64)v196 < v197 );
            }
            v200 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, hkpAgentNnEntry *, __int64))(*v200[11] + 16i64))(v200[11], v194, 960i64);
            v192 = v227;
            v193 += 8i64;
          }
          while ( v191 < v227 );
        }
        v227 = 0;
        if ( v228 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)&p.m_size.m_storage,
            8 * v228);
      }
      v5 = vars0;
    }
    else
    {
      v176 = 0i64;
      vars0 = 0i64;
      do
      {
        v177 = *(&p_m_narrowphaseAgentTrack + v176);
        v178 = 0;
        if ( v177->m_sectors.m_size > 0 )
        {
          v179 = 0i64;
          do
          {
            v180 = (hkpAgentNnEntry *)v177->m_sectors.m_data[v179];
            v181 = v180;
            while ( v181 < (hkpAgentNnEntry *)((char *)v180 + (int)hkpAgentNnTrack::getSectorSize(v177, v178)) )
            {
              v182 = *(hkpSimulationIsland **)(&v181->m_collidable[0][2].m_broadPhaseHandle.m_type
                                             + v181->m_collidable[0]->m_ownerOffset);
              if ( v182->m_storageIndex == 0xFFFF )
                v182 = *(hkpSimulationIsland **)(&v181->m_collidable[1][2].m_broadPhaseHandle.m_type
                                               + v181->m_collidable[1]->m_ownerOffset);
              if ( v182 == v5 )
              {
                v181 = (hkpAgentNnEntry *)((char *)v181 + (unsigned __int8)v181->m_size);
              }
              else
              {
                v183 = &v182->m_midphaseAgentTrack;
                v184 = (char *)((char *)v181 - (char *)v180);
                if ( !vars0 )
                  v183 = &v182->m_narrowphaseAgentTrack;
                hkAgentNnMachine_CopyAndRelinkAgentEntry(v183, v181);
                hkAgentNnMachine_InternalDeallocateEntry(v177, v181);
                if ( v178 >= v177->m_sectors.m_size )
                  break;
                v180 = (hkpAgentNnEntry *)v177->m_sectors.m_data[v179];
                v181 = (hkpAgentNnEntry *)((char *)v180 + (_QWORD)v184);
              }
            }
            ++v178;
            ++v179;
          }
          while ( v178 < v177->m_sectors.m_size );
          v176 = (__int64)vars0;
        }
        vars0 = (hkpSimulationIsland *)++v176;
      }
      while ( v176 < 2 );
    }
    hkpWorld::unlockForIslandSplit(retaddr, v5);
    p_m_sectors = &v5->m_narrowphaseAgentTrack.m_sectors;
    m_capacityAndFlags = v5->m_narrowphaseAgentTrack.m_sectors.m_capacityAndFlags;
    if ( m_capacityAndFlags >= 0 )
    {
      v203 = ((((((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 4) | ((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 2) | ((((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 4) | ((((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3)) >> 8) | ((unsigned int)(p_m_sectors->m_size + 3) >> 16) | (p_m_sectors->m_size + 3);
      v204 = (v203 | (v203 >> 1)) + 1;
      if ( v204 < 1 )
      {
        v205 = 1;
        hkArrayUtil::_reduce(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_sectors->m_data,
          8,
          (char *)v5->m_narrowphaseAgentTrack.m_sectors.m_storage,
          1);
LABEL_254:
        v206 = &v5->m_midphaseAgentTrack.m_sectors;
        v207 = v5->m_midphaseAgentTrack.m_sectors.m_capacityAndFlags;
        if ( v207 >= 0 )
        {
          v208 = ((((((((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3)) >> 8) | ((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3)) >> 4) | ((((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3)) >> 8) | ((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3)) >> 2) | ((((((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3)) >> 8) | ((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3)) >> 4) | ((((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3)) >> 8) | ((unsigned int)(v206->m_size + 3) >> 16) | (v206->m_size + 3);
          v209 = (v208 | (v208 >> 1)) + 1;
          if ( v209 >= 1 )
          {
            if ( v209 < (v207 & 0x3FFFFFFF) )
              hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&v206->m_data, 8, 0i64, v209);
          }
          else
          {
            hkArrayUtil::_reduce(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&v206->m_data,
              8,
              (char *)v5->m_midphaseAgentTrack.m_sectors.m_storage,
              1);
          }
        }
        v210 = v232[0].m_enum;
        v211 = (char *)m_storage;
        if ( v232[0].m_enum > HK_FAILURE )
        {
          v212 = (__int64 *)((char *)m_storage + 8);
          do
          {
            v213 = *v212;
            v214 = v205++;
            ++v212;
            *(_BYTE *)(v213 + 48) = v5->m_splitCheckFrameCounter + v214;
          }
          while ( v205 < v210 );
        }
        v215 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v216 = (v233[0].m_enum + 15) & 0xFFFFFFF0;
        if ( v233[0].m_enum > v215->m_slabSize || &v211[v216] != v215->m_cur || v215->m_firstNonLifoEnd == v211 )
          hkLifoAllocator::slowBlockFree(v215, v211, v216);
        else
          v215->m_cur = v211;
        v16 = v225;
        goto LABEL_268;
      }
      if ( v204 < (m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reduce(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_sectors->m_data, 8, 0i64, v204);
    }
    v205 = 1;
    goto LABEL_254;
  }
LABEL_268:
  v217 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v218 = (result.m_enum + 15) & 0xFFFFFFF0;
  if ( result.m_enum > v217->m_slabSize || &v16[v218] != v217->m_cur || v217->m_firstNonLifoEnd == v16 )
    hkLifoAllocator::slowBlockFree(v217, v16, v218);
  else
    v217->m_cur = v16;
  elementsPerGroup.m_size = 0;
  if ( elementsPerGroup.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      elementsPerGroup.m_data,
      4 * elementsPerGroup.m_capacityAndFlags);
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_capacityAndFlags = 0x80000000;
LABEL_276:
  v219 = parents.m_data.m_storage;
  v220 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v221 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v222 = (v220 + 15) & 0xFFFFFFF0;
  if ( v220 > v221->m_slabSize || (char *)v219 + v222 != v221->m_cur || v221->m_firstNonLifoEnd == v219 )
    hkLifoAllocator::slowBlockFree(v221, (char *)v219, v222);
  else
    v221->m_cur = v219;
}

// File Line: 1237
// RVA: 0xD804A0
void __fastcall hkpWorldOperationUtil::splitSimulationIsland(
        hkArray<hkpEntity *,hkContainerHeapAllocator> *world,
        hkpSimulationIsland *currentIsland)
{
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v4; // r14
  char v5; // r12
  int m_size; // edi
  int v7; // esi
  char v8; // bl
  char v9; // dl
  hkpSimulationIsland *v10; // rdi
  char v11; // al
  char v12; // [rsp+70h] [rbp+18h]

  v4 = (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)&world[4];
  v5 = *((_BYTE *)currentIsland + 50) & 3;
  if ( !v5 )
    v4 = (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)&world[5];
  *((_BYTE *)currentIsland + 49) &= 0xFCu;
  m_size = v4->m_size;
  v12 = m_size;
  hkpWorldOperationUtil::splitSimulationIsland(
    (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)currentIsland,
    world,
    v4,
    0i64);
  v7 = m_size;
  v8 = (*((_BYTE *)currentIsland + 50) >> 2) & 3;
  if ( m_size < v4->m_size )
  {
    v9 = 4 * (v5 & 3);
    do
    {
      v10 = v4->m_data[v7];
      *((_BYTE *)v10 + 50) &= 0xF3u;
      *((_BYTE *)v10 + 50) = v5 | (*((_BYTE *)v10 + 50) | v9) & 0xFC;
      if ( v5 )
      {
        if ( !v8 )
        {
          hkpWorldOperationUtil::markIslandInactive((hkpWorld *)world, v10);
          v9 = 4 * (v5 & 3);
        }
      }
      v11 = v7++ + currentIsland->m_splitCheckFrameCounter - v12;
      v10->m_splitCheckFrameCounter = v11;
    }
    while ( v7 < v4->m_size );
  }
}

// File Line: 1282
// RVA: 0xD80450
void __fastcall hkpWorldOperationUtil::splitSimulationIslands(hkpWorld *world)
{
  int v2; // eax
  __int64 i; // rbx
  hkpSimulationIsland *v4; // rdx

  if ( world->m_wantSimulationIslands.m_bool )
  {
    v2 = world->m_activeSimulationIslands.m_size - 1;
    for ( i = v2; i >= 0; --i )
    {
      v4 = world->m_activeSimulationIslands.m_data[i];
      if ( (*((_BYTE *)v4 + 49) & 3) != 0 )
        hkpWorldOperationUtil::splitSimulationIsland(world, v4);
    }
  }
}

// File Line: 1328
// RVA: 0xD7EA90
void __fastcall hkpWorldOperationUtil::mergeIslands(hkpWorld *world, hkpEntity *entityA, hkpEntity *entityB)
{
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpEntity *v4; // [rsp+28h] [rbp-20h]
  hkpEntity *v5; // [rsp+30h] [rbp-18h]

  if ( world->m_criticalOperationsLockCount )
  {
    v4 = entityA;
    operation.m_type.m_storage = 13;
    v5 = entityB;
    hkpWorld::queueOperation(world, &operation);
  }
  else
  {
    hkpWorldOperationUtil::internalMergeTwoIslands(world, entityA->m_simulationIsland, entityB->m_simulationIsland);
  }
}

// File Line: 1349
// RVA: 0xD7EAE0
void __fastcall hkpWorldOperationUtil::internalMergeTwoIslands(
        hkpWorld *world,
        hkpSimulationIsland *islandA,
        hkpSimulationIsland *islandB)
{
  int m_size; // eax
  int v5; // ecx
  hkpSimulationIsland *v6; // rdi
  hkpSimulationIsland *v7; // rbx
  char v8; // al
  bool v9; // dl
  bool v10; // r12
  hkpSimulationIsland *v11; // rdx
  char v12; // al
  int v13; // r14d
  unsigned __int16 v14; // bp
  int v15; // eax
  int v16; // eax
  int v17; // r9d
  int v18; // r9d
  __int64 v19; // r8
  hkpEntity *v20; // rax
  __int64 v21; // r15
  int v22; // ebp
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  int v26; // r8d
  __int64 v27; // r9
  __int64 v28; // rdx
  hkpAction *v29; // rcx
  int v30; // eax
  int v31; // eax
  int v32; // r9d
  int v33; // r9d
  __int64 v34; // r10
  hkpEntity *v35; // rcx
  hkConstraintInternal *m_data; // rdx
  int i; // r8d
  hkpConstraintInstance *m_constraint; // rax
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_activeSimulationIslands; // r9
  bool v40; // zf
  unsigned __int16 m_storageIndex; // r10
  __int64 v42; // r11
  __int64 v43; // r8
  bool v44; // al
  char v45; // cl
  bool v46; // al
  __int64 v47; // rcx
  hkpSimulationIsland *v48; // rdx
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_size = islandA->m_entities.m_size;
  v5 = islandB->m_entities.m_size;
  v6 = islandB;
  v7 = islandA;
  if ( m_size <= v5 && (m_size < v5 || islandA->m_storageIndex > islandB->m_storageIndex) )
  {
    v7 = islandB;
    v6 = islandA;
  }
  ++world->m_criticalOperationsLockCount;
  v8 = *((_BYTE *)v7 + 50);
  v9 = (v8 & 3) != 0 || (*((_BYTE *)v6 + 50) & 3) != 0;
  v10 = (v8 & 0xC) != 0 || (*((_BYTE *)v6 + 50) & 0xC) != 0;
  if ( v9 )
  {
    if ( (v8 & 3) != 0 )
    {
      v12 = *((_BYTE *)v6 + 50);
      if ( (v12 & 3) != 0 )
        goto LABEL_19;
      v11 = v6;
      *((_BYTE *)v6 + 50) = v12 & 0xF3 | 4;
    }
    else
    {
      v11 = v7;
      *((_BYTE *)v7 + 50) = v8 & 0xF3 | 4;
    }
    hkpWorldOperationUtil::internalActivateIsland(world, v11, 0);
  }
LABEL_19:
  *((_BYTE *)v7 + 49) |= *((_BYTE *)v6 + 49) & 0xC;
  hkpSimulationIsland::markForWrite(v7);
  hkpSimulationIsland::markForWrite(v6);
  hkpSimulationIsland::markForWrite(world->m_fixedIsland);
  hkAgentNnMachine_AppendTrack(&v7->m_narrowphaseAgentTrack, &v6->m_narrowphaseAgentTrack);
  hkAgentNnMachine_AppendTrack(&v7->m_midphaseAgentTrack, &v6->m_midphaseAgentTrack);
  v13 = v7->m_entities.m_size + v6->m_entities.m_size;
  v14 = v7->m_entities.m_size;
  v15 = v7->m_entities.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < v13 )
  {
    v16 = 2 * v15;
    v17 = v7->m_entities.m_size + v6->m_entities.m_size;
    if ( v13 < v16 )
      v17 = v16;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_entities.m_data, v17, 8);
  }
  v7->m_entities.m_size = v13;
  v18 = 0;
  if ( v6->m_entities.m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = v6->m_entities.m_data[v19];
      ++v18;
      ++v19;
      v7->m_entities.m_data[v14] = v20;
      v6->m_entities.m_data[v19 - 1]->m_simulationIsland = v7;
      v6->m_entities.m_data[v19 - 1]->m_storageIndex = v14++;
    }
    while ( v18 < v6->m_entities.m_size );
  }
  v21 = v7->m_actions.m_size;
  v22 = v21 + v6->m_actions.m_size;
  v23 = v7->m_actions.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < v22 )
  {
    v24 = 2 * v23;
    v25 = v21 + v6->m_actions.m_size;
    if ( v22 < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_actions.m_data, v25, 8);
  }
  v7->m_actions.m_size = v22;
  v26 = 0;
  if ( v6->m_actions.m_size > 0 )
  {
    v27 = v21;
    v28 = 0i64;
    do
    {
      v29 = v6->m_actions.m_data[v28];
      if ( v29 )
      {
        LODWORD(v21) = v21 + 1;
        v7->m_actions.m_data[v27++] = v29;
        v7->m_actions.m_data[v27 - 1]->m_island = v7;
      }
      ++v26;
      ++v28;
    }
    while ( v26 < v6->m_actions.m_size );
  }
  v30 = v7->m_actions.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v30 < (int)v21 )
  {
    v31 = 2 * v30;
    v32 = v21;
    if ( (int)v21 < v31 )
      v32 = v31;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_actions.m_data, v32, 8);
  }
  v7->m_actions.m_size = v21;
  v33 = 0;
  if ( v6->m_entities.m_size > 0 )
  {
    v34 = 0i64;
    do
    {
      v35 = v6->m_entities.m_data[v34];
      m_data = v35->m_constraintsMaster.m_data;
      for ( i = v35->m_constraintsMaster.m_size - 1; i >= 0; m_constraint->m_owner = v7 )
      {
        --i;
        m_constraint = m_data->m_constraint;
        ++m_data;
      }
      ++v33;
      ++v34;
    }
    while ( v33 < v6->m_entities.m_size );
  }
  hkpSimulationIsland::mergeConstraintInfo(v7, v6);
  p_m_activeSimulationIslands = &world->m_activeSimulationIslands;
  v7->m_numConstraints += v6->m_numConstraints;
  v40 = (*((_BYTE *)v6 + 50) & 3) == 0;
  m_storageIndex = v6->m_storageIndex;
  v6->m_numConstraints = 0;
  if ( v40 )
    p_m_activeSimulationIslands = &world->m_inactiveSimulationIslands;
  v42 = p_m_activeSimulationIslands->m_size;
  if ( m_storageIndex < (int)v42 - 1 )
  {
    v43 = m_storageIndex;
    p_m_activeSimulationIslands->m_data[v43] = p_m_activeSimulationIslands->m_data[v42 - 1];
    p_m_activeSimulationIslands->m_data[v43]->m_storageIndex = m_storageIndex;
  }
  --p_m_activeSimulationIslands->m_size;
  v44 = (*((_BYTE *)v7 + 49) & 3) != 0 || (*((_BYTE *)v6 + 49) & 3) != 0;
  *((_BYTE *)v7 + 49) &= 0xFCu;
  *((_BYTE *)v7 + 49) |= v44 & 3;
  v45 = *((_BYTE *)v7 + 49);
  v46 = (v45 & 0x30) != 0 || (*((_BYTE *)v6 + 49) & 0x30) != 0;
  *((_BYTE *)v7 + 50) &= 0xF3u;
  *((_BYTE *)v7 + 49) = v45 ^ (v45 ^ (16 * v46)) & 0x30;
  *((_BYTE *)v7 + 50) |= 4 * v10;
  if ( v6->m_dirtyListIndex != 0xFFFF )
  {
    EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
    if ( v7->m_dirtyListIndex == 0xFFFF )
    {
      v7->m_dirtyListIndex = world->m_dirtySimulationIslands.m_size;
      if ( world->m_dirtySimulationIslands.m_size == (world->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&world->m_dirtySimulationIslands.m_data,
          8);
      world->m_dirtySimulationIslands.m_data[world->m_dirtySimulationIslands.m_size++] = v7;
    }
    LeaveCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
  }
  hkpWorldOperationUtil::removeIslandFromDirtyList(world, v6);
  v6->vfptr->__vecDelDtor(v6, 1u);
  if ( (*((_BYTE *)v7 + 50) & 3) != 0 )
  {
    v47 = v7->m_storageIndex;
    if ( v7->m_storageIndex )
    {
      v48 = *world->m_activeSimulationIslands.m_data;
      if ( v7->m_entities.m_size > v48->m_entities.m_size )
      {
        v7->m_storageIndex = 0;
        v48->m_storageIndex = v47;
        *world->m_activeSimulationIslands.m_data = v7;
        world->m_activeSimulationIslands.m_data[v47] = v48;
      }
    }
  }
  hkpWorld::checkDeterminismOfIslandBroadPhase(world, v7);
  v40 = world->m_criticalOperationsLockCount-- == 1;
  if ( v40 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 )
    {
      if ( world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(world);
    }
  }
}

// File Line: 1549
// RVA: 0xD80580
void __fastcall hkpWorldOperationUtil::validateWorld(hkpWorld *world)
{
  int v2; // eax
  __int64 i; // rbx
  int v4; // eax
  __int64 j; // rbx

  v2 = world->m_activeSimulationIslands.m_size - 1;
  for ( i = v2; i >= 0; hkpSimulationIsland::isValid(world->m_activeSimulationIslands.m_data[i--]) )
    ;
  v4 = world->m_inactiveSimulationIslands.m_size - 1;
  for ( j = v4; j >= 0; hkpSimulationIsland::isValid(world->m_inactiveSimulationIslands.m_data[j--]) )
    ;
  hkpSimulationIsland::isValid(world->m_fixedIsland);
}

// File Line: 1573
// RVA: 0xD80AE0
void __fastcall hkpWorldOperationUtil::setRigidBodyMotionType(
        hkpRigidBody *body,
        hkpMotion::MotionType newState,
        hkpEntityActivation initialActivationState,
        hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode)
{
  int m_storage; // ebx
  bool v8; // r14
  bool v9; // si
  hkpWorld *world; // rdi
  hkpSimulationIsland *m_simulationIsland; // rcx
  int v12; // r14d
  __int64 v13; // rsi
  hkpConstraintInstance *v14; // rbx
  int m_size; // r9d
  int v16; // ebx
  hkpEntity *v17; // rcx
  __int64 v18; // rsi
  hkpEntity *v19; // r8
  hkpSimulation *m_simulation; // rcx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+30h] [rbp-A8h] BYREF
  hkpAgentNnTrack agentsRemoved; // [rsp+40h] [rbp-98h] BYREF
  hkpAgentNnTrack appendee; // [rsp+60h] [rbp-78h] BYREF
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> removedConstraints; // [rsp+E8h] [rbp+10h] BYREF
  char v25; // [rsp+F8h] [rbp+20h] BYREF
  hkpEntity *entity[3]; // [rsp+1A8h] [rbp+D0h] BYREF

  m_storage = (unsigned __int8)body->m_motion.m_type.m_storage;
  if ( m_storage != newState )
  {
    if ( m_storage == 5 )
    {
      hkpLinkedCollidable::sortEntries(&body->m_collidable);
      hkpEntity::sortConstraintsSlavesDeterministically(entity[0]);
      body = (hkpRigidBody *)entity[0];
    }
    v8 = (unsigned int)(newState - 4) > 1;
    v9 = (unsigned int)(m_storage - 4) > 1;
    if ( (unsigned int)(newState - 4) <= 1 || (unsigned int)(m_storage - 4) > 1 || body->m_motion.m_savedMotion )
    {
      hkReferencedObject::addReference(body);
      world = entity[0]->m_world;
      if ( !world || (m_storage == 5) == (newState == MOTION_FIXED) )
      {
        hkpWorldOperationUtil::replaceMotionObject(
          (hkpRigidBody *)entity[0],
          newState,
          (hkBool)v8,
          (hkBool)v9,
          entity[0]->m_world);
        if ( world )
          hkpWorld::updateCollisionFilterOnEntity(
            world,
            entity[0],
            collisionFilterUpdateMode,
            HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      }
      else
      {
        *(_WORD *)&world->m_blockExecutingPendingOperations.m_bool = 1;
        removedConstraints.m_data = (hkpConstraintInstance **)&v25;
        agentsRemoved.m_bytesUsedInLastSector = 960;
        agentsRemoved.m_sectors.m_storage[0] = (hkpAgentNnSector *)&appendee.m_sectors;
        agentsRemoved.m_sectors.m_data = agentsRemoved.m_sectors.m_storage;
        removedConstraints.m_size = 0;
        *(_DWORD *)&appendee.m_bytesUsedInLastSector = 0x10000;
        agentsRemoved.m_sectors.m_size = 0;
        appendee.m_sectors.m_size = 0;
        removedConstraints.m_capacityAndFlags = -2147483632;
        appendee.m_sectors.m_data = appendee.m_sectors.m_storage;
        *(_DWORD *)(&appendee.m_padding + 1) = -2147483632;
        agentsRemoved.m_sectors.m_capacityAndFlags = -2147483647;
        agentsRemoved.m_nnTrackType.m_storage = 2;
        appendee.m_sectors.m_capacityAndFlags = -2147483647;
        hkpWorldOperationUtil::removeAttachedConstraints(entity[0], &removedConstraints);
        if ( newState == MOTION_FIXED )
          hkpWorldOperationUtil::removeAttachedActionsFromDynamicIsland(
            world,
            entity[0],
            (hkArray<hkpAction *,hkContainerHeapAllocator> *)agentsRemoved.m_sectors.m_storage);
        else
          hkpWorldOperationUtil::removeAttachedActionsFromFixedIsland(
            world,
            entity[0],
            (hkArray<hkpAction *,hkContainerHeapAllocator> *)agentsRemoved.m_sectors.m_storage);
        hkpWorldOperationUtil::removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(
          &entity[0]->m_simulationIsland->m_narrowphaseAgentTrack,
          entity[0],
          &agentsRemoved,
          newState);
        hkpWorldOperationUtil::removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(
          &entity[0]->m_simulationIsland->m_midphaseAgentTrack,
          entity[0],
          &appendee,
          newState);
        if ( m_storage != 5 )
        {
          m_simulationIsland = entity[0]->m_simulationIsland;
          if ( m_simulationIsland->m_entities.m_size > 2 )
          {
            *((_BYTE *)m_simulationIsland + 49) &= ~2u;
            *((_BYTE *)m_simulationIsland + 49) |= 1u;
          }
        }
        hkpWorldOperationUtil::removeEntitySI(world, entity[0]);
        hkpWorldOperationUtil::replaceMotionObject((hkpRigidBody *)entity[0], newState, (hkBool)v8, (hkBool)v9, world);
        hkpWorldOperationUtil::addEntitySI(world, entity[0], initialActivationState);
        hkpWorldOperationUtil::addActionsToEntitysIsland(
          world,
          entity[0],
          (hkArray<hkpAction *,hkContainerHeapAllocator> *)agentsRemoved.m_sectors.m_storage);
        world->m_criticalOperationsAllowed.m_bool = 1;
        entries.m_data = 0i64;
        entries.m_size = 0;
        entries.m_capacityAndFlags = 0x80000000;
        v12 = 0;
        if ( removedConstraints.m_size > 0 )
        {
          v13 = 0i64;
          do
          {
            v14 = removedConstraints.m_data[v13];
            hkpWorldOperationUtil::addConstraintImmediately(
              world,
              v14,
              DO_NOT_FIRE_CALLBACKS_AND_SUPPRESS_EXECUTION_OF_PENDING_OPERATIONS);
            hkReferencedObject::removeReference(v14);
            ++v12;
            ++v13;
          }
          while ( v12 < removedConstraints.m_size );
        }
        if ( newState == MOTION_FIXED
          || (hkpLinkedCollidable::getCollisionEntriesSorted(&entity[0]->m_collidable, &entries),
              m_size = entries.m_size,
              v16 = 0,
              entries.m_size <= 0) )
        {
          v17 = entity[0];
        }
        else
        {
          v17 = entity[0];
          v18 = 0i64;
          do
          {
            v19 = (hkpEntity *)((char *)entries.m_data[v18].m_partner + entries.m_data[v18].m_partner->m_ownerOffset);
            if ( v17->m_motion.m_type.m_storage != 5
              && v19->m_motion.m_type.m_storage != 5
              && v17->m_simulationIsland != v19->m_simulationIsland )
            {
              hkpWorldOperationUtil::mergeIslands(v17->m_world, v17, v19);
              v17 = entity[0];
              m_size = entries.m_size;
            }
            ++v16;
            ++v18;
          }
          while ( v16 < m_size );
        }
        hkAgentNnMachine_AppendTrack(&v17->m_simulationIsland->m_narrowphaseAgentTrack, &agentsRemoved);
        hkAgentNnMachine_AppendTrack(&entity[0]->m_simulationIsland->m_midphaseAgentTrack, &appendee);
        if ( newState == MOTION_FIXED )
        {
          hkSweptTransformUtil::freezeMotionState(
            world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage,
            &entity[0]->m_motion.m_motionState);
          m_simulation = world->m_simulation;
          ++world->m_criticalOperationsLockCount;
          ((void (__fastcall *)(hkpSimulation *, hkpEntity **, __int64, hkpWorld *, int))m_simulation->vfptr[6].__vecDelDtor)(
            m_simulation,
            entity,
            1i64,
            world,
            7);
          hkpSimulation::collideEntitiesBroadPhaseDiscrete(entity, 1u, world);
          hkpWorldCallbackUtil::fireInactiveEntityMoved(entity[0]->m_world, entity[0]);
          --world->m_criticalOperationsLockCount;
        }
        hkpWorld::updateCollisionFilterOnEntity(
          world,
          entity[0],
          collisionFilterUpdateMode,
          HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
        world->m_blockExecutingPendingOperations.m_bool = 0;
        if ( !world->m_criticalOperationsLockCount )
        {
          if ( world->m_pendingOperationsCount )
            hkpWorld::internal_executePendingOperations(world);
          if ( world->m_pendingOperationQueueCount == 1 && world->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(world);
        }
        entries.m_size = 0;
        if ( entries.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            entries.m_data,
            16 * entries.m_capacityAndFlags);
        entries.m_data = 0i64;
        entries.m_capacityAndFlags = 0x80000000;
        appendee.m_sectors.m_size = 0;
        if ( appendee.m_sectors.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            appendee.m_sectors.m_data,
            8 * appendee.m_sectors.m_capacityAndFlags);
        appendee.m_sectors.m_data = 0i64;
        appendee.m_sectors.m_capacityAndFlags = 0x80000000;
        agentsRemoved.m_sectors.m_size = 0;
        if ( agentsRemoved.m_sectors.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            agentsRemoved.m_sectors.m_data,
            8 * agentsRemoved.m_sectors.m_capacityAndFlags);
        agentsRemoved.m_sectors.m_data = 0i64;
        agentsRemoved.m_sectors.m_capacityAndFlags = 0x80000000;
        *(_DWORD *)&appendee.m_bytesUsedInLastSector = 0;
        if ( *(int *)(&appendee.m_padding + 1) >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            agentsRemoved.m_sectors.m_storage[0],
            8 * *(_DWORD *)(&appendee.m_padding + 1));
        agentsRemoved.m_sectors.m_storage[0] = 0i64;
        *(_DWORD *)(&appendee.m_padding + 1) = 0x80000000;
        removedConstraints.m_size = 0;
        if ( removedConstraints.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            removedConstraints.m_data,
            8 * removedConstraints.m_capacityAndFlags);
      }
      hkReferencedObject::removeReference(entity[0]);
    }
  }
}

// File Line: 1757
// RVA: 0xD81720
void __fastcall hkpWorldOperationUtil::removeAttachedConstraints(
        hkpEntity *entity,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *removedConstraints)
{
  hkpWorld *m_world; // r15
  int v4; // eax
  __int64 v6; // rdi
  __int64 v7; // rsi
  hkpConstraintInstance *v8; // rbp
  int v9; // eax
  __int64 i; // rdi
  hkpConstraintInstance *v11; // rsi

  m_world = entity->m_world;
  v4 = entity->m_constraintsMaster.m_size - 1;
  v6 = v4;
  if ( v4 >= 0 )
  {
    v7 = (__int64)v4 << 6;
    do
    {
      v8 = *(hkpConstraintInstance **)((char *)&entity->m_constraintsMaster.m_data->m_constraint + v7);
      hkReferencedObject::addReference(v8);
      hkpWorldOperationUtil::removeConstraintImmediately(
        m_world,
        v8,
        DO_NOT_FIRE_CALLBACKS_AND_SUPPRESS_EXECUTION_OF_PENDING_OPERATIONS);
      if ( removedConstraints->m_size == (removedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&removedConstraints->m_data, 8);
      v7 -= 64i64;
      removedConstraints->m_data[removedConstraints->m_size++] = v8;
      --v6;
    }
    while ( v6 >= 0 );
  }
  v9 = entity->m_constraintsSlave.m_size - 1;
  for ( i = v9; i >= 0; --i )
  {
    v11 = entity->m_constraintsSlave.m_data[i];
    hkReferencedObject::addReference(v11);
    hkpWorldOperationUtil::removeConstraintImmediately(
      m_world,
      v11,
      DO_NOT_FIRE_CALLBACKS_AND_SUPPRESS_EXECUTION_OF_PENDING_OPERATIONS);
    if ( removedConstraints->m_size == (removedConstraints->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&removedConstraints->m_data, 8);
    removedConstraints->m_data[removedConstraints->m_size++] = v11;
  }
}

// File Line: 1790
// RVA: 0xD81610
void __fastcall hkpWorldOperationUtil::removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(
        hkpAgentNnTrack *trackToScan,
        hkpEntity *entity,
        hkpAgentNnTrack *agentsRemoved,
        hkpMotion::MotionType newMotionType)
{
  int v6; // ebp
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *CollisionEntriesDeterministicUnchecked; // r12
  __int64 v8; // r14
  hkpLinkedCollidable::CollisionEntry *m_data; // rsi
  hkpAgentNnEntry *m_agentEntry; // rdi
  hkpSimulationIsland **v11; // rbx
  hkpAgentNnTrack *p_m_narrowphaseAgentTrack; // rcx
  hkpAgentNnEntry *v13; // rdx
  hkpSimulationIsland *v14; // rcx

  v6 = 0;
  CollisionEntriesDeterministicUnchecked = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(&entity->m_collidable);
  if ( CollisionEntriesDeterministicUnchecked->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = CollisionEntriesDeterministicUnchecked->m_data;
      m_agentEntry = CollisionEntriesDeterministicUnchecked->m_data[v8].m_agentEntry;
      if ( m_agentEntry->m_nnTrackType.m_storage == trackToScan->m_nnTrackType.m_storage )
      {
        v11 = (hkpSimulationIsland **)((char *)m_data[v8].m_partner + m_data[v8].m_partner->m_ownerOffset);
        if ( *((_BYTE *)v11 + 352) == 5 )
        {
          p_m_narrowphaseAgentTrack = agentsRemoved;
          v13 = CollisionEntriesDeterministicUnchecked->m_data[v8].m_agentEntry;
        }
        else
        {
          if ( newMotionType != MOTION_FIXED
            || hkpWorldAgentUtil::getIslandFromAgentEntry(m_agentEntry, entity->m_simulationIsland, v11[37]) != entity->m_simulationIsland )
          {
            goto LABEL_12;
          }
          v13 = m_data[v8].m_agentEntry;
          v14 = v11[37];
          if ( v13->m_nnTrackType.m_storage == 2 )
            p_m_narrowphaseAgentTrack = &v14->m_narrowphaseAgentTrack;
          else
            p_m_narrowphaseAgentTrack = &v14->m_midphaseAgentTrack;
        }
        hkAgentNnMachine_CopyAndRelinkAgentEntry(p_m_narrowphaseAgentTrack, v13);
        hkAgentNnMachine_InternalDeallocateEntry(trackToScan, m_agentEntry);
      }
LABEL_12:
      ++v6;
      ++v8;
    }
    while ( v6 < CollisionEntriesDeterministicUnchecked->m_size );
  }
}

// File Line: 1844
// RVA: 0xD825D0
hkBool *__fastcall worldOperationUtil_less_hkSimulationIslandPtr(
        hkBool *result,
        hkpSimulationIsland *a,
        hkpSimulationIsland *b)
{
  if ( b )
  {
    if ( a )
      result->m_bool = (*a->m_entities.m_data)->m_uid < (*b->m_entities.m_data)->m_uid;
    else
      result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 1852
// RVA: 0xD81840
void __fastcall hkpWorldOperationUtil::cleanupDirtyIslands(hkpWorld *world)
{
  int m_size; // r8d
  int i; // edx
  hkpSimulationIsland *v4; // r8
  __int64 v5; // rdx
  hkpSimulationIsland *m_simulationIsland; // rdi
  bool v7; // zf
  int v8; // r8d
  int v9; // ebp
  __int64 v10; // r9
  int v11; // eax
  __int64 v12; // rdx
  hkpAction **m_data; // rcx
  __int64 v14; // r9
  __int64 v15; // rcx
  hkpAction **v16; // rdx
  hkpAction *v17; // r8
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  unsigned __int8 v21; // dl
  char v22; // cl
  int m_numConstraints; // r8d
  hkpSimulationIsland *j; // rax
  hkpEntity *v25; // rbx
  int v26; // r8d
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = world->m_dirtySimulationIslands.m_size;
  if ( m_size )
  {
    if ( m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        (hkpRigidBody **)world->m_dirtySimulationIslands.m_data,
        0,
        m_size - 1,
        (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))worldOperationUtil_less_hkSimulationIslandPtr);
    for ( i = 0; i < world->m_dirtySimulationIslands.m_size; ++i )
    {
      v4 = world->m_dirtySimulationIslands.m_data[i];
      if ( v4 )
        v4->m_dirtyListIndex = i;
    }
    while ( world->m_dirtySimulationIslands.m_size )
    {
      v5 = world->m_dirtySimulationIslands.m_size;
      m_simulationIsland = world->m_dirtySimulationIslands.m_data[v5 - 1];
      world->m_dirtySimulationIslands.m_size = v5 - 1;
      if ( m_simulationIsland )
      {
        v7 = (*((_BYTE *)m_simulationIsland + 49) & 0x30) == 0;
        m_simulationIsland->m_dirtyListIndex = -1;
        if ( !v7 )
        {
          v8 = m_simulationIsland->m_actions.m_size;
          v9 = -1;
          v10 = -1i64;
          v11 = 0;
          v12 = 0i64;
          if ( v8 > 0 )
          {
            m_data = m_simulationIsland->m_actions.m_data;
            while ( *m_data )
            {
              ++v11;
              ++v12;
              ++m_data;
              if ( v11 >= v8 )
                goto LABEL_17;
            }
            v9 = v11;
            v10 = v12;
            ++v11;
            ++v12;
          }
LABEL_17:
          if ( v11 < v8 )
          {
            v14 = v10;
            v15 = v12;
            do
            {
              v16 = m_simulationIsland->m_actions.m_data;
              v17 = v16[v15];
              if ( v17 )
              {
                v16[v14] = v17;
                ++v9;
                ++v14;
              }
              ++v11;
              ++v15;
            }
            while ( v11 < m_simulationIsland->m_actions.m_size );
          }
          if ( v9 != -1 )
          {
            v18 = m_simulationIsland->m_actions.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v18 >= v9 )
            {
              result.m_enum = HK_SUCCESS;
            }
            else
            {
              v19 = 2 * v18;
              v20 = v9;
              if ( v9 < v19 )
                v20 = v19;
              hkArrayUtil::_reserve(
                &result,
                &hkContainerHeapAllocator::s_alloc,
                (const void **)&m_simulationIsland->m_actions.m_data,
                v20,
                8);
            }
            m_simulationIsland->m_actions.m_size = v9;
          }
          *((_BYTE *)m_simulationIsland + 49) &= 0xCFu;
        }
        v21 = *((_BYTE *)m_simulationIsland + 50);
        v22 = (v21 >> 2) & 3;
        if ( v22 == (v21 & 3) )
        {
          if ( (v21 & 0x30) != 0 && v22 )
          {
            *((_BYTE *)m_simulationIsland + 50) = v21 & 0xCF;
            m_numConstraints = m_simulationIsland->m_numConstraints;
            if ( m_simulationIsland->m_entities.m_size > m_numConstraints )
              m_numConstraints = m_simulationIsland->m_entities.m_size;
            for ( j = findSmallSparseActiveIsland(
                        world,
                        &world->m_activeSimulationIslands,
                        m_numConstraints,
                        m_simulationIsland);
                  j;
                  j = findSmallSparseActiveIsland(
                        world,
                        &world->m_activeSimulationIslands,
                        v26,
                        v25->m_simulationIsland) )
            {
              v25 = *m_simulationIsland->m_entities.m_data;
              hkpWorldOperationUtil::internalMergeTwoIslands(world, m_simulationIsland, j);
              m_simulationIsland = v25->m_simulationIsland;
              v26 = m_simulationIsland->m_numConstraints;
              if ( m_simulationIsland->m_entities.m_size > v26 )
                v26 = m_simulationIsland->m_entities.m_size;
            }
          }
        }
        else if ( v22 )
        {
          hkpWorldOperationUtil::internalActivateIsland(world, m_simulationIsland, (hkBool)1);
        }
        else
        {
          hkpWorldOperationUtil::internalDeactivateIsland(world, m_simulationIsland);
        }
      }
    }
    hkpWorld::checkDeterminism(world);
  }
}

// File Line: 1969
// RVA: 0xD7E6C0
void __fastcall hkpWorldOperationUtil::internalActivateIsland(
        hkpWorld *world,
        hkpSimulationIsland *island,
        hkBool allowIslandMerges)
{
  hkpSimulationIsland *m_simulationIsland; // rdi
  __int16 m_size; // ax
  int v6; // ebp
  __int64 v7; // r15
  hkpEntity *v8; // rbx
  int m_deactivationIntegrateCounter; // r10d
  __int16 v10; // dx
  __int16 v11; // r8
  unsigned __int16 v12; // r8
  hkpEntity *v13; // rbx
  int v14; // r8d
  int v15; // ebp
  hkpSimulationIsland *SmallSparseActiveIsland; // rax
  hkpEntity *v17; // rbx
  int v18; // r8d
  __int64 m_storageIndex; // rcx
  hkpSimulationIsland *v20; // rdx
  hkSimdFloat32 startTime; // [rsp+20h] [rbp-38h] BYREF

  m_simulationIsland = island;
  world->m_inactiveSimulationIslands.m_data[island->m_storageIndex] = world->m_inactiveSimulationIslands.m_data[world->m_inactiveSimulationIslands.m_size - 1];
  world->m_inactiveSimulationIslands.m_data[island->m_storageIndex]->m_storageIndex = island->m_storageIndex;
  --world->m_inactiveSimulationIslands.m_size;
  if ( world->m_activeSimulationIslands.m_size == (world->m_activeSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&world->m_activeSimulationIslands.m_data,
      8);
  world->m_activeSimulationIslands.m_data[world->m_activeSimulationIslands.m_size++] = m_simulationIsland;
  m_size = world->m_activeSimulationIslands.m_size;
  startTime.m_real = 0i64;
  *((_BYTE *)m_simulationIsland + 50) &= ~2u;
  *((_BYTE *)m_simulationIsland + 50) |= 1u;
  m_simulationIsland->m_storageIndex = m_size - 1;
  *(_QWORD *)&m_simulationIsland->m_timeSinceLastHighFrequencyCheck = 0i64;
  v6 = 0;
  if ( m_simulationIsland->m_entities.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = m_simulationIsland->m_entities.m_data[v7];
      hkSweptTransformUtil::setTimeInformation(&startTime, &startTime, &v8->m_motion.m_motionState);
      m_deactivationIntegrateCounter = (unsigned __int8)v8->m_motion.m_deactivationIntegrateCounter;
      *(_DWORD *)v8->m_motion.m_deactivationNumInactiveFrames = 0;
      v10 = (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
      v11 = (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
      if ( (unsigned __int8)(world->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(m_deactivationIntegrateCounter & 3) )
        v11 = ~v11;
      v12 = v11 << 14;
      if ( (unsigned __int8)world->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < m_deactivationIntegrateCounter )
        v10 = ~v10;
      ++v6;
      v8->m_motion.m_deactivationNumInactiveFrames[0] = v12;
      v8->m_motion.m_deactivationNumInactiveFrames[1] = v10 << 14;
      ++v7;
    }
    while ( v6 < m_simulationIsland->m_entities.m_size );
  }
  hkpWorldAgentUtil::warpTime(
    m_simulationIsland,
    m_simulationIsland->m_timeOfDeactivation,
    world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage,
    world->m_collisionInput);
  v13 = *m_simulationIsland->m_entities.m_data;
  hkReferencedObject::addReference(v13);
  hkpWorldCallbackUtil::fireIslandActivated(world, m_simulationIsland);
  if ( v13->m_simulationIsland == m_simulationIsland )
  {
    hkReferencedObject::removeReference(v13);
    if ( !allowIslandMerges.m_bool )
      goto LABEL_19;
    v14 = m_simulationIsland->m_numConstraints + 3;
    v15 = 0;
    if ( m_simulationIsland->m_entities.m_size + 1 > v14 )
      v14 = m_simulationIsland->m_entities.m_size + 1;
    SmallSparseActiveIsland = findSmallSparseActiveIsland(
                                world,
                                &world->m_activeSimulationIslands,
                                v14,
                                m_simulationIsland);
    if ( !SmallSparseActiveIsland )
      goto LABEL_19;
    do
    {
      v17 = *m_simulationIsland->m_entities.m_data;
      hkpWorldOperationUtil::internalMergeTwoIslands(world, SmallSparseActiveIsland, m_simulationIsland);
      m_simulationIsland = v17->m_simulationIsland;
      ++v15;
      v18 = m_simulationIsland->m_numConstraints + 3;
      if ( m_simulationIsland->m_entities.m_size + 1 > v18 )
        v18 = m_simulationIsland->m_entities.m_size + 1;
      SmallSparseActiveIsland = findSmallSparseActiveIsland(
                                  world,
                                  &world->m_activeSimulationIslands,
                                  v18,
                                  v17->m_simulationIsland);
    }
    while ( SmallSparseActiveIsland );
    if ( !v15 )
    {
LABEL_19:
      m_storageIndex = m_simulationIsland->m_storageIndex;
      if ( m_simulationIsland->m_storageIndex )
      {
        v20 = *world->m_activeSimulationIslands.m_data;
        if ( m_simulationIsland->m_entities.m_size > v20->m_entities.m_size )
        {
          m_simulationIsland->m_storageIndex = 0;
          v20->m_storageIndex = m_storageIndex;
          *world->m_activeSimulationIslands.m_data = m_simulationIsland;
          world->m_activeSimulationIslands.m_data[m_storageIndex] = v20;
        }
      }
    }
  }
  else
  {
    hkReferencedObject::removeReference(v13);
  }
}

// File Line: 2071
// RVA: 0xD7E930
void __fastcall hkpWorldOperationUtil::internalDeactivateIsland(hkpWorld *world, hkpSimulationIsland *island)
{
  int v4; // esi
  __int16 m_size; // ax
  __int64 v6; // r14
  hkpEntity *v7; // rbx

  if ( hkRigidMotionUtilCanDeactivateFinal(
         &world->m_dynamicsStepInfo.m_stepInfo,
         (hkpMotion *const *)island->m_entities.m_data,
         island->m_entities.m_size,
         336) )
  {
    if ( world->m_inactiveSimulationIslands.m_size == (world->m_inactiveSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&world->m_inactiveSimulationIslands.m_data,
        8);
    v4 = 0;
    world->m_inactiveSimulationIslands.m_data[world->m_inactiveSimulationIslands.m_size++] = island;
    world->m_activeSimulationIslands.m_data[island->m_storageIndex] = world->m_activeSimulationIslands.m_data[world->m_activeSimulationIslands.m_size - 1];
    world->m_activeSimulationIslands.m_data[island->m_storageIndex]->m_storageIndex = island->m_storageIndex;
    --world->m_activeSimulationIslands.m_size;
    m_size = world->m_inactiveSimulationIslands.m_size;
    *((_BYTE *)island + 50) &= 0xFCu;
    island->m_storageIndex = m_size - 1;
    island->m_timeOfDeactivation = world->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage;
    if ( island->m_entities.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        v7 = island->m_entities.m_data[v6];
        hkSweptTransformUtil::freezeMotionState(island->m_timeOfDeactivation, &v7->m_motion.m_motionState);
        v7->m_motion.vfptr[9].__vecDelDtor(&v7->m_motion, (unsigned int)&aabbOut);
        ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v7->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v7->m_motion,
          &aabbOut);
        ++v4;
        ++v6;
      }
      while ( v4 < island->m_entities.m_size );
    }
    hkpWorldCallbackUtil::fireIslandDeactivated(world, island);
  }
  else
  {
    *((_BYTE *)island + 50) &= ~8u;
    *((_BYTE *)island + 50) |= 4u;
  }
}

// File Line: 2126
// RVA: 0xD81AA0
void __fastcall hkpWorldOperationUtil::markIslandInactive(hkpWorld *world, hkpSimulationIsland *island)
{
  *((_BYTE *)island + 50) &= 0xF3u;
  EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
  if ( island->m_dirtyListIndex == 0xFFFF )
  {
    island->m_dirtyListIndex = world->m_dirtySimulationIslands.m_size;
    if ( world->m_dirtySimulationIslands.m_size == (world->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&world->m_dirtySimulationIslands.m_data,
        8);
    world->m_dirtySimulationIslands.m_data[world->m_dirtySimulationIslands.m_size++] = island;
  }
  LeaveCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
}

// File Line: 2133
// RVA: 0xD81B30
void __fastcall hkpWorldOperationUtil::markIslandInactiveMt(hkpWorld *world, hkpSimulationIsland *island)
{
  *((_BYTE *)island + 50) &= 0xF3u;
  EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
  if ( island->m_dirtyListIndex == 0xFFFF )
  {
    island->m_dirtyListIndex = world->m_dirtySimulationIslands.m_size;
    if ( world->m_dirtySimulationIslands.m_size == (world->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&world->m_dirtySimulationIslands.m_data,
        8);
    world->m_dirtySimulationIslands.m_data[world->m_dirtySimulationIslands.m_size++] = island;
  }
  LeaveCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
}

// File Line: 2149
// RVA: 0xD81BC0
void __fastcall hkpWorldOperationUtil::markIslandActive(hkpWorld *world, hkpSimulationIsland *island)
{
  char v2; // al

  v2 = *((_BYTE *)island + 50);
  if ( (v2 & 0xC) == 0 && (v2 & 3) != 0 )
    *((_BYTE *)island + 50) = v2 & 0xCF | 0x10;
  *((_BYTE *)island + 50) &= ~8u;
  *((_BYTE *)island + 50) |= 4u;
  EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
  if ( island->m_dirtyListIndex == 0xFFFF )
  {
    island->m_dirtyListIndex = world->m_dirtySimulationIslands.m_size;
    if ( world->m_dirtySimulationIslands.m_size == (world->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&world->m_dirtySimulationIslands.m_data,
        8);
    world->m_dirtySimulationIslands.m_data[world->m_dirtySimulationIslands.m_size++] = island;
  }
  LeaveCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
}

// File Line: 2161
// RVA: 0xD81C70
void __fastcall hkpWorldOperationUtil::removeIslandFromDirtyList(hkpWorld *world, hkpSimulationIsland *island)
{
  unsigned __int16 m_dirtyListIndex; // ax

  m_dirtyListIndex = island->m_dirtyListIndex;
  if ( m_dirtyListIndex != 0xFFFF )
  {
    world->m_dirtySimulationIslands.m_data[m_dirtyListIndex] = 0i64;
    island->m_dirtyListIndex = -1;
  }
}

// File Line: 2175
// RVA: 0xD81080
void __fastcall hkpWorldOperationUtil::replaceMotionObject(
        hkpRigidBody *body,
        hkpMotion::MotionType newState,
        hkBool newStateNeedsInertia,
        hkBool oldStateNeedsInertia,
        hkpWorld *world)
{
  char v5; // bl
  hkpWorld *v6; // rsi
  hkpWorld *v9; // r15
  hkpMaxSizeMotion *m_savedMotion; // rsi
  hkpMaxSizeMotion *v11; // rdx
  int i; // eax
  hkReferencedObject v13; // xmm0
  hkpMaxSizeMotion *p_m_motion; // rdx
  __int64 v15; // r9
  char *v16; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  unsigned __int16 EncodedFloat; // ax
  float maxLinearVelocity; // xmm6_4
  float maxAngularVelocity; // xmm7_4
  unsigned __int16 v21; // ax
  float Mass; // xmm0_4
  hkpMaxSizeMotion *v23; // rcx
  hkpMaxSizeMotion *v24; // r8
  __int64 v25; // r9
  char *v26; // rdx
  hkBaseObjectVtbl *v27; // rax
  hkpMotion *v28; // rax
  hkpMotion *v29; // rbx
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  hkpMotion *v33; // rax
  _QWORD **Value; // rax
  hkpMotion *v35; // rax
  hkpMaxSizeMotion *v36; // rsi
  unsigned __int16 m_memSizeAndFlags; // r8
  int v38; // eax
  hkpMotion *p_inertiaLocal; // rcx
  hkReferencedObject v40; // xmm0
  __int16 v41; // dx
  __int16 v42; // r8
  __int16 v43; // r8
  __m128 v44; // [rsp+148h] [rbp-98h] BYREF
  hkSimdFloat32 time; // [rsp+158h] [rbp-88h] BYREF
  hkpMotion inertiaLocal; // [rsp+168h] [rbp-78h] BYREF
  char v47; // [rsp+328h] [rbp+148h]
  hkpWorld *v48; // [rsp+330h] [rbp+150h]
  float v49; // [rsp+330h] [rbp+150h]
  float CurrentTime; // [rsp+330h] [rbp+150h]

  v47 = v5;
  v48 = v6;
  if ( newStateNeedsInertia.m_bool )
  {
    v9 = v6;
    if ( !oldStateNeedsInertia.m_bool )
    {
      m_savedMotion = body->m_motion.m_savedMotion;
      body->m_motion.hkpEntity::vfptr[14].__vecDelDtor(&body->m_motion, (unsigned int)m_savedMotion);
      *(_DWORD *)m_savedMotion->m_deactivationNumInactiveFrames = 0;
      body->m_collidable.m_broadPhaseHandle.m_objectQualityType = body->m_motion.m_savedQualityTypeIndex;
      v11 = m_savedMotion;
      for ( i = 20; i > 0; --i )
      {
        v13 = v11->hkReferencedObject;
        v11 = (hkpMaxSizeMotion *)((char *)v11 + 16);
        *(hkReferencedObject *)((char *)v11 + (char *)body - (char *)m_savedMotion + 320) = v13;
      }
      hkString::memSet(&body->m_contactListeners, 0, 0);
      hkReferencedObject::removeReference(m_savedMotion);
      hkpEntity::setCachedShapeData(body, v48, body->m_collidable.m_shape);
    }
    if ( (unsigned __int8)body->m_motion.m_type.m_storage != newState && newState != MOTION_DYNAMIC )
    {
      hkpMotion::hkpMotion(&inertiaLocal);
      inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u64[0] = 0i64;
      inertiaLocal.vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
      p_m_motion = &body->m_motion;
      v15 = 10i64;
      v16 = &v44.m128_i8[8];
      do
      {
        vfptr = p_m_motion->vfptr;
        v16 += 32;
        p_m_motion = (hkpMaxSizeMotion *)((char *)p_m_motion + 32);
        *((_QWORD *)v16 - 4) = vfptr;
        *((_QWORD *)v16 - 3) = p_m_motion[-1].m_savedMotion;
        *((_QWORD *)v16 - 2) = *(_QWORD *)&p_m_motion[-1].m_savedQualityTypeIndex;
        *((_QWORD *)v16 - 1) = *(_QWORD *)(&p_m_motion[-1].m_gravityFactor + 3);
        --v15;
      }
      while ( v15 );
      ((void (__fastcall *)(hkpMaxSizeMotion *, hkpMaxSizeMotion **))body->m_motion.hkpEntity::vfptr[3].__first_virtual_table_function__)(
        &body->m_motion,
        &inertiaLocal.m_savedMotion);
      EncodedFloat = hkUFloat8::getEncodedFloat(inertiaLocal.m_motionState.m_deltaAngle.m_quad.m128_i8[3]);
      maxLinearVelocity = 0.0;
      if ( EncodedFloat )
        LODWORD(maxAngularVelocity) = (EncodedFloat + 243712) << 12;
      else
        maxAngularVelocity = 0.0;
      v21 = hkUFloat8::getEncodedFloat(inertiaLocal.m_motionState.m_deltaAngle.m_quad.m128_i8[2]);
      if ( v21 )
        LODWORD(maxLinearVelocity) = (v21 + 243712) << 12;
      Mass = hkpMotion::getMass(&inertiaLocal);
      hkpRigidBody::createDynamicRigidMotion(
        newState,
        (hkVector4f *)&inertiaLocal.m_motionState.m_transform.m_rotation.m_col1.m_quad.m128_u16[4],
        (hkQuaternionf *)&inertiaLocal.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_u16[4],
        Mass,
        (hkMatrix3f *)&inertiaLocal.m_savedMotion,
        (hkVector4f *)&inertiaLocal.m_motionState.m_sweptTransform.m_rotation0.m_vec.m_quad.m128_u16[4],
        maxLinearVelocity,
        maxAngularVelocity,
        (hkpThinBoxMotion *)&body->m_motion);
      hkpMotion::getMotionStateAndVelocitiesAndDeactivationType(&inertiaLocal, &body->m_motion);
      body->m_motion.m_motionState.m_linearDamping.m_value = COERCE_INT(
                                                               COERCE_FLOAT(inertiaLocal.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_i16[6] << 16)
                                                             * 1.0039062) >> 16;
      v49 = COERCE_FLOAT(inertiaLocal.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_i16[7] << 16)
          * 1.0039062;
      body->m_motion.m_motionState.m_angularDamping.m_value = HIWORD(v49);
      hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion((hkpKeyframedRigidMotion *)&inertiaLocal);
    }
  }
  else
  {
    hkpMotion::hkpMotion(&inertiaLocal);
    v23 = &body->m_motion;
    inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u64[0] = 0i64;
    v24 = &body->m_motion;
    v25 = 10i64;
    v26 = &v44.m128_i8[8];
    inertiaLocal.vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
    do
    {
      v27 = v24->vfptr;
      v26 += 32;
      v24 = (hkpMaxSizeMotion *)((char *)v24 + 32);
      *((_QWORD *)v26 - 4) = v27;
      *((_QWORD *)v26 - 3) = v24[-1].m_savedMotion;
      *((_QWORD *)v26 - 2) = *(_QWORD *)&v24[-1].m_savedQualityTypeIndex;
      *((_QWORD *)v26 - 1) = *(_QWORD *)(&v24[-1].m_gravityFactor + 3);
      --v25;
    }
    while ( v25 );
    v9 = v6;
    if ( newState == MOTION_FIXED )
    {
      if ( body == (hkpRigidBody *)-336i64 )
      {
        v29 = 0i64;
      }
      else
      {
        hkpFixedRigidMotion::hkpFixedRigidMotion(
          (hkpFixedRigidMotion *)v23,
          &body->m_motion.m_motionState.m_transform.m_translation,
          &body->m_motion.m_motionState.m_sweptTransform.m_rotation1);
        v29 = v28;
      }
      hkMotionState::operator=(&v29->m_motionState, (hkMotionState *)&inertiaLocal.m_memSizeAndFlags);
      v29->m_deactivationIntegrateCounter = time.m_real.m128_i8[9];
      v30 = _mm_shuffle_ps(
              *(__m128 *)((char *)&inertiaLocal.m_motionState.m_transform.m_translation.m_quad + 8),
              *(__m128 *)((char *)&inertiaLocal.m_motionState.m_transform.m_translation.m_quad + 8),
              255);
      if ( v30.m128_f32[0] != 0.0 )
      {
        v31 = _mm_rcp_ps(v30);
        v32 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v30)), v31),
                _mm_shuffle_ps(
                  *(__m128 *)((char *)&inertiaLocal.m_motionState.m_transform.m_rotation.m_col2.m_quad + 8),
                  *(__m128 *)((char *)&inertiaLocal.m_motionState.m_transform.m_rotation.m_col2.m_quad + 8),
                  255));
        if ( v6 )
        {
          CurrentTime = hkpWorld::getCurrentTime(v6);
          v44 = _mm_shuffle_ps((__m128)LODWORD(CurrentTime), (__m128)LODWORD(CurrentTime), 0);
        }
        else
        {
          v44 = v32;
        }
        time.m_real = v44;
        hkSweptTransformUtil::freezeMotionState(&time, &v29->m_motionState);
      }
    }
    else
    {
      if ( body == (hkpRigidBody *)-336i64 )
      {
        v29 = 0i64;
      }
      else
      {
        hkpKeyframedRigidMotion::hkpKeyframedRigidMotion(
          v23,
          &body->m_motion.m_motionState.m_transform.m_translation,
          &body->m_motion.m_motionState.m_sweptTransform.m_rotation1);
        v29 = v33;
      }
      hkpMotion::getMotionStateAndVelocitiesAndDeactivationType(&inertiaLocal, v29);
    }
    if ( v47 )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v35 = (hkpMotion *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 320i64);
      v36 = (hkpMaxSizeMotion *)v35;
      if ( v35 )
      {
        hkpMotion::hkpMotion(v35);
        v36->m_savedMotion = 0i64;
        v36->vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
      }
      else
      {
        v36 = 0i64;
      }
      m_memSizeAndFlags = v36->m_memSizeAndFlags;
      v38 = 20;
      p_inertiaLocal = &inertiaLocal;
      do
      {
        v40 = p_inertiaLocal->hkReferencedObject;
        --v38;
        p_inertiaLocal = (hkpMotion *)((char *)p_inertiaLocal + 16);
        *(hkReferencedObject *)((char *)p_inertiaLocal + (char *)v36 - (char *)&inertiaLocal - 16) = v40;
      }
      while ( v38 > 0 );
      v36->m_memSizeAndFlags = m_memSizeAndFlags;
      v36->m_referenceCount = 1;
      v29->m_savedMotion = v36;
      v29->m_savedQualityTypeIndex = body->m_collidable.m_broadPhaseHandle.m_objectQualityType;
      hkpEntity::setCachedShapeData(body, v9, body->m_collidable.m_shape);
    }
    else
    {
      v29->vfptr[15].__vecDelDtor(v29, inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u64[0]);
      v29->m_savedQualityTypeIndex = inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u16[4];
    }
    body->m_solverData = 0;
    body->m_collidable.m_broadPhaseHandle.m_objectQualityType = newState != MOTION_FIXED;
    hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion((hkpKeyframedRigidMotion *)&inertiaLocal);
  }
  body->m_collidable.m_motion = &body->m_motion.m_motionState;
  if ( v9 )
  {
    v41 = (unsigned __int8)v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
    v42 = (unsigned __int8)v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
    if ( (unsigned __int8)(v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(body->m_motion.m_deactivationIntegrateCounter & 3) )
      v42 = ~v42;
    v43 = v42 << 14;
    if ( (unsigned __int8)v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < (int)(unsigned __int8)body->m_motion.m_deactivationIntegrateCounter )
      v41 = ~v41;
    body->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
    body->m_motion.m_deactivationNumInactiveFrames[0] |= v43;
    body->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
    body->m_motion.m_deactivationNumInactiveFrames[1] |= v41 << 14;
  }
}

