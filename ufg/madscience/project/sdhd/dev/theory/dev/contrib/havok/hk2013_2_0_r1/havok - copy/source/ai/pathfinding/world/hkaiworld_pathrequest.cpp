// File Line: 25
// RVA: 0xC05D60
hkaiNavMeshPathRequestInfo *__fastcall hkaiWorld::cancelRequestedNavMeshPath(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v5; // r8
  hkaiNavMeshPathRequestInfo *m_data; // rbx
  hkBool *i; // rax
  __int64 v9; // rcx

  m_size = this->m_navMeshPathRequests.m_size;
  v3 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  m_data = this->m_navMeshPathRequests.m_data;
  for ( i = &m_data->m_markedForDeletion; *(hkaiPathRequestInfoOwner **)&i[-8].m_bool != owner || i->m_bool; i += 56 )
  {
    ++v5;
    ++v3;
    if ( v5 >= m_size )
      return 0i64;
  }
  v9 = v3;
  m_data[v9].m_markedForDeletion.m_bool = 1;
  return &this->m_navMeshPathRequests.m_data[v9];
}

// File Line: 40
// RVA: 0xC05DD0
hkaiNavVolumePathRequestInfo *__fastcall hkaiWorld::cancelRequestedNavVolumePath(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v5; // r8
  hkaiNavVolumePathRequestInfo *m_data; // rbx
  hkBool *i; // rax
  __int64 v9; // rcx

  m_size = this->m_navVolumePathRequests.m_size;
  v3 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  m_data = this->m_navVolumePathRequests.m_data;
  for ( i = &m_data->m_markedForDeletion; *(hkaiPathRequestInfoOwner **)&i[-8].m_bool != owner || i->m_bool; i += 56 )
  {
    ++v5;
    ++v3;
    if ( v5 >= m_size )
      return 0i64;
  }
  v9 = v3;
  m_data[v9].m_markedForDeletion.m_bool = 1;
  return &this->m_navVolumePathRequests.m_data[v9];
}

// File Line: 55
// RVA: 0xC05920
void __fastcall hkaiWorld::requestPath(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner,
        hkaiPathfindingUtil::FindPathInput *input,
        int priority)
{
  int v7; // r11d
  __int64 v8; // r10
  hkaiNavMeshPathRequestInfo *m_data; // rax
  hkArray<hkaiNavMeshPathRequestInfo,hkContainerHeapAllocator> *p_m_navMeshPathRequests; // rdi
  __int64 v11; // rax
  __int64 v12; // rbx
  hkReferencedObject *v13; // rcx

  v7 = 0;
  if ( this->m_navMeshPathRequests.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = this->m_navMeshPathRequests.m_data;
      if ( m_data[v8].m_owner == owner )
        m_data[v8].m_markedForDeletion.m_bool = 1;
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_navMeshPathRequests.m_size );
  }
  p_m_navMeshPathRequests = &this->m_navMeshPathRequests;
  if ( this->m_navMeshPathRequests.m_size == (this->m_navMeshPathRequests.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_navMeshPathRequests, 56);
  v11 = (__int64)&p_m_navMeshPathRequests->m_data[p_m_navMeshPathRequests->m_size];
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
  v12 = (__int64)&p_m_navMeshPathRequests->m_data[p_m_navMeshPathRequests->m_size++];
  if ( input )
    hkReferencedObject::addReference(input);
  v13 = *(hkReferencedObject **)(v12 + 16);
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  *(_QWORD *)(v12 + 16) = input;
  *(_QWORD *)(v12 + 40) = owner;
  *(_DWORD *)(v12 + 32) = priority;
}

// File Line: 75
// RVA: 0xC05A40
void __fastcall hkaiWorld::requestPath(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner,
        hkaiVolumePathfindingUtil::FindPathInput *input,
        int priority)
{
  int v7; // r11d
  __int64 v8; // r10
  hkaiNavVolumePathRequestInfo *m_data; // rax
  hkArray<hkaiNavVolumePathRequestInfo,hkContainerHeapAllocator> *p_m_navVolumePathRequests; // rdi
  __int64 v11; // rax
  __int64 v12; // rbx
  hkReferencedObject *v13; // rcx

  v7 = 0;
  if ( this->m_navVolumePathRequests.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = this->m_navVolumePathRequests.m_data;
      if ( m_data[v8].m_owner == owner )
        m_data[v8].m_markedForDeletion.m_bool = 1;
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_navVolumePathRequests.m_size );
  }
  p_m_navVolumePathRequests = &this->m_navVolumePathRequests;
  if ( this->m_navVolumePathRequests.m_size == (this->m_navVolumePathRequests.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_navVolumePathRequests, 56);
  v11 = (__int64)&p_m_navVolumePathRequests->m_data[p_m_navVolumePathRequests->m_size];
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
  v12 = (__int64)&p_m_navVolumePathRequests->m_data[p_m_navVolumePathRequests->m_size++];
  if ( input )
    hkReferencedObject::addReference(input);
  v13 = *(hkReferencedObject **)(v12 + 16);
  if ( v13 )
    hkReferencedObject::removeReference(v13);
  *(_QWORD *)(v12 + 16) = input;
  *(_QWORD *)(v12 + 40) = owner;
  *(_DWORD *)(v12 + 32) = priority;
}

// File Line: 95
// RVA: 0xC05B60
hkaiNavMeshPathRequestInfo *__fastcall hkaiWorld::getNavMeshPathRequest(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  __int64 m_size; // r8
  hkaiNavMeshPathRequestInfo *v9; // rbx
  int v10; // edx
  __int64 v11; // rcx
  hkaiNavMeshPathRequestInfo *m_data; // r9
  hkBool *p_m_markedForDeletion; // rax
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtlinearSearch";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  m_size = this->m_navMeshPathRequests.m_size;
  v9 = 0i64;
  v10 = 0;
  v11 = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->m_navMeshPathRequests.m_data;
    p_m_markedForDeletion = &m_data->m_markedForDeletion;
    while ( *(hkaiPathRequestInfoOwner **)&p_m_markedForDeletion[-8].m_bool != owner || p_m_markedForDeletion->m_bool )
    {
      ++v11;
      ++v10;
      p_m_markedForDeletion += 56;
      if ( v11 >= m_size )
        goto LABEL_10;
    }
    v9 = &m_data[v10];
  }
LABEL_10:
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v16 = __rdtsc();
    v17 = v15 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v14[1] = v17;
  }
  return v9;
}

// File Line: 112
// RVA: 0xC05C50
hkaiNavVolumePathRequestInfo *__fastcall hkaiWorld::getNavVolumePathRequest(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  __int64 m_size; // r8
  hkaiNavVolumePathRequestInfo *v9; // rbx
  int v10; // edx
  __int64 v11; // rcx
  hkaiNavVolumePathRequestInfo *m_data; // r9
  hkBool *p_m_markedForDeletion; // rax
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtlinearSearch";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  m_size = this->m_navVolumePathRequests.m_size;
  v9 = 0i64;
  v10 = 0;
  v11 = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->m_navVolumePathRequests.m_data;
    p_m_markedForDeletion = &m_data->m_markedForDeletion;
    while ( *(hkaiPathRequestInfoOwner **)&p_m_markedForDeletion[-8].m_bool != owner || p_m_markedForDeletion->m_bool )
    {
      ++v11;
      ++v10;
      p_m_markedForDeletion += 56;
      if ( v11 >= m_size )
        goto LABEL_10;
    }
    v9 = &m_data[v10];
  }
LABEL_10:
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "Et";
    v16 = __rdtsc();
    v17 = v15 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v14[1] = v17;
  }
  return v9;
}

// File Line: 129
// RVA: 0xC05D40
// attributes: thunk
hkaiNavMeshPathRequestInfo *__fastcall hkaiWorld::getNavMeshPathRequest(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner)
{
  return ?getNavMeshPathRequest@hkaiWorld@@QEBAPEBVhkaiNavMeshPathRequestInfo@@PEBVhkaiPathRequestInfoOwner@@@Z(
           this,
           owner);
}

// File Line: 135
// RVA: 0xC05D50
// attributes: thunk
hkaiNavVolumePathRequestInfo *__fastcall hkaiWorld::getNavVolumePathRequest(
        hkaiWorld *this,
        hkaiPathRequestInfoOwner *owner)
{
  return ?getNavVolumePathRequest@hkaiWorld@@QEBAPEBVhkaiNavVolumePathRequestInfo@@PEBVhkaiPathRequestInfoOwner@@@Z(
           this,
           owner);
}

// File Line: 142
// RVA: 0xC05E40
void __fastcall hkaiWorld::incrementRequestPriorities(hkaiWorld *this)
{
  int v1; // edx
  int v2; // r8d
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
      ++this->m_navMeshPathRequests.m_data[v3++].m_priority;
    }
    while ( v2 < this->m_navMeshPathRequests.m_size );
  }
  if ( this->m_navVolumePathRequests.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      ++v1;
      ++this->m_navVolumePathRequests.m_data[v4++].m_priority;
    }
    while ( v1 < this->m_navVolumePathRequests.m_size );
  }
}

// File Line: 156
// RVA: 0xC071D0
void __fastcall prepareRequestArray_hkaiNavMeshPathRequestInfo_(
        hkArrayBase<hkaiNavMeshPathRequestInfo> *pathRequests,
        hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> *sortedRequests,
        hkaiWorld::PathType pathType)
{
  int v3; // ebp
  int v4; // r14d
  __int64 v8; // rsi
  __int64 v9; // r12
  hkaiNavMeshPathRequestInfo *v10; // rdi
  hkReferencedObject *m_pntr; // rcx
  hkReferencedObject *v12; // rcx
  __int64 v13; // rcx
  __int64 v14; // rdx
  hkaiNavMeshPathRequestInfo *v15; // rax
  char *v16; // r8
  __int64 v17; // rcx
  int m_size; // r8d
  __int64 v19; // rdi
  hkaiWorld::SortedRequest *v20; // rdx

  v3 = 0;
  v4 = pathRequests->m_size - 1;
  if ( v4 >= 0 )
  {
    v8 = v4;
    v9 = v8 * 56;
    do
    {
      hkaiNavMeshPathRequestInfo::checkDeterminism((hkaiNavMeshPathRequestInfo *)((char *)pathRequests->m_data + v9));
      v10 = &pathRequests->m_data[v8];
      if ( v10->m_markedForDeletion.m_bool )
      {
        v10->m_markedForDeletion.m_bool = 1;
        m_pntr = v10->m_input.m_pntr;
        if ( m_pntr )
          hkReferencedObject::removeReference(m_pntr);
        v10->m_input.m_pntr = 0i64;
        v12 = v10->m_output.m_pntr;
        if ( v12 )
          hkReferencedObject::removeReference(v12);
        v10->m_output.m_pntr = 0i64;
        pathRequests->m_data[v8].vfptr->__vecDelDtor(&pathRequests->m_data[v8], 0i64);
        v13 = --pathRequests->m_size;
        if ( (_DWORD)v13 != v4 )
        {
          v14 = 7i64;
          v15 = &pathRequests->m_data[v8];
          v16 = (char *)((char *)&pathRequests->m_data[v13] - (char *)v15);
          do
          {
            v17 = *(__int64 *)((char *)&v15->vfptr + (_QWORD)v16);
            v15 = (hkaiNavMeshPathRequestInfo *)((char *)v15 + 8);
            *(_QWORD *)&v15[-1].m_markedForDeletion.m_bool = v17;
            --v14;
          }
          while ( v14 );
        }
      }
      v9 -= 56i64;
      --v8;
      --v4;
    }
    while ( v4 >= 0 );
  }
  m_size = pathRequests->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiNavVolumePathRequestInfo,hkAlgorithm::less<hkaiNavVolumePathRequestInfo>>(
      (hkaiNavVolumePathRequestInfo *)pathRequests->m_data,
      0,
      m_size - 1,
      0);
  if ( pathRequests->m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      if ( !pathRequests->m_data[v19].m_output.m_pntr )
      {
        if ( sortedRequests->m_size == (sortedRequests->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, sortedRequests, 16);
        v20 = &sortedRequests->m_data[sortedRequests->m_size++];
        v20->m_pathType = pathType;
        v20->m_priority = pathRequests->m_data[v19].m_priority;
        v20->m_request = &pathRequests->m_data[v3];
      }
      ++v3;
      ++v19;
    }
    while ( v3 < pathRequests->m_size );
  }
}

// File Line: 184
// RVA: 0xC070E0
void __fastcall hkaiWorld::prepareRequestArray(
        hkaiWorld *this,
        hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> *sortedRequests)
{
  int m_size; // r8d
  __int64 m_maxRequestsPerStep; // rbx
  int v6; // edx
  int *i; // rcx
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  prepareRequestArray_hkaiNavMeshPathRequestInfo_(&this->m_navMeshPathRequests, sortedRequests, PATH_TYPE_NAVMESH);
  prepareRequestArray_hkaiNavVolumePathRequestInfo_(&this->m_navVolumePathRequests, sortedRequests, PATH_TYPE_NAVVOLUME);
  m_size = sortedRequests->m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiWorld::SortedRequest,hkAlgorithm::less<hkaiWorld::SortedRequest>>(
      sortedRequests->m_data,
      0,
      m_size - 1,
      0);
  m_maxRequestsPerStep = this->m_maxRequestsPerStep;
  v6 = sortedRequests->m_size;
  if ( (int)m_maxRequestsPerStep < v6 )
  {
    for ( i = &sortedRequests->m_data[m_maxRequestsPerStep].m_priority; *i >= this->m_priorityThreshold; i += 4 )
    {
      LODWORD(m_maxRequestsPerStep) = m_maxRequestsPerStep + 1;
      if ( (int)m_maxRequestsPerStep >= v6 )
        return;
    }
    v8 = sortedRequests->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < (int)m_maxRequestsPerStep )
    {
      v9 = 2 * v8;
      v10 = m_maxRequestsPerStep;
      if ( (int)m_maxRequestsPerStep < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, sortedRequests, v10, 16);
    }
    sortedRequests->m_size = m_maxRequestsPerStep;
  }
}

// File Line: 240
// RVA: 0xC074F0
__int64 __fastcall PathSearchJobManager::_findNavMeshJobIndex(
        PathSearchJobManager *this,
        hkaiPathfindingUtil::FindPathInput *input)
{
  int m_size; // esi
  unsigned int v5; // ebx
  hkaiNavMeshAStarJob *v6; // r14
  hkaiWorld *m_world; // rdx
  __int128 v8; // xmm7
  __m128 v9; // xmm1
  __int128 v10; // xmm8
  __int128 v11; // xmm9
  __m128i v12; // xmm2
  hkaiNavMeshAStarJob *v13; // rdx
  hkArray<hkaiNavMeshAStarCommand,hkContainerTempAllocator> *v14; // rax
  hkJob v16; // [rsp+20h] [rbp-E8h]
  __int128 v17; // [rsp+40h] [rbp-C8h]
  __int128 v18; // [rsp+80h] [rbp-88h]
  __int128 m_data; // [rsp+90h] [rbp-78h]
  __int128 v20; // [rsp+A0h] [rbp-68h]

  m_size = this->m_meshCommands.m_size;
  v5 = 0;
  if ( m_size <= 0 )
  {
LABEL_5:
    m_world = this->m_world;
    v16.m_threadAffinity = -1;
    v8 = *(_OWORD *)&input->m_searchParameters.m_edgeFilter;
    v17 = *(_OWORD *)input->m_searchParameters.m_up.m_vec;
    *(_WORD *)&v16.m_jobSubType = 2305;
    v16.m_jobSpuType.m_storage = 1;
    v16.m_size = 144;
    *(_QWORD *)&v18 = *(_QWORD *)&input->m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes;
    v9 = _mm_mul_ps(m_world->m_up.m_quad, (__m128)xmmword_141A71390);
    v10 = *(_OWORD *)&input->m_searchParameters.m_heuristicWeight;
    v11 = *(_OWORD *)&input->m_searchParameters.m_searchCapsuleRadius;
    DWORD2(v18) = 100000;
    LODWORD(v20) = 0;
    m_data = (unsigned __int64)m_world->m_streamingCollection.m_pntr->m_instances.m_data;
    v12 = _mm_add_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
              _mm_cvttps_epi32(v9)),
            _mm_loadu_si128((const __m128i *)hkPackedUnitVector_m_offset));
    LOWORD(v17) = _mm_extract_epi16(v12, 1);
    WORD1(v17) = _mm_extract_epi16(v12, 3);
    WORD2(v17) = _mm_extract_epi16(v12, 5);
    if ( this->m_meshJobs.m_size == (this->m_meshJobs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, this, 144);
    v13 = &this->m_meshJobs.m_data[this->m_meshJobs.m_size];
    if ( v13 )
    {
      v13->hkJob = v16;
      *(_OWORD *)&v13->m_semaphore = 0i64;
      *(_OWORD *)v13->m_searchParameters.m_up.m_vec = v17;
      *(_OWORD *)&v13->m_searchParameters.m_edgeFilter = v8;
      *(_OWORD *)&v13->m_searchParameters.m_heuristicWeight = v10;
      *(_OWORD *)&v13->m_searchParameters.m_searchCapsuleRadius = v11;
      *(_OWORD *)&v13->m_searchParameters.m_hierarchyBufferSizes.m_maxSearchStateSizeBytes = v18;
      *(_OWORD *)&v13->m_streamingSectionInfo = m_data;
      *(_OWORD *)&v13->m_numCommands = v20;
    }
    ++this->m_meshJobs.m_size;
    if ( this->m_meshCommands.m_size == (this->m_meshCommands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_meshCommands, 16);
    v14 = &this->m_meshCommands.m_data[this->m_meshCommands.m_size];
    if ( v14 )
    {
      v14->m_data = 0i64;
      v14->m_size = 0;
      v14->m_capacityAndFlags = 0x80000000;
    }
    ++this->m_meshCommands.m_size;
    return (unsigned int)(this->m_meshJobs.m_size - 1);
  }
  else
  {
    v6 = this->m_meshJobs.m_data;
    while ( !hkaiNavMeshPathSearchParameters::operator==(&v6[v5].m_searchParameters, &input->m_searchParameters) )
    {
      if ( (int)++v5 >= m_size )
        goto LABEL_5;
    }
    return v5;
  }
}

// File Line: 264
// RVA: 0xC07760
__int64 __fastcall PathSearchJobManager::_findNavVolumeJobIndex(
        PathSearchJobManager *this,
        hkaiVolumePathfindingUtil::FindPathInput *input)
{
  __int64 m_size; // r11
  unsigned int v4; // r10d
  __int64 v5; // r9
  hkaiAstarCostModifier **p_m_costModifier; // r8
  __int128 v7; // xmm7
  __int128 v8; // xmm8
  hkaiNavVolumeAStarJob *v9; // rax
  hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *v10; // rax
  hkJob v12; // [rsp+20h] [rbp-A8h]
  __int128 v13; // [rsp+60h] [rbp-68h]
  __int128 m_data; // [rsp+70h] [rbp-58h]
  __int128 v15; // [rsp+80h] [rbp-48h]

  m_size = this->m_volumeJobs.m_size;
  v4 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_10:
    v12.m_threadAffinity = -1;
    *(hkaiSearchParameters::BufferSizes *)&v13 = input->m_searchParameters.m_bufferSizes;
    v7 = *(_OWORD *)input->m_searchParameters.m_up.m_vec;
    v8 = *(_OWORD *)&input->m_searchParameters.m_edgeFilter;
    *(_WORD *)&v12.m_jobSubType = 2560;
    v12.m_jobSpuType.m_storage = 1;
    v12.m_size = 112;
    m_data = (unsigned __int64)this->m_world->m_streamingCollection.m_pntr->m_instances.m_data;
    DWORD2(v13) = 100000;
    LODWORD(v15) = 0;
    if ( this->m_volumeJobs.m_size == (this->m_volumeJobs.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_volumeJobs, 112);
    v9 = &this->m_volumeJobs.m_data[this->m_volumeJobs.m_size];
    if ( v9 )
    {
      v9->hkJob = v12;
      *(_OWORD *)&v9->m_semaphore = 0i64;
      *(_OWORD *)v9->m_searchParameters.m_up.m_vec = v7;
      *(_OWORD *)&v9->m_searchParameters.m_edgeFilter = v8;
      *(_OWORD *)&v9->m_searchParameters.m_bufferSizes.m_maxOpenSetSizeBytes = v13;
      *(_OWORD *)&v9->m_streamingSectionInfo = m_data;
      *(_OWORD *)&v9->m_numCommands = v15;
    }
    ++this->m_volumeJobs.m_size;
    if ( this->m_volumeCommands.m_size == (this->m_volumeCommands.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_volumeCommands, 16);
    v10 = &this->m_volumeCommands.m_data[this->m_volumeCommands.m_size];
    if ( v10 )
    {
      v10->m_data = 0i64;
      v10->m_size = 0;
      v10->m_capacityAndFlags = 0x80000000;
    }
    ++this->m_volumeCommands.m_size;
    return (unsigned int)(this->m_volumeJobs.m_size - 1);
  }
  else
  {
    p_m_costModifier = &this->m_volumeJobs.m_data->m_searchParameters.m_costModifier;
    while ( *p_m_costModifier != input->m_searchParameters.m_costModifier
         || p_m_costModifier[1] != (hkaiAstarCostModifier *)input->m_searchParameters.m_edgeFilter
         || input->m_searchParameters.m_lineOfSightFlags.m_storage != *((_BYTE *)p_m_costModifier + 16)
         || input->m_searchParameters.m_heuristicWeight != *((float *)p_m_costModifier + 5)
         || *((_DWORD *)p_m_costModifier + 6) != input->m_searchParameters.m_bufferSizes.m_maxOpenSetSizeBytes
         || *((_DWORD *)p_m_costModifier + 7) != input->m_searchParameters.m_bufferSizes.m_maxSearchStateSizeBytes )
    {
      ++v5;
      ++v4;
      p_m_costModifier += 14;
      if ( v5 >= m_size )
        goto LABEL_10;
    }
    return v4;
  }
}

// File Line: 290
// RVA: 0xC07B90
void __fastcall reorderPathfindingCommands_hkaiNavVolumeAStarCommand_(
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *commands,
        const int jobSize)
{
  int m_size; // ebx
  hkRelocationInfo::Import *m_data; // r11
  int v5; // eax
  int v6; // edx
  __int64 v7; // r12
  int v8; // eax
  __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rcx
  _QWORD *v12; // rcx
  __int64 v13; // rsi
  int v14; // r10d
  __int64 v15; // r14
  int v16; // edi
  __int64 v17; // r8
  __int64 v18; // rbp
  hkaiNavVolumeAStarCommand *v19; // rcx
  hkRelocationInfo::Import *v20; // rdx
  int v21; // eax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  m_size = commands->m_size;
  m_data = 0i64;
  v5 = (m_size + jobSize - 1) / jobSize;
  v6 = 0;
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  array.m_size = 0;
  v7 = v5;
  if ( m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, m_size, 112);
    v6 = array.m_size;
    m_data = array.m_data;
  }
  v8 = m_size - v6;
  v9 = 112i64 * v6;
  v10 = m_size - v6;
  v11 = v9 + 64;
  if ( v8 > 0 )
  {
    v12 = (_QWORD *)((char *)&m_data->m_fromOffset + v11);
    do
    {
      if ( v12 != (_QWORD *)64 )
        *v12 = 0i64;
      v12 += 14;
      --v10;
    }
    while ( v10 );
    m_data = array.m_data;
  }
  array.m_size = m_size;
  if ( (int)v7 > 0 )
  {
    v13 = 0i64;
    v14 = v7;
    v15 = (unsigned int)v7;
    do
    {
      v16 = (v14 + m_size - 1) / v14;
      if ( v16 > 0 )
      {
        v17 = v13;
        v18 = (unsigned int)v16;
        do
        {
          v19 = (hkaiNavVolumeAStarCommand *)commands->m_data;
          v20 = m_data;
          m_data += 7;
          *v20 = *(hkRelocationInfo::Import *)((char *)commands->m_data + v17);
          v20[1] = *(hkRelocationInfo::Import *)((char *)&v19->m_goalPoint + v17);
          v20[2].m_fromOffset = *(unsigned int *)((char *)&v19->m_startCellKey + v17);
          *(&v20[2].m_fromOffset + 1) = *(unsigned int *)((char *)&v19->m_goalCellKey + v17);
          v20[2].m_identifier = *(const char **)((char *)&v19->m_multipleGoalPoints + v17);
          *(_QWORD *)&v20[3].m_fromOffset = *(const unsigned int **)((char *)&v19->m_multipleGoalCellKeys + v17);
          LODWORD(v20[3].m_identifier) = *(int *)((char *)&v19->m_numGoals + v17);
          HIDWORD(v20[3].m_identifier) = *(int *)((char *)&v19->m_maxNumberOfIterations + v17);
          *(hkaiAgentTraversalInfo *)&v20[4].m_fromOffset = *(hkaiAgentTraversalInfo *)((char *)&v19->m_agentInfo + v17);
          v20[4].m_identifier = *(const char **)((char *)&v19->m_AStarOutput + v17);
          *(_QWORD *)&v20[5].m_fromOffset = *(unsigned int **)((char *)&v19->m_cellsOut + v17);
          LODWORD(v20[5].m_identifier) = *(int *)((char *)&v19->m_maxCellsOut + v17);
          *(_QWORD *)&v20[6].m_fromOffset = *(hkaiPath::PathPoint **)((char *)&v19->m_pointsOut + v17);
          v21 = *(int *)((char *)&v19->m_maxPointsOut + v17);
          v17 += 112 * v7;
          LODWORD(v20[6].m_identifier) = v21;
          --v18;
        }
        while ( v18 );
      }
      m_size -= v16;
      --v14;
      v13 += 112i64;
      --v15;
    }
    while ( v15 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(commands, &array);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      112 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 317
// RVA: 0xC07DC0
void __fastcall _firePathRequestProcessedCallbacks<hkaiNavMeshPathRequestInfo>(
        hkArrayBase<hkaiWorld::Listener *> *listeners,
        hkaiNavMeshPathRequestInfo *pathRequest)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  int v8; // ebx
  __int64 v9; // rdi
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "Ttcallbacks";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  v8 = 0;
  if ( listeners->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      ((void (__fastcall *)(hkaiWorld::Listener *, hkaiNavMeshPathRequestInfo *, _QWORD *))listeners->m_data[v9]->vfptr->pathRequestProcessedCallback)(
        listeners->m_data[v9],
        pathRequest,
        Value);
      ++v8;
      ++v9;
    }
    while ( v8 < listeners->m_size );
  }
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "Et";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
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
  _QWORD *Value; // r9
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rax
  unsigned __int64 v9; // rdx
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int64 v14; // r13
  hkaiWorld::PathType v15; // edx
  _QWORD *v16; // rsi
  __int64 v17; // rcx
  __int64 v18; // r14
  _QWORD **v19; // rax
  __int64 v20; // rax
  hkReferencedObject *v21; // rbx
  hkReferencedObject *v22; // rcx
  int NavVolumeJobIndex; // eax
  hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *v24; // rdi
  __int64 v25; // rbx
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  __int64 v29; // rax
  int v30; // eax
  __int64 v31; // rbx
  int v32; // r8d
  _DWORD *v33; // rcx
  __int128 *v34; // rdx
  __int128 v35; // xmm0
  int v36; // eax
  hkaiPathfindingUtil::FindPathOutput *v37; // rdi
  int m_maxPathSearchEdgesOut; // r9d
  int v39; // eax
  int v40; // eax
  int m_maxPathSearchPointsOut; // r9d
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *p_m_pathOut; // rsi
  int v43; // eax
  int v44; // eax
  hkResult *v45; // rcx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v46; // r8
  _QWORD *v47; // rbx
  __int64 v48; // rcx
  bool v49; // si
  __int64 v50; // r14
  _QWORD **v51; // rax
  __int64 v52; // rax
  hkReferencedObject *v53; // rcx
  int NavMeshJobIndex; // eax
  hkArray<hkaiNavMeshAStarCommand,hkContainerTempAllocator> *v55; // rsi
  __int64 v56; // rbx
  int v57; // r9d
  int v58; // eax
  int v59; // eax
  __int64 v60; // rax
  int v61; // eax
  _DWORD *v62; // rcx
  __int128 v63; // xmm0
  int v64; // eax
  int v65; // r9d
  int v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int m_size; // ebx
  int v71; // eax
  _QWORD *v72; // r8
  _QWORD *v73; // rcx
  unsigned __int64 v74; // rax
  _QWORD *v75; // rcx
  __int64 v76; // rdx
  __int64 v77; // r8
  hkResultEnum m_enum; // r9d
  char *v79; // rsi
  hkArray<hkaiNavMeshAStarCommand,hkContainerTempAllocator> *v80; // r13
  int v81; // r14d
  int v82; // r15d
  int v83; // edi
  __int64 v84; // r12
  int v85; // eax
  int v86; // ebx
  __int64 v87; // rdx
  __int64 v88; // r8
  hkResultEnum v89; // r9d
  char *v90; // rsi
  hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *v91; // r13
  int v92; // r14d
  int v93; // r15d
  int v94; // edi
  __int64 v95; // r12
  int v96; // eax
  int v97; // ebx
  _QWORD *v98; // r8
  _QWORD *v99; // rcx
  unsigned __int64 v100; // rax
  _QWORD *v101; // rcx
  int v102; // r13d
  __int64 v103; // rdi
  hkaiWorld::PathType m_pathType; // edx
  hkaiNavVolumePathRequestInfo *m_request; // rbx
  hkaiVolumePathfindingUtil::FindPathOutput *m_pntr; // rsi
  int PathLength; // r15d
  int NumPathPoints; // eax
  int v109; // ecx
  int v110; // ebx
  int v111; // ecx
  int v112; // r9d
  int v113; // eax
  int v114; // eax
  int v115; // r9d
  hkaiNavMeshPathRequestInfo *v116; // rbx
  hkaiPathfindingUtil::FindPathOutput *v117; // rsi
  char m_storage; // bl
  int v119; // r15d
  int v120; // ebx
  int v121; // eax
  int v122; // eax
  int v123; // r9d
  int v124; // eax
  int v125; // eax
  int v126; // r9d
  _QWORD *v127; // r8
  _QWORD *v128; // rcx
  unsigned __int64 v129; // rax
  _QWORD *v130; // rcx
  int v131; // [rsp+30h] [rbp-79h]
  int v132; // [rsp+30h] [rbp-79h]
  int v133; // [rsp+30h] [rbp-79h]
  hkResult v134[2]; // [rsp+38h] [rbp-71h] BYREF
  unsigned int validGoalsMask[2]; // [rsp+40h] [rbp-69h] BYREF
  hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> sortedRequests; // [rsp+48h] [rbp-61h] BYREF
  hkResult v137; // [rsp+58h] [rbp-51h] BYREF
  hkResult v138; // [rsp+5Ch] [rbp-4Dh] BYREF
  hkResult v139; // [rsp+60h] [rbp-49h] BYREF
  hkResult result; // [rsp+64h] [rbp-45h] BYREF
  hkResult v141; // [rsp+68h] [rbp-41h] BYREF
  PathSearchJobManager v142; // [rsp+70h] [rbp-39h] BYREF
  hkResult v146; // [rsp+128h] [rbp+7Fh] BYREF

  v3 = threadPool;
  v4 = this;
  if ( !this->m_navMeshPathRequests.m_size && !this->m_navVolumePathRequests.m_size )
    return;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = Value[1];
  if ( v6 < Value[3] )
  {
    *(_QWORD *)v6 = "LtstepPathSearchesMT";
    *(_QWORD *)(v6 + 16) = "StsortRequests";
    v7 = __rdtsc();
    *(_DWORD *)(v6 + 8) = v7;
    Value[1] = v6 + 24;
  }
  v4->m_isPathRequestArrayLocked.m_bool = 1;
  sortedRequests.m_data = 0i64;
  sortedRequests.m_size = 0;
  sortedRequests.m_capacityAndFlags = 0x80000000;
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
      v13 = v10 + 2;
      *((_DWORD *)v13 - 2) = v12;
      v11[1] = v13;
    }
    v142.m_meshJobs.m_capacityAndFlags = 0x80000000;
    v142.m_meshCommands.m_capacityAndFlags = 0x80000000;
    v142.m_meshJobs.m_data = 0i64;
    v142.m_meshJobs.m_size = 0;
    v142.m_meshCommands.m_data = 0i64;
    v142.m_meshCommands.m_size = 0;
    v142.m_volumeJobs.m_data = 0i64;
    v142.m_volumeJobs.m_size = 0;
    v142.m_volumeJobs.m_capacityAndFlags = 0x80000000;
    v142.m_volumeCommands.m_data = 0i64;
    v142.m_volumeCommands.m_size = 0;
    v142.m_volumeCommands.m_capacityAndFlags = 0x80000000;
    v142.m_world = v4;
    v131 = 0;
    v146.m_enum = -1;
    if ( sortedRequests.m_size <= 0 )
    {
LABEL_83:
      m_size = sortedRequests.m_size;
      if ( v4->m_maxEstimatedIterationsPerStep >= 0 && sortedRequests.m_size > 0 )
      {
        v71 = ((__int64 (__fastcall *)(hkJobThreadPool *, unsigned __int64, _QWORD *))v3->vfptr[3].__vecDelDtor)(
                v3,
                v9,
                v11);
        v146.m_enum = ((v71 + m_size) / (v71 + 1) + v4->m_maxEstimatedIterationsPerStep - 1)
                    / ((v71 + m_size)
                     / (v71 + 1));
      }
      v72 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v73 = (_QWORD *)v72[1];
      if ( (unsigned __int64)v73 < v72[3] )
      {
        *v73 = "StprocessJobs";
        v74 = __rdtsc();
        v75 = v73 + 2;
        *((_DWORD *)v75 - 2) = v74;
        v72[1] = v75;
      }
      v132 = 0;
      if ( v142.m_meshJobs.m_size > 0 )
      {
        v76 = 0i64;
        v77 = 0i64;
        *(_QWORD *)validGoalsMask = 0i64;
        *(_QWORD *)&v134[0].m_enum = 0i64;
        do
        {
          m_enum = v146.m_enum;
          v79 = &v142.m_meshJobs.m_data->m_jobSubType + v77;
          v80 = (hkArray<hkaiNavMeshAStarCommand,hkContainerTempAllocator> *)((char *)v142.m_meshCommands.m_data + v76);
          if ( v146.m_enum >= HK_SUCCESS )
          {
            reorderPathfindingCommands_hkaiNavMeshAStarCommand_(v80, v4->m_numPathRequestsPerJob);
            v77 = *(_QWORD *)validGoalsMask;
            m_enum = v146.m_enum;
          }
          v81 = v80->m_size;
          v82 = 0;
          v83 = (v4->m_numPathRequestsPerJob + v81 - 1) / v4->m_numPathRequestsPerJob;
          if ( v83 > 0 )
          {
            v84 = (unsigned int)v83;
            do
            {
              *((_QWORD *)v79 + 15) = &v80->m_data[v82];
              v85 = (v83 + v81 - 1) / v83;
              v86 = v85;
              *((_DWORD *)v79 + 32) = v85;
              if ( m_enum >= HK_SUCCESS )
                *((_DWORD *)v79 + 26) = m_enum * v85;
              hkJobQueue::addJob(jobQueue, (hkJob *)v79, JOB_HIGH_PRIORITY);
              m_enum = v146.m_enum;
              v82 += v86;
              v81 -= v86;
              --v83;
              --v84;
            }
            while ( v84 );
            v77 = *(_QWORD *)validGoalsMask;
            v4 = this;
          }
          v77 += 144i64;
          v76 = *(_QWORD *)&v134[0].m_enum + 16i64;
          *(_QWORD *)validGoalsMask = v77;
          ++v132;
          *(_QWORD *)&v134[0].m_enum += 16i64;
        }
        while ( v132 < v142.m_meshJobs.m_size );
      }
      v133 = 0;
      if ( v142.m_volumeJobs.m_size > 0 )
      {
        v87 = 0i64;
        v88 = 0i64;
        *(_QWORD *)validGoalsMask = 0i64;
        *(_QWORD *)&v134[0].m_enum = 0i64;
        do
        {
          v89 = v146.m_enum;
          v90 = &v142.m_volumeJobs.m_data->m_jobSubType + v88;
          v91 = (hkArray<hkaiNavVolumeAStarCommand,hkContainerTempAllocator> *)((char *)v142.m_volumeCommands.m_data
                                                                              + v87);
          if ( v146.m_enum >= HK_SUCCESS )
          {
            reorderPathfindingCommands_hkaiNavVolumeAStarCommand_(v91, v4->m_numPathRequestsPerJob);
            v88 = *(_QWORD *)validGoalsMask;
            v89 = v146.m_enum;
          }
          v92 = v91->m_size;
          v93 = 0;
          v94 = (v4->m_numPathRequestsPerJob + v92 - 1) / v4->m_numPathRequestsPerJob;
          if ( v94 > 0 )
          {
            v95 = (unsigned int)v94;
            do
            {
              *((_QWORD *)v90 + 11) = &v91->m_data[v93];
              v96 = (v94 + v92 - 1) / v94;
              v97 = v96;
              *((_DWORD *)v90 + 24) = v96;
              if ( v89 >= HK_SUCCESS )
                *((_DWORD *)v90 + 18) = v89 * v96;
              hkJobQueue::addJob(jobQueue, (hkJob *)v90, JOB_HIGH_PRIORITY);
              v89 = v146.m_enum;
              v93 += v97;
              v92 -= v97;
              --v94;
              --v95;
            }
            while ( v95 );
            v88 = *(_QWORD *)validGoalsMask;
            v4 = this;
          }
          v88 += 112i64;
          v87 = *(_QWORD *)&v134[0].m_enum + 16i64;
          *(_QWORD *)validGoalsMask = v88;
          ++v133;
          *(_QWORD *)&v134[0].m_enum += 16i64;
        }
        while ( v133 < v142.m_volumeJobs.m_size );
      }
      ((void (__fastcall *)(hkJobThreadPool *, hkJobQueue *, __int64))threadPool->vfptr[5].__first_virtual_table_function__)(
        threadPool,
        jobQueue,
        9i64);
      hkJobQueue::processAllJobs(jobQueue, 1);
      ((void (__fastcall *)(hkJobThreadPool *))threadPool->vfptr[2].__vecDelDtor)(threadPool);
      v98 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v99 = (_QWORD *)v98[1];
      if ( (unsigned __int64)v99 < v98[3] )
      {
        *v99 = "StprocessResults";
        v100 = __rdtsc();
        v101 = v99 + 2;
        *((_DWORD *)v101 - 2) = v100;
        v98[1] = v101;
      }
      v102 = 0;
      if ( sortedRequests.m_size > 0 )
      {
        v103 = 0i64;
        while ( 1 )
        {
          m_pathType = sortedRequests.m_data[v103].m_pathType;
          if ( m_pathType )
          {
            if ( m_pathType == PATH_TYPE_NAVVOLUME )
            {
              m_request = (hkaiNavVolumePathRequestInfo *)sortedRequests.m_data[v103].m_request;
              _firePathRequestProcessedCallbacks<hkaiNavVolumePathRequestInfo>(&v4->m_listeners, m_request);
              m_pntr = m_request->m_output.m_pntr;
              if ( m_pntr )
              {
                PathLength = hkaiPathUtil::_getPathLength(m_pntr->m_visitedCells.m_data, this->m_maxPathSearchEdgesOut);
                NumPathPoints = hkaiPathUtil::_getNumPathPoints(
                                  m_pntr->m_pathOut.m_data,
                                  this->m_maxPathSearchPointsOut);
                v109 = m_pntr->m_visitedCells.m_capacityAndFlags & 0x3FFFFFFF;
                v110 = NumPathPoints;
                if ( v109 >= PathLength )
                {
                  v146.m_enum = HK_SUCCESS;
                }
                else
                {
                  v111 = 2 * v109;
                  v112 = PathLength;
                  if ( PathLength < v111 )
                    v112 = v111;
                  hkArrayUtil::_reserve(&v146, &hkContainerHeapAllocator::s_alloc, &m_pntr->m_visitedCells, v112, 4);
                }
                m_pntr->m_visitedCells.m_size = PathLength;
                v113 = m_pntr->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
                if ( v113 >= v110 )
                {
                  v134[0].m_enum = HK_SUCCESS;
                  m_pntr->m_pathOut.m_size = v110;
                  hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(m_pntr);
                }
                else
                {
                  v114 = 2 * v113;
                  v115 = v110;
                  if ( v110 < v114 )
                    v115 = v114;
                  hkArrayUtil::_reserve(v134, &hkContainerHeapAllocator::s_alloc, &m_pntr->m_pathOut, v115, 48);
                  m_pntr->m_pathOut.m_size = v110;
                  hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(m_pntr);
                }
              }
            }
          }
          else
          {
            v116 = (hkaiNavMeshPathRequestInfo *)sortedRequests.m_data[v103].m_request;
            _firePathRequestProcessedCallbacks<hkaiNavMeshPathRequestInfo>(&v4->m_listeners, v116);
            v117 = v116->m_output.m_pntr;
            if ( v117 )
            {
              m_storage = v116->m_input.m_pntr->m_searchParameters.m_outputPathFlags.m_storage;
              v119 = hkaiPathUtil::_getPathLength(v117->m_visitedEdges.m_data, v4->m_maxPathSearchEdgesOut);
              if ( (m_storage & 1) != 0 )
                v120 = hkaiPathUtil::_getNumPathPoints(v117->m_pathOut.m_data, v4->m_maxPathSearchPointsOut);
              else
                v120 = 0;
              v121 = v117->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v121 >= v119 )
              {
                v138.m_enum = HK_SUCCESS;
              }
              else
              {
                v122 = 2 * v121;
                v123 = v119;
                if ( v119 < v122 )
                  v123 = v122;
                hkArrayUtil::_reserve(&v138, &hkContainerHeapAllocator::s_alloc, &v117->m_visitedEdges, v123, 4);
              }
              v117->m_visitedEdges.m_size = v119;
              v124 = v117->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v124 >= v120 )
              {
                v137.m_enum = HK_SUCCESS;
              }
              else
              {
                v125 = 2 * v124;
                v126 = v120;
                if ( v120 < v125 )
                  v126 = v125;
                hkArrayUtil::_reserve(&v137, &hkContainerHeapAllocator::s_alloc, &v117->m_pathOut, v126, 48);
              }
              v117->m_pathOut.m_size = v120;
              hkaiPathfindingUtil::FindPathOutput::checkDeterminism(v117);
            }
          }
          ++v102;
          ++v103;
          if ( v102 >= sortedRequests.m_size )
            break;
          v4 = this;
        }
      }
      hkaiWorld::incrementRequestPriorities(this);
      this->m_isPathRequestArrayLocked.m_bool = 0;
      PathSearchJobManager::~PathSearchJobManager(&v142);
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
        v20 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 64i64);
        v21 = (hkReferencedObject *)v20;
        if ( v20 )
        {
          *(_DWORD *)(v20 + 8) = 0x1FFFF;
          *(_QWORD *)v20 = &hkaiVolumePathfindingUtil::FindPathOutput::`vftable;
          *(_DWORD *)(v20 + 28) = 0x80000000;
          *(_QWORD *)(v20 + 16) = 0i64;
          *(_DWORD *)(v20 + 24) = 0;
          *(_QWORD *)(v20 + 32) = 0i64;
          *(_DWORD *)(v20 + 40) = 0;
          *(_DWORD *)(v20 + 44) = 0x80000000;
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
        NavVolumeJobIndex = PathSearchJobManager::_findNavVolumeJobIndex(
                              &v142,
                              (hkaiVolumePathfindingUtil::FindPathInput *)v18);
        v24 = &v142.m_volumeCommands.m_data[NavVolumeJobIndex];
        v25 = v24->m_size;
        v26 = v25 + 1;
        v27 = v24->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v27 >= (int)v25 + 1 )
        {
          result.m_enum = HK_SUCCESS;
        }
        else
        {
          v28 = 2 * v27;
          if ( v26 < v28 )
            v26 = v28;
          hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, v24, v26, 112);
        }
        v29 = (__int64)&v24->m_data[v24->m_size];
        if ( v29 )
          *(_QWORD *)(v29 + 64) = 0i64;
        ++v24->m_size;
        v30 = *(_DWORD *)(v18 + 48);
        v31 = (__int64)&v24->m_data[v25];
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
        m_maxPathSearchEdgesOut = v4->m_maxPathSearchEdgesOut;
        v39 = v37->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v39 >= m_maxPathSearchEdgesOut )
        {
          v141.m_enum = HK_SUCCESS;
        }
        else
        {
          v40 = 2 * v39;
          if ( m_maxPathSearchEdgesOut < v40 )
            m_maxPathSearchEdgesOut = v40;
          hkArrayUtil::_reserve(
            &v141,
            &hkContainerHeapAllocator::s_alloc,
            &v37->m_visitedEdges,
            m_maxPathSearchEdgesOut,
            4);
        }
        m_maxPathSearchPointsOut = v4->m_maxPathSearchPointsOut;
        p_m_pathOut = &v37->m_pathOut;
        v43 = v37->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v43 < m_maxPathSearchPointsOut )
        {
          v44 = 2 * v43;
          v45 = &v139;
          v46 = &v37->m_pathOut;
          if ( m_maxPathSearchPointsOut < v44 )
            m_maxPathSearchPointsOut = v44;
          goto LABEL_42;
        }
        v139.m_enum = HK_SUCCESS;
LABEL_44:
        *(_QWORD *)(v31 + 80) = v37->m_visitedEdges.m_data;
        *(_DWORD *)(v31 + 88) = v37->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
        *(_QWORD *)(v31 + 96) = p_m_pathOut->m_data;
        *(_DWORD *)(v31 + 104) = v37->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
        *(_QWORD *)(v31 + 72) = &v37->m_outputParameters;
      }
LABEL_81:
      ++v14;
      if ( ++v131 >= sortedRequests.m_size )
      {
        v3 = threadPool;
        goto LABEL_83;
      }
    }
    v47 = sortedRequests.m_data[v14].m_request;
    v48 = v47[5];
    v49 = v48
       && (*(unsigned __int8 (__fastcall **)(__int64, _QWORD *, _QWORD *))(*(_QWORD *)v48 + 16i64))(v48, v47, v11);
    v50 = v47[2];
    hkaiPathfindingUtil::FindPathInput::checkDeterminism((hkaiPathfindingUtil::FindPathInput *)v50);
    v51 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v52 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v51[11] + 8i64))(v51[11], 64i64);
    v37 = (hkaiPathfindingUtil::FindPathOutput *)v52;
    if ( v52 )
    {
      *(_DWORD *)(v52 + 8) = 0x1FFFF;
      *(_QWORD *)v52 = &hkaiPathfindingUtil::FindPathOutput::`vftable;
      *(_DWORD *)(v52 + 28) = 0x80000000;
      *(_QWORD *)(v52 + 16) = 0i64;
      *(_DWORD *)(v52 + 24) = 0;
      *(_QWORD *)(v52 + 32) = 0i64;
      *(_DWORD *)(v52 + 40) = 0;
      *(_DWORD *)(v52 + 44) = 0x80000000;
      *(_DWORD *)(v52 + 48) = 0;
      *(_DWORD *)(v52 + 52) = -1;
      *(_DWORD *)(v52 + 56) = 2139095022;
      *(_WORD *)(v52 + 60) = 0;
    }
    else
    {
      v37 = 0i64;
    }
    v53 = (hkReferencedObject *)v47[3];
    if ( v53 && v53 != v37 )
      hkReferencedObject::removeReference(v53);
    v47[3] = v37;
    if ( !v49
      || !hkaiNavMeshSearchValidationUtils::validateFindPathInput(
            v4->m_streamingCollection.m_pntr,
            (hkaiPathfindingUtil::FindPathInput *)v50,
            validGoalsMask) )
    {
      generateFailureOutput(v37);
      goto LABEL_81;
    }
    NavMeshJobIndex = PathSearchJobManager::_findNavMeshJobIndex(&v142, (hkaiPathfindingUtil::FindPathInput *)v50);
    v55 = &v142.m_meshCommands.m_data[NavMeshJobIndex];
    v56 = v55->m_size;
    v57 = v56 + 1;
    v58 = v55->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v58 >= (int)v56 + 1 )
    {
      v137.m_enum = HK_SUCCESS;
    }
    else
    {
      v59 = 2 * v58;
      if ( v57 < v59 )
        v57 = v59;
      hkArrayUtil::_reserve(&v137, &hkContainerTempAllocator::s_alloc, v55, v57, 112);
    }
    v60 = (__int64)&v55->m_data[v55->m_size];
    if ( v60 )
      *(_QWORD *)(v60 + 64) = 0i64;
    ++v55->m_size;
    v61 = *(_DWORD *)(v50 + 48);
    v31 = (__int64)&v55->m_data[v56];
    *(_OWORD *)v31 = *(_OWORD *)(v50 + 16);
    *(_DWORD *)(v31 + 32) = v61;
    v11 = (_QWORD *)*(unsigned int *)(v50 + 40);
    v62 = *(_DWORD **)(v50 + 56);
    v9 = *(_QWORD *)(v50 + 32);
    if ( (_DWORD)v11 == 1 )
    {
      v63 = *(_OWORD *)v9;
      *(_DWORD *)(v31 + 36) = *v62;
      *(_OWORD *)(v31 + 16) = v63;
      *(_DWORD *)(v31 + 56) = 1;
    }
    else
    {
      if ( (int)v11 > 1 )
      {
        *(_OWORD *)(v31 + 16) = *(_OWORD *)v9;
        v64 = *v62;
        *(_QWORD *)(v31 + 40) = v9;
        *(_QWORD *)(v31 + 48) = v62;
        *(_DWORD *)(v31 + 36) = v64;
        *(_DWORD *)(v31 + 56) = (_DWORD)v11;
        goto LABEL_70;
      }
      *(_DWORD *)(v31 + 56) = 0;
    }
    *(_QWORD *)(v31 + 48) = 0i64;
    *(_QWORD *)(v31 + 40) = 0i64;
LABEL_70:
    *(_DWORD *)(v31 + 60) = *(_DWORD *)(v50 + 72);
    *(_QWORD *)(v31 + 64) = *(_QWORD *)(v50 + 76);
    v65 = v4->m_maxPathSearchEdgesOut;
    v66 = v37->m_visitedEdges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v66 >= v65 )
    {
      v138.m_enum = HK_SUCCESS;
    }
    else
    {
      v67 = 2 * v66;
      if ( v65 < v67 )
        v65 = v67;
      hkArrayUtil::_reserve(&v138, &hkContainerHeapAllocator::s_alloc, &v37->m_visitedEdges, v65, 4);
    }
    m_maxPathSearchPointsOut = v4->m_maxPathSearchPointsOut;
    p_m_pathOut = &v37->m_pathOut;
    v68 = v37->m_pathOut.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v68 >= m_maxPathSearchPointsOut )
    {
      v134[0].m_enum = HK_SUCCESS;
    }
    else
    {
      v69 = 2 * v68;
      v45 = v134;
      v46 = &v37->m_pathOut;
      if ( m_maxPathSearchPointsOut < v69 )
        m_maxPathSearchPointsOut = v69;
LABEL_42:
      hkArrayUtil::_reserve(v45, &hkContainerHeapAllocator::s_alloc, v46, m_maxPathSearchPointsOut, 48);
    }
    goto LABEL_44;
  }
  v4->m_isPathRequestArrayLocked.m_bool = 0;
LABEL_145:
  sortedRequests.m_size = 0;
  if ( sortedRequests.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sortedRequests.m_data,
      16 * sortedRequests.m_capacityAndFlags);
  sortedRequests.m_data = 0i64;
  sortedRequests.m_capacityAndFlags = 0x80000000;
  v127 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v128 = (_QWORD *)v127[1];
  if ( (unsigned __int64)v128 < v127[3] )
  {
    *v128 = "lt";
    v129 = __rdtsc();
    v130 = v128 + 2;
    *((_DWORD *)v130 - 2) = v129;
    v127[1] = v130;
  }
}

// File Line: 617
// RVA: 0xC06050
void __fastcall hkaiWorld::stepPathSearches(hkaiWorld *this)
{
  int m_maxEstimatedIterationsPerStep; // r14d
  int v3; // r12d
  __int64 v4; // r15
  hkaiWorld::PathType m_pathType; // ecx
  hkaiNavVolumePathRequestInfo *m_request; // rdi
  _QWORD **Value; // rax
  __int64 v8; // rax
  hkaiVolumePathfindingUtil::FindPathOutput *v9; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkaiPathRequestInfoOwner *m_owner; // rcx
  hkaiVolumePathfindingUtil::FindPathInput *v12; // rsi
  int m_maxNumberOfIterations; // ecx
  hkBaseObjectVtbl *v14; // rax
  hkaiNavMeshPathRequestInfo *v15; // rdi
  _QWORD **v16; // rax
  __int64 v17; // rax
  hkReferencedObject *v18; // rcx
  hkaiPathRequestInfoOwner *v19; // rcx
  hkaiPathfindingUtil::FindPathInput *v20; // rsi
  int v21; // ecx
  int m_capacityAndFlags; // r8d
  hkArray<hkaiWorld::SortedRequest,hkContainerHeapAllocator> sortedRequests; // [rsp+20h] [rbp-D8h] BYREF
  hkaiPathfindingUtil::FindPathInput input; // [rsp+30h] [rbp-C8h] BYREF

  this->m_isPathRequestArrayLocked.m_bool = 1;
  sortedRequests.m_capacityAndFlags = 0x80000000;
  sortedRequests.m_data = 0i64;
  sortedRequests.m_size = 0;
  hkaiWorld::prepareRequestArray(this, &sortedRequests);
  m_maxEstimatedIterationsPerStep = 0x7FFFFFFF;
  v3 = 0;
  if ( this->m_maxEstimatedIterationsPerStep >= 0 )
    m_maxEstimatedIterationsPerStep = this->m_maxEstimatedIterationsPerStep;
  if ( sortedRequests.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      m_pathType = sortedRequests.m_data[v4].m_pathType;
      if ( m_pathType )
      {
        if ( m_pathType == PATH_TYPE_NAVVOLUME )
        {
          m_request = (hkaiNavVolumePathRequestInfo *)sortedRequests.m_data[v4].m_request;
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v8 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
          v9 = (hkaiVolumePathfindingUtil::FindPathOutput *)v8;
          if ( v8 )
          {
            *(_DWORD *)(v8 + 8) = 0x1FFFF;
            *(_QWORD *)v8 = &hkaiVolumePathfindingUtil::FindPathOutput::`vftable;
            *(_QWORD *)(v8 + 16) = 0i64;
            *(_DWORD *)(v8 + 24) = 0;
            *(_DWORD *)(v8 + 28) = 0x80000000;
            *(_QWORD *)(v8 + 32) = 0i64;
            *(_DWORD *)(v8 + 40) = 0;
            *(_DWORD *)(v8 + 44) = 0x80000000;
            *(_DWORD *)(v8 + 48) = 0;
            *(_DWORD *)(v8 + 52) = -1;
            *(_DWORD *)(v8 + 56) = 2139095022;
            *(_WORD *)(v8 + 60) = 0;
          }
          else
          {
            v9 = 0i64;
          }
          m_pntr = m_request->m_output.m_pntr;
          if ( m_pntr && m_pntr != v9 )
            hkReferencedObject::removeReference(m_pntr);
          m_request->m_output.m_pntr = v9;
          m_owner = m_request->m_owner;
          v12 = m_request->m_input.m_pntr;
          if ( m_owner )
            m_owner->vfptr->prePathSearchCallback(m_owner, m_request);
          hkaiVolumePathfindingUtil::FindPathInput::FindPathInput((hkaiVolumePathfindingUtil::FindPathInput *)&input, 0);
          hkaiVolumePathfindingUtil::FindPathInput::operator=((hkaiVolumePathfindingUtil::FindPathInput *)&input, v12);
          if ( this->m_maxEstimatedIterationsPerStep >= 0 )
          {
            m_maxNumberOfIterations = m_maxEstimatedIterationsPerStep;
            if ( input.m_maxNumberOfIterations < m_maxEstimatedIterationsPerStep )
              m_maxNumberOfIterations = input.m_maxNumberOfIterations;
            input.m_maxNumberOfIterations = m_maxNumberOfIterations;
          }
          hkaiVolumePathfindingUtil::FindPathInput::checkDeterminism((hkaiVolumePathfindingUtil::FindPathInput *)&input);
          hkaiVolumePathfindingUtil::findPath(
            this->m_streamingCollection.m_pntr,
            (hkaiVolumePathfindingUtil::FindPathInput *)&input,
            v9);
          _firePathRequestProcessedCallbacks<hkaiNavVolumePathRequestInfo>(&this->m_listeners, m_request);
          hkaiVolumePathfindingUtil::FindPathOutput::checkDeterminism(v9);
          v14 = (hkBaseObjectVtbl *)&hkaiVolumePathfindingUtil::FindPathInput::`vftable;
LABEL_20:
          m_maxEstimatedIterationsPerStep -= v9->m_outputParameters.m_numIterations;
          input.m_goalFaceKeys.m_size = 0;
          input.vfptr = v14;
          if ( input.m_goalFaceKeys.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              input.m_goalFaceKeys.m_data,
              4 * input.m_goalFaceKeys.m_capacityAndFlags);
          input.m_goalFaceKeys.m_data = 0i64;
          input.m_goalFaceKeys.m_capacityAndFlags = 0x80000000;
          input.m_goalPoints.m_size = 0;
          if ( input.m_goalPoints.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              input.m_goalPoints.m_data,
              16 * input.m_goalPoints.m_capacityAndFlags);
        }
      }
      else
      {
        v15 = (hkaiNavMeshPathRequestInfo *)sortedRequests.m_data[v4].m_request;
        v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v17 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 64i64);
        v9 = (hkaiVolumePathfindingUtil::FindPathOutput *)v17;
        if ( v17 )
        {
          *(_DWORD *)(v17 + 8) = 0x1FFFF;
          *(_QWORD *)v17 = &hkaiPathfindingUtil::FindPathOutput::`vftable;
          *(_QWORD *)(v17 + 16) = 0i64;
          *(_DWORD *)(v17 + 24) = 0;
          *(_DWORD *)(v17 + 28) = 0x80000000;
          *(_QWORD *)(v17 + 32) = 0i64;
          *(_DWORD *)(v17 + 40) = 0;
          *(_DWORD *)(v17 + 44) = 0x80000000;
          *(_DWORD *)(v17 + 48) = 0;
          *(_DWORD *)(v17 + 52) = -1;
          *(_DWORD *)(v17 + 56) = 2139095022;
          *(_WORD *)(v17 + 60) = 0;
        }
        else
        {
          v9 = 0i64;
        }
        v18 = v15->m_output.m_pntr;
        if ( v18 && v18 != v9 )
          hkReferencedObject::removeReference(v18);
        v15->m_output.m_pntr = (hkaiPathfindingUtil::FindPathOutput *)v9;
        v19 = v15->m_owner;
        v20 = v15->m_input.m_pntr;
        if ( v19 && v19->vfptr->prePathSearchCallback(v19, v15) )
        {
          hkaiPathfindingUtil::FindPathInput::FindPathInput(&input, 0);
          hkaiPathfindingUtil::FindPathInput::operator=(&input, v20);
          if ( this->m_maxEstimatedIterationsPerStep >= 0 )
          {
            v21 = m_maxEstimatedIterationsPerStep;
            if ( input.m_maxNumberOfIterations < m_maxEstimatedIterationsPerStep )
              v21 = input.m_maxNumberOfIterations;
            input.m_maxNumberOfIterations = v21;
          }
          hkaiPathfindingUtil::FindPathInput::checkDeterminism(&input);
          hkaiPathfindingUtil::findPath(
            this->m_streamingCollection.m_pntr,
            &input,
            (hkaiPathfindingUtil::FindPathOutput *)v9);
          _firePathRequestProcessedCallbacks<hkaiNavMeshPathRequestInfo>(&this->m_listeners, v15);
          hkaiPathfindingUtil::FindPathOutput::checkDeterminism((hkaiPathfindingUtil::FindPathOutput *)v9);
          v14 = (hkBaseObjectVtbl *)&hkaiPathfindingUtil::FindPathInput::`vftable;
          goto LABEL_20;
        }
        generateFailureOutput((hkaiPathfindingUtil::FindPathOutput *)v9);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < sortedRequests.m_size );
  }
  hkaiWorld::incrementRequestPriorities(this);
  m_capacityAndFlags = sortedRequests.m_capacityAndFlags;
  this->m_isPathRequestArrayLocked.m_bool = 0;
  sortedRequests.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      sortedRequests.m_data,
      16 * m_capacityAndFlags);
}

// File Line: 720
// RVA: 0xC05EB0
void __fastcall hkaiWorld::_deleteNavMeshPathRequestAt(hkaiWorld *this, int i)
{
  __int64 v4; // rsi
  hkaiNavMeshPathRequestInfo *v5; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkReferencedObject *v7; // rcx
  __int64 v8; // rcx
  hkaiNavMeshPathRequestInfo *m_data; // rax
  __int64 v10; // rdx
  hkaiNavMeshPathRequestInfo *v11; // r8
  hkaiNavMeshPathRequestInfo *v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx

  v4 = i;
  v5 = &this->m_navMeshPathRequests.m_data[v4];
  v5->m_markedForDeletion.m_bool = 1;
  m_pntr = v5->m_input.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  v5->m_input.m_pntr = 0i64;
  v7 = v5->m_output.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v5->m_output.m_pntr = 0i64;
  this->m_navMeshPathRequests.m_data[v4].vfptr->__vecDelDtor(&this->m_navMeshPathRequests.m_data[v4], 0i64);
  v8 = --this->m_navMeshPathRequests.m_size;
  if ( (_DWORD)v8 != i )
  {
    m_data = this->m_navMeshPathRequests.m_data;
    v10 = 7i64;
    v11 = &m_data[v8];
    v12 = &m_data[v4];
    v13 = (char *)v11 - (char *)v12;
    do
    {
      v14 = *(__int64 *)((char *)&v12->vfptr + v13);
      v12 = (hkaiNavMeshPathRequestInfo *)((char *)v12 + 8);
      *(_QWORD *)&v12[-1].m_markedForDeletion.m_bool = v14;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 726
// RVA: 0xC05F80
void __fastcall hkaiWorld::_deleteNavVolumePathRequestAt(hkaiWorld *this, int i)
{
  __int64 v4; // rsi
  hkaiNavVolumePathRequestInfo *v5; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkReferencedObject *v7; // rcx
  __int64 v8; // rcx
  hkaiNavVolumePathRequestInfo *m_data; // rax
  __int64 v10; // rdx
  hkaiNavVolumePathRequestInfo *v11; // r8
  hkaiNavVolumePathRequestInfo *v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx

  v4 = i;
  v5 = &this->m_navVolumePathRequests.m_data[v4];
  v5->m_markedForDeletion.m_bool = 1;
  m_pntr = v5->m_input.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  v5->m_input.m_pntr = 0i64;
  v7 = v5->m_output.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v5->m_output.m_pntr = 0i64;
  this->m_navVolumePathRequests.m_data[v4].vfptr->__vecDelDtor(&this->m_navVolumePathRequests.m_data[v4], 0i64);
  v8 = --this->m_navVolumePathRequests.m_size;
  if ( (_DWORD)v8 != i )
  {
    m_data = this->m_navVolumePathRequests.m_data;
    v10 = 7i64;
    v11 = &m_data[v8];
    v12 = &m_data[v4];
    v13 = (char *)v11 - (char *)v12;
    do
    {
      v14 = *(__int64 *)((char *)&v12->vfptr + v13);
      v12 = (hkaiNavVolumePathRequestInfo *)((char *)v12 + 8);
      *(_QWORD *)&v12[-1].m_markedForDeletion.m_bool = v14;
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
  __int64 v5; // r10
  __int64 v6; // rdi
  hkaiNavMeshPathRequestInfo *m_data; // r11
  __m128 *m_pntr; // rdx
  int v9; // r8d
  __int64 v10; // rcx
  hkaiPathfindingUtil::FindPathOutput *v11; // rdx
  int i; // eax

  v2 = 0;
  if ( this->m_navMeshPathRequests.m_size > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    do
    {
      m_data = this->m_navMeshPathRequests.m_data;
      if ( !m_data[v6].m_markedForDeletion.m_bool )
      {
        m_pntr = (__m128 *)m_data[v6].m_input.m_pntr;
        v9 = 0;
        m_pntr[1] = _mm_add_ps(m_pntr[1], shift->m_quad);
        if ( m_pntr[2].m128_i32[2] > 0 )
        {
          v10 = 0i64;
          do
          {
            ++v9;
            v10 += 16i64;
            *(__m128 *)(v10 + m_pntr[2].m128_u64[0] - 16) = _mm_add_ps(
                                                              *(__m128 *)(v10 + m_pntr[2].m128_u64[0] - 16),
                                                              shift->m_quad);
          }
          while ( v9 < m_pntr[2].m128_i32[2] );
        }
        v11 = m_data[v6].m_output.m_pntr;
        if ( v11 )
        {
          for ( i = 0;
                i < v11->m_pathOut.m_size;
                v11->m_pathOut.m_data[v5].m_position.m_quad = _mm_add_ps(
                                                                v11->m_pathOut.m_data[v5].m_position.m_quad,
                                                                shift->m_quad) )
          {
            ++i;
          }
        }
      }
      ++v2;
      ++v6;
      ++v5;
    }
    while ( v2 < this->m_navMeshPathRequests.m_size );
  }
}

