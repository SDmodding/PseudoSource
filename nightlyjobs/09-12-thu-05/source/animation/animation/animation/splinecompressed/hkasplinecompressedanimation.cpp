// File Line: 27
// RVA: 0xB29A90
void __fastcall hkaSplineCompressedAnimation::~hkaSplineCompressedAnimation(hkaSplineCompressedAnimation *this)
{
  hkaSplineCompressedAnimation *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8
  int v6; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaSplineCompressedAnimation::`vftable;
  v2 = this->m_data.m_capacityAndFlags;
  this->m_data.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_data.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_data.m_data = 0i64;
  v1->m_data.m_capacityAndFlags = 2147483648;
  v3 = v1->m_floatOffsets.m_capacityAndFlags;
  v1->m_floatOffsets.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_floatOffsets.m_data,
      4 * v3);
  v1->m_floatOffsets.m_data = 0i64;
  v1->m_floatOffsets.m_capacityAndFlags = 2147483648;
  v4 = v1->m_transformOffsets.m_capacityAndFlags;
  v1->m_transformOffsets.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_transformOffsets.m_data,
      4 * v4);
  v1->m_transformOffsets.m_data = 0i64;
  v1->m_transformOffsets.m_capacityAndFlags = 2147483648;
  v5 = v1->m_floatBlockOffsets.m_capacityAndFlags;
  v1->m_floatBlockOffsets.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_floatBlockOffsets.m_data,
      4 * v5);
  v1->m_floatBlockOffsets.m_data = 0i64;
  v1->m_floatBlockOffsets.m_capacityAndFlags = 2147483648;
  v6 = v1->m_blockOffsets.m_capacityAndFlags;
  v1->m_blockOffsets.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_blockOffsets.m_data,
      4 * v6);
  v1->m_blockOffsets.m_data = 0i64;
  v1->m_blockOffsets.m_capacityAndFlags = 2147483648;
  hkaAnimation::~hkaAnimation((hkaAnimation *)&v1->vfptr);
}

// File Line: 32
// RVA: 0xB28650
hkBool *__fastcall hkaSplineCompressedAnimation::PerTrackCompressionParams::isOk(hkaSplineCompressedAnimation::PerTrackCompressionParams *this, hkBool *result)
{
  int v2; // ebx
  hkBool *v3; // rsi
  hkaSplineCompressedAnimation::PerTrackCompressionParams *v4; // rdi
  hkBool *v5; // rax
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v2 = 0;
  v3 = result;
  v4 = this;
  if ( this->m_parameterPalette.m_size <= 0 )
  {
LABEL_4:
    v3->m_bool = 1;
    v5 = v3;
  }
  else
  {
    while ( hkaSplineCompressedAnimation::TrackCompressionParams::isOk(&v4->m_parameterPalette.m_data[v2], &resulta)->m_bool )
    {
      if ( ++v2 >= v4->m_parameterPalette.m_size )
        goto LABEL_4;
    }
    v3->m_bool = 0;
    v5 = v3;
  }
  return v5;
}

// File Line: 47
// RVA: 0xB28340
hkBool *__fastcall hkaSplineCompressedAnimation::TrackCompressionParams::isOk(hkaSplineCompressedAnimation::TrackCompressionParams *this, hkBool *result)
{
  hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization v2; // er15
  hkaSplineCompressedAnimation::TrackCompressionParams *v3; // rbx
  hkBool *v4; // rdi
  bool v5; // r14
  float v6; // xmm6_4
  bool v7; // si
  hkErrStream v9; // [rsp+20h] [rbp-D0h]
  char buf; // [rsp+40h] [rbp-B0h]
  hkBool resulta; // [rsp+280h] [rbp+190h]
  void *retaddr; // [rsp+288h] [rbp+198h]
  hkBool v13; // [rsp+290h] [rbp+1A0h]
  hkBool v14; // [rsp+298h] [rbp+1A8h]

  v2 = (unsigned __int8)this->m_translationQuantizationType.m_storage;
  v3 = this;
  v4 = result;
  v5 = hkaSplineCompressedAnimation::TrackCompressionParams::validQuantization(&resulta, v2)->m_bool
    && hkaSplineCompressedAnimation::TrackCompressionParams::validQuantization(
         (hkBool *)&retaddr,
         (hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization)(unsigned __int8)v3->m_rotationQuantizationType.m_storage)->m_bool
    && hkaSplineCompressedAnimation::TrackCompressionParams::validQuantization(
         &v13,
         (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)(unsigned __int8)v3->m_scaleQuantizationType.m_storage)->m_bool
    && hkaSplineCompressedAnimation::TrackCompressionParams::validQuantization(
         &v14,
         (hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)(unsigned __int8)v3->m_floatQuantizationType.m_storage)->m_bool;
  v6 = v3->m_translationTolerance;
  v7 = v6 >= 0.0 && v3->m_rotationTolerance >= 0.0 && v3->m_scaleTolerance >= 0.0 && v3->m_floatingTolerance >= 0.0;
  if ( v6 < hkaSplineCompressedAnimation::TrackCompressionParams::approximateQuantizationAccuracy(v2) )
  {
    hkErrStream::hkErrStream(&v9, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v9.vfptr,
      "Quantization may be limiting translation quality.  If artifacts are visible, try increasing the number of translat"
      "ion quantization bits.");
    hkError::messageWarning(-1413850527, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 78);
    hkOstream::~hkOstream((hkOstream *)&v9.vfptr);
  }
  if ( hkaSplineCompressedAnimation::TrackCompressionParams::approximateQuantizationAccuracy((hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)(unsigned __int8)v3->m_scaleQuantizationType.m_storage) > v3->m_scaleTolerance )
  {
    hkErrStream::hkErrStream(&v9, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v9.vfptr,
      "Quantization may be limiting scale quality.  If artifacts are visible, try increasing the number of scale quantization bits.");
    hkError::messageWarning(-1413850527, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 83);
    hkOstream::~hkOstream((hkOstream *)&v9.vfptr);
  }
  if ( hkaSplineCompressedAnimation::TrackCompressionParams::approximateQuantizationAccuracy((hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization)(unsigned __int8)v3->m_floatQuantizationType.m_storage) > v3->m_floatingTolerance )
  {
    hkErrStream::hkErrStream(&v9, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v9.vfptr,
      "Quantization may be limiting float quality.  If artifacts are visible, try increasing the number of float quantization bits.");
    hkError::messageWarning(-1413850527, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 88);
    hkOstream::~hkOstream((hkOstream *)&v9.vfptr);
  }
  if ( (float)(hkaSplineCompressedAnimation::TrackCompressionParams::approximateQuantizationAccuracy((hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization)(unsigned __int8)v3->m_rotationQuantizationType.m_storage)
             * 0.16260162) > v3->m_rotationTolerance )
  {
    hkErrStream::hkErrStream(&v9, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v9.vfptr,
      "Quantization may be limiting rotation quality.  If artifacts are visible, try increasing the number of rotation qu"
      "antization bits.");
    hkError::messageWarning(-1413850527, &buf, "Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 99);
    hkOstream::~hkOstream((hkOstream *)&v9.vfptr);
  }
  v4->m_bool = v5 && v7;
  return v4;
}

// File Line: 112
// RVA: 0xB28300
hkBool *__fastcall hkaSplineCompressedAnimation::TrackCompressionParams::validQuantization(hkBool *result, hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type)
{
  result->m_bool = (unsigned int)type <= 5;
  return result;
}

// File Line: 125
// RVA: 0xB28320
hkBool *__fastcall hkaSplineCompressedAnimation::TrackCompressionParams::validQuantization(hkBool *result, hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type)
{
  result->m_bool = (unsigned int)type <= 1;
  return result;
}

// File Line: 131
// RVA: 0xB285C0
void __fastcall hkaSplineCompressedAnimation::TrackCompressionParams::approximateQuantizationAccuracy(hkaSplineCompressedAnimation::TrackCompressionParams::RotationQuantization type)
{
  switch ( type )
  {
    case 0:
      hkaSignedQuaternion::getApproximateAccuracySignedQuaternion32();
      break;
    case 1:
      hkaSignedQuaternion::getApproximateAccuracySignedQuaternion40();
      break;
    case 2:
      hkaSignedQuaternion::getApproximateAccuracySignedQuaternion48();
      break;
    case 3:
      hkaSignedQuaternion::getApproximateAccuracySignedQuaternion24();
      break;
    case 4:
      hkaSignedQuaternion::getApproximateAccuracySignedQuaternion16();
      break;
    case 5:
      hkaSignedQuaternion::getApproximateAccuracySignedQuaternion128();
      break;
    default:
      return;
  }
}

// File Line: 153
// RVA: 0xB28620
float __fastcall hkaSplineCompressedAnimation::TrackCompressionParams::approximateQuantizationAccuracy(hkaSplineCompressedAnimation::TrackCompressionParams::ScalarQuantization type)
{
  if ( type == BITS8 )
    return FLOAT_0_0078125;
  if ( type == 1 )
    return FLOAT_0_000030517578;
  return 0.0;
}

// File Line: 167
// RVA: 0xB29490
__int64 __fastcall hkaSplineCompressedAnimation::getNumOriginalFrames(hkaSplineCompressedAnimation *this)
{
  return (unsigned int)this->m_numFrames;
}

// File Line: 173
// RVA: 0xB29A60
signed __int64 __fastcall hkaSplineCompressedAnimation::getSizeInBytes(hkaSplineCompressedAnimation *this)
{
  return (unsigned int)this->m_data.m_size
       + 4i64
       * (unsigned int)(this->m_blockOffsets.m_size + this->m_transformOffsets.m_size + this->m_floatOffsets.m_size)
       + 176;
}

// File Line: 180
// RVA: 0xB294A0
signed __int64 __fastcall hkaSplineCompressedAnimation::getNumDataChunks(hkaSplineCompressedAnimation *this, unsigned int frame, float delta)
{
  return 3i64;
}

// File Line: 187
// RVA: 0xB294B0
void __fastcall hkaSplineCompressedAnimation::getDataChunks(hkaSplineCompressedAnimation *this, unsigned int frame, float delta, hkaAnimation::DataChunk *dataChunks)
{
  hkaSplineCompressedAnimation *v4; // r10
  signed int v5; // eax
  signed int v6; // edx
  int v7; // eax
  int v8; // er11
  int v9; // er8
  __int64 v10; // rcx
  unsigned int *v11; // rax

  dataChunks->m_data = (const char *)this;
  dataChunks->m_size = 176;
  v4 = this;
  v5 = frame / (this->m_maxFramesPerBlock - 1);
  v6 = 0;
  if ( v5 > 0 )
    v6 = v5;
  v7 = this->m_numBlocks - 1;
  v8 = this->m_numBlocks - 1;
  if ( v6 < v7 )
    v8 = v6;
  if ( v8 == v7 )
    v9 = this->m_data.m_size;
  else
    v9 = this->m_blockOffsets.m_data[v8 + 1];
  v10 = this->m_blockOffsets.m_data[v8];
  dataChunks[1].m_data = &v4->m_data.m_data[v10];
  dataChunks[1].m_size = (v9 - v10 + 15) & 0xFFFFFFF0;
  v11 = v4->m_floatBlockOffsets.m_data;
  dataChunks[2].m_size = 4;
  dataChunks[2].m_data = (const char *)&v11[v8];
}

// File Line: 217
// RVA: 0xB29540
signed __int64 __fastcall hkaSplineCompressedAnimation::getMaxSizeOfCombinedDataChunks(hkaSplineCompressedAnimation *this)
{
  int v1; // eax
  int v2; // er9
  int v3; // edx
  __int64 v4; // r8
  unsigned int *v5; // rdx
  int v6; // eax

  v1 = this->m_data.m_size;
  v2 = 0;
  v3 = this->m_blockOffsets.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &this->m_blockOffsets.m_data[v3];
    do
    {
      v6 = v1 - *v5;
      --v5;
      if ( v2 > v6 )
        v6 = v2;
      --v4;
      v2 = v6;
      v1 = v5[1];
    }
    while ( v4 >= 0 );
  }
  return ((v2 + 15) & 0xFFFFFFF0) + 192i64;
}

// File Line: 244
// RVA: 0xB286D0
void __fastcall hkaSplineCompressedAnimation::sampleTracks(hkaSplineCompressedAnimation *this, float time, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  int v4; // ST20_4

  v4 = this->m_numberOfFloatTracks;
  ((void (__fastcall *)(hkaSplineCompressedAnimation *, hkBaseObjectVtbl *, _QWORD, hkQsTransformf *, int, float *))this->vfptr[2].__vecDelDtor)(
    this,
    this->vfptr,
    (unsigned int)this->m_numberOfTransformTracks,
    transformTracksOut,
    v4,
    floatTracksOut);
}

// File Line: 259
// RVA: 0xB28700
void __fastcall hkaSplineCompressedAnimation::samplePartialTracks(hkaSplineCompressedAnimation *this, float time, unsigned int maxNumTransformTracks, hkQsTransformf *transformTracksOut, unsigned int maxNumFloatTracks, float *floatTracksOut)
{
  hkaSplineCompressedAnimation *v6; // rsi
  hkQsTransformf *v7; // r13
  unsigned int v8; // er14
  _QWORD *v9; // rax
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rcx
  _QWORD *v12; // r8
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  hkBaseObjectVtbl *v15; // rax
  signed int v16; // eax
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  unsigned int v19; // eax
  __m128 v20; // xmm1
  __m128i v21; // xmm5
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  unsigned int v25; // er10
  float v26; // xmm7_4
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  int v29; // er9
  __int64 v30; // r12
  const unsigned int *v31; // rdx
  signed int v32; // ecx
  signed int v33; // edi
  const char *v34; // rcx
  float v35; // xmm6_4
  signed int v36; // ebp
  char *v37; // rax
  const unsigned int *v38; // rdx
  const char *v39; // rcx
  char *v40; // rbx
  const char *v41; // rax
  char *v42; // rdi
  int v43; // ebx
  unsigned int v44; // er12
  unsigned int v45; // ecx
  unsigned int v46; // er14
  int v47; // er15
  int v48; // ecx
  char *v49; // rdx
  __int64 v50; // r8
  unsigned int v51; // er14
  int v52; // eax
  char *v53; // rbx
  float *v54; // rdi
  unsigned int v55; // eax
  char v56; // r9
  _QWORD *v57; // rax
  _QWORD *v58; // rcx
  _QWORD *v59; // r8
  unsigned __int64 v60; // rax
  signed __int64 v61; // rcx
  char *dataInOut; // [rsp+90h] [rbp+8h]
  float v63; // [rsp+98h] [rbp+10h]
  unsigned int v64; // [rsp+A0h] [rbp+18h]

  v64 = maxNumTransformTracks;
  v6 = this;
  v7 = transformTracksOut;
  v8 = maxNumTransformTracks;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v9[1];
  v12 = v9;
  if ( (unsigned __int64)v11 < v9[3] )
  {
    *v11 = "TtSampleSpline";
    v13 = __rdtsc();
    v10 = (unsigned __int64)HIDWORD(v13) << 32;
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = v6->vfptr;
  v63 = time;
  v16 = (unsigned __int64)((__int64 (__fastcall *)(hkaSplineCompressedAnimation *, unsigned __int64, _QWORD *))v15[4].__vecDelDtor)(
                            v6,
                            v10,
                            v12)
      - 1;
  v17 = 0i64;
  v18 = _mm_shuffle_ps((__m128)LODWORD(v6->m_duration), (__m128)LODWORD(v6->m_duration), 0);
  v17.m128_f32[0] = (float)v16;
  v19 = v16 - 1;
  v20 = _mm_rcp_ps(v18);
  v21 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v20)), v20),
                       _mm_shuffle_ps((__m128)LODWORD(v63), (__m128)LODWORD(v63), 0)),
                     _mm_shuffle_ps(v17, v17, 0)),
                   _mm_cmpltps((__m128)0i64, v18));
  v22 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v21, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v23 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v21, 1u), 1u));
  v24 = _mm_or_ps(
          _mm_andnot_ps(v23, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v21, v22)), v22)),
          _mm_and_ps((__m128)v21, v23));
  v25 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v24));
  if ( v25 <= v19 )
  {
    v27 = _mm_sub_ps((__m128)v21, v24);
    v28 = _mm_cmpltps(v27, query.m_quad);
    v26 = fmax(
            0.0,
            COERCE_FLOAT(v27.m128_i32[0] & v28.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v28, query.m_quad)));
  }
  else
  {
    v26 = *(float *)&FLOAT_1_0;
    v25 = v19;
  }
  v29 = v6->m_maxFramesPerBlock;
  v30 = 0i64;
  v31 = v6->m_blockOffsets.m_data;
  v32 = 0;
  if ( (signed int)(v25 / (v29 - 1)) > 0 )
    v32 = v25 / (v29 - 1);
  v33 = v6->m_numBlocks - 1;
  if ( v32 < v33 )
    v33 = v32;
  v34 = v6->m_data.m_data;
  v63 = *(float *)&v33;
  v35 = (float)((float)(signed int)(v25 - v33 * (v29 - 1)) + v26) * v6->m_frameDuration;
  v36 = (signed int)(float)((float)(v35 * v6->m_blockInverseDuration) * (float)(v29 - 1));
  v37 = (char *)hkaCompression::computePackedNurbsOffsets(v34, v31, v33, v6->m_maskAndQuantizationSize);
  v38 = v6->m_blockOffsets.m_data;
  v39 = v6->m_data.m_data;
  v40 = v37;
  dataInOut = v37;
  v41 = hkaCompression::computePackedNurbsOffsets(v39, v38, v33, 0x80000000);
  v42 = (char *)v41;
  if ( v40 && v41 )
  {
    v43 = 0;
    if ( v8 )
    {
      v44 = v64;
      while ( 1 )
      {
        v45 = (unsigned __int8)*v42++;
        v46 = v45 >> 6;
        v47 = (v45 >> 2) & 0xF;
        v48 = v45 & 3;
        if ( v48 )
        {
          if ( v48 != 1 )
            goto LABEL_19;
          hkaSplineCompressedAnimation::sampleTranslation<1>(
            v6,
            v35,
            v36,
            *v42,
            (const char **)&dataInOut,
            &v7[v43].m_translation);
        }
        else
        {
          hkaSplineCompressedAnimation::sampleTranslation<0>(
            v6,
            v35,
            v36,
            *v42,
            (const char **)&dataInOut,
            &v7[v43].m_translation);
        }
        ++v42;
LABEL_19:
        switch ( v47 )
        {
          case 0:
            hkaSplineCompressedAnimation::sampleRotation<0>(
              v6,
              v35,
              v36,
              *v42,
              (const char **)&dataInOut,
              &v7[v43].m_rotation);
            goto LABEL_26;
          case 1:
            hkaSplineCompressedAnimation::sampleRotation<1>(
              v6,
              v35,
              v36,
              *v42,
              (const char **)&dataInOut,
              &v7[v43].m_rotation);
            goto LABEL_26;
          case 2:
            hkaSplineCompressedAnimation::sampleRotation<2>(
              v6,
              v35,
              v36,
              *v42,
              (const char **)&dataInOut,
              &v7[v43].m_rotation);
            goto LABEL_26;
          case 3:
            hkaSplineCompressedAnimation::sampleRotation<3>(
              v6,
              v35,
              v36,
              *v42,
              (const char **)&dataInOut,
              &v7[v43].m_rotation);
            goto LABEL_26;
          case 4:
            hkaSplineCompressedAnimation::sampleRotation<4>(
              v6,
              v35,
              v36,
              *v42,
              (const char **)&dataInOut,
              &v7[v43].m_rotation);
            goto LABEL_26;
          case 5:
            hkaSplineCompressedAnimation::sampleRotation<5>(
              v6,
              v35,
              v36,
              *v42,
              (const char **)&dataInOut,
              &v7[v43].m_rotation);
LABEL_26:
            ++v42;
            break;
          default:
            break;
        }
        if ( !v46 )
        {
          hkaSplineCompressedAnimation::sampleScale<0>(v6, v35, v36, *v42, (const char **)&dataInOut, &v7[v43].m_scale);
          goto LABEL_31;
        }
        if ( v46 == 1 )
        {
          hkaSplineCompressedAnimation::sampleScale<1>(v6, v35, v36, *v42, (const char **)&dataInOut, &v7[v43].m_scale);
LABEL_31:
          ++v42;
        }
        if ( ++v43 >= v44 )
        {
          v30 = 0i64;
          break;
        }
      }
    }
    v49 = v6->m_data.m_data;
    v50 = v6->m_blockOffsets.m_data[SLODWORD(v63)];
    v51 = maxNumFloatTracks;
    v52 = 4 * v6->m_numberOfTransformTracks;
    dataInOut = &v49[v6->m_floatBlockOffsets.m_data[SLODWORD(v63)] + v50];
    v53 = &v49[v52 + v50];
    if ( maxNumFloatTracks )
    {
      v54 = floatTracksOut;
      do
      {
        v55 = (unsigned __int8)*v53++;
        v56 = v55 & 0xF9;
        if ( (v55 >> 1) & 3 )
        {
          if ( ((v55 >> 1) & 3) == 1 )
            hkaSplineCompressedAnimation::sampleFloat<1>(v6, v35, v36, v56, (const char **)&dataInOut, &v54[v30]);
        }
        else
        {
          hkaSplineCompressedAnimation::sampleFloat<0>(v6, v35, v36, v56, (const char **)&dataInOut, &v54[v30]);
        }
        v30 = (unsigned int)(v30 + 1);
      }
      while ( (unsigned int)v30 < v51 );
    }
  }
  v57 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v58 = (_QWORD *)v57[1];
  v59 = v57;
  if ( (unsigned __int64)v58 < v57[3] )
  {
    *v58 = "Et";
    v60 = __rdtsc();
    v61 = (signed __int64)(v58 + 2);
    *(_DWORD *)(v61 - 8) = v60;
    v59[1] = v61;
  }
}

// File Line: 374
// RVA: 0xB28D20
void __fastcall hkaSplineCompressedAnimation::sampleIndividualTransformTracks(hkaSplineCompressedAnimation *this, float time, const __int16 *tracks, unsigned int numTracks, hkQsTransformf *transformTracksOut)
{
  unsigned int v5; // er14
  const __int16 *v6; // rsi
  hkaSplineCompressedAnimation *v7; // rbx
  signed int v8; // eax
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  unsigned int v11; // eax
  __m128 v12; // xmm1
  __m128i v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  unsigned int v17; // er10
  float v18; // xmm0_4
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  int v21; // er9
  __int64 v22; // rdi
  signed int v23; // ecx
  signed int v24; // ebp
  float v25; // xmm6_4
  signed int v26; // er12
  hkQsTransformf *v27; // r14
  _OWORD *v28; // r15
  int v29; // esi
  int v30; // eax
  char *v31; // rax
  const unsigned int *v32; // rdx
  const char *v33; // rcx
  char *v34; // rax
  char *v35; // rsi
  unsigned int v36; // ebp
  unsigned int v37; // er13
  int v38; // eax
  char *dataInOut; // [rsp+A0h] [rbp+8h]
  float v40; // [rsp+A8h] [rbp+10h]
  const __int16 *v41; // [rsp+B0h] [rbp+18h]
  unsigned int v42; // [rsp+B8h] [rbp+20h]

  v42 = numTracks;
  v41 = tracks;
  v40 = time;
  v5 = numTracks;
  v6 = tracks;
  v7 = this;
  v8 = (unsigned __int64)((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() - 1;
  v9 = 0i64;
  v10 = _mm_shuffle_ps((__m128)LODWORD(v7->m_duration), (__m128)LODWORD(v7->m_duration), 0);
  v9.m128_f32[0] = (float)v8;
  v11 = v8 - 1;
  v12 = _mm_rcp_ps(v10);
  v13 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v12)), v12),
                       _mm_shuffle_ps((__m128)LODWORD(v40), (__m128)LODWORD(v40), 0)),
                     _mm_shuffle_ps(v9, v9, 0)),
                   _mm_cmpltps((__m128)0i64, v10));
  v14 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v13, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v15 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v13, 1u), 1u));
  v16 = _mm_or_ps(
          _mm_andnot_ps(v15, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v13, v14)), v14)),
          _mm_and_ps((__m128)v13, v15));
  v17 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v16));
  if ( v17 <= v11 )
  {
    v19 = _mm_sub_ps((__m128)v13, v16);
    v20 = _mm_cmpltps(v19, query.m_quad);
    v18 = fmax(
            0.0,
            COERCE_FLOAT(v19.m128_i32[0] & v20.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v20, query.m_quad)));
  }
  else
  {
    v18 = *(float *)&FLOAT_1_0;
    v17 = v11;
  }
  v21 = v7->m_maxFramesPerBlock;
  v22 = 0i64;
  v23 = 0;
  if ( (signed int)(v17 / (v21 - 1)) > 0 )
    v23 = v17 / (v21 - 1);
  v24 = v7->m_numBlocks - 1;
  if ( v23 < v24 )
    v24 = v23;
  v40 = *(float *)&v24;
  v25 = (float)((float)(signed int)(v17 - v24 * (v21 - 1)) + v18) * v7->m_frameDuration;
  v26 = (signed int)(float)((float)(v25 * v7->m_blockInverseDuration) * (float)(v21 - 1));
  if ( v5 )
  {
    v27 = transformTracksOut;
    v28 = (_OWORD *)transformTracksOut->m_scale.m_quad.m128_f32;
    do
    {
      if ( *v6 >= 0 )
      {
        v29 = *v6;
        v30 = v7->m_numberOfTransformTracks;
        if ( v29 < v30 )
        {
          v31 = (char *)hkaCompression::computePackedNurbsOffsets(
                          v7->m_data.m_data,
                          v7->m_blockOffsets.m_data,
                          v24,
                          v7->m_transformOffsets.m_data[v29 + v24 * v30]);
          v32 = v7->m_blockOffsets.m_data;
          v33 = v7->m_data.m_data;
          dataInOut = v31;
          v34 = (char *)hkaCompression::computePackedNurbsOffsets(v33, v32, v24, 4 * v29);
          v35 = v34;
          LODWORD(v34) = (unsigned __int8)*v34;
          v36 = (unsigned int)v34 >> 6;
          v37 = ((unsigned int)v34 >> 2) & 0xF;
          v38 = (unsigned __int8)v34 & 3;
          if ( v38 )
          {
            if ( v38 == 1 )
              hkaSplineCompressedAnimation::sampleTranslation<1>(
                v7,
                v25,
                v26,
                v35[1],
                (const char **)&dataInOut,
                &v27[v22].m_translation);
          }
          else
          {
            hkaSplineCompressedAnimation::sampleTranslation<0>(
              v7,
              v25,
              v26,
              v35[1],
              (const char **)&dataInOut,
              &v27[v22].m_translation);
          }
          switch ( v37 )
          {
            case 0u:
              hkaSplineCompressedAnimation::sampleRotation<0>(
                v7,
                v25,
                v26,
                v35[2],
                (const char **)&dataInOut,
                &v27[v22].m_rotation);
              break;
            case 1u:
              hkaSplineCompressedAnimation::sampleRotation<1>(
                v7,
                v25,
                v26,
                v35[2],
                (const char **)&dataInOut,
                &v27[v22].m_rotation);
              break;
            case 2u:
              hkaSplineCompressedAnimation::sampleRotation<2>(
                v7,
                v25,
                v26,
                v35[2],
                (const char **)&dataInOut,
                &v27[v22].m_rotation);
              break;
            case 3u:
              hkaSplineCompressedAnimation::sampleRotation<3>(
                v7,
                v25,
                v26,
                v35[2],
                (const char **)&dataInOut,
                &v27[v22].m_rotation);
              break;
            case 4u:
              hkaSplineCompressedAnimation::sampleRotation<4>(
                v7,
                v25,
                v26,
                v35[2],
                (const char **)&dataInOut,
                &v27[v22].m_rotation);
              break;
            case 5u:
              hkaSplineCompressedAnimation::sampleRotation<5>(
                v7,
                v25,
                v26,
                v35[2],
                (const char **)&dataInOut,
                &v27[v22].m_rotation);
              break;
            default:
              break;
          }
          if ( v36 )
          {
            if ( v36 == 1 )
              hkaSplineCompressedAnimation::sampleScale<1>(
                v7,
                v25,
                v26,
                v35[3],
                (const char **)&dataInOut,
                &v27[v22].m_scale);
          }
          else
          {
            hkaSplineCompressedAnimation::sampleScale<0>(
              v7,
              v25,
              v26,
              v35[3],
              (const char **)&dataInOut,
              &v27[v22].m_scale);
          }
          v6 = v41;
          v24 = LODWORD(v40);
          goto LABEL_27;
        }
        v6 = v41;
      }
      *(v28 - 2) = 0i64;
      *(v28 - 1) = 0i64;
      *v28 = 0i64;
LABEL_27:
      ++v6;
      v22 = (unsigned int)(v22 + 1);
      v28 += 3;
      v41 = v6;
    }
    while ( (unsigned int)v22 < v42 );
  }
}

// File Line: 458
// RVA: 0xB29200
void __fastcall hkaSplineCompressedAnimation::sampleIndividualFloatTracks(hkaSplineCompressedAnimation *this, float time, const __int16 *tracks, unsigned int numTracks, float *floatTracksOut)
{
  unsigned int v5; // esi
  const __int16 *v6; // r15
  hkaSplineCompressedAnimation *v7; // rbx
  signed int v8; // eax
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  unsigned int v11; // eax
  __m128 v12; // xmm1
  __m128i v13; // xmm5
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  unsigned int v17; // er10
  float v18; // xmm7_4
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  int v21; // er9
  signed int v22; // ecx
  signed int v23; // ebp
  __int64 v24; // rdi
  float v25; // xmm6_4
  signed int v26; // er13
  float *v27; // r12
  float *v28; // rsi
  int v29; // er14
  int v30; // eax
  char *v31; // rax
  const unsigned int *v32; // rdx
  const char *v33; // rcx
  unsigned int v34; // ecx
  char v35; // r9
  char *dataInOut; // [rsp+90h] [rbp+8h]
  float v37; // [rsp+98h] [rbp+10h]
  unsigned int v38; // [rsp+A8h] [rbp+20h]

  v38 = numTracks;
  v37 = time;
  v5 = numTracks;
  v6 = tracks;
  v7 = this;
  v8 = (unsigned __int64)((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() - 1;
  v9 = 0i64;
  v10 = _mm_shuffle_ps((__m128)LODWORD(v7->m_duration), (__m128)LODWORD(v7->m_duration), 0);
  v9.m128_f32[0] = (float)v8;
  v11 = v8 - 1;
  v12 = _mm_rcp_ps(v10);
  v13 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v12)), v12),
                       _mm_shuffle_ps((__m128)LODWORD(v37), (__m128)LODWORD(v37), 0)),
                     _mm_shuffle_ps(v9, v9, 0)),
                   _mm_cmpltps((__m128)0i64, v10));
  v14 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v13, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v15 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v13, 1u), 1u));
  v16 = _mm_or_ps(
          _mm_andnot_ps(v15, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v13, v14)), v14)),
          _mm_and_ps((__m128)v13, v15));
  v17 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v16));
  if ( v17 <= v11 )
  {
    v19 = _mm_sub_ps((__m128)v13, v16);
    v20 = _mm_cmpltps(v19, query.m_quad);
    v18 = fmax(
            0.0,
            COERCE_FLOAT(v19.m128_i32[0] & v20.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v20, query.m_quad)));
  }
  else
  {
    v18 = *(float *)&FLOAT_1_0;
    v17 = v11;
  }
  v21 = v7->m_maxFramesPerBlock;
  v22 = 0;
  if ( (signed int)(v17 / (v21 - 1)) > 0 )
    v22 = v17 / (v21 - 1);
  v23 = v7->m_numBlocks - 1;
  if ( v22 < v23 )
    v23 = v22;
  v24 = 0i64;
  v25 = (float)((float)(signed int)(v17 - v23 * (v21 - 1)) + v18) * v7->m_frameDuration;
  v26 = (signed int)(float)((float)(v25 * v7->m_blockInverseDuration) * (float)(v21 - 1));
  if ( v5 )
  {
    v27 = floatTracksOut;
    v28 = floatTracksOut;
    do
    {
      if ( *v6 < 0 || (v29 = *v6, v30 = v7->m_numberOfFloatTracks, v29 >= v30) )
      {
        *v28 = 0.0;
      }
      else
      {
        v31 = (char *)hkaCompression::computePackedNurbsOffsets(
                        v7->m_data.m_data,
                        v7->m_blockOffsets.m_data,
                        v23,
                        v7->m_floatOffsets.m_data[v29 + v23 * v30]);
        v32 = v7->m_blockOffsets.m_data;
        v33 = v7->m_data.m_data;
        dataInOut = v31;
        v34 = *(unsigned __int8 *)hkaCompression::computePackedNurbsOffsets(
                                    v33,
                                    v32,
                                    v23,
                                    v29 + 4 * v7->m_numberOfTransformTracks);
        v35 = v34 & 0xF9;
        if ( (v34 >> 1) & 3 )
        {
          if ( ((v34 >> 1) & 3) == 1 )
            hkaSplineCompressedAnimation::sampleFloat<1>(v7, v25, v26, v35, (const char **)&dataInOut, &v27[v24]);
        }
        else
        {
          hkaSplineCompressedAnimation::sampleFloat<0>(v7, v25, v26, v35, (const char **)&dataInOut, &v27[v24]);
        }
      }
      v24 = (unsigned int)(v24 + 1);
      ++v6;
      ++v28;
    }
    while ( (unsigned int)v24 < v38 );
  }
}

// File Line: 518
// RVA: 0xB2B870
void __fastcall hkaSplineCompressedAnimation::sampleRotation<2>(hkaSplineCompressedAnimation *this, float time, char quantizedTime, char mask, const char **dataInOut, hkQuaternionf *out)
{
  hkaSplineCompressedAnimation::readNURBSQuaternion<2>(
    this,
    dataInOut,
    quantizedTime,
    this->m_frameDuration,
    time,
    mask,
    out);
  *dataInOut = (const char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
}

// File Line: 533
// RVA: 0xB2BB30
void __fastcall hkaSplineCompressedAnimation::sampleTranslation<0>(hkaSplineCompressedAnimation *this, float time, char quantizedTime, char mask, const char **dataInOut, hkVector4f *out)
{
  float v6; // xmm3_4
  hkVector4f I; // [rsp+40h] [rbp-18h]

  if ( mask )
  {
    v6 = this->m_frameDuration;
    I.m_quad = 0i64;
    hkaSplineCompressedAnimation::readNURBSCurve<0>(this, dataInOut, quantizedTime, v6, time, mask, &I, out);
  }
  else
  {
    *out = 0i64;
  }
  *dataInOut = (const char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
}

// File Line: 561
// RVA: 0xB2BA00
void __fastcall hkaSplineCompressedAnimation::sampleScale<1>(hkaSplineCompressedAnimation *this, float time, char quantizedTime, char mask, const char **dataInOut, hkVector4f *out)
{
  if ( mask )
    hkaSplineCompressedAnimation::readNURBSCurve<1>(
      this,
      dataInOut,
      quantizedTime,
      this->m_frameDuration,
      time,
      mask,
      &query,
      out);
  else
    *out = (hkVector4f)query.m_quad;
  *dataInOut = (const char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
}

// File Line: 585
// RVA: 0xB2B720
void __fastcall hkaSplineCompressedAnimation::sampleFloat<1>(hkaSplineCompressedAnimation *this, float time, char quantizedTime, char mask, const char **dataInOut, float *out)
{
  float v6; // xmm3_4
  hkVector4f I; // [rsp+40h] [rbp-28h]
  hkVector4f v8; // [rsp+50h] [rbp-18h]

  if ( mask )
  {
    v6 = this->m_frameDuration;
    I.m_quad = 0i64;
    hkaSplineCompressedAnimation::readNURBSCurve<1>(this, dataInOut, quantizedTime, v6, time, mask, &I, &v8);
    *out = v8.m_quad.m128_f32[0];
  }
  else
  {
    *out = 0.0;
  }
  *dataInOut = (const char *)((unsigned __int64)(*dataInOut + 3) & 0xFFFFFFFFFFFFFFFCui64);
}

// File Line: 617
// RVA: 0xB29C00
__int64 __fastcall hkaSplineCompressedAnimation::readKnots(const char **dataInOut, int *_n, int *_p, char quantizedTime, float frameDuration, float *U)
{
  int *v6; // rbp
  int *v7; // r12
  __int64 v8; // r10
  const char *v9; // r11
  const char **v10; // r15
  __int64 result; // rax
  const char *v12; // r11
  int v13; // esi
  int v14; // er13
  __int64 v15; // rbx
  int v16; // er9
  int v17; // ecx
  __m128 v18; // xmm1
  float *v19; // r8
  __int64 v20; // rdx
  unsigned int v21; // ecx
  __int64 v22; // r10
  __m128i v23; // xmm0
  __int64 v24; // rdx
  float *v25; // r8
  __int64 v26; // r9
  __m128 v27; // xmm0
  int v28; // er8
  int v29; // er10
  int v30; // eax
  unsigned __int8 v31; // dl

  v6 = _p;
  v7 = _n;
  v8 = *(unsigned __int16 *)*dataInOut;
  v9 = *dataInOut + 2;
  v10 = dataInOut;
  *dataInOut = v9;
  result = *(unsigned __int8 *)v9;
  v12 = v9 + 1;
  *dataInOut = v12;
  v13 = v8;
  v14 = result + v8;
  v15 = (unsigned int)result;
  if ( (unsigned __int8)quantizedTime < v12[v8 + 1] )
  {
    if ( (unsigned __int8)quantizedTime > *v12 )
    {
      v28 = v8 + 1;
      v29 = result;
      v30 = v13 + 1 + result;
      while ( 1 )
      {
        result = v30 / 2;
        v31 = v12[(signed int)result];
        if ( (unsigned __int8)quantizedTime < v31 )
          goto LABEL_19;
        if ( (unsigned __int8)quantizedTime < v12[(signed int)result + 1] )
          break;
        if ( (unsigned __int8)quantizedTime >= v31 )
        {
          v29 = result;
          v30 = v28 + result;
        }
        else
        {
LABEL_19:
          v28 = result;
          v30 = result + v29;
        }
      }
    }
  }
  else
  {
    result = (unsigned int)v8;
  }
  v16 = 2 * v15;
  v17 = 0;
  v18 = _mm_shuffle_ps((__m128)LODWORD(frameDuration), (__m128)LODWORD(frameDuration), 0);
  if ( 2 * (signed int)v15 - 3 > 0 )
  {
    v19 = U;
    v20 = (signed int)result - (signed int)v15 + 1;
    v21 = ((unsigned int)(2 * v15 - 4) >> 2) + 1;
    v22 = v21;
    v17 = 4 * v21;
    do
    {
      v23 = (__m128i)*(unsigned int *)&v12[v20];
      v19 += 4;
      v20 += 4i64;
      *((__m128 *)v19 - 1) = _mm_mul_ps(
                               _mm_cvtepi32_ps(_mm_unpacklo_epi16(_mm_unpacklo_epi8(v23, (__m128i)0i64), (__m128i)0i64)),
                               v18);
      --v22;
    }
    while ( v22 );
  }
  v24 = v17;
  if ( v17 < v16 )
  {
    v25 = &U[v17];
    v26 = (unsigned int)(v16 - v17);
    do
    {
      v27 = 0i64;
      ++v25;
      v27.m128_f32[0] = (float)(unsigned __int8)v12[(signed int)result - v15 + ++v24];
      *(v25 - 1) = COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 0)) * v18.m128_f32[0];
      --v26;
    }
    while ( v26 );
  }
  *v6 = v15;
  *v7 = v13;
  *v10 = &v12[v14 + 2];
  return result;
}

// File Line: 672
// RVA: 0xB2AAE0
void __fastcall hkaSplineCompressedAnimation::readNURBSQuaternion<1>(hkaSplineCompressedAnimation *this, const char **dataInOut, char quantizedTime, float frameDuration, float u, char mask, hkQuaternionf *out)
{
  const char **v7; // rdi
  hkaSplineCompressedAnimation *v8; // rsi
  int v9; // eax
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int n; // [rsp+30h] [rbp-78h]
  float U; // [rsp+40h] [rbp-68h]
  hkQuaternionf P; // [rsp+60h] [rbp-48h]

  v7 = dataInOut;
  v8 = this;
  if ( mask & 0xF0 )
  {
    v9 = hkaSplineCompressedAnimation::readKnots(dataInOut, &n, (int *)&mask, quantizedTime, frameDuration, &U);
    v10 = mask;
    hkaSplineCompressedAnimation::readPackedQuaternions<1>(v8, v7, n, mask, v9, &P);
    v11 = v10 - 1;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 1 )
          hkaSplineCompressedAnimation::evaluateSimple3(u, 3, &U, &P.m_vec, &out->m_vec);
      }
      else
      {
        hkaSplineCompressedAnimation::evaluateSimple2(u, 2, &U, &P.m_vec, &out->m_vec);
      }
    }
    else
    {
      hkaSplineCompressedAnimation::evaluateSimple1(u, 1, &U, &P.m_vec, &out->m_vec);
    }
  }
  else if ( mask & 0xF )
  {
    hkaSignedQuaternion::unpackSignedQuaternion40(*dataInOut, out);
    *v7 += 5;
  }
  else
  {
    *out = (hkQuaternionf)qi.m_vec.m_quad;
  }
}

// File Line: 720
// RVA: 0xB2A710
void __fastcall hkaSplineCompressedAnimation::readNURBSCurve<0>(hkaSplineCompressedAnimation *this, const char **dataInOut, char quantizedTime, float frameDuration, float u, char mask, hkVector4f *I, hkVector4f *out)
{
  unsigned __int8 v8; // si
  const char **v9; // rbx
  int v10; // edx
  char v11; // di
  int v12; // eax
  int v13; // er9
  int v14; // er14
  unsigned __int8 v15; // r8
  const char *v16; // rax
  int v17; // xmm0_4
  int v18; // xmm1_4
  const char *v19; // rax
  int v20; // xmm0_4
  int v21; // xmm1_4
  const char *v22; // rax
  int v23; // xmm0_4
  int v24; // xmm1_4
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm5
  hkVector4f *v28; // rcx
  hkVector4f *v29; // rax
  hkVector4f v30; // xmm3
  __m128 v31; // xmm6
  unsigned __int64 v32; // rcx
  __m128 v33; // xmm8
  float v34; // edi
  char *v35; // rdx
  int v36; // ecx
  int v37; // er10
  __m128 v38; // xmm6
  __m128 v39; // xmm3
  hkVector4f *v40; // r11
  __int64 v41; // rsi
  int v42; // er8
  __m128 v43; // xmm7
  char v44; // al
  char v45; // al
  char v46; // al
  int v47; // er9
  int v48; // er9
  int _n; // [rsp+30h] [rbp-D0h]
  __m128 v50; // [rsp+40h] [rbp-C0h]
  __m128 v51; // [rsp+50h] [rbp-B0h]
  hkVector4f P; // [rsp+60h] [rbp-A0h]
  int v53; // [rsp+70h] [rbp-90h]
  int v54; // [rsp+74h] [rbp-8Ch]
  int v55; // [rsp+78h] [rbp-88h]
  int v56; // [rsp+7Ch] [rbp-84h]
  float U; // [rsp+A0h] [rbp-60h]
  int _p; // [rsp+138h] [rbp+38h]

  v8 = mask;
  v9 = dataInOut;
  v10 = 0;
  _p = 0;
  _n = 0;
  v11 = mask & 0xF0;
  if ( mask & 0xF0 )
  {
    v12 = hkaSplineCompressedAnimation::readKnots(v9, &_n, &_p, quantizedTime, frameDuration, &U);
    v13 = _p;
    v14 = _n;
    v10 = v12;
  }
  else
  {
    v13 = 0;
    v14 = 0;
  }
  v15 = v8;
  v16 = (const char *)((unsigned __int64)(*v9 + 3) & 0xFFFFFFFFFFFFFFFCui64);
  *v9 = v16;
  v51 = 0i64;
  v50 = 0i64;
  P.m_quad = 0i64;
  if ( v8 & 1 )
  {
    v51.m128_i32[0] = *(_DWORD *)v16;
  }
  else
  {
    if ( !(v8 & 0x10) )
      goto LABEL_9;
    v17 = *(_DWORD *)v16;
    v16 += 4;
    *v9 = v16;
    v18 = *(_DWORD *)v16;
    v50.m128_i32[0] = v17;
    P.m_quad.m128_i32[0] = v18;
  }
  *v9 = v16 + 4;
LABEL_9:
  if ( v8 & 2 )
  {
    v19 = *v9;
    v51.m128_i32[1] = *(_DWORD *)*v9;
  }
  else
  {
    if ( !(v8 & 0x20) )
      goto LABEL_14;
    v19 = *v9 + 4;
    v20 = *(_DWORD *)*v9;
    *v9 = v19;
    v21 = *(_DWORD *)v19;
    v50.m128_i32[1] = v20;
    P.m_quad.m128_i32[1] = v21;
  }
  *v9 = v19 + 4;
LABEL_14:
  if ( v8 & 4 )
  {
    v22 = *v9;
    v51.m128_i32[2] = *(_DWORD *)*v9;
  }
  else
  {
    if ( !(v8 & 0x40) )
      goto LABEL_19;
    v22 = *v9 + 4;
    v23 = *(_DWORD *)*v9;
    *v9 = v22;
    v24 = *(_DWORD *)v22;
    v50.m128_i32[2] = v23;
    P.m_quad.m128_i32[2] = v24;
  }
  *v9 = v22 + 4;
LABEL_19:
  v25 = v51;
  v26 = *(__m128 *)&hkVector4fComparison_maskToComparison_86[4 * (v8 & 0xF)];
  v27 = *(__m128 *)&hkVector4fComparison_maskToComparison_86[4
                                                           * ((unsigned __int8)(~v8 >> 4) & (unsigned __int8)~v8 & 0xF)];
  if ( v11 )
  {
    v31 = P.m_quad;
    v32 = (unsigned __int64)(*v9 + 1) & 0xFFFFFFFFFFFFFFFEui64;
    v53 = 1;
    v33 = v50;
    P.m_quad.m128_u64[0] = 0x100000000i64;
    P.m_quad.m128_u64[1] = 8589934593i64;
    v54 = 2;
    v55 = 2;
    v56 = 3;
    v34 = P.m_quad.m128_f32[((unsigned __int64)v8 >> 4) & 7];
    *v9 = (const char *)v32;
    _n = 0;
    v35 = (char *)(v32 + LODWORD(v34) * (v10 - v13));
    if ( v13 >= 0 )
    {
      v36 = v8 & 0x10;
      v37 = v8 & 0x20;
      v38 = _mm_sub_ps(v31, v33);
      v39 = _mm_and_ps(v25, v26);
      v40 = &P;
      v41 = (unsigned int)(v13 + 1);
      v42 = v15 & 0x40;
      v43 = _mm_and_ps(I->m_quad, v27);
      do
      {
        if ( v36 )
        {
          v44 = *v35++;
          LOBYTE(_n) = v44;
        }
        if ( v37 )
        {
          v45 = *v35++;
          BYTE1(_n) = v45;
        }
        if ( v42 )
        {
          v46 = *v35++;
          BYTE2(_n) = v46;
        }
        ++v40;
        v40[-1].m_quad = _mm_or_ps(
                           _mm_andnot_ps(
                             v27,
                             _mm_or_ps(
                               _mm_andnot_ps(
                                 v26,
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_cvtepi32_ps(
                                         _mm_unpacklo_epi16(
                                           _mm_unpacklo_epi8((__m128i)(unsigned int)_n, (__m128i)0i64),
                                           (__m128i)0i64)),
                                       (__m128)xmmword_141A71250),
                                     v38),
                                   v33)),
                               v39)),
                           v43);
        --v41;
      }
      while ( v41 );
    }
    v47 = v13 - 1;
    if ( v47 )
    {
      v48 = v47 - 1;
      if ( v48 )
      {
        if ( v48 == 1 )
          hkaSplineCompressedAnimation::evaluateSimple3(u, 3, &U, &P, out);
      }
      else
      {
        hkaSplineCompressedAnimation::evaluateSimple2(u, 2, &U, &P, out);
      }
    }
    else
    {
      hkaSplineCompressedAnimation::evaluateSimple1(u, 1, &U, &P, out);
    }
    *v9 += LODWORD(v34) * (v14 + 1);
  }
  else
  {
    v28 = out;
    v29 = I;
    v30.m_quad = _mm_or_ps(_mm_and_ps(v51, v26), _mm_andnot_ps(v26, out->m_quad));
    *out = (hkVector4f)v30.m_quad;
    v28->m_quad = _mm_or_ps(_mm_and_ps(v29->m_quad, v27), _mm_andnot_ps(v27, v30.m_quad));
  }
}

// File Line: 851
// RVA: 0xB2B540
void __fastcall hkaSplineCompressedAnimation::readPackedQuaternions<4>(hkaSplineCompressedAnimation *this, const char **dataInOut, int n, int p, int span, hkQuaternionf *P)
{
  int v6; // er14
  const char **v7; // rsi
  hkQuaternionf *v8; // rbx
  __int64 v9; // rbp
  __int64 v10; // rdi

  v6 = n;
  v7 = dataInOut;
  *dataInOut = (const char *)((unsigned __int64)(*dataInOut + 1) & 0xFFFFFFFFFFFFFFFEui64);
  if ( p >= 0 )
  {
    v8 = P;
    v9 = (unsigned int)(p + 1);
    v10 = 2 * (span - p);
    do
    {
      hkaSignedQuaternion::unpackSignedQuaternion16(&(*v7)[v10], v8);
      v10 += 2i64;
      ++v8;
      --v9;
    }
    while ( v9 );
  }
  *v7 += 2 * v6 + 2;
}

// File Line: 873
// RVA: 0xB29D90
void __fastcall hkaSplineCompressedAnimation::evaluateSimple(float uR, int p, const float *U, hkVector4f *P, hkVector4f *out)
{
  __int64 v5; // r11
  signed int v6; // er10
  hkVector4f *v7; // rbx
  const float *v8; // rdi
  int v9; // esi
  __m128 v10; // xmm7
  int v11; // er9
  __int64 v12; // rdx
  __m128 *v13; // r8
  __m128 v14; // xmm6
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __int64 v18; // rax
  __int64 v19; // rcx
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __int128 v24; // xmm4
  hkVector4f v25; // xmm1
  __int128 *v26; // rax
  signed __int64 v27; // rbx
  signed __int64 v28; // rcx
  __m128 v29; // xmm0
  __int128 v30; // [rsp+0h] [rbp-118h]
  __m128 v31; // [rsp+10h] [rbp-108h]
  __int128 v32[4]; // [rsp+20h] [rbp-F8h]
  __int128 v33[4]; // [rsp+60h] [rbp-B8h]
  char v34[48]; // [rsp+A0h] [rbp-78h]

  v5 = p;
  v6 = 1;
  v7 = P;
  v8 = U;
  v9 = p - 1;
  v31 = query.m_quad;
  v10 = _mm_shuffle_ps((__m128)LODWORD(uR), (__m128)LODWORD(uR), 0);
  if ( p >= 1 )
  {
    v11 = p - 1;
    v12 = 0i64;
    do
    {
      v13 = (__m128 *)&v34[v12 * 16];
      v14 = 0i64;
      v15 = (__m128)LODWORD(v8[v11]);
      v16 = _mm_sub_ps(v10, _mm_shuffle_ps(v15, v15, 0));
      v17 = (__m128)LODWORD(v8[v6 + v9]);
      *(__m128 *)&v34[v12 * 16] = v16;
      v33[v12] = (__int128)_mm_sub_ps(_mm_shuffle_ps(v17, v17, 0), v10);
      if ( v6 > 0 )
      {
        v18 = 0i64;
        v19 = (unsigned int)v6;
        do
        {
          v20 = (__m128)v33[v18];
          ++v18;
          --v13;
          v21 = _mm_add_ps(v20, v13[1]);
          v22 = _mm_rcp_ps(v21);
          v23 = _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22),
                  *(__m128 *)((char *)&v30 + v18 * 16));
          v24 = (__int128)_mm_add_ps(_mm_mul_ps(v20, v23), v14);
          v14 = _mm_mul_ps(v13[1], v23);
          *(__int128 *)((char *)&v30 + v18 * 16) = v24;
          --v19;
        }
        while ( v19 );
      }
      ++v6;
      v32[v12] = (__int128)v14;
      --v11;
      ++v12;
    }
    while ( v6 <= (signed int)v5 );
  }
  v25.m_quad = 0i64;
  if ( (signed int)v5 >= 0 )
  {
    v26 = (__int128 *)&v31;
    v27 = (char *)v7 - (char *)&v31;
    v28 = v5 + 1;
    do
    {
      v29 = *(__m128 *)((char *)v26 + v27);
      ++v26;
      v25.m_quad = _mm_add_ps(v25.m_quad, _mm_mul_ps(v29, (__m128)*(v26 - 1)));
      --v28;
    }
    while ( v28 );
  }
  *out = (hkVector4f)v25.m_quad;
}

// File Line: 921
// RVA: 0xB29F30
void __fastcall hkaSplineCompressedAnimation::evaluateSimple1(float uR, int p, const float *U, hkVector4f *P, hkVector4f *out)
{
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm1

  v5 = (__m128)*(unsigned __int64 *)U;
  v6 = _mm_shuffle_ps((__m128)LODWORD(uR), (__m128)LODWORD(uR), 0);
  v7 = _mm_sub_ps(v6, _mm_shuffle_ps(v5, v5, 0));
  v8 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v5, v5, 85), v6), v7);
  v9 = _mm_rcp_ps(v8);
  out->m_quad = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(P[1].m_quad, P->m_quad),
                    _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v8)), v9), v7)),
                  P->m_quad);
}

// File Line: 943
// RVA: 0xB29FA0
void __fastcall hkaSplineCompressedAnimation::evaluateSimple2(float uR, int p, const float *U, hkVector4f *P, hkVector4f *out)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm11
  __m128 v7; // xmm9
  __m128 v8; // xmm10
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm7
  __m128 v12; // xmm11
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm8

  v5 = _mm_shuffle_ps((__m128)LODWORD(uR), (__m128)LODWORD(uR), 0);
  v6 = *(__m128 *)U;
  v7 = _mm_sub_ps(_mm_shuffle_ps(v6, v6, 170), v5);
  v8 = _mm_sub_ps(v5, _mm_shuffle_ps(*(__m128 *)U, *(__m128 *)U, 85));
  v9 = _mm_add_ps(v7, v8);
  v10 = _mm_rcp_ps(v9);
  v11 = _mm_sub_ps(v5, _mm_shuffle_ps(*(__m128 *)U, *(__m128 *)U, 0));
  v12 = _mm_sub_ps(_mm_shuffle_ps(v6, v6, 255), v5);
  v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v9)), v10);
  v14 = _mm_mul_ps(v8, v13);
  v15 = _mm_mul_ps(v7, v13);
  v16 = _mm_add_ps(v11, v7);
  v17 = _mm_rcp_ps(v16);
  v18 = _mm_mul_ps(v17, v16);
  v19 = _mm_add_ps(v12, v8);
  v20 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v18), v17);
  v21 = _mm_rcp_ps(v19);
  v22 = _mm_mul_ps(v20, v15);
  v23 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v19)), v21), v14);
  out->m_quad = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v12, v23), _mm_mul_ps(v11, v22)), P[1].m_quad),
                    _mm_mul_ps(_mm_mul_ps(v7, v22), P->m_quad)),
                  _mm_mul_ps(_mm_mul_ps(v8, v23), P[2].m_quad));
}

// File Line: 1011
// RVA: 0xB2A0E0
void __fastcall hkaSplineCompressedAnimation::evaluateSimple3(float uR, int p, const float *U, hkVector4f *P, hkVector4f *out)
{
  __m128 v5; // xmm8
  __m128 v6; // xmm9
  __m128 v7; // xmm13
  __m128 v8; // xmm15
  __m128 v9; // xmm14
  __m128 v10; // xmm1
  __m128 v11; // xmm11
  __m128 v12; // xmm15
  __m128 v13; // xmm2
  __m128 v14; // xmm10
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm6
  __m128 v27; // xmm3
  __m128 v28; // xmm7
  __m128 v29; // xmm5
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm13
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  __m128 v43; // xmm12

  v5 = *(__m128 *)U;
  v6 = _mm_shuffle_ps((__m128)LODWORD(uR), (__m128)LODWORD(uR), 0);
  v7 = _mm_sub_ps(_mm_shuffle_ps(v5, v5, 255), v6);
  v8 = (__m128)*((unsigned __int64 *)U + 2);
  v9 = _mm_sub_ps(v6, _mm_shuffle_ps(*(__m128 *)U, *(__m128 *)U, 170));
  v10 = _mm_add_ps(v7, v9);
  v11 = _mm_sub_ps(_mm_shuffle_ps(v8, v8, 0), v6);
  v12 = _mm_sub_ps(_mm_shuffle_ps(v8, v8, 85), v6);
  v13 = _mm_rcp_ps(v10);
  v14 = _mm_sub_ps(v6, _mm_shuffle_ps(*(__m128 *)U, *(__m128 *)U, 85));
  v15 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v10)), v13);
  v16 = _mm_mul_ps(v7, v15);
  v17 = _mm_mul_ps(v9, v15);
  v18 = _mm_add_ps(v14, v7);
  v19 = _mm_rcp_ps(v18);
  v20 = _mm_mul_ps(v19, v18);
  v21 = _mm_add_ps(v11, v9);
  v22 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v20), v19);
  v23 = _mm_rcp_ps(v21);
  v24 = _mm_mul_ps(v22, v16);
  v25 = _mm_mul_ps(v14, v24);
  v26 = _mm_mul_ps(v7, v24);
  v27 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v21)), v23), v17);
  v28 = _mm_mul_ps(v9, v27);
  v29 = _mm_add_ps(_mm_mul_ps(v11, v27), v25);
  v30 = _mm_sub_ps(v6, _mm_shuffle_ps(v5, v5, 0));
  v31 = _mm_add_ps(v30, v7);
  v32 = _mm_rcp_ps(v31);
  v33 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v31)), v32), v26);
  v34 = _mm_mul_ps(v30, v33);
  v35 = _mm_add_ps(v11, v14);
  v36 = _mm_mul_ps(_mm_mul_ps(v7, v33), P->m_quad);
  v37 = _mm_rcp_ps(v35);
  v38 = _mm_mul_ps(v37, v35);
  v39 = _mm_add_ps(v12, v9);
  v40 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v38), v37);
  v41 = _mm_rcp_ps(v39);
  v42 = _mm_mul_ps(v40, v29);
  v43 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v39)), v41), v28);
  out->m_quad = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v12, v43), _mm_mul_ps(v14, v42)), P[2].m_quad),
                    _mm_add_ps(_mm_mul_ps(P[1].m_quad, _mm_add_ps(_mm_mul_ps(v11, v42), v34)), v36)),
                  _mm_mul_ps(_mm_mul_ps(v9, v43), P[3].m_quad));
}

// File Line: 1111
// RVA: 0xB29590
void __fastcall hkaSplineCompressedAnimation::samplePartialWithDataChunks(unsigned int frameIndex, float frameDelta, unsigned int maxNumTransformTracks, hkQsTransformf *transformTracksOut, unsigned int maxNumFloatTracks, float *floatTracksOut, hkaAnimation::DataChunk *dataChunks, int numDataChunks)
{
  unsigned int v8; // ebx
  hkQsTransformf *v9; // r13
  unsigned int v10; // ebp
  _QWORD *v11; // rax
  _QWORD *v12; // rcx
  _QWORD *v13; // r9
  unsigned __int64 v14; // rax
  signed __int64 v15; // rcx
  hkaAnimation::DataChunk *v16; // r10
  hkaSplineCompressedAnimation *v17; // rsi
  const char *v18; // rdi
  __int64 v19; // r12
  int v20; // er9
  signed int v21; // ecx
  int v22; // eax
  int v23; // eax
  unsigned int v24; // ebx
  float v25; // xmm6_4
  signed int v26; // er14
  unsigned int v27; // ecx
  unsigned int v28; // ebp
  int v29; // er15
  int v30; // ecx
  int v31; // eax
  const char *v32; // rbx
  unsigned int v33; // eax
  char v34; // r9
  _QWORD *v35; // rax
  _QWORD *v36; // rcx
  _QWORD *v37; // r8
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  char *dataInOut; // [rsp+30h] [rbp-58h]
  unsigned int v41; // [rsp+A0h] [rbp+18h]

  v41 = maxNumTransformTracks;
  v8 = frameIndex;
  v9 = transformTracksOut;
  v10 = maxNumTransformTracks;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  v13 = v11;
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "TtSampleSplineChunk";
    v14 = __rdtsc();
    v15 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v15 - 8) = v14;
    v13[1] = v15;
  }
  v16 = dataChunks;
  v17 = (hkaSplineCompressedAnimation *)dataChunks->m_data;
  v18 = dataChunks[1].m_data;
  v19 = 0i64;
  v20 = *((_DWORD *)dataChunks->m_data + 16);
  v21 = 0;
  if ( (signed int)(v8 / (v20 - 1)) > 0 )
    v21 = v8 / (v20 - 1);
  v22 = v17->m_numBlocks - 1;
  if ( v21 < v22 )
    v22 = v21;
  v23 = v8 - (v20 - 1) * v22;
  v24 = 0;
  dataInOut = (char *)&v18[v17->m_maskAndQuantizationSize];
  v25 = (float)((float)v23 + frameDelta) * v17->m_frameDuration;
  v26 = (signed int)(float)((float)(v25 * v17->m_blockInverseDuration) * (float)(v20 - 1));
  if ( v10 )
  {
    do
    {
      v27 = *(unsigned __int8 *)v18;
      v28 = v27 >> 6;
      v29 = (v27 >> 2) & 0xF;
      v30 = v27 & 3;
      if ( v30 )
      {
        if ( v30 == 1 )
          hkaSplineCompressedAnimation::sampleTranslation<1>(
            v17,
            v25,
            v26,
            v18[1],
            (const char **)&dataInOut,
            &v9[v24].m_translation);
      }
      else
      {
        hkaSplineCompressedAnimation::sampleTranslation<0>(
          v17,
          v25,
          v26,
          v18[1],
          (const char **)&dataInOut,
          &v9[v24].m_translation);
      }
      switch ( v29 )
      {
        case 0:
          hkaSplineCompressedAnimation::sampleRotation<0>(
            v17,
            v25,
            v26,
            v18[2],
            (const char **)&dataInOut,
            &v9[v24].m_rotation);
          break;
        case 1:
          hkaSplineCompressedAnimation::sampleRotation<1>(
            v17,
            v25,
            v26,
            v18[2],
            (const char **)&dataInOut,
            &v9[v24].m_rotation);
          break;
        case 2:
          hkaSplineCompressedAnimation::sampleRotation<2>(
            v17,
            v25,
            v26,
            v18[2],
            (const char **)&dataInOut,
            &v9[v24].m_rotation);
          break;
        case 3:
          hkaSplineCompressedAnimation::sampleRotation<3>(
            v17,
            v25,
            v26,
            v18[2],
            (const char **)&dataInOut,
            &v9[v24].m_rotation);
          break;
        case 4:
          hkaSplineCompressedAnimation::sampleRotation<4>(
            v17,
            v25,
            v26,
            v18[2],
            (const char **)&dataInOut,
            &v9[v24].m_rotation);
          break;
        case 5:
          hkaSplineCompressedAnimation::sampleRotation<5>(
            v17,
            v25,
            v26,
            v18[2],
            (const char **)&dataInOut,
            &v9[v24].m_rotation);
          break;
        default:
          break;
      }
      if ( v28 )
      {
        if ( v28 == 1 )
          hkaSplineCompressedAnimation::sampleScale<1>(
            v17,
            v25,
            v26,
            v18[3],
            (const char **)&dataInOut,
            &v9[v24].m_scale);
      }
      else
      {
        hkaSplineCompressedAnimation::sampleScale<0>(v17, v25, v26, v18[3], (const char **)&dataInOut, &v9[v24].m_scale);
      }
      ++v24;
      v18 += 4;
    }
    while ( v24 < v41 );
    v16 = dataChunks;
    v19 = 0i64;
  }
  v31 = 4 * v17->m_numberOfTransformTracks;
  dataChunks = (hkaAnimation::DataChunk *)&v16[1].m_data[*(unsigned int *)v16[2].m_data];
  v32 = &v16[1].m_data[v31];
  if ( maxNumFloatTracks )
  {
    do
    {
      v33 = *(unsigned __int8 *)v32++;
      v34 = v33 & 0xF9;
      if ( (v33 >> 1) & 3 )
      {
        if ( ((v33 >> 1) & 3) == 1 )
          hkaSplineCompressedAnimation::sampleFloat<1>(
            v17,
            v25,
            v26,
            v34,
            (const char **)&dataChunks,
            &floatTracksOut[v19]);
      }
      else
      {
        hkaSplineCompressedAnimation::sampleFloat<0>(
          v17,
          v25,
          v26,
          v34,
          (const char **)&dataChunks,
          &floatTracksOut[v19]);
      }
      v19 = (unsigned int)(v19 + 1);
    }
    while ( (unsigned int)v19 < maxNumFloatTracks );
  }
  v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v36 = (_QWORD *)v35[1];
  v37 = v35;
  if ( (unsigned __int64)v36 < v35[3] )
  {
    *v36 = "Et";
    v38 = __rdtsc();
    v39 = (signed __int64)(v36 + 2);
    *(_DWORD *)(v39 - 8) = v38;
    v37[1] = v39;
  }
}

