// File Line: 62
// RVA: 0xB98280
__int64 __fastcall pointInTriangle(
        hkVector4f *point,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        hkVector4f *vertexC,
        hkSimdFloat32 *tolerance)
{
  __m128 m_quad; // xmm1
  int v6; // r11d
  int v8; // r8d
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 v11; // xmm14
  __m128 v12; // xmm7
  int v13; // ecx
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm7
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  float v21; // xmm2_4
  __m128 v23; // xmm1
  __int64 v24; // r10
  __m128 v25; // xmm9
  __m128 v26; // xmm0
  __int128 *v27; // r9
  __m128 v28; // xmm8
  __m128 v29; // xmm10
  int v30; // ecx
  unsigned int v31; // edx
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm6
  __m128 v39; // xmm2
  __m128 v40; // xmm6
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  __int128 v45[3]; // [rsp+0h] [rbp-C8h] BYREF

  m_quad = vertexB->m_quad;
  v6 = 1;
  v8 = 0;
  v9 = _mm_sub_ps(m_quad, vertexA->m_quad);
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
            _mm_cmple_ps(v16, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
              _mm_mul_ps(*(__m128 *)_xmm, v17))));
  v19 = _mm_mul_ps(vertexA->m_quad, v18);
  v20 = _mm_mul_ps(v11, v18);
  v21 = (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
              + _mm_shuffle_ps(v20, v20, 170).m128_f32[0])
      - (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
              + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]);
  if ( v21 < (float)(0.0 - tolerance->m_real.m128_f32[0]) )
    v13 = 1;
  if ( (v21 > tolerance->m_real.m128_f32[0]) | v13 )
    return 0i64;
  v23 = vertexB->m_quad;
  v24 = 3i64;
  v25 = *(__m128 *)&hkVector4fComparison_maskToComparison_102[60];
  v45[0] = (__int128)vertexA->m_quad;
  v26 = vertexC->m_quad;
  v27 = v45;
  v28 = _mm_shuffle_ps(v18, v18, 201);
  v45[2] = (__int128)v26;
  v45[1] = (__int128)v23;
  v29 = 0i64;
  do
  {
    v30 = v6;
    ++v27;
    v31 = (unsigned __int64)(1431655766i64 * v6++) >> 32;
    v32 = _mm_sub_ps((__m128)v45[v30 - 3 * ((v31 >> 31) + v31)], *((__m128 *)v27 - 1));
    v33 = _mm_sub_ps(_mm_mul_ps(v28, v32), _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v18));
    v34 = _mm_shuffle_ps(v33, v33, 201);
    v35 = _mm_mul_ps(v34, v34);
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
            _mm_shuffle_ps(v35, v35, 170));
    v37 = _mm_rsqrt_ps(v36);
    v38 = _mm_mul_ps(
            v34,
            _mm_andnot_ps(
              _mm_cmple_ps(v36, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                _mm_mul_ps(*(__m128 *)_xmm, v37))));
    v39 = _mm_mul_ps(v38, *((__m128 *)v27 - 1));
    v40 = _mm_shuffle_ps(
            v38,
            _mm_unpackhi_ps(
              v38,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                  _mm_shuffle_ps(v39, v39, 170)))),
            196);
    v41 = _mm_mul_ps(v11, v40);
    v42 = _mm_shuffle_ps(v41, _mm_unpackhi_ps(v41, v40), 196);
    v43 = _mm_add_ps(_mm_shuffle_ps(v42, v42, 78), v42);
    v44 = _mm_cmplt_ps((__m128)0i64, _mm_add_ps(_mm_shuffle_ps(v43, v43, 177), v43));
    v25 = _mm_and_ps(v25, v44);
    v29 = _mm_or_ps(v29, v44);
    --v24;
  }
  while ( v24 );
  LOBYTE(v8) = _mm_movemask_ps(v29) == 0;
  return v8 | (unsigned int)_mm_movemask_ps(v25);
}

// File Line: 115
// RVA: 0xB985B0
void __fastcall hkaiTriangleSetAabbTester::init(hkaiTriangleSetAabbTester *this)
{
  unsigned int v1; // edi
  int v3; // edx
  __int64 v4; // rbp
  __int64 v5; // r14
  __int64 v6; // rsi
  int *m_data; // rcx
  hkVector4f *v8; // rdx
  __int64 v9; // r8
  __int64 v10; // rax
  __int64 v11; // r9
  hkAabb aabb; // [rsp+20h] [rbp-38h] BYREF

  v1 = 0;
  v3 = this->m_tris->m_size / 3;
  v4 = v3;
  if ( v3 > 0 )
  {
    v5 = 0i64;
    v6 = 2i64;
    do
    {
      m_data = this->m_tris->m_data;
      v8 = this->m_vertices->m_data;
      v9 = m_data[v5];
      v10 = m_data[v6 - 1];
      v11 = m_data[v6];
      aabb.m_min.m_quad = _mm_min_ps(v8[m_data[v5]].m_quad, v8[m_data[v6 - 1]].m_quad);
      aabb.m_max.m_quad = _mm_max_ps(v8[v9].m_quad, v8[v10].m_quad);
      aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v8[v11].m_quad);
      aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v8[v11].m_quad);
      hkcdDynamicAabbTree::insert(&this->m_tree, &aabb, v1++);
      v5 += 3i64;
      v6 += 3i64;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 143
// RVA: 0xB98680
__int64 __fastcall hkaiTriangleSetAabbTester::AabbCollector::processLeaf(
        hkaiTriangleSetAabbTester::AabbCollector *this,
        int leafKey,
        hkAabb *leafAabb)
{
  signed int v3; // r8d
  int *m_data; // r9
  hkVector4f v7; // xmm0
  hkVector4f *v8; // r10
  __int64 v9; // rcx
  hkArray<int,hkContainerTempAllocator> *m_hits; // rbx

  v3 = 3 * leafKey;
  m_data = this->m_tris->m_data;
  v7.m_quad = (__m128)this->m_queryAabb.m_min;
  v8 = this->m_vertices->m_data;
  v9 = 3 * leafKey + 2;
  if ( (_mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(
              _mm_min_ps(_mm_min_ps(v8[m_data[v3]].m_quad, v8[m_data[v3 + 1]].m_quad), v8[m_data[v9]].m_quad),
              this->m_queryAabb.m_max.m_quad),
            _mm_cmple_ps(
              v7.m_quad,
              _mm_max_ps(_mm_max_ps(v8[m_data[v3]].m_quad, v8[m_data[v3 + 1]].m_quad), v8[m_data[v9]].m_quad)))) & 7) == 7 )
  {
    m_hits = this->m_hits;
    if ( m_hits->m_size == (m_hits->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, m_hits, 4);
    m_hits->m_data[m_hits->m_size++] = leafKey;
  }
  return 1i64;
}

// File Line: 185
// RVA: 0xB98150
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
        hkVector4f *axis,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *v2,
        hkSimdFloat32 *iminOut,
        hkSimdFloat32 *imaxOut)
{
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1

  v6 = _mm_mul_ps(v1->m_quad, axis->m_quad);
  v7 = _mm_mul_ps(v0->m_quad, axis->m_quad);
  v8 = _mm_unpackhi_ps(v7, v6);
  v9 = _mm_mul_ps(v2->m_quad, axis->m_quad);
  v10 = _mm_unpacklo_ps(v7, v6);
  v11 = _mm_movelh_ps(v10, v9);
  v12 = _mm_add_ps(_mm_shuffle_ps(v8, v9, 228), _mm_add_ps(v11, _mm_shuffle_ps(_mm_movehl_ps(v11, v10), v9, 212)));
  v13 = _mm_shuffle_ps(v12, v12, 85);
  v14 = _mm_shuffle_ps(v12, v12, 0);
  v15 = _mm_shuffle_ps(v12, v12, 170);
  iminOut->m_real = _mm_min_ps(v15, _mm_min_ps(v13, v14));
  imaxOut->m_real = _mm_max_ps(v15, _mm_max_ps(v13, v14));
}

// File Line: 194
// RVA: 0xB97D80
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *this,
        hkVector4f *axis,
        hkSimdFloat32 *imin,
        hkSimdFloat32 *imax)
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
char __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::doesTriangleIntersectObb(
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *this,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *v2)
{
  __m128 m_quad; // xmm2
  __m128 v9; // xmm8
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  hkVector4f v16; // xmm9
  __m128 *v17; // rdi
  int v18; // ebx
  hkVector4f v19; // xmm10
  __m128 v20; // xmm6
  int v21; // ecx
  int v22; // eax
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  bool v28; // cf
  __int64 v29; // rsi
  hkVector4f *m_axis; // rax
  __m128 *v31; // r14
  __m128 v32; // xmm6
  __int64 v33; // rbx
  __m128 *p_m_quad; // rdi
  __m128 v35; // xmm7
  __m128 v36; // xmm2
  int v37; // ecx
  int v38; // eax
  _BYTE imin[40]; // [rsp+28h] [rbp-79h] BYREF
  unsigned __int64 v40; // [rsp+50h] [rbp-51h] BYREF
  __int128 v41[5]; // [rsp+58h] [rbp-49h] BYREF
  hkVector4f *v0a; // [rsp+110h] [rbp+6Fh]

  m_quad = v0->m_quad;
  v9 = _mm_sub_ps(v1->m_quad, v0->m_quad);
  v10 = _mm_sub_ps(v2->m_quad, v0->m_quad);
  v41[0] = (__int128)v9;
  v41[1] = (__int128)v10;
  v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10));
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_mul_ps(m_quad, v12);
  *(__m128 *)&imin[8] = v12;
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v40 = v14.m128_u64[1];
  *(__m128 *)&imin[24] = v14;
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
    this,
    (hkVector4f *)&imin[8],
    (hkSimdFloat32 *)&v40,
    (hkSimdFloat32 *)((char *)v41 + 8));
  if ( *(float *)&imin[16] < v14.m128_f32[0] || v14.m128_f32[0] < *(float *)imin )
    return 0;
  v16.m_quad = (__m128)this->m_center;
  v17 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
  v18 = 0;
  v19.m_quad = (__m128)this->m_extent;
  while ( 1 )
  {
    *(__m128 *)&imin[8] = *(__m128 *)((char *)v17
                                    + (char *)this
                                    - (char *)`hkVector4f::getComponent::`2::indexToMask
                                    + 16);
    v20 = *(__m128 *)&imin[8];
    hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
      (hkVector4f *)&imin[8],
      v0,
      v1,
      v2,
      (hkSimdFloat32 *)&imin[32],
      (hkSimdFloat32 *)&imin[24]);
    v21 = 0;
    v22 = 0;
    v23 = _mm_and_ps(v19.m_quad, *v17);
    v24 = _mm_mul_ps(v16.m_quad, v20);
    v25 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
            _mm_shuffle_ps(v24, v24, 170));
    v26 = _mm_or_ps(_mm_shuffle_ps(v23, v23, 78), v23);
    *(__m128 *)imin = _mm_sub_ps(v25, _mm_or_ps(_mm_shuffle_ps(v26, v26, 177), v26));
    v27 = _mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v26, v26, 177), v26), v25);
    v28 = *(float *)&imin[24] < *(float *)imin;
    *(__m128 *)&imin[16] = v27;
    if ( v28 )
      v21 = 1;
    if ( v27.m128_f32[0] < *(float *)&imin[32] )
      v22 = 1;
    if ( v22 | v21 )
      return 0;
    ++v18;
    ++v17;
    if ( v18 >= 3 )
    {
      v29 = 0i64;
      m_axis = this->m_axis;
      v31 = (__m128 *)v41;
      v41[2] = (__int128)_mm_sub_ps(v10, v9);
LABEL_11:
      v32 = *v31;
      v33 = 0i64;
      p_m_quad = &m_axis->m_quad;
      v35 = _mm_shuffle_ps(v32, v32, 201);
      while ( 1 )
      {
        v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 201), v32), _mm_mul_ps(v35, *p_m_quad));
        *(__m128 *)&imin[8] = _mm_shuffle_ps(v36, v36, 201);
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
          (hkVector4f *)&imin[8],
          v0a,
          v1,
          v2,
          (hkSimdFloat32 *)&imin[32],
          (hkSimdFloat32 *)&imin[24]);
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getProjection(
          this,
          (hkVector4f *)&imin[8],
          (hkSimdFloat32 *)imin,
          (hkSimdFloat32 *)&imin[16]);
        v37 = 0;
        v38 = 0;
        if ( *(float *)&imin[24] < *(float *)imin )
          v37 = 1;
        if ( *(float *)&imin[16] < *(float *)&imin[32] )
          v38 = 1;
        if ( v38 | v37 )
          return 0;
        ++v33;
        ++p_m_quad;
        if ( v33 >= 3 )
        {
          ++v29;
          ++v31;
          m_axis = this->m_axis;
          if ( v29 < 3 )
            goto LABEL_11;
          return 1;
        }
      }
    }
  }
}

// File Line: 257
// RVA: 0xB981D0
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getClosestPointOnLine(
        hkVector4f *p,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *out)
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
                      _mm_cmplt_ps(
                        v8,
                        _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999999eN9), (__m128)LODWORD(FLOAT_9_9999999eN9), 0)),
                      _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v8)), v9), v6))),
                  a->m_quad);
}

// File Line: 268
// RVA: 0xB97AF0
void __fastcall hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::makeBoxFromExtrudedTriangle(
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb *this,
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *c,
        hkVector4f *normal,
        hkSimdFloat32 *extrusionLength)
{
  __m128 m_quad; // xmm10
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
  hkVector4f v30; // xmm0
  __m128 v31; // xmm3
  __m128 v32; // xmm10
  __m128 v33; // xmm3
  hkVector4f v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  hkVector4f ba; // [rsp+20h] [rbp-B8h] BYREF
  hkVector4f aa; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f p; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f out; // [rsp+50h] [rbp-88h] BYREF

  m_quad = c->m_quad;
  v8 = _mm_sub_ps(a->m_quad, b->m_quad);
  v9 = _mm_mul_ps(v8, v8);
  v10 = (float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
      + _mm_shuffle_ps(v9, v9, 170).m128_f32[0];
  v11 = _mm_sub_ps(a->m_quad, c->m_quad);
  v12 = _mm_mul_ps(v11, v11);
  v13 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
      + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
  v14 = _mm_sub_ps(b->m_quad, c->m_quad);
  v15 = _mm_mul_ps(v14, v14);
  v16 = (float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
      + _mm_shuffle_ps(v15, v15, 170).m128_f32[0];
  if ( v10 <= v13 )
  {
    if ( v13 > v16 )
    {
      v18 = c->m_quad;
      v17 = a->m_quad;
      m_quad = b->m_quad;
      goto LABEL_7;
    }
LABEL_6:
    v18 = c->m_quad;
    v17 = b->m_quad;
    m_quad = a->m_quad;
    goto LABEL_7;
  }
  if ( v10 <= v16 )
    goto LABEL_6;
  v17 = a->m_quad;
  v18 = b->m_quad;
LABEL_7:
  ba.m_quad = v18;
  v19 = _mm_sub_ps(v18, v17);
  p.m_quad = m_quad;
  aa.m_quad = v17;
  v20 = _mm_mul_ps(v19, v19);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_andnot_ps(
          _mm_cmple_ps(v21, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)), _mm_mul_ps(*(__m128 *)_xmm, v22)));
  v24 = _mm_mul_ps(v19, v23);
  v25 = _mm_mul_ps(v23, v21);
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::getClosestPointOnLine(&p, &aa, &ba, &out);
  v26 = _mm_sub_ps(m_quad, out.m_quad);
  v27 = _mm_mul_ps(v26, v26);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_rsqrt_ps(v28);
  v30.m_quad = _mm_add_ps(_mm_mul_ps(normal->m_quad, extrusionLength->m_real), v17);
  v31 = _mm_andnot_ps(
          _mm_cmple_ps(v28, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)), _mm_mul_ps(*(__m128 *)_xmm, v29)));
  this->m_center = (hkVector4f)v30.m_quad;
  v32 = _mm_mul_ps(v26, v31);
  v33 = _mm_mul_ps(v31, v28);
  v34.m_quad = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v25, (__m128)xmmword_141A711B0), v24), v30.m_quad);
  this->m_center = (hkVector4f)v34.m_quad;
  this->m_center.m_quad = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v33, (__m128)xmmword_141A711B0), v32), v34.m_quad);
  v35 = normal->m_quad;
  this->m_axis[1].m_quad = v24;
  this->m_axis[0].m_quad = v35;
  this->m_axis[2].m_quad = v32;
  v36 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000099999997), (__m128)LODWORD(FLOAT_0_000099999997), 0);
  this->m_extent.m_quad = _mm_movelh_ps(
                            _mm_unpacklo_ps(
                              _mm_add_ps(v36, extrusionLength->m_real),
                              _mm_add_ps(_mm_mul_ps(v25, (__m128)xmmword_141A711B0), v36)),
                            _mm_unpacklo_ps(_mm_add_ps(_mm_mul_ps(v33, (__m128)xmmword_141A711B0), v36), v36));
}

// File Line: 334
// RVA: 0xB953A0
__int64 __fastcall hkaiNavMeshGenerationUtils::generateWallClimbingNavMesh(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *triMeshIn,
        hkaiNavMesh *navMeshOut,
        hkaiNavMeshGenerationProgressCallback *_callbacks)
{
  hkaiNavMeshGenerationOutputs outputs; // [rsp+30h] [rbp-228h] BYREF
  hkaiNavMeshGenerationSettings inputa; // [rsp+60h] [rbp-1F8h] BYREF

  hkaiNavMeshGenerationOutputs::hkaiNavMeshGenerationOutputs(&outputs);
  outputs.m_navMesh = navMeshOut;
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&inputa);
  hkaiNavMeshGenerationSettings::operator=(&inputa, input);
  inputa.m_wallClimbingSettings.m_enableWallClimbing.m_bool = 1;
  LODWORD(navMeshOut) = hkaiNavMeshGenerationUtils::_generateNavMesh(&inputa, triMeshIn, &outputs, _callbacks, 0i64);
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&inputa);
  return (unsigned int)navMeshOut;
}

// File Line: 348
// RVA: 0xB95440
__int64 __fastcall hkaiNavMeshGenerationUtils::generateWallClimbingNavMeshDeprecated(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *triMeshIn,
        hkaiNavMesh *navMeshOut)
{
  hkaiNavMeshGenerationSettings inputa; // [rsp+30h] [rbp-1F8h] BYREF

  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&inputa);
  hkaiNavMeshGenerationSettings::operator=(&inputa, input);
  inputa.m_wallClimbingSettings.m_enableWallClimbing.m_bool = 1;
  LODWORD(input) = hkaiNavMeshGenerationUtils::_generateWallClimbingNavMeshDeprecated(
                     &inputa,
                     triMeshIn,
                     navMeshOut,
                     0i64,
                     0i64);
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&inputa);
  return (unsigned int)input;
}

// File Line: 368
// RVA: 0xB954C0
__int64 __fastcall hkaiNavMeshGenerationUtils::_generateWallClimbingNavMeshDeprecated(
        hkaiNavMeshGenerationSettings *input,
        hkGeometry *triMeshIn,
        hkaiNavMesh *navMeshOut,
        hkaiNavMeshGenerationProgressCallback *callbacks,
        hkaiEdgeGeometryRaycaster *edgeConnectionRaycaster)
{
  hkaiNavMeshGenerationSettings *v7; // r14
  __int64 v8; // rax
  int m_size; // r8d
  int v10; // ebx
  __int64 v11; // rdi
  int v12; // r9d
  int m_capacityAndFlags; // eax
  int v14; // r9d
  int v15; // edi
  __int64 v16; // r15
  int v17; // r13d
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  hkRefPtr<hkaiVolume const > *v21; // rbx
  __int64 v22; // rdi
  hkReferencedObject *m_pntr; // rcx
  hkRefPtr<hkaiVolume const > *m_data; // rbx
  hkRefPtr<hkaiVolume const > *v25; // rsi
  __int64 i; // rdi
  hkReferencedObject *v27; // rcx
  hkReferencedObject *v28; // rcx
  hkaiVolume *v29; // rax
  hkReferencedObject **p_m_pntr; // rdi
  __int64 v31; // rsi
  char *v32; // r12
  __m128 m_quad; // xmm0
  _QWORD **Value; // rax
  hkaiInvertedAabbVolume *v35; // rax
  hkaiVolume *v36; // rax
  hkaiVolume *v37; // rbx
  int v38; // ecx
  hkRefPtr<hkaiVolume const > *v39; // rdi
  hkRefPtr<hkaiVolume const > *v40; // rdx
  __int64 v41; // rsi
  hkReferencedObject *v42; // rcx
  int v43; // r15d
  int v44; // eax
  int v45; // edi
  int v46; // r9d
  int v47; // r8d
  __int64 v48; // rdx
  __int64 v49; // rdi
  __int64 v50; // rcx
  __m128 v51; // xmm13
  unsigned __int64 m_storage; // r8
  __int64 v53; // rdi
  int v54; // r13d
  hkVector4f *v55; // rsi
  hkVector4f *v56; // r15
  hkVector4f *v57; // r12
  bool v58; // zf
  __m128 v59; // xmm0
  __m128 v60; // xmm2
  __m128 v61; // xmm6
  __m128 v62; // xmm6
  __m128 v63; // xmm1
  __m128 v64; // xmm3
  __m128 v65; // xmm2
  __m128 v66; // xmm5
  hkLifoAllocator *v67; // rax
  hkVector4f *m_cur; // rdx
  hkVector4f *v69; // rcx
  hkVector4f v70; // xmm0
  hkVector4f v71; // xmm0
  hkVector4f v72; // xmm0
  BOOL isWalkableBySlope; // eax
  char *v74; // rbx
  int v75; // eax
  signed int v76; // edi
  hkLifoAllocator *v77; // rax
  int v78; // r8d
  signed int v79; // edi
  hkLifoAllocator *v80; // rax
  int v81; // r8d
  __m128 v82; // xmm5
  __m128 v83; // xmm1
  __m128 v84; // xmm2
  __m128 v85; // xmm1
  __m128 v86; // xmm2
  __m128 v87; // xmm5
  hkVector4f v88; // xmm3
  hkVector4f v89; // xmm3
  hkVector4f v90; // xmm3
  int v91; // esi
  int v92; // edi
  hkVector4f *v93; // rbx
  __int64 v94; // rcx
  int *p_m_c; // r14
  __int64 v96; // rcx
  __int64 v97; // rcx
  int m_c; // r15d
  int m_b; // r12d
  int m_a; // r13d
  __int64 v101; // rdi
  unsigned __int64 v102; // rsi
  int Key; // eax
  int v104; // ecx
  int v105; // eax
  hkVector4f *v106; // rbx
  unsigned __int64 v107; // r9
  unsigned int mStereo; // eax
  int v109; // r9d
  int v110; // ebx
  __int64 v111; // rdi
  int v112; // edx
  __int64 v113; // rcx
  int v114; // edi
  int v115; // ecx
  int v116; // r13d
  int v117; // edi
  __int32 v118; // ecx
  unsigned int *v119; // r8
  int v120; // eax
  int v121; // eax
  int v122; // eax
  int v123; // r9d
  __int64 v124; // rcx
  unsigned int *v125; // rdi
  int v126; // ebx
  __int64 v127; // rdi
  int v128; // ecx
  hkGeometry::Triangle *v129; // rsi
  hkGeometry::Triangle *v130; // rsi
  int v131; // ecx
  hkGeometry::Triangle *v132; // rsi
  int v133; // ecx
  __int64 v134; // r12
  int v135; // eax
  int v136; // esi
  __int64 v137; // r13
  __m128 v138; // xmm9
  __int64 v139; // r12
  __m128 v140; // xmm12
  hkVector4f *v141; // rdx
  hkVector4f *v142; // rdi
  hkVector4f *v143; // r8
  __m128 v144; // xmm1
  __m128 v145; // xmm2
  __m128 v146; // xmm6
  __m128 v147; // xmm6
  __m128 v148; // xmm1
  __m128 v149; // xmm3
  __m128 v150; // xmm2
  __m128 v151; // xmm4
  hkReferencedObject v152; // xmm5
  __m128 v153; // xmm0
  __m128 v154; // xmm5
  __m128 v155; // xmm0
  __m128 v156; // xmm1
  __m128 v157; // xmm2
  __m128 v158; // xmm2
  hkVector4f v159; // xmm4
  __m128 v160; // xmm3
  int v161; // ebx
  __int64 v162; // rdi
  __int64 v163; // r8
  __int64 v164; // r9
  __int64 v165; // rax
  hkVector4f *v166; // r15
  int v167; // r13d
  int v168; // ebx
  hkResultEnum m_enum; // edi
  __m128 v170; // xmm6
  __m128 v171; // xmm7
  __int64 v172; // rsi
  __int64 v173; // r14
  __m128 v174; // xmm8
  __int64 v175; // rax
  __int64 v176; // rcx
  __int64 v177; // rdx
  __m128 v178; // xmm3
  __m128 v179; // xmm1
  hkReferencedObject v180; // xmm2
  __m128 v181; // xmm0
  __m128 v182; // xmm0
  int *v183; // r12
  __int64 v184; // rcx
  __int64 v185; // rdi
  hkVector4f *v186; // rbx
  hkVector4f *v187; // rsi
  hkVector4f *v188; // r14
  int v189; // edi
  __int64 v190; // rsi
  int v191; // ebx
  unsigned int *v192; // r12
  __int64 v193; // rdi
  __int64 v194; // rax
  int *v195; // rdi
  hkaiMaterialPainter::ResolveOverlapCallback *m_painterOverlapCallback; // r9
  hkaiNavMesh *v197; // r15
  hkaiNavMesh *v198; // rbx
  hkaiEdgeGeometryRaycaster *p_raycaster; // rsi
  int k; // edi
  hkaiNavMeshGenerationProgressCallback *v201; // rsi
  __m128 v202; // xmm1
  unsigned int v203; // esi
  hkRefPtr<hkaiVolume const > *v204; // rbx
  __int64 v205; // rdi
  hkReferencedObject *v206; // rcx
  hkArray<int,hkContainerHeapAllocator> trisPerFaceOut; // [rsp+50h] [rbp-B0h] BYREF
  int *v208; // [rsp+60h] [rbp-A0h] BYREF
  int v209; // [rsp+68h] [rbp-98h]
  int v210; // [rsp+6Ch] [rbp-94h]
  hkArrayBase<hkRefPtr<hkaiVolume const > > array; // [rsp+70h] [rbp-90h] BYREF
  int v212; // [rsp+80h] [rbp-80h]
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> newTriangles; // [rsp+90h] [rbp-70h] BYREF
  hkArrayBase<unsigned int> v214; // [rsp+A0h] [rbp-60h] BYREF
  hkArrayBase<hkVector4f> v215; // [rsp+B0h] [rbp-50h] BYREF
  hkArrayBase<int> perTriangleDataInOut; // [rsp+C0h] [rbp-40h] BYREF
  hkArray<int,hkContainerHeapAllocator> trisOut; // [rsp+D0h] [rbp-30h] BYREF
  unsigned int m_material; // [rsp+E0h] [rbp-20h]
  hkAabb aabb; // [rsp+F0h] [rbp-10h] BYREF
  char *v220; // [rsp+110h] [rbp+10h] BYREF
  int v221; // [rsp+118h] [rbp+18h]
  int v222; // [rsp+11Ch] [rbp+1Ch]
  char *v223; // [rsp+120h] [rbp+20h] BYREF
  int v224; // [rsp+128h] [rbp+28h]
  int v225; // [rsp+12Ch] [rbp+2Ch]
  hkArrayBase<hkVector4f> points; // [rsp+130h] [rbp+30h] BYREF
  void *p; // [rsp+140h] [rbp+40h]
  hkArray<int,hkContainerHeapAllocator> *m_tris; // [rsp+148h] [rbp+48h]
  hkAabb v229; // [rsp+150h] [rbp+50h]
  hkVector4f normal; // [rsp+170h] [rbp+70h] BYREF
  hkArray<int,hkContainerHeapAllocator> triConnectivityOut; // [rsp+180h] [rbp+80h] BYREF
  hkResult v232[2]; // [rsp+190h] [rbp+90h] BYREF
  hkBitField trisToRemove; // [rsp+198h] [rbp+98h] BYREF
  hkArrayBase<unsigned int> v234; // [rsp+1B0h] [rbp+B0h] BYREF
  AMD_HD3D v235; // [rsp+1C0h] [rbp+C0h] BYREF
  hkGeometry geomInOut; // [rsp+1E0h] [rbp+E0h] BYREF
  hkResult v237[2]; // [rsp+210h] [rbp+110h] BYREF
  hkArray<int,hkContainerHeapAllocator> materialsOut; // [rsp+218h] [rbp+118h] BYREF
  hkResult v239[2]; // [rsp+228h] [rbp+128h] BYREF
  hkErrStream v240; // [rsp+230h] [rbp+130h] BYREF
  hkGeometry mesh; // [rsp+250h] [rbp+150h] BYREF
  AMD_HD3D v242; // [rsp+280h] [rbp+180h] BYREF
  hkResult v243; // [rsp+2A0h] [rbp+1A0h] BYREF
  hkResult v244; // [rsp+2A4h] [rbp+1A4h] BYREF
  __int64 j; // [rsp+2A8h] [rbp+1A8h]
  __int64 v246; // [rsp+2B0h] [rbp+1B0h]
  hkaiEdgeGeometry v247; // [rsp+2C0h] [rbp+1C0h] BYREF
  int v248[4]; // [rsp+310h] [rbp+210h]
  hkResult v249; // [rsp+320h] [rbp+220h] BYREF
  hkResult v250; // [rsp+324h] [rbp+224h] BYREF
  hkResult v251; // [rsp+328h] [rbp+228h] BYREF
  hkResult v252; // [rsp+32Ch] [rbp+22Ch] BYREF
  hkaiEdgeGeometry extrudeGeom; // [rsp+330h] [rbp+230h] BYREF
  hkaiSelfIntersectBooleanFilter2 filter; // [rsp+380h] [rbp+280h] BYREF
  hkaiCarverTree carverTree; // [rsp+3E0h] [rbp+2E0h] BYREF
  hkSimdFloat32 extrusionLength; // [rsp+410h] [rbp+310h] BYREF
  hkaiEdgeGeometry geomA; // [rsp+420h] [rbp+320h] BYREF
  hkaiTriangleSetAabbTester v258; // [rsp+470h] [rbp+370h] BYREF
  hkaiTriangleSetAabbTester v259; // [rsp+4C0h] [rbp+3C0h] BYREF
  hkaiTriangleSetAabbTester v260; // [rsp+510h] [rbp+410h] BYREF
  hkaiEdgeGeometry geom; // [rsp+560h] [rbp+460h] BYREF
  hkaiEdgeGeometry geomOut; // [rsp+5B0h] [rbp+4B0h] BYREF
  hkaiEdgeGeometryRaycaster raycaster; // [rsp+600h] [rbp+500h] BYREF
  hkaiGeometryToEdgeGeometryConverter v264; // [rsp+670h] [rbp+570h] BYREF
  hkaiNavMeshGenerationUtils::ExtrudedTriangleObb v265; // [rsp+6D0h] [rbp+5D0h] BYREF
  hkaiNavMesh v266; // [rsp+720h] [rbp+620h] BYREF
  hkaiBooleanOperation buf; // [rsp+7D0h] [rbp+6D0h] BYREF
  hkResult result; // [rsp+AA8h] [rbp+9A8h] BYREF
  hkaiNavMesh *navMesh; // [rsp+AB0h] [rbp+9B0h]
  hkaiNavMeshGenerationProgressCallback *callbacksa; // [rsp+AB8h] [rbp+9B8h]

  callbacksa = callbacks;
  navMesh = navMeshOut;
  v7 = input;
  if ( !triMeshIn->m_triangles.m_size )
  {
    hkErrStream::hkErrStream(&v240, &buf, 512);
    hkOstream::operator<<(&v240, "Passed in empty triMesh to generateWallClimbingNavMesh()");
    hkError::messageWarning(1060047688, (const char *)&buf, "NavMesh\\hkaiNavMeshGenerationUtils_wallClimbing.cpp", 381);
    hkOstream::~hkOstream(&v240);
    v8 = 1i64;
    navMeshOut->m_aabb.m_min = (hkVector4f)aabbOut.m_quad;
    navMeshOut->m_aabb.m_max = (hkVector4f)aabbOut.m_quad;
    return v8;
  }
  if ( !HK_flyingcolors_ai_0.m_bool )
  {
    hkaiCheckKeycode(input, triMeshIn, navMeshOut);
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_0);
    if ( !HK_flyingcolors_ai_0.m_bool )
    {
      hkErrStream::hkErrStream(&v240, &buf, 512);
      hkOstream::operator<<(&v240, "Invalid keycode. Exiting nav mesh generation.");
      hkError::messageWarning(
        691989308,
        (const char *)&buf,
        "NavMesh\\hkaiNavMeshGenerationUtils_wallClimbing.cpp",
        393);
      hkOstream::~hkOstream(&v240);
      v8 = 3i64;
      navMeshOut->m_aabb.m_min = (hkVector4f)aabbOut.m_quad;
      navMeshOut->m_aabb.m_max = (hkVector4f)aabbOut.m_quad;
      return v8;
    }
  }
  if ( v7->m_saveInputSnapshot.m_bool )
    hkaiNavMeshGenerationUtils::_saveSnapshot(v7, triMeshIn);
  hkGeometry::hkGeometry(&geomInOut, triMeshIn);
  hkaiNavMeshGenerationUtils::quantize(&geomInOut, v7->m_quantizationGridSize);
  m_size = v7->m_materialMap.m_size;
  *(_QWORD *)&v235.mEnableStereo = 0i64;
  v235.mWidth = 0;
  v235.mHeight = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v235,
    &hkContainerHeapAllocator::s_alloc,
    m_size);
  v10 = 0;
  if ( v7->m_materialMap.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v235,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned int)v7->m_materialMap.m_data[v11].m_materialIndex,
        v7->m_materialMap.m_data[v11].m_flags.m_storage);
      ++v10;
      ++v11;
    }
    while ( v10 < v7->m_materialMap.m_size );
  }
  v12 = v7->m_carvers.m_size;
  m_capacityAndFlags = 0x80000000;
  array.m_data = 0i64;
  v14 = v12 + 1;
  v15 = 0;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  if ( v14 > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v14, 8);
    m_capacityAndFlags = array.m_capacityAndFlags;
    v15 = array.m_size;
  }
  v16 = v7->m_carvers.m_size;
  v17 = v7->m_carvers.m_size;
  if ( (int)v16 > v15 )
    v17 = v15;
  v18 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < (int)v16 )
  {
    v19 = 2 * v18;
    v20 = v7->m_carvers.m_size;
    if ( (int)v16 < v19 )
      v20 = v19;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v20, 8);
  }
  v21 = &array.m_data[v16];
  v22 = v15 - (int)v16 - 1;
  if ( (int)v22 >= 0 )
  {
    do
    {
      m_pntr = v21[v22].m_pntr;
      if ( m_pntr )
        hkReferencedObject::removeReference(m_pntr);
      v21[v22--].m_pntr = 0i64;
    }
    while ( v22 >= 0 );
  }
  m_data = v7->m_carvers.m_data;
  v25 = array.m_data;
  for ( i = 0i64; i < v17; v25[i - 1].m_pntr = v29 )
  {
    v27 = m_data[i].m_pntr;
    if ( v27 )
      hkReferencedObject::addReference(v27);
    v28 = v25[i].m_pntr;
    if ( v28 )
      hkReferencedObject::removeReference(v28);
    v29 = m_data[i++].m_pntr;
  }
  p_m_pntr = &v7->m_carvers.m_data[v17].m_pntr;
  v31 = (int)v16 - v17;
  if ( (int)v16 - v17 > 0 )
  {
    v32 = (char *)((char *)&array.m_data[v17] - (char *)p_m_pntr);
    do
    {
      if ( (hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v32) )
      {
        if ( *p_m_pntr )
          hkReferencedObject::addReference(*p_m_pntr);
        *(hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v32) = *p_m_pntr;
      }
      ++p_m_pntr;
      --v31;
    }
    while ( v31 );
  }
  m_quad = v7->m_boundsAabb.m_max.m_quad;
  array.m_size = v16;
  if ( (_mm_movemask_ps(_mm_cmple_ps(m_quad, v7->m_boundsAabb.m_min.m_quad)) & 7) == 0 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v35 = (hkaiInvertedAabbVolume *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 96i64);
    if ( v35 )
    {
      hkaiInvertedAabbVolume::hkaiInvertedAabbVolume(v35, &v7->m_boundsAabb);
      v37 = v36;
    }
    else
    {
      v37 = 0i64;
    }
    v38 = array.m_size;
    if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &array, 8);
      v38 = array.m_size;
    }
    v39 = array.m_data;
    v40 = &array.m_data[v38];
    if ( v40 )
    {
      v40->m_pntr = 0i64;
      v38 = array.m_size;
      v39 = array.m_data;
    }
    v41 = v38;
    array.m_size = v38 + 1;
    v42 = v39[v38].m_pntr;
    if ( v42 && v42 != v37 )
      hkReferencedObject::removeReference(v42);
    v39[v41].m_pntr = v37;
  }
  hkaiCarverTree::hkaiCarverTree(&carverTree);
  hkaiCarverTree::init(&carverTree, &result, &array, &v7->m_painters);
  hkaiNavMeshGenerationUtils::setCarvedMaterialsDeprecated(
    &geomInOut,
    v7->m_carvedCuttingMaterialDeprecated,
    v7->m_carvedMaterialDeprecated,
    (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v235,
    v7->m_defaultConstructionProperties.m_storage,
    &carverTree);
  if ( v7->m_weldInputVertices.m_bool )
    hkGeometryUtils::weldVertices(&geomInOut, v7->m_weldThreshold);
  hkaiGeometryToEdgeGeometryConverter::hkaiGeometryToEdgeGeometryConverter(&v264);
  v43 = 0;
  v215.m_data = 0i64;
  v215.m_size = 0;
  v215.m_capacityAndFlags = 0x80000000;
  v214.m_data = 0i64;
  v214.m_size = 0;
  v214.m_capacityAndFlags = 0x80000000;
  v234.m_data = 0i64;
  v234.m_size = 0;
  v234.m_capacityAndFlags = 0x80000000;
  v235.mStereo = 0i64;
  v235.mExtension = (IAmdDxExt *)0x8000000000000000i64;
  perTriangleDataInOut.m_data = 0i64;
  perTriangleDataInOut.m_size = 0;
  perTriangleDataInOut.m_capacityAndFlags = 0x80000000;
  newTriangles.m_data = 0i64;
  newTriangles.m_size = 0;
  newTriangles.m_capacityAndFlags = 0x80000000;
  if ( geomInOut.m_triangles.m_size > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &newTriangles, geomInOut.m_triangles.m_size, 16);
  hkGeometryUtils::removeDuplicateTrianglesFast(&result, &geomInOut, &newTriangles);
  newTriangles.m_size = 0;
  if ( newTriangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      newTriangles.m_data,
      16 * newTriangles.m_capacityAndFlags);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomOut);
  hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
    &v264,
    &result,
    &geomInOut,
    (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
    &geomOut);
  v44 = geomInOut.m_triangles.m_size;
  v45 = 3 * geomInOut.m_triangles.m_size;
  v223 = 0i64;
  v224 = 0;
  v225 = 0x80000000;
  if ( 3 * geomInOut.m_triangles.m_size > 0 )
  {
    v46 = 3 * geomInOut.m_triangles.m_size;
    if ( v45 < 0 )
      v46 = 0;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v223, v46, 4);
    v44 = geomInOut.m_triangles.m_size;
  }
  v224 = v45;
  v47 = 0;
  if ( v44 > 0 )
  {
    v48 = 0i64;
    v49 = 0i64;
    do
    {
      ++v47;
      ++v49;
      v48 += 12i64;
      *(_DWORD *)&v223[v48 - 12] = geomInOut.m_triangles.m_data[v49 - 1].m_a;
      *(_DWORD *)&v223[v48 - 8] = geomInOut.m_triangles.m_data[v49 - 1].m_b;
      *(_DWORD *)&v223[v48 - 4] = geomInOut.m_triangles.m_data[v49 - 1].m_c;
    }
    while ( v47 < geomInOut.m_triangles.m_size );
  }
  v258.m_vertices = &geomInOut.m_vertices;
  v258.m_tris = (hkArray<int,hkContainerHeapAllocator> *)&v223;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&v258.m_tree);
  hkaiTriangleSetAabbTester::init(&v258);
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geomA);
  hkaiEdgeGeometry::setForSingleTriangle(&geomA, &result);
  mesh.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  *(_DWORD *)&mesh.m_memSizeAndFlags = 0x1FFFF;
  mesh.m_vertices.m_data = 0i64;
  mesh.m_vertices.m_size = 0;
  mesh.m_vertices.m_capacityAndFlags = 0x80000000;
  mesh.m_triangles.m_data = 0i64;
  mesh.m_triangles.m_size = 0;
  mesh.m_triangles.m_capacityAndFlags = 0x80000000;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&geom);
  v50 = 0i64;
  v51 = _mm_shuffle_ps((__m128)LODWORD(v7->m_characterHeight), (__m128)LODWORD(v7->m_characterHeight), 0);
  result.m_enum = HK_SUCCESS;
  extrusionLength.m_real = v51;
  for ( j = 0i64; result.m_enum < geomInOut.m_triangles.m_size; ++j )
  {
    m_storage = v7->m_defaultConstructionProperties.m_storage;
    v53 = v50;
    m_material = geomInOut.m_triangles.m_data[v50].m_material;
    v54 = m_material;
    if ( (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v235,
            m_material,
            m_storage) & 1) != 0 )
    {
      v55 = &geomInOut.m_vertices.m_data[geomInOut.m_triangles.m_data[v53].m_a];
      v56 = &geomInOut.m_vertices.m_data[geomInOut.m_triangles.m_data[v53].m_b];
      v57 = &geomInOut.m_vertices.m_data[geomInOut.m_triangles.m_data[v53].m_c];
      *geomA.m_vertices.m_data = (hkVector4f)v55->m_quad;
      geomA.m_vertices.m_data[1] = (hkVector4f)v56->m_quad;
      geomA.m_vertices.m_data[2] = (hkVector4f)v57->m_quad;
      v58 = v7->m_wallClimbingSettings.m_excludeWalkableFaces.m_bool == 0;
      v59 = _mm_sub_ps(v57->m_quad, v55->m_quad);
      v60 = _mm_sub_ps(v56->m_quad, v55->m_quad);
      v61 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v60), _mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v59));
      v62 = _mm_shuffle_ps(v61, v61, 201);
      v63 = _mm_mul_ps(v62, v62);
      v64 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
              _mm_shuffle_ps(v63, v63, 170));
      v65 = _mm_rsqrt_ps(v64);
      v66 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v64), (__m128)0i64);
      normal.m_quad = _mm_or_ps(
                        _mm_and_ps(
                          _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmple_ps(v64, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v65, v64), v65)),
                                _mm_mul_ps(*(__m128 *)_xmm, v65))),
                            v62),
                          v66),
                        _mm_andnot_ps(v66, v62));
      if ( v58 )
        goto LABEL_87;
      points.m_capacityAndFlags = 0x80000000;
      points.m_data = 0i64;
      points.m_size = 0;
      LODWORD(m_tris) = 3;
      v67 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (hkVector4f *)v67->m_cur;
      v69 = m_cur + 8;
      if ( v67->m_slabSize < 128 || v69 > v67->m_end )
        m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v67, 128);
      else
        v67->m_cur = v69;
      v70.m_quad = v55->m_quad;
      points.m_data = m_cur;
      p = m_cur;
      points.m_capacityAndFlags = -2147483645;
      m_cur[points.m_size] = (hkVector4f)v70.m_quad;
      v71.m_quad = v56->m_quad;
      points.m_data[++points.m_size] = (hkVector4f)v71.m_quad;
      v72.m_quad = v57->m_quad;
      points.m_data[++points.m_size] = (hkVector4f)v72.m_quad;
      ++points.m_size;
      isWalkableBySlope = hkaiNavMeshGenerationSettings::isWalkableBySlope(v7, &normal, &points, v54);
      v74 = (char *)p;
      v58 = !isWalkableBySlope;
      v75 = points.m_size;
      if ( v58 )
      {
        if ( p == points.m_data )
          v75 = 0;
        points.m_size = v75;
        v79 = (16 * (_DWORD)m_tris + 127) & 0xFFFFFF80;
        v80 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v81 = (v79 + 15) & 0xFFFFFFF0;
        if ( v79 > v80->m_slabSize || &v74[v81] != v80->m_cur || v80->m_firstNonLifoEnd == v74 )
          hkLifoAllocator::slowBlockFree(v80, v74, v81);
        else
          v80->m_cur = v74;
        points.m_size = 0;
        if ( points.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            points.m_data,
            16 * points.m_capacityAndFlags);
LABEL_87:
        hkStopwatch::getTickCounter();
        mesh.m_triangles.m_size = 0;
        v82 = _mm_mul_ps(normal.m_quad, v51);
        v220 = 0i64;
        v83 = v55->m_quad;
        v84 = v56->m_quad;
        v221 = 0;
        v85 = _mm_add_ps(v83, v82);
        v86 = _mm_add_ps(v84, v82);
        v87 = _mm_add_ps(v82, v57->m_quad);
        aabb.m_min = (hkVector4f)xmmword_141A712A0;
        points.m_data = (hkVector4f *)&hkaiTriangleSetAabbTester::AabbCollector::`vftable;
        *(_QWORD *)&points.m_size = &v220;
        aabb.m_max.m_quad = _mm_xor_ps(
                              (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                              (__m128)xmmword_141A712A0);
        aabb.m_min.m_quad = _mm_min_ps((__m128)xmmword_141A712A0, v55->m_quad);
        v88.m_quad = _mm_max_ps(aabb.m_max.m_quad, v55->m_quad);
        p = v258.m_vertices;
        aabb.m_max = (hkVector4f)v88.m_quad;
        aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v56->m_quad);
        v89.m_quad = _mm_max_ps(v88.m_quad, v56->m_quad);
        v222 = 0x80000000;
        m_tris = v258.m_tris;
        aabb.m_max = (hkVector4f)v89.m_quad;
        aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v57->m_quad);
        v90.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(_mm_max_ps(v89.m_quad, v57->m_quad), v85), v86), v87);
        aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(aabb.m_min.m_quad, v85), v86), v87);
        v229.m_min = aabb.m_min;
        aabb.m_max = (hkVector4f)v90.m_quad;
        v229.m_max = (hkVector4f)v90.m_quad;
        hkcdDynamicAabbTree::queryAabb(&v258.m_tree, &aabb, (hkcdAabbTreeQueries::AabbCollector *)&points);
        hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::makeBoxFromExtrudedTriangle(
          &v265,
          v55,
          v56,
          v57,
          &normal,
          &extrusionLength);
        v91 = v221;
        v43 = 0;
        v242.mHeight = -1;
        *(_QWORD *)&v242.mEnableStereo = 0i64;
        v242.mWidth = 0;
        mesh.m_vertices.m_size = 0;
        v92 = v221;
        if ( (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= v221 )
        {
          v243.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v221 < 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            v91 = 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v243, &hkContainerHeapAllocator::s_alloc, &mesh.m_triangles, v91, 16);
          v91 = v221;
        }
        mesh.m_triangles.m_size = v92;
        v212 = 0;
        if ( v91 <= 0 )
        {
LABEL_113:
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v242,
            &hkContainerHeapAllocator::s_alloc);
          _(&v242);
          v221 = 0;
          if ( v222 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v220, 4 * v222);
          v220 = 0i64;
          v222 = 0x80000000;
          hkaiGeometryToEdgeGeometryConverter::convertGeometryToEdgeGeometry(
            &v264,
            &v250,
            &mesh,
            (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)1,
            &geom);
          hkaiNavMeshGenerationUtils::pruneEdgeGeometryByMaterialDeprecated(
            &geom,
            (hkPointerMap<unsigned __int64,unsigned int,hkContainerHeapAllocator> *)&v235,
            v7->m_defaultConstructionProperties.m_storage,
            2u);
          hkaiEdgeGeometry::hkaiEdgeGeometry(&extrudeGeom);
          v240.hkReferencedObject = (hkReferencedObject)_mm_mul_ps(_mm_sub_ps((__m128)0i64, v51), normal.m_quad);
          hkaiGeometryExtrudeUtil::silhouetteExtrudeDeprecated(&v252, &geom, (hkVector4f *)&v240, &extrudeGeom);
          hkaiGeometryCarverExtractor::addCarversInRegion(&v249, &extrudeGeom, &carverTree, &aabb);
          hkaiEdgeGeometry::hkaiEdgeGeometry(&v247);
          newTriangles.m_data = 0i64;
          newTriangles.m_size = 0;
          newTriangles.m_capacityAndFlags = 0x80000000;
          hkaiBooleanOperation::hkaiBooleanOperation(&buf);
          hkaiSelfIntersectBooleanFilter2::hkaiSelfIntersectBooleanFilter2(&filter);
          hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(&filter, &v251, &geomA, &extrudeGeom);
          hkaiBooleanOperation::subtract(
            &buf,
            v237,
            &geomA,
            &extrudeGeom,
            &v247,
            (hkaiBooleanFaceFaceIntersects *)&newTriangles,
            &filter);
          trisOut.m_data = 0i64;
          trisOut.m_size = 0;
          trisOut.m_capacityAndFlags = 0x80000000;
          trisPerFaceOut.m_data = 0i64;
          trisPerFaceOut.m_size = 0;
          trisPerFaceOut.m_capacityAndFlags = 0x80000000;
          triConnectivityOut.m_data = 0i64;
          triConnectivityOut.m_size = 0;
          triConnectivityOut.m_capacityAndFlags = 0x80000000;
          materialsOut.m_data = 0i64;
          materialsOut.m_size = 0;
          materialsOut.m_capacityAndFlags = 0x80000000;
          hkaiNavMeshGenerationUtils::_triangulate(
            v239,
            v7,
            &v247,
            &trisOut,
            &trisPerFaceOut,
            &triConnectivityOut,
            &materialsOut,
            1);
          hkaiNavMeshGenerationUtils::_removeDegenerateTriangles(
            v232,
            &v247.m_vertices,
            &trisOut,
            &trisPerFaceOut,
            &triConnectivityOut,
            &materialsOut,
            (__m128 *)v7);
          v110 = v215.m_size;
          hkArrayBase<hkVector4f>::_append(
            &v215,
            &hkContainerHeapAllocator::s_alloc,
            v247.m_vertices.m_data,
            v247.m_vertices.m_size);
          v111 = v214.m_size;
          hkArrayBase<unsigned int>::_append(
            &v214,
            &hkContainerHeapAllocator::s_alloc,
            (const unsigned int *)trisOut.m_data,
            trisOut.m_size);
          v112 = 0;
          if ( trisOut.m_size > 0 )
          {
            v113 = v111;
            do
            {
              ++v112;
              v214.m_data[v113++] += v110;
            }
            while ( v112 < trisOut.m_size );
          }
          hkArrayBase<unsigned int>::_append(
            &v234,
            &hkContainerHeapAllocator::s_alloc,
            (const unsigned int *)trisPerFaceOut.m_data,
            trisPerFaceOut.m_size);
          hkArrayBase<unsigned int>::_append(
            (hkArrayBase<unsigned int> *)&v235.mStereo,
            &hkContainerHeapAllocator::s_alloc,
            (const unsigned int *)triConnectivityOut.m_data,
            triConnectivityOut.m_size);
          v114 = 0;
          if ( trisOut.m_size / 3 > 0 )
          {
            v115 = perTriangleDataInOut.m_size;
            do
            {
              if ( v115 == (perTriangleDataInOut.m_capacityAndFlags & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &perTriangleDataInOut, 4);
                v115 = perTriangleDataInOut.m_size;
              }
              ++v114;
              perTriangleDataInOut.m_data[v115] = v54;
              v115 = ++perTriangleDataInOut.m_size;
            }
            while ( v114 < trisOut.m_size / 3 );
          }
          materialsOut.m_size = 0;
          if ( materialsOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              materialsOut.m_data,
              4 * materialsOut.m_capacityAndFlags);
          materialsOut.m_data = 0i64;
          materialsOut.m_capacityAndFlags = 0x80000000;
          triConnectivityOut.m_size = 0;
          if ( triConnectivityOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              triConnectivityOut.m_data,
              4 * triConnectivityOut.m_capacityAndFlags);
          triConnectivityOut.m_data = 0i64;
          triConnectivityOut.m_capacityAndFlags = 0x80000000;
          trisPerFaceOut.m_size = 0;
          if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              trisPerFaceOut.m_data,
              4 * trisPerFaceOut.m_capacityAndFlags);
          trisPerFaceOut.m_data = 0i64;
          trisPerFaceOut.m_capacityAndFlags = 0x80000000;
          trisOut.m_size = 0;
          if ( trisOut.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              trisOut.m_data,
              4 * trisOut.m_capacityAndFlags);
          trisOut.m_data = 0i64;
          trisOut.m_capacityAndFlags = 0x80000000;
          filter.m_face1Results.m_size = 0;
          if ( filter.m_face1Results.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              filter.m_face1Results.m_data,
              filter.m_face1Results.m_capacityAndFlags & 0x3FFFFFFF);
          filter.m_face1Results.m_data = 0i64;
          filter.m_face1Results.m_capacityAndFlags = 0x80000000;
          filter.m_vertexMapB.m_size = 0;
          if ( filter.m_vertexMapB.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              filter.m_vertexMapB.m_data,
              4 * filter.m_vertexMapB.m_capacityAndFlags);
          filter.m_vertexMapB.m_data = 0i64;
          filter.m_vertexMapB.m_capacityAndFlags = 0x80000000;
          filter.m_vertexMapA.m_size = 0;
          if ( filter.m_vertexMapA.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              filter.m_vertexMapA.m_data,
              4 * filter.m_vertexMapA.m_capacityAndFlags);
          filter.m_vertexMapA.m_data = 0i64;
          filter.vfptr = (hkaiBooleanFilterVtbl *)&hkaiBooleanFilter::`vftable;
          filter.m_vertexMapA.m_capacityAndFlags = 0x80000000;
          hkaiBooleanOperation::~hkaiBooleanOperation(&buf);
          newTriangles.m_size = 0;
          if ( newTriangles.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              newTriangles.m_data,
              16 * newTriangles.m_capacityAndFlags);
          newTriangles.m_data = 0i64;
          newTriangles.m_capacityAndFlags = 0x80000000;
          v247.m_vertices.m_size = 0;
          if ( v247.m_vertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v247.m_vertices.m_data,
              16 * v247.m_vertices.m_capacityAndFlags);
          v247.m_vertices.m_data = 0i64;
          v247.m_vertices.m_capacityAndFlags = 0x80000000;
          v247.m_faces.m_size = 0;
          if ( v247.m_faces.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v247.m_faces.m_data,
              12 * (v247.m_faces.m_capacityAndFlags & 0x3FFFFFFF));
          v247.m_faces.m_data = 0i64;
          v247.m_faces.m_capacityAndFlags = 0x80000000;
          v247.m_edges.m_size = 0;
          if ( v247.m_edges.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v247.m_edges.m_data,
              16 * v247.m_edges.m_capacityAndFlags);
          v247.m_edges.m_data = 0i64;
          v247.m_edges.m_capacityAndFlags = 0x80000000;
          v247.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
          extrudeGeom.m_vertices.m_size = 0;
          if ( extrudeGeom.m_vertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              extrudeGeom.m_vertices.m_data,
              16 * extrudeGeom.m_vertices.m_capacityAndFlags);
          extrudeGeom.m_vertices.m_data = 0i64;
          extrudeGeom.m_vertices.m_capacityAndFlags = 0x80000000;
          extrudeGeom.m_faces.m_size = 0;
          if ( extrudeGeom.m_faces.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              extrudeGeom.m_faces.m_data,
              12 * (extrudeGeom.m_faces.m_capacityAndFlags & 0x3FFFFFFF));
          extrudeGeom.m_faces.m_data = 0i64;
          extrudeGeom.m_faces.m_capacityAndFlags = 0x80000000;
          extrudeGeom.m_edges.m_size = 0;
          if ( extrudeGeom.m_edges.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              extrudeGeom.m_edges.m_data,
              16 * extrudeGeom.m_edges.m_capacityAndFlags);
          goto LABEL_151;
        }
        v93 = geomInOut.m_vertices.m_data;
        v94 = 0i64;
        p_m_c = &mesh.m_triangles.m_data->m_c;
        v246 = 0i64;
        while ( 2 )
        {
          v96 = *(int *)&v220[v94];
          if ( (_DWORD)v96 != result.m_enum )
          {
            v97 = v96;
            m_c = geomInOut.m_triangles.m_data[v97].m_c;
            m_b = geomInOut.m_triangles.m_data[v97].m_b;
            m_a = geomInOut.m_triangles.m_data[v97].m_a;
            if ( hkaiNavMeshGenerationUtils::ExtrudedTriangleObb::doesTriangleIntersectObb(
                   &v265,
                   &v93[m_a],
                   &v93[m_b],
                   &v93[m_c]) )
            {
              v248[2] = m_c;
              v43 = 0;
              v248[0] = m_a;
              v101 = 0i64;
              v248[1] = m_b;
              do
              {
                v102 = v248[v101];
                Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v242,
                                      v102);
                if ( Key > (int)v242.mHeight )
                {
                  v104 = mesh.m_vertices.m_size;
                  v105 = mesh.m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
                  *(_DWORD *)((char *)&v242.mStereo + v101 * 4) = mesh.m_vertices.m_size;
                  v106 = &geomInOut.m_vertices.m_data[v102];
                  if ( v104 == v105 )
                  {
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &mesh.m_vertices, 16);
                    v104 = mesh.m_vertices.m_size;
                  }
                  v107 = *(int *)((char *)&v242.mStereo + v101 * 4);
                  mesh.m_vertices.m_data[v104] = (hkVector4f)v106->m_quad;
                  ++mesh.m_vertices.m_size;
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v242,
                    &hkContainerHeapAllocator::s_alloc,
                    v102,
                    v107);
                }
                else
                {
                  *(_DWORD *)((char *)&v242.mStereo + v101 * 4) = *(_DWORD *)(*(_QWORD *)&v242.mEnableStereo
                                                                            + 16i64 * Key
                                                                            + 8);
                }
                ++v101;
              }
              while ( v101 < 3 );
              mStereo = (unsigned int)v242.mStereo;
              p_m_c[1] = -1;
              p_m_c += 4;
              *((_QWORD *)p_m_c - 3) = __PAIR64__(HIDWORD(v242.mStereo), mStereo);
              *(p_m_c - 4) = (int)v242.mExtension;
              v93 = geomInOut.m_vertices.m_data;
              v92 = mesh.m_triangles.m_size;
              v91 = v221;
              goto LABEL_111;
            }
            v43 = 0;
          }
          if ( (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) >= --v92 )
          {
            v244.m_enum = HK_SUCCESS;
          }
          else
          {
            v109 = v92;
            if ( v92 < 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
              v109 = 2 * (mesh.m_triangles.m_capacityAndFlags & 0x3FFFFFFF);
            hkArrayUtil::_reserve(&v244, &hkContainerHeapAllocator::s_alloc, &mesh.m_triangles, v109, 16);
            v93 = geomInOut.m_vertices.m_data;
            v91 = v221;
          }
          mesh.m_triangles.m_size = v92;
LABEL_111:
          v94 = v246 + 4;
          ++v212;
          v246 += 4i64;
          if ( v212 >= v91 )
          {
            v7 = input;
            v54 = m_material;
            goto LABEL_113;
          }
          continue;
        }
      }
      v43 = 0;
      if ( p == points.m_data )
        v75 = 0;
      points.m_size = v75;
      v76 = (16 * (_DWORD)m_tris + 127) & 0xFFFFFF80;
      v77 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v78 = (v76 + 15) & 0xFFFFFFF0;
      if ( v76 > v77->m_slabSize || &v74[v78] != v77->m_cur || v77->m_firstNonLifoEnd == v74 )
        hkLifoAllocator::slowBlockFree(v77, v74, v78);
      else
        v77->m_cur = v74;
      points.m_size = 0;
      if ( points.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          points.m_data,
          16 * points.m_capacityAndFlags);
    }
LABEL_151:
    v50 = j + 1;
    ++result.m_enum;
  }
  trisToRemove.m_storage.m_words.m_data = 0i64;
  trisToRemove.m_storage.m_words.m_size = 0;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  v116 = v214.m_size / 3;
  v117 = (v214.m_size / 3 + 31) >> 5;
  v118 = v117;
  if ( v117 )
  {
    result.m_enum = 4 * v117;
    v119 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                             &hkContainerHeapAllocator::s_alloc,
                             &result);
    v118 = result.m_enum / 4;
  }
  else
  {
    v119 = 0i64;
  }
  v120 = 0x80000000;
  trisToRemove.m_storage.m_words.m_data = v119;
  if ( v118 )
    v120 = v118;
  trisToRemove.m_storage.m_words.m_size = v117;
  trisToRemove.m_storage.m_numBits = v116;
  trisToRemove.m_storage.m_words.m_capacityAndFlags = v120;
  v121 = v120 & 0x3FFFFFFF;
  if ( v121 < v117 )
  {
    v122 = 2 * v121;
    v123 = v117;
    if ( v117 < v122 )
      v123 = v122;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &trisToRemove, v123, 4);
    v119 = trisToRemove.m_storage.m_words.m_data;
  }
  trisToRemove.m_storage.m_words.m_size = v117;
  if ( v117 - 1 >= 0 )
  {
    v124 = (unsigned int)v117;
    v125 = v119;
    while ( v124 )
    {
      *v125++ = 0;
      --v124;
    }
  }
  v208 = 0i64;
  v209 = 0;
  v210 = 0x80000000;
  v126 = 0;
  if ( geomInOut.m_triangles.m_size > 0 )
  {
    v127 = 0i64;
    do
    {
      if ( (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v235,
              (unsigned int)geomInOut.m_triangles.m_data[v127].m_material,
              v7->m_defaultConstructionProperties.m_storage) & 2) != 0 )
      {
        v128 = v209;
        v129 = geomInOut.m_triangles.m_data;
        if ( v209 == (v210 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v208, 4);
          v128 = v209;
        }
        v208[v128] = v129[v127].m_a;
        v130 = geomInOut.m_triangles.m_data;
        v131 = v209 + 1;
        v209 = v131;
        if ( v131 == (v210 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v208, 4);
          v131 = v209;
        }
        v208[v131] = v130[v127].m_b;
        v132 = geomInOut.m_triangles.m_data;
        v133 = v209 + 1;
        v209 = v133;
        if ( v133 == (v210 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v208, 4);
          v133 = v209;
        }
        v208[v133] = v132[v127].m_c;
        ++v209;
      }
      ++v126;
      ++v127;
    }
    while ( v126 < geomInOut.m_triangles.m_size );
  }
  v260.m_vertices = &geomInOut.m_vertices;
  v260.m_tris = (hkArray<int,hkContainerHeapAllocator> *)&v208;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&v260.m_tree);
  hkaiTriangleSetAabbTester::init(&v260);
  v134 = v116;
  v135 = v7->m_painters.m_size + array.m_size;
  *(_QWORD *)&v232[0].m_enum = v116;
  v136 = 1;
  m_material = v135;
  if ( v116 > 0 )
  {
    v137 = *(_QWORD *)&v232[0].m_enum;
    result.m_enum = 981668463;
    v138 = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
    v139 = 0i64;
    v140 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v141 = &v215.m_data[v214.m_data[v139]];
      v142 = &v215.m_data[v214.m_data[v139 + 1]];
      v143 = &v215.m_data[v214.m_data[v139 + 2]];
      normal.m_quad = _mm_add_ps(v142->m_quad, v141->m_quad);
      normal.m_quad = _mm_mul_ps(_mm_add_ps(v143->m_quad, normal.m_quad), (__m128)xmmword_141A711C0);
      v144 = _mm_sub_ps(v143->m_quad, v141->m_quad);
      v145 = _mm_sub_ps(v142->m_quad, v141->m_quad);
      v146 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v144, v144, 201), v145),
               _mm_mul_ps(_mm_shuffle_ps(v145, v145, 201), v144));
      v147 = _mm_shuffle_ps(v146, v146, 201);
      v148 = _mm_mul_ps(v147, v147);
      v149 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v148, v148, 85), _mm_shuffle_ps(v148, v148, 0)),
               _mm_shuffle_ps(v148, v148, 170));
      v150 = _mm_rsqrt_ps(v149);
      v151 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v149), (__m128)0i64);
      v152 = (hkReferencedObject)_mm_or_ps(
                                   _mm_and_ps(
                                     _mm_mul_ps(
                                       _mm_andnot_ps(
                                         _mm_cmple_ps(v149, (__m128)0i64),
                                         _mm_mul_ps(
                                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v150, v149), v150)),
                                           _mm_mul_ps(*(__m128 *)_xmm, v150))),
                                       v147),
                                     v151),
                                   _mm_andnot_ps(v151, v147));
      v153 = _mm_mul_ps(v138, (__m128)v152);
      v240.hkReferencedObject = v152;
      v154 = _mm_mul_ps((__m128)v152, v51);
      normal.m_quad = _mm_add_ps(normal.m_quad, v153);
      v155 = _mm_add_ps(v141->m_quad, v154);
      v156 = _mm_add_ps(v142->m_quad, v154);
      v157 = v143->m_quad;
      aabb.m_min = (hkVector4f)xmmword_141A712A0;
      aabb.m_max.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v140);
      v158 = _mm_add_ps(v157, v154);
      aabb.m_min.m_quad = _mm_min_ps((__m128)xmmword_141A712A0, v141->m_quad);
      aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v141->m_quad);
      aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v142->m_quad);
      aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v142->m_quad);
      v159.m_quad = _mm_min_ps(aabb.m_min.m_quad, v143->m_quad);
      points.m_data = (hkVector4f *)&hkaiTriangleSetAabbTester::AabbCollector::`vftable;
      aabb.m_min = (hkVector4f)v159.m_quad;
      v160 = _mm_max_ps(aabb.m_max.m_quad, v143->m_quad);
      *(_QWORD *)&points.m_size = &trisPerFaceOut;
      p = v260.m_vertices;
      trisPerFaceOut.m_data = 0i64;
      aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(v159.m_quad, v155), v156), v158);
      aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(v160, v155), v156), v158);
      v229 = aabb;
      trisPerFaceOut.m_size = 0;
      trisPerFaceOut.m_capacityAndFlags = 0x80000000;
      m_tris = v260.m_tris;
      hkcdDynamicAabbTree::queryAabb(&v260.m_tree, &aabb, (hkcdAabbTreeQueries::AabbCollector *)&points);
      v161 = 0;
      if ( trisPerFaceOut.m_size > 0 )
      {
        v162 = 0i64;
        while ( 1 )
        {
          v163 = v208[3 * trisPerFaceOut.m_data[v162]];
          v164 = v208[3 * trisPerFaceOut.m_data[v162] + 1];
          v165 = v208[3 * trisPerFaceOut.m_data[v162] + 2];
          newTriangles = 0i64;
          if ( hkaiNavMeshGenerationUtils::_rayTriangleIntersect(
                 &normal,
                 (hkVector4f *)&v240,
                 &geomInOut.m_vertices.m_data[v163],
                 &geomInOut.m_vertices.m_data[v164],
                 &geomInOut.m_vertices.m_data[v165],
                 (hkSimdFloat32 *)&newTriangles)
            && *(float *)&newTriangles.m_data > 0.0
            && *(float *)&newTriangles.m_data < v51.m128_f32[0] )
          {
            break;
          }
          ++v161;
          ++v162;
          if ( v161 >= trisPerFaceOut.m_size )
            goto LABEL_186;
        }
        trisToRemove.m_storage.m_words.m_data[(__int64)v43 >> 5] |= v136;
      }
LABEL_186:
      trisPerFaceOut.m_size = 0;
      if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          trisPerFaceOut.m_data,
          4 * trisPerFaceOut.m_capacityAndFlags);
      v136 = __ROL4__(v136, 1);
      ++v43;
      v139 += 3i64;
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_capacityAndFlags = 0x80000000;
      --v137;
    }
    while ( v137 );
    v7 = input;
    v134 = *(_QWORD *)&v232[0].m_enum;
  }
  v259.m_vertices = (hkArray<hkVector4f,hkContainerHeapAllocator> *)&v215;
  v259.m_tris = (hkArray<int,hkContainerHeapAllocator> *)&v214;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&v259.m_tree);
  hkaiTriangleSetAabbTester::init(&v259);
  v166 = v215.m_data;
  v167 = 0;
  v168 = 1;
  m_enum = HK_SUCCESS;
  v212 = 1;
  v170 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_89999998), (__m128)LODWORD(FLOAT_0_89999998), 0);
  result.m_enum = HK_SUCCESS;
  v171 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v240.hkReferencedObject = (hkReferencedObject)_mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
  if ( v134 > 0 )
  {
    v172 = 0i64;
    *(_QWORD *)&v239[0].m_enum = 0i64;
    v173 = v134;
    *(_QWORD *)&v237[0].m_enum = v134;
    v174 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    while ( 1 )
    {
      v175 = *(int *)((char *)v214.m_data + v172 + 8);
      v176 = *(int *)((char *)v214.m_data + v172);
      v177 = *(int *)((char *)v214.m_data + v172 + 4);
      v178 = v166[*(int *)((char *)v214.m_data + v172 + 8)].m_quad;
      v179 = v166[*(int *)((char *)v214.m_data + v172 + 4)].m_quad;
      v180 = (hkReferencedObject)_mm_mul_ps(
                                   _mm_add_ps(_mm_add_ps(v166[*(int *)((char *)v214.m_data + v172)].m_quad, v179), v178),
                                   (__m128)xmmword_141A711C0);
      v181 = _mm_sub_ps(v166[*(int *)((char *)v214.m_data + v172)].m_quad, (__m128)v180);
      v247.hkReferencedObject = v180;
      v247.m_edges = (hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator>)_mm_add_ps(
                                                                                 _mm_mul_ps(v181, v170),
                                                                                 (__m128)v180);
      v247.m_faces = (hkArray<hkaiEdgeGeometry::Face,hkContainerHeapAllocator>)_mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_sub_ps(v179, (__m128)v180),
                                                                                   v170),
                                                                                 (__m128)v180);
      aabb.m_min = (hkVector4f)xmmword_141A712A0;
      v247.m_vertices = (hkArray<hkVector4f,hkContainerHeapAllocator>)_mm_add_ps(
                                                                        _mm_mul_ps(_mm_sub_ps(v178, (__m128)v180), v170),
                                                                        (__m128)v180);
      aabb.m_max.m_quad = _mm_xor_ps((__m128)xmmword_141A712A0, v174);
      aabb.m_min.m_quad = _mm_min_ps((__m128)xmmword_141A712A0, v166[v176].m_quad);
      aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v166[v176].m_quad);
      aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v166[v177].m_quad);
      aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v166[v177].m_quad);
      aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v166[v175].m_quad);
      v182 = _mm_max_ps(aabb.m_max.m_quad, v166[v175].m_quad);
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_size = 0;
      points.m_data = (hkVector4f *)&hkaiTriangleSetAabbTester::AabbCollector::`vftable;
      trisPerFaceOut.m_capacityAndFlags = 0x80000000;
      aabb.m_min.m_quad = _mm_sub_ps(aabb.m_min.m_quad, v171);
      *(_QWORD *)&points.m_size = &trisPerFaceOut;
      aabb.m_max.m_quad = _mm_add_ps(v182, v171);
      v229 = aabb;
      p = v259.m_vertices;
      m_tris = v259.m_tris;
      hkcdDynamicAabbTree::queryAabb(&v259.m_tree, &aabb, (hkcdAabbTreeQueries::AabbCollector *)&points);
      v166 = v215.m_data;
      if ( trisPerFaceOut.m_size <= 0 )
        goto LABEL_203;
      v183 = trisPerFaceOut.m_data;
      while ( 1 )
      {
        v184 = *v183;
        if ( (_DWORD)v184 != m_enum )
          break;
LABEL_200:
        ++v167;
        ++v183;
        if ( v167 >= trisPerFaceOut.m_size )
        {
          v168 = v212;
          goto LABEL_202;
        }
      }
      v185 = *v183;
      if ( ((trisToRemove.m_storage.m_words.m_data[v184 >> 5] >> (v184 & 0x1F)) & 1) != 0 )
        break;
      v186 = &v166[v214.m_data[3 * v185]];
      v187 = &v166[v214.m_data[3 * v185 + 1]];
      v188 = &v166[v214.m_data[3 * v185 + 2]];
      v189 = 0;
      while ( !pointInTriangle((hkVector4f *)&v247.hkReferencedObject + v189, v186, v187, v188, (hkSimdFloat32 *)&v240) )
      {
        if ( ++v189 >= 4 )
          goto LABEL_199;
      }
      m_enum = result.m_enum;
      v168 = v212;
      trisToRemove.m_storage.m_words.m_data[(__int64)(int)result.m_enum >> 5] |= v212;
      v166 = v215.m_data;
LABEL_202:
      v173 = *(_QWORD *)&v237[0].m_enum;
      v172 = *(_QWORD *)&v239[0].m_enum;
LABEL_203:
      v167 = 0;
      trisPerFaceOut.m_size = 0;
      if ( trisPerFaceOut.m_capacityAndFlags >= 0 )
      {
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          trisPerFaceOut.m_data,
          4 * trisPerFaceOut.m_capacityAndFlags);
        v166 = v215.m_data;
      }
      v168 = __ROL4__(v168, 1);
      ++m_enum;
      v172 += 12i64;
      --v173;
      trisPerFaceOut.m_data = 0i64;
      trisPerFaceOut.m_capacityAndFlags = 0x80000000;
      result.m_enum = m_enum;
      v212 = v168;
      *(_QWORD *)&v239[0].m_enum = v172;
      *(_QWORD *)&v237[0].m_enum = v173;
      if ( !v173 )
      {
        v7 = input;
        v134 = *(_QWORD *)&v232[0].m_enum;
        goto LABEL_207;
      }
    }
LABEL_199:
    m_enum = result.m_enum;
    goto LABEL_200;
  }
LABEL_207:
  if ( (int)m_material > 0 )
  {
    v190 = 0i64;
    v191 = 1;
    if ( v134 > 0 )
    {
      v192 = v214.m_data + 2;
      do
      {
        v193 = (__int64)v167 >> 5;
        if ( ((trisToRemove.m_storage.m_words.m_data[v193] >> (v167 & 0x1F)) & 1) == 0 )
        {
          v194 = (int)*v192;
          normal.m_quad = _mm_add_ps(v166[*(v192 - 2)].m_quad, v166[*(v192 - 1)].m_quad);
          normal.m_quad = _mm_mul_ps(_mm_add_ps(v166[v194].m_quad, normal.m_quad), (__m128)xmmword_141A711C0);
          if ( hkaiCarverTree::carversContainPoint(&carverTree, &normal) )
          {
            trisToRemove.m_storage.m_words.m_data[v193] |= v191;
          }
          else
          {
            v195 = perTriangleDataInOut.m_data;
            m_painterOverlapCallback = v7->m_painterOverlapCallback;
            result.m_enum = HK_SUCCESS;
            v195[v190] = hkaiCarverTree::getPaintedMaterialForPoint(
                           &carverTree,
                           &normal,
                           perTriangleDataInOut.m_data[v190],
                           m_painterOverlapCallback,
                           &result);
          }
        }
        v191 = __ROL4__(v191, 1);
        ++v190;
        ++v167;
        v192 += 3;
      }
      while ( v190 < *(__int64 *)&v232[0].m_enum );
    }
  }
  hkaiNavMeshGenerationUtils::_removeTriangles(
    &trisToRemove,
    (hkArray<int,hkContainerHeapAllocator> *)&v214,
    (hkArray<int,hkContainerHeapAllocator> *)&v235.mStereo,
    (hkArray<int,hkContainerHeapAllocator> *)&v234,
    &perTriangleDataInOut,
    0i64);
  hkaiNavMesh::hkaiNavMesh(&v266);
  v197 = navMesh;
  v198 = &v266;
  if ( !v7->m_enableSimplification.m_bool )
    v198 = navMesh;
  hkaiNavMesh::setEdgeDataStriding(v198, &result, 0, 0);
  hkaiNavMesh::setEdgeDataStriding(v197, &result, 0, 0);
  hkaiNavMeshGenerationUtils::_createNavMesh(
    &result,
    (hkArray<hkVector4f,hkContainerHeapAllocator> *)&v215,
    (hkArray<int,hkContainerHeapAllocator> *)&v214,
    (hkArray<int,hkContainerHeapAllocator> *)&v234,
    (hkArray<int,hkContainerHeapAllocator> *)&v235.mStereo,
    (hkArray<int,hkContainerHeapAllocator> *)&perTriangleDataInOut,
    &carverTree,
    v7,
    v198);
  v198->m_flags.m_storage |= 1u;
  if ( v198->m_faces.m_size && v198->m_edges.m_size )
  {
    hkaiEdgeGeometryRaycaster::hkaiEdgeGeometryRaycaster(&raycaster);
    p_raycaster = edgeConnectionRaycaster;
    if ( !edgeConnectionRaycaster )
    {
      hkaiEdgeGeometryRaycaster::init(&raycaster, &result, &geomOut);
      p_raycaster = &raycaster;
    }
    hkaiEdgeGeometryRaycaster::setupForEdgeConnections(p_raycaster);
    for ( k = 0; k < v7->m_edgeConnectionIterations; ++k )
      hkaiNavMeshGenerationUtils::_connectEdges(&result, v7, v198, (hkaiNavMesh *)p_raycaster, k, 0i64, 0i64);
    hkaiNavMeshUtils::compactVertices(&result, v198, 0, 0);
    hkaiNavMeshGenerationUtils::_mergeVertices(&result, v198, 0.00039999999);
    hkaiNavMeshGenerationUtils::_removeDegenerateFaces(&result, (hkSimdFloat32 *)v198);
    hkaiNavMeshUtils::validate(v198, 0);
    hkaiNavMeshSimplificationUtils::hertelMehlhorn(&result, v7, v198, 0i64, 0i64);
    v201 = callbacksa;
    hkaiNavMeshGenerationUtils::_applyMinCharacterRadius(&result, v198, v7, &raycaster, callbacksa);
    hkaiNavMeshGenerationUtils::_pruneRegions(&result, v198, &v7->m_up, &v7->m_regionPruningSettings);
    hkaiNavMeshUtils::compactVertices(&result, v198, 0, 0);
    hkAabbUtil::calcAabb(v198->m_vertices.m_data, v198->m_vertices.m_size, &v198->m_aabb);
    v202 = _mm_sub_ps(v198->m_aabb.m_min.m_quad, v51);
    v198->m_aabb.m_max.m_quad = _mm_add_ps(v198->m_aabb.m_max.m_quad, v51);
    v198->m_aabb.m_min.m_quad = v202;
    if ( v7->m_enableSimplification.m_bool )
    {
      hkaiNavMesh::setEdgeDataStriding(v198, &result, 1, 0);
      hkaiNavMesh::setEdgeDataStriding(v197, &result, 1, 0);
      hkaiNavMeshUtils::validate(v198, 0);
      hkaiNavMeshSimplificationUtils::_simplifyNavMesh(v7, v198, v197, 0i64, v201);
      v197->m_flags.m_storage = v198->m_flags.m_storage;
    }
    hkaiNavMeshUtils::validate(v197, 1);
    v203 = 5;
    hkaiEdgeGeometryRaycaster::~hkaiEdgeGeometryRaycaster(&raycaster);
  }
  else
  {
    hkErrStream::hkErrStream(&v240, &buf, 512);
    hkOstream::operator<<(
      &v240,
      "Empty nav mesh created. This could happen if all input was unwalkable, or if all walkable geometry was contained in carvers.");
    hkError::messageWarning(1541620706, (const char *)&buf, "NavMesh\\hkaiNavMeshGenerationUtils_wallClimbing.cpp", 894);
    hkOstream::~hkOstream(&v240);
    v203 = 1;
    v197->m_aabb.m_min = (hkVector4f)aabbOut.m_quad;
    v197->m_aabb.m_max = (hkVector4f)aabbOut.m_quad;
  }
  hkaiNavMesh::~hkaiNavMesh(&v266);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&v259.m_tree);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&v260.m_tree);
  v209 = 0;
  if ( v210 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v208, 4 * v210);
  v208 = 0i64;
  v210 = 0x80000000;
  hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>((hkaMatrix<float> *)&trisToRemove);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geom);
  hkGeometry::~hkGeometry(&mesh);
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomA);
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&v258.m_tree);
  v224 = 0;
  if ( v225 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v223, 4 * v225);
  v223 = 0i64;
  v225 = 0x80000000;
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&geomOut);
  perTriangleDataInOut.m_size = 0;
  if ( perTriangleDataInOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      perTriangleDataInOut.m_data,
      4 * perTriangleDataInOut.m_capacityAndFlags);
  perTriangleDataInOut.m_data = 0i64;
  perTriangleDataInOut.m_capacityAndFlags = 0x80000000;
  LODWORD(v235.mExtension) = 0;
  if ( SHIDWORD(v235.mExtension) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v235.mStereo,
      4 * HIDWORD(v235.mExtension));
  v235.mStereo = 0i64;
  HIDWORD(v235.mExtension) = 0x80000000;
  v234.m_size = 0;
  if ( v234.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v234.m_data,
      4 * v234.m_capacityAndFlags);
  v234.m_data = 0i64;
  v234.m_capacityAndFlags = 0x80000000;
  v214.m_size = 0;
  if ( v214.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v214.m_data,
      4 * v214.m_capacityAndFlags);
  v214.m_data = 0i64;
  v214.m_capacityAndFlags = 0x80000000;
  v215.m_size = 0;
  if ( v215.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v215.m_data,
      16 * v215.m_capacityAndFlags);
  v215.m_data = 0i64;
  v215.m_capacityAndFlags = 0x80000000;
  hkaiGeometryToEdgeGeometryConverter::~hkaiGeometryToEdgeGeometryConverter(&v264);
  hkaiCarverTree::~hkaiCarverTree(&carverTree);
  v204 = array.m_data;
  v205 = array.m_size - 1;
  if ( array.m_size - 1 >= 0 )
  {
    do
    {
      v206 = v204[v205].m_pntr;
      if ( v206 )
        hkReferencedObject::removeReference(v206);
      v204[v205--].m_pntr = 0i64;
    }
    while ( v205 >= 0 );
    v204 = array.m_data;
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v204,
      8 * array.m_capacityAndFlags);
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v235,
    &hkContainerHeapAllocator::s_alloc);
  _(&v235);
  hkGeometry::~hkGeometry(&geomInOut);
  return v203;
} v214.m_size = 0;
  if ( v214.m_capacityAndFl

