// File Line: 29
// RVA: 0x1321760
hkBool *__fastcall operator<(hkBool *result, hkEntry *lhs, hkEntry *rhs)
{
  result->m_bool = lhs->m_value < rhs->m_value;
  return result;
}

// File Line: 34
// RVA: 0x1321780
hkBool *__fastcall operator!=(hkBool *result, hkEntry *lhs, hkEntry *rhs)
{
  result->m_bool = COERCE_FLOAT((unsigned int)(2 * COERCE_INT(lhs->m_value - rhs->m_value)) >> 1) > 0.001;
  return result;
}

// File Line: 72
// RVA: 0x1321FC0
float __fastcall hkHistogram::evaluate(hkHistogram *this)
{
  int m_size; // r8d
  int v4; // eax
  int v5; // edi
  float *v6; // r9
  int v7; // ebx
  int v8; // r15d
  int v9; // esi
  __int64 v10; // r12
  __int64 v11; // r13
  __int64 v12; // r10
  bool v13; // cc
  hkBool *v14; // rax
  __int64 v15; // r9
  float v16; // xmm2_4
  __int64 v17; // r8
  hkEntry *m_data; // rax
  float *v19; // rdx
  float *v20; // rcx
  unsigned __int64 v21; // rax
  float v22; // xmm0_4
  float v23; // xmm1_4
  __int64 v24; // r8
  hkEntry *v25; // rdx
  float m_hi; // xmm0_4
  hkEntry *v27; // rax
  int v28; // xmm7_4
  float v29; // xmm6_4
  float *v30; // rax
  __int64 v31; // rcx
  int v32; // eax
  float v33; // xmm6_4
  char v34; // dl
  float *v35; // rax
  __int64 v36; // rcx
  float v37; // xmm0_4
  __int64 v38; // [rsp+20h] [rbp-39h]
  float *array; // [rsp+28h] [rbp-31h] BYREF
  int v40; // [rsp+30h] [rbp-29h]
  int v41; // [rsp+34h] [rbp-25h]
  float result; // [rsp+C0h] [rbp+67h] BYREF
  __int64 v43; // [rsp+C8h] [rbp+6Fh]
  int v44; // [rsp+D0h] [rbp+77h]
  int v45; // [rsp+D8h] [rbp+7Fh]

  m_size = this->m_entries.m_size;
  if ( !m_size )
    return this->m_freeAngle;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkEntry,hkAlgorithm::less<hkEntry>>(this->m_entries.m_data, 0, m_size - 1, 0);
  v4 = this->m_entries.m_size;
  v5 = 1;
  v6 = 0i64;
  v7 = 0;
  v8 = 0x80000000;
  v9 = 0;
  v10 = 0i64;
  array = 0i64;
  v11 = 1i64;
  v40 = 0;
  v41 = 0x80000000;
  if ( v4 >= 1 )
  {
    v12 = 0i64;
    v38 = 12i64;
    v43 = 0i64;
    v13 = v4 > 1;
    do
    {
      if ( v13
        && (v14 = operator!=((hkBool *)&result, &this->m_entries.m_data[v9], &this->m_entries.m_data[v5]),
            v12 = v43,
            !v14->m_bool) )
      {
        v31 = v38;
      }
      else
      {
        v15 = 0i64;
        v16 = 0.0;
        v17 = v5 - v9;
        if ( v17 >= 4 )
        {
          m_data = this->m_entries.m_data;
          v19 = (float *)((char *)&m_data[2].m_lo + v12);
          v20 = (float *)((char *)&m_data->m_hi + v12);
          v21 = ((unsigned __int64)(v17 - 4) >> 2) + 1;
          v15 = 4 * v21;
          do
          {
            v22 = *v20;
            v23 = v20[3];
            v20 += 12;
            v19 += 12;
            v16 = (float)((float)((float)(v16 + (float)(v22 - *(v19 - 18))) + (float)(v23 - *(v20 - 10)))
                        + (float)(*(v20 - 6) - *(v19 - 12)))
                + (float)(*(v20 - 3) - *(v19 - 9));
            --v21;
          }
          while ( v21 );
        }
        if ( v15 < v17 )
        {
          v24 = v17 - v15;
          v25 = &this->m_entries.m_data[v15 + v10];
          do
          {
            m_hi = v25->m_hi;
            ++v25;
            v16 = v16 + (float)(m_hi - v25[-1].m_lo);
            --v24;
          }
          while ( v24 );
        }
        v27 = this->m_entries.m_data;
        *(float *)&v43 = v16;
        v44 = 0;
        v45 = 1065353216;
        v28 = *(_DWORD *)((char *)&v27->m_value + v12);
        v29 = fminf(fmaxf(v16, 0.0), 1.0);
        if ( v7 == (v8 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 12);
          v8 = v41;
          v7 = v40;
        }
        v30 = &array[3 * v7];
        if ( v30 )
        {
          *v30 = 0.0;
          v30[1] = v29;
          *((_DWORD *)v30 + 2) = v28;
          v8 = v41;
          v7 = v40;
        }
        v31 = v38;
        ++v7;
        v9 = v5;
        v12 = v38;
        v43 = v38;
        v40 = v7;
        v10 = v11;
      }
      v32 = this->m_entries.m_size;
      ++v5;
      ++v11;
      v38 = v31 + 12;
      v13 = v5 < v32;
    }
    while ( v5 <= v32 );
    v6 = array;
  }
  v33 = FLOAT_3_1415927;
  v34 = 0;
  if ( v7 <= 0 )
    goto LABEL_29;
  v35 = v6 + 2;
  v36 = (unsigned int)v7;
  do
  {
    if ( (float)(*(v35 - 1) - *(v35 - 2)) >= 0.60000002 )
    {
      v37 = *v35;
      *(float *)&v43 = v33;
      v34 = 1;
      result = v37;
      v33 = fminf(v33, v37);
    }
    v35 += 3;
    --v36;
  }
  while ( v36 );
  if ( !v34 )
LABEL_29:
    v33 = 0.0;
  v40 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v6, 12 * (v8 & 0x3FFFFFFF));
  return v33;
}

// File Line: 159
// RVA: 0x13217E0
void __fastcall hkBuildClipPlanesForTriangle(hkVector4f *out, hkpTriangleShape *triangle, float extraRadius)
{
  hkVector4f *p_m_vertexC; // rsi
  hkVector4f *p_m_vertexA; // rbx
  hkVector4f *p_m_vertexB; // rdi
  __m128 m_quad; // xmm10
  __m128 v8; // xmm5
  __m128 v9; // xmm12
  __m128 v10; // xmm2
  __m128 v11; // xmm8
  __m128 v12; // xmm13
  __m128 v13; // xmm11
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm2
  __m128 v23; // xmm11
  __m128 v24; // xmm11
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm11
  __m128 v29; // xmm2
  __m128 v30; // xmm13
  __m128 v31; // xmm13
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm13
  __m128 v36; // xmm2
  hkVector4f normal; // [rsp+20h] [rbp-88h] BYREF

  p_m_vertexC = &triangle->m_vertexC;
  p_m_vertexA = &triangle->m_vertexA;
  p_m_vertexB = &triangle->m_vertexB;
  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(
    &triangle->m_vertexA,
    &triangle->m_vertexB,
    &triangle->m_vertexC,
    &normal);
  m_quad = normal.m_quad;
  v8 = _mm_sub_ps(p_m_vertexB->m_quad, p_m_vertexA->m_quad);
  v9 = _mm_shuffle_ps(
         (__m128)(unsigned int)(LODWORD(extraRadius) ^ _xmm[0]),
         (__m128)(unsigned int)(LODWORD(extraRadius) ^ _xmm[0]),
         0);
  v10 = _mm_mul_ps(p_m_vertexA->m_quad, normal.m_quad);
  v11 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 201);
  v12 = _mm_sub_ps(p_m_vertexA->m_quad, p_m_vertexC->m_quad);
  v13 = _mm_sub_ps(p_m_vertexC->m_quad, p_m_vertexB->m_quad);
  out->m_quad = _mm_shuffle_ps(
                  normal.m_quad,
                  _mm_unpackhi_ps(
                    normal.m_quad,
                    _mm_sub_ps(
                      v9,
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                        _mm_shuffle_ps(v10, v10, 170)))),
                  196);
  v14 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), m_quad);
  v15 = _mm_mul_ps(p_m_vertexA->m_quad, v14);
  out[1].m_quad = _mm_shuffle_ps(
                    v14,
                    _mm_unpackhi_ps(
                      v14,
                      _mm_sub_ps(
                        v9,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                          _mm_shuffle_ps(v15, v15, 170)))),
                    196);
  v16 = _mm_sub_ps(_mm_mul_ps(v8, v11), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), m_quad));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_mul_ps(
          v17,
          _mm_andnot_ps(
            _mm_cmple_ps(v19, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
              _mm_mul_ps(v20, *(__m128 *)_xmm))));
  v22 = _mm_mul_ps(p_m_vertexA->m_quad, v21);
  out[2].m_quad = _mm_shuffle_ps(
                    v21,
                    _mm_unpackhi_ps(
                      v21,
                      _mm_sub_ps(
                        v9,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                          _mm_shuffle_ps(v22, v22, 170)))),
                    196);
  v23 = _mm_sub_ps(_mm_mul_ps(v13, v11), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), m_quad));
  v24 = _mm_shuffle_ps(v23, v23, 201);
  v25 = _mm_mul_ps(v24, v24);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_rsqrt_ps(v26);
  v28 = _mm_mul_ps(
          v24,
          _mm_andnot_ps(
            _mm_cmple_ps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(v27, *(__m128 *)_xmm))));
  v29 = _mm_mul_ps(v28, p_m_vertexB->m_quad);
  out[3].m_quad = _mm_shuffle_ps(
                    v28,
                    _mm_unpackhi_ps(
                      v28,
                      _mm_sub_ps(
                        v9,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                          _mm_shuffle_ps(v29, v29, 170)))),
                    196);
  v30 = _mm_sub_ps(_mm_mul_ps(v12, v11), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), m_quad));
  v31 = _mm_shuffle_ps(v30, v30, 201);
  v32 = _mm_mul_ps(v31, v31);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(
          v31,
          _mm_andnot_ps(
            _mm_cmple_ps(v33, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(v34, *(__m128 *)_xmm))));
  v36 = _mm_mul_ps(v35, p_m_vertexC->m_quad);
  out[4].m_quad = _mm_shuffle_ps(
                    v35,
                    _mm_unpackhi_ps(
                      v35,
                      _mm_sub_ps(
                        v9,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                          _mm_shuffle_ps(v36, v36, 170)))),
                    196);
}

// File Line: 193
// RVA: 0x1321B20
char __fastcall hkClipEdgeAgainstPlanes(
        hkVector4f *v0,
        hkVector4f *v1,
        int planeCount,
        hkVector4f *planeEquations,
        float *lo,
        float *hi)
{
  __m128 m_quad; // xmm7
  __int64 v7; // rax
  __m128 v8; // xmm8
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 v18; // xmm7
  __m128 v19; // xmm8
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  float v22; // xmm5_4

  m_quad = v0->m_quad;
  v7 = 0i64;
  v8 = v1->m_quad;
  if ( planeCount <= 0 )
  {
LABEL_9:
    v17 = _mm_sub_ps(v1->m_quad, v0->m_quad);
    v18 = _mm_mul_ps(_mm_sub_ps(m_quad, v0->m_quad), v17);
    v19 = _mm_mul_ps(_mm_sub_ps(v8, v0->m_quad), v17);
    v20 = _mm_mul_ps(v17, v17);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    v20.m128_f32[0] = _mm_rcp_ps(v21).m128_f32[0];
    v22 = (float)(2.0 - (float)(v20.m128_f32[0] * v21.m128_f32[0])) * v20.m128_f32[0];
    *lo = (float)((float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
                + _mm_shuffle_ps(v18, v18, 170).m128_f32[0])
        * v22;
    *hi = (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                + _mm_shuffle_ps(v19, v19, 170).m128_f32[0])
        * v22;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v9 = _mm_mul_ps(planeEquations->m_quad, m_quad);
      v10 = _mm_shuffle_ps(planeEquations->m_quad, planeEquations->m_quad, 255);
      v11 = _mm_mul_ps(planeEquations->m_quad, v8);
      v12 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)),
              v10);
      v13 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170)),
              v10);
      if ( v12.m128_f32[0] >= 0.0 && v13.m128_f32[0] >= 0.0 )
        return 0;
      if ( (float)(v13.m128_f32[0] * v12.m128_f32[0]) < 0.0 )
      {
        v14 = _mm_sub_ps(v12, v13);
        v15 = _mm_rcp_ps(v14);
        v16 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(v8, m_quad),
                  _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15), v12)),
                m_quad);
        if ( v12.m128_f32[0] <= 0.0 )
          v8 = v16;
        else
          m_quad = v16;
      }
      ++v7;
      ++planeEquations;
      if ( v7 >= planeCount )
        goto LABEL_9;
    }
  }
}

// File Line: 251
// RVA: 0x131EFC0
void __fastcall hkpMeshWeldingUtility::computeWeldingInfo(
        hkpShapeCollection *collection,
        hkpBvTreeShape *bvTree,
        hkpWeldingUtility::WeldingType weldingType,
        bool weldOpenEdges)
{
  hkLifoAllocator *Value; // rax
  hkpMeshWeldingUtility::ShapeInfo *m_cur; // rdx
  hkVector4f *p_m_translation; // rcx
  int m_size; // r8d
  hkpMeshWeldingUtility::ShapeInfo *v11; // rcx
  __int128 v12; // xmm0
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // r8d
  hkArray<hkpMeshWeldingUtility::ShapeInfo,hkContainerHeapAllocator> array; // [rsp+28h] [rbp-61h] BYREF
  void *p; // [rsp+38h] [rbp-51h]
  int v20; // [rsp+40h] [rbp-49h]
  __int128 v21; // [rsp+88h] [rbp-1h]
  bool v22; // [rsp+108h] [rbp+7Fh]

  *(_QWORD *)&v21 = bvTree;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v20 = 1;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkpMeshWeldingUtility::ShapeInfo *)Value->m_cur;
  p_m_translation = &m_cur[1].m_transform.m_translation;
  if ( Value->m_slabSize < 128 || p_m_translation > Value->m_end )
    m_cur = (hkpMeshWeldingUtility::ShapeInfo *)hkLifoAllocator::allocateFromNewSlab(Value, 128);
  else
    Value->m_cur = p_m_translation;
  m_size = array.m_size;
  array.m_data = m_cur;
  array.m_capacityAndFlags = -2147483647;
  p = m_cur;
  if ( array.m_size == 1 )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 80);
    m_size = array.m_size;
    m_cur = array.m_data;
  }
  v11 = &m_cur[m_size];
  if ( v11 )
  {
    v12 = v21;
    v11->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    v11->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v11->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v11->m_transform.m_translation = 0i64;
    *(_OWORD *)&v11->m_shape = v12;
    m_size = array.m_size;
  }
  array.m_size = m_size + 1;
  hkpMeshWeldingUtility::computeWeldingInfoMultiShape(
    (hkTransformf *)&transform,
    collection,
    weldingType,
    &array,
    weldOpenEdges,
    v22);
  v13 = array.m_size;
  v14 = (char *)p;
  if ( p == array.m_data )
    v13 = 0;
  array.m_size = v13;
  v15 = (80 * v20 + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      80 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 265
// RVA: 0x131F1C0
void __fastcall hkpMeshWeldingUtility::computeWeldingInfoMultiShape(
        hkTransformf *meshTransform,
        hkpShapeCollection *mesh,
        unsigned int weldingType,
        hkArray<hkpMeshWeldingUtility::ShapeInfo,hkContainerHeapAllocator> *allShapes,
        bool weldOpenEdges,
        bool disableEdges)
{
  char m_storage; // al
  hkArray<hkpMeshWeldingUtility::ShapeInfo,hkContainerHeapAllocator> *v7; // r14
  hkpShapeContainer *v10; // rsi
  unsigned int v11; // edi
  hkVector4f *v12; // rax
  __m128 *p_m_quad; // rsi
  __m128 *v14; // r12
  __int64 v15; // rbx
  unsigned __int16 v16; // di
  int v17; // r15d
  __m128 *v18; // rax
  __m128 v19; // xmm1
  char v20; // bl
  int v21; // esi
  __int64 v22; // rbx
  signed __int64 v23; // r8
  hkVector4f *p_m_translation; // r9
  __m128 v25; // xmm12
  __m128 v26; // xmm8
  __m128 v27; // xmm9
  __m128 v28; // xmm10
  hkpMeshWeldingUtility::ShapeInfo *m_data; // rdx
  __int64 v30; // rcx
  hkVector4f *v31; // rax
  __int64 *v32; // rdi
  __m128 v33; // xmm7
  __m128 v34; // xmm6
  __m128 m_quad; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm5
  __m128 v38; // xmm0
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm5
  __m128 v42; // xmm1
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm6
  __m128 v47; // xmm11
  __m128 v48; // xmm7
  __m128 v49; // xmm10
  __m128 v50; // xmm13
  __m128 v51; // xmm1
  __int64 v52; // rax
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm9
  __m128 v56; // xmm1
  __int64 v57; // rcx
  unsigned int v58; // r15d
  __int64 v59; // rax
  hkVector4f *v60; // rax
  hkpTriangleShape *v61; // rsi
  hkVector4f *v62; // rbx
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm3
  __m128 v66; // xmm4
  __m128 v67; // xmm1
  __m128 v68; // xmm8
  __m128 v69; // xmm5
  __m128 v70; // xmm5
  __m128 v71; // xmm1
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  int v74; // edi
  char v75; // r12
  __int64 v76; // r14
  float v77; // xmm12_4
  __m128 v78; // xmm6
  __m128 v79; // xmm5
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm2
  __m128 v83; // xmm5
  __m128 v84; // xmm2
  __m128 v85; // xmm2
  __m128 v86; // xmm2
  __m128 v87; // xmm7
  float v88; // xmm3_4
  __m128 v89; // xmm6
  __m128 v90; // xmm2
  __m128 v91; // xmm2
  __m128 v92; // xmm2
  __m128 v93; // xmm2
  __m128 v94; // xmm2
  __m128 v95; // xmm2
  __m128 v96; // xmm1
  __m128 v97; // xmm3
  __m128 v98; // xmm2
  float v99; // xmm4_4
  __m128 v100; // xmm1
  float v101; // xmm5_4
  float v102; // xmm6_4
  hkOstream *v103; // rax
  hkOstream *v104; // rax
  hkOstream *v105; // rax
  hkOstream *v106; // rax
  int m_size; // r8d
  float v108; // xmm0_4
  float v109; // xmm5_4
  int v110; // ecx
  float v111; // xmm0_4
  __int64 v112; // rdx
  hkEntry *v113; // rax
  int v114; // r10d
  int v115; // edx
  __int64 v116; // rcx
  hkEntry *v117; // rax
  int v118; // r8d
  float v119; // xmm0_4
  __int64 v120; // r8
  unsigned __int16 v121; // [rsp+30h] [rbp-D0h]
  __int64 *v122; // [rsp+38h] [rbp-C8h]
  unsigned int u; // [rsp+40h] [rbp-C0h]
  int v124; // [rsp+44h] [rbp-BCh]
  hkHistogram v125; // [rsp+48h] [rbp-B8h] BYREF
  int v126; // [rsp+60h] [rbp-A0h]
  int v127; // [rsp+64h] [rbp-9Ch]
  float lo; // [rsp+68h] [rbp-98h] BYREF
  __m128 *v129; // [rsp+70h] [rbp-90h]
  int v130; // [rsp+78h] [rbp-88h]
  int v131; // [rsp+80h] [rbp-80h]
  hkVector4f *v132; // [rsp+88h] [rbp-78h]
  float hi[6]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v134; // [rsp+A8h] [rbp-58h]
  __int64 v135; // [rsp+B0h] [rbp-50h]
  __m128 *v136; // [rsp+B8h] [rbp-48h]
  hkEntry t; // [rsp+C0h] [rbp-40h] BYREF
  hkEntry v138; // [rsp+D0h] [rbp-30h] BYREF
  __m128 v139; // [rsp+E0h] [rbp-20h]
  hkVector4f *v140; // [rsp+F0h] [rbp-10h]
  _BOOL8 v141; // [rsp+F8h] [rbp-8h]
  __int64 v142; // [rsp+100h] [rbp+0h]
  hkVector4f b; // [rsp+110h] [rbp+10h] BYREF
  hkVector4f triangleNormal; // [rsp+120h] [rbp+20h] BYREF
  hkVector4f a; // [rsp+130h] [rbp+30h] BYREF
  hkVector4f c; // [rsp+140h] [rbp+40h] BYREF
  __m256 v147; // [rsp+150h] [rbp+50h] BYREF
  __m128 v148; // [rsp+170h] [rbp+70h]
  hkVector4f edgeNormal; // [rsp+1A0h] [rbp+A0h] BYREF
  __m128 v150; // [rsp+1B0h] [rbp+B0h]
  hkSimdFloat32 v151; // [rsp+1C0h] [rbp+C0h] BYREF
  __m128 v152; // [rsp+1D0h] [rbp+D0h]
  hkVector4f edgeOrtho; // [rsp+1E0h] [rbp+E0h] BYREF
  __m128 v154; // [rsp+1F0h] [rbp+F0h]
  __m128 v155; // [rsp+200h] [rbp+100h]
  hkVector4f normal; // [rsp+210h] [rbp+110h] BYREF
  hkVector4f v0; // [rsp+220h] [rbp+120h] BYREF
  __m128i v158; // [rsp+230h] [rbp+130h] BYREF
  __m128 v159; // [rsp+240h] [rbp+140h]
  __m128 v160; // [rsp+250h] [rbp+150h]
  hkSimdFloat32 tolerance; // [rsp+260h] [rbp+160h] BYREF
  hkVector4f v1; // [rsp+270h] [rbp+170h] BYREF
  char *v163; // [rsp+280h] [rbp+180h] BYREF
  int v164; // [rsp+288h] [rbp+188h]
  int v165; // [rsp+28Ch] [rbp+18Ch]
  char v166; // [rsp+290h] [rbp+190h] BYREF
  char buf[512]; // [rsp+490h] [rbp+390h] BYREF
  char v168[512]; // [rsp+690h] [rbp+590h] BYREF
  char v169[512]; // [rsp+890h] [rbp+790h] BYREF
  char v171; // [rsp+B78h] [rbp+A78h]

  m_storage = mesh->m_collectionType.m_storage;
  v7 = allShapes;
  if ( m_storage == 3 || !m_storage || (unsigned __int8)m_storage >= 7u )
  {
    hkErrStream::hkErrStream((hkErrStream *)&v147, buf, 512);
    hkOstream::operator<<((hkOstream *)&v147, "hkpShapeCollection must be a triangle collection that supports welding.");
    hkError::messageWarning(0x3F508C6Au, buf, "Util\\Welding\\hkpMeshWeldingUtility.cpp", 274);
    hkOstream::~hkOstream((hkOstream *)&v147);
    return;
  }
  ((void (__fastcall *)(hkpShapeCollection *, _QWORD))mesh->hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[8].__first_virtual_table_function__)(
    mesh,
    weldingType);
  if ( weldingType != 6 )
  {
    v10 = &mesh->hkpShapeContainer;
    mesh->m_disableWelding.m_bool = 1;
    v11 = mesh->hkpShapeContainer::vfptr->getFirstKey(&mesh->hkpShapeContainer);
    u = v11;
    v141 = weldingType != 5;
    while ( v11 != -1 )
    {
      v12 = (hkVector4f *)v10->vfptr->getChildShape(v10, v11, (char (*)[512])v169);
      p_m_quad = &v12->m_quad;
      v129 = &v12->m_quad;
      if ( v12[1].m_quad.m128_i8[0] != 2 )
        goto LABEL_74;
      v14 = &v12[5].m_quad;
      v15 = (__int64)&v12[3];
      v16 = 0;
      v121 = 0;
      v132 = v12 + 5;
      hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(v12 + 3, v12 + 4, v12 + 5, &normal);
      hi[4] = 0.0000099999997;
      v17 = 0;
      v126 = 0;
      v18 = (__m128 *)v15;
      v19 = _mm_shuffle_ps((__m128)0x3727C5ACu, (__m128)0x3727C5ACu, 0);
      v154 = v19;
      v136 = (__m128 *)v15;
      do
      {
        v125.m_entries.m_data = 0i64;
        v125.m_entries.m_size = 0;
        v125.m_entries.m_capacityAndFlags = 0x80000000;
        v125.m_freeAngle = 0.0;
        if ( !weldOpenEdges )
          v125.m_freeAngle = 3.1415927;
        a.m_quad = *v18;
        tolerance.m_real = v19;
        b.m_quad = p_m_quad[(v17 + 1) % 3 + 3];
        c.m_quad = p_m_quad[(v17 + 2) % 3 + 3];
        if ( hkcdTriangleUtil::isDegenerate(&a, &b, &c, &tolerance) )
        {
          v125.m_entries.m_size = 0;
          if ( v125.m_entries.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v125.m_entries.m_data,
              12 * (v125.m_entries.m_capacityAndFlags & 0x3FFFFFFF));
        }
        else
        {
          v20 = 0;
          v171 = 0;
          v21 = 0;
          v124 = 0;
          if ( v7->m_size > 0 )
          {
            v22 = 0i64;
            v23 = (char *)&v147 - (char *)meshTransform;
            p_m_translation = &meshTransform->m_translation;
            v25 = *(__m128 *)_xmm;
            v135 = 0i64;
            v142 = (char *)&v147 - (char *)meshTransform;
            v140 = &meshTransform->m_translation;
            v26 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 85);
            v27 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 0);
            v160 = v26;
            v150 = v27;
            v28 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 170);
            v152 = v28;
            v158 = _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
            while ( 1 )
            {
              m_data = v7->m_data;
              v30 = 3i64;
              v31 = p_m_translation;
              v32 = *(__int64 **)((char *)&v7->m_data->m_shape + v22);
              v122 = v32;
              v33 = *(__m128 *)((char *)&v7->m_data->m_transform.m_rotation.m_col1.m_quad + v22);
              v34 = *(__m128 *)((char *)&v7->m_data->m_transform.m_rotation.m_col2.m_quad + v22);
              do
              {
                m_quad = v31->m_quad;
                --v31;
                --v30;
                v36 = *(__m128 *)((char *)&m_data->m_transform.m_rotation.m_col0.m_quad + v22);
                v37 = _mm_unpackhi_ps(v36, v33);
                v38 = _mm_unpacklo_ps(v36, v33);
                v39 = _mm_movelh_ps(v38, v34);
                *(__m128 *)((char *)&v31[1].m_quad + v23) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps(_mm_movehl_ps(v39, v38), v34, 212),
                                                                  _mm_shuffle_ps(m_quad, m_quad, 85)),
                                                                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v39)),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps(m_quad, m_quad, 170),
                                                                _mm_shuffle_ps(v37, v34, 228)));
              }
              while ( v30 >= 0 );
              v40 = *(__m128 *)((char *)&m_data->m_transform.m_rotation.m_col2.m_quad + v22);
              v41 = _mm_sub_ps(
                      p_m_translation->m_quad,
                      *(__m128 *)((char *)&m_data->m_transform.m_translation.m_quad + v22));
              v42 = *(__m128 *)((char *)&m_data->m_transform.m_rotation.m_col0.m_quad + v22);
              v43 = _mm_unpackhi_ps(v42, *(__m128 *)((char *)&m_data->m_transform.m_rotation.m_col1.m_quad + v22));
              v44 = _mm_unpacklo_ps(v42, *(__m128 *)((char *)&m_data->m_transform.m_rotation.m_col1.m_quad + v22));
              v45 = _mm_movelh_ps(v44, v40);
              v46 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v45, v44), v40, 212), _mm_shuffle_ps(v41, v41, 85)),
                        _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v45)),
                      _mm_mul_ps(_mm_shuffle_ps(v43, v40, 228), _mm_shuffle_ps(v41, v41, 170)));
              v159 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)v147.m256_f32, v27),
                         _mm_mul_ps(*(__m128 *)&v147.m256_f32[4], v26)),
                       _mm_mul_ps(v148, v28));
              edgeNormal.m_quad = v159;
              v47 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(a.m_quad, a.m_quad, 85), *(__m128 *)&v147.m256_f32[4]),
                          _mm_mul_ps(_mm_shuffle_ps(a.m_quad, a.m_quad, 0), *(__m128 *)v147.m256_f32)),
                        _mm_mul_ps(_mm_shuffle_ps(a.m_quad, a.m_quad, 170), v148)),
                      v46);
              v0.m_quad = v47;
              v48 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 85), *(__m128 *)&v147.m256_f32[4]),
                          _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 0), *(__m128 *)v147.m256_f32)),
                        _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 170), v148)),
                      v46);
              v139 = v48;
              v1.m_quad = v48;
              v49 = _mm_sub_ps(v48, v47);
              v50 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(c.m_quad, c.m_quad, 85), *(__m128 *)&v147.m256_f32[4]),
                          _mm_mul_ps(_mm_shuffle_ps(c.m_quad, c.m_quad, 0), *(__m128 *)v147.m256_f32)),
                        _mm_mul_ps(_mm_shuffle_ps(c.m_quad, c.m_quad, 170), v148)),
                      v46);
              v51 = _mm_mul_ps(v49, v49);
              v155 = v50;
              v164 = 0;
              v165 = -2147483520;
              v163 = &v166;
              v52 = *v32;
              v53 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                      _mm_shuffle_ps(v51, v51, 170));
              v54 = _mm_rsqrt_ps(v53);
              v55 = _mm_mul_ps(
                      v49,
                      _mm_andnot_ps(
                        _mm_cmple_ps(v53, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
                          _mm_mul_ps(v25, v54))));
              v56 = _mm_max_ps(
                      _mm_max_ps(_mm_xor_ps((__m128)_mm_load_si128(&v158), (__m128)xmmword_141A712A0), v47),
                      v48);
              *(__m128 *)v147.m256_f32 = _mm_min_ps(_mm_min_ps((__m128)xmmword_141A712A0, v47), v48);
              *(__m128 *)&v147.m256_f32[4] = v56;
              (*(void (__fastcall **)(__int64 *, __m256 *, char **))(v52 + 136))(v32, &v147, &v163);
              v127 = 0;
              if ( v164 > 0 )
                break;
LABEL_58:
              v164 = 0;
              if ( v165 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v163, 4 * v165);
              v27 = v150;
              v28 = v152;
              v23 = v142;
              p_m_translation = v140;
              ++v21;
              v22 += 80i64;
              v124 = v21;
              v135 = v22;
              if ( v21 >= v7->m_size )
              {
                v20 = v171;
                v16 = v121;
                v17 = v126;
                goto LABEL_62;
              }
            }
            v57 = 0i64;
            v134 = 0i64;
            while ( 2 )
            {
              v58 = *(_DWORD *)&v163[v57];
              v59 = (*(__int64 (__fastcall **)(__int64 *))(*v32 + 112))(v32);
              v60 = (hkVector4f *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v59 + 40i64))(
                                    v59,
                                    v58,
                                    v168);
              v61 = (hkpTriangleShape *)v60;
              if ( v60[1].m_quad.m128_i8[0] == 2 )
              {
                v62 = v60 + 3;
                v131 = 925353388;
                v151.m_real = _mm_shuffle_ps((__m128)0x3727C5ACu, (__m128)0x3727C5ACu, 0);
                if ( hkcdTriangleUtil::isDegenerate(v60 + 3, v60 + 4, v60 + 5, &v151) )
                  goto LABEL_55;
                v63 = v62->m_quad;
                hi[2] = 0.001;
                v64 = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
                if ( (_mm_movemask_ps(
                        _mm_cmplt_ps(
                          (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v129[3], v63), 1u), 1u),
                          v64)) & 7) == 7
                  && (_mm_movemask_ps(
                        _mm_cmplt_ps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32((__m128i)_mm_sub_ps(v129[4], v61->m_vertexB.m_quad), 1u),
                                    1u),
                          v64)) & 7) == 7
                  && (_mm_movemask_ps(
                        _mm_cmplt_ps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32((__m128i)_mm_sub_ps(*v14, v61->m_vertexC.m_quad), 1u),
                                    1u),
                          v64)) & 7) == 7 )
                {
                  goto LABEL_55;
                }
                v65 = v61->m_vertexC.m_quad;
                v66 = v61->m_vertexB.m_quad;
                if ( ((_mm_movemask_ps(
                         _mm_cmplt_ps(
                           (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v63, v48), 1u), 1u),
                           v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                  _mm_cmplt_ps(
                                                    (__m128)_mm_srli_epi32(
                                                              _mm_slli_epi32((__m128i)_mm_sub_ps(v66, v48), 1u),
                                                              1u),
                                                    v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                                           _mm_cmplt_ps(
                                                                             (__m128)_mm_srli_epi32(
                                                                                       _mm_slli_epi32(
                                                                                         (__m128i)_mm_sub_ps(v65, v48),
                                                                                         1u),
                                                                                       1u),
                                                                             v64)) & 7) == 7)
                  && ((_mm_movemask_ps(
                         _mm_cmplt_ps(
                           (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v63, v50), 1u), 1u),
                           v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                  _mm_cmplt_ps(
                                                    (__m128)_mm_srli_epi32(
                                                              _mm_slli_epi32((__m128i)_mm_sub_ps(v66, v50), 1u),
                                                              1u),
                                                    v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                                           _mm_cmplt_ps(
                                                                             (__m128)_mm_srli_epi32(
                                                                                       _mm_slli_epi32(
                                                                                         (__m128i)_mm_sub_ps(v65, v50),
                                                                                         1u),
                                                                                       1u),
                                                                             v64)) & 7) == 7)
                  || ((_mm_movemask_ps(
                         _mm_cmplt_ps(
                           (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v63, v50), 1u), 1u),
                           v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                  _mm_cmplt_ps(
                                                    (__m128)_mm_srli_epi32(
                                                              _mm_slli_epi32((__m128i)_mm_sub_ps(v66, v50), 1u),
                                                              1u),
                                                    v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                                           _mm_cmplt_ps(
                                                                             (__m128)_mm_srli_epi32(
                                                                                       _mm_slli_epi32(
                                                                                         (__m128i)_mm_sub_ps(v65, v50),
                                                                                         1u),
                                                                                       1u),
                                                                             v64)) & 7) == 7)
                  && ((_mm_movemask_ps(
                         _mm_cmplt_ps(
                           (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v63, v47), 1u), 1u),
                           v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                  _mm_cmplt_ps(
                                                    (__m128)_mm_srli_epi32(
                                                              _mm_slli_epi32((__m128i)_mm_sub_ps(v66, v47), 1u),
                                                              1u),
                                                    v64)) & 7) == 7) | ((_mm_movemask_ps(
                                                                           _mm_cmplt_ps(
                                                                             (__m128)_mm_srli_epi32(
                                                                                       _mm_slli_epi32(
                                                                                         (__m128i)_mm_sub_ps(v65, v47),
                                                                                         1u),
                                                                                       1u),
                                                                             v64)) & 7) == 7) )
                {
                  v32 = v122;
                }
                else
                {
                  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(
                    v62,
                    &v61->m_vertexB,
                    &v61->m_vertexC,
                    &triangleNormal);
                  v130 = 1028443341;
                  v67 = _mm_mul_ps(triangleNormal.m_quad, v55);
                  if ( COERCE_FLOAT((unsigned int)(2
                                                 * COERCE_INT(
                                                     (float)(_mm_shuffle_ps(v67, v67, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v67, v67, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v67, v67, 170).m128_f32[0])) >> 1) < _mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0).m128_f32[0] )
                  {
                    v68 = _mm_shuffle_ps(v55, v55, 201);
                    v69 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v159, v159, 201), v55), _mm_mul_ps(v159, v68));
                    v70 = _mm_shuffle_ps(v69, v69, 201);
                    v71 = _mm_mul_ps(v70, v70);
                    v72 = _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                            _mm_shuffle_ps(v71, v71, 170));
                    v73 = _mm_rsqrt_ps(v72);
                    edgeOrtho.m_quad = _mm_mul_ps(
                                         v70,
                                         _mm_andnot_ps(
                                           _mm_cmple_ps(v72, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v73, v72), v73)),
                                             _mm_mul_ps(v25, v73))));
                    v74 = 1;
                    v75 = 0;
                    v76 = 3i64;
                    v77 = hkpMeshWeldingUtility::calcAngleForEdge(&edgeNormal, &edgeOrtho, &triangleNormal);
                    do
                    {
                      v78 = *(&v61->m_vertexA.m_quad + v74 % 3);
                      v79 = _mm_sub_ps(v78, v62->m_quad);
                      v80 = _mm_mul_ps(v79, v79);
                      v81 = _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
                              _mm_shuffle_ps(v80, v80, 170));
                      v82 = _mm_rsqrt_ps(v81);
                      v83 = _mm_mul_ps(
                              v79,
                              _mm_andnot_ps(
                                _mm_cmple_ps(v81, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v82, v81), v82)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v82))));
                      v84 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v55), _mm_mul_ps(v83, v68));
                      v85 = _mm_shuffle_ps(v84, v84, 201);
                      v86 = _mm_mul_ps(v85, v85);
                      if ( (float)((float)(_mm_shuffle_ps(v86, v86, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v86, v86, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v86, v86, 170).m128_f32[0]) < 0.0000000099999991 )
                      {
                        v87 = _mm_sub_ps(v62->m_quad, v47);
                        hi[1] = 0.000099999997;
                        v88 = _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0).m128_f32[0];
                        v89 = _mm_sub_ps(v78, v47);
                        v90 = _mm_sub_ps(_mm_mul_ps(v87, v68), _mm_mul_ps(_mm_shuffle_ps(v87, v87, 201), v55));
                        v91 = _mm_shuffle_ps(v90, v90, 201);
                        v92 = _mm_mul_ps(v91, v91);
                        if ( (float)((float)(_mm_shuffle_ps(v92, v92, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v92, v92, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v92, v92, 170).m128_f32[0]) <= v88 )
                        {
                          v93 = _mm_sub_ps(_mm_mul_ps(v89, v68), _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v55));
                          v94 = _mm_shuffle_ps(v93, v93, 201);
                          v95 = _mm_mul_ps(v94, v94);
                          if ( (float)((float)(_mm_shuffle_ps(v95, v95, 85).m128_f32[0]
                                             + _mm_shuffle_ps(v95, v95, 0).m128_f32[0])
                                     + _mm_shuffle_ps(v95, v95, 170).m128_f32[0]) <= v88 )
                          {
                            v96 = _mm_mul_ps(v49, v49);
                            v97 = _mm_mul_ps(v49, v89);
                            v98 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
                                    _mm_shuffle_ps(v96, v96, 170));
                            v96.m128_f32[0] = _mm_rcp_ps(v98).m128_f32[0];
                            v99 = (float)(2.0 - (float)(v96.m128_f32[0] * v98.m128_f32[0])) * v96.m128_f32[0];
                            v100 = _mm_mul_ps(v49, v87);
                            v101 = fmax(
                                     fmin(
                                       (float)((float)(_mm_shuffle_ps(v100, v100, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v100, v100, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v100, v100, 170).m128_f32[0])
                                     * v99,
                                       1.0),
                                     0.0);
                            v102 = fmax(
                                     fmin(
                                       (float)((float)(_mm_shuffle_ps(v97, v97, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v97, v97, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v97, v97, 170).m128_f32[0])
                                     * v99,
                                       1.0),
                                     0.0);
                            if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v102 - v101)) >> 1) > 0.1 )
                            {
                              if ( v141 && v102 > v101 )
                              {
                                hkErrStream::hkErrStream((hkErrStream *)&v147, buf, 512);
                                v103 = hkOstream::operator<<(
                                         (hkOstream *)&v147,
                                         "Inconsistent triangle winding between at least triangle ");
                                v104 = hkOstream::operator<<(v103, u);
                                v105 = hkOstream::operator<<(v104, " and triangle ");
                                v106 = hkOstream::operator<<(v105, v58);
                                hkOstream::operator<<(v106, ". One sided welding will not work.");
                                hkError::messageWarning(
                                  0xABBA751E,
                                  buf,
                                  "Util\\Welding\\hkpMeshWeldingUtility.cpp",
                                  449);
                                hkOstream::~hkOstream((hkOstream *)&v147);
                                v171 = 1;
                                ((void (__fastcall *)(hkpShapeCollection *, _QWORD, _QWORD))mesh->hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[9].__vecDelDtor)(
                                  mesh,
                                  v58,
                                  v61->m_weldingInfo | 0x8000u);
                              }
                              else
                              {
                                m_size = v125.m_entries.m_size;
                                v108 = v101;
                                v75 = 1;
                                v109 = fmin(v101, v102);
                                v110 = 0;
                                v111 = fmax(v108, v102);
                                v112 = 0i64;
                                if ( v125.m_entries.m_size > 0 )
                                {
                                  v113 = v125.m_entries.m_data;
                                  while ( v109 <= v113->m_lo )
                                  {
                                    ++v112;
                                    ++v110;
                                    ++v113;
                                    if ( v112 >= v125.m_entries.m_size )
                                      goto LABEL_43;
                                  }
                                  m_size = v110 + 1;
                                }
LABEL_43:
                                t.m_lo = v109;
                                t.m_hi = v111;
                                t.m_value = v77;
                                hkArrayBase<hkEntry>::_insertAt(
                                  &v125.m_entries,
                                  &hkContainerHeapAllocator::s_alloc,
                                  m_size,
                                  &t);
                              }
                            }
                          }
                        }
                      }
                      ++v74;
                      ++v62;
                      --v76;
                    }
                    while ( v76 );
                    v50 = v155;
                    if ( !v75 )
                    {
                      hkBuildClipPlanesForTriangle((hkVector4f *)&v147, v61, 0.050000001);
                      if ( hkClipEdgeAgainstPlanes(&v0, &v1, 5, (hkVector4f *)&v147, &lo, hi) )
                      {
                        v114 = v125.m_entries.m_size;
                        v115 = 0;
                        v116 = 0i64;
                        if ( v125.m_entries.m_size > 0 )
                        {
                          v117 = v125.m_entries.m_data;
                          while ( lo <= v117->m_lo )
                          {
                            ++v116;
                            ++v115;
                            ++v117;
                            if ( v116 >= v125.m_entries.m_size )
                              goto LABEL_53;
                          }
                          v114 = v115 + 1;
                        }
LABEL_53:
                        v138.m_lo = lo;
                        v138.m_hi = hi[0];
                        v138.m_value = v77;
                        hkArrayBase<hkEntry>::_insertAt(
                          &v125.m_entries,
                          &hkContainerHeapAllocator::s_alloc,
                          v114,
                          &v138);
                      }
                    }
                    v25 = *(__m128 *)_xmm;
                    v48 = v139;
                    v14 = &v132->m_quad;
                  }
LABEL_55:
                  v32 = v122;
                }
              }
              v57 = v134 + 4;
              ++v127;
              v134 += 4i64;
              if ( v127 >= v164 )
              {
                v26 = v160;
                v22 = v135;
                v21 = v124;
                v7 = allShapes;
                goto LABEL_58;
              }
              continue;
            }
          }
LABEL_62:
          if ( disableEdges && v20 )
          {
            v118 = 31;
          }
          else
          {
            v119 = hkHistogram::evaluate(&v125);
            v118 = hkpWeldingUtility::calcEdgeAngleBitcode(v119);
          }
          v121 = hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(v16, v17, v118);
          v16 = v121;
          if ( v20 )
          {
            v16 = v121 | 0x8000;
            v121 |= 0x8000u;
          }
          v125.m_entries.m_size = 0;
          if ( v125.m_entries.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v125.m_entries.m_data,
              12 * (v125.m_entries.m_capacityAndFlags & 0x3FFFFFFF));
          p_m_quad = v129;
        }
        v19 = v154;
        ++v17;
        v18 = v136 + 1;
        v126 = v17;
        ++v136;
      }
      while ( v17 < 3 );
      v120 = v16;
      v11 = u;
      ((void (__fastcall *)(hkpShapeCollection *, _QWORD, __int64))mesh->hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[9].__vecDelDtor)(
        mesh,
        u,
        v120);
LABEL_74:
      v10 = &mesh->hkpShapeContainer;
      v11 = mesh->hkpShapeContainer::vfptr->getNextKey(&mesh->hkpShapeContainer, v11);
      u = v11;
    }
  }
}

// File Line: 510
// RVA: 0x13203A0
hkResult *__fastcall hkpMeshWeldingUtility::testWindingConsistency(
        hkResult *result,
        hkVector4f *localVertex0,
        hkVector4f *localEdgeOrtho,
        hkVector4f *localNormal,
        hkpTriangleShape *adjacentTriangle,
        hkVector4f *adjacentNormal)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  __m128 m_quad; // xmm8
  __int64 v10; // r9
  hkVector4f *p_m_vertexA; // r8
  __m128 v12; // xmm11
  float v13; // xmm6_4
  hkVector4f *v14; // rax
  __int64 v15; // rdx
  float v16; // xmm7_4
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  int v19; // eax
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  float v23; // xmm2_4
  __m128 v24; // xmm8
  int v25; // eax
  float v27; // [rsp+8h] [rbp-78h]

  v6 = FLOAT_N3_40282e38;
  v7 = FLOAT_3_40282e38;
  m_quad = localEdgeOrtho->m_quad;
  v10 = 3i64;
  p_m_vertexA = &adjacentTriangle->m_vertexA;
  v12 = localVertex0->m_quad;
  v13 = FLOAT_N3_40282e38;
  v14 = &adjacentTriangle->m_vertexA;
  v15 = 3i64;
  v16 = FLOAT_3_40282e38;
  do
  {
    v17 = v14->m_quad;
    ++v14;
    v18 = _mm_mul_ps(_mm_sub_ps(v17, v12), m_quad);
    v27 = (float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
        + _mm_shuffle_ps(v18, v18, 170).m128_f32[0];
    v13 = fmaxf(v27, v13);
    v16 = fminf(v27, v16);
    --v15;
  }
  while ( v15 );
  if ( v13 <= 0.0099999998 && v16 >= 0.0099999998 )
    goto LABEL_19;
  if ( v13 > 0.2 && v16 < 0.2 )
    goto LABEL_15;
  v19 = 0;
  v20 = _mm_mul_ps(localNormal->m_quad, adjacentNormal->m_quad);
  LOBYTE(v19) = COERCE_FLOAT((unsigned int)(2 * LODWORD(v13)) >> 1) > COERCE_FLOAT((unsigned int)(2 * LODWORD(v16)) >> 1);
  if ( (float)((float)v19
             * (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                     + _mm_shuffle_ps(v20, v20, 170).m128_f32[0])) >= 0.0 )
  {
LABEL_19:
    do
    {
      v21 = p_m_vertexA->m_quad;
      ++p_m_vertexA;
      v22 = _mm_mul_ps(_mm_sub_ps(v21, v12), localNormal->m_quad);
      v23 = (float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0] + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
          + _mm_shuffle_ps(v22, v22, 170).m128_f32[0];
      v6 = fmaxf(v23, v6);
      v7 = fminf(v23, v7);
      --v10;
    }
    while ( v10 );
    if ( (v6 > 0.0099999998 || v7 < 0.0099999998) && (v6 <= 0.2 || v7 >= 0.2) )
    {
      v24 = _mm_mul_ps(m_quad, adjacentNormal->m_quad);
      v25 = 0;
      LOBYTE(v25) = COERCE_FLOAT((unsigned int)(2 * LODWORD(v6)) >> 1) > COERCE_FLOAT((unsigned int)(2 * LODWORD(v7)) >> 1);
      if ( (float)((float)v25
                 * (float)((float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0] + _mm_shuffle_ps(v24, v24, 0).m128_f32[0])
                         + _mm_shuffle_ps(v24, v24, 170).m128_f32[0])) > 0.0 )
        goto LABEL_8;
    }
LABEL_15:
    result->m_enum = HK_SUCCESS;
    return result;
  }
LABEL_8:
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 565
// RVA: 0x1320260
float __fastcall hkpMeshWeldingUtility::calcAngleForEdge(
        hkVector4f *edgeNormal,
        hkVector4f *edgeOrtho,
        hkVector4f *triangleNormal)
{
  __m128 v3; // xmm2
  __m128 v4; // xmm1
  __m128 v5; // xmm8
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm5
  float result; // xmm0_4

  v3 = _mm_mul_ps(triangleNormal->m_quad, edgeNormal->m_quad);
  v4 = _mm_mul_ps(triangleNormal->m_quad, edgeOrtho->m_quad);
  v5 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170));
  v6 = _mm_rcp_ps(_mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170)));
  v7 = _mm_mul_ps(v6, v5);
  v8 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v7), _mm_cmplt_ps(*(__m128 *)_xmm, v7));
  v9 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v7), v8), _mm_andnot_ps(v8, v7));
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v10, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v10, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v10, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v10, *(__m128 *)s3))),
          _mm_mul_ps(v9, *(__m128 *)t3));
  v12 = _mm_cmple_ps((__m128)0i64, v6);
  v13 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v9, *(__m128 *)_xmm), *(__m128 *)_xmm), v11), v8),
          _mm_andnot_ps(v8, v11));
  LODWORD(result) = _mm_andnot_ps(v12, _mm_add_ps(_mm_or_ps(_mm_and_ps(*(__m128 *)_xmm, v5), *(__m128 *)_xmm), v13)).m128_u32[0] | v13.m128_i32[0] & v12.m128_i32[0];
  return result;
}

// File Line: 576
// RVA: 0x13201D0
void __fastcall hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(
        hkVector4f *vertex0,
        hkVector4f *vertex1,
        hkVector4f *vertex2,
        hkVector4f *normal)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2

  v4 = _mm_sub_ps(vertex2->m_quad, vertex1->m_quad);
  v5 = _mm_sub_ps(vertex1->m_quad, vertex0->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4));
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  normal->m_quad = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v9, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10))),
                     v7);
}

// File Line: 589
// RVA: 0x13201A0
__int64 __fastcall hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(
        unsigned __int16 combinedBitcode,
        char edgeIndex,
        int bitcode)
{
  return (bitcode << (5 * edgeIndex)) | (unsigned int)(unsigned __int16)(combinedBitcode & ~(31 << (5 * edgeIndex)));
}

// File Line: 603
// RVA: 0x1320180
__int64 __fastcall hkpMeshWeldingUtility::calcSingleEdgeBitcode(unsigned __int16 triangleEdgesBitcode, char edgeIndex)
{
  return (triangleEdgesBitcode >> (5 * edgeIndex)) & 0x1F;
}

// File Line: 619
// RVA: 0x1320EA0
hkResult *__fastcall hkpMeshWeldingUtility::calcWeldingInfoForTriangle(
        hkResult *result,
        unsigned int shapeKey,
        hkpBvTreeShape *bvTreeShape,
        hkpMeshWeldingUtility::WindingConsistency testConsistency,
        unsigned __int16 *info)
{
  __int64 v9; // rax
  hkVector4f *v10; // rax
  hkpTriangleShape *v11; // rbp
  hkResultEnum v12; // ebx
  unsigned __int16 *v13; // rax
  int edgeIndex; // edi
  hkResult resulta; // [rsp+40h] [rbp-248h] BYREF
  hkSimdFloat32 tolerance; // [rsp+50h] [rbp-238h] BYREF
  char v18[512]; // [rsp+60h] [rbp-228h] BYREF
  float combinedBitcodesOut; // [rsp+2A0h] [rbp+18h] BYREF

  v9 = ((__int64 (__fastcall *)(hkpBvTreeShape *))bvTreeShape->vfptr[7].__vecDelDtor)(bvTreeShape);
  v10 = (hkVector4f *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v9 + 40i64))(v9, shapeKey, v18);
  combinedBitcodesOut = hkDefaultTriangleDegeneracyTolerance;
  v11 = (hkpTriangleShape *)v10;
  tolerance.m_real = _mm_shuffle_ps(
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       0);
  v12 = HK_SUCCESS;
  if ( hkcdTriangleUtil::isDegenerate(v10 + 3, v10 + 4, v10 + 5, &tolerance) )
  {
    v13 = info;
    result->m_enum = HK_FAILURE;
    *v13 = 0;
  }
  else
  {
    LOWORD(combinedBitcodesOut) = 0;
    for ( edgeIndex = 0; edgeIndex < 3; ++edgeIndex )
    {
      if ( hkpMeshWeldingUtility::calcBitcodeForTriangleEdge(
             &resulta,
             bvTreeShape,
             v11,
             shapeKey,
             edgeIndex,
             testConsistency,
             (__int16 *)&combinedBitcodesOut)->m_enum == HK_FAILURE )
        v12 = HK_FAILURE;
    }
    *info = LOWORD(combinedBitcodesOut);
    result->m_enum = v12;
  }
  return result;
}

// File Line: 654
// RVA: 0x1320FD0
hkBool *__fastcall hkpMeshWeldingUtility::isTriangleWindingValid(
        hkBool *result,
        unsigned int shapeKey,
        hkpBvTreeShape *bvTreeShape)
{
  __int64 v6; // rax
  hkpTriangleShape *v7; // r14
  int edgeIndex; // ebx
  __int64 v9; // r8
  char v11[552]; // [rsp+40h] [rbp-228h] BYREF
  char v12; // [rsp+270h] [rbp+8h] BYREF
  __int16 combinedBitcodesOut; // [rsp+280h] [rbp+18h] BYREF
  hkResult resulta; // [rsp+288h] [rbp+20h] BYREF

  v6 = ((__int64 (__fastcall *)(hkpBvTreeShape *))bvTreeShape->vfptr[7].__vecDelDtor)(bvTreeShape);
  v7 = (hkpTriangleShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v6 + 40i64))(
                             v6,
                             shapeKey,
                             v11);
  ((void (__fastcall *)(hkError *, char *, __int64))hkSingleton<hkError>::s_instance->vfptr[2].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    &v12,
    4271404318i64);
  if ( v12 )
    ((void (__fastcall *)(hkError *, __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
      hkSingleton<hkError>::s_instance,
      4271404318i64,
      0i64);
  result->m_bool = 1;
  combinedBitcodesOut = 0;
  edgeIndex = 0;
  while ( hkpMeshWeldingUtility::calcBitcodeForTriangleEdge(
            &resulta,
            bvTreeShape,
            v7,
            shapeKey,
            edgeIndex,
            WINDING_IGNORE_CONSISTENCY,
            &combinedBitcodesOut)->m_enum != HK_FAILURE )
  {
    if ( ++edgeIndex >= 3 )
      goto LABEL_8;
  }
  result->m_bool = 0;
LABEL_8:
  if ( v12 )
  {
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(hkError *, __int64, __int64))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
      hkSingleton<hkError>::s_instance,
      4271404318i64,
      v9);
  }
  return result;
}

// File Line: 694
// RVA: 0x13210E0
hkResult *__fastcall hkpMeshWeldingUtility::calcBitcodeForTriangleEdge(
        hkResult *result,
        hkpBvTreeShape *bvTreeShape,
        hkpTriangleShape *triangleShape,
        unsigned int triangleShapeKey,
        unsigned __int16 *edgeIndex,
        hkpMeshWeldingUtility::WindingConsistency testConsistency,
        __int16 *combinedBitcodesOut)
{
  int v7; // esi
  __int64 v11; // rax
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  hkBaseObjectVtbl *vfptr; // rax
  char v15; // si
  __int64 v16; // rdi
  unsigned int v17; // ebx
  __int64 v18; // rax
  hkVector4f *v19; // rax
  hkOstream *v20; // rax
  hkOstream *v21; // rax
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  int v24; // eax
  int v25; // r8d
  _OWORD v27[2]; // [rsp+30h] [rbp-C0h] BYREF
  hkVector4f vertexArrayOut; // [rsp+50h] [rbp-A0h] BYREF
  char *v29; // [rsp+A0h] [rbp-50h] BYREF
  int v30; // [rsp+A8h] [rbp-48h]
  int v31; // [rsp+ACh] [rbp-44h]
  char v32; // [rsp+B0h] [rbp-40h] BYREF
  char buf[528]; // [rsp+2B0h] [rbp+1C0h] BYREF
  hkResult *vars0; // [rsp+4F0h] [rbp+400h]
  void *orderedEdgeVerticesOnTriangle1; // [rsp+4F8h] [rbp+408h] BYREF
  hkVector4f *vertices0; // [rsp+500h] [rbp+410h]
  int v37; // [rsp+510h] [rbp+420h]
  int v38; // [rsp+518h] [rbp+428h]

  v38 = v7;
  v29 = &v32;
  vertices0 = &triangleShape->m_vertexA;
  v30 = 0;
  v31 = -2147483520;
  v11 = v37 % 3;
  v12 = _mm_add_ps((__m128)_xmm, *(&triangleShape->m_vertexA.m_quad + v11));
  v13 = _mm_add_ps((__m128)_xmm, *(&triangleShape->m_vertexA.m_quad + v11));
  vfptr = bvTreeShape->vfptr;
  v27[0] = v12;
  v27[1] = v13;
  ((void (__fastcall *)(hkpBvTreeShape *, _OWORD *, char **))vfptr[8].__first_virtual_table_function__)(
    bvTreeShape,
    v27,
    &v29);
  v15 = 1;
  v16 = v30 - 1;
  if ( v30 - 1 >= 0 )
  {
    do
    {
      v17 = *(_DWORD *)&v29[4 * v16];
      if ( v17 != triangleShapeKey )
      {
        v18 = ((__int64 (__fastcall *)(hkpBvTreeShape *))bvTreeShape->vfptr[7].__vecDelDtor)(bvTreeShape);
        v19 = (hkVector4f *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v18 + 40i64))(v18, v17, buf);
        if ( v19[1].m_quad.m128_i8[0] == 2
          && hkpMeshWeldingUtility::createSingularVertexArray(
               vertices0,
               v19 + 3,
               v37,
               &vertexArrayOut,
               (int *)&orderedEdgeVerticesOnTriangle1) == 4 )
        {
          if ( v38 && (_DWORD)orderedEdgeVerticesOnTriangle1 != (HIDWORD(orderedEdgeVerticesOnTriangle1) + 1) % 3 )
          {
            if ( v15 )
            {
              hkErrStream::hkErrStream((hkErrStream *)v27, buf, 512);
              v20 = hkOstream::operator<<((hkOstream *)v27, "Inconsistant triangle winding between at least triangle ");
              v21 = hkOstream::operator<<(v20, triangleShapeKey);
              v22 = hkOstream::operator<<(v21, " and triangle ");
              v23 = hkOstream::operator<<(v22, v17);
              hkOstream::operator<<(v23, ". One sided welding will not work.");
              hkError::messageWarning(0xABBA751E, buf, "Util\\Welding\\hkpMeshWeldingUtility.cpp", 773);
              hkOstream::~hkOstream((hkOstream *)v27);
            }
            v15 = 0;
          }
          v24 = hkpMeshWeldingUtility::calcEdgeAngleBitcode(&vertexArrayOut);
          *edgeIndex = hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(*edgeIndex, v37, v24);
        }
      }
      --v16;
    }
    while ( v16 >= 0 );
    result = vars0;
  }
  v25 = v31;
  v30 = 0;
  result->m_enum = v15 == 0;
  if ( v25 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v29, 4 * v25);
  return result;
}

// File Line: 805
// RVA: 0x13213A0
__int64 __fastcall hkpMeshWeldingUtility::createSingularVertexArray(
        hkVector4f *vertices0,
        hkVector4f *vertices1,
        int edgeIndex,
        hkVector4f *vertexArrayOut,
        int *orderedEdgeVerticesOnTriangle1)
{
  __int64 v9; // rcx
  hkVector4f *v10; // r8
  int v11; // edx
  unsigned int v12; // r9d
  __m128 m_quad; // xmm3
  __int64 v14; // rax
  hkVector4f *v15; // rcx
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  hkVector4f *v18; // rax

  *vertexArrayOut = vertices0[edgeIndex % 3];
  v9 = (edgeIndex + 1) % 3;
  v10 = vertexArrayOut + 3;
  vertexArrayOut[1] = vertices0[v9];
  v11 = 0;
  vertexArrayOut[2] = vertices0[(edgeIndex + 2) % 3];
  v12 = 3;
  do
  {
    m_quad = vertices1->m_quad;
    v14 = 0i64;
    v15 = vertexArrayOut;
    while ( 1 )
    {
      v16 = _mm_sub_ps(v15->m_quad, m_quad);
      v17 = _mm_mul_ps(v16, v16);
      if ( (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
                 + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) == 0.0 )
        break;
      ++v14;
      ++v15;
      if ( v14 >= 2 )
      {
        v18 = v10;
        ++v12;
        ++v10;
        *v18 = (hkVector4f)m_quad;
        goto LABEL_7;
      }
    }
    orderedEdgeVerticesOnTriangle1[v14] = v11;
LABEL_7:
    ++v11;
    ++vertices1;
  }
  while ( v11 < 3 );
  return v12;
}

// File Line: 849
// RVA: 0x13214C0
__int64 __fastcall hkpMeshWeldingUtility::calcEdgeAngleBitcode(hkVector4f *vertices)
{
  float v1; // xmm0_4
  __int64 result; // rax
  float v3; // xmm1_4
  float cosAngleOut; // [rsp+38h] [rbp+10h] BYREF
  float sinAngleOut; // [rsp+40h] [rbp+18h] BYREF

  v1 = hkpMeshWeldingUtility::calcAngleFromVertices(vertices, &sinAngleOut, &cosAngleOut);
  result = 0i64;
  while ( 1 )
  {
    v3 = (float)((float)(int)result * 0.20943952) - 3.1415927;
    if ( v1 <= v3 )
      break;
    result = (unsigned int)(result + 1);
    if ( (int)result >= 31 )
      return result;
  }
  if ( v1 > 0.0 && v1 != v3 )
    return (unsigned int)(result - 1);
  return result;
}

// File Line: 890
// RVA: 0x1321530
float __fastcall hkpMeshWeldingUtility::calcAngleFromVertices(
        hkVector4f *vertices,
        float *sinAngleOut,
        float *cosAngleOut)
{
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm8
  __m128 v15; // xmm7
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm6
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm6
  float result; // xmm0_4
  hkVector4f v25; // [rsp+20h] [rbp-68h] BYREF
  hkVector4f normal; // [rsp+30h] [rbp-58h] BYREF

  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(vertices, vertices + 1, vertices + 2, &v25);
  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(vertices + 1, vertices, vertices + 3, &normal);
  v6 = _mm_sub_ps(vertices[1].m_quad, vertices->m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_mul_ps(
          v6,
          _mm_andnot_ps(
            _mm_cmple_ps(v8, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9))));
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v25.m_quad, v25.m_quad, 201), v10),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v25.m_quad));
  v12 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), normal.m_quad);
  v13 = _mm_mul_ps(normal.m_quad, v25.m_quad);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v16 = _mm_rcp_ps(v15);
  v17 = _mm_mul_ps(v16, v14);
  v18 = _mm_or_ps(_mm_cmpnle_ps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v17), _mm_cmplt_ps(*(__m128 *)_xmm, v17));
  v19 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v17), v18), _mm_andnot_ps(v18, v17));
  v20 = _mm_mul_ps(v19, v19);
  v21 = _mm_cmple_ps((__m128)0i64, v16);
  v22 = _mm_mul_ps(
          _mm_rcp_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_rcp_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_rcp_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v20, *(__m128 *)s0)), *(__m128 *)t0),
                          _mm_add_ps(v20, *(__m128 *)s1))),
                      *(__m128 *)t1),
                    _mm_add_ps(v20, *(__m128 *)s2))),
                *(__m128 *)t2),
              _mm_add_ps(v20, *(__m128 *)s3))),
          _mm_mul_ps(v19, *(__m128 *)t3));
  *sinAngleOut = v14.m128_f32[0];
  *cosAngleOut = v15.m128_f32[0];
  v23 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v19, *(__m128 *)_xmm), *(__m128 *)_xmm), v22), v18),
          _mm_andnot_ps(v18, v22));
  LODWORD(result) = v23.m128_i32[0] & v21.m128_i32[0] | _mm_andnot_ps(
                                                          v21,
                                                          _mm_add_ps(
                                                            _mm_or_ps(_mm_and_ps(v14, *(__m128 *)_xmm), *(__m128 *)_xmm),
                                                            v23)).m128_u32[0];
  return result;
}

// File Line: 938
// RVA: 0x1320620
__int64 __fastcall hkpMeshWeldingUtility::computeTriangleWeldingInfo(
        hkVector4f *triangle,
        hkVector4f *neighbors,
        unsigned int numNeighbors,
        hkBool weldOpenEdges,
        float tolerance)
{
  __int64 v5; // rbx
  hkVector4f *v8; // rsi
  float v9; // xmm12_4
  float padding; // xmm7_4
  hkVector4f *v11; // r13
  __int64 v12; // rdi
  __m128 m_real; // xmm11
  __int64 v14; // rbx
  int v15; // esi
  __m128 m_quad; // xmm13
  hkVector4f *v17; // rdi
  hkVector4f *v18; // r8
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm6
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  float v30; // xmm0_4
  __int64 v31; // r9
  __int64 v32; // r10
  int v33; // edx
  __int64 v34; // rcx
  float *v35; // rax
  unsigned __int16 v36; // si
  int v37; // ebx
  hkHistogram **v38; // rdi
  float v39; // xmm0_4
  int v40; // eax
  unsigned __int16 v41; // ax
  float lo; // [rsp+40h] [rbp-C0h] BYREF
  float hi[3]; // [rsp+44h] [rbp-BCh] BYREF
  int v45; // [rsp+50h] [rbp-B0h] BYREF
  void *v46; // [rsp+58h] [rbp-A8h]
  int v47; // [rsp+60h] [rbp-A0h]
  int v48; // [rsp+64h] [rbp-9Ch]
  int v49; // [rsp+68h] [rbp-98h] BYREF
  void *v50; // [rsp+70h] [rbp-90h]
  int v51; // [rsp+78h] [rbp-88h]
  int v52; // [rsp+7Ch] [rbp-84h]
  __int64 v53; // [rsp+80h] [rbp-80h]
  int v54; // [rsp+88h] [rbp-78h] BYREF
  void *v55; // [rsp+90h] [rbp-70h]
  int v56; // [rsp+98h] [rbp-68h]
  int v57; // [rsp+9Ch] [rbp-64h]
  hkEntry t; // [rsp+A0h] [rbp-60h] BYREF
  hkSimdFloat32 v59; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f normal; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v61[4]; // [rsp+D0h] [rbp-30h] BYREF
  hkSimdFloat32 v62; // [rsp+F0h] [rbp-10h] BYREF
  hkVector4f edgeOrtho; // [rsp+100h] [rbp+0h] BYREF
  float result; // [rsp+1E0h] [rbp+E0h] BYREF
  char m_bool; // [rsp+1E8h] [rbp+E8h]

  m_bool = weldOpenEdges.m_bool;
  v5 = numNeighbors;
  if ( !numNeighbors )
    return 0i64;
  v8 = triangle + 1;
  result = hkDefaultTriangleDegeneracyTolerance;
  v59.m_real = _mm_shuffle_ps(
                 (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                 (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                 0);
  if ( hkcdTriangleUtil::isDegenerate(triangle, triangle + 1, triangle + 2, &v59) )
    return 0i64;
  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(triangle, v8, triangle + 2, (hkVector4f *)&v59);
  v55 = 0i64;
  v56 = 0;
  v57 = 0x80000000;
  v54 = 0;
  if ( !m_bool )
    v54 = 1078530011;
  v46 = 0i64;
  v47 = 0;
  v48 = 0x80000000;
  v45 = 0;
  if ( !m_bool )
    v45 = 1078530011;
  v50 = 0i64;
  v51 = 0;
  v52 = 0x80000000;
  v49 = 0;
  if ( !m_bool )
    v49 = 1078530011;
  v61[0] = (__int64)&v54;
  v61[1] = (__int64)&v45;
  LODWORD(v9) = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0).m128_u32[0];
  v61[2] = (__int64)&v49;
  if ( (int)v5 > 0 )
  {
    padding = tolerance;
    v11 = neighbors + 1;
    v12 = v5;
    v53 = v5;
    m_real = v59.m_real;
    do
    {
      hi[1] = hkDefaultTriangleDegeneracyTolerance;
      v62.m_real = _mm_shuffle_ps(
                     (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                     (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                     0);
      if ( !hkcdTriangleUtil::isDegenerate(v11 - 1, v11, v11 + 1, &v62) )
      {
        hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(v11 - 1, v11, v11 + 1, &normal);
        v14 = 0i64;
        v15 = 1;
        m_quad = normal.m_quad;
        v17 = triangle;
        do
        {
          v18 = &triangle[v15 % 3];
          v19 = _mm_sub_ps(v18->m_quad, v17->m_quad);
          v20 = _mm_mul_ps(v19, v19);
          v21 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                  _mm_shuffle_ps(v20, v20, 170));
          v22 = _mm_rsqrt_ps(v21);
          v23 = _mm_mul_ps(
                  v19,
                  _mm_andnot_ps(
                    _mm_cmple_ps(v21, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                      _mm_mul_ps(*(__m128 *)_xmm, v22))));
          v24 = _mm_mul_ps(m_quad, v23);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_INT(
                                             (float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0]
                                                   + _mm_shuffle_ps(v24, v24, 0).m128_f32[0])
                                           + _mm_shuffle_ps(v24, v24, 170).m128_f32[0])) >> 1) < v9 )
          {
            lo = 0.0;
            hi[0] = 1.0;
            if ( hkpMeshWeldingUtility::clipLineAgainstTriangle(
                   (hkBool *)&result,
                   v17,
                   v18,
                   v11 - 1,
                   &normal,
                   padding,
                   &lo,
                   hi)->m_bool )
            {
              v25 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(m_real, m_real, 201), v23),
                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), m_real));
              v26 = _mm_shuffle_ps(v25, v25, 201);
              v27 = _mm_mul_ps(v26, v26);
              v28 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                      _mm_shuffle_ps(v27, v27, 170));
              v29 = _mm_rsqrt_ps(v28);
              edgeOrtho.m_quad = _mm_mul_ps(
                                   v26,
                                   _mm_andnot_ps(
                                     _mm_cmple_ps(v28, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                                       _mm_mul_ps(*(__m128 *)_xmm, v29))));
              v30 = hkpMeshWeldingUtility::calcAngleForEdge((hkVector4f *)&v59, &edgeOrtho, &normal);
              v31 = v61[v14];
              v32 = *(int *)(v31 + 16);
              v33 = 0;
              v34 = 0i64;
              if ( (int)v32 > 0 )
              {
                v35 = *(float **)(v31 + 8);
                while ( lo <= *v35 )
                {
                  ++v34;
                  ++v33;
                  v35 += 3;
                  if ( v34 >= v32 )
                    goto LABEL_21;
                }
                LODWORD(v32) = v33 + 1;
              }
LABEL_21:
              t.m_lo = lo;
              t.m_hi = hi[0];
              t.m_value = v30;
              hkArrayBase<hkEntry>::_insertAt(
                (hkArrayBase<hkEntry> *)(v31 + 8),
                &hkContainerHeapAllocator::s_alloc,
                v32,
                &t);
            }
          }
          ++v14;
          ++v15;
          ++v17;
        }
        while ( v14 < 3 );
        v12 = v53;
      }
      v11 += 3;
      v53 = --v12;
    }
    while ( v12 );
  }
  v36 = 0;
  v37 = 0;
  v38 = (hkHistogram **)v61;
  do
  {
    v39 = hkHistogram::evaluate(*v38);
    v40 = hkpWeldingUtility::calcEdgeAngleBitcode(v39);
    v41 = hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(v36, v37++, v40);
    ++v38;
    v36 = v41;
  }
  while ( v37 < 3 );
  v51 = 0;
  if ( v52 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v50, 12 * (v52 & 0x3FFFFFFF));
  v50 = 0i64;
  v52 = 0x80000000;
  v47 = 0;
  if ( v48 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v46, 12 * (v48 & 0x3FFFFFFF));
  v46 = 0i64;
  v48 = 0x80000000;
  v56 = 0;
  if ( v57 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v55, 12 * (v57 & 0x3FFFFFFF));
  return v36;
}oc, v46, 12 * (v48 & 0x3FFFFFFF));
  v46 = 0i64;
  v48 = 0x80000000;
  v56 = 0;
  if ( v57 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v55, 12 * (v57 & 0x3FFFFFFF));
  return 

// File Line: 1016
// RVA: 0x1320B70
hkBool *__fastcall hkpMeshWeldingUtility::clipLineAgainstTriangle(
        hkBool *result,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *vertices,
        hkVector4f *normal,
        float padding,
        float *lo,
        float *hi)
{
  __m128 m_quad; // xmm7
  char v11; // bl
  hkVector4f *v12; // r9
  __m128 v13; // xmm9
  int v14; // r8d
  __m128 v15; // xmm10
  __m128 v16; // xmm6
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  __m128 v20; // xmm6
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm3
  __m128 v34; // xmm7
  __m128 v35; // xmm9
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  float v38; // xmm1_4
  float v39; // xmm0_4

  m_quad = v0->m_quad;
  v11 = 0;
  v12 = vertices - 2;
  v13 = v1->m_quad;
  v14 = -2;
  v15 = _mm_shuffle_ps(
          (__m128)(unsigned int)(LODWORD(padding) ^ _xmm[0]),
          (__m128)(unsigned int)(LODWORD(padding) ^ _xmm[0]),
          0);
  do
  {
    if ( v14 == -2 )
    {
      v16 = normal->m_quad;
      v17 = _mm_mul_ps(vertices->m_quad, normal->m_quad);
    }
    else if ( v14 == -1 )
    {
      v16 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), normal->m_quad);
      v17 = _mm_mul_ps(vertices->m_quad, v16);
    }
    else
    {
      v18 = _mm_sub_ps(vertices[(v14 + 1) % 3].m_quad, v12->m_quad);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(normal->m_quad, normal->m_quad, 201), v18),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), normal->m_quad));
      v20 = _mm_shuffle_ps(v19, v19, 201);
      v21 = _mm_mul_ps(v20, v20);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_rsqrt_ps(v22);
      v16 = _mm_mul_ps(
              v20,
              _mm_andnot_ps(
                _mm_cmple_ps(v22, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                  _mm_mul_ps(*(__m128 *)_xmm, v23))));
      v17 = _mm_mul_ps(v16, v12->m_quad);
    }
    v24 = _mm_sub_ps(
            v15,
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)));
    v25 = _mm_mul_ps(m_quad, v16);
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_mul_ps(v13, v16);
    v28 = _mm_add_ps(v26, v24);
    v29 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
              _mm_shuffle_ps(v27, v27, 170)),
            v24);
    if ( v28.m128_f32[0] >= 0.0 && v29.m128_f32[0] >= 0.0 )
    {
      result->m_bool = 0;
      return result;
    }
    if ( (float)(v29.m128_f32[0] * v28.m128_f32[0]) < 0.0 )
    {
      v30 = _mm_sub_ps(v28, v29);
      v31 = _mm_rcp_ps(v30);
      v32 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(v13, m_quad),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v30)), v31), v28)),
              m_quad);
      if ( v28.m128_f32[0] <= 0.0 )
        v13 = v32;
      else
        m_quad = v32;
      v11 = 1;
    }
    ++v14;
    ++v12;
  }
  while ( v14 < 3 );
  if ( v11 )
  {
    v33 = _mm_sub_ps(v1->m_quad, v0->m_quad);
    v34 = _mm_mul_ps(_mm_sub_ps(m_quad, v0->m_quad), v33);
    v35 = _mm_mul_ps(_mm_sub_ps(v13, v0->m_quad), v33);
    v36 = _mm_mul_ps(v33, v33);
    v37 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
            _mm_shuffle_ps(v36, v36, 170));
    v38 = _mm_rcp_ps(v37).m128_f32[0];
    v39 = (float)(2.0 - (float)(v38 * v37.m128_f32[0])) * v38;
    *lo = v39
        * (float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
                + _mm_shuffle_ps(v34, v34, 170).m128_f32[0]);
    *hi = v39
        * (float)((float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
                + _mm_shuffle_ps(v35, v35, 170).m128_f32[0]);
  }
  else
  {
    *lo = 0.0;
    *hi = 1.0;
  }
  result->m_bool = 1;
  return result;
}

