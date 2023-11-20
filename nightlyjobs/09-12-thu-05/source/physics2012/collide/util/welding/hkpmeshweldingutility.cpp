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
  result->m_bool = COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(lhs->m_value - rhs->m_value)) >> 1) > 0.001;
  return result;
}

// File Line: 72
// RVA: 0x1321FC0
float __fastcall hkHistogram::evaluate(hkHistogram *this)
{
  int v1; // er8
  hkHistogram *v2; // r14
  signed int v4; // eax
  signed int v5; // edi
  float *v6; // r9
  int v7; // ebx
  signed int v8; // er15
  signed int v9; // esi
  signed __int64 v10; // r12
  signed __int64 v11; // r13
  __int64 v12; // r10
  bool v13; // sf
  unsigned __int8 v14; // of
  hkBool *v15; // rax
  signed __int64 v16; // r9
  float v17; // xmm2_4
  signed __int64 v18; // r8
  hkEntry *v19; // rax
  signed __int64 v20; // rdx
  float *v21; // rcx
  unsigned __int64 v22; // rax
  float v23; // xmm0_4
  float v24; // xmm1_4
  signed __int64 v25; // r8
  signed __int64 v26; // rdx
  float v27; // xmm0_4
  hkEntry *v28; // rax
  int v29; // xmm7_4
  float v30; // xmm6_4
  __int64 v31; // rax
  signed __int64 v32; // rcx
  int v33; // eax
  float v34; // xmm6_4
  char v35; // dl
  float *v36; // rax
  __int64 v37; // rcx
  float v38; // xmm0_4
  signed __int64 v39; // [rsp+20h] [rbp-39h]
  float *array; // [rsp+28h] [rbp-31h]
  int v41; // [rsp+30h] [rbp-29h]
  int v42; // [rsp+34h] [rbp-25h]
  hkBool result; // [rsp+C0h] [rbp+67h]
  __int64 v44; // [rsp+C8h] [rbp+6Fh]
  int v45; // [rsp+D0h] [rbp+77h]
  int v46; // [rsp+D8h] [rbp+7Fh]

  v1 = this->m_entries.m_size;
  v2 = this;
  if ( !v1 )
    return this->m_freeAngle;
  if ( v1 > 1 )
    hkAlgorithm::quickSortRecursive<hkEntry,hkAlgorithm::less<hkEntry>>(this->m_entries.m_data, 0, v1 - 1, 0);
  v4 = v2->m_entries.m_size;
  v5 = 1;
  v6 = 0i64;
  v7 = 0;
  v8 = 2147483648;
  v9 = 0;
  v10 = 0i64;
  array = 0i64;
  v11 = 1i64;
  v41 = 0;
  v42 = 2147483648;
  if ( v4 >= 1 )
  {
    v12 = 0i64;
    v39 = 12i64;
    v44 = 0i64;
    v14 = __OFSUB__(1, v4);
    v13 = 1 - v4 < 0;
    do
    {
      if ( v13 ^ v14
        && (v15 = operator!=(&result, &v2->m_entries.m_data[v9], &v2->m_entries.m_data[v5]), v12 = v44, !v15->m_bool) )
      {
        v32 = v39;
      }
      else
      {
        v16 = 0i64;
        v17 = 0.0;
        v18 = v5 - v9;
        if ( v18 >= 4 )
        {
          v19 = v2->m_entries.m_data;
          v20 = (signed __int64)&v19[2] + v12;
          v21 = (float *)((char *)&v19->m_hi + v12);
          v22 = ((unsigned __int64)(v18 - 4) >> 2) + 1;
          v16 = 4 * v22;
          do
          {
            v23 = *v21;
            v24 = v21[3];
            v21 += 12;
            v20 += 48i64;
            v17 = (float)((float)((float)(v17 + (float)(v23 - *(float *)(v20 - 72))) + (float)(v24 - *(v21 - 10)))
                        + (float)(*(v21 - 6) - *(float *)(v20 - 48)))
                + (float)(*(v21 - 3) - *(float *)(v20 - 36));
            --v22;
          }
          while ( v22 );
        }
        if ( v16 < v18 )
        {
          v25 = v18 - v16;
          v26 = (signed __int64)&v2->m_entries.m_data[v16 + v10];
          do
          {
            v27 = *(float *)(v26 + 4);
            v26 += 12i64;
            v17 = v17 + (float)(v27 - *(float *)(v26 - 12));
            --v25;
          }
          while ( v25 );
        }
        v28 = v2->m_entries.m_data;
        *(float *)&v44 = v17;
        v45 = 0;
        v46 = 1065353216;
        v29 = *(_DWORD *)((char *)&v28->m_value + v12);
        v30 = fminf(fmaxf(v17, 0.0), 1.0);
        if ( v7 == (v8 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 12);
          v8 = v42;
          v7 = v41;
        }
        v31 = (__int64)&array[3 * v7];
        if ( v31 )
        {
          *(_DWORD *)v31 = 0;
          *(float *)(v31 + 4) = v30;
          *(_DWORD *)(v31 + 8) = v29;
          v8 = v42;
          v7 = v41;
        }
        v32 = v39;
        ++v7;
        v9 = v5;
        v12 = v39;
        v44 = v39;
        v41 = v7;
        v10 = v11;
      }
      v33 = v2->m_entries.m_size;
      ++v5;
      ++v11;
      v39 = v32 + 12;
      v14 = __OFSUB__(v5, v33);
      v13 = v5 - v33 < 0;
    }
    while ( v5 <= v33 );
    v6 = array;
  }
  v34 = FLOAT_3_1415927;
  v35 = 0;
  if ( v7 <= 0 )
    goto LABEL_35;
  v36 = v6 + 2;
  v37 = (unsigned int)v7;
  do
  {
    if ( (float)(*(v36 - 1) - *(v36 - 2)) >= 0.60000002 )
    {
      v38 = *v36;
      *(float *)&v44 = v34;
      v35 = 1;
      *(float *)&result.m_bool = v38;
      v34 = fminf(v34, v38);
    }
    v36 += 3;
    --v37;
  }
  while ( v37 );
  if ( !v35 )
LABEL_35:
    v34 = 0.0;
  v41 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v6,
      12 * (v8 & 0x3FFFFFFF));
  return v34;
}

// File Line: 159
// RVA: 0x13217E0
void __fastcall hkBuildClipPlanesForTriangle(hkVector4f *out, hkpTriangleShape *triangle, float extraRadius)
{
  __m128 *v3; // rsi
  __m128 *v4; // rbx
  __m128 *v5; // rdi
  hkVector4f *v6; // rbp
  __m128 v7; // xmm10
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
  hkVector4f normal; // [rsp+20h] [rbp-88h]

  v3 = &triangle->m_vertexC.m_quad;
  v4 = &triangle->m_vertexA.m_quad;
  v5 = &triangle->m_vertexB.m_quad;
  v6 = out;
  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(
    &triangle->m_vertexA,
    &triangle->m_vertexB,
    &triangle->m_vertexC,
    &normal);
  v7 = normal.m_quad;
  v8 = _mm_sub_ps(*v5, *v4);
  v9 = _mm_shuffle_ps(
         (__m128)(unsigned int)(LODWORD(extraRadius) ^ _xmm[0]),
         (__m128)(unsigned int)(LODWORD(extraRadius) ^ _xmm[0]),
         0);
  v10 = _mm_mul_ps(*v4, normal.m_quad);
  v11 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 201);
  v12 = _mm_sub_ps(*v4, *v3);
  v13 = _mm_sub_ps(*v3, *v5);
  v6->m_quad = _mm_shuffle_ps(
                 normal.m_quad,
                 _mm_unpackhi_ps(
                   normal.m_quad,
                   _mm_sub_ps(
                     v9,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                       _mm_shuffle_ps(v10, v10, 170)))),
                 196);
  v14 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v7);
  v15 = _mm_mul_ps(*v4, v14);
  v6[1].m_quad = _mm_shuffle_ps(
                   v14,
                   _mm_unpackhi_ps(
                     v14,
                     _mm_sub_ps(
                       v9,
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                         _mm_shuffle_ps(v15, v15, 170)))),
                   196);
  v16 = _mm_sub_ps(_mm_mul_ps(v8, v11), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7));
  v17 = _mm_shuffle_ps(v16, v16, 201);
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_mul_ps(
          v17,
          _mm_andnot_ps(
            _mm_cmpleps(v19, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
              _mm_mul_ps(v20, *(__m128 *)_xmm))));
  v22 = _mm_mul_ps(*v4, v21);
  v6[2].m_quad = _mm_shuffle_ps(
                   v21,
                   _mm_unpackhi_ps(
                     v21,
                     _mm_sub_ps(
                       v9,
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                         _mm_shuffle_ps(v22, v22, 170)))),
                   196);
  v23 = _mm_sub_ps(_mm_mul_ps(v13, v11), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v7));
  v24 = _mm_shuffle_ps(v23, v23, 201);
  v25 = _mm_mul_ps(v24, v24);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_rsqrt_ps(v26);
  v28 = _mm_mul_ps(
          v24,
          _mm_andnot_ps(
            _mm_cmpleps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(v27, *(__m128 *)_xmm))));
  v29 = _mm_mul_ps(v28, *v5);
  v6[3].m_quad = _mm_shuffle_ps(
                   v28,
                   _mm_unpackhi_ps(
                     v28,
                     _mm_sub_ps(
                       v9,
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                         _mm_shuffle_ps(v29, v29, 170)))),
                   196);
  v30 = _mm_sub_ps(_mm_mul_ps(v12, v11), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v7));
  v31 = _mm_shuffle_ps(v30, v30, 201);
  v32 = _mm_mul_ps(v31, v31);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(
          v31,
          _mm_andnot_ps(
            _mm_cmpleps(v33, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(v34, *(__m128 *)_xmm))));
  v36 = _mm_mul_ps(v35, *v3);
  v6[4].m_quad = _mm_shuffle_ps(
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
char __fastcall hkClipEdgeAgainstPlanes(hkVector4f *v0, hkVector4f *v1, int planeCount, hkVector4f *planeEquations, float *lo, float *hi)
{
  __m128 v6; // xmm7
  signed __int64 v7; // rax
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
  char result; // al

  v6 = v0->m_quad;
  v7 = 0i64;
  v8 = v1->m_quad;
  if ( planeCount <= 0 )
  {
LABEL_9:
    v17 = _mm_sub_ps(v1->m_quad, v0->m_quad);
    v18 = _mm_mul_ps(_mm_sub_ps(v6, v0->m_quad), v17);
    v19 = _mm_mul_ps(_mm_sub_ps(v8, v0->m_quad), v17);
    v20 = _mm_mul_ps(v17, v17);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    v20.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v21);
    v22 = (float)(2.0 - (float)(v20.m128_f32[0] * v21.m128_f32[0])) * v20.m128_f32[0];
    *lo = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170)))
        * v22;
    *hi = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170)))
        * v22;
    result = 1;
  }
  else
  {
    while ( 1 )
    {
      v9 = _mm_mul_ps(planeEquations->m_quad, v6);
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
        break;
      if ( (float)(v13.m128_f32[0] * v12.m128_f32[0]) < 0.0 )
      {
        v14 = _mm_sub_ps(v12, v13);
        v15 = _mm_rcp_ps(v14);
        v16 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(v8, v6),
                  _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15), v12)),
                v6);
        if ( v12.m128_f32[0] <= 0.0 )
          v8 = v16;
        else
          v6 = v16;
      }
      ++v7;
      ++planeEquations;
      if ( v7 >= planeCount )
        goto LABEL_9;
    }
    result = 0;
  }
  return result;
}

// File Line: 251
// RVA: 0x131EFC0
void __fastcall hkpMeshWeldingUtility::computeWeldingInfo(hkpShapeCollection *collection, hkpBvTreeShape *bvTree, hkpWeldingUtility::WeldingType weldingType, bool weldOpenEdges)
{
  hkpShapeCollection *v4; // rsi
  bool v5; // bl
  hkpWeldingUtility::WeldingType v6; // edi
  hkLifoAllocator *v7; // rax
  char *v8; // rdx
  unsigned __int64 v9; // rcx
  int v10; // er8
  signed __int64 v11; // rcx
  __int128 v12; // xmm0
  int v13; // eax
  char *v14; // rdi
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  char *array; // [rsp+28h] [rbp-61h]
  int v19; // [rsp+30h] [rbp-59h]
  int v20; // [rsp+34h] [rbp-55h]
  void *p; // [rsp+38h] [rbp-51h]
  int v22; // [rsp+40h] [rbp-49h]
  __int128 v23; // [rsp+88h] [rbp-1h]
  bool v24; // [rsp+108h] [rbp+7Fh]

  v4 = collection;
  v5 = weldOpenEdges;
  v6 = weldingType;
  *(_QWORD *)&v23 = bvTree;
  array = 0i64;
  v19 = 0;
  v20 = 2147483648;
  v22 = 1;
  v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (char *)v7->m_cur;
  v9 = (unsigned __int64)(v8 + 128);
  if ( v7->m_slabSize < 128 || (void *)v9 > v7->m_end )
    v8 = (char *)hkLifoAllocator::allocateFromNewSlab(v7, 128);
  else
    v7->m_cur = (void *)v9;
  v10 = v19;
  array = v8;
  v20 = -2147483647;
  p = v8;
  if ( v19 == 1 )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 80);
    v10 = v19;
    v8 = array;
  }
  v11 = (signed __int64)&v8[80 * v10];
  if ( v11 )
  {
    v12 = v23;
    *(hkVector4f *)v11 = (hkVector4f)transform.m_quad;
    *(hkVector4f *)(v11 + 16) = (hkVector4f)direction.m_quad;
    *(hkVector4f *)(v11 + 32) = (hkVector4f)stru_141A71280.m_quad;
    *(_OWORD *)(v11 + 48) = 0i64;
    *(_OWORD *)(v11 + 64) = v12;
    v10 = v19;
  }
  v19 = v10 + 1;
  hkpMeshWeldingUtility::computeWeldingInfoMultiShape(
    (hkTransformf *)&transform,
    v4,
    v6,
    (hkArray<hkpMeshWeldingUtility::ShapeInfo,hkContainerHeapAllocator> *)&array,
    v5,
    v24);
  v13 = v19;
  v14 = (char *)p;
  if ( p == array )
    v13 = 0;
  v19 = v13;
  v15 = (80 * v22 + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || &v14[v17] != v16->m_cur || v16->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v16, v14, v17);
  else
    v16->m_cur = v14;
  v19 = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      80 * (v20 & 0x3FFFFFFF));
}

// File Line: 265
// RVA: 0x131F1C0
void __fastcall hkpMeshWeldingUtility::computeWeldingInfoMultiShape(hkTransformf *meshTransform, hkpShapeCollection *mesh, hkpWeldingUtility::WeldingType weldingType, hkArray<hkpMeshWeldingUtility::ShapeInfo,hkContainerHeapAllocator> *allShapes, bool weldOpenEdges, bool disableEdges)
{
  char v6; // al
  hkArray<hkpMeshWeldingUtility::ShapeInfo,hkContainerHeapAllocator> *v7; // r14
  hkpWeldingUtility::WeldingType v8; // ebx
  hkpShapeCollection *v9; // r13
  signed __int64 v10; // rsi
  unsigned int v11; // edi
  hkVector4f *v12; // rax
  __m128 *v13; // rsi
  __m128 *v14; // r12
  signed __int64 v15; // rbx
  unsigned __int16 v16; // di
  int v17; // er15
  __m128i *v18; // rax
  __m128 v19; // xmm1
  char v20; // bl
  int v21; // esi
  __int64 v22; // rbx
  char *v23; // r8
  __m128 *v24; // r9
  __m128 v25; // xmm12
  __m128 v26; // xmm8
  __m128 v27; // xmm9
  __m128 v28; // xmm10
  hkpMeshWeldingUtility::ShapeInfo *v29; // rdx
  signed __int64 v30; // rcx
  __m128 *v31; // rax
  __int64 *v32; // rdi
  __m128 v33; // xmm7
  __m128 v34; // xmm6
  __m128 v35; // xmm3
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm11
  __m128 v44; // xmm7
  __m128 v45; // xmm10
  __m128 v46; // xmm13
  __m128 v47; // xmm1
  __int64 v48; // rax
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  __m128 v51; // xmm9
  __m128 v52; // xmm1
  __int64 v53; // rcx
  unsigned int v54; // er15
  __int64 v55; // rax
  hkVector4f *v56; // rax
  hkpTriangleShape *v57; // rsi
  hkVector4f *v58; // rbx
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  __m128 v61; // xmm3
  __m128 v62; // xmm4
  __m128 v63; // xmm1
  __m128 v64; // xmm8
  __m128 v65; // xmm5
  __m128 v66; // xmm5
  __m128 v67; // xmm1
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  signed int v70; // edi
  char v71; // r12
  signed __int64 v72; // r14
  float v73; // xmm12_4
  __m128 v74; // xmm6
  __m128 v75; // xmm5
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm2
  __m128 v79; // xmm5
  __m128 v80; // xmm2
  __m128 v81; // xmm2
  __m128 v82; // xmm2
  __m128 v83; // xmm7
  float v84; // xmm3_4
  __m128 v85; // xmm6
  __m128 v86; // xmm2
  __m128 v87; // xmm2
  __m128 v88; // xmm2
  __m128 v89; // xmm2
  __m128 v90; // xmm2
  __m128 v91; // xmm2
  __m128 v92; // xmm1
  __m128 v93; // xmm3
  __m128 v94; // xmm2
  float v95; // xmm4_4
  __m128 v96; // xmm1
  float v97; // xmm5_4
  float v98; // xmm6_4
  hkOstream *v99; // rax
  hkOstream *v100; // rax
  hkOstream *v101; // rax
  hkOstream *v102; // rax
  int v103; // er8
  float v104; // xmm0_4
  float v105; // xmm5_4
  int v106; // ecx
  float v107; // xmm0_4
  signed __int64 v108; // rdx
  hkEntry *v109; // rax
  int v110; // er10
  int v111; // edx
  signed __int64 v112; // rcx
  hkEntry *v113; // rax
  int v114; // er8
  float v115; // xmm0_4
  __int64 v116; // r8
  unsigned __int16 v117; // [rsp+30h] [rbp-D0h]
  __int64 *v118; // [rsp+38h] [rbp-C8h]
  unsigned int u; // [rsp+40h] [rbp-C0h]
  int v120; // [rsp+44h] [rbp-BCh]
  hkHistogram v121; // [rsp+48h] [rbp-B8h]
  int v122; // [rsp+60h] [rbp-A0h]
  int v123; // [rsp+64h] [rbp-9Ch]
  float lo; // [rsp+68h] [rbp-98h]
  __m128 *v125; // [rsp+70h] [rbp-90h]
  int v126; // [rsp+78h] [rbp-88h]
  int v127; // [rsp+80h] [rbp-80h]
  hkVector4f *v128; // [rsp+88h] [rbp-78h]
  float hi; // [rsp+90h] [rbp-70h]
  int v130; // [rsp+94h] [rbp-6Ch]
  int v131; // [rsp+98h] [rbp-68h]
  int v132; // [rsp+A0h] [rbp-60h]
  __int64 v133; // [rsp+A8h] [rbp-58h]
  __int64 v134; // [rsp+B0h] [rbp-50h]
  __m128i *v135; // [rsp+B8h] [rbp-48h]
  hkEntry t; // [rsp+C0h] [rbp-40h]
  hkEntry v137; // [rsp+D0h] [rbp-30h]
  __m128 v138; // [rsp+E0h] [rbp-20h]
  hkVector4f *v139; // [rsp+F0h] [rbp-10h]
  _BOOL8 v140; // [rsp+F8h] [rbp-8h]
  hkErrStream *v141; // [rsp+100h] [rbp+0h]
  hkVector4f b; // [rsp+110h] [rbp+10h]
  hkVector4f triangleNormal; // [rsp+120h] [rbp+20h]
  hkVector4f a; // [rsp+130h] [rbp+30h]
  hkVector4f c; // [rsp+140h] [rbp+40h]
  hkErrStream v146; // [rsp+150h] [rbp+50h]
  __m128 v147; // [rsp+170h] [rbp+70h]
  hkVector4f edgeNormal; // [rsp+1A0h] [rbp+A0h]
  __m128 v149; // [rsp+1B0h] [rbp+B0h]
  hkSimdFloat32 v150; // [rsp+1C0h] [rbp+C0h]
  __m128 v151; // [rsp+1D0h] [rbp+D0h]
  hkVector4f edgeOrtho; // [rsp+1E0h] [rbp+E0h]
  __m128 v153; // [rsp+1F0h] [rbp+F0h]
  __m128 v154; // [rsp+200h] [rbp+100h]
  hkVector4f normal; // [rsp+210h] [rbp+110h]
  hkVector4f v0; // [rsp+220h] [rbp+120h]
  __int128 v157; // [rsp+230h] [rbp+130h]
  __m128 v158; // [rsp+240h] [rbp+140h]
  __m128 v159; // [rsp+250h] [rbp+150h]
  hkSimdFloat32 tolerance; // [rsp+260h] [rbp+160h]
  hkVector4f v1; // [rsp+270h] [rbp+170h]
  char *v162; // [rsp+280h] [rbp+180h]
  int v163; // [rsp+288h] [rbp+188h]
  int v164; // [rsp+28Ch] [rbp+18Ch]
  char v165; // [rsp+290h] [rbp+190h]
  char buf; // [rsp+490h] [rbp+390h]
  char v167; // [rsp+690h] [rbp+590h]
  char v168; // [rsp+890h] [rbp+790h]
  hkTransformf *v169; // [rsp+B70h] [rbp+A70h]
  char v170; // [rsp+B78h] [rbp+A78h]
  hkArray<hkpMeshWeldingUtility::ShapeInfo,hkContainerHeapAllocator> *v171; // [rsp+B88h] [rbp+A88h]

  v171 = allShapes;
  v169 = meshTransform;
  v6 = mesh->m_collectionType.m_storage;
  v7 = allShapes;
  v8 = weldingType;
  v9 = mesh;
  if ( v6 == 3 || !v6 || (unsigned __int8)v6 >= 7u )
  {
    hkErrStream::hkErrStream(&v146, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v146.vfptr,
      "hkpShapeCollection must be a triangle collection that supports welding.");
    hkError::messageWarning(1062243434, &buf, "Util\\Welding\\hkpMeshWeldingUtility.cpp", 274);
    hkOstream::~hkOstream((hkOstream *)&v146.vfptr);
    return;
  }
  ((void (__fastcall *)(hkpShapeCollection *, _QWORD))mesh->vfptr[8].__first_virtual_table_function__)(
    mesh,
    (unsigned int)weldingType);
  if ( v8 != 6 )
  {
    v10 = (signed __int64)&v9->vfptr;
    v9->m_disableWelding.m_bool = 1;
    v11 = v9->vfptr->getFirstKey((hkpShapeContainer *)&v9->vfptr);
    u = v11;
    v140 = v8 != 5;
    while ( v11 != -1 )
    {
      v12 = (hkVector4f *)(*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v10 + 40i64))(
                            v10,
                            v11,
                            &v168);
      v13 = &v12->m_quad;
      v125 = &v12->m_quad;
      if ( v12[1].m_quad.m128_i8[0] != 2 )
        goto LABEL_74;
      v14 = &v12[5].m_quad;
      v15 = (signed __int64)&v12[3];
      v16 = 0;
      v117 = 0;
      v128 = v12 + 5;
      hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(v12 + 3, v12 + 4, v12 + 5, &normal);
      v132 = 925353388;
      v17 = 0;
      v122 = 0;
      v18 = (__m128i *)v15;
      v19 = _mm_shuffle_ps((__m128)0x3727C5ACu, (__m128)0x3727C5ACu, 0);
      v153 = v19;
      v135 = (__m128i *)v15;
      do
      {
        v121.m_entries.m_data = 0i64;
        v121.m_entries.m_size = 0;
        v121.m_entries.m_capacityAndFlags = 2147483648;
        v121.m_freeAngle = 0.0;
        if ( !weldOpenEdges )
          v121.m_freeAngle = 3.1415927;
        _mm_store_si128((__m128i *)&a, *v18);
        tolerance.m_real = v19;
        _mm_store_si128((__m128i *)&b, (__m128i)v13[(v17 + 1) % 3 + 3]);
        _mm_store_si128((__m128i *)&c, (__m128i)v13[(v17 + 2) % 3 + 3]);
        if ( (unsigned int)hkcdTriangleUtil::isDegenerate(&a, &b, &c, &tolerance) )
        {
          v121.m_entries.m_size = 0;
          if ( v121.m_entries.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v121.m_entries.m_data,
              12 * (v121.m_entries.m_capacityAndFlags & 0x3FFFFFFF));
        }
        else
        {
          v20 = 0;
          v170 = 0;
          v21 = 0;
          v120 = 0;
          if ( v7->m_size > 0 )
          {
            v22 = 0i64;
            v23 = (char *)((char *)&v146 - (char *)v169);
            v24 = &v169->m_translation.m_quad;
            v25 = *(__m128 *)_xmm;
            v134 = 0i64;
            v141 = (hkErrStream *)((char *)&v146 - (char *)v169);
            v139 = &v169->m_translation;
            v26 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 85);
            v27 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 0);
            v159 = v26;
            v149 = v27;
            v28 = _mm_shuffle_ps(normal.m_quad, normal.m_quad, 170);
            v151 = v28;
            _mm_store_si128((__m128i *)&v157, _mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
            while ( 1 )
            {
              v29 = v7->m_data;
              v30 = 3i64;
              v31 = v24;
              v32 = *(__int64 **)((char *)&v7->m_data->m_shape + v22);
              v118 = *(__int64 **)((char *)&v7->m_data->m_shape + v22);
              v33 = *(__m128 *)((char *)&v7->m_data->m_transform.m_rotation.m_col1.m_quad + v22);
              v34 = *(__m128 *)((char *)&v7->m_data->m_transform.m_rotation.m_col2.m_quad + v22);
              do
              {
                v35 = *v31;
                --v31;
                --v30;
                v36 = _mm_unpacklo_ps(*(__m128 *)((char *)&v29->m_transform.m_rotation.m_col0.m_quad + v22), v33);
                v37 = _mm_movelh_ps(v36, v34);
                *(__m128 *)((char *)v31 + (_QWORD)v23 + 16) = _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(
                                                                    _mm_shuffle_ps(_mm_movehl_ps(v37, v36), v34, 212),
                                                                    _mm_shuffle_ps(v35, v35, 85)),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v37)),
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps(v35, v35, 170),
                                                                  _mm_shuffle_ps(
                                                                    _mm_unpackhi_ps(
                                                                      *(__m128 *)((char *)&v29->m_transform.m_rotation.m_col0.m_quad
                                                                                + v22),
                                                                      v33),
                                                                    v34,
                                                                    228)));
              }
              while ( v30 >= 0 );
              v38 = *(__m128 *)((char *)&v29->m_transform.m_rotation.m_col2.m_quad + v22);
              v39 = _mm_sub_ps(*v24, *(__m128 *)((char *)&v29->m_transform.m_translation.m_quad + v22));
              v40 = _mm_unpacklo_ps(
                      *(__m128 *)((char *)&v29->m_transform.m_rotation.m_col0.m_quad + v22),
                      *(__m128 *)((char *)&v29->m_transform.m_rotation.m_col1.m_quad + v22));
              v41 = _mm_movelh_ps(v40, v38);
              v42 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(_mm_movehl_ps(v41, v40), v38, 212), _mm_shuffle_ps(v39, v39, 85)),
                        _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), v41)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          _mm_unpackhi_ps(
                            *(__m128 *)((char *)&v29->m_transform.m_rotation.m_col0.m_quad + v22),
                            *(__m128 *)((char *)&v29->m_transform.m_rotation.m_col1.m_quad + v22)),
                          v38,
                          228),
                        _mm_shuffle_ps(v39, v39, 170)));
              v158 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)&v146.vfptr, v27),
                         _mm_mul_ps(*(__m128 *)&v146.m_writer.m_pntr, v26)),
                       _mm_mul_ps(v147, v28));
              edgeNormal.m_quad = v158;
              v43 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(a.m_quad, a.m_quad, 85), *(__m128 *)&v146.m_writer.m_pntr),
                          _mm_mul_ps(_mm_shuffle_ps(a.m_quad, a.m_quad, 0), *(__m128 *)&v146.vfptr)),
                        _mm_mul_ps(_mm_shuffle_ps(a.m_quad, a.m_quad, 170), v147)),
                      v42);
              v0.m_quad = v43;
              v44 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 85), *(__m128 *)&v146.m_writer.m_pntr),
                          _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 0), *(__m128 *)&v146.vfptr)),
                        _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 170), v147)),
                      v42);
              v138 = v44;
              v1.m_quad = v44;
              v45 = _mm_sub_ps(v44, v43);
              v46 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(c.m_quad, c.m_quad, 85), *(__m128 *)&v146.m_writer.m_pntr),
                          _mm_mul_ps(_mm_shuffle_ps(c.m_quad, c.m_quad, 0), *(__m128 *)&v146.vfptr)),
                        _mm_mul_ps(_mm_shuffle_ps(c.m_quad, c.m_quad, 170), v147)),
                      v42);
              v47 = _mm_mul_ps(v45, v45);
              v154 = v46;
              v163 = 0;
              v164 = -2147483520;
              v162 = &v165;
              v48 = *v32;
              v49 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                      _mm_shuffle_ps(v47, v47, 170));
              v50 = _mm_rsqrt_ps(v49);
              v51 = _mm_mul_ps(
                      v45,
                      _mm_andnot_ps(
                        _mm_cmpleps(v49, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                          _mm_mul_ps(v25, v50))));
              v52 = _mm_max_ps(
                      _mm_max_ps(
                        _mm_xor_ps((__m128)_mm_load_si128((const __m128i *)&v157), (__m128)xmmword_141A712A0),
                        v43),
                      v44);
              *(__m128 *)&v146.vfptr = _mm_min_ps(_mm_min_ps((__m128)xmmword_141A712A0, v43), v44);
              *(__m128 *)&v146.m_writer.m_pntr = v52;
              (*(void (__fastcall **)(__int64 *, hkErrStream *, char **))(v48 + 136))(v32, &v146, &v162);
              v123 = 0;
              if ( v163 > 0 )
                break;
LABEL_58:
              v163 = 0;
              if ( v164 >= 0 )
                hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                  v162,
                  4 * v164);
              v27 = v149;
              v28 = v151;
              v23 = (char *)v141;
              v24 = &v139->m_quad;
              ++v21;
              v22 += 80i64;
              v120 = v21;
              v134 = v22;
              if ( v21 >= v7->m_size )
              {
                v20 = v170;
                v16 = v117;
                v17 = v122;
                goto LABEL_62;
              }
            }
            v53 = 0i64;
            v133 = 0i64;
            while ( 2 )
            {
              v54 = *(_DWORD *)&v162[v53];
              v55 = (*(__int64 (__fastcall **)(__int64 *))(*v32 + 112))(v32);
              v56 = (hkVector4f *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v55 + 40i64))(
                                    v55,
                                    v54,
                                    &v167);
              v57 = (hkpTriangleShape *)v56;
              if ( v56[1].m_quad.m128_i8[0] == 2 )
              {
                v58 = v56 + 3;
                v127 = 925353388;
                v150.m_real = _mm_shuffle_ps((__m128)0x3727C5ACu, (__m128)0x3727C5ACu, 0);
                if ( (unsigned int)hkcdTriangleUtil::isDegenerate(v56 + 3, v56 + 4, v56 + 5, &v150) )
                  goto LABEL_55;
                v59 = v58->m_quad;
                v131 = 981668463;
                v60 = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
                if ( (_mm_movemask_ps(
                        _mm_cmpltps(
                          (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v125[3], v59), 1u), 1u),
                          v60)) & 7) == 7
                  && (_mm_movemask_ps(
                        _mm_cmpltps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32((__m128i)_mm_sub_ps(v125[4], v57->m_vertexB.m_quad), 1u),
                                    1u),
                          v60)) & 7) == 7
                  && (_mm_movemask_ps(
                        _mm_cmpltps(
                          (__m128)_mm_srli_epi32(
                                    _mm_slli_epi32((__m128i)_mm_sub_ps(*v14, v57->m_vertexC.m_quad), 1u),
                                    1u),
                          v60)) & 7) == 7 )
                {
                  goto LABEL_55;
                }
                v61 = v57->m_vertexC.m_quad;
                v62 = v57->m_vertexB.m_quad;
                if ( ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(
                                                             _mm_slli_epi32((__m128i)_mm_sub_ps(v59, v44), 1u),
                                                             1u), v60)) & 7) == 7) | ((_mm_movemask_ps(
                                                                                         _mm_cmpltps(
                                                                                           (__m128)_mm_srli_epi32(
                                                                                                     _mm_slli_epi32((__m128i)_mm_sub_ps(v57->m_vertexB.m_quad, v44), 1u),
                                                                                                     1u),
                                                                                           v60)) & 7) == 7) | ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v57->m_vertexC.m_quad, v44), 1u), 1u), v60)) & 7) == 7)
                  && ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(
                                                             _mm_slli_epi32((__m128i)_mm_sub_ps(v59, v46), 1u),
                                                             1u), v60)) & 7) == 7) | ((_mm_movemask_ps(
                                                                                         _mm_cmpltps(
                                                                                           (__m128)_mm_srli_epi32(
                                                                                                     _mm_slli_epi32((__m128i)_mm_sub_ps(v62, v46), 1u),
                                                                                                     1u),
                                                                                           v60)) & 7) == 7) | ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v61, v46), 1u), 1u), v60)) & 7) == 7)
                  || ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(
                                                             _mm_slli_epi32((__m128i)_mm_sub_ps(v59, v46), 1u),
                                                             1u), v60)) & 7) == 7) | ((_mm_movemask_ps(
                                                                                         _mm_cmpltps(
                                                                                           (__m128)_mm_srli_epi32(
                                                                                                     _mm_slli_epi32((__m128i)_mm_sub_ps(v62, v46), 1u),
                                                                                                     1u),
                                                                                           v60)) & 7) == 7) | ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v61, v46), 1u), 1u), v60)) & 7) == 7)
                  && ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(
                                                             _mm_slli_epi32((__m128i)_mm_sub_ps(v59, v43), 1u),
                                                             1u), v60)) & 7) == 7) | ((_mm_movemask_ps(
                                                                                         _mm_cmpltps(
                                                                                           (__m128)_mm_srli_epi32(
                                                                                                     _mm_slli_epi32((__m128i)_mm_sub_ps(v62, v43), 1u),
                                                                                                     1u),
                                                                                           v60)) & 7) == 7) | ((_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v61, v43), 1u), 1u), v60)) & 7) == 7) )
                {
                  v32 = v118;
                }
                else
                {
                  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(
                    v58,
                    &v57->m_vertexB,
                    &v57->m_vertexC,
                    &triangleNormal);
                  v126 = 1028443341;
                  v63 = _mm_mul_ps(triangleNormal.m_quad, v51);
                  if ( COERCE_FLOAT((unsigned int)(2
                                                 * COERCE_SIGNED_INT(
                                                     (float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85))
                                                           + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170)))) >> 1) < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0)) )
                  {
                    v64 = _mm_shuffle_ps(v51, v51, 201);
                    v65 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v51), _mm_mul_ps(v158, v64));
                    v66 = _mm_shuffle_ps(v65, v65, 201);
                    v67 = _mm_mul_ps(v66, v66);
                    v68 = _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                            _mm_shuffle_ps(v67, v67, 170));
                    v69 = _mm_rsqrt_ps(v68);
                    edgeOrtho.m_quad = _mm_mul_ps(
                                         v66,
                                         _mm_andnot_ps(
                                           _mm_cmpleps(v68, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v69, v68), v69)),
                                             _mm_mul_ps(v25, v69))));
                    v70 = 1;
                    v71 = 0;
                    v72 = 3i64;
                    v73 = hkpMeshWeldingUtility::calcAngleForEdge(&edgeNormal, &edgeOrtho, &triangleNormal);
                    do
                    {
                      v74 = *(__m128 *)&(&v57->vfptr)[2 * (v70 % 3 + 3i64)];
                      v75 = _mm_sub_ps(*(__m128 *)&(&v57->vfptr)[2 * (v70 % 3 + 3i64)], v58->m_quad);
                      v76 = _mm_mul_ps(v75, v75);
                      v77 = _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
                              _mm_shuffle_ps(v76, v76, 170));
                      v78 = _mm_rsqrt_ps(v77);
                      v79 = _mm_mul_ps(
                              v75,
                              _mm_andnot_ps(
                                _mm_cmpleps(v77, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v78, v77), v78)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v78))));
                      v80 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v79, v79, 201), v51), _mm_mul_ps(v79, v64));
                      v81 = _mm_shuffle_ps(v80, v80, 201);
                      v82 = _mm_mul_ps(v81, v81);
                      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v82, v82, 170))) < 0.0000000099999991 )
                      {
                        v83 = _mm_sub_ps(v58->m_quad, v43);
                        v130 = 953267991;
                        LODWORD(v84) = (unsigned __int128)_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0);
                        v85 = _mm_sub_ps(v74, v43);
                        v86 = _mm_sub_ps(_mm_mul_ps(v83, v64), _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v51));
                        v87 = _mm_shuffle_ps(v86, v86, 201);
                        v88 = _mm_mul_ps(v87, v87);
                        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 170))) <= v84 )
                        {
                          v89 = _mm_sub_ps(_mm_mul_ps(v85, v64), _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v51));
                          v90 = _mm_shuffle_ps(v89, v89, 201);
                          v91 = _mm_mul_ps(v90, v90);
                          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 85))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 0)))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 170))) <= v84 )
                          {
                            v92 = _mm_mul_ps(v45, v45);
                            v93 = _mm_mul_ps(v45, v85);
                            v94 = _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                                    _mm_shuffle_ps(v92, v92, 170));
                            v92.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v94);
                            v95 = (float)(2.0 - (float)(v92.m128_f32[0] * v94.m128_f32[0])) * v92.m128_f32[0];
                            v96 = _mm_mul_ps(v45, v83);
                            v97 = fmax(
                                    fmin(
                                      (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 85))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 0)))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 170)))
                                    * v95,
                                      1.0),
                                    0.0);
                            v98 = fmax(
                                    fmin(
                                      (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v93, v93, 85))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v93, v93, 0)))
                                            + COERCE_FLOAT(_mm_shuffle_ps(v93, v93, 170)))
                                    * v95,
                                      1.0),
                                    0.0);
                            if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v98 - v97)) >> 1) > 0.1 )
                            {
                              if ( v140 && v98 > v97 )
                              {
                                hkErrStream::hkErrStream(&v146, &buf, 512);
                                v99 = hkOstream::operator<<(
                                        (hkOstream *)&v146.vfptr,
                                        "Inconsistent triangle winding between at least triangle ");
                                v100 = hkOstream::operator<<(v99, u, (int)v99);
                                v101 = hkOstream::operator<<(v100, " and triangle ");
                                v102 = hkOstream::operator<<(v101, v54, (int)v101);
                                hkOstream::operator<<(v102, ". One sided welding will not work.");
                                hkError::messageWarning(
                                  -1413843682,
                                  &buf,
                                  "Util\\Welding\\hkpMeshWeldingUtility.cpp",
                                  449);
                                hkOstream::~hkOstream((hkOstream *)&v146.vfptr);
                                v170 = 1;
                                ((void (__fastcall *)(hkpShapeCollection *, _QWORD, _QWORD))v9->vfptr[9].__vecDelDtor)(
                                  v9,
                                  v54,
                                  v57->m_weldingInfo | 0x8000u);
                              }
                              else
                              {
                                v103 = v121.m_entries.m_size;
                                v104 = v97;
                                v71 = 1;
                                v105 = fmin(v97, v98);
                                v106 = 0;
                                v107 = fmax(v104, v98);
                                v108 = 0i64;
                                if ( v121.m_entries.m_size > 0 )
                                {
                                  v109 = v121.m_entries.m_data;
                                  while ( v105 <= v109->m_lo )
                                  {
                                    ++v108;
                                    ++v106;
                                    ++v109;
                                    if ( v108 >= v121.m_entries.m_size )
                                      goto LABEL_43;
                                  }
                                  v103 = v106 + 1;
                                }
LABEL_43:
                                t.m_lo = v105;
                                t.m_hi = v107;
                                t.m_value = v73;
                                hkArrayBase<hkEntry>::_insertAt(
                                  (hkArrayBase<hkEntry> *)&v121.m_entries.m_data,
                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                                  v103,
                                  &t);
                              }
                            }
                          }
                        }
                      }
                      ++v70;
                      ++v58;
                      --v72;
                    }
                    while ( v72 );
                    v46 = v154;
                    if ( !v71 )
                    {
                      hkBuildClipPlanesForTriangle((hkVector4f *)&v146, v57, 0.050000001);
                      if ( hkClipEdgeAgainstPlanes(&v0, &v1, 5, (hkVector4f *)&v146, &lo, &hi) )
                      {
                        v110 = v121.m_entries.m_size;
                        v111 = 0;
                        v112 = 0i64;
                        if ( v121.m_entries.m_size > 0 )
                        {
                          v113 = v121.m_entries.m_data;
                          while ( lo <= v113->m_lo )
                          {
                            ++v112;
                            ++v111;
                            ++v113;
                            if ( v112 >= v121.m_entries.m_size )
                              goto LABEL_53;
                          }
                          v110 = v111 + 1;
                        }
LABEL_53:
                        v137.m_lo = lo;
                        v137.m_hi = hi;
                        v137.m_value = v73;
                        hkArrayBase<hkEntry>::_insertAt(
                          (hkArrayBase<hkEntry> *)&v121.m_entries.m_data,
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                          v110,
                          &v137);
                      }
                    }
                    v25 = *(__m128 *)_xmm;
                    v44 = v138;
                    v14 = &v128->m_quad;
                  }
LABEL_55:
                  v32 = v118;
                }
              }
              v53 = v133 + 4;
              ++v123;
              v133 += 4i64;
              if ( v123 >= v163 )
              {
                v26 = v159;
                v22 = v134;
                v21 = v120;
                v7 = v171;
                goto LABEL_58;
              }
              continue;
            }
          }
LABEL_62:
          if ( disableEdges && v20 )
          {
            v114 = 31;
          }
          else
          {
            v115 = hkHistogram::evaluate(&v121);
            v114 = hkpWeldingUtility::calcEdgeAngleBitcode(v115);
          }
          v117 = hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(v16, v17, v114);
          v16 = v117;
          if ( v20 )
          {
            v16 = v117 | 0x8000;
            v117 |= 0x8000u;
          }
          v121.m_entries.m_size = 0;
          if ( v121.m_entries.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v121.m_entries.m_data,
              12 * (v121.m_entries.m_capacityAndFlags & 0x3FFFFFFF));
          v13 = v125;
        }
        v19 = v153;
        ++v17;
        v18 = v135 + 1;
        v122 = v17;
        ++v135;
      }
      while ( v17 < 3 );
      v116 = v16;
      v11 = u;
      ((void (__fastcall *)(hkpShapeCollection *, _QWORD, __int64))v9->vfptr[9].__vecDelDtor)(v9, u, v116);
LABEL_74:
      v10 = (signed __int64)&v9->vfptr;
      v11 = v9->vfptr->getNextKey((hkpShapeContainer *)&v9->vfptr, v11);
      u = v11;
    }
  }
}

// File Line: 510
// RVA: 0x13203A0
hkResult *__fastcall hkpMeshWeldingUtility::testWindingConsistency(hkResult *result, hkVector4f *localVertex0, hkVector4f *localEdgeOrtho, hkVector4f *localNormal, hkpTriangleShape *adjacentTriangle, hkVector4f *adjacentNormal)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  __m128 v8; // xmm8
  hkVector4f *v9; // r10
  signed __int64 v10; // r9
  __m128 *v11; // r8
  __m128 v12; // xmm11
  float v13; // xmm6_4
  __m128 *v14; // rax
  signed __int64 v15; // rdx
  float v16; // xmm7_4
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  float v19; // ST08_4
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  float v23; // xmm2_4
  __m128 v24; // xmm8

  v6 = FLOAT_N3_40282e38;
  v7 = FLOAT_3_40282e38;
  v8 = localEdgeOrtho->m_quad;
  v9 = localNormal;
  v10 = 3i64;
  v11 = &adjacentTriangle->m_vertexA.m_quad;
  v12 = localVertex0->m_quad;
  v13 = FLOAT_N3_40282e38;
  v14 = &adjacentTriangle->m_vertexA.m_quad;
  v15 = 3i64;
  v16 = FLOAT_3_40282e38;
  do
  {
    v17 = *v14;
    ++v14;
    v18 = _mm_mul_ps(_mm_sub_ps(v17, v12), v8);
    v19 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170));
    v13 = fmaxf(v19, v13);
    v16 = fminf(v19, v16);
    --v15;
  }
  while ( v15 );
  if ( v13 <= 0.0099999998 && v16 >= 0.0099999998 )
    goto LABEL_19;
  if ( v13 > 0.2 && v16 < 0.2 )
    goto LABEL_15;
  v20 = _mm_mul_ps(v9->m_quad, adjacentNormal->m_quad);
  if ( (float)((float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v13)) >> 1) > COERCE_FLOAT((unsigned int)(2 * LODWORD(v16)) >> 1))
             * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170)))) >= 0.0 )
  {
LABEL_19:
    do
    {
      v21 = *v11;
      ++v11;
      v22 = _mm_mul_ps(_mm_sub_ps(v21, v12), v9->m_quad);
      v23 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170));
      v6 = fmaxf(v23, v6);
      v7 = fminf(v23, v7);
      --v10;
    }
    while ( v10 );
    if ( (v6 > 0.0099999998 || v7 < 0.0099999998) && (v6 <= 0.2 || v7 >= 0.2) )
    {
      v24 = _mm_mul_ps(v8, adjacentNormal->m_quad);
      if ( (float)((float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v6)) >> 1) > COERCE_FLOAT((unsigned int)(2 * LODWORD(v7)) >> 1))
                 * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170)))) > 0.0 )
        goto LABEL_8;
    }
LABEL_15:
    result->m_enum = 0;
    return result;
  }
LABEL_8:
  result->m_enum = 1;
  return result;
}

// File Line: 565
// RVA: 0x1320260
float __fastcall hkpMeshWeldingUtility::calcAngleForEdge(hkVector4f *edgeNormal, hkVector4f *edgeOrtho, hkVector4f *triangleNormal)
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
  v8 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v7), _mm_cmpltps(*(__m128 *)_xmm, v7));
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
  v12 = _mm_cmpleps((__m128)0i64, v6);
  v13 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v9, *(__m128 *)_xmm), *(__m128 *)_xmm), v11), v8),
          _mm_andnot_ps(v8, v11));
  LODWORD(result) = *(unsigned __int128 *)&_mm_andnot_ps(
                                             v12,
                                             _mm_add_ps(
                                               _mm_or_ps(_mm_and_ps(*(__m128 *)_xmm, v5), *(__m128 *)_xmm),
                                               v13)) | v13.m128_i32[0] & v12.m128_i32[0];
  return result;
}

// File Line: 576
// RVA: 0x13201D0
void __fastcall hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(hkVector4f *vertex0, hkVector4f *vertex1, hkVector4f *vertex2, hkVector4f *normal)
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
                       _mm_cmpleps(v9, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                         _mm_mul_ps(*(__m128 *)_xmm, v10))),
                     v7);
}

// File Line: 589
// RVA: 0x13201A0
__int64 __fastcall hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(unsigned __int16 combinedBitcode, int edgeIndex, int bitcode)
{
  return (bitcode << 5 * edgeIndex) | (unsigned int)(unsigned __int16)(combinedBitcode & ~(31 << 5 * edgeIndex));
}

// File Line: 603
// RVA: 0x1320180
__int64 __fastcall hkpMeshWeldingUtility::calcSingleEdgeBitcode(unsigned __int16 triangleEdgesBitcode, int edgeIndex)
{
  return ((unsigned int)triangleEdgesBitcode >> 5 * edgeIndex) & 0x1F;
}

// File Line: 619
// RVA: 0x1320EA0
hkResult *__fastcall hkpMeshWeldingUtility::calcWeldingInfoForTriangle(hkResult *result, unsigned int shapeKey, hkpBvTreeShape *bvTreeShape, hkpMeshWeldingUtility::WindingConsistency testConsistency, unsigned __int16 *info)
{
  hkResult *v5; // r14
  hkpMeshWeldingUtility::WindingConsistency v6; // er13
  hkpBvTreeShape *v7; // r15
  unsigned int v8; // er12
  __int64 v9; // rax
  hkVector4f *v10; // rax
  hkpTriangleShape *v11; // rbp
  signed int v12; // ebx
  unsigned __int16 *v13; // rax
  int edgeIndex; // edi
  hkResult resulta; // [rsp+40h] [rbp-248h]
  hkSimdFloat32 tolerance; // [rsp+50h] [rbp-238h]
  char v18; // [rsp+60h] [rbp-228h]
  float combinedBitcodesOut; // [rsp+2A0h] [rbp+18h]

  v5 = result;
  v6 = testConsistency;
  v7 = bvTreeShape;
  v8 = shapeKey;
  v9 = ((__int64 (__fastcall *)(hkpBvTreeShape *))bvTreeShape->vfptr[7].__vecDelDtor)(bvTreeShape);
  v10 = (hkVector4f *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v9 + 40i64))(v9, v8, &v18);
  combinedBitcodesOut = hkDefaultTriangleDegeneracyTolerance;
  v11 = (hkpTriangleShape *)v10;
  tolerance.m_real = _mm_shuffle_ps(
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       0);
  v12 = 0;
  if ( (unsigned int)hkcdTriangleUtil::isDegenerate(v10 + 3, v10 + 4, v10 + 5, &tolerance) )
  {
    v13 = info;
    v5->m_enum = 1;
    *v13 = 0;
  }
  else
  {
    LOWORD(combinedBitcodesOut) = 0;
    edgeIndex = 0;
    do
    {
      if ( hkpMeshWeldingUtility::calcBitcodeForTriangleEdge(
             &resulta,
             v7,
             v11,
             v8,
             edgeIndex,
             v6,
             (__int16 *)&combinedBitcodesOut)->m_enum == 1 )
        v12 = 1;
      ++edgeIndex;
    }
    while ( edgeIndex < 3 );
    *info = LOWORD(combinedBitcodesOut);
    v5->m_enum = v12;
  }
  return v5;
}

// File Line: 654
// RVA: 0x1320FD0
hkBool *__fastcall hkpMeshWeldingUtility::isTriangleWindingValid(hkBool *result, unsigned int shapeKey, hkpBvTreeShape *bvTreeShape)
{
  hkBool *v3; // rdi
  hkpBvTreeShape *v4; // rsi
  unsigned int v5; // ebp
  __int64 v6; // rax
  hkpTriangleShape *v7; // r14
  int edgeIndex; // ebx
  __int64 v9; // r8
  char v11; // [rsp+40h] [rbp-228h]
  char v12; // [rsp+270h] [rbp+8h]
  __int16 combinedBitcodesOut; // [rsp+280h] [rbp+18h]
  hkResult resulta; // [rsp+288h] [rbp+20h]

  v3 = result;
  v4 = bvTreeShape;
  v5 = shapeKey;
  v6 = ((__int64 (__fastcall *)(hkpBvTreeShape *))bvTreeShape->vfptr[7].__vecDelDtor)(bvTreeShape);
  v7 = (hkpTriangleShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v6 + 40i64))(v6, v5, &v11);
  ((void (__fastcall *)(hkError *, char *, signed __int64))hkSingleton<hkError>::s_instance->vfptr[2].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    &v12,
    4271404318i64);
  if ( v12 )
    ((void (__fastcall *)(hkError *, signed __int64, _QWORD))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
      hkSingleton<hkError>::s_instance,
      4271404318i64,
      0i64);
  v3->m_bool = 1;
  combinedBitcodesOut = 0;
  edgeIndex = 0;
  while ( hkpMeshWeldingUtility::calcBitcodeForTriangleEdge(&resulta, v4, v7, v5, edgeIndex, 0, &combinedBitcodesOut)->m_enum != 1 )
  {
    if ( ++edgeIndex >= 3 )
      goto LABEL_8;
  }
  v3->m_bool = 0;
LABEL_8:
  if ( v12 )
  {
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(hkError *, signed __int64, __int64))hkSingleton<hkError>::s_instance->vfptr[2].__vecDelDtor)(
      hkSingleton<hkError>::s_instance,
      4271404318i64,
      v9);
  }
  return v3;
}

// File Line: 694
// RVA: 0x13210E0
hkResult *__fastcall hkpMeshWeldingUtility::calcBitcodeForTriangleEdge(hkResult *result, hkpBvTreeShape *bvTreeShape, hkpTriangleShape *triangleShape, unsigned int triangleShapeKey, __int64 edgeIndex, hkpMeshWeldingUtility::WindingConsistency testConsistency, __int16 *combinedBitcodesOut)
{
  hkpBvTreeShape *v7; // r12
  hkResult *v8; // rbx
  unsigned int v9; // er13
  __m128 v10; // xmm1
  hkBaseObjectVtbl *v11; // rax
  char v12; // si
  __int64 v13; // rdi
  unsigned int v14; // ebx
  __int64 v15; // rax
  hkVector4f *v16; // rax
  hkOstream *v17; // rax
  hkOstream *v18; // rax
  hkOstream *v19; // rax
  hkOstream *v20; // rax
  int v21; // eax
  int v22; // er8
  hkErrStream v24; // [rsp+30h] [rbp-C0h]
  hkVector4f vertexArrayOut; // [rsp+50h] [rbp-A0h]
  char *v26; // [rsp+A0h] [rbp-50h]
  int v27; // [rsp+A8h] [rbp-48h]
  int v28; // [rsp+ACh] [rbp-44h]
  char v29; // [rsp+B0h] [rbp-40h]
  char buf; // [rsp+2B0h] [rbp+1C0h]
  hkResult *vars0; // [rsp+4F0h] [rbp+400h]
  void *orderedEdgeVerticesOnTriangle1; // [rsp+4F8h] [rbp+408h]
  hkVector4f *vertices0; // [rsp+500h] [rbp+410h]
  int v34; // [rsp+510h] [rbp+420h]
  int v35; // [rsp+518h] [rbp+428h]

  v7 = bvTreeShape;
  v8 = result;
  v26 = &v29;
  vertices0 = &triangleShape->m_vertexA;
  v9 = triangleShapeKey;
  v27 = 0;
  v28 = -2147483520;
  v10 = _mm_add_ps((__m128)_xmm, *(&triangleShape->m_vertexA.m_quad + v34 % 3));
  v11 = bvTreeShape->vfptr;
  *(__m128 *)&v24.vfptr = _mm_add_ps((__m128)_xmm, *(&triangleShape->m_vertexA.m_quad + v34 % 3));
  *(__m128 *)&v24.m_writer.m_pntr = v10;
  ((void (__fastcall *)(hkpBvTreeShape *, hkErrStream *, char **))v11[8].__first_virtual_table_function__)(
    bvTreeShape,
    &v24,
    &v26);
  v12 = 1;
  v13 = v27 - 1;
  if ( v27 - 1 >= 0 )
  {
    do
    {
      v14 = *(_DWORD *)&v26[4 * v13];
      if ( v14 != v9 )
      {
        v15 = ((__int64 (__fastcall *)(hkpBvTreeShape *))v7->vfptr[7].__vecDelDtor)(v7);
        v16 = (hkVector4f *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v15 + 40i64))(
                              v15,
                              v14,
                              &buf);
        if ( v16[1].m_quad.m128_i8[0] == 2
          && hkpMeshWeldingUtility::createSingularVertexArray(
               vertices0,
               v16 + 3,
               v34,
               &vertexArrayOut,
               (int *)&orderedEdgeVerticesOnTriangle1) == 4 )
        {
          if ( v35 && (_DWORD)orderedEdgeVerticesOnTriangle1 != (HIDWORD(orderedEdgeVerticesOnTriangle1) + 1) % 3 )
          {
            if ( v12 )
            {
              hkErrStream::hkErrStream(&v24, &buf, 512);
              v17 = hkOstream::operator<<(
                      (hkOstream *)&v24.vfptr,
                      "Inconsistant triangle winding between at least triangle ");
              v18 = hkOstream::operator<<(v17, v9, (int)v17);
              v19 = hkOstream::operator<<(v18, " and triangle ");
              v20 = hkOstream::operator<<(v19, v14, (int)v19);
              hkOstream::operator<<(v20, ". One sided welding will not work.");
              hkError::messageWarning(-1413843682, &buf, "Util\\Welding\\hkpMeshWeldingUtility.cpp", 773);
              hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
            }
            v12 = 0;
          }
          v21 = hkpMeshWeldingUtility::calcEdgeAngleBitcode(&vertexArrayOut);
          *(_WORD *)edgeIndex = hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(*(_WORD *)edgeIndex, v34, v21);
        }
      }
      --v13;
    }
    while ( v13 >= 0 );
    v8 = vars0;
  }
  v22 = v28;
  v27 = 0;
  v8->m_enum = v12 == 0;
  if ( v22 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v26,
      4 * v22);
  return v8;
}

// File Line: 805
// RVA: 0x13213A0
__int64 __fastcall hkpMeshWeldingUtility::createSingularVertexArray(hkVector4f *vertices0, hkVector4f *vertices1, int edgeIndex, hkVector4f *vertexArrayOut, int *orderedEdgeVerticesOnTriangle1)
{
  hkVector4f *v5; // r11
  hkVector4f *v6; // rbx
  int v7; // er10
  hkVector4f *v8; // rdi
  __int64 v9; // rcx
  hkVector4f *v10; // r8
  int v11; // edx
  unsigned int v12; // er9
  __m128 v13; // xmm3
  signed __int64 v14; // rax
  __m128 *v15; // rcx
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  hkVector4f *v18; // rax

  v5 = vertices0;
  v6 = vertices1;
  v7 = edgeIndex;
  v8 = vertexArrayOut;
  *vertexArrayOut = vertices0[edgeIndex % 3];
  v9 = (edgeIndex + 1) % 3;
  v10 = vertexArrayOut + 3;
  vertexArrayOut[1] = v5[v9];
  v11 = 0;
  vertexArrayOut[2] = v5[(v7 + 2) % 3];
  v12 = 3;
  do
  {
    v13 = v6->m_quad;
    v14 = 0i64;
    v15 = &v8->m_quad;
    while ( 1 )
    {
      v16 = _mm_sub_ps(*v15, v13);
      v17 = _mm_mul_ps(v16, v16);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170))) == 0.0 )
        break;
      ++v14;
      ++v15;
      if ( v14 >= 2 )
      {
        v18 = v10;
        ++v12;
        ++v10;
        *v18 = (hkVector4f)v13;
        goto LABEL_7;
      }
    }
    orderedEdgeVerticesOnTriangle1[v14] = v11;
LABEL_7:
    ++v11;
    ++v6;
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
  float cosAngleOut; // [rsp+38h] [rbp+10h]
  float sinAngleOut; // [rsp+40h] [rbp+18h]

  v1 = hkpMeshWeldingUtility::calcAngleFromVertices(vertices, &sinAngleOut, &cosAngleOut);
  result = 0i64;
  while ( 1 )
  {
    v3 = (float)((float)(signed int)result * 0.20943952) - 3.1415927;
    if ( v1 <= v3 )
      break;
    result = (unsigned int)(result + 1);
    if ( (signed int)result >= 31 )
      return result;
  }
  if ( v1 > 0.0 && v1 != v3 )
    result = (unsigned int)(result - 1);
  return result;
}

// File Line: 890
// RVA: 0x1321530
float __fastcall hkpMeshWeldingUtility::calcAngleFromVertices(hkVector4f *vertices, float *sinAngleOut, float *cosAngleOut)
{
  float *v3; // rbp
  float *v4; // rsi
  hkVector4f *v5; // rdi
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
  __m128 v25; // [rsp+20h] [rbp-68h]
  hkVector4f normal; // [rsp+30h] [rbp-58h]

  v3 = cosAngleOut;
  v4 = sinAngleOut;
  v5 = vertices;
  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(vertices, vertices + 1, vertices + 2, (hkVector4f *)&v25);
  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(v5 + 1, v5, v5 + 3, &normal);
  v6 = _mm_sub_ps(v5[1].m_quad, v5->m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_mul_ps(
          v6,
          _mm_andnot_ps(
            _mm_cmpleps(v8, (__m128)0i64),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9))));
  v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v25));
  v12 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), normal.m_quad);
  v13 = _mm_mul_ps(normal.m_quad, v25);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v16 = _mm_rcp_ps(v15);
  v17 = _mm_mul_ps(v16, v14);
  v18 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v17), _mm_cmpltps(*(__m128 *)_xmm, v17));
  v19 = _mm_or_ps(_mm_and_ps(_mm_rcp_ps(v17), v18), _mm_andnot_ps(v18, v17));
  v20 = _mm_mul_ps(v19, v19);
  v21 = _mm_cmpleps((__m128)0i64, v16);
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
  *v4 = v14.m128_f32[0];
  *v3 = v15.m128_f32[0];
  v23 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v19, *(__m128 *)_xmm), *(__m128 *)_xmm), v22), v18),
          _mm_andnot_ps(v18, v22));
  LODWORD(result) = v23.m128_i32[0] & v21.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                 v21,
                                                                                 _mm_add_ps(
                                                                                   _mm_or_ps(
                                                                                     _mm_and_ps(v14, *(__m128 *)_xmm),
                                                                                     *(__m128 *)_xmm),
                                                                                   v23));
  return result;
}

// File Line: 938
// RVA: 0x1320620
__int64 __fastcall hkpMeshWeldingUtility::computeTriangleWeldingInfo(hkVector4f *triangle, hkVector4f *neighbors, int numNeighbors, hkBool weldOpenEdges, float tolerance)
{
  __int64 v5; // rbx
  hkVector4f *v6; // r13
  hkVector4f *v7; // r12
  hkVector4f *v8; // rsi
  float v9; // xmm12_4
  float padding; // xmm7_4
  hkVector4f *v11; // r13
  __int64 v12; // rdi
  __m128 v13; // xmm11
  signed __int64 v14; // rbx
  signed int v15; // esi
  __m128 v16; // xmm13
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
  int *v31; // r9
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
  float lo; // [rsp+40h] [rbp-C0h]
  float hi; // [rsp+44h] [rbp-BCh]
  float v45; // [rsp+48h] [rbp-B8h]
  int v46; // [rsp+50h] [rbp-B0h]
  void *v47; // [rsp+58h] [rbp-A8h]
  int v48; // [rsp+60h] [rbp-A0h]
  int v49; // [rsp+64h] [rbp-9Ch]
  int v50; // [rsp+68h] [rbp-98h]
  void *v51; // [rsp+70h] [rbp-90h]
  int v52; // [rsp+78h] [rbp-88h]
  int v53; // [rsp+7Ch] [rbp-84h]
  __int64 v54; // [rsp+80h] [rbp-80h]
  int v55; // [rsp+88h] [rbp-78h]
  void *v56; // [rsp+90h] [rbp-70h]
  int v57; // [rsp+98h] [rbp-68h]
  int v58; // [rsp+9Ch] [rbp-64h]
  hkEntry t; // [rsp+A0h] [rbp-60h]
  hkSimdFloat32 v60; // [rsp+B0h] [rbp-50h]
  hkVector4f normal; // [rsp+C0h] [rbp-40h]
  int *v62; // [rsp+D0h] [rbp-30h]
  int *v63; // [rsp+D8h] [rbp-28h]
  int *v64; // [rsp+E0h] [rbp-20h]
  hkSimdFloat32 v65; // [rsp+F0h] [rbp-10h]
  hkVector4f edgeOrtho; // [rsp+100h] [rbp+0h]
  float result; // [rsp+1E0h] [rbp+E0h]
  char v68; // [rsp+1E8h] [rbp+E8h]

  v68 = weldOpenEdges.m_bool;
  v5 = (unsigned int)numNeighbors;
  v6 = neighbors;
  v7 = triangle;
  if ( !numNeighbors )
    return 0i64;
  v8 = triangle + 1;
  result = hkDefaultTriangleDegeneracyTolerance;
  v60.m_real = _mm_shuffle_ps(
                 (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                 (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                 0);
  if ( (unsigned int)hkcdTriangleUtil::isDegenerate(triangle, triangle + 1, triangle + 2, &v60) )
    return 0i64;
  hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(v7, v8, v7 + 2, (hkVector4f *)&v60);
  v56 = 0i64;
  v57 = 0;
  v58 = 2147483648;
  v55 = 0;
  if ( !v68 )
    v55 = 1078530011;
  v47 = 0i64;
  v48 = 0;
  v49 = 2147483648;
  v46 = 0;
  if ( !v68 )
    v46 = 1078530011;
  v51 = 0i64;
  v52 = 0;
  v53 = 2147483648;
  v50 = 0;
  if ( !v68 )
    v50 = 1078530011;
  v62 = &v55;
  v63 = &v46;
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  v64 = &v50;
  if ( (signed int)v5 > 0 )
  {
    padding = tolerance;
    v11 = v6 + 1;
    v12 = v5;
    v54 = v5;
    v13 = v60.m_real;
    do
    {
      v45 = hkDefaultTriangleDegeneracyTolerance;
      v65.m_real = _mm_shuffle_ps(
                     (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                     (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                     0);
      if ( !(unsigned int)hkcdTriangleUtil::isDegenerate(v11 - 1, v11, v11 + 1, &v65) )
      {
        hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal(v11 - 1, v11, v11 + 1, &normal);
        v14 = 0i64;
        v15 = 1;
        v16 = normal.m_quad;
        v17 = v7;
        do
        {
          v18 = &v7[v15 % 3];
          v19 = _mm_sub_ps(v18->m_quad, v17->m_quad);
          v20 = _mm_mul_ps(v19, v19);
          v21 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                  _mm_shuffle_ps(v20, v20, 170));
          v22 = _mm_rsqrt_ps(v21);
          v23 = _mm_mul_ps(
                  v19,
                  _mm_andnot_ps(
                    _mm_cmpleps(v21, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                      _mm_mul_ps(*(__m128 *)_xmm, v22))));
          v24 = _mm_mul_ps(v16, v23);
          if ( COERCE_FLOAT((unsigned int)(2
                                         * COERCE_SIGNED_INT(
                                             (float)(COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 85))
                                                   + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 0)))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v24, v24, 170)))) >> 1) < v9 )
          {
            lo = 0.0;
            hi = 1.0;
            if ( hkpMeshWeldingUtility::clipLineAgainstTriangle(
                   (hkBool *)&result,
                   v17,
                   v18,
                   v11 - 1,
                   &normal,
                   padding,
                   &lo,
                   &hi)->m_bool )
            {
              v25 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v23),
                      _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v13));
              v26 = _mm_shuffle_ps(v25, v25, 201);
              v27 = _mm_mul_ps(v26, v26);
              v28 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                      _mm_shuffle_ps(v27, v27, 170));
              v29 = _mm_rsqrt_ps(v28);
              edgeOrtho.m_quad = _mm_mul_ps(
                                   v26,
                                   _mm_andnot_ps(
                                     _mm_cmpleps(v28, (__m128)0i64),
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                                       _mm_mul_ps(*(__m128 *)_xmm, v29))));
              v30 = hkpMeshWeldingUtility::calcAngleForEdge((hkVector4f *)&v60, &edgeOrtho, &normal);
              v31 = (&v62)[v14];
              v32 = v31[4];
              v33 = 0;
              v34 = 0i64;
              if ( (signed int)v32 > 0 )
              {
                v35 = (float *)*((_QWORD *)v31 + 1);
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
              t.m_hi = hi;
              t.m_value = v30;
              hkArrayBase<hkEntry>::_insertAt(
                (hkArrayBase<hkEntry> *)(v31 + 2),
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                v32,
                &t);
            }
          }
          ++v14;
          ++v15;
          ++v17;
        }
        while ( v14 < 3 );
        v12 = v54;
      }
      v11 += 3;
      v54 = --v12;
    }
    while ( v12 );
  }
  v36 = 0;
  v37 = 0;
  v38 = (hkHistogram **)&v62;
  do
  {
    v39 = hkHistogram::evaluate(*v38);
    v40 = hkpWeldingUtility::calcEdgeAngleBitcode(v39);
    v41 = hkpMeshWeldingUtility::modifyCombinedEdgesBitcode(v36, v37++, v40);
    ++v38;
    v36 = v41;
  }
  while ( v37 < 3 );
  v52 = 0;
  if ( v53 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v51,
      12 * (v53 & 0x3FFFFFFF));
  v51 = 0i64;
  v53 = 2147483648;
  v48 = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v47,
      12 * (v49 & 0x3FFFFFFF));
  v47 = 0i64;
  v49 = 2147483648;
  v57 = 0;
  if ( v58 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v56,
      12 * (v58 & 0x3FFFFFFF));
  return v36;
});
  v47 = 0i64;
  v49 = 2147483648;
  v57 = 0;
 

// File Line: 1016
// RVA: 0x1320B70
hkBool *__fastcall hkpMeshWeldingUtility::clipLineAgainstTriangle(hkBool *result, hkVector4f *v0, hkVector4f *v1, hkVector4f *vertices, hkVector4f *normal, float padding, float *lo, float *hi)
{
  __m128 v8; // xmm7
  hkVector4f *v9; // r10
  hkVector4f *v10; // rsi
  char v11; // bl
  hkVector4f *v12; // r9
  __m128 v13; // xmm9
  signed int v14; // er8
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

  v8 = v0->m_quad;
  v9 = vertices;
  v10 = v1;
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
      v17 = _mm_mul_ps(v9->m_quad, normal->m_quad);
    }
    else if ( v14 == -1 )
    {
      v16 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), normal->m_quad);
      v17 = _mm_mul_ps(v9->m_quad, v16);
    }
    else
    {
      v18 = _mm_sub_ps(v9[(v14 + 1) % 3].m_quad, v12->m_quad);
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
                _mm_cmpleps(v22, (__m128)0i64),
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
    v25 = _mm_mul_ps(v8, v16);
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
                _mm_sub_ps(v13, v8),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v31, v30)), v31), v28)),
              v8);
      if ( v28.m128_f32[0] <= 0.0 )
        v13 = v32;
      else
        v8 = v32;
      v11 = 1;
    }
    ++v14;
    ++v12;
  }
  while ( v14 < 3 );
  if ( v11 )
  {
    v33 = _mm_sub_ps(v10->m_quad, v0->m_quad);
    v34 = _mm_mul_ps(_mm_sub_ps(v8, v0->m_quad), v33);
    v35 = _mm_mul_ps(_mm_sub_ps(v13, v0->m_quad), v33);
    v36 = _mm_mul_ps(v33, v33);
    v37 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
            _mm_shuffle_ps(v36, v36, 170));
    LODWORD(v38) = (unsigned __int128)_mm_rcp_ps(v37);
    v36.m128_f32[0] = (float)(2.0 - (float)(v38 * v37.m128_f32[0])) * v38;
    *lo = v36.m128_f32[0]
        * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170)));
    *hi = v36.m128_f32[0]
        * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170)));
  }
  else
  {
    *lo = 0.0;
    *hi = 1.0;
  }
  result->m_bool = 1;
  return result;
}

