// File Line: 19
// RVA: 0xBB81D0
void __fastcall hkaiStreamingSet::GraphConnection::GraphConnection(hkaiStreamingSet::GraphConnection *this)
{
  *(_QWORD *)&this->m_nodeIndex = -1i64;
  this->m_edgeData = 0;
  this->m_edgeCost.m_value = -16512;
}

// File Line: 25
// RVA: 0xBB8200
void __fastcall hkaiStreamingSet::_findOrExpandSetsForUids(
        hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *streamingSetsA,
        hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *streamingSetsB,
        unsigned int uidA,
        unsigned int uidB,
        hkaiStreamingSet **setAOut,
        hkaiStreamingSet **setBOut)
{
  int m_size; // r11d
  int v7; // ebp
  int v10; // esi
  int v11; // r10d
  hkaiStreamingSet *m_data; // rax
  int v13; // edx
  int v14; // ecx
  hkaiStreamingSet *v15; // rax
  int v16; // r9d
  int v17; // eax
  int v18; // eax
  hkaiStreamingSet *v19; // rax
  int v20; // r9d
  int v21; // eax
  int v22; // eax
  hkaiStreamingSet *v23; // rax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = streamingSetsA->m_size;
  v7 = -1;
  v10 = -1;
  v11 = 0;
  if ( m_size > 0 )
  {
    m_data = streamingSetsA->m_data;
    while ( m_data->m_thisUid != uidA || m_data->m_oppositeUid != uidB )
    {
      ++v11;
      ++m_data;
      if ( v11 >= m_size )
        goto LABEL_8;
    }
    v7 = v11;
  }
LABEL_8:
  v13 = streamingSetsB->m_size;
  v14 = 0;
  if ( v13 > 0 )
  {
    v15 = streamingSetsB->m_data;
    while ( v15->m_thisUid != uidB || v15->m_oppositeUid != uidA )
    {
      ++v14;
      ++v15;
      if ( v14 >= v13 )
        goto LABEL_15;
    }
    v10 = v14;
  }
LABEL_15:
  if ( v7 == -1 )
  {
    v16 = m_size + 1;
    v7 = m_size;
    v17 = streamingSetsA->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 < m_size + 1 )
    {
      v18 = 2 * v17;
      if ( v16 < v18 )
        v16 = v18;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, streamingSetsA, v16, 56);
    }
    v19 = &streamingSetsA->m_data[streamingSetsA->m_size];
    if ( v19 )
    {
      *(_QWORD *)&v19->m_thisUid = 0i64;
      v19->m_meshConnections.m_data = 0i64;
      v19->m_meshConnections.m_size = 0;
      v19->m_meshConnections.m_capacityAndFlags = 0x80000000;
      v19->m_graphConnections.m_data = 0i64;
      v19->m_graphConnections.m_size = 0;
      v19->m_graphConnections.m_capacityAndFlags = 0x80000000;
      v19->m_volumeConnections.m_data = 0i64;
      v19->m_volumeConnections.m_size = 0;
      v19->m_volumeConnections.m_capacityAndFlags = 0x80000000;
    }
    ++streamingSetsA->m_size;
  }
  if ( v10 == -1 )
  {
    v10 = streamingSetsB->m_size;
    v20 = v10 + 1;
    v21 = streamingSetsB->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < v10 + 1 )
    {
      v22 = 2 * v21;
      if ( v20 < v22 )
        v20 = v22;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, streamingSetsB, v20, 56);
    }
    v23 = &streamingSetsB->m_data[streamingSetsB->m_size];
    if ( v23 )
    {
      *(_QWORD *)&v23->m_thisUid = 0i64;
      v23->m_meshConnections.m_data = 0i64;
      v23->m_meshConnections.m_size = 0;
      v23->m_meshConnections.m_capacityAndFlags = 0x80000000;
      v23->m_graphConnections.m_data = 0i64;
      v23->m_graphConnections.m_size = 0;
      v23->m_graphConnections.m_capacityAndFlags = 0x80000000;
      v23->m_volumeConnections.m_data = 0i64;
      v23->m_volumeConnections.m_size = 0;
      v23->m_volumeConnections.m_capacityAndFlags = 0x80000000;
    }
    ++streamingSetsB->m_size;
  }
  *setAOut = &streamingSetsA->m_data[v7];
  *setBOut = &streamingSetsB->m_data[v10];
}

// File Line: 65
// RVA: 0xBB83C0
hkResult *__fastcall hkaiStreamingSet::_copy(
        hkResult *result,
        hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *dst,
        hkArrayBase<hkaiStreamingSet> *src)
{
  __int64 m_size; // rbp
  int v4; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // ebx
  hkaiStreamingSet *v11; // rdi
  __int64 v12; // rax
  int v13; // ecx
  __int64 v14; // rdx
  __int64 v15; // rax
  char *v16; // rax
  int v17; // ebx
  hkResult resulta; // [rsp+68h] [rbp+10h] BYREF

  m_size = src->m_size;
  v4 = dst->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 >= (int)m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v8 = 2 * v4;
    v9 = src->m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, dst, v9, 56);
    if ( resulta.m_enum )
      goto LABEL_16;
  }
  v10 = dst->m_size - m_size - 1;
  if ( v10 >= 0 )
  {
    v11 = &dst->m_data[m_size + v10];
    do
    {
      hkaiStreamingSet::~hkaiStreamingSet(v11--);
      --v10;
    }
    while ( v10 >= 0 );
  }
  v12 = dst->m_size;
  v13 = m_size - v12;
  v14 = (int)m_size - (int)v12;
  v15 = 56 * v12 + 20;
  if ( v13 > 0 )
  {
    v16 = (char *)dst->m_data + v15;
    do
    {
      if ( v16 != (char *)20 )
      {
        *((_DWORD *)v16 - 5) = 0;
        *((_DWORD *)v16 - 4) = 0;
        *(_QWORD *)(v16 - 12) = 0i64;
        *((_DWORD *)v16 - 1) = 0;
        *(_DWORD *)v16 = 0x80000000;
        *(_QWORD *)(v16 + 4) = 0i64;
        *((_DWORD *)v16 + 3) = 0;
        *((_DWORD *)v16 + 4) = 0x80000000;
        *(_QWORD *)(v16 + 20) = 0i64;
        *((_DWORD *)v16 + 7) = 0;
        *((_DWORD *)v16 + 8) = 0x80000000;
      }
      v16 += 56;
      --v14;
    }
    while ( v14 );
  }
  dst->m_size = m_size;
  if ( resulta.m_enum )
  {
LABEL_16:
    result->m_enum = HK_FAILURE;
    return result;
  }
  v17 = 0;
  if ( (int)m_size > 0 )
  {
    do
    {
      hkaiStreamingSet::operator=(&dst->m_data[v17], &src->m_data[v17]);
      ++v17;
    }
    while ( v17 < dst->m_size );
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 78
// RVA: 0xBB8540
__int64 __fastcall hkaiStreamingSet::indexOfGraphConnection(hkaiStreamingSet *this, int nodeIndex, int oppNodeIndex)
{
  __int64 m_size; // r11
  unsigned int v4; // r10d
  __int64 v5; // r9
  hkaiStreamingSet::GraphConnection *i; // rax

  m_size = this->m_graphConnections.m_size;
  v4 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = this->m_graphConnections.m_data; i->m_nodeIndex != nodeIndex || i->m_oppositeNodeIndex != oppNodeIndex; ++i )
  {
    ++v5;
    ++v4;
    if ( v5 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 92
// RVA: 0xBB8580
bool __fastcall hkaiStreamingSet::containsGraphConnection(hkaiStreamingSet *this, int nodeIndex, int oppNodeIndex)
{
  return (int)hkaiStreamingSet::indexOfGraphConnection(this, nodeIndex, oppNodeIndex) >= 0;
}

// File Line: 97
// RVA: 0xBB85A0
__int64 __fastcall hkaiStreamingSet::indexOfStreamingSet(
        hkArrayBase<hkaiStreamingSet> *sets,
        unsigned int thisUid,
        unsigned int oppositeUid)
{
  __int64 m_size; // r11
  unsigned int v4; // r10d
  __int64 v5; // r9
  hkaiStreamingSet *i; // rax

  m_size = sets->m_size;
  v4 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = sets->m_data; i->m_thisUid != thisUid || i->m_oppositeUid != oppositeUid; ++i )
  {
    ++v5;
    ++v4;
    if ( v5 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 110
// RVA: 0xBB8530
void __fastcall hkaiStreamingSet::checkDeterminism(hkArrayBase<hkaiStreamingSet> *sets)
{
  ;
}

// File Line: 120
// RVA: 0xBB8520
void __fastcall hkaiStreamingSet::checkDeterminism(hkaiStreamingSet *this)
{
  ;
}

