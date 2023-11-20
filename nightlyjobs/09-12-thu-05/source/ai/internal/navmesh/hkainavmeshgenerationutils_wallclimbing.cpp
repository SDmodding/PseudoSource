// File Line: 62
// RVA: 0xB98280
__int64 __fastcall pointInTriangle(hkVector4f *point, hkVector4f *vertexA, hkVector4f *vertexB, hkVector4f *vertexC, hkSimdFloat32 *tolerance)
{
  __m128 v5; // xmm1
  signed int v6; // er11
  hkVector4f *v7; // r10
  int v8; // er8
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 v11; // xmm14
  __m128 v12; // xmm7
  signed int v13; // ecx
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  float v21; // xmm2_4
  signed int v22; // eax
  __m128i v24; // xmm1
  signed __int64 v25; // r10
  __m128 v26; // xmm9
  __m128 v27; // xmm0
  __int128 *v28; // r9
  __m128 v29; // xmm8
  __m128 v30; // xmm10
  signed int v31; // ecx
  int v32; // edx
  unsigned int v33; // eax
  __m128 v34; // xmm1
  __m128 v35; // xmm6
  __m128 v36; // xmm6
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm6
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm2
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm1
  __int128 v47; // [rsp+0h] [rbp-C8h]
  __int128 v48; // [rsp+10h] [rbp-B8h]
  __int128 v49; // [rsp+20h] [rbp-A8h]

  v5 = vertexB->m_quad;
  v6 = 1;
  v7 = vertexB;
  v8 = 0;
  v9 = _mm_sub_ps(v5, vertexA->m_quad);
  v10 = _mm_sub_ps(vertexC->m_quad, vertexA->m_quad);
  v11 = point->m_quad;
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10));
  v13 = 0;
  v14 = _mm_shuffle_ps(v12, v12, 201);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  v18 = _mm_mul_ps(
          v14,
          _mm_andnot_ps(
            _mm_cmpleps(v16, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
              _mm_mul_ps(*(__m128 *)_xmm, v17))));
  v19 = _mm_mul_ps(vertexA->m_quad, v18);
  v20 = _mm_mul_ps(v11, v18);
  v21 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170)))
      - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170)));
  if ( v21 < (float)(0.0 - tolerance->m_real.m128_f32[0]) )
    v13 = 1;
  v22 = 0;
  if ( v21 > tolerance->m_real.m128_f32[0] )
    v22 = 1;
  if ( v22 | v13 )
    return 0i64;
  v24 = (__m128i)v7->m_quad;
  v25 = 3i64;
  v26 = *(__m128 *)&hkVector4fComparison_maskToComparison_102[60];
  _mm_store_si128((__m128i *)&v47, (__m128i)vertexA->m_quad);
  v27 = vertexC->m_quad;
  v28 = &v47;
  v29 = _mm_shuffle_ps(v18, v18, 201);
  _mm_store_si128((__m128i *)&v49, (__m128i)v27);
  _mm_store_si128((__m128i *)&v48, v24);
  v30 = 0i64;
  do
  {
    v31 = v6;
    ++v28;
    v32 = (unsigned __int64)(1431655766i64 * v6) >> 32;
    v33 = (unsigned __int64)(1431655766i64 * v6++) >> 32;
    v34 = _mm_sub_ps((__m128)*(&v47 + (signed int)(v31 - 3 * ((v33 >> 31) + v32))), (__m128)*(v28 - 1));
    v35 = _mm_sub_ps(_mm_mul_ps(v29, v34), _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v18));
    v36 = _mm_shuffle_ps(v35, v35, 201);
    v37 = _mm_mul_ps(v36, v36);
    v38 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
            _mm_shuffle_ps(v37, v37, 170));
    v39 = _mm_rsqrt_ps(v38);
    v40 = _mm_mul_ps(
            v36,
            _mm_andnot_ps(
              _mm_cmpleps(v38, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                _mm_mul_ps(*(__m128 *)_xmm, v39))));
    v41 = _mm_mul_ps(v40, (__m128)*(v28 - 1));
    v42 = _mm_shuffle_ps(
            v40,
            _mm_unpackhi_ps(
              v40,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                  _mm_shuffle_ps(v41, v41, 170)))),
            196);
    v43 = _mm_mul_ps(v11, v42);
    v44 = _mm_shuffle_ps(v43, _mm_unpackhi_ps(v43, v42), 196);
    v45 = _mm_add_ps(_mm_shuffle_ps(v44, v44, 78), v44);
    v46 = _mm_cmpltps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v45, v45, 177), v45));
    v26 = _mm_and_ps(v26, v46);
    v30 = _mm_or_ps(v30, v46);
    --v25;
  }
  while ( v25 );
  LOBYTE(v8) = _mm_movemask_ps(v30) == 0;
  return v8 | (unsigned int)_mm_movemask_ps(v26);
}

// File Line: 115
// RVA: 0xB985B0
void __fastcall hkaiTriangleSetAabbTester::init(hkaiTriangleSetAabbTester *this)
{
  unsigned int v1; // edi
  hkaiTriangleSetAabbTester *v2; // rbx
  int v3; // edx
  __int64 v4; // rbp
  __int64 v5; // r14
  signed __int64 v6; // rsi
  int *v7; // rcx
  hkVector4f *v8; // rdx
  signed __int64 v9; // r8
  signed __int64 v10; // rax
  signed __int64 v11; // r9
  hkAabb aabb; // [rsp+20h] [rbp-38h]

  v1 = 0;
  v2 = this;
  v3 = this->m_tris->m_size / 3;
  v4 = v3;
  if ( v3 > 0 )
  {
    v5 = 0i64;
    v6 = 2i64;
    do
    {
      v7 = v2->m_tris->m_data;
      v8 = v2->m_vertices->m_data;
      v9 = v7[v5];
      v10 = v7[v6 - 1];
      v11 = v7[v6];
      aabb.m_min.m_quad = _mm_min_ps(v8[v7[v5]].m_quad, v8[v7[v6 - 1]].m_quad);
      aabb.m_max.m_quad = _mm_max_ps(v8[v9].m_quad, v8[v10].m_quad);
      aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v8[v11].m_quad);
      aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v8[v11].m_quad);
      hkcdDynamicAabbTree::insert(&v2->m_tree, &aabb, v1++);
      v5 += 3i64;
      v6 += 3i64;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 143
// RVA: 0xB98680
signed __int64 __fastcall hkaiTriangleSetAabbTester::AabbCollector::processLeaf(hkaiTriangleSetAabbTester::AabbCollector *this, unsigned int leafKey, hkAabb *leafAabb)
{
  signed int v3; // er8
  hkaiTriangleSetAabbTester::AabbCollector *v4; // rbx
  int *v5; // r9
  unsigned int v6; // edi
  hkVector4f v7; // xmm0
  hkVector4f *v8; // r10
  __int64 v9; // rcx
  hkArray<int,hkContainerTempAllocator> *v10; // rbx

  v3 = 3 * leafKey;
  v4 = this;
  v5 = this->m_tris->m_data;
  v6 = leafKey;
  v7.m_quad = (__m128)this->m_queryAabb.m_min;
  v8 = this->m_vertices->m_data;
  v9 = (signed int)(3 * leafKey + 2);
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(
              _mm_min_ps(_mm_min_ps(v8[v5[v3]].m_quad, v8[v5[v3 + 1]].m_quad), v8[v5[v9]].m_quad),
              v4->m_queryAabb.m_max.m_quad),
            _mm_cmpleps(v7.m_quad, _mm_max_ps(_mm_max_ps(v8[v5[v3]].m_quad, v8[v5[v3 + 1]].m_quad), v8[v5[v9]].m_quad)))) & 7) == 7 )
  {
    v10 = v4->m_hits;
    if ( v10->m_size == (v10->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v10, 4);
    v10->m_data[v10->m_size++] = v6;
  }
  return 1i64;
}

// File Line: 185
// RVA: 0xB98150
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(hkVector4f *axis, hkVector4f *v0, hkVector4f *v1, hkVector4f *v2, hkSimdFloat32 *iminOut, hkSimdFloat32 *imaxOut)
{
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm1

  v6 = _mm_mul_ps(v1->m_quad, axis->m_quad);
  v7 = _mm_mul_ps(v0->m_quad, axis->m_quad);
  v8 = v7;
  v9 = _mm_unpackhi_ps(v7, v6);
  v10 = _mm_mul_ps(v2->m_quad, axis->m_quad);
  v11 = _mm_unpacklo_ps(v8, v6);
  v12 = _mm_movelh_ps(v11, v10);
  v13 = _mm_add_ps(_mm_shuffle_ps(v9, v10, 228), _mm_add_ps(v12, _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v10, 212)));
  v14 = _mm_shuffle_ps(v13, v13, 85);
  v15 = _mm_shuffle_ps(v13, v13, 0);
  v16 = _mm_shuffle_ps(v13, v13, 170);
  iminOut->m_real = _mm_min_ps(v16, _mm_min_ps(v14, v15));
  imaxOut->m_real = _mm_max_ps(v16, _mm_max_ps(v14, v15));
}

// File Line: 194
// RVA: 0xB97D80
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *this, hkVector4f *axis, hkSimdFloat32 *imin, hkSimdFloat32 *imax)
{
  __m128 v4; // xmm4
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm1

  v4 = _mm_mul_ps(this->m_axis[0].m_quad, axis->m_quad);
  v5 = _mm_mul_ps(this->m_axis[2].m_quad, axis->m_quad);
  v6 = _mm_mul_ps(axis->m_quad, this->m_center.m_quad);
  v7 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170));
  v8 = _mm_mul_ps(this->m_axis[1].m_quad, axis->m_quad);
  v9 = _mm_unpacklo_ps(v4, v8);
  v10 = _mm_movelh_ps(v9, v5);
  v11 = _mm_mul_ps(
          (__m128)_mm_srli_epi32(
                    _mm_slli_epi32(
                      (__m128i)_mm_add_ps(
                                 _mm_shuffle_ps(_mm_unpackhi_ps(v4, v8), v5, 228),
                                 _mm_add_ps(v10, _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v5, 212))),
                      1u),
                    1u),
          (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&this->m_extent), 1u), 1u));
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  imin->m_real = _mm_sub_ps(v7, v12);
  imax->m_real = _mm_add_ps(v12, v7);
}

// File Line: 207
// RVA: 0xB97E30
char __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::doesTriangleIntersectObb(hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *this, hkVector4f *v0, hkVector4f *v1, hkVector4f *v2)
{
  __m128 v4; // xmm2
  hkVector4f *v5; // r12
  hkVector4f *v6; // r13
  hkVector4f *v7; // rsi
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *v8; // r15
  __m128 v9; // xmm8
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  signed int v15; // ecx
  signed int v16; // eax
  __m128 v18; // xmm9
  __m128 *v19; // rdi
  signed int v20; // ebx
  __m128 v21; // xmm10
  __m128 v22; // xmm6
  signed int v23; // ecx
  signed int v24; // eax
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm1
  bool v30; // cf
  signed __int64 v31; // rsi
  signed __int64 v32; // rax
  __m128 *v33; // r14
  __m128 v34; // xmm6
  signed __int64 v35; // rbx
  __m128 *v36; // rdi
  __m128 v37; // xmm7
  __m128 v38; // xmm2
  signed int v39; // ecx
  signed int v40; // eax
  char imin[24]; // [rsp+28h] [rbp-79h]
  char iminOut[24]; // [rsp+40h] [rbp-61h]
  __m128 v43; // [rsp+58h] [rbp-49h]
  __m128 v44; // [rsp+68h] [rbp-39h]
  __m128 v45; // [rsp+78h] [rbp-29h]
  hkVector4f *v0a; // [rsp+110h] [rbp+6Fh]

  v4 = v0->m_quad;
  v5 = v2;
  v6 = v1;
  v7 = v0;
  v8 = this;
  v9 = _mm_sub_ps(v1->m_quad, v0->m_quad);
  v10 = _mm_sub_ps(v2->m_quad, v0->m_quad);
  v43 = v9;
  v44 = v10;
  v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10));
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_mul_ps(v4, v12);
  *(__m128 *)&imin[8] = v12;
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  *(__m128 *)&iminOut[8] = v14;
  *(__m128 *)iminOut = v14;
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
    this,
    (hkVector4f *)&imin[8],
    (hkSimdFloat32 *)&iminOut[16],
    (hkSimdFloat32 *)&v43.m128_u16[4]);
  v15 = 0;
  if ( v14.m128_f32[0] < *(float *)imin )
    v15 = 1;
  v16 = 0;
  if ( *(float *)&imin[16] < v14.m128_f32[0] )
    v16 = 1;
  if ( v16 | v15 )
    return 0;
  v18 = v8->m_center.m_quad;
  v19 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
  v20 = 0;
  v21 = v8->m_extent.m_quad;
  while ( 1 )
  {
    *(__m128 *)&imin[8] = *(__m128 *)((char *)v19
                                    + (char *)v8
                                    - (char *)`hkVector4f::getComponent::`2::indexToMask
                                    + 16);
    v22 = *(__m128 *)&imin[8];
    hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
      (hkVector4f *)&imin[8],
      v7,
      v6,
      v5,
      (hkSimdFloat32 *)&iminOut[8],
      (hkSimdFloat32 *)iminOut);
    v23 = 0;
    v24 = 0;
    v25 = _mm_and_ps(v21, *v19);
    v26 = _mm_mul_ps(v18, v22);
    v27 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
            _mm_shuffle_ps(v26, v26, 170));
    v28 = _mm_or_ps(_mm_shuffle_ps(v25, v25, 78), v25);
    *(__m128 *)imin = _mm_sub_ps(v27, _mm_or_ps(_mm_shuffle_ps(v28, v28, 177), v28));
    v29 = _mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v28, v28, 177), v28), v27);
    v30 = *(float *)iminOut < *(float *)imin;
    *(__m128 *)&imin[16] = v29;
    if ( v30 )
      v23 = 1;
    if ( v29.m128_f32[0] < *(float *)&iminOut[8] )
      v24 = 1;
    if ( v24 | v23 )
      return 0;
    ++v20;
    ++v19;
    if ( v20 >= 3 )
    {
      v31 = 0i64;
      v32 = (signed __int64)v8->m_axis;
      v33 = &v43;
      v45 = _mm_sub_ps(v10, v9);
LABEL_15:
      v34 = *v33;
      v35 = 0i64;
      v36 = (__m128 *)v32;
      v37 = _mm_shuffle_ps(v34, v34, 201);
      while ( 1 )
      {
        v38 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v36, *v36, 201), v34), _mm_mul_ps(v37, *v36));
        *(__m128 *)&imin[8] = _mm_shuffle_ps(v38, v38, 201);
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
          (hkVector4f *)&imin[8],
          v0a,
          v6,
          v5,
          (hkSimdFloat32 *)&iminOut[8],
          (hkSimdFloat32 *)iminOut);
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
          v8,
          (hkVector4f *)&imin[8],
          (hkSimdFloat32 *)imin,
          (hkSimdFloat32 *)&imin[16]);
        v39 = 0;
        v40 = 0;
        if ( *(float *)iminOut < *(float *)imin )
          v39 = 1;
        if ( *(float *)&imin[16] < *(float *)&iminOut[8] )
          v40 = 1;
        if ( v40 | v39 )
          return 0;
        ++v35;
        ++v36;
        if ( v35 >= 3 )
        {
          ++v31;
          ++v33;
          v32 = (signed __int64)v8->m_axis;
          if ( v31 < 3 )
            goto LABEL_15;
          return 1;
        }
      }
    }
  }
}

// File Line: 257
// RVA: 0xB981D0
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getClosestPointOnLine(hkVector4f *p, hkVector4f *a, hkVector4f *b, hkVector4f *out)
{
  __m128 v4; // xmm6
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1

  v4 = _mm_sub_ps(b->m_quad, a->m_quad);
  v5 = _mm_mul_ps(_mm_sub_ps(p->m_quad, a->m_quad), v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_mul_ps(v4, v4);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rcp_ps(v8);
  out->m_quad = _mm_add_ps(
                  _mm_mul_ps(
                    v4,
                    _mm_andnot_ps(
                      _mm_cmpltps(
                        v8,
                        _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999999eN9), (__m128)LODWORD(FLOAT_9_9999999eN9), 0)),
                      _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v8)), v9), v6))),
                  a->m_quad);
}

// File Line: 268
// RVA: 0xB97AF0
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::makeBoxFromExtrudedTriangle(hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *this, hkVector4f *a, hkVector4f *b, hkVector4f *c, hkVector4f *normal, hkSimdFloat32 *extrusionLength)
{
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *v6; // rbx
  __m128 v7; // xmm10
  __m128 v8; // xmm1
  __m128 v9; // xmm1
  float v10; // xmm3_4
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  float v13; // xmm4_4
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  float v16; // xmm2_4
  __m128 v17; // xmm12
  __m128 v18; // xmm11
  __m128 v19; // xmm11
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm9
  __m128 v24; // xmm11
  __m128 v25; // xmm9
  __m128 v26; // xmm10
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  __m128 v32; // xmm10
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  hkVector4f ba; // [rsp+20h] [rbp-B8h]
  hkVector4f aa; // [rsp+30h] [rbp-A8h]
  hkVector4f p; // [rsp+40h] [rbp-98h]
  hkVector4f out; // [rsp+50h] [rbp-88h]

  v6 = this;
  v7 = c->m_quad;
  v8 = _mm_sub_ps(a->m_quad, b->m_quad);
  v9 = _mm_mul_ps(v8, v8);
  v10 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_sub_ps(a->m_quad, c->m_quad);
  v12 = _mm_mul_ps(v11, v11);
  v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_sub_ps(b->m_quad, c->m_quad);
  v15 = _mm_mul_ps(v14, v14);
  v16 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170));
  if ( v10 <= v13 )
  {
    if ( v13 > v16 )
    {
      v18 = c->m_quad;
      v17 = a->m_quad;
      v7 = b->m_quad;
      goto LABEL_7;
    }
LABEL_6:
    v18 = c->m_quad;
    v17 = b->m_quad;
    v7 = a->m_quad;
    goto LABEL_7;
  }
  if ( v10 <= v16 )
    goto LABEL_6;
  v17 = a->m_quad;
  v18 = b->m_quad;
LABEL_7:
  ba.m_quad = v18;
  v19 = _mm_sub_ps(v18, v17);
  p.m_quad = v7;
  aa.m_quad = v17;
  v20 = _mm_mul_ps(v19, v19);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_andnot_ps(
          _mm_cmpleps(v21, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)), _mm_mul_ps(*(__m128 *)_xmm, v22)));
  v24 = _mm_mul_ps(v19, v23);
  v25 = _mm_mul_ps(v23, v21);
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getClosestPointOnLine(&p, &aa, &ba, &out);
  v26 = _mm_sub_ps(v7, out.m_quad);
  v27 = _mm_mul_ps(v26, v26);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_rsqrt_ps(v28);
  v30 = _mm_add_ps(_mm_mul_ps(normal->m_quad, extrusionLength->m_real), v17);
  v31 = _mm_andnot_ps(
          _mm_cmpleps(v28, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)), _mm_mul_ps(*(__m128 *)_xmm, v29)));
  v6->m_center.m_quad = v30;
  v32 = _mm_mul_ps(v26, v31);
  v33 = _mm_mul_ps(v31, v28);
  v34 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v25, (__m128)xmmword_141A711B0), v24), v30);
  v6->m_center.m_quad = v34;
  v6->m_center.m_quad = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v33, (__m128)xmmword_141A711B0), v32), v34);
  v35 = normal->m_quad;
  v6->m_axis[1].m_quad = v24;
  v6->m_axis[0].m_quad = v35;
  v6->m_axis[2].m_quad = v32;
  v36 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0);
  v6->m_extent.m_quad = _mm_movelh_ps(
                          _mm_unpacklo_ps(
                            _mm_add_ps(v36, extrusionLength->m_real),
                            _mm_add_ps(_mm_mul_ps(v25, (__m128)xmmword_141A711B0), v36)),
                          _mm_unpacklo_ps(_mm_add_ps(_mm_mul_ps(v33, (__m128)xmmword_141A711B0), v36), v36));
}

// File Line: 334
// RVA: 0xB953A0
__int64 __fastcall hkaiNavMeshGenerationUtils::generateWallClimbingNavMesh(hkaiNavMeshGenerationSettings *input, hkGeometry *triMeshIn, hkaiNavMesh *navMeshOut, hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  hkaiNavMeshGenerationSettings *v4; // rdi
  hkaiNavMeshGenerationProgressCallback *v5; // rsi
  hkaiNavMesh *v6; // rbx
  hkGeometry *v7; // rbp
  hkaiNavMeshGenerationOutputs outputs; // [rsp+30h] [rbp-228h]
  hkaiNavMeshGenerationSettings inputa; // [rsp+60h] [rbp-1F8h]

  v4 = input;
  v5 = _callbacks;
  v6 = navMeshOut;
  v7 = triMeshIn;
  hkaiNavMeshGenerationOutputs::hkaiNavMeshGenerationOutputs(&outputs);
  outputs.m_navMesh = v6;
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&inputa);
  hkaiNavMeshGenerationSettings::operator=(&inputa, v4);
  inputa.m_wallClimbingSettings.m_enableWallClimbing.m_bool = 1;
  LODWORD(v6) = hkaiNavMeshGenerationUtils::_generateNavMesh(&inputa, v7, &outputs, v5, 0i64);
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&inputa);
  return (unsigned int)v6;
}

// File Line: 348
// RVA: 0xB95440
__int64 __fastcall hkaiNavMeshGenerationUtils::generateWallClimbingNavMeshDeprecated(hkaiNavMeshGenerationSettings *input, hkGeometry *triMeshIn, hkaiNavMesh *navMeshOut)
{
  hkaiNavMeshGenerationSettings *v3; // rbx
  hkaiNavMesh *v4; // rdi
  hkGeometry *v5; // rsi
  hkaiNavMeshGenerationSettings inputa; // [rsp+30h] [rbp-1F8h]

  v3 = input;
  v4 = navMeshOut;
  v5 = triMeshIn;
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&inputa);
  hkaiNavMeshGenerationSettings::operator=(&inputa, v3);
  inputa.m_wallClimbingSettings.m_enableWallClimbing.m_bool = 1;
  LODWORD(v3) = hkaiNavMeshGenerationUtils::_generateWallClimbingNavMeshDeprecated(&inputa, v5, v4, 0i64, 0i64);
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&inputa);
  return (unsigned int)v3;
}

// File Line: 368
// RVA: 0xB954C0
signed __int64 __fastcall hkaiNavMeshGenerationUtils::_generateWallClimbingNavMeshDeprecated(hkaiNavMeshGenerationSettings *input, hkGeometry *triMeshIn, hkaiNavMesh *navMeshOut, hkaiNavMeshGenerationProgressCallback *callbacks, hkaiEdgeGeometryRaycaster *edgeConnectionRaycaster)
{
  hkaiNavMesh *v5; // rbx
  hkGeometry *v6; // rdi
  hkaiNavMeshGenerationSettings *v7; // r14
  signed __int64 v8; // rax
  int v9; // er8
  int v10; // ebx
  __int64 v11; // rdi
  int v12; // er9
  unsigned int v13; // eax
  int v14; // er9
  signed int v15; // edi
  __int64 v16; // r15
  int v17; // er13
  int v18; // eax
  int v19; // eax
  int v20; // er9
  __int64 v21; // rbx
  __int64 v22; // rdi
  hkReferencedObject *v23; // rcx
  hkRefPtr<hkaiVolume const > *v24; // rbx
  __int64 v25; // rsi
  signed __int64 v26; // rdi
  hkReferencedObject *v27; // rcx
  hkReferencedObject *v28; // rcx
  hkaiVolume *v29; // rax
  hkReferencedObject **v30; // rdi
  __int64 v31; // rsi
  __int64 v32; // r12
  __m128 v33; // xmm0
  _QWORD **v34; // rax
  hkaiInvertedAabbVolume *v35; // rax
  hkReferencedObject *v36; // rax
  hkReferencedObject *v37; // rbx
  int v38; // ecx
  __int64 v39; // rdi
  _QWORD *v40; // rdx
  __int64 v41; // rsi
  hkReferencedObject *v42; // rcx
  int v43; // er9
  int v44; // er15
  int v45; // eax
  int v46; // edi
  int v47; // er9
  int v48; // er8
  __int64 v49; // rdx
  __int64 v50; // rdi
  __int64 v51; // rcx
  __m128 v52; // xmm13
  unsigned __int64 v53; // r8
  __int64 v54; // rdi
  int v55; // er13
  hkVector4f *v56; // rsi
  hkVector4f *v57; // r15
  hkVector4f *v58; // r12
  bool v59; // zf
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm6
  __m128 v63; // xmm6
  __m128 v64; // xmm1
  __m128 v65; // xmm3
  __m128 v66; // xmm2
  __m128 v67; // xmm5
  hkLifoAllocator *v68; // rax
  hkVector4f *v69; // rdx
  unsigned __int64 v70; // rcx
  hkVector4f v71; // xmm0
  hkVector4f v72; // xmm0
  int v73; // eax
  hkVector4f v74; // xmm0
  int v75; // eax
  int v76; // eax
  char *v77; // rbx
  int v78; // eax
  signed int v79; // edi
  hkLifoAllocator *v80; // rax
  int v81; // er8
  signed int v82; // edi
  hkLifoAllocator *v83; // rax
  int v84; // er8
  __m128 v85; // xmm5
  __m128 v86; // xmm1
  __m128 v87; // xmm2
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  __m128 v90; // xmm5
  hkVector4f v91; // xmm3
  hkVector4f v92; // xmm3
  hkVector4f v93; // xmm3
  hkVector4f v94; // xmm3
  int v95; // esi
  int v96; // edi
  hkVector4f *v97; // rbx
  __int64 v98; // rcx
  int *v99; // r14
  __int64 v100; // rcx
  __int64 v101; // rcx
  int v102; // er15
  int v103; // er12
  int v104; // er13
  signed __int64 v105; // rdi
  unsigned __int64 v106; // rsi
  int v107; // eax
  int v108; // ecx
  int v109; // eax
  hkVector4f *v110; // rbx
  unsigned __int64 v111; // r9
  int v112; // eax
  int v113; // er9
  int v114; // ebx
  __int64 v115; // rdi
  int v116; // edx
  __int64 v117; // rcx
  int v118; // edi
  int v119; // ecx
  int v120; // er13
  int v121; // edi
  __int32 v122; // ecx
  unsigned int *v123; // r8
  int v124; // eax
  int v125; // eax
  int v126; // eax
  int v127; // er9
  __int64 v128; // rcx
  unsigned int *v129; // rdi
  int v130; // ebx
  __int64 v131; // rdi
  int v132; // ecx
  hkGeometry::Triangle *v133; // rsi
  hkGeometry::Triangle *v134; // rsi
  int v135; // ecx
  hkGeometry::Triangle *v136; // rsi
  int v137; // ecx
  __int64 v138; // r12
  int v139; // eax
  signed int v140; // esi
  __int64 v141; // r13
  __m128 v142; // xmm9
  __int64 v143; // r12
  __m128 v144; // xmm12
  hkVector4f *v145; // rdx
  hkVector4f *v146; // rdi
  hkVector4f *v147; // r8
  __m128 v148; // xmm1
  __m128 v149; // xmm2
  __m128 v150; // xmm6
  __m128 v151; // xmm6
  __m128 v152; // xmm1
  __m128 v153; // xmm3
  __m128 v154; // xmm2
  __m128 v155; // xmm4
  __m128 v156; // xmm5
  __m128 v157; // xmm0
  hkVector4f v158; // xmm3
  __m128 v159; // xmm5
  __m128 v160; // xmm0
  __m128 v161; // xmm1
  __m128 v162; // xmm2
  hkVector4f v163; // xmm4
  __m128 v164; // xmm2
  hkVector4f v165; // xmm3
  hkVector4f v166; // xmm4
  hkVector4f v167; // xmm3
  hkVector4f v168; // xmm4
  __m128 v169; // xmm3
  int v170; // ebx
  __int64 v171; // rdi
  __int64 v172; // r8
  __int64 v173; // r9
  __int64 v174; // rax
  hkVector4f *v175; // r15
  int v176; // er13
  signed int v177; // ebx
  hkResultEnum v178; // edi
  __m128 v179; // xmm6
  __m128 v180; // xmm7
  __int64 v181; // rsi
  __int64 v182; // r14
  __m128 v183; // xmm8
  signed __int64 v184; // rax
  signed __int64 v185; // rcx
  signed __int64 v186; // rdx
  __m128 v187; // xmm3
  __m128 v188; // xmm1
  __m128 v189; // xmm2
  __m128 v190; // xmm0
  hkVector4f v191; // xmm0
  hkVector4f v192; // xmm0
  hkVector4f v193; // xmm0
  __m128 v194; // xmm0
  int *v195; // r12
  __int64 v196; // rcx
  __int64 v197; // rdi
  hkVector4f *v198; // rbx
  hkVector4f *v199; // rsi
  hkVector4f *v200; // r14
  int v201; // edi
  __int64 v202; // rsi
  signed int v203; // ebx
  unsigned int *v204; // r12
  signed __int64 v205; // rdi
  signed __int64 v206; // rax
  int *v207; // rdi
  hkaiMaterialPainter::ResolveOverlapCallback *v208; // r9
  hkaiNavMesh *v209; // r15
  hkaiNavMesh *v210; // rbx
  hkaiEdgeGeometryRaycaster *v211; // rsi
  int i; // edi
  hkaiNavMeshGenerationProgressCallback *v213; // rsi
  __m128 v214; // xmm1
  unsigned int v215; // esi
  _QWORD *v216; // rbx
  __int64 v217; // rdi
  hkReferencedObject *v218; // rcx
  hkArray<int,hkContainerHeapAllocator> trisPerFaceOut; // [rsp+50h] [rbp-B0h]
  signed int *v220; // [rsp+60h] [rbp-A0h]
  int v221; // [rsp+68h] [rbp-98h]
  int v222; // [rsp+6Ch] [rbp-94h]
  _BYTE *array; // [rsp+70h] [rbp-90h]
  int v224; // [rsp+78h] [rbp-88h]
  int v225; // [rsp+7Ch] [rbp-84h]
  int v226; // [rsp+80h] [rbp-80h]
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> newTriangles; // [rsp+90h] [rbp-70h]
  hkArrayBase<unsigned int> v228; // [rsp+A0h] [rbp-60h]
  hkArrayBase<hkVector4f> v229; // [rsp+B0h] [rbp-50h]
  hkArrayBase<int> perTriangleDataInOut; // [rsp+C0h] [rbp-40h]
  hkArray<int,hkContainerHeapAllocator> trisOut; // [rsp+D0h] [rbp-30h]
  unsigned int v232; // [rsp+E0h] [rbp-20h]
  hkAabb aabb; // [rsp+F0h] [rbp-10h]
  char *v234; // [rsp+110h] [rbp+10h]
  int v235; // [rsp+118h] [rbp+18h]
  int v236; // [rsp+11Ch] [rbp+1Ch]
  char *v237; // [rsp+120h] [rbp+20h]
  int v238; // [rsp+128h] [rbp+28h]
  int v239; // [rsp+12Ch] [rbp+2Ch]
  hkArrayBase<hkVector4f> points; // [rsp+130h] [rbp+30h]
  void *p; // [rsp+140h] [rbp+40h]
  hkArray<int,hkContainerHeapAllocator> *v242; // [rsp+148h] [rbp+48h]
  hkAabb v243; // [rsp+150h] [rbp+50h]
  hkVector4f normal; // [rsp+170h] [rbp+70h]
  hkArray<int,hkContainerHeapAllocator> triConnectivityOut; // [rsp+180h] [rbp+80h]
  hkResult v246[2]; // [rsp+190h] [rbp+90h]
  hkBitField trisToRemove; // [rsp+198h] [rbp+98h]
  hkArrayBase<unsigned int> v248; // [rsp+1B0h] [rbp+B0h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v249; // [rsp+1C0h] [rbp+C0h]
  hkArrayBase<unsigned int> v250; // [rsp+1D0h] [rbp+D0h]
  hkGeometry geomInOut; // [rsp+1E0h] [rbp+E0h]
  hkResult v252[2]; // [rsp+210h] [rbp+110h]
  hkArray<int,hkContainerHeapAllocator> materialsOut; // [rsp+218h] [rbp+118h]
  hkResult v254[2]; // [rsp+228h] [rbp+128h]
  hkErrStream v255; // [rsp+230h] [rbp+130h]
  hkGeometry mesh; // [rsp+250h] [rbp+150h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v257; // [rsp+280h] [rbp+180h]
  int v258; // [rsp+290h] [rbp+190h]
  int v259; // [rsp+294h] [rbp+194h]
  int v260; // [rsp+298h] [rbp+198h]
  hkResult v261; // [rsp+2A0h] [rbp+1A0h]
  hkResult v262; // [rsp+2A4h] [rbp+1A4h]
  __int64 v263; // [rsp+2A8h] [rbp+1A8h]
  __int64 v264; // [rsp+2B0h] [rbp+1B0h]
  hkaiEdgeGeometry v265; // [rsp+2C0h] [rbp+1C0h]
  int v266; // [rsp+310h] [rbp+210h]
  int v267; // [rsp+314h] [rbp+214h]
  int v268; // [rsp+318h] [rbp+218h]
  hkResult v269; // [rsp+320h] [rbp+220h]
  hkResult v270; // [rsp+324h] [rbp+224h]
  hkResult v271; // [rsp+328h] [rbp+228h]
  hkResult v272; // [rsp+32Ch] [rbp+22Ch]
  hkaiEdgeGeometry extrudeGeom; // [rsp+330h] [rbp+230h]
  hkaiSelfIntersectBooleanFilter2 filter; // [rsp+380h] [rbp+280h]
  hkaiCarverTree carverTree; // [rsp+3E0h] [rbp+2E0h]
  hkSimdFloat32 extrusionLength; // [rsp+410h] [rbp+310h]
  hkaiEdgeGeometry geomA; // [rsp+420h] [rbp+320h]
  hkaiTriangleSetAabbTester v278; // [rsp+470h] [rbp+370h]
  hkaiTriangleSetAabbTester v279; // [rsp+4C0h] [rbp+3C0h]
  hkaiTriangleSetAabbTester v280; // [rsp+510h] [rbp+410h]
  hkaiEdgeGeometry geom; // [rsp+560h] [rbp+460h]
  hkaiEdgeGeometry geomOut; // [rsp+5B0h] [rbp+4B0h]
  hkaiEdgeGeometryRaycaster raycaster; // [rsp+600h] [rbp+500h]
  hkaiGeometryToEdgeGeometryConverter v284; // [rsp+670h] [rbp+570h]
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb v285; // [rsp+6D0h] [rbp+5D0h]
  hkaiNavMesh v286; // [rsp+720h] [rbp+620h]
  hkaiBooleanOperation buf; // [rsp+7D0h] [rbp+6D0h]
  hkaiNavMeshGenerationSettings *v288; // [rsp+AA0h] [rbp+9A0h]
  hkResult result; // [rsp+AA8h] [rbp+9A8h]
  hkaiNavMesh *navMesh; // [rsp+AB0h] [rbp+9B0h]
  hkaiNavMeshGenerationProgressCallback *callbacksa; // [rsp+AB8h] [rbp+9B8h]

  callbacksa = callbacks;
  navMesh = navMeshOut;
  v288 = input;
  v5 = navMeshOut;
  v6 = triMeshIn;
  v7 = input;
  if ( !triMeshIn->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v255, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v255.vfptr, "Passed in empty triMesh to generateWallClimbingNavMesh()");
    hkError::messageWarning(1060047688, (const char *)&buf, "NavMesh\\hkaiNavMeshGenerationUtils_wallClimbing.cpp", 381);
    hkOstream::~hkOstream((hkOstream *)&v255.vfptr);
    v8 = 1i64;
    v5->m_aabb.m_min = (hkVector4f)aabbOut.m_quad;
    v5->m_aabb.m_max = (hkVector4f)aabbOut.m_quad;
    return v8;
  }
  if ( !HK_flyingcolors_ai_0.m_bool )
  {
    hkaiCheckKeycode(input, triMeshIn, navMeshOut);
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_0);
    if ( !HK_flyingcolors_ai_0.m_bool )
    {
      hkErrStream::hkErrStream(&v255, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v255.vfptr, "Invalid keycode. Exiting nav mesh generation.");
      hkError::messageWarning(
        691989308,
        (const char *)&buf,
        "NavMesh\\hkaiNavMeshGenerationUtils_wallClimbing.cpp",
        393);
      hkOstream::~hkOstream((hkOstream *)&v255.vfptr);
      v8 = 3i64;
      v5->m_aabb.m_min = (hkVector4f)aabbOut.m_quad;
      v5->m_aabb.m_max = (hkVector4f)aabbOut.m_quad;
      return v8;
    }
  }
  if ( v7->m_saveInputSnapshot.m_bool )
    hkaiNavMeshGenerationUtils::_saveSnapshot(v7, v6);
  hkGeometry::hkGeometry(&geomInOut, v6);
  hkaiNavMeshGenerationUtils::quantize(&geomInOut, v7->m_quantizationGridSize);
  v9 = v7->m_materialMap.m_size;
  v249.m_elem = 0i64;
  v249.m_numElems = 0;
  v249.m_hashMod = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    &v249,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v9);
  v10 = 0;
  if ( v7->m_materialMap.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v249,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned int)v7->m_materialMap.m_data[v11].m_materialIndex,
        v7->m_materialMap.m_data[v11].m_flags.m_storage);
      ++v10;
      ++v11;
    }
    while ( v10 < v7->m_materialMap.m_size );
  }
  v12 = v7->m_carvers.m_size;
  v13 = 2147483648;
  array = 0i64;
  v14 = v12 + 1;
  v15 = 0;
  v224 = 0;
  v225 = 2147483648;
  if ( v14 > 0 )
  {
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v14, 8);
    v13 = v225;
    v15 = v224;
  }
  v16 = v7->m_carvers.m_size;
  v17 = v7->m_carvers.m_size;
  if ( (signed int)v16 > v15 )
    v17 = v15;
  v18 = v13 & 0x3FFFFFFF;
  if ( v18 < (signed int)v16 )
  {
    v19 = 2 * v18;
    v20 = v7->m_carvers.m_size;
    if ( (signed int)v16 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v20, 8);
  }
  v21 = (__int64)&array[8 * v16];
  v22 = v15 - (signed int)v16 - 1;
  if ( (signed int)v22 >= 0 )
  {
    do
    {
      v23 = *(hkReferencedObject **)(v21 + 8 * v22);
      if ( v23 )
        hkReferencedObject::removeReference(v23);
      *(_QWORD *)(v21 + 8 * v22--) = 0i64;
    }
    while ( v22 >= 0 );
  }
  v24 = v7->m_carvers.m_data;
  v25 = (__int64)array;
  v26 = 0i64;
  if ( v17 > 0 )
  {
    do
    {
      v27 = (hkReferencedObject *)&v24[v26].m_pntr->vfptr;
      if ( v27 )
        hkReferencedObject::addReference(v27);
      v28 = *(hkReferencedObject **)(v25 + 8 * v26);
      if ( v28 )
        hkReferencedObject::removeReference(v28);
      v29 = v24[v26++].m_pntr;
      *(_QWORD *)(v25 + 8 * v26 - 8) = v29;
    }
    while ( v26 < v17 );
  }
  v30 = (hkReferencedObject **)&v7->m_carvers.m_data[v17];
  v31 = (signed int)v16 - v17;
  if ( (signed int)v16 - v17 > 0 )
  {
    v32 = &array[8 * v17] - (_BYTE *)v30;
    do
    {
      if ( (hkReferencedObject **)((char *)v30 + v32) )
      {
        if ( *v30 )
          hkReferencedObject::addReference(*v30);
        *(hkReferencedObject **)((char *)v30 + v32) = *v30;
      }
      ++v30;
      --v31;
    }
    while ( v31 );
  }
  v33 = v7->m_boundsAabb.m_max.m_quad;
  v224 = v16;
  if ( !(_mm_movemask_ps(_mm_cmpleps(v33, v7->m_boundsAabb.m_min.m_quad)) & 7) )
  {
    v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v35 = (hkaiInvertedAabbVolume *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v34[11] + 8i64))(
                                      v34[11],
                                      96i64);
    if ( v35 )
    {
      hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(v35, &v7->m_boundsAabb);
      v37 = v36;
    }
    else
    {
      v37 = 0i64;
    }
    v38 = v224;
    if ( v224 == (v225 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
      v38 = v224;
    }
    v39 = (__int64)array;
    v40 = &array[8 * v38];
    if ( v40 )
    {
      *v40 = 0i64;
      v38 = v224;
      v39 = (__int64)array;
    }
    v41 = v38;
    v224 = v38 + 1;
    v42 = *(hkReferencedObject **)(v39 + 8i64 * v38);
    if ( v42 && v42 != v37 )
      hkReferencedObject::removeReference(v42);
    *(_QWORD *)(v39 + 8 * v41) = v37;
  }
  hkaiCarverTree::hkaiCarverTree(&carverTree);
  hkaiCarverTree::init(
    &carverTree,
    &result,
    (hkArrayBase<hkRefPtr<hkaiVolume const > > *)&array,
    (hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *)&v7->m_painters.m_data);
  hkaiNavMeshGenerationUtils::setCarvedMaterialsDeprecated(
    &geomInOut,
    v7->m_carvedCuttingMaterialDeprecated,
    v7->m_carvedMaterialDeprecated,
    (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v249,
    v7->m_defaultConstructionProperties.m_storage,
    &carverTree);
  if ( v7->m_weldInputVertices.m_bool )
    hkGeometryUtils::weldVertices(&geomInOut, v7->m_weldThreshold);
  hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter(&v284);
  v43 = geomInOut.m_triangles.m_size;
  v44 = 0;
  v229.m_data = 0i64;
  v229.m_size = 0;
  v229.m_capacityAndFlags = 2147483648;
  v228.m_data = 0i64;
  v228.m_size = 0;
  v228.m_capacityAndFlags = 2147483648;
  v248.m_data = 0i64;
  v248.m_size = 0;
  v248.m_capacityAndFlags = 2147483648;
  v250.m_data = 0i64;
  v250.m_size = 0;
  v250.m_capacityAndFlags = 2147483648;
  perTriangleDataInOut.m_data = 0i64;
  perTriangleDataInOut.m_size = 0;
  perTriangleDataInOut.m_capacityAndFlags = 2147483648;
  newTriangles.m_data = 0i64;
  newTriangles.m_size = 0;
  newTriangles.m_capacityAndFlags = 2147483648;
  if ( geomInOut.m_triangles.m_size > 0 )
  {
    if ( geomInOut.m_triangles.m_size < 0 )
      v43 = 0;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &newTriangles,
      v43,
      16);
  }
  hkGeometryUtils::removeDuplicateTrianglesFast(&result, &geomInOut, &newTriangles);
  newTriangles.m_size = 0;
  if ( newTriangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      newTriangles.m_data,
      16 * newTriangles.m_capacityAndFlags);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomOut);
  hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
    &v284,
    &result,
    &geomInOut,
    (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
    &geomOut);
  v45 = geomInOut.m_triangles.m_size;
  v46 = 3 * geomInOut.m_triangles.m_size;
  v237 = 0i64;
  v238 = 0;
  v239 = 2147483648;
  if ( 3 * geomInOut.m_triangles.m_size > 0 )
  {
    v47 = 3 * geomInOut.m_triangles.m_size;
    if ( v46 < 0 )
      v47 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v237, v47, 4);
    v45 = geomInOut.m_triangles.m_size;
  }
  v238 = v46;
  v48 = 0;
  if ( v45 > 0 )
  {
    v49 = 0i64;
    v50 = 0i64;
    do
    {
      ++v48;
      ++v50;
      v49 += 12i64;
      *(_DWORD *)&v237[v49 - 12] = geomInOut.m_triangles.m_data[v50 - 1].m_a;
      *(_DWORD *)&v237[v49 - 8] = *((_DWORD *)&geomInOut.m_triangles.m_data[v50] - 3);
      *(_DWORD *)&v237[v49 - 4] = *((_DWORD *)&geomInOut.m_triangles.m_data[v50] - 2);
    }
    while ( v48 < geomInOut.m_triangles.m_size );
  }
  v278.m_vertices = &geomInOut.m_vertices;
  v278.m_tris = (hkArray<int,hkContainerHeapAllocator> *)&v237;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&v278.m_tree);
  hkaiTriangleSetAabbTester::init(&v278);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomA);
  hkaiEdgeGeometry::setForSingleTriangle(&geomA, &result);
  mesh.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&mesh.m_memSizeAndFlags = 0x1FFFF;
  mesh.m_vertices.m_data = 0i64;
  mesh.m_vertices.m_size = 0;
  mesh.m_vertices.m_capacityAndFlags = 2147483648;
  mesh.m_triangles.m_data = 0i64;
  mesh.m_triangles.m_size = 0;
  mesh.m_triangles.m_capacityAndFlags = 2147483648;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geom);
  v51 = 0i64;
  v52 = _mm_shuffle_ps((__m128)LODWORD(v7->m_characterHeight), (__m128)LODWORD(v7->m_characterHeight), 0);
  result.m_enum = 0;
  extrusionLength.m_real = v52;
  v263 = 0i64;
  if ( geomInOut.m_triangles.m_size > 0 )
  {
    do
    {
      v53 = v7->m_defaultConstructionProperties.m_storage;
      v54 = v51;
      v232 = geomInOut.m_triangles.m_data[v51].m_material;
      v55 = v232;
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             &v249,
             v232,
             v53) & 1 )
      {
        v56 = &geomInOut.m_vertices.m_data[geomInOut.m_triangles.m_data[v54].m_a];
        v57 = &geomInOut.m_vertices.m_data[geomInOut.m_triangles.m_data[v54].m_b];
        v58 = &geomInOut.m_vertices.m_data[geomInOut.m_triangles.m_data[v54].m_c];
        *geomA.m_vertices.m_data = (hkVector4f)v56->m_quad;
        geomA.m_vertices.m_data[1] = (hkVector4f)v57->m_quad;
        geomA.m_vertices.m_data[2] = (hkVector4f)v58->m_quad;
        v59 = v7->m_wallClimbingSettings.m_excludeWalkableFaces.m_bool == 0;
        v60 = _mm_sub_ps(v58->m_quad, v56->m_quad);
        v61 = _mm_sub_ps(v57->m_quad, v56->m_quad);
        v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v61), _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v60));
        v63 = _mm_shuffle_ps(v62, v62, 201);
        v64 = _mm_mul_ps(v63, v63);
        v65 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                _mm_shuffle_ps(v64, v64, 170));
        v66 = _mm_rsqrt_ps(v65);
        v67 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v65), (__m128)0i64);
        normal.m_quad = _mm_or_ps(
                          _mm_and_ps(
                            _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v65, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v66, v65), v66)),
                                  _mm_mul_ps(*(__m128 *)_xmm, v66))),
                              v63),
                            v67),
                          _mm_andnot_ps(v67, v63));
        if ( v59 )
          goto LABEL_89;
        points.m_capacityAndFlags = 2147483648;
        points.m_data = 0i64;
        points.m_size = 0;
        LODWORD(v242) = 3;
        v68 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v69 = (hkVector4f *)v68->m_cur;
        v70 = (unsigned __int64)&v69[8];
        if ( v68->m_slabSize < 128 || (void *)v70 > v68->m_end )
          v69 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v68, 128);
        else
          v68->m_cur = (void *)v70;
        v71.m_quad = v56->m_quad;
        points.m_data = v69;
        p = v69;
        points.m_capacityAndFlags = -2147483645;
        v69[points.m_size] = (hkVector4f)v71.m_quad;
        v72.m_quad = v57->m_quad;
        v73 = points.m_size + 1;
        points.m_size = v73;
        points.m_data[v73] = (hkVector4f)v72.m_quad;
        v74.m_quad = v58->m_quad;
        v75 = points.m_size + 1;
        points.m_size = v75;
        points.m_data[v75] = (hkVector4f)v74.m_quad;
        ++points.m_size;
        v76 = hkaiNavMeshGenerationSettings::isWalkableBySlope(v7, &normal, &points, v55);
        v77 = (char *)p;
        v59 = v76 == 0;
        v78 = points.m_size;
        if ( v59 )
        {
          if ( p == points.m_data )
            v78 = 0;
          points.m_size = v78;
          v82 = (16 * (_DWORD)v242 + 127) & 0xFFFFFF80;
          v83 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v84 = (v82 + 15) & 0xFFFFFFF0;
          if ( v82 > v83->m_slabSize || &v77[v84] != v83->m_cur || v83->m_firstNonLifoEnd == v77 )
            hkLifoAllocator::slowBlockFree(v83, v77, v84);
          else
            v83->m_cur = v77;
          points.m_size = 0;
          if ( points.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              points.m_data,
              16 * points.m_capacityAndFlags);
LABEL_89:
          hkStopwatch::getTickCounter();
          mesh.m_triangles.m_size = 0;
          v85 = _mm_mul_ps(normal.m_quad, v52);
          v234 = 0i64;
          v86 = v56->m_quad;
          v87 = v57->m_quad;
          v235 = 0;
          v88 = _mm_add_ps(v86, v85);
          v89 = _mm_add_ps(v87, v85);
          v90 = _mm_add_ps(v85, v58->m_quad);
          aabb.m_min = (hkVector4f)xmmword_141A712A0;
          points.m_data = (hkVector4f *)&hkaiTriangleSetAabbTester::AabbCollector::`vftable;
          *(_QWORD *)&points.m_size = &v234;
          v91.m_quad = _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         (__m128)xmmword_141A712A0);
          aabb.m_max = (hkVector4f)v91.m_quad;
          aabb.m_min.m_quad = _mm_min_ps((__m128)xmmword_141A712A0, v56->m_quad);
          v92.m_quad = _mm_max_ps(v91.m_quad, v56->m_quad);
          p = v278.m_vertices;
          aabb.m_max = (hkVector4f)v92.m_quad;
          aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v57->m_quad);
          v93.m_quad = _mm_max_ps(v92.m_quad, v57->m_quad);
          v236 = 2147483648;
          v242 = v278.m_tris;
          aabb.m_max = (hkVector4f)v93.m_quad;
          aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v58->m_quad);
          v94.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(_mm_max_ps(v93.m_quad, v58->m_quad), v88), v89), v90);
          aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(aabb.m_min.m_quad, v88), v89), v90);
          v243.m_min = aabb.m_min;
          aabb.m_max = (hkVector4f)v94.m_quad;
          v243.m_max = (hkVector4f)v94.m_quad;
          hkcdDynamicAabbTree::queryAabb(&v278.m_tree, &aabb, (hkcdAabbTreeQueries::AabbCollector *)&points);
          hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::makeBoxFromExtrudedTriangle(
            &v285,
            v56,
            v57,
            v58,
            &normal,
            &extrusionLength);
          v95 = v235;
          v44 = 0;
          v257.m_hashMod = -1;
          v257.m_elem = 0i64;
          v257.m_numElems = 0;
          mesh.m_vertices.m_size = 0;
          v96 = v235;
          if ( (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= v235 )
          {
            v261.m_enum = 0;
          }
          else
          {
            if ( v235 < 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
              v95 = 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF);
            hkArrayUtil::_reserve(
              &v261,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &mesh.m_triangles,
              v95,
              16);
            v95 = v235;
          }
          mesh.m_triangles.m_size = v96;
          v226 = 0;
          if ( v95 <= 0 )
          {
LABEL_115:
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              &v257,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
            _((AMD_HD3D *)&v257);
            v235 = 0;
            if ( v236 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                v234,
                4 * v236);
            v234 = 0i64;
            v236 = 2147483648;
            hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
              &v284,
              &v270,
              &mesh,
              (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
              &geom);
            hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(
              &geom,
              (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v249,
              v7->m_defaultConstructionProperties.m_storage,
              2u);
            hkaiEdgeGeometry::hkaiEdgeGeometry(&extrudeGeom);
            *(__m128 *)&v255.vfptr = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v52), normal.m_quad);
            hkaiGeometryExtrudeUtil::silhouetteExtrudeDeprecated(&v272, &geom, (hkVector4f *)&v255, &extrudeGeom);
            hkaiGeometryCarverExtractor::addCarversInRegion(&v269, &extrudeGeom, &carverTree, &aabb);
            hkaiEdgeGeometry::hkaiEdgeGeometry(&v265);
            newTriangles.m_data = 0i64;
            newTriangles.m_size = 0;
            newTriangles.m_capacityAndFlags = 2147483648;
            hkaiBooleanOperation::hkaiBooleanOperation(&buf);
            hkaiSelfIntersectBooleanFilter2::hkaiSelfIntersectBooleanFilter2(&filter);
            hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(&filter, &v271, &geomA, &extrudeGeom);
            hkaiBooleanOperation::subtract(
              &buf,
              v252,
              &geomA,
              &extrudeGeom,
              &v265,
              (hkaiBooleanFaceFaceIntersects *)&newTriangles,
              (hkaiBooleanFilter *)&filter.vfptr);
            trisOut.m_data = 0i64;
            trisOut.m_size = 0;
            trisOut.m_capacityAndFlags = 2147483648;
            trisPerFaceOut.m_data = 0i64;
            trisPerFaceOut.m_size = 0;
            trisPerFaceOut.m_capacityAndFlags = 2147483648;
            triConnectivityOut.m_data = 0i64;
            triConnectivityOut.m_size = 0;
            triConnectivityOut.m_capacityAndFlags = 2147483648;
            materialsOut.m_data = 0i64;
            materialsOut.m_size = 0;
            materialsOut.m_capacityAndFlags = 2147483648;
            hkaiNavMeshGenerationUtils::_triangulate(
              v254,
              v7,
              &v265,
              &trisOut,
              &trisPerFaceOut,
              &triConnectivityOut,
              &materialsOut,
              1);
            hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(
              v246,
              &v265.m_vertices,
              &trisOut,
              &trisPerFaceOut,
              &triConnectivityOut,
              (hkArrayBase<int> *)&materialsOut.m_data,
              v7);
            v114 = v229.m_size;
            hkArrayBase<hkVector4f>::_append(
              &v229,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v265.m_vertices.m_data,
              v265.m_vertices.m_size);
            v115 = v228.m_size;
            hkArrayBase<unsigned int>::_append(
              &v228,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (const unsigned int *)trisOut.m_data,
              trisOut.m_size);
            v116 = 0;
            if ( trisOut.m_size > 0 )
            {
              v117 = v115;
              do
              {
                ++v116;
                ++v117;
                v228.m_data[v117 - 1] += v114;
              }
              while ( v116 < trisOut.m_size );
            }
            hkArrayBase<unsigned int>::_append(
              &v248,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (const unsigned int *)trisPerFaceOut.m_data,
              trisPerFaceOut.m_size);
            hkArrayBase<unsigned int>::_append(
              &v250,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (const unsigned int *)triConnectivityOut.m_data,
              triConnectivityOut.m_size);
            v118 = 0;
            if ( trisOut.m_size / 3 > 0 )
            {
              v119 = perTriangleDataInOut.m_size;
              do
              {
                if ( v119 == (perTriangleDataInOut.m_capacityAndFlags & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    &perTriangleDataInOut,
                    4);
                  v119 = perTriangleDataInOut.m_size;
                }
                ++v118;
                perTriangleDataInOut.m_data[v119] = v55;
                v119 = perTriangleDataInOut.m_size++ + 1;
              }
              while ( v118 < trisOut.m_size / 3 );
            }
            materialsOut.m_size = 0;
            if ( materialsOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                materialsOut.m_data,
                4 * materialsOut.m_capacityAndFlags);
            materialsOut.m_data = 0i64;
            materialsOut.m_capacityAndFlags = 2147483648;
            triConnectivityOut.m_size = 0;
            if ( triConnectivityOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                triConnectivityOut.m_data,
                4 * triConnectivityOut.m_capacityAndFlags);
            triConnectivityOut.m_data = 0i64;
            triConnectivityOut.m_capacityAndFlags = 2147483648;
            trisPerFaceOut.m_size = 0;
            if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                trisPerFaceOut.m_data,
                4 * trisPerFaceOut.m_capacityAndFlags);
            trisPerFaceOut.m_data = 0i64;
            trisPerFaceOut.m_capacityAndFlags = 2147483648;
            trisOut.m_size = 0;
            if ( trisOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                trisOut.m_data,
                4 * trisOut.m_capacityAndFlags);
            trisOut.m_data = 0i64;
            trisOut.m_capacityAndFlags = 2147483648;
            filter.m_face1Results.m_size = 0;
            if ( filter.m_face1Results.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                filter.m_face1Results.m_data,
                filter.m_face1Results.m_capacityAndFlags & 0x3FFFFFFF);
            filter.m_face1Results.m_data = 0i64;
            filter.m_face1Results.m_capacityAndFlags = 2147483648;
            filter.m_vertexMapB.m_size = 0;
            if ( filter.m_vertexMapB.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                filter.m_vertexMapB.m_data,
                4 * filter.m_vertexMapB.m_capacityAndFlags);
            filter.m_vertexMapB.m_data = 0i64;
            filter.m_vertexMapB.m_capacityAndFlags = 2147483648;
            filter.m_vertexMapA.m_size = 0;
            if ( filter.m_vertexMapA.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                filter.m_vertexMapA.m_data,
                4 * filter.m_vertexMapA.m_capacityAndFlags);
            filter.m_vertexMapA.m_data = 0i64;
            filter.vfptr = (hkaiBooleanFilterVtbl *)&hkaiBooleanFilter::`vftable;
            filter.m_vertexMapA.m_capacityAndFlags = 2147483648;
            hkaiBooleanOperation::~hkaiBooleanOperation(&buf);
            newTriangles.m_size = 0;
            if ( newTriangles.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                newTriangles.m_data,
                16 * newTriangles.m_capacityAndFlags);
            newTriangles.m_data = 0i64;
            newTriangles.m_capacityAndFlags = 2147483648;
            v265.m_vertices.m_size = 0;
            if ( v265.m_vertices.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v265.m_vertices.m_data,
                16 * v265.m_vertices.m_capacityAndFlags);
            v265.m_vertices.m_data = 0i64;
            v265.m_vertices.m_capacityAndFlags = 2147483648;
            v265.m_faces.m_size = 0;
            if ( v265.m_faces.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v265.m_faces.m_data,
                12 * (v265.m_faces.m_capacityAndFlags & 0x3FFFFFFF));
            v265.m_faces.m_data = 0i64;
            v265.m_faces.m_capacityAndFlags = 2147483648;
            v265.m_edges.m_size = 0;
            if ( v265.m_edges.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v265.m_edges.m_data,
                16 * v265.m_edges.m_capacityAndFlags);
            v265.m_edges.m_data = 0i64;
            v265.m_edges.m_capacityAndFlags = 2147483648;
            v265.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
            extrudeGeom.m_vertices.m_size = 0;
            if ( extrudeGeom.m_vertices.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                extrudeGeom.m_vertices.m_data,
                16 * extrudeGeom.m_vertices.m_capacityAndFlags);
            extrudeGeom.m_vertices.m_data = 0i64;
            extrudeGeom.m_vertices.m_capacityAndFlags = 2147483648;
            extrudeGeom.m_faces.m_size = 0;
            if ( extrudeGeom.m_faces.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                extrudeGeom.m_faces.m_data,
                12 * (extrudeGeom.m_faces.m_capacityAndFlags & 0x3FFFFFFF));
            extrudeGeom.m_faces.m_data = 0i64;
            extrudeGeom.m_faces.m_capacityAndFlags = 2147483648;
            extrudeGeom.m_edges.m_size = 0;
            if ( extrudeGeom.m_edges.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                extrudeGeom.m_edges.m_data,
                16 * extrudeGeom.m_edges.m_capacityAndFlags);
            goto LABEL_153;
          }
          v97 = geomInOut.m_vertices.m_data;
          v98 = 0i64;
          v99 = &mesh.m_triangles.m_data->m_c;
          v264 = 0i64;
          while ( 2 )
          {
            v100 = *(signed int *)&v234[v98];
            if ( (_DWORD)v100 != result.m_enum )
            {
              v101 = v100;
              v102 = geomInOut.m_triangles.m_data[v101].m_c;
              v103 = geomInOut.m_triangles.m_data[v101].m_b;
              v104 = geomInOut.m_triangles.m_data[v101].m_a;
              if ( hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::doesTriangleIntersectObb(
                     &v285,
                     &v97[geomInOut.m_triangles.m_data[v101].m_a],
                     &v97[geomInOut.m_triangles.m_data[v101].m_b],
                     &v97[geomInOut.m_triangles.m_data[v101].m_c]) )
              {
                v268 = v102;
                v44 = 0;
                v266 = v104;
                v105 = 0i64;
                v267 = v103;
                do
                {
                  v106 = *(int *)((char *)&v266 + v105);
                  v107 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                             &v257,
                                             v106);
                  if ( v107 > v257.m_hashMod )
                  {
                    v108 = mesh.m_vertices.m_size;
                    v109 = mesh.m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
                    *(int *)((char *)&v258 + v105) = mesh.m_vertices.m_size;
                    v110 = &geomInOut.m_vertices.m_data[v106];
                    if ( v108 == v109 )
                    {
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &mesh.m_vertices,
                        16);
                      v108 = mesh.m_vertices.m_size;
                    }
                    v111 = *(int *)((char *)&v258 + v105);
                    mesh.m_vertices.m_data[v108] = (hkVector4f)v110->m_quad;
                    ++mesh.m_vertices.m_size;
                    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                      &v257,
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                      v106,
                      v111);
                  }
                  else
                  {
                    *(int *)((char *)&v258 + v105) = v257.m_elem[v107].val;
                  }
                  v105 += 4i64;
                }
                while ( v105 < 12 );
                v112 = v258;
                v99[1] = -1;
                v99 += 4;
                *(v99 - 6) = v112;
                *(v99 - 5) = v259;
                *(v99 - 4) = v260;
                v97 = geomInOut.m_vertices.m_data;
                v96 = mesh.m_triangles.m_size;
                v95 = v235;
                goto LABEL_113;
              }
              v44 = 0;
            }
            if ( (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= --v96 )
            {
              v262.m_enum = 0;
            }
            else
            {
              v113 = v96;
              if ( v96 < 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
                v113 = 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF);
              hkArrayUtil::_reserve(
                &v262,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &mesh.m_triangles,
                v113,
                16);
              v97 = geomInOut.m_vertices.m_data;
              v95 = v235;
            }
            mesh.m_triangles.m_size = v96;
LABEL_113:
            v98 = v264 + 4;
            ++v226;
            v264 += 4i64;
            if ( v226 >= v95 )
            {
              v7 = v288;
              v55 = v232;
              goto LABEL_115;
            }
            continue;
          }
        }
        v44 = 0;
        if ( p == points.m_data )
          v78 = 0;
        points.m_size = v78;
        v79 = (16 * (_DWORD)v242 + 127) & 0xFFFFFF80;
        v80 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v81 = (v79 + 15) & 0xFFFFFFF0;
        if ( v79 > v80->m_slabSize || &v77[v81] != v80->m_cur || v80->m_firstNonLifoEnd == v77 )
          hkLifoAllocator::slowBlockFree(v80, v77, v81);
        else
          v80->m_cur = v77;
        points.m_size = 0;
        if ( points.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            points.m_data,
            16 * points.m_capacityAndFlags);
      }
LABEL_153:
      v51 = v263 + 1;
      ++result.m_enum;
      ++v263;
    }
    while ( result.m_enum < geomInOut.m_triangles.m_size );
  }
  trisToRemove.m_storage.m_words.m_data = 0i64;
  trisToRemove.m_storage.m_words.m_size = 0;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v120 = v228.m_size / 3;
  v121 = (v228.m_size / 3 + 31) >> 5;
  v122 = v121;
  if ( v121 )
  {
    result.m_enum = 4 * v121;
    v123 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                             (int *)&result);
    v122 = result.m_enum / 4;
  }
  else
  {
    v123 = 0i64;
  }
  v124 = 2147483648;
  trisToRemove.m_storage.m_words.m_data = v123;
  if ( v122 )
    v124 = v122;
  trisToRemove.m_storage.m_words.m_size = v121;
  trisToRemove.m_storage.m_numBits = v120;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = v124;
  v125 = v124 & 0x3FFFFFFF;
  if ( v125 < v121 )
  {
    v126 = 2 * v125;
    v127 = v121;
    if ( v121 < v126 )
      v127 = v126;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &trisToRemove,
      v127,
      4);
    v123 = trisToRemove.m_storage.m_words.m_data;
  }
  trisToRemove.m_storage.m_words.m_size = v121;
  if ( v121 - 1 >= 0 )
  {
    v128 = (unsigned int)v121;
    v129 = v123;
    while ( v128 )
    {
      *v129 = 0;
      ++v129;
      --v128;
    }
  }
  v220 = 0i64;
  v221 = 0;
  v222 = 2147483648;
  v130 = 0;
  if ( geomInOut.m_triangles.m_size > 0 )
  {
    v131 = 0i64;
    do
    {
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             &v249,
             (unsigned int)geomInOut.m_triangles.m_data[v131].m_material,
             v7->m_defaultConstructionProperties.m_storage) & 2 )
      {
        v132 = v221;
        v133 = geomInOut.m_triangles.m_data;
        if ( v221 == (v222 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v220, 4);
          v132 = v221;
        }
        v220[v132] = v133[v131].m_a;
        v134 = geomInOut.m_triangles.m_data;
        v135 = v221 + 1;
        v221 = v135;
        if ( v135 == (v222 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v220, 4);
          v135 = v221;
        }
        v220[v135] = v134[v131].m_b;
        v136 = geomInOut.m_triangles.m_data;
        v137 = v221 + 1;
        v221 = v137;
        if ( v137 == (v222 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v220, 4);
          v137 = v221;
        }
        v220[v137] = v136[v131].m_c;
        ++v221;
      }
      ++v130;
      ++v131;
    }
    while ( v130 < geomInOut.m_triangles.m_size );
  }
  v280.m_vertices = &geomInOut.m_vertices;
  v280.m_tris = (hkArray<int,hkContainerHeapAllocator> *)&v220;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&v280.m_tree);
  hkaiTriangleSetAabbTester::init(&v280);
  v138 = v120;
  v139 = v7->m_painters.m_size + v224;
  *(_QWORD *)&v246[0].m_enum = v120;
  v140 = 1;
  v232 = v139;
  if ( v120 > 0 )
  {
    v141 = *(_QWORD *)&v246[0].m_enum;
    result.m_enum = 981668463;
    v142 = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
    v143 = 0i64;
    v144 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v145 = &v229.m_data[v228.m_data[v143]];
      v146 = &v229.m_data[v228.m_data[v143 + 1]];
      v147 = &v229.m_data[v228.m_data[v143 + 2]];
      normal.m_quad = _mm_add_ps(v146->m_quad, v145->m_quad);
      normal.m_quad = _mm_mul_ps(_mm_add_ps(v147->m_quad, normal.m_quad), (__m128)xmmword_141A711C0);
      v148 = _mm_sub_ps(v147->m_quad, v145->m_quad);
      v149 = _mm_sub_ps(v146->m_quad, v145->m_quad);
      v150 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v148, v148, 201), v149),
               _mm_mul_ps(_mm_shuffle_ps(v149, v149, 201), v148));
      v151 = _mm_shuffle_ps(v150, v150, 201);
      v152 = _mm_mul_ps(v151, v151);
      v153 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v152, v152, 85), _mm_shuffle_ps(v152, v152, 0)),
               _mm_shuffle_ps(v152, v152, 170));
      v154 = _mm_rsqrt_ps(v153);
      v155 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v153), (__m128)0i64);
      v156 = _mm_or_ps(
               _mm_and_ps(
                 _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpleps(v153, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v154, v153), v154)),
                       _mm_mul_ps(*(__m128 *)_xmm, v154))),
                   v151),
                 v155),
               _mm_andnot_ps(v155, v151));
      v157 = _mm_mul_ps(v142, v156);
      *(__m128 *)&v255.vfptr = v156;
      v158.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v144);
      v159 = _mm_mul_ps(v156, v52);
      normal.m_quad = _mm_add_ps(normal.m_quad, v157);
      v160 = _mm_add_ps(v145->m_quad, v159);
      v161 = _mm_add_ps(v146->m_quad, v159);
      v162 = v147->m_quad;
      aabb.m_min = (hkVector4f)xmmword_141A712A0;
      aabb.m_max = (hkVector4f)v158.m_quad;
      v163.m_quad = _mm_min_ps((__m128)xmmword_141A712A0, v145->m_quad);
      v164 = _mm_add_ps(v162, v159);
      aabb.m_min = (hkVector4f)v163.m_quad;
      v165.m_quad = _mm_max_ps(v158.m_quad, v145->m_quad);
      aabb.m_max = (hkVector4f)v165.m_quad;
      v166.m_quad = _mm_min_ps(v163.m_quad, v146->m_quad);
      aabb.m_min = (hkVector4f)v166.m_quad;
      v167.m_quad = _mm_max_ps(v165.m_quad, v146->m_quad);
      aabb.m_max = (hkVector4f)v167.m_quad;
      v168.m_quad = _mm_min_ps(v166.m_quad, v147->m_quad);
      points.m_data = (hkVector4f *)&hkaiTriangleSetAabbTester::AabbCollector::`vftable;
      aabb.m_min = (hkVector4f)v168.m_quad;
      v169 = _mm_max_ps(v167.m_quad, v147->m_quad);
      *(_QWORD *)&points.m_size = &trisPerFaceOut;
      p = v280.m_vertices;
      trisPerFaceOut.m_data = 0i64;
      aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(v168.m_quad, v160), v161), v164);
      aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(v169, v160), v161), v164);
      v243 = aabb;
      trisPerFaceOut.m_size = 0;
      trisPerFaceOut.m_capacityAndFlags = 2147483648;
      v242 = v280.m_tris;
      hkcdDynamicAabbTree::queryAabb(&v280.m_tree, &aabb, (hkcdAabbTreeQueries::AabbCollector *)&points);
      v170 = 0;
      if ( trisPerFaceOut.m_size > 0 )
      {
        v171 = 0i64;
        while ( 1 )
        {
          v172 = v220[3 * trisPerFaceOut.m_data[v171]];
          v173 = v220[3 * trisPerFaceOut.m_data[v171] + 1];
          v174 = v220[3 * trisPerFaceOut.m_data[v171] + 2];
          newTriangles = 0i64;
          if ( hkaiNavMeshGenerationUtils::_rayTriangleIntersect(
                 &normal,
                 (hkVector4f *)&v255,
                 &geomInOut.m_vertices.m_data[v172],
                 &geomInOut.m_vertices.m_data[v173],
                 &geomInOut.m_vertices.m_data[v174],
                 (hkSimdFloat32 *)&newTriangles)
            && *(float *)&newTriangles.m_data > 0.0
            && *(float *)&newTriangles.m_data < v52.m128_f32[0] )
          {
            break;
          }
          ++v170;
          ++v171;
          if ( v170 >= trisPerFaceOut.m_size )
            goto LABEL_188;
        }
        trisToRemove.m_storage.m_words.m_data[(signed __int64)v44 >> 5] |= v140;
      }
LABEL_188:
      trisPerFaceOut.m_size = 0;
      if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          trisPerFaceOut.m_data,
          4 * trisPerFaceOut.m_capacityAndFlags);
      v140 = __ROL4__(v140, 1);
      ++v44;
      v143 += 3i64;
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_capacityAndFlags = 2147483648;
      --v141;
    }
    while ( v141 );
    v7 = v288;
    v138 = *(_QWORD *)&v246[0].m_enum;
  }
  v279.m_vertices = (hkArray<hkVector4f,hkContainerHeapAllocator> *)&v229;
  v279.m_tris = (hkArray<int,hkContainerHeapAllocator> *)&v228;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&v279.m_tree);
  hkaiTriangleSetAabbTester::init(&v279);
  v175 = v229.m_data;
  v176 = 0;
  v177 = 1;
  v178 = 0;
  v226 = 1;
  v179 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_89999998), (__m128)LODWORD(FLOAT_0_89999998), 0);
  result.m_enum = 0;
  v180 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  *(__m128 *)&v255.vfptr = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
  if ( v138 > 0 )
  {
    v181 = 0i64;
    *(_QWORD *)&v254[0].m_enum = 0i64;
    v182 = v138;
    *(_QWORD *)&v252[0].m_enum = v138;
    v183 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    while ( 1 )
    {
      v184 = *(signed int *)((char *)v228.m_data + v181 + 8);
      v185 = *(signed int *)((char *)v228.m_data + v181);
      v186 = *(signed int *)((char *)v228.m_data + v181 + 4);
      v187 = v175[*(signed int *)((char *)v228.m_data + v181 + 8)].m_quad;
      v188 = v175[*(signed int *)((char *)v228.m_data + v181 + 4)].m_quad;
      v189 = _mm_mul_ps(
               _mm_add_ps(_mm_add_ps(v175[*(signed int *)((char *)v228.m_data + v181)].m_quad, v188), v187),
               (__m128)xmmword_141A711C0);
      v190 = _mm_sub_ps(v175[*(signed int *)((char *)v228.m_data + v181)].m_quad, v189);
      *(__m128 *)&v265.vfptr = v189;
      v265.m_edges = (hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator>)_mm_add_ps(_mm_mul_ps(v190, v179), v189);
      v265.m_faces = (hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator>)_mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_sub_ps(v188, v189),
                                                                                   v179),
                                                                                 v189);
      aabb.m_min = (hkVector4f)xmmword_141A712A0;
      v265.m_vertices = (hkArray<hkVector4f,hkContainerHeapAllocator>)_mm_add_ps(
                                                                        _mm_mul_ps(_mm_sub_ps(v187, v189), v179),
                                                                        v189);
      v191.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v183);
      aabb.m_max = (hkVector4f)v191.m_quad;
      aabb.m_min.m_quad = _mm_min_ps((__m128)xmmword_141A712A0, v175[v185].m_quad);
      v192.m_quad = _mm_max_ps(v191.m_quad, v175[v185].m_quad);
      aabb.m_max = (hkVector4f)v192.m_quad;
      aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v175[v186].m_quad);
      v193.m_quad = _mm_max_ps(v192.m_quad, v175[v186].m_quad);
      aabb.m_max = (hkVector4f)v193.m_quad;
      aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v175[v184].m_quad);
      v194 = _mm_max_ps(v193.m_quad, v175[v184].m_quad);
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_size = 0;
      points.m_data = (hkVector4f *)&hkaiTriangleSetAabbTester::AabbCollector::`vftable;
      trisPerFaceOut.m_capacityAndFlags = 2147483648;
      aabb.m_min.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v180);
      *(_QWORD *)&points.m_size = &trisPerFaceOut;
      aabb.m_max.m_quad = _mm_add_ps(v194, v180);
      v243 = aabb;
      p = v279.m_vertices;
      v242 = v279.m_tris;
      hkcdDynamicAabbTree::queryAabb(&v279.m_tree, &aabb, (hkcdAabbTreeQueries::AabbCollector *)&points);
      v175 = v229.m_data;
      if ( trisPerFaceOut.m_size <= 0 )
        goto LABEL_205;
      v195 = trisPerFaceOut.m_data;
      while ( 1 )
      {
        v196 = *v195;
        if ( (_DWORD)v196 != v178 )
          break;
LABEL_202:
        ++v176;
        ++v195;
        if ( v176 >= trisPerFaceOut.m_size )
        {
          v177 = v226;
          goto LABEL_204;
        }
      }
      v197 = *v195;
      if ( (trisToRemove.m_storage.m_words.m_data[v196 >> 5] >> (v196 & 0x1F)) & 1 )
        break;
      v198 = &v175[v228.m_data[3 * v197]];
      v199 = &v175[v228.m_data[3 * v197 + 1]];
      v200 = &v175[v228.m_data[3 * v197 + 2]];
      v201 = 0;
      while ( !pointInTriangle((hkVector4f *)&(&v265.vfptr)[2 * v201], v198, v199, v200, (hkSimdFloat32 *)&v255) )
      {
        if ( ++v201 >= 4 )
          goto LABEL_201;
      }
      v178 = result.m_enum;
      v177 = v226;
      trisToRemove.m_storage.m_words.m_data[(signed __int64)(signed int)result.m_enum >> 5] |= v226;
      v175 = v229.m_data;
LABEL_204:
      v182 = *(_QWORD *)&v252[0].m_enum;
      v181 = *(_QWORD *)&v254[0].m_enum;
LABEL_205:
      v176 = 0;
      trisPerFaceOut.m_size = 0;
      if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
      {
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          trisPerFaceOut.m_data,
          4 * trisPerFaceOut.m_capacityAndFlags);
        v175 = v229.m_data;
      }
      v177 = __ROL4__(v177, 1);
      ++v178;
      v181 += 12i64;
      --v182;
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_capacityAndFlags = 2147483648;
      result.m_enum = v178;
      v226 = v177;
      *(_QWORD *)&v254[0].m_enum = v181;
      *(_QWORD *)&v252[0].m_enum = v182;
      if ( !v182 )
      {
        v7 = v288;
        v138 = *(_QWORD *)&v246[0].m_enum;
        goto LABEL_209;
      }
    }
LABEL_201:
    v178 = result.m_enum;
    goto LABEL_202;
  }
LABEL_209:
  if ( (signed int)v232 > 0 )
  {
    v202 = 0i64;
    v203 = 1;
    if ( v138 > 0 )
    {
      v204 = v228.m_data + 2;
      do
      {
        v205 = (signed __int64)v176 >> 5;
        if ( !((trisToRemove.m_storage.m_words.m_data[v205] >> (v176 & 0x1F)) & 1) )
        {
          v206 = (signed int)*v204;
          normal.m_quad = _mm_add_ps(v175[*(v204 - 2)].m_quad, v175[*(v204 - 1)].m_quad);
          normal.m_quad = _mm_mul_ps(_mm_add_ps(v175[v206].m_quad, normal.m_quad), (__m128)xmmword_141A711C0);
          if ( hkaiCarverTree::carversContainPoint(&carverTree, &normal) )
          {
            trisToRemove.m_storage.m_words.m_data[v205] |= v203;
          }
          else
          {
            v207 = perTriangleDataInOut.m_data;
            v208 = v7->m_painterOverlapCallback;
            result.m_enum = 0;
            v207[v202] = hkaiCarverTree::getPaintedMaterialForPoint(
                           &carverTree,
                           &normal,
                           perTriangleDataInOut.m_data[v202],
                           v208,
                           &result);
          }
        }
        v203 = __ROL4__(v203, 1);
        ++v202;
        ++v176;
        v204 += 3;
      }
      while ( v202 < *(_QWORD *)&v246[0].m_enum );
    }
  }
  hkaiNavMeshGenerationUtils::_removeTriangles(
    &trisToRemove,
    (hkArray<int,hkContainerHeapAllocator> *)&v228,
    (hkArray<int,hkContainerHeapAllocator> *)&v250,
    (hkArray<int,hkContainerHeapAllocator> *)&v248,
    &perTriangleDataInOut,
    0i64);
  hkaiNavMesh::hkaiNavMesh(&v286);
  v209 = navMesh;
  v210 = &v286;
  if ( !v7->m_enableSimplification.m_bool )
    v210 = navMesh;
  hkaiNavMesh::setEdgeDataStriding(v210, &result, 0, 0);
  hkaiNavMesh::setEdgeDataStriding(v209, &result, 0, 0);
  hkaiNavMeshGenerationUtils::_createNavMesh(
    &result,
    (hkArray<hkVector4f,hkContainerHeapAllocator> *)&v229,
    (hkArray<int,hkContainerHeapAllocator> *)&v228,
    (hkArray<int,hkContainerHeapAllocator> *)&v248,
    (hkArray<int,hkContainerHeapAllocator> *)&v250,
    (hkArray<int,hkContainerHeapAllocator> *)&perTriangleDataInOut,
    &carverTree,
    v7,
    v210);
  v210->m_flags.m_storage |= 1u;
  if ( v210->m_faces.m_size && v210->m_edges.m_size )
  {
    hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(&raycaster);
    v211 = edgeConnectionRaycaster;
    if ( !edgeConnectionRaycaster )
    {
      hkaiEdgeGeometryRaycaster::init(&raycaster, &result, &geomOut);
      v211 = &raycaster;
    }
    hkaiEdgeGeometryRaycaster::setupForEdgeConnections(v211);
    for ( i = 0; i < v7->m_edgeConnectionIterations; ++i )
      hkaiNavMeshGenerationUtils::_connectEdges(&result, v7, v210, v211, i, 0i64, 0i64);
    hkaiNavMeshUtils::compactVertices(&result, v210, 0, 0);
    hkaiNavMeshGenerationUtils::_mergeVertices(&result, v210, 0.00039999999);
    hkaiNavMeshGenerationUtils::_removeDegenerateFaces(&result, v210);
    hkaiNavMeshUtils::validate(v210, 0);
    hkaiNavMeshSimplificationUtils::hertelMehlhorn(&result, v7, v210, 0i64, 0i64);
    v213 = callbacksa;
    hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(&result, v210, v7, &raycaster, callbacksa);
    hkaiNavMeshGenerationUtils::_pruneRegions(&result, v210, &v7->m_up, &v7->m_regionPruningSettings);
    hkaiNavMeshUtils::compactVertices(&result, v210, 0, 0);
    hkAabbUtil::calcAabb(v210->m_vertices.m_data, v210->m_vertices.m_size, &v210->m_aabb);
    v214 = _mm_sub_ps(v210->m_aabb.m_min.m_quad, v52);
    v210->m_aabb.m_max.m_quad = _mm_add_ps(v210->m_aabb.m_max.m_quad, v52);
    v210->m_aabb.m_min.m_quad = v214;
    if ( v7->m_enableSimplification.m_bool )
    {
      hkaiNavMesh::setEdgeDataStriding(v210, &result, 1, 0);
      hkaiNavMesh::setEdgeDataStriding(v209, &result, 1, 0);
      hkaiNavMeshUtils::validate(v210, 0);
      hkaiNavMeshSimplificationUtils::_simplifyNavMesh(v7, v210, v209, 0i64, v213);
      v209->m_flags.m_storage = v210->m_flags.m_storage;
    }
    hkaiNavMeshUtils::validate(v209, 1);
    v215 = 5;
    hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&raycaster);
  }
  else
  {
    hkErrStream::hkErrStream(&v255, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v255.vfptr,
      "Empty nav mesh created. This could happen if all input was unwalkable, or if all walkable geometry was contained in carvers.");
    hkError::messageWarning(1541620706, (const char *)&buf, "NavMesh\\hkaiNavMeshGenerationUtils_wallClimbing.cpp", 894);
    hkOstream::~hkOstream((hkOstream *)&v255.vfptr);
    v215 = 1;
    v209->m_aabb.m_min = (hkVector4f)aabbOut.m_quad;
    v209->m_aabb.m_max = (hkVector4f)aabbOut.m_quad;
  }
  hkaiNavMesh::~hkaiNavMesh(&v286);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&v279.m_tree);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&v280.m_tree);
  v221 = 0;
  if ( v222 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v220,
      4 * v222);
  v220 = 0i64;
  v222 = 2147483648;
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&trisToRemove);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geom);
  hkGeometry::~hkGeometry(&mesh);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&v278.m_tree);
  v238 = 0;
  if ( v239 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v237,
      4 * v239);
  v237 = 0i64;
  v239 = 2147483648;
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomOut);
  perTriangleDataInOut.m_size = 0;
  if ( perTriangleDataInOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      perTriangleDataInOut.m_data,
      4 * perTriangleDataInOut.m_capacityAndFlags);
  perTriangleDataInOut.m_data = 0i64;
  perTriangleDataInOut.m_capacityAndFlags = 2147483648;
  v250.m_size = 0;
  if ( v250.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v250.m_data,
      4 * v250.m_capacityAndFlags);
  v250.m_data = 0i64;
  v250.m_capacityAndFlags = 2147483648;
  v248.m_size = 0;
  if ( v248.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v248.m_data,
      4 * v248.m_capacityAndFlags);
  v248.m_data = 0i64;
  v248.m_capacityAndFlags = 2147483648;
  v228.m_size = 0;
  if ( v228.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v228.m_data,
      4 * v228.m_capacityAndFlags);
  v228.m_data = 0i64;
  v228.m_capacityAndFlags = 2147483648;
  v229.m_size = 0;
  if ( v229.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v229.m_data,
      16 * v229.m_capacityAndFlags);
  v229.m_data = 0i64;
  v229.m_capacityAndFlags = 2147483648;
  hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&v284);
  hkaiCarverTree::~hkaiCarverTree(&carverTree);
  v216 = array;
  v217 = v224 - 1;
  if ( v224 - 1 >= 0 )
  {
    do
    {
      v218 = (hkReferencedObject *)v216[v217];
      if ( v218 )
        hkReferencedObject::removeReference(v218);
      v216[v217--] = 0i64;
    }
    while ( v217 >= 0 );
    v216 = array;
  }
  v224 = 0;
  if ( v225 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v216,
      8 * v225);
  array = 0i64;
  v225 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v249,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v249);
  hkGeometry::~hkGeometry(&geomInOut);
  return v215;
}r::s_alloc.vfptr);
  _((AMD_HD3D *)&v249);
  hkGeometry::~hkGeometry(&geomInOut);
  return v215;
}

