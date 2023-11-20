// File Line: 25
// RVA: 0xC05D60
hkaiNavMeshPathRequestInfo *__fastcall hkaiWorld::cancelRequestedNavMeshPath(hkaiWorld *this, hkaiPathRequestInfoOwner *owner)
{
  __int64 v2; // r10
  int v3; // er9
  hkaiWorld *v4; // r11
  __int64 v5; // r8
  hkaiNavMeshPathRequestInfo *v6; // rbx
  hkBool *v7; // rax
  signed __int64 v9; // rcx

  v2 = this->m_navMeshPathRequests.m_size;
  v3 = 0;
  v4 = this;
  v5 = 0i64;
  if ( v2 <= 0 )
    return 0i64;
  v6 = this->m_navMeshPathRequests.m_data;
  v7 = &v6->m_markedForDeletion;
  while ( *(hkaiPathRequestInfoOwner **)&v7[-8].m_bool != owner || v7->m_bool )
  {
    ++v5;
    ++v3;
    v7 += 56;
    if ( v5 >= v2 )
      return 0i64;
  }
  v9 = v3;
  v6[v9].m_markedForDeletion.m_bool = 1;
  return &v4->m_navMeshPathRequests.m_data[v9];
}

// File Line: 40
// RVA: 0xC05DD0
hkaiNavVolumePathRequestInfo *__fastcall hkaiWorld::cancelRequestedNavVolumePath(hkaiWorld *this, hkaiPathRequestInfoOwner *owner)
{
  __int64 v2; // r10
  int v3; // er9
  hkaiWorld *v4; // r11
  __int64 v5; // r8
  hkaiNavVolumePathRequestInfo *v6; // rbx
  hkBool *v7; // rax
  signed __int64 v9; // rcx

  v2 = this->m_navVolumePathRequests.m_size;
  v3 = 0;
  v4 = this;
  v5 = 0i64;
  if ( v2 <= 0 )
    return 0i64;
  v6 = this->m_navVolumePathRequests.m_data;
  v7 = &v6->m_markedForDeletion;
  while ( *(hkaiPathRequestInfoOwner **)&v7[-8].m_bool != owner || v7->m_bool )
  {
    ++v5;
    ++v3;
    v7 += 56;
    if ( v5 >= v2 )
      return 0i64;
  }
  v9 = v3;
  v6[v9].m_markedForDeletion.m_bool = 1;
  return &v4->m_navVolumePathRequests.m_data[v9];
}

// File Line: 55
// RVA: 0xC05920
void __fastcall hkaiWorld::requestPath(hkaiWorld *this, hkaiPathRequestInfoOwner *owner, hkaiPathfindingUtil::FindPathInput *input, int priority)
{
  int v4; // er14
  hkaiPathfindingUtil::FindPathInput *v5; // rbp
  hkaiPathRequestInfoOwner *v6; // rsi
  int v7; // er11
  __int64 v8; // r10
  hkaiNavMeshPathRequestInfo *v9; // rax
  signed int *v10; // rdi
  signed __int64 v11; // rax
  signed __int64 v12; // rbx
  hkReferencedObject *v13; // rcx

  v4 = priority;
  v5 = input;
  v6 = owner;
  v7 = 0;
  if ( this->m_navMeshPathRequests.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = this->m_navMeshPathRequests.m_data;
      if ( v9[v8].m_owner == owner )
        v9[v8].m_markedForDeletion.m_bool = 1;
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_navMeshPathRequests.m_size );
  }
  v10 = (signed int *)&this->m_navMeshPathRequests;
  if ( this->m_navMeshPathRequests.m_size == (this->m_navMeshPathRequests.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 56);
  v11 = *(_QWORD *)v10 + 56i64 * v10[2];
  if ( v11 )
  {
    *(_DWORD *)(v11 + 8) = 0x1FFFF;
    *(_QWORD *)v11 = &hkaiNavMeshPathRequestInfo::`vftable;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 24) = 0i64;
    *(_DWORD *)(v11 + 32) = 0;
    *(_QWORD *)(v11 + 40) = 0i64;
    *(_BYTE *)(v11 + 48) = 0;
  }
  v12 = *(_QWORD *)v10 + 56i64 * v10[2]++;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  v13 = *(hkReferencedObject **)(v12 + 16);
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  *(_QWORD *)(v12 + 16) = v5;
  *(_QWORD *)(v12 + 40) = v6;
  *(_DWORD *)(v12 + 32) = v4;
}

// File Line: 75
// RVA: 0xC05A40
void __fastcall hkaiWorld::requestPath(hkaiWorld *this, hkaiPathRequestInfoOwner *owner, hkaiVolumePathfindingUtil::FindPathInput *input, int priority)
{
  int v4; // er14
  hkaiVolumePathfindingUtil::FindPathInput *v5; // rbp
  hkaiPathRequestInfoOwner *v6; // rsi
  int v7; // er11
  __int64 v8; // r10
  hkaiNavVolumePathRequestInfo *v9; // rax
  signed int *v10; // rdi
  signed __int64 v11; // rax
  signed __int64 v12; // rbx
  hkReferencedObject *v13; // rcx

  v4 = priority;
  v5 = input;
  v6 = owner;
  v7 = 0;
  if ( this->m_navVolumePathRequests.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = this->m_navVolumePathRequests.m_data;
      if ( v9[v8].m_owner == owner )
        v9[v8].m_markedForDeletion.m_bool = 1;
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_navVolumePathRequests.m_size );
  }
  v10 = (signed int *)&this->m_navVolumePathRequests;
  if ( this->m_navVolumePathRequests.m_size == (this->m_navVolumePathRequests.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 56);
  v11 = *(_QWORD *)v10 + 56i64 * v10[2];
  if ( v11 )
  {
    *(_DWORD *)(v11 + 8) = 0x1FFFF;
    *(_QWORD *)v11 = &hkaiNavVolumePathRequestInfo::`vftable;
    *(_QWORD *)(v11 + 16) = 0i64;
    *(_QWORD *)(v11 + 24) = 0i64;
    *(_DWORD *)(v11 + 32) = 0;
    *(_QWORD *)(v11 + 40) = 0i64;
    *(_BYTE *)(v11 + 48) = 0;
  }
  v12 = *(_QWORD *)v10 + 56i64 * v10[2]++;
  if ( v5 )
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
  v13 = *(hkReferencedObject **)(v12 + 16);
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  *(_QWORD *)(v12 + 16) = v5;
  *(_QWORD *)(v12 + 40) = v6;
  *(_DWORD *)(v12 + 32) = v4;
}

// File Line: 95
// RVA: 0xC05B60
hkaiNavMeshPathRequestInfo *__fastcall hkaiWorld::getNavMeshPathRequest(hkaiWorld *this, hkaiPathRequestInfoOwner *owner)
{
  hkaiWorld *v2; // rsi
  hkaiPathRequestInfoOwner *v3; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // r8
  signed __int64 v9; // rbx
  int v10; // edx
  __int64 v11; // rcx
  hkaiNavMeshPathRequestInfo *v12; // r9
  hkaiPathRequestInfoOwner **v13; // rax
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx

  v2 = this;
  v3 = owner;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtlinearSearch";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = v2->m_navMeshPathRequests.m_size;
  v9 = 0i64;
  v10 = 0;
  v11 = 0i64;
  if ( v8 > 0 )
  {
    v12 = v2->m_navMeshPathRequests.m_data;
    v13 = (hkaiPathRequestInfoOwner **)&v12->m_markedForDeletion;
    while ( *(v13 - 1) != v3 || *(_BYTE *)v13 )
    {
      ++v11;
      ++v10;
      v13 += 7;
      if ( v11 >= v8 )
        goto LABEL_10;
    }
    v9 = (signed __int64)&v12[v10];
  }
LABEL_10:
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v16 = __rdtsc();
    v17 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v14[1] = v17;
  }
  return (hkaiNavMeshPathRequestInfo *)v9;
}

// File Line: 112
// RVA: 0xC05C50
hkaiNavVolumePathRequestInfo *__fastcall hkaiWorld::getNavVolumePathRequest(hkaiWorld *this, hkaiPathRequestInfoOwner *owner)
{
  hkaiWorld *v2; // rsi
  hkaiPathRequestInfoOwner *v3; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // r8
  signed __int64 v9; // rbx
  int v10; // edx
  __int64 v11; // rcx
  hkaiNavVolumePathRequestInfo *v12; // r9
  hkaiPathRequestInfoOwner **v13; // rax
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx

  v2 = this;
  v3 = owner;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtlinearSearch";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = v2->m_navVolumePathRequests.m_size;
  v9 = 0i64;
  v10 = 0;
  v11 = 0i64;
  if ( v8 > 0 )
  {
    v12 = v2->m_navVolumePathRequests.m_data;
    v13 = (hkaiPathRequestInfoOwner **)&v12->m_markedForDeletion;
    while ( *(v13 - 1) != v3 || *(_BYTE *)v13 )
    {
      ++v11;
      ++v10;
      v13 += 7;
      if ( v11 >= v8 )
        goto LABEL_10;
    }
    v9 = (signed __int64)&v12[v10];
  }
LABEL_10:
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v16 = __rdtsc();
    v17 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v14[1] = v17;
  }
  return (hkaiNavVolumePathRequestInfo *)v9;
}

// File Line: 129
// RVA: 0xC05D40
hkaiNavMeshPathRequestInfo *__fastcall hkaiWorld::getNavMeshPathRequest(hkaiWorld *this, hkaiPathRequestInfoOwner *owner)
{
  return hkaiWorld::getNavMeshPathRequest(this, owner);
}

// File Line: 135
// RVA: 0xC05D50
hkaiNavVolumePathRequestInfo *__fastcall hkaiWorld::getNavVolumePathRequest(hkaiWorld *this, hkaiPathRequestInfoOwner *owner)
{
  return hkaiWorld::getNavVolumePathRequest(this, owner);
}

// File Line: 142
// RVA: 0xC05E40
void __fastcall hkaiWorld::incrementRequestPriorities(hkaiWorld *this)
{
  int v1; // edx
  int v2; // er8
  __int64 v3; // r9
  __int64 v4; // r8

  v1 = 0;
  v2 = 0;
  if ( this->m_navMeshPathRequests.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ++v2;
      ++v3;
      ++*((_DWORD *)&this->m_navMeshPathRequests.m_data[v3] - 6);
    }
    while ( v2 < this->m_navMeshPathRequests.m_size );
  }
  if ( this->m_navVolumePathRequests.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      ++v1;
      ++v4;
      ++*((_DWORD *)&this->m_navVolumePathRequests.m_data[v4] - 6);
    }
    while ( v1 < this->m_navVolumePathRequests.m_size );
  }
}

// File Line: 156
// RVA: 0xC071D0
void __fastcall prepareRequestArray_hkaiNavMeshPathRequestInfo_(hkArrayBase<hkaiNavMeshPathRequestInfo> *pathRequests, hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> *sortedRequests, hkaiWorld::PathType pathType)
{
  int v3; // ebp
  int v4; // er14
  hkaiWorld::PathType v5; // er13
  hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> *v6; // r15
  hkArrayBase<hkaiNavMeshPathRequestInfo> *v7; // rbx
  signed __int64 v8; // rsi
  signed __int64 v9; // r12
  hkaiNavMeshPathRequestInfo *v10; // rdi
  hkReferencedObject *v11; // rcx
  hkReferencedObject *v12; // rcx
  __int64 v13; // rcx
  signed __int64 v14; // rdx
  hkaiNavMeshPathRequestInfo *v15; // rax
  signed __int64 v16; // r8
  __int64 v17; // rcx
  signed int v18; // er8
  __int64 v19; // rdi
  signed __int64 v20; // rdx

  v3 = 0;
  v4 = pathRequests->m_size - 1;
  v5 = pathType;
  v6 = sortedRequests;
  v7 = pathRequests;
  if ( v4 >= 0 )
  {
    v8 = v4;
    v9 = v4;
    do
    {
      hkaiNavMeshPathRequestInfo::checkDeterminism(&v7->m_data[v9]);
      v10 = &v7->m_data[v8];
      if ( v10->m_markedForDeletion.m_bool )
      {
        v10->m_markedForDeletion.m_bool = 1;
        v11 = (hkReferencedObject *)&v10->m_input.m_pntr->vfptr;
        if ( v11 )
          hkReferencedObject::removeReference(v11);
        v10->m_input.m_pntr = 0i64;
        v12 = (hkReferencedObject *)&v10->m_output.m_pntr->vfptr;
        if ( v12 )
          hkReferencedObject::removeReference(v12);
        v10->m_output.m_pntr = 0i64;
        v7->m_data[v8].vfptr->__vecDelDtor(&v7->m_data[v8], 0i64);
        v13 = --v7->m_size;
        if ( (_DWORD)v13 != v4 )
        {
          v14 = 7i64;
          v15 = &v7->m_data[v8];
          v16 = (char *)&v7->m_data[v13] - (char *)v15;
          do
          {
            v17 = *(__int64 *)((char *)&v15->vfptr + v16);
            v15 = (hkaiNavMeshPathRequestInfo *)((char *)v15 + 8);
            *(_QWORD *)&v15[-1].m_markedForDeletion.m_bool = v17;
            --v14;
          }
          while ( v14 );
        }
      }
      --v9;
      --v8;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v18 = v7->m_size;
  if ( v18 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiNavVolumePathRequestInfo,hkAlgorithm::less<hkaiNavVolumePathRequestInfo>>(
      (hkaiNavVolumePathRequestInfo *)v7->m_data,
      0,
      v18 - 1,
      0);
  if ( v7->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      if ( !v7->m_data[v19].m_output.m_pntr )
      {
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 16);
        v20 = (signed __int64)&v6->m_data[v6->m_size++];
        *(_DWORD *)(v20 + 8) = v5;
        *(_DWORD *)(v20 + 12) = v7->m_data[v19].m_priority;
        *(_QWORD *)v20 = &v7->m_data[v3];
      }
      ++v3;
      ++v19;
    }
    while ( v3 < v7->m_size );
  }
}

// File Line: 184
// RVA: 0xC070E0
void __fastcall hkaiWorld::prepareRequestArray(hkaiWorld *this, hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> *sortedRequests)
{
  hkaiWorld *v2; // rsi
  hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> *v3; // rdi
  signed int v4; // er8
  __int64 v5; // rbx
  signed int v6; // edx
  int *v7; // rcx
  int v8; // eax
  int v9; // eax
  int v10; // er9
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = this;
  v3 = sortedRequests;
  prepareRequestArray_hkaiNavMeshPathRequestInfo_(
    (hkArrayBase<hkaiNavMeshPathRequestInfo> *)&this->m_navMeshPathRequests.m_data,
    sortedRequests,
    0);
  prepareRequestArray_hkaiNavVolumePathRequestInfo_(
    (hkArrayBase<hkaiNavVolumePathRequestInfo> *)&v2->m_navVolumePathRequests.m_data,
    v3,
    PATH_TYPE_NAVVOLUME);
  v4 = v3->m_size;
  if ( v4 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiWorld::SortedRequest,hkAlgorithm::less<hkaiWorld::SortedRequest>>(
      v3->m_data,
      0,
      v4 - 1,
      0);
  v5 = v2->m_maxRequestsPerStep;
  v6 = v3->m_size;
  if ( (signed int)v5 < v6 )
  {
    v7 = &v3->m_data[v5].m_priority;
    while ( *v7 >= v2->m_priorityThreshold )
    {
      LODWORD(v5) = v5 + 1;
      v7 += 4;
      if ( (signed int)v5 >= v6 )
        return;
    }
    v8 = v3->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < (signed int)v5 )
    {
      v9 = 2 * v8;
      v10 = v5;
      if ( (signed int)v5 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v10, 16);
    }
    v3->m_size = v5;
  }
}

// File Line: 240
// RVA: 0xC074F0
__int64 __fastcall PathSearchJobManager::_findNavMeshJobIndex(PathSearchJobManager *this, hkaiPathfindingUtil::FindPathInput *input)
{
  int v2; // esi
  hkaiPathfindingUtil::FindPathInput *v3; // r15
  PathSearchJobManager *v4; // rdi
  unsigned int v5; // ebx
  hkaiNavMeshAStarJob *v6; // r14
  __m128 *v7; // rdx
  __int128 v8; // xmm7
  __m128 v9; // xmm1
  __int128 v10; // xmm8
  __int128 v11; // xmm9
  __m128i v12; // xmm2
  hkaiNavMeshAStarJob *v13; // rdx
  signed __int64 v14; // rax
  __int64 result; // rax
  hkJob v16; // [rsp+20h] [rbp-E8h]
  __int128 v17; // [rsp+40h] [rbp-C8h]
  __int128 v18; // [rsp+80h] [rbp-88h]
  __int128 v19; // [rsp+90h] [rbp-78h]
  __int128 v20; // [rsp+A0h] [rbp-68h]

  v2 = this->m_meshCommands.m_size;
  v3 = input;
  v4 = this;
  v5 = 0;
  if ( v2 <= 0 )
  {
LABEL_5:
    v7 = (__m128 *)v4->m_world;
    v16.m_threadAffinity = -1;
    v8 = *(_OWORD *)&v3->m_searchParameters.m_edgeFilter;
    v17 = *(_OWORD *)v3->m_searchParameters.m_up.m_vec;
    *(_WORD *)&v16.m_jobSubType = 2305;
    v16.m_jobSpuType.m_storage = 1;
    v16.m_size = 144;
    *(_QWORD *)&v18 = *(_QWORD *)&v3->m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes;
    v9 = _mm_mul_ps(v7[1], (__m128)xmmword_141A71390);
    v10 = *(_OWORD *)&v3->m_searchParameters.m_heuristicWeight;
    v11 = *(_OWORD *)&v3->m_searchParameters.m_searchCapsuleRadius;
    DWORD2(v18) = 100000;
    LODWORD(v20) = 0;
    v19 = *(unsigned __int64 *)(v7[2].m128_u64[0] + 32);
    v12 = _mm_add_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
              _mm_cvttps_epi32(v9)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    LOWORD(v17) = _mm_extract_epi16(v12, 1);
    WORD1(v17) = _mm_extract_epi16(v12, 3);
    WORD2(v17) = _mm_extract_epi16(v12, 5);
    if ( v4->m_meshJobs.m_size == (v4->m_meshJobs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 144);
    v13 = &v4->m_meshJobs.m_data[v4->m_meshJobs.m_size];
    if ( v13 )
    {
      v13->0 = v16;
      *(_OWORD *)&v13->m_semaphore = 0i64;
      *(_OWORD *)v13->m_searchParameters.m_up.m_vec = v17;
      *(_OWORD *)&v13->m_searchParameters.m_edgeFilter = v8;
      *(_OWORD *)&v13->m_searchParameters.m_heuristicWeight = v10;
      *(_OWORD *)&v13->m_searchParameters.m_searchCapsuleRadius = v11;
      *(_OWORD *)&v13->m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes = v18;
      *(_OWORD *)&v13->m_streamingSectionInfo = v19;
      *(_OWORD *)&v13->m_numCommands = v20;
    }
    ++v4->m_meshJobs.m_size;
    if ( v4->m_meshCommands.m_size == (v4->m_meshCommands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v4->m_meshCommands, 16);
    v14 = (signed __int64)&v4->m_meshCommands.m_data[v4->m_meshCommands.m_size];
    if ( v14 )
    {
      *(_QWORD *)v14 = 0i64;
      *(_DWORD *)(v14 + 8) = 0;
      *(_DWORD *)(v14 + 12) = 2147483648;
    }
    ++v4->m_meshCommands.m_size;
    result = (unsigned int)(v4->m_meshJobs.m_size - 1);
  }
  else
  {
    v6 = this->m_meshJobs.m_data;
    while ( !hkaiNavMeshPathSearchParameters::operator==(&v6[v5].m_searchParameters, &v3->m_searchParameters) )
    {
      if ( (signed int)++v5 >= v2 )
        goto LABEL_5;
    }
    result = v5;
  }
  return result;
}

// File Line: 264
// RVA: 0xC07760
__int64 __fastcall PathSearchJobManager::_findNavVolumeJobIndex(PathSearchJobManager *this, hkaiVolumePathfindingUtil::FindPathInput *input)
{
  __int64 v2; // r11
  PathSearchJobManager *v3; // rdi
  unsigned int v4; // er10
  __int64 v5; // r9
  float *v6; // r8
  __int128 v7; // xmm7
  __int128 v8; // xmm8
  hkaiNavVolumeAStarJob *v9; // rax
  signed __int64 v10; // rax
  __int64 result; // rax
  hkJob v12; // [rsp+20h] [rbp-A8h]
  __int128 v13; // [rsp+60h] [rbp-68h]
  __int128 v14; // [rsp+70h] [rbp-58h]
  __int128 v15; // [rsp+80h] [rbp-48h]

  v2 = this->m_volumeJobs.m_size;
  v3 = this;
  v4 = 0;
  v5 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_8:
    v12.m_threadAffinity = -1;
    *(hkaiSearchParameters::BufferSizes *)&v13 = input->m_searchParameters.m_bufferSizes;
    v7 = *(_OWORD *)input->m_searchParameters.m_up.m_vec;
    v8 = *(_OWORD *)&input->m_searchParameters.m_edgeFilter;
    *(_WORD *)&v12.m_jobSubType = 2560;
    v12.m_jobSpuType.m_storage = 1;
    v12.m_size = 112;
    DWORD2(v13) = 100000;
    v14 = (unsigned __int64)this->m_world->m_streamingCollection.m_pntr->m_instances.m_data;
    LODWORD(v15) = 0;
    if ( this->m_volumeJobs.m_size == (this->m_volumeJobs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &this->m_volumeJobs, 112);
    v9 = &v3->m_volumeJobs.m_data[v3->m_volumeJobs.m_size];
    if ( v9 )
    {
      v9->0 = v12;
      *(_OWORD *)&v9->m_semaphore = 0i64;
      *(_OWORD *)v9->m_searchParameters.m_up.m_vec = v7;
      *(_OWORD *)&v9->m_searchParameters.m_edgeFilter = v8;
      *(_OWORD *)&v9->m_searchParameters.m_bufferSizes.m_maxOpenSetSizeBytes = v13;
      *(_OWORD *)&v9->m_streamingSectionInfo = v14;
      *(_OWORD *)&v9->m_numCommands = v15;
    }
    ++v3->m_volumeJobs.m_size;
    if ( v3->m_volumeCommands.m_size == (v3->m_volumeCommands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &v3->m_volumeCommands,
        16);
    v10 = (signed __int64)&v3->m_volumeCommands.m_data[v3->m_volumeCommands.m_size];
    if ( v10 )
    {
      *(_QWORD *)v10 = 0i64;
      *(_DWORD *)(v10 + 8) = 0;
      *(_DWORD *)(v10 + 12) = 2147483648;
    }
    ++v3->m_volumeCommands.m_size;
    result = (unsigned int)(v3->m_volumeJobs.m_size - 1);
  }
  else
  {
    v6 = (float *)&this->m_volumeJobs.m_data->m_searchParameters.m_costModifier;
    while ( *(_OWORD *)v6 != *(_OWORD *)&input->m_searchParameters.m_costModifier
         || input->m_searchParameters.m_lineOfSightFlags.m_storage != *((_BYTE *)v6 + 16)
         || input->m_searchParameters.m_heuristicWeight != v6[5]
         || *((_QWORD *)v6 + 3) != *(_QWORD *)&input->m_searchParameters.m_bufferSizes )
    {
      ++v5;
      ++v4;
      v6 += 28;
      if ( v5 >= v2 )
        goto LABEL_8;
    }
    result = v4;
  }
  return result;
}

// File Line: 290
// RVA: 0xC07B90
void __fastcall reorderPathfindingCommands_hkaiNavVolumeAStarCommand_(hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *commands, const int jobSize)
{
  int v2; // ebx
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v3; // r15
  hkRelocationInfo::Import *v4; // r11
  int v5; // eax
  int v6; // edx
  __int64 v7; // r12
  int v8; // er9
  int v9; // eax
  signed __int64 v10; // rcx
  __int64 v11; // rdx
  signed __int64 v12; // rcx
  char *v13; // rcx
  __int64 v14; // rsi
  int v15; // er10
  __int64 v16; // r14
  int v17; // edi
  __int64 v18; // r8
  __int64 v19; // rbp
  hkRelocationInfo::Import *v20; // rcx
  hkRelocationInfo::Import *v21; // rdx
  int v22; // eax
  char *array; // [rsp+30h] [rbp-38h]
  int v24; // [rsp+38h] [rbp-30h]
  int v25; // [rsp+3Ch] [rbp-2Ch]
  hkResult result; // [rsp+78h] [rbp+10h]

  v2 = commands->m_size;
  v3 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)commands;
  v4 = 0i64;
  v5 = (v2 + jobSize - 1) / jobSize;
  v6 = 0;
  array = 0i64;
  v25 = 2147483648;
  v24 = 0;
  v7 = v5;
  if ( v2 > 0 )
  {
    v8 = v2;
    if ( v2 < 0 )
      v8 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v8, 112);
    v6 = v24;
    v4 = (hkRelocationInfo::Import *)array;
  }
  v9 = v2 - v6;
  v10 = 112i64 * v6;
  v11 = v2 - v6;
  v12 = v10 + 64;
  if ( v9 > 0 )
  {
    v13 = (char *)v4 + v12;
    do
    {
      if ( v13 != (char *)64 )
        *(_QWORD *)v13 = 0i64;
      v13 += 112;
      --v11;
    }
    while ( v11 );
    v4 = (hkRelocationInfo::Import *)array;
  }
  v24 = v2;
  if ( (signed int)v7 > 0 )
  {
    v14 = 0i64;
    v15 = v7;
    v16 = (unsigned int)v7;
    do
    {
      v17 = (v15 + v2 - 1) / v15;
      if ( v17 > 0 )
      {
        v18 = v14;
        v19 = (unsigned int)v17;
        do
        {
          v20 = v3->m_data;
          v21 = v4;
          v4 += 7;
          *v21 = *(hkRelocationInfo::Import *)((char *)v3->m_data + v18);
          v21[1] = *(hkRelocationInfo::Import *)((char *)v20 + v18 + 16);
          v21[2].m_fromOffset = *(int *)((char *)&v20[2].m_fromOffset + v18);
          *(&v21[2].m_fromOffset + 1) = *(int *)((char *)&v20[2].m_fromOffset + v18 + 4);
          v21[2].m_identifier = *(const char **)((char *)&v20[2].m_identifier + v18);
          *(_QWORD *)&v21[3].m_fromOffset = *(_QWORD *)((char *)&v20[3].m_fromOffset + v18);
          LODWORD(v21[3].m_identifier) = *(_DWORD *)((char *)&v20[3].m_identifier + v18);
          HIDWORD(v21[3].m_identifier) = *(_DWORD *)((char *)&v20[3].m_identifier + v18 + 4);
          *(_QWORD *)&v21[4].m_fromOffset = *(_QWORD *)((char *)&v20[4].m_fromOffset + v18);
          v21[4].m_identifier = *(const char **)((char *)&v20[4].m_identifier + v18);
          *(_QWORD *)&v21[5].m_fromOffset = *(_QWORD *)((char *)&v20[5].m_fromOffset + v18);
          LODWORD(v21[5].m_identifier) = *(_DWORD *)((char *)&v20[5].m_identifier + v18);
          *(_QWORD *)&v21[6].m_fromOffset = *(_QWORD *)((char *)&v20[6].m_fromOffset + v18);
          v22 = *(_DWORD *)((char *)&v20[6].m_identifier + v18);
          v18 += 112 * v7;
          LODWORD(v21[6].m_identifier) = v22;
          --v19;
        }
        while ( v19 );
      }
      v2 -= v17;
      --v15;
      v14 += 112i64;
      --v16;
    }
    while ( v16 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    v3,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  v24 = 0;
  if ( v25 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      112 * (v25 & 0x3FFFFFFF));
}

// File Line: 317
// RVA: 0xC07DC0
void __fastcall _firePathRequestProcessedCallbacks<hkaiNavMeshPathRequestInfo>(hkArrayBase<hkaiWorld::Listener *> *listeners, hkaiNavMeshPathRequestInfo *pathRequest)
{
  hkArrayBase<hkaiWorld::Listener *> *v2; // rsi
  hkaiNavMeshPathRequestInfo *v3; // rbp
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  int v8; // ebx
  __int64 v9; // rdi
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx

  v2 = listeners;
  v3 = pathRequest;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "Ttcallbacks";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = 0;
  if ( v2->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      ((void (__fastcall *)(hkaiWorld::Listener *, hkaiNavMeshPathRequestInfo *, _QWORD *))v2->m_data[v9]->vfptr->pathRequestProcessedCallback)(
        v2->m_data[v9],
        v3,
        v4);
      ++v8;
      ++v9;
    }
    while ( v8 < v2->m_size );
  }
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "Et";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
}

// File Line: 326
// RVA: 0xC07950
void __fastcall generateFailureOutput(hkaiPathfindingUtil::FindPathOutput *output)
{
  output->m_outputParameters.m_goalIndex = -1;
  output->m_outputParameters.m_numIterations = 0;
  output->m_outputParameters.m_status.m_storage = 5;
}

// File Line: 334
// RVA: 0xC06430
void __fastcall hkaiWorld::stepPathSearchesMT(hkaiWorld *this, hkJobQueue *jobQueue, hkJobThreadPool *threadPool)
{
  hkJobThreadPool *v3; // rdi
  hkaiWorld *v4; // r12
  _QWORD *v5; // r9
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // r13
  hkaiWorld::PathType v15; // edx
  _QWORD *v16; // rsi
  __int64 v17; // rcx
  __int64 v18; // r14
  _QWORD **v19; // rax
  __int64 v20; // rax
  hkReferencedObject *v21; // rbx
  hkReferencedObject *v22; // rcx
  int v23; // eax
  hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *v24; // rdi
  __int64 v25; // rbx
  int v26; // er9
  int v27; // eax
  int v28; // eax
  signed __int64 v29; // rax
  int v30; // eax
  signed __int64 v31; // rbx
  signed int v32; // er8
  _DWORD *v33; // rcx
  __int128 *v34; // rdx
  __int128 v35; // xmm0
  int v36; // eax
  hkaiPathfindingUtil::FindPathOutput *v37; // rdi
  int v38; // er9
  int v39; // eax
  int v40; // eax
  int v41; // er9
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v42; // rsi
  int v43; // eax
  int v44; // eax
  void *v45; // rbx
  __int64 v46; // rcx
  bool v47; // si
  __int64 v48; // r14
  _QWORD **v49; // rax
  __int64 v50; // rax
  hkReferencedObject *v51; // rcx
  int v52; // eax
  hkArray<hkaiNavMeshAStarCommand,hkContainerTempAllocator> *v53; // rsi
  __int64 v54; // rbx
  int v55; // er9
  int v56; // eax
  int v57; // eax
  signed __int64 v58; // rax
  int v59; // eax
  _DWORD *v60; // rcx
  __int128 v61; // xmm0
  int v62; // eax
  int v63; // er9
  int v64; // eax
  int v65; // eax
  int v66; // er9
  int v67; // eax
  int v68; // eax
  int v69; // ebx
  int v70; // eax
  _QWORD *v71; // r8
  _QWORD *v72; // rcx
  unsigned __int64 v73; // rax
  signed __int64 v74; // rcx
  signed __int64 v75; // rdx
  __int64 v76; // r8
  hkResultEnum v77; // er9
  char *v78; // rsi
  hkArray<hkaiNavMeshAStarCommand,hkContainerTempAllocator> *v79; // r13
  int v80; // er14
  int v81; // er15
  int v82; // edi
  __int64 v83; // r12
  int v84; // eax
  int v85; // ebx
  signed __int64 v86; // rdx
  __int64 v87; // r8
  hkResultEnum v88; // er9
  char *v89; // rsi
  hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *v90; // r13
  int v91; // er14
  int v92; // er15
  int v93; // edi
  __int64 v94; // r12
  int v95; // eax
  int v96; // ebx
  _QWORD *v97; // r8
  _QWORD *v98; // rcx
  unsigned __int64 v99; // rax
  signed __int64 v100; // rcx
  int v101; // er13
  __int64 v102; // rdi
  hkaiWorld::PathType v103; // edx
  void *v104; // rbx
  hkaiVolumePathfindingUtil::FindPathOutput *v105; // rsi
  int v106; // er15
  int v107; // eax
  int v108; // ecx
  int v109; // ebx
  int v110; // ecx
  int v111; // er9
  int v112; // eax
  int v113; // eax
  int v114; // er9
  void *v115; // rbx
  hkaiPathfindingUtil::FindPathOutput *v116; // rsi
  char v117; // bl
  int v118; // er15
  int v119; // ebx
  int v120; // eax
  int v121; // eax
  int v122; // er9
  int v123; // eax
  int v124; // eax
  int v125; // er9
  _QWORD *v126; // r8
  _QWORD *v127; // rcx
  unsigned __int64 v128; // rax
  signed __int64 v129; // rcx
  int v130; // [rsp+30h] [rbp-79h]
  int v131; // [rsp+30h] [rbp-79h]
  int v132; // [rsp+30h] [rbp-79h]
  hkResult v133[2]; // [rsp+38h] [rbp-71h]
  unsigned int validGoalsMask[2]; // [rsp+40h] [rbp-69h]
  hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> sortedRequests; // [rsp+48h] [rbp-61h]
  hkResult v136; // [rsp+58h] [rbp-51h]
  hkResult v137; // [rsp+5Ch] [rbp-4Dh]
  hkResult v138; // [rsp+60h] [rbp-49h]
  hkResult result; // [rsp+64h] [rbp-45h]
  hkResult v140; // [rsp+68h] [rbp-41h]
  PathSearchJobManager v141; // [rsp+70h] [rbp-39h]
  hkaiWorld *v142; // [rsp+110h] [rbp+67h]
  hkJobQueue *v143; // [rsp+118h] [rbp+6Fh]
  hkJobThreadPool *v144; // [rsp+120h] [rbp+77h]
  hkResult v145; // [rsp+128h] [rbp+7Fh]

  v144 = threadPool;
  v143 = jobQueue;
  v142 = this;
  v3 = threadPool;
  v4 = this;
  if ( !this->m_navMeshPathRequests.m_size && !this->m_navVolumePathRequests.m_size )
    return;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = v5[1];
  if ( v6 < v5[3] )
  {
    *(_QWORD *)v6 = "LtstepPathSearchesMT";
    *(_QWORD *)(v6 + 16) = "StsortRequests";
    v7 = __rdtsc();
    *(_DWORD *)(v6 + 8) = v7;
    v5[1] = v6 + 24;
  }
  v4->m_isPathRequestArrayLocked.m_bool = 1;
  sortedRequests.m_data = 0i64;
  sortedRequests.m_size = 0;
  sortedRequests.m_capacityAndFlags = 2147483648;
  hkaiWorld::prepareRequestArray(v4, &sortedRequests);
  if ( sortedRequests.m_size )
  {
    v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v10 = (_QWORD *)v8[1];
    v11 = v8;
    if ( (unsigned __int64)v10 < v8[3] )
    {
      *v10 = "StsetupJobs";
      v12 = __rdtsc();
      v9 = (unsigned __int64)HIDWORD(v12) << 32;
      v13 = (signed __int64)(v10 + 2);
      *(_DWORD *)(v13 - 8) = v12;
      v11[1] = v13;
    }
    v141.m_meshJobs.m_capacityAndFlags = 2147483648;
    v141.m_meshCommands.m_capacityAndFlags = 2147483648;
    v141.m_meshJobs.m_data = 0i64;
    v141.m_meshJobs.m_size = 0;
    v141.m_meshCommands.m_data = 0i64;
    v141.m_meshCommands.m_size = 0;
    v141.m_volumeJobs.m_data = 0i64;
    v141.m_volumeJobs.m_size = 0;
    v141.m_volumeJobs.m_capacityAndFlags = 2147483648;
    v141.m_volumeCommands.m_data = 0i64;
    v141.m_volumeCommands.m_size = 0;
    v141.m_volumeCommands.m_capacityAndFlags = 2147483648;
    v141.m_world = v4;
    v130 = 0;
    v145.m_enum = -1;
    if ( sortedRequests.m_size <= 0 )
    {
LABEL_83:
      v69 = sortedRequests.m_size;
      if ( v4->m_maxEstimatedIterationsPerStep >= 0 && sortedRequests.m_size > 0 )
      {
        v70 = ((__int64 (__fastcall *)(hkJobThreadPool *, unsigned __int64, _QWORD *))v3->vfptr[3].__vecDelDtor)(
                v3,
                v9,
                v11);
        v145.m_enum = ((v70 + v69) / (v70 + 1) + v4->m_maxEstimatedIterationsPerStep - 1) / ((v70 + v69) / (v70 + 1));
      }
      v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v72 = (_QWORD *)v71[1];
      if ( (unsigned __int64)v72 < v71[3] )
      {
        *v72 = "StprocessJobs";
        v73 = __rdtsc();
        v74 = (signed __int64)(v72 + 2);
        *(_DWORD *)(v74 - 8) = v73;
        v71[1] = v74;
      }
      v131 = 0;
      if ( v141.m_meshJobs.m_size > 0 )
      {
        v75 = 0i64;
        v76 = 0i64;
        *(_QWORD *)validGoalsMask = 0i64;
        *(_QWORD *)&v133[0].m_enum = 0i64;
        do
        {
          v77 = v145.m_enum;
          v78 = &v141.m_meshJobs.m_data->m_jobSubType + v76;
          v79 = (hkArray<hkaiNavMeshAStarCommand,hkContainerTempAllocator> *)((char *)v141.m_meshCommands.m_data + v75);
          if ( (signed int)v145.m_enum >= 0 )
          {
            reorderPathfindingCommands_hkaiNavMeshAStarCommand_(v79, v4->m_numPathRequestsPerJob);
            v76 = *(_QWORD *)validGoalsMask;
            v77 = v145.m_enum;
          }
          v80 = v79->m_size;
          v81 = 0;
          v82 = (v4->m_numPathRequestsPerJob + v80 - 1) / v4->m_numPathRequestsPerJob;
          if ( v82 > 0 )
          {
            v83 = (unsigned int)v82;
            do
            {
              *((_QWORD *)v78 + 15) = &v79->m_data[v81];
              v84 = (v82 + v80 - 1) / v82;
              v85 = v84;
              *((_DWORD *)v78 + 32) = v84;
              if ( (signed int)v77 >= 0 )
                *((_DWORD *)v78 + 26) = v77 * v84;
              hkJobQueue::addJob(v143, (hkJob *)v78, 0);
              v77 = v145.m_enum;
              v81 += v85;
              v80 -= v85;
              --v82;
              --v83;
            }
            while ( v83 );
            v76 = *(_QWORD *)validGoalsMask;
            v4 = v142;
          }
          v76 += 144i64;
          v75 = *(_QWORD *)&v133[0].m_enum + 16i64;
          *(_QWORD *)validGoalsMask = v76;
          ++v131;
          *(_QWORD *)&v133[0].m_enum += 16i64;
        }
        while ( v131 < v141.m_meshJobs.m_size );
      }
      v132 = 0;
      if ( v141.m_volumeJobs.m_size > 0 )
      {
        v86 = 0i64;
        v87 = 0i64;
        *(_QWORD *)validGoalsMask = 0i64;
        *(_QWORD *)&v133[0].m_enum = 0i64;
        do
        {
          v88 = v145.m_enum;
          v89 = &v141.m_volumeJobs.m_data->m_jobSubType + v87;
          v90 = (hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *)((char *)v141.m_volumeCommands.m_data
                                                                              + v86);
          if ( (signed int)v145.m_enum >= 0 )
          {
            reorderPathfindingCommands_hkaiNavVolumeAStarCommand_(v90, v4->m_numPathRequestsPerJob);
            v87 = *(_QWORD *)validGoalsMask;
            v88 = v145.m_enum;
          }
          v91 = v90->m_size;
          v92 = 0;
          v93 = (v4->m_numPathRequestsPerJob + v91 - 1) / v4->m_numPathRequestsPerJob;
          if ( v93 > 0 )
          {
            v94 = (unsigned int)v93;
            do
            {
              *((_QWORD *)v89 + 11) = &v90->m_data[v92];
              v95 = (v93 + v91 - 1) / v93;
              v96 = v95;
              *((_DWORD *)v89 + 24) = v95;
              if ( (signed int)v88 >= 0 )
                *((_DWORD *)v89 + 18) = v88 * v95;
              hkJobQueue::addJob(v143, (hkJob *)v89, 0);
              v88 = v145.m_enum;
              v92 += v96;
              v91 -= v96;
              --v93;
              --v94;
            }
            while ( v94 );
            v87 = *(_QWORD *)validGoalsMask;
            v4 = v142;
          }
          v87 += 112i64;
          v86 = *(_QWORD *)&v133[0].m_enum + 16i64;
          *(_QWORD *)validGoalsMask = v87;
          ++v132;
          *(_QWORD *)&v133[0].m_enum += 16i64;
        }
        while ( v132 < v141.m_volumeJobs.m_size );
      }
      ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, signed __int64))v144->vfptr[5].__first_virtual_table_function__)(
        v144,
        v143,
        9i64);
      hkJobQueue::processAllJobs(v143, 1);
      ((void (__fastcall *)(hkJobThreadPool *))v144->vfptr[2].__vecDelDtor)(v144);
      v97 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v98 = (_QWORD *)v97[1];
      if ( (unsigned __int64)v98 < v97[3] )
      {
        *v98 = "StprocessResults";
        v99 = __rdtsc();
        v100 = (signed __int64)(v98 + 2);
        *(_DWORD *)(v100 - 8) = v99;
        v97[1] = v100;
      }
      v101 = 0;
      if ( sortedRequests.m_size > 0 )
      {
        v102 = 0i64;
        while ( 1 )
        {
          v103 = sortedRequests.m_data[v102].m_pathType;
          if ( v103 )
          {
            if ( v103 == 1 )
            {
              v104 = sortedRequests.m_data[v102].m_request;
              _firePathRequestProcessedCallbacks<hkaiNavVolumePathRequestInfo>(
                (hkArrayBase<hkaiWorld::Listener *> *)&v4->m_listeners.m_data,
                (hkaiNavVolumePathRequestInfo *)sortedRequests.m_data[v102].m_request);
              v105 = (hkaiVolumePathfindingUtil::FindPathOutput *)*((_QWORD *)v104 + 3);
              if ( v105 )
              {
                v106 = hkaiPathUtil::_getPathLength(v105->m_visitedCells.m_data, v142->m_maxPathSearchEdgesOut);
                v107 = hkaiPathUtil::_getNumPathPoints(v105->m_pathOut.m_data, v142->m_maxPathSearchPointsOut);
                v108 = v105->m_visitedCells.m_capacityAndFlags & 0x3FFFFFFF;
                v109 = v107;
                if ( v108 >= v106 )
                {
                  v145.m_enum = 0;
                }
                else
                {
                  v110 = 2 * v108;
                  v111 = v106;
                  if ( v106 < v110 )
                    v111 = v110;
                  hkArrayUtil::_reserve(
                    &v145,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &v105->m_visitedCells,
                    v111,
                    4);
                }
                v105->m_visitedCells.m_size = v106;
                v112 = v105->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
                if ( v112 >= v109 )
                {
                  v133[0].m_enum = 0;
                  v105->m_pathOut.m_size = v109;
                  hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(v105);
                }
                else
                {
                  v113 = 2 * v112;
                  v114 = v109;
                  if ( v109 < v113 )
                    v114 = v113;
                  hkArrayUtil::_reserve(
                    v133,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &v105->m_pathOut,
                    v114,
                    48);
                  v105->m_pathOut.m_size = v109;
                  hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(v105);
                }
              }
            }
          }
          else
          {
            v115 = sortedRequests.m_data[v102].m_request;
            _firePathRequestProcessedCallbacks<hkaiNavMeshPathRequestInfo>(
              (hkArrayBase<hkaiWorld::Listener *> *)&v4->m_listeners.m_data,
              (hkaiNavMeshPathRequestInfo *)sortedRequests.m_data[v102].m_request);
            v116 = (hkaiPathfindingUtil::FindPathOutput *)*((_QWORD *)v115 + 3);
            if ( v116 )
            {
              v117 = *(_BYTE *)(*((_QWORD *)v115 + 2) + 113i64);
              v118 = hkaiPathUtil::_getPathLength(v116->m_visitedEdges.m_data, v4->m_maxPathSearchEdgesOut);
              if ( v117 & 1 )
                v119 = hkaiPathUtil::_getNumPathPoints(v116->m_pathOut.m_data, v4->m_maxPathSearchPointsOut);
              else
                v119 = 0;
              v120 = v116->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v120 >= v118 )
              {
                v137.m_enum = 0;
              }
              else
              {
                v121 = 2 * v120;
                v122 = v118;
                if ( v118 < v121 )
                  v122 = v121;
                hkArrayUtil::_reserve(
                  &v137,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v116->m_visitedEdges,
                  v122,
                  4);
              }
              v116->m_visitedEdges.m_size = v118;
              v123 = v116->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v123 >= v119 )
              {
                v136.m_enum = 0;
              }
              else
              {
                v124 = 2 * v123;
                v125 = v119;
                if ( v119 < v124 )
                  v125 = v124;
                hkArrayUtil::_reserve(
                  &v136,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v116->m_pathOut,
                  v125,
                  48);
              }
              v116->m_pathOut.m_size = v119;
              hkaiPathfindingUtil::FindPathOutput::checkDeterminism(v116);
            }
          }
          ++v101;
          ++v102;
          if ( v101 >= sortedRequests.m_size )
            break;
          v4 = v142;
        }
      }
      hkaiWorld::incrementRequestPriorities(v142);
      v142->m_isPathRequestArrayLocked.m_bool = 0;
      PathSearchJobManager::~PathSearchJobManager(&v141);
      goto LABEL_145;
    }
    v14 = 0i64;
    while ( 1 )
    {
      v15 = sortedRequests.m_data[v14].m_pathType;
      if ( v15 == PATH_TYPE_NAVMESH )
        break;
      v9 = (unsigned int)(v15 - 1);
      if ( !(_DWORD)v9 )
      {
        v16 = sortedRequests.m_data[v14].m_request;
        v17 = v16[5];
        if ( v17 )
          (*(void (__fastcall **)(__int64, _QWORD *, _QWORD *))(*(_QWORD *)v17 + 8i64))(v17, v16, v11);
        v18 = v16[2];
        v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v20 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 64i64);
        v21 = (hkReferencedObject *)v20;
        if ( v20 )
        {
          *(_DWORD *)(v20 + 8) = 0x1FFFF;
          *(_QWORD *)v20 = &hkaiVolumePathfindingUtil::FindPathOutput::`vftable;
          *(_DWORD *)(v20 + 28) = 2147483648;
          *(_QWORD *)(v20 + 16) = 0i64;
          *(_DWORD *)(v20 + 24) = 0;
          *(_QWORD *)(v20 + 32) = 0i64;
          *(_DWORD *)(v20 + 40) = 0;
          *(_DWORD *)(v20 + 44) = 2147483648;
          *(_DWORD *)(v20 + 48) = 0;
          *(_DWORD *)(v20 + 52) = -1;
          *(_DWORD *)(v20 + 56) = 2139095022;
          *(_WORD *)(v20 + 60) = 0;
        }
        else
        {
          v21 = 0i64;
        }
        v22 = (hkReferencedObject *)v16[3];
        if ( v22 && v22 != v21 )
          hkReferencedObject::removeReference(v22);
        v16[3] = v21;
        v23 = PathSearchJobManager::_findNavVolumeJobIndex(&v141, (hkaiVolumePathfindingUtil::FindPathInput *)v18);
        v24 = &v141.m_volumeCommands.m_data[v23];
        v25 = v24->m_size;
        v26 = v25 + 1;
        v27 = v24->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v27 >= (signed int)v25 + 1 )
        {
          result.m_enum = 0;
        }
        else
        {
          v28 = 2 * v27;
          if ( v26 < v28 )
            v26 = v28;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v24, v26, 112);
        }
        v29 = (signed __int64)&v24->m_data[v24->m_size];
        if ( v29 )
          *(_QWORD *)(v29 + 64) = 0i64;
        ++v24->m_size;
        v30 = *(_DWORD *)(v18 + 48);
        v31 = (signed __int64)&v24->m_data[v25];
        *(_OWORD *)v31 = *(_OWORD *)(v18 + 16);
        *(_DWORD *)(v31 + 32) = v30;
        v32 = *(_DWORD *)(v18 + 40);
        v33 = *(_DWORD **)(v18 + 56);
        v34 = *(__int128 **)(v18 + 32);
        if ( v32 == 1 )
        {
          v35 = *v34;
          *(_DWORD *)(v31 + 36) = *v33;
          *(_OWORD *)(v31 + 16) = v35;
          *(_DWORD *)(v31 + 56) = 1;
          goto LABEL_33;
        }
        if ( v32 <= 1 )
        {
          *(_DWORD *)(v31 + 56) = 0;
LABEL_33:
          *(_QWORD *)(v31 + 48) = 0i64;
          *(_QWORD *)(v31 + 40) = 0i64;
        }
        else
        {
          *(_OWORD *)(v31 + 16) = *v34;
          v36 = *v33;
          *(_QWORD *)(v31 + 40) = v34;
          *(_QWORD *)(v31 + 48) = v33;
          *(_DWORD *)(v31 + 36) = v36;
          *(_DWORD *)(v31 + 56) = v32;
        }
        *(_DWORD *)(v31 + 60) = *(_DWORD *)(v18 + 72);
        *(_QWORD *)(v31 + 64) = *(_QWORD *)(v18 + 76);
        hkaiVolumePathfindingUtil::FindPathInput::checkDeterminism((hkaiVolumePathfindingUtil::FindPathInput *)v18);
        v37 = (hkaiPathfindingUtil::FindPathOutput *)v16[3];
        v38 = v4->m_maxPathSearchEdgesOut;
        v39 = v37->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v39 >= v38 )
        {
          v140.m_enum = 0;
        }
        else
        {
          v40 = 2 * v39;
          if ( v38 < v40 )
            v38 = v40;
          hkArrayUtil::_reserve(
            &v140,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v37->m_visitedEdges,
            v38,
            4);
        }
        v41 = v4->m_maxPathSearchPointsOut;
        v42 = &v37->m_pathOut;
        v43 = v37->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v43 >= v41 )
        {
          v138.m_enum = 0;
        }
        else
        {
          v44 = 2 * v43;
          if ( v41 < v44 )
            v41 = v44;
          hkArrayUtil::_reserve(
            &v138,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v37->m_pathOut,
            v41,
            48);
        }
LABEL_44:
        *(_QWORD *)(v31 + 80) = v37->m_visitedEdges.m_data;
        *(_DWORD *)(v31 + 88) = v37->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
        *(_QWORD *)(v31 + 96) = v42->m_data;
        *(_DWORD *)(v31 + 104) = v37->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
        *(_QWORD *)(v31 + 72) = (char *)v37 + 48;
      }
LABEL_81:
      ++v14;
      if ( ++v130 >= sortedRequests.m_size )
      {
        v3 = v144;
        goto LABEL_83;
      }
    }
    v45 = sortedRequests.m_data[v14].m_request;
    v46 = *((_QWORD *)v45 + 5);
    v47 = v46 && (*(unsigned __int8 (__fastcall **)(__int64, void *, _QWORD *))(*(_QWORD *)v46 + 16i64))(v46, v45, v11);
    v48 = *((_QWORD *)v45 + 2);
    hkaiPathfindingUtil::FindPathInput::checkDeterminism(*((hkaiPathfindingUtil::FindPathInput **)v45 + 2));
    v49 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v50 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v49[11] + 8i64))(v49[11], 64i64);
    v37 = (hkaiPathfindingUtil::FindPathOutput *)v50;
    if ( v50 )
    {
      *(_DWORD *)(v50 + 8) = 0x1FFFF;
      *(_QWORD *)v50 = &hkaiPathfindingUtil::FindPathOutput::`vftable;
      *(_DWORD *)(v50 + 28) = 2147483648;
      *(_QWORD *)(v50 + 16) = 0i64;
      *(_DWORD *)(v50 + 24) = 0;
      *(_QWORD *)(v50 + 32) = 0i64;
      *(_DWORD *)(v50 + 40) = 0;
      *(_DWORD *)(v50 + 44) = 2147483648;
      *(_DWORD *)(v50 + 48) = 0;
      *(_DWORD *)(v50 + 52) = -1;
      *(_DWORD *)(v50 + 56) = 2139095022;
      *(_WORD *)(v50 + 60) = 0;
    }
    else
    {
      v37 = 0i64;
    }
    v51 = (hkReferencedObject *)*((_QWORD *)v45 + 3);
    if ( v51 && v51 != (hkReferencedObject *)v37 )
      hkReferencedObject::removeReference(v51);
    *((_QWORD *)v45 + 3) = v37;
    if ( !v47
      || !hkaiNavMeshSearchValidationUtils::validateFindPathInput(
            v4->m_streamingCollection.m_pntr,
            (hkaiPathfindingUtil::FindPathInput *)v48,
            validGoalsMask) )
    {
      generateFailureOutput(v37);
      goto LABEL_81;
    }
    v52 = PathSearchJobManager::_findNavMeshJobIndex(&v141, (hkaiPathfindingUtil::FindPathInput *)v48);
    v53 = &v141.m_meshCommands.m_data[v52];
    v54 = v53->m_size;
    v55 = v54 + 1;
    v56 = v53->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v56 >= (signed int)v54 + 1 )
    {
      v136.m_enum = 0;
    }
    else
    {
      v57 = 2 * v56;
      if ( v55 < v57 )
        v55 = v57;
      hkArrayUtil::_reserve(&v136, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v53, v55, 112);
    }
    v58 = (signed __int64)&v53->m_data[v53->m_size];
    if ( v58 )
      *(_QWORD *)(v58 + 64) = 0i64;
    ++v53->m_size;
    v59 = *(_DWORD *)(v48 + 48);
    v31 = (signed __int64)&v53->m_data[v54];
    *(_OWORD *)v31 = *(_OWORD *)(v48 + 16);
    *(_DWORD *)(v31 + 32) = v59;
    v11 = (_QWORD *)*(unsigned int *)(v48 + 40);
    v60 = *(_DWORD **)(v48 + 56);
    v9 = *(_QWORD *)(v48 + 32);
    if ( (_DWORD)v11 == 1 )
    {
      v61 = *(_OWORD *)v9;
      *(_DWORD *)(v31 + 36) = *v60;
      *(_OWORD *)(v31 + 16) = v61;
      *(_DWORD *)(v31 + 56) = 1;
    }
    else
    {
      if ( (signed int)v11 > 1 )
      {
        *(_OWORD *)(v31 + 16) = *(_OWORD *)v9;
        v62 = *v60;
        *(_QWORD *)(v31 + 40) = v9;
        *(_QWORD *)(v31 + 48) = v60;
        *(_DWORD *)(v31 + 36) = v62;
        *(_DWORD *)(v31 + 56) = (_DWORD)v11;
LABEL_70:
        *(_DWORD *)(v31 + 60) = *(_DWORD *)(v48 + 72);
        *(_QWORD *)(v31 + 64) = *(_QWORD *)(v48 + 76);
        v63 = v4->m_maxPathSearchEdgesOut;
        v64 = v37->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v64 >= v63 )
        {
          v137.m_enum = 0;
        }
        else
        {
          v65 = 2 * v64;
          if ( v63 < v65 )
            v63 = v65;
          hkArrayUtil::_reserve(
            &v137,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v37->m_visitedEdges,
            v63,
            4);
        }
        v66 = v4->m_maxPathSearchPointsOut;
        v42 = &v37->m_pathOut;
        v67 = v37->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v67 >= v66 )
        {
          v133[0].m_enum = 0;
        }
        else
        {
          v68 = 2 * v67;
          if ( v66 < v68 )
            v66 = v68;
          hkArrayUtil::_reserve(
            v133,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v37->m_pathOut,
            v66,
            48);
        }
        goto LABEL_44;
      }
      *(_DWORD *)(v31 + 56) = 0;
    }
    *(_QWORD *)(v31 + 48) = 0i64;
    *(_QWORD *)(v31 + 40) = 0i64;
    goto LABEL_70;
  }
  v4->m_isPathRequestArrayLocked.m_bool = 0;
LABEL_145:
  sortedRequests.m_size = 0;
  if ( sortedRequests.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sortedRequests.m_data,
      16 * sortedRequests.m_capacityAndFlags);
  sortedRequests.m_data = 0i64;
  sortedRequests.m_capacityAndFlags = 2147483648;
  v126 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v127 = (_QWORD *)v126[1];
  if ( (unsigned __int64)v127 < v126[3] )
  {
    *v127 = "lt";
    v128 = __rdtsc();
    v129 = (signed __int64)(v127 + 2);
    *(_DWORD *)(v129 - 8) = v128;
    v126[1] = v129;
  }
}

// File Line: 617
// RVA: 0xC06050
void __fastcall hkaiWorld::stepPathSearches(hkaiWorld *this)
{
  hkaiWorld *v1; // r13
  int v2; // er14
  int v3; // er12
  __int64 v4; // r15
  hkaiWorld::PathType v5; // ecx
  hkaiNavVolumePathRequestInfo *v6; // rdi
  _QWORD **v7; // rax
  __int64 v8; // rax
  hkaiVolumePathfindingUtil::FindPathOutput *v9; // rbx
  hkReferencedObject *v10; // rcx
  hkaiPathRequestInfoOwner *v11; // rcx
  hkaiVolumePathfindingUtil::FindPathInput *v12; // rsi
  int v13; // ecx
  hkBaseObjectVtbl *v14; // rax
  hkaiNavMeshPathRequestInfo *v15; // rdi
  _QWORD **v16; // rax
  __int64 v17; // rax
  hkReferencedObject *v18; // rcx
  hkaiPathRequestInfoOwner *v19; // rcx
  hkaiPathfindingUtil::FindPathInput *v20; // rsi
  int v21; // ecx
  int v22; // er8
  hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> sortedRequests; // [rsp+20h] [rbp-D8h]
  hkaiVolumePathfindingUtil::FindPathInput input; // [rsp+30h] [rbp-C8h]

  v1 = this;
  this->m_isPathRequestArrayLocked.m_bool = 1;
  sortedRequests.m_capacityAndFlags = 2147483648;
  sortedRequests.m_data = 0i64;
  sortedRequests.m_size = 0;
  hkaiWorld::prepareRequestArray(this, &sortedRequests);
  v2 = 0x7FFFFFFF;
  v3 = 0;
  if ( v1->m_maxEstimatedIterationsPerStep >= 0 )
    v2 = v1->m_maxEstimatedIterationsPerStep;
  if ( sortedRequests.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = sortedRequests.m_data[v4].m_pathType;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          v6 = (hkaiNavVolumePathRequestInfo *)sortedRequests.m_data[v4].m_request;
          v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v8 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 64i64);
          v9 = (hkaiVolumePathfindingUtil::FindPathOutput *)v8;
          if ( v8 )
          {
            *(_DWORD *)(v8 + 8) = 0x1FFFF;
            *(_QWORD *)v8 = &hkaiVolumePathfindingUtil::FindPathOutput::`vftable;
            *(_QWORD *)(v8 + 16) = 0i64;
            *(_DWORD *)(v8 + 24) = 0;
            *(_DWORD *)(v8 + 28) = 2147483648;
            *(_QWORD *)(v8 + 32) = 0i64;
            *(_DWORD *)(v8 + 40) = 0;
            *(_DWORD *)(v8 + 44) = 2147483648;
            *(_DWORD *)(v8 + 48) = 0;
            *(_DWORD *)(v8 + 52) = -1;
            *(_DWORD *)(v8 + 56) = 2139095022;
            *(_WORD *)(v8 + 60) = 0;
          }
          else
          {
            v9 = 0i64;
          }
          v10 = (hkReferencedObject *)&v6->m_output.m_pntr->vfptr;
          if ( v10 && v10 != (hkReferencedObject *)v9 )
            hkReferencedObject::removeReference(v10);
          v6->m_output.m_pntr = v9;
          v11 = v6->m_owner;
          v12 = v6->m_input.m_pntr;
          if ( v11 )
            v11->vfptr->prePathSearchCallback(v11, v6);
          hkaiVolumePathfindingUtil::FindPathInput::FindPathInput(&input, 0);
          hkaiVolumePathfindingUtil::FindPathInput::operator=(&input, v12);
          if ( v1->m_maxEstimatedIterationsPerStep >= 0 )
          {
            v13 = v2;
            if ( input.m_maxNumberOfIterations < v2 )
              v13 = input.m_maxNumberOfIterations;
            input.m_maxNumberOfIterations = v13;
          }
          hkaiVolumePathfindingUtil::FindPathInput::checkDeterminism(&input);
          hkaiVolumePathfindingUtil::findPath(v1->m_streamingCollection.m_pntr, &input, v9);
          _firePathRequestProcessedCallbacks<hkaiNavVolumePathRequestInfo>(
            (hkArrayBase<hkaiWorld::Listener *> *)&v1->m_listeners.m_data,
            v6);
          hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(v9);
          v14 = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathInput::`vftable;
LABEL_20:
          v2 -= v9->m_outputParameters.m_numIterations;
          input.m_goalCellKeys.m_size = 0;
          input.vfptr = v14;
          if ( input.m_goalCellKeys.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              input.m_goalCellKeys.m_data,
              4 * input.m_goalCellKeys.m_capacityAndFlags);
          input.m_goalCellKeys.m_data = 0i64;
          input.m_goalCellKeys.m_capacityAndFlags = 2147483648;
          input.m_goalPoints.m_size = 0;
          if ( input.m_goalPoints.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              input.m_goalPoints.m_data,
              16 * input.m_goalPoints.m_capacityAndFlags);
          goto LABEL_38;
        }
      }
      else
      {
        v15 = (hkaiNavMeshPathRequestInfo *)sortedRequests.m_data[v4].m_request;
        v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v17 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 64i64);
        v9 = (hkaiVolumePathfindingUtil::FindPathOutput *)v17;
        if ( v17 )
        {
          *(_DWORD *)(v17 + 8) = 0x1FFFF;
          *(_QWORD *)v17 = &hkaiPathfindingUtil::FindPathOutput::`vftable;
          *(_QWORD *)(v17 + 16) = 0i64;
          *(_DWORD *)(v17 + 24) = 0;
          *(_DWORD *)(v17 + 28) = 2147483648;
          *(_QWORD *)(v17 + 32) = 0i64;
          *(_DWORD *)(v17 + 40) = 0;
          *(_DWORD *)(v17 + 44) = 2147483648;
          *(_DWORD *)(v17 + 48) = 0;
          *(_DWORD *)(v17 + 52) = -1;
          *(_DWORD *)(v17 + 56) = 2139095022;
          *(_WORD *)(v17 + 60) = 0;
        }
        else
        {
          v9 = 0i64;
        }
        v18 = (hkReferencedObject *)&v15->m_output.m_pntr->vfptr;
        if ( v18 && v18 != (hkReferencedObject *)v9 )
          hkReferencedObject::removeReference(v18);
        v15->m_output.m_pntr = (hkaiPathfindingUtil::FindPathOutput *)v9;
        v19 = v15->m_owner;
        v20 = v15->m_input.m_pntr;
        if ( v19 && v19->vfptr->prePathSearchCallback(v19, v15) )
        {
          hkaiPathfindingUtil::FindPathInput::FindPathInput((hkaiPathfindingUtil::FindPathInput *)&input, 0);
          hkaiPathfindingUtil::FindPathInput::operator=((hkaiPathfindingUtil::FindPathInput *)&input, v20);
          if ( v1->m_maxEstimatedIterationsPerStep >= 0 )
          {
            v21 = v2;
            if ( input.m_maxNumberOfIterations < v2 )
              v21 = input.m_maxNumberOfIterations;
            input.m_maxNumberOfIterations = v21;
          }
          hkaiPathfindingUtil::FindPathInput::checkDeterminism((hkaiPathfindingUtil::FindPathInput *)&input);
          hkaiPathfindingUtil::findPath(
            v1->m_streamingCollection.m_pntr,
            (hkaiPathfindingUtil::FindPathInput *)&input,
            (hkaiPathfindingUtil::FindPathOutput *)v9);
          _firePathRequestProcessedCallbacks<hkaiNavMeshPathRequestInfo>(
            (hkArrayBase<hkaiWorld::Listener *> *)&v1->m_listeners.m_data,
            v15);
          hkaiPathfindingUtil::FindPathOutput::checkDeterminism((hkaiPathfindingUtil::FindPathOutput *)v9);
          v14 = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
          goto LABEL_20;
        }
        generateFailureOutput((hkaiPathfindingUtil::FindPathOutput *)v9);
      }
LABEL_38:
      ++v3;
      ++v4;
    }
    while ( v3 < sortedRequests.m_size );
  }
  hkaiWorld::incrementRequestPriorities(v1);
  v22 = sortedRequests.m_capacityAndFlags;
  v1->m_isPathRequestArrayLocked.m_bool = 0;
  sortedRequests.m_size = 0;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sortedRequests.m_data,
      16 * v22);
}

// File Line: 720
// RVA: 0xC05EB0
void __fastcall hkaiWorld::_deleteNavMeshPathRequestAt(hkaiWorld *this, int i)
{
  int v2; // ebp
  hkaiWorld *v3; // rdi
  unsigned __int64 v4; // rsi
  hkaiNavMeshPathRequestInfo *v5; // rbx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx
  __int64 v8; // rcx
  hkaiNavMeshPathRequestInfo *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx

  v2 = i;
  v3 = this;
  v4 = i;
  v5 = &this->m_navMeshPathRequests.m_data[v4];
  v5->m_markedForDeletion.m_bool = 1;
  v6 = (hkReferencedObject *)&v5->m_input.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_input.m_pntr = 0i64;
  v7 = (hkReferencedObject *)&v5->m_output.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v5->m_output.m_pntr = 0i64;
  v3->m_navMeshPathRequests.m_data[v4].vfptr->__vecDelDtor(&v3->m_navMeshPathRequests.m_data[v4], 0i64);
  v8 = --v3->m_navMeshPathRequests.m_size;
  if ( (_DWORD)v8 != v2 )
  {
    v9 = v3->m_navMeshPathRequests.m_data;
    v10 = 7i64;
    v11 = (signed __int64)&v9[v8];
    v12 = (unsigned __int64)&v9[v4];
    v13 = v11 - v12;
    do
    {
      v14 = *(_QWORD *)(v13 + v12);
      v12 += 8i64;
      *(_QWORD *)(v12 - 8) = v14;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 726
// RVA: 0xC05F80
void __fastcall hkaiWorld::_deleteNavVolumePathRequestAt(hkaiWorld *this, int i)
{
  int v2; // ebp
  hkaiWorld *v3; // rdi
  unsigned __int64 v4; // rsi
  hkaiNavVolumePathRequestInfo *v5; // rbx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx
  __int64 v8; // rcx
  hkaiNavVolumePathRequestInfo *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx

  v2 = i;
  v3 = this;
  v4 = i;
  v5 = &this->m_navVolumePathRequests.m_data[v4];
  v5->m_markedForDeletion.m_bool = 1;
  v6 = (hkReferencedObject *)&v5->m_input.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_input.m_pntr = 0i64;
  v7 = (hkReferencedObject *)&v5->m_output.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v5->m_output.m_pntr = 0i64;
  v3->m_navVolumePathRequests.m_data[v4].vfptr->__vecDelDtor(&v3->m_navVolumePathRequests.m_data[v4], 0i64);
  v8 = --v3->m_navVolumePathRequests.m_size;
  if ( (_DWORD)v8 != v2 )
  {
    v9 = v3->m_navVolumePathRequests.m_data;
    v10 = 7i64;
    v11 = (signed __int64)&v9[v8];
    v12 = (unsigned __int64)&v9[v4];
    v13 = v11 - v12;
    do
    {
      v14 = *(_QWORD *)(v13 + v12);
      v12 += 8i64;
      *(_QWORD *)(v12 - 8) = v14;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 732
// RVA: 0xC07000
void __fastcall hkaiWorld::shiftPathRequests(hkaiWorld *this, hkVector4f *shift)
{
  int v2; // ebx
  hkVector4f *v3; // r9
  hkaiWorld *v4; // rsi
  __int64 v5; // r10
  __int64 v6; // rdi
  hkaiNavMeshPathRequestInfo *v7; // r11
  __m128 *v8; // rdx
  int v9; // er8
  __int64 v10; // rcx
  hkaiPathfindingUtil::FindPathOutput *v11; // rdx
  int i; // eax

  v2 = 0;
  v3 = shift;
  v4 = this;
  if ( this->m_navMeshPathRequests.m_size > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    do
    {
      v7 = v4->m_navMeshPathRequests.m_data;
      if ( !v7[v6].m_markedForDeletion.m_bool )
      {
        v8 = (__m128 *)v7[v6].m_input.m_pntr;
        v9 = 0;
        v8[1] = _mm_add_ps(v8[1], v3->m_quad);
        if ( v8[2].m128_i32[2] > 0 )
        {
          v10 = 0i64;
          do
          {
            ++v9;
            v10 += 16i64;
            *(__m128 *)(v10 + v8[2].m128_u64[0] - 16) = _mm_add_ps(
                                                          *(__m128 *)(v10 + v8[2].m128_u64[0] - 16),
                                                          v3->m_quad);
          }
          while ( v9 < v8[2].m128_i32[2] );
        }
        v11 = v7[v6].m_output.m_pntr;
        if ( v11 )
        {
          for ( i = 0;
                i < v11->m_pathOut.m_size;
                v11->m_pathOut.m_data[v5].m_position.m_quad = _mm_add_ps(
                                                                v11->m_pathOut.m_data[v5].m_position.m_quad,
                                                                v3->m_quad) )
          {
            ++i;
          }
        }
      }
      ++v2;
      ++v6;
      ++v5;
    }
    while ( v2 < v4->m_navMeshPathRequests.m_size );
  }
}

