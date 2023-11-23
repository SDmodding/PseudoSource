// File Line: 16
// RVA: 0xB440C0
hkQsTransformf *__fastcall hkaParameterizeAnimationUtil::sampleReferenceFrame(
        hkQsTransformf *result,
        float sampleTime,
        hkQsTransformf *t,
        int numT,
        float duration)
{
  __int64 v5; // r9
  __m128 v6; // xmm0
  __m128 v7; // xmm7
  int v8; // r11d
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
  v6.m128_f32[0] = (float)(int)v5;
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
                            (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16), (__m128)0i64),
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
void __fastcall hkaParameterizeAnimationUtil::project(
        hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *options,
        hkQsTransformf *rootMotion,
        hkQsTransformf *projectionOut)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm4
  hkVector4f *p_m_up; // rdi
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  hkSimdFloat32 angleOut; // [rsp+20h] [rbp-38h] BYREF
  hkQuaternionf restOut; // [rsp+30h] [rbp-28h] BYREF

  v3.m_quad = (__m128)options->m_up;
  v4.m_quad = (__m128)options->m_forward;
  p_m_up = &options->m_up;
  v7 = _mm_mul_ps(rootMotion->m_translation.m_quad, v3.m_quad);
  v8 = _mm_mul_ps(
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170)),
         v3.m_quad);
  v9 = _mm_mul_ps(rootMotion->m_translation.m_quad, v4.m_quad);
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 201), v3.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 201), v4.m_quad));
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
    hkQuaternionf::decomposeRestAxis(&rootMotion->m_rotation, p_m_up, &restOut, &angleOut);
    hkQuaternionf::setAxisAngle(&projectionOut->m_rotation, p_m_up, &angleOut);
  }
  else
  {
    projectionOut->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  }
}

// File Line: 84
// RVA: 0xB44380
void __fastcall hkaParameterizeAnimationUtil::computeLinearSpeed(
        hkaAnimatedReferenceFrame *referenceFrame,
        float *linearSpeedOut)
{
  hkBaseObjectVtbl *vfptr; // rbx
  __int64 v5; // rdx
  __m128 v6; // xmm6
  __m128 v7; // xmm6
  __m128 v8; // xmm3
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  float v11; // xmm0_4
  __m128 v12[3]; // [rsp+20h] [rbp-78h] BYREF
  __m128 v13[3]; // [rsp+50h] [rbp-48h] BYREF
  float v14; // [rsp+A0h] [rbp+8h]

  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, float *, __m128 *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    linearSpeedOut,
    v13);
  vfptr = referenceFrame->vfptr;
  referenceFrame->vfptr[2].__first_virtual_table_function__(referenceFrame);
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    v5,
    v12);
  v6 = _mm_sub_ps(v12[0], v13[0]);
  v7 = _mm_mul_ps(v6, v6);
  v14 = ((float (__fastcall *)(hkaAnimatedReferenceFrame *))referenceFrame->vfptr[2].__first_virtual_table_function__)(referenceFrame);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_shuffle_ps((__m128)LODWORD(v14), (__m128)LODWORD(v14), 0);
  v10 = _mm_rsqrt_ps(v8);
  v11 = _mm_rcp_ps(v9).m128_f32[0];
  *linearSpeedOut = (float)((float)(2.0 - (float)(v9.m128_f32[0] * v11)) * v11)
                  * _mm_andnot_ps(
                      _mm_cmple_ps(v8, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v8), v10)),
                          _mm_mul_ps(*(__m128 *)_xmm, v10)),
                        v8)).m128_f32[0];
}

// File Line: 98
// RVA: 0xB44480
void __fastcall hkaParameterizeAnimationUtil::computeLinearDirection(
        hkaAnimatedReferenceFrame *referenceFrame,
        hkVector4f *forwardAxis,
        hkVector4f *upAxis,
        float *linearDirectionOut)
{
  hkBaseObjectVtbl *vfptr; // rbx
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
  hkQuaternionf v30; // [rsp+20h] [rbp-118h] BYREF
  hkSimdFloat32 angleOut; // [rsp+30h] [rbp-108h] BYREF
  hkQuaternionf restOut; // [rsp+40h] [rbp-F8h] BYREF
  __m128 v33[3]; // [rsp+50h] [rbp-E8h] BYREF
  __m128 v34[7]; // [rsp+80h] [rbp-B8h] BYREF

  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, hkVector4f *, __m128 *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    forwardAxis,
    v34);
  vfptr = referenceFrame->vfptr;
  referenceFrame->vfptr[2].__first_virtual_table_function__(referenceFrame);
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    v9,
    v33);
  v10 = _mm_sub_ps(v33[0], v34[0]);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(
          v10,
          _mm_andnot_ps(
            _mm_cmple_ps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13))));
  v15 = _mm_mul_ps(forwardAxis->m_quad, v14);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99998999), (__m128)LODWORD(FLOAT_0_99998999), 0).m128_f32[0];
  if ( v16.m128_f32[0] <= v17 )
  {
    if ( v16.m128_f32[0] >= (float)(0.0 - v17) )
    {
      v18 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v16), (__m128)xmmword_141A711B0);
      v19 = _mm_rsqrt_ps(v18);
      v20 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), forwardAxis->m_quad),
              _mm_mul_ps(_mm_shuffle_ps(forwardAxis->m_quad, forwardAxis->m_quad, 201), v14));
      v21 = _mm_shuffle_ps(v20, v20, 201);
      v22 = _mm_andnot_ps(
              _mm_cmple_ps(v18, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                _mm_mul_ps(*(__m128 *)_xmm, v19)));
      v23 = _mm_mul_ps(v22, (__m128)xmmword_141A711B0);
      if ( v16.m128_f32[0] < _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0).m128_f32[0] )
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
                    _mm_cmple_ps(v25, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v25), v28)),
                      _mm_mul_ps(*(__m128 *)_xmm, v28))),
                  v25),
                _mm_andnot_ps(
                  _mm_cmple_ps(v26, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                    _mm_mul_ps(*(__m128 *)_xmm, v27))));
      }
      v29 = _mm_mul_ps(v21, v23);
      v30.m_vec.m_quad = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, _mm_mul_ps(v22, v18)), 196);
    }
    else
    {
      hkQuaternionf::setFlippedRotation(&v30, forwardAxis);
    }
  }
  else
  {
    v30.m_vec.m_quad = qi.m_vec.m_quad;
  }
  hkQuaternionf::decomposeRestAxis(&v30, upAxis, &restOut, &angleOut);
  *linearDirectionOut = angleOut.m_real.m128_f32[0];
}

// File Line: 120
// RVA: 0xB44760
void __fastcall hkaParameterizeAnimationUtil::computeMovementDisplacement(
        hkaAnimatedReferenceFrame *referenceFrame,
        const __m128i *rotationAxis,
        hkVector4f *outDirection)
{
  __int64 v6; // rdx
  __int64 v7; // rdx
  __m128i v8; // xmm4
  __m128 v9; // xmm3
  int v10; // edx
  int v11; // edx
  hkVector4f v12; // xmm0
  __m128 v13[3]; // [rsp+20h] [rbp-78h] BYREF
  __m128 v14[3]; // [rsp+50h] [rbp-48h] BYREF

  referenceFrame->vfptr[2].__first_virtual_table_function__(referenceFrame);
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    v6,
    v13);
  ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, __m128 *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
    referenceFrame,
    v7,
    v14);
  v8 = (__m128i)_mm_sub_ps(v14[0], v13[0]);
  *outDirection = (hkVector4f)v8;
  v9 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(rotationAxis), 1u), 1u);
  v10 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
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
        v12.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(v8, 4), 4);
      else
        v12.m_quad = (__m128)_mm_slli_si128(_mm_srli_si128(v8, 4), 4);
      *outDirection = (hkVector4f)v12.m_quad;
    }
    else
    {
      outDirection->m_quad = _mm_shuffle_ps((__m128)v8, _mm_unpackhi_ps((__m128)v8, (__m128)0i64), 180);
    }
  }
  else
  {
    outDirection->m_quad = _mm_shuffle_ps(_mm_unpacklo_ps((__m128)v8, (__m128)0i64), (__m128)v8, 228);
  }
}

// File Line: 135
// RVA: 0xB44870
hkBool *__fastcall hkaParameterizeAnimationUtil::computeTurnParameters(
        hkBool *result,
        hkaAnimatedReferenceFrame *referenceFrame,
        const float sampleRate,
        hkVector4f *sideAxis,
        hkVector4f *forwardAxis,
        hkVector4f *upAxis,
        float *outRotationAngle,
        float *outRadius,
        hkVector4f *outRadiusDir)
{
  hkBool *v9; // rsi
  int v11; // r12d
  hkLifoAllocator *Value; // rax
  __int64 v13; // rdx
  hkVector4f *m_cur; // rbp
  int v15; // r13d
  char *v16; // rcx
  int v17; // ebx
  __int64 v18; // r15
  int v19; // edi
  hkVector4f *v20; // rsi
  float *v21; // r15
  unsigned int m_slotID; // ecx
  hkLifoAllocator *v23; // rax
  int v24; // r8d
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm12
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  float v31; // xmm11_4
  __int64 v32; // rdx
  __m128 m_quad; // xmm6
  hkVector4f *v34; // rdi
  __int64 v35; // rsi
  __m128 v36; // xmm1
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128 v40; // xmm7
  float v41; // xmm6_4
  hkVector4f *v42; // rdi
  __m128 v43; // xmm1
  float *v44; // rax
  __m128 v45; // xmm1
  float v46; // xmm2_4
  hkLifoAllocator *v47; // rax
  int v48; // r8d
  hkVector4f center; // [rsp+40h] [rbp-F8h] BYREF
  hkVector4f pointOut; // [rsp+50h] [rbp-E8h] BYREF
  hkVector4f v51; // [rsp+60h] [rbp-D8h] BYREF
  hkQuaternionf v52; // [rsp+70h] [rbp-C8h] BYREF
  hkResult resulta; // [rsp+150h] [rbp+18h] BYREF
  hkVector4f *sideAxisa; // [rsp+158h] [rbp+20h]

  sideAxisa = sideAxis;
  v9 = result;
  v11 = (int)(float)(((float (__fastcall *)(hkaAnimatedReferenceFrame *))referenceFrame->vfptr[2].__first_virtual_table_function__)(referenceFrame)
                   / sampleRate);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkVector4f *)Value->m_cur;
  v15 = (16 * v11 + 127) & 0xFFFFFF80;
  v16 = (char *)m_cur + v15;
  if ( v15 > Value->m_slabSize || v16 > Value->m_end )
    m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v15);
  else
    Value->m_cur = v16;
  v17 = 0;
  v18 = v11;
  v19 = 0;
  if ( v11 > 0 )
  {
    v20 = m_cur;
    do
    {
      ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, hkVector4f *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
        referenceFrame,
        v13,
        &v51);
      ++v19;
      *v20++ = (hkVector4f)v51.m_quad;
      --v18;
    }
    while ( v18 );
    v9 = result;
  }
  v21 = outRadius;
  center.m_quad = 0i64;
  if ( hkaParameterizeAnimationUtil::fitCircle(&resulta, m_cur, v11, sideAxisa, forwardAxis, &center, outRadius)->m_enum == HK_FAILURE )
  {
    m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
    v9->m_bool = 0;
    v23 = (hkLifoAllocator *)TlsGetValue(m_slotID);
    v24 = (v15 + 15) & 0xFFFFFFF0;
    if ( v15 > v23->m_slabSize || (char *)m_cur + v24 != v23->m_cur || v23->m_firstNonLifoEnd == m_cur )
    {
      hkLifoAllocator::slowBlockFree(v23, m_cur, v24);
      return v9;
    }
    else
    {
      v23->m_cur = m_cur;
      return v9;
    }
  }
  else
  {
    v26 = _mm_mul_ps(center.m_quad, center.m_quad);
    v27 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
            _mm_shuffle_ps(v26, v26, 170));
    v28 = 0i64;
    v29 = _mm_rsqrt_ps(v27);
    v30 = _mm_cmplt_ps(v27, (__m128)xmmword_141A712D0);
    outRadiusDir->m_quad = _mm_or_ps(
                             _mm_andnot_ps(
                               v30,
                               _mm_mul_ps(
                                 center.m_quad,
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v27), v29)),
                                   _mm_mul_ps(v29, *(__m128 *)_xmm)))),
                             _mm_and_ps(v30, transform.m_quad));
    v31 = *v21;
    hkaParameterizeAnimationUtil::projectPointOntoCircle(m_cur, &center, *v21, &pointOut);
    if ( v11 > 1 )
    {
      m_quad = pointOut.m_quad;
      v34 = m_cur + 1;
      v35 = (unsigned int)(v11 - 1);
      do
      {
        hkaParameterizeAnimationUtil::projectPointOntoCircle(v34++, &center, v31, &pointOut);
        v36 = _mm_sub_ps(pointOut.m_quad, m_quad);
        m_quad = pointOut.m_quad;
        v37 = _mm_mul_ps(v36, v36);
        v38 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                _mm_shuffle_ps(v37, v37, 170));
        v39 = _mm_rsqrt_ps(v38);
        v28 = _mm_add_ps(
                v28,
                _mm_andnot_ps(
                  _mm_cmple_ps(v38, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                      _mm_mul_ps(v39, *(__m128 *)_xmm)),
                    v38)));
        --v35;
      }
      while ( v35 );
    }
    v40 = 0i64;
    v41 = 0.0;
    if ( v11 > 0 )
    {
      v42 = upAxis;
      do
      {
        ((void (__fastcall *)(hkaAnimatedReferenceFrame *, __int64, hkVector4f *))referenceFrame->vfptr[1].__first_virtual_table_function__)(
          referenceFrame,
          v32,
          &v51);
        hkQuaternionf::decomposeRestAxis(&v52, v42, (hkQuaternionf *)&pointOut, (hkSimdFloat32 *)&center);
        v43 = center.m_quad;
        if ( (float)(center.m_quad.m128_f32[0] - v41) > 3.1415927 )
        {
          do
            v43 = _mm_sub_ps(v43, (__m128)xmmword_141A713F0);
          while ( (float)(v43.m128_f32[0] - v41) > 3.1415927 );
          center.m_quad = v43;
        }
        if ( (float)(v43.m128_f32[0] - v41) < (float)(0.0 - 3.1415927) )
        {
          do
            v43 = _mm_add_ps(v43, (__m128)xmmword_141A713F0);
          while ( (float)(v43.m128_f32[0] - v41) < (float)(0.0 - 3.1415927) );
          center.m_quad = v43;
        }
        ++v17;
        v40 = _mm_add_ps(v40, v43);
        v41 = v43.m128_f32[0];
      }
      while ( v17 < v11 );
    }
    v44 = outRotationAngle;
    v45 = _mm_shuffle_ps((__m128)*(unsigned int *)v21, (__m128)*(unsigned int *)v21, 0);
    v46 = _mm_rcp_ps(v45).m128_f32[0];
    result->m_bool = 1;
    *v44 = COERCE_FLOAT((_mm_cmple_ps(v40, (__m128)0i64).m128_u32[0] >> 31 << 31) ^ 0x3F800000)
         * (float)((float)((float)(2.0 - (float)(v46 * v45.m128_f32[0])) * v46) * v28.m128_f32[0]);
    v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v48 = (v15 + 15) & 0xFFFFFFF0;
    if ( v15 > v47->m_slabSize || (char *)m_cur + v48 != v47->m_cur || v47->m_firstNonLifoEnd == m_cur )
      hkLifoAllocator::slowBlockFree(v47, m_cur, v48);
    else
      v47->m_cur = m_cur;
    return result;
  }
}

// File Line: 205
// RVA: 0xB44CE0
void __fastcall hkaParameterizeAnimationUtil::computeTurnSpeed(
        float rotationAngleR,
        float radiusR,
        float durationR,
        float *outLinearSpeed,
        float *outAngularSpeed)
{
  float v5; // xmm5_4
  float v6; // xmm4_4
  __m128 v7; // xmm1
  float v8; // xmm0_4
  float v9; // xmm2_4

  LODWORD(v5) = _mm_shuffle_ps((__m128)LODWORD(rotationAngleR), (__m128)LODWORD(rotationAngleR), 0).m128_u32[0];
  LODWORD(v6) = (unsigned int)(2 * LODWORD(v5)) >> 1;
  if ( v6 < _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0).m128_f32[0] )
  {
    *outAngularSpeed = 0.0;
    *outLinearSpeed = radiusR;
  }
  else
  {
    v7 = _mm_shuffle_ps((__m128)LODWORD(durationR), (__m128)LODWORD(durationR), 0);
    v8 = _mm_rcp_ps(v7).m128_f32[0];
    v9 = (float)(2.0 - (float)(v7.m128_f32[0] * v8)) * v8;
    *outAngularSpeed = v9 * v5;
    *outLinearSpeed = (float)(_mm_shuffle_ps((__m128)LODWORD(radiusR), (__m128)LODWORD(radiusR), 0).m128_f32[0] * v6)
                    * v9;
  }
}

// File Line: 227
// RVA: 0xB44D90
hkResult *__fastcall hkaParameterizeAnimationUtil::fitCircle(
        hkResult *result,
        hkVector4f *points,
        int numPoints,
        const __m128i *sideAxis,
        hkVector4f *forwardAxis,
        hkVector4f *centerOut,
        float *radiusOut)
{
  hkVector4f *v7; // rbx
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
  __m128 m_quad; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  __m128 v41; // xmm3
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm1
  __m128 v45; // xmm10
  __m128 v46; // xmm11
  __m128 v47; // xmm15
  __m128 v48; // xmm2
  __m128 v49; // xmm4
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 v52; // xmm1
  hkVector4f v53; // xmm1
  __m128i v54; // xmm0
  __m128 v55; // xmm1
  __m128 v57; // [rsp+0h] [rbp-B8h]

  v7 = points;
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
  v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(sideAxis), 1u), 1u);
  v18 = _mm_shuffle_ps(v14, v14, 0);
  v19 = 0i64;
  v20 = 0i64;
  v21 = _mm_rcp_ps(v18);
  v22 = 0i64;
  v23 = 0i64;
  v24 = 0i64;
  v25 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v21)), v21);
  v57 = v25;
  v26 = _mm_mul_ps(v10, v25);
  v27 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(
              _mm_max_ps(
                _mm_shuffle_ps(v17, v17, 170),
                _mm_max_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0))),
              v17),
            (__m128)xmmword_141A48D80));
  v28 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)forwardAxis), 1u), 1u);
  v29 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                               _mm_and_ps(
                                                                 _mm_cmple_ps(
                                                                   _mm_max_ps(
                                                                     _mm_shuffle_ps(v28, v28, 170),
                                                                     _mm_max_ps(
                                                                       _mm_shuffle_ps(v28, v28, 85),
                                                                       _mm_shuffle_ps(v28, v28, 0))),
                                                                   v28),
                                                                 (__m128)xmmword_141A48D80))];
  v30 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v27];
  if ( numPoints > 0i64 )
  {
    v31 = v30;
    do
    {
      m_quad = v7->m_quad;
      ++v7;
      v33 = _mm_sub_ps(m_quad, v26);
      v34 = _mm_and_ps(v33, (__m128)`hkVector4f::getComponent::`2::indexToMask[v29]);
      v35 = _mm_and_ps(v33, (__m128)`hkVector4f::getComponent::`2::indexToMask[v31]);
      v36 = _mm_or_ps(_mm_shuffle_ps(v35, v35, 78), v35);
      v37 = _mm_or_ps(_mm_shuffle_ps(v34, v34, 78), v34);
      v38 = _mm_or_ps(_mm_shuffle_ps(v36, v36, 177), v36);
      v39 = _mm_or_ps(_mm_shuffle_ps(v37, v37, 177), v37);
      v40 = _mm_mul_ps(v38, v38);
      v41 = _mm_mul_ps(v39, v38);
      v42 = _mm_mul_ps(v39, v39);
      v15 = _mm_add_ps(v15, v40);
      v20 = _mm_add_ps(v20, _mm_mul_ps(v38, v40));
      v16 = _mm_add_ps(v16, v41);
      v19 = _mm_add_ps(v19, v42);
      v22 = _mm_add_ps(v22, _mm_mul_ps(v39, v42));
      v23 = _mm_add_ps(v23, _mm_mul_ps(v39, v41));
      v24 = _mm_add_ps(v24, _mm_mul_ps(v38, v41));
      --v9;
    }
    while ( v9 );
    v25 = v57;
    v13 = (__m128)_xmm;
  }
  v43 = _mm_sub_ps(_mm_mul_ps(v19, v15), _mm_mul_ps(v16, v16));
  if ( v43.m128_f32[0] >= _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_090000004), (__m128)LODWORD(FLOAT_0_090000004), 0).m128_f32[0] )
  {
    v44 = _mm_rcp_ps(v43);
    result->m_enum = HK_SUCCESS;
    v45 = _mm_mul_ps(_mm_add_ps(v23, v20), (__m128)xmmword_141A711B0);
    v46 = _mm_mul_ps(_mm_add_ps(v24, v22), (__m128)xmmword_141A711B0);
    v47 = _mm_mul_ps(_mm_sub_ps(v13, _mm_mul_ps(v44, v43)), v44);
    v48 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v19, v45), _mm_mul_ps(v16, v46)), v47);
    v49 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v46), _mm_mul_ps(v16, v45)), v47);
    v50 = _mm_unpacklo_ps(v48, v49);
    v51 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v49, v49), _mm_mul_ps(v48, v48)), _mm_mul_ps(_mm_add_ps(v19, v15), v25));
    v52 = _mm_add_ps(_mm_movelh_ps(v50, v50), v26);
    v53.m_quad = _mm_shuffle_ps(v52, _mm_unpackhi_ps(v52, (__m128)0i64), 180);
    *centerOut = (hkVector4f)v53.m_quad;
    v54 = (__m128i)v53.m_quad;
    v55 = _mm_rsqrt_ps(v51);
    *(__m128i *)centerOut = _mm_srli_si128(_mm_slli_si128(v54, 4), 4);
    *(_DWORD *)radiusOut = _mm_andnot_ps(
                             _mm_cmple_ps(v51, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v51), v55)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v55)),
                               v51)).m128_u32[0];
  }
  else
  {
    result->m_enum = HK_FAILURE;
    *radiusOut = 3.40282e38;
    *centerOut = 0i64;
  }
  return result;
}

// File Line: 301
// RVA: 0xB45120
void __fastcall hkaParameterizeAnimationUtil::projectPointOntoCircle(
        hkVector4f *pointIn,
        hkVector4f *center,
        const float radius,
        hkVector4f *pointOut)
{
  __m128 v4; // xmm5
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm1

  v4 = _mm_sub_ps(pointIn->m_quad, center->m_quad);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  v8 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)LODWORD(radius), (__m128)LODWORD(radius), 0),
         _mm_mul_ps(
           _mm_andnot_ps(
             _mm_cmple_ps(v6, (__m128)0i64),
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v7, v6), v7)), _mm_mul_ps(*(__m128 *)_xmm, v7))),
           v4));
  *pointOut = (hkVector4f)v8;
  pointOut->m_quad = _mm_add_ps(center->m_quad, v8);
}

