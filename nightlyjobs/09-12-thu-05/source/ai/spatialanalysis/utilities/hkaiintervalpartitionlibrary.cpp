// File Line: 15
// RVA: 0xC3D870
__int64 __fastcall hkaiIntervalPartitionLibrary::addIntervalPartition(hkaiIntervalPartitionLibrary *this, hkaiIntervalPartition *intervalPartition, bool storeYData, bool storeIntData)
{
  unsigned int v4; // er13
  bool v5; // si
  hkaiIntervalPartition *v6; // r15
  hkaiIntervalPartitionLibrary *v7; // rbx
  bool v8; // r12
  hkaiIntervalPartitionLibrary::PartitionRecord *v9; // rcx
  __int64 v10; // rdx
  int v11; // ebp
  int v12; // esi
  int i; // edi
  hkaiIntervalPartition::Interval *v14; // r14
  int v15; // er14
  int j; // edi
  hkaiIntervalPartition::Interval *v17; // rbp
  int v18; // edi
  bool v20; // [rsp+68h] [rbp+20h]
  unsigned int v21; // [rsp+68h] [rbp+20h]

  v20 = storeIntData;
  v4 = this->m_partitionRecords.m_size;
  v5 = storeIntData;
  v6 = intervalPartition;
  v7 = this;
  v8 = storeYData;
  if ( v4 == (this->m_partitionRecords.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_partitionRecords,
      8);
  v9 = v7->m_partitionRecords.m_data;
  v10 = v7->m_partitionRecords.m_size;
  v7->m_partitionRecords.m_size = v10 + 1;
  v9[v10].m_intervalDataOffset = v7->m_data.m_size;
  v9[v10].m_numIntervals = v6->m_intervals.m_size;
  v9[v10].m_hasYData.m_bool = v8;
  v9[v10].m_hasIntData.m_bool = v5;
  v11 = v6->m_intervals.m_size;
  v12 = 0;
  for ( i = 0; i < v11; ++v7->m_data.m_size )
  {
    v14 = hkaiIntervalPartition::getInterval(v6, i);
    if ( v7->m_data.m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
    v7->m_data.m_data[v7->m_data.m_size++] = v14->m_leftX;
    if ( v7->m_data.m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
    ++i;
    v7->m_data.m_data[v7->m_data.m_size] = v14->m_rightX;
  }
  if ( v8 )
  {
    v15 = v6->m_intervals.m_size;
    for ( j = 0; j < v15; ++v7->m_data.m_size )
    {
      v17 = hkaiIntervalPartition::getInterval(v6, j);
      if ( v7->m_data.m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
      v7->m_data.m_data[v7->m_data.m_size++] = v17->m_offset;
      if ( v7->m_data.m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
      ++j;
      v7->m_data.m_data[v7->m_data.m_size] = v17->m_slope;
    }
  }
  if ( v20 )
  {
    v18 = v6->m_intervals.m_size;
    if ( v18 > 0 )
    {
      do
      {
        v21 = hkaiIntervalPartition::getInterval(v6, v12)->m_data;
        if ( v7->m_data.m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 4);
        ++v12;
        LODWORD(v7->m_data.m_data[v7->m_data.m_size++]) = v21;
      }
      while ( v12 < v18 );
    }
  }
  return v4;
}

// File Line: 63
// RVA: 0xC3DA90
__int64 __fastcall hkaiIntervalPartitionLibrary::isDefinedAt(hkaiIntervalPartitionLibrary *this, unsigned int idx, float x)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *v3; // r8
  unsigned int v4; // er10
  float *v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // rax

  v3 = this->m_partitionRecords.m_data;
  v4 = 0;
  v5 = &this->m_data.m_data[v3[idx].m_intervalDataOffset];
  v6 = v3[idx].m_numIntervals;
  v7 = 0i64;
  if ( v6 <= 0 )
    return 0i64;
  while ( x > v5[2 * v7 + 1] )
  {
    if ( ++v7 >= v6 )
      return 0i64;
  }
  LOBYTE(v4) = x >= v5[2 * v7];
  return v4;
}

// File Line: 82
// RVA: 0xC3DAE0
signed __int64 __fastcall hkaiIntervalPartitionLibrary::tryEvaluateYAt(hkaiIntervalPartitionLibrary *this, unsigned int idx, float x, float *y)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *v4; // r8
  float *v5; // r11
  __int64 v6; // rax
  int v7; // edx
  __int64 v8; // rcx
  signed __int64 result; // rax
  float v10; // xmm2_4

  v4 = this->m_partitionRecords.m_data;
  v5 = &this->m_data.m_data[v4[idx].m_intervalDataOffset];
  v6 = v4[idx].m_numIntervals;
  v7 = 0;
  v8 = 0i64;
  if ( (signed int)v6 <= 0 )
    return 0i64;
  while ( x > v5[2 * v8 + 1] )
  {
    ++v8;
    ++v7;
    if ( v8 >= v6 )
      return 0i64;
  }
  if ( x < v5[2 * v8] )
    return 0i64;
  v10 = (float)(x * v5[2 * ((unsigned int)v6 + (signed __int64)v7) + 1])
      + v5[2 * ((unsigned int)v6 + (signed __int64)v7)];
  result = 1i64;
  *y = v10;
  return result;
}

// File Line: 115
// RVA: 0xC3DB50
signed __int64 __fastcall hkaiIntervalPartitionLibrary::tryGetIntDataAt(hkaiIntervalPartitionLibrary *this, unsigned int idx, float x, unsigned int *intData)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *v4; // rbx
  __int64 v5; // r11
  __int64 v6; // rdi
  int v7; // er10
  float *v8; // r8
  int v9; // edx
  __int64 v10; // rax

  v4 = this->m_partitionRecords.m_data;
  v5 = (signed int)idx;
  v6 = v4[idx].m_numIntervals;
  v7 = 0;
  v8 = &this->m_data.m_data[v4[idx].m_intervalDataOffset];
  v9 = 0;
  v10 = 0i64;
  if ( (signed int)v6 <= 0 )
    return 0i64;
  while ( x > v8[2 * v10 + 1] )
  {
    ++v10;
    ++v9;
    if ( v10 >= v6 )
      return 0i64;
  }
  if ( x < v8[2 * v10] )
    return 0i64;
  if ( v4[v5].m_hasYData.m_bool )
    v7 = 2 * v6;
  *intData = LODWORD(v8[v9 + v7 + 2 * v6]);
  return 1i64;
}

// File Line: 146
// RVA: 0xC3DCB0
__int64 __fastcall hkaiIntervalPartitionLibrary::getNumIntervals(hkaiIntervalPartitionLibrary *this, unsigned int idx)
{
  return this->m_partitionRecords.m_data[idx].m_numIntervals;
}

// File Line: 151
// RVA: 0xC3DCD0
void __fastcall hkaiIntervalPartitionLibrary::getInterval(hkaiIntervalPartitionLibrary *this, unsigned int idx, unsigned __int16 intervalIdx, hkaiIntervalPartition::Interval *intervalOut)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *v4; // r11
  __int64 v5; // rdi
  __int64 v6; // rsi
  float *v7; // rbx
  int v8; // er8
  __int64 v9; // rcx

  v4 = this->m_partitionRecords.m_data;
  v5 = v4[idx].m_numIntervals;
  v6 = intervalIdx;
  v7 = &this->m_data.m_data[v4[idx].m_intervalDataOffset];
  v8 = 0;
  intervalOut->m_leftX = v7[2 * v6];
  intervalOut->m_rightX = v7[2 * v6 + 1];
  if ( v4[idx].m_hasYData.m_bool )
  {
    v9 = v6 + (signed int)v5;
    intervalOut->m_offset = v7[2 * v9];
    intervalOut->m_slope = v7[2 * v9 + 1];
  }
  else
  {
    *(_QWORD *)&intervalOut->m_slope = 0i64;
  }
  if ( v4[idx].m_hasIntData.m_bool )
  {
    if ( v4[idx].m_hasYData.m_bool )
      v8 = 2 * v5;
    *(float *)&intervalOut->m_data = v7[v6 + v8 + 2 * v5];
  }
  else
  {
    intervalOut->m_data = -1;
  }
}

// File Line: 182
// RVA: 0xC3DBE0
signed __int64 __fastcall hkaiIntervalPartitionLibrary::getClosestDefined(hkaiIntervalPartitionLibrary *this, unsigned int idx, float *xInOut)
{
  float v3; // xmm4_4
  hkaiIntervalPartitionLibrary *v4; // rax
  __int64 v5; // rcx
  hkaiIntervalPartitionLibrary::PartitionRecord *v6; // rdx
  float *v7; // r10
  unsigned __int16 v8; // r9
  float *v10; // r8
  int v11; // ecx
  signed __int64 v12; // rdx
  float v13; // xmm2_4
  float v14; // xmm3_4

  v3 = *xInOut;
  v4 = this;
  v5 = (signed int)idx;
  v6 = v4->m_partitionRecords.m_data;
  v7 = xInOut;
  v8 = v6[v5].m_numIntervals;
  if ( !v8 )
    return 0i64;
  v10 = &v4->m_data.m_data[v6[v5].m_intervalDataOffset];
  if ( v3 < *v10 )
  {
    *v7 = *v10;
    return 1i64;
  }
  v11 = 0;
  v12 = 0i64;
  if ( 2 * v8 - 1 <= 0 )
  {
LABEL_9:
    *v7 = v10[2 * v8 - 1];
    return 1i64;
  }
  while ( 1 )
  {
    v13 = v10[v12];
    v14 = v10[v12 + 1];
    if ( v3 >= v13 && v3 <= v14 )
      break;
    ++v12;
    ++v11;
    if ( v12 >= 2 * v8 - 1 )
      goto LABEL_9;
  }
  if ( !(v11 % 2) )
    return 1i64;
  if ( (float)(v3 - v13) >= (float)(v14 - v3) )
    v13 = v10[v12 + 1];
  *v7 = v13;
  return 1i64;
}

