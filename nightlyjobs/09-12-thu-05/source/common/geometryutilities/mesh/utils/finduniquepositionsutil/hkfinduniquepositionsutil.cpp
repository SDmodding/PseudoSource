// File Line: 15
// RVA: 0xCA30E0
void __fastcall hkFindUniquePositionsUtil::reset(hkFindUniquePositionsUtil *this, int sizeEstimate)
{
  int v2; // edi
  int v3; // eax
  int v5; // eax
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  this->m_positions.m_size = 0;
  v2 = sizeEstimate;
  v3 = this->m_positions.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < sizeEstimate )
  {
    v5 = 2 * v3;
    v6 = sizeEstimate;
    if ( sizeEstimate < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_positions.m_data, v6, 16);
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_hashMap.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &this->m_hashMap.m_map,
    &hkContainerHeapAllocator::s_alloc,
    v2);
  this->m_entries.m_size = 0;
  v7 = this->m_entries.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v2 )
  {
    v8 = 2 * v7;
    if ( v2 < v8 )
      v2 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_entries.m_data, v2, 8);
  }
}

// File Line: 23
// RVA: 0xCA35C0
_BOOL8 __fastcall hkFindUniquePositionsUtil_equals(hkVector4f *a, hkVector4f *b)
{
  return (_mm_movemask_ps(_mm_cmpeq_ps(a->m_quad, b->m_quad)) & 7) == 7;
}

// File Line: 37
// RVA: 0xCA31A0
__int64 __fastcall hkFindUniquePositionsUtil::addPosition(hkFindUniquePositionsUtil *this, const __m128i *pos)
{
  __m128i si128; // xmm2
  unsigned __int64 v5; // r15
  int Key; // eax
  unsigned int m_size; // esi
  unsigned __int64 v8; // rdi
  __int64 v9; // r10
  hkFindUniquePositionsUtil::Entry *v10; // r11
  __int64 result; // rax
  hkFindUniquePositionsUtil::Entry *m_data; // rdx
  hkArray<hkFindUniquePositionsUtil::Entry,hkContainerHeapAllocator> *p_m_entries; // rdi
  __int64 val_low; // r14
  int *v15; // rcx
  __int64 v16; // rax
  int v17; // ebx
  __int64 v18; // rdx
  hkFindUniquePositionsUtil::Entry *v19; // r8
  hkFindUniquePositionsUtil::Entry *v20; // r9

  si128 = _mm_load_si128(pos);
  v5 = (_mm_cvtsi128_si32(si128) ^ __ROL4__(_mm_cvtsi128_si32(_mm_shuffle_epi32(si128, 85)), 16) ^ __ROR4__(
                                                                                                     _mm_cvtsi128_si32(_mm_shuffle_epi32(si128, 170)),
                                                                                                     3)) & 0xFFFFFFFE;
  Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                        &this->m_hashMap.m_map,
                        v5);
  m_size = this->m_positions.m_size;
  if ( Key <= this->m_hashMap.m_map.m_hashMod )
  {
    m_data = this->m_entries.m_data;
    p_m_entries = &this->m_entries;
    val_low = SLODWORD(this->m_hashMap.m_map.m_elem[Key].val);
    v15 = (int *)&m_data[val_low];
    if ( (_mm_movemask_ps(_mm_cmpeq_ps(this->m_positions.m_data[m_data[val_low].m_positionIndex].m_quad, *(__m128 *)pos)) & 7) == 7 )
    {
      return (unsigned int)*v15;
    }
    else
    {
      while ( 1 )
      {
        v16 = v15[1];
        if ( (int)v16 < 0 )
          break;
        v15 = (int *)&m_data[v16];
        if ( (_mm_movemask_ps(_mm_cmpeq_ps(this->m_positions.m_data[*v15].m_quad, *(__m128 *)pos)) & 7) == 7 )
          return (unsigned int)*v15;
      }
      if ( m_size == (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_positions.m_data, 16);
      this->m_positions.m_data[this->m_positions.m_size++] = (hkVector4f)*pos;
      v17 = this->m_entries.m_size;
      if ( p_m_entries->m_size == (p_m_entries->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_entries->m_data, 8);
      v18 = p_m_entries->m_size;
      v19 = p_m_entries->m_data;
      result = m_size;
      v20 = &p_m_entries->m_data[v18];
      p_m_entries->m_size = v18 + 1;
      v20->m_positionIndex = m_size;
      v20->m_nextEntryIndex = v19[val_low].m_nextEntryIndex;
      v19[val_low].m_nextEntryIndex = v17;
    }
  }
  else
  {
    if ( m_size == (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_positions.m_data, 16);
    this->m_positions.m_data[this->m_positions.m_size++] = (hkVector4f)*pos;
    v8 = this->m_entries.m_size;
    if ( this->m_entries.m_size == (this->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_entries.m_data, 8);
    v9 = this->m_entries.m_size;
    v10 = &this->m_entries.m_data[v9];
    this->m_entries.m_size = v9 + 1;
    v10->m_positionIndex = m_size;
    v10->m_nextEntryIndex = -1;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &this->m_hashMap.m_map,
      &hkContainerHeapAllocator::s_alloc,
      v5,
      v8);
    return m_size;
  }
  return result;
}

// File Line: 96
// RVA: 0xCA33B0
void __fastcall hkFindUniquePositionsUtil::addPositions(hkFindUniquePositionsUtil *this, hkVector4f *pos, int numPos)
{
  const __m128i *v3; // rbx
  hkVector4f *v5; // rdi

  v3 = (const __m128i *)pos;
  v5 = &pos[numPos];
  if ( pos != v5 )
  {
    do
      hkFindUniquePositionsUtil::addPosition(this, v3++);
    while ( v3 != (const __m128i *)v5 );
  }
}

// File Line: 105
// RVA: 0xCA3400
__int64 __fastcall hkFindUniquePositionsUtil::findPosition(hkFindUniquePositionsUtil *this, const __m128i *pos)
{
  __m128i si128; // xmm2
  int Key; // eax
  hkFindUniquePositionsUtil::Entry *m_data; // rdx
  int *v7; // rax
  __int64 v8; // rcx

  si128 = _mm_load_si128(pos);
  Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                        &this->m_hashMap.m_map,
                        (_mm_cvtsi128_si32(si128) ^ __ROL4__(_mm_cvtsi128_si32(_mm_shuffle_epi32(si128, 85)), 16) ^ __ROR4__(_mm_cvtsi128_si32(_mm_shuffle_epi32(si128, 170)), 3)) & 0xFFFFFFFE);
  if ( Key <= this->m_hashMap.m_map.m_hashMod )
  {
    m_data = this->m_entries.m_data;
    v7 = (int *)&m_data[SLODWORD(this->m_hashMap.m_map.m_elem[Key].val)];
    if ( (_mm_movemask_ps(_mm_cmpeq_ps(this->m_positions.m_data[*v7].m_quad, *(__m128 *)pos)) & 7) == 7 )
      return (unsigned int)*v7;
    while ( 1 )
    {
      v8 = v7[1];
      if ( (int)v8 < 0 )
        break;
      v7 = (int *)&m_data[v8];
      if ( (_mm_movemask_ps(_mm_cmpeq_ps(this->m_positions.m_data[*v7].m_quad, *(__m128 *)pos)) & 7) == 7 )
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
void __fastcall hkFindUniquePositionsUtil::setBuffer(
        hkFindUniquePositionsUtil *this,
        hkVector4f *_buffer,
        int numPoints)
{
  int v4; // edi
  hkPointerMap<unsigned int,int,hkContainerHeapAllocator> *p_m_hashMap; // rbp
  int SizeInBytesFor; // eax

  this->m_positions.m_data = _buffer;
  this->m_positions.m_size = 0;
  v4 = 16 * numPoints;
  p_m_hashMap = &this->m_hashMap;
  this->m_positions.m_capacityAndFlags = numPoints | 0x80000000;
  this->m_entries.m_size = 0;
  this->m_entries.m_capacityAndFlags = numPoints | 0x80000000;
  this->m_entries.m_data = (hkFindUniquePositionsUtil::Entry *)&_buffer[numPoints];
  if ( this != (hkFindUniquePositionsUtil *)-16i64 )
  {
    SizeInBytesFor = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(numPoints);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      &p_m_hashMap->m_map,
      (char *)_buffer + (int)(v4 + ((8 * numPoints + 15) & 0xFFFFFFF0)),
      SizeInBytesFor);
  }
}

