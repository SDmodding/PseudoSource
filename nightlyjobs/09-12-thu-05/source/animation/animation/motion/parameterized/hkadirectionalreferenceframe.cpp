// File Line: 16
// RVA: 0xB347E0
void __fastcall hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame(
        hkaDirectionalReferenceFrame *this,
        hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *options)
{
  __int128 v4; // xmm0
  hkVector4f v5; // xmm1
  hkVector4f v6; // xmm0
  _QWORD **Value; // rax
  hkaDefaultAnimatedReferenceFrame *v8; // rax
  hkaAnimatedReferenceFrame *v9; // rax
  hkaAnimatedReferenceFrame *v10; // rbx
  hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions optionsa; // [rsp+20h] [rbp-48h] BYREF

  hkaDefaultAnimatedReferenceFrame::hkaDefaultAnimatedReferenceFrame(this, options, REFERENCE_FRAME_PARAMETRIC);
  this->vfptr = (hkBaseObjectVtbl *)&hkaDirectionalReferenceFrame::`vftable;
  v4 = *(_OWORD *)&options->m_referenceFrameTransforms;
  *(_OWORD *)&optionsa.m_numSamples = *(_OWORD *)&options->m_numSamples;
  v5.m_quad = (__m128)options->m_forward;
  *(_OWORD *)&optionsa.m_referenceFrameTransforms = v4;
  optionsa.m_allowTurning.m_bool = 0;
  v6.m_quad = (__m128)options->m_up;
  optionsa.m_forward = (hkVector4f)v5.m_quad;
  optionsa.m_up = (hkVector4f)v6.m_quad;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkaDefaultAnimatedReferenceFrame *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                             Value[11],
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
  hkaParameterizeAnimationUtil::computeMovementDisplacement(v10, &optionsa.m_up, &this->m_movementDir);
  hkReferencedObject::removeReference(v10);
}

// File Line: 27
// RVA: 0xB348A0
void __fastcall hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame(
        hkaDirectionalReferenceFrame *this,
        hkaDefaultAnimatedReferenceFrame *baseReferenceFrame)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_frameType.m_storage = 1;
  this->m_referenceFrameSamples.m_data = 0i64;
  this->m_referenceFrameSamples.m_size = 0;
  this->m_referenceFrameSamples.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkaParameterizedReferenceFrame::`vftable;
  hkaDefaultAnimatedReferenceFrame::operator=(this, baseReferenceFrame);
  this->vfptr = (hkBaseObjectVtbl *)&hkaDirectionalReferenceFrame::`vftable;
  this->m_frameType.m_storage = 2;
  hkaParameterizeAnimationUtil::computeMovementDisplacement(
    baseReferenceFrame,
    &baseReferenceFrame->m_up,
    &this->m_movementDir);
}

// File Line: 33
// RVA: 0xB34910
void __fastcall hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame(
        hkaDirectionalReferenceFrame *this,
        hkFinishLoadedObjectFlag flag)
{
  this->m_frameType.m_storage = 2;
  this->vfptr = (hkBaseObjectVtbl *)&hkaDirectionalReferenceFrame::`vftable;
}

// File Line: 37
// RVA: 0xB34930
void __fastcall hkaDirectionalReferenceFrame::getParameters(
        hkaDirectionalReferenceFrame *this,
        hkVector4f *outParamVec)
{
  __m128 m_real; // xmm7
  __m128 v5; // xmm1
  __m128 v6; // xmm0
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm11
  hkVector4f v12; // xmm5
  hkVector4f v13; // xmm10
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm10
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  float v20; // xmm1_4
  __m128 v21; // xmm9
  __m128 v22; // xmm2
  __m128 v23; // xmm6
  __m128 v24; // xmm6
  __m128 v25; // xmm8
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm6
  hkQuaternionf v33; // [rsp+20h] [rbp-B8h] BYREF
  hkSimdFloat32 angleOut; // [rsp+30h] [rbp-A8h] BYREF
  hkQuaternionf restOut; // [rsp+40h] [rbp-98h] BYREF
  float v36; // [rsp+E0h] [rbp+8h]

  m_real = 0i64;
  v36 = ((float (__fastcall *)(hkaDirectionalReferenceFrame *))this->vfptr[2].__first_virtual_table_function__)(this);
  v5 = _mm_shuffle_ps((__m128)LODWORD(v36), (__m128)LODWORD(v36), 0);
  v6 = _mm_rcp_ps(v5);
  v7 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5, v6));
  v8 = _mm_mul_ps(this->m_movementDir.m_quad, this->m_movementDir.m_quad);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  v11 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                _mm_mul_ps(v10, *(__m128 *)_xmm)),
              v9)),
          _mm_mul_ps(v7, v6));
  if ( v11.m128_f32[0] > 0.00000011920929 )
  {
    v12.m_quad = (__m128)this->m_forward;
    v13.m_quad = (__m128)this->m_movementDir;
    v14 = _mm_mul_ps(v13.m_quad, v13.m_quad);
    v15 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170));
    v16 = _mm_rsqrt_ps(v15);
    v17 = _mm_mul_ps(
            v13.m_quad,
            _mm_andnot_ps(
              _mm_cmple_ps(v15, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                _mm_mul_ps(v16, *(__m128 *)_xmm))));
    v18 = _mm_mul_ps(v17, v12.m_quad);
    v19 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
            _mm_shuffle_ps(v18, v18, 170));
    v20 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99998999), (__m128)LODWORD(FLOAT_0_99998999), 0).m128_f32[0];
    if ( v19.m128_f32[0] <= v20 )
    {
      if ( v19.m128_f32[0] >= (float)(0.0 - v20) )
      {
        v21 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v19), (__m128)xmmword_141A711B0);
        v22 = _mm_rsqrt_ps(v21);
        v23 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v12.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v12.m_quad, v12.m_quad, 201), v17));
        v24 = _mm_shuffle_ps(v23, v23, 201);
        v25 = _mm_andnot_ps(
                _mm_cmple_ps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
                  _mm_mul_ps(v22, *(__m128 *)_xmm)));
        v26 = _mm_mul_ps(v25, (__m128)xmmword_141A711B0);
        if ( v19.m128_f32[0] < _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_99900001), (__m128)LODWORD(FLOAT_N0_99900001), 0).m128_f32[0] )
        {
          v27 = _mm_mul_ps(v24, v24);
          v28 = _mm_sub_ps(v21, v19);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                  _mm_shuffle_ps(v27, v27, 170));
          v30 = _mm_rsqrt_ps(v29);
          v31 = _mm_rsqrt_ps(v28);
          v26 = _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps(v28, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v28), v31)),
                        _mm_mul_ps(v31, *(__m128 *)_xmm))),
                    v28),
                  _mm_andnot_ps(
                    _mm_cmple_ps(v29, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                      _mm_mul_ps(v30, *(__m128 *)_xmm))));
        }
        v32 = _mm_mul_ps(v24, v26);
        v33.m_vec.m_quad = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, _mm_mul_ps(v25, v21)), 196);
      }
      else
      {
        hkQuaternionf::setFlippedRotation(&v33, &this->m_forward);
      }
    }
    else
    {
      v33.m_vec.m_quad = qi.m_vec.m_quad;
    }
    hkQuaternionf::decomposeRestAxis(&v33, &this->m_up, &restOut, &angleOut);
    m_real = angleOut.m_real;
  }
  outParamVec->m_quad = _mm_movelh_ps(_mm_unpacklo_ps(m_real, v11), _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad));
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
  return _mm_andnot_ps(
           _mm_cmple_ps(v2, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v3, v2), v3)), _mm_mul_ps(*(__m128 *)_xmm, v3)),
             v2)).m128_f32[0]
       + 1.0;
}

