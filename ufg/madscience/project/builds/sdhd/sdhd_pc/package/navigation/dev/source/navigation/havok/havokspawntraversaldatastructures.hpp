// File Line: 27
// RVA: 0xF5680
hkSimdFloat32 *__fastcall UFG::SpawnTraversalCostModifier::getModifiedCost(UFG::SpawnTraversalCostModifier *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *v3; // r11
  __m128 v4; // xmm6
  const int *v5; // r9
  hkSimdFloat32 *v6; // rax
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm0

  v3 = context->m_edgeFaceInfo;
  v4 = 0i64;
  if ( v3->m_face )
  {
    v5 = v3->m_faceData;
    if ( *v5 == 1 )
    {
      v4 = _mm_add_ps((__m128)0i64, (__m128)_xmm);
    }
    else if ( *v5 == 2 )
    {
      v4 = _mm_add_ps(
             (__m128)0i64,
             _mm_shuffle_ps((__m128)LODWORD(this->m_roadCost), (__m128)LODWORD(this->m_roadCost), 0));
    }
    else if ( *v5 != 4 )
    {
      v4 = _mm_add_ps((__m128)0i64, (__m128)_xmm);
    }
  }
  v6 = result;
  v7 = _mm_sub_ps(v3->m_incomingEdgeInfo.m_position.m_quad, this->m_searchOrigin.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v9, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                _mm_mul_ps(*(__m128 *)_xmm, v10))),
            v7),
          this->m_searchDirection.m_quad);
  v12 = (__m128)(unsigned int)FLOAT_1_0;
  v12.m128_f32[0] = (float)(1.0
                          - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))))
                  * 100.0;
  result->m_real = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 0), v4), context->m_originalCost.m_real);
  return v6;
}

