// File Line: 31
// RVA: 0xB5BC90
void __fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(hkaiNavMeshSimplificationUtils::PlaneFitter *this)
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
void __fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(hkaiNavMeshSimplificationUtils::PlaneFitter *this, hkVector4f *newPoint)
{
  hkaiNavMeshSimplificationUtils::PlaneFitter *v2; // rbx
  hkMatrix3f *v3; // rcx
  __m128 v4; // xmm2
  hkMatrix3f a; // [rsp+20h] [rbp-38h]

  v2 = this;
  v3 = &this->m_productSums;
  v3[-1].m_col2.m_quad = _mm_add_ps(newPoint->m_quad, v3[-1].m_col2.m_quad);
  v4 = newPoint->m_quad;
  a.m_col0.m_quad = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v4);
  a.m_col1.m_quad = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), v4);
  a.m_col2.m_quad = _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), v4);
  hkMatrix3f::add(v3, &a);
  ++v2->m_numPoints;
}

// File Line: 62
// RVA: 0xB5C140
hkSimdFloat32 *__fastcall calcCovarianceElem_2_2_(hkSimdFloat32 *result, hkVector4f *mean, hkVector4f *sum, hkMatrix3f *productSum, hkSimdFloat32 *np)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  hkSimdFloat32 *v7; // rax

  v5 = _mm_shuffle_ps(mean->m_quad, mean->m_quad, 170);
  v6 = _mm_shuffle_ps(sum->m_quad, sum->m_quad, 170);
  v7 = result;
  result->m_real = _mm_add_ps(
                     _mm_sub_ps(
                       _mm_sub_ps(
                         _mm_shuffle_ps(productSum->m_col2.m_quad, productSum->m_col2.m_quad, 170),
                         _mm_mul_ps(v6, v5)),
                       _mm_mul_ps(v6, v5)),
                     _mm_mul_ps(_mm_mul_ps(np->m_real, v5), v5));
  return v7;
}

// File Line: 74
// RVA: 0xB5BD60
void __fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::calcCovariance(hkaiNavMeshSimplificationUtils::PlaneFitter *this, hkMatrix3f *covariance, hkSimdFloat32 *invNumPointsOut)
{
  __m128 v3; // xmm13
  __m128 v4; // xmm13
  __m128 v5; // xmm1
  hkSimdFloat32 v6; // xmm12
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
  v6.m_real = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v5)), v5);
  *invNumPointsOut = (hkSimdFloat32)v6.m_real;
  v7.m_quad = (__m128)this->m_sum;
  v8.m_quad = (__m128)this->m_productSums.m_col1;
  v9 = _mm_mul_ps(v6.m_real, v7.m_quad);
  v10.m_quad = (__m128)this->m_productSums.m_col0;
  v11 = _mm_shuffle_ps(v9, v9, 85);
  v12 = _mm_shuffle_ps(this->m_sum.m_quad, v7.m_quad, 85);
  v13 = _mm_shuffle_ps(this->m_sum.m_quad, v7.m_quad, 170);
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
                                      _mm_sub_ps(
                                        _mm_shuffle_ps(
                                          this->m_productSums.m_col0.m_quad,
                                          this->m_productSums.m_col0.m_quad,
                                          0),
                                        _mm_mul_ps(v17, v15)),
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
hkResult *__fastcall hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(hkaiNavMeshSimplificationUtils::PlaneFitter *this, hkResult *result, hkVector4f *planeOut)
{
  hkVector4f *v3; // rbx
  hkResult *v4; // rsi
  hkaiNavMeshSimplificationUtils::PlaneFitter *v5; // rdi
  __m128 v6; // xmm3
  __m128 v7; // xmm3
  hkResult *v8; // rax
  __m128 v9; // xmm2
  hkSimdFloat32 invNumPointsOut; // [rsp+30h] [rbp-98h]
  hkVector4f eigenVal; // [rsp+40h] [rbp-88h]
  hkMatrix3f covariance; // [rsp+50h] [rbp-78h]
  hkRotationf eigenVec; // [rsp+80h] [rbp-48h]

  v3 = planeOut;
  v4 = result;
  v5 = this;
  if ( this->m_numPoints < 3 )
    *planeOut = 0i64;
  invNumPointsOut.m_real = 0i64;
  hkaiNavMeshSimplificationUtils::PlaneFitter::calcCovariance(this, &covariance, &invNumPointsOut);
  hkMatrix3f::diagonalizeSymmetric(&covariance, v4, &eigenVec, &eigenVal, 20, 0.00000011920929);
  v6 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&eigenVal), 1u), 1u);
  v7 = *(&eigenVec.m_col0.m_quad
       + (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                 _mm_and_ps(
                                                                   _mm_cmpleps(
                                                                     v6,
                                                                     _mm_min_ps(
                                                                       _mm_shuffle_ps(v6, v6, 170),
                                                                       _mm_min_ps(
                                                                         _mm_shuffle_ps(v6, v6, 85),
                                                                         _mm_shuffle_ps(v6, v6, 0)))),
                                                                   (__m128)xmmword_141A4CC80))]);
  v8 = v4;
  *v3 = (hkVector4f)v7;
  v9 = _mm_mul_ps(_mm_mul_ps(v5->m_sum.m_quad, invNumPointsOut.m_real), v7);
  v3->m_quad = _mm_shuffle_ps(
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
signed __int64 __fastcall Partitioner::BoundaryIntersectionQuery::processLeaf(Partitioner::BoundaryIntersectionQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkArray<int,hkContainerTempAllocator> *v3; // rax
  unsigned int v4; // ebx
  Partitioner::BoundaryIntersectionQuery *v5; // r10
  __int64 v6; // r9
  int v7; // ecx
  __int64 v8; // r8
  int *v9; // rax
  hkaiNavMesh *v10; // r9
  __int64 v11; // r8
  signed __int64 v12; // rax
  hkVector4f *v13; // rcx
  hkaiNavMesh::Edge *v14; // r11
  signed __int64 v15; // rdi
  __int64 v16; // r14
  signed __int64 v17; // rax
  __int64 v18; // rdx
  signed __int64 v19; // rsi
  __int64 v20; // r15
  __int64 v21; // r9
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
  __m128 v52; // xmm0
  __m128 v53; // xmm2
  __m128 v54; // xmm8
  __m128 v55; // xmm7
  __m128 v56; // xmm0
  __m128 v57; // xmm3
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm11
  __m128 v61; // xmm1
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
  unsigned __int64 v74; // [rsp+100h] [rbp+67h]

  v3 = this->m_temporarilyRemovedFromBoundary;
  v4 = 0;
  v5 = this;
  v6 = v3->m_size;
  v7 = 0;
  v8 = 0i64;
  if ( v6 > 0 )
  {
    v9 = v3->m_data;
    while ( *v9 != leafKey )
    {
      ++v8;
      ++v7;
      ++v9;
      if ( v8 >= v6 )
        goto LABEL_5;
    }
    if ( v7 != -1 )
      return 1i64;
  }
LABEL_5:
  v10 = v5->m_mesh;
  v11 = v5->m_compX;
  v12 = v5->m_edgeIdx;
  v13 = v10->m_vertices.m_data;
  v14 = v10->m_edges.m_data;
  v15 = v12;
  v16 = v14[v12].m_a;
  v17 = (signed int)leafKey;
  v18 = v5->m_compY;
  v19 = v17;
  v20 = v14[v17].m_a;
  v21 = v14[v17].m_b;
  v22 = v14[v15].m_b;
  v72.m_quad = (__m128)v13[v16];
  v23 = v72.m_quad.m128_f32[v11];
  v24 = v72.m_quad.m128_f32[v18];
  *(float *)&v74 = v72.m_quad.m128_f32[v11];
  HIDWORD(v74) = LODWORD(v72.m_quad.m128_f32[v18]);
  v71.m_quad = (__m128)v13[v22];
  v25 = v71.m_quad.m128_f32[v11];
  v26 = v71.m_quad.m128_f32[v18];
  v72.m_quad = (__m128)v13[v20];
  v27 = v72.m_quad.m128_f32[v11];
  v28 = v72.m_quad.m128_f32[v18];
  v73.m_quad = (__m128)v13[v21];
  v29 = v73.m_quad.m128_f32[v11];
  v30 = v73.m_quad.m128_f32[v18];
  v72.m_quad.m128_i32[0] = v73.m_quad.m128_i32[v11];
  v72.m_quad.m128_f32[1] = v30;
  v71.m_quad.m128_u64[0] = __PAIR__(LODWORD(v28), LODWORD(v27));
  if ( (_DWORD)v20 == (_DWORD)v16
    || (_DWORD)v21 == (_DWORD)v16
    || (_DWORD)v20 == v14[v15].m_b
    || (_DWORD)v21 == v14[v15].m_b )
  {
    v65 = 1;
    if ( (_DWORD)v16 != (_DWORD)v20
      || (float)((float)((float)(v30 - v28) * (float)(v26 - v28)) + (float)((float)(v29 - v27) * (float)(v25 - v27))) <= 0.0
      || (v66 = 1,
          fminf(
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)((float)(v29 - v27) * (float)(v26 - v28))
                                                - (float)((float)(v30 - v28) * (float)(v25 - v27)))
                                        / fsqrt(
                                            (float)((float)(v28 - v30) * (float)(v28 - v30))
                                          + (float)((float)(v27 - v29) * (float)(v27 - v29))))) >> 1),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)((float)(v30 - v28) * (float)(v25 - v27))
                                                - (float)((float)(v29 - v27) * (float)(v26 - v28)))
                                        / fsqrt(
                                            (float)((float)(v28 - v26) * (float)(v28 - v26))
                                          + (float)((float)(v27 - v25) * (float)(v27 - v25))))) >> 1)) > 0.001) )
    {
      v66 = 0;
    }
    v5->m_intersects |= v66;
    if ( v14[v15].m_b != v14[v19].m_b
      || (float)((float)((float)(v28 - v30) * (float)(v24 - v30)) + (float)((float)(v27 - v29) * (float)(v23 - v29))) <= 0.0
      || (v67 = 1,
          fminf(
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)((float)(v24 - v30) * (float)(v27 - v29))
                                                - (float)((float)(v23 - v29) * (float)(v28 - v30)))
                                        / fsqrt(
                                            (float)((float)(v30 - v28) * (float)(v30 - v28))
                                          + (float)((float)(v29 - v27) * (float)(v29 - v27))))) >> 1),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)((float)(v23 - v29) * (float)(v28 - v30))
                                                - (float)((float)(v24 - v30) * (float)(v27 - v29)))
                                        / fsqrt(
                                            (float)((float)(v30 - v24) * (float)(v30 - v24))
                                          + (float)((float)(v29 - v23) * (float)(v29 - v23))))) >> 1)) > 0.001) )
    {
      v67 = 0;
    }
    v68 = v67 | v5->m_intersects;
    v5->m_intersects = v68;
    if ( v14[v15].m_a != v14[v19].m_b
      || (float)((float)((float)(v28 - v30) * (float)(v26 - v30)) + (float)((float)(v27 - v29) * (float)(v25 - v29))) <= 0.0
      || (v69 = 1,
          fminf(
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)((float)(v26 - v30) * (float)(v27 - v29))
                                                - (float)((float)(v25 - v29) * (float)(v28 - v30)))
                                        / fsqrt(
                                            (float)((float)(v30 - v28) * (float)(v30 - v28))
                                          + (float)((float)(v29 - v27) * (float)(v29 - v27))))) >> 1),
            COERCE_FLOAT((unsigned int)(2
                                      * COERCE_SIGNED_INT(
                                          (float)((float)((float)(v25 - v29) * (float)(v28 - v30))
                                                - (float)((float)(v26 - v30) * (float)(v27 - v29)))
                                        / fsqrt(
                                            (float)((float)(v30 - v26) * (float)(v30 - v26))
                                          + (float)((float)(v29 - v25) * (float)(v29 - v25))))) >> 1)) > 0.001) )
    {
      v69 = 0;
    }
    v70 = v69 | v68;
    v5->m_intersects = v70;
    if ( v14[v15].m_b != v14[v19].m_a
      || (float)((float)((float)(v30 - v28) * (float)(v24 - v28)) + (float)((float)(v29 - v27) * (float)(v23 - v27))) <= 0.0
      || fminf(
           COERCE_FLOAT((unsigned int)(2
                                     * COERCE_SIGNED_INT(
                                         (float)((float)((float)(v24 - v28) * (float)(v29 - v27))
                                               - (float)((float)(v23 - v27) * (float)(v30 - v28)))
                                       / fsqrt(
                                           (float)((float)(v28 - v30) * (float)(v28 - v30))
                                         + (float)((float)(v27 - v29) * (float)(v27 - v29))))) >> 1),
           COERCE_FLOAT((unsigned int)(2
                                     * COERCE_SIGNED_INT(
                                         (float)((float)((float)(v23 - v27) * (float)(v30 - v28))
                                               - (float)((float)(v24 - v28) * (float)(v29 - v27)))
                                       / fsqrt(
                                           (float)((float)(v28 - v24) * (float)(v28 - v24))
                                         + (float)((float)(v27 - v23) * (float)(v27 - v23))))) >> 1)) > 0.001 )
    {
      v65 = 0;
    }
    v5->m_intersects = v65 | v70;
  }
  else
  {
    v31 = _mm_shuffle_ps((__m128)v74, _mm_unpackhi_ps((__m128)v74, (__m128)0i64), 180);
    v32 = _mm_shuffle_ps(
            (__m128)v71.m_quad.m128_u64[0],
            _mm_unpackhi_ps((__m128)v71.m_quad.m128_u64[0], (__m128)0i64),
            180);
    v33 = _mm_sub_ps(
            _mm_shuffle_ps(
              (__m128)__PAIR__(LODWORD(v26), LODWORD(v25)),
              _mm_unpackhi_ps((__m128)__PAIR__(LODWORD(v26), LODWORD(v25)), (__m128)0i64),
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
    v52 = _mm_mul_ps(v51, v43);
    v53 = _mm_cmpleps(v46, *(__m128 *)&epsilon);
    v54 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v52), v51);
    v55 = _mm_sub_ps(_mm_mul_ps(v45, v40), _mm_mul_ps(v41, v37));
    v56 = _mm_cmpltps(v55, v46);
    v57 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  v53,
                  _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v56, v46), _mm_and_ps(v56, v55))), v48)),
                _mm_and_ps(v53, query.m_quad)),
              _mm_mul_ps(v37, v50)),
            _mm_mul_ps(v41, v50));
    v58 = _mm_cmpltps(v57, query.m_quad);
    v59 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v58, query.m_quad), _mm_and_ps(v58, v57)));
    v60 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v37, v54), v59), _mm_mul_ps(v40, v54));
    v61 = _mm_cmpltps(v60, query.m_quad);
    v62 = _mm_sub_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v61, query.m_quad), _mm_and_ps(v61, v60))),
                v33),
              v31),
            _mm_add_ps(_mm_mul_ps(v59, v35), v32));
    v63 = _mm_mul_ps(v62, v62);
    v5->m_intersects |= (float)(0.001 * 0.001) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85))
                                                               + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                                                       + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170)));
  }
  LOBYTE(v4) = v5->m_intersects == 0;
  return v4;
}

// File Line: 253
// RVA: 0xB5D860
void __fastcall Partitioner::~Partitioner(Partitioner *this)
{
  Partitioner *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  hkcdDynamicAabbTree::~hkcdDynamicAabbTree(&this->m_tree);
  v2 = v1->m_points.m_capacityAndFlags;
  v1->m_points.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_points.m_data,
      16 * v2);
  v1->m_points.m_data = 0i64;
  v1->m_points.m_capacityAndFlags = 2147483648;
  v1->m_fitter.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v3 = v1->m_partition.m_elem.m_capacityAndFlags;
  v1->m_partition.m_elem.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_partition.m_elem.m_data,
      4 * v3);
  v1->m_partition.m_elem.m_data = 0i64;
  v1->m_partition.m_elem.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_boundary.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_boundary);
}

// File Line: 274
// RVA: 0xB5D9F0
hkResult *__fastcall Partitioner::addEdgeToBoundary(Partitioner *this, hkResult *result, hkaiNavMesh *mesh, int edgeIndex)
{
  hkaiNavMesh::Edge *v4; // rax
  hkVector4f *v5; // r8
  unsigned __int64 v6; // rbx
  hkResult *v7; // rdi
  Partitioner *v8; // rbp
  hkaiNavMesh::Edge *v9; // r11
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  unsigned int v12; // eax
  hkResult *v13; // rax
  hkAabb aabb; // [rsp+30h] [rbp-38h]
  hkResult v15; // [rsp+70h] [rbp+8h]
  hkResult res; // [rsp+88h] [rbp+20h]

  v4 = mesh->m_edges.m_data;
  v5 = mesh->m_vertices.m_data;
  v6 = edgeIndex;
  v7 = result;
  v8 = this;
  v9 = &v4[edgeIndex];
  v10 = v5[v9->m_a].m_quad;
  v11 = v5[v9->m_b].m_quad;
  aabb.m_min.m_quad = _mm_min_ps(v5[v9->m_a].m_quad, v11);
  aabb.m_max.m_quad = _mm_max_ps(v10, v11);
  v12 = hkcdDynamicAabbTree::tryInsert(&this->m_tree, &aabb, edgeIndex, &res);
  if ( res.m_enum
    || (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_boundary.m_map.m_elem,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v6,
          v12,
          &v15),
        v15.m_enum) )
  {
    v7->m_enum = 1;
    v13 = v7;
  }
  else
  {
    v7->m_enum = 0;
    v13 = v7;
  }
  return v13;
}

// File Line: 307
// RVA: 0xB5DAC0
char __fastcall Partitioner::canInclude(Partitioner *this, hkaiNavMesh *mesh, hkaiNavMesh *origMesh, int faceIdx, int majorAxis, hkResult *resOut)
{
  hkResult *v6; // r12
  hkaiNavMesh *v7; // r10
  Partitioner *v8; // rbx
  int v9; // ecx
  hkaiNavMesh *v10; // r13
  hkaiNavMeshSimplificationUtils::Settings *v12; // rax
  int v13; // edi
  hkaiNavMesh::Face *v14; // r15
  __m128i v15; // xmm0
  hkVector4f v16; // xmm1
  int v17; // er14
  signed int v18; // esi
  __m128 v19; // xmm7
  __m128 v20; // xmm10
  hkVector4f v21; // xmm0
  hkArray<int,hkContainerHeapAllocator> *v22; // rax
  int v23; // er9
  int v24; // edx
  __int64 v25; // rcx
  __int64 v26; // r8
  int *v27; // rax
  __m128 v28; // xmm6
  int v29; // er9
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
  __m128i v47; // xmm4
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
  __m128 *v58; // rax
  __m128 v59; // xmm3
  __m128 v60; // xmm4
  __m128 v61; // xmm0
  __m128 v62; // xmm3
  __m128 v63; // xmm0
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm4
  __m128 v67; // xmm0
  __m128 v68; // xmm2
  __m128 v69; // xmm11
  __m128 v70; // xmm12
  __m128 v71; // xmm1
  __m128 v72; // xmm7
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  char v75; // al
  __m128 v76; // xmm3
  int v77; // eax
  int v78; // eax
  int v79; // er9
  int v80; // eax
  int v81; // eax
  int v82; // er9
  int v83; // er9
  hkResultEnum v84; // eax
  char v85; // bl
  int v86; // er9
  int v87; // er11
  hkResultEnum v88; // eax
  signed int v89; // er12
  float v90; // xmm4_4
  hkArray<int,hkContainerHeapAllocator> *v91; // rax
  int v92; // er10
  int v93; // edx
  __int64 v94; // rcx
  __int64 v95; // r8
  int *v96; // rax
  hkaiNavMesh::Edge *v97; // r9
  hkaiNavMeshSimplificationUtils::Settings *v98; // rax
  __m128 v99; // xmm2
  hkVector4f *v100; // rcx
  __m128 v101; // xmm1
  __m128 v102; // xmm1
  __m128 v103; // xmm3
  __m128 v104; // xmm1
  __m128 v105; // xmm1
  __m128 v106; // xmm2
  unsigned int v107; // esi
  int v108; // er8
  int *v109; // r14
  int v110; // ecx
  int v111; // edx
  int v112; // eax
  __int64 v113; // rdx
  __m128 v114; // xmm6
  hkcdDynamicAabbTree *v115; // r10
  int v116; // esi
  __int64 v117; // r14
  hkVector4f *v118; // rdx
  hkaiNavMesh::Edge *v119; // rcx
  __int64 v120; // r9
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  int v123; // eax
  _DWORD *v124; // [rsp+30h] [rbp-D0h]
  int v125; // [rsp+38h] [rbp-C8h]
  int v126; // [rsp+3Ch] [rbp-C4h]
  _DWORD *array; // [rsp+40h] [rbp-C0h]
  int v128; // [rsp+48h] [rbp-B8h]
  int v129; // [rsp+4Ch] [rbp-B4h]
  hkVector4f newPoint; // [rsp+50h] [rbp-B0h]
  __m128 v131; // [rsp+60h] [rbp-A0h]
  __m128 v132; // [rsp+70h] [rbp-90h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+80h] [rbp-80h]
  hkcdDynamicAabbTree *v134; // [rsp+88h] [rbp-78h]
  hkaiNavMesh *v135; // [rsp+90h] [rbp-70h]
  BOOL v136; // [rsp+98h] [rbp-68h]
  int v137; // [rsp+9Ch] [rbp-64h]
  void **v138; // [rsp+A0h] [rbp-60h]
  int v139; // [rsp+A8h] [rbp-58h]
  char v140; // [rsp+ACh] [rbp-54h]
  hkaiNavMeshSimplificationUtils::PlaneFitter v141; // [rsp+B0h] [rbp-50h]
  hkaiNavMesh *v142; // [rsp+1C0h] [rbp+C0h]

  v142 = origMesh;
  v6 = resOut;
  v7 = origMesh;
  v8 = this;
  resOut->m_enum = 0;
  v9 = this->m_partition.m_numElems;
  v10 = mesh;
  if ( !v9 )
    return 1;
  v12 = v8->m_settings;
  if ( v9 >= v12->m_maxPartitionSize )
    return 0;
  v13 = majorAxis;
  v14 = &mesh->m_faces.m_data[faceIdx];
  if ( !v12->m_useHeightPartitioning.m_bool || !v12->m_useConservativeHeightPartitioning.m_bool )
    goto LABEL_45;
  v15 = (__m128i)v8->m_fitter.m_sum;
  v16.m_quad = (__m128)v8->m_fitter.m_productSums.m_col1;
  v17 = v8->m_points.m_size;
  *(_DWORD *)&v141.m_memSizeAndFlags = 0x1FFFF;
  v18 = 0;
  v19 = v8->m_minHeight.m_real;
  v20 = v8->m_maxHeight.m_real;
  _mm_store_si128((__m128i *)&v141.m_sum, v15);
  v141.vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshSimplificationUtils::PlaneFitter::`vftable;
  v141.m_numPoints = v8->m_fitter.m_numPoints;
  v21.m_quad = (__m128)v8->m_fitter.m_productSums.m_col0;
  v141.m_productSums.m_col1 = (hkVector4f)v16.m_quad;
  v141.m_productSums.m_col0 = (hkVector4f)v21.m_quad;
  v141.m_productSums.m_col2 = v8->m_fitter.m_productSums.m_col2;
  if ( v14->m_numEdges > 0 )
  {
    do
    {
      v22 = v8->m_edgesToRemove;
      v23 = v18 + v14->m_startEdgeIndex;
      if ( !v8->m_edgesToRemove )
        goto LABEL_15;
      v24 = 0;
      v25 = 0i64;
      v26 = v22->m_size;
      if ( v26 <= 0 )
        goto LABEL_15;
      v27 = v22->m_data;
      while ( *v27 != v23 )
      {
        ++v25;
        ++v24;
        ++v27;
        if ( v25 >= v26 )
          goto LABEL_15;
      }
      if ( v24 == -1 )
      {
LABEL_15:
        v28 = v7->m_vertices.m_data[v10->m_edges.m_data[v23].m_a].m_quad;
        newPoint.m_quad = (__m128)v7->m_vertices.m_data[v10->m_edges.m_data[v23].m_a];
        hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&v141, &newPoint);
        v29 = v8->m_points.m_size + 1;
        v30 = v8->m_points.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v30 >= v29 )
        {
          v32 = 0;
          LODWORD(resOut) = 0;
        }
        else
        {
          v31 = 2 * v30;
          if ( v29 < v31 )
            v29 = v31;
          hkArrayUtil::_reserve(
            (hkResult *)&resOut,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v8->m_points,
            v29,
            16);
          v32 = (signed int)resOut;
        }
        v6->m_enum = v32;
        if ( v32 )
          return 0;
        v7 = v142;
        v8->m_points.m_data[v8->m_points.m_size++].m_quad = v28;
        v13 = majorAxis;
        v33 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[majorAxis], v28);
        v34 = _mm_or_ps(_mm_shuffle_ps(v33, v33, 78), v33);
        v35 = _mm_or_ps(_mm_shuffle_ps(v34, v34, 177), v34);
        v19 = _mm_min_ps(v19, v35);
        v20 = _mm_max_ps(v20, v35);
      }
      ++v18;
    }
    while ( v18 < v14->m_numEdges );
  }
  v36 = v20.m128_f32[0] - v19.m128_f32[0];
  if ( v36 <= v8->m_settings->m_maxPartitionHeightError )
    goto LABEL_94;
  hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&v141, (hkResult *)&resOut, &newPoint);
  v37 = _mm_mul_ps(newPoint.m_quad, newPoint.m_quad);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  v40 = (__m128i)_mm_mul_ps(
                   newPoint.m_quad,
                   _mm_andnot_ps(
                     _mm_cmpleps(v38, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                       _mm_mul_ps(*(__m128 *)_xmm, v39))));
  v41 = _mm_shuffle_ps((__m128)v40, _mm_unpackhi_ps((__m128)v40, (__m128)0i64), 196);
  v42 = _mm_shuffle_ps(v41, v41, 241);
  v43 = _mm_shuffle_ps(v41, v41, 206);
  v44 = _mm_mul_ps(v43, v43);
  v45 = _mm_mul_ps(v42, v42);
  v46 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
            _mm_shuffle_ps(v45, v45, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
            _mm_shuffle_ps(v44, v44, 170)));
  v47 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v48 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v46, v43), _mm_andnot_ps(v46, v42)), (__m128)v47);
  v49 = _mm_mul_ps(v48, v48);
  v50 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)), _mm_shuffle_ps(v49, v49, 170));
  v51 = _mm_rsqrt_ps(v50);
  v52 = v8->m_points.m_size;
  v53 = (__m128)xmmword_141A712A0;
  v54 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v47, 0), (__m128)xmmword_141A712A0);
  v55 = (__m128i)_mm_mul_ps(
                   v48,
                   _mm_andnot_ps(
                     _mm_cmpleps(v50, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                       _mm_mul_ps(*(__m128 *)_xmm, v51))));
  v56 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)v55, (__m128)v55, 201), (__m128)v40),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v40, (__m128)v40, 201), (__m128)v55));
  v57 = (__m128i)_mm_shuffle_ps(v56, v56, 201);
  if ( v52 > 0 )
  {
    v58 = &v8->m_points.m_data->m_quad;
    do
    {
      v59 = *v58;
      ++v58;
      v60 = v59;
      v61 = v59;
      v62 = _mm_mul_ps(v59, (__m128)v57);
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
  v69 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v40, 1u), 1u);
  v70 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v55, 1u), 1u);
  v71 = _mm_unpacklo_ps(v69, v70);
  v72 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v57, 1u), 1u);
  newPoint.m_quad = _mm_movelh_ps(v71, v72);
  v132 = _mm_shuffle_ps(_mm_unpackhi_ps(v69, v70), v72, 228);
  v131 = _mm_shuffle_ps(_mm_movehl_ps(newPoint.m_quad, v71), v72, 212);
  v73 = *(&newPoint.m_quad + v13);
  v74 = _mm_rcp_ps(v73);
  v75 = _mm_movemask_ps(_mm_cmpltps((__m128)_xmm, v73));
  v76 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v73, v74)), v74), _mm_sub_ps(v54, v53));
  if ( v75 & 1 )
    v36 = fmin(v36, COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 0)));
  if ( v75 & 2 )
    v36 = fmin(v36, COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 85)));
  if ( v75 & 4 )
    v36 = fmin(v36, COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 170)));
  if ( v36 <= v8->m_settings->m_maxPartitionHeightError )
  {
LABEL_94:
    v80 = v8->m_points.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v80 < v17 )
    {
      v81 = 2 * v80;
      v82 = v17;
      if ( v17 < v81 )
        v82 = v81;
      hkArrayUtil::_reserve(
        (hkResult *)&resOut,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v8->m_points,
        v82,
        16);
    }
    v8->m_points.m_size = v17;
LABEL_45:
    array = 0i64;
    v128 = 0;
    v129 = 2147483648;
    v83 = v14->m_numEdges;
    if ( v83 <= 0 )
    {
      v84 = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        (hkResult *)&resOut,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &array,
        v83,
        4);
      v84 = (signed int)resOut;
    }
    v6->m_enum = v84;
    if ( v84 )
    {
      v85 = 0;
    }
    else
    {
      v124 = 0i64;
      v125 = 0;
      v126 = 2147483648;
      v86 = v14->m_numEdges;
      v87 = 0;
      if ( v86 <= 0 )
      {
        v88 = 0;
      }
      else
      {
        hkArrayUtil::_reserve(
          (hkResult *)&resOut,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          &v124,
          v86,
          4);
        v87 = v125;
        v88 = (signed int)resOut;
      }
      v6->m_enum = v88;
      if ( v88 )
      {
LABEL_85:
        v85 = 0;
      }
      else
      {
        v89 = 0;
        LODWORD(v90) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)LODWORD(v8->m_settings->m_maxPartitionHeightError),
                                            (__m128)LODWORD(v8->m_settings->m_maxPartitionHeightError),
                                            0);
        if ( v14->m_numEdges > 0 )
        {
          do
          {
            v91 = v8->m_edgesToRemove;
            v92 = v89 + v14->m_startEdgeIndex;
            if ( !v8->m_edgesToRemove )
              goto LABEL_62;
            v93 = 0;
            v94 = 0i64;
            v95 = v91->m_size;
            if ( v95 <= 0 )
              goto LABEL_62;
            v96 = v91->m_data;
            while ( *v96 != v92 )
            {
              ++v94;
              ++v93;
              ++v96;
              if ( v94 >= v95 )
                goto LABEL_62;
            }
            if ( v93 == -1 )
            {
LABEL_62:
              v97 = v10->m_edges.m_data;
              v98 = v8->m_settings;
              if ( v98->m_useHeightPartitioning.m_bool )
              {
                if ( !v98->m_useConservativeHeightPartitioning.m_bool )
                {
                  v99 = v8->m_plane.m_quad;
                  v100 = v10->m_vertices.m_data;
                  v101 = _mm_mul_ps(v100[v97[v92].m_a].m_quad, v99);
                  v102 = _mm_shuffle_ps(v101, _mm_unpackhi_ps(v101, v99), 196);
                  v103 = _mm_add_ps(_mm_shuffle_ps(v102, v102, 78), v102);
                  v104 = _mm_mul_ps(v100[v97[v92].m_b].m_quad, v99);
                  v105 = _mm_shuffle_ps(v104, _mm_unpackhi_ps(v104, v99), 196);
                  v106 = _mm_add_ps(_mm_shuffle_ps(v105, v105, 78), v105);
                  if ( COERCE_FLOAT((unsigned int)(2
                                                 * COERCE_SIGNED_INT(COERCE_FLOAT(_mm_shuffle_ps(v103, v103, 177)) + v103.m128_f32[0])) >> 1) > v90
                    || COERCE_FLOAT((unsigned int)(2
                                                 * COERCE_SIGNED_INT(COERCE_FLOAT(_mm_shuffle_ps(v106, v106, 177)) + v106.m128_f32[0])) >> 1) > v90 )
                  {
                    goto LABEL_85;
                  }
                }
              }
              v107 = v97[v92].m_oppositeFace;
              v108 = v8->m_partition.m_elem.m_size - 1;
              if ( v108 <= 0
                || (v109 = v8->m_partition.m_elem.m_data, v110 = v108 & -1640531535 * v107,
                                                          v111 = v109[v110],
                                                          v111 == -1) )
              {
LABEL_70:
                v112 = v8->m_partition.m_elem.m_size;
              }
              else
              {
                while ( v111 != v107 )
                {
                  v110 = v108 & (v110 + 1);
                  v111 = v109[v110];
                  if ( v111 == -1 )
                    goto LABEL_70;
                }
                v112 = v110;
              }
              if ( v112 > v108 )
              {
                v124[v87] = v92;
                v87 = v125++ + 1;
              }
              else
              {
                v113 = (signed int)v97[v92].m_oppositeEdge;
                if ( v97[v92].m_a != v97[v113].m_b || v97[v92].m_b != v97[v113].m_a )
                  goto LABEL_85;
                array[v128++] = v113;
                v87 = v125;
              }
            }
            ++v89;
          }
          while ( v89 < v14->m_numEdges );
        }
        collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&Partitioner::BoundaryIntersectionQuery::`vftable;
        v114 = _mm_shuffle_ps(
                 (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
                 (__m128)LODWORD(hkaiNavMeshSimplificationUtils::s_triangulatorEpsilon),
                 0);
        v138 = (void **)&array;
        v136 = majorAxis == 0;
        v115 = &v8->m_tree;
        v135 = v10;
        v139 = -1;
        v116 = 0;
        v137 = (majorAxis != 2) + 1;
        v134 = &v8->m_tree;
        if ( v87 <= 0 )
        {
LABEL_84:
          v85 = 1;
          collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
        }
        else
        {
          v117 = 0i64;
          while ( 1 )
          {
            v118 = v10->m_vertices.m_data;
            v119 = v10->m_edges.m_data;
            v120 = (signed int)v124[v117];
            v121 = _mm_min_ps(v118[v119[v120].m_a].m_quad, v118[v119[v120].m_b].m_quad);
            v122 = _mm_max_ps(v118[v119[v120].m_a].m_quad, v118[v119[v120].m_b].m_quad);
            v123 = v8->m_aabb.m_max.m_quad.m128_i32[majorAxis];
            v139 = v124[v117];
            v140 = 0;
            v131 = _mm_add_ps(v122, v114);
            newPoint.m_quad = _mm_sub_ps(v121, v114);
            v131.m128_i32[majorAxis] = v123;
            newPoint.m_quad.m128_i32[majorAxis] = v8->m_aabb.m_min.m_quad.m128_i32[majorAxis];
            hkcdDynamicAabbTree::queryAabb(v115, (hkAabb *)&newPoint, &collector);
            if ( v140 )
              break;
            ++v116;
            ++v117;
            if ( v116 >= v125 )
              goto LABEL_84;
            v115 = v134;
          }
          v85 = 0;
          collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
        }
      }
      v125 = 0;
      if ( v126 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v124,
          4 * v126);
      v126 = 2147483648;
      v124 = 0i64;
    }
    v128 = 0;
    if ( v129 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        4 * v129);
    return v85;
  }
  v77 = v8->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v77 < v17 )
  {
    v78 = 2 * v77;
    v79 = v17;
    if ( v17 < v78 )
      v79 = v78;
    hkArrayUtil::_reserve(
      (hkResult *)&resOut,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_points,
      v79,
      16);
  }
  v8->m_points.m_size = v17;
  return 0;
}

// File Line: 531
// RVA: 0xB5E510
hkResult *__fastcall Partitioner::include(Partitioner *this, hkResult *result, hkaiNavMesh *mesh, hkaiNavMesh *origMesh, int faceIdx, int majorAxis)
{
  int v6; // ebx
  hkaiNavMesh *v7; // r14
  hkResult *v8; // r13
  Partitioner *v9; // rsi
  hkaiNavMesh::Face *v10; // r12
  int v11; // er15
  hkArray<int,hkContainerHeapAllocator> *v12; // rax
  int v13; // ebx
  int v14; // edx
  __int64 v15; // rcx
  __int64 v16; // r8
  int *v17; // rax
  hkaiNavMesh::Edge *v18; // rdi
  hkaiNavMeshSimplificationUtils::Settings *v19; // rax
  hkVector4f *v20; // rax
  int v21; // er9
  __m128 v22; // xmm6
  int v23; // eax
  int v24; // eax
  __int64 v25; // rax
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  bool v30; // zf
  signed int v31; // er9
  int v32; // er8
  int *v33; // r10
  int v34; // eax
  int v35; // edx
  int v36; // ecx
  unsigned __int64 v37; // rbx
  unsigned int v38; // eax
  hkaiNavMeshSimplificationUtils::Settings *v39; // rax
  int v40; // er8
  int v41; // er8
  int *v42; // r10
  int v43; // er9
  signed int v44; // er8
  int v45; // ecx
  int v46; // edx
  hkResult v48; // [rsp+30h] [rbp-68h]
  hkResult v49; // [rsp+34h] [rbp-64h]
  hkResult v50; // [rsp+38h] [rbp-60h]
  hkVector4f newPoint; // [rsp+40h] [rbp-58h]
  hkResult resulta; // [rsp+B0h] [rbp+18h]
  hkaiNavMesh *v53; // [rsp+B8h] [rbp+20h]

  v53 = origMesh;
  v6 = faceIdx;
  v7 = mesh;
  v8 = result;
  v9 = this;
  v10 = &mesh->m_faces.m_data[faceIdx];
  v11 = 0;
  if ( v10->m_numEdges > 0 )
  {
    while ( 1 )
    {
      v12 = v9->m_edgesToRemove;
      v13 = v11 + v10->m_startEdgeIndex;
      if ( v9->m_edgesToRemove )
      {
        v14 = 0;
        v15 = 0i64;
        v16 = v12->m_size;
        if ( v16 > 0 )
        {
          v17 = v12->m_data;
          while ( *v17 != v13 )
          {
            ++v15;
            ++v14;
            ++v17;
            if ( v15 >= v16 )
              goto LABEL_9;
          }
          if ( v14 != -1 )
            goto LABEL_33;
        }
      }
LABEL_9:
      v18 = &v7->m_edges.m_data[v13];
      v19 = v9->m_settings;
      if ( v19->m_useHeightPartitioning.m_bool )
      {
        if ( v19->m_useConservativeHeightPartitioning.m_bool )
        {
          v20 = origMesh->m_vertices.m_data;
          v21 = v9->m_points.m_size + 1;
          v22 = v20[v18->m_a].m_quad;
          LODWORD(v20) = v9->m_points.m_capacityAndFlags;
          newPoint.m_quad = v22;
          v23 = (unsigned int)v20 & 0x3FFFFFFF;
          if ( v23 >= v21 )
          {
            resulta.m_enum = 0;
          }
          else
          {
            v24 = 2 * v23;
            if ( v21 < v24 )
              v21 = v24;
            hkArrayUtil::_reserve(
              &resulta,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v9->m_points,
              v21,
              16);
            if ( resulta.m_enum )
              goto LABEL_35;
          }
          v9->m_points.m_data[v9->m_points.m_size++].m_quad = v22;
          v25 = majorAxis;
          v26 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[majorAxis], v22);
          v27 = _mm_or_ps(_mm_shuffle_ps(v26, v26, 78), v26);
          v9->m_minHeight.m_real = _mm_min_ps(v9->m_minHeight.m_real, _mm_or_ps(_mm_shuffle_ps(v27, v27, 177), v27));
          v28 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v25], v22);
          v29 = _mm_or_ps(_mm_shuffle_ps(v28, v28, 78), v28);
          v9->m_maxHeight.m_real = _mm_max_ps(v9->m_maxHeight.m_real, _mm_or_ps(_mm_shuffle_ps(v29, v29, 177), v29));
        }
        else
        {
          newPoint.m_quad = (__m128)v7->m_vertices.m_data[v18->m_a];
        }
        hkaiNavMeshSimplificationUtils::PlaneFitter::addPoint(&v9->m_fitter, &newPoint);
      }
      if ( !v9->m_partition.m_numElems )
        break;
      v31 = v18->m_oppositeFace;
      v32 = v9->m_partition.m_elem.m_size - 1;
      if ( v32 <= 0 || (v33 = v9->m_partition.m_elem.m_data, v34 = v32 & -1640531535 * v31, v35 = v33[v34], v35 == -1) )
      {
LABEL_26:
        v36 = v9->m_partition.m_elem.m_size;
      }
      else
      {
        while ( v35 != v31 )
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
        Partitioner::addEdgeToBoundary(v9, &v49, v7, v13);
        v30 = v49.m_enum == 0;
LABEL_31:
        if ( !v30 )
          goto LABEL_35;
        goto LABEL_32;
      }
      v37 = (signed int)v18->m_oppositeEdge;
      v38 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9->m_boundary.m_map.m_elem,
              v37,
              0xFFFFFFFFui64);
      hkcdDynamicAabbTree::remove(&v9->m_tree, v38);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9->m_boundary.m_map.m_elem,
        &v50,
        v37);
LABEL_32:
      origMesh = v53;
LABEL_33:
      if ( ++v11 >= v10->m_numEdges )
      {
        v6 = faceIdx;
        goto LABEL_37;
      }
    }
    Partitioner::addEdgeToBoundary(v9, &v48, v7, v13);
    v30 = v48.m_enum == 0;
    goto LABEL_31;
  }
LABEL_37:
  v39 = v9->m_settings;
  if ( v39->m_useHeightPartitioning.m_bool && !v39->m_useConservativeHeightPartitioning.m_bool )
    hkaiNavMeshSimplificationUtils::PlaneFitter::calcPlane(&v9->m_fitter, (hkResult *)&faceIdx, &v9->m_plane);
  v40 = v9->m_partition.m_elem.m_size - 1;
  if ( 2 * v9->m_partition.m_numElems > v40
    && hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::resizeTable(
         &v9->m_partition,
         (hkResult *)&faceIdx,
         2 * v40 + 2)->m_enum )
  {
LABEL_35:
    v8->m_enum = 1;
  }
  else
  {
    v41 = v9->m_partition.m_elem.m_size;
    if ( 2 * v9->m_partition.m_numElems > v41 - 1 )
      hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::resizeTable(
        &v9->m_partition,
        (hkResult *)&faceIdx,
        2 * v41);
    v42 = v9->m_partition.m_elem.m_data;
    v43 = v9->m_partition.m_elem.m_size - 1;
    v44 = 1;
    v45 = v43 & -1640531535 * v6;
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
    v9->m_partition.m_numElems += v44;
    v8->m_enum = 0;
    v42[v45] = v6;
  }
  return v8;
}

// File Line: 617
// RVA: 0xB5C280
hkResult *__fastcall partitionFaces(hkResult *result, hkaiNavMesh *mesh, hkaiNavMesh *origMesh, hkVector4f *up, Partitioner *partitioner, hkArray<int,hkContainerHeapAllocator> *numFacesInPartition, hkArray<int,hkContainerHeapAllocator> *partitions, hkArray<int,hkContainerHeapAllocator> *numEdgesInGroupInOut, hkArray<int,hkContainerHeapAllocator> *edgesToRemoveInOut)
{
  hkVector4f *v9; // r14
  __int64 v10; // r9
  hkaiNavMesh *v11; // r15
  hkResult *v12; // rbx
  int v13; // edi
  int v14; // er8
  int v16; // ebx
  int v17; // er9
  __int64 v18; // rcx
  char *v19; // rdi
  signed int *v20; // rdi
  __int64 v21; // rcx
  signed __int64 v22; // rdx
  Partitioner *v23; // r13
  int v24; // ebx
  int v25; // er12
  int v26; // edi
  __int32 v27; // eax
  float *v28; // r9
  signed int v29; // er8
  int v30; // er9
  hkResult *v31; // rdi
  __int64 v32; // r8
  float *v33; // rdx
  __int64 v34; // rcx
  float *v35; // rdi
  __m128 v36; // xmm3
  int v37; // er8
  int v38; // ebx
  int v39; // er14
  int v40; // edi
  int v41; // esi
  int v42; // er15
  int v43; // edx
  __int64 v44; // rcx
  int v45; // edi
  int v46; // ebx
  unsigned int *v47; // r9
  int v48; // er10
  __int64 v49; // rcx
  __int64 v50; // rsi
  __int64 v51; // r13
  float v52; // edx
  hkaiNavMesh *v53; // r11
  hkaiNavMesh::Face *v54; // r12
  hkResultEnum v55; // edx
  bool v56; // al
  int v57; // ecx
  int v58; // er9
  signed __int64 v59; // r15
  hkaiNavMesh *v60; // r11
  signed __int64 v61; // r14
  signed __int64 v62; // rsi
  int v63; // ecx
  int v64; // eax
  int v65; // esi
  int v66; // edx
  __int64 v67; // rcx
  hkArray<int,hkContainerHeapAllocator> *v68; // r11
  hkResultEnum v69; // ecx
  bool v70; // zf
  bool v71; // sf
  __int64 v72; // r13
  __int64 v73; // r14
  char v74; // si
  __int64 v75; // r15
  char v76; // bl
  __int64 v77; // r14
  __int64 v78; // r11
  int *v79; // r8
  int v80; // ecx
  signed __int64 v81; // rax
  hkArray<int,hkContainerHeapAllocator> *v82; // rsi
  __int64 v83; // r11
  __int64 v84; // r8
  int v85; // ecx
  signed __int64 v86; // rax
  int v87; // er10
  __int64 v88; // rbx
  int v89; // ecx
  int v90; // er9
  int v91; // er9
  int v92; // er8
  int *v93; // rcx
  int v94; // edx
  __int64 v95; // rdx
  int v96; // eax
  signed __int64 v97; // rdx
  __int32 v98; // er8
  signed __int64 v99; // rdi
  __int64 v100; // rcx
  int v101; // eax
  int v102; // er9
  int v103; // eax
  int v104; // eax
  int v105; // ecx
  int v106; // er9
  int v107; // eax
  int v108; // eax
  int v109; // er8
  unsigned int *v110; // [rsp+30h] [rbp-B1h]
  int numtoinsert; // [rsp+38h] [rbp-A9h]
  int v112; // [rsp+3Ch] [rbp-A5h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+40h] [rbp-A1h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v114; // [rsp+50h] [rbp-91h]
  hkResult resulta; // [rsp+60h] [rbp-81h]
  char *array; // [rsp+68h] [rbp-79h]
  int v117; // [rsp+70h] [rbp-71h]
  int v118; // [rsp+74h] [rbp-6Dh]
  hkaMatrix<float> v119; // [rsp+78h] [rbp-69h]
  hkQueue<hkpRigidBody *> v120; // [rsp+90h] [rbp-51h]
  hkResult v121; // [rsp+A8h] [rbp-39h]
  hkResult v122; // [rsp+ACh] [rbp-35h]
  int majorAxis; // [rsp+B0h] [rbp-31h]
  hkResult v124; // [rsp+B4h] [rbp-2Dh]
  hkResult v125; // [rsp+B8h] [rbp-29h]
  hkResult v126; // [rsp+BCh] [rbp-25h]
  hkResult v127; // [rsp+C0h] [rbp-21h]
  hkResult v128; // [rsp+C4h] [rbp-1Dh]
  hkResult resOut; // [rsp+C8h] [rbp-19h]
  __int64 v130; // [rsp+D0h] [rbp-11h]
  hkResult *v131; // [rsp+120h] [rbp+3Fh]
  hkaiNavMesh *mesha; // [rsp+128h] [rbp+47h]
  hkaiNavMesh *origMesha; // [rsp+130h] [rbp+4Fh]

  origMesha = origMesh;
  mesha = mesh;
  v131 = result;
  v9 = up;
  v10 = (unsigned int)mesh->m_edges.m_size;
  v11 = mesh;
  v12 = result;
  v118 = 2147483648;
  array = 0i64;
  v13 = 0;
  v117 = 0;
  if ( (signed int)v10 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v10, 4);
    if ( resulta.m_enum )
    {
      v14 = v118;
      v12->m_enum = 1;
      v117 = 0;
      if ( v14 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          4 * v14);
      return v12;
    }
    v13 = v117;
  }
  v16 = v11->m_edges.m_size;
  if ( (v118 & 0x3FFFFFFF) < v16 )
  {
    v17 = v11->m_edges.m_size;
    if ( v16 < 2 * (v118 & 0x3FFFFFFF) )
      v17 = 2 * (v118 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v121, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v17, 4);
    v13 = v117;
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
  v117 = v16;
  if ( edgesToRemoveInOut->m_size )
  {
    origMesh = 0i64;
    if ( v11->m_faces.m_size > 0 )
    {
      v10 = 0i64;
      do
      {
        v20 = (int *)((char *)&v11->m_faces.m_data->m_startEdgeIndex + v10);
        v21 = *v20;
        if ( (signed int)v21 < (signed int)v21 + *((signed __int16 *)v20 + 4) )
        {
          v22 = 4 * v21;
          do
          {
            LODWORD(v21) = v21 + 1;
            v22 += 4i64;
            *(_DWORD *)&array[v22 - 4] = (_DWORD)origMesh;
          }
          while ( (signed int)v21 < *v20 + *((signed __int16 *)v20 + 4) );
        }
        origMesh = (hkaiNavMesh *)(unsigned int)((_DWORD)origMesh + 1);
        v10 += 16i64;
      }
      while ( (signed int)origMesh < v11->m_faces.m_size );
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
  a.m_capacityAndFlags = 2147483648;
  a.m_data = 0i64;
  a.m_size = 0;
  v26 = (v24 + 31) >> 5;
  v114.m_data = 0i64;
  v114.m_size = 0;
  v114.m_capacityAndFlags = 2147483648;
  v119.m_data.m_data = 0i64;
  v119.m_data.m_size = 0;
  v27 = v26;
  v119.m_data.m_capacityAndFlags = 2147483648;
  if ( v26 )
  {
    resulta.m_enum = 4 * v26;
    v28 = (float *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, hkaiNavMesh *, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                     &hkContainerHeapAllocator::s_alloc,
                     &resulta,
                     origMesh,
                     v10);
    v27 = resulta.m_enum / 4;
  }
  else
  {
    v28 = 0i64;
  }
  v29 = 2147483648;
  v119.m_data.m_data = v28;
  if ( v27 )
    v29 = v27;
  v119.m_data.m_size = (v24 + 31) >> 5;
  v119.m_m = v24;
  v119.m_data.m_capacityAndFlags = v29;
  if ( (v29 & 0x3FFFFFFF) < v26 )
  {
    v30 = (v24 + 31) >> 5;
    if ( v26 < 2 * (v29 & 0x3FFFFFFF) )
      v30 = 2 * (v29 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&v121, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v119, v30, 4);
    v29 = v119.m_data.m_capacityAndFlags;
    v28 = v119.m_data.m_data;
  }
  v119.m_data.m_size = (v24 + 31) >> 5;
  if ( !v28 )
  {
    v31 = v131;
    v119.m_data.m_size = 0;
    v131->m_enum = 1;
    if ( v29 < 0 )
    {
LABEL_38:
      v119.m_data.m_data = 0i64;
      v119.m_data.m_capacityAndFlags = 2147483648;
LABEL_50:
      v114.m_size = 0;
      if ( v114.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v114.m_data,
          4 * v114.m_capacityAndFlags);
      v114.m_data = 0i64;
      v114.m_capacityAndFlags = 2147483648;
      a.m_size = 0;
      if ( a.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          a.m_data,
          4 * a.m_capacityAndFlags);
      a.m_data = 0i64;
      v117 = 0;
      goto LABEL_55;
    }
    v32 = (unsigned int)(4 * v29);
    v33 = 0i64;
LABEL_37:
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v33, v32);
    goto LABEL_38;
  }
  if ( v26 - 1 >= 0 )
  {
    v34 = (unsigned int)v26;
    v35 = v28;
    while ( v34 )
    {
      *v35 = -6.8056469e38/*NaN*/;
      ++v35;
      --v34;
    }
  }
  v36 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v9), 1u), 1u);
  majorAxis = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                     _mm_and_ps(
                                                                       _mm_cmpleps(
                                                                         _mm_max_ps(
                                                                           _mm_shuffle_ps(v36, v36, 170),
                                                                           _mm_max_ps(
                                                                             _mm_shuffle_ps(v36, v36, 85),
                                                                             _mm_shuffle_ps(v36, v36, 0))),
                                                                         v36),
                                                                       (__m128)xmmword_141A4CC80))];
  hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v120);
  hkQueue<int>::setCapacity((hkQueue<int> *)&v120, 8);
  if ( !v120.m_data )
  {
    v31 = v131;
    v131->m_enum = 1;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v120);
    v119.m_data.m_size = 0;
    if ( v119.m_data.m_capacityAndFlags < 0 )
      goto LABEL_38;
    v33 = v119.m_data.m_data;
    v32 = (unsigned int)(4 * v119.m_data.m_capacityAndFlags);
    goto LABEL_37;
  }
LABEL_46:
  v37 = v11->m_faces.m_size;
  v38 = 0;
  v39 = 0;
  *(_QWORD *)&v120.m_head = 0i64;
  v40 = 0;
  v41 = 0;
  v120.m_elementsInUse = 0;
  if ( v37 <= 0 )
    goto LABEL_49;
  while ( !((LODWORD(v119.m_data.m_data[(signed __int64)v41 >> 5]) >> (v41 & 0x1F)) & 1) )
  {
    if ( ++v41 >= v37 )
      goto LABEL_49;
  }
  v42 = v120.m_capacity;
  if ( v120.m_capacity <= 0 )
  {
    v43 = 8;
    if ( v120.m_capacity )
      v43 = 2 * v120.m_capacity;
    hkQueue<int>::setCapacity((hkQueue<int> *)&v120, v43);
    v42 = v120.m_capacity;
    v39 = v120.m_head;
    v40 = v120.m_tail;
    v38 = v120.m_elementsInUse;
  }
  if ( v40 == v42 )
    v40 = 0;
  v44 = v40;
  v45 = v40 + 1;
  v46 = v38 + 1;
  v120.m_elementsInUse = v46;
  *((_DWORD *)v120.m_data + v44) = v41;
  v120.m_tail = v45;
  if ( !v46 )
  {
LABEL_49:
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)numEdgesInGroupInOut,
      &a);
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)edgesToRemoveInOut,
      &v114);
    v31 = v131;
    v131->m_enum = 0;
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v120);
    hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v119);
    goto LABEL_50;
  }
  resulta.m_enum = -1;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v23->m_boundary.m_map.m_elem);
  hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::clear(&v23->m_partition);
  hkaiNavMeshSimplificationUtils::PlaneFitter::reset(&v23->m_fitter);
  v23->m_points.m_size = 0;
  v23->m_plane = 0i64;
  v23->m_minHeight = (hkSimdFloat32)xmmword_141A712A0;
  v23->m_maxHeight.m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  hkcdDynamicAabbTree::clear(&v23->m_tree);
  v47 = 0i64;
  v110 = 0i64;
  v48 = 0;
  numtoinsert = 0;
  v112 = 2147483648;
  while ( 1 )
  {
    v49 = v39++;
    v50 = *((signed int *)v120.m_data + v49);
    if ( v39 == v42 )
      v39 = 0;
    --v46;
    v120.m_head = v39;
    v51 = v50 >> 5;
    v52 = v119.m_data.m_data[v51];
    v120.m_elementsInUse = v46;
    if ( !((LODWORD(v52) >> (v50 & 0x1F)) & 1) )
      goto LABEL_103;
    v53 = mesha;
    v54 = &mesha->m_faces.m_data[v50];
    if ( mesha->m_faceDataStriding )
      v55 = mesha->m_faceData.m_data[v50 * mesha->m_faceDataStriding];
    else
      v55 = 0;
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
    v42 = v120.m_capacity;
    if ( !v46 )
    {
      v68 = numEdgesInGroupInOut;
      v69 = 0;
      v70 = numEdgesInGroupInOut->m_size == 0;
      v71 = numEdgesInGroupInOut->m_size < 0;
      resulta.m_enum = 0;
      if ( !v71 && !v70 )
      {
        v72 = 0i64;
        while ( 1 )
        {
          v73 = v69;
          v74 = 0;
          v75 = v68->m_data[v72];
          v76 = 1;
          v130 = v69;
          v121.m_enum = (signed int)v75;
          if ( (signed int)v75 <= 0 )
            goto LABEL_130;
          v77 = v69;
          v78 = v75;
          v79 = &edgesToRemoveInOut->m_data[v77];
          do
          {
            v80 = 0;
            v81 = 0i64;
            if ( v48 <= 0 )
              goto LABEL_111;
            while ( v47[v81] != *(_DWORD *)&array[4 * *v79] )
            {
              ++v81;
              ++v80;
              if ( v81 >= v48 )
                goto LABEL_111;
            }
            if ( v80 == -1 )
LABEL_111:
              v76 = 0;
            else
              v74 = 1;
            ++v79;
            --v78;
          }
          while ( v78 );
          v75 = v121.m_enum;
          if ( v76 )
            break;
          if ( v74 )
          {
            v82 = edgesToRemoveInOut;
            v83 = v121.m_enum;
            do
            {
              v84 = *(signed int *)&array[4 * edgesToRemoveInOut->m_data[v77]];
              v85 = 0;
              v86 = 0i64;
              if ( v48 > 0 )
              {
                while ( v47[v86] != (_DWORD)v84 )
                {
                  ++v86;
                  ++v85;
                  if ( v86 >= v48 )
                    goto LABEL_126;
                }
                if ( v86 != -1 )
                {
                  v87 = v48 - 1;
                  numtoinsert = v87;
                  if ( v87 != v85 )
                    v47[v86] = v47[v87];
                  LODWORD(v119.m_data.m_data[v84 >> 5]) |= 1 << (v84 & 0x1F);
                  v48 = numtoinsert;
                  v47 = v110;
                }
              }
LABEL_126:
              ++v77;
              --v83;
            }
            while ( v83 );
            v73 = v130;
            v88 = v75;
            goto LABEL_152;
          }
          v68 = numEdgesInGroupInOut;
          v69 = v121.m_enum + resulta.m_enum;
          resulta.m_enum += v121.m_enum;
LABEL_161:
          ++v25;
          ++v72;
          if ( v25 >= v68->m_size )
            goto LABEL_162;
        }
        v73 = v130;
LABEL_130:
        v89 = a.m_size;
        v90 = a.m_size + 1;
        if ( (a.m_capacityAndFlags & 0x3FFFFFFF) >= a.m_size + 1 )
        {
          v127.m_enum = 0;
        }
        else
        {
          if ( v90 < 2 * (a.m_capacityAndFlags & 0x3FFFFFFF) )
            v90 = 2 * (a.m_capacityAndFlags & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v127, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &a, v90, 4);
          if ( v127.m_enum )
            goto LABEL_140;
          v89 = a.m_size;
        }
        *(&a.m_data->m_fromOffset + v89) = v75;
        ++a.m_size;
        v91 = v75 + v114.m_size;
        if ( (v114.m_capacityAndFlags & 0x3FFFFFFF) >= (signed int)v75 + v114.m_size )
        {
          v124.m_enum = 0;
        }
        else
        {
          if ( v91 < 2 * (v114.m_capacityAndFlags & 0x3FFFFFFF) )
            v91 = 2 * (v114.m_capacityAndFlags & 0x3FFFFFFF);
          hkArrayUtil::_reserve(&v124, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v114, v91, 4);
          if ( v124.m_enum )
            goto LABEL_140;
        }
        v82 = edgesToRemoveInOut;
        hkArrayBase<unsigned int>::_append(
          (hkArrayBase<unsigned int> *)&v114,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (const unsigned int *)&edgesToRemoveInOut->m_data[v73],
          v75);
        v48 = numtoinsert;
        v47 = v110;
        v88 = (signed int)v75;
LABEL_152:
        v68 = numEdgesInGroupInOut;
        --v68->m_size;
        v93 = &numEdgesInGroupInOut->m_data[v72];
        v94 = 4 * (numEdgesInGroupInOut->m_size - v25);
        if ( v94 > 0 )
        {
          v95 = ((unsigned int)(v94 - 1) >> 2) + 1;
          do
          {
            v96 = v93[1];
            ++v93;
            *(v93 - 1) = v96;
            --v95;
          }
          while ( v95 );
          v48 = numtoinsert;
          v47 = v110;
        }
        v82->m_size -= v75;
        v97 = (signed __int64)&v82->m_data[v73];
        v98 = 4 * (v82->m_size - resulta.m_enum);
        if ( v98 > 0 )
        {
          v99 = (signed __int64)&v82->m_data[v88 + v73] - v97;
          v100 = ((unsigned int)(v98 - 1) >> 2) + 1;
          do
          {
            v101 = *(_DWORD *)(v99 + v97);
            v97 += 4i64;
            *(_DWORD *)(v97 - 4) = v101;
            --v100;
          }
          while ( v100 );
          v48 = numtoinsert;
          v47 = v110;
        }
        v69 = resulta.m_enum;
        --v25;
        --v72;
        goto LABEL_161;
      }
LABEL_162:
      if ( v48 )
      {
        v102 = numFacesInPartition->m_size + 1;
        v103 = numFacesInPartition->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v103 >= v102 )
        {
          v126.m_enum = 0;
        }
        else
        {
          v104 = 2 * v103;
          if ( v102 < v104 )
            v102 = v104;
          hkArrayUtil::_reserve(
            &v126,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            numFacesInPartition,
            v102,
            4);
          if ( v126.m_enum )
          {
LABEL_179:
            v109 = v112;
            v31 = v131;
            numtoinsert = 0;
            v131->m_enum = 1;
            if ( v109 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                v110,
                4 * v109);
            v110 = 0i64;
            v112 = 2147483648;
            hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v120);
            hkArray<unsigned int,hkContainerHeapAllocator>::~hkArray<unsigned int,hkContainerHeapAllocator>(&v119);
            goto LABEL_145;
          }
          v48 = numtoinsert;
        }
        numFacesInPartition->m_data[numFacesInPartition->m_size++] = v48;
        v105 = numtoinsert;
        v106 = numtoinsert + partitions->m_size;
        v107 = partitions->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v107 >= v106 )
        {
          v122.m_enum = 0;
        }
        else
        {
          v108 = 2 * v107;
          if ( v106 < v108 )
            v106 = v108;
          hkArrayUtil::_reserve(
            &v122,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            partitions,
            v106,
            4);
          if ( v122.m_enum )
            goto LABEL_179;
          v105 = numtoinsert;
        }
        hkArrayBase<unsigned int>::_append(
          (hkArrayBase<unsigned int> *)partitions,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v110,
          v105);
        v47 = v110;
      }
      v25 = 0;
      numtoinsert = 0;
      if ( v112 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v47,
          4 * v112);
      v11 = mesha;
      v23 = partitioner;
      v110 = 0i64;
      v112 = 2147483648;
      goto LABEL_46;
    }
  }
  v56 = Partitioner::canInclude(partitioner, mesha, origMesha, v50, majorAxis, &resOut) == 0;
  if ( resOut.m_enum )
    goto LABEL_140;
  if ( v56 )
  {
LABEL_101:
    v47 = v110;
    v48 = numtoinsert;
    goto LABEL_102;
  }
  v53 = mesha;
LABEL_78:
  Partitioner::include(partitioner, &v128, v53, origMesha, v50, majorAxis);
  if ( v128.m_enum )
    goto LABEL_140;
  v57 = numtoinsert;
  v58 = numtoinsert + 1;
  if ( (v112 & 0x3FFFFFFF) >= numtoinsert + 1 )
  {
    v125.m_enum = 0;
LABEL_85:
    v110[v57] = v50;
    ++numtoinsert;
    LODWORD(v119.m_data.m_data[v51]) &= ~(1 << (v50 & 0x1F));
    v59 = v54->m_startEdgeIndex;
    if ( (signed int)v59 < (signed int)v59 + v54->m_numEdges )
    {
      v60 = mesha;
      v61 = v59;
      do
      {
        v62 = (signed __int64)&v60->m_edges.m_data[v61];
        v63 = *(_DWORD *)(v62 + 12);
        if ( v63 != -1
          && (LODWORD(v119.m_data.m_data[(signed __int64)*(signed int *)(v62 + 12) >> 5]) >> (v63 & 0x1F)) & 1 )
        {
          v64 = v120.m_capacity;
          if ( v46 >= v120.m_capacity )
          {
            hkQueue<int>::setCapacity((hkQueue<int> *)&v120, 2 * v120.m_capacity);
            if ( !v120.m_data )
              goto LABEL_140;
            v46 = v120.m_elementsInUse;
            v45 = v120.m_tail;
            v64 = v120.m_capacity;
          }
          v65 = *(_DWORD *)(v62 + 12);
          if ( v46 >= v64 )
          {
            v66 = 8;
            if ( v64 )
              v66 = 2 * v64;
            hkQueue<int>::setCapacity((hkQueue<int> *)&v120, v66);
            v64 = v120.m_capacity;
            v45 = v120.m_tail;
            v46 = v120.m_elementsInUse;
          }
          v60 = mesha;
          if ( v45 == v64 )
            v45 = 0;
          v67 = v45++;
          ++v46;
          *((_DWORD *)v120.m_data + v67) = v65;
          v120.m_elementsInUse = v46;
          v120.m_tail = v45;
        }
        LODWORD(v59) = v59 + 1;
        ++v61;
      }
      while ( (signed int)v59 < v54->m_startEdgeIndex + v54->m_numEdges );
      v39 = v120.m_head;
    }
    goto LABEL_101;
  }
  if ( v58 < 2 * (v112 & 0x3FFFFFFF) )
    v58 = 2 * (v112 & 0x3FFFFFFF);
  hkArrayUtil::_reserve(&v125, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v110, v58, 4);
  if ( v125.m_enum == HK_SUCCESS )
  {
    v57 = numtoinsert;
    goto LABEL_85;
  }
LABEL_140:
  v92 = v112;
  v31 = v131;
  v131->m_enum = 1;
  numtoinsert = 0;
  if ( v92 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v110,
      4 * v92);
  v110 = 0i64;
  v112 = 2147483648;
  hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v120);
  v119.m_data.m_size = 0;
  if ( v119.m_data.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v119.m_data.m_data,
      4 * v119.m_data.m_capacityAndFlags);
  v119.m_data.m_data = 0i64;
  v119.m_data.m_capacityAndFlags = 2147483648;
LABEL_145:
  v114.m_size = 0;
  if ( v114.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v114.m_data,
      4 * v114.m_capacityAndFlags);
  v114.m_data = 0i64;
  v114.m_capacityAndFlags = 2147483648;
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      a.m_data,
      4 * a.m_capacityAndFlags);
  a.m_data = 0i64;
  v117 = 0;
LABEL_55:
  a.m_capacityAndFlags = 2147483648;
  if ( v118 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v118);
  return v31;
}483648;
LABEL_145:
  v114.m_size = 0;
  if ( v114.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v114.m_data,
      4 * v114.m_capacityAndFlags);
  v114.m_data = 0i64;
  v114.m_capacityAndFlags = 2147483648;
  a.m_size = 0;
  if ( a.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      a.m_data,
      4 * a.m_capacityAndFlags);
  a.m_data = 0i64;
  v117 = 0;
LABEL_55:
  a.m_capacityAndFlags = 2147483648;
  if ( v118 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocato

// File Line: 815
// RVA: 0xB5CFE0
void __fastcall getOnePartitionWC(hkaiNavMesh *mesh, hkaiNavMesh *origMesh, Partitioner *partitioner, int startingFace, hkVector4f *parDir, hkArray<int,hkContainerTempAllocator> *newPartition, hkBitField *unassignedFacesInOut)
{
  int v7; // ebx
  hkSimdFloat32 *v8; // r15
  Partitioner *v9; // rdi
  __m128 v10; // xmm2
  int v11; // er12
  int v12; // esi
  int v13; // er14
  int v14; // edx
  int v15; // edi
  __int64 v16; // rcx
  int v17; // edi
  int v18; // esi
  int v19; // ebx
  __int64 v20; // rcx
  hkaiNavMesh *v21; // r10
  signed __int64 v22; // rdx
  hkArray<int,hkContainerHeapAllocator> *v23; // rax
  signed int *v24; // r13
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  Partitioner *v28; // r8
  __int64 v29; // r12
  signed __int64 v30; // r15
  __int64 v31; // rbx
  int v32; // edx
  __int64 v33; // rcx
  hkQueue<hkpRigidBody *> v34; // [rsp+10h] [rbp-71h]
  hkResult *resOut; // [rsp+28h] [rbp-59h]
  int v36; // [rsp+30h] [rbp-51h]
  hkResult result; // [rsp+34h] [rbp-4Dh]
  hkResult v38; // [rsp+38h] [rbp-49h]
  __int64 v39; // [rsp+40h] [rbp-41h]
  int v40[4]; // [rsp+50h] [rbp-31h]
  int faceIndex[4]; // [rsp+60h] [rbp-21h]
  char v42; // [rsp+70h] [rbp-11h]
  __int64 v43; // [rsp+80h] [rbp-1h]
  hkSimdFloat32 *v44; // [rsp+D0h] [rbp+4Fh]
  hkaiNavMesh *origMesha; // [rsp+D8h] [rbp+57h]
  Partitioner *vars0; // [rsp+E0h] [rbp+5Fh]
  __m128 *v47; // [rsp+F0h] [rbp+6Fh]
  hkaiNavMesh *array; // [rsp+F8h] [rbp+77h]
  Partitioner *v49; // [rsp+100h] [rbp+7Fh]

  v49 = partitioner;
  array = origMesh;
  v47 = (__m128 *)mesh;
  v7 = startingFace;
  v8 = (hkSimdFloat32 *)mesh;
  v9 = partitioner;
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
    (hkaiNavMeshUtils *)&v42,
    (hkSimdFloat32 *)mesh,
    (hkaiNavMesh *)(unsigned int)startingFace,
    (unsigned __int64)&v43,
    *(hkVector4f **)&v34.m_tail);
  v10 = _mm_mul_ps(*v47, *(__m128 *)faceIndex);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170))) >= 0.5 )
  {
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9->m_boundary.m_map.m_elem);
    hkSet<int,hkContainerHeapAllocator,hkMapOperations<int>>::clear(&v9->m_partition);
    hkaiNavMeshSimplificationUtils::PlaneFitter::reset(&v9->m_fitter);
    v11 = 0;
    v9->m_points.m_size = 0;
    v9->m_plane = 0i64;
    v9->m_minHeight = (hkSimdFloat32)xmmword_141A712A0;
    v9->m_maxHeight.m_real = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
    hkcdDynamicAabbTree::clear(&v9->m_tree);
    HIDWORD(resOut) = -1;
    hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>(&v34);
    v12 = v34.m_elementsInUse;
    v13 = v34.m_capacity;
    if ( v34.m_elementsInUse >= v34.m_capacity )
    {
      v14 = 8;
      if ( v34.m_capacity )
        v14 = 2 * v34.m_capacity;
      hkQueue<int>::setCapacity((hkQueue<int> *)&v34, v14);
      v13 = v34.m_capacity;
      v12 = v34.m_elementsInUse;
    }
    v15 = v34.m_tail;
    if ( v34.m_tail == v13 )
      v15 = 0;
    v16 = v15;
    v17 = v15 + 1;
    v18 = v12 + 1;
    v34.m_elementsInUse = v18;
    *((_DWORD *)v34.m_data + v16) = v7;
    v34.m_tail = v17;
    if ( v18 )
    {
      v19 = v34.m_head;
      while ( 1 )
      {
        v20 = v19++;
        v21 = (hkaiNavMesh *)*((signed int *)v34.m_data + v20);
        if ( v19 == v13 )
          v19 = 0;
        --v18;
        LODWORD(resOut) = *((_DWORD *)v34.m_data + v20);
        v22 = 4 * ((signed __int64)v21 >> 5);
        v23 = v49->m_edgesToRemove;
        v39 = v22;
        v34.m_head = v19;
        LODWORD(v22) = *(_DWORD *)((char *)&v23->m_data + v22);
        v34.m_elementsInUse = v18;
        v36 = (unsigned __int8)v21 & 0x1F;
        if ( !(((unsigned int)v22 >> ((unsigned __int8)v21 & 0x1F)) & 1) )
          goto LABEL_37;
        v24 = (signed int *)(v8[1].m_real.m128_u64[0] + 16i64 * (_QWORD)v21);
        if ( v8[7].m_real.m128_i32[0] )
          v11 = *(_DWORD *)(v8[5].m_real.m128_u64[0] + 4 * (_QWORD)v21 * v8[7].m_real.m128_i32[0]);
        if ( !*(_DWORD *)&array->m_memSizeAndFlags )
          break;
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
          (hkaiNavMeshUtils *)&v42,
          v8,
          v21,
          (unsigned __int64)v40,
          *(hkVector4f **)&v34.m_tail);
        v25 = _mm_mul_ps(*v47, *(__m128 *)v40);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170))) >= 0.5
          && v11 == HIDWORD(resOut) )
        {
          v26 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)v47, 1u), 1u);
          if ( Partitioner::canInclude(
                 vars0,
                 (hkaiNavMesh *)v8,
                 origMesha,
                 (int)resOut,
                 (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                        _mm_and_ps(
                                                                          _mm_cmpleps(
                                                                            _mm_max_ps(
                                                                              _mm_shuffle_ps(v26, v26, 170),
                                                                              _mm_max_ps(
                                                                                _mm_shuffle_ps(v26, v26, 85),
                                                                                _mm_shuffle_ps(v26, v26, 0))),
                                                                            v26),
                                                                          (__m128)xmmword_141A4CC80))],
                 &v38) )
          {
            LODWORD(v21) = (_DWORD)resOut;
            goto LABEL_21;
          }
        }
LABEL_36:
        v11 = 0;
LABEL_37:
        if ( !v18 )
          goto LABEL_38;
      }
      HIDWORD(resOut) = v11;
LABEL_21:
      v27 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v47), 1u), 1u);
      Partitioner::include(
        vars0,
        &result,
        (hkaiNavMesh *)v8,
        origMesha,
        (int)v21,
        (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v27, v27, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v27, v27, 85),
                                                                       _mm_shuffle_ps(v27, v27, 0))),
                                                                   v27),
                                                                 (__m128)xmmword_141A4CC80))]);
      if ( *(_DWORD *)&array->m_memSizeAndFlags == (*(_DWORD *)(&array->m_referenceCount + 1) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, array, 4);
      v28 = v49;
      *((_DWORD *)&array->vfptr->__vecDelDtor + (signed int)(*(_DWORD *)&array->m_memSizeAndFlags)++) = (_DWORD)resOut;
      *(_DWORD *)((char *)&v49->m_edgesToRemove->m_data + v39) &= ~(1 << v36);
      v29 = *v24;
      if ( (signed int)v29 < (signed int)v29 + *((signed __int16 *)v24 + 4) )
      {
        v30 = 20 * v29;
        do
        {
          v31 = *(signed int *)(v30 + v44[2].m_real.m128_u64[0] + 12);
          if ( (_DWORD)v31 != -1 && (*((_DWORD *)&v28->m_edgesToRemove->m_data + (v31 >> 5)) >> (v31 & 0x1F)) & 1 )
          {
            if ( v18 >= v13 )
            {
              v32 = 8;
              if ( v13 )
                v32 = 2 * v13;
              hkQueue<int>::setCapacity((hkQueue<int> *)&v34, v32);
              v28 = v49;
              v13 = v34.m_capacity;
              v17 = v34.m_tail;
              v18 = v34.m_elementsInUse;
            }
            if ( v17 == v13 )
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
        while ( (signed int)v29 < *v24 + *((signed __int16 *)v24 + 4) );
        v19 = v34.m_head;
        v8 = v44;
      }
      goto LABEL_36;
    }
LABEL_38:
    hkQueue<int>::~hkQueue<int>((hkQueue<int> *)&v34);
  }
}

// File Line: 886
// RVA: 0xB5D440
void __fastcall partitionFacesWC(hkaiNavMesh *mesh, hkaiNavMesh *origMesh, Partitioner *partitioner, hkArray<int,hkContainerHeapAllocator> *numFacesInPartition, hkArray<int,hkContainerHeapAllocator> *partitionDir, hkArray<int,hkContainerHeapAllocator> *partitions)
{
  int v6; // ebx
  hkaiNavMesh *v7; // r14
  int v8; // edi
  __int32 v9; // er10
  _DWORD *v10; // rcx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // eax
  _DWORD *v16; // rdi
  __int64 i; // rcx
  __int32 v18; // er12
  void *v19; // rsi
  int v20; // er13
  int v21; // edi
  int v22; // ebx
  int v23; // er15
  int v24; // er14
  hkVector4f *v25; // rax
  int v26; // eax
  int *v27; // r8
  signed __int64 v28; // rcx
  int v29; // edx
  hkResult result; // [rsp+40h] [rbp-79h]
  hkArray<int,hkContainerTempAllocator> newPartition; // [rsp+48h] [rbp-71h]
  _DWORD *array; // [rsp+58h] [rbp-61h]
  int v33; // [rsp+60h] [rbp-59h]
  int v34; // [rsp+64h] [rbp-55h]
  int v35; // [rsp+68h] [rbp-51h]
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > __that; // [rsp+70h] [rbp-49h]
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > v37; // [rsp+88h] [rbp-31h]
  hkVector4f parDir; // [rsp+A0h] [rbp-19h]
  hkVector4f v39; // [rsp+B0h] [rbp-9h]
  hkaiNavMesh *mesha; // [rsp+110h] [rbp+57h]
  hkaiNavMesh *origMesha; // [rsp+118h] [rbp+5Fh]
  Partitioner *partitionera; // [rsp+120h] [rbp+67h]
  hkArray<int,hkContainerHeapAllocator> *v43; // [rsp+128h] [rbp+6Fh]

  v43 = numFacesInPartition;
  partitionera = partitioner;
  origMesha = origMesh;
  mesha = mesh;
  v6 = mesh->m_faces.m_size;
  v7 = mesh;
  array = 0i64;
  v33 = 0;
  v8 = (v6 + 31) >> 5;
  v34 = 2147483648;
  v9 = v8;
  if ( v8 )
  {
    result.m_enum = 4 * v8;
    v10 = (_DWORD *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                      (int *)&result);
    v9 = result.m_enum / 4;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 2147483648;
  array = v10;
  if ( v9 )
    v11 = v9;
  v33 = (v6 + 31) >> 5;
  v35 = v6;
  v34 = v11;
  v12 = v11 & 0x3FFFFFFF;
  if ( v12 < v8 )
  {
    v13 = 2 * v12;
    v14 = (v6 + 31) >> 5;
    if ( v8 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v14, 4);
  }
  v15 = v8 - 1;
  v33 = (v6 + 31) >> 5;
  if ( v8 - 1 >= 0 )
  {
    v16 = array;
    for ( i = (unsigned int)(v15 + 1); i; --i )
    {
      *v16 = -1;
      ++v16;
    }
  }
  v18 = 2147483648;
  newPartition.m_data = 0i64;
  newPartition.m_size = 0;
  newPartition.m_capacityAndFlags = 2147483648;
  v19 = 0i64;
  v20 = -1;
  v37.m_words.m_capacityAndFlags = 2147483648;
  v37.m_words.m_data = 0i64;
  v37.m_words.m_size = 0;
  v37.m_numBits = 0;
  while ( 1 )
  {
    v21 = v7->m_faces.m_size;
    v22 = 0;
    if ( v21 <= 0 )
      break;
    while ( !((array[(signed __int64)v22 >> 5] >> (v22 & 0x1F)) & 1) )
    {
      if ( ++v22 >= v21 )
        goto LABEL_18;
    }
    if ( v22 == -1 )
      break;
    v23 = 0;
    v24 = 0;
    do
    {
      newPartition.m_size = 0;
      v25 = hkaiNavMeshSimplificationUtils::_classToDir(&v39, v24);
      __that.m_words.m_data = 0i64;
      __that.m_words.m_size = 0;
      __that.m_words.m_capacityAndFlags = 2147483648;
      parDir.m_quad = v25->m_quad;
      __that.m_numBits = 0;
      hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(
        &__that,
        (hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *)&array);
      getOnePartitionWC(mesha, origMesha, partitionera, v22, &parDir, &newPartition, (hkBitField *)&__that);
      v26 = newPartition.m_size;
      if ( newPartition.m_size && newPartition.m_size > v23 )
      {
        if ( (v18 & 0x3FFFFFFF) < newPartition.m_size )
        {
          if ( v18 >= 0 )
          {
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v19,
              4 * v18);
            v26 = newPartition.m_size;
          }
          result.m_enum = 4 * v26;
          v19 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  (int *)&result);
          v26 = newPartition.m_size;
          v18 = result.m_enum / 4;
        }
        v27 = newPartition.m_data;
        v28 = 0i64;
        v23 = v26;
        if ( v26 > 0 )
        {
          do
          {
            v29 = v27[v28++];
            *((_DWORD *)v19 + v28 - 1) = v29;
          }
          while ( v28 < v26 );
        }
        v20 = v24;
        hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(&v37, &__that);
      }
      if ( __that.m_words.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          __that.m_words.m_data,
          4 * __that.m_words.m_capacityAndFlags);
      ++v24;
    }
    while ( v24 < 6 );
    if ( v43->m_size == (v43->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v43, 4);
    v43->m_data[v43->m_size++] = v23;
    if ( partitionDir->m_size == (partitionDir->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, partitionDir, 4);
    partitionDir->m_data[partitionDir->m_size++] = v20;
    hkArrayBase<unsigned int>::_append(
      (hkArrayBase<unsigned int> *)partitions,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (const unsigned int *)v19,
      v23);
    hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(
      (hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *)&array,
      &v37);
    v7 = mesha;
  }
LABEL_18:
  if ( v37.m_words.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v37.m_words.m_data,
      4 * v37.m_words.m_capacityAndFlags);
  if ( v18 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v19,
      4 * v18);
  newPartition.m_size = 0;
  if ( newPartition.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      newPartition.m_data,
      4 * newPartition.m_capacityAndFlags);
  newPartition.m_data = 0i64;
  newPartition.m_capacityAndFlags = 2147483648;
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v34);
}

// File Line: 991
// RVA: 0xB5BA50
hkResult *__fastcall hkaiNavMeshSimplificationUtils::partition(hkResult *result, hkaiNavMesh *mesh, hkaiNavMesh *origMesh, hkaiNavMeshGenerationSettings *settings, hkArray<int,hkContainerHeapAllocator> *numFacesInPartition, hkArray<int,hkContainerHeapAllocator> *partitions, hkArray<int,hkContainerHeapAllocator> *numEdgesInGroupInOut, hkArray<int,hkContainerHeapAllocator> *edgesToRemoveInOut)
{
  hkResult *v8; // rbp
  hkaiNavMeshGenerationSettings *v9; // rbx
  hkaiNavMesh *v10; // rdi
  hkaiNavMesh *v11; // rsi
  hkVector4f v12; // xmm1
  Partitioner partitioner; // [rsp+50h] [rbp-128h]

  v8 = result;
  v9 = settings;
  _mm_store_si128((__m128i *)&partitioner, (__m128i)0i64);
  v10 = origMesh;
  v11 = mesh;
  partitioner.m_boundary.m_map.m_numElems = 0;
  partitioner.m_settings = &settings->m_simplificationSettings;
  partitioner.m_boundary.m_map.m_hashMod = -1;
  partitioner.m_partition.m_elem.m_data = 0i64;
  partitioner.m_partition.m_elem.m_size = 0;
  partitioner.m_partition.m_elem.m_capacityAndFlags = 2147483648;
  partitioner.m_partition.m_numElems = 0;
  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&partitioner.m_fitter);
  partitioner.m_points.m_data = 0i64;
  partitioner.m_points.m_size = 0;
  partitioner.m_points.m_capacityAndFlags = 2147483648;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&partitioner.m_tree);
  v12.m_quad = (__m128)v11->m_aabb.m_max;
  partitioner.m_aabb.m_min = v11->m_aabb.m_min;
  partitioner.m_aabb.m_max = (hkVector4f)v12.m_quad;
  partitionFaces(
    v8,
    v11,
    v10,
    &v9->m_up,
    &partitioner,
    numFacesInPartition,
    partitions,
    numEdgesInGroupInOut,
    edgesToRemoveInOut);
  Partitioner::~Partitioner(&partitioner);
  return v8;
}

// File Line: 997
// RVA: 0xB5BB90
void __fastcall hkaiNavMeshSimplificationUtils::partitionWC(hkaiNavMesh *mesh, hkaiNavMesh *origMesh, hkaiNavMeshGenerationSettings *settings, hkArray<int,hkContainerHeapAllocator> *numFacesInPartition, hkArray<int,hkContainerHeapAllocator> *partitionDir, hkArray<int,hkContainerHeapAllocator> *partitions)
{
  hkaiNavMesh *v6; // rsi
  hkArray<int,hkContainerHeapAllocator> *v7; // rbx
  hkaiNavMesh *v8; // rdi
  hkVector4f v9; // xmm1
  Partitioner partitioner; // [rsp+30h] [rbp-128h]

  v6 = mesh;
  v7 = numFacesInPartition;
  _mm_store_si128((__m128i *)&partitioner, (__m128i)0i64);
  v8 = origMesh;
  partitioner.m_boundary.m_map.m_numElems = 0;
  partitioner.m_boundary.m_map.m_hashMod = -1;
  partitioner.m_settings = &settings->m_simplificationSettings;
  partitioner.m_partition.m_elem.m_data = 0i64;
  partitioner.m_partition.m_elem.m_size = 0;
  partitioner.m_partition.m_elem.m_capacityAndFlags = 2147483648;
  partitioner.m_partition.m_numElems = 0;
  hkaiNavMeshSimplificationUtils::PlaneFitter::PlaneFitter(&partitioner.m_fitter);
  partitioner.m_points.m_data = 0i64;
  partitioner.m_points.m_size = 0;
  partitioner.m_points.m_capacityAndFlags = 2147483648;
  hkcdDynamicAabbTree::hkcdDynamicAabbTree(&partitioner.m_tree);
  v9.m_quad = (__m128)v6->m_aabb.m_max;
  partitioner.m_aabb.m_min = v6->m_aabb.m_min;
  partitioner.m_aabb.m_max = (hkVector4f)v9.m_quad;
  partitionFacesWC(v6, v8, &partitioner, v7, partitionDir, partitions);
  Partitioner::~Partitioner(&partitioner);
}

