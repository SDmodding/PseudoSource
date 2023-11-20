// File Line: 18
// RVA: 0x12E8DD0
bool __fastcall hkaiDegenerateFaceCutter::Interval::overlaps(hkaiDegenerateFaceCutter::Interval *this, hkaiDegenerateFaceCutter::Interval *other)
{
  return other->m_max >= this->m_min && this->m_max >= other->m_min;
}

// File Line: 23
// RVA: 0x12E8E40
float __fastcall hkaiDegenerateFaceCutter::Interval::distanceTo(hkaiDegenerateFaceCutter::Interval *this, hkaiDegenerateFaceCutter::Interval *other)
{
  hkaiDegenerateFaceCutter::Interval *v2; // rbx
  hkaiDegenerateFaceCutter::Interval *v3; // rdi
  float result; // xmm0_4

  v2 = other;
  v3 = this;
  if ( hkaiDegenerateFaceCutter::Interval::overlaps(this, other) )
    result = 0.0;
  else
    result = fminf(
               COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v3->m_max - v2->m_min)) >> 1),
               COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v3->m_min - v2->m_max)) >> 1));
  return result;
}

// File Line: 36
// RVA: 0x12E8DF0
void __fastcall hkaiDegenerateFaceCutter::Interval::setUnion(hkaiDegenerateFaceCutter::Interval *this, hkaiDegenerateFaceCutter::Interval *other)
{
  float v2; // [rsp+8h] [rbp+8h]

  v2 = this->m_max;
  this->m_min = fminf(this->m_min, other->m_min);
  this->m_max = fmaxf(v2, other->m_max);
}

// File Line: 46
// RVA: 0x12E8ED0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::IntervalList(hkaiDegenerateFaceCutter::IntervalList *this, int maxSize)
{
  int v2; // edi
  hkaiDegenerateFaceCutter::IntervalList *v3; // rbx
  hkLifoAllocator *v4; // rax
  hkLifoAllocator *v5; // rcx
  hkaiDegenerateFaceCutter::Interval *v6; // rax
  int v7; // er8
  char *v8; // rdx
  unsigned int v9; // edi
  int v10; // edi
  int v11; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = maxSize;
  v3 = this;
  this->m_intervals.m_capacityAndFlags = 2147483648;
  this->m_intervals.m_initialCapacity = maxSize;
  this->m_intervals.m_data = 0i64;
  this->m_intervals.m_size = 0;
  if ( maxSize )
  {
    v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = v4;
    v6 = (hkaiDegenerateFaceCutter::Interval *)v4->m_cur;
    v7 = (8 * v2 + 127) & 0xFFFFFF80;
    v8 = (char *)v6 + v7;
    if ( v7 > v5->m_slabSize || v8 > v5->m_end )
      v6 = (hkaiDegenerateFaceCutter::Interval *)hkLifoAllocator::allocateFromNewSlab(v5, v7);
    else
      v5->m_cur = v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = v2 | 0x80000000;
  v3->m_intervals.m_data = v6;
  v3->m_intervals.m_localMemory = v6;
  v3->m_intervals.m_capacityAndFlags = v9;
  v10 = v9 & 0x3FFFFFFF;
  if ( v10 < 0 )
  {
    v11 = 0;
    if ( 2 * v10 > 0 )
      v11 = 2 * v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v11, 8);
  }
  v3->m_intervals.m_size = 0;
}

// File Line: 51
// RVA: 0x12E90C0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::sort(hkaiDegenerateFaceCutter::IntervalList *this)
{
  int v1; // er8

  v1 = this->m_intervals.m_size;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiDegenerateFaceCutter::Interval,hkAlgorithm::less<hkaiDegenerateFaceCutter::Interval>>(
      (DuplicateVertexRef *)this->m_intervals.m_data,
      0,
      v1 - 1,
      0);
}

// File Line: 62
// RVA: 0x12E8FA0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::mergeIntervals(hkaiDegenerateFaceCutter::IntervalList *this)
{
  hkaiDegenerateFaceCutter::IntervalList *v1; // rdi
  char v2; // r13
  int v3; // er12
  int v4; // ebx
  signed __int64 v5; // r14
  signed __int64 v6; // rcx
  signed __int64 v7; // r15
  hkaiDegenerateFaceCutter::Interval *v8; // rsi
  hkaiDegenerateFaceCutter::Interval *v9; // rbp
  __int64 v10; // rax
  signed __int64 v11; // rdx
  signed __int64 v12; // r8
  hkaiDegenerateFaceCutter::Interval *v13; // rax
  signed __int64 v14; // r8
  float v15; // ecx

  v1 = this;
  do
  {
    v2 = 0;
    v3 = 0;
    v4 = v1->m_intervals.m_size - 1;
    if ( v4 <= 0 )
      break;
    do
    {
      if ( v4 > v3 )
      {
        v5 = v4;
        v6 = v3;
        v7 = v4;
        do
        {
          v8 = &v1->m_intervals.m_data[v7];
          v9 = &v1->m_intervals.m_data[v6];
          if ( hkaiDegenerateFaceCutter::Interval::overlaps(&v1->m_intervals.m_data[v6], &v1->m_intervals.m_data[v7]) )
          {
            hkaiDegenerateFaceCutter::Interval::setUnion(v9, v8);
            v10 = --v1->m_intervals.m_size;
            if ( (_DWORD)v10 != v4 )
            {
              v11 = 2i64;
              v12 = (signed __int64)&v1->m_intervals.m_data[v10];
              v13 = &v1->m_intervals.m_data[v5];
              v14 = v12 - (_QWORD)v13;
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
          --v7;
          --v5;
        }
        while ( v4 > v3 );
      }
      ++v3;
      v4 = v1->m_intervals.m_size - 1;
    }
    while ( v3 < v4 );
  }
  while ( v2 );
}

// File Line: 83
// RVA: 0x12E90F0
void __fastcall hkaiDegenerateFaceCutter::IntervalList::addInterval(hkaiDegenerateFaceCutter::IntervalList *this, float minVal, float maxVal)
{
  int v3; // er14
  signed int v4; // ebx
  hkaiDegenerateFaceCutter::IntervalList *v5; // rsi
  int v6; // edi
  hkaiDegenerateFaceCutter::Interval *v7; // r15
  signed int v8; // ebp
  int v9; // ecx
  int v10; // er14
  float v11; // xmm6_4
  hkaiDegenerateFaceCutter::Interval *v12; // rdi
  float v13; // xmm0_4
  __int64 v14; // rcx
  hkaiDegenerateFaceCutter::Interval other; // [rsp+60h] [rbp+8h]

  v3 = this->m_intervals.m_size;
  v4 = 0;
  v5 = this;
  v6 = 0;
  other.m_min = minVal;
  other.m_max = maxVal;
  if ( v3 <= 0 )
  {
LABEL_5:
    v8 = -1;
    if ( v3 < (v5->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      ++v5->m_intervals.m_size;
      v8 = v3;
      if ( v3 >= 0 )
        goto LABEL_20;
    }
    hkaiDegenerateFaceCutter::IntervalList::mergeIntervals(v5);
    v9 = v5->m_intervals.m_size;
    if ( v9 < (v5->m_intervals.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      ++v5->m_intervals.m_size;
      v8 = v9;
    }
    if ( v8 >= 0 )
    {
LABEL_20:
      v14 = v8;
      v5->m_intervals.m_data[v14].m_min = minVal;
      v5->m_intervals.m_data[v14].m_max = maxVal;
    }
    else
    {
      v10 = v5->m_intervals.m_size;
      v11 = FLOAT_3_40282e38;
      if ( v10 > 0 )
      {
        v12 = v5->m_intervals.m_data;
        do
        {
          v13 = hkaiDegenerateFaceCutter::Interval::distanceTo(&other, v12);
          if ( v13 < v11 )
          {
            v11 = v13;
            v8 = v4;
          }
          ++v4;
          ++v12;
        }
        while ( v4 < v10 );
      }
      hkaiDegenerateFaceCutter::Interval::setUnion(&v5->m_intervals.m_data[v8], &other);
    }
  }
  else
  {
    v7 = this->m_intervals.m_data;
    while ( !hkaiDegenerateFaceCutter::Interval::overlaps(&v7[v6], &other) )
    {
      if ( ++v6 >= v3 )
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
void __fastcall hkaiDegenerateFaceCutter::setSegment(hkaiDegenerateFaceCutter *this, hkVector4f *segA, hkVector4f *segB, int successfulEdge, int duplicateEdge, hkVector4f *up)
{
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm6
  __m128 v9; // xmm1

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
  v9 = segB->m_quad;
  this->m_edgeIndices[0] = successfulEdge;
  this->m_edgeIndices[1] = duplicateEdge;
  this->m_originalVertices[1].m_quad = v9;
}

// File Line: 174
// RVA: 0x12E9470
char __fastcall intersectSegmentSilhouette(hkVector4f *segA, hkVector4f *segB, hkVector4f *vertices, int loopSize, hkVector4f *up, float *tMin, float *tMax)
{
  __m128 v7; // xmm8
  __m128 v8; // xmm13
  signed __int64 v9; // rcx
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
  bool v26; // cf
  bool v27; // zf
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  char result; // al

  v7 = query.m_quad;
  v8 = segA->m_quad;
  v9 = 0i64;
  v10 = _mm_sub_ps(segB->m_quad, v8);
  v11 = 0i64;
  if ( loopSize - 1 <= 0 )
  {
LABEL_8:
    *tMin = v11.m128_f32[0];
    *tMax = v7.m128_f32[0];
    result = 1;
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
                _mm_cmpleps(v18, (__m128)0i64),
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
        v28 = _mm_rcp_ps(v23);
        v29 = _mm_mul_ps(v28, v23);
        v30 = _mm_cmpltps(v23, (__m128)0i64);
        v31 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v29), v28), _mm_sub_ps((__m128)0i64, v25));
        v11 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v31, v11), v30), _mm_andnot_ps(v30, v11));
        v7 = _mm_or_ps(_mm_andnot_ps(v30, _mm_min_ps(v31, v7)), _mm_and_ps(v30, v7));
        v26 = v11.m128_f32[0] < v7.m128_f32[0];
        v27 = v11.m128_f32[0] == v7.m128_f32[0];
      }
      else
      {
        v26 = v25.m128_f32[0] < 0.0;
        v27 = v25.m128_f32[0] == 0.0;
      }
      if ( !v26 && !v27 )
        break;
      ++v9;
      ++vertices;
      if ( v9 >= loopSize - 1 )
        goto LABEL_8;
    }
    result = 0;
  }
  return result;
}

// File Line: 243
// RVA: 0x12E89E0
signed __int64 __fastcall hkaiDegenerateFaceCutter::addSilhouette(hkaiDegenerateFaceCutter *this, hkVector4f *points, int loopSize, hkaiDegenerateFaceCutter::IntervalType it, int materialIndex, hkVector4f *up)
{
  __int64 v6; // r10
  float minVal; // [rsp+40h] [rbp-18h]
  float maxVal; // [rsp+78h] [rbp+20h]

  minVal = 0.0;
  maxVal = *(float *)&FLOAT_1_0;
  if ( it == 2
    && intersectSegmentSilhouette(
         this->m_projectedVertices,
         &this->m_projectedVertices[1],
         points,
         loopSize,
         up,
         &minVal,
         &maxVal) )
  {
    hkaiDegenerateFaceCutter::IntervalList::addInterval(
      (hkaiDegenerateFaceCutter::IntervalList *)(v6 + 72),
      minVal,
      maxVal);
  }
  return 1i64;
}

// File Line: 263
// RVA: 0x12E8A60
__int64 __fastcall hkaiDegenerateFaceCutter::computeConvexDecomposition(hkaiDegenerateFaceCutter *this, hkaiFaceCutResults *resultsInMainMem, unsigned int faceKey, int numFaceVerts)
{
  hkaiDegenerateFaceCutter *v4; // r13
  hkaiFaceCutResults *v5; // rsi
  int v6; // eax
  int v7; // ebx
  int v8; // er15
  hkLifoAllocator *v9; // rax
  _DWORD *v10; // r8
  int v11; // edx
  char *v12; // rcx
  unsigned int v13; // ebx
  int v14; // ebx
  int v15; // er9
  __int64 v16; // r9
  signed int v17; // er12
  signed int v18; // er14
  int v19; // er10
  int i; // ecx
  int v21; // eax
  hkaiDegenerateFaceCutter::Interval *v22; // r8
  __int64 v23; // rax
  float *v24; // rcx
  unsigned int v25; // ecx
  signed int v26; // ebx
  unsigned int *v27; // rdx
  _QWORD **v28; // rax
  __int64 v29; // rax
  unsigned int v30; // esi
  int v31; // ecx
  signed __int64 v32; // rbx
  int v33; // eax
  char *v34; // rdi
  signed int v35; // ebx
  hkLifoAllocator *v36; // rax
  int v37; // er8
  _DWORD *array; // [rsp+30h] [rbp-28h]
  int v40; // [rsp+38h] [rbp-20h]
  int v41; // [rsp+3Ch] [rbp-1Ch]
  void *p; // [rsp+40h] [rbp-18h]
  int v43; // [rsp+48h] [rbp-10h]
  hkResult result; // [rsp+A0h] [rbp+48h]
  unsigned int *dataPtr; // [rsp+A8h] [rbp+50h]
  unsigned int v46; // [rsp+B0h] [rbp+58h]
  int v47; // [rsp+B8h] [rbp+60h]

  v47 = numFaceVerts;
  v46 = faceKey;
  v4 = this;
  v5 = resultsInMainMem;
  hkaiDegenerateFaceCutter::IntervalList::mergeIntervals(&this->m_intervals);
  hkaiDegenerateFaceCutter::IntervalList::sort(&v4->m_intervals);
  v6 = v4->m_intervals.m_intervals.m_size;
  v7 = 2 * v6 + 2;
  v8 = 0;
  array = 0i64;
  v40 = 0;
  v41 = 2147483648;
  v43 = 2 * v6 + 2;
  if ( 2 * v6 == -2 )
  {
    v10 = 0i64;
    array = 0i64;
  }
  else
  {
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = v9->m_cur;
    v11 = (4 * v7 + 127) & 0xFFFFFF80;
    v12 = (char *)v10 + v11;
    if ( v11 > v9->m_slabSize || v12 > v9->m_end )
    {
      v10 = hkLifoAllocator::allocateFromNewSlab(v9, v11);
      array = v10;
    }
    else
    {
      v9->m_cur = v12;
      array = v10;
    }
  }
  v13 = v7 | 0x80000000;
  p = v10;
  v41 = v13;
  v14 = v13 & 0x3FFFFFFF;
  if ( v14 < 0 )
  {
    v15 = 0;
    if ( 2 * v14 > 0 )
      v15 = 2 * v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 4);
    v10 = array;
  }
  v16 = 0i64;
  v40 = 0;
  v17 = 0;
  v18 = 2;
  if ( v47 == 2 )
  {
    *v10 = 0;
    v19 = 0;
    for ( i = v40++ + 1; v19 < v4->m_intervals.m_intervals.m_size; ++v40 )
    {
      v21 = *(_DWORD *)((char *)&v4->m_intervals.m_intervals.m_data->m_min + v16);
      ++v19;
      v16 += 8i64;
      array[i] = v21;
      v22 = v4->m_intervals.m_intervals.m_data;
      array[++v40] = *(_DWORD *)((char *)v22 + v16 - 4);
      i = v40 + 1;
    }
    array[i] = 1065353216;
    v23 = v4->m_intervals.m_intervals.m_size;
    LODWORD(v16) = v40 + 1;
    v40 = v16;
    v18 = v16;
    if ( (_DWORD)v23 )
    {
      v24 = (float *)v4->m_intervals.m_intervals.m_data;
      if ( *v24 < 0.000001 )
        v17 = 2;
      if ( v24[2 * v23 - 1] >= 0.99999899 )
        v18 = v16 - 2;
    }
    v10 = array;
    v8 = (v18 - v17) / 2;
  }
  v25 = v46;
  v5->m_numEdges = 4 * v8;
  v5->m_originalFace = v25;
  v5->m_numPolys = v8;
  v5->m_numVertices = 0;
  v26 = 16 * ((4 * v8 + 3) & 0xFFFFFFFC) + ((36 * v8 + 11 * v8 + 15) & 0xFFFFFFF0);
  if ( v26 <= 0x7FFFFFFF )
  {
    if ( v26 > 0 )
    {
      v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v29 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v28[11] + 8i64))(v28[11], (unsigned int)v26);
      LODWORD(v16) = v40;
      v10 = array;
      v5->m_data = (char *)v29;
    }
    v27 = (unsigned int *)v5->m_data;
    v5->m_allocatedSize = v26;
  }
  else
  {
    v27 = 0i64;
  }
  if ( v8 )
  {
    if ( !v27 )
    {
      v30 = 0;
      goto LABEL_32;
    }
    v31 = v5->m_numPolys;
    v32 = v17;
    v33 = 9 * v5->m_numEdges;
    dataPtr = v27;
    *(_QWORD *)&result.m_enum = &v5->m_data[(11 * v31 + v33 + 15i64) & 0xFFFFFFFFFFFFFFF0ui64];
    if ( v17 < (signed __int64)v18 )
    {
      do
      {
        hkaiDegenerateFaceCutter::writeFace(
          v4,
          v5,
          &dataPtr,
          (hkVector4f **)&result,
          *(float *)&v10[v32],
          *(float *)&v10[v32 + 1]);
        v10 = array;
        v32 += 2i64;
      }
      while ( v32 < v18 );
      LODWORD(v16) = v40;
    }
  }
  v30 = 1;
LABEL_32:
  v34 = (char *)p;
  if ( p == v10 )
    LODWORD(v16) = 0;
  v35 = (4 * v43 + 127) & 0xFFFFFF80;
  v40 = v16;
  v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v37 = (v35 + 15) & 0xFFFFFFF0;
  if ( v35 > v36->m_slabSize || &v34[v37] != v36->m_cur || v36->m_firstNonLifoEnd == v34 )
    hkLifoAllocator::slowBlockFree(v36, v34, v37);
  else
    v36->m_cur = v34;
  v40 = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v41);
  return v30;
}

// File Line: 347
// RVA: 0x12E9240
void __fastcall hkaiDegenerateFaceCutter::writeFace(hkaiDegenerateFaceCutter *this, hkaiFaceCutResults *results, unsigned int **dataPtr, hkVector4f **verticesOut, float t0f, float t1f)
{
  __m128 v6; // xmm1
  hkaiFaceCutResults *v7; // rbx
  __m128 v8; // xmm0
  hkVector4f v9; // xmm3
  hkVector4f v10; // xmm2
  int v11; // edx
  unsigned int *v12; // rdx
  unsigned int *v13; // rdx
  __int64 v14; // [rsp+2Ch] [rbp-54h]
  unsigned int *v15; // [rsp+38h] [rbp-48h]
  int v16; // [rsp+40h] [rbp-40h]
  int v17; // [rsp+44h] [rbp-3Ch]
  int v18; // [rsp+48h] [rbp-38h]
  int v19; // [rsp+4Ch] [rbp-34h]
  int v20; // [rsp+50h] [rbp-30h]
  int v21; // [rsp+54h] [rbp-2Ch]
  unsigned int *v22; // [rsp+58h] [rbp-28h]
  int v23; // [rsp+60h] [rbp-20h]
  int v24; // [rsp+64h] [rbp-1Ch]
  int v25; // [rsp+68h] [rbp-18h]
  int v26; // [rsp+6Ch] [rbp-14h]
  int v27; // [rsp+70h] [rbp-10h]
  int v28; // [rsp+74h] [rbp-Ch]

  v6 = this->m_originalVertices[0].m_quad;
  v7 = results;
  v8 = _mm_sub_ps(this->m_originalVertices[1].m_quad, v6);
  v9.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t0f), (__m128)LODWORD(t0f), 0), v8), v6);
  v10.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t1f), (__m128)LODWORD(t1f), 0), v8), v6);
  **verticesOut = (hkVector4f)v9.m_quad;
  ++*verticesOut;
  **verticesOut = (hkVector4f)v10.m_quad;
  ++*verticesOut;
  **verticesOut = (hkVector4f)v10.m_quad;
  ++*verticesOut;
  **verticesOut = (hkVector4f)v9.m_quad;
  ++*verticesOut;
  v11 = results->m_numVertices;
  v25 = v11;
  v23 = 4;
  v24 = -2147483644;
  v16 = 4;
  v17 = -2147483644;
  v14 = 361419386981974020i64;
  v19 = -1;
  v21 = -1;
  v22 = (unsigned int *)&v25;
  v15 = (unsigned int *)&v18;
  v26 = v11 + 1;
  v27 = v11 + 2;
  v7->m_numVertices = v11 + 4;
  v28 = v11 + 3;
  v18 = this->m_edgeIndices[0];
  v20 = this->m_edgeIndices[1];
  **dataPtr = 4;
  ++*dataPtr;
  **dataPtr = -1;
  ++*dataPtr;
  v12 = v22;
  **dataPtr = *v22;
  ++*dataPtr;
  **dataPtr = v12[1];
  ++*dataPtr;
  **dataPtr = v12[2];
  ++*dataPtr;
  **dataPtr = v12[3];
  ++*dataPtr;
  v13 = v15;
  **dataPtr = *v15;
  ++*dataPtr;
  **dataPtr = v13[1];
  ++*dataPtr;
  **dataPtr = v13[2];
  ++*dataPtr;
  **dataPtr = v13[3];
  ++*dataPtr;
  hkaiFaceCutResults::writeFlags(
    v7,
    dataPtr,
    (hkFlags<enum hkaiFaceCutResults::ConnectivityTypes,unsigned char> *)&v14 + 4,
    4);
  if ( (signed int)v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (char *)&v14 + 4,
      v14 & 0x3FFFFFFF);
  v16 = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v15,
      4 * v17);
  v15 = 0i64;
  v17 = 2147483648;
  v23 = 0;
  if ( v24 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22,
      4 * v24);
}

