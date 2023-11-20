// File Line: 20
// RVA: 0xC137A0
void __fastcall hkaiEdgePathSteeringUtil::calcTangentDirs(hkVector4f *p1, hkVector4f *p2, hkVector4f *c1, hkVector4f *c2, hkVector4f *up, hkVector4f *tangentDir1, hkVector4f *tangentDir2, hkVector4f *perpDir1, hkVector4f *perpDir2)
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
  __m128 v37; // xmm0
  __m128 v38; // xmm6
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
          _mm_cmpleps(v21, (__m128)0i64),
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
  v37 = _mm_cmpleps(v34, (__m128)0i64);
  v38 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v28, 0x1Fu), 0x1Fu), _mm_shuffle_ps(v36, v36, 201));
  v39 = _mm_or_ps(
          _mm_andnot_ps(v37, _mm_mul_ps(_mm_shuffle_ps(v33, v34, 228), v34)),
          _mm_and_ps(v37, `hkaiEdgePathSteeringUtil::calcTangentDirs'::`2'::insideLenFactorsQuad));
  v40 = _mm_rsqrt_ps(v39);
  v41 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v39, (__m128)0i64),
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
  tangentDir2->m_quad = _mm_add_ps(_mm_mul_ps(v26, v45), _mm_mul_ps(v38, v44));
  perpDir1->m_quad = _mm_sub_ps(_mm_mul_ps(v35, v43), _mm_mul_ps(v25, v42));
  perpDir2->m_quad = _mm_sub_ps(_mm_mul_ps(v38, v45), _mm_mul_ps(v26, v44));
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
void __fastcall hkaiEdgePathSteeringUtil::calcMutualTangentPoints(hkVector4f *aIn, hkVector4f *bIn, hkVector4f *up, hkVector4f *aTangentPoint)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm4
  hkVector4f *v6; // rbx
  __m128 v7; // xmm6
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  __m128 v10; // xmm1
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm7
  __m128 v15; // xmm4
  __m128 v16; // xmm8
  __m128 v17; // xmm0
  __m128 v18; // xmm5
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm0
  __m128 v25; // xmm0
  __m128 v26; // xmm4
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  __m128 v29; // xmm6
  __m128 v30; // xmm1
  hkVector4f c1; // [rsp+48h] [rbp-61h]
  hkVector4f p1; // [rsp+58h] [rbp-51h]
  hkVector4f p2; // [rsp+68h] [rbp-41h]
  hkVector4f perpDir1; // [rsp+78h] [rbp-31h]
  hkVector4f perpDir2; // [rsp+88h] [rbp-21h]
  hkVector4f tangentDir2; // [rsp+98h] [rbp-11h]
  hkVector4f v37; // [rsp+A8h] [rbp-1h]
  __m128 *v38; // [rsp+128h] [rbp+7Fh]

  v4 = up->m_quad;
  v5 = bIn->m_quad;
  v6 = aTangentPoint;
  v7 = aIn->m_quad;
  v8 = v7;
  v9 = v5;
  v10 = _mm_mul_ps(up->m_quad, aIn->m_quad);
  v11 = _mm_shuffle_ps(v7, v7, 255);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v13 = _mm_mul_ps(bIn->m_quad, up->m_quad);
  v14 = _mm_sub_ps(v8, _mm_mul_ps(v12, up->m_quad));
  v15 = _mm_shuffle_ps(v5, v5, 255);
  p1.m_quad = v14;
  v16 = _mm_sub_ps(
          v9,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170)),
            v4));
  c1.m_quad = v16;
  if ( v11.m128_f32[0] == (float)(0.0 - v15.m128_f32[0]) )
  {
    v17 = _mm_sub_ps(v16, v14);
    v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v17), _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v4));
    v19 = _mm_shuffle_ps(v18, v18, 201);
    v20 = _mm_mul_ps(v19, v19);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    v22 = _mm_rsqrt_ps(v21);
    v23 = _mm_mul_ps(
            _mm_mul_ps(
              v19,
              _mm_andnot_ps(
                _mm_cmpleps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                  _mm_mul_ps(*(__m128 *)_xmm, v22)))),
            v11);
    aTangentPoint->m_quad = _mm_add_ps(v23, v14);
    *v38 = _mm_add_ps(v23, v16);
  }
  else if ( v11.m128_f32[0] == 0.0 )
  {
    hkaiEdgePathSteeringUtil::calcTangentDirs(&p1, &p1, &c1, &c1, up, &p2, &tangentDir2, &perpDir1, &perpDir2);
    v24 = p2.m_quad;
    *v6 = (hkVector4f)v14;
    *v38 = _mm_add_ps(v24, v14);
  }
  else if ( v15.m128_f32[0] == 0.0 )
  {
    hkaiEdgePathSteeringUtil::calcTangentDirs(&c1, &c1, &p1, &p1, up, &p2, &perpDir1, &perpDir2, &tangentDir2);
    v25 = _mm_add_ps(p2.m_quad, v16);
    *v38 = v16;
    *v6 = (hkVector4f)v25;
  }
  else
  {
    v26 = _mm_add_ps(v15, v11);
    v27 = _mm_rcp_ps(v26);
    v28 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v27)), v27), v11);
    v29 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16, v14), v28), v14);
    p2.m_quad = v29;
    p1.m_quad = _mm_shuffle_ps(
                  v14,
                  _mm_unpackhi_ps(
                    v14,
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v28, (__m128)0i64), 0x1Fu), 0x1Fu),
                      _mm_shuffle_ps(v14, v14, 255))),
                  196);
    c1.m_quad = _mm_shuffle_ps(
                  v16,
                  _mm_unpackhi_ps(
                    v16,
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(query.m_quad, v28), 0x1Fu), 0x1Fu),
                      _mm_shuffle_ps(v16, v16, 255))),
                  196);
    hkaiEdgePathSteeringUtil::calcTangentDirs(&p2, &p2, &p1, &c1, up, &perpDir1, &perpDir2, &v37, &tangentDir2);
    v30 = perpDir2.m_quad;
    v6->m_quad = _mm_add_ps(perpDir1.m_quad, v29);
    *v38 = _mm_add_ps(v30, v29);
  }
}

// File Line: 186
// RVA: 0xBECE20
signed __int64 __fastcall hkaiEdgePathSteeringUtil::inCapsule(hkVector4f *p, hkVector4f *c1, hkVector4f *c2, hkVector4f *up)
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
  signed __int64 result; // rax
  __m128 v22; // xmm5
  __m128 v23; // xmm5

  v4 = _mm_sub_ps(p->m_quad, c1->m_quad);
  v5 = _mm_sub_ps(c2->m_quad, c1->m_quad);
  v6 = _mm_mul_ps(up->m_quad, v5);
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps(c1->m_quad, c1->m_quad, 255);
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
  v16 = _mm_cmpltps(v15, query.m_quad);
  v17 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v15, v16), _mm_andnot_ps(v16, query.m_quad)));
  v18 = _mm_sub_ps(v13, _mm_mul_ps(v8, v17));
  v19 = (float)((float)((float)(0.0 - COERCE_FLOAT(_mm_shuffle_ps(c2->m_quad, c2->m_quad, 255))) - v7) * v17.m128_f32[0])
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
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170))) < (float)(v19 * v19) )
    result = 1i64;
  return result;
}

