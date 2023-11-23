// File Line: 20
// RVA: 0xBABD10
void __fastcall hkaCompression::sampleDynamicScalarsInternal(
        float *poseOut,
        __int64 numPoseOut,
        char *elements,
        const float *minimums,
        const float *spans,
        char *values,
        int n)
{
  int v10; // r11d
  const unsigned __int16 *v11; // rdx
  unsigned __int64 v12; // rcx
  __int64 v13; // rax
  __m128 v14; // xmm1
  const unsigned __int16 *v15; // rdx
  const float *v16; // rax
  __int64 v17; // r8
  int v18; // ecx
  __m128 v19; // xmm0
  __m128 v20; // xmm1

  if ( HK_flyingcolors_animation_0.m_bool
    || (hkaCheckKeycode(poseOut, numPoseOut),
        hkaProcessFlyingColors(&HK_flyingcolors_animation_0),
        HK_flyingcolors_animation_0.m_bool) )
  {
    v10 = 0;
    if ( n >= 0 && (n & 0xFFFFFFFC) != 0 )
    {
      v11 = (const unsigned __int16 *)(elements + 4);
      v12 = ((unsigned __int64)((int)(n & 0xFFFFFFFC) - 1i64) >> 2) + 1;
      do
      {
        v13 = v10;
        v11 += 4;
        v10 += 4;
        v14 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_unpacklo_epi16(_mm_loadl_epi64((const __m128i *)&values[2 * v13]), (__m128i)0i64)),
                  *(__m128 *)&spans[v13]),
                *(__m128 *)&minimums[v13]);
        poseOut[*(v11 - 6)] = v14.m128_f32[0];
        LODWORD(poseOut[*(v11 - 5)]) = _mm_shuffle_ps(v14, v14, 85).m128_u32[0];
        LODWORD(poseOut[*(v11 - 4)]) = _mm_shuffle_ps(v14, v14, 170).m128_u32[0];
        LODWORD(poseOut[*(v11 - 3)]) = _mm_shuffle_ps(v14, v14, 255).m128_u32[0];
        --v12;
      }
      while ( v12 );
    }
    if ( v10 < n )
    {
      v15 = (const unsigned __int16 *)&elements[2 * v10];
      v16 = &minimums[v10];
      v17 = (unsigned int)(n - v10);
      do
      {
        v18 = *(const unsigned __int16 *)((char *)v15 + values - elements);
        v19 = (__m128)*(unsigned int *)((char *)v16 + (char *)spans - (char *)minimums);
        v20 = 0i64;
        ++v16;
        ++v15;
        v20.m128_f32[0] = (float)v18;
        poseOut[*(v15 - 1)] = (float)(_mm_shuffle_ps(v20, v20, 0).m128_f32[0] * _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                            + _mm_shuffle_ps((__m128)*((unsigned int *)v16 - 1), (__m128)*((unsigned int *)v16 - 1), 0).m128_f32[0];
        --v17;
      }
      while ( v17 );
    }
  }
}

