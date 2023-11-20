// File Line: 34
// RVA: 0xD77090
void __fastcall hkpPhantom::removeNullOverlapListeners(hkpPhantom *this)
{
  hkpPhantom *v1; // r11
  int v2; // er10
  __int64 i; // r9
  hkpPhantomOverlapListener **v4; // rax
  signed __int64 v5; // rax
  int v6; // ecx
  __int64 v7; // rdx
  __int64 v8; // rcx

  v1 = this;
  v2 = this->m_overlapListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = v1->m_overlapListeners.m_data;
    if ( !v4[i] )
    {
      --v1->m_overlapListeners.m_size;
      v5 = (signed __int64)&v4[i];
      v6 = 8 * (v1->m_overlapListeners.m_size - v2);
      if ( v6 > 0 )
      {
        v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
        do
        {
          v8 = *(_QWORD *)(v5 + 8);
          v5 += 8i64;
          *(_QWORD *)(v5 - 8) = v8;
          --v7;
        }
        while ( v7 );
      }
    }
    --v2;
  }
}

// File Line: 45
// RVA: 0xD77110
void __fastcall hkpPhantom::removeNullPhantomListeners(hkpPhantom *this)
{
  hkpPhantom *v1; // r11
  int v2; // er10
  __int64 i; // r9
  hkpPhantomListener **v4; // rax
  signed __int64 v5; // rax
  int v6; // ecx
  __int64 v7; // rdx
  __int64 v8; // rcx

  v1 = this;
  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = v1->m_phantomListeners.m_data;
    if ( !v4[i] )
    {
      --v1->m_phantomListeners.m_size;
      v5 = (signed __int64)&v4[i];
      v6 = 8 * (v1->m_phantomListeners.m_size - v2);
      if ( v6 > 0 )
      {
        v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
        do
        {
          v8 = *(_QWORD *)(v5 + 8);
          v5 += 8i64;
          *(_QWORD *)(v5 - 8) = v8;
          --v7;
        }
        while ( v7 );
      }
    }
    --v2;
  }
}

// File Line: 56
// RVA: 0xD76A80
void __fastcall hkpPhantom::firePhantomDeleted(hkpPhantom *this)
{
  hkpPhantom *v1; // rdi
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v1 = this;
  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = v1->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomDeletedCallback(v4, v1);
  }
}

// File Line: 71
// RVA: 0xD769C0
void __fastcall hkpPhantom::firePhantomRemoved(hkpPhantom *this)
{
  hkpPhantom *v1; // rdi
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v1 = this;
  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = v1->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomRemovedCallback(v4, v1);
  }
  hkpPhantom::removeNullPhantomListeners(v1);
}

// File Line: 86
// RVA: 0xD76960
void __fastcall hkpPhantom::firePhantomAdded(hkpPhantom *this)
{
  hkpPhantom *v1; // rdi
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v1 = this;
  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = v1->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomAddedCallback(v4, v1);
  }
  hkpPhantom::removeNullPhantomListeners(v1);
}

// File Line: 100
// RVA: 0xD76A20
void __fastcall hkpPhantom::firePhantomShapeSet(hkpPhantom *this)
{
  hkpPhantom *v1; // rdi
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v1 = this;
  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = v1->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomShapeSetCallback(v4, v1);
  }
  hkpPhantom::removeNullPhantomListeners(v1);
}

// File Line: 114
// RVA: 0xD76AD0
void __fastcall hkpPhantom::updateBroadPhase(hkpPhantom *this, hkAabb *aabb)
{
  hkpPhantom *v2; // rbx
  hkpWorld *v3; // rcx
  hkAabb *v4; // rsi
  int v5; // edi
  LPVOID v6; // rax
  hkLifoAllocator *v7; // rcx
  hkpBroadPhaseHandlePair *v8; // rax
  int v9; // edx
  char *v10; // r8
  hkpWorld *v11; // rax
  int v12; // edi
  LPVOID v13; // rax
  hkLifoAllocator *v14; // rcx
  hkpBroadPhaseHandlePair *v15; // rax
  int v16; // edx
  char *v17; // r8
  hkpWorld *v18; // rax
  hkpBroadPhase *v19; // rcx
  hkpWorld *v20; // rcx
  hkpCollidableCollidableFilter *v21; // r9
  hkpCollidableCollidableFilter *v22; // r9
  hkpBroadPhase *v23; // rcx
  hkpWorld *v24; // rbx
  bool v25; // zf
  int v26; // eax
  char *v27; // rdi
  signed int v28; // ebx
  hkLifoAllocator *v29; // rax
  int v30; // er8
  int v31; // eax
  char *v32; // rdi
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // er8
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-19h]
  hkpPhantom *v37; // [rsp+38h] [rbp-11h]
  hkAabb *v38; // [rsp+40h] [rbp-9h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+48h] [rbp-1h]
  void *p; // [rsp+58h] [rbp+Fh]
  int v41; // [rsp+60h] [rbp+17h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+68h] [rbp+1Fh]
  void *v43; // [rsp+78h] [rbp+2Fh]
  int v44; // [rsp+80h] [rbp+37h]
  hkpTypedBroadPhaseHandle *v45; // [rsp+B0h] [rbp+67h]

  v2 = this;
  v3 = this->m_world;
  v4 = aabb;
  if ( v3 )
  {
    if ( v3->m_criticalOperationsLockCount + v3->m_criticalOperationsLockCountForPhantoms )
    {
      v38 = aabb;
      operation.m_type.m_storage = 18;
      v37 = v2;
      hkpWorld::queueOperation(v3, &operation);
    }
    else
    {
      ++v3->m_criticalOperationsLockCount;
      v5 = v2->m_world->m_broadPhaseUpdateSize;
      newPairs.m_data = 0i64;
      newPairs.m_size = 0;
      newPairs.m_capacityAndFlags = 2147483648;
      v44 = v5;
      if ( v5 )
      {
        v6 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v7 = (hkLifoAllocator *)v6;
        v8 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v6 + 3);
        v9 = (16 * v5 + 127) & 0xFFFFFF80;
        v10 = (char *)v8 + v9;
        if ( v9 > v7->m_slabSize || v10 > v7->m_end )
          v8 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v7, v9);
        else
          v7->m_cur = v10;
      }
      else
      {
        v8 = 0i64;
      }
      newPairs.m_data = v8;
      v43 = v8;
      v11 = v2->m_world;
      newPairs.m_capacityAndFlags = v5 | 0x80000000;
      v12 = v11->m_broadPhaseUpdateSize;
      delPairs.m_data = 0i64;
      delPairs.m_size = 0;
      delPairs.m_capacityAndFlags = 2147483648;
      v41 = v12;
      if ( v12 )
      {
        v13 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (hkLifoAllocator *)v13;
        v15 = (hkpBroadPhaseHandlePair *)*((_QWORD *)v13 + 3);
        v16 = (16 * v12 + 127) & 0xFFFFFF80;
        v17 = (char *)v15 + v16;
        if ( v16 > v14->m_slabSize || v17 > v14->m_end )
          v15 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v14, v16);
        else
          v14->m_cur = v17;
      }
      else
      {
        v15 = 0i64;
      }
      delPairs.m_data = v15;
      p = v15;
      v45 = &v2->m_collidable.m_broadPhaseHandle;
      v18 = v2->m_world;
      delPairs.m_capacityAndFlags = v12 | 0x80000000;
      v19 = v18->m_broadPhase;
      if ( v19->m_criticalSection )
        hkpBroadPhase::lockImplementation(v19);
      ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle **, hkAabb *, signed __int64, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))v2->m_world->m_broadPhase->vfptr[5].__first_virtual_table_function__)(
        v2->m_world->m_broadPhase,
        &v45,
        v4,
        1i64,
        &newPairs,
        &delPairs);
      if ( newPairs.m_size || delPairs.m_size )
      {
        hkpTypedBroadPhaseDispatcher::removeDuplicates(&newPairs, &delPairs);
        hkpTypedBroadPhaseDispatcher::removePairs(
          v2->m_world->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
          delPairs.m_size);
        v20 = v2->m_world;
        v21 = (hkpCollidableCollidableFilter *)v20->m_collisionFilter;
        if ( v21 )
          v22 = v21 + 2;
        else
          v22 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          v20->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v22);
        hkpPhantom::removeNullOverlapListeners(v2);
      }
      v23 = v2->m_world->m_broadPhase;
      if ( v23->m_criticalSection )
        hkpBroadPhase::unlockImplementation(v23);
      hkpPhantom::setBoundingVolumeData(v2, v4);
      v24 = v2->m_world;
      v25 = v24->m_criticalOperationsLockCount-- == 1;
      if ( v25 && !v24->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v24->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v24);
        if ( v24->m_pendingOperationQueueCount == 1 && v24->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v24);
      }
      v26 = delPairs.m_size;
      v27 = (char *)p;
      if ( p == delPairs.m_data )
        v26 = 0;
      delPairs.m_size = v26;
      v28 = (16 * v41 + 127) & 0xFFFFFF80;
      v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v30 = (v28 + 15) & 0xFFFFFFF0;
      if ( v28 > v29->m_slabSize || &v27[v30] != v29->m_cur || v29->m_firstNonLifoEnd == v27 )
        hkLifoAllocator::slowBlockFree(v29, v27, v30);
      else
        v29->m_cur = v27;
      delPairs.m_size = 0;
      if ( delPairs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          delPairs.m_data,
          16 * delPairs.m_capacityAndFlags);
      v31 = newPairs.m_size;
      v32 = (char *)v43;
      delPairs.m_data = 0i64;
      if ( v43 == newPairs.m_data )
        v31 = 0;
      delPairs.m_capacityAndFlags = 2147483648;
      newPairs.m_size = v31;
      v33 = (16 * v44 + 127) & 0xFFFFFF80;
      v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v35 = (v33 + 15) & 0xFFFFFFF0;
      if ( v33 > v34->m_slabSize || &v32[v35] != v34->m_cur || v34->m_firstNonLifoEnd == v32 )
        hkLifoAllocator::slowBlockFree(v34, v32, v35);
      else
        v34->m_cur = v32;
      newPairs.m_size = 0;
      if ( newPairs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          newPairs.m_data,
          16 * newPairs.m_capacityAndFlags);
    }
  }
}

// File Line: 165
// RVA: 0xD76E70
void __fastcall hkpPhantom::setBoundingVolumeData(hkpPhantom *this, hkAabb *aabb)
{
  __m128 v2; // xmm5
  hkpProcessCollisionInput *v3; // r8
  __m128 v4; // xmm4
  __m128i v5; // xmm2
  __m128 v6; // xmm4
  __m128i v7; // xmm2
  __m128i v8; // xmm1
  __m128i v9; // xmm4
  __m128i v10; // xmm4
  __m128i v11; // xmm5
  __m128i v12; // xmm5
  __m128i v13; // xmm0
  __m128i v14; // xmm1
  int v15; // eax
  unsigned int v16; // eax
  __m128i v17; // xmm0
  __m128i v18; // xmm2
  __m128i v19; // xmm0
  __m128i v20; // xmm1
  unsigned int v21; // eax
  __m128 v22; // xmm4
  __m128i v23; // xmm4
  __m128i v24; // xmm4
  __m128 v25; // xmm5
  __m128i v26; // xmm5
  __m128i v27; // xmm5

  v2 = hkAabbUtil::hkAabbUint32MaxVal;
  v3 = this->m_world->m_collisionInput;
  v4 = _mm_max_ps(
         _mm_min_ps(
           _mm_mul_ps(
             _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, aabb->m_min.m_quad),
             v3->m_aabb32Info.m_bitScale.m_quad),
           hkAabbUtil::hkAabbUint32MaxVal),
         (__m128)0i64);
  v5 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v4);
  _mm_store_si128(
    (__m128i *)&this->m_collidable.m_boundingVolumeData,
    _mm_or_si128(
      _mm_add_epi32(
        _mm_cvttps_epi32(
          _mm_max_ps(
            _mm_sub_ps(v4, _mm_and_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, (__m128)v5)),
            (__m128)0i64)),
        _mm_slli_epi32(v5, 0x1Fu)),
      (__m128i)_mm_cmpleps(
                 _mm_add_ps(
                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                 v4)));
  v6 = _mm_max_ps(
         _mm_min_ps(
           _mm_mul_ps(
             _mm_add_ps(v3->m_aabb32Info.m_bitOffsetHigh.m_quad, aabb->m_max.m_quad),
             v3->m_aabb32Info.m_bitScale.m_quad),
           v2),
         (__m128)0i64);
  v7 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v6);
  v8 = _mm_cvtsi32_si128(0);
  _mm_store_si128(
    (__m128i *)this->m_collidable.m_boundingVolumeData.m_max,
    _mm_or_si128(
      _mm_add_epi32(
        _mm_cvttps_epi32(
          _mm_max_ps(
            _mm_sub_ps(v6, _mm_and_ps((__m128)v7, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
            (__m128)0i64)),
        _mm_slli_epi32(v7, 0x1Fu)),
      (__m128i)_mm_cmpleps(
                 _mm_add_ps(
                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                 v6)));
  v9 = _mm_unpacklo_epi32(
         _mm_unpacklo_epi32(
           _mm_cvtsi32_si128(this->m_collidable.m_boundingVolumeData.m_min[0]),
           _mm_cvtsi32_si128(this->m_collidable.m_boundingVolumeData.m_min[2])),
         _mm_unpacklo_epi32(_mm_cvtsi32_si128(this->m_collidable.m_boundingVolumeData.m_min[1]), v8));
  v10 = _mm_sub_epi32(v9, v9);
  v11 = _mm_unpacklo_epi32(
          _mm_unpacklo_epi32(
            _mm_cvtsi32_si128(this->m_collidable.m_boundingVolumeData.m_max[0]),
            _mm_cvtsi32_si128(this->m_collidable.m_boundingVolumeData.m_max[2])),
          _mm_unpacklo_epi32(_mm_cvtsi32_si128(this->m_collidable.m_boundingVolumeData.m_max[1]), v8));
  v12 = _mm_sub_epi32(v11, v11);
  v13 = _mm_or_si128(v12, v10);
  v14 = _mm_or_si128(_mm_shuffle_epi32(v13, 225), v13);
  v15 = _mm_cvtsi128_si32(_mm_or_si128(_mm_shuffle_epi32(v14, 78), v14));
  v16 = v15 | 0xFF | ((v15 | 0xFFu) >> 1) | ((v15 | 0xFF | ((v15 | 0xFFu) >> 1)) >> 2);
  v17 = _mm_cvtsi32_si128(v16 | (v16 >> 4) | ((v16 | (v16 >> 4)) >> 8) | ((v16 | (v16 >> 4) | ((v16 | (v16 >> 4)) >> 8)) >> 16));
  v18 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v17, 1u), (__m128i)_xmm), _mm_and_si128(v17, (__m128i)_xmm));
  v19 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v18, 2u), (__m128i)_xmm), _mm_and_si128(v18, (__m128i)_xmm));
  v20 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v19, 4u), v19), (__m128i)_xmm), (__m128i)0i64);
  v21 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v20, 78), v20)) - 8;
  v22 = (__m128)_mm_srli_epi32(v10, v21);
  v23 = (__m128i)_mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(v21), 0)), 196);
  v24 = _mm_packs_epi32(v23, v23);
  v25 = (__m128)_mm_srli_epi32(v12, v21);
  *(_DWORD *)this->m_collidable.m_boundingVolumeData.m_expansionMin = (unsigned __int128)_mm_packus_epi16(v24, v24);
  v26 = (__m128i)_mm_shuffle_ps(
                   v25,
                   _mm_unpackhi_ps(
                     v25,
                     (__m128)_mm_shuffle_epi32(
                               _mm_cvtsi32_si128((unsigned __int8)this->m_collidable.m_boundingVolumeData.m_padding),
                               0)),
                   196);
  v27 = _mm_packs_epi32(v26, v26);
  *(_DWORD *)this->m_collidable.m_boundingVolumeData.m_expansionMax = (unsigned __int128)_mm_packus_epi16(v27, v27);
}

// File Line: 180
// RVA: 0xD76780
void __fastcall hkpPhantom::addPhantomListener(hkpPhantom *this, hkpPhantomListener *el)
{
  hkArray<hkpPhantomListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpPhantomListener *v3; // rdi

  v2 = &this->m_phantomListeners;
  v3 = el;
  if ( this->m_phantomListeners.m_size == (this->m_phantomListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 187
// RVA: 0xD767E0
void __fastcall hkpPhantom::removePhantomListener(hkpPhantom *this, hkpPhantomListener *el)
{
  signed int v2; // er9
  hkpPhantom *v3; // r11
  __int64 v4; // rcx
  __int64 v5; // r8
  hkpPhantomListener **v6; // rax
  signed __int64 v7; // rax
  int v8; // edx
  __int64 v9; // rdx
  __int64 v10; // rcx

  v2 = 0;
  v3 = this;
  v4 = this->m_phantomListeners.m_size;
  v5 = 0i64;
  if ( (signed int)v4 <= 0 )
  {
LABEL_5:
    v2 = -1;
  }
  else
  {
    v6 = v3->m_phantomListeners.m_data;
    while ( *v6 != el )
    {
      ++v5;
      ++v2;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_5;
    }
  }
  v3->m_phantomListeners.m_size = v4 - 1;
  v7 = (signed __int64)&v3->m_phantomListeners.m_data[v2];
  v8 = 8 * (v4 - 1 - v2);
  if ( v8 > 0 )
  {
    v9 = ((unsigned int)(v8 - 1) >> 3) + 1;
    do
    {
      v10 = *(_QWORD *)(v7 + 8);
      v7 += 8i64;
      *(_QWORD *)(v7 - 8) = v10;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 196
// RVA: 0xD76870
void __fastcall hkpPhantom::addPhantomOverlapListener(hkpPhantom *this, hkpPhantomOverlapListener *el)
{
  hkArray<hkpPhantomOverlapListener *,hkContainerHeapAllocator> *v2; // rbx
  hkpPhantomOverlapListener *v3; // rdi

  v2 = &this->m_overlapListeners;
  v3 = el;
  if ( this->m_overlapListeners.m_size == (this->m_overlapListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 203
// RVA: 0xD768D0
void __fastcall hkpPhantom::removePhantomOverlapListener(hkpPhantom *this, hkpPhantomOverlapListener *el)
{
  signed int v2; // er9
  hkpPhantom *v3; // r11
  __int64 v4; // rcx
  __int64 v5; // r8
  hkpPhantomOverlapListener **v6; // rax
  signed __int64 v7; // rax
  int v8; // edx
  __int64 v9; // rdx
  __int64 v10; // rcx

  v2 = 0;
  v3 = this;
  v4 = this->m_overlapListeners.m_size;
  v5 = 0i64;
  if ( (signed int)v4 <= 0 )
  {
LABEL_5:
    v2 = -1;
  }
  else
  {
    v6 = v3->m_overlapListeners.m_data;
    while ( *v6 != el )
    {
      ++v5;
      ++v2;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_5;
    }
  }
  v3->m_overlapListeners.m_size = v4 - 1;
  v7 = (signed __int64)&v3->m_overlapListeners.m_data[v2];
  v8 = 8 * (v4 - 1 - v2);
  if ( v8 > 0 )
  {
    v9 = ((unsigned int)(v8 - 1) >> 3) + 1;
    do
    {
      v10 = *(_QWORD *)(v7 + 8);
      v7 += 8i64;
      *(_QWORD *)(v7 - 8) = v10;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 212
// RVA: 0xD766B0
void __fastcall hkpPhantom::~hkpPhantom(hkpPhantom *this)
{
  hkpPhantom *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhantom::`vftable;
  hkpPhantom::firePhantomDeleted(this);
  v2 = v1->m_phantomListeners.m_capacityAndFlags;
  v1->m_phantomListeners.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_phantomListeners.m_data,
      8 * v2);
  v1->m_phantomListeners.m_data = 0i64;
  v1->m_phantomListeners.m_capacityAndFlags = 2147483648;
  v3 = v1->m_overlapListeners.m_capacityAndFlags;
  v1->m_overlapListeners.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_overlapListeners.m_data,
      8 * v3);
  v1->m_overlapListeners.m_data = 0i64;
  v1->m_overlapListeners.m_capacityAndFlags = 2147483648;
  hkpWorldObject::~hkpWorldObject((hkpWorldObject *)&v1->vfptr);
}

// File Line: 218
// RVA: 0xD77190
void __fastcall hkpPhantom::deallocateInternalArrays(hkpPhantom *this)
{
  hkpPhantom *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  if ( !this->m_overlapListeners.m_size )
  {
    v2 = this->m_overlapListeners.m_capacityAndFlags;
    this->m_overlapListeners.m_size = 0;
    if ( v2 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_overlapListeners.m_data,
        8 * v2);
    v1->m_overlapListeners.m_data = 0i64;
    v1->m_overlapListeners.m_capacityAndFlags = 2147483648;
  }
  if ( !v1->m_phantomListeners.m_size )
  {
    v3 = v1->m_phantomListeners.m_capacityAndFlags;
    v1->m_phantomListeners.m_size = 0;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v1->m_phantomListeners.m_data,
        8 * v3);
    v1->m_phantomListeners.m_data = 0i64;
    v1->m_phantomListeners.m_capacityAndFlags = 2147483648;
  }
}

