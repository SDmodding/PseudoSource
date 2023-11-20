// File Line: 29
// RVA: 0xDFEA50
void __fastcall hkpCvxCvxDistByHeuristicSamplingPerformSample(hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkTransformf *aTb, hkVector4f *direction, hkpCvxCvxDistByHeuristicSamplingSample *sampleOut)
{
  hkTransformf *v5; // rdi
  hkBaseObjectVtbl *v6; // rax
  hkpConvexShape *v7; // rbx
  hkVector4f *v8; // rsi
  hkBaseObjectVtbl *v9; // rax
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  hkcdVertex v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // [rsp+20h] [rbp-48h]
  __m128 v17; // [rsp+30h] [rbp-38h]
  __m128 v18; // [rsp+40h] [rbp-28h]
  hkcdVertex v19; // [rsp+50h] [rbp-18h]

  v5 = aTb;
  v6 = shapeA->vfptr;
  v7 = shapeB;
  v8 = direction;
  v16 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), direction->m_quad);
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, hkcdVertex *))v6[4].__vecDelDtor)(shapeA, &v16, &v19);
  v9 = v7->vfptr;
  v10 = v5->m_rotation.m_col2.m_quad;
  v11 = _mm_unpacklo_ps(v5->m_rotation.m_col0.m_quad, v5->m_rotation.m_col1.m_quad);
  v12 = _mm_movelh_ps(v11, v10);
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v8->m_quad, v8->m_quad, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v10, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v8->m_quad, v8->m_quad, 0), v12)),
          _mm_mul_ps(
            _mm_shuffle_ps(v8->m_quad, v8->m_quad, 170),
            _mm_shuffle_ps(_mm_unpackhi_ps(v5->m_rotation.m_col0.m_quad, v5->m_rotation.m_col1.m_quad), v10, 228)));
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, __m128 *))v9[4].__vecDelDtor)(v7, &v17, &v18);
  v13.m_quad = v18;
  v14 = _mm_mul_ps(
          _mm_sub_ps(
            v19.m_quad,
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v5->m_rotation.m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v5->m_rotation.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v5->m_rotation.m_col2.m_quad)),
              v5->m_translation.m_quad)),
          v8->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  if ( v15.m128_f32[0] > COERCE_FLOAT(
                           _mm_shuffle_ps(
                             sampleOut->m_separatingNormalA.m_quad,
                             sampleOut->m_separatingNormalA.m_quad,
                             255)) )
  {
    sampleOut->m_vertexAinA = (hkcdVertex)v19.m_quad;
    sampleOut->m_vertexBinB = (hkcdVertex)v13.m_quad;
    sampleOut->m_separatingNormalA.m_quad = _mm_shuffle_ps(v8->m_quad, _mm_unpackhi_ps(v8->m_quad, v15), 196);
  }
}

// File Line: 52
// RVA: 0xDFE640
void __fastcall hkpCvxCvxDistByHeuristicSampling(hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkTransformf *btoa, hkcdVertex *pointAinAOut, hkcdVertex *pointBinBOut, hkpGskOut *output)
{
  hkcdVertex *v6; // r12
  hkTransformf *v7; // rdi
  hkpConvexShape *v8; // rsi
  hkpConvexShape *v9; // r14
  hkVector4f *v10; // rbx
  __m128i v11; // xmm12
  signed __int64 v12; // r15
  __m128 v13; // xmm7
  __m128 v14; // xmm6
  __m128 v15; // xmm13
  __m128 v16; // xmm10
  float v17; // xmm11_4
  __m128 v18; // xmm13
  __m128 v19; // xmm7
  __m128 v20; // xmm5
  __m128 v21; // xmm7
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm7
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm7
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm7
  __m128 v33; // xmm6
  __m128 v34; // xmm5
  __m128 v35; // xmm1
  __m128 v36; // xmm1
  __m128 v37; // xmm7
  __m128 v38; // xmm8
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __int128 v44; // xmm2
  __int128 v45; // xmm0
  hkVector4f direction; // [rsp+40h] [rbp-98h]
  char sampleOut[24]; // [rsp+50h] [rbp-88h]
  __int128 v48; // [rsp+68h] [rbp-70h]
  __m128 v49; // [rsp+78h] [rbp-60h]
  int vars0; // [rsp+170h] [rbp+98h]
  __int128 *retaddr; // [rsp+178h] [rbp+A0h]
  __int64 v52; // [rsp+180h] [rbp+A8h]

  v6 = pointAinAOut;
  v7 = btoa;
  v8 = shapeB;
  v9 = shapeA;
  v10 = &transform;
  v11 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v12 = 3i64;
  *(_OWORD *)&sampleOut[8] = 0i64;
  v48 = 0i64;
  v49 = _mm_shuffle_ps((__m128)0i64, _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A712F0), 196);
  v13 = (__m128)_mm_shuffle_epi32(v11, 0);
  do
  {
    direction.m_quad = v10->m_quad;
    v14 = direction.m_quad;
    ++v10;
    hkpCvxCvxDistByHeuristicSamplingPerformSample(
      v9,
      v8,
      v7,
      &direction,
      (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
    direction.m_quad = _mm_xor_ps(v13, v14);
    hkpCvxCvxDistByHeuristicSamplingPerformSample(
      v9,
      v8,
      v7,
      &direction,
      (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
    --v12;
  }
  while ( v12 );
  v15 = query.m_quad;
  vars0 = 981668463;
  if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0)) < 1.0 )
  {
    vars0 = 981668463;
    v16 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99000001), (__m128)LODWORD(FLOAT_0_99000001), 0);
    LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
    do
    {
      v18 = _mm_mul_ps(v15, v16);
      v19 = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, (__m128)0i64), 196);
      v20 = _mm_shuffle_ps(v19, v19, 241);
      v21 = _mm_shuffle_ps(v19, v19, 206);
      v22 = _mm_mul_ps(v21, v21);
      v23 = _mm_mul_ps(v20, v20);
      v24 = _mm_cmpltps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                _mm_shuffle_ps(v23, v23, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170)));
      v25 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v21, v24), _mm_andnot_ps(v24, v20)), (__m128)v11);
      v26 = _mm_mul_ps(v25, v25);
      v27 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
              _mm_shuffle_ps(v26, v26, 170));
      v28 = _mm_rsqrt_ps(v27);
      v29 = _mm_mul_ps(
              v25,
              _mm_andnot_ps(
                _mm_cmpleps(v27, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                  _mm_mul_ps(*(__m128 *)_xmm, v28))));
      v30 = _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v29);
      v31 = _mm_shuffle_ps(v29, v29, 201);
      v32 = _mm_mul_ps(v29, v18);
      v33 = _mm_sub_ps(v49, v32);
      v34 = _mm_add_ps(v32, v49);
      v35 = _mm_sub_ps(_mm_mul_ps(v31, v49), v30);
      v36 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v18);
      v37 = _mm_add_ps(v36, v49);
      v38 = _mm_sub_ps(v49, v36);
      v39 = _mm_mul_ps(v34, v34);
      v40 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
              _mm_shuffle_ps(v39, v39, 170));
      v41 = _mm_rsqrt_ps(v40);
      v42 = _mm_andnot_ps(
              _mm_cmpleps(v40, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                _mm_mul_ps(*(__m128 *)_xmm, v41)));
      direction.m_quad = _mm_mul_ps(v34, v42);
      *(__m128 *)sampleOut = _mm_mul_ps(v33, v42);
      *(__m128 *)&sampleOut[16] = _mm_mul_ps(v37, v42);
      *(__int128 *)((char *)&v48 + 8) = (__int128)_mm_mul_ps(v38, v42);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        v9,
        v8,
        v7,
        &direction,
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        v9,
        v8,
        v7,
        (hkVector4f *)sampleOut,
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        v9,
        v8,
        v7,
        (hkVector4f *)&sampleOut[16],
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        v9,
        v8,
        v7,
        (hkVector4f *)((char *)&v48 + 8),
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      v15 = _mm_mul_ps(v18, (__m128)xmmword_141A711B0);
    }
    while ( v15.m128_f32[0] > v17 );
  }
  v43 = v49;
  v44 = *(_OWORD *)&sampleOut[8];
  v45 = v48;
  *v6 = *(hkcdVertex *)&sampleOut[8];
  *retaddr = v45;
  *(_DWORD *)(v52 + 32) = (unsigned __int128)_mm_shuffle_ps(v43, v43, 255);
  *(__m128 *)v52 = v43;
  *(_OWORD *)(v52 + 16) = v44;
}

