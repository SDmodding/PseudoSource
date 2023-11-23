// File Line: 31
// RVA: 0xB5BC90
void __fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(
        hkaiNavMeshSimplificationUtils::PlaneFitter *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshSimplificationUtils::PlaneFitter::`vftable;
  hkaiNavMeshSimplificationUtils::PlaneFitter::reset(this);
}

// File Line: 36
// RVA: 0xB5BCC0
void __fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::reset(hkaiNavMeshSimplificationUtils::PlaneFitter *this)
{
  this->m_sum = 0i64;
  this->m_productSums.m_col0 = 0i64;
  this->m_productSums.m_col1 = 0i64;
  this->m_productSums.m_col2 = 0i64;
  this->m_numPoints = 0;
}

// File Line: 43
// RVA: 0xB5BCF0
void __fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(
        hkaiNavMeshSimplificationUtils::PlaneFitter *this,
        hkVector4f *newPoint)
{
  hkMatrix3f *p_m_productSums; // rcx
  __m128 m_quad; // xmm2
  hkMatrix3f a; // [rsp+20h] [rbp-38h] BYREF

  p_m_productSums = &this->m_productSums;
  p_m_productSums[-1].m_col2.m_quad = _mm_add_ps(newPoint->m_quad, p_m_productSums[-1].m_col2.m_quad);
  m_quad = newPoint->m_quad;
  a.m_col0.m_quad = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), m_quad);
  a.m_col1.m_quad = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), m_quad);
  a.m_col2.m_quad = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), m_quad);
  hkMatrix3f::add(p_m_productSums, &a);
  ++this->m_numPoints;
}

// File Line: 62
// RVA: 0xB5C140
hkSimdFloat32 *__fastcall calcCovarianceElem_2_2_(
        hkSimdFloat32 *result,
        hkVector4f *mean,
        hkVector4f *sum,
        hkMatrix3f *productSum,
        hkSimdFloat32 *np)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  hkSimdFloat32 *v7; // rax

  v5 = _mm_shuffle_ps(mean->m_quad, mean->m_quad, 170);
  v6 = _mm_mul_ps(_mm_shuffle_ps(sum->m_quad, sum->m_quad, 170), v5);
  v7 = result;
  result->m_real = _mm_add_ps(
                     _mm_sub_ps(
                       _mm_sub_ps(_mm_shuffle_ps(productSum->m_col2.m_quad, productSum->m_col2.m_quad, 170), v6),
                       v6),
                     _mm_mul_ps(_mm_mul_ps(np->m_real, v5), v5));
  return v7;
}

// File Line: 74
// RVA: 0xB5BD60
void __fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::calcCovariance(
        hkaiNavMeshSimplificationUtils::PlaneFitter *this,
        hkMatrix3f *covariance,
        hkSimdFloat32 *invNumPointsOut)
{
  __m128 v3; // xmm13
  __m128 v4; // xmm13
  __m128 v5; // xmm1
  __m128 v6; // xmm12
  hkVector4f v7; // xmm8
  hkVector4f v8; // xmm11
  __m128 v9; // xmm12
  hkVector4f v10; // xmm5
  __m128 v11; // xmm10
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm9
  __m128 v15; // xmm7
  __m128 v16; // xmm12
  __m128 v17; // xmm8
  __m128 v18; // xmm6
  __m128 v19; // xmm4
  __m128 v20; // xmm11
  __m128 v21; // xmm0

  v3 = 0i64;
  v3.m128_f32[0] = (float)this->m_numPoints;
  v4 = _mm_shuffle_ps(v3, v3, 0);
  v5 = _mm_rcp_ps(v4);
  v6 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v5)), v5);
  *invNumPointsOut = (hkSimdFloat32)v6;
  v7.m_quad = (__m128)this->m_sum;
  v8.m_quad = (__m128)this->m_productSums.m_col1;
  v9 = _mm_mul_ps(v6, v7.m_quad);
  v10.m_quad = (__m128)this->m_productSums.m_col0;
  v11 = _mm_shuffle_ps(v9, v9, 85);
  v12 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 85);
  v13 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 170);
  v14 = _mm_sub_ps(_mm_sub_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 85), _mm_mul_ps(v12, v11)), _mm_mul_ps(v12, v11));
  v15 = _mm_shuffle_ps(v9, v9, 0);
  v16 = _mm_shuffle_ps(v9, v9, 170);
  v17 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 0);
  v18 = _mm_sub_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(this->m_productSums.m_col2.m_quad, this->m_productSums.m_col2.m_quad, 170),
            _mm_mul_ps(v13, v16)),
          _mm_mul_ps(v13, v16));
  v19 = _mm_add_ps(
          _mm_sub_ps(_mm_sub_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 85), _mm_mul_ps(v15, v12)), _mm_mul_ps(v17, v11)),
          _mm_mul_ps(_mm_mul_ps(v4, v11), v15));
  v20 = _mm_add_ps(
          _mm_sub_ps(_mm_sub_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 170), _mm_mul_ps(v11, v13)), _mm_mul_ps(v16, v12)),
          _mm_mul_ps(_mm_mul_ps(v16, v4), v11));
  v21 = _mm_add_ps(
          _mm_sub_ps(
            _mm_sub_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 170), _mm_mul_ps(v15, v13)),
            _mm_mul_ps(v16, v17)),
          _mm_mul_ps(_mm_mul_ps(v4, v16), v15));
  covariance->m_col0.m_quad = _mm_movelh_ps(
                                _mm_unpacklo_ps(
                                  _mm_add_ps(
                                    _mm_sub_ps(
                                      _mm_sub_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 0), _mm_mul_ps(v17, v15)),
                                      _mm_mul_ps(v17, v15)),
                                    _mm_mul_ps(_mm_mul_ps(v4, v15), v15)),
                                  v19),
                                _mm_unpacklo_ps(v21, aabbOut.m_quad));
  covariance->m_col1.m_quad = _mm_movelh_ps(
                                _mm_unpacklo_ps(v19, _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v4, v11), v11), v14)),
                                _mm_unpacklo_ps(v20, aabbOut.m_quad));
  covariance->m_col2.m_quad = _mm_movelh_ps(
                                _mm_unpacklo_ps(v21, v20),
                                _mm_unpacklo_ps(_mm_add_ps(_mm_mul_ps(_mm_mul_ps(v4, v16), v16), v18), aabbOut.m_quad));
}

// File Line: 93
// RVA: 0xB5BF70
hkResult *__fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(
        hkaiNavMeshSimplificationUtils::PlaneFitter *this,
        hkResult *result,
        hkVector4f *planeOut)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm3
  hkResult *v8; // rax
  __m128 v9; // xmm2
  hkSimdFloat32 invNumPointsOut; // [rsp+30h] [rbp-98h] BYREF
  hkVector4f eigenVal; // [rsp+40h] [rbp-88h] BYREF
  hkMatrix3f covariance; // [rsp+50h] [rbp-78h] BYREF
  hkRotationf eigenVec; // [rsp+80h] [rbp-48h] BYREF

  if ( this->m_numPoints < 3 )
    *planeOut = 0i64;
  invNumPointsOut.m_real = 0i64;
  hkaiNavMeshSimplificationUtils::PlaneFitter::calcCovariance(this, &covariance, &invNumPointsOut);
  hkMatrix3f::diagonalizeSymmetric(&covariance, result, &eigenVec, &eigenVal, 20, 0.00000011920929);
  v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&eigenVal), 1u), 1u);
  v7 = *(&eigenVec.m_col0.m_quad
       + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmple_ps(
                                                                     v6,
                                                                     _mm_min_ps(
                                                                       _mm_shuffle_ps(v6, v6, 170),
                                                                       _mm_min_ps(
                                                                         _mm_shuffle_ps(v6, v6, 85),
                                                                         _mm_shuffle_ps(v6, v6, 0)))),
                                                                   (__m128)xmmword_141A4CC80))]);
  v8 = result;
  *planeOut = (hkVector4f)v7;
  v9 = _mm_mul_ps(_mm_mul_ps(this->m_sum.m_quad, invNumPointsOut.m_real), v7);
  planeOut->m_quad = _mm_shuffle_ps(
                       v7,
                       _mm_unpackhi_ps(
                         v7,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                             _mm_shuffle_ps(v9, v9, 170)))),
                       196);
  return v8;
}

// File Line: 169
// RVA: 0xB5E8F0
__int64 __fastcall Partitioner::BoundaryIntersectionQuery::processLeaf(
        Partitioner::BoundaryIntersectionQuery *this,
        int leafKey,
        hkAabb *leafAabb)
{
  hkArray<int,hkContainerTempAllocator> *m_temporarilyRemovedFromBoundary; // rax
  unsigned int v4; // ebx
  __int64 m_size; // r9
  int v7; // ecx
  __int64 v8; // r8
  int *m_data; // rax
  hkaiNavMesh *m_mesh; // r9
  __int64 m_compX; // r8
  __int64 m_edgeIdx; // rax
  hkVector4f *v13; // rcx
  hkaiNavMesh::Edge *v14; // r11
  __int64 v15; // rdi
  __int64 m_a; // r14
  __int64 v17; // rax
  __int64 m_compY; // rdx
  __int64 v19; // rsi
  __int64 v20; // r15
  __int64 m_b; // r9
  __int64 v22; // rax
  float v23; // xmm11_4
  float v24; // xmm12_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  __m128 v31; // xmm15
  __m128 v32; // xmm13
  __m128 v33; // xmm14
  __m128 v34; // xmm2
  __m128 v35; // xmm12
  __m128 v36; // xmm1
  __m128 v37; // xmm11
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm10
  __m128 v41; // xmm9
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm7
  __m128 v46; // xmm6
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm5
  __m128 v51; // xmm1
  __m128 v52; // xmm8
  __m128 v53; // xmm7
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  __m128 v56; // xmm3
  __m128 v57; // xmm3
  __m128 v58; // xmm0
  __m128 v59; // xmm2
  __m128 v60; // xmm11
  __m128 v61; // xmm0
  __m128 v62; // xmm3
  __m128 v63; // xmm3
  char v65; // dl
  char v66; // al
  char v67; // al
  char v68; // cl
  char v69; // al
  char v70; // cl
  hkVector4f v71; // [rsp+0h] [rbp-99h]
  hkVector4f v72; // [rsp+10h] [rbp-89h]
  hkVector4f v73; // [rsp+20h] [rbp-79h]

  m_temporarilyRemovedFromBoundary = this->m_temporarilyRemovedFromBoundary;
  v4 = 0;
  m_size = m_temporarilyRemovedFromBoundary->m_size;
  v7 = 0;
  v8 = 0i64;
  if ( m_size > 0 )
  {
    m_data = m_temporarilyRemovedFromBoundary->m_data;
    while ( *m_data != leafKey )
    {
      ++v8;
      ++v7;
      ++m_data;
      if ( v8 >= m_size )
        goto LABEL_5;
    }
    if ( v7 != -1 )
      return 1i64;
  }
LABEL_5:
  m_mesh = this->m_mesh;
  m_compX = this->m_compX;
  m_edgeIdx = this->m_edgeIdx;
  v13 = m_mesh->m_vertices.m_data;
  v14 = m_mesh->m_edges.m_data;
  v15 = m_edgeIdx;
  m_a = v14[m_edgeIdx].m_a;
  v17 = leafKey;
  m_compY = this->m_compY;
  v19 = v17;
  v20 = v14[v17].m_a;
  m_b = v14[v17].m_b;
  v22 = v14[v15].m_b;
  v72.m_quad = (__m128)v13[m_a];
  v23 = v72.m_quad.m128_f32[m_compX];
  v24 = v72.m_quad.m128_f32[m_compY];
  v71.m_quad = (__m128)v13[v22];
  v25 = v71.m_quad.m128_f32[m_compX];
  v26 = v71.m_quad.m128_f32[m_compY];
  v72.m_quad = (__m128)v13[v20];
  v27 = v72.m_quad.m128_f32[m_compX];
  v28 = v72.m_quad.m128_f32[m_compY];
  v73.m_quad = (__m128)v13[m_b];
  v29 = v73.m_quad.m128_f32[m_compX];
  v30 = v73.m_quad.m128_f32[m_compY];
  v72.m_quad.m128_u64[0] = __PAIR64__(LODWORD(v30), LODWORD(v29));
  v71.m_quad.m128_u64[0] = __PAIR64__(LODWORD(v28), LODWORD(v27));
  if ( (_DWORD)v20 == (_DWORD)m_a
    || (_DWORD)m_b == (_DWORD)m_a
    || (_DWORD)v20 == v14[v15].m_b
    || (_DWORD)m_b == v14[v15].m_b )
  {
    v65 = 1;
    if ( (_DWORD)m_a != (_DWORD)v20
      || (float)((float)((float)(v30 - v28) * (float)(v26 - v28)) + (float)((float)(v29 - v27) * (float)(v25 - v27))) <= 0.0
      || (v66 = 1,
          fminf(
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)((float)(v29 - v27) * (float)(v26 - v28))
                                                - (float)((float)(v30 - v28) * (float)(v25 - v27)))
                                        / fsqrt(
                                            (float)((float)(v28 - v30) * (float)(v28 - v30))
                                          + (float)((float)(v27 - v29) * (float)(v27 - v29))))) >> 1),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)((float)(v30 - v28) * (float)(v25 - v27))
                                                - (float)((float)(v29 - v27) * (float)(v26 - v28)))
                                        / fsqrt(
                                            (float)((float)(v28 - v26) * (float)(v28 - v26))
                                          + (float)((float)(v27 - v25) * (float)(v27 - v25))))) >> 1)) > 0.001) )
    {
      v66 = 0;
    }
    this->m_intersects |= v66;
    if ( v14[v15].m_b != v14[v19].m_b
      || (float)((float)((float)(v28 - v30) * (float)(v24 - v30)) + (float)((float)(v27 - v29) * (float)(v23 - v29))) <= 0.0
      || (v67 = 1,
          fminf(
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)((float)(v24 - v30) * (float)(v27 - v29))
                                                - (float)((float)(v23 - v29) * (float)(v28 - v30)))
                                        / fsqrt(
                                            (float)((float)(v30 - v28) * (float)(v30 - v28))
                                          + (float)((float)(v29 - v27) * (float)(v29 - v27))))) >> 1),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)((float)(v23 - v29) * (float)(v28 - v30))
                                                - (float)((float)(v24 - v30) * (float)(v27 - v29)))
                                        / fsqrt(
                                            (float)((float)(v30 - v24) * (float)(v30 - v24))
                                          + (float)((float)(v29 - v23) * (float)(v29 - v23))))) >> 1)) > 0.001) )
    {
      v67 = 0;
    }
    v68 = v67 | this->m_intersects;
    this->m_intersects = v68;
    if ( v14[v15].m_a != v14[v19].m_b
      || (float)((float)((float)(v28 - v30) * (float)(v26 - v30)) + (float)((float)(v27 - v29) * (float)(v25 - v29))) <= 0.0
      || (v69 = 1,
          fminf(
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)((float)(v26 - v30) * (float)(v27 - v29))
                                                - (float)((float)(v25 - v29) * (float)(v28 - v30)))
                                        / fsqrt(
                                            (float)((float)(v30 - v28) * (float)(v30 - v28))
                                          + (float)((float)(v29 - v27) * (float)(v29 - v27))))) >> 1),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_INT(
                                          (float)((float)((float)(v25 - v29) * (float)(v28 - v30))
                                                - (float)((float)(v26 - v30) * (float)(v27 - v29)))
                                        / fsqrt(
                                            (float)((float)(v30 - v26) * (float)(v30 - v26))
                                          + (float)((float)(v29 - v25) * (float)(v29 - v25))))) >> 1)) > 0.001) )
    {
      v69 = 0;
    }
    v70 = v69 | v68;
    this->m_intersects = v70;
    if ( v14[v15].m_b != v14[v19].m_a
      || (float)((float)((float)(v30 - v28) * (float)(v24 - v28)) + (float)((float)(v29 - v27) * (float)(v23 - v27))) <= 0.0
      || fminf(
           COERCE_FLOAT((unsigned int)(2
                                     * COERCE_INT(
                                         (float)((float)((float)(v24 - v28) * (float)(v29 - v27))
                                               - (float)((float)(v23 - v27) * (float)(v30 - v28)))
                                       / fsqrt(
                                           (float)((float)(v28 - v30) * (float)(v28 - v30))
                                         + (float)((float)(v27 - v29) * (float)(v27 - v29))))) >> 1),
           COERCE_FLOAT((unsigned int)(2
                                     * COERCE_INT(
                                         (float)((float)((float)(v23 - v27) * (float)(v30 - v28))
                                               - (float)((float)(v24 - v28) * (float)(v29 - v27)))
                                       / fsqrt(
                                           (float)((float)(v28 - v24) * (float)(v28 - v24))
                                         + (float)((float)(v27 - v23) * (float)(v27 - v23))))) >> 1)) > 0.001 )
    {
      v65 = 0;
    }
    this->m_intersects = v65 | v70;
  }
  else
  {
    v31 = _mm_shuffle_ps(
            (__m128)__PAIR64__(LODWORD(v24), LODWORD(v23)),
            _mm_unpackhi_ps((__m128)__PAIR64__(LODWORD(v24), LODWORD(v23)), (__m128)0i64),
            180);
    v32 = _mm_shuffle_ps(
            (__m128)v71.m_quad.m128_u64[0],
            _mm_unpackhi_ps((__m128)v71.m_quad.m128_u64[0], (__m128)0i64),
            180);
    v33 = _mm_sub_ps(
            _mm_shuffle_ps(
              (__m128)__PAIR64__(LODWORD(v26), LODWORD(v25)),
              _mm_unpackhi_ps((__m128)__PAIR64__(LODWORD(v26), LODWORD(v25)), (__m128)0i64),
              180),
            v31);
    v34 = _mm_sub_ps(v32, v31);
    v35 = _mm_sub_ps(
            _mm_shuffle_ps(
              (__m128)v72.m_quad.m128_u64[0],
              _mm_unpackhi_ps((__m128)v72.m_quad.m128_u64[0], (__m128)0i64),
              180),
            v32);
    v36 = _mm_mul_ps(v35, v33);
    v37 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
            _mm_shuffle_ps(v36, v36, 170));
    v38 = _mm_mul_ps(v34, v33);
    v39 = _mm_mul_ps(v34, v35);
    v40 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
            _mm_shuffle_ps(v38, v38, 170));
    v41 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
            _mm_shuffle_ps(v39, v39, 170));
    v42 = _mm_mul_ps(v33, v33);
    v43 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
            _mm_shuffle_ps(v42, v42, 170));
    v44 = _mm_mul_ps(v35, v35);
    v45 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
            _mm_shuffle_ps(v44, v44, 170));
    v46 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v45, v43), _mm_mul_ps(v37, v37)), *(__m128 *)&epsilon);
    v47 = _mm_rcp_ps(v46);
    v48 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v47, v46)), v47);
    v49 = _mm_rcp_ps(v45);
    v50 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v45)), v49);
    v51 = _mm_rcp_ps(v43);
    v52 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v51, v43)), v51);
    v53 = _mm_sub_ps(_mm_mul_ps(v45, v40), _mm_mul_ps(v41, v37));
    v54 = _mm_cmplt_ps(v53, v46);
    v55 = _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v54, v46), _mm_and_ps(v54, v53))), v48);
    v56 = _mm_cmple_ps(v46, *(__m128 *)&epsilon);
    v57 = _mm_sub_ps(
            _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v56, v55), _mm_and_ps(v56, query.m_quad)), _mm_mul_ps(v37, v50)),
            _mm_mul_ps(v41, v50));
    v58 = _mm_cmplt_ps(v57, query.m_quad);
    v59 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v58, query.m_quad), _mm_and_ps(v58, v57)));
    v60 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v37, v52), v59), _mm_mul_ps(v40, v52));
    v61 = _mm_cmplt_ps(v60, query.m_quad);
    v62 = _mm_sub_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v61, query.m_quad), _mm_and_ps(v61, v60))),
                v33),
              v31),
            _mm_add_ps(_mm_mul_ps(v59, v35), v32));
    v63 = _mm_mul_ps(v62, v62);
    this->m_intersects |= (float)(0.001 * 0.001) > (float)((float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0]
                                                                 + _mm_shuffle_ps(v63, v63, 0).m128_f32[0])
                                                         + _mm_shuffle_ps(v63, v63, 170).m128_f32[0]);
  }
  LOBYTE(v4) = !this->m_intersects;
  return v4;
} v63, 85).m128_f32[0]
 

// File Line: 253
// RVA: 0xB5D860
void __fastcall Partitioner::~Partitioner(Partitioner *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&this->m_tree);
  m_capacityAndFlags = this->m_points.m_capacityAndFlags;
  this->m_points.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_points.m_data,
      16 * m_capacityAndFlags);
  this->m_points.m_data = 0i64;
  this->m_points.m_capacityAndFlags = 0x80000000;
  this->m_fitter.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v3 = this->m_partition.m_elem.m_capacityAndFlags;
  this->m_partition.m_elem.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_partition.m_elem.m_data,
      4 * v3);
  this->m_partition.m_elem.m_data = 0i64;
  this->m_partition.m_elem.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_boundary.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_boundary);
}

// File Line: 274
// RVA: 0xB5D9F0
hkResult *__fastcall Partitioner::addEdgeToBoundary(
        Partitioner *this,
        hkResult *result,
        hkaiNavMesh *mesh,
        unsigned int edgeIndex)
{
  hkaiNavMesh::Edge *m_data; // rax
  hkVector4f *v5; // r8
  unsigned __int64 v6; // rbx
  hkaiNavMesh::Edge *v9; // r11
  __m128 m_quad; // xmm2
  __m128 v11; // xmm1
  unsigned int v12; // eax
  hkAabb aabb; // [rsp+30h] [rbp-38h] BYREF
  hkResult v15; // [rsp+70h] [rbp+8h] BYREF
  hkResult res; // [rsp+88h] [rbp+20h] BYREF

  m_data = mesh->m_edges.m_data;
  v5 = mesh->m_vertices.m_data;
  v6 = (int)edgeIndex;
  v9 = &m_data[edgeIndex];
  m_quad = v5[v9->m_a].m_quad;
  v11 = v5[v9->m_b].m_quad;
  aabb.m_min.m_quad = _mm_min_ps(m_quad, v11);
  aabb.m_max.m_quad = _mm_max_ps(m_quad, v11);
  v12 = hkcdDynamicAabbTree::tryInsert(&this->m_tree, &aabb, edgeIndex, &res);
  if ( res.m_enum
    || (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
          &this->m_boundary.m_map,
          &hkContainerHeapAllocator::s_alloc,
          v6,
          v12,
          &v15),
        v15.m_enum) )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 307
// RVA: 0xB5DAC0
char __fastcall Partitioner::canInclude(
        Partitioner *this,
        hkaiNavMesh *mesh,
        hkaiNavMesh *origMesh,
        int faceIdx,
        int majorAxis,
        hkResult *resOut)
{
  hkResult *v6; // r12
  hkaiNavMesh *v7; // r10
  int m_numElems; // ecx
  hkaiNavMeshSimplificationUtils::Settings *m_settings; // rax
  int v13; // edi
  hkaiNavMesh::Face *v14; // r15
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  int m_size; // r14d
  int v18; // esi
  hkSimdFloat32 v19; // xmm7
  hkSimdFloat32 v20; // xmm10
  hkVector4f v21; // xmm0
  hkArray<int,hkContainerHeapAllocator> *m_edgesToRemove; // rax
  int v23; // r9d
  int v24; // edx
  __int64 v25; // rcx
  __int64 v26; // r8
  int *m_data; // rax
  hkVector4f v28; // xmm6
  int v29; // r9d
  int v30; // eax
  int v31; // eax
  hkResultEnum v32; // eax
  __m128 v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  float v36; // xmm10_4
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128i v40; // xmm11
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm6
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm3
  __m128i inserted; // xmm4
  __m128 v48; // xmm12
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __int64 v52; // rcx
  __m128 v53; // xmm6
  __m128 v54; // xmm5
  __m128i v55; // xmm12
  __m128 v56; // xmm7
  __m128i v57; // xmm7
  hkVector4f *v58; // rax
  __m128 m_quad; // xmm3
  __m128 v60; // xmm4
  __m128 v61; // xmm0
  __m128 v62; // xmm3
  __m128 v63; // xmm0
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm4
  __m128 v67; // xmm0
  __m128 v68; // xmm2
  __m128 v69; // xmm12
  __m128 v70; // xmm1
  __m128 v71; // xmm11
  __m128 v72; // xmm1
  __m128 v73; // xmm7
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  char v76; // al
  __m128 v77; // xmm3
  int v78; // eax
  int v79; // eax
  int v80; // r9d
  int v81; // eax
  int v82; // eax
  int v83; // r9d
  int m_numEdges; // r9d
  hkResultEnum v85; // eax
  char v86; // bl
  int v87; // r9d
  int v88; // r11d
  hkResultEnum v89; // eax
  int v90; // r12d
  float v91; // xmm4_4
  hkArray<int,hkContainerHeapAllocator> *v92; // rax
  int v93; // r10d
  int v94; // edx
  __int64 v95; // rcx
  __int64 v96; // r8
  int *v97; // rax
  hkaiNavMesh::Edge *v98; // r9
  hkaiNavMeshSimplificationUtils::Settings *v99; // rax
  hkVector4f v100; // xmm2
  hkVector4f *v101; // rcx
  __m128 v102; // xmm1
  __m128 v103; // xmm1
  __m128 v104; // xmm3
  __m128 v105; // xmm1
  __m128 v106; // xmm1
  __m128 v107; // xmm2
  unsigned int m_oppositeFace; // esi
  int v109; // r8d
  int *v110; // r14
  int v111; // ecx
  int v112; // edx
  int v113; // eax
  __int64 m_oppositeEdge; // rdx
  __m128 v115; // xmm6
  hkcdDynamicAabbTree *p_m_tree; // r10
  int v117; // esi
  __int64 v118; // r14
  hkVector4f *v119; // rdx
  hkaiNavMesh::Edge *v120; // rcx
  __int64 v121; // r9
  __int64 m_b; // rax
  __m128 v123; // xmm2
  __m128 v124; // xmm1
  _DWORD *v125; // [rsp+30h] [rbp-D0h] BYREF
  int v126; // [rsp+38h] [rbp-C8h]
  int v127; // [rsp+3Ch] [rbp-C4h]
  _DWORD *array; // [rsp+40h] [rbp-C0h] BYREF
  int v129; // [rsp+48h] [rbp-B8h]
  int v130; // [rsp+4Ch] [rbp-B4h]
  hkAabb newPoint; // [rsp+50h] [rbp-B0h] BYREF
  __m128 v132; // [rsp+70h] [rbp-90h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+80h] [rbp-80h] BYREF
  hkcdDynamicAabbTree *v134; // [rsp+88h] [rbp-78h]
  hkaiNavMesh *v135; // [rsp+90h] [rbp-70h]
  BOOL v136; // [rsp+98h] [rbp-68h]
  int v137; // [rsp+9Ch] [rbp-64h]
  void **p_array; // [rsp+A0h] [rbp-60h]
  int v139; // [rsp+A8h] [rbp-58h]
  char v140; // [rsp+ACh] [rbp-54h]
  hkaiNavMeshSimplificationUtils::PlaneFitter v141; // [rsp+B0h] [rbp-50h] BYREF

  v6 = resOut;
  v7 = origMesh;
  resOut->m_enum = HK_SUCCESS;
  m_numElems = this->m_partition.m_numElems;
  if ( !m_numElems )
    return 1;
  m_settings = this->m_settings;
  if ( m_numElems >= m_settings->m_maxPartitionSize )
    return 0;
  v13 = majorAxis;
  v14 = &mesh->m_faces.m_data[faceIdx];
  if ( !m_settings->m_useHeightPartitioning.m_bool || !m_settings->m_useConservativeHeightPartitioning.m_bool )
    goto LABEL_45;
  v15.m_quad = (__m128)this->m_fitter.m_sum;
  v16.m_quad = (__m128)this->m_fitter.m_productSums.m_col1;
  m_size = this->m_points.m_size;
  *(_DWORD *)&v141.m_memSizeAndFlags = 0x1FFFF;
  v18 = 0;
  v19.m_real = (__m128)this->m_minHeight;
  v20.m_real = (__m128)this->m_maxHeight;
  v141.m_sum = (hkVector4f)v15.m_quad;
  v141.vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshSimplificationUtils::PlaneFitter::`vftable;
  v141.m_numPoints = this->m_fitter.m_numPoints;
  v21.m_quad = (__m128)this->m_fitter.m_productSums.m_col0;
  v141.m_productSums.m_col1 = (hkVector4f)v16.m_quad;
  v141.m_productSums.m_col0 = (hkVector4f)v21.m_quad;
  for ( v141.m_productSums.m_col2 = this->m_fitter.m_productSums.m_col2; v18 < v14->m_numEdges; ++v18 )
  {
    m_edgesToRemove = this->m_edgesToRemove;
    v23 = v18 + v14->m_startEdgeIndex;
    if ( !this->m_edgesToRemove )
      goto LABEL_15;
    v24 = 0;
    v25 = 0i64;
    v26 = m_edgesToRemove->m_size;
    if ( v26 <= 0 )
      goto LABEL_15;
    m_data = m_edgesToRemove->m_data;
    while ( *m_data != v23 )
    {
      ++v25;
      ++v24;
      ++m_data;
      if ( v25 >= v26 )
        goto LABEL_15;
    }
    if ( v24 == -1 )
    {
LABEL_15:
      v28.m_quad = (__m128)v7->m_vertices.m_data[mesh->m_edges.m_data[v23].m_a];
      newPoint.m_min = (hkVector4f)v28.m_quad;
      hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&v141, &newPoint.m_min);
      v29 = this->m_points.m_size + 1;
      v30 = this->m_points.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v30 >= v29 )
      {
        v32 = HK_SUCCESS;
        LODWORD(resOut) = 0;
      }
      else
      {
        v31 = 2 * v30;
        if ( v29 < v31 )
          v29 = v31;
        hkArrayUtil::_reserve((hkResult *)&resOut, &hkContainerHeapAllocator::s_alloc, &this->m_points, v29, 16);
        v32 = (int)resOut;
      }
      v6->m_enum = v32;
      if ( v32 )
        return 0;
      v7 = origMesh;
      this->m_points.m_data[this->m_points.m_size++] = (hkVector4f)v28.m_quad;
      v13 = majorAxis;
      v33 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[majorAxis], v28.m_quad);
      v34 = _mm_or_ps(_mm_shuffle_ps(v33, v33, 78), v33);
      v35 = _mm_or_ps(_mm_shuffle_ps(v34, v34, 177), v34);
      v19.m_real = _mm_min_ps(v19.m_real, v35);
      v20.m_real = _mm_max_ps(v20.m_real, v35);
    }
  }
  v36 = v20.m_real.m128_f32[0] - v19.m_real.m128_f32[0];
  if ( v36 <= this->m_settings->m_maxPartitionHeightError )
    goto LABEL_40;
  hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&v141, (hkResult *)&resOut, &newPoint.m_min);
  v37 = _mm_mul_ps(newPoint.m_min.m_quad, newPoint.m_min.m_quad);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  v40 = (__m128i)_mm_mul_ps(
                   newPoint.m_min.m_quad,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v38, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                       _mm_mul_ps(*(__m128 *)_xmm, v39))));
  v41 = _mm_shuffle_ps((__m128)v40, _mm_unpackhi_ps((__m128)v40, (__m128)0i64), 196);
  v42 = _mm_shuffle_ps(v41, v41, 241);
  v43 = _mm_shuffle_ps(v41, v41, 206);
  v44 = _mm_mul_ps(v43, v43);
  v45 = _mm_mul_ps(v42, v42);
  v46 = _mm_cmplt_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
            _mm_shuffle_ps(v45, v45, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
            _mm_shuffle_ps(v44, v44, 170)));
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v48 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v46, v43), _mm_andnot_ps(v46, v42)), (__m128)inserted);
  v49 = _mm_mul_ps(v48, v48);
  v50 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)), _mm_shuffle_ps(v49, v49, 170));
  v51 = _mm_rsqrt_ps(v50);
  v52 = this->m_points.m_size;
  v53 = (__m128)xmmword_141A712A0;
  v54 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), (__m128)xmmword_141A712A0);
  v55 = (__m128i)_mm_mul_ps(
                   v48,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v50, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                       _mm_mul_ps(*(__m128 *)_xmm, v51))));
  v56 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v55, (__m128)v55, 201), (__m128)v40),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v40, (__m128)v40, 201), (__m128)v55));
  v57 = (__m128i)_mm_shuffle_ps(v56, v56, 201);
  if ( v52 > 0 )
  {
    v58 = this->m_points.m_data;
    do
    {
      m_quad = v58->m_quad;
      ++v58;
      v60 = m_quad;
      v61 = m_quad;
      v62 = _mm_mul_ps(m_quad, (__m128)v57);
      v63 = _mm_mul_ps(v61, (__m128)v55);
      v64 = _mm_mul_ps(v60, (__m128)v40);
      v65 = _mm_unpacklo_ps(v64, v63);
      v66 = _mm_unpackhi_ps(v64, v63);
      v67 = _mm_movelh_ps(v65, v62);
      v68 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v67, v65), v62, 212), v67),
              _mm_shuffle_ps(v66, v62, 228));
      v53 = _mm_min_ps(v53, v68);
      v54 = _mm_max_ps(v54, v68);
      --v52;
    }
    while ( v52 );
  }
  v69 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v55, 1u), 1u);
  v70 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v40, 1u), 1u);
  v71 = _mm_unpackhi_ps(v70, v69);
  v72 = _mm_unpacklo_ps(v70, v69);
  v73 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v57, 1u), 1u);
  newPoint.m_min.m_quad = _mm_movelh_ps(v72, v73);
  v132 = _mm_shuffle_ps(v71, v73, 228);
  newPoint.m_max.m_quad = _mm_shuffle_ps(_mm_movehl_ps(newPoint.m_min.m_quad, v72), v73, 212);
  v74 = *(&newPoint.m_min.m_quad + v13);
  v75 = _mm_rcp_ps(v74);
  v76 = _mm_movemask_ps(_mm_cmplt_ps((__m128)_xmm, v74));
  v77 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v74, v75)), v75), _mm_sub_ps(v54, v53));
  if ( (v76 & 1) != 0 )
    v36 = fmin(v36, _mm_shuffle_ps(v77, v77, 0).m128_f32[0]);
  if ( (v76 & 2) != 0 )
    v36 = fmin(v36, _mm_shuffle_ps(v77, v77, 85).m128_f32[0]);
  if ( (v76 & 4) != 0 )
    v36 = fmin(v36, _mm_shuffle_ps(v77, v77, 170).m128_f32[0]);
  if ( v36 <= this->m_settings->m_maxPartitionHeightError )
  {
LABEL_40:
    v81 = this->m_points.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v81 < m_size )
    {
      v82 = 2 * v81;
      v83 = m_size;
      if ( m_size < v82 )
        v83 = v82;
      hkArrayUtil::_reserve((hkResult *)&resOut, &hkContainerHeapAllocator::s_alloc, &this->m_points, v83, 16);
    }
    this->m_points.m_size = m_size;
LABEL_45:
    array = 0i64;
    v129 = 0;
    v130 = 0x80000000;
    m_numEdges = v14->m_numEdges;
    if ( m_numEdges <= 0 )
    {
      v85 = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve((hkResult *)&resOut, &hkContainerTempAllocator::s_alloc, &array, m_numEdges, 4);
      v85 = (int)resOut;
    }
    v6->m_enum = v85;
    if ( v85 )
    {
      v86 = 0;
    }
    else
    {
      v125 = 0i64;
      v126 = 0;
      v127 = 0x80000000;
      v87 = v14->m_numEdges;
      v88 = 0;
      if ( v87 <= 0 )
      {
        v89 = HK_SUCCESS;
      }
      else
      {
        hkArrayUtil::_reserve((hkResult *)&resOut, &hkContainerTempAllocator::s_alloc, &v125, v87, 4);
        v88 = v126;
        v89 = (int)resOut;
      }
      v6->m_enum = v89;
      if ( v89 )
      {
LABEL_85:
        v86 = 0;
      }
      else
      {
        v90 = 0;
        for ( LODWORD(v91) = _mm_shuffle_ps(
                               (__m128)LODWORD(this->m_settings->m_maxPartitionHeightError),
                               (__m128)LODWORD(this->m_settings->m_maxPartitionHeightError),
                               0).m128_u32[0]; v90 < v14->m_numEdges; ++v90 )
        {
          v92 = this->m_edgesToRemove;
          v93 = v90 + v14->m_startEdgeIndex;
          if ( !this->m_edgesToRemove )
            goto LABEL_62;
          v94 = 0;
          v95 = 0i64;
          v96 = v92->m_size;
          if ( v96 <= 0 )
            goto LABEL_62;
          v97 = v92->m_data;
          while ( *v97 != v93 )
          {
            ++v95;
            ++v94;
            ++v97;
            if ( v95 >= v96 )
              goto LABEL_62;
          }
          if ( v94 == -1 )
          {
LABEL_62:
            v98 = mesh->m_edges.m_data;
            v99 = this->m_settings;
            if ( v99->m_useHeightPartitioning.m_bool )
            {
              if ( !v99->m_useConservativeHeightPartitioning.m_bool )
              {
                v100.m_quad = (__m128)this->m_plane;
                v101 = mesh->m_vertices.m_data;
                v102 = _mm_mul_ps(v101[v98[v93].m_a].m_quad, v100.m_quad);
                v103 = _mm_shuffle_ps(v102, _mm_unpackhi_ps(v102, v100.m_quad), 196);
                v104 = _mm_add_ps(_mm_shuffle_ps(v103, v103, 78), v103);
                v105 = _mm_mul_ps(v101[v98[v93].m_b].m_quad, v100.m_quad);
                v106 = _mm_shuffle_ps(v105, _mm_unpackhi_ps(v105, v100.m_quad), 196);
                v107 = _mm_add_ps(_mm_shuffle_ps(v106, v106, 78), v106);
                if ( COERCE_FLOAT((unsigned int)(2
                                               * COERCE_INT(_mm_shuffle_ps(v104, v104, 177).m128_f32[0] + v104.m128_f32[0])) >> 1) > v91
                  || COERCE_FLOAT((unsigned int)(2
                                               * COERCE_INT(_mm_shuffle_ps(v107, v107, 177).m128_f32[0] + v107.m128_f32[0])) >> 1) > v91 )
                {
                  goto LABEL_85;
                }
              }
            }
            m_oppositeFace = v98[v93].m_oppositeFace;
            v109 = this->m_partition.m_elem.m_size - 1;
            if ( v109 <= 0
              || (v110 = this->m_partition.m_elem.m_data,
                  v111 = v109 & (-1640531535 * m_oppositeFace),
                  v112 = v110[v111],
                  v112 == -1) )
            {
LABEL_70:
              v113 = this->m_partition.m_elem.m_size;
            }
            else
            {
              while ( v112 != m_oppositeFace )
              {
                v111 = v109 & (v111 + 1);
                v112 = v110[v111];
                if ( v112 == -1 )
                  goto LABEL_70;
              }
              v113 = v111;
            }
            if ( v113 > v109 )
            {
              v125[v88] = v93;
              v88 = ++v126;
            }
            else
            {
              m_oppositeEdge = (int)v98[v93].m_oppositeEdge;
              if ( v98[v93].m_a != v98[m_oppositeEdge].m_b || v98[v93].m_b != v98[m_oppositeEdge].m_a )
                goto LABEL_85;
              array[v129++] = m_oppositeEdge;
              v88 = v126;
            }
          }
        }
        collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&Partitioner::BoundaryIntersectionQuery::`vftable;
        v115 = _mm_shuffle_ps(
                 (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
                 (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
                 0);
        p_array = (void **)&array;
        v136 = majorAxis == 0;
        p_m_tree = &this->m_tree;
        v135 = mesh;
        v139 = -1;
        v117 = 0;
        v137 = (majorAxis != 2) + 1;
        v134 = &this->m_tree;
        if ( v88 <= 0 )
        {
LABEL_84:
          v86 = 1;
          collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
        }
        else
        {
          v118 = 0i64;
          while ( 1 )
          {
            v119 = mesh->m_vertices.m_data;
            v120 = mesh->m_edges.m_data;
            v121 = (int)v125[v118];
            m_b = v120[v121].m_b;
            v123 = _mm_min_ps(v119[v120[v121].m_a].m_quad, v119[m_b].m_quad);
            v124 = _mm_max_ps(v119[v120[v121].m_a].m_quad, v119[m_b].m_quad);
            LODWORD(m_b) = this->m_aabb.m_max.m_quad.m128_i32[majorAxis];
            v139 = v125[v118];
            v140 = 0;
            newPoint.m_max.m_quad = _mm_add_ps(v124, v115);
            newPoint.m_min.m_quad = _mm_sub_ps(v123, v115);
            newPoint.m_max.m_quad.m128_i32[majorAxis] = m_b;
            newPoint.m_min.m_quad.m128_i32[majorAxis] = this->m_aabb.m_min.m_quad.m128_i32[majorAxis];
            hkcdDynamicAabbTree::queryAabb(p_m_tree, &newPoint, &collector);
            if ( v140 )
              break;
            ++v117;
            ++v118;
            if ( v117 >= v126 )
              goto LABEL_84;
            p_m_tree = v134;
          }
          v86 = 0;
          collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
        }
      }
      v126 = 0;
      if ( v127 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v125, 4 * v127);
      v127 = 0x80000000;
      v125 = 0i64;
    }
    v129 = 0;
    if ( v130 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v130);
    return v86;
  }
  v78 = this->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v78 < m_size )
  {
    v79 = 2 * v78;
    v80 = m_size;
    if ( m_size < v79 )
      v80 = v79;
    hkArrayUtil::_reserve((hkResult *)&resOut, &hkContainerHeapAllocator::s_alloc, &this->m_points, v80, 16);
  }
  this->m_points.m_size = m_size;
  return 0;
}

// File Line: 531
// RVA: 0xB5E510
hkResult *__fastcall Partitioner::include(
        Partitioner *this,
        hkResult *result,
        hkaiNavMesh *mesh,
        hkaiNavMesh *origMesh,
        int faceIdx,
        int majorAxis)
{
  int v6; // ebx
  hkaiNavMesh::Face *v10; // r12
  int v11; // r15d
  hkArray<int,hkContainerHeapAllocator> *m_edgesToRemove; // rax
  unsigned int v13; // ebx
  int v14; // edx
  __int64 v15; // rcx
  __int64 m_size; // r8
  int *m_data; // rax
  hkaiNavMesh::Edge *v18; // rdi
  hkaiNavMeshSimplificationUtils::Settings *m_settings; // rax
  hkVector4f *v20; // rax
  int v21; // r9d
  __m128 m_quad; // xmm6
  int v23; // eax
  int v24; // eax
  __int64 v25; // rax
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  bool v30; // zf
  unsigned int m_oppositeFace; // r9d
  int v32; // r8d
  int *v33; // r10
  int v34; // eax
  int v35; // edx
  int v36; // ecx
  unsigned __int64 m_oppositeEdge; // rbx
  unsigned int v38; // eax
  hkaiNavMeshSimplificationUtils::Settings *v39; // rax
  int v40; // r8d
  int v41; // r8d
  int *v42; // r10
  int v43; // r9d
  int v44; // r8d
  int v45; // ecx
  int v46; // edx
  hkResult v48; // [rsp+30h] [rbp-68h] BYREF
  hkResult v49; // [rsp+34h] [rbp-64h] BYREF
  hkResult v50; // [rsp+38h] [rbp-60h] BYREF
  hkVector4f newPoint; // [rsp+40h] [rbp-58h] BYREF
  hkResult resulta; // [rsp+B0h] [rbp+18h] BYREF
  hkaiNavMesh *v53; // [rsp+B8h] [rbp+20h]

  v53 = origMesh;
  v6 = faceIdx;
  v10 = &mesh->m_faces.m_data[faceIdx];
  v11 = 0;
  if ( v10->m_numEdges > 0 )
  {
    while ( 1 )
    {
      m_edgesToRemove = this->m_edgesToRemove;
      v13 = v11 + v10->m_startEdgeIndex;
      if ( this->m_edgesToRemove )
      {
        v14 = 0;
        v15 = 0i64;
        m_size = m_edgesToRemove->m_size;
        if ( m_size > 0 )
        {
          m_data = m_edgesToRemove->m_data;
          while ( *m_data != v13 )
          {
            ++v15;
            ++v14;
            ++m_data;
            if ( v15 >= m_size )
              goto LABEL_9;
          }
          if ( v14 != -1 )
            goto LABEL_33;
        }
      }
LABEL_9:
      v18 = &mesh->m_edges.m_data[v13];
      m_settings = this->m_settings;
      if ( m_settings->m_useHeightPartitioning.m_bool )
      {
        if ( m_settings->m_useConservativeHeightPartitioning.m_bool )
        {
          v20 = origMesh->m_vertices.m_data;
          v21 = this->m_points.m_size + 1;
          m_quad = v20[v18->m_a].m_quad;
          LODWORD(v20) = this->m_points.m_capacityAndFlags;
          newPoint.m_quad = m_quad;
          v23 = (unsigned int)v20 & 0x3FFFFFFF;
          if ( v23 >= v21 )
          {
            resulta.m_enum = HK_SUCCESS;
          }
          else
          {
            v24 = 2 * v23;
            if ( v21 < v24 )
              v21 = v24;
            hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_points, v21, 16);
            if ( resulta.m_enum )
              goto LABEL_35;
          }
          this->m_points.m_data[this->m_points.m_size++].m_quad = m_quad;
          v25 = majorAxis;
          v26 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[majorAxis], m_quad);
          v27 = _mm_or_ps(_mm_shuffle_ps(v26, v26, 78), v26);
          this->m_minHeight.m_real = _mm_min_ps(this->m_minHeight.m_real, _mm_or_ps(_mm_shuffle_ps(v27, v27, 177), v27));
          v28 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v25], m_quad);
          v29 = _mm_or_ps(_mm_shuffle_ps(v28, v28, 78), v28);
          this->m_maxHeight.m_real = _mm_max_ps(this->m_maxHeight.m_real, _mm_or_ps(_mm_shuffle_ps(v29, v29, 177), v29));
        }
        else
        {
          newPoint.m_quad = (__m128)mesh->m_vertices.m_data[v18->m_a];
        }
        hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&this->m_fitter, &newPoint);
      }
      if ( !this->m_partition.m_numElems )
        break;
      m_oppositeFace = v18->m_oppositeFace;
      v32 = this->m_partition.m_elem.m_size - 1;
      if ( v32 <= 0
        || (v33 = this->m_partition.m_elem.m_data, v34 = v32 & (-1640531535 * m_oppositeFace), v35 = v33[v34], v35 == -1) )
      {
LABEL_26:
        v36 = this->m_partition.m_elem.m_size;
      }
      else
      {
        while ( v35 != m_oppositeFace )
        {
          v34 = v32 & (v34 + 1);
          v35 = v33[v34];
          if ( v35 == -1 )
            goto LABEL_26;
        }
        v36 = v34;
      }
      if ( v36 > v32 )
      {
        Partitioner::addEdgeToBoundary(this, &v49, mesh, v13);
        v30 = v49.m_enum == HK_SUCCESS;
LABEL_31:
        if ( !v30 )
          goto LABEL_35;
        goto LABEL_32;
      }
      m_oppositeEdge = (int)v18->m_oppositeEdge;
      v38 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &this->m_boundary.m_map,
              m_oppositeEdge,
              0xFFFFFFFFui64);
      hkcdDynamicAabbTree::remove(&this->m_tree, v38);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
        &this->m_boundary.m_map,
        &v50,
        m_oppositeEdge);
LABEL_32:
      origMesh = v53;
LABEL_33:
      if ( ++v11 >= v10->m_numEdges )
      {
        v6 = faceIdx;
        goto LABEL_37;
      }
    }
    Partitioner::addEdgeToBoundary(this, &v48, mesh, v13);
    v30 = v48.m_enum == HK_SUCCESS;
    goto LABEL_31;
  }
LABEL_37:
  v39 = this->m_settings;
  if ( v39->m_useHeightPartitioning.m_bool && !v39->m_useConservativeHeightPartitioning.m_bool )
    hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&this->m_fitter, (hkResult *)&faceIdx, &this->m_plane);
  v40 = this->m_partition.m_elem.m_size - 1;
  if ( 2 * this->m_partition.m_numElems > v40
    && hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::resizeTable(
         &this->m_partition,
         (hkResult *)&faceIdx,
         2 * v40 + 2)->m_enum )
  {
LABEL_35:
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v41 = this->m_partition.m_elem.m_size;
    if ( 2 * this->m_partition.m_numElems > v41 - 1 )
      hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::resizeTable(
        &this->m_partition,
        (hkResult *)&faceIdx,
        2 * v41);
    v42 = this->m_partition.m_elem.m_data;
    v43 = this->m_partition.m_elem.m_size - 1;
    v44 = 1;
    v45 = v43 & (-1640531535 * v6);
    v46 = v42[v45];
    if ( v46 != -1 )
    {
      while ( v46 != v6 )
      {
        v45 = v43 & (v45 + 1);
        v46 = v42[v45];
        if ( v46 == -1 )
          goto LABEL_49;
      }
      v44 = 0;
    }
LABEL_49:
    this->m_partition.m_numElems += v44;
    result->m_enum = HK_SUCCESS;
    v42[v45] = v6;
  }
  return result;
}

// File Line: 617
// RVA: 0xB5C280
hkResult *__fastcall partitionFaces(
        hkResult *result,
        hkaiNavMesh *mesh,
        unsigned __int64 origMesh,
        const __m128i *up,
        Partitioner *partitioner,
        hkArray<int,hkContainerHeapAllocator> *numFacesInPartition,
        hkArrayBase<unsigned int> *partitions,
        hkArray<int,hkContainerHeapAllocator> *numEdgesInGroupInOut,
        hkArray<int,hkContainerHeapAllocator> *edgesToRemoveInOut)
{
  __int64 m_size; // r9
  hkaiNavMesh *v11; // r15
  int v13; // edi
  int v14; // r8d
  int v16; // ebx
  int v17; // r9d
  __int64 v18; // rcx
  char *v19; // rdi
  int *v20; // rdi
  __int64 v21; // rcx
  __int64 v22; // rdx
  Partitioner *v23; // r13
  int v24; // ebx
  int v25; // r12d
  int v26; // edi
  __int32 v27; // eax
  float *m_data; // r9
  int m_capacityAndFlags; // r8d
  int v30; // r9d
  hkResult *v31; // rdi
  __int64 v32; // r8
  float *v33; // rdx
  __int64 v34; // rcx
  float *v35; // rdi
  __m128 v36; // xmm3
  int v37; // r8d
  int m_elementsInUse; // ebx
  int m_head; // r14d
  int m_tail; // edi
  int v41; // esi
  int m_capacity; // r15d
  int v43; // edx
  __int64 v44; // rcx
  int v45; // edi
  int v46; // ebx
  unsigned int *v47; // r9
  int v48; // r10d
  __int64 v49; // rcx
  __int64 v50; // rsi
  __int64 v51; // r13
  float v52; // edx
  hkaiNavMesh *v53; // r11
  hkaiNavMesh::Face *v54; // r12
  hkResultEnum v55; // edx
  bool v56; // al
  int v57; // ecx
  int v58; // r9d
  __int64 m_startEdgeIndex; // r15
  hkaiNavMesh *v60; // r11
  __int64 v61; // r14
  hkaiNavMesh::Edge *v62; // rsi
  unsigned int m_oppositeFace; // ecx
  int v64; // eax
  unsigned int v65; // esi
  int v66; // edx
  __int64 v67; // rcx
  hkArray<int,hkContainerHeapAllocator> *v68; // r11
  hkResultEnum v69; // ecx
  bool v70; // cc
  __int64 v71; // r13
  __int64 v72; // r14
  char v73; // si
  __int64 m_enum; // r15
  char v75; // bl
  __int64 v76; // r14
  __int64 v77; // r11
  int *v78; // r8
  int v79; // ecx
  __int64 v80; // rax
  hkArray<int,hkContainerHeapAllocator> *v81; // rsi
  __int64 v82; // r11
  __int64 v83; // r8
  int v84; // ecx
  __int64 v85; // rax
  int v86; // r10d
  __int64 v87; // rbx
  int v88; // ecx
  int v89; // r9d
  int v90; // r9d
  int v91; // r8d
  int *v92; // rcx
  int v93; // edx
  __int64 v94; // rdx
  int v95; // eax
  __int64 v96; // rdx
  __int32 v97; // r8d
  char *v98; // rdi
  __int64 v99; // rcx
  int v100; // eax
  int v101; // r9d
  int v102; // eax
  int v103; // eax
  int v104; // ecx
  int v105; // r9d
  int v106; // eax
  int v107; // eax
  int v108; // r8d
  unsigned int *v109; // [rsp+30h] [rbp-B1h] BYREF
  int numtoinsert; // [rsp+38h] [rbp-A9h]
  int v111; // [rsp+3Ch] [rbp-A5h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+40h] [rbp-A1h] BYREF
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v113; // [rsp+50h] [rbp-91h] BYREF
  hkResult resulta; // [rsp+60h] [rbp-81h] BYREF
  char *array; // [rsp+68h] [rbp-79h] BYREF
  int v116; // [rsp+70h] [rbp-71h]
  int v117; // [rsp+74h] [rbp-6Dh]
  hkaMatrix<float> v118; // [rsp+78h] [rbp-69h] BYREF
  hkQueue<hkpRigidBody *> v119; // [rsp+90h] [rbp-51h] BYREF
  hkResult v120; // [rsp+A8h] [rbp-39h] BYREF
  hkResult v121; // [rsp+ACh] [rbp-35h] BYREF
  int majorAxis; // [rsp+B0h] [rbp-31h]
  hkResult v123; // [rsp+B4h] [rbp-2Dh] BYREF
  hkResult v124; // [rsp+B8h] [rbp-29h] BYREF
  hkResult v125; // [rsp+BCh] [rbp-25h] BYREF
  hkResult v126; // [rsp+C0h] [rbp-21h] BYREF
  hkResult v127; // [rsp+C4h] [rbp-1Dh] BYREF
  hkResult resOut; // [rsp+C8h] [rbp-19h] BYREF
  __int64 v129; // [rsp+D0h] [rbp-11h]
  hkaiNavMesh *origMesha; // [rsp+130h] [rbp+4Fh]

  origMesha = (hkaiNavMesh *)origMesh;
  m_size = (unsigned int)mesh->m_edges.m_size;
  v11 = mesh;
  v117 = 0x80000000;
  array = 0i64;
  v13 = 0;
  v116 = 0;
  if ( (int)m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 4);
    if ( resulta.m_enum )
    {
      v14 = v117;
      result->m_enum = HK_FAILURE;
      v116 = 0;
      if ( v14 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v14);
      return result;
    }
    v13 = v116;
  }
  v16 = v11->m_edges.m_size;
  if ( (v117 & 0x3FFFFFFF) < v16 )
  {
    v17 = v11->m_edges.m_size;
    if ( v16 < 2 * (v117 & 0x3FFFFFFF) )
      v17 = 2 * (v117 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v120, &hkContainerTempAllocator::s_alloc, &array, v17, 4);
    v13 = v116;
  }
  v18 = v16 - v13;
  if ( v16 - v13 > 0 )
  {
    v19 = &array[4 * v13];
    while ( v18 )
    {
      *(_DWORD *)v19 = -1;
      v19 += 4;
      --v18;
    }
  }
  v116 = v16;
  if ( edgesToRemoveInOut->m_size )
  {
    origMesh = 0i64;
    if ( v11->m_faces.m_size > 0 )
    {
      m_size = 0i64;
      do
      {
        v20 = (int *)((char *)&v11->m_faces.m_data->m_startEdgeIndex + m_size);
        v21 = *v20;
        if ( (int)v21 < (int)v21 + *((__int16 *)v20 + 4) )
        {
          v22 = 4 * v21;
          do
          {
            LODWORD(v21) = v21 + 1;
            v22 += 4i64;
            *(_DWORD *)&array[v22 - 4] = origMesh;
          }
          while ( (int)v21 < *v20 + *((__int16 *)v20 + 4) );
        }
        origMesh = (unsigned int)(origMesh + 1);
        m_size += 16i64;
      }
      while ( (int)origMesh < v11->m_faces.m_size );
    }
    v23 = partitioner;
    partitioner->m_edgesToRemove = edgesToRemoveInOut;
  }
  else
  {
    v23 = partitioner;
  }
  v24 = v11->m_faces.m_size;
  v25 = 0;
  a.m_capacityAndFlags = 0x80000000;
  a.m_data = 0i64;
  a.m_size = 0;
  v26 = (v24 + 31) >> 5;
  v113.m_data = 0i64;
  v113.m_size = 0;
  v113.m_capacityAndFlags = 0x80000000;
  v118.m_data.m_data = 0i64;
  v118.m_data.m_size = 0;
  v27 = v26;
  v118.m_data.m_capacityAndFlags = 0x80000000;
  if ( v26 )
  {
    resulta.m_enum = 4 * v26;
    m_data = (float *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, unsigned __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                        &hkContainerHeapAllocator::s_alloc,
                        &resulta,
                        origMesh,
                        m_size);
    v27 = resulta.m_enum / 4;
  }
  else
  {
    m_data = 0i64;
  }
  m_capacityAndFlags = 0x80000000;
  v118.m_data.m_data = m_data;
  if ( v27 )
    m_capacityAndFlags = v27;
  v118.m_data.m_size = (v24 + 31) >> 5;
  v118.m_m = v24;
  v118.m_data.m_capacityAndFlags = m_capacityAndFlags;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < v26 )
  {
    v30 = (v24 + 31) >> 5;
    if ( v26 < 2 * (m_capacityAndFlags & 0x3FFFFFFF) )
      v30 = 2 * (m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v120, &hkContainerHeapAllocator::s_alloc, &v118, v30, 4);
    m_capacityAndFlags = v118.m_data.m_capacityAndFlags;
    m_data = v118.m_data.m_data;
  }
  v118.m_data.m_size = (v24 + 31) >> 5;
  if ( !m_data )
  {
    v31 = result;
    v118.m_data.m_size = 0;
    result->m_enum = HK_FAILURE;
    if ( m_capacityAndFlags < 0 )
    {
LABEL_38:
      v118.m_data.m_data = 0i64;
      v118.m_data.m_capacityAndFlags = 0x80000000;
LABEL_50:
      v113.m_size = 0;
      if ( v113.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v113.m_data,
          4 * v113.m_capacityAndFlags);
      v113.m_data = 0i64;
      v113.m_capacityAndFlags = 0x80000000;
      a.m_size = 0;
      if ( a.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          a.m_data,
          4 * a.m_capacityAndFlags);
      a.m_data = 0i64;
      v116 = 0;
      goto LABEL_55;
    }
    v32 = (unsigned int)(4 * m_capacityAndFlags);
    v33 = 0i64;
LABEL_37:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v33, v32);
    goto LABEL_38;
  }
  if ( v26 - 1 >= 0 )
  {
    v34 = (unsigned int)v26;
    v35 = m_data;
    while ( v34 )
    {
      *v35++ = NAN;
      --v34;
    }
  }
  v36 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(up), 1u), 1u);
  majorAxis = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmple_ps(
                                                                         _mm_max_ps(
                                                                           _mm_shuffle_ps(v36, v36, 170),
                                                                           _mm_max_ps(
                                                                             _mm_shuffle_ps(v36, v36, 85),
                                                                             _mm_shuffle_ps(v36, v36, 0))),
                                                                         v36),
                                                                       (__m128)xmmword_141A4CC80))];
  hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v119);
  hkQueue<int>::setCapacity((hkQueue<int> *)&v119, 8);
  if ( !v119.m_data )
  {
    v31 = result;
    result->m_enum = HK_FAILURE;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v119);
    v118.m_data.m_size = 0;
    if ( v118.m_data.m_capacityAndFlags < 0 )
      goto LABEL_38;
    v33 = v118.m_data.m_data;
    v32 = (unsigned int)(4 * v118.m_data.m_capacityAndFlags);
    goto LABEL_37;
  }
LABEL_46:
  v37 = v11->m_faces.m_size;
  m_elementsInUse = 0;
  m_head = 0;
  *(_QWORD *)&v119.m_head = 0i64;
  m_tail = 0;
  v41 = 0;
  v119.m_elementsInUse = 0;
  if ( v37 <= 0 )
    goto LABEL_49;
  while ( ((LODWORD(v118.m_data.m_data[(__int64)v41 >> 5]) >> (v41 & 0x1F)) & 1) == 0 )
  {
    if ( ++v41 >= v37 )
      goto LABEL_49;
  }
  m_capacity = v119.m_capacity;
  if ( v119.m_capacity <= 0 )
  {
    v43 = 8;
    if ( v119.m_capacity )
      v43 = 2 * v119.m_capacity;
    hkQueue<int>::setCapacity((hkQueue<int> *)&v119, v43);
    m_capacity = v119.m_capacity;
    m_head = v119.m_head;
    m_tail = v119.m_tail;
    m_elementsInUse = v119.m_elementsInUse;
  }
  if ( m_tail == m_capacity )
    m_tail = 0;
  v44 = m_tail;
  v45 = m_tail + 1;
  v46 = m_elementsInUse + 1;
  v119.m_elementsInUse = v46;
  *((_DWORD *)v119.m_data + v44) = v41;
  v119.m_tail = v45;
  if ( !v46 )
  {
LABEL_49:
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)numEdgesInGroupInOut,
      &a);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)edgesToRemoveInOut,
      &v113);
    v31 = result;
    result->m_enum = HK_SUCCESS;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v119);
    hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v118);
    goto LABEL_50;
  }
  resulta.m_enum = -1;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&v23->m_boundary.m_map);
  hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::clear(&v23->m_partition);
  hkaiNavMeshSimplificationUtils::PlaneFitter::reset(&v23->m_fitter);
  v23->m_points.m_size = 0;
  v23->m_plane = 0i64;
  v23->m_minHeight = (hkSimdFloat32)xmmword_141A712A0;
  v23->m_maxHeight.m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  hkcdDynamicAabbTree::clear(&v23->m_tree);
  v47 = 0i64;
  v109 = 0i64;
  v48 = 0;
  numtoinsert = 0;
  v111 = 0x80000000;
  while ( 1 )
  {
    v49 = m_head++;
    v50 = *((int *)v119.m_data + v49);
    if ( m_head == m_capacity )
      m_head = 0;
    --v46;
    v119.m_head = m_head;
    v51 = v50 >> 5;
    v52 = v118.m_data.m_data[v51];
    v119.m_elementsInUse = v46;
    if ( ((LODWORD(v52) >> (v50 & 0x1F)) & 1) == 0 )
      goto LABEL_103;
    v53 = mesh;
    v54 = &mesh->m_faces.m_data[v50];
    if ( mesh->m_faceDataStriding )
      v55 = mesh->m_faceData.m_data[v50 * mesh->m_faceDataStriding];
    else
      v55 = HK_SUCCESS;
    if ( !v48 )
    {
      resulta.m_enum = v55;
      goto LABEL_78;
    }
    if ( v55 == resulta.m_enum )
      break;
LABEL_102:
    v25 = 0;
LABEL_103:
    m_capacity = v119.m_capacity;
    if ( !v46 )
    {
      v68 = numEdgesInGroupInOut;
      v69 = HK_SUCCESS;
      v70 = numEdgesInGroupInOut->m_size <= 0;
      resulta.m_enum = HK_SUCCESS;
      if ( !v70 )
      {
        v71 = 0i64;
        while ( 1 )
        {
          v72 = v69;
          v73 = 0;
          m_enum = v68->m_data[v71];
          v75 = 1;
          v129 = v69;
          v120.m_enum = (int)m_enum;
          if ( (int)m_enum <= 0 )
            goto LABEL_130;
          v76 = v69;
          v77 = m_enum;
          v78 = &edgesToRemoveInOut->m_data[v76];
          do
          {
            v79 = 0;
            v80 = 0i64;
            if ( v48 <= 0 )
              goto LABEL_111;
            while ( v47[v80] != *(_DWORD *)&array[4 * *v78] )
            {
              ++v80;
              ++v79;
              if ( v80 >= v48 )
                goto LABEL_111;
            }
            if ( v79 == -1 )
LABEL_111:
              v75 = 0;
            else
              v73 = 1;
            ++v78;
            --v77;
          }
          while ( v77 );
          m_enum = v120.m_enum;
          if ( v75 )
            break;
          if ( v73 )
          {
            v81 = edgesToRemoveInOut;
            v82 = v120.m_enum;
            do
            {
              v83 = *(int *)&array[4 * edgesToRemoveInOut->m_data[v76]];
              v84 = 0;
              v85 = 0i64;
              if ( v48 > 0 )
              {
                while ( v47[v85] != (_DWORD)v83 )
                {
                  ++v85;
                  ++v84;
                  if ( v85 >= v48 )
                    goto LABEL_126;
                }
                if ( v85 != -1 )
                {
                  v86 = v48 - 1;
                  numtoinsert = v86;
                  if ( v86 != v84 )
                    v47[v85] = v47[v86];
                  LODWORD(v118.m_data.m_data[v83 >> 5]) |= 1 << (v83 & 0x1F);
                  v48 = numtoinsert;
                  v47 = v109;
                }
              }
LABEL_126:
              ++v76;
              --v82;
            }
            while ( v82 );
            v72 = v129;
            v87 = m_enum;
            goto LABEL_152;
          }
          v68 = numEdgesInGroupInOut;
          v69 = v120.m_enum + resulta.m_enum;
          resulta.m_enum += v120.m_enum;
LABEL_161:
          ++v25;
          ++v71;
          if ( v25 >= v68->m_size )
            goto LABEL_162;
        }
        v72 = v129;
LABEL_130:
        v88 = a.m_size;
        v89 = a.m_size + 1;
        if ( (a.m_capacityAndFlags & 0x3FFFFFFF) >= a.m_size + 1 )
        {
          v126.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v89 < 2 * (a.m_capacityAndFlags & 0x3FFFFFFF) )
            v89 = 2 * (a.m_capacityAndFlags & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v126, &hkContainerHeapAllocator::s_alloc, &a, v89, 4);
          if ( v126.m_enum )
            goto LABEL_140;
          v88 = a.m_size;
        }
        *(&a.m_data->m_fromOffset + v88) = m_enum;
        ++a.m_size;
        v90 = m_enum + v113.m_size;
        if ( (v113.m_capacityAndFlags & 0x3FFFFFFF) >= (int)m_enum + v113.m_size )
        {
          v123.m_enum = HK_SUCCESS;
        }
        else
        {
          if ( v90 < 2 * (v113.m_capacityAndFlags & 0x3FFFFFFF) )
            v90 = 2 * (v113.m_capacityAndFlags & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v123, &hkContainerHeapAllocator::s_alloc, &v113, v90, 4);
          if ( v123.m_enum )
            goto LABEL_140;
        }
        v81 = edgesToRemoveInOut;
        hkArrayBase<unsigned int>::_append(
          (hkArrayBase<unsigned int> *)&v113,
          &hkContainerHeapAllocator::s_alloc,
          (const unsigned int *)&edgesToRemoveInOut->m_data[v72],
          m_enum);
        v48 = numtoinsert;
        v47 = v109;
        v87 = (int)m_enum;
LABEL_152:
        v68 = numEdgesInGroupInOut;
        --numEdgesInGroupInOut->m_size;
        v92 = &numEdgesInGroupInOut->m_data[v71];
        v93 = 4 * (numEdgesInGroupInOut->m_size - v25);
        if ( v93 > 0 )
        {
          v94 = ((unsigned int)(v93 - 1) >> 2) + 1;
          do
          {
            v95 = v92[1];
            *v92++ = v95;
            --v94;
          }
          while ( v94 );
          v48 = numtoinsert;
          v47 = v109;
        }
        v81->m_size -= m_enum;
        v96 = (__int64)&v81->m_data[v72];
        v97 = 4 * (v81->m_size - resulta.m_enum);
        if ( v97 > 0 )
        {
          v98 = (char *)&v81->m_data[v87 + v72] - v96;
          v99 = ((unsigned int)(v97 - 1) >> 2) + 1;
          do
          {
            v100 = *(_DWORD *)&v98[v96];
            v96 += 4i64;
            *(_DWORD *)(v96 - 4) = v100;
            --v99;
          }
          while ( v99 );
          v48 = numtoinsert;
          v47 = v109;
        }
        v69 = resulta.m_enum;
        --v25;
        --v71;
        goto LABEL_161;
      }
LABEL_162:
      if ( v48 )
      {
        v101 = numFacesInPartition->m_size + 1;
        v102 = numFacesInPartition->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v102 >= v101 )
        {
          v125.m_enum = HK_SUCCESS;
        }
        else
        {
          v103 = 2 * v102;
          if ( v101 < v103 )
            v101 = v103;
          hkArrayUtil::_reserve(&v125, &hkContainerHeapAllocator::s_alloc, numFacesInPartition, v101, 4);
          if ( v125.m_enum )
          {
LABEL_179:
            v108 = v111;
            v31 = result;
            numtoinsert = 0;
            result->m_enum = HK_FAILURE;
            if ( v108 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v109, 4 * v108);
            v109 = 0i64;
            v111 = 0x80000000;
            hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v119);
            hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v118);
            goto LABEL_145;
          }
          v48 = numtoinsert;
        }
        numFacesInPartition->m_data[numFacesInPartition->m_size++] = v48;
        v104 = numtoinsert;
        v105 = numtoinsert + partitions->m_size;
        v106 = partitions->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v106 >= v105 )
        {
          v121.m_enum = HK_SUCCESS;
        }
        else
        {
          v107 = 2 * v106;
          if ( v105 < v107 )
            v105 = v107;
          hkArrayUtil::_reserve(&v121, &hkContainerHeapAllocator::s_alloc, partitions, v105, 4);
          if ( v121.m_enum )
            goto LABEL_179;
          v104 = numtoinsert;
        }
        hkArrayBase<unsigned int>::_append(partitions, &hkContainerHeapAllocator::s_alloc, v109, v104);
        v47 = v109;
      }
      v25 = 0;
      numtoinsert = 0;
      if ( v111 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v47, 4 * v111);
      v11 = mesh;
      v23 = partitioner;
      v109 = 0i64;
      v111 = 0x80000000;
      goto LABEL_46;
    }
  }
  v56 = !Partitioner::canInclude(partitioner, mesh, origMesha, v50, majorAxis, &resOut);
  if ( resOut.m_enum )
    goto LABEL_140;
  if ( v56 )
  {
LABEL_101:
    v47 = v109;
    v48 = numtoinsert;
    goto LABEL_102;
  }
  v53 = mesh;
LABEL_78:
  Partitioner::include(partitioner, &v127, v53, origMesha, v50, majorAxis);
  if ( v127.m_enum )
    goto LABEL_140;
  v57 = numtoinsert;
  v58 = numtoinsert + 1;
  if ( (v111 & 0x3FFFFFFF) >= numtoinsert + 1 )
  {
    v124.m_enum = HK_SUCCESS;
LABEL_85:
    v109[v57] = v50;
    ++numtoinsert;
    LODWORD(v118.m_data.m_data[v51]) &= ~(1 << (v50 & 0x1F));
    m_startEdgeIndex = v54->m_startEdgeIndex;
    if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + v54->m_numEdges )
    {
      v60 = mesh;
      v61 = m_startEdgeIndex;
      do
      {
        v62 = &v60->m_edges.m_data[v61];
        m_oppositeFace = v62->m_oppositeFace;
        if ( m_oppositeFace != -1
          && ((LODWORD(v118.m_data.m_data[(__int64)(int)v62->m_oppositeFace >> 5]) >> (m_oppositeFace & 0x1F)) & 1) != 0 )
        {
          v64 = v119.m_capacity;
          if ( v46 >= v119.m_capacity )
          {
            hkQueue<int>::setCapacity((hkQueue<int> *)&v119, 2 * v119.m_capacity);
            if ( !v119.m_data )
              goto LABEL_140;
            v46 = v119.m_elementsInUse;
            v45 = v119.m_tail;
            v64 = v119.m_capacity;
          }
          v65 = v62->m_oppositeFace;
          if ( v46 >= v64 )
          {
            v66 = 8;
            if ( v64 )
              v66 = 2 * v64;
            hkQueue<int>::setCapacity((hkQueue<int> *)&v119, v66);
            v64 = v119.m_capacity;
            v45 = v119.m_tail;
            v46 = v119.m_elementsInUse;
          }
          v60 = mesh;
          if ( v45 == v64 )
            v45 = 0;
          v67 = v45++;
          ++v46;
          *((_DWORD *)v119.m_data + v67) = v65;
          v119.m_elementsInUse = v46;
          v119.m_tail = v45;
        }
        LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
        ++v61;
      }
      while ( (int)m_startEdgeIndex < v54->m_startEdgeIndex + v54->m_numEdges );
      m_head = v119.m_head;
    }
    goto LABEL_101;
  }
  if ( v58 < 2 * (v111 & 0x3FFFFFFF) )
    v58 = 2 * (v111 & 0x3FFFFFFF);
  hkArrayUtil::_reserve(&v124, &hkContainerTempAllocator::s_alloc, &v109, v58, 4);
  if ( v124.m_enum == HK_SUCCESS )
  {
    v57 = numtoinsert;
    goto LABEL_85;
  }
LABEL_140:
  v91 = v111;
  v31 = result;
  result->m_enum = HK_FAILURE;
  numtoinsert = 0;
  if ( v91 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v109, 4 * v91);
  v109 = 0i64;
  v111 = 0x80000000;
  hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v119);
  v118.m_data.m_size = 0;
  if ( v118.m_data.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v118.m_data.m_data,
      4 * v118.m_data.m_capacityAndFlags);
  v118.m_data.m_data = 0i64;
  v118.m_data.m_capacityAndFlags = 0x80000000;
LABEL_145:
  v113.m_size = 0;
  if ( v113.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v113.m_data,
      4 * v113.m_capacityAndFlags);
  v113.m_data = 0i64;
  v113.m_capacityAndFlags = 0x80000000;
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      a.m_data,
      4 * a.m_capacityAndFlags);
  a.m_data = 0i64;
  v116 = 0;
LABEL_55:
  a.m_capacityAndFlags = 0x80000000;
  if ( v117 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v117);
  return v31;
}TempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v117);
  return v31;
}

// File Line: 815
// RVA: 0xB5CFE0
void __fastcall getOnePartitionWC(
        hkSimdFloat32 *mesh,
        hkaiNavMesh *origMesh,
        Partitioner *partitioner,
        unsigned int startingFace,
        hkVector4f *parDir,
        hkArray<int,hkContainerTempAllocator> *newPartition,
        hkBitField *unassignedFacesInOut)
{
  hkSimdFloat32 *v8; // r15
  __m128 v10; // xmm2
  int v11; // r12d
  int m_elementsInUse; // esi
  int m_capacity; // r14d
  int v14; // edx
  int m_tail; // edi
  __int64 v16; // rcx
  int v17; // edi
  int v18; // esi
  int m_head; // ebx
  __int64 v20; // rcx
  hkaiNavMesh *v21; // r10
  hkArray<int,hkContainerHeapAllocator> *m_edgesToRemove; // rax
  unsigned int v23; // edx
  int *v24; // r13
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  Partitioner *v28; // r8
  __int64 v29; // r12
  __int64 v30; // r15
  __int64 v31; // rbx
  int v32; // edx
  __int64 v33; // rcx
  hkQueue<hkpRigidBody *> v34; // [rsp+10h] [rbp-71h] BYREF
  int resOut; // [rsp+28h] [rbp-59h]
  int resOut_4; // [rsp+2Ch] [rbp-55h]
  int v37; // [rsp+30h] [rbp-51h]
  hkResult result; // [rsp+34h] [rbp-4Dh] BYREF
  hkResult v39; // [rsp+38h] [rbp-49h] BYREF
  __int64 v40; // [rsp+40h] [rbp-41h]
  int v41[4]; // [rsp+50h] [rbp-31h] BYREF
  int faceIndex[4]; // [rsp+60h] [rbp-21h]
  hkaiNavMeshUtils v43[16]; // [rsp+70h] [rbp-11h] BYREF
  __int64 v44; // [rsp+80h] [rbp-1h] BYREF
  hkSimdFloat32 *v45; // [rsp+D0h] [rbp+4Fh]
  hkaiNavMesh *origMesha; // [rsp+D8h] [rbp+57h]
  Partitioner *vars0; // [rsp+E0h] [rbp+5Fh]

  v8 = mesh;
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    v43,
    mesh,
    (hkaiNavMesh *)startingFace,
    (int)&v44,
    *(hkVector4f **)&v34.m_tail);
  v10 = _mm_mul_ps(mesh->m_real, *(__m128 *)faceIndex);
  if ( (float)((float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
             + _mm_shuffle_ps(v10, v10, 170).m128_f32[0]) >= 0.5 )
  {
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&partitioner->m_boundary.m_map);
    hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::clear(&partitioner->m_partition);
    hkaiNavMeshSimplificationUtils::PlaneFitter::reset(&partitioner->m_fitter);
    v11 = 0;
    partitioner->m_points.m_size = 0;
    partitioner->m_plane = 0i64;
    partitioner->m_minHeight = (hkSimdFloat32)xmmword_141A712A0;
    partitioner->m_maxHeight.m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
    hkcdDynamicAabbTree::clear(&partitioner->m_tree);
    resOut_4 = -1;
    hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v34);
    m_elementsInUse = v34.m_elementsInUse;
    m_capacity = v34.m_capacity;
    if ( v34.m_elementsInUse >= v34.m_capacity )
    {
      v14 = 8;
      if ( v34.m_capacity )
        v14 = 2 * v34.m_capacity;
      hkQueue<int>::setCapacity((hkQueue<int> *)&v34, v14);
      m_capacity = v34.m_capacity;
      m_elementsInUse = v34.m_elementsInUse;
    }
    m_tail = v34.m_tail;
    if ( v34.m_tail == m_capacity )
      m_tail = 0;
    v16 = m_tail;
    v17 = m_tail + 1;
    v18 = m_elementsInUse + 1;
    v34.m_elementsInUse = v18;
    *((_DWORD *)v34.m_data + v16) = startingFace;
    v34.m_tail = v17;
    if ( v18 )
    {
      m_head = v34.m_head;
      while ( 1 )
      {
        v20 = m_head++;
        v21 = (hkaiNavMesh *)*((int *)v34.m_data + v20);
        if ( m_head == m_capacity )
          m_head = 0;
        --v18;
        resOut = *((_DWORD *)v34.m_data + v20);
        m_edgesToRemove = partitioner->m_edgesToRemove;
        v40 = 4 * ((__int64)v21 >> 5);
        v34.m_head = m_head;
        v23 = *(_DWORD *)((char *)&m_edgesToRemove->m_data + v40);
        v34.m_elementsInUse = v18;
        v37 = (unsigned __int8)v21 & 0x1F;
        if ( ((v23 >> ((unsigned __int8)v21 & 0x1F)) & 1) == 0 )
          goto LABEL_37;
        v24 = (int *)(v8[1].m_real.m128_u64[0] + 16i64 * (_QWORD)v21);
        if ( v8[7].m_real.m128_i32[0] )
          v11 = *(_DWORD *)(v8[5].m_real.m128_u64[0] + 4 * (_QWORD)v21 * v8[7].m_real.m128_i32[0]);
        if ( !*(_DWORD *)&origMesh->m_memSizeAndFlags )
          break;
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(v43, v8, v21, (int)v41, *(hkVector4f **)&v34.m_tail);
        v25 = _mm_mul_ps(mesh->m_real, *(__m128 *)v41);
        if ( (float)((float)(_mm_shuffle_ps(v25, v25, 85).m128_f32[0] + _mm_shuffle_ps(v25, v25, 0).m128_f32[0])
                   + _mm_shuffle_ps(v25, v25, 170).m128_f32[0]) >= 0.5
          && v11 == resOut_4 )
        {
          v26 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)mesh->m_real, 1u), 1u);
          if ( Partitioner::canInclude(
                 vars0,
                 (hkaiNavMesh *)v8,
                 origMesha,
                 resOut,
                 (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                        _mm_and_ps(
                                                                          _mm_cmple_ps(
                                                                            _mm_max_ps(
                                                                              _mm_shuffle_ps(v26, v26, 170),
                                                                              _mm_max_ps(
                                                                                _mm_shuffle_ps(v26, v26, 85),
                                                                                _mm_shuffle_ps(v26, v26, 0))),
                                                                            v26),
                                                                          (__m128)xmmword_141A4CC80))],
                 &v39) )
          {
            LODWORD(v21) = resOut;
            goto LABEL_21;
          }
        }
LABEL_36:
        v11 = 0;
LABEL_37:
        if ( !v18 )
          goto LABEL_38;
      }
      resOut_4 = v11;
LABEL_21:
      v27 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)mesh), 1u), 1u);
      Partitioner::include(
        vars0,
        &result,
        (hkaiNavMesh *)v8,
        origMesha,
        (int)v21,
        (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v27, v27, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v27, v27, 85),
                                                                       _mm_shuffle_ps(v27, v27, 0))),
                                                                   v27),
                                                                 (__m128)xmmword_141A4CC80))]);
      if ( *(_DWORD *)&origMesh->m_memSizeAndFlags == (*(_DWORD *)(&origMesh->m_referenceCount + 1) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, origMesh, 4);
      v28 = partitioner;
      *((_DWORD *)&origMesh->vfptr->__vecDelDtor + (int)(*(_DWORD *)&origMesh->m_memSizeAndFlags)++) = resOut;
      *(_DWORD *)((char *)&partitioner->m_edgesToRemove->m_data + v40) &= ~(1 << v37);
      v29 = *v24;
      if ( (int)v29 < (int)v29 + *((__int16 *)v24 + 4) )
      {
        v30 = 20 * v29;
        do
        {
          v31 = *(int *)(v30 + v45[2].m_real.m128_u64[0] + 12);
          if ( (_DWORD)v31 != -1 && ((*((_DWORD *)&v28->m_edgesToRemove->m_data + (v31 >> 5)) >> (v31 & 0x1F)) & 1) != 0 )
          {
            if ( v18 >= m_capacity )
            {
              v32 = 8;
              if ( m_capacity )
                v32 = 2 * m_capacity;
              hkQueue<int>::setCapacity((hkQueue<int> *)&v34, v32);
              v28 = partitioner;
              m_capacity = v34.m_capacity;
              v17 = v34.m_tail;
              v18 = v34.m_elementsInUse;
            }
            if ( v17 == m_capacity )
              v17 = 0;
            v33 = v17++;
            ++v18;
            *((_DWORD *)v34.m_data + v33) = v31;
            v34.m_elementsInUse = v18;
            v34.m_tail = v17;
          }
          LODWORD(v29) = v29 + 1;
          v30 += 20i64;
        }
        while ( (int)v29 < *v24 + *((__int16 *)v24 + 4) );
        m_head = v34.m_head;
        v8 = v45;
      }
      goto LABEL_36;
    }
LABEL_38:
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v34);
  }
}

// File Line: 886
// RVA: 0xB5D440
void __fastcall partitionFacesWC(
        hkSimdFloat32 *mesh,
        hkaiNavMesh *origMesh,
        Partitioner *partitioner,
        hkArray<int,hkContainerHeapAllocator> *numFacesInPartition,
        hkArray<int,hkContainerHeapAllocator> *partitionDir,
        hkArray<int,hkContainerHeapAllocator> *partitions)
{
  int v6; // ebx
  hkSimdFloat32 *v7; // r14
  int v8; // edi
  __int32 v9; // r10d
  unsigned int *v10; // rcx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  int v15; // eax
  unsigned int *m_data; // rdi
  __int64 i; // rcx
  __int32 v18; // r12d
  void *v19; // rsi
  int v20; // r13d
  int v21; // edi
  signed int v22; // ebx
  int k; // r15d
  int j; // r14d
  hkVector4f *v25; // rax
  int m_size; // eax
  int *v27; // r8
  __int64 v28; // rcx
  int v29; // edx
  hkResult result; // [rsp+40h] [rbp-79h] BYREF
  hkArray<int,hkContainerTempAllocator> newPartition; // [rsp+48h] [rbp-71h] BYREF
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > array; // [rsp+58h] [rbp-61h] BYREF
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > __that; // [rsp+70h] [rbp-49h] BYREF
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > v34; // [rsp+88h] [rbp-31h] BYREF
  hkVector4f parDir; // [rsp+A0h] [rbp-19h] BYREF
  hkVector4f v36; // [rsp+B0h] [rbp-9h] BYREF

  v6 = mesh[1].m_real.m128_i32[2];
  v7 = mesh;
  array.m_words.m_data = 0i64;
  array.m_words.m_size = 0;
  v8 = (v6 + 31) >> 5;
  array.m_words.m_capacityAndFlags = 0x80000000;
  v9 = v8;
  if ( v8 )
  {
    result.m_enum = 4 * v8;
    v10 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &result);
    v9 = result.m_enum / 4;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 0x80000000;
  array.m_words.m_data = v10;
  if ( v9 )
    v11 = v9;
  array.m_words.m_size = (v6 + 31) >> 5;
  array.m_numBits = v6;
  array.m_words.m_capacityAndFlags = v11;
  v12 = v11 & 0x3FFFFFFF;
  if ( v12 < v8 )
  {
    v13 = 2 * v12;
    v14 = (v6 + 31) >> 5;
    if ( v8 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v14, 4);
  }
  v15 = v8 - 1;
  array.m_words.m_size = (v6 + 31) >> 5;
  if ( v8 - 1 >= 0 )
  {
    m_data = array.m_words.m_data;
    for ( i = (unsigned int)(v15 + 1); i; --i )
      *m_data++ = -1;
  }
  v18 = 0x80000000;
  newPartition.m_data = 0i64;
  newPartition.m_size = 0;
  newPartition.m_capacityAndFlags = 0x80000000;
  v19 = 0i64;
  v20 = -1;
  v34.m_words.m_capacityAndFlags = 0x80000000;
  v34.m_words.m_data = 0i64;
  v34.m_words.m_size = 0;
  v34.m_numBits = 0;
  while ( 1 )
  {
    v21 = v7[1].m_real.m128_i32[2];
    v22 = 0;
    if ( v21 <= 0 )
      break;
    while ( ((array.m_words.m_data[(__int64)v22 >> 5] >> (v22 & 0x1F)) & 1) == 0 )
    {
      if ( ++v22 >= v21 )
        goto LABEL_18;
    }
    if ( v22 == -1 )
      break;
    k = 0;
    for ( j = 0; j < 6; ++j )
    {
      newPartition.m_size = 0;
      v25 = hkaiNavMeshSimplificationUtils::_classToDir(&v36, j);
      __that.m_words.m_data = 0i64;
      __that.m_words.m_size = 0;
      __that.m_words.m_capacityAndFlags = 0x80000000;
      parDir.m_quad = v25->m_quad;
      __that.m_numBits = 0;
      hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(&__that, &array);
      getOnePartitionWC(mesh, origMesh, partitioner, v22, &parDir, &newPartition, (hkBitField *)&__that);
      m_size = newPartition.m_size;
      if ( newPartition.m_size && newPartition.m_size > k )
      {
        if ( (v18 & 0x3FFFFFFF) < newPartition.m_size )
        {
          if ( v18 >= 0 )
          {
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v19, 4 * v18);
            m_size = newPartition.m_size;
          }
          result.m_enum = 4 * m_size;
          v19 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &result);
          m_size = newPartition.m_size;
          v18 = result.m_enum / 4;
        }
        v27 = newPartition.m_data;
        v28 = 0i64;
        for ( k = m_size; v28 < m_size; *((_DWORD *)v19 + v28 - 1) = v29 )
          v29 = v27[v28++];
        v20 = j;
        hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(&v34, &__that);
      }
      if ( __that.m_words.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          __that.m_words.m_data,
          4 * __that.m_words.m_capacityAndFlags);
    }
    if ( numFacesInPartition->m_size == (numFacesInPartition->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, numFacesInPartition, 4);
    numFacesInPartition->m_data[numFacesInPartition->m_size++] = k;
    if ( partitionDir->m_size == (partitionDir->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, partitionDir, 4);
    partitionDir->m_data[partitionDir->m_size++] = v20;
    hkArrayBase<unsigned int>::_append(
      (hkArrayBase<unsigned int> *)partitions,
      &hkContainerHeapAllocator::s_alloc,
      (const unsigned int *)v19,
      k);
    hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(&array, &v34);
    v7 = mesh;
  }
LABEL_18:
  if ( v34.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v34.m_words.m_data,
      4 * v34.m_words.m_capacityAndFlags);
  if ( v18 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v19, 4 * v18);
  newPartition.m_size = 0;
  if ( newPartition.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      newPartition.m_data,
      4 * newPartition.m_capacityAndFlags);
  newPartition.m_data = 0i64;
  newPartition.m_capacityAndFlags = 0x80000000;
  array.m_words.m_size = 0;
  if ( array.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_words.m_data,
      4 * array.m_words.m_capacityAndFlags);
}

// File Line: 991
// RVA: 0xB5BA50
hkResult *__fastcall hkaiNavMeshSimplificationUtils::partition(
        hkResult *result,
        hkaiNavMesh *mesh,
        hkaiNavMesh *origMesh,
        hkaiNavMeshGenerationSettings *settings,
        hkArray<int,hkContainerHeapAllocator> *numFacesInPartition,
        hkArray<int,hkContainerHeapAllocator> *partitions,
        hkArray<int,hkContainerHeapAllocator> *numEdgesInGroupInOut,
        hkArray<int,hkContainerHeapAllocator> *edgesToRemoveInOut)
{
  hkVector4f v12; // xmm1
  Partitioner partitioner; // [rsp+50h] [rbp-128h] BYREF

  memset(&partitioner, 0, 20);
  partitioner.m_settings = &settings->m_simplificationSettings;
  partitioner.m_boundary.m_map.m_hashMod = -1;
  partitioner.m_partition.m_elem.m_data = 0i64;
  partitioner.m_partition.m_elem.m_size = 0;
  partitioner.m_partition.m_elem.m_capacityAndFlags = 0x80000000;
  partitioner.m_partition.m_numElems = 0;
  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&partitioner.m_fitter);
  partitioner.m_points.m_data = 0i64;
  partitioner.m_points.m_size = 0;
  partitioner.m_points.m_capacityAndFlags = 0x80000000;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&partitioner.m_tree);
  v12.m_quad = (__m128)mesh->m_aabb.m_max;
  partitioner.m_aabb.m_min = mesh->m_aabb.m_min;
  partitioner.m_aabb.m_max = (hkVector4f)v12.m_quad;
  partitionFaces(
    result,
    mesh,
    origMesh,
    &settings->m_up,
    &partitioner,
    numFacesInPartition,
    partitions,
    numEdgesInGroupInOut,
    edgesToRemoveInOut);
  Partitioner::~Partitioner(&partitioner);
  return result;
}

// File Line: 997
// RVA: 0xB5BB90
void __fastcall hkaiNavMeshSimplificationUtils::partitionWC(
        hkaiNavMesh *mesh,
        hkaiNavMesh *origMesh,
        hkaiNavMeshGenerationSettings *settings,
        hkArray<int,hkContainerHeapAllocator> *numFacesInPartition,
        hkArray<int,hkContainerHeapAllocator> *partitionDir,
        hkArray<int,hkContainerHeapAllocator> *partitions)
{
  hkVector4f v9; // xmm1
  Partitioner partitioner; // [rsp+30h] [rbp-128h] BYREF

  memset(&partitioner, 0, 20);
  partitioner.m_boundary.m_map.m_hashMod = -1;
  partitioner.m_settings = &settings->m_simplificationSettings;
  partitioner.m_partition.m_elem.m_data = 0i64;
  partitioner.m_partition.m_elem.m_size = 0;
  partitioner.m_partition.m_elem.m_capacityAndFlags = 0x80000000;
  partitioner.m_partition.m_numElems = 0;
  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&partitioner.m_fitter);
  partitioner.m_points.m_data = 0i64;
  partitioner.m_points.m_size = 0;
  partitioner.m_points.m_capacityAndFlags = 0x80000000;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&partitioner.m_tree);
  v9.m_quad = (__m128)mesh->m_aabb.m_max;
  partitioner.m_aabb.m_min = mesh->m_aabb.m_min;
  partitioner.m_aabb.m_max = (hkVector4f)v9.m_quad;
  partitionFacesWC(mesh, origMesh, &partitioner, numFacesInPartition, partitionDir, partitions);
  Partitioner::~Partitioner(&partitioner);
}

