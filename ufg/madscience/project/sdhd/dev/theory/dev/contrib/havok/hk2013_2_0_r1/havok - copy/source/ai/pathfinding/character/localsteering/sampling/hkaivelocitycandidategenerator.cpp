// File Line: 88
// RVA: 0xC29A60
void __fastcall hkaiVelocityCandidateGenerator::init(
        hkaiVelocityCandidateGenerator *this,
        hkVector4f *forward,
        hkVector4f *right,
        hkVector4f *prev,
        hkSimdFloat32 *maxSpeed,
        hkSimdFloat32 *desiredSpeed)
{
  __m128 v6; // xmm8
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 v11; // xmm1
  __m128 v12; // xmm6
  __m128 v13; // xmm2
  const char *v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm3

  this->m_forward = (hkVector4f)forward->m_quad;
  this->m_right = (hkVector4f)right->m_quad;
  this->m_maxSpeed = (hkSimdFloat32)maxSpeed->m_real;
  v6 = _mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, maxSpeed->m_real), _mm_div_ps(query.m_quad, maxSpeed->m_real));
  v7 = _mm_mul_ps(prev->m_quad, prev->m_quad);
  v8 = _mm_mul_ps(prev->m_quad, v6);
  v9 = _mm_mul_ps(forward->m_quad, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_mul_ps(right->m_quad, v8);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v14 = hkaiVelocityCandidateGenerator::s_halfSpeed_template;
  v15 = _mm_rsqrt_ps(v13);
  v16 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v13, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v13), v15)),
              _mm_mul_ps(*(__m128 *)_xmm, v15))),
          desiredSpeed->m_real);
  v17 = _mm_mul_ps(desiredSpeed->m_real, v6);
  this->m_firstBlockForward.m_quad = _mm_movelh_ps(
                                       _mm_unpacklo_ps(v10, v17),
                                       _mm_unpacklo_ps(_mm_mul_ps(v16, v10), aabbOut.m_quad));
  this->m_firstBlockRight.m_quad = _mm_movelh_ps(
                                     _mm_unpacklo_ps(v12, aabbOut.m_quad),
                                     _mm_unpacklo_ps(_mm_mul_ps(v16, v12), aabbOut.m_quad));
  if ( v17.m128_f32[0] > 0.78539819 )
    v14 = hkaiVelocityCandidateGenerator::s_main_template;
  this->m_template = v14;
}

// File Line: 133
// RVA: 0xC29BC0
void __fastcall hkaiVelocityCandidateGenerator::generateCandidate(
        hkaiVelocityCandidateGenerator *this,
        int candidateIdx,
        hkVector4f *candidateOut)
{
  int v5; // edx
  int v6; // ecx
  __int64 v7; // rdx
  hkVector4f v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm5
  hkVector4f v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128i v20; // xmm1
  __m128i v21; // xmm4
  __m128i v22; // xmm0
  hkVector4f v23; // xmm1
  __m128 v24; // xmm7
  __m128 v25; // xmm8
  __m128 v26; // xmm0
  __m128 v27; // xmm7
  __m128 v28; // xmm4
  __m128 v29; // xmm8
  __m128 v30; // xmm0
  __m128 v31; // xmm5
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __int128 v37[4]; // [rsp+0h] [rbp-68h]

  v5 = (candidateIdx >> 31) & 3;
  v6 = (v5 + candidateIdx) >> 2;
  v7 = ((v5 + candidateIdx) & 3) - v5;
  v8.m_quad = (__m128)this->m_forward;
  if ( v6 )
  {
    v20 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&this->m_template[8 * v6]), (__m128i)0i64);
    v21 = _mm_unpackhi_epi16(v20, (__m128i)0i64);
    v22 = _mm_unpacklo_epi16(v20, (__m128i)0i64);
    v23.m_quad = (__m128)this->m_right;
    v24 = _mm_add_ps(
            _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v22, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
            _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v22, 0x10u), 0x10u)));
    v25 = _mm_cvtepi32_ps(_mm_srli_epi32(v21, 0x10u));
    v26 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v21, 0x10u), 0x10u));
    v27 = _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(v24, (__m128)xmmword_141A71230), g_vectorfConstants[0]),
            this->m_maxSpeed.m_real);
    v28 = _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 0), v27);
    v29 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(v25, (__m128)`hkIntVector::convertU32ToF32::`2::two16), v26),
                (__m128)xmmword_141A71230),
              g_vectorfConstants[0]),
            this->m_maxSpeed.m_real);
    v14 = _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 85), v27);
    v13 = _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 170), v27);
    v16 = _mm_add_ps(v28, _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 0), v29));
    v30 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 85);
    v18 = _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 170), v29);
    v19 = _mm_mul_ps(v30, v29);
  }
  else
  {
    v9 = _mm_mul_ps(this->m_firstBlockForward.m_quad, this->m_maxSpeed.m_real);
    v10 = _mm_mul_ps(this->m_firstBlockRight.m_quad, this->m_maxSpeed.m_real);
    v11 = _mm_shuffle_ps(v8.m_quad, v8.m_quad, 85);
    v12 = _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 0), v9);
    v13 = _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 170), v9);
    v14 = _mm_mul_ps(v11, v9);
    v15.m_quad = (__m128)this->m_right;
    v16 = _mm_add_ps(v12, _mm_mul_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 0), v10));
    v17 = _mm_shuffle_ps(v15.m_quad, v15.m_quad, 85);
    v18 = _mm_mul_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 170), v10);
    v19 = _mm_mul_ps(v17, v10);
  }
  v31 = _mm_add_ps(v14, v19);
  v32 = _mm_shuffle_ps(v16, v31, 68);
  v33 = _mm_add_ps(v13, v18);
  v34 = _mm_shuffle_ps(v33, (__m128)0i64, 238);
  v35 = _mm_shuffle_ps(v33, (__m128)0i64, 68);
  v36 = _mm_shuffle_ps(v16, v31, 238);
  v37[0] = (__int128)_mm_shuffle_ps(v32, v35, 136);
  v37[1] = (__int128)_mm_shuffle_ps(v32, v35, 221);
  v37[2] = (__int128)_mm_shuffle_ps(v36, v34, 136);
  v37[3] = (__int128)_mm_shuffle_ps(v36, v34, 221);
  *candidateOut = (hkVector4f)v37[v7];
}

// File Line: 161
// RVA: 0xC29D90
hkSimdFloat32 *__fastcall hkaiVelocityCandidateGenerator::generateProgressScore(
        hkaiVelocityCandidateGenerator *this,
        hkSimdFloat32 *result,
        int candidateIdx,
        hkSimdFloat32 *mainForward,
        hkSimdFloat32 *mainRight,
        hkSimdFloat32 *wallForward,
        hkSimdFloat32 *wallRight,
        hkSimdFloat32 *bonusForward,
        hkSimdFloat32 *bonusRight,
        hkSimdFloat32 *desiredSpeedRecip,
        hkSimdFloat32 *wallPenalty)
{
  int v12; // eax
  int v13; // r8d
  __int64 v14; // rdx
  hkVector4f v15; // xmm3
  hkVector4f v16; // xmm4
  __m128 v17; // xmm8
  __m128 v18; // xmm0
  __m128i v19; // xmm1
  __m128i v20; // xmm0
  __m128 v21; // xmm7
  __m128i v22; // xmm0
  __m128 v23; // xmm7
  __m128 v24; // xmm6
  hkSimdFloat32 *v25; // rax
  __m128 v26; // xmm0
  __m128 v27; // xmm1

  v12 = candidateIdx % 4;
  v13 = candidateIdx / 4;
  v14 = v12;
  if ( v13 )
  {
    v19 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&this->m_template[8 * v13]), (__m128i)0i64);
    v20 = _mm_unpacklo_epi16(v19, (__m128i)0i64);
    v21 = _mm_add_ps(
            _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v20, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
            _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v20, 0x10u), 0x10u)));
    v22 = _mm_unpackhi_epi16(v19, (__m128i)0i64);
    v23 = _mm_add_ps(_mm_mul_ps(v21, (__m128)xmmword_141A71230), g_vectorfConstants[0]);
    v24 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v22, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v22, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    v17 = _mm_add_ps(
            _mm_sub_ps(
              _mm_max_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v23, mainForward->m_real), _mm_mul_ps(v24, mainRight->m_real)),
                  (__m128)xmmword_141A710D0),
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_mul_ps(wallForward->m_real, v23), _mm_mul_ps(wallRight->m_real, v24)),
                    (__m128)xmmword_141A710D0),
                  wallPenalty->m_real)),
              _mm_mul_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v24, v24), _mm_mul_ps(v23, v23)), desiredSpeedRecip->m_real),
                this->m_maxSpeed.m_real)),
            _mm_mul_ps(bonusForward->m_real, v23));
    v18 = _mm_mul_ps(bonusRight->m_real, v24);
  }
  else
  {
    v15.m_quad = (__m128)this->m_firstBlockForward;
    v16.m_quad = (__m128)this->m_firstBlockRight;
    v17 = _mm_add_ps(
            _mm_sub_ps(
              _mm_max_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(mainForward->m_real, v15.m_quad), _mm_mul_ps(v16.m_quad, mainRight->m_real)),
                  (__m128)xmmword_141A710D0),
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_mul_ps(wallForward->m_real, v15.m_quad), _mm_mul_ps(wallRight->m_real, v16.m_quad)),
                    (__m128)xmmword_141A710D0),
                  wallPenalty->m_real)),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v16.m_quad, v16.m_quad), _mm_mul_ps(v15.m_quad, v15.m_quad)),
                  desiredSpeedRecip->m_real),
                this->m_maxSpeed.m_real)),
            _mm_mul_ps(bonusForward->m_real, v15.m_quad));
    v18 = _mm_mul_ps(bonusRight->m_real, v16.m_quad);
  }
  v25 = result;
  v26 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent::`2::indexToMask[v14],
          _mm_mul_ps(_mm_add_ps(v17, v18), this->m_maxSpeed.m_real));
  v27 = _mm_or_ps(_mm_shuffle_ps(v26, v26, 78), v26);
  result->m_real = _mm_or_ps(_mm_shuffle_ps(v27, v27, 177), v27);
  return v25;
}

