// File Line: 16
// RVA: 0xB347E0
void __fastcall hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame(hkaDirectionalReferenceFrame *this, hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *options)
{
  hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *v2; // rbx
  hkaDirectionalReferenceFrame *v3; // rdi
  __int128 v4; // xmm0
  hkVector4f v5; // xmm1
  hkVector4f v6; // xmm0
  _QWORD **v7; // rax
  hkaDefaultAnimatedReferenceFrame *v8; // rax
  hkaAnimatedReferenceFrame *v9; // rax
  hkaAnimatedReferenceFrame *v10; // rbx
  hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions optionsa; // [rsp+20h] [rbp-48h]

  v2 = options;
  v3 = this;
  hkaDefaultAnimatedReferenceFrame::hkaDefaultAnimatedReferenceFrame(
    (hkaDefaultAnimatedReferenceFrame *)&this->vfptr,
    options,
    REFERENCE_FRAME_PARAMETRIC);
  v3->vfptr = (hkBaseObjectVtbl *)&hkaDirectionalReferenceFrame::`vftable;
  v4 = *(_OWORD *)&v2->m_referenceFrameTransforms;
  *(_OWORD *)&optionsa.m_numSamples = *(_OWORD *)&v2->m_numSamples;
  v5.m_quad = (__m128)v2->m_forward;
  *(_OWORD *)&optionsa.m_referenceFrameTransforms = v4;
  optionsa.m_allowTurning.m_bool = 0;
  v6.m_quad = (__m128)v2->m_up;
  optionsa.m_forward = (hkVector4f)v5.m_quad;
  optionsa.m_up = (hkVector4f)v6.m_quad;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkaDefaultAnimatedReferenceFrame *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(
                                             v7[11],
                                             96i64);
  if ( v8 )
  {
    hkaDefaultAnimatedReferenceFrame::hkaDefaultAnimatedReferenceFrame(v8, &optionsa, REFERENCE_FRAME_DEFAULT);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  hkaParameterizeAnimationUtil::computeMovementDisplacement(v10, &optionsa.m_up, &v3->m_movementDir);
  hkReferencedObject::removeReference((hkReferencedObject *)&v10->vfptr);
}

// File Line: 27
// RVA: 0xB348A0
void __fastcall hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame(hkaDirectionalReferenceFrame *this, hkaDefaultAnimatedReferenceFrame *baseReferenceFrame)
{
  hkaDefaultAnimatedReferenceFrame *v2; // rbx
  hkaDirectionalReferenceFrame *v3; // rdi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_frameType.m_storage = 1;
  this->m_referenceFrameSamples.m_data = 0i64;
  this->m_referenceFrameSamples.m_size = 0;
  this->m_referenceFrameSamples.m_capacityAndFlags = 2147483648;
  v2 = baseReferenceFrame;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaParameterizedReferenceFrame::`vftable;
  hkaDefaultAnimatedReferenceFrame::operator=((hkaDefaultAnimatedReferenceFrame *)&this->vfptr, baseReferenceFrame);
  v3->vfptr = (hkBaseObjectVtbl *)&hkaDirectionalReferenceFrame::`vftable;
  v3->m_frameType.m_storage = 2;
  hkaParameterizeAnimationUtil::computeMovementDisplacement(
    (hkaAnimatedReferenceFrame *)&v2->vfptr,
    &v2->m_up,
    &v3->m_movementDir);
}

// File Line: 33
// RVA: 0xB34910
void __fastcall hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame(hkaDirectionalReferenceFrame *this, hkFinishLoadedObjectFlag flag)
{
  this->m_frameType.m_storage = 2;
  this->vfptr = (hkBaseObjectVtbl *)&hkaDirectionalReferenceFrame::`vftable;
}

// File Line: 37
// RVA: 0xB34930
void __usercall hkaDirectionalReferenceFrame::getParameters(hkaDirectionalReferenceFrame *this@<rcx>, hkVector4f *outParamVec@<rdx>, unsigned int a3@<xmm0>)
{
  hkVector4f *v3; // rdi
  hkaDirectionalReferenceFrame *v4; // rbx
  __m128 v5; // xmm7
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm11
  __m128 v13; // xmm5
  __m128 v14; // xmm10
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm10
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  float v21; // xmm1_4
  __m128 v22; // xmm9
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm6
  __m128 v26; // xmm8
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  hkQuaternionf v34; // [rsp+20h] [rbp-B8h]
  hkSimdFloat32 angleOut; // [rsp+30h] [rbp-A8h]
  hkQuaternionf restOut; // [rsp+40h] [rbp-98h]

  v3 = outParamVec;
  v4 = this;
  ((void (*)(void))this->vfptr[2].__first_virtual_table_function__)();
  v5 = 0i64;
  v6 = _mm_shuffle_ps((__m128)a3, (__m128)a3, 0);
  v7 = _mm_rcp_ps(v6);
  v8 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v6, v7));
  v9 = _mm_mul_ps(v4->m_movementDir.m_quad, v4->m_movementDir.m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                _mm_mul_ps(v11, *(__m128 *)_xmm)),
              v10)),
          _mm_mul_ps(v8, v7));
  if ( v12.m128_f32[0] > 0.00000011920929 )
  {
    v13 = v4->m_forward.m_quad;
    v14 = v4->m_movementDir.m_quad;
    v15 = _mm_mul_ps(v14, v14);
    v16 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
            _mm_shuffle_ps(v15, v15, 170));
    v17 = _mm_rsqrt_ps(v16);
    v18 = _mm_mul_ps(
            v14,
            _mm_andnot_ps(
              _mm_cmpleps(v16, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                _mm_mul_ps(v17, *(__m128 *)_xmm))));
    v19 = _mm_mul_ps(v18, v13);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    LODWORD(v21) = (unsigned __int128)_mm_shuffle_ps(
                                        (__m128)LODWORD(FLOAT_0_99998999),
                                        (__m128)LODWORD(FLOAT_0_99998999),
                                        0);
    if ( v20.m128_f32[0] <= v21 )
    {
      if ( v20.m128_f32[0] >= (float)(0.0 - v21) )
      {
        v22 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v20), (__m128)xmmword_141A711B0);
        v23 = _mm_rsqrt_ps(v22);
        v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v13), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v18));
        v25 = _mm_shuffle_ps(v24, v24, 201);
        v26 = _mm_andnot_ps(
                _mm_cmpleps(v22, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                  _mm_mul_ps(v23, *(__m128 *)_xmm)));
        v27 = _mm_mul_ps(v26, (__m128)xmmword_141A711B0);
        if ( v20.m128_f32[0] < COERCE_FLOAT(
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(FLOAT_N0_99900001),
                                   (__m128)LODWORD(FLOAT_N0_99900001),
                                   0)) )
        {
          v28 = _mm_mul_ps(v25, v25);
          v29 = _mm_sub_ps(v22, v20);
          v30 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170));
          v31 = _mm_rsqrt_ps(v30);
          v32 = _mm_rsqrt_ps(v29);
          v27 = _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmpleps(v29, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v29), v32)),
                        _mm_mul_ps(v32, *(__m128 *)_xmm))),
                    v29),
                  _mm_andnot_ps(
                    _mm_cmpleps(v30, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                      _mm_mul_ps(v31, *(__m128 *)_xmm))));
        }
        v33 = _mm_mul_ps(v25, v27);
        v34.m_vec.m_quad = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, _mm_mul_ps(v26, v22)), 196);
      }
      else
      {
        hkQuaternionf::setFlippedRotation(&v34, &v4->m_forward);
      }
    }
    else
    {
      v34.m_vec.m_quad = qi.m_vec.m_quad;
    }
    hkQuaternionf::decomposeRestAxis(&v34, &v4->m_up, &restOut, &angleOut);
    v5 = angleOut.m_real;
  }
  v3->m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v5, v12), _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad));
}

// File Line: 64
// RVA: 0xB34C70
float __fastcall hkaDirectionalReferenceFrame::getDistanceCovered(hkaDirectionalReferenceFrame *this)
{
  __m128 v1; // xmm1
  __m128 v2; // xmm5
  __m128 v3; // xmm2

  v1 = _mm_mul_ps(this->m_movementDir.m_quad, this->m_movementDir.m_quad);
  v2 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v1, v1, 85), _mm_shuffle_ps(v1, v1, 0)), _mm_shuffle_ps(v1, v1, 170));
  v3 = _mm_rsqrt_ps(v2);
  return COERCE_FLOAT(
           _mm_andnot_ps(
             _mm_cmpleps(v2, (__m128)0i64),
             _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v3, v2), v3)), _mm_mul_ps(*(__m128 *)_xmm, v3)),
               v2)))
       + 1.0;
}

