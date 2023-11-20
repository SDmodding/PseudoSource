// File Line: 86
// RVA: 0xD7DBF0
void __fastcall hkpWorldOperationUtil::updateEntityBP(hkpWorld *world, hkpEntity *entity)
{
  unsigned int *v2; // rbx
  hkpWorld *v3; // rdi
  hkpShape *v4; // rax
  __m128i v5; // xmm4
  __m128i v6; // xmm2
  __m128i v7; // xmm3
  int v8; // esi
  __m128i v9; // xmm4
  unsigned int v10; // eax
  __m128i v11; // xmm3
  __m128i v12; // xmm4
  __m128i v13; // xmm2
  int v14; // xmm0_4
  __m128i v15; // xmm3
  __m128i v16; // xmm3
  LPVOID v17; // rax
  hkLifoAllocator *v18; // rcx
  hkpBroadPhaseHandlePair *v19; // rax
  int v20; // edx
  char *v21; // r8
  int v22; // esi
  hkLifoAllocator *v23; // rax
  hkLifoAllocator *v24; // rcx
  char *v25; // rax
  int v26; // edx
  char *v27; // r8
  hkpBroadPhase *v28; // rcx
  int v29; // edx
  hkpCollisionFilter *v30; // r9
  hkpCollidableCollidableFilter *v31; // r9
  char *v32; // rsi
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // er8
  int v36; // eax
  char *v37; // rsi
  signed int v38; // ebx
  hkLifoAllocator *v39; // rax
  int v40; // er8
  bool v41; // zf
  hkWorldOperation::BaseOperation operation[8]; // [rsp+30h] [rbp-19h]
  int numDeletedPairs[2]; // [rsp+38h] [rbp-11h]
  void *p; // [rsp+40h] [rbp-9h]
  int v45; // [rsp+48h] [rbp-1h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+50h] [rbp+7h]
  void *v47; // [rsp+60h] [rbp+17h]
  int v48; // [rsp+68h] [rbp+1Fh]
  __int64 v49; // [rsp+70h] [rbp+27h]
  int v50; // [rsp+78h] [rbp+2Fh]
  __int64 v51; // [rsp+80h] [rbp+37h]
  int v52; // [rsp+88h] [rbp+3Fh]
  unsigned int *v53; // [rsp+B0h] [rbp+67h]
  hkpEntity *entityBatch; // [rsp+B8h] [rbp+6Fh]

  entityBatch = entity;
  v2 = (unsigned int *)entity;
  v3 = world;
  if ( world->m_criticalOperationsLockCount )
  {
    *(_QWORD *)numDeletedPairs = entity;
    operation[0].m_type.m_storage = 3;
    hkpWorld::queueOperation(world, operation);
  }
  else
  {
    v4 = entity->m_collidable.m_shape;
    world->m_criticalOperationsLockCount = 1;
    if ( v4 )
    {
      if ( entity->m_collidable.m_boundingVolumeData.m_min[0] > entity->m_collidable.m_boundingVolumeData.m_max[0] )
        hkpEntityAabbUtil::entityBatchRecalcAabb(
          (hkpCollisionInput *)&world->m_collisionInput->m_dispatcher,
          &entityBatch,
          1i64);
      v5 = (__m128i)v2[23];
      v6 = _mm_cvtsi32_si128(v2[21]);
      v7 = _mm_cvtsi32_si128(v2[20]);
      v8 = v3->m_broadPhaseQuerySize;
      newPairs.m_data = 0i64;
      newPairs.m_size = 0;
      newPairs.m_capacityAndFlags = 2147483648;
      v9 = _mm_unpacklo_epi16(_mm_unpacklo_epi8(v5, (__m128i)0i64), (__m128i)0i64);
      v48 = v8;
      v10 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v9, 255));
      v11 = _mm_sub_epi32(
              _mm_unpacklo_epi32(
                _mm_unpacklo_epi32(v7, _mm_cvtsi32_si128(v2[22])),
                _mm_unpacklo_epi32(v6, _mm_cvtsi32_si128(0))),
              _mm_slli_epi32(v9, v10));
      v12 = (__m128i)v2[27];
      v13 = _mm_cvtsi32_si128(v2[25]);
      v14 = (unsigned __int128)_mm_shuffle_epi32(v11, 170);
      v49 = v11.m128i_i64[0];
      v15 = _mm_cvtsi32_si128(v2[24]);
      v50 = v14;
      v16 = _mm_add_epi32(
              _mm_unpacklo_epi32(
                _mm_unpacklo_epi32(v15, _mm_cvtsi32_si128(v2[26])),
                _mm_unpacklo_epi32(v13, _mm_cvtsi32_si128(0))),
              _mm_slli_epi32(_mm_unpacklo_epi16(_mm_unpacklo_epi8(v12, (__m128i)0i64), (__m128i)0i64), v10));
      v51 = v16.m128i_i64[0];
      v52 = (unsigned __int128)_mm_shuffle_epi32(v16, 170);
      if ( v8 )
      {
        v17 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v18 = (hkLifoAllocator *)v17;
        v19 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v17 + 3);
        v20 = (16 * v8 + 127) & 0xFFFFFF80;
        v21 = (char *)v19 + v20;
        if ( v20 > v18->m_slabSize || v21 > v18->m_end )
          v19 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
        else
          v18->m_cur = v21;
      }
      else
      {
        v19 = 0i64;
      }
      newPairs.m_data = v19;
      v47 = v19;
      newPairs.m_capacityAndFlags = v8 | 0x80000000;
      v22 = v3->m_broadPhaseQuerySize;
      *(_QWORD *)&operation[0].m_type.m_storage = 0i64;
      numDeletedPairs[0] = 0;
      numDeletedPairs[1] = 2147483648;
      v45 = v22;
      if ( v22 )
      {
        v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v24 = v23;
        v25 = (char *)v23->m_cur;
        v26 = (16 * v22 + 127) & 0xFFFFFF80;
        v27 = &v25[v26];
        if ( v26 > v24->m_slabSize || v27 > v24->m_end )
          v25 = (char *)hkLifoAllocator::allocateFromNewSlab(v24, v26);
        else
          v24->m_cur = v27;
      }
      else
      {
        v25 = 0i64;
      }
      v28 = v3->m_broadPhase;
      *(_QWORD *)&operation[0].m_type.m_storage = v25;
      p = v25;
      numDeletedPairs[1] = v22 | 0x80000000;
      v53 = v2 + 17;
      ((void (__fastcall *)(hkpBroadPhase *, unsigned int **, __int64 *, signed __int64, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkWorldOperation::BaseOperation *))v28->vfptr[6].__vecDelDtor)(
        v28,
        &v53,
        &v49,
        1i64,
        &newPairs,
        operation);
      v29 = numDeletedPairs[0];
      if ( numDeletedPairs[0] + newPairs.m_size > 0 )
      {
        hkpTypedBroadPhaseDispatcher::removeDuplicates(
          &newPairs,
          (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *)operation);
        hkpTypedBroadPhaseDispatcher::removePairs(
          v3->m_broadPhaseDispatcher,
          *(hkpTypedBroadPhaseHandlePair **)&operation[0].m_type.m_storage,
          numDeletedPairs[0]);
        v30 = v3->m_collisionFilter;
        if ( v30 )
          v31 = (hkpCollidableCollidableFilter *)&v30->vfptr;
        else
          v31 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          v3->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v31);
        v29 = numDeletedPairs[0];
      }
      v32 = (char *)p;
      if ( p == *(void **)&operation[0].m_type.m_storage )
        v29 = 0;
      numDeletedPairs[0] = v29;
      v33 = (16 * v45 + 127) & 0xFFFFFF80;
      v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v35 = (v33 + 15) & 0xFFFFFFF0;
      if ( v33 > v34->m_slabSize || &v32[v35] != v34->m_cur || v34->m_firstNonLifoEnd == v32 )
        hkLifoAllocator::slowBlockFree(v34, v32, v35);
      else
        v34->m_cur = v32;
      numDeletedPairs[0] = 0;
      if ( numDeletedPairs[1] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)&operation[0].m_type.m_storage,
          16 * numDeletedPairs[1]);
      v36 = newPairs.m_size;
      v37 = (char *)v47;
      *(_QWORD *)&operation[0].m_type.m_storage = 0i64;
      if ( v47 == newPairs.m_data )
        v36 = 0;
      numDeletedPairs[1] = 2147483648;
      newPairs.m_size = v36;
      v38 = (16 * v48 + 127) & 0xFFFFFF80;
      v39 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v40 = (v38 + 15) & 0xFFFFFFF0;
      if ( v38 > v39->m_slabSize || &v37[v40] != v39->m_cur || v39->m_firstNonLifoEnd == v37 )
        hkLifoAllocator::slowBlockFree(v39, v37, v40);
      else
        v39->m_cur = v37;
      newPairs.m_size = 0;
      if ( newPairs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          newPairs.m_data,
          16 * newPairs.m_capacityAndFlags);
    }
    v41 = v3->m_criticalOperationsLockCount-- == 1;
    if ( v41 && !v3->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v3->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v3);
      if ( v3->m_pendingOperationQueueCount == 1 )
      {
        if ( v3->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v3);
      }
    }
  }
}_executePendingOperations(v3);
      if ( v3->m_pendingOperationQueueCount =

// File Line: 152
// RVA: 0xD7D890
void __fastcall hkpWorldOperationUtil::addEntityBP(hkpWorld *world, hkpEntity *entity)
{
  hkpEntity *v2; // rsi
  hkpWorld *v3; // rdi
  int v4; // ebx
  LPVOID v5; // rax
  hkLifoAllocator *v6; // rcx
  hkpTypedBroadPhaseHandlePair *v7; // rax
  int v8; // edx
  char *v9; // r8
  hkpCollisionInput *v10; // rcx
  hkpBroadPhase *v11; // rcx
  int v12; // eax
  hkpCollisionFilter *v13; // rcx
  hkpCollidableCollidableFilter *v14; // r9
  char *v15; // rdi
  signed int v16; // ebx
  hkLifoAllocator *v17; // rax
  int v18; // er8
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+30h] [rbp-40h]
  int numNewPairs; // [rsp+38h] [rbp-38h]
  int v21; // [rsp+3Ch] [rbp-34h]
  void *p; // [rsp+40h] [rbp-30h]
  int v23; // [rsp+48h] [rbp-28h]
  __int128 v24; // [rsp+50h] [rbp-20h]
  __int128 v25; // [rsp+60h] [rbp-10h]
  hkpEntity *entityBatch; // [rsp+98h] [rbp+28h]

  entityBatch = entity;
  v2 = entity;
  v3 = world;
  if ( entity->m_collidable.m_shape )
  {
    v4 = world->m_broadPhaseQuerySize;
    v21 = 2147483648;
    v23 = v4;
    newPairs = 0i64;
    numNewPairs = 0;
    if ( v4 )
    {
      v5 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkLifoAllocator *)v5;
      v7 = (hkpTypedBroadPhaseHandlePair *)*((_QWORD *)v5 + 3);
      v8 = (16 * v4 + 127) & 0xFFFFFF80;
      v9 = (char *)v7 + v8;
      if ( v8 > v6->m_slabSize || v9 > v6->m_end )
        v7 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
      else
        v6->m_cur = v9;
    }
    else
    {
      v7 = 0i64;
    }
    v10 = (hkpCollisionInput *)&v3->m_collisionInput->m_dispatcher;
    newPairs = v7;
    v21 = v4 | 0x80000000;
    p = v7;
    hkpEntityAabbUtil::entityBatchRecalcAabb(v10, &entityBatch, 1i64);
    v11 = v3->m_broadPhase;
    v24 = *(_OWORD *)entityBatch->m_collidable.m_boundingVolumeData.m_min;
    v25 = *(_OWORD *)entityBatch->m_collidable.m_boundingVolumeData.m_max;
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, __int128 *, hkpTypedBroadPhaseHandlePair **, _BYTE))v11->vfptr[3].__vecDelDtor)(
      v11,
      &v2->m_collidable.m_broadPhaseHandle,
      &v24,
      &newPairs,
      0);
    v12 = numNewPairs;
    if ( numNewPairs > 0 )
    {
      v13 = v3->m_collisionFilter;
      v14 = (hkpCollidableCollidableFilter *)&v13->vfptr;
      if ( !v13 )
        v14 = 0i64;
      hkpTypedBroadPhaseDispatcher::addPairs(v3->m_broadPhaseDispatcher, newPairs, numNewPairs, v14);
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        newPairs,
        16 * v21);
  }
}

// File Line: 178
// RVA: 0xD7DFF0
void __fastcall hkpWorldOperationUtil::addPhantomBP(hkpWorld *world, hkpPhantom *phantom)
{
  int v2; // ebx
  hkpPhantom *v3; // rsi
  hkpWorld *v4; // rdi
  LPVOID v5; // rax
  hkLifoAllocator *v6; // rcx
  hkpTypedBroadPhaseHandlePair *v7; // rax
  int v8; // edx
  char *v9; // r8
  bool v10; // zf
  hkBaseObjectVtbl *v11; // rax
  bool v12; // bl
  int v13; // eax
  hkpCollisionFilter *v14; // rcx
  hkpCollidableCollidableFilter *v15; // r9
  char *v16; // rdi
  signed int v17; // ebx
  hkLifoAllocator *v18; // rax
  int v19; // er8
  hkpTypedBroadPhaseHandlePair *newPairs; // [rsp+30h] [rbp-48h]
  int numNewPairs; // [rsp+38h] [rbp-40h]
  int v22; // [rsp+3Ch] [rbp-3Ch]
  void *p; // [rsp+40h] [rbp-38h]
  int v24; // [rsp+48h] [rbp-30h]
  hkAabb aabb; // [rsp+50h] [rbp-28h]

  v2 = world->m_broadPhaseQuerySize;
  v3 = phantom;
  v4 = world;
  v22 = 2147483648;
  newPairs = 0i64;
  numNewPairs = 0;
  v24 = v2;
  if ( v2 )
  {
    v5 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkLifoAllocator *)v5;
    v7 = (hkpTypedBroadPhaseHandlePair *)*((_QWORD *)v5 + 3);
    v8 = (16 * v2 + 127) & 0xFFFFFF80;
    v9 = (char *)v7 + v8;
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
      v7 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
    else
      v6->m_cur = v9;
  }
  else
  {
    v7 = 0i64;
  }
  v10 = v3->m_collidable.m_broadPhaseHandle.m_type == 3;
  newPairs = v7;
  p = v7;
  v11 = v3->vfptr;
  v22 = v2 | 0x80000000;
  v12 = v10;
  ((void (__fastcall *)(hkpPhantom *, hkAabb *))v11[3].__first_virtual_table_function__)(v3, &aabb);
  ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkAabb *, hkpTypedBroadPhaseHandlePair **, bool))v4->m_broadPhase->vfptr[2].__first_virtual_table_function__)(
    v4->m_broadPhase,
    &v3->m_collidable.m_broadPhaseHandle,
    &aabb,
    &newPairs,
    v12);
  hkpPhantom::setBoundingVolumeData(v3, &aabb);
  v13 = numNewPairs;
  if ( numNewPairs )
  {
    v14 = v4->m_collisionFilter;
    v15 = (hkpCollidableCollidableFilter *)&v14->vfptr;
    if ( !v14 )
      v15 = 0i64;
    hkpTypedBroadPhaseDispatcher::addPairs(v4->m_broadPhaseDispatcher, newPairs, numNewPairs, v15);
    v13 = numNewPairs;
  }
  v16 = (char *)p;
  if ( p == newPairs )
    v13 = 0;
  numNewPairs = v13;
  v17 = (16 * v24 + 127) & 0xFFFFFF80;
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (v17 + 15) & 0xFFFFFFF0;
  if ( v17 > v18->m_slabSize || &v16[v19] != v18->m_cur || v18->m_firstNonLifoEnd == v16 )
    hkLifoAllocator::slowBlockFree(v18, v16, v19);
  else
    v18->m_cur = v16;
  numNewPairs = 0;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newPairs,
      16 * v22);
}

// File Line: 200
// RVA: 0xD81CA0
hkpSimulationIsland *__fastcall findSmallSparseActiveIsland(hkpWorld *world, hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *islands, int islandSizeAddon, hkpSimulationIsland *islandToIgnore)
{
  int v4; // ebx
  int v5; // er11
  int v6; // eax
  __int64 v7; // rcx
  hkpSimulationIsland **v8; // r8
  hkpSimulationIsland *result; // rax
  int v10; // edx

  v4 = world->m_minDesiredIslandSize;
  v5 = islandSizeAddon;
  if ( islandSizeAddon >= v4 )
    return 0i64;
  if ( !world->m_wantSimulationIslands.m_bool )
    return 0i64;
  v6 = islands->m_size - 1;
  v7 = v6;
  if ( v6 < 0 )
    return 0i64;
  v8 = &islands->m_data[v6];
  while ( 1 )
  {
    result = *v8;
    if ( islandToIgnore != *v8 )
    {
      v10 = result->m_numConstraints;
      if ( *((_BYTE *)result + 50) & 0xC )
      {
        if ( result->m_entities.m_size > v10 )
          v10 = result->m_entities.m_size;
        if ( v5 + v10 < v4 )
          break;
      }
    }
    --v8;
    if ( --v7 < 0 )
      return 0i64;
  }
  *((_BYTE *)result + 49) &= 0xF7u;
  *((_BYTE *)result + 49) |= 4u;
  return result;
}

// File Line: 231
// RVA: 0xD7E310
void __fastcall hkpWorldOperationUtil::addEntitySI(hkpWorld *world, hkpEntity *entity, hkpEntityActivation initialActivationState)
{
  bool v3; // zf
  hkpEntity *v4; // rsi
  hkpWorld *v5; // rbx
  bool v6; // bp
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v7; // rdi
  hkpSimulationIsland *v8; // rax
  _QWORD **v9; // rax
  hkpSimulationIsland *v10; // rax
  hkpSimulationIsland *v11; // rax
  hkpSimulationIsland *v12; // rbx
  __int16 v13; // ax

  v3 = entity->m_motion.m_type.m_storage == 5;
  v4 = entity;
  v5 = world;
  entity->m_world = world;
  if ( v3 )
  {
    hkpSimulationIsland::internalAddEntity(world->m_fixedIsland, entity);
    return;
  }
  if ( world->m_wantSimulationIslands.m_bool )
  {
    v6 = initialActivationState == 1;
    if ( initialActivationState == 1 )
    {
      v7 = &world->m_activeSimulationIslands;
      v8 = findSmallSparseActiveIsland(world, &world->m_activeSimulationIslands, 4, 0i64);
      if ( v8 )
      {
        hkpSimulationIsland::internalAddEntity(v8, v4);
        return;
      }
    }
    else
    {
      v7 = &world->m_inactiveSimulationIslands;
    }
    v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 184i64);
    if ( v10 )
    {
      hkpSimulationIsland::hkpSimulationIsland(v10, v5);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    *((_BYTE *)v12 + 50) &= 0xF3u;
    *((_BYTE *)v12 + 50) = v6 & 3 | (*((_BYTE *)v12 + 50) | 4 * (v6 & 3)) & 0xFC;
    v13 = v7->m_size;
    v12->m_storageIndex = v13;
    v12->m_splitCheckFrameCounter = v13;
    if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 8);
    v7->m_data[v7->m_size++] = v12;
  }
  else
  {
    v12 = *world->m_activeSimulationIslands.m_data;
  }
  hkpSimulationIsland::internalAddEntity(v12, v4);
  v12->m_splitCheckFrameCounter = v4->m_uid;
}

// File Line: 289
// RVA: 0xD7DA50
void __fastcall hkpWorldOperationUtil::removeEntityBP(hkpWorld *world, hkpEntity *entity)
{
  hkpEntity *v2; // rsi
  hkpWorld *v3; // rbx
  int v4; // edi
  LPVOID v5; // rax
  hkLifoAllocator *v6; // rcx
  hkpTypedBroadPhaseHandlePair *v7; // rax
  int v8; // edx
  char *v9; // r8
  hkpBroadPhase *v10; // rcx
  int v11; // eax
  char *v12; // rdi
  signed int v13; // ebx
  hkLifoAllocator *v14; // rax
  int v15; // er8
  hkpTypedBroadPhaseHandlePair *deletedPairs; // [rsp+30h] [rbp-28h]
  int numDeletedPairs; // [rsp+38h] [rbp-20h]
  int v18; // [rsp+3Ch] [rbp-1Ch]
  void *p; // [rsp+40h] [rbp-18h]
  int v20; // [rsp+48h] [rbp-10h]
  hkpEntity *v21; // [rsp+68h] [rbp+10h]

  v21 = entity;
  v2 = entity;
  v3 = world;
  if ( entity->m_collidable.m_shape )
  {
    ((void (__fastcall *)(hkpSimulation *, hkpEntity **, signed __int64, hkpWorld *, signed int))world->m_simulation->vfptr[6].__vecDelDtor)(
      world->m_simulation,
      &v21,
      1i64,
      world,
      1);
    v4 = v3->m_broadPhaseQuerySize;
    v18 = 2147483648;
    deletedPairs = 0i64;
    numDeletedPairs = 0;
    v20 = v4;
    if ( v4 )
    {
      v5 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkLifoAllocator *)v5;
      v7 = (hkpTypedBroadPhaseHandlePair *)*((_QWORD *)v5 + 3);
      v8 = (16 * v4 + 127) & 0xFFFFFF80;
      v9 = (char *)v7 + v8;
      if ( v8 > v6->m_slabSize || v9 > v6->m_end )
        v7 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
      else
        v6->m_cur = v9;
    }
    else
    {
      v7 = 0i64;
    }
    v10 = v3->m_broadPhase;
    deletedPairs = v7;
    p = v7;
    v18 = v4 | 0x80000000;
    ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkpTypedBroadPhaseHandlePair **))v10->vfptr[4].__vecDelDtor)(
      v10,
      &v2->m_collidable.m_broadPhaseHandle,
      &deletedPairs);
    v11 = numDeletedPairs;
    if ( numDeletedPairs > 0 )
    {
      hkpTypedBroadPhaseDispatcher::removePairs(v3->m_broadPhaseDispatcher, deletedPairs, numDeletedPairs);
      v11 = numDeletedPairs;
    }
    v12 = (char *)p;
    if ( p == deletedPairs )
      v11 = 0;
    numDeletedPairs = v11;
    v13 = (16 * v20 + 127) & 0xFFFFFF80;
    v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v15 = (v13 + 15) & 0xFFFFFFF0;
    if ( v13 > v14->m_slabSize || &v12[v15] != v14->m_cur || v14->m_firstNonLifoEnd == v12 )
      hkLifoAllocator::slowBlockFree(v14, v12, v15);
    else
      v14->m_cur = v12;
    numDeletedPairs = 0;
    if ( v18 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        deletedPairs,
        16 * v18);
  }
}

// File Line: 310
// RVA: 0xD7E1A0
void __fastcall hkpWorldOperationUtil::removePhantomBP(hkpWorld *world, hkpPhantom *phantom)
{
  int v2; // ebx
  hkpPhantom *v3; // rsi
  hkpWorld *v4; // rdi
  LPVOID v5; // rax
  hkLifoAllocator *v6; // rcx
  hkpTypedBroadPhaseHandlePair *v7; // rax
  int v8; // edx
  char *v9; // r8
  hkpBroadPhase *v10; // rcx
  int v11; // eax
  char *v12; // rdi
  signed int v13; // ebx
  hkLifoAllocator *v14; // rax
  int v15; // er8
  hkpTypedBroadPhaseHandlePair *deletedPairs; // [rsp+20h] [rbp-28h]
  int numDeletedPairs; // [rsp+28h] [rbp-20h]
  int v18; // [rsp+2Ch] [rbp-1Ch]
  void *p; // [rsp+30h] [rbp-18h]
  int v20; // [rsp+38h] [rbp-10h]

  v2 = world->m_broadPhaseQuerySize;
  v3 = phantom;
  v4 = world;
  v18 = 2147483648;
  deletedPairs = 0i64;
  numDeletedPairs = 0;
  v20 = v2;
  if ( v2 )
  {
    v5 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkLifoAllocator *)v5;
    v7 = (hkpTypedBroadPhaseHandlePair *)*((_QWORD *)v5 + 3);
    v8 = (16 * v2 + 127) & 0xFFFFFF80;
    v9 = (char *)v7 + v8;
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
      v7 = (hkpTypedBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
    else
      v6->m_cur = v9;
  }
  else
  {
    v7 = 0i64;
  }
  v10 = v4->m_broadPhase;
  deletedPairs = v7;
  p = v7;
  v18 = v2 | 0x80000000;
  ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle *, hkpTypedBroadPhaseHandlePair **))v10->vfptr[4].__vecDelDtor)(
    v10,
    &v3->m_collidable.m_broadPhaseHandle,
    &deletedPairs);
  v11 = numDeletedPairs;
  if ( numDeletedPairs )
  {
    hkpTypedBroadPhaseDispatcher::removePairs(v4->m_broadPhaseDispatcher, deletedPairs, numDeletedPairs);
    v11 = numDeletedPairs;
  }
  v12 = (char *)p;
  if ( p == deletedPairs )
    v11 = 0;
  numDeletedPairs = v11;
  v13 = (16 * v20 + 127) & 0xFFFFFF80;
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v14->m_slabSize || &v12[v15] != v14->m_cur || v14->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v14, v12, v15);
  else
    v14->m_cur = v12;
  numDeletedPairs = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      deletedPairs,
      16 * v18);
}

// File Line: 328
// RVA: 0xD7E450
void __fastcall hkpWorldOperationUtil::removeEntitySI(hkpWorld *world, hkpEntity *entity)
{
  hkpSimulationIsland *v2; // rbx
  hkpWorld *v3; // rdi

  v2 = entity->m_simulationIsland;
  v3 = world;
  entity->m_world = 0i64;
  hkpSimulationIsland::internalRemoveEntity(v2, entity);
  if ( v2->m_storageIndex != -1 && !v2->m_entities.m_size )
  {
    if ( v3->m_wantSimulationIslands.m_bool )
    {
      hkpWorldOperationUtil::removeIsland(v3, v2);
      v2->vfptr->__vecDelDtor((hkBaseObject *)&v2->vfptr, 1u);
    }
  }
}

// File Line: 362
// RVA: 0xD805F0
void __fastcall hkpWorldOperationUtil::removeAttachedActionsFromFixedIsland(hkpWorld *world, hkpEntity *entity, hkArray<hkpAction *,hkContainerHeapAllocator> *actionsToBeMoved)
{
  signed int v3; // ebp
  hkArray<hkpAction *,hkContainerHeapAllocator> *v4; // rsi
  hkpEntity *v5; // r13
  hkpWorld *v6; // rdi
  __int64 v7; // r14
  hkpAction *v8; // rbx
  hkpSimulationIsland *v9; // r15

  v3 = 0;
  v4 = actionsToBeMoved;
  v5 = entity;
  v6 = world;
  if ( entity->m_actions.m_size > 0u )
  {
    v7 = 0i64;
    do
    {
      v8 = v5->m_actions.m_data[v7];
      if ( v8->m_island == v6->m_fixedIsland )
      {
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
        v4->m_data[v4->m_size++] = v8;
        hkReferencedObject::addReference((hkReferencedObject *)&v8->vfptr);
        hkpSimulationIsland::removeAction(v6->m_fixedIsland, v8);
        *((_BYTE *)v6->m_fixedIsland + 49) = *((_BYTE *)v6->m_fixedIsland + 49) & 0xDF | 0x10;
        v9 = v6->m_fixedIsland;
        EnterCriticalSection(&v6->m_islandDirtyListCriticalSection->m_section);
        if ( v9->m_dirtyListIndex == -1 )
        {
          v9->m_dirtyListIndex = v6->m_dirtySimulationIslands.m_size;
          if ( v6->m_dirtySimulationIslands.m_size == (v6->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v6->m_dirtySimulationIslands,
              8);
          v6->m_dirtySimulationIslands.m_data[v6->m_dirtySimulationIslands.m_size++] = v9;
        }
        LeaveCriticalSection(&v6->m_islandDirtyListCriticalSection->m_section);
      }
      ++v3;
      ++v7;
    }
    while ( v3 < v5->m_actions.m_size );
  }
}

// File Line: 394
// RVA: 0xD80740
void __fastcall hkpWorldOperationUtil::removeAttachedActionsFromDynamicIsland(hkpWorld *world, hkpEntity *entity, hkArray<hkpAction *,hkContainerHeapAllocator> *actionsToBeMoved)
{
  hkpSimulationIsland *v3; // rbp
  hkArray<hkpAction *,hkContainerHeapAllocator> *v4; // rsi
  hkpEntity *v5; // rdi
  hkpWorld *v6; // r15
  signed int v7; // er14
  __int64 v8; // r12
  hkpAction *v9; // rbx
  int v10; // edx
  char *v11; // r9
  __int64 v12; // rax
  char *v13; // [rsp+20h] [rbp-B8h]
  int v14; // [rsp+28h] [rbp-B0h]
  int v15; // [rsp+2Ch] [rbp-ACh]
  char v16; // [rsp+30h] [rbp-A8h]

  v3 = entity->m_simulationIsland;
  v4 = actionsToBeMoved;
  v5 = entity;
  v6 = world;
  v7 = 0;
  if ( entity->m_actions.m_size > 0u )
  {
    v8 = 0i64;
    do
    {
      v9 = v5->m_actions.m_data[v8];
      v14 = 0;
      v13 = &v16;
      v15 = -2147483632;
      v9->vfptr[2].__vecDelDtor((hkBaseObject *)&v9->vfptr, (unsigned int)&v13);
      v10 = 0;
      if ( v14 <= 0 )
      {
LABEL_8:
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
        v4->m_data[v4->m_size++] = v9;
        hkReferencedObject::addReference((hkReferencedObject *)&v9->vfptr);
        hkpSimulationIsland::removeAction(v3, v9);
        *((_BYTE *)v3 + 49) &= 0xDFu;
        *((_BYTE *)v3 + 49) |= 0x10u;
        EnterCriticalSection(&v6->m_islandDirtyListCriticalSection->m_section);
        if ( v3->m_dirtyListIndex == -1 )
        {
          v3->m_dirtyListIndex = v6->m_dirtySimulationIslands.m_size;
          if ( v6->m_dirtySimulationIslands.m_size == (v6->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v6->m_dirtySimulationIslands,
              8);
          v6->m_dirtySimulationIslands.m_data[v6->m_dirtySimulationIslands.m_size++] = v3;
        }
        LeaveCriticalSection(&v6->m_islandDirtyListCriticalSection->m_section);
        v11 = v13;
      }
      else
      {
        v11 = v13;
        v12 = (__int64)v13;
        while ( *(_BYTE *)(*(_QWORD *)v12 + 352i64) == 5 || *(hkpEntity **)v12 == v5 )
        {
          ++v10;
          v12 += 8i64;
          if ( v10 >= v14 )
            goto LABEL_8;
        }
      }
      v14 = 0;
      if ( v15 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v11,
          8 * v15);
      ++v7;
      ++v8;
    }
    while ( v7 < v5->m_actions.m_size );
  }
}

// File Line: 449
// RVA: 0xD80930
void __fastcall hkpWorldOperationUtil::addActionsToEntitysIsland(hkpWorld *world, hkpEntity *entity, hkArray<hkpAction *,hkContainerHeapAllocator> *actionsToBeMoved)
{
  hkpSimulationIsland *v3; // r12
  hkArray<hkpAction *,hkContainerHeapAllocator> *v4; // r15
  int v5; // ebp
  signed int v6; // er8
  hkpEntity *v7; // rbx
  hkpWorld *v8; // r13
  __int64 v9; // r14
  hkpSimulationIsland *v10; // rcx
  hkReferencedObject *v11; // rdi
  hkpAction *v12; // rdx
  int v13; // edx
  int v14; // esi
  __int64 v15; // rdi
  hkpEntity *v16; // rcx
  char *v17; // [rsp+20h] [rbp-B8h]
  int v18; // [rsp+28h] [rbp-B0h]
  int v19; // [rsp+2Ch] [rbp-ACh]
  char v20; // [rsp+30h] [rbp-A8h]

  v3 = entity->m_simulationIsland;
  v4 = actionsToBeMoved;
  v5 = 0;
  v6 = -2147483632;
  v7 = entity;
  v8 = world;
  v17 = &v20;
  v18 = 0;
  v19 = -2147483632;
  if ( v4->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = v8->m_fixedIsland;
      v11 = (hkReferencedObject *)&v4->m_data[v9]->vfptr;
      v12 = v4->m_data[v9];
      if ( v3 == v10 )
      {
        hkpSimulationIsland::addAction(v10, v12);
        hkReferencedObject::removeReference(v11);
      }
      else
      {
        hkpSimulationIsland::addAction(v3, v12);
        hkReferencedObject::removeReference(v11);
        v18 = 0;
        v11->vfptr[2].__vecDelDtor((hkBaseObject *)&v11->vfptr, (unsigned int)&v17);
        v13 = v18;
        v14 = 0;
        if ( v18 > 0 )
        {
          v15 = 0i64;
          do
          {
            v16 = *(hkpEntity **)&v17[v15];
            if ( v16 != v7
              && v16->m_motion.m_type.m_storage != 5
              && v7->m_motion.m_type.m_storage != 5
              && v16->m_simulationIsland != v7->m_simulationIsland )
            {
              hkpWorldOperationUtil::mergeIslands(v16->m_world, *(hkpEntity **)&v17[v15], v7);
              v13 = v18;
            }
            ++v14;
            v15 += 8i64;
          }
          while ( v14 < v13 );
        }
      }
      ++v5;
      ++v9;
    }
    while ( v5 < v4->m_size );
    v6 = v19;
  }
  v18 = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v17,
      8 * v6);
}

// File Line: 499
// RVA: 0xD7EF50
void __fastcall hkpWorldOperationUtil::removeIsland(hkpWorld *world, hkpSimulationIsland *island)
{
  if ( *((_BYTE *)island + 50) & 3 )
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
void __fastcall hkpWorldOperationUtil::addConstraintToCriticalLockedIsland(hkpWorld *world, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // rbx
  hkpWorld *v3; // rdi

  v2 = constraint;
  v3 = world;
  hkpWorldConstraintUtil::addConstraint(world, constraint);
  if ( v3->m_constraintListeners.m_size )
    hkpWorldCallbackUtil::fireConstraintAdded(v3, v2);
  if ( v2->m_listeners.m_size )
    hkpConstraintCallbackUtil::fireConstraintAdded(v2);
}

// File Line: 550
// RVA: 0xD7E510
void __fastcall hkpWorldOperationUtil::removeConstraintFromCriticalLockedIsland(hkpWorld *world, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // rbx

  v2 = constraint;
  if ( world->m_constraintListeners.m_size )
    hkpWorldCallbackUtil::fireConstraintRemoved(world, constraint);
  if ( v2->m_listeners.m_size )
    hkpConstraintCallbackUtil::fireConstraintRemoved(v2);
  hkpWorldConstraintUtil::removeConstraint(v2);
}

// File Line: 577
// RVA: 0xD7E550
hkpConstraintInstance *__fastcall hkpWorldOperationUtil::addConstraintImmediately(hkpWorld *world, hkpConstraintInstance *constraint, hkpWorldOperationUtil::FireCallbacks fireCallbacks)
{
  hkpWorldOperationUtil::FireCallbacks v3; // ebx
  hkpConstraintInstance *v4; // rsi
  hkpWorld *v5; // rdi
  bool v6; // zf

  ++world->m_criticalOperationsLockCount;
  v3 = fireCallbacks;
  v4 = constraint;
  v5 = world;
  hkpWorldConstraintUtil::addConstraint(world, constraint);
  if ( v3 )
  {
    if ( v5->m_constraintListeners.m_size )
      hkpWorldCallbackUtil::fireConstraintAdded(v5, v4);
    if ( v4->m_listeners.m_size )
      hkpConstraintCallbackUtil::fireConstraintAdded(v4);
  }
  v6 = v5->m_criticalOperationsLockCount-- == 1;
  if ( v6 && !v5->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v5->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v5);
    if ( v5->m_pendingOperationQueueCount == 1 && v5->m_pendingBodyOperationsCount )
      hkpWorld::internal_executePendingBodyOperations(v5);
  }
  return v4;
}

// File Line: 629
// RVA: 0xD7E5F0
void __fastcall hkpWorldOperationUtil::removeConstraintImmediately(hkpWorld *world, hkpConstraintInstance *constraint, hkpWorldOperationUtil::FireCallbacks fireCallbacks)
{
  hkpConstraintOwner *v3; // rax
  hkpConstraintInstance *v4; // rdi
  hkpWorld *v5; // rbx
  bool v6; // zf

  v3 = constraint->m_owner;
  v4 = constraint;
  v5 = world;
  BYTE1(v3[1].m_constraintInfo.m_maxSizeOfSchema) &= 0xFDu;
  BYTE1(v3[1].m_constraintInfo.m_maxSizeOfSchema) |= 1u;
  if ( world->m_criticalOperationsLockCount )
  {
    if ( fireCallbacks )
    {
      if ( world->m_constraintListeners.m_size )
        hkpWorldCallbackUtil::fireConstraintRemoved(world, constraint);
      if ( v4->m_listeners.m_size )
        hkpConstraintCallbackUtil::fireConstraintRemoved(v4);
    }
    hkpWorldConstraintUtil::removeConstraint(v4);
  }
  else
  {
    world->m_criticalOperationsLockCount = 1;
    if ( fireCallbacks && world->m_constraintListeners.m_size )
      hkpWorldCallbackUtil::fireConstraintRemoved(world, constraint);
    hkpWorldConstraintUtil::removeConstraint(v4);
    v6 = v5->m_criticalOperationsLockCount-- == 1;
    if ( v6 && !v5->m_blockExecutingPendingOperations.m_bool )
    {
      if ( v5->m_pendingOperationsCount )
        hkpWorld::internal_executePendingOperations(v5);
      if ( v5->m_pendingOperationQueueCount == 1 && v5->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v5);
    }
  }
}

// File Line: 679
// RVA: 0xD81D20
void __fastcall findInactiveGroups(hkUnionFind *checker, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, hkpWorld *world, __int64 numGroups, hkFixedArray<int> *isActive)
{
  int v5; // er11
  hkpWorld *v6; // rsi
  __int64 i; // r10
  __int64 v8; // r9
  __int64 v9; // r10
  hkpEntity *v10; // r8
  int v11; // eax
  int v12; // er8
  char v13; // al
  int v14; // eax
  int v15; // er8

  v5 = 0;
  numGroups = (signed int)numGroups;
  v6 = world;
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
      if ( (unsigned __int8)v6->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v11 >> 14 )
        v11 >>= 7;
      v12 = v10->m_motion.m_deactivationNumInactiveFrames[0];
      v13 = v11 & 0x7F;
      if ( (unsigned __int8)v6->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v12 >> 14 )
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
void __fastcall identifyDeactivatedSubgroups(hkUnionFind *checker, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, hkpWorld *world, hkArray<int,hkContainerHeapAllocator> *groupsSizes, hkFixedArray<signed char> *groupSparse)
{
  __int64 v5; // r15
  hkUnionFind *v6; // r12
  hkArray<int,hkContainerHeapAllocator> *v7; // r13
  hkpWorld *v8; // rbp
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v9; // r14
  hkLifoAllocator *v10; // rax
  hkLifoAllocator *v11; // rcx
  int *v12; // rax
  int v13; // edx
  char *v14; // r10
  __int64 v15; // rsi
  __int64 v16; // r11
  __int64 v17; // rcx
  int v18; // ebx
  signed int v19; // er10
  __int64 v20; // rdi
  __int64 v21; // r9
  int v22; // er8
  int v23; // er9
  char v24; // r8
  int v25; // er8
  int v26; // er9
  signed __int64 v27; // r8
  signed __int64 v28; // rbx
  int *v29; // rdi
  signed int v30; // ebx
  hkLifoAllocator *v31; // rax
  int v32; // er8
  hkFixedArray<int> rindex; // [rsp+20h] [rbp-38h]

  v5 = groupsSizes->m_size;
  v6 = checker;
  v7 = groupsSizes;
  v8 = world;
  v9 = entities;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = v10;
  v12 = (int *)v10->m_cur;
  v13 = (4 * v5 + 127) & 0xFFFFFF80;
  v14 = (char *)v12 + v13;
  if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    v12 = (int *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
  else
    v11->m_cur = v14;
  v15 = 0i64;
  rindex.m_data.m_storage = v12;
  rindex.m_size.m_storage = v5;
  v16 = v5;
  v17 = 0i64;
  if ( (signed int)v5 > 0 )
  {
    do
    {
      v12[v17] = 0;
      v12 = rindex.m_data.m_storage;
      ++v17;
    }
    while ( v17 < v5 );
  }
  v18 = 0;
  v19 = 1;
  if ( v9->m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      v21 = *(__int64 *)((char *)v9->m_data + v15);
      v22 = *(unsigned __int16 *)(v21 + 356);
      if ( (unsigned __int8)v8->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v22 >> 14 )
        v22 >>= 7;
      v23 = *(unsigned __int16 *)(v21 + 354);
      v24 = v22 & 0x7F;
      if ( (unsigned __int8)v8->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v23 >> 14 )
        v23 >>= 7;
      v25 = v24 & 0x7F;
      v26 = v23 & 0x7F;
      if ( v26 > v25 )
        v25 = v26;
      if ( v25 <= 5 )
      {
        v12[v6->m_parents->m_data.m_storage[v20]] = 1;
        v12 = rindex.m_data.m_storage;
      }
      ++v18;
      v15 += 8i64;
      ++v20;
    }
    while ( v18 < v9->m_size );
    LODWORD(v15) = 0;
  }
  v27 = 1i64;
  *groupSparse->m_data.m_storage = 1;
  if ( (signed int)v5 > 0 )
  {
    v28 = -(signed __int64)v12;
    do
    {
      if ( *(int *)((char *)v12 + v28 + (unsigned __int64)rindex.m_data.m_storage) )
      {
        *v12 = v15;
      }
      else
      {
        *v12 = v19++;
        groupSparse->m_data.m_storage[v27++] = 0;
      }
      ++v12;
      --v16;
    }
    while ( v16 );
  }
  if ( v19 <= (signed int)v5 )
    hkUnionFind::reindex(v6, &rindex, (unsigned int)v19, v7);
  else
    *groupSparse->m_data.m_storage = 0;
  v29 = rindex.m_data.m_storage;
  v30 = (4 * rindex.m_size.m_storage + 127) & 0xFFFFFF80;
  v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (v30 + 15) & 0xFFFFFFF0;
  if ( v30 > v31->m_slabSize || (char *)v29 + v32 != v31->m_cur || v31->m_firstNonLifoEnd == v29 )
    hkLifoAllocator::slowBlockFree(v31, v29, v32);
  else
    v31->m_cur = v29;
}

// File Line: 750
// RVA: 0xD82030
void __fastcall findInactiveGroupsAndEstimateSolverSize(hkUnionFind *checker, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, int numGroups, hkFixedArray<int> *isActive, hkFixedArray<int> *sizes, char *deactivationNumInactiveFramesSelectFlag)
{
  int v6; // er10
  hkFixedArray<int> *v7; // r14
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v8; // rsi
  __int64 v9; // rbx
  __int64 v10; // rdi
  unsigned __int16 *v11; // r9
  int v12; // eax
  __int64 v13; // r11
  int v14; // er8
  char v15; // al
  int v16; // eax
  int v17; // er8
  signed int v18; // edx

  v6 = 0;
  v7 = isActive;
  v8 = entities;
  if ( entities->m_size > 0 )
  {
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      v11 = (unsigned __int16 *)v8->m_data[v10];
      v12 = v11[178];
      v13 = checker->m_parents->m_data.m_storage[v9];
      if ( (unsigned __int8)deactivationNumInactiveFramesSelectFlag[1] == v12 >> 14 )
        v12 >>= 7;
      v14 = v11[177];
      v15 = v12 & 0x7F;
      if ( (unsigned __int8)*deactivationNumInactiveFramesSelectFlag == v14 >> 14 )
        v14 >>= 7;
      v16 = v15 & 0x7F;
      v17 = v14 & 0x7F;
      if ( v17 > v16 )
        v16 = v17;
      if ( v16 <= 5 )
        v7->m_data.m_storage[v13] = 1;
      v18 = v11[128];
      if ( v18 < 1 )
        v18 = 1;
      ++v6;
      ++v10;
      sizes->m_data.m_storage[v13] += v18;
      ++v9;
    }
    while ( v6 < v8->m_size );
  }
}

// File Line: 773
// RVA: 0xD82140
void __fastcall estimateSolverSize(hkUnionFind *checker, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, int numGroups, hkFixedArray<int> *isActive, hkFixedArray<int> *sizes)
{
  int v5; // er8
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v6; // rbx
  hkUnionFind *v7; // rsi
  __int64 v8; // r10
  __int64 v9; // r11
  hkpEntity *v10; // rdx
  __int64 v11; // rcx
  signed int v12; // edx

  v5 = 0;
  v6 = entities;
  v7 = checker;
  if ( entities->m_size > 0 )
  {
    v8 = 0i64;
    v9 = 0i64;
    do
    {
      ++v9;
      ++v8;
      v10 = v6->m_data[v9 - 1];
      v11 = v7->m_parents->m_data.m_storage[v8 - 1];
      isActive->m_data.m_storage[v11] = 1;
      v12 = v10->m_constraintsMaster.m_size;
      if ( v12 < 1 )
        v12 = 1;
      ++v5;
      sizes->m_data.m_storage[v11] += v12;
    }
    while ( v5 < v6->m_size );
  }
}

// File Line: 791
// RVA: 0xD821D0
void __fastcall mergeSmallSubgroups(hkpWorld *world, hkUnionFind *checker, hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, hkArray<int,hkContainerHeapAllocator> *groupsSizes, hkFixedArray<signed char> *groupSparse)
{
  signed __int64 v5; // rbx
  hkpWorld *v6; // r13
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v7; // rdi
  hkLifoAllocator *v8; // rax
  _DWORD *v9; // r15
  int v10; // esi
  char *v11; // r9
  hkLifoAllocator *v12; // rax
  int *v13; // rdx
  char *v14; // rcx
  unsigned int v15; // ebp
  signed __int64 v16; // r14
  signed __int64 v17; // rcx
  signed __int64 v18; // r12
  int v19; // esi
  __int64 v20; // r11
  __int64 v21; // rbx
  unsigned __int16 *v22; // r9
  int v23; // edx
  __int64 v24; // r10
  int v25; // er8
  char v26; // dl
  int v27; // edx
  int v28; // er8
  signed int v29; // ecx
  int v30; // er8
  __int64 v31; // r9
  __int64 v32; // r10
  hkpEntity *v33; // rdx
  __int64 v34; // rcx
  signed int v35; // eax
  signed __int64 i; // rcx
  int *v37; // r9
  signed __int64 v38; // rax
  signed __int64 v39; // rcx
  int *v40; // r8
  int *v41; // rsi
  int v42; // edx
  signed __int64 v43; // rdi
  int v44; // ebx
  signed __int64 v45; // r10
  int *v46; // rcx
  signed __int64 v47; // r11
  int v48; // er9
  int v49; // eax
  int *v50; // rdi
  signed int v51; // ebx
  hkLifoAllocator *v52; // rax
  int v53; // er8
  hkLifoAllocator *v54; // rax
  int v55; // er8
  int v56; // [rsp+20h] [rbp-78h]
  signed __int64 v57; // [rsp+28h] [rbp-70h]
  signed __int64 v58; // [rsp+28h] [rbp-70h]
  _DWORD *v59; // [rsp+30h] [rbp-68h]
  int *v60; // [rsp+38h] [rbp-60h]
  signed __int64 v61; // [rsp+40h] [rbp-58h]
  int *v62; // [rsp+48h] [rbp-50h]
  hkFixedArray<int> rindex; // [rsp+50h] [rbp-48h]
  hkpWorld *v64; // [rsp+A0h] [rbp+8h]
  hkUnionFind *v65; // [rsp+A8h] [rbp+10h]
  hkArray<int,hkContainerHeapAllocator> *elementsPerGroup; // [rsp+B8h] [rbp+20h]

  elementsPerGroup = groupsSizes;
  v65 = checker;
  v64 = world;
  v5 = groupsSizes->m_size;
  v6 = world;
  v7 = entities;
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = v8->m_cur;
  v10 = (4 * v5 + 127) & 0xFFFFFF80;
  v56 = (4 * v5 + 127) & 0xFFFFFF80;
  v59 = v9;
  v11 = (char *)v9 + v10;
  if ( v10 > v8->m_slabSize || v11 > v8->m_end )
  {
    v9 = hkLifoAllocator::allocateFromNewSlab(v8, v10);
    v59 = v9;
  }
  else
  {
    v8->m_cur = v11;
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
  rindex.m_size.m_storage = v5;
  v16 = v5;
  v57 = v5;
  v17 = 0i64;
  if ( (signed int)v5 > 0 )
  {
    do
    {
      rindex.m_data.m_storage[++v17 - 1] = 0;
      v9[v17 - 1] = 0;
    }
    while ( v17 < v5 );
  }
  v18 = 1i64;
  if ( v6->m_wantDeactivation.m_bool )
  {
    v19 = 0;
    if ( v7->m_size > 0 )
    {
      v20 = 0i64;
      v21 = 0i64;
      do
      {
        v22 = (unsigned __int16 *)v7->m_data[v21];
        v23 = v22[178];
        v24 = v65->m_parents->m_data.m_storage[v20];
        if ( (unsigned __int8)v6->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v23 >> 14 )
          v23 >>= 7;
        v25 = v22[177];
        v26 = v23 & 0x7F;
        if ( (unsigned __int8)v6->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0] == v25 >> 14 )
          v25 >>= 7;
        v27 = v26 & 0x7F;
        v28 = v25 & 0x7F;
        if ( v28 > v27 )
          v27 = v28;
        if ( v27 <= 5 )
          rindex.m_data.m_storage[v24] = 1;
        v29 = v22[128];
        if ( v29 < 1 )
          v29 = 1;
        ++v19;
        ++v21;
        v9[v24] += v29;
        ++v20;
      }
      while ( v19 < v7->m_size );
      v16 = v57;
    }
  }
  else
  {
    v30 = 0;
    if ( v7->m_size > 0 )
    {
      v31 = 0i64;
      v32 = 0i64;
      do
      {
        ++v32;
        ++v31;
        v33 = v7->m_data[v32 - 1];
        v34 = v65->m_parents->m_data.m_storage[v31 - 1];
        rindex.m_data.m_storage[v34] = 1;
        v35 = v33->m_constraintsMaster.m_size;
        if ( v35 < 1 )
          v35 = 1;
        ++v30;
        v9[v34] += v35;
      }
      while ( v30 < v7->m_size );
      v16 = v5;
    }
  }
  for ( i = 0i64; i < v16; ++i )
  {
    if ( !rindex.m_data.m_storage[i] )
      v9[i] = -1;
  }
  v37 = rindex.m_data.m_storage;
  v38 = 0i64;
  v62 = rindex.m_data.m_storage;
  if ( v16 > 0 )
  {
    v39 = v16;
    v40 = rindex.m_data.m_storage;
    v60 = rindex.m_data.m_storage;
    v41 = v9;
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
            v47 = (char *)v37 - (char *)v9;
            do
            {
              v48 = v64->m_minDesiredIslandSize;
              if ( v42 + 10 >= v48 )
                break;
              v49 = *v46;
              if ( *v46 >= 0 && v49 + v42 < v48 )
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
            v9 = v59;
            v40 = v60;
            v39 = v61;
            v37 = v62;
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
  hkUnionFind::reindex(v65, &rindex, v15, elementsPerGroup);
  v50 = rindex.m_data.m_storage;
  v51 = (4 * rindex.m_size.m_storage + 127) & 0xFFFFFF80;
  v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v53 = (v51 + 15) & 0xFFFFFFF0;
  if ( v51 > v52->m_slabSize || (char *)v50 + v53 != v52->m_cur || v52->m_firstNonLifoEnd == v50 )
    hkLifoAllocator::slowBlockFree(v52, v50, v53);
  else
    v52->m_cur = v50;
  v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v55 = (v56 + 15) & 0xFFFFFFF0;
  if ( v56 > v54->m_slabSize || (char *)v9 + v55 != v54->m_cur || v54->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v54, v9, v55);
  else
    v54->m_cur = v9;
}

// File Line: 876
// RVA: 0xD7EFD0
void __fastcall hkpWorldOperationUtil::splitSimulationIsland(hkpSimulationIsland *currentIsland, hkpWorld *world, hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *newIslandsOut, hkArray<hkpEntity *,hkContainerHeapAllocator> *oldEntitiesOut)
{
  int v4; // ebx
  hkpSimulationIsland *v5; // r13
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v6; // r14
  hkpWorld *v7; // rdi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v8; // r15
  hkLifoAllocator *v9; // rax
  int *v10; // r9
  int v11; // edx
  char *v12; // rcx
  int v13; // er8
  int v14; // ebx
  hkLifoAllocator *v15; // rax
  _BYTE *v16; // rsi
  int v17; // edx
  _BYTE *v18; // rcx
  signed __int64 v19; // r12
  __int64 v20; // rsi
  hkLifoAllocator *v21; // rax
  signed __int64 v22; // r9
  int v23; // edx
  char *v24; // rcx
  __int64 v25; // rdi
  __int64 v26; // r10
  __int64 v27; // rax
  int v28; // er11
  __int64 v29; // rbx
  __int64 v30; // r8
  int v31; // edx
  int v32; // er8
  char v33; // dl
  int v34; // edx
  int v35; // er8
  __int64 v36; // r8
  _BYTE *v37; // rdx
  signed __int64 v38; // r11
  signed int v39; // ebx
  hkLifoAllocator *v40; // rax
  int v41; // er8
  char *v42; // rdi
  signed int v43; // ebx
  hkLifoAllocator *v44; // rax
  int v45; // er8
  signed __int64 v46; // rbx
  hkLifoAllocator *v47; // rax
  int *v48; // r14
  int v49; // er15
  char *v50; // rcx
  hkLifoAllocator *v51; // rax
  char *v52; // rdx
  char *v53; // rcx
  signed __int64 v54; // r11
  signed __int64 v55; // rcx
  int v56; // esi
  __int64 v57; // r10
  __int64 v58; // rbx
  unsigned __int16 *v59; // r9
  int v60; // edx
  __int64 v61; // rdi
  int v62; // er8
  char v63; // dl
  int v64; // edx
  int v65; // er8
  signed int v66; // ecx
  int v67; // er10
  __int64 v68; // r8
  __int64 v69; // r9
  hkpEntity *v70; // rdx
  signed __int64 v71; // rcx
  signed int v72; // eax
  signed __int64 j; // rcx
  hkResultEnum v74; // ecx
  __int64 v75; // r9
  signed __int64 v76; // rbx
  _DWORD *v77; // r8
  int *v78; // r15
  _BYTE *v79; // r13
  int v80; // edx
  hkResultEnum v81; // edi
  _BYTE *v82; // rsi
  signed __int64 v83; // r10
  int *v84; // rcx
  int v85; // er9
  int v86; // eax
  char *v87; // rdi
  signed int v88; // ebx
  hkLifoAllocator *v89; // rax
  int v90; // er8
  hkLifoAllocator *v91; // rax
  int v92; // er8
  signed __int64 v93; // rbx
  hkLifoAllocator *v94; // rax
  char *v95; // rcx
  hkLifoAllocator *v96; // rax
  char *v97; // rdx
  char *v98; // rcx
  signed __int64 v99; // r11
  signed __int64 v100; // rcx
  int v101; // esi
  __int64 v102; // r10
  __int64 v103; // rbx
  unsigned __int16 *v104; // r9
  int v105; // edx
  __int64 v106; // rdi
  int v107; // er8
  char v108; // dl
  int v109; // edx
  int v110; // er8
  signed int v111; // ecx
  int v112; // er10
  __int64 v113; // r8
  __int64 v114; // r9
  hkpEntity *v115; // rdx
  signed __int64 v116; // rcx
  signed int v117; // eax
  signed __int64 i; // rcx
  __int64 v119; // r9
  signed __int64 v120; // rbx
  _DWORD *v121; // r8
  int *v122; // r15
  _BYTE *v123; // r13
  int v124; // edx
  hkResultEnum v125; // edi
  _BYTE *v126; // rsi
  signed __int64 v127; // r10
  int *v128; // rcx
  int v129; // er9
  int v130; // eax
  int v131; // eax
  char v132; // dl
  signed __int64 v133; // rbx
  hkLifoAllocator *v134; // rax
  _QWORD *v135; // r12
  int v136; // edx
  char *v137; // rcx
  bool v138; // zf
  signed __int64 v139; // rdi
  signed __int64 v140; // rsi
  _QWORD **v141; // rax
  hkpSimulationIsland *v142; // rax
  __int64 v143; // rax
  __int64 v144; // rbx
  char v145; // al
  int v146; // er9
  hkpEntity **v147; // rdx
  void *v148; // rdi
  int *v149; // rax
  signed __int64 v150; // r10
  hkpEntity *v151; // rbx
  __int64 v152; // r8
  unsigned __int16 *v153; // rdx
  signed int v154; // er9
  int v155; // ecx
  unsigned int v156; // er10
  unsigned int v157; // er11
  __int64 v158; // rax
  int v159; // er12
  _WORD *v160; // rax
  __int64 v161; // rdi
  int v162; // eax
  _WORD *v163; // rax
  int v164; // ecx
  hkpAction **v165; // r12
  hkpSimulationIsland *v166; // r14
  __int64 v167; // rax
  __int64 v168; // rsi
  __int64 v169; // r15
  hkpAction *v170; // rdi
  hkpAction *v171; // rcx
  hkBaseObjectVtbl *v172; // rax
  hkpSimulationIsland *v173; // rbx
  int v174; // edx
  __int64 v175; // rcx
  signed __int64 v176; // r14
  hkpAgentNnTrack *v177; // rsi
  int v178; // er15
  __int64 v179; // r12
  hkpAgentNnSector **v180; // rax
  unsigned __int64 v181; // rdi
  hkpAgentNnEntry *v182; // rbx
  hkpSimulationIsland *v183; // rdx
  hkpAgentNnTrack *v184; // rcx
  char *v185; // r14
  signed __int64 v186; // rsi
  __int64 v187; // rbx
  char v188; // al
  signed int v189; // eax
  __int64 v190; // rcx
  __int16 v191; // cx
  int v192; // er15
  int v193; // ecx
  __int64 v194; // r12
  unsigned __int64 v195; // r14
  signed int v196; // eax
  hkpAgentNnEntry *v197; // rbx
  unsigned __int64 v198; // rdi
  __int64 v199; // rdx
  hkpAgentNnTrack *v200; // rcx
  _QWORD **v201; // rax
  hkInplaceArray<hkpAgentNnSector *,1,hkContainerHeapAllocator> *v202; // rdx
  int v203; // er8
  unsigned int v204; // ecx
  int v205; // eax
  signed int v206; // edi
  hkInplaceArray<hkpAgentNnSector *,1,hkContainerHeapAllocator> *v207; // rdx
  int v208; // er9
  unsigned int v209; // ecx
  int v210; // eax
  hkResultEnum v211; // er8
  char *v212; // rbx
  __int64 *v213; // rdx
  __int64 v214; // rax
  char v215; // cl
  hkLifoAllocator *v216; // rax
  int v217; // er8
  hkLifoAllocator *v218; // rax
  int v219; // er8
  int *v220; // rdi
  signed int v221; // ebx
  hkLifoAllocator *v222; // rax
  int v223; // er8
  int v224; // [rsp+30h] [rbp-C0h]
  __int32 v225; // [rsp+30h] [rbp-C0h]
  _BYTE *v226; // [rsp+38h] [rbp-B8h]
  void *p; // [rsp+40h] [rbp-B0h]
  __int64 *array; // [rsp+48h] [rbp-A8h]
  int v229; // [rsp+50h] [rbp-A0h]
  int v230; // [rsp+54h] [rbp-9Ch]
  __int64 v231; // [rsp+58h] [rbp-98h]
  _DWORD *v232; // [rsp+60h] [rbp-90h]
  void *v233; // [rsp+68h] [rbp-88h]
  hkResult v234[2]; // [rsp+70h] [rbp-80h]
  hkResult v235[2]; // [rsp+78h] [rbp-78h]
  hkpAgentNnTrack *v236; // [rsp+80h] [rbp-70h]
  hkpAgentNnTrack *v237; // [rsp+88h] [rbp-68h]
  hkResult result; // [rsp+90h] [rbp-60h]
  hkUnionFind checkConnectivityOut; // [rsp+98h] [rbp-58h]
  hkFixedArray<int> parents; // [rsp+B0h] [rbp-40h]
  hkArray<int,hkContainerHeapAllocator> elementsPerGroup; // [rsp+C0h] [rbp-30h]
  char v242; // [rsp+D0h] [rbp-20h]
  char *v243; // [rsp+150h] [rbp+60h]
  int v244; // [rsp+158h] [rbp+68h]
  int v245; // [rsp+15Ch] [rbp+6Ch]
  char v246; // [rsp+160h] [rbp+70h]
  hkpSimulationIsland *vars0; // [rsp+230h] [rbp+140h]
  hkpWorld *retaddr; // [rsp+238h] [rbp+148h]
  hkpSimulationIsland *v249; // [rsp+240h] [rbp+150h]
  hkpWorld *v250; // [rsp+248h] [rbp+158h]

  v250 = world;
  v249 = currentIsland;
  v4 = currentIsland->m_entities.m_size;
  v5 = currentIsland;
  v6 = newIslandsOut;
  v7 = world;
  v8 = oldEntitiesOut;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (int *)v9->m_cur;
  v11 = (4 * v4 + 127) & 0xFFFFFF80;
  v12 = (char *)v10 + v11;
  if ( v11 > v9->m_slabSize || v12 > v9->m_end )
    v10 = (int *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
  else
    v9->m_cur = v12;
  v13 = v5->m_entities.m_size;
  parents.m_data.m_storage = v10;
  parents.m_size.m_storage = v4;
  hkUnionFind::hkUnionFind(&checkConnectivityOut, &parents, v13);
  if ( hkpSimulationIsland::isFullyConnected(v5, &checkConnectivityOut) )
  {
    *((_BYTE *)v5 + 49) &= 0xF3u;
    goto LABEL_276;
  }
  elementsPerGroup.m_data = (int *)&v242;
  elementsPerGroup.m_capacityAndFlags = -2147483616;
  elementsPerGroup.m_size = 0;
  hkUnionFind::assignGroups(&checkConnectivityOut, &result, &elementsPerGroup);
  v14 = elementsPerGroup.m_size;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = v15->m_cur;
  v17 = (v14 + 128) & 0xFFFFFF80;
  result.m_enum = (v14 + 128) & 0xFFFFFF80;
  v226 = v16;
  v18 = &v16[v17];
  if ( v17 > v15->m_slabSize || v18 > v15->m_end )
  {
    v16 = hkLifoAllocator::allocateFromNewSlab(v15, v17);
    v226 = v16;
  }
  else
  {
    v15->m_cur = v18;
  }
  v19 = 1i64;
  if ( !(*((_BYTE *)v5 + 49) & 0xC) )
  {
    if ( !v7->m_minDesiredIslandSize )
    {
      hkString::memSet(v16, 0, elementsPerGroup.m_size + 1);
      goto LABEL_159;
    }
    v93 = elementsPerGroup.m_size;
    v94 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v48 = (int *)v94->m_cur;
    v49 = (4 * v93 + 127) & 0xFFFFFF80;
    v224 = (4 * v93 + 127) & 0xFFFFFF80;
    v95 = (char *)v48 + v49;
    if ( v49 > v94->m_slabSize || v95 > v94->m_end )
      v48 = (int *)hkLifoAllocator::allocateFromNewSlab(v94, v49);
    else
      v94->m_cur = v95;
    v96 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v97 = (char *)v96->m_cur;
    v98 = &v97[v49];
    if ( v49 > v96->m_slabSize || v98 > v96->m_end )
      v97 = (char *)hkLifoAllocator::allocateFromNewSlab(v96, v49);
    else
      v96->m_cur = v98;
    p = v97;
    LODWORD(array) = v93;
    v99 = v93;
    v100 = 0i64;
    if ( (signed int)v93 > 0 )
    {
      do
      {
        *((_DWORD *)p + ++v100 - 1) = 0;
        v48[v100 - 1] = 0;
      }
      while ( v100 < v93 );
    }
    if ( v7->m_wantDeactivation.m_bool )
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
            *((_DWORD *)p + v106) = 1;
          v111 = v104[128];
          if ( v111 < 1 )
            v111 = 1;
          ++v101;
          ++v103;
          v48[v106] += v111;
          ++v102;
        }
        while ( v101 < v5->m_entities.m_size );
        v49 = v224;
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
          *(_DWORD *)((char *)p + v116 * 4) = 1;
          v117 = v115->m_constraintsMaster.m_size;
          if ( v117 < 1 )
            v117 = 1;
          ++v112;
          v48[v116] += v117;
        }
        while ( v112 < v5->m_entities.m_size );
      }
    }
    for ( i = 0i64; i < v99; ++i )
    {
      if ( !*((_DWORD *)p + i) )
        v48[i] = -1;
    }
    v74 = 0;
    v119 = 0i64;
    v233 = p;
    if ( v99 <= 0 )
      goto LABEL_99;
    v120 = v99;
    v121 = p;
    v232 = p;
    v122 = v48;
    v123 = p;
    *(_QWORD *)&v235[0].m_enum = v99;
    do
    {
      v124 = *v122;
      if ( *v122 != -2 )
      {
        v125 = v74;
        v126 = &v226[v119];
        ++v74;
        ++v119;
        *v126 = 0;
        *v121 = v125;
        *(_QWORD *)&v234[0].m_enum = v119;
        if ( v124 >= 0 )
        {
          v127 = v19;
          if ( v19 < v99 )
          {
            v128 = v122 + 1;
            do
            {
              v129 = retaddr->m_minDesiredIslandSize;
              if ( v124 + 10 >= v129 )
                break;
              v130 = *v128;
              if ( *v128 >= 0 && v130 + v124 < v129 )
              {
                *v126 = 1;
                *(int *)((char *)v128 + v123 - (_BYTE *)v48) = v125;
                v124 += v130;
                *v128 = -2;
              }
              ++v127;
              ++v128;
            }
            while ( v127 < v99 );
            v121 = v232;
            v74 = v234[0].m_enum;
            v119 = *(_QWORD *)&v234[0].m_enum;
            v120 = *(_QWORD *)&v235[0].m_enum;
            v123 = v233;
          }
        }
      }
      ++v121;
      ++v122;
      ++v19;
      --v120;
      v232 = v121;
      *(_QWORD *)&v235[0].m_enum = v120;
    }
    while ( v120 );
    goto LABEL_98;
  }
  if ( !v7->m_wantDeactivation.m_bool )
  {
    v46 = elementsPerGroup.m_size;
    v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v48 = (int *)v47->m_cur;
    v49 = (4 * v46 + 127) & 0xFFFFFF80;
    v224 = (4 * v46 + 127) & 0xFFFFFF80;
    v50 = (char *)v48 + v49;
    if ( v49 > v47->m_slabSize || v50 > v47->m_end )
      v48 = (int *)hkLifoAllocator::allocateFromNewSlab(v47, v49);
    else
      v47->m_cur = v50;
    v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v52 = (char *)v51->m_cur;
    v53 = &v52[v49];
    if ( v49 > v51->m_slabSize || v53 > v51->m_end )
      v52 = (char *)hkLifoAllocator::allocateFromNewSlab(v51, v49);
    else
      v51->m_cur = v53;
    p = v52;
    LODWORD(array) = v46;
    v54 = v46;
    v55 = 0i64;
    if ( (signed int)v46 > 0 )
    {
      do
      {
        *((_DWORD *)p + ++v55 - 1) = 0;
        v48[v55 - 1] = 0;
      }
      while ( v55 < v46 );
    }
    if ( v7->m_wantDeactivation.m_bool )
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
            *((_DWORD *)p + v61) = 1;
          v66 = v59[128];
          if ( v66 < 1 )
            v66 = 1;
          ++v56;
          ++v58;
          v48[v61] += v66;
          ++v57;
        }
        while ( v56 < v5->m_entities.m_size );
        v49 = v224;
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
          *(_DWORD *)((char *)p + v71 * 4) = 1;
          v72 = v70->m_constraintsMaster.m_size;
          if ( v72 < 1 )
            v72 = 1;
          ++v67;
          v48[v71] += v72;
        }
        while ( v67 < v5->m_entities.m_size );
      }
    }
    for ( j = 0i64; j < v54; ++j )
    {
      if ( !*((_DWORD *)p + j) )
        v48[j] = -1;
    }
    v74 = 0;
    v75 = 0i64;
    v233 = p;
    if ( v54 <= 0 )
      goto LABEL_99;
    v76 = v54;
    v77 = p;
    v232 = p;
    v78 = v48;
    v79 = p;
    *(_QWORD *)&v235[0].m_enum = v54;
    do
    {
      v80 = *v78;
      if ( *v78 != -2 )
      {
        v81 = v74++;
        v82 = &v226[v75++];
        *v82 = 0;
        *(_QWORD *)&v234[0].m_enum = v75;
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
                *(int *)((char *)v84 + v79 - (_BYTE *)v48) = v81;
                v80 += v86;
                *v84 = -2;
              }
              ++v83;
              ++v84;
            }
            while ( v83 < v54 );
            v77 = v232;
            v74 = v234[0].m_enum;
            v75 = *(_QWORD *)&v234[0].m_enum;
            v76 = *(_QWORD *)&v235[0].m_enum;
            v79 = v233;
          }
        }
      }
      ++v77;
      ++v78;
      ++v19;
      --v76;
      v232 = v77;
      *(_QWORD *)&v235[0].m_enum = v76;
    }
    while ( v76 );
LABEL_98:
    v5 = vars0;
    v49 = v224;
LABEL_99:
    hkUnionFind::reindex(&checkConnectivityOut, (hkFixedArray<int> *)&p, (unsigned int)v74, &elementsPerGroup);
    v87 = (char *)p;
    v88 = (4 * (_DWORD)array + 127) & 0xFFFFFF80;
    v89 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v90 = (v88 + 15) & 0xFFFFFFF0;
    if ( v88 > v89->m_slabSize || &v87[v90] != v89->m_cur || v89->m_firstNonLifoEnd == v87 )
      hkLifoAllocator::slowBlockFree(v89, v87, v90);
    else
      v89->m_cur = v87;
    v91 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v92 = (v49 + 15) & 0xFFFFFFF0;
    if ( v49 > v91->m_slabSize || (char *)v48 + v92 != v91->m_cur || v91->m_firstNonLifoEnd == v48 )
    {
      hkLifoAllocator::slowBlockFree(v91, v48, v92);
      v6 = (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)v249;
      v8 = (hkArray<hkpEntity *,hkContainerHeapAllocator> *)v250;
      v16 = v226;
    }
    else
    {
      v8 = (hkArray<hkpEntity *,hkContainerHeapAllocator> *)v250;
      v16 = v226;
      v91->m_cur = v48;
      v6 = (hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *)v249;
    }
    goto LABEL_159;
  }
  v20 = elementsPerGroup.m_size;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (signed __int64)v21->m_cur;
  v23 = (4 * v20 + 127) & 0xFFFFFF80;
  v24 = (char *)(v22 + v23);
  if ( v23 > v21->m_slabSize || v24 > v21->m_end )
    v22 = (signed __int64)hkLifoAllocator::allocateFromNewSlab(v21, v23);
  else
    v21->m_cur = v24;
  v25 = 0i64;
  p = (void *)v22;
  LODWORD(array) = v20;
  v26 = v20;
  v27 = 0i64;
  if ( (signed int)v20 > 0 )
  {
    do
    {
      *(_DWORD *)(v22 + 4 * v27) = 0;
      v22 = (signed __int64)p;
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
      v30 = *(__int64 *)((char *)v5->m_entities.m_data + v25);
      v31 = *(unsigned __int16 *)(v30 + 356);
      if ( (unsigned __int8)retaddr->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1] == v31 >> 14 )
        v31 >>= 7;
      v32 = *(unsigned __int16 *)(v30 + 354);
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
        v22 = (signed __int64)p;
      }
      ++v28;
      v25 += 8i64;
      ++v29;
    }
    while ( v28 < v5->m_entities.m_size );
    v8 = (hkArray<hkpEntity *,hkContainerHeapAllocator> *)v250;
    LODWORD(v25) = 0;
  }
  v36 = 1i64;
  *v226 = 1;
  if ( (signed int)v20 > 0 )
  {
    v37 = v226 + 1;
    v38 = -v22;
    do
    {
      if ( *(_DWORD *)((char *)p + v38 + v22) )
      {
        *(_DWORD *)v22 = v25;
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
  if ( (signed int)v36 <= (signed int)v20 )
  {
    hkUnionFind::reindex(&checkConnectivityOut, (hkFixedArray<int> *)&p, v36, &elementsPerGroup);
    v42 = (char *)p;
    v43 = (4 * (_DWORD)array + 127) & 0xFFFFFF80;
    v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v45 = (v43 + 15) & 0xFFFFFFF0;
    if ( v43 > v44->m_slabSize || &v42[v45] != v44->m_cur || v44->m_firstNonLifoEnd == v42 )
      hkLifoAllocator::slowBlockFree(v44, v42, v45);
    else
      v44->m_cur = v42;
    v16 = v226;
  }
  else
  {
    v16 = v226;
    *v226 = 0;
    v39 = (4 * (_DWORD)array + 127) & 0xFFFFFF80;
    v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v41 = (v39 + 15) & 0xFFFFFFF0;
    if ( v39 > v40->m_slabSize || (char *)p + v41 != v40->m_cur || v40->m_firstNonLifoEnd == p )
      hkLifoAllocator::slowBlockFree(v40, p, v41);
    else
      v40->m_cur = p;
  }
  if ( elementsPerGroup.m_size == 1 )
    goto LABEL_268;
LABEL_159:
  v131 = hkUnionFind::moveBiggestGroupToIndexZero(&checkConnectivityOut, &elementsPerGroup);
  v132 = *v16;
  *v16 = v16[v131];
  v16[v131] = v132;
  v133 = elementsPerGroup.m_size;
  v234[0] = (hkResult)elementsPerGroup.m_size;
  v235[0] = *(hkResult *)elementsPerGroup.m_data;
  v225 = v5->m_entities.m_size;
  if ( elementsPerGroup.m_size != 1 )
  {
    v134 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v135 = v134->m_cur;
    v136 = (8 * v133 + 127) & 0xFFFFFF80;
    v235[0].m_enum = (8 * v133 + 127) & 0xFFFFFF80;
    v233 = v135;
    v137 = (char *)v135 + v136;
    if ( v136 > v134->m_slabSize || v137 > v134->m_end )
    {
      v135 = hkLifoAllocator::allocateFromNewSlab(v134, v136);
      v233 = v135;
    }
    else
    {
      v134->m_cur = v137;
    }
    v138 = *v16 == 0;
    v139 = 1i64;
    v140 = v133;
    *((_BYTE *)v5 + 49) ^= (*((_BYTE *)v5 + 49) ^ 4 * !v138) & 0xC;
    *v135 = v5;
    if ( v133 > 1 )
    {
      do
      {
        v141 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v142 = (hkpSimulationIsland *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v141[11] + 8i64))(
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
        v145 = (*(_BYTE *)(v144 + 49) ^ 4 * (v226[v139] != 0)) & 0xC;
        *(_BYTE *)(v144 + 50) = *(_BYTE *)(v144 + 50) & 0xDF | 0x10;
        *(_BYTE *)(v144 + 49) ^= v145;
        *(_WORD *)(v144 + 44) = v6->m_size;
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
        v6->m_data[v6->m_size++] = (hkpSimulationIsland *)v144;
        v135[v139] = v144;
        v146 = elementsPerGroup.m_data[v139];
        if ( (*(_DWORD *)(v144 + 108) & 0x3FFFFFFF) >= v146 )
          v234[0].m_enum = 0;
        else
          hkArrayUtil::_reserve(
            v234,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (void *)(v144 + 96),
            v146,
            8);
        ++v139;
      }
      while ( v139 < v140 );
      v5 = vars0;
      v8 = (hkArray<hkpEntity *,hkContainerHeapAllocator> *)v250;
    }
    v147 = v5->m_entities.m_data;
    v148 = (void *)v5->m_entities.m_size;
    v232 = v5->m_entities.m_data;
    if ( v8 )
    {
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v5->m_entities,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v8);
      v149 = elementsPerGroup.m_data;
      v5->m_entities.m_size = 0;
      if ( (v5->m_entities.m_capacityAndFlags & 0x3FFFFFFF) < *v149 )
        hkArrayUtil::_reserve(
          v234,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v5->m_entities,
          *v149,
          8);
      v147 = (hkpEntity **)v232;
    }
    else
    {
      v5->m_entities.m_size = 0;
    }
    v150 = 0i64;
    *(_QWORD *)&v234[0].m_enum = 0i64;
    p = v148;
    if ( (signed int)v148 > 0 )
    {
      do
      {
        v151 = v147[v150];
        v152 = v135[parents.m_data.m_storage[v150]];
        v151->m_simulationIsland = (hkpSimulationIsland *)v152;
        v151->m_storageIndex = *(_WORD *)(v152 + 104);
        *(_QWORD *)(*(_QWORD *)(v152 + 96) + 8i64 * (signed int)(*(_DWORD *)(v152 + 104))++) = v151;
        if ( v5 != (hkpSimulationIsland *)v152 )
        {
          v153 = (unsigned __int16 *)v151->m_constraintsMaster.m_data;
          v154 = 0;
          if ( v151->m_constraintsMaster.m_size > 0u )
          {
            do
            {
              v155 = v153[18];
              v156 = v153[19];
              v157 = v153[20];
              --v5->m_numConstraints;
              v158 = *(_QWORD *)v153;
              v159 = v5->m_constraintInfo.m_maxSizeOfSchema;
              v138 = *(_QWORD *)(*(_QWORD *)v153 + 96i64) == 0i64;
              HIDWORD(v236) = v155;
              v237 = (hkpAgentNnTrack *)__PAIR__(v157, v156);
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
                if ( *(_DWORD *)(v152 + 16) > v159 )
                  v159 = *(_DWORD *)(v152 + 16);
                if ( v159 > v155 )
                  v162 = v159;
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
            while ( v154 < v151->m_constraintsMaster.m_size );
            v150 = *(_QWORD *)&v234[0].m_enum;
            v135 = v233;
          }
          v147 = (hkpEntity **)v232;
        }
        *(_QWORD *)&v234[0].m_enum = ++v150;
      }
      while ( v150 < (signed __int64)p );
    }
    v165 = v5->m_actions.m_data;
    v166 = retaddr->m_fixedIsland;
    v167 = v5->m_actions.m_size;
    v5->m_actions.m_size = 0;
    v168 = 0i64;
    v169 = v167;
    if ( (signed int)v167 > 0 )
    {
      do
      {
        v170 = v165[v168];
        if ( v170 )
        {
          v171 = v165[v168];
          v243 = &v246;
          v172 = v170->vfptr;
          v173 = 0i64;
          v244 = 0;
          v245 = -2147483632;
          v172[2].__vecDelDtor((hkBaseObject *)&v171->vfptr, (unsigned int)&v243);
          v174 = 0;
          if ( v244 > 0 )
          {
            v175 = (__int64)v243;
            do
            {
              v173 = *(hkpSimulationIsland **)(*(_QWORD *)v175 + 296i64);
              if ( v173 != v166 )
                break;
              ++v174;
              v175 += 8i64;
            }
            while ( v174 < v244 );
          }
          v244 = 0;
          if ( v245 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v243,
              8 * v245);
          v243 = 0i64;
          v245 = 2147483648;
          v170->m_island = v173;
          if ( v173->m_actions.m_size == (v173->m_actions.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v173->m_actions,
              8);
          v173->m_actions.m_data[v173->m_actions.m_size++] = v170;
        }
        ++v168;
      }
      while ( v168 < v169 );
      v5 = vars0;
    }
    hkpWorld::lockForIslandSplit(retaddr, v5);
    v236 = &v5->m_narrowphaseAgentTrack;
    v237 = &v5->m_midphaseAgentTrack;
    if ( 8 * (v225 - v235[0].m_enum) >= v225 )
    {
      v186 = 0i64;
      do
      {
        v187 = (__int64)*(&v236 + v186);
        v188 = *(_BYTE *)(v187 + 2);
        array = &v231;
        v229 = 0;
        v230 = -2147483647;
        LOWORD(p) = 960;
        BYTE2(p) = v188;
        v189 = *(_DWORD *)(v187 + 16);
        if ( v189 == 1 )
        {
          v190 = **(_QWORD **)(v187 + 8);
          v229 = 1;
          v231 = v190;
          *(_DWORD *)(v187 + 16) = 0;
        }
        else if ( v189 > 1 )
        {
          hkArrayUtil::_reserve(v235, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2, 8);
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array,
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(v187 + 8));
        }
        v191 = (signed __int16)p;
        v192 = 0;
        LOWORD(p) = *(_WORD *)v187;
        *(_WORD *)v187 = v191;
        v193 = v229;
        if ( v229 > 0 )
        {
          v194 = 0i64;
          do
          {
            ++v192;
            v195 = array[v194];
            v196 = (unsigned __int16)p;
            v197 = (hkpAgentNnEntry *)array[v194];
            if ( v192 != v193 )
              v196 = 960;
            v198 = v195 + v196;
            if ( v195 < v198 )
            {
              do
              {
                v199 = *(_QWORD *)(&v197->m_collidable[0][2].m_broadPhaseHandle.m_type
                                 + v197->m_collidable[0]->m_ownerOffset);
                if ( *(_WORD *)(v199 + 44) == -1 )
                  v199 = *(_QWORD *)(&v197->m_collidable[1][2].m_broadPhaseHandle.m_type
                                   + v197->m_collidable[1]->m_ownerOffset);
                v200 = (hkpAgentNnTrack *)(v199 + 120);
                if ( !v186 )
                  v200 = (hkpAgentNnTrack *)(v199 + 152);
                hkAgentNnMachine_CopyAndRelinkAgentEntry(v200, v197);
                v197 = (hkpAgentNnEntry *)((char *)v197 + (unsigned __int8)v197->m_size);
              }
              while ( (unsigned __int64)v197 < v198 );
            }
            v201 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, unsigned __int64, signed __int64))(*v201[11] + 16i64))(
              v201[11],
              v195,
              960i64);
            v193 = v229;
            ++v194;
          }
          while ( v192 < v229 );
        }
        v229 = 0;
        if ( v230 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            8 * v230);
        ++v186;
      }
      while ( v186 < 2 );
      v5 = vars0;
    }
    else
    {
      v176 = 0i64;
      vars0 = 0i64;
      do
      {
        v177 = *(&v236 + v176);
        v178 = 0;
        if ( v177->m_sectors.m_size > 0 )
        {
          v179 = 0i64;
          do
          {
            v180 = v177->m_sectors.m_data;
            v181 = (unsigned __int64)v180[v179];
            v182 = (hkpAgentNnEntry *)v180[v179];
            if ( v181 < v181 + (signed int)hkpAgentNnTrack::getSectorSize(v177, v178) )
            {
              do
              {
                v183 = *(hkpSimulationIsland **)(&v182->m_collidable[0][2].m_broadPhaseHandle.m_type
                                               + v182->m_collidable[0]->m_ownerOffset);
                if ( v183->m_storageIndex == -1 )
                  v183 = *(hkpSimulationIsland **)(&v182->m_collidable[1][2].m_broadPhaseHandle.m_type
                                                 + v182->m_collidable[1]->m_ownerOffset);
                if ( v183 == v5 )
                {
                  v182 = (hkpAgentNnEntry *)((char *)v182 + (unsigned __int8)v182->m_size);
                }
                else
                {
                  v184 = &v183->m_midphaseAgentTrack;
                  v185 = &v182->m_streamCommand - v181;
                  if ( !vars0 )
                    v184 = &v183->m_narrowphaseAgentTrack;
                  hkAgentNnMachine_CopyAndRelinkAgentEntry(v184, v182);
                  hkAgentNnMachine_InternalDeallocateEntry(v177, v182);
                  if ( v178 >= v177->m_sectors.m_size )
                    break;
                  v181 = (unsigned __int64)v177->m_sectors.m_data[v179];
                  v182 = (hkpAgentNnEntry *)&v185[v181];
                }
              }
              while ( (unsigned __int64)v182 < v181 + (signed int)hkpAgentNnTrack::getSectorSize(v177, v178) );
            }
            ++v178;
            ++v179;
          }
          while ( v178 < v177->m_sectors.m_size );
          v176 = (signed __int64)vars0;
        }
        vars0 = (hkpSimulationIsland *)++v176;
      }
      while ( v176 < 2 );
    }
    hkpWorld::unlockForIslandSplit(retaddr, v5);
    v202 = &v5->m_narrowphaseAgentTrack.m_sectors;
    v203 = v5->m_narrowphaseAgentTrack.m_sectors.m_capacityAndFlags;
    if ( v203 >= 0 )
    {
      v204 = ((((((((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size
                                                                                             + 3)) >> 8) | ((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3)) >> 2) | ((((((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_narrowphaseAgentTrack.m_sectors.m_size + 3);
      v205 = (v204 | (v204 >> 1)) + 1;
      if ( v205 < 1 )
      {
        v206 = 1;
        hkArrayUtil::_reduce(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v202,
          8,
          (char *)v5->m_narrowphaseAgentTrack.m_sectors.m_storage,
          1);
LABEL_254:
        v207 = &v5->m_midphaseAgentTrack.m_sectors;
        v208 = v5->m_midphaseAgentTrack.m_sectors.m_capacityAndFlags;
        if ( v208 >= 0 )
        {
          v209 = ((((((((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size
                                                                                              + 3)) >> 8) | ((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size + 3)) >> 2) | ((((((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size + 3)) >> 4) | ((((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size + 3)) >> 8) | ((unsigned int)(v5->m_midphaseAgentTrack.m_sectors.m_size + 3) >> 16) | (v5->m_midphaseAgentTrack.m_sectors.m_size + 3);
          v210 = (v209 | (v209 >> 1)) + 1;
          if ( v210 >= 1 )
          {
            if ( v210 < (v208 & 0x3FFFFFFF) )
              hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v207, 8, 0i64, v210);
          }
          else
          {
            hkArrayUtil::_reduce(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v207,
              8,
              (char *)v5->m_midphaseAgentTrack.m_sectors.m_storage,
              1);
          }
        }
        v211 = v234[0].m_enum;
        v212 = (char *)v233;
        if ( v234[0].m_enum > 1 )
        {
          v213 = (__int64 *)((char *)v233 + 8);
          do
          {
            v214 = *v213;
            v215 = v206++;
            ++v213;
            *(_BYTE *)(v214 + 48) = v5->m_splitCheckFrameCounter + v215;
          }
          while ( v206 < v211 );
        }
        v216 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v217 = (v235[0].m_enum + 15) & 0xFFFFFFF0;
        if ( v235[0].m_enum > v216->m_slabSize || &v212[v217] != v216->m_cur || v216->m_firstNonLifoEnd == v212 )
          hkLifoAllocator::slowBlockFree(v216, v212, v217);
        else
          v216->m_cur = v212;
        v16 = v226;
        goto LABEL_268;
      }
      if ( v205 < (v203 & 0x3FFFFFFF) )
        hkArrayUtil::_reduce((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v202, 8, 0i64, v205);
    }
    v206 = 1;
    goto LABEL_254;
  }
LABEL_268:
  v218 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v219 = (result.m_enum + 15) & 0xFFFFFFF0;
  if ( result.m_enum > v218->m_slabSize || &v16[v219] != v218->m_cur || v218->m_firstNonLifoEnd == v16 )
    hkLifoAllocator::slowBlockFree(v218, v16, v219);
  else
    v218->m_cur = v16;
  elementsPerGroup.m_size = 0;
  if ( elementsPerGroup.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      elementsPerGroup.m_data,
      4 * elementsPerGroup.m_capacityAndFlags);
  elementsPerGroup.m_data = 0i64;
  elementsPerGroup.m_capacityAndFlags = 2147483648;
LABEL_276:
  v220 = parents.m_data.m_storage;
  v221 = (4 * parents.m_size.m_storage + 127) & 0xFFFFFF80;
  v222 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v223 = (v221 + 15) & 0xFFFFFFF0;
  if ( v221 > v222->m_slabSize || (char *)v220 + v223 != v222->m_cur || v222->m_firstNonLifoEnd == v220 )
    hkLifoAllocator::slowBlockFree(v222, v220, v223);
  else
    v222->m_cur = v220;
}::slowBlockFree(v222, v220, v223);
  else
    v222->m_cur = v220;
}

// File Line: 1237
// RVA: 0xD804A0
void __fastcall hkpWorldOperationUtil::splitSimulationIsland(hkpWorld *world, hkpSimulationIsland *currentIsland)
{
  hkpSimulationIsland *v2; // r15
  hkpWorld *v3; // rbp
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v4; // r14
  char v5; // r12
  int v6; // edi
  int v7; // esi
  char v8; // bl
  char v9; // dl
  hkpSimulationIsland *v10; // rdi
  char v11; // al
  int v12; // [rsp+70h] [rbp+18h]

  v2 = currentIsland;
  v3 = world;
  v4 = &world->m_activeSimulationIslands;
  v5 = *((_BYTE *)currentIsland + 50) & 3;
  if ( !v5 )
    v4 = &world->m_inactiveSimulationIslands;
  *((_BYTE *)currentIsland + 49) &= 0xFCu;
  v6 = v4->m_size;
  v12 = v4->m_size;
  hkpWorldOperationUtil::splitSimulationIsland(currentIsland, world, v4, 0i64);
  v7 = v6;
  v8 = (*((_BYTE *)v2 + 50) >> 2) & 3;
  if ( v6 < v4->m_size )
  {
    v9 = 4 * (v5 & 3);
    do
    {
      v10 = v4->m_data[v7];
      *((_BYTE *)v10 + 50) &= 0xF3u;
      *((_BYTE *)v10 + 50) = v5 & 3 | (*((_BYTE *)v10 + 50) | v9) & 0xFC;
      if ( v5 )
      {
        if ( !v8 )
        {
          hkpWorldOperationUtil::markIslandInactive(v3, v10);
          v9 = 4 * (v5 & 3);
        }
      }
      v11 = v7++ + v2->m_splitCheckFrameCounter - v12;
      v10->m_splitCheckFrameCounter = v11;
    }
    while ( v7 < v4->m_size );
  }
}

// File Line: 1282
// RVA: 0xD80450
void __fastcall hkpWorldOperationUtil::splitSimulationIslands(hkpWorld *world)
{
  hkpWorld *v1; // rdi
  int v2; // eax
  __int64 i; // rbx
  hkpSimulationIsland *v4; // rdx

  v1 = world;
  if ( world->m_wantSimulationIslands.m_bool )
  {
    v2 = world->m_activeSimulationIslands.m_size - 1;
    for ( i = v2; i >= 0; --i )
    {
      v4 = v1->m_activeSimulationIslands.m_data[i];
      if ( *((_BYTE *)v4 + 49) & 3 )
        hkpWorldOperationUtil::splitSimulationIsland(v1, v4);
    }
  }
}

// File Line: 1328
// RVA: 0xD7EA90
void __fastcall hkpWorldOperationUtil::mergeIslands(hkpWorld *world, hkpEntity *entityA, hkpEntity *entityB)
{
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
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
void __fastcall hkpWorldOperationUtil::internalMergeTwoIslands(hkpWorld *world, hkpSimulationIsland *islandA, hkpSimulationIsland *islandB)
{
  int v3; // eax
  hkpWorld *v4; // rsi
  int v5; // ecx
  hkpSimulationIsland *v6; // rdi
  hkpSimulationIsland *v7; // rbx
  char v8; // al
  bool v9; // dl
  bool v10; // r12
  hkpSimulationIsland *v11; // rdx
  char v12; // al
  int v13; // er14
  unsigned __int16 v14; // bp
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // er9
  __int64 v19; // r8
  hkpEntity *v20; // rax
  signed __int64 v21; // r15
  int v22; // ebp
  int v23; // eax
  int v24; // eax
  int v25; // er9
  int v26; // er8
  signed __int64 v27; // r9
  __int64 v28; // rdx
  hkpAction *v29; // rcx
  int v30; // eax
  int v31; // eax
  int v32; // er9
  int v33; // er9
  __int64 v34; // r10
  hkpEntity *v35; // rcx
  hkConstraintInternal *v36; // rdx
  int i; // er8
  hkpConstraintInstance *v38; // rax
  signed __int64 v39; // r9
  bool v40; // zf
  unsigned __int16 v41; // r10
  __int64 v42; // r11
  signed __int64 v43; // r8
  bool v44; // al
  char v45; // cl
  bool v46; // al
  __int64 v47; // rcx
  hkpSimulationIsland *v48; // rdx
  hkResult result; // [rsp+60h] [rbp+8h]

  v3 = islandA->m_entities.m_size;
  v4 = world;
  v5 = islandB->m_entities.m_size;
  v6 = islandB;
  v7 = islandA;
  if ( v3 <= v5 && (v3 < v5 || islandA->m_storageIndex > islandB->m_storageIndex) )
  {
    v7 = islandB;
    v6 = islandA;
  }
  ++v4->m_criticalOperationsLockCount;
  v8 = *((_BYTE *)v7 + 50);
  v9 = v8 & 3 || *((_BYTE *)v6 + 50) & 3;
  v10 = v8 & 0xC || *((_BYTE *)v6 + 50) & 0xC;
  if ( v9 )
  {
    if ( v8 & 3 )
    {
      v12 = *((_BYTE *)v6 + 50);
      if ( v12 & 3 )
        goto LABEL_19;
      v11 = v6;
      *((_BYTE *)v6 + 50) = v12 & 0xF7 | 4;
    }
    else
    {
      v11 = v7;
      *((_BYTE *)v7 + 50) = v8 & 0xF7 | 4;
    }
    hkpWorldOperationUtil::internalActivateIsland(v4, v11, 0);
  }
LABEL_19:
  *((_BYTE *)v7 + 49) |= *((_BYTE *)v6 + 49) & 0xC;
  hkpSimulationIsland::markForWrite(v7);
  hkpSimulationIsland::markForWrite(v6);
  hkpSimulationIsland::markForWrite(v4->m_fixedIsland);
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
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_entities,
      v17,
      8);
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
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_actions,
      v25,
      8);
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
        ++v27;
        v7->m_actions.m_data[v27 - 1] = v29;
        v7->m_actions.m_data[v27 - 1]->m_island = v7;
      }
      ++v26;
      ++v28;
    }
    while ( v26 < v6->m_actions.m_size );
  }
  v30 = v7->m_actions.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v30 < (signed int)v21 )
  {
    v31 = 2 * v30;
    v32 = v21;
    if ( (signed int)v21 < v31 )
      v32 = v31;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_actions,
      v32,
      8);
  }
  v7->m_actions.m_size = v21;
  v33 = 0;
  if ( v6->m_entities.m_size > 0 )
  {
    v34 = 0i64;
    do
    {
      v35 = v6->m_entities.m_data[v34];
      v36 = v35->m_constraintsMaster.m_data;
      for ( i = v35->m_constraintsMaster.m_size - 1; i >= 0; v38->m_owner = (hkpConstraintOwner *)&v7->vfptr )
      {
        --i;
        v38 = v36->m_constraint;
        ++v36;
      }
      ++v33;
      ++v34;
    }
    while ( v33 < v6->m_entities.m_size );
  }
  hkpSimulationIsland::mergeConstraintInfo(v7, v6);
  v39 = (signed __int64)&v4->m_activeSimulationIslands;
  v7->m_numConstraints += v6->m_numConstraints;
  v40 = (*((_BYTE *)v6 + 50) & 3) == 0;
  v41 = v6->m_storageIndex;
  v6->m_numConstraints = 0;
  if ( v40 )
    v39 = (signed __int64)&v4->m_inactiveSimulationIslands;
  v42 = *(signed int *)(v39 + 8);
  if ( v41 < (signed int)v42 - 1 )
  {
    v43 = 8i64 * v41;
    *(_QWORD *)(v43 + *(_QWORD *)v39) = *(_QWORD *)(*(_QWORD *)v39 + 8 * v42 - 8);
    *(_WORD *)(*(_QWORD *)(*(_QWORD *)v39 + v43) + 44i64) = v41;
  }
  --*(_DWORD *)(v39 + 8);
  v44 = *((_BYTE *)v7 + 49) & 3 || *((_BYTE *)v6 + 49) & 3;
  *((_BYTE *)v7 + 49) &= 0xFCu;
  *((_BYTE *)v7 + 49) |= v44 & 3;
  v45 = *((_BYTE *)v7 + 49);
  v46 = v45 & 0x30 || *((_BYTE *)v6 + 49) & 0x30;
  *((_BYTE *)v7 + 50) &= 0xF3u;
  *((_BYTE *)v7 + 49) = v45 ^ (v45 ^ 16 * v46) & 0x30;
  *((_BYTE *)v7 + 50) |= 4 * (v10 != 0);
  if ( v6->m_dirtyListIndex != -1 )
  {
    EnterCriticalSection(&v4->m_islandDirtyListCriticalSection->m_section);
    if ( v7->m_dirtyListIndex == -1 )
    {
      v7->m_dirtyListIndex = v4->m_dirtySimulationIslands.m_size;
      if ( v4->m_dirtySimulationIslands.m_size == (v4->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v4->m_dirtySimulationIslands,
          8);
      v4->m_dirtySimulationIslands.m_data[v4->m_dirtySimulationIslands.m_size++] = v7;
    }
    LeaveCriticalSection(&v4->m_islandDirtyListCriticalSection->m_section);
  }
  hkpWorldOperationUtil::removeIslandFromDirtyList(v4, v6);
  v6->vfptr->__vecDelDtor((hkBaseObject *)&v6->vfptr, 1u);
  if ( *((_BYTE *)v7 + 50) & 3 )
  {
    v47 = v7->m_storageIndex;
    if ( v7->m_storageIndex )
    {
      v48 = *v4->m_activeSimulationIslands.m_data;
      if ( v7->m_entities.m_size > v48->m_entities.m_size )
      {
        v7->m_storageIndex = 0;
        v48->m_storageIndex = v47;
        *v4->m_activeSimulationIslands.m_data = v7;
        v4->m_activeSimulationIslands.m_data[v47] = v48;
      }
    }
  }
  hkpWorld::checkDeterminismOfIslandBroadPhase(v4, v7);
  v40 = v4->m_criticalOperationsLockCount-- == 1;
  if ( v40 && !v4->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v4->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v4);
    if ( v4->m_pendingOperationQueueCount == 1 )
    {
      if ( v4->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v4);
    }
  }
}

// File Line: 1549
// RVA: 0xD80580
void __fastcall hkpWorldOperationUtil::validateWorld(hkpWorld *world)
{
  hkpWorld *v1; // rdi
  int v2; // eax
  __int64 i; // rbx
  int v4; // eax
  __int64 j; // rbx

  v1 = world;
  v2 = world->m_activeSimulationIslands.m_size - 1;
  for ( i = v2; i >= 0; hkpSimulationIsland::isValid(v1->m_activeSimulationIslands.m_data[i--]) )
    ;
  v4 = v1->m_inactiveSimulationIslands.m_size - 1;
  for ( j = v4; j >= 0; hkpSimulationIsland::isValid(v1->m_inactiveSimulationIslands.m_data[j--]) )
    ;
  hkpSimulationIsland::isValid(v1->m_fixedIsland);
}

// File Line: 1573
// RVA: 0xD80AE0
void __fastcall hkpWorldOperationUtil::setRigidBodyMotionType(hkpRigidBody *body, hkpMotion::MotionType newState, hkpEntityActivation initialActivationState, hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode)
{
  int v4; // ebx
  hkpUpdateCollisionFilterOnEntityMode v5; // er13
  hkpEntityActivation v6; // er12
  hkpMotion::MotionType v7; // er15
  bool v8; // r14
  bool v9; // si
  hkpWorld *v10; // rdi
  hkpSimulationIsland *v11; // rcx
  int v12; // er14
  __int64 v13; // rsi
  hkpConstraintInstance *v14; // rbx
  int v15; // er9
  int v16; // ebx
  hkpEntity *v17; // rcx
  __int64 v18; // rsi
  hkpEntity *v19; // r8
  hkpSimulation *v20; // rcx
  hkpWorld *world; // [rsp+20h] [rbp-B8h]
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> entries; // [rsp+30h] [rbp-A8h]
  hkpAgentNnTrack agentsRemoved; // [rsp+40h] [rbp-98h]
  hkpAgentNnTrack appendee; // [rsp+60h] [rbp-78h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> removedConstraints; // [rsp+E8h] [rbp+10h]
  char v26; // [rsp+F8h] [rbp+20h]
  hkpEntity *entity; // [rsp+1A8h] [rbp+D0h]

  v4 = (unsigned __int8)body->m_motion.m_type.m_storage;
  v5 = collisionFilterUpdateMode;
  v6 = initialActivationState;
  v7 = newState;
  if ( v4 != newState )
  {
    if ( v4 == 5 )
    {
      hkpLinkedCollidable::sortEntries(&body->m_collidable);
      hkpEntity::sortConstraintsSlavesDeterministically(entity);
      body = (hkpRigidBody *)entity;
    }
    v8 = (unsigned int)(v7 - 4) > 1;
    v9 = (unsigned int)(v4 - 4) > 1;
    if ( (unsigned int)(v7 - 4) <= 1 || v9 || body->m_motion.m_savedMotion )
    {
      hkReferencedObject::addReference((hkReferencedObject *)&body->vfptr);
      v10 = entity->m_world;
      if ( v10 && (v4 == 5) != (v7 == 5) )
      {
        *(_WORD *)&v10->m_blockExecutingPendingOperations.m_bool = 1;
        removedConstraints.m_data = (hkpConstraintInstance **)&v26;
        agentsRemoved.m_bytesUsedInLastSector = 960;
        agentsRemoved.m_sectors.m_storage[0] = (hkpAgentNnSector *)&appendee.m_sectors;
        agentsRemoved.m_sectors.m_data = agentsRemoved.m_sectors.m_storage;
        removedConstraints.m_size = 0;
        *(_DWORD *)&appendee.m_bytesUsedInLastSector = 0;
        agentsRemoved.m_sectors.m_size = 0;
        appendee.m_sectors.m_size = 0;
        removedConstraints.m_capacityAndFlags = -2147483632;
        appendee.m_sectors.m_data = appendee.m_sectors.m_storage;
        *(_DWORD *)(&appendee.m_padding + 1) = -2147483632;
        agentsRemoved.m_sectors.m_capacityAndFlags = -2147483647;
        agentsRemoved.m_nnTrackType.m_storage = 2;
        appendee.m_sectors.m_capacityAndFlags = -2147483647;
        appendee.m_nnTrackType.m_storage = 1;
        hkpWorldOperationUtil::removeAttachedConstraints(entity, &removedConstraints);
        if ( v7 == 5 )
          hkpWorldOperationUtil::removeAttachedActionsFromDynamicIsland(
            v10,
            entity,
            (hkArray<hkpAction *,hkContainerHeapAllocator> *)agentsRemoved.m_sectors.m_storage);
        else
          hkpWorldOperationUtil::removeAttachedActionsFromFixedIsland(
            v10,
            entity,
            (hkArray<hkpAction *,hkContainerHeapAllocator> *)agentsRemoved.m_sectors.m_storage);
        hkpWorldOperationUtil::removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(
          &entity->m_simulationIsland->m_narrowphaseAgentTrack,
          entity,
          &agentsRemoved,
          v7);
        hkpWorldOperationUtil::removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(
          &entity->m_simulationIsland->m_midphaseAgentTrack,
          entity,
          &appendee,
          v7);
        if ( v4 != 5 )
        {
          v11 = entity->m_simulationIsland;
          if ( v11->m_entities.m_size > 2 )
          {
            *((_BYTE *)v11 + 49) &= 0xFDu;
            *((_BYTE *)v11 + 49) |= 1u;
          }
        }
        hkpWorldOperationUtil::removeEntitySI(v10, entity);
        hkpWorldOperationUtil::replaceMotionObject((hkpRigidBody *)entity, v7, (hkBool)v8, (hkBool)v9, v10);
        hkpWorldOperationUtil::addEntitySI(v10, entity, v6);
        hkpWorldOperationUtil::addActionsToEntitysIsland(
          v10,
          entity,
          (hkArray<hkpAction *,hkContainerHeapAllocator> *)agentsRemoved.m_sectors.m_storage);
        v10->m_criticalOperationsAllowed.m_bool = 1;
        entries.m_data = 0i64;
        entries.m_size = 0;
        entries.m_capacityAndFlags = 2147483648;
        v12 = 0;
        if ( removedConstraints.m_size > 0 )
        {
          v13 = 0i64;
          do
          {
            v14 = removedConstraints.m_data[v13];
            hkpWorldOperationUtil::addConstraintImmediately(v10, removedConstraints.m_data[v13], 0);
            hkReferencedObject::removeReference((hkReferencedObject *)&v14->vfptr);
            ++v12;
            ++v13;
          }
          while ( v12 < removedConstraints.m_size );
        }
        if ( v7 == 5
          || (hkpLinkedCollidable::getCollisionEntriesSorted(&entity->m_collidable, &entries),
              v15 = entries.m_size,
              v16 = 0,
              entries.m_size <= 0) )
        {
          v17 = entity;
        }
        else
        {
          v17 = entity;
          v18 = 0i64;
          do
          {
            v19 = (hkpEntity *)((char *)entries.m_data[v18].m_partner + entries.m_data[v18].m_partner->m_ownerOffset);
            if ( v17->m_motion.m_type.m_storage != 5
              && v19->m_motion.m_type.m_storage != 5
              && v17->m_simulationIsland != v19->m_simulationIsland )
            {
              hkpWorldOperationUtil::mergeIslands(v17->m_world, v17, v19);
              v17 = entity;
              v15 = entries.m_size;
            }
            ++v16;
            ++v18;
          }
          while ( v16 < v15 );
        }
        hkAgentNnMachine_AppendTrack(&v17->m_simulationIsland->m_narrowphaseAgentTrack, &agentsRemoved);
        hkAgentNnMachine_AppendTrack(&entity->m_simulationIsland->m_midphaseAgentTrack, &appendee);
        if ( v7 == 5 )
        {
          hkSweptTransformUtil::freezeMotionState(
            v10->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage,
            &entity->m_motion.m_motionState);
          v20 = v10->m_simulation;
          ++v10->m_criticalOperationsLockCount;
          LODWORD(world) = 7;
          ((void (__fastcall *)(hkpSimulation *, hkpEntity **, signed __int64, hkpWorld *, hkpWorld *))v20->vfptr[6].__vecDelDtor)(
            v20,
            &entity,
            1i64,
            v10,
            world);
          hkpSimulation::collideEntitiesBroadPhaseDiscrete(&entity, 1, v10);
          hkpWorldCallbackUtil::fireInactiveEntityMoved(entity->m_world, entity);
          --v10->m_criticalOperationsLockCount;
        }
        hkpWorld::updateCollisionFilterOnEntity(v10, entity, v5, HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
        v10->m_blockExecutingPendingOperations.m_bool = 0;
        if ( !v10->m_criticalOperationsLockCount )
        {
          if ( v10->m_pendingOperationsCount )
            hkpWorld::internal_executePendingOperations(v10);
          if ( v10->m_pendingOperationQueueCount == 1 && v10->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(v10);
        }
        entries.m_size = 0;
        if ( entries.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            entries.m_data,
            16 * entries.m_capacityAndFlags);
        entries.m_data = 0i64;
        entries.m_capacityAndFlags = 2147483648;
        appendee.m_sectors.m_size = 0;
        if ( appendee.m_sectors.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            appendee.m_sectors.m_data,
            8 * appendee.m_sectors.m_capacityAndFlags);
        appendee.m_sectors.m_data = 0i64;
        appendee.m_sectors.m_capacityAndFlags = 2147483648;
        agentsRemoved.m_sectors.m_size = 0;
        if ( agentsRemoved.m_sectors.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            agentsRemoved.m_sectors.m_data,
            8 * agentsRemoved.m_sectors.m_capacityAndFlags);
        agentsRemoved.m_sectors.m_data = 0i64;
        agentsRemoved.m_sectors.m_capacityAndFlags = 2147483648;
        *(_DWORD *)&appendee.m_bytesUsedInLastSector = 0;
        if ( *(_DWORD *)(&appendee.m_padding + 1) >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            agentsRemoved.m_sectors.m_storage[0],
            8 * *(_DWORD *)(&appendee.m_padding + 1));
        agentsRemoved.m_sectors.m_storage[0] = 0i64;
        *(_DWORD *)(&appendee.m_padding + 1) = 2147483648;
        removedConstraints.m_size = 0;
        if ( removedConstraints.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            removedConstraints.m_data,
            8 * removedConstraints.m_capacityAndFlags);
      }
      else
      {
        hkpWorldOperationUtil::replaceMotionObject((hkpRigidBody *)entity, v7, (hkBool)v8, (hkBool)v9, entity->m_world);
        if ( v10 )
          hkpWorld::updateCollisionFilterOnEntity(
            v10,
            entity,
            v5,
            HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
      }
      hkReferencedObject::removeReference((hkReferencedObject *)&entity->vfptr);
    }
  }
}

// File Line: 1757
// RVA: 0xD81720
void __fastcall hkpWorldOperationUtil::removeAttachedConstraints(hkpEntity *entity, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *removedConstraints)
{
  hkpWorld *v2; // r15
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v3; // rbx
  int v4; // eax
  hkpEntity *v5; // r14
  __int64 v6; // rdi
  signed __int64 v7; // rsi
  hkpConstraintInstance *v8; // rbp
  int v9; // eax
  __int64 i; // rdi
  hkpConstraintInstance *v11; // rsi

  v2 = entity->m_world;
  v3 = removedConstraints;
  v4 = entity->m_constraintsMaster.m_size - 1;
  v5 = entity;
  v6 = v4;
  if ( v4 >= 0 )
  {
    v7 = (signed __int64)v4 << 6;
    do
    {
      v8 = *(hkpConstraintInstance **)((char *)&v5->m_constraintsMaster.m_data->m_constraint + v7);
      hkReferencedObject::addReference((hkReferencedObject *)&v8->vfptr);
      hkpWorldOperationUtil::removeConstraintImmediately(v2, v8, 0);
      if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
      v7 -= 64i64;
      v3->m_data[v3->m_size++] = v8;
      --v6;
    }
    while ( v6 >= 0 );
  }
  v9 = v5->m_constraintsSlave.m_size - 1;
  for ( i = v9; i >= 0; --i )
  {
    v11 = v5->m_constraintsSlave.m_data[i];
    hkReferencedObject::addReference((hkReferencedObject *)&v11->vfptr);
    hkpWorldOperationUtil::removeConstraintImmediately(v2, v11, 0);
    if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
    v3->m_data[v3->m_size++] = v11;
  }
}

// File Line: 1790
// RVA: 0xD81610
void __fastcall hkpWorldOperationUtil::removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(hkpAgentNnTrack *trackToScan, hkpEntity *entity, hkpAgentNnTrack *agentsRemoved, hkpMotion::MotionType newMotionType)
{
  hkpAgentNnTrack *v4; // r15
  hkpEntity *v5; // r13
  int v6; // ebp
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v7; // r12
  __int64 v8; // r14
  hkpLinkedCollidable::CollisionEntry *v9; // rsi
  hkpAgentNnEntry *v10; // rdi
  hkpSimulationIsland **v11; // rbx
  hkpAgentNnTrack *v12; // rcx
  hkpAgentNnEntry *v13; // rdx
  hkpSimulationIsland *v14; // rcx
  hkpAgentNnTrack *v15; // [rsp+70h] [rbp+18h]
  hkpMotion::MotionType v16; // [rsp+78h] [rbp+20h]

  v16 = newMotionType;
  v15 = agentsRemoved;
  v4 = trackToScan;
  v5 = entity;
  v6 = 0;
  v7 = hkpLinkedCollidable::getCollisionEntriesDeterministicUnchecked(&entity->m_collidable);
  if ( v7->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v7->m_data;
      v10 = v7->m_data[v8].m_agentEntry;
      if ( v10->m_nnTrackType.m_storage == v4->m_nnTrackType.m_storage )
      {
        v11 = (hkpSimulationIsland **)((char *)v9[v8].m_partner + v9[v8].m_partner->m_ownerOffset);
        if ( *((_BYTE *)v11 + 352) == 5 )
        {
          v12 = v15;
          v13 = v7->m_data[v8].m_agentEntry;
        }
        else
        {
          if ( v16 != 5
            || hkpWorldAgentUtil::getIslandFromAgentEntry(v10, v5->m_simulationIsland, v11[37]) != v5->m_simulationIsland )
          {
            goto LABEL_12;
          }
          v13 = v9[v8].m_agentEntry;
          v14 = v11[37];
          if ( v13->m_nnTrackType.m_storage == 2 )
            v12 = &v14->m_narrowphaseAgentTrack;
          else
            v12 = &v14->m_midphaseAgentTrack;
        }
        hkAgentNnMachine_CopyAndRelinkAgentEntry(v12, v13);
        hkAgentNnMachine_InternalDeallocateEntry(v4, v10);
      }
LABEL_12:
      ++v6;
      ++v8;
    }
    while ( v6 < v7->m_size );
  }
}

// File Line: 1844
// RVA: 0xD825D0
hkBool *__fastcall worldOperationUtil_less_hkSimulationIslandPtr(hkBool *result, hkpSimulationIsland *a, hkpSimulationIsland *b)
{
  hkBool *v3; // rax

  if ( b )
  {
    if ( a )
      result->m_bool = (*a->m_entities.m_data)->m_uid < (*b->m_entities.m_data)->m_uid;
    else
      result->m_bool = 1;
    v3 = result;
  }
  else
  {
    result->m_bool = 0;
    v3 = result;
  }
  return v3;
}

// File Line: 1852
// RVA: 0xD81840
void __fastcall hkpWorldOperationUtil::cleanupDirtyIslands(hkpWorld *world)
{
  int v1; // er8
  hkpWorld *v2; // rsi
  int i; // edx
  hkpSimulationIsland *v4; // r8
  __int64 v5; // rdx
  hkpSimulationIsland *v6; // rdi
  bool v7; // zf
  int v8; // er8
  signed int v9; // ebp
  signed __int64 v10; // r9
  signed int v11; // eax
  signed __int64 v12; // rdx
  hkpAction **v13; // rcx
  signed __int64 v14; // r9
  signed __int64 v15; // rcx
  hkpAction **v16; // rdx
  hkpAction *v17; // r8
  int v18; // eax
  int v19; // eax
  int v20; // er9
  unsigned __int8 v21; // dl
  char v22; // cl
  int v23; // er8
  hkpSimulationIsland *j; // rax
  hkpEntity *v25; // rbx
  int v26; // er8
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = world->m_dirtySimulationIslands.m_size;
  v2 = world;
  if ( v1 )
  {
    if ( v1 > 1 )
      hkAlgorithm::quickSortRecursive<hkFreeList::Element *,hkBool (*)(hkFreeList::Element const *,hkFreeList::Element const *)>(
        (hkpRigidBody **)world->m_dirtySimulationIslands.m_data,
        0,
        v1 - 1,
        (hkBool *(__fastcall *)(hkBool *, hkpRigidBody *, hkpRigidBody *))worldOperationUtil_less_hkSimulationIslandPtr);
    for ( i = 0; i < v2->m_dirtySimulationIslands.m_size; ++i )
    {
      v4 = v2->m_dirtySimulationIslands.m_data[i];
      if ( v4 )
        v4->m_dirtyListIndex = i;
    }
    while ( v2->m_dirtySimulationIslands.m_size )
    {
      v5 = v2->m_dirtySimulationIslands.m_size;
      v6 = v2->m_dirtySimulationIslands.m_data[v5 - 1];
      v2->m_dirtySimulationIslands.m_size = v5 - 1;
      if ( v6 )
      {
        v7 = (*((_BYTE *)v6 + 49) & 0x30) == 0;
        v6->m_dirtyListIndex = -1;
        if ( !v7 )
        {
          v8 = v6->m_actions.m_size;
          v9 = -1;
          v10 = -1i64;
          v11 = 0;
          v12 = 0i64;
          if ( v8 > 0 )
          {
            v13 = v6->m_actions.m_data;
            while ( *v13 )
            {
              ++v11;
              ++v12;
              ++v13;
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
              v16 = v6->m_actions.m_data;
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
            while ( v11 < v6->m_actions.m_size );
          }
          if ( v9 != -1 )
          {
            v18 = v6->m_actions.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v18 >= v9 )
            {
              result.m_enum = 0;
            }
            else
            {
              v19 = 2 * v18;
              v20 = v9;
              if ( v9 < v19 )
                v20 = v19;
              hkArrayUtil::_reserve(
                &result,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v6->m_actions,
                v20,
                8);
            }
            v6->m_actions.m_size = v9;
          }
          *((_BYTE *)v6 + 49) &= 0xCFu;
        }
        v21 = *((_BYTE *)v6 + 50);
        v22 = (v21 >> 2) & 3;
        if ( v22 == (v21 & 3) )
        {
          if ( v21 & 0x30 && v22 )
          {
            *((_BYTE *)v6 + 50) = v21 & 0xCF;
            v23 = v6->m_numConstraints;
            if ( v6->m_entities.m_size > v23 )
              v23 = v6->m_entities.m_size;
            for ( j = findSmallSparseActiveIsland(v2, &v2->m_activeSimulationIslands, v23, v6);
                  j;
                  j = findSmallSparseActiveIsland(v2, &v2->m_activeSimulationIslands, v26, v25->m_simulationIsland) )
            {
              v25 = *v6->m_entities.m_data;
              hkpWorldOperationUtil::internalMergeTwoIslands(v2, v6, j);
              v6 = v25->m_simulationIsland;
              v26 = v6->m_numConstraints;
              if ( v6->m_entities.m_size > v26 )
                v26 = v6->m_entities.m_size;
            }
          }
        }
        else if ( v22 )
        {
          hkpWorldOperationUtil::internalActivateIsland(v2, v6, (hkBool)1);
        }
        else
        {
          hkpWorldOperationUtil::internalDeactivateIsland(v2, v6);
        }
      }
    }
    hkpWorld::checkDeterminism(v2);
  }
}

// File Line: 1969
// RVA: 0xD7E6C0
void __fastcall hkpWorldOperationUtil::internalActivateIsland(hkpWorld *world, hkpSimulationIsland *island, hkBool allowIslandMerges)
{
  hkpSimulationIsland *v3; // rdi
  hkpWorld *v4; // rsi
  __int16 v5; // ax
  int v6; // ebp
  __int64 v7; // r15
  hkpEntity *v8; // rbx
  signed int v9; // er10
  __int16 v10; // dx
  __int16 v11; // r8
  unsigned __int16 v12; // r8
  hkpEntity *v13; // rbx
  int v14; // er8
  int v15; // ebp
  hkpSimulationIsland *v16; // rax
  hkpEntity *v17; // rbx
  int v18; // er8
  __int64 v19; // rcx
  hkpSimulationIsland *v20; // rdx
  hkSimdFloat32 startTime; // [rsp+20h] [rbp-38h]
  char v22; // [rsp+70h] [rbp+18h]

  v22 = allowIslandMerges.m_bool;
  v3 = island;
  v4 = world;
  world->m_inactiveSimulationIslands.m_data[island->m_storageIndex] = world->m_inactiveSimulationIslands.m_data[world->m_inactiveSimulationIslands.m_size - 1];
  world->m_inactiveSimulationIslands.m_data[island->m_storageIndex]->m_storageIndex = island->m_storageIndex;
  --world->m_inactiveSimulationIslands.m_size;
  if ( world->m_activeSimulationIslands.m_size == (world->m_activeSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &world->m_activeSimulationIslands,
      8);
  v4->m_activeSimulationIslands.m_data[v4->m_activeSimulationIslands.m_size++] = v3;
  v5 = v4->m_activeSimulationIslands.m_size;
  startTime.m_real = 0i64;
  *((_BYTE *)v3 + 50) &= 0xFDu;
  *((_BYTE *)v3 + 50) |= 1u;
  v3->m_storageIndex = v5 - 1;
  *(_QWORD *)&v3->m_timeSinceLastHighFrequencyCheck = 0i64;
  v6 = 0;
  if ( v3->m_entities.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v3->m_entities.m_data[v7];
      hkSweptTransformUtil::setTimeInformation(&startTime, &startTime, &v8->m_motion.m_motionState);
      v9 = (unsigned __int8)v8->m_motion.m_deactivationIntegrateCounter;
      *(_DWORD *)v8->m_motion.m_deactivationNumInactiveFrames = 0;
      v10 = (unsigned __int8)v4->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
      v11 = (unsigned __int8)v4->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
      if ( (unsigned __int8)(v4->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(v9 & 3) )
        v11 = ~v11;
      v12 = v11 << 14;
      if ( (unsigned __int8)v4->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < v9 )
        v10 = ~v10;
      ++v6;
      v8->m_motion.m_deactivationNumInactiveFrames[0] = v12;
      v8->m_motion.m_deactivationNumInactiveFrames[1] = v10 << 14;
      ++v7;
    }
    while ( v6 < v3->m_entities.m_size );
  }
  hkpWorldAgentUtil::warpTime(
    v3,
    v3->m_timeOfDeactivation,
    v4->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage,
    (hkpCollisionInput *)&v4->m_collisionInput->m_dispatcher);
  v13 = *v3->m_entities.m_data;
  hkReferencedObject::addReference((hkReferencedObject *)&v13->vfptr);
  hkpWorldCallbackUtil::fireIslandActivated(v4, v3);
  if ( v13->m_simulationIsland == v3 )
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&v13->vfptr);
    if ( !v22 )
      goto LABEL_25;
    v14 = v3->m_numConstraints + 3;
    v15 = 0;
    if ( v3->m_entities.m_size + 1 > v14 )
      v14 = v3->m_entities.m_size + 1;
    v16 = findSmallSparseActiveIsland(v4, &v4->m_activeSimulationIslands, v14, v3);
    if ( !v16 )
      goto LABEL_25;
    do
    {
      v17 = *v3->m_entities.m_data;
      hkpWorldOperationUtil::internalMergeTwoIslands(v4, v16, v3);
      v3 = v17->m_simulationIsland;
      ++v15;
      v18 = v3->m_numConstraints + 3;
      if ( v3->m_entities.m_size + 1 > v18 )
        v18 = v3->m_entities.m_size + 1;
      v16 = findSmallSparseActiveIsland(v4, &v4->m_activeSimulationIslands, v18, v17->m_simulationIsland);
    }
    while ( v16 );
    if ( !v15 )
    {
LABEL_25:
      v19 = v3->m_storageIndex;
      if ( v3->m_storageIndex )
      {
        v20 = *v4->m_activeSimulationIslands.m_data;
        if ( v3->m_entities.m_size > v20->m_entities.m_size )
        {
          v3->m_storageIndex = 0;
          v20->m_storageIndex = v19;
          *v4->m_activeSimulationIslands.m_data = v3;
          v4->m_activeSimulationIslands.m_data[v19] = v20;
        }
      }
    }
  }
  else
  {
    hkReferencedObject::removeReference((hkReferencedObject *)&v13->vfptr);
  }
}

// File Line: 2071
// RVA: 0xD7E930
void __fastcall hkpWorldOperationUtil::internalDeactivateIsland(hkpWorld *world, hkpSimulationIsland *island)
{
  hkpSimulationIsland *v2; // rdi
  hkpWorld *v3; // rbp
  int v4; // esi
  __int16 v5; // ax
  __int64 v6; // r14
  hkpEntity *v7; // rbx

  v2 = island;
  v3 = world;
  if ( hkRigidMotionUtilCanDeactivateFinal(
         &world->m_dynamicsStepInfo.m_stepInfo,
         (hkpMotion *const *)island->m_entities.m_data,
         island->m_entities.m_size,
         336) )
  {
    if ( v3->m_inactiveSimulationIslands.m_size == (v3->m_inactiveSimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v3->m_inactiveSimulationIslands,
        8);
    v4 = 0;
    v3->m_inactiveSimulationIslands.m_data[v3->m_inactiveSimulationIslands.m_size++] = v2;
    v3->m_activeSimulationIslands.m_data[v2->m_storageIndex] = v3->m_activeSimulationIslands.m_data[v3->m_activeSimulationIslands.m_size - 1];
    v3->m_activeSimulationIslands.m_data[v2->m_storageIndex]->m_storageIndex = v2->m_storageIndex;
    --v3->m_activeSimulationIslands.m_size;
    v5 = v3->m_inactiveSimulationIslands.m_size;
    *((_BYTE *)v2 + 50) &= 0xFCu;
    v2->m_storageIndex = v5 - 1;
    v2->m_timeOfDeactivation = v3->m_dynamicsStepInfo.m_stepInfo.m_startTime.m_storage;
    if ( v2->m_entities.m_size > 0 )
    {
      v6 = 0i64;
      do
      {
        v7 = v2->m_entities.m_data[v6];
        hkSweptTransformUtil::freezeMotionState(v2->m_timeOfDeactivation, &v7->m_motion.m_motionState);
        v7->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&aabbOut);
        ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v7->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v7->m_motion,
          &aabbOut);
        ++v4;
        ++v6;
      }
      while ( v4 < v2->m_entities.m_size );
    }
    hkpWorldCallbackUtil::fireIslandDeactivated(v3, v2);
  }
  else
  {
    *((_BYTE *)v2 + 50) &= 0xF7u;
    *((_BYTE *)v2 + 50) |= 4u;
  }
}

// File Line: 2126
// RVA: 0xD81AA0
void __fastcall hkpWorldOperationUtil::markIslandInactive(hkpWorld *world, hkpSimulationIsland *island)
{
  hkpWorld *v2; // rdi
  hkpSimulationIsland *v3; // rsi

  *((_BYTE *)island + 50) &= 0xF3u;
  v2 = world;
  v3 = island;
  EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
  if ( v3->m_dirtyListIndex == -1 )
  {
    v3->m_dirtyListIndex = v2->m_dirtySimulationIslands.m_size;
    if ( v2->m_dirtySimulationIslands.m_size == (v2->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_dirtySimulationIslands,
        8);
    v2->m_dirtySimulationIslands.m_data[v2->m_dirtySimulationIslands.m_size++] = v3;
  }
  LeaveCriticalSection(&v2->m_islandDirtyListCriticalSection->m_section);
}

// File Line: 2133
// RVA: 0xD81B30
void __fastcall hkpWorldOperationUtil::markIslandInactiveMt(hkpWorld *world, hkpSimulationIsland *island)
{
  hkpWorld *v2; // rdi
  hkpSimulationIsland *v3; // rsi

  *((_BYTE *)island + 50) &= 0xF3u;
  v2 = world;
  v3 = island;
  EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
  if ( v3->m_dirtyListIndex == -1 )
  {
    v3->m_dirtyListIndex = v2->m_dirtySimulationIslands.m_size;
    if ( v2->m_dirtySimulationIslands.m_size == (v2->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_dirtySimulationIslands,
        8);
    v2->m_dirtySimulationIslands.m_data[v2->m_dirtySimulationIslands.m_size++] = v3;
  }
  LeaveCriticalSection(&v2->m_islandDirtyListCriticalSection->m_section);
}

// File Line: 2149
// RVA: 0xD81BC0
void __fastcall hkpWorldOperationUtil::markIslandActive(hkpWorld *world, hkpSimulationIsland *island)
{
  char v2; // al
  hkpSimulationIsland *v3; // rbx
  hkpWorld *v4; // rsi

  v2 = *((_BYTE *)island + 50);
  v3 = island;
  v4 = world;
  if ( !(v2 & 0xC) && v2 & 3 )
    *((_BYTE *)island + 50) = v2 & 0xDF | 0x10;
  *((_BYTE *)island + 50) &= 0xF7u;
  *((_BYTE *)island + 50) |= 4u;
  EnterCriticalSection(&world->m_islandDirtyListCriticalSection->m_section);
  if ( v3->m_dirtyListIndex == -1 )
  {
    v3->m_dirtyListIndex = v4->m_dirtySimulationIslands.m_size;
    if ( v4->m_dirtySimulationIslands.m_size == (v4->m_dirtySimulationIslands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_dirtySimulationIslands,
        8);
    v4->m_dirtySimulationIslands.m_data[v4->m_dirtySimulationIslands.m_size++] = v3;
  }
  LeaveCriticalSection(&v4->m_islandDirtyListCriticalSection->m_section);
}

// File Line: 2161
// RVA: 0xD81C70
void __fastcall hkpWorldOperationUtil::removeIslandFromDirtyList(hkpWorld *world, hkpSimulationIsland *island)
{
  unsigned __int16 v2; // ax

  v2 = island->m_dirtyListIndex;
  if ( v2 != -1 )
  {
    world->m_dirtySimulationIslands.m_data[v2] = 0i64;
    island->m_dirtyListIndex = -1;
  }
}

// File Line: 2175
// RVA: 0xD81080
void __usercall hkpWorldOperationUtil::replaceMotionObject(hkpRigidBody *body@<rcx>, hkpMotion::MotionType newState@<edx>, hkBool newStateNeedsInertia@<r8b>, hkBool oldStateNeedsInertia@<r9b>, __int64 a5@<rbx>, hkpWorld *a6@<rsi>, hkpWorld *world)
{
  hkpRigidBody *v7; // rdi
  hkpMotion::MotionType v8; // er13
  hkpWorld *v9; // r15
  hkpMaxSizeMotion *v10; // rsi
  hkpMaxSizeMotion *v11; // rdx
  signed int v12; // eax
  __int128 v13; // xmm0
  hkpMaxSizeMotion *v14; // rdx
  signed __int64 v15; // r9
  char *v16; // rcx
  hkBaseObjectVtbl *v17; // rax
  unsigned __int16 v18; // ax
  float maxLinearVelocity; // xmm6_4
  float maxAngularVelocity; // xmm7_4
  unsigned __int16 v21; // ax
  float v22; // xmm0_4
  hkpFixedRigidMotion *v23; // rcx
  hkpMaxSizeMotion *v24; // r8
  signed __int64 v25; // r9
  char *v26; // rdx
  hkBaseObjectVtbl *v27; // rax
  hkpMotion *v28; // rax
  hkpMotion *v29; // rbx
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128i v32; // xmm3
  hkpMotion *v33; // rax
  _QWORD **v34; // rax
  hkpMotion *v35; // rax
  hkpMaxSizeMotion *v36; // rsi
  unsigned __int16 v37; // r8
  signed int v38; // eax
  hkpMotion *v39; // rcx
  __int128 v40; // xmm0
  __int16 v41; // dx
  __int16 v42; // r8
  __int16 v43; // r8
  __m128i v44; // [rsp+148h] [rbp-98h]
  hkSimdFloat32 time; // [rsp+158h] [rbp-88h]
  hkpMotion inertiaLocal; // [rsp+168h] [rbp-78h]
  __int64 v47; // [rsp+328h] [rbp+148h]
  hkpWorld *v48; // [rsp+330h] [rbp+150h]
  float v49; // [rsp+330h] [rbp+150h]
  float v50; // [rsp+330h] [rbp+150h]

  v47 = a5;
  v48 = a6;
  v7 = body;
  v8 = newState;
  if ( newStateNeedsInertia.m_bool )
  {
    v9 = a6;
    if ( !oldStateNeedsInertia.m_bool )
    {
      v10 = body->m_motion.m_savedMotion;
      body->m_motion.vfptr[14].__vecDelDtor((hkBaseObject *)&body->m_motion, (unsigned int)v10);
      *(_DWORD *)v10->m_deactivationNumInactiveFrames = 0;
      v7->m_collidable.m_broadPhaseHandle.m_objectQualityType = v7->m_motion.m_savedQualityTypeIndex;
      v11 = v10;
      v12 = 20;
      do
      {
        v13 = *(_OWORD *)&v11->vfptr;
        --v12;
        v11 = (hkpMaxSizeMotion *)((char *)v11 + 16);
        *(_OWORD *)((char *)&v11[1].vfptr + (char *)v7 - (char *)v10) = v13;
      }
      while ( v12 > 0 );
      hkString::memSet(&v7->m_contactListeners, 0, 0);
      hkReferencedObject::removeReference((hkReferencedObject *)&v10->vfptr);
      hkpEntity::setCachedShapeData((hkpEntity *)&v7->vfptr, v48, v7->m_collidable.m_shape);
    }
    if ( (unsigned __int8)v7->m_motion.m_type.m_storage != v8 && v8 != 1 )
    {
      hkpMotion::hkpMotion(&inertiaLocal);
      inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u64[0] = 0i64;
      inertiaLocal.vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
      v14 = &v7->m_motion;
      v15 = 10i64;
      v16 = &v44.m128i_i8[8];
      do
      {
        v17 = v14->vfptr;
        v16 += 32;
        v14 = (hkpMaxSizeMotion *)((char *)v14 + 32);
        *((_QWORD *)v16 - 4) = v17;
        *((_QWORD *)v16 - 3) = v14[-1].m_savedMotion;
        *((_QWORD *)v16 - 2) = *(_QWORD *)&v14[-1].m_savedQualityTypeIndex;
        *((_QWORD *)v16 - 1) = *(_QWORD *)((char *)&v14[-1].m_gravityFactor + 6);
        --v15;
      }
      while ( v15 );
      ((void (__fastcall *)(hkpMaxSizeMotion *, hkpMaxSizeMotion **))v7->m_motion.vfptr[3].__first_virtual_table_function__)(
        &v7->m_motion,
        &inertiaLocal.m_savedMotion);
      v18 = hkUFloat8::getEncodedFloat(inertiaLocal.m_motionState.m_deltaAngle.m_quad.m128_i8[3]);
      maxLinearVelocity = 0.0;
      if ( v18 )
        LODWORD(maxAngularVelocity) = (v18 + 243712) << 12;
      else
        maxAngularVelocity = 0.0;
      v21 = hkUFloat8::getEncodedFloat(inertiaLocal.m_motionState.m_deltaAngle.m_quad.m128_i8[2]);
      if ( v21 )
        LODWORD(maxLinearVelocity) = (v21 + 243712) << 12;
      v22 = hkpMotion::getMass(&inertiaLocal);
      hkpRigidBody::createDynamicRigidMotion(
        v8,
        (hkVector4f *)((char *)&inertiaLocal.m_motionState.m_transform.m_rotation.m_col1 + 8),
        (hkQuaternionf *)&inertiaLocal.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_u16[4],
        v22,
        (hkMatrix3f *)&inertiaLocal.m_savedMotion,
        (hkVector4f *)((char *)&inertiaLocal.m_motionState.m_sweptTransform.m_rotation0.m_vec + 8),
        maxLinearVelocity,
        maxAngularVelocity,
        &v7->m_motion);
      hkpMotion::getMotionStateAndVelocitiesAndDeactivationType(&inertiaLocal, (hkpMotion *)&v7->m_motion.vfptr);
      v7->m_motion.m_motionState.m_linearDamping.m_value = COERCE_UNSIGNED_INT(
                                                             COERCE_FLOAT(inertiaLocal.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_i16[6] << 16)
                                                           * 1.0039062) >> 16;
      v49 = COERCE_FLOAT(inertiaLocal.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_i16[7] << 16)
          * 1.0039062;
      v7->m_motion.m_motionState.m_angularDamping.m_value = HIWORD(v49);
      hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion((hkpKeyframedRigidMotion *)&inertiaLocal);
    }
  }
  else
  {
    hkpMotion::hkpMotion(&inertiaLocal);
    v23 = (hkpFixedRigidMotion *)&v7->m_motion;
    inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u64[0] = 0i64;
    v24 = &v7->m_motion;
    v25 = 10i64;
    v26 = &v44.m128i_i8[8];
    inertiaLocal.vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
    do
    {
      v27 = v24->vfptr;
      v26 += 32;
      v24 = (hkpMaxSizeMotion *)((char *)v24 + 32);
      *((_QWORD *)v26 - 4) = v27;
      *((_QWORD *)v26 - 3) = v24[-1].m_savedMotion;
      *((_QWORD *)v26 - 2) = *(_QWORD *)&v24[-1].m_savedQualityTypeIndex;
      *((_QWORD *)v26 - 1) = *(_QWORD *)((char *)&v24[-1].m_gravityFactor + 6);
      --v25;
    }
    while ( v25 );
    v9 = a6;
    if ( v8 == 5 )
    {
      if ( v7 == (hkpRigidBody *)-336i64 )
      {
        v29 = 0i64;
      }
      else
      {
        hkpFixedRigidMotion::hkpFixedRigidMotion(
          v23,
          &v7->m_motion.m_motionState.m_transform.m_translation,
          &v7->m_motion.m_motionState.m_sweptTransform.m_rotation1);
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
        v32 = (__m128i)_mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v30)), v31),
                         _mm_shuffle_ps(
                           *(__m128 *)((char *)&inertiaLocal.m_motionState.m_transform.m_rotation.m_col2.m_quad + 8),
                           *(__m128 *)((char *)&inertiaLocal.m_motionState.m_transform.m_rotation.m_col2.m_quad + 8),
                           255));
        if ( a6 )
        {
          v50 = hkpWorld::getCurrentTime(a6);
          v44 = (__m128i)_mm_shuffle_ps((__m128)LODWORD(v50), (__m128)LODWORD(v50), 0);
        }
        else
        {
          _mm_store_si128(&v44, v32);
        }
        _mm_store_si128((__m128i *)&time, v44);
        hkSweptTransformUtil::freezeMotionState(&time, &v29->m_motionState);
      }
    }
    else
    {
      if ( v7 == (hkpRigidBody *)-336i64 )
      {
        v29 = 0i64;
      }
      else
      {
        hkpKeyframedRigidMotion::hkpKeyframedRigidMotion(
          (hkpKeyframedRigidMotion *)&v23->vfptr,
          &v7->m_motion.m_motionState.m_transform.m_translation,
          &v7->m_motion.m_motionState.m_sweptTransform.m_rotation1);
        v29 = v33;
      }
      hkpMotion::getMotionStateAndVelocitiesAndDeactivationType(&inertiaLocal, v29);
    }
    if ( (_BYTE)v47 )
    {
      v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v35 = (hkpMotion *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v34[11] + 8i64))(v34[11], 320i64);
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
      v37 = v36->m_memSizeAndFlags;
      v38 = 20;
      v39 = &inertiaLocal;
      do
      {
        v40 = *(_OWORD *)&v39->vfptr;
        --v38;
        v39 = (hkpMotion *)((char *)v39 + 16);
        *(_OWORD *)((char *)v39 + (char *)v36 - (char *)&inertiaLocal - 16) = v40;
      }
      while ( v38 > 0 );
      v36->m_memSizeAndFlags = v37;
      v36->m_referenceCount = 1;
      v29->m_savedMotion = v36;
      v29->m_savedQualityTypeIndex = v7->m_collidable.m_broadPhaseHandle.m_objectQualityType;
      hkpEntity::setCachedShapeData((hkpEntity *)&v7->vfptr, v9, v7->m_collidable.m_shape);
    }
    else
    {
      v29->vfptr[15].__vecDelDtor(
        (hkBaseObject *)&v29->vfptr,
        inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u64[0]);
      v29->m_savedQualityTypeIndex = inertiaLocal.m_deactivationRefPosition[1].m_quad.m128_u16[4];
    }
    v7->m_solverData = 0;
    v7->m_collidable.m_broadPhaseHandle.m_objectQualityType = v8 != 5;
    hkpKeyframedRigidMotion::~hkpKeyframedRigidMotion((hkpKeyframedRigidMotion *)&inertiaLocal);
  }
  v7->m_collidable.m_motion = &v7->m_motion.m_motionState;
  if ( v9 )
  {
    v41 = (unsigned __int8)v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
    v42 = (unsigned __int8)v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
    if ( (unsigned __int8)(v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3) < (unsigned __int8)(v7->m_motion.m_deactivationIntegrateCounter & 3) )
      v42 = ~v42;
    v43 = v42 << 14;
    if ( (unsigned __int8)v9->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter < (signed int)(unsigned __int8)v7->m_motion.m_deactivationIntegrateCounter )
      v41 = ~v41;
    v7->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
    v7->m_motion.m_deactivationNumInactiveFrames[0] |= v43;
    v7->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
    v7->m_motion.m_deactivationNumInactiveFrames[1] |= v41 << 14;
  }
}

