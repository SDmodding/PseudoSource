// File Line: 16
// RVA: 0xB440C0
hkQsTransformf *__fastcall hkaParameterizeAnimationUtil::sampleReferenceFrame(hkQsTransformf *result, float sampleTime, hkQsTransformf *t, int numT, float duration)
{
  __int64 v5; // r9
  __m128 v6; // xmm0
  __m128 v7; // xmm7
  signed int v8; // er11
  hkQsTransformf *v9; // rax
  hkQuaternionf v10; // xmm1
  hkVector4f v11; // xmm0
  __m128 v12; // xmm0
  __m128 v13; // xmm7
  __m128 v14; // xmm0
  hkVector4f v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2

  v5 = (unsigned int)(numT - 1);
  v6 = 0i64;
  v6.m128_f32[0] = (float)(signed int)v5;
  v7 = _mm_mul_ps(
         _mm_shuffle_ps(
           (__m128)COERCE_UNSIGNED_INT(sampleTime / duration),
           (__m128)COERCE_UNSIGNED_INT(sampleTime / duration),
           0),
         _mm_shuffle_ps(v6, v6, 0));
  v8 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v7));
  if ( v8 <= (unsigned int)(v5 - 1) )
  {
    v12 = 0i64;
    v12.m128_f32[0] = (float)v8;
    v9 = result;
    v13 = _mm_sub_ps(v7, _mm_shuffle_ps(v12, v12, 0));
    v14 = _mm_mul_ps(t[v8 + 1].m_rotation.m_vec.m_quad, t[v8].m_rotation.m_vec.m_quad);
    v15.m_quad = _mm_add_ps(
                   _mm_mul_ps(_mm_sub_ps(t[v8 + 1].m_scale.m_quad, t[v8].m_scale.m_quad), v13),
                   t[v8].m_scale.m_quad);
    result->m_translation.m_quad = _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps(t[v8 + 1].m_translation.m_quad, t[v8].m_translation.m_quad),
                                       v13),
                                     t[v8].m_translation.m_quad);
    v16 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
    v17 = _mm_add_ps(
            _mm_mul_ps(
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(
                          _mm_srli_epi32(
                            (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16), (__m128)0i64),
                            0x1Fu),
                          0x1Fu),
                v13),
              t[v8 + 1].m_rotation.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(query.m_quad, v13), t[v8].m_rotation.m_vec.m_quad));
    v18 = _mm_mul_ps(v17, v17);
    v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
    v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
    v21 = _mm_rsqrt_ps(v20);
    result->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                        v17,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v21)));
    result->m_scale = (hkVector4f)v15.m_quad;
  }
  else
  {
    v9 = result;
    v10.m_vec.m_quad = (__m128)t[v5].m_rotation;
    result->m_translation = t[v5].m_translation;
    v11.m_quad = (__m128)t[v5].m_scale;
    result->m_rotation = (hkQuaternionf)v10.m_vec.m_quad;
    result->m_scale = (hkVector4f)v11.m_quad;
  }
  return v9;
}

// File Line: 35
// RVA: 0xB44250
void __fastcall hkaParameterizeAnimationUtil::project(hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *options, hkQsTransformf *rootMotion, hkQsTransformf *projectionOut)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f *v5; // rdi
  hkQsTransformf *v6; // rbx
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  hkSimdFloat32 angleOut; // [rsp+20h] [rbp-38h]
  hkQuaternionf restOut; // [rsp+30h] [rbp-28h]

  v3.m_quad = (__m128)options->m_up;
  v4.m_quad = (__m128)options->m_forward;
  v5 = &options->m_up;
  v6 = projectionOut;
  v7 = _mm_mul_ps(rootMotion->m_translation.m_quad, v3.m_quad);
  v8 = _mm_mul_ps(
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170)),
         v3.m_quad);
  v9 = _mm_mul_ps(rootMotion->m_translation.m_quad, v4.m_quad);
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 201), v3.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(options->m_up.m_quad, v3.m_quad, 201), v4.m_quad));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(rootMotion->m_translation.m_quad, v11);
  v13 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170)),
          v11);
  projectionOut->m_translation = 0i64;
  v14 = _mm_mul_ps(
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)),
          v4.m_quad);
  if ( options->m_allowFrontBack.m_bool )
    projectionOut->m_translation.m_quad = _mm_add_ps((__m128)0i64, v14);
  if ( options->m_allowUpDown.m_bool )
    projectionOut->m_translation.m_quad = _mm_add_ps(v8, projectionOut->m_translation.m_quad);
  if ( options->m_allowRightLeft.m_bool )
    projectionOut->m_translation.m_quad = _mm_add_ps(v13, projectionOut->m_translation.m_quad);
  if ( options->m_allowTurning.m_bool )
  {
    hkQuaternionf::decomposeRestAxis(&rootMotion->m_rotation, v5, &restOut, &angleOut);
    hkQuaternionf::setAxisAngle(&v6->m_rotation, v5, &angleOut);
  }
  else
  {
    projectionOut->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  }
}

// File Line: 84
// RVA: 0xB44380
void __usercall hkaParameterizeAnimationUtil::computeLinearSpeed(hkaAnimatedReferenceFrame *referenceFrame@<rcx>, float *linearSpeedOut@<rdx>, unsigned int a3@<xmm0>)
{
  float *v3; // rsi
  hkaAnimatedReferenceFrame *v4; // rdi
  hkBaseObjectVtbl *v5; // rbx
  __int64 v6; // rdx
  __m128 v7; // xmm6
  __m128 v8; // xmm6
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  float v12; // xmm0_4
  __m128 v13; // [rsp+20h] [rbp-78h]
  __m128 v14; // [rsp+50h] [rbp-48h]

  v3 = linearSpeedOut;
  v4 = referenceFrame;
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, float *, __m128 *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    linearSpeedOut,
    &v14);
  v5 = v4->vfptr;
  v4->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v4->vfptr);
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))v5[1].__first_virtual_table_function__)(
    v4,
    v6,
    &v13);
  v7 = _mm_sub_ps(v13, v14);
  v4->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v4->vfptr);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_shuffle_ps((__m128)a3, (__m128)a3, 0);
  v11 = _mm_rsqrt_ps(v9);
  LODWORD(v12) = (unsigned __int128)_mm_rcp_ps(v10);
  *v3 = (float)((float)(2.0 - (float)(v10.m128_f32[0] * v12)) * v12)
      * COERCE_FLOAT(
          _mm_andnot_ps(
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v9), v11)),
                _mm_mul_ps(*(__m128 *)_xmm, v11)),
              v9)));
}

// File Line: 98
// RVA: 0xB44480
void __fastcall hkaParameterizeAnimationUtil::computeLinearDirection(hkaAnimatedReferenceFrame *referenceFrame, hkVector4f *forwardAxis, hkVector4f *upAxis, float *linearDirectionOut)
{
  hkVector4f *v4; // r14
  float *v5; // rbp
  hkVector4f *v6; // rsi
  hkaAnimatedReferenceFrame *v7; // rdi
  hkBaseObjectVtbl *v8; // rbx
  __int64 v9; // rdx
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm9
  float v17; // xmm1_4
  __m128 v18; // xmm8
  __m128 v19; // xmm2
  __m128 v20; // xmm6
  __m128 v21; // xmm6
  __m128 v22; // xmm7
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm6
  hkQuaternionf v30; // [rsp+20h] [rbp-118h]
  hkSimdFloat32 angleOut; // [rsp+30h] [rbp-108h]
  hkQuaternionf restOut; // [rsp+40h] [rbp-F8h]
  __m128 v33; // [rsp+50h] [rbp-E8h]
  __m128 v34; // [rsp+80h] [rbp-B8h]

  v4 = upAxis;
  v5 = linearDirectionOut;
  v6 = forwardAxis;
  v7 = referenceFrame;
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, hkVector4f *, __m128 *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    forwardAxis,
    &v34);
  v8 = v7->vfptr;
  v7->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v7->vfptr);
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))v8[1].__first_virtual_table_function__)(
    v7,
    v9,
    &v33);
  v10 = _mm_sub_ps(v33, v34);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(
          v10,
          _mm_andnot_ps(
            _mm_cmpleps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13))));
  v15 = _mm_mul_ps(v6->m_quad, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(FLOAT_0_99998999),
                                      (__m128)LODWORD(FLOAT_0_99998999),
                                      0);
  if ( v16.m128_f32[0] <= v17 )
  {
    if ( v16.m128_f32[0] >= (float)(0.0 - v17) )
    {
      v18 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v16), (__m128)xmmword_141A711B0);
      v19 = _mm_rsqrt_ps(v18);
      v20 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v6->m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v6->m_quad, v6->m_quad, 201), v14));
      v21 = _mm_shuffle_ps(v20, v20, 201);
      v22 = _mm_andnot_ps(
              _mm_cmpleps(v18, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                _mm_mul_ps(*(__m128 *)_xmm, v19)));
      v23 = _mm_mul_ps(v22, (__m128)xmmword_141A711B0);
      if ( v16.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0)) )
      {
        v24 = _mm_mul_ps(v21, v21);
        v25 = _mm_sub_ps(v18, v16);
        v26 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170));
        v27 = _mm_rsqrt_ps(v26);
        v28 = _mm_rsqrt_ps(v25);
        v23 = _mm_mul_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v25, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v25), v28)),
                      _mm_mul_ps(*(__m128 *)_xmm, v28))),
                  v25),
                _mm_andnot_ps(
                  _mm_cmpleps(v26, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                    _mm_mul_ps(*(__m128 *)_xmm, v27))));
      }
      v29 = _mm_mul_ps(v21, v23);
      v30.m_vec.m_quad = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, _mm_mul_ps(v22, v18)), 196);
    }
    else
    {
      hkQuaternionf::setFlippedRotation(&v30, v6);
    }
  }
  else
  {
    v30.m_vec.m_quad = qi.m_vec.m_quad;
  }
  hkQuaternionf::decomposeRestAxis(&v30, v4, &restOut, &angleOut);
  *v5 = angleOut.m_real.m128_f32[0];
}

// File Line: 120
// RVA: 0xB44760
void __fastcall hkaParameterizeAnimationUtil::computeMovementDisplacement(hkaAnimatedReferenceFrame *referenceFrame, hkVector4f *rotationAxis, hkVector4f *outDirection)
{
  hkVector4f *v3; // rsi
  hkVector4f *v4; // rdi
  hkaAnimatedReferenceFrame *v5; // rbx
  __int64 v6; // rdx
  __int64 v7; // rdx
  __m128i v8; // xmm4
  __m128 v9; // xmm3
  int v10; // edx
  int v11; // edx
  __m128i v12; // xmm0
  __m128 v13; // [rsp+20h] [rbp-78h]
  __m128 v14; // [rsp+50h] [rbp-48h]

  v3 = outDirection;
  v4 = rotationAxis;
  v5 = referenceFrame;
  ((void (*)(void))referenceFrame->vfptr[2].__first_virtual_table_function__)();
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))v5->vfptr[1].__first_virtual_table_function__)(
    v5,
    v6,
    &v13);
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))v5->vfptr[1].__first_virtual_table_function__)(
    v5,
    v7,
    &v14);
  v8 = (__m128i)_mm_sub_ps(v14, v13);
  *v3 = (hkVector4f)v8;
  v9 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v4), 1u), 1u);
  v10 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v9, v9, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v9, v9, 85),
                                                                       _mm_shuffle_ps(v9, v9, 0))),
                                                                   v9),
                                                                 (__m128)xmmword_141A48D80))]
      - 1;
  if ( v10 )
  {
    v11 = v10 - 1;
    if ( v11 )
    {
      if ( v11 == 1 )
        v12 = _mm_srli_si128(_mm_slli_si128(v8, 4), 4);
      else
        v12 = _mm_slli_si128(_mm_srli_si128(v8, 4), 4);
      *v3 = (hkVector4f)v12;
    }
    else
    {
      v3->m_quad = _mm_shuffle_ps((__m128)v8, _mm_unpackhi_ps((__m128)v8, (__m128)0i64), 180);
    }
  }
  else
  {
    v3->m_quad = _mm_shuffle_ps(_mm_unpacklo_ps((__m128)v8, (__m128)0i64), (__m128)v8, 228);
  }
}

// File Line: 135
// RVA: 0xB44870
hkBool *__usercall hkaParameterizeAnimationUtil::computeTurnParameters@<rax>(hkBool *result@<rcx>, hkaAnimatedReferenceFrame *referenceFrame@<rdx>, const float sampleRate@<xmm2>, hkVector4f *sideAxis@<r9>, float a5@<xmm0>, hkVector4f *forwardAxis, hkVector4f *upAxis, float *outRotationAngle, float *outRadius, hkVector4f *outRadiusDir)
{
  hkBool *v10; // rsi
  hkaAnimatedReferenceFrame *v11; // r14
  int v12; // er12
  hkLifoAllocator *v13; // rax
  __int64 v14; // rdx
  hkVector4f *v15; // rbp
  int v16; // er13
  char *v17; // rcx
  int v18; // ebx
  __int64 v19; // r15
  int v20; // edi
  hkVector4f *v21; // rsi
  float *v22; // r15
  unsigned int v23; // ecx
  hkLifoAllocator *v24; // rax
  int v25; // er8
  hkBool *v26; // rax
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm12
  __m128 v30; // xmm2
  __m128 v31; // xmm4
  float v32; // xmm11_4
  __int64 v33; // rdx
  __m128 v34; // xmm6
  hkVector4f *v35; // rdi
  __int64 v36; // rsi
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm7
  float v42; // xmm6_4
  hkVector4f *v43; // rdi
  __m128 v44; // xmm1
  float *v45; // rax
  __m128 v46; // xmm1
  float v47; // xmm2_4
  hkLifoAllocator *v48; // rax
  int v49; // er8
  hkVector4f center; // [rsp+40h] [rbp-F8h]
  hkVector4f pointOut; // [rsp+50h] [rbp-E8h]
  hkVector4f v52; // [rsp+60h] [rbp-D8h]
  hkQuaternionf v53; // [rsp+70h] [rbp-C8h]
  hkBool *v54; // [rsp+140h] [rbp+8h]
  hkResult resulta; // [rsp+150h] [rbp+18h]
  hkVector4f *sideAxisa; // [rsp+158h] [rbp+20h]

  sideAxisa = sideAxis;
  v54 = result;
  v10 = result;
  v11 = referenceFrame;
  referenceFrame->vfptr[2].__first_virtual_table_function__((hkBaseObject *)referenceFrame);
  v12 = (signed int)(float)(a5 / sampleRate);
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkVector4f *)v13->m_cur;
  v16 = (16 * v12 + 127) & 0xFFFFFF80;
  v17 = (char *)v15 + v16;
  if ( v16 > v13->m_slabSize || v17 > v13->m_end )
    v15 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v13, v16);
  else
    v13->m_cur = v17;
  v18 = 0;
  v19 = v12;
  v20 = 0;
  if ( v12 > 0 )
  {
    v21 = v15;
    do
    {
      ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, hkVector4f *))v11->vfptr[1].__first_virtual_table_function__)(
        v11,
        v14,
        &v52);
      ++v20;
      *v21 = (hkVector4f)v52.m_quad;
      ++v21;
      --v19;
    }
    while ( v19 );
    v10 = v54;
  }
  v22 = outRadius;
  center.m_quad = 0i64;
  if ( hkaParameterizeAnimationUtil::fitCircle(&resulta, v15, v12, sideAxisa, forwardAxis, &center, outRadius)->m_enum == 1 )
  {
    v23 = hkMemoryRouter::s_memoryRouter.m_slotID;
    v10->m_bool = 0;
    v24 = (hkLifoAllocator *)TlsGetValue(v23);
    v25 = (v16 + 15) & 0xFFFFFFF0;
    if ( v16 > v24->m_slabSize || (char *)v15 + v25 != v24->m_cur || v24->m_firstNonLifoEnd == v15 )
    {
      hkLifoAllocator::slowBlockFree(v24, v15, v25);
      v26 = v10;
    }
    else
    {
      v24->m_cur = v15;
      v26 = v10;
    }
  }
  else
  {
    v27 = _mm_mul_ps(center.m_quad, center.m_quad);
    v28 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170));
    v29 = 0i64;
    v30 = _mm_rsqrt_ps(v28);
    v31 = _mm_cmpltps(v28, (__m128)xmmword_141A712D0);
    outRadiusDir->m_quad = _mm_or_ps(
                             _mm_andnot_ps(
                               v31,
                               _mm_mul_ps(
                                 center.m_quad,
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v28), v30)),
                                   _mm_mul_ps(v30, *(__m128 *)_xmm)))),
                             _mm_and_ps(v31, transform.m_quad));
    v32 = *v22;
    hkaParameterizeAnimationUtil::projectPointOntoCircle(v15, &center, *v22, &pointOut);
    if ( v12 > 1 )
    {
      v34 = pointOut.m_quad;
      v35 = v15 + 1;
      v36 = (unsigned int)(v12 - 1);
      do
      {
        hkaParameterizeAnimationUtil::projectPointOntoCircle(v35, &center, v32, &pointOut);
        ++v35;
        v37 = _mm_sub_ps(pointOut.m_quad, v34);
        v34 = pointOut.m_quad;
        v38 = _mm_mul_ps(v37, v37);
        v39 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                _mm_shuffle_ps(v38, v38, 170));
        v40 = _mm_rsqrt_ps(v39);
        v29 = _mm_add_ps(
                v29,
                _mm_andnot_ps(
                  _mm_cmpleps(v39, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v39), v40)),
                      _mm_mul_ps(v40, *(__m128 *)_xmm)),
                    v39)));
        --v36;
      }
      while ( v36 );
    }
    v41 = 0i64;
    v42 = 0.0;
    if ( v12 > 0 )
    {
      v43 = upAxis;
      do
      {
        ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, hkVector4f *))v11->vfptr[1].__first_virtual_table_function__)(
          v11,
          v33,
          &v52);
        hkQuaternionf::decomposeRestAxis(&v53, v43, (hkQuaternionf *)&pointOut, (hkSimdFloat32 *)&center);
        v44 = center.m_quad;
        if ( (float)(center.m_quad.m128_f32[0] - v42) > 3.1415927 )
        {
          do
            v44 = _mm_sub_ps(v44, (__m128)xmmword_141A713F0);
          while ( (float)(v44.m128_f32[0] - v42) > 3.1415927 );
          center.m_quad = v44;
        }
        if ( (float)(v44.m128_f32[0] - v42) < (float)(0.0 - 3.1415927) )
        {
          do
            v44 = _mm_add_ps(v44, (__m128)xmmword_141A713F0);
          while ( (float)(v44.m128_f32[0] - v42) < (float)(0.0 - 3.1415927) );
          center.m_quad = v44;
        }
        ++v18;
        v41 = _mm_add_ps(v41, v44);
        v42 = v44.m128_f32[0];
      }
      while ( v18 < v12 );
    }
    v45 = outRotationAngle;
    v46 = _mm_shuffle_ps((__m128)*(unsigned int *)v22, (__m128)*(unsigned int *)v22, 0);
    LODWORD(v47) = (unsigned __int128)_mm_rcp_ps(v46);
    v54->m_bool = 1;
    *v45 = COERCE_FLOAT(((unsigned int)*(_OWORD *)&_mm_cmpleps(v41, (__m128)0i64) >> 31 << 31) ^ query.m_quad.m128_i32[0])
         * (float)((float)((float)(2.0 - (float)(v47 * v46.m128_f32[0])) * v47) * v29.m128_f32[0]);
    v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v49 = (v16 + 15) & 0xFFFFFFF0;
    if ( v16 > v48->m_slabSize || (char *)v15 + v49 != v48->m_cur || v48->m_firstNonLifoEnd == v15 )
      hkLifoAllocator::slowBlockFree(v48, v15, v49);
    else
      v48->m_cur = v15;
    v26 = v54;
  }
  return v26;
}

// File Line: 205
// RVA: 0xB44CE0
void __fastcall hkaParameterizeAnimationUtil::computeTurnSpeed(float rotationAngleR, float radiusR, float durationR, float *outLinearSpeed, float *outAngularSpeed)
{
  float v5; // xmm5_4
  float v6; // xmm4_4
  __m128 v7; // xmm1
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // [rsp+28h] [rbp+10h]

  v10 = radiusR;
  LODWORD(v5) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(rotationAngleR), (__m128)LODWORD(rotationAngleR), 0);
  LODWORD(v6) = (unsigned int)(2 * LODWORD(v5)) >> 1;
  if ( v6 < COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0)) )
  {
    *outAngularSpeed = 0.0;
    *outLinearSpeed = radiusR;
  }
  else
  {
    v7 = _mm_shuffle_ps((__m128)LODWORD(durationR), (__m128)LODWORD(durationR), 0);
    LODWORD(v8) = (unsigned __int128)_mm_rcp_ps(v7);
    v9 = (float)(2.0 - (float)(v7.m128_f32[0] * v8)) * v8;
    *outAngularSpeed = v9 * v5;
    *outLinearSpeed = (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v10), (__m128)LODWORD(v10), 0)) * v6) * v9;
  }
}

// File Line: 227
// RVA: 0xB44D90
hkResult *__fastcall hkaParameterizeAnimationUtil::fitCircle(hkResult *result, hkVector4f *points, int numPoints, hkVector4f *sideAxis, hkVector4f *forwardAxis, hkVector4f *centerOut, float *radiusOut)
{
  hkVector4f *v7; // rbx
  hkResult *v8; // rdi
  __int64 v9; // r11
  __m128 v10; // xmm6
  hkVector4f *v11; // rax
  __int64 v12; // r10
  __m128 v13; // xmm15
  __m128 v14; // xmm1
  __m128 v15; // xmm9
  __m128 v16; // xmm7
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm8
  __m128 v20; // xmm12
  __m128 v21; // xmm0
  __m128 v22; // xmm13
  __m128 v23; // xmm10
  __m128 v24; // xmm11
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  __int64 v27; // rcx
  __m128 v28; // xmm3
  int v29; // eax
  __int64 v30; // rcx
  __int64 v31; // rcx
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm10
  __m128 v47; // xmm11
  __m128 v48; // xmm15
  __m128 v49; // xmm2
  __m128 v50; // xmm4
  __m128 v51; // xmm1
  __m128 v52; // xmm4
  __m128 v53; // xmm1
  hkVector4f v54; // xmm1
  __m128i v55; // xmm0
  __m128 v56; // xmm1
  __m128 v58; // [rsp+0h] [rbp-B8h]

  v7 = points;
  v8 = result;
  v9 = numPoints;
  v10 = 0i64;
  if ( numPoints > 0 )
  {
    v11 = points;
    v12 = numPoints;
    do
    {
      v10 = _mm_add_ps(v10, v11->m_quad);
      ++v11;
      --v12;
    }
    while ( v12 );
  }
  v13 = (__m128)_xmm;
  v14 = 0i64;
  v14.m128_f32[0] = (float)numPoints;
  v15 = 0i64;
  v16 = 0i64;
  v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)sideAxis), 1u), 1u);
  v18 = _mm_shuffle_ps(v14, v14, 0);
  v19 = 0i64;
  v20 = 0i64;
  v21 = _mm_rcp_ps(v18);
  v22 = 0i64;
  v23 = 0i64;
  v24 = 0i64;
  v25 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v21)), v21);
  v58 = v25;
  v26 = _mm_mul_ps(v10, v25);
  v27 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(
              _mm_max_ps(
                _mm_shuffle_ps(v17, v17, 170),
                _mm_max_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0))),
              v17),
            (__m128)xmmword_141A48D80));
  v28 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)forwardAxis), 1u), 1u);
  v29 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmpleps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v28, v28, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v28, v28, 85),
                                                                       _mm_shuffle_ps(v28, v28, 0))),
                                                                   v28),
                                                                 (__m128)xmmword_141A48D80))];
  v30 = *(unsigned __int8 *)(v27 + 5396439360i64);
  if ( numPoints > 0i64 )
  {
    v31 = v30;
    do
    {
      v32 = v7->m_quad;
      ++v7;
      v33 = _mm_sub_ps(v32, v26);
      v34 = v33;
      v35 = _mm_and_ps(v33, (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v29]);
      v36 = _mm_and_ps(v34, (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v31]);
      v37 = _mm_or_ps(_mm_shuffle_ps(v36, v36, 78), v36);
      v38 = _mm_or_ps(_mm_shuffle_ps(v35, v35, 78), v35);
      v39 = _mm_or_ps(_mm_shuffle_ps(v37, v37, 177), v37);
      v40 = _mm_or_ps(_mm_shuffle_ps(v38, v38, 177), v38);
      v41 = _mm_mul_ps(v39, v39);
      v42 = _mm_mul_ps(v40, v39);
      v43 = _mm_mul_ps(v40, v40);
      v15 = _mm_add_ps(v15, v41);
      v20 = _mm_add_ps(v20, _mm_mul_ps(v39, v41));
      v16 = _mm_add_ps(v16, v42);
      v19 = _mm_add_ps(v19, v43);
      v22 = _mm_add_ps(v22, _mm_mul_ps(v40, v43));
      v23 = _mm_add_ps(v23, _mm_mul_ps(v40, v42));
      v24 = _mm_add_ps(v24, _mm_mul_ps(v39, v42));
      --v9;
    }
    while ( v9 );
    v25 = v58;
    v13 = (__m128)_xmm;
  }
  v44 = _mm_sub_ps(_mm_mul_ps(v19, v15), _mm_mul_ps(v16, v16));
  if ( v44.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_090000004), (__m128)LODWORD(FLOAT_0_090000004), 0)) )
  {
    v45 = _mm_rcp_ps(v44);
    v8->m_enum = 0;
    v46 = _mm_mul_ps(_mm_add_ps(v23, v20), (__m128)xmmword_141A711B0);
    v47 = _mm_mul_ps(_mm_add_ps(v24, v22), (__m128)xmmword_141A711B0);
    v48 = _mm_mul_ps(_mm_sub_ps(v13, _mm_mul_ps(v45, v44)), v45);
    v49 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v19, v46), _mm_mul_ps(v16, v47)), v48);
    v50 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v47), _mm_mul_ps(v16, v46)), v48);
    v51 = _mm_unpacklo_ps(v49, v50);
    v52 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v50, v50), _mm_mul_ps(v49, v49)), _mm_mul_ps(_mm_add_ps(v19, v15), v25));
    v53 = _mm_add_ps(_mm_movelh_ps(v51, v51), v26);
    v54.m_quad = _mm_shuffle_ps(v53, _mm_unpackhi_ps(v53, (__m128)0i64), 180);
    *centerOut = (hkVector4f)v54.m_quad;
    v55 = (__m128i)v54.m_quad;
    v56 = _mm_rsqrt_ps(v52);
    *(__m128i *)centerOut = _mm_srli_si128(_mm_slli_si128(v55, 4), 4);
    *(_DWORD *)radiusOut = (unsigned __int128)_mm_andnot_ps(
                                                _mm_cmpleps(v52, (__m128)0i64),
                                                _mm_mul_ps(
                                                  _mm_mul_ps(
                                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v52), v56)),
                                                    _mm_mul_ps(*(__m128 *)_xmm, v56)),
                                                  v52));
  }
  else
  {
    v8->m_enum = 1;
    *radiusOut = 3.40282e38;
    *centerOut = 0i64;
  }
  return v8;
}

// File Line: 301
// RVA: 0xB45120
void __fastcall hkaParameterizeAnimationUtil::projectPointOntoCircle(hkVector4f *pointIn, hkVector4f *center, const float radius, hkVector4f *pointOut)
{
  __m128 v4; // xmm5
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  hkVector4f v8; // xmm1
  float v9; // [rsp+18h] [rbp+18h]

  v9 = radius;
  v4 = _mm_sub_ps(pointIn->m_quad, center->m_quad);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  v8.m_quad = _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(v9), (__m128)LODWORD(v9), 0),
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v6, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v7, v6), v7)),
                      _mm_mul_ps(*(__m128 *)_xmm, v7))),
                  v4));
  *pointOut = (hkVector4f)v8.m_quad;
  pointOut->m_quad = _mm_add_ps(center->m_quad, v8.m_quad);
}

