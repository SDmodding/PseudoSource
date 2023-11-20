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
void __fastcall hkaiStreamingSet::_findOrExpandSetsForUids(hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *streamingSetsA, hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *streamingSetsB, unsigned int uidA, unsigned int uidB, hkaiStreamingSet **setAOut, hkaiStreamingSet **setBOut)
{
  int v6; // er11
  signed int v7; // ebp
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v8; // rbx
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v9; // rdi
  signed int v10; // esi
  int v11; // er10
  hkaiStreamingSet *v12; // rax
  int v13; // edx
  int v14; // ecx
  hkaiStreamingSet *v15; // rax
  int v16; // er9
  int v17; // eax
  int v18; // eax
  signed __int64 v19; // rax
  int v20; // er9
  int v21; // eax
  int v22; // eax
  signed __int64 v23; // rax
  hkResult result; // [rsp+50h] [rbp+8h]

  v6 = streamingSetsA->m_size;
  v7 = -1;
  v8 = streamingSetsB;
  v9 = streamingSetsA;
  v10 = -1;
  v11 = 0;
  if ( v6 > 0 )
  {
    v12 = streamingSetsA->m_data;
    while ( v12->m_thisUid != uidA || v12->m_oppositeUid != uidB )
    {
      ++v11;
      ++v12;
      if ( v11 >= v6 )
        goto LABEL_8;
    }
    v7 = v11;
  }
LABEL_8:
  v13 = streamingSetsB->m_size;
  v14 = 0;
  if ( v13 > 0 )
  {
    v15 = v8->m_data;
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
    v16 = v6 + 1;
    v7 = v6;
    v17 = v9->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 < v6 + 1 )
    {
      v18 = 2 * v17;
      if ( v16 < v18 )
        v16 = v18;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9, v16, 56);
    }
    v19 = (signed __int64)&v9->m_data[v9->m_size];
    if ( v19 )
    {
      *(_QWORD *)v19 = 0i64;
      *(_QWORD *)(v19 + 8) = 0i64;
      *(_DWORD *)(v19 + 16) = 0;
      *(_DWORD *)(v19 + 20) = 2147483648;
      *(_QWORD *)(v19 + 24) = 0i64;
      *(_DWORD *)(v19 + 32) = 0;
      *(_DWORD *)(v19 + 36) = 2147483648;
      *(_QWORD *)(v19 + 40) = 0i64;
      *(_DWORD *)(v19 + 48) = 0;
      *(_DWORD *)(v19 + 52) = 2147483648;
    }
    ++v9->m_size;
  }
  if ( v10 == -1 )
  {
    v10 = v8->m_size;
    v20 = v10 + 1;
    v21 = v8->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < v10 + 1 )
    {
      v22 = 2 * v21;
      if ( v20 < v22 )
        v20 = v22;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v20, 56);
    }
    v23 = (signed __int64)&v8->m_data[v8->m_size];
    if ( v23 )
    {
      *(_QWORD *)v23 = 0i64;
      *(_QWORD *)(v23 + 8) = 0i64;
      *(_DWORD *)(v23 + 16) = 0;
      *(_DWORD *)(v23 + 20) = 2147483648;
      *(_QWORD *)(v23 + 24) = 0i64;
      *(_DWORD *)(v23 + 32) = 0;
      *(_DWORD *)(v23 + 36) = 2147483648;
      *(_QWORD *)(v23 + 40) = 0i64;
      *(_DWORD *)(v23 + 48) = 0;
      *(_DWORD *)(v23 + 52) = 2147483648;
    }
    ++v8->m_size;
  }
  *setAOut = &v9->m_data[v7];
  *setBOut = &v8->m_data[v10];
}

// File Line: 65
// RVA: 0xBB83C0
hkResult *__fastcall hkaiStreamingSet::_copy(hkResult *result, hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *dst, hkArrayBase<hkaiStreamingSet> *src)
{
  __int64 v3; // rbp
  int v4; // eax
  hkArrayBase<hkaiStreamingSet> *v5; // r15
  hkArray<hkaiStreamingSet,hkContainerHeapAllocator> *v6; // rsi
  hkResult *v7; // r14
  int v8; // eax
  int v9; // er9
  int v10; // ebx
  hkaiStreamingSet *v11; // rdi
  __int64 v12; // rax
  int v13; // ecx
  __int64 v14; // rdx
  signed __int64 v15; // rax
  char *v16; // rax
  int v17; // ebx
  hkResult resulta; // [rsp+68h] [rbp+10h]

  v3 = src->m_size;
  v4 = dst->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = src;
  v6 = dst;
  v7 = result;
  if ( v4 >= (signed int)v3 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v8 = 2 * v4;
    v9 = src->m_size;
    if ( (signed int)v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, dst, v9, 56);
    if ( resulta.m_enum )
      goto LABEL_16;
  }
  v10 = v6->m_size - v3 - 1;
  if ( v10 >= 0 )
  {
    v11 = &v6->m_data[v3 + v10];
    do
    {
      hkaiStreamingSet::~hkaiStreamingSet(v11);
      --v11;
      --v10;
    }
    while ( v10 >= 0 );
  }
  v12 = v6->m_size;
  v13 = v3 - v12;
  v14 = (signed int)v3 - (signed int)v12;
  v15 = 56 * v12 + 20;
  if ( v13 > 0 )
  {
    v16 = (char *)v6->m_data + v15;
    do
    {
      if ( v16 != (char *)20 )
      {
        *((_DWORD *)v16 - 5) = 0;
        *((_DWORD *)v16 - 4) = 0;
        *(_QWORD *)(v16 - 12) = 0i64;
        *((_DWORD *)v16 - 1) = 0;
        *(_DWORD *)v16 = 2147483648;
        *(_QWORD *)(v16 + 4) = 0i64;
        *((_DWORD *)v16 + 3) = 0;
        *((_DWORD *)v16 + 4) = 2147483648;
        *(_QWORD *)(v16 + 20) = 0i64;
        *((_DWORD *)v16 + 7) = 0;
        *((_DWORD *)v16 + 8) = 2147483648;
      }
      v16 += 56;
      --v14;
    }
    while ( v14 );
  }
  v6->m_size = v3;
  if ( resulta.m_enum )
  {
LABEL_16:
    v7->m_enum = 1;
    return v7;
  }
  v17 = 0;
  if ( (signed int)v3 > 0 )
  {
    do
    {
      hkaiStreamingSet::operator=(&v6->m_data[v17], &v5->m_data[v17]);
      ++v17;
    }
    while ( v17 < v6->m_size );
  }
  v7->m_enum = 0;
  return v7;
}

// File Line: 78
// RVA: 0xBB8540
signed __int64 __fastcall hkaiStreamingSet::indexOfGraphConnection(hkaiStreamingSet *this, int nodeIndex, int oppNodeIndex)
{
  __int64 v3; // r11
  unsigned int v4; // er10
  __int64 v5; // r9
  hkaiStreamingSet::GraphConnection *v6; // rax

  v3 = this->m_graphConnections.m_size;
  v4 = 0;
  v5 = 0i64;
  if ( v3 <= 0 )
    return 0xFFFFFFFFi64;
  v6 = this->m_graphConnections.m_data;
  while ( v6->m_nodeIndex != nodeIndex || v6->m_oppositeNodeIndex != oppNodeIndex )
  {
    ++v5;
    ++v4;
    ++v6;
    if ( v5 >= v3 )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 92
// RVA: 0xBB8580
bool __fastcall hkaiStreamingSet::containsGraphConnection(hkaiStreamingSet *this, int nodeIndex, int oppNodeIndex)
{
  return (signed int)hkaiStreamingSet::indexOfGraphConnection(this, nodeIndex, oppNodeIndex) >= 0;
}

// File Line: 97
// RVA: 0xBB85A0
signed __int64 __fastcall hkaiStreamingSet::indexOfStreamingSet(hkArrayBase<hkaiStreamingSet> *sets, unsigned int thisUid, unsigned int oppositeUid)
{
  __int64 v3; // r11
  unsigned int v4; // er10
  __int64 v5; // r9
  hkaiStreamingSet *v6; // rax

  v3 = sets->m_size;
  v4 = 0;
  v5 = 0i64;
  if ( v3 <= 0 )
    return 0xFFFFFFFFi64;
  v6 = sets->m_data;
  while ( v6->m_thisUid != thisUid || v6->m_oppositeUid != oppositeUid )
  {
    ++v5;
    ++v4;
    ++v6;
    if ( v5 >= v3 )
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

