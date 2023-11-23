// File Line: 18
// RVA: 0x12E8DD0
bool __fastcall hkaiDegenerateFaceCutter::Interval::overlaps(
        hkaiDegenerateFaceCutter::Interval *this,
        hkaiDegenerateFaceCutter::Interval *other)
{
  return other->m_max >= this->m_min && this->m_max >= other->m_min;
}

// File Line: 23
// RVA: 0x12E8E40
float __fastcall hkaiDegenerateFaceCutter::Interval::distanceTo(
        hkaiDegenerateFaceCutter::Interval *this,
        hkaiDegenerateFaceCutter::Interval *other)
{
  if ( hkaiDegenerateFaceCutter::Interval::overlaps(this, other) )
    return 0.0;
  else
    return fminf(
             COERCE_FLOAT((unsigned int)(2 * COERCE_INT(this->m_max - other->m_min)) >> 1),
             COERCE_FLOAT((unsigned int)(2 * COERCE_INT(this->m_min - other->m_max)) >> 1));
}

// File Line: 36
// RVA: 0x12E8DF0
void __fastcall hkaiDegenerateFaceCutter::Interval::setUnion(
        hkaiDegenerateFaceCutter::Interval *this,
        hkaiDegenerateFaceCutter::Interval *other)
{
  float m_max; // [rsp+8h] [rbp+8h]

  m_max = this->m_max;
  this->m_min = fminf(this->m_min, other->m_min);
  this->m_max = fmaxf(m_max, other->m_max);
}

// File Line: 46
// RVA: 0x12E8ED0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::IntervalList(
        hkaiDegenerateFaceCutter::IntervalList *this,
        int maxSize)
{
  hkLifoAllocator *Value; // rcx
  hkaiDegenerateFaceCutter::Interval *m_cur; // rax
  int v6; // r8d
  char *v7; // rdx

  this->m_intervals.m_capacityAndFlags = 0x80000000;
  this->m_intervals.m_initialCapacity = maxSize;
  this->m_intervals.m_data = 0i64;
  this->m_intervals.m_size = 0;
  if ( maxSize )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkaiDegenerateFaceCutter::Interval *)Value->m_cur;
    v6 = (8 * maxSize + 127) & 0xFFFFFF80;
    v7 = (char *)m_cur + v6;
    if ( v6 > Value->m_slabSize || v7 > Value->m_end )
      m_cur = (hkaiDegenerateFaceCutter::Interval *)hkLifoAllocator::allocateFromNewSlab(Value, v6);
    else
      Value->m_cur = v7;
  }
  else
  {
    m_cur = 0i64;
  }
  this->m_intervals.m_data = m_cur;
  this->m_intervals.m_localMemory = m_cur;
  this->m_intervals.m_capacityAndFlags = maxSize | 0x80000000;
  this->m_intervals.m_size = 0;
}

// File Line: 51
// RVA: 0x12E90C0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::sort(hkaiDegenerateFaceCutter::IntervalList *this)
{
  int m_size; // r8d

  m_size = this->m_intervals.m_size;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
      (DuplicateVertexRef *)this->m_intervals.m_data,
      0,
      m_size - 1,
      0);
}

// File Line: 62
// RVA: 0x12E8FA0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::mergeIntervals(hkaiDegenerateFaceCutter::IntervalList *this)
{
  char v2; // r13
  int v3; // r12d
  int v4; // ebx
  __int64 v5; // r14
  __int64 v6; // rcx
  __int64 v7; // r15
  hkaiDegenerateFaceCutter::Interval *v8; // rsi
  hkaiDegenerateFaceCutter::Interval *v9; // rbp
  __int64 v10; // rax
  __int64 v11; // rdx
  hkaiDegenerateFaceCutter::Interval *v12; // r8
  hkaiDegenerateFaceCutter::Interval *v13; // rax
  signed __int64 v14; // r8
  float v15; // ecx

  do
  {
    v2 = 0;
    v3 = 0;
    v4 = this->m_intervals.m_size - 1;
    if ( v4 <= 0 )
      break;
    do
    {
      if ( v4 > v3 )
      {
        v5 = v4;
        v6 = v3;
        v7 = v5 * 8;
        do
        {
          v8 = (hkaiDegenerateFaceCutter::Interval *)((char *)this->m_intervals.m_data + v7);
          v9 = &this->m_intervals.m_data[v6];
          if ( hkaiDegenerateFaceCutter::Interval::overlaps(v9, v8) )
          {
            hkaiDegenerateFaceCutter::Interval::setUnion(v9, v8);
            v10 = --this->m_intervals.m_size;
            if ( (_DWORD)v10 != v4 )
            {
              v11 = 2i64;
              v12 = &this->m_intervals.m_data[v10];
              v13 = &this->m_intervals.m_data[v5];
              v14 = (char *)v12 - (char *)v13;
              do
              {
                v15 = *(float *)((char *)&v13->m_min + v14);
                v13 = (hkaiDegenerateFaceCutter::Interval *)((char *)v13 + 4);
                v13[-1].m_max = v15;
                --v11;
              }
              while ( v11 );
            }
            v2 = 1;
          }
          v6 = v3;
          --v4;
          v7 -= 8i64;
          --v5;
        }
        while ( v4 > v3 );
      }
      ++v3;
      v4 = this->m_intervals.m_size - 1;
    }
    while ( v3 < v4 );
  }
  while ( v2 );
}

// File Line: 83
// RVA: 0x12E90F0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::addInterval(
        hkaiDegenerateFaceCutter::IntervalList *this,
        float minVal,
        float maxVal)
{
  int m_size; // r14d
  int v4; // ebx
  int v6; // edi
  hkaiDegenerateFaceCutter::Interval *v7; // r15
  int v8; // ebp
  int v9; // ecx
  int v10; // r14d
  float v11; // xmm6_4
  hkaiDegenerateFaceCutter::Interval *m_data; // rdi
  float v13; // xmm0_4
  hkaiDegenerateFaceCutter::Interval other; // [rsp+60h] [rbp+8h] BYREF

  m_size = this->m_intervals.m_size;
  v4 = 0;
  v6 = 0;
  other.m_min = minVal;
  other.m_max = maxVal;
  if ( m_size <= 0 )
  {
LABEL_5:
    v8 = -1;
    if ( m_size < (this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      ++this->m_intervals.m_size;
      v8 = m_size;
      if ( m_size >= 0 )
        goto LABEL_17;
    }
    hkaiDegenerateFaceCutter::IntervalList::mergeIntervals(this);
    v9 = this->m_intervals.m_size;
    if ( v9 < (this->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      ++this->m_intervals.m_size;
      v8 = v9;
    }
    if ( v8 >= 0 )
    {
LABEL_17:
      this->m_intervals.m_data[v8].m_min = minVal;
      this->m_intervals.m_data[v8].m_max = maxVal;
    }
    else
    {
      v10 = this->m_intervals.m_size;
      v11 = FLOAT_3_40282e38;
      if ( v10 > 0 )
      {
        m_data = this->m_intervals.m_data;
        do
        {
          v13 = hkaiDegenerateFaceCutter::Interval::distanceTo(&other, m_data);
          if ( v13 < v11 )
          {
            v11 = v13;
            v8 = v4;
          }
          ++v4;
          ++m_data;
        }
        while ( v4 < v10 );
      }
      hkaiDegenerateFaceCutter::Interval::setUnion(&this->m_intervals.m_data[v8], &other);
    }
  }
  else
  {
    v7 = this->m_intervals.m_data;
    while ( !hkaiDegenerateFaceCutter::Interval::overlaps(&v7[v6], &other) )
    {
      if ( ++v6 >= m_size )
        goto LABEL_5;
    }
    hkaiDegenerateFaceCutter::Interval::setUnion(&v7[v6], &other);
  }
}

// File Line: 148
// RVA: 0x12E8910
void __fastcall hkaiDegenerateFaceCutter::hkaiDegenerateFaceCutter(hkaiDegenerateFaceCutter *this)
{
  hkaiDegenerateFaceCutter::IntervalList::IntervalList(&this->m_intervals, 16);
}

// File Line: 153
// RVA: 0x12E8940
void __fastcall hkaiDegenerateFaceCutter::reset(hkaiDegenerateFaceCutter *this)
{
  this->m_intervals.m_intervals.m_size = 0;
}

// File Line: 158
// RVA: 0x12E8950
void __fastcall hkaiDegenerateFaceCutter::setSegment(
        hkaiDegenerateFaceCutter *this,
        hkVector4f *segA,
        hkVector4f *segB,
        int successfulEdge,
        int duplicateEdge,
        hkVector4f *up)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm6
  __m128 m_quad; // xmm1

  v6 = _mm_mul_ps(segB->m_quad, up->m_quad);
  v7 = _mm_mul_ps(up->m_quad, segA->m_quad);
  v8 = _mm_sub_ps(
         segA->m_quad,
         _mm_mul_ps(
           _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170)),
           up->m_quad));
  this->m_projectedVertices[1].m_quad = _mm_sub_ps(
                                          segB->m_quad,
                                          _mm_mul_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)),
                                              _mm_shuffle_ps(v6, v6, 170)),
                                            up->m_quad));
  this->m_projectedVertices[0].m_quad = v8;
  this->m_originalVertices[0] = (hkVector4f)segA->m_quad;
  m_quad = segB->m_quad;
  this->m_edgeIndices[0] = successfulEdge;
  this->m_edgeIndices[1] = duplicateEdge;
  this->m_originalVertices[1].m_quad = m_quad;
}

// File Line: 174
// RVA: 0x12E9470
char __fastcall intersectSegmentSilhouette(
        hkVector4f *segA,
        hkVector4f *segB,
        hkVector4f *vertices,
        int loopSize,
        hkVector4f *up,
        float *tMin,
        float *tMax)
{
  __m128 m_quad; // xmm8
  __m128 v8; // xmm13
  __int64 v9; // rcx
  __m128 v10; // xmm12
  __m128 v11; // xmm7
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm6
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  bool v26; // cc
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm4
  __m128 v30; // xmm1

  m_quad = query.m_quad;
  v8 = segA->m_quad;
  v9 = 0i64;
  v10 = _mm_sub_ps(segB->m_quad, v8);
  v11 = 0i64;
  if ( loopSize - 1 <= 0 )
  {
LABEL_8:
    *tMin = v11.m128_f32[0];
    *tMax = m_quad.m128_f32[0];
    return 1;
  }
  else
  {
    v12 = up->m_quad;
    v13 = _mm_shuffle_ps(v12, v12, 201);
    while ( 1 )
    {
      v14 = _mm_sub_ps(vertices[1].m_quad, vertices->m_quad);
      v15 = _mm_sub_ps(_mm_mul_ps(v13, v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12));
      v16 = _mm_shuffle_ps(v15, v15, 201);
      v17 = _mm_mul_ps(v16, v16);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      v20 = _mm_mul_ps(
              v16,
              _mm_andnot_ps(
                _mm_cmple_ps(v18, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                  _mm_mul_ps(*(__m128 *)_xmm, v19))));
      v21 = _mm_mul_ps(v20, vertices->m_quad);
      v22 = _mm_mul_ps(v20, v10);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      v24 = _mm_mul_ps(v8, v20);
      v25 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                _mm_shuffle_ps(v21, v21, 170)));
      if ( COERCE_FLOAT((unsigned int)(2 * v23.m128_i32[0]) >> 1) >= 0.00000011920929 )
      {
        v27 = _mm_rcp_ps(v23);
        v28 = _mm_mul_ps(v27, v23);
        v29 = _mm_cmplt_ps(v23, (__m128)0i64);
        v30 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v28), v27), _mm_sub_ps((__m128)0i64, v25));
        v11 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v30, v11), v29), _mm_andnot_ps(v29, v11));
        m_quad = _mm_or_ps(_mm_andnot_ps(v29, _mm_min_ps(v30, m_quad)), _mm_and_ps(v29, m_quad));
        v26 = v11.m128_f32[0] <= m_quad.m128_f32[0];
      }
      else
      {
        v26 = v25.m128_f32[0] <= 0.0;
      }
      if ( !v26 )
        return 0;
      ++v9;
      ++vertices;
      if ( v9 >= loopSize - 1 )
        goto LABEL_8;
    }
  }
}

// File Line: 243
// RVA: 0x12E89E0
__int64 __fastcall hkaiDegenerateFaceCutter::addSilhouette(
        hkaiDegenerateFaceCutter *this,
        hkVector4f *points,
        int loopSize,
        hkaiDegenerateFaceCutter::IntervalType it,
        int materialIndex,
        hkVector4f *up)
{
  __int64 v6; // r10
  float minVal[6]; // [rsp+40h] [rbp-18h] BYREF
  float maxVal; // [rsp+78h] [rbp+20h] BYREF

  minVal[0] = 0.0;
  LODWORD(maxVal) = (_DWORD)FLOAT_1_0;
  if ( it == INTERVAL_CUTTING
    && intersectSegmentSilhouette(
         this->m_projectedVertices,
         &this->m_projectedVertices[1],
         points,
         loopSize,
         up,
         minVal,
         &maxVal) )
  {
    hkaiDegenerateFaceCutter::IntervalList::addInterval(
      (hkaiDegenerateFaceCutter::IntervalList *)(v6 + 72),
      minVal[0],
      maxVal);
  }
  return 1i64;
}

// File Line: 263
// RVA: 0x12E8A60
__int64 __fastcall hkaiDegenerateFaceCutter::computeConvexDecomposition(
        hkaiDegenerateFaceCutter *this,
        hkaiFaceCutResults *resultsInMainMem,
        unsigned int faceKey,
        int numFaceVerts)
{
  int m_size; // eax
  int v7; // ebx
  int v8; // r15d
  hkLifoAllocator *Value; // rax
  char *m_cur; // r8
  int v11; // edx
  char *v12; // rcx
  __int64 v13; // r9
  int v14; // r12d
  int v15; // r14d
  int v16; // r10d
  int v17; // ecx
  float m_min; // eax
  __int64 v19; // rax
  hkaiDegenerateFaceCutter::Interval *m_data; // rcx
  unsigned int v21; // ecx
  int v22; // ebx
  _QWORD **v23; // rax
  char *v24; // rax
  unsigned int *v25; // rdx
  unsigned int v26; // esi
  int m_numPolys; // ecx
  __int64 v28; // rbx
  int v29; // eax
  signed int v30; // ebx
  hkLifoAllocator *v31; // rax
  int v32; // r8d
  char *array; // [rsp+30h] [rbp-28h]
  int i; // [rsp+38h] [rbp-20h]
  int v36; // [rsp+38h] [rbp-20h]
  char *p; // [rsp+40h] [rbp-18h]
  int v38; // [rsp+48h] [rbp-10h]
  hkVector4f *result; // [rsp+A0h] [rbp+48h] BYREF
  unsigned int *dataPtr; // [rsp+A8h] [rbp+50h] BYREF
  unsigned int v41; // [rsp+B0h] [rbp+58h]
  int v42; // [rsp+B8h] [rbp+60h]

  v42 = numFaceVerts;
  v41 = faceKey;
  hkaiDegenerateFaceCutter::IntervalList::mergeIntervals(&this->m_intervals);
  hkaiDegenerateFaceCutter::IntervalList::sort(&this->m_intervals);
  m_size = this->m_intervals.m_intervals.m_size;
  v7 = 2 * m_size + 2;
  v8 = 0;
  v38 = v7;
  if ( 2 * m_size == -2 )
  {
    m_cur = 0i64;
    array = 0i64;
  }
  else
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v11 = (4 * v7 + 127) & 0xFFFFFF80;
    v12 = &m_cur[v11];
    if ( v11 > Value->m_slabSize || v12 > Value->m_end )
    {
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
      array = m_cur;
    }
    else
    {
      Value->m_cur = v12;
      array = m_cur;
    }
  }
  p = m_cur;
  v13 = 0i64;
  v14 = 0;
  v15 = 2;
  if ( v42 == 2 )
  {
    *(_DWORD *)m_cur = 0;
    v16 = 0;
    v17 = 1;
    for ( i = 1; v16 < this->m_intervals.m_intervals.m_size; i = v36 + 1 )
    {
      m_min = this->m_intervals.m_intervals.m_data[v13].m_min;
      ++v16;
      ++v13;
      *(float *)&array[4 * v17] = m_min;
      v36 = i + 1;
      *(float *)&array[4 * v36] = this->m_intervals.m_intervals.m_data[v13 - 1].m_max;
      v17 = v36 + 1;
    }
    *(_DWORD *)&array[4 * v17] = 1065353216;
    v19 = this->m_intervals.m_intervals.m_size;
    v15 = i + 1;
    if ( (_DWORD)v19 )
    {
      m_data = this->m_intervals.m_intervals.m_data;
      if ( m_data->m_min < 0.000001 )
        v14 = 2;
      if ( m_data[v19 - 1].m_max >= 0.99999899 )
        v15 = i - 1;
    }
    m_cur = array;
    v8 = (v15 - v14) / 2;
  }
  v21 = v41;
  resultsInMainMem->m_numEdges = 4 * v8;
  resultsInMainMem->m_originalFace = v21;
  resultsInMainMem->m_numPolys = v8;
  resultsInMainMem->m_numVertices = 0;
  v22 = 16 * ((4 * v8 + 3) & 0xFFFFFFFC) + ((36 * v8 + 11 * v8 + 15) & 0xFFFFFFF0);
  if ( v22 > 0 )
  {
    v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (char *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v23[11] + 8i64))(v23[11], (unsigned int)v22);
    m_cur = array;
    resultsInMainMem->m_data = v24;
  }
  v25 = (unsigned int *)resultsInMainMem->m_data;
  resultsInMainMem->m_allocatedSize = v22;
  if ( !v8 )
    goto LABEL_23;
  if ( v25 )
  {
    m_numPolys = resultsInMainMem->m_numPolys;
    v28 = v14;
    v29 = 9 * resultsInMainMem->m_numEdges;
    dataPtr = v25;
    result = (hkVector4f *)&resultsInMainMem->m_data[(11 * m_numPolys + v29 + 15i64) & 0xFFFFFFFFFFFFFFF0ui64];
    if ( v14 < (__int64)v15 )
    {
      do
      {
        hkaiDegenerateFaceCutter::writeFace(
          this,
          resultsInMainMem,
          &dataPtr,
          &result,
          *(float *)&m_cur[4 * v28],
          *(float *)&m_cur[4 * v28 + 4]);
        m_cur = array;
        v28 += 2i64;
      }
      while ( v28 < v15 );
    }
LABEL_23:
    v26 = 1;
    goto LABEL_24;
  }
  v26 = 0;
LABEL_24:
  v30 = (4 * v38 + 127) & 0xFFFFFF80;
  v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (v30 + 15) & 0xFFFFFFF0;
  if ( v30 > v31->m_slabSize || &p[v32] != v31->m_cur || v31->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v31, p, v32);
  else
    v31->m_cur = p;
  return v26;
}

// File Line: 347
// RVA: 0x12E9240
void __fastcall hkaiDegenerateFaceCutter::writeFace(
        hkaiDegenerateFaceCutter *this,
        hkaiFaceCutResults *results,
        unsigned int **dataPtr,
        hkVector4f **verticesOut,
        float t0f,
        float t1f)
{
  __m128 m_quad; // xmm1
  __m128 v8; // xmm0
  hkVector4f v9; // xmm3
  hkVector4f v10; // xmm2
  int v11; // eax
  unsigned int *v12; // rdx
  unsigned int *v13; // rdx
  int v14; // [rsp+30h] [rbp-50h] BYREF
  unsigned int *v15; // [rsp+38h] [rbp-48h]
  int v16; // [rsp+40h] [rbp-40h]
  int v17; // [rsp+44h] [rbp-3Ch]
  int v18[4]; // [rsp+48h] [rbp-38h] BYREF
  unsigned int *v19; // [rsp+58h] [rbp-28h]
  int v20; // [rsp+60h] [rbp-20h]
  int v21; // [rsp+64h] [rbp-1Ch]
  int v22[6]; // [rsp+68h] [rbp-18h] BYREF

  m_quad = this->m_originalVertices[0].m_quad;
  v8 = _mm_sub_ps(this->m_originalVertices[1].m_quad, m_quad);
  v9.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t0f), (__m128)LODWORD(t0f), 0), v8), m_quad);
  v10.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t1f), (__m128)LODWORD(t1f), 0), v8), m_quad);
  *(*verticesOut)++ = (hkVector4f)v9.m_quad;
  *(*verticesOut)++ = (hkVector4f)v10.m_quad;
  *(*verticesOut)++ = (hkVector4f)v10.m_quad;
  *(*verticesOut)++ = (hkVector4f)v9.m_quad;
  v22[0] = results->m_numVertices;
  v20 = 4;
  v21 = -2147483644;
  v16 = 4;
  v17 = -2147483644;
  v18[1] = -1;
  v18[3] = -1;
  v14 = 84149508;
  v19 = (unsigned int *)v22;
  v15 = (unsigned int *)v18;
  v22[1] = v22[0] + 1;
  v22[2] = v22[0] + 2;
  v11 = v22[0] + 3;
  results->m_numVertices = LOWORD(v22[0]) + 4;
  v22[3] = v11;
  v18[0] = this->m_edgeIndices[0];
  v18[2] = this->m_edgeIndices[1];
  *(*dataPtr)++ = 4;
  *(*dataPtr)++ = -1;
  v12 = v19;
  *(*dataPtr)++ = *v19;
  *(*dataPtr)++ = v12[1];
  *(*dataPtr)++ = v12[2];
  *(*dataPtr)++ = v12[3];
  v13 = v15;
  *(*dataPtr)++ = *v15;
  *(*dataPtr)++ = v13[1];
  *(*dataPtr)++ = v13[2];
  *(*dataPtr)++ = v13[3];
  hkaiFaceCutResults::writeFlags(
    results,
    dataPtr,
    (hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *)&v14,
    4);
  v16 = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v15, 4 * v17);
  v15 = 0i64;
  v17 = 0x80000000;
  v20 = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v19, 4 * v21);
}

