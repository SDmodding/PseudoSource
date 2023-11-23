// File Line: 29
// RVA: 0xDFEA50
void __fastcall hkpCvxCvxDistByHeuristicSamplingPerformSample(
        hkpConvexShape *shapeA,
        hkpConvexShape *shapeB,
        hkTransformf *aTb,
        hkVector4f *direction,
        hkpCvxCvxDistByHeuristicSamplingSample *sampleOut)
{
  hkBaseObjectVtbl *vfptr; // rax
  hkBaseObjectVtbl *v9; // rax
  hkVector4f v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  hkcdVertex v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // [rsp+20h] [rbp-48h] BYREF
  __m128 v17; // [rsp+30h] [rbp-38h] BYREF
  __m128 v18; // [rsp+40h] [rbp-28h] BYREF
  __m128 v19; // [rsp+50h] [rbp-18h] BYREF

  vfptr = shapeA->vfptr;
  v16 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), direction->m_quad);
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, __m128 *))vfptr[4].__vecDelDtor)(shapeA, &v16, &v19);
  v9 = shapeB->vfptr;
  v10.m_quad = (__m128)aTb->m_rotation.m_col2;
  v11 = _mm_unpacklo_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad);
  v12 = _mm_movelh_ps(v11, v10.m_quad);
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v10.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 0), v12)),
          _mm_mul_ps(
            _mm_shuffle_ps(direction->m_quad, direction->m_quad, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad),
              v10.m_quad,
              228)));
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, __m128 *))v9[4].__vecDelDtor)(shapeB, &v17, &v18);
  v13.m_quad = v18;
  v14 = _mm_mul_ps(
          _mm_sub_ps(
            v19,
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), aTb->m_rotation.m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), aTb->m_rotation.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), aTb->m_rotation.m_col2.m_quad)),
              aTb->m_translation.m_quad)),
          direction->m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  if ( v15.m128_f32[0] > _mm_shuffle_ps(
                           sampleOut->m_separatingNormalA.m_quad,
                           sampleOut->m_separatingNormalA.m_quad,
                           255).m128_f32[0] )
  {
    sampleOut->m_vertexAinA.m_quad = v19;
    sampleOut->m_vertexBinB = (hkcdVertex)v13.m_quad;
    sampleOut->m_separatingNormalA.m_quad = _mm_shuffle_ps(
                                              direction->m_quad,
                                              _mm_unpackhi_ps(direction->m_quad, v15),
                                              196);
  }
}

// File Line: 52
// RVA: 0xDFE640
void __fastcall hkpCvxCvxDistByHeuristicSampling(
        hkpConvexShape *shapeA,
        hkpConvexShape *shapeB,
        hkTransformf *btoa,
        hkcdVertex *pointAinAOut,
        hkcdVertex *pointBinBOut,
        hkpGskOut *output)
{
  __int64 v6; // rbx
  hkVector4f *v11; // rbx
  __m128i inserted; // xmm12
  __int64 v13; // r15
  __m128 v14; // xmm7
  __m128 m_quad; // xmm6
  __m128 v16; // xmm13
  __m128 v17; // xmm10
  float v18; // xmm11_4
  __m128 v19; // xmm13
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128 v22; // xmm7
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm7
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm7
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm7
  __m128 v34; // xmm6
  __m128 v35; // xmm5
  __m128 v36; // xmm1
  __m128 v37; // xmm1
  __m128 v38; // xmm7
  __m128 v39; // xmm8
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __int128 v45; // xmm2
  __int128 v46; // xmm0
  hkVector4f direction; // [rsp+40h] [rbp-98h] BYREF
  _BYTE sampleOut[56]; // [rsp+50h] [rbp-88h] BYREF
  int vars0; // [rsp+170h] [rbp+98h]
  _OWORD *retaddr; // [rsp+178h] [rbp+A0h]
  __int64 v51; // [rsp+180h] [rbp+A8h]

  v51 = v6;
  v11 = &transform;
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v13 = 3i64;
  memset(&sampleOut[8], 0, 32);
  *(__m128 *)&sampleOut[40] = _mm_shuffle_ps(
                                (__m128)0i64,
                                _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A712F0),
                                196);
  v14 = (__m128)_mm_shuffle_epi32(inserted, 0);
  do
  {
    direction.m_quad = v11->m_quad;
    m_quad = direction.m_quad;
    ++v11;
    hkpCvxCvxDistByHeuristicSamplingPerformSample(
      shapeA,
      shapeB,
      btoa,
      &direction,
      (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
    direction.m_quad = _mm_xor_ps(v14, m_quad);
    hkpCvxCvxDistByHeuristicSamplingPerformSample(
      shapeA,
      shapeB,
      btoa,
      &direction,
      (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
    --v13;
  }
  while ( v13 );
  v16 = query.m_quad;
  vars0 = 981668463;
  if ( _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0).m128_f32[0] < 1.0 )
  {
    vars0 = 981668463;
    v17 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99000001), (__m128)LODWORD(FLOAT_0_99000001), 0);
    LODWORD(v18) = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0).m128_u32[0];
    do
    {
      v19 = _mm_mul_ps(v16, v17);
      v20 = _mm_shuffle_ps(*(__m128 *)&sampleOut[40], _mm_unpackhi_ps(*(__m128 *)&sampleOut[40], (__m128)0i64), 196);
      v21 = _mm_shuffle_ps(v20, v20, 241);
      v22 = _mm_shuffle_ps(v20, v20, 206);
      v23 = _mm_mul_ps(v22, v22);
      v24 = _mm_mul_ps(v21, v21);
      v25 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                _mm_shuffle_ps(v23, v23, 170)));
      v26 = _mm_xor_ps(_mm_or_ps(_mm_and_ps(v22, v25), _mm_andnot_ps(v25, v21)), (__m128)inserted);
      v27 = _mm_mul_ps(v26, v26);
      v28 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
              _mm_shuffle_ps(v27, v27, 170));
      v29 = _mm_rsqrt_ps(v28);
      v30 = _mm_mul_ps(
              v26,
              _mm_andnot_ps(
                _mm_cmple_ps(v28, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                  _mm_mul_ps(*(__m128 *)_xmm, v29))));
      v31 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&sampleOut[40], *(__m128 *)&sampleOut[40], 201), v30);
      v32 = _mm_shuffle_ps(v30, v30, 201);
      v33 = _mm_mul_ps(v30, v19);
      v34 = _mm_sub_ps(*(__m128 *)&sampleOut[40], v33);
      v35 = _mm_add_ps(v33, *(__m128 *)&sampleOut[40]);
      v36 = _mm_sub_ps(_mm_mul_ps(v32, *(__m128 *)&sampleOut[40]), v31);
      v37 = _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v19);
      v38 = _mm_add_ps(v37, *(__m128 *)&sampleOut[40]);
      v39 = _mm_sub_ps(*(__m128 *)&sampleOut[40], v37);
      v40 = _mm_mul_ps(v35, v35);
      v41 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
              _mm_shuffle_ps(v40, v40, 170));
      v42 = _mm_rsqrt_ps(v41);
      v43 = _mm_andnot_ps(
              _mm_cmple_ps(v41, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v42, v41), v42)),
                _mm_mul_ps(*(__m128 *)_xmm, v42)));
      direction.m_quad = _mm_mul_ps(v35, v43);
      *(__m128 *)sampleOut = _mm_mul_ps(v34, v43);
      *(__m128 *)&sampleOut[16] = _mm_mul_ps(v38, v43);
      *(__m128 *)&sampleOut[32] = _mm_mul_ps(v39, v43);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        shapeA,
        shapeB,
        btoa,
        &direction,
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        shapeA,
        shapeB,
        btoa,
        (hkVector4f *)sampleOut,
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        shapeA,
        shapeB,
        btoa,
        (hkVector4f *)&sampleOut[16],
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      hkpCvxCvxDistByHeuristicSamplingPerformSample(
        shapeA,
        shapeB,
        btoa,
        (hkVector4f *)&sampleOut[32],
        (hkpCvxCvxDistByHeuristicSamplingSample *)&sampleOut[8]);
      v16 = _mm_mul_ps(v19, (__m128)xmmword_141A711B0);
    }
    while ( v16.m128_f32[0] > v18 );
  }
  v44 = *(__m128 *)&sampleOut[40];
  v45 = *(_OWORD *)&sampleOut[8];
  v46 = *(_OWORD *)&sampleOut[24];
  *pointAinAOut = *(hkcdVertex *)&sampleOut[8];
  *retaddr = v46;
  *(_DWORD *)(v51 + 32) = _mm_shuffle_ps(v44, v44, 255).m128_u32[0];
  *(__m128 *)v51 = v44;
  *(_OWORD *)(v51 + 16) = v45;
}

