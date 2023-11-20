// File Line: 55
// RVA: 0xBBED00
__int64 __fastcall hkAlgorithm::findMinimumIndex<hkVector4f,hkVector4UtilImpl<float>::DistanceToPoint,hkAlgorithm::less<float>>(hkVector4f *pArr, int N, hkVector4UtilImpl<float>::DistanceToPoint *evalFunc, hkAlgorithm::less<float> compFunc)
{
  __m128 v4; // xmm4
  hkVector4f *v5; // r8
  unsigned int v6; // er9
  __m128 v7; // xmm1
  int v8; // ecx
  __m128 v9; // xmm1
  float i; // xmm3_4
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  float v13; // xmm2_4

  v4 = evalFunc->m_p.m_quad;
  v5 = pArr + 1;
  v6 = 0;
  v7 = _mm_sub_ps(v4, pArr->m_quad);
  v8 = 1;
  v9 = _mm_mul_ps(v7, v7);
  for ( i = (float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170)); v8 < N; ++v8 )
  {
    ++v5;
    v11 = _mm_sub_ps(v4, v5[-1].m_quad);
    v12 = _mm_mul_ps(v11, v11);
    v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
    if ( i > v13 )
    {
      i = v13;
      v6 = v8;
    }
  }
  return v6;
}

// File Line: 62
// RVA: 0xC28D10
int __fastcall hkAlgorithm::findMinimumIndex<hkaiStaticObstacleSystem::VelocityObstacleEdge,`anonymous namespace::CalculateEdgePenalty>(hkaiStaticObstacleSystem::VelocityObstacleEdge *pArr, int N, CalculateEdgePenalty *evalFunc)
{
  return hkAlgorithm::findMinimumIndex<hkaiStaticObstacleSystem::VelocityObstacleEdge,`anonymous namespace::CalculateEdgePenalty,hkAlgorithm::less<float>>(
           pArr,
           N,
           evalFunc,
           0);
}

