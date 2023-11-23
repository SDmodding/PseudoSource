// File Line: 15
// RVA: 0xC3D870
__int64 __fastcall hkaiIntervalPartitionLibrary::addIntervalPartition(
        hkaiIntervalPartitionLibrary *this,
        hkaiIntervalPartition *intervalPartition,
        char storeYData,
        char storeIntData)
{
  unsigned int m_size; // r13d
  hkaiIntervalPartitionLibrary::PartitionRecord *m_data; // rcx
  __int64 v10; // rdx
  int v11; // ebp
  int v12; // esi
  int i; // edi
  hkaiIntervalPartition::Interval *Interval; // r14
  int v15; // r14d
  int j; // edi
  hkaiIntervalPartition::Interval *v17; // rbp
  int v18; // edi
  unsigned int v21; // [rsp+68h] [rbp+20h]

  m_size = this->m_partitionRecords.m_size;
  if ( m_size == (this->m_partitionRecords.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_partitionRecords, 8);
  m_data = this->m_partitionRecords.m_data;
  v10 = this->m_partitionRecords.m_size;
  this->m_partitionRecords.m_size = v10 + 1;
  m_data[v10].m_intervalDataOffset = this->m_data.m_size;
  m_data[v10].m_numIntervals = intervalPartition->m_intervals.m_size;
  m_data[v10].m_hasYData.m_bool = storeYData;
  m_data[v10].m_hasIntData.m_bool = storeIntData;
  v11 = intervalPartition->m_intervals.m_size;
  v12 = 0;
  for ( i = 0; i < v11; ++this->m_data.m_size )
  {
    Interval = hkaiIntervalPartition::getInterval(intervalPartition, i);
    if ( this->m_data.m_size == (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 4);
    this->m_data.m_data[this->m_data.m_size++] = Interval->m_leftX;
    if ( this->m_data.m_size == (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 4);
    ++i;
    this->m_data.m_data[this->m_data.m_size] = Interval->m_rightX;
  }
  if ( storeYData )
  {
    v15 = intervalPartition->m_intervals.m_size;
    for ( j = 0; j < v15; ++this->m_data.m_size )
    {
      v17 = hkaiIntervalPartition::getInterval(intervalPartition, j);
      if ( this->m_data.m_size == (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 4);
      this->m_data.m_data[this->m_data.m_size++] = v17->m_offset;
      if ( this->m_data.m_size == (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 4);
      ++j;
      this->m_data.m_data[this->m_data.m_size] = v17->m_slope;
    }
  }
  if ( storeIntData )
  {
    v18 = intervalPartition->m_intervals.m_size;
    if ( v18 > 0 )
    {
      do
      {
        v21 = hkaiIntervalPartition::getInterval(intervalPartition, v12)->m_data;
        if ( this->m_data.m_size == (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 4);
        ++v12;
        LODWORD(this->m_data.m_data[this->m_data.m_size++]) = v21;
      }
      while ( v12 < v18 );
    }
  }
  return m_size;
}

// File Line: 63
// RVA: 0xC3DA90
__int64 __fastcall hkaiIntervalPartitionLibrary::isDefinedAt(hkaiIntervalPartitionLibrary *this, int idx, float x)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *m_data; // r8
  unsigned int v4; // r10d
  float *v5; // rcx
  __int64 m_numIntervals; // rdx
  __int64 v7; // rax

  m_data = this->m_partitionRecords.m_data;
  v4 = 0;
  v5 = &this->m_data.m_data[m_data[idx].m_intervalDataOffset];
  m_numIntervals = m_data[idx].m_numIntervals;
  v7 = 0i64;
  if ( !m_numIntervals )
    return 0i64;
  while ( x > v5[2 * v7 + 1] )
  {
    if ( ++v7 >= m_numIntervals )
      return 0i64;
  }
  LOBYTE(v4) = x >= v5[2 * v7];
  return v4;
}

// File Line: 82
// RVA: 0xC3DAE0
__int64 __fastcall hkaiIntervalPartitionLibrary::tryEvaluateYAt(
        hkaiIntervalPartitionLibrary *this,
        int idx,
        float x,
        float *y)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *m_data; // r8
  float *v5; // r11
  __int64 m_numIntervals; // rax
  int v7; // edx
  __int64 v8; // rcx
  __int64 result; // rax
  float v10; // xmm2_4

  m_data = this->m_partitionRecords.m_data;
  v5 = &this->m_data.m_data[m_data[idx].m_intervalDataOffset];
  m_numIntervals = m_data[idx].m_numIntervals;
  v7 = 0;
  v8 = 0i64;
  if ( (int)m_numIntervals <= 0 )
    return 0i64;
  while ( x > v5[2 * v8 + 1] )
  {
    ++v8;
    ++v7;
    if ( v8 >= m_numIntervals )
      return 0i64;
  }
  if ( x < v5[2 * v8] )
    return 0i64;
  v10 = (float)(x * v5[2 * (unsigned int)m_numIntervals + 1 + 2 * (__int64)v7])
      + v5[2 * (unsigned int)m_numIntervals + 2 * (__int64)v7];
  result = 1i64;
  *y = v10;
  return result;
}

// File Line: 115
// RVA: 0xC3DB50
__int64 __fastcall hkaiIntervalPartitionLibrary::tryGetIntDataAt(
        hkaiIntervalPartitionLibrary *this,
        int idx,
        float x,
        unsigned int *intData)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *m_data; // rbx
  __int64 v5; // r11
  __int64 m_numIntervals; // rdi
  int v7; // r10d
  float *v8; // r8
  int v9; // edx
  __int64 v10; // rax

  m_data = this->m_partitionRecords.m_data;
  v5 = idx;
  m_numIntervals = m_data[idx].m_numIntervals;
  v7 = 0;
  v8 = &this->m_data.m_data[m_data[idx].m_intervalDataOffset];
  v9 = 0;
  v10 = 0i64;
  if ( !m_data[v5].m_numIntervals )
    return 0i64;
  while ( x > v8[2 * v10 + 1] )
  {
    ++v10;
    ++v9;
    if ( v10 >= m_numIntervals )
      return 0i64;
  }
  if ( x < v8[2 * v10] )
    return 0i64;
  if ( m_data[v5].m_hasYData.m_bool )
    v7 = 2 * m_numIntervals;
  *intData = LODWORD(v8[2 * m_numIntervals + v9 + v7]);
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
void __fastcall hkaiIntervalPartitionLibrary::getInterval(
        hkaiIntervalPartitionLibrary *this,
        int idx,
        unsigned __int16 intervalIdx,
        hkaiIntervalPartition::Interval *intervalOut)
{
  hkaiIntervalPartitionLibrary::PartitionRecord *m_data; // r11
  __int64 m_numIntervals; // rdi
  __int64 v6; // rsi
  float *v7; // rbx
  int v8; // r8d
  __int64 v9; // rcx

  m_data = this->m_partitionRecords.m_data;
  m_numIntervals = m_data[idx].m_numIntervals;
  v6 = intervalIdx;
  v7 = &this->m_data.m_data[m_data[idx].m_intervalDataOffset];
  v8 = 0;
  intervalOut->m_leftX = v7[2 * v6];
  intervalOut->m_rightX = v7[2 * v6 + 1];
  if ( m_data[idx].m_hasYData.m_bool )
  {
    v9 = v6 + (int)m_numIntervals;
    intervalOut->m_offset = v7[2 * v9];
    intervalOut->m_slope = v7[2 * v9 + 1];
  }
  else
  {
    *(_QWORD *)&intervalOut->m_slope = 0i64;
  }
  if ( m_data[idx].m_hasIntData.m_bool )
  {
    if ( m_data[idx].m_hasYData.m_bool )
      v8 = 2 * m_numIntervals;
    *(float *)&intervalOut->m_data = v7[2 * m_numIntervals + v6 + v8];
  }
  else
  {
    intervalOut->m_data = -1;
  }
}

// File Line: 182
// RVA: 0xC3DBE0
__int64 __fastcall hkaiIntervalPartitionLibrary::getClosestDefined(
        hkaiIntervalPartitionLibrary *this,
        int idx,
        float *xInOut)
{
  float v3; // xmm4_4
  __int64 v5; // rcx
  hkaiIntervalPartitionLibrary::PartitionRecord *m_data; // rdx
  unsigned __int16 m_numIntervals; // r9
  float *v10; // r8
  int v11; // ecx
  __int64 v12; // rdx
  float v13; // xmm2_4
  float v14; // xmm3_4

  v3 = *xInOut;
  v5 = idx;
  m_data = this->m_partitionRecords.m_data;
  m_numIntervals = m_data[v5].m_numIntervals;
  if ( !m_numIntervals )
    return 0i64;
  v10 = &this->m_data.m_data[m_data[v5].m_intervalDataOffset];
  if ( v3 < *v10 )
  {
    *xInOut = *v10;
    return 1i64;
  }
  v11 = 0;
  v12 = 0i64;
  if ( 2 * m_numIntervals - 1 <= 0 )
  {
LABEL_9:
    *xInOut = v10[2 * m_numIntervals - 1];
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
    if ( v12 >= 2 * m_numIntervals - 1 )
      goto LABEL_9;
  }
  if ( !(v11 % 2) )
    return 1i64;
  if ( (float)(v3 - v13) >= (float)(v14 - v3) )
    v13 = v10[v12 + 1];
  *xInOut = v13;
  return 1i64;
}

