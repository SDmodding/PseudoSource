// File Line: 88
// RVA: 0xC29A60
void __fastcall hkaiVelocityCandidateGenerator::init(hkaiVelocityCandidateGenerator *this, hkVector4f *forward, hkVector4f *right, hkVector4f *prev, hkSimdFloat32 *maxSpeed, hkSimdFloat32 *desiredSpeed)
{
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm8
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm7
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm2
  const char *v16; // rax
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm3

  this->m_forward = (hkVector4f)forward->m_quad;
  this->m_right = (hkVector4f)right->m_quad;
  this->m_maxSpeed = (hkSimdFloat32)maxSpeed->m_real;
  v6 = prev->m_quad;
  v7 = v6;
  v8 = _mm_andnot_ps(_mm_cmpeqps((__m128)0i64, maxSpeed->m_real), _mm_div_ps(query.m_quad, maxSpeed->m_real));
  v9 = _mm_mul_ps(v6, v6);
  v10 = _mm_mul_ps(v7, v8);
  v11 = _mm_mul_ps(forward->m_quad, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_mul_ps(right->m_quad, v10);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v16 = hkaiVelocityCandidateGenerator::s_halfSpeed_template;
  v17 = _mm_rsqrt_ps(v15);
  v18 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v15), v17)),
              _mm_mul_ps(*(__m128 *)_xmm, v17))),
          desiredSpeed->m_real);
  v19 = _mm_mul_ps(desiredSpeed->m_real, v8);
  this->m_firstBlockForward.m_quad = _mm_movelh_ps(
                                       _mm_unpacklo_ps(v12, v19),
                                       _mm_unpacklo_ps(_mm_mul_ps(v18, v12), aabbOut.m_quad));
  this->m_firstBlockRight.m_quad = _mm_movelh_ps(
                                     _mm_unpacklo_ps(v14, aabbOut.m_quad),
                                     _mm_unpacklo_ps(_mm_mul_ps(v18, v14), aabbOut.m_quad));
  if ( v19.m128_f32[0] > 0.78539819 )
    v16 = hkaiVelocityCandidateGenerator::s_main_template;
  this->m_template = v16;
}

// File Line: 133
// RVA: 0xC29BC0
void __fastcall hkaiVelocityCandidateGenerator::generateCandidate(hkaiVelocityCandidateGenerator *this, int candidateIdx, hkVector4f *candidateOut)
{
  int v3; // kr00_4
  int v4; // edx
  int v5; // eax
  __int64 v6; // rdx
  hkVector4f v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm5
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  hkVector4f v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm0
  hkVector4f v19; // xmm3
  __m128i v20; // xmm4
  __m128i v21; // xmm1
  __m128i v22; // xmm4
  __m128i v23; // xmm1
  __m128 v24; // xmm7
  __m128 v25; // xmm0
  hkVector4f v26; // xmm1
  __m128 v27; // xmm7
  __m128 v28; // xmm8
  __m128 v29; // xmm0
  __m128 v30; // xmm7
  __m128 v31; // xmm4
  __m128 v32; // xmm8
  __m128 v33; // xmm0
  __m128 v34; // xmm5
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm1
  __m128 v40; // xmm4
  __m128 v41; // [rsp+0h] [rbp-68h]
  __m128 v42; // [rsp+10h] [rbp-58h]
  __m128 v43; // [rsp+20h] [rbp-48h]
  __m128 v44; // [rsp+30h] [rbp-38h]

  v3 = candidateIdx;
  v4 = (candidateIdx >> 31) & 3;
  v5 = v4 + v3;
  v6 = ((v4 + v3) & 3) - v4;
  if ( v5 >> 2 )
  {
    v19.m_quad = (__m128)this->m_forward;
    v20 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&this->m_template[8 * (v5 >> 2)]), (__m128i)0i64);
    v21 = v20;
    v22 = _mm_unpackhi_epi16(v20, (__m128i)0i64);
    v23 = _mm_unpacklo_epi16(v21, (__m128i)0i64);
    v24 = _mm_cvtepi32_ps(_mm_srli_epi32(v23, 0x10u));
    v25 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v23, 0x10u), 0x10u));
    v26.m_quad = (__m128)this->m_right;
    v27 = _mm_add_ps(_mm_mul_ps(v24, (__m128)`hkIntVector::convertU32ToF32'::`2'::two16), v25);
    v28 = _mm_cvtepi32_ps(_mm_srli_epi32(v22, 0x10u));
    v29 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v22, 0x10u), 0x10u));
    v30 = _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(v27, (__m128)xmmword_141A71230), g_vectorfConstants[0]),
            this->m_maxSpeed.m_real);
    v31 = _mm_mul_ps(_mm_shuffle_ps(v19.m_quad, v19.m_quad, 0), v30);
    v32 = _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(v28, (__m128)`hkIntVector::convertU32ToF32'::`2'::two16), v29),
                (__m128)xmmword_141A71230),
              g_vectorfConstants[0]),
            this->m_maxSpeed.m_real);
    v13 = _mm_mul_ps(_mm_shuffle_ps(v19.m_quad, v19.m_quad, 85), v30);
    v12 = _mm_mul_ps(_mm_shuffle_ps(v19.m_quad, v19.m_quad, 170), v30);
    v15 = _mm_add_ps(v31, _mm_mul_ps(_mm_shuffle_ps(v26.m_quad, v26.m_quad, 0), v32));
    v33 = _mm_shuffle_ps(this->m_right.m_quad, v26.m_quad, 85);
    v17 = _mm_mul_ps(_mm_shuffle_ps(v26.m_quad, v26.m_quad, 170), v32);
    v18 = _mm_mul_ps(v33, v32);
  }
  else
  {
    v7.m_quad = (__m128)this->m_forward;
    v8 = _mm_mul_ps(this->m_firstBlockForward.m_quad, this->m_maxSpeed.m_real);
    v9 = _mm_mul_ps(this->m_firstBlockRight.m_quad, this->m_maxSpeed.m_real);
    v10 = _mm_shuffle_ps(this->m_forward.m_quad, v7.m_quad, 85);
    v11 = _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 0), v8);
    v12 = _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 170), v8);
    v13 = _mm_mul_ps(v10, v8);
    v14.m_quad = (__m128)this->m_right;
    v15 = _mm_add_ps(v11, _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 0), v9));
    v16 = _mm_shuffle_ps(this->m_right.m_quad, v14.m_quad, 85);
    v17 = _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 170), v9);
    v18 = _mm_mul_ps(v16, v9);
  }
  v34 = _mm_add_ps(v13, v18);
  v35 = _mm_add_ps(v12, v17);
  v36 = _mm_shuffle_ps(v15, v34, 68);
  v37 = v35;
  v38 = _mm_shuffle_ps(v35, (__m128)0i64, 238);
  v39 = _mm_shuffle_ps(v37, (__m128)0i64, 68);
  v40 = _mm_shuffle_ps(v15, v34, 238);
  v41 = _mm_shuffle_ps(v36, v39, 136);
  v42 = _mm_shuffle_ps(v36, v39, 221);
  v43 = _mm_shuffle_ps(v40, v38, 136);
  v44 = _mm_shuffle_ps(v40, v38, 221);
  *candidateOut = *((hkVector4f *)&v41 + v6);
}s(v40, v38, 136);
  v44 = _mm_shuffle_ps(v40, v38, 221);
  *ca

// File Line: 161
// RVA: 0xC29D90
hkSimdFloat32 *__fastcall hkaiVelocityCandidateGenerator::generateProgressScore(hkaiVelocityCandidateGenerator *this, hkSimdFloat32 *result, int candidateIdx, hkSimdFloat32 *mainForward, hkSimdFloat32 *mainRight, hkSimdFloat32 *wallForward, hkSimdFloat32 *wallRight, hkSimdFloat32 *bonusForward, hkSimdFloat32 *bonusRight, hkSimdFloat32 *desiredSpeedRecip, hkSimdFloat32 *wallPenalty)
{
  hkSimdFloat32 *v11; // r10
  int v12; // edx
  char v13; // al
  int v14; // er8
  __int64 v15; // rdx
  hkVector4f v16; // xmm3
  hkVector4f v17; // xmm4
  __m128 v18; // xmm8
  __m128 v19; // xmm0
  __m128i v20; // xmm3
  __m128i v21; // xmm1
  __m128i v22; // xmm3
  __m128i v23; // xmm1
  __m128 v24; // xmm7
  __m128 v25; // xmm6
  hkSimdFloat32 *v26; // rax
  __m128 v27; // xmm0
  __m128 v28; // xmm1

  v11 = result;
  v12 = (candidateIdx >> 31) & 3;
  v13 = v12 + candidateIdx;
  v14 = candidateIdx / 4;
  v15 = (v13 & 3) - v12;
  if ( v14 )
  {
    v20 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)&this->m_template[8 * v14]), (__m128i)0i64);
    v21 = v20;
    v22 = _mm_unpackhi_epi16(v20, (__m128i)0i64);
    v23 = _mm_unpacklo_epi16(v21, (__m128i)0i64);
    v24 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v23, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v23, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    v25 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v22, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v22, 0x10u), 0x10u))),
              (__m128)xmmword_141A71230),
            g_vectorfConstants[0]);
    v18 = _mm_add_ps(
            _mm_sub_ps(
              _mm_max_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v24, mainForward->m_real), _mm_mul_ps(v25, mainRight->m_real)),
                  (__m128)xmmword_141A710D0),
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_mul_ps(wallForward->m_real, v24), _mm_mul_ps(wallRight->m_real, v25)),
                    (__m128)xmmword_141A710D0),
                  wallPenalty->m_real)),
              _mm_mul_ps(
                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v25, v25), _mm_mul_ps(v24, v24)), desiredSpeedRecip->m_real),
                this->m_maxSpeed.m_real)),
            _mm_mul_ps(bonusForward->m_real, v24));
    v19 = _mm_mul_ps(bonusRight->m_real, v25);
  }
  else
  {
    v16.m_quad = (__m128)this->m_firstBlockForward;
    v17.m_quad = (__m128)this->m_firstBlockRight;
    v18 = _mm_add_ps(
            _mm_sub_ps(
              _mm_max_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(mainForward->m_real, v16.m_quad), _mm_mul_ps(v17.m_quad, mainRight->m_real)),
                  (__m128)xmmword_141A710D0),
                _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_mul_ps(wallForward->m_real, v16.m_quad), _mm_mul_ps(wallRight->m_real, v17.m_quad)),
                    (__m128)xmmword_141A710D0),
                  wallPenalty->m_real)),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v17.m_quad, v17.m_quad), _mm_mul_ps(v16.m_quad, v16.m_quad)),
                  desiredSpeedRecip->m_real),
                this->m_maxSpeed.m_real)),
            _mm_mul_ps(bonusForward->m_real, v16.m_quad));
    v19 = _mm_mul_ps(bonusRight->m_real, v17.m_quad);
  }
  v26 = v11;
  v27 = _mm_and_ps(
          (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v15],
          _mm_mul_ps(_mm_add_ps(v18, v19), this->m_maxSpeed.m_real));
  v28 = _mm_or_ps(_mm_shuffle_ps(v27, v27, 78), v27);
  v11->m_real = _mm_or_ps(_mm_shuffle_ps(v28, v28, 177), v28);
  return v26;
}v27, 78), v27);
  v11->m_real = _mm_or_p

