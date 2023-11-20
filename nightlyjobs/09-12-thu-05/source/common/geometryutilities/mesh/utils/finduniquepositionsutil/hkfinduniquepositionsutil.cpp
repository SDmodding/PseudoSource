// File Line: 15
// RVA: 0xCA30E0
void __fastcall hkFindUniquePositionsUtil::reset(hkFindUniquePositionsUtil *this, int sizeEstimate)
{
  int v2; // edi
  int v3; // eax
  hkFindUniquePositionsUtil *v4; // rsi
  int v5; // eax
  int v6; // er9
  int v7; // eax
  int v8; // eax
  hkResult result; // [rsp+48h] [rbp+10h]

  this->m_positions.m_size = 0;
  v2 = sizeEstimate;
  v3 = this->m_positions.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = this;
  if ( v3 < sizeEstimate )
  {
    v5 = 2 * v3;
    v6 = sizeEstimate;
    if ( sizeEstimate < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v6, 16);
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_hashMap.m_map.m_elem);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_hashMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v2);
  v4->m_entries.m_size = 0;
  v7 = v4->m_entries.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v2 )
  {
    v8 = 2 * v7;
    if ( v2 < v8 )
      v2 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_entries, v2, 8);
  }
}

// File Line: 23
// RVA: 0xCA35C0
_BOOL8 __fastcall hkFindUniquePositionsUtil_equals(hkVector4f *a, hkVector4f *b)
{
  return (_mm_movemask_ps(_mm_cmpeqps(a->m_quad, b->m_quad)) & 7) == 7;
}

// File Line: 37
// RVA: 0xCA31A0
__int64 __fastcall hkFindUniquePositionsUtil::addPosition(hkFindUniquePositionsUtil *this, hkVector4f *pos)
{
  __m128i v2; // xmm2
  hkVector4f *v3; // rbp
  hkFindUniquePositionsUtil *v4; // rbx
  unsigned __int64 v5; // r15
  int v6; // eax
  unsigned int v7; // esi
  unsigned __int64 v8; // rdi
  __int64 v9; // r10
  hkFindUniquePositionsUtil::Entry *v10; // r11
  __int64 result; // rax
  hkFindUniquePositionsUtil::Entry *v12; // rdx
  hkArray<hkFindUniquePositionsUtil::Entry,hkContainerHeapAllocator> *v13; // rdi
  signed __int64 v14; // r14
  hkFindUniquePositionsUtil::Entry *v15; // rcx
  __int64 v16; // rax
  int v17; // ebx
  __int64 v18; // rdx
  hkFindUniquePositionsUtil::Entry *v19; // r8
  hkFindUniquePositionsUtil::Entry *v20; // r9

  v2 = _mm_load_si128((const __m128i *)pos);
  v3 = pos;
  v4 = this;
  v5 = (_mm_cvtsi128_si32(v2) ^ __ROL4__(_mm_cvtsi128_si32(_mm_shuffle_epi32(v2, 85)), 16) ^ __ROR4__(
                                                                                               _mm_cvtsi128_si32(
                                                                                                 _mm_shuffle_epi32(
                                                                                                   v2,
                                                                                                   170)),
                                                                                               3)) & 0xFFFFFFFE;
  v6 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_hashMap.m_map.m_elem,
                           v5);
  v7 = v4->m_positions.m_size;
  if ( v6 <= v4->m_hashMap.m_map.m_hashMod )
  {
    v12 = v4->m_entries.m_data;
    v13 = &v4->m_entries;
    v14 = SLODWORD(v4->m_hashMap.m_map.m_elem[v6].val);
    v15 = &v12[v14];
    if ( (_mm_movemask_ps(_mm_cmpeqps(v4->m_positions.m_data[v12[v14].m_positionIndex].m_quad, v3->m_quad)) & 7) == 7 )
    {
LABEL_10:
      result = (unsigned int)v15->m_positionIndex;
    }
    else
    {
      while ( 1 )
      {
        v16 = v15->m_nextEntryIndex;
        if ( (signed int)v16 < 0 )
          break;
        v15 = &v12[v16];
        if ( (_mm_movemask_ps(_mm_cmpeqps(v4->m_positions.m_data[v12[v16].m_positionIndex].m_quad, v3->m_quad)) & 7) == 7 )
          goto LABEL_10;
      }
      if ( v7 == (v4->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
      v4->m_positions.m_data[v4->m_positions.m_size++] = (hkVector4f)v3->m_quad;
      v17 = v4->m_entries.m_size;
      if ( v13->m_size == (v13->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, 8);
      v18 = v13->m_size;
      v19 = v13->m_data;
      result = v7;
      v20 = &v13->m_data[v18];
      v13->m_size = v18 + 1;
      v20->m_positionIndex = v7;
      v20->m_nextEntryIndex = v19[v14].m_nextEntryIndex;
      v19[v14].m_nextEntryIndex = v17;
    }
  }
  else
  {
    if ( v7 == (v4->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
    v4->m_positions.m_data[v4->m_positions.m_size++] = (hkVector4f)v3->m_quad;
    v8 = v4->m_entries.m_size;
    if ( v4->m_entries.m_size == (v4->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_entries, 8);
    v9 = v4->m_entries.m_size;
    v10 = &v4->m_entries.m_data[v9];
    v4->m_entries.m_size = v9 + 1;
    v10->m_positionIndex = v7;
    v10->m_nextEntryIndex = -1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_hashMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v5,
      v8);
    result = v7;
  }
  return result;
}

// File Line: 96
// RVA: 0xCA33B0
void __fastcall hkFindUniquePositionsUtil::addPositions(hkFindUniquePositionsUtil *this, hkVector4f *pos, int numPos)
{
  hkVector4f *v3; // rbx
  hkFindUniquePositionsUtil *v4; // rsi
  hkVector4f *v5; // rdi

  v3 = pos;
  v4 = this;
  v5 = &pos[numPos];
  if ( pos != v5 )
  {
    do
    {
      hkFindUniquePositionsUtil::addPosition(v4, v3);
      ++v3;
    }
    while ( v3 != v5 );
  }
}

// File Line: 105
// RVA: 0xCA3400
signed __int64 __fastcall hkFindUniquePositionsUtil::findPosition(hkFindUniquePositionsUtil *this, hkVector4f *pos)
{
  __m128i v2; // xmm2
  hkVector4f *v3; // rdi
  hkFindUniquePositionsUtil *v4; // rbx
  int v5; // eax
  hkFindUniquePositionsUtil::Entry *v6; // rdx
  signed int *v7; // rax
  __int64 v8; // rcx

  v2 = _mm_load_si128((const __m128i *)pos);
  v3 = pos;
  v4 = this;
  v5 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_hashMap.m_map.m_elem,
                           (_mm_cvtsi128_si32(v2) ^ __ROL4__(_mm_cvtsi128_si32(_mm_shuffle_epi32(v2, 85)), 16) ^ __ROR4__(_mm_cvtsi128_si32(_mm_shuffle_epi32(v2, 170)), 3)) & 0xFFFFFFFE);
  if ( v5 <= v4->m_hashMap.m_map.m_hashMod )
  {
    v6 = v4->m_entries.m_data;
    v7 = (signed int *)&v6[SLODWORD(v4->m_hashMap.m_map.m_elem[v5].val)];
    if ( (_mm_movemask_ps(_mm_cmpeqps(v4->m_positions.m_data[*v7].m_quad, v3->m_quad)) & 7) == 7 )
      return (unsigned int)*v7;
    while ( 1 )
    {
      v8 = v7[1];
      if ( (signed int)v8 < 0 )
        break;
      v7 = (signed int *)&v6[v8];
      if ( (_mm_movemask_ps(_mm_cmpeqps(v4->m_positions.m_data[v6[v8].m_positionIndex].m_quad, v3->m_quad)) & 7) == 7 )
        return (unsigned int)*v7;
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 136
// RVA: 0xCA34F0
unsigned __int64 __fastcall hkFindUniquePositionsUtil::getSizeInBytesFor(int N)
{
  return 16i64 * N
       + ((8i64 * N + 15) & 0xFFFFFFFFFFFFFFF0ui64)
       + (((unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(N)
         + 15) & 0xFFFFFFF0);
}

// File Line: 144
// RVA: 0xCA3530
void __fastcall hkFindUniquePositionsUtil::setBuffer(hkFindUniquePositionsUtil *this, void *_buffer, int numPoints)
{
  char *v3; // rsi
  int v4; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rbp
  int v6; // ebx
  int v7; // eax

  this->m_positions.m_data = (hkVector4f *)_buffer;
  v3 = (char *)_buffer;
  this->m_positions.m_size = 0;
  v4 = 16 * numPoints;
  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_hashMap.m_map.m_elem;
  this->m_positions.m_capacityAndFlags = numPoints | 0x80000000;
  v6 = numPoints;
  this->m_entries.m_size = 0;
  this->m_entries.m_capacityAndFlags = numPoints | 0x80000000;
  this->m_entries.m_data = (hkFindUniquePositionsUtil::Entry *)((char *)_buffer + 16 * numPoints);
  if ( this != (hkFindUniquePositionsUtil *)-16i64 )
  {
    v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(numPoints);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      v5,
      &v3[v4 + ((8 * v6 + 15) & 0xFFFFFFF0)],
      v7);
  }
}

