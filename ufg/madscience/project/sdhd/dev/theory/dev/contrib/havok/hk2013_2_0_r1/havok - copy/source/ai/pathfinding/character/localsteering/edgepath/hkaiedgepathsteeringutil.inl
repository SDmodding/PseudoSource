// File Line: 20
// RVA: 0xC137A0
void __fastcall hkaiEdgePathSteeringUtil::calcTangentDirs(
        hkVector4f *p1,
        hkVector4f *p2,
        hkVector4f *c1,
        hkVector4f *c2,
        hkVector4f *up,
        hkVector4f *tangentDir1,
        hkVector4f *tangentDir2,
        hkVector4f *perpDir1,
        hkVector4f *perpDir2)
{
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm5
  __m128 v18; // xmm11
  __m128 v19; // xmm1
  __m128 v20; // xmm11
  __m128 v21; // xmm11
  __m128 v22; // xmm2
  __m128 v23; // xmm10
  __m128 v24; // xmm2
  __m128 v25; // xmm12
  __m128 v26; // xmm13
  __m128i v27; // xmm15
  __m128i v28; // xmm14
  __m128 v29; // xmm8
  __m128 v30; // xmm1
  __m128 v31; // xmm15
  __m128 v32; // xmm15
  __m128 v33; // xmm15
  __m128 v34; // xmm11
  __m128 v35; // xmm8
  __m128 v36; // xmm1
  __m128 v37; // xmm6
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm5
  __m128 v42; // xmm4
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm5

  v9 = _mm_sub_ps(c2->m_quad, p2->m_quad);
  v10 = _mm_sub_ps(c1->m_quad, p1->m_quad);
  v11 = _mm_mul_ps(v10, up->m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_mul_ps(v9, up->m_quad);
  v14 = _mm_sub_ps(v10, _mm_mul_ps(v12, up->m_quad));
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v16 = _mm_mul_ps(v14, v14);
  v17 = _mm_sub_ps(v9, _mm_mul_ps(v15, up->m_quad));
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v19 = _mm_mul_ps(v17, v17);
  v20 = _mm_unpacklo_ps(
          v18,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170)));
  v21 = _mm_movelh_ps(v20, v20);
  v22 = _mm_rsqrt_ps(v21);
  v23 = _mm_andnot_ps(
          _mm_cmple_ps(v21, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v22), v22)), _mm_mul_ps(v22, *(__m128 *)_xmm)));
  v24 = _mm_shuffle_ps(up->m_quad, up->m_quad, 201);
  v25 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v14);
  v26 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v17);
  v27 = (__m128i)_mm_shuffle_ps(c1->m_quad, c1->m_quad, 255);
  v28 = (__m128i)_mm_shuffle_ps(c2->m_quad, c2->m_quad, 255);
  v29 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v27, 0x1Fu), 0x1Fu);
  v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), up->m_quad), _mm_mul_ps(v25, v24));
  v31 = _mm_unpacklo_ps((__m128)v27, (__m128)v28);
  v32 = _mm_movelh_ps(v31, v31);
  v33 = _mm_mul_ps(v32, v32);
  v34 = _mm_sub_ps(v21, v33);
  v35 = _mm_xor_ps(v29, _mm_shuffle_ps(v30, v30, 201));
  v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), up->m_quad), _mm_mul_ps(v26, v24));
  v37 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v28, 0x1Fu), 0x1Fu), _mm_shuffle_ps(v36, v36, 201));
  v38 = _mm_cmple_ps(v34, (__m128)0i64);
  v39 = _mm_or_ps(
          _mm_andnot_ps(v38, _mm_mul_ps(_mm_shuffle_ps(v33, v34, 228), v34)),
          _mm_and_ps(v38, `hkaiEdgePathSteeringUtil::calcTangentDirs::`2::insideLenFactorsQuad));
  v40 = _mm_rsqrt_ps(v39);
  v41 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v39, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v40), v40)),
                _mm_mul_ps(v40, *(__m128 *)_xmm)),
              v39)),
          v23);
  v42 = _mm_shuffle_ps(v41, v41, 0);
  v43 = _mm_shuffle_ps(v41, v41, 170);
  v44 = _mm_shuffle_ps(v41, v41, 85);
  v45 = _mm_shuffle_ps(v41, v41, 255);
  tangentDir1->m_quad = _mm_add_ps(_mm_mul_ps(v25, v43), _mm_mul_ps(v35, v42));
  tangentDir2->m_quad = _mm_add_ps(_mm_mul_ps(v26, v45), _mm_mul_ps(v37, v44));
  perpDir1->m_quad = _mm_sub_ps(_mm_mul_ps(v35, v43), _mm_mul_ps(v25, v42));
  perpDir2->m_quad = _mm_sub_ps(_mm_mul_ps(v37, v45), _mm_mul_ps(v26, v44));
  perpDir1->m_quad = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32((__m128i)_mm_shuffle_ps(c1->m_quad, c1->m_quad, 255), 0x1Fu),
                                 0x1Fu),
                       perpDir1->m_quad);
  perpDir2->m_quad = _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32((__m128i)_mm_shuffle_ps(c2->m_quad, c2->m_quad, 255), 0x1Fu),
                                 0x1Fu),
                       perpDir2->m_quad);
}

// File Line: 138
// RVA: 0xC134B0
void __fastcall hkaiEdgePathSteeringUtil::calcMutualTangentPoints(
        hkVector4f *aIn,
        hkVector4f *bIn,
        hkVector4f *up,
        hkVector4f *aTangentPoint)
{
  __m128 m_quad; // xmm3
  __m128 v6; // xmm8
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm7
  __m128 v12; // xmm4
  __m128 v13; // xmm8
  __m128 v14; // xmm0
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm0
  hkVector4f v22; // xmm0
  __m128 v23; // xmm4
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm6
  __m128 v27; // xmm1
  hkVector4f c1; // [rsp+48h] [rbp-61h] BYREF
  hkVector4f p1; // [rsp+58h] [rbp-51h] BYREF
  hkVector4f p2; // [rsp+68h] [rbp-41h] BYREF
  hkVector4f perpDir1; // [rsp+78h] [rbp-31h] BYREF
  hkVector4f perpDir2; // [rsp+88h] [rbp-21h] BYREF
  hkVector4f tangentDir2; // [rsp+98h] [rbp-11h] BYREF
  hkVector4f v34; // [rsp+A8h] [rbp-1h] BYREF
  __m128 *v35; // [rsp+128h] [rbp+7Fh]

  m_quad = up->m_quad;
  v6 = bIn->m_quad;
  v7 = _mm_mul_ps(up->m_quad, aIn->m_quad);
  v8 = _mm_shuffle_ps(aIn->m_quad, aIn->m_quad, 255);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v10 = _mm_mul_ps(bIn->m_quad, up->m_quad);
  v11 = _mm_sub_ps(aIn->m_quad, _mm_mul_ps(v9, up->m_quad));
  v12 = _mm_shuffle_ps(v6, v6, 255);
  p1.m_quad = v11;
  v13 = _mm_sub_ps(
          v6,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
              _mm_shuffle_ps(v10, v10, 170)),
            m_quad));
  c1.m_quad = v13;
  if ( v8.m128_f32[0] == (float)(0.0 - v12.m128_f32[0]) )
  {
    v14 = _mm_sub_ps(v13, v11);
    v15 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v14),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), m_quad));
    v16 = _mm_shuffle_ps(v15, v15, 201);
    v17 = _mm_mul_ps(v16, v16);
    v18 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
            _mm_shuffle_ps(v17, v17, 170));
    v19 = _mm_rsqrt_ps(v18);
    v20 = _mm_mul_ps(
            _mm_mul_ps(
              v16,
              _mm_andnot_ps(
                _mm_cmple_ps(v18, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                  _mm_mul_ps(*(__m128 *)_xmm, v19)))),
            v8);
    aTangentPoint->m_quad = _mm_add_ps(v20, v11);
    *v35 = _mm_add_ps(v20, v13);
  }
  else if ( v8.m128_f32[0] == 0.0 )
  {
    hkaiEdgePathSteeringUtil::calcTangentDirs(&p1, &p1, &c1, &c1, up, &p2, &tangentDir2, &perpDir1, &perpDir2);
    v21 = p2.m_quad;
    *aTangentPoint = (hkVector4f)v11;
    *v35 = _mm_add_ps(v21, v11);
  }
  else if ( v12.m128_f32[0] == 0.0 )
  {
    hkaiEdgePathSteeringUtil::calcTangentDirs(&c1, &c1, &p1, &p1, up, &p2, &perpDir1, &perpDir2, &tangentDir2);
    v22.m_quad = _mm_add_ps(p2.m_quad, v13);
    *v35 = v13;
    *aTangentPoint = (hkVector4f)v22.m_quad;
  }
  else
  {
    v23 = _mm_add_ps(v12, v8);
    v24 = _mm_rcp_ps(v23);
    v25 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v24)), v24), v8);
    v26 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v13, v11), v25), v11);
    p2.m_quad = v26;
    p1.m_quad = _mm_shuffle_ps(
                  v11,
                  _mm_unpackhi_ps(
                    v11,
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(v25, (__m128)0i64), 0x1Fu), 0x1Fu),
                      _mm_shuffle_ps(v11, v11, 255))),
                  196);
    c1.m_quad = _mm_shuffle_ps(
                  v13,
                  _mm_unpackhi_ps(
                    v13,
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(query.m_quad, v25), 0x1Fu), 0x1Fu),
                      _mm_shuffle_ps(v13, v13, 255))),
                  196);
    hkaiEdgePathSteeringUtil::calcTangentDirs(&p2, &p2, &p1, &c1, up, &perpDir1, &perpDir2, &v34, &tangentDir2);
    v27 = perpDir2.m_quad;
    aTangentPoint->m_quad = _mm_add_ps(perpDir1.m_quad, v26);
    *v35 = _mm_add_ps(v27, v26);
  }
}

// File Line: 186
// RVA: 0xBECE20
__int64 __fastcall hkaiEdgePathSteeringUtil::inCapsule(hkVector4f *p, hkVector4f *c1, hkVector4f *c2, hkVector4f *up)
{
  __m128 v4; // xmm5
  __m128 v5; // xmm8
  __m128 v6; // xmm1
  float v7; // xmm7_4
  __m128 v8; // xmm8
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm5
  float v19; // xmm10_4
  __m128 v20; // xmm1
  __int64 result; // rax
  __m128 v22; // xmm5
  __m128 v23; // xmm5

  v4 = _mm_sub_ps(p->m_quad, c1->m_quad);
  v5 = _mm_sub_ps(c2->m_quad, c1->m_quad);
  v6 = _mm_mul_ps(up->m_quad, v5);
  v7 = _mm_shuffle_ps(c1->m_quad, c1->m_quad, 255).m128_f32[0];
  v8 = _mm_sub_ps(
         v5,
         _mm_mul_ps(
           _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170)),
           up->m_quad));
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_mul_ps(up->m_quad, v4);
  v12 = _mm_rcp_ps(v10);
  v13 = _mm_sub_ps(
          v4,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170)),
            up->m_quad));
  v14 = _mm_mul_ps(v8, v13);
  v15 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170)),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v12)), v12));
  v16 = _mm_cmplt_ps(v15, query.m_quad);
  v17 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v15, v16), _mm_andnot_ps(v16, query.m_quad)));
  v18 = _mm_sub_ps(v13, _mm_mul_ps(v8, v17));
  v19 = (float)((float)((float)(0.0 - _mm_shuffle_ps(c2->m_quad, c2->m_quad, 255).m128_f32[0]) - v7) * v17.m128_f32[0])
      + v7;
  v20 = _mm_mul_ps(up->m_quad, v18);
  result = 0i64;
  v22 = _mm_sub_ps(
          v18,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
              _mm_shuffle_ps(v20, v20, 170)),
            up->m_quad));
  v23 = _mm_mul_ps(v22, v22);
  if ( (float)((float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
             + _mm_shuffle_ps(v23, v23, 170).m128_f32[0]) < (float)(v19 * v19) )
    return 1i64;
  return result;
}

