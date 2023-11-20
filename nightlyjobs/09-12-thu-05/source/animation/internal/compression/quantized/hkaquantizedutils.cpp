// File Line: 20
// RVA: 0xBABD10
void __fastcall hkaCompression::sampleDynamicScalarsInternal(float *poseOut, __int64 numPoseOut, const unsigned __int16 *elements, const float *minimums, const float *spans, const unsigned __int16 *values, int n)
{
  const float *v7; // rsi
  const unsigned __int16 *v8; // rdi
  float *v9; // rbx
  int v10; // er11
  signed __int64 v11; // rdx
  unsigned __int64 v12; // rcx
  __int64 v13; // rax
  __m128 v14; // xmm1
  signed __int64 v15; // rdx
  signed __int64 v16; // rax
  __int64 v17; // r8
  signed int v18; // ecx
  __m128 v19; // xmm0
  __m128 v20; // xmm1

  v7 = minimums;
  v8 = elements;
  v9 = poseOut;
  if ( HK_flyingcolors_animation_0.m_bool
    || (hkaCheckKeycode(poseOut, numPoseOut),
        hkaProcessFlyingColors(&HK_flyingcolors_animation_0),
        HK_flyingcolors_animation_0.m_bool) )
  {
    v10 = 0;
    if ( (signed int)(n & 0xFFFFFFFC) > 0 )
    {
      v11 = (signed __int64)(v8 + 2);
      v12 = ((unsigned __int64)((signed int)(n & 0xFFFFFFFC) - 1i64) >> 2) + 1;
      do
      {
        v13 = v10;
        v11 += 8i64;
        v10 += 4;
        v14 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_unpacklo_epi16(_mm_loadl_epi64((const __m128i *)&values[v13]), (__m128i)0i64)),
                  *(__m128 *)&spans[v13]),
                *(__m128 *)&v7[v13]);
        v9[*(unsigned __int16 *)(v11 - 12)] = v14.m128_f32[0];
        LODWORD(v9[*(unsigned __int16 *)(v11 - 10)]) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 85);
        LODWORD(v9[*(unsigned __int16 *)(v11 - 8)]) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 170);
        LODWORD(v9[*(unsigned __int16 *)(v11 - 6)]) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 255);
        --v12;
      }
      while ( v12 );
    }
    if ( v10 < n )
    {
      v15 = (signed __int64)&v8[v10];
      v16 = (signed __int64)&v7[v10];
      v17 = (unsigned int)(n - v10);
      do
      {
        v18 = *(unsigned __int16 *)((char *)values - (char *)v8 + v15);
        v19 = (__m128)*(unsigned int *)((char *)spans - (char *)v7 + v16);
        v20 = 0i64;
        v16 += 4i64;
        v15 += 2i64;
        v20.m128_f32[0] = (float)v18;
        v9[*(unsigned __int16 *)(v15 - 2)] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0))
                                                   * COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                                           + COERCE_FLOAT(
                                               _mm_shuffle_ps(
                                                 (__m128)*(unsigned int *)(v16 - 4),
                                                 (__m128)*(unsigned int *)(v16 - 4),
                                                 0));
        --v17;
      }
      while ( v17 );
    }
  }
}

