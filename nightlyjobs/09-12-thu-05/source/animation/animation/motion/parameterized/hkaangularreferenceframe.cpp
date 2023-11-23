// File Line: 18
// RVA: 0xB330D0
void __fastcall hkaAngularReferenceFrame::hkaAngularReferenceFrame(
        hkaAngularReferenceFrame *this,
        hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *options)
{
  __int128 v4; // xmm0
  hkVector4f v5; // xmm1
  hkVector4f v6; // xmm0
  _QWORD **Value; // rax
  hkaDefaultAnimatedReferenceFrame *v8; // rax
  hkaDefaultAnimatedReferenceFrame *v9; // rax
  hkaDefaultAnimatedReferenceFrame *v10; // rbx
  hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions optionsa; // [rsp+20h] [rbp-48h] BYREF

  hkaDefaultAnimatedReferenceFrame::hkaDefaultAnimatedReferenceFrame(this, options, REFERENCE_FRAME_PARAMETRIC);
  this->vfptr = (hkBaseObjectVtbl *)&hkaAngularReferenceFrame::`vftable;
  v4 = *(_OWORD *)&options->m_referenceFrameTransforms;
  *(_OWORD *)&optionsa.m_numSamples = *(_OWORD *)&options->m_numSamples;
  v5.m_quad = (__m128)options->m_forward;
  *(_OWORD *)&optionsa.m_referenceFrameTransforms = v4;
  optionsa.m_allowTurning.m_bool = 1;
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
  hkaAngularReferenceFrame::initialize(this, v10);
  hkReferencedObject::removeReference(v10);
}

// File Line: 28
// RVA: 0xB33180
void __fastcall hkaAngularReferenceFrame::hkaAngularReferenceFrame(
        hkaAngularReferenceFrame *this,
        hkaDefaultAnimatedReferenceFrame *baseReferenceFrame)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_frameType.m_storage = 1;
  this->m_referenceFrameSamples.m_data = 0i64;
  this->m_referenceFrameSamples.m_size = 0;
  this->m_referenceFrameSamples.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkaParameterizedReferenceFrame::`vftable;
  hkaDefaultAnimatedReferenceFrame::operator=(this, baseReferenceFrame);
  this->vfptr = (hkBaseObjectVtbl *)&hkaAngularReferenceFrame::`vftable;
  this->m_frameType.m_storage = 2;
  hkaAngularReferenceFrame::initialize(this, baseReferenceFrame);
}

// File Line: 33
// RVA: 0xB332F0
void __fastcall hkaAngularReferenceFrame::initialize(
        hkaAngularReferenceFrame *this,
        hkaDefaultAnimatedReferenceFrame *baseReferenceFrame)
{
  int m_size; // ebx
  double v5; // xmm0_8
  float *outRadius; // rbp
  float *outRotationAngle; // rdi
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  hkVector4f sideAxis; // [rsp+50h] [rbp-48h] BYREF
  hkVector4f outDirection; // [rsp+60h] [rbp-38h] BYREF
  hkVector4f outRadiusDir; // [rsp+70h] [rbp-28h] BYREF
  hkBool result; // [rsp+A0h] [rbp+8h] BYREF
  float v16; // [rsp+A8h] [rbp+10h]

  m_size = baseReferenceFrame->m_referenceFrameSamples.m_size;
  v5 = ((double (__fastcall *)(hkaDefaultAnimatedReferenceFrame *))baseReferenceFrame->vfptr[2].__first_virtual_table_function__)(baseReferenceFrame);
  outRadius = &this->m_radius;
  outRotationAngle = &this->m_topAngle;
  v8 = _mm_sub_ps(
         _mm_mul_ps(
           _mm_shuffle_ps(baseReferenceFrame->m_up.m_quad, baseReferenceFrame->m_up.m_quad, 201),
           baseReferenceFrame->m_forward.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(baseReferenceFrame->m_forward.m_quad, baseReferenceFrame->m_forward.m_quad, 201),
           baseReferenceFrame->m_up.m_quad));
  sideAxis.m_quad = _mm_shuffle_ps(v8, v8, 201);
  hkaParameterizeAnimationUtil::computeTurnParameters(
    &result,
    baseReferenceFrame,
    *(float *)&v5 / (float)m_size,
    &sideAxis,
    &baseReferenceFrame->m_forward,
    &baseReferenceFrame->m_up,
    outRotationAngle,
    outRadius,
    &outRadiusDir);
  if ( !result.m_bool || (v16 = *outRotationAngle, COERCE_FLOAT((unsigned int)(2 * LODWORD(v16)) >> 1) < 0.087266468) )
  {
    hkaParameterizeAnimationUtil::computeMovementDisplacement(
      baseReferenceFrame,
      &baseReferenceFrame->m_up,
      &outDirection);
    v9 = _mm_mul_ps(outDirection.m_quad, outDirection.m_quad);
    v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
    v11 = _mm_rsqrt_ps(v10);
    *(_DWORD *)outRadius = _mm_andnot_ps(
                             _mm_cmple_ps(v10, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v11)),
                               v10)).m128_u32[0];
    *outRotationAngle = 0.0;
  }
}

// File Line: 53
// RVA: 0xB331F0
void __fastcall hkaAngularReferenceFrame::hkaAngularReferenceFrame(
        hkaAngularReferenceFrame *this,
        hkFinishLoadedObjectFlag flag)
{
  this->m_frameType.m_storage = 2;
  this->vfptr = (hkBaseObjectVtbl *)&hkaAngularReferenceFrame::`vftable;
}

// File Line: 57
// RVA: 0xB33210
void __fastcall hkaAngularReferenceFrame::getParameters(hkaAngularReferenceFrame *this, hkVector4f *outParamVec)
{
  unsigned int v4; // xmm0_4
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128i v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm0

  *(float *)&v4 = ((float (__fastcall *)(hkaAngularReferenceFrame *))this->vfptr[2].__first_virtual_table_function__)(this);
  v5 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
  v6 = _mm_shuffle_ps((__m128)v4, (__m128)v4, 0);
  v7 = _mm_rcp_ps(v6);
  v8 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v6, v7));
  v9 = (__m128i)_mm_shuffle_ps((__m128)LODWORD(this->m_topAngle), (__m128)LODWORD(this->m_topAngle), 0);
  v10 = _mm_mul_ps(v8, v7);
  v11 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u);
  if ( v11.m128_f32[0] < 0.00000011920929 )
  {
    v12 = 0i64;
    v13 = _mm_mul_ps(v10, v5);
  }
  else
  {
    v12 = _mm_mul_ps((__m128)v9, v10);
    v13 = _mm_mul_ps(_mm_mul_ps(v11, v5), v10);
  }
  outParamVec->m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v12, v13), _mm_unpacklo_ps(aabbOut.m_quad, aabbOut.m_quad));
}

// File Line: 80
// RVA: 0xB332B0
float __fastcall hkaAngularReferenceFrame::getDistanceCovered(hkaAngularReferenceFrame *this)
{
  return (float)(COERCE_FLOAT((2
                             * _mm_shuffle_ps((__m128)LODWORD(this->m_topAngle), (__m128)LODWORD(this->m_topAngle), 0).m128_u32[0]) >> 1)
               + 1.0)
       * (float)(_mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0).m128_f32[0] + 1.0);
}

