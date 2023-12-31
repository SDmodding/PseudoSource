// File Line: 24
// RVA: 0xB33720
void __fastcall hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions::MotionExtractionOptions(
        hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *this)
{
  this->m_numSamples = 2;
  this->m_referenceFrameTransforms = 0i64;
  *(_QWORD *)&this->m_numReferenceFrameTransforms = 0i64;
  *(_DWORD *)&this->m_allowUpDown.m_bool = 256;
  this->m_up = (hkVector4f)stru_141A71280.m_quad;
  this->m_forward = (hkVector4f)transform.m_quad;
}

// File Line: 30
// RVA: 0xB34450
float __fastcall hkaDefaultAnimatedReferenceFrame::getDuration(hkaDefaultAnimatedReferenceFrame *this)
{
  return this->m_duration;
}

// File Line: 35
// RVA: 0xB34600
hkQsTransformf *__fastcall sampleReferenceFrame(
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

// File Line: 55
// RVA: 0xB33760
void __fastcall hkaDefaultAnimatedReferenceFrame::hkaDefaultAnimatedReferenceFrame(
        hkaDefaultAnimatedReferenceFrame *this,
        hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *options,
        hkaAnimatedReferenceFrame::hkaReferenceFrameTypeEnum frameType)
{
  int v3; // r15d
  __int64 v6; // rdi
  __m128 v7; // xmm1
  __m128 m_duration_low; // xmm9
  hkQsTransformf *m_referenceFrameTransforms; // rax
  __m128 m_quad; // xmm11
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  float v13; // xmm0_4
  float v14; // xmm9_4
  hkVector4f v15; // xmm2
  hkVector4f v16; // xmm0
  __m128 v17; // xmm3
  float v18; // xmm4_4
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  float v21; // xmm8_4
  float v22; // xmm7_4
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  hkOstream *v26; // rax
  int v27; // eax
  int v28; // eax
  int v29; // r9d
  __int64 v30; // r12
  __m128 v31; // xmm7
  __m128 v32; // xmm8
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  hkReferencedObject v40; // xmm0
  hkErrStream projectionOut; // [rsp+30h] [rbp-A8h] BYREF
  hkVector4f previousProjection; // [rsp+50h] [rbp-88h] BYREF
  char transform[56]; // [rsp+60h] [rbp-78h] BYREF
  char buf[600]; // [rsp+98h] [rbp-40h] BYREF
  hkResult result; // [rsp+338h] [rbp+260h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_frameType.m_storage = frameType;
  v3 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaDefaultAnimatedReferenceFrame::`vftable;
  this->m_referenceFrameSamples.m_data = 0i64;
  this->m_referenceFrameSamples.m_size = 0;
  this->m_referenceFrameSamples.m_capacityAndFlags = 0x80000000;
  LODWORD(v6) = options->m_numSamples;
  if ( (_DWORD)v6 == -1 )
    LODWORD(v6) = options->m_numReferenceFrameTransforms;
  this->m_up = options->m_up;
  this->m_forward = options->m_forward;
  v7 = 0i64;
  this->m_duration = options->m_referenceFrameDuration;
  m_duration_low = (__m128)LODWORD(this->m_duration);
  v7.m128_f32[0] = (float)(v6 - 1);
  m_referenceFrameTransforms = options->m_referenceFrameTransforms;
  previousProjection.m_quad = 0i64;
  m_quad = m_referenceFrameTransforms->m_translation.m_quad;
  v11 = m_referenceFrameTransforms->m_rotation.m_vec.m_quad;
  v12 = _mm_shuffle_ps(v7, v7, 0);
  v13 = _mm_rcp_ps(v12).m128_f32[0];
  *(hkVector4f *)&transform[40] = m_referenceFrameTransforms->m_scale;
  v14 = _mm_shuffle_ps(m_duration_low, m_duration_low, 0).m128_f32[0]
      * (float)((float)(2.0 - (float)(v12.m128_f32[0] * v13)) * v13);
  hkaDefaultAnimatedReferenceFrame::project(
    options,
    &hkQsTransformf_identityStorage,
    &previousProjection,
    (hkVector4f *)&projectionOut);
  previousProjection.m_quad = (__m128)projectionOut.hkReferencedObject;
  if ( options->m_allowTurning.m_bool )
  {
    v15.m_quad = (__m128)options->m_forward;
    v16.m_quad = (__m128)options->m_up;
    result.m_enum = LODWORD(FLOAT_0_0099999998);
    v17 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 201), v16.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 201), v15.m_quad));
    v18 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0).m128_f32[0];
    v19 = _mm_mul_ps((__m128)projectionOut.hkReferencedObject, v15.m_quad);
    v20 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), (__m128)projectionOut.hkReferencedObject);
    LODWORD(v21) = (unsigned int)(2
                                * COERCE_INT(
                                    (float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v19, v19, 170).m128_f32[0])) >> 1;
    LODWORD(v22) = (unsigned int)(2
                                * COERCE_INT(
                                    (float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v20, v20, 170).m128_f32[0])) >> 1;
    if ( v21 > v18 || v22 > v18 )
    {
      hkErrStream::hkErrStream(&projectionOut, buf, 512);
      hkOstream::operator<<(
        &projectionOut,
        "Extracting turning motion on an animation works best when the start frame is vertically aligned with the origin.");
      hkError::messageWarning(-1413836219, buf, "Motion\\Default\\hkaDefaultAnimatedReferenceFrame.cpp", 89);
      hkOstream::~hkOstream(&projectionOut);
      hkErrStream::hkErrStream(&projectionOut, buf, 512);
      v23 = hkOstream::operator<<(&projectionOut, "Some misalignment (");
      v24 = hkOstream::operator<<(v23, v21);
      v25 = hkOstream::operator<<(v24, ", ");
      v26 = hkOstream::operator<<(v25, v22);
      hkOstream::operator<<(v26, ") found.");
      hkError::messageWarning(-1413836219, buf, "Motion\\Default\\hkaDefaultAnimatedReferenceFrame.cpp", 90);
      hkOstream::~hkOstream(&projectionOut);
      hkErrStream::hkErrStream(&projectionOut, buf, 512);
      hkOstream::operator<<(
        &projectionOut,
        "For best results, try moving the animation to the origin in the Create Animations filter.");
      hkError::messageWarning(-1413836219, buf, "Motion\\Default\\hkaDefaultAnimatedReferenceFrame.cpp", 91);
      hkOstream::~hkOstream(&projectionOut);
    }
  }
  v27 = this->m_referenceFrameSamples.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v27 < (int)v6 )
  {
    v28 = 2 * v27;
    v29 = v6;
    if ( (int)v6 < v28 )
      v29 = v28;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_referenceFrameSamples, v29, 16);
  }
  this->m_referenceFrameSamples.m_size = v6;
  v6 = (int)v6;
  if ( (int)v6 > 0 )
  {
    v30 = 0i64;
    v31 = _mm_shuffle_ps(v11, v11, 201);
    v32 = _mm_shuffle_ps(v11, v11, 255);
    do
    {
      v33 = 0i64;
      v33.m128_f32[0] = (float)v3;
      sampleReferenceFrame(
        (hkQsTransformf *)&transform[8],
        _mm_shuffle_ps(v33, v33, 0).m128_f32[0] * v14,
        options->m_referenceFrameTransforms,
        options->m_numReferenceFrameTransforms,
        options->m_referenceFrameDuration);
      v34 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&transform[24], *(__m128 *)&transform[24], 201), v11),
              _mm_mul_ps(*(__m128 *)&transform[24], v31));
      v35 = _mm_mul_ps(*(__m128 *)&transform[24], v11);
      v36 = _mm_add_ps(
              _mm_sub_ps(
                _mm_shuffle_ps(v34, v34, 201),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&transform[24], *(__m128 *)&transform[24], 255), v11)),
              _mm_mul_ps(*(__m128 *)&transform[24], v32));
      v37 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 78), v35);
      v38 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, _mm_add_ps(_mm_shuffle_ps(v37, v37, 177), v37)), 196);
      v39 = _mm_sub_ps(*(__m128 *)&transform[8], m_quad);
      *(__m128 *)&transform[16] = v38;
      previousProjection.m_quad.m128_u64[1] = _mm_srli_si128(
                                                _mm_slli_si128(_mm_load_si128((const __m128i *)&query), 4),
                                                4).m128i_u64[0];
      *(__m128 *)transform = v39;
      hkaDefaultAnimatedReferenceFrame::project(
        options,
        (hkQsTransformf *)transform,
        &previousProjection,
        (hkVector4f *)&projectionOut);
      v40 = projectionOut.hkReferencedObject;
      ++v30;
      ++v3;
      this->m_referenceFrameSamples.m_data[v30 - 1] = (hkVector4f)projectionOut.hkReferencedObject;
      previousProjection.m_quad = (__m128)v40;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 123
// RVA: 0xB33BD0
void __fastcall hkaDefaultAnimatedReferenceFrame::getReferenceFrame(
        hkaDefaultAnimatedReferenceFrame *this,
        float timeR,
        hkQsTransformf *motionOut)
{
  __int64 m_size; // rcx
  __m128 v5; // xmm3
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm6
  __m128 m_quad; // xmm1
  __m128 v14; // xmm1
  int v15; // ecx
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  int v19; // eax
  __m128 v20; // xmm2
  hkSimdFloat32 angle; // [rsp+20h] [rbp-28h] BYREF

  m_size = this->m_referenceFrameSamples.m_size;
  v5 = 0i64;
  v7 = _mm_shuffle_ps((__m128)LODWORD(timeR), (__m128)LODWORD(timeR), 0);
  v8 = 0i64;
  v9 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  v8.m128_f32[0] = (float)(m_size - 1);
  v10 = _mm_shuffle_ps(v8, v8, 0);
  v11 = _mm_rcp_ps(v10);
  v12 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v11)), v11), v9);
  if ( v7.m128_f32[0] < v9.m128_f32[0] )
  {
    if ( v7.m128_f32[0] >= 0.0 )
    {
      v14 = _mm_rcp_ps(v12);
      v15 = m_size - 2;
      v16 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v12)), v14);
      v17 = 0i64;
      v18 = _mm_mul_ps(v16, v7);
      v19 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v18));
      v17.m128_f32[0] = (float)v19;
      v20 = _mm_sub_ps(v18, _mm_shuffle_ps(v17, v17, 0));
      if ( v19 > v15 )
      {
        v5.m128_f32[0] = (float)v15;
        v19 = v15;
        v20 = _mm_sub_ps(v18, _mm_shuffle_ps(v5, v5, 0));
      }
      m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     this->m_referenceFrameSamples.m_data[v19 + 1].m_quad,
                     this->m_referenceFrameSamples.m_data[v19].m_quad),
                   v20),
                 this->m_referenceFrameSamples.m_data[v19].m_quad);
    }
    else
    {
      m_quad = this->m_referenceFrameSamples.m_data->m_quad;
    }
  }
  else
  {
    m_quad = this->m_referenceFrameSamples.m_data[m_size - 1].m_quad;
  }
  motionOut->m_translation.m_quad = m_quad;
  angle.m_real = _mm_shuffle_ps(m_quad, m_quad, 255);
  hkQuaternionf::setAxisAngle(&motionOut->m_rotation, &this->m_up, &angle);
  motionOut->m_scale = (hkVector4f)query.m_quad;
}

// File Line: 174
// RVA: 0xB34460
void __fastcall hkaDefaultAnimatedReferenceFrame::project(
        hkaDefaultAnimatedReferenceFrame::MotionExtractionOptions *options,
        hkQsTransformf *transform,
        hkVector4f *previousProjection,
        __m128i *projectionOut)
{
  hkVector4f v4; // xmm4
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 m_quad; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm7
  __m128 v14; // xmm3
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 m_real; // xmm2
  float v20; // xmm1_4
  hkSimdFloat32 angleOut; // [rsp+20h] [rbp-48h] BYREF
  hkQuaternionf restOut; // [rsp+30h] [rbp-38h] BYREF

  v4.m_quad = (__m128)options->m_forward;
  v5.m_quad = (__m128)options->m_up;
  v6.m_quad = (__m128)transform->m_translation;
  v9 = _mm_mul_ps(transform->m_translation.m_quad, v5.m_quad);
  *projectionOut = 0i64;
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  m_quad = v6.m_quad;
  v12 = _mm_mul_ps(v6.m_quad, v4.m_quad);
  v13 = _mm_mul_ps(v10, v5.m_quad);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 201), v5.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 201), v4.m_quad));
  v15 = _mm_shuffle_ps(v14, v14, 201);
  v16 = _mm_mul_ps(m_quad, v15);
  v17 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
            _mm_shuffle_ps(v16, v16, 170)),
          v15);
  v18 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170)),
          v4.m_quad);
  if ( options->m_allowFrontBack.m_bool )
    *(__m128 *)projectionOut = _mm_add_ps((__m128)0i64, v18);
  if ( options->m_allowUpDown.m_bool )
    *(__m128 *)projectionOut = _mm_add_ps(v13, *(__m128 *)projectionOut);
  if ( options->m_allowRightLeft.m_bool )
    *(__m128 *)projectionOut = _mm_add_ps(v17, *(__m128 *)projectionOut);
  if ( options->m_allowTurning.m_bool )
  {
    hkQuaternionf::decomposeRestAxis(&transform->m_rotation, &options->m_up, &restOut, &angleOut);
    m_real = angleOut.m_real;
    v20 = _mm_shuffle_ps(previousProjection->m_quad, previousProjection->m_quad, 255).m128_f32[0];
    if ( (float)(angleOut.m_real.m128_f32[0] - v20) > 3.1415927 )
    {
      do
        m_real = _mm_sub_ps(m_real, (__m128)xmmword_141A713F0);
      while ( (float)(m_real.m128_f32[0] - v20) > 3.1415927 );
    }
    for ( ;
          (float)(m_real.m128_f32[0] - v20) < (float)(0.0 - 3.1415927);
          m_real = _mm_add_ps(m_real, (__m128)xmmword_141A713F0) )
    {
      ;
    }
    *(__m128 *)projectionOut = _mm_shuffle_ps(
                                 *(__m128 *)projectionOut,
                                 _mm_unpackhi_ps(*(__m128 *)projectionOut, m_real),
                                 196);
  }
  else
  {
    *projectionOut = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(projectionOut), 4), 4);
  }
}

// File Line: 241
// RVA: 0xB33CF0
void __fastcall hkaDefaultAnimatedReferenceFrame::getDeltaReferenceFrame(
        hkaDefaultAnimatedReferenceFrame *this,
        float time,
        float nextTime,
        int loops,
        hkQsTransformf *output,
        float cropStartAmount,
        float cropEndAmount)
{
  __int64 v7; // rdx
  __int64 v10; // rdx
  __int64 v11; // rdx
  __int64 v12; // rdx
  __m128 v13; // xmm2
  __m128 v14; // xmm13
  __m128i inserted; // xmm0
  __m128 v16; // xmm8
  __m128 v17; // xmm9
  __m128 v18; // xmm1
  __m128 v19; // xmm7
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm11
  __m128 v26; // xmm8
  __m128 v27; // xmm11
  __m128 v28; // xmm11
  __m128 v29; // xmm12
  __m128 v30; // xmm11
  __m128 v31; // xmm9
  BOOL v32; // esi
  unsigned int v33; // ecx
  __m128 v34; // xmm7
  __m128 v35; // xmm10
  __int64 v36; // rbx
  __m128i v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm6
  __m128 v41; // xmm4
  __m128i v42; // xmm8
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm10
  __m128 v46; // xmm3
  __m128 v47; // xmm9
  __m128 v48; // xmm1
  __m128 v49; // xmm7
  __m128 v50; // xmm9
  __m128 v51; // xmm2
  __m128 v52; // xmm5
  __m128 v53; // xmm3
  __m128 v54; // xmm6
  __m128 v55; // xmm4
  __m128 v56; // xmm10
  __m128 v57; // xmm3
  __m128 v58; // xmm3
  __m128 v59; // xmm1
  __m128 v60; // xmm2
  __m128i v61; // xmm0
  __m128 v62; // xmm8
  __m128 v63; // xmm9
  __m128 v64; // xmm1
  __m128 v65; // xmm7
  __m128 v66; // xmm5
  __m128 v67; // xmm4
  __m128 v68; // xmm3
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm3
  __m128 v72; // xmm4
  __m128 v73; // xmm8
  __m128 v74; // xmm4
  __m128 v75; // xmm3
  __m128 v76; // xmm4
  __m128 v77; // [rsp+20h] [rbp-C8h] BYREF
  __m128 v78; // [rsp+30h] [rbp-B8h]
  __m128 v79; // [rsp+40h] [rbp-A8h]
  hkVector4f v80; // [rsp+50h] [rbp-98h] BYREF
  __m256i v81; // [rsp+60h] [rbp-88h] BYREF
  hkVector4f direction; // [rsp+98h] [rbp-50h] BYREF
  hkQuaternionf quat; // [rsp+A8h] [rbp-40h] BYREF
  __m128 v84; // [rsp+B8h] [rbp-30h]
  hkVector4f v85; // [rsp+C8h] [rbp-20h] BYREF
  hkQuaternionf v86; // [rsp+D8h] [rbp-10h] BYREF
  __m128 v87; // [rsp+E8h] [rbp+0h]
  __int64 v88; // [rsp+1B8h] [rbp+D0h]
  float v89; // [rsp+1C8h] [rbp+E0h]

  *(float *)&v88 = time;
  if ( _mm_shuffle_ps((__m128)LODWORD(nextTime), (__m128)LODWORD(nextTime), 0).m128_f32[0] >= _mm_shuffle_ps(
                                                                                                (__m128)COERCE_UNSIGNED_INT(this->m_duration - v89),
                                                                                                (__m128)COERCE_UNSIGNED_INT(this->m_duration - v89),
                                                                                                0).m128_f32[0] )
  {
    *(_OWORD *)v88 = 0i64;
    *(hkQuaternionf *)(v88 + 16) = (hkQuaternionf)qi.m_vec.m_quad;
    *(hkVector4f *)(v88 + 32) = (hkVector4f)query.m_quad;
    return;
  }
  ((void (__fastcall *)(hkaDefaultAnimatedReferenceFrame *, __int64, hkVector4f *))this->vfptr[1].__first_virtual_table_function__)(
    this,
    v7,
    &v85);
  ((void (__fastcall *)(hkaDefaultAnimatedReferenceFrame *, __int64, __m128 *))this->vfptr[1].__first_virtual_table_function__)(
    this,
    v10,
    &v77);
  if ( loops )
  {
    ((void (__fastcall *)(hkaDefaultAnimatedReferenceFrame *, __int64, hkVector4f *))this->vfptr[1].__first_virtual_table_function__)(
      this,
      v11,
      &v80);
    if ( nextTime == 0.0 )
    {
      v29 = *(__m128 *)&v81.m256i_u64[2];
      v30 = *(__m128 *)v81.m256i_i8;
      v14 = (__m128)xmmword_141A711B0;
    }
    else
    {
      ((void (__fastcall *)(hkaDefaultAnimatedReferenceFrame *, __int64, hkVector4f *))this->vfptr[1].__first_virtual_table_function__)(
        this,
        v12,
        &direction);
      hkVector4f::setRotatedInverseDir((hkVector4f *)&v81.m256i_u64[1], &quat, &direction);
      v13 = _mm_rcp_ps(v84);
      v14 = (__m128)xmmword_141A711B0;
      inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v16 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), quat.m_vec.m_quad);
      v17 = (__m128)_mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v84)), v13), 4),
                      4);
      v18 = _mm_mul_ps(v80.m_quad, v16);
      v19 = _mm_shuffle_ps(v16, v16, 255);
      v20 = _mm_shuffle_ps(v16, v16, 201);
      v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v80.m_quad, v80.m_quad, 201), v16), _mm_mul_ps(v20, v80.m_quad));
      v22 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                    _mm_shuffle_ps(v18, v18, 170)),
                  v16),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v19, v19), (__m128)xmmword_141A711B0), v80.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v19));
      v80.m_quad = _mm_add_ps(
                     _mm_add_ps(v22, v22),
                     _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), *(__m128 *)&v81.m256i_u64[1]));
      v23 = _mm_shuffle_ps(*(__m128 *)v81.m256i_i8, *(__m128 *)v81.m256i_i8, 255);
      v24 = _mm_mul_ps(v23, v16);
      v25 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v81.m256i_i8, *(__m128 *)v81.m256i_i8, 201), v16);
      v26 = _mm_mul_ps(v16, *(__m128 *)v81.m256i_i8);
      v27 = _mm_sub_ps(v25, _mm_mul_ps(v20, *(__m128 *)v81.m256i_i8));
      v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 201), _mm_mul_ps(v19, *(__m128 *)v81.m256i_i8)), v24);
      v29 = _mm_mul_ps(*(__m128 *)&v81.m256i_u64[2], v17);
      v30 = _mm_shuffle_ps(
              v28,
              _mm_unpackhi_ps(
                v28,
                _mm_sub_ps(
                  _mm_mul_ps(v23, v19),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                    _mm_shuffle_ps(v26, v26, 170)))),
              196);
      *(__m128 *)v81.m256i_i8 = v30;
      *(__m128 *)&v81.m256i_u64[2] = v29;
    }
    v31 = v78;
    v32 = _mm_movemask_ps(_mm_cmple_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v30, v78), 1u), 1u), (__m128)_xmm)) == 15;
    v33 = abs32(loops);
    if ( v33 )
    {
      v34 = v79;
      v35 = v77;
      v36 = v33;
      while ( loops >= 0 )
      {
        v34 = _mm_mul_ps(v34, v29);
        v51 = _mm_mul_ps(v35, v30);
        v52 = _mm_shuffle_ps(v30, v30, 201);
        v79 = v34;
        v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v30), _mm_mul_ps(v52, v35));
        v54 = _mm_shuffle_ps(v30, v30, 255);
        v55 = _mm_shuffle_ps(v31, v31, 255);
        v56 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                      _mm_shuffle_ps(v51, v51, 170)),
                    v30),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v54, v54), v14), v35)),
                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v54));
        v35 = _mm_add_ps(_mm_add_ps(v56, v56), v80.m_quad);
        v77 = v35;
        v57 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v30), _mm_mul_ps(v52, v31));
        v58 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v57, v57, 201), _mm_mul_ps(v54, v31)), _mm_mul_ps(v55, v30));
        v59 = _mm_mul_ps(v30, v31);
        v31 = _mm_shuffle_ps(
                v58,
                _mm_unpackhi_ps(
                  v58,
                  _mm_sub_ps(
                    _mm_mul_ps(v55, v54),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
                      _mm_shuffle_ps(v59, v59, 170)))),
                196);
        v78 = v31;
        if ( v32 )
        {
          v31 = v30;
          goto LABEL_13;
        }
LABEL_14:
        if ( !--v36 )
          goto LABEL_15;
      }
      hkVector4f::setRotatedInverseDir((hkVector4f *)&v81.m256i_u64[1], (hkQuaternionf *)&v81, &v80);
      v29 = *(__m128 *)&v81.m256i_u64[2];
      v30 = *(__m128 *)v81.m256i_i8;
      v37 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v38 = _mm_rcp_ps(*(__m128 *)&v81.m256i_u64[2]);
      v14 = (__m128)xmmword_141A711B0;
      v39 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v37, 64), *(__m128 *)v81.m256i_i8);
      v40 = _mm_shuffle_ps(v39, v39, 255);
      v41 = _mm_shuffle_ps(v39, v39, 201);
      v42 = _mm_slli_si128(
              (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, *(__m128 *)&v81.m256i_u64[2])), v38),
              4);
      v43 = _mm_mul_ps(v77, v39);
      v44 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v39), _mm_mul_ps(v41, v77));
      v45 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                    _mm_shuffle_ps(v43, v43, 170)),
                  v39),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v40, v40), (__m128)xmmword_141A711B0), v77)),
              _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v40));
      v46 = _mm_shuffle_ps(v78, v78, 255);
      v35 = _mm_add_ps(
              _mm_add_ps(v45, v45),
              _mm_xor_ps((__m128)_mm_shuffle_epi32(v37, 0), *(__m128 *)&v81.m256i_u64[1]));
      v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v39), _mm_mul_ps(v41, v78));
      v48 = _mm_mul_ps(v46, v39);
      v49 = _mm_mul_ps(v39, v78);
      v50 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 201), _mm_mul_ps(v40, v78)), v48);
      v31 = _mm_shuffle_ps(
              v50,
              _mm_unpackhi_ps(
                v50,
                _mm_sub_ps(
                  _mm_mul_ps(v46, v40),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                    _mm_shuffle_ps(v49, v49, 170)))),
              196);
      v34 = _mm_mul_ps(v79, (__m128)_mm_srli_si128(v42, 4));
      v77 = v35;
      v79 = v34;
LABEL_13:
      v78 = v31;
      goto LABEL_14;
    }
  }
LABEL_15:
  hkVector4f::setRotatedInverseDir((hkVector4f *)&v81.m256i_u64[1], &v86, &v85);
  v60 = _mm_rcp_ps(v87);
  v61 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v62 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v61, 64), v86.m_vec.m_quad);
  v63 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v60, v87)), v60), 4),
                  4);
  v64 = _mm_mul_ps(v62, v77);
  v65 = _mm_shuffle_ps(v62, v62, 255);
  v66 = _mm_shuffle_ps(v62, v62, 201);
  v67 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v62), _mm_mul_ps(v77, v66));
  v68 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)), _mm_shuffle_ps(v64, v64, 170));
  v69 = v62;
  v70 = v78;
  v71 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v68, v62), _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v65, v65), (__m128)xmmword_141A711B0), v77)),
          _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v65));
  v72 = _mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v62);
  v73 = _mm_mul_ps(v62, v78);
  v74 = _mm_sub_ps(v72, _mm_mul_ps(v78, v66));
  *(__m128 *)v88 = _mm_add_ps(
                     _mm_add_ps(v71, v71),
                     _mm_xor_ps((__m128)_mm_shuffle_epi32(v61, 0), *(__m128 *)&v81.m256i_u64[1]));
  v75 = _mm_shuffle_ps(v70, v70, 255);
  v76 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v74, v74, 201), _mm_mul_ps(v70, v65)), _mm_mul_ps(v69, v75));
  *(__m128 *)(v88 + 16) = _mm_shuffle_ps(
                            v76,
                            _mm_unpackhi_ps(
                              v76,
                              _mm_sub_ps(
                                _mm_mul_ps(v75, v65),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                                  _mm_shuffle_ps(v73, v73, 170)))),
                            196);
  *(__m128 *)(v88 + 32) = _mm_mul_ps(v63, v79);
  *(hkVector4f *)(v88 + 32) = (hkVector4f)query.m_quad;
}

