// File Line: 34
// RVA: 0xD77090
void __fastcall hkpPhantom::removeNullOverlapListeners(hkpPhantom *this)
{
  int v2; // r10d
  __int64 i; // r9
  hkpPhantomOverlapListener **m_data; // rax
  hkpPhantomOverlapListener **v5; // rax
  int v6; // ecx
  __int64 v7; // rdx
  hkpPhantomOverlapListener *v8; // rcx

  v2 = this->m_overlapListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    m_data = this->m_overlapListeners.m_data;
    if ( !m_data[i] )
    {
      --this->m_overlapListeners.m_size;
      v5 = &m_data[i];
      v6 = 8 * (this->m_overlapListeners.m_size - v2);
      if ( v6 > 0 )
      {
        v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
        do
        {
          v8 = v5[1];
          *v5++ = v8;
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
  int v2; // r10d
  __int64 i; // r9
  hkpPhantomListener **m_data; // rax
  hkpPhantomListener **v5; // rax
  int v6; // ecx
  __int64 v7; // rdx
  hkpPhantomListener *v8; // rcx

  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    m_data = this->m_phantomListeners.m_data;
    if ( !m_data[i] )
    {
      --this->m_phantomListeners.m_size;
      v5 = &m_data[i];
      v6 = 8 * (this->m_phantomListeners.m_size - v2);
      if ( v6 > 0 )
      {
        v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
        do
        {
          v8 = v5[1];
          *v5++ = v8;
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
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = this->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomDeletedCallback(v4, this);
  }
}

// File Line: 71
// RVA: 0xD769C0
void __fastcall hkpPhantom::firePhantomRemoved(hkpPhantom *this)
{
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = this->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomRemovedCallback(v4, this);
  }
  hkpPhantom::removeNullPhantomListeners(this);
}

// File Line: 86
// RVA: 0xD76960
void __fastcall hkpPhantom::firePhantomAdded(hkpPhantom *this)
{
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = this->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomAddedCallback(v4, this);
  }
  hkpPhantom::removeNullPhantomListeners(this);
}

// File Line: 100
// RVA: 0xD76A20
void __fastcall hkpPhantom::firePhantomShapeSet(hkpPhantom *this)
{
  int v2; // eax
  __int64 i; // rbx
  hkpPhantomListener *v4; // rcx

  v2 = this->m_phantomListeners.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = this->m_phantomListeners.m_data[i];
    if ( v4 )
      v4->vfptr->phantomShapeSetCallback(v4, this);
  }
  hkpPhantom::removeNullPhantomListeners(this);
}

// File Line: 114
// RVA: 0xD76AD0
void __fastcall hkpPhantom::updateBroadPhase(hkpPhantom *this, hkAabb *aabb)
{
  hkpWorld *m_world; // rcx
  int m_broadPhaseUpdateSize; // edi
  hkLifoAllocator *Value; // rcx
  hkpBroadPhaseHandlePair *m_cur; // rax
  int v8; // edx
  char *v9; // r8
  hkpWorld *v10; // rax
  int v11; // edi
  hkLifoAllocator *v12; // rcx
  hkpBroadPhaseHandlePair *v13; // rax
  int v14; // edx
  char *v15; // r8
  hkpWorld *v16; // rax
  hkpBroadPhase *m_broadPhase; // rcx
  hkpWorld *v18; // rcx
  hkpCollisionFilter *m_collisionFilter; // r9
  hkpCollidableCollidableFilter *v20; // r9
  hkpBroadPhase *v21; // rcx
  hkpWorld *v22; // rbx
  bool v23; // zf
  int m_size; // eax
  char *v25; // rdi
  signed int v26; // ebx
  hkLifoAllocator *v27; // rax
  int v28; // r8d
  int v29; // eax
  char *v30; // rdi
  signed int v31; // ebx
  hkLifoAllocator *v32; // rax
  int v33; // r8d
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-19h] BYREF
  hkpPhantom *v35; // [rsp+38h] [rbp-11h]
  hkAabb *v36; // [rsp+40h] [rbp-9h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> delPairs; // [rsp+48h] [rbp-1h] BYREF
  void *p; // [rsp+58h] [rbp+Fh]
  int v39; // [rsp+60h] [rbp+17h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> newPairs; // [rsp+68h] [rbp+1Fh] BYREF
  void *v41; // [rsp+78h] [rbp+2Fh]
  int v42; // [rsp+80h] [rbp+37h]
  hkpTypedBroadPhaseHandle *p_m_broadPhaseHandle; // [rsp+B0h] [rbp+67h] BYREF

  m_world = this->m_world;
  if ( m_world )
  {
    if ( m_world->m_criticalOperationsLockCount + m_world->m_criticalOperationsLockCountForPhantoms )
    {
      v36 = aabb;
      operation.m_type.m_storage = 18;
      v35 = this;
      hkpWorld::queueOperation(m_world, &operation);
    }
    else
    {
      ++m_world->m_criticalOperationsLockCount;
      m_broadPhaseUpdateSize = this->m_world->m_broadPhaseUpdateSize;
      newPairs.m_data = 0i64;
      newPairs.m_size = 0;
      newPairs.m_capacityAndFlags = 0x80000000;
      v42 = m_broadPhaseUpdateSize;
      if ( m_broadPhaseUpdateSize )
      {
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkpBroadPhaseHandlePair *)Value->m_cur;
        v8 = (16 * m_broadPhaseUpdateSize + 127) & 0xFFFFFF80;
        v9 = (char *)m_cur + v8;
        if ( v8 > Value->m_slabSize || v9 > Value->m_end )
          m_cur = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
        else
          Value->m_cur = v9;
      }
      else
      {
        m_cur = 0i64;
      }
      newPairs.m_data = m_cur;
      v41 = m_cur;
      v10 = this->m_world;
      newPairs.m_capacityAndFlags = m_broadPhaseUpdateSize | 0x80000000;
      v11 = v10->m_broadPhaseUpdateSize;
      delPairs.m_data = 0i64;
      delPairs.m_size = 0;
      delPairs.m_capacityAndFlags = 0x80000000;
      v39 = v11;
      if ( v11 )
      {
        v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (hkpBroadPhaseHandlePair *)v12->m_cur;
        v14 = (16 * v11 + 127) & 0xFFFFFF80;
        v15 = (char *)v13 + v14;
        if ( v14 > v12->m_slabSize || v15 > v12->m_end )
          v13 = (hkpBroadPhaseHandlePair *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
        else
          v12->m_cur = v15;
      }
      else
      {
        v13 = 0i64;
      }
      delPairs.m_data = v13;
      p = v13;
      p_m_broadPhaseHandle = &this->m_collidable.m_broadPhaseHandle;
      v16 = this->m_world;
      delPairs.m_capacityAndFlags = v11 | 0x80000000;
      m_broadPhase = v16->m_broadPhase;
      if ( m_broadPhase->m_criticalSection )
        hkpBroadPhase::lockImplementation(m_broadPhase);
      ((void (__fastcall *)(hkpBroadPhase *, hkpTypedBroadPhaseHandle **, hkAabb *, __int64, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))this->m_world->m_broadPhase->vfptr[5].__first_virtual_table_function__)(
        this->m_world->m_broadPhase,
        &p_m_broadPhaseHandle,
        aabb,
        1i64,
        &newPairs,
        &delPairs);
      if ( newPairs.m_size || delPairs.m_size )
      {
        hkpTypedBroadPhaseDispatcher::removeDuplicates(&newPairs, &delPairs);
        hkpTypedBroadPhaseDispatcher::removePairs(
          this->m_world->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)delPairs.m_data,
          delPairs.m_size);
        v18 = this->m_world;
        m_collisionFilter = v18->m_collisionFilter;
        if ( m_collisionFilter )
          v20 = &m_collisionFilter->hkpCollidableCollidableFilter;
        else
          v20 = 0i64;
        hkpTypedBroadPhaseDispatcher::addPairs(
          v18->m_broadPhaseDispatcher,
          (hkpTypedBroadPhaseHandlePair *)newPairs.m_data,
          newPairs.m_size,
          v20);
        hkpPhantom::removeNullOverlapListeners(this);
      }
      v21 = this->m_world->m_broadPhase;
      if ( v21->m_criticalSection )
        hkpBroadPhase::unlockImplementation(v21);
      hkpPhantom::setBoundingVolumeData(this, aabb);
      v22 = this->m_world;
      v23 = v22->m_criticalOperationsLockCount-- == 1;
      if ( v23 && !v22->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v22->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v22);
        if ( v22->m_pendingOperationQueueCount == 1 && v22->m_pendingBodyOperationsCount )
          hkpWorld::internal_executePendingBodyOperations(v22);
      }
      m_size = delPairs.m_size;
      v25 = (char *)p;
      if ( p == delPairs.m_data )
        m_size = 0;
      delPairs.m_size = m_size;
      v26 = (16 * v39 + 127) & 0xFFFFFF80;
      v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v28 = (v26 + 15) & 0xFFFFFFF0;
      if ( v26 > v27->m_slabSize || &v25[v28] != v27->m_cur || v27->m_firstNonLifoEnd == v25 )
        hkLifoAllocator::slowBlockFree(v27, v25, v28);
      else
        v27->m_cur = v25;
      delPairs.m_size = 0;
      if ( delPairs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          delPairs.m_data,
          16 * delPairs.m_capacityAndFlags);
      v29 = newPairs.m_size;
      v30 = (char *)v41;
      delPairs.m_data = 0i64;
      if ( v41 == newPairs.m_data )
        v29 = 0;
      delPairs.m_capacityAndFlags = 0x80000000;
      newPairs.m_size = v29;
      v31 = (16 * v42 + 127) & 0xFFFFFF80;
      v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (v31 + 15) & 0xFFFFFFF0;
      if ( v31 > v32->m_slabSize || &v30[v33] != v32->m_cur || v32->m_firstNonLifoEnd == v30 )
        hkLifoAllocator::slowBlockFree(v32, v30, v33);
      else
        v32->m_cur = v30;
      newPairs.m_size = 0;
      if ( newPairs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
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
  hkpProcessCollisionInput *m_collisionInput; // r8
  __m128 v4; // xmm4
  __m128i v5; // xmm2
  __m128 v6; // xmm4
  __m128i v7; // xmm0
  __m128i v8; // xmm1
  __m128i v9; // xmm4
  __m128i v10; // xmm4
  __m128i v11; // xmm5
  __m128i v12; // xmm5
  __m128i v13; // xmm0
  __m128i v14; // xmm1
  int v15; // eax
  unsigned int v16; // eax
  __m128i v17; // xmm2
  __m128i v18; // xmm0
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
  m_collisionInput = this->m_world->m_collisionInput;
  v4 = _mm_max_ps(
         _mm_min_ps(
           _mm_mul_ps(
             _mm_add_ps(m_collisionInput->m_aabb32Info.m_bitOffsetLow.m_quad, aabb->m_min.m_quad),
             m_collisionInput->m_aabb32Info.m_bitScale.m_quad),
           hkAabbUtil::hkAabbUint32MaxVal),
         (__m128)0i64);
  v5 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v4);
  *(__m128i *)this->m_collidable.m_boundingVolumeData.m_min = _mm_or_si128(
                                                                _mm_add_epi32(
                                                                  _mm_cvttps_epi32(
                                                                    _mm_max_ps(
                                                                      _mm_sub_ps(
                                                                        v4,
                                                                        _mm_and_ps(
                                                                          *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                                          (__m128)v5)),
                                                                      (__m128)0i64)),
                                                                  _mm_slli_epi32(v5, 0x1Fu)),
                                                                (__m128i)_mm_cmple_ps(
                                                                           _mm_add_ps(
                                                                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                                           v4));
  v6 = _mm_max_ps(
         _mm_min_ps(
           _mm_mul_ps(
             _mm_add_ps(m_collisionInput->m_aabb32Info.m_bitOffsetHigh.m_quad, aabb->m_max.m_quad),
             m_collisionInput->m_aabb32Info.m_bitScale.m_quad),
           v2),
         (__m128)0i64);
  v7 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v6);
  v8 = _mm_cvtsi32_si128(0);
  *(__m128i *)this->m_collidable.m_boundingVolumeData.m_max = _mm_or_si128(
                                                                _mm_add_epi32(
                                                                  _mm_cvttps_epi32(
                                                                    _mm_max_ps(
                                                                      _mm_sub_ps(
                                                                        v6,
                                                                        _mm_and_ps(
                                                                          (__m128)v7,
                                                                          *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                                                      (__m128)0i64)),
                                                                  _mm_slli_epi32(v7, 0x1Fu)),
                                                                (__m128i)_mm_cmple_ps(
                                                                           _mm_add_ps(
                                                                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                                           v6));
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
  *(_DWORD *)this->m_collidable.m_boundingVolumeData.m_expansionMin = _mm_packus_epi16(v24, v24).m128i_u32[0];
  v26 = (__m128i)_mm_shuffle_ps(
                   v25,
                   _mm_unpackhi_ps(
                     v25,
                     (__m128)_mm_shuffle_epi32(
                               _mm_cvtsi32_si128((unsigned __int8)this->m_collidable.m_boundingVolumeData.m_padding),
                               0)),
                   196);
  v27 = _mm_packs_epi32(v26, v26);
  *(_DWORD *)this->m_collidable.m_boundingVolumeData.m_expansionMax = _mm_packus_epi16(v27, v27).m128i_u32[0];
}

// File Line: 180
// RVA: 0xD76780
void __fastcall hkpPhantom::addPhantomListener(hkpPhantom *this, hkpPhantomListener *el)
{
  hkArray<hkpPhantomListener *,hkContainerHeapAllocator> *p_m_phantomListeners; // rbx

  p_m_phantomListeners = &this->m_phantomListeners;
  if ( this->m_phantomListeners.m_size == (this->m_phantomListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_phantomListeners->m_data, 8);
  p_m_phantomListeners->m_data[p_m_phantomListeners->m_size++] = el;
}

// File Line: 187
// RVA: 0xD767E0
void __fastcall hkpPhantom::removePhantomListener(hkpPhantom *this, hkpPhantomListener *el)
{
  int v2; // r9d
  __int64 m_size; // rcx
  __int64 v5; // r8
  hkpPhantomListener **m_data; // rax
  hkpPhantomListener **v7; // rax
  int v8; // edx
  __int64 v9; // rdx
  hkpPhantomListener *v10; // rcx

  v2 = 0;
  m_size = this->m_phantomListeners.m_size;
  v5 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_5:
    v2 = -1;
  }
  else
  {
    m_data = this->m_phantomListeners.m_data;
    while ( *m_data != el )
    {
      ++v5;
      ++v2;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_phantomListeners.m_size = m_size - 1;
  v7 = &this->m_phantomListeners.m_data[v2];
  v8 = 8 * (m_size - 1 - v2);
  if ( v8 > 0 )
  {
    v9 = ((unsigned int)(v8 - 1) >> 3) + 1;
    do
    {
      v10 = v7[1];
      *v7++ = v10;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 196
// RVA: 0xD76870
void __fastcall hkpPhantom::addPhantomOverlapListener(hkpPhantom *this, hkpPhantomOverlapListener *el)
{
  hkArray<hkpPhantomOverlapListener *,hkContainerHeapAllocator> *p_m_overlapListeners; // rbx

  p_m_overlapListeners = &this->m_overlapListeners;
  if ( this->m_overlapListeners.m_size == (this->m_overlapListeners.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_overlapListeners->m_data, 8);
  p_m_overlapListeners->m_data[p_m_overlapListeners->m_size++] = el;
}

// File Line: 203
// RVA: 0xD768D0
void __fastcall hkpPhantom::removePhantomOverlapListener(hkpPhantom *this, hkpPhantomOverlapListener *el)
{
  int v2; // r9d
  __int64 m_size; // rcx
  __int64 v5; // r8
  hkpPhantomOverlapListener **m_data; // rax
  hkpPhantomOverlapListener **v7; // rax
  int v8; // edx
  __int64 v9; // rdx
  hkpPhantomOverlapListener *v10; // rcx

  v2 = 0;
  m_size = this->m_overlapListeners.m_size;
  v5 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_5:
    v2 = -1;
  }
  else
  {
    m_data = this->m_overlapListeners.m_data;
    while ( *m_data != el )
    {
      ++v5;
      ++v2;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_overlapListeners.m_size = m_size - 1;
  v7 = &this->m_overlapListeners.m_data[v2];
  v8 = 8 * (m_size - 1 - v2);
  if ( v8 > 0 )
  {
    v9 = ((unsigned int)(v8 - 1) >> 3) + 1;
    do
    {
      v10 = v7[1];
      *v7++ = v10;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 212
// RVA: 0xD766B0
void __fastcall hkpPhantom::~hkpPhantom(hkpPhantom *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpPhantom::`vftable;
  hkpPhantom::firePhantomDeleted(this);
  m_capacityAndFlags = this->m_phantomListeners.m_capacityAndFlags;
  this->m_phantomListeners.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_phantomListeners.m_data,
      8 * m_capacityAndFlags);
  this->m_phantomListeners.m_data = 0i64;
  this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  v3 = this->m_overlapListeners.m_capacityAndFlags;
  this->m_overlapListeners.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_overlapListeners.m_data,
      8 * v3);
  this->m_overlapListeners.m_data = 0i64;
  this->m_overlapListeners.m_capacityAndFlags = 0x80000000;
  hkpWorldObject::~hkpWorldObject(this);
}

// File Line: 218
// RVA: 0xD77190
void __fastcall hkpPhantom::deallocateInternalArrays(hkpPhantom *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  if ( !this->m_overlapListeners.m_size )
  {
    m_capacityAndFlags = this->m_overlapListeners.m_capacityAndFlags;
    this->m_overlapListeners.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_overlapListeners.m_data,
        8 * m_capacityAndFlags);
    this->m_overlapListeners.m_data = 0i64;
    this->m_overlapListeners.m_capacityAndFlags = 0x80000000;
  }
  if ( !this->m_phantomListeners.m_size )
  {
    v3 = this->m_phantomListeners.m_capacityAndFlags;
    this->m_phantomListeners.m_size = 0;
    if ( v3 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_phantomListeners.m_data,
        8 * v3);
    this->m_phantomListeners.m_data = 0i64;
    this->m_phantomListeners.m_capacityAndFlags = 0x80000000;
  }
}

