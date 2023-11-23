// File Line: 25
// RVA: 0xB2EF60
void __fastcall hkaPredictiveCompressedAnimation::TrackCompressionParams::TrackCompressionParams(
        hkaPredictiveCompressedAnimation::TrackCompressionParams *this)
{
  this->m_staticTranslationTolerance = 0.000099999997;
  this->m_staticRotationTolerance = 0.000099999997;
  this->m_staticScaleTolerance = 0.000099999997;
  this->m_staticFloatTolerance = 0.000099999997;
  *(_QWORD *)&this->m_dynamicTranslationTolerance = 953267991i64;
  this->m_dynamicScaleTolerance = 0.000099999997;
  this->m_dynamicFloatTolerance = 0.000099999997;
}

// File Line: 29
// RVA: 0xB2EFA0
void __fastcall hkaPredictiveCompressedAnimation::CompressionParams::CompressionParams(
        hkaPredictiveCompressedAnimation::CompressionParams *this)
{
  float *v2; // rax
  float *v3; // rdi
  hkaPredictiveCompressedAnimation::TrackCompressionParams *v4; // rcx
  hkaPredictiveCompressedAnimation::TrackCompressionParams v5; // [rsp+20h] [rbp-28h] BYREF

  this->m_parameterPalette.m_capacityAndFlags = 0x80000000;
  this->m_parameterPalette.m_data = 0i64;
  this->m_parameterPalette.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_data = 0i64;
  this->m_trackIndexToPaletteIndex.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  this->m_floatTrackIndexToPaletteIndex.m_data = 0i64;
  this->m_floatTrackIndexToPaletteIndex.m_size = 0;
  this->m_floatTrackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  hkaPredictiveCompressedAnimation::TrackCompressionParams::TrackCompressionParams(&v5);
  v3 = v2;
  if ( this->m_parameterPalette.m_size == (this->m_parameterPalette.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 32);
  v4 = &this->m_parameterPalette.m_data[this->m_parameterPalette.m_size];
  if ( v4 )
  {
    v4->m_staticTranslationTolerance = *v3;
    v4->m_staticRotationTolerance = v3[1];
    v4->m_staticScaleTolerance = v3[2];
    v4->m_staticFloatTolerance = v3[3];
    v4->m_dynamicTranslationTolerance = v3[4];
    v4->m_dynamicRotationTolerance = v3[5];
    v4->m_dynamicScaleTolerance = v3[6];
    v4->m_dynamicFloatTolerance = v3[7];
  }
  ++this->m_parameterPalette.m_size;
}

// File Line: 36
// RVA: 0xB2F060
void __fastcall hkaPredictiveCompressedAnimation::CompressionParams::CompressionParams(
        hkaPredictiveCompressedAnimation::CompressionParams *this,
        float staticTranslationTolerance,
        float staticRotationTolerance,
        float staticScaleTolerance,
        float staticFloatTolerance,
        float dynamicTranslationTolerance,
        float dynamicRotationTolerance,
        float dynamicScaleTolerance,
        float dynamicFloatTolerance)
{
  hkaPredictiveCompressedAnimation::TrackCompressionParams *v10; // rax
  hkaPredictiveCompressedAnimation::TrackCompressionParams v11; // [rsp+20h] [rbp-A8h] BYREF

  this->m_parameterPalette.m_capacityAndFlags = 0x80000000;
  this->m_parameterPalette.m_data = 0i64;
  this->m_parameterPalette.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_data = 0i64;
  this->m_trackIndexToPaletteIndex.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  this->m_floatTrackIndexToPaletteIndex.m_data = 0i64;
  this->m_floatTrackIndexToPaletteIndex.m_size = 0;
  this->m_floatTrackIndexToPaletteIndex.m_capacityAndFlags = 0x80000000;
  hkaPredictiveCompressedAnimation::TrackCompressionParams::TrackCompressionParams(&v11);
  if ( this->m_parameterPalette.m_size == (this->m_parameterPalette.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 32);
  v10 = &this->m_parameterPalette.m_data[this->m_parameterPalette.m_size];
  if ( v10 )
  {
    v10->m_staticTranslationTolerance = staticTranslationTolerance;
    v10->m_staticRotationTolerance = staticRotationTolerance;
    v10->m_staticScaleTolerance = staticScaleTolerance;
    v10->m_staticFloatTolerance = staticFloatTolerance;
    v10->m_dynamicTranslationTolerance = dynamicTranslationTolerance;
    v10->m_dynamicRotationTolerance = dynamicRotationTolerance;
    v10->m_dynamicScaleTolerance = dynamicScaleTolerance;
    v10->m_dynamicFloatTolerance = dynamicFloatTolerance;
  }
  ++this->m_parameterPalette.m_size;
}

// File Line: 51
// RVA: 0xB326F0
__int64 __fastcall weightFromBit(char b)
{
  return (unsigned __int8)-b;
}

// File Line: 56
// RVA: 0xB32700
void __fastcall normalize4IfManhattan(hkVector4f *q)
{
  __m128 v1; // xmm0
  __m128 v2; // xmm1
  __m128 v3; // xmm3
  __m128 v4; // xmm2

  v1 = _mm_mul_ps(q->m_quad, q->m_quad);
  v2 = _mm_add_ps(_mm_shuffle_ps(v1, v1, 78), v1);
  v3 = _mm_add_ps(_mm_shuffle_ps(v2, v2, 177), v2);
  v4 = _mm_rsqrt_ps(v3);
  q->m_quad = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v3, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v4, v3), v4)),
                    _mm_mul_ps(*(__m128 *)_xmm, v4))),
                q->m_quad);
}

// File Line: 70
// RVA: 0xB32760
void __fastcall applyWeights(const unsigned __int16 **bitmap, char *weights, int n)
{
  int v3; // r10d
  __int64 v4; // r9
  __int64 i; // r11
  int v8; // edx
  int v9; // eax
  __int64 v10; // r8
  char *v11; // rax
  char v12; // cl

  if ( weights )
  {
    v3 = n;
    v4 = 0i64;
    for ( i = n; v4 < i; v3 -= 16 )
    {
      v8 = *(*bitmap)++;
      v9 = 16;
      if ( v3 < 16 )
        v9 = v3;
      v10 = v9;
      if ( v9 > 0 )
      {
        v11 = &weights[v4];
        do
        {
          v12 = v8;
          v8 >>= 1;
          *v11++ &= -(v12 & 1);
          --v10;
        }
        while ( v10 );
      }
      v4 += 16i64;
    }
  }
}

// File Line: 90
// RVA: 0xB32810
void __fastcall dequantize8(
        const __m128i *quant,
        hkVector4f *f_leftscale,
        hkVector4f *f_rightscale,
        hkVector4f *f_leftoff,
        hkVector4f *f_rightoff,
        hkVector4f *out_left,
        hkVector4f *out_right)
{
  __m128i si128; // xmm0

  si128 = _mm_load_si128(quant);
  out_left->m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(si128, (__m128i)0i64), 0x10u), 0x10u)),
                         f_leftscale->m_quad),
                       f_leftoff->m_quad);
  out_right->m_quad = _mm_add_ps(
                        _mm_mul_ps(
                          _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(si128, (__m128i)0i64), 0x10u), 0x10u)),
                          f_rightscale->m_quad),
                        f_rightoff->m_quad);
}

// File Line: 108
// RVA: 0xB32870
void __fastcall lerp(hkVector4f *a, hkSimdFloat32 *aw, hkVector4f *b, hkSimdFloat32 *bw, hkVector4f *out)
{
  __m128 v5; // xmm1

  v5 = _mm_mul_ps(a->m_quad, aw->m_real);
  *out = (hkVector4f)v5;
  out->m_quad = _mm_add_ps(_mm_mul_ps(b->m_quad, bw->m_real), v5);
}

// File Line: 168
// RVA: 0xB328A0
void __fastcall expandParams(
        unsigned __int16 *fixed,
        hkVector4f *scale,
        hkVector4f *offset,
        float **scalePtr,
        float **offsetPtr,
        hkSimdFloat32 *fixedScale,
        hkSimdFloat32 *fixedOffset)
{
  __int64 v7; // r10
  __int64 v9; // rdi
  __int64 v10; // rbx
  __m128 m_real; // xmm1
  float *v12; // rcx
  float *v13; // rcx
  hkVector4f v14; // xmm1
  hkVector4f v15; // [rsp+0h] [rbp-28h]
  __m128 v16; // [rsp+10h] [rbp-18h]

  v7 = 0i64;
  v9 = 4i64;
  v10 = 0i64;
  do
  {
    if ( (*(_BYTE *)fixed & 1) != 0 )
    {
      m_real = fixedOffset->m_real;
      v15.m_quad.m128_i32[v7] = (int)*fixedScale;
      v16.m128_i32[v7] = m_real.m128_i32[0];
    }
    else
    {
      v12 = *scalePtr;
      v15.m_quad.m128_f32[v10] = **scalePtr;
      *scalePtr = v12 + 1;
      v13 = *offsetPtr;
      v16.m128_f32[v10] = **offsetPtr;
      *offsetPtr = v13 + 1;
    }
    *fixed >>= 1;
    ++v7;
    ++v10;
    --v9;
  }
  while ( v9 );
  v14.m_quad = v16;
  *scale = (hkVector4f)v15.m_quad;
  *offset = (hkVector4f)v14.m_quad;
}

// File Line: 212
// RVA: 0xB32960
void __fastcall loadDynamicData(
        const char **compressedData,
        int frame,
        const bool singleFrame,
        const float **scalePtr,
        const float **offsetPtr,
        const unsigned __int16 **isFixedRange,
        __m128 *scratchSpace)
{
  _QWORD *Value; // rcx
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rax
  const char *v14; // rcx
  const char *v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  __int64 v20; // r9
  __int64 v21; // rdi
  unsigned __int16 v22; // dx
  __int64 v23; // r10
  __int64 v24; // r11
  __int64 v25; // rsi
  int *v26; // rcx
  int *v27; // rcx
  __m128 v28; // xmm8
  __int64 v29; // r10
  __int64 v30; // r11
  __int64 v31; // rsi
  int *v32; // rcx
  int *v33; // rcx
  __m128 v34; // xmm6
  __m128 v35; // xmm7
  __int64 v36; // r10
  __int64 v37; // r11
  __int64 v38; // rsi
  int *v39; // rcx
  int *v40; // rcx
  __m128 v41; // xmm4
  __m128 v42; // xmm5
  __int64 v43; // r10
  int *v44; // rcx
  int *v45; // rcx
  __m128i si128; // xmm0
  __m128 v47; // xmm10
  __m128 v48; // xmm9
  __m128i v49; // xmm0
  __m128 v50; // xmm10
  __m128 v51; // xmm9
  __m128 v52; // xmm11
  __m128 v53; // xmm12
  __m128i v54; // xmm0
  __m128i v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm8
  __m128 v58; // xmm7
  __m128 v59; // xmm6
  __m128 v60; // xmm3
  __m128 v61; // xmm1
  __m128 v62; // xmm4
  __m128 v63; // xmm0
  __m128 v64; // xmm2
  __m128 v65; // xmm5
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  _QWORD *v69; // rcx
  __m256i v70; // [rsp+18h] [rbp-79h]
  void *retaddr; // [rsp+D8h] [rbp+47h]
  int **v72; // [rsp+E8h] [rbp+57h]
  unsigned __int16 **v73; // [rsp+F0h] [rbp+5Fh]
  __m128i *frameData; // [rsp+F8h] [rbp+67h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = Value[1];
  if ( v12 < Value[3] )
  {
    *(_QWORD *)v12 = "LtloadDynamic";
    *(_QWORD *)(v12 + 16) = "StDecompress";
    v13 = __rdtsc();
    *(_DWORD *)(v12 + 8) = v13;
    Value[1] = v12 + 24;
  }
  v14 = *compressedData;
  if ( singleFrame )
    v15 = hkaPredictiveBlockCompression::decodeSingleFrame(v14, frame, frameData->m128i_i16);
  else
    v15 = hkaPredictiveBlockCompression::decodeAdjacentFrames(v14, frame, frameData->m128i_i16);
  *compressedData = v15;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "StDequantize";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
  *(float *)&retaddr = FLOAT_0_00012208521;
  v20 = 0i64;
  v21 = 4i64;
  v22 = **v73;
  v23 = 0i64;
  v24 = 0i64;
  ++*v73;
  v25 = 4i64;
  do
  {
    if ( (v22 & 1) != 0 )
    {
      *(float *)&v70.m256i_i32[v23 + 4] = FLOAT_0_00012208521;
      v70.m256i_i32[v23 + 2] = 0;
    }
    else
    {
      v26 = (int *)*scalePtr;
      *(float *)&v70.m256i_i32[v24 + 4] = **scalePtr;
      *scalePtr = (const float *)(v26 + 1);
      v27 = *v72;
      v70.m256i_i32[v24 + 2] = **v72;
      *v72 = v27 + 1;
    }
    v22 >>= 1;
    ++v23;
    ++v24;
    --v25;
  }
  while ( v25 );
  v28 = *(__m128 *)&v70.m256i_u64[2];
  v29 = 0i64;
  v30 = 0i64;
  v31 = 4i64;
  do
  {
    if ( (v22 & 1) != 0 )
    {
      *(float *)&v70.m256i_i32[v29 + 4] = FLOAT_0_00012208521;
      v70.m256i_i32[v29] = 0;
    }
    else
    {
      v32 = (int *)*scalePtr;
      *(float *)&v70.m256i_i32[v30 + 4] = **scalePtr;
      *scalePtr = (const float *)(v32 + 1);
      v33 = *v72;
      v70.m256i_i32[v30] = **v72;
      *v72 = v33 + 1;
    }
    v22 >>= 1;
    ++v29;
    ++v30;
    --v31;
  }
  while ( v31 );
  v34 = *(__m128 *)&v70.m256i_u64[2];
  v35 = *(__m128 *)v70.m256i_i8;
  v36 = 0i64;
  v37 = 0i64;
  v38 = 4i64;
  do
  {
    if ( (v22 & 1) != 0 )
    {
      *(float *)&v70.m256i_i32[v36 + 4] = FLOAT_0_00012208521;
      v70.m256i_i32[v36] = 0;
    }
    else
    {
      v39 = (int *)*scalePtr;
      *(float *)&v70.m256i_i32[v37 + 4] = **scalePtr;
      *scalePtr = (const float *)(v39 + 1);
      v40 = *v72;
      v70.m256i_i32[v37] = **v72;
      *v72 = v40 + 1;
    }
    v22 >>= 1;
    ++v36;
    ++v37;
    --v38;
  }
  while ( v38 );
  v41 = *(__m128 *)&v70.m256i_u64[2];
  v42 = *(__m128 *)v70.m256i_i8;
  v43 = 0i64;
  do
  {
    if ( (v22 & 1) != 0 )
    {
      *(float *)&v70.m256i_i32[v20] = FLOAT_0_00012208521;
      v70.m256i_i32[v20 + 4] = 0;
    }
    else
    {
      v44 = (int *)*scalePtr;
      *(float *)&v70.m256i_i32[v43] = **scalePtr;
      *scalePtr = (const float *)(v44 + 1);
      v45 = *v72;
      v70.m256i_i32[v43 + 4] = **v72;
      *v72 = v45 + 1;
    }
    v22 >>= 1;
    ++v20;
    ++v43;
    --v21;
  }
  while ( v21 );
  si128 = _mm_load_si128(frameData);
  v47 = _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(si128, (__m128i)0i64), 0x10u), 0x10u));
  v48 = _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(si128, (__m128i)0i64), 0x10u), 0x10u));
  v49 = _mm_load_si128(frameData + 1);
  v50 = _mm_add_ps(_mm_mul_ps(v47, v34), v35);
  v51 = _mm_add_ps(_mm_mul_ps(v48, v28), *(__m128 *)&v70.m256i_u64[1]);
  v52 = _mm_add_ps(
          _mm_mul_ps(
            _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v49, (__m128i)0i64), 0x10u), 0x10u)),
            v41),
          v42);
  v53 = _mm_add_ps(
          _mm_mul_ps(
            _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v49, (__m128i)0i64), 0x10u), 0x10u)),
            *(__m128 *)v70.m256i_i8),
          *(__m128 *)&v70.m256i_u64[2]);
  if ( singleFrame )
  {
    *((__m128 *)offsetPtr + 8) = v51;
    *((__m128 *)offsetPtr + 9) = v50;
    *((__m128 *)offsetPtr + 10) = v52;
    *((__m128 *)offsetPtr + 11) = v53;
  }
  else
  {
    *(__m128 *)offsetPtr = v51;
    *((__m128 *)offsetPtr + 1) = v50;
    *((__m128 *)offsetPtr + 2) = v52;
    *((__m128 *)offsetPtr + 3) = v53;
    v54 = _mm_load_si128(frameData + 2);
    v55 = _mm_load_si128(frameData + 3);
    v56 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v54, (__m128i)0i64), 0x10u), 0x10u)),
              v28),
            *(__m128 *)&v70.m256i_u64[1]);
    *((__m128 *)offsetPtr + 4) = v56;
    v57 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v54, (__m128i)0i64), 0x10u), 0x10u)),
              v34),
            v35);
    *((__m128 *)offsetPtr + 5) = v57;
    v58 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v55, (__m128i)0i64), 0x10u), 0x10u)),
              v41),
            v42);
    v59 = _mm_add_ps(
            _mm_mul_ps(
              _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v55, (__m128i)0i64), 0x10u), 0x10u)),
              *(__m128 *)v70.m256i_i8),
            *(__m128 *)&v70.m256i_u64[2]);
    *((__m128 *)offsetPtr + 6) = v58;
    *((__m128 *)offsetPtr + 7) = v59;
    v60 = *(__m128 *)isFixedRange;
    v61 = _mm_mul_ps(*scratchSpace, v58);
    v62 = _mm_add_ps(_mm_mul_ps(*scratchSpace, v56), _mm_mul_ps(*(__m128 *)isFixedRange, v51));
    v63 = _mm_mul_ps(*(__m128 *)isFixedRange, v50);
    v64 = _mm_mul_ps(*scratchSpace, v57);
    v65 = _mm_mul_ps(*scratchSpace, v59);
    *((__m128 *)offsetPtr + 8) = v62;
    *((__m128 *)offsetPtr + 9) = _mm_add_ps(v64, v63);
    *((__m128 *)offsetPtr + 10) = _mm_add_ps(v61, _mm_mul_ps(v60, v52));
    *((__m128 *)offsetPtr + 11) = _mm_add_ps(v65, _mm_mul_ps(v60, v53));
  }
  v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v67 = (_QWORD *)v66[1];
  if ( (unsigned __int64)v67 < v66[3] )
  {
    *v67 = "lt";
    v68 = __rdtsc();
    v69 = v67 + 2;
    *((_DWORD *)v69 - 2) = v68;
    v66[1] = v69;
  }
}    *v67 = "lt";
    v68 = __rdtsc();
    v69 = v67 + 2;
    *((_DWORD *)v69 - 2) = v68;
    v66[1] = v69;
  }
}

// File Line: 291
// RVA: 0xB32660
void __fastcall hkaPredictiveCompressedAnimation::getCompressedDataOffset(
        hkaPredictiveCompressedAnimation *this,
        unsigned int frame,
        unsigned int *start,
        unsigned int *end)
{
  __int64 v4; // r11

  *start = 0;
  v4 = frame / 0xF;
  if ( (_DWORD)v4 )
    *start = *(_DWORD *)&this->m_intData.m_data[2 * (int)v4 - 2 + this->m_intArrayOffsets[0]];
  *end = *(_DWORD *)&this->m_intData.m_data[2 * v4 + this->m_intArrayOffsets[0]];
}

// File Line: 313
// RVA: 0xB2F9E0
void __fastcall hkaPredictiveCompressedAnimation::sampleFullPose(
        hkaPredictiveCompressedAnimation *this,
        unsigned int frameIndex,
        float frameDelta,
        const char *compressedData,
        hkQsTransformf *refBones,
        const float *refFloats,
        int numBones,
        __int64 numFloats,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        char *boneWeightsInOut,
        char *floatWeightsInOut)
{
  hkaPredictiveCompressedAnimation *v12; // r15
  const char *v13; // r12
  _QWORD *Value; // r8
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // r8
  int v21; // r9d
  __int64 v22; // rax
  unsigned int v23; // ebx
  char v24; // al
  __m128 v25; // xmm8
  __m128 *p_m_quad; // rax
  __m128 v27; // xmm9
  float *m_data; // rcx
  int *v29; // rdi
  __int64 v30; // rax
  __int64 v31; // rsi
  __int64 v32; // rax
  __int64 v33; // rdx
  unsigned __int16 *v34; // rcx
  __int64 v35; // rax
  __int64 v36; // rdx
  __int64 v37; // rax
  hkLifoAllocator *v38; // rax
  __m128i *v39; // rbx
  hkLifoAllocator *v40; // rax
  bool v41; // cc
  __m128 *m_cur; // r14
  __m128 *v43; // rcx
  float *v44; // r13
  __int64 v45; // rbx
  unsigned __int16 *v46; // r9
  unsigned __int64 v47; // r10
  int v48; // r11d
  int v49; // edx
  int v50; // eax
  __int64 v51; // r8
  float *v52; // rcx
  char v53; // al
  __int64 v54; // r13
  __int64 v55; // r10
  char *v56; // r14
  int v57; // r11d
  int v58; // edx
  int v59; // eax
  __int64 v60; // r8
  char *v61; // rcx
  char v62; // al
  int v63; // r13d
  unsigned int v64; // ebx
  hkLifoAllocator *v65; // rax
  char *v66; // r15
  int v67; // r12d
  char *v68; // rcx
  hkLifoAllocator *v69; // rax
  __m128 *v70; // rbx
  char *v71; // rcx
  __int64 v72; // rdx
  __int64 v73; // rax
  _QWORD *v74; // rax
  _QWORD *v75; // rcx
  _QWORD *v76; // r8
  unsigned __int64 v77; // rax
  _QWORD *v78; // rcx
  __int64 v79; // r10
  __int64 v80; // r12
  __int64 v81; // rdx
  signed __int64 v82; // r8
  __int128 *v83; // rcx
  signed __int64 v84; // r9
  __int128 v85; // xmm0
  __int128 v86; // xmm1
  __int128 v87; // xmm2
  _QWORD *v88; // r8
  _QWORD *v89; // rcx
  unsigned __int64 v90; // rax
  _QWORD *v91; // rcx
  int v92; // r10d
  char *v93; // r11
  int *v94; // rcx
  int v95; // r8d
  __int64 v96; // rdx
  int v97; // xmm0_4
  int v98; // xmm0_4
  _QWORD *v99; // r8
  _QWORD *v100; // rcx
  unsigned __int64 v101; // rax
  _QWORD *v102; // rcx
  __int64 v103; // rbx
  int v104; // r15d
  _QWORD *v105; // rax
  unsigned __int64 v106; // rcx
  _QWORD *v107; // r8
  unsigned __int64 v108; // rax
  const char *v109; // rax
  _QWORD *v110; // r8
  _QWORD *v111; // rcx
  unsigned __int64 v112; // rax
  _QWORD *v113; // rcx
  __int64 v114; // r8
  unsigned __int16 v115; // cx
  __int64 v116; // rdx
  __int64 v117; // r9
  int v118; // eax
  __m128 v119; // xmm12
  __m128 v120; // xmm13
  __int64 v121; // r8
  __int64 v122; // rdx
  __int64 v123; // r9
  int v124; // eax
  __m128 v125; // xmm10
  __m128 v126; // xmm11
  __int64 v127; // r8
  __int64 v128; // rdx
  __int64 v129; // r9
  int v130; // eax
  __m128 v131; // xmm6
  __m128 v132; // xmm7
  __int64 v133; // r8
  __int64 v134; // rdx
  __int64 v135; // r9
  int v136; // eax
  __m128 v137; // xmm5
  __m128 v138; // xmm1
  _QWORD *v139; // r8
  _QWORD *v140; // rcx
  unsigned __int64 v141; // rax
  _QWORD *v142; // rcx
  int v143; // ecx
  int v144; // r9d
  __int64 v145; // r8
  __int64 v146; // r10
  _DWORD *v147; // rdi
  __int64 v148; // rsi
  __m128 *v149; // rdx
  int v150; // xmm0_4
  int v151; // xmm1_4
  int v152; // xmm0_4
  int v153; // xmm1_4
  _QWORD *v154; // r8
  _QWORD *v155; // rcx
  unsigned __int64 v156; // rax
  _QWORD *v157; // rcx
  int v158; // r11d
  int v159; // ecx
  signed int v160; // eax
  __int64 v161; // rbx
  int v162; // r9d
  unsigned __int16 *v163; // r10
  __int64 v164; // r8
  __int64 v165; // rdx
  __int64 v166; // rcx
  __int64 v167; // r9
  __m128 v168; // xmm5
  __m128 v169; // xmm6
  __m128 v170; // xmm0
  __m128 v171; // xmm5
  __m128i v172; // xmm15
  __m128i v173; // xmm5
  __m128i v174; // xmm6
  __m128 v175; // xmm3
  __m128 v176; // xmm13
  __m128 v177; // xmm15
  __m128 v178; // xmm2
  __m128 v179; // xmm0
  __m128 v180; // xmm3
  __m128 v181; // xmm0
  __m128 v182; // xmm6
  __m128 v183; // xmm11
  __m128 v184; // xmm13
  __m128 v185; // xmm12
  __m128 v186; // xmm0
  __m128 v187; // xmm15
  __m128 v188; // xmm1
  __m128 v189; // xmm9
  __m128 v190; // xmm1
  __m128 v191; // xmm0
  __m128 v192; // xmm7
  __m128 v193; // xmm1
  __m128 v194; // xmm1
  __m128 v195; // xmm5
  __m128 v196; // xmm0
  __m128 v197; // xmm1
  __m128 v198; // xmm6
  __m128 v199; // xmm1
  __m128 v200; // xmm3
  __m128 v201; // xmm0
  __m128 v202; // xmm1
  __m128 v203; // xmm4
  __m128 v204; // xmm2
  __m128 v205; // xmm0
  __int64 v206; // r9
  __int64 v207; // rdx
  int v208; // ecx
  __int64 v209; // r8
  __int64 v210; // rcx
  __m128 v211; // xmm2
  __m128 v212; // xmm3
  __m128 v213; // xmm0
  __m128 v214; // xmm6
  __m128 v215; // xmm0
  __m128 v216; // xmm1
  __m128 v217; // xmm2
  __m128 v218; // xmm3
  __int64 v219; // rcx
  __m128 v220; // xmm1
  __m128 v221; // xmm3
  __m128 v222; // xmm0
  __m128 v223; // xmm6
  __m128 v224; // xmm0
  __m128 v225; // xmm1
  __m128 v226; // xmm2
  __m128 v227; // xmm3
  __m128 *v228; // r13
  hkLifoAllocator *v229; // rax
  int v230; // r12d
  int v231; // ebx
  __int64 v232; // rbx
  int v233; // r9d
  __m128 *v234; // r10
  unsigned __int16 *v235; // r14
  __int64 v236; // r8
  __int64 v237; // rcx
  __int64 v238; // rdx
  __int64 v239; // r9
  __m128 v240; // xmm8
  __m128 v241; // xmm12
  __m128 v242; // xmm0
  __m128i v243; // xmm4
  __m128i v244; // xmm12
  __m128i v245; // xmm7
  __m128i v246; // xmm3
  __m128 v247; // xmm13
  __m128 v248; // xmm12
  __m128 v249; // xmm0
  __m128 v250; // xmm13
  __m128 v251; // xmm4
  __m128 v252; // xmm11
  __m128 v253; // xmm2
  __m128 v254; // xmm0
  __m128 v255; // xmm2
  __m128 v256; // xmm0
  __m128 v257; // xmm7
  __m128 v258; // xmm10
  __m128 v259; // xmm0
  __m128 v260; // xmm8
  __m128i v261; // xmm15
  __m128i v262; // xmm4
  __m128i v263; // xmm11
  __m128 v264; // xmm7
  __m128 v265; // xmm2
  __m128 v266; // xmm0
  __m128 v267; // xmm12
  __m128 v268; // xmm2
  __m128 v269; // xmm0
  __m128 v270; // xmm11
  __m128 v271; // xmm6
  __m128 v272; // xmm7
  __m128 v273; // xmm1
  __m128 v274; // xmm12
  __m128 v275; // xmm4
  __m128 v276; // xmm0
  __m128 v277; // xmm2
  __m128 v278; // xmm5
  __m128 v279; // xmm4
  __m128 v280; // xmm3
  __m128 v281; // xmm2
  __m128 v282; // xmm3
  __m128 v283; // xmm15
  __m128 v284; // xmm0
  __m128 v285; // xmm1
  __m128 v286; // xmm13
  __m128 v287; // xmm1
  __m128 v288; // xmm9
  __m128 v289; // xmm10
  __m128 v290; // xmm0
  __m128 v291; // xmm1
  __m128 v292; // xmm2
  __m128 v293; // xmm1
  __m128 v294; // xmm8
  __m128 v295; // xmm6
  __m128 v296; // xmm7
  __m128 v297; // xmm0
  __m128 v298; // xmm1
  __m128 v299; // xmm2
  __m128 v300; // xmm1
  __m128 v301; // xmm5
  __m128 v302; // xmm4
  __m128 v303; // xmm0
  __m128 v304; // xmm1
  __m128 v305; // xmm2
  __m128 v306; // xmm1
  char *v307; // rdx
  __int64 v308; // r8
  int v309; // ecx
  __int64 v310; // r9
  __int64 v311; // rcx
  __m128 v312; // xmm2
  __m128 v313; // xmm2
  __m128 v314; // xmm0
  __m128 v315; // xmm0
  __m128 v316; // xmm2
  __m128 v317; // xmm7
  __m128 v318; // xmm2
  __m128 v319; // xmm0
  __m128 v320; // xmm4
  __m128 v321; // xmm0
  __m128 v322; // xmm1
  __m128 v323; // xmm5
  __m128 v324; // xmm0
  __m128 v325; // xmm1
  __m128 v326; // xmm2
  __m128 v327; // xmm3
  __int64 v328; // rcx
  __m128 v329; // xmm2
  __m128 v330; // xmm2
  __m128 v331; // xmm0
  __m128 v332; // xmm1
  __m128 v333; // xmm2
  __m128 v334; // xmm7
  __m128 v335; // xmm2
  __m128 v336; // xmm0
  __m128 v337; // xmm4
  __m128 v338; // xmm0
  __m128 v339; // xmm1
  __m128 v340; // xmm5
  __m128 v341; // xmm0
  __m128 v342; // xmm1
  __m128 v343; // xmm3
  hkLifoAllocator *v344; // r9
  _QWORD *v345; // r8
  _QWORD *v346; // rcx
  unsigned __int64 v347; // rax
  _QWORD *v348; // rcx
  hkQsTransformf *v349; // rcx
  hkQsTransformf *v350; // rbx
  __int64 v351; // rdx
  signed __int64 v352; // r8
  int v353; // eax
  _QWORD *v354; // r8
  _QWORD *v355; // rcx
  unsigned __int64 v356; // rax
  _QWORD *v357; // rcx
  unsigned __int16 *v358; // rdx
  __int64 v359; // rcx
  unsigned __int16 *v360; // r10
  int v361; // eax
  int v362; // ecx
  int *v363; // rdx
  __int64 v364; // r8
  int v365; // eax
  __int64 v366; // r9
  int v367; // eax
  _QWORD *v368; // r8
  _QWORD *v369; // rcx
  unsigned __int64 v370; // rax
  _QWORD *v371; // rcx
  __int64 m_firstFloatBlockScaleAndOffsetIndex; // rcx
  float *v373; // rdx
  int v374; // ecx
  int v375; // r10d
  signed int v376; // ecx
  int v377; // r13d
  _QWORD *v378; // r8
  unsigned __int64 v379; // rcx
  unsigned __int64 v380; // rax
  const char *v381; // rax
  _QWORD *v382; // r8
  _QWORD *v383; // rcx
  unsigned __int64 v384; // rax
  _QWORD *v385; // rcx
  __int64 v386; // r8
  unsigned __int16 v387; // cx
  __int64 v388; // rdx
  __int64 v389; // r9
  int v390; // eax
  __m128 v391; // xmm12
  __m128 v392; // xmm13
  __int64 v393; // r8
  __int64 v394; // rdx
  __int64 v395; // r9
  int v396; // eax
  __m128 v397; // xmm10
  __m128 v398; // xmm11
  __int64 v399; // r8
  __int64 v400; // rdx
  __int64 v401; // r9
  int v402; // eax
  __m128 v403; // xmm6
  __m128 v404; // xmm7
  __int64 v405; // r8
  __int64 v406; // rdx
  __int64 v407; // r9
  int v408; // eax
  __m128 v409; // xmm5
  __m128 v410; // xmm1
  _QWORD *v411; // rax
  _QWORD *v412; // rcx
  _QWORD *v413; // r8
  unsigned __int64 v414; // rax
  _QWORD *v415; // rcx
  __int64 v416; // r8
  __int64 v417; // r15
  int v418; // ecx
  int v419; // r9d
  __int64 v420; // rdx
  int v421; // eax
  __int64 v422; // rax
  __int64 v423; // rbx
  int v424; // r15d
  _QWORD *v425; // r8
  unsigned __int64 v426; // rcx
  unsigned __int64 v427; // rax
  const char *v428; // rax
  _QWORD *v429; // r8
  _QWORD *v430; // rcx
  unsigned __int64 v431; // rax
  _QWORD *v432; // rcx
  __int64 v433; // r8
  unsigned __int16 v434; // cx
  __int64 v435; // rdx
  __int64 v436; // r9
  int v437; // eax
  __m128 v438; // xmm12
  __m128 v439; // xmm13
  __int64 v440; // r8
  __int64 v441; // rdx
  __int64 v442; // r9
  int v443; // eax
  __m128 v444; // xmm10
  __m128 v445; // xmm11
  __int64 v446; // r8
  __int64 v447; // rdx
  __int64 v448; // r9
  int v449; // eax
  __m128 v450; // xmm6
  __m128 v451; // xmm7
  __int64 v452; // r8
  __int64 v453; // rdx
  __int64 v454; // r9
  int v455; // eax
  __m128 v456; // xmm5
  __m128 v457; // xmm1
  _QWORD *v458; // r8
  _QWORD *v459; // rcx
  unsigned __int64 v460; // rax
  _QWORD *v461; // rcx
  int v462; // ecx
  hkQsTransformf *v463; // r9
  __int64 v464; // r8
  __int64 v465; // r10
  __m128 *v466; // rdx
  int v467; // eax
  hkLifoAllocator *v468; // rax
  hkLifoAllocator *v469; // r9
  _QWORD *v470; // r8
  _QWORD *v471; // rcx
  unsigned __int64 v472; // rax
  _QWORD *v473; // rcx
  char v474; // [rsp+20h] [rbp-D8h]
  __m128 *p; // [rsp+28h] [rbp-D0h]
  __m128i *frameData; // [rsp+30h] [rbp-C8h]
  __m128 v477; // [rsp+40h] [rbp-B8h]
  __m128 v478; // [rsp+50h] [rbp-A8h]
  void *v479; // [rsp+60h] [rbp-98h]
  unsigned __int16 *v480; // [rsp+68h] [rbp-90h]
  unsigned __int16 *v481; // [rsp+70h] [rbp-88h]
  int *v482; // [rsp+78h] [rbp-80h]
  int *v483; // [rsp+80h] [rbp-78h]
  __m128 *v484; // [rsp+88h] [rbp-70h]
  __m128 v485; // [rsp+98h] [rbp-60h]
  __m128 v486; // [rsp+A8h] [rbp-50h]
  __int64 v487; // [rsp+B8h] [rbp-40h]
  __m128 v488; // [rsp+C8h] [rbp-30h]
  __m128 v489; // [rsp+D8h] [rbp-20h]
  __m128 v490; // [rsp+E8h] [rbp-10h]
  __m128 v491; // [rsp+F8h] [rbp+0h]
  const char *v492; // [rsp+108h] [rbp+10h]
  __m128 v493; // [rsp+118h] [rbp+20h]
  __m128 v494; // [rsp+128h] [rbp+30h]
  __m128 v495; // [rsp+138h] [rbp+40h]
  __m128 v496; // [rsp+148h] [rbp+50h]
  __m128 v497; // [rsp+158h] [rbp+60h]
  __m128 v498; // [rsp+168h] [rbp+70h]
  __m128 v499; // [rsp+178h] [rbp+80h]
  __m128 v500; // [rsp+188h] [rbp+90h]
  const char *v501; // [rsp+198h] [rbp+A0h]
  __m128 v502; // [rsp+1A8h] [rbp+B0h]
  __m128 v503; // [rsp+1B8h] [rbp+C0h]
  __m128 v504; // [rsp+1C8h] [rbp+D0h]
  __m128 v505; // [rsp+1D8h] [rbp+E0h]
  __m128 v506; // [rsp+1E8h] [rbp+F0h]
  __m128 v507; // [rsp+1F8h] [rbp+100h]
  __m128 v508; // [rsp+208h] [rbp+110h]
  __m128 v509; // [rsp+218h] [rbp+120h]
  __m128 v510; // [rsp+228h] [rbp+130h]
  __m128 v511; // [rsp+238h] [rbp+140h]
  __m128 v512; // [rsp+248h] [rbp+150h]
  __m128 v513; // [rsp+258h] [rbp+160h]
  __m128 v514; // [rsp+268h] [rbp+170h]
  __m128 v515; // [rsp+278h] [rbp+180h]
  __m128 v516; // [rsp+288h] [rbp+190h]
  __m128 v517; // [rsp+298h] [rbp+1A0h] BYREF
  __m128 v518; // [rsp+2A8h] [rbp+1B0h]
  __m128 v519; // [rsp+2B8h] [rbp+1C0h]
  __m128 v520; // [rsp+2C8h] [rbp+1D0h]
  __m128 v521; // [rsp+2D8h] [rbp+1E0h]
  __m128 v522; // [rsp+2E8h] [rbp+1F0h]
  __m128 v523; // [rsp+2F8h] [rbp+200h]
  __m128 v524; // [rsp+308h] [rbp+210h]
  __m128 v525; // [rsp+318h] [rbp+220h]
  __m128 v526; // [rsp+328h] [rbp+230h]
  __m128 v527; // [rsp+338h] [rbp+240h]
  __m128 v528; // [rsp+348h] [rbp+250h]
  __m128 v529; // [rsp+358h] [rbp+260h]
  __m128 v530; // [rsp+368h] [rbp+270h]
  __m128 v531; // [rsp+378h] [rbp+280h]
  __m128 v532; // [rsp+388h] [rbp+290h]
  __m128 v533; // [rsp+398h] [rbp+2A0h]
  __m128 v534; // [rsp+3A8h] [rbp+2B0h]
  __m128 v535; // [rsp+3B8h] [rbp+2C0h]
  __m128 v536; // [rsp+3C8h] [rbp+2D0h]
  __m128 v537; // [rsp+3D8h] [rbp+2E0h]
  __m128 v538; // [rsp+3E8h] [rbp+2F0h]
  __m128 v539; // [rsp+3F8h] [rbp+300h]
  __m128 v540; // [rsp+408h] [rbp+310h]
  __m128 v541; // [rsp+418h] [rbp+320h]
  __m128 v542; // [rsp+428h] [rbp+330h]
  __m128 v543; // [rsp+438h] [rbp+340h]
  __m128 v544; // [rsp+448h] [rbp+350h]
  __m128 v545; // [rsp+458h] [rbp+360h]
  __m128 v546; // [rsp+468h] [rbp+370h]
  __m128 v547; // [rsp+478h] [rbp+380h]
  __m128 v548; // [rsp+488h] [rbp+390h]
  __m128 v549; // [rsp+498h] [rbp+3A0h]
  __m128 v550; // [rsp+4A8h] [rbp+3B0h]
  __m128 v551; // [rsp+4B8h] [rbp+3C0h]
  __m128 v552; // [rsp+4C8h] [rbp+3D0h]
  __m128 m_quad; // [rsp+4D8h] [rbp+3E0h] BYREF
  __m128 v554; // [rsp+4E8h] [rbp+3F0h]
  __m128 v555; // [rsp+4F8h] [rbp+400h]
  __m128i si128; // [rsp+508h] [rbp+410h]
  __m128 v557; // [rsp+518h] [rbp+420h]
  __m128 v558; // [rsp+528h] [rbp+430h]
  __m128i v559; // [rsp+538h] [rbp+440h]
  __m128 v560; // [rsp+548h] [rbp+450h]
  __m128 v561; // [rsp+558h] [rbp+460h]
  __m128 v562; // [rsp+568h] [rbp+470h]
  __m128 v563; // [rsp+578h] [rbp+480h]
  __m128i v564; // [rsp+588h] [rbp+490h]
  __m128 v565; // [rsp+598h] [rbp+4A0h]
  __m128i v566; // [rsp+5A8h] [rbp+4B0h]
  __m128 v567; // [rsp+5B8h] [rbp+4C0h]
  __m128i v568; // [rsp+5C8h] [rbp+4D0h]
  __m128 v569; // [rsp+5D8h] [rbp+4E0h]
  __m128i v570; // [rsp+5E8h] [rbp+4F0h]
  __m128i v571; // [rsp+5F8h] [rbp+500h]
  __m128 v572; // [rsp+608h] [rbp+510h]
  __m128 v573; // [rsp+618h] [rbp+520h]
  __m128i v574; // [rsp+628h] [rbp+530h]
  __m128 v575; // [rsp+638h] [rbp+540h]
  __m128i v576; // [rsp+648h] [rbp+550h]
  __m128 v577; // [rsp+658h] [rbp+560h]
  __m128i v578; // [rsp+668h] [rbp+570h]
  __m128i v579; // [rsp+678h] [rbp+580h]
  __m128i v580; // [rsp+688h] [rbp+590h]
  __m128 v581; // [rsp+698h] [rbp+5A0h]
  __m128 v582; // [rsp+6A8h] [rbp+5B0h]
  __int64 retaddr; // [rsp+7A8h] [rbp+6B0h]
  hkaPredictiveCompressedAnimation *start; // [rsp+7B0h] [rbp+6B8h] BYREF
  unsigned int v585; // [rsp+7B8h] [rbp+6C0h]
  __int64 end; // [rsp+7C0h] [rbp+6C8h] BYREF
  const char *v587; // [rsp+7C8h] [rbp+6D0h]

  v587 = compressedData;
  *(float *)&end = frameDelta;
  start = this;
  v12 = this;
  v13 = compressedData;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = Value[1];
  if ( v16 < Value[3] )
  {
    *(_QWORD *)v16 = "LtPredictiveSample";
    *(_QWORD *)(v16 + 16) = "StSetup";
    v17 = __rdtsc();
    *(_DWORD *)(v16 + 8) = v17;
    Value[1] = v16 + 24;
  }
  if ( !v13 )
  {
    hkaPredictiveCompressedAnimation::getCompressedDataOffset(
      v12,
      frameIndex,
      (unsigned int *)&start,
      (unsigned int *)&end);
    v13 = &v12->m_compressedData.m_data[(unsigned int)start];
    end = (__int64)v13;
  }
  v18 = v12->m_intArrayOffsets[1];
  v492 = v13;
  v19 = frameIndex / 0xF;
  v20 = (__int64)&v12->m_intData.m_data[v18];
  v21 = *(unsigned __int16 *)(v20 + 4 * v19 + 2);
  v22 = *(unsigned __int16 *)(v20 + 4 * v19);
  v23 = frameIndex % 0xF;
  LODWORD(start) = v23;
  v501 = &v13[v22 | (unsigned int)(v21 << 16)];
  if ( frameDelta >= 0.001 )
  {
    if ( frameDelta <= 0.99900001 )
    {
      v24 = 0;
    }
    else
    {
      v24 = 1;
      LODWORD(start) = v23 + 1;
    }
  }
  else
  {
    v24 = 1;
  }
  v474 = v24;
  v25 = _mm_shuffle_ps((__m128)v585, (__m128)v585, 0);
  v498 = v25;
  if ( v24 )
  {
    m_quad = query.m_quad;
    p_m_quad = &m_quad;
  }
  else
  {
    p_m_quad = &v517;
    v517 = _mm_sub_ps(query.m_quad, v25);
  }
  v27 = *p_m_quad;
  m_data = v12->m_floatData.m_data;
  v29 = (int *)&m_data[v12->m_floatArrayOffsets[1]];
  v30 = v12->m_floatArrayOffsets[2];
  v494 = v27;
  v31 = (__int64)&m_data[v30];
  v32 = v12->m_floatArrayOffsets[0];
  v482 = v29;
  v33 = (__int64)&m_data[v32];
  v34 = v12->m_intData.m_data;
  v35 = v12->m_intArrayOffsets[2];
  v483 = (int *)v33;
  v36 = (__int64)&v34[v35];
  v37 = v12->m_intArrayOffsets[3];
  v480 = (unsigned __int16 *)v36;
  v482 = (int *)v31;
  v481 = &v34[v37];
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  frameData = (__m128i *)v38->m_cur;
  v39 = frameData + 8;
  if ( v38->m_slabSize < 128 || v39 > v38->m_end )
    frameData = (__m128i *)hkLifoAllocator::allocateFromNewSlab(v38, 128);
  else
    v38->m_cur = v39;
  v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v41 = v40->m_slabSize < 256;
  m_cur = (__m128 *)v40->m_cur;
  v43 = m_cur + 16;
  v484 = m_cur;
  if ( v41 || v43 > v40->m_end )
  {
    m_cur = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v40, 256);
    v484 = m_cur;
  }
  else
  {
    v40->m_cur = v43;
  }
  v44 = floatsOut;
  v45 = (int)refFloats;
  v46 = v480;
  if ( floatsOut )
  {
    v47 = 0i64;
    if ( (int)refFloats > 0i64 )
    {
      v48 = (int)refFloats;
      do
      {
        v49 = *v46;
        v50 = 16;
        ++v46;
        if ( v48 < 16 )
          v50 = v48;
        v51 = v50;
        if ( v50 > 0 )
        {
          v52 = &v44[v47 / 4];
          do
          {
            v53 = v49;
            v49 >>= 1;
            v52 = (float *)((char *)v52 + 1);
            *((_BYTE *)v52 - 1) &= -(v53 & 1);
            --v51;
          }
          while ( v51 );
        }
        v47 += 16i64;
        v48 -= 16;
      }
      while ( (__int64)v47 < v45 );
      v29 = v482;
    }
  }
  v54 = numBones;
  if ( boneWeightsInOut )
  {
    v55 = 0i64;
    if ( numBones > 0 )
    {
      v56 = boneWeightsInOut;
      v57 = numBones;
      do
      {
        v58 = *v46;
        v59 = 16;
        ++v46;
        if ( v57 < 16 )
          v59 = v57;
        v60 = v59;
        if ( v59 > 0 )
        {
          v61 = &v56[v55];
          do
          {
            v62 = v58;
            v58 >>= 1;
            *v61++ &= -(v62 & 1);
            --v60;
          }
          while ( v60 );
        }
        v55 += 16i64;
        v57 -= 16;
      }
      while ( v55 < v54 );
      v31 = (__int64)v482;
      m_cur = v484;
    }
  }
  if ( (int)refFloats > 0 )
  {
    v63 = 12 * (_DWORD)refFloats;
    v64 = ((_DWORD)refFloats + 3) & 0xFFFFFFFC;
    v65 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v66 = (char *)v65->m_cur;
    v479 = v66;
    v67 = (48 * v64 + 127) & 0xFFFFFF80;
    LODWORD(floatsOut) = v67;
    v68 = &v66[v67];
    if ( v67 > v65->m_slabSize || v68 > v65->m_end )
    {
      v66 = (char *)hkLifoAllocator::allocateFromNewSlab(v65, v67);
      v479 = v66;
    }
    else
    {
      v65->m_cur = v68;
    }
    v69 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v70 = (__m128 *)v69->m_cur;
    v71 = (char *)v70 + v67;
    p = v70;
    if ( v67 > v69->m_slabSize || v71 > v69->m_end )
    {
      v70 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v69, v67);
      p = v70;
    }
    else
    {
      v69->m_cur = v71;
    }
    v72 = *(_QWORD *)(retaddr + 72);
    v487 = v72 + 2i64 * *(int *)(retaddr + 104);
    v73 = v72 + 2i64 * *(int *)(retaddr + 120);
    boneWeightsInOut = (char *)(v72 + 2i64 * *(int *)(retaddr + 112));
    v480 = (unsigned __int16 *)v73;
    v74 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v75 = (_QWORD *)v74[1];
    v76 = v74;
    if ( (unsigned __int64)v75 < v74[3] )
    {
      *v75 = "StCopyReferencePose";
      v77 = __rdtsc();
      v78 = v75 + 2;
      *((_DWORD *)v78 - 2) = v77;
      v76[1] = v78;
    }
    v79 = (int)refFloats;
    v80 = numFloats;
    if ( (int)refFloats > 0 )
    {
      v81 = numFloats - (_QWORD)v587;
      v82 = v66 - v587;
      v83 = (__int128 *)(v587 + 32);
      v84 = (char *)v70 - v587;
      do
      {
        v85 = *(v83 - 2);
        v86 = *(v83 - 1);
        v87 = *v83;
        v83 += 3;
        *(__int128 *)((char *)v83 + v81 - 80) = v85;
        *(__int128 *)((char *)v83 + v81 - 64) = v86;
        *(__int128 *)((char *)v83 + v81 - 48) = v87;
        *(__int128 *)((char *)v83 + v82 - 80) = v85;
        *(__int128 *)((char *)v83 + v82 - 64) = v86;
        *(__int128 *)((char *)v83 + v82 - 48) = v87;
        *(__int128 *)((char *)v83 + v84 - 80) = v85;
        *(__int128 *)((char *)v83 + v84 - 64) = v86;
        *(__int128 *)((char *)v83 + v84 - 48) = v87;
        --v79;
      }
      while ( v79 );
    }
    v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v89 = (_QWORD *)v88[1];
    if ( (unsigned __int64)v89 < v88[3] )
    {
      *v89 = "StCopyStaticTracks";
      v90 = __rdtsc();
      v91 = v89 + 2;
      *((_DWORD *)v91 - 2) = v90;
      v88[1] = v91;
    }
    v92 = *(_DWORD *)(retaddr + 116) - *(_DWORD *)(retaddr + 112);
    if ( v92 > 0 )
    {
      v93 = boneWeightsInOut;
      v94 = v483;
      v95 = *(unsigned __int16 *)boneWeightsInOut;
      v96 = 0i64;
      if ( v92 - 1 <= 0 )
      {
LABEL_61:
        if ( v95 < v63 )
        {
          v98 = *v94;
          *(_DWORD *)(v80 + 4i64 * v95) = *v94;
          *(_DWORD *)&v66[4 * v95] = v98;
          v70->m128_i32[v95] = v98;
        }
      }
      else
      {
        while ( v95 < v63 )
        {
          v97 = *v94;
          ++v96;
          *(_DWORD *)(v80 + 4i64 * v95) = *v94;
          *(_DWORD *)&v66[4 * v95] = v97;
          ++v94;
          v70->m128_i32[v95] = v97;
          v95 = *(unsigned __int16 *)&v93[2 * v96];
          if ( v96 >= v92 - 1 )
            goto LABEL_61;
        }
      }
      v483 += v92;
    }
    v99 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v100 = (_QWORD *)v99[1];
    if ( (unsigned __int64)v100 < v99[3] )
    {
      *v100 = "StCopyDynamicTracks";
      v101 = __rdtsc();
      v102 = v100 + 2;
      *((_DWORD *)v102 - 2) = v101;
      v99[1] = v102;
    }
    v12 = (hkaPredictiveCompressedAnimation *)retaddr;
    v103 = 0i64;
    LODWORD(refFloats) = 0;
    LODWORD(boneWeightsInOut) = *(_DWORD *)(retaddr + 108) - *(_DWORD *)(retaddr + 104);
    v490.m128_u64[0] = (int)boneWeightsInOut;
    if ( (int)boneWeightsInOut > 0 )
    {
      do
      {
        v104 = *(unsigned __int16 *)(v487 + 2 * v103);
        if ( v104 >= v63 )
          break;
        v492 = (const char *)end;
        v105 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v106 = v105[1];
        v107 = v105;
        if ( v106 < v105[3] )
        {
          *(_QWORD *)v106 = "LtloadDynamic";
          *(_QWORD *)(v106 + 16) = "StDecompress";
          v108 = __rdtsc();
          *(_DWORD *)(v106 + 8) = v108;
          v107[1] = v106 + 24;
        }
        if ( v474 )
          v109 = hkaPredictiveBlockCompression::decodeSingleFrame((const char *)end, (int)start, frameData->m128i_i16);
        else
          v109 = hkaPredictiveBlockCompression::decodeAdjacentFrames(
                   (const char *)end,
                   (int)start,
                   frameData->m128i_i16);
        end = (__int64)v109;
        v110 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v111 = (_QWORD *)v110[1];
        if ( (unsigned __int64)v111 < v110[3] )
        {
          *v111 = "StDequantize";
          v112 = __rdtsc();
          v113 = v111 + 2;
          *((_DWORD *)v113 - 2) = v112;
          v110[1] = v113;
        }
        v114 = 0i64;
        v585 = 956302336;
        v115 = *v481;
        v116 = 0i64;
        ++v481;
        v117 = 4i64;
        do
        {
          if ( (v115 & 1) != 0 )
          {
            v489.m128_i32[v114] = 956302336;
            v493.m128_i32[v114] = 0;
          }
          else
          {
            v118 = *v29++;
            v31 += 4i64;
            v489.m128_i32[v116] = v118;
            v493.m128_i32[v116] = *(_DWORD *)(v31 - 4);
          }
          v115 >>= 1;
          ++v114;
          ++v116;
          --v117;
        }
        while ( v117 );
        v119 = v489;
        v120 = v493;
        v121 = 0i64;
        v122 = 0i64;
        v123 = 4i64;
        v543 = v489;
        v519 = v493;
        do
        {
          if ( (v115 & 1) != 0 )
          {
            v491.m128_i32[v121] = 956302336;
            v488.m128_i32[v121] = 0;
          }
          else
          {
            v124 = *v29++;
            v31 += 4i64;
            v491.m128_i32[v122] = v124;
            v488.m128_i32[v122] = *(_DWORD *)(v31 - 4);
          }
          v115 >>= 1;
          ++v121;
          ++v122;
          --v123;
        }
        while ( v123 );
        v125 = v491;
        v126 = v488;
        v127 = 0i64;
        v128 = 0i64;
        v129 = 4i64;
        v545 = v491;
        v521 = v488;
        do
        {
          if ( (v115 & 1) != 0 )
          {
            v485.m128_i32[v127] = 956302336;
            v486.m128_i32[v127] = 0;
          }
          else
          {
            v130 = *v29++;
            v31 += 4i64;
            v485.m128_i32[v128] = v130;
            v486.m128_i32[v128] = *(_DWORD *)(v31 - 4);
          }
          v115 >>= 1;
          ++v127;
          ++v128;
          --v129;
        }
        while ( v129 );
        v131 = v485;
        v132 = v486;
        v133 = 0i64;
        v134 = 0i64;
        v135 = 4i64;
        v547 = v485;
        v523 = v486;
        do
        {
          if ( (v115 & 1) != 0 )
          {
            v478.m128_i32[v133] = 956302336;
            v477.m128_i32[v133] = 0;
          }
          else
          {
            v136 = *v29++;
            v31 += 4i64;
            v478.m128_i32[v134] = v136;
            v477.m128_i32[v134] = *(_DWORD *)(v31 - 4);
          }
          v115 >>= 1;
          ++v133;
          ++v134;
          --v135;
        }
        while ( v135 );
        v482 = v29;
        v549 = v478;
        v525 = v477;
        si128 = _mm_load_si128(frameData);
        v137 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(si128, (__m128i)0i64), 0x10u), 0x10u)),
                   v119),
                 v120);
        v502 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(si128, (__m128i)0i64), 0x10u), 0x10u)),
                   v125),
                 v126);
        v551 = v137;
        v579 = _mm_load_si128(frameData + 1);
        v500 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v579, (__m128i)0i64), 0x10u), 0x10u)),
                   v131),
                 v132);
        v504 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v579, (__m128i)0i64), 0x10u), 0x10u)),
                   v478),
                 v477);
        if ( v474 )
        {
          m_cur[8] = v137;
          m_cur[9] = v502;
          m_cur[10] = v500;
          v138 = v504;
        }
        else
        {
          *m_cur = v137;
          m_cur[1] = v502;
          m_cur[2] = v500;
          m_cur[3] = v504;
          v559 = _mm_load_si128(frameData + 2);
          v506 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v559, (__m128i)0i64), 0x10u), 0x10u)),
                     v545),
                   v521);
          v527 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v559, (__m128i)0i64), 0x10u), 0x10u)),
                     v543),
                   v519);
          v571 = _mm_load_si128(frameData + 3);
          v511 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v571, (__m128i)0i64), 0x10u), 0x10u)),
                     v547),
                   v523);
          v509 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v571, (__m128i)0i64), 0x10u), 0x10u)),
                     v549),
                   v525);
          m_cur[4] = v527;
          m_cur[5] = v506;
          m_cur[6] = v511;
          m_cur[7] = v509;
          v561 = _mm_add_ps(_mm_mul_ps(v27, v551), _mm_mul_ps(v527, v25));
          v515 = _mm_add_ps(_mm_mul_ps(v27, v502), _mm_mul_ps(v506, v25));
          v529 = _mm_add_ps(_mm_mul_ps(v27, v500), _mm_mul_ps(v511, v25));
          v555 = _mm_add_ps(_mm_mul_ps(v27, v504), _mm_mul_ps(v509, v25));
          m_cur[8] = v561;
          m_cur[9] = v515;
          m_cur[10] = v529;
          v138 = v555;
        }
        m_cur[11] = v138;
        v139 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v140 = (_QWORD *)v139[1];
        if ( (unsigned __int64)v140 < v139[3] )
        {
          *v140 = "lt";
          v141 = __rdtsc();
          v142 = v140 + 2;
          *((_DWORD *)v142 - 2) = v141;
          v139[1] = v142;
        }
        v143 = (int)boneWeightsInOut;
        v144 = (int)refFloats;
        v145 = 0i64;
        if ( (int)refFloats + 16 < (int)boneWeightsInOut )
          v143 = (_DWORD)refFloats + 16;
        v146 = v143 - 1;
        if ( v103 < v146 )
        {
          v147 = v479;
          v148 = v487;
          v149 = m_cur + 8;
          do
          {
            if ( (unsigned __int16)v104 >= v63 )
              break;
            v150 = v149[-8].m128_i32[0];
            v151 = v149[-4].m128_i32[0];
            ++v103;
            ++v144;
            *(_DWORD *)(v80 + 4i64 * (unsigned __int16)v104) = v149->m128_i32[0];
            ++v145;
            v149 = (__m128 *)((char *)v149 + 4);
            v147[(unsigned __int16)v104] = v150;
            p->m128_i32[(unsigned __int16)v104] = v151;
            LOWORD(v104) = *(_WORD *)(v148 + 2 * v103);
          }
          while ( v103 < v146 );
          v29 = v482;
          v31 = (__int64)v482;
          m_cur = v484;
          LODWORD(refFloats) = v144;
        }
        if ( (unsigned __int16)v104 < v63 )
        {
          v152 = m_cur->m128_i32[v145];
          v153 = m_cur[4].m128_i32[v145];
          ++v103;
          *(_DWORD *)(v80 + 4i64 * (unsigned __int16)v104) = m_cur[8].m128_i32[v145];
          LODWORD(refFloats) = v144 + 1;
          *((_DWORD *)v479 + (unsigned __int16)v104) = v152;
          p->m128_i32[(unsigned __int16)v104] = v153;
        }
      }
      while ( v103 < v490.m128_i64[0] );
      v12 = (hkaPredictiveCompressedAnimation *)retaddr;
    }
    v154 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v155 = (_QWORD *)v154[1];
    if ( (unsigned __int64)v155 < v154[3] )
    {
      *v155 = "StInterpolateQuaternions";
      v156 = __rdtsc();
      v157 = v155 + 2;
      *((_DWORD *)v157 - 2) = v156;
      v154[1] = v157;
    }
    v158 = v12->m_intData.m_size - v12->m_intArrayOffsets[8] - 8;
    if ( v158 <= 0 )
    {
      v228 = p;
    }
    else
    {
      v159 = 0;
      LODWORD(refFloats) = 0;
      v160 = (v158 & 0xFFFFFFFC) - 4;
      if ( v474 )
      {
        if ( v160 > 0 )
        {
          v161 = 0i64;
          v162 = v480[3];
          retaddr = v160;
          v163 = v480 + 2;
          do
          {
            if ( v162 >= v63 )
              break;
            v164 = 6i64 * *(v163 - 2);
            v165 = 6i64 * *v163;
            v166 = 6i64 * *(v163 - 1);
            v167 = 6i64 * v162;
            v168 = *(__m128 *)(v80 + 48i64 * *(v163 - 2) + 16);
            v169 = _mm_shuffle_ps(v168, *(__m128 *)(v80 + 48i64 * *(v163 - 1) + 16), 238);
            v170 = _mm_shuffle_ps(*(__m128 *)(v80 + 48i64 * *v163 + 16), *(__m128 *)(v80 + 8 * v167 + 16), 68);
            v171 = _mm_shuffle_ps(v168, *(__m128 *)(v80 + 48i64 * *(v163 - 1) + 16), 68);
            v172 = (__m128i)_mm_shuffle_ps(v171, v170, 136);
            v173 = (__m128i)_mm_shuffle_ps(v171, v170, 221);
            v174 = (__m128i)_mm_shuffle_ps(
                              v169,
                              _mm_shuffle_ps(
                                *(__m128 *)(v80 + 48i64 * *v163 + 16),
                                *(__m128 *)(v80 + 8 * v167 + 16),
                                238),
                              136);
            v175 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v172, 1u), 1u);
            v176 = _mm_shuffle_ps((__m128)v172, (__m128)v173, 68);
            v177 = _mm_shuffle_ps((__m128)v172, (__m128)v173, 238);
            v178 = _mm_sub_ps(
                     query.m_quad,
                     _mm_add_ps(
                       _mm_add_ps(v175, (__m128)_mm_srli_epi32(_mm_slli_epi32(v173, 1u), 1u)),
                       (__m128)_mm_srli_epi32(_mm_slli_epi32(v174, 1u), 1u)));
            v179 = _mm_cmplt_ps(v178, query.m_quad);
            v180 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v179, query.m_quad), _mm_and_ps(v178, v179)));
            v181 = _mm_shuffle_ps((__m128)v174, v180, 68);
            v182 = _mm_shuffle_ps((__m128)v174, v180, 238);
            v183 = _mm_shuffle_ps(v176, v181, 136);
            v184 = _mm_shuffle_ps(v176, v181, 221);
            v185 = _mm_shuffle_ps(v177, v182, 136);
            v186 = _mm_mul_ps(v183, v183);
            v187 = _mm_shuffle_ps(v177, v182, 221);
            v188 = _mm_add_ps(_mm_shuffle_ps(v186, v186, 78), v186);
            v189 = _mm_add_ps(_mm_shuffle_ps(v188, v188, 177), v188);
            v190 = _mm_rsqrt_ps(v189);
            v577 = v189;
            v191 = _mm_mul_ps(v184, v184);
            v192 = _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v190, v189), v190)),
                     _mm_mul_ps(v190, *(__m128 *)_xmm));
            v163 += 4;
            v193 = _mm_add_ps(_mm_shuffle_ps(v191, v191, 78), v191);
            v161 += 4i64;
            v563 = _mm_add_ps(_mm_shuffle_ps(v193, v193, 177), v193);
            v194 = _mm_rsqrt_ps(v563);
            v195 = _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v194, v563), v194)),
                     _mm_mul_ps(v194, *(__m128 *)_xmm));
            v196 = _mm_mul_ps(v185, v185);
            v197 = _mm_add_ps(_mm_shuffle_ps(v196, v196, 78), v196);
            v198 = _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v563, (__m128)0i64), v195), v184);
            v573 = _mm_add_ps(_mm_shuffle_ps(v197, v197, 177), v197);
            v199 = _mm_rsqrt_ps(v573);
            v200 = _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v199, v573), v199)),
                     _mm_mul_ps(v199, *(__m128 *)_xmm));
            v201 = _mm_mul_ps(v187, v187);
            v202 = _mm_add_ps(_mm_shuffle_ps(v201, v201, 78), v201);
            v203 = _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v573, (__m128)0i64), v200), v185);
            v204 = _mm_add_ps(_mm_shuffle_ps(v202, v202, 177), v202);
            v565 = v204;
            v205 = _mm_rsqrt_ps(v204);
            *(__m128 *)(v80 + 8 * v164 + 16) = _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v189, (__m128)0i64), v192), v183);
            *(__m128 *)(v80 + 8 * v166 + 16) = v198;
            *(__m128 *)(v80 + 8 * v165 + 16) = v203;
            v159 = (_DWORD)refFloats + 4;
            LODWORD(refFloats) = (_DWORD)refFloats + 4;
            *(__m128 *)(v80 + 8 * v167 + 16) = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmple_ps(v204, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v204, v205), v205)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v205))),
                                                 v187);
            v162 = v163[1];
          }
          while ( v161 < retaddr );
          v25 = v498;
          v27 = v494;
        }
        v206 = (__int64)v480;
        v207 = v159;
        v208 = v480[v159];
        v209 = v158 - 1;
        if ( v207 >= v209 )
        {
LABEL_124:
          if ( v208 < v63 )
          {
            v219 = 6i64 * v208;
            v220 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)(v80 + 8 * v219 + 16), 1u), 1u);
            v221 = _mm_sub_ps(
                     query.m_quad,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v220, v220, 85), _mm_shuffle_ps(v220, v220, 0)),
                       _mm_shuffle_ps(v220, v220, 170)));
            v222 = _mm_cmplt_ps(v221, query.m_quad);
            v223 = _mm_shuffle_ps(
                     *(__m128 *)(v80 + 8 * v219 + 16),
                     _mm_unpackhi_ps(
                       *(__m128 *)(v80 + 8 * v219 + 16),
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v221, v222), _mm_andnot_ps(v222, query.m_quad)))),
                     196);
            v224 = _mm_mul_ps(v223, v223);
            v225 = _mm_add_ps(_mm_shuffle_ps(v224, v224, 78), v224);
            v226 = _mm_add_ps(_mm_shuffle_ps(v225, v225, 177), v225);
            v227 = _mm_rsqrt_ps(v226);
            v567 = v226;
            *(__m128 *)(v80 + 8 * v219 + 16) = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmple_ps(v226, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v227, v226), v227)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v227))),
                                                 v223);
          }
        }
        else
        {
          while ( v208 < v63 )
          {
            ++v207;
            v210 = 6i64 * v208;
            v211 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)(v80 + 8 * v210 + 16), 1u), 1u);
            v212 = _mm_sub_ps(
                     query.m_quad,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v211, v211, 0), _mm_shuffle_ps(v211, v211, 85)),
                       _mm_shuffle_ps(v211, v211, 170)));
            v213 = _mm_cmplt_ps(v212, query.m_quad);
            v214 = _mm_shuffle_ps(
                     *(__m128 *)(v80 + 8 * v210 + 16),
                     _mm_unpackhi_ps(
                       *(__m128 *)(v80 + 8 * v210 + 16),
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v213, query.m_quad), _mm_and_ps(v212, v213)))),
                     196);
            v215 = _mm_mul_ps(v214, v214);
            v216 = _mm_add_ps(_mm_shuffle_ps(v215, v215, 78), v215);
            v217 = _mm_add_ps(_mm_shuffle_ps(v216, v216, 177), v216);
            v218 = _mm_rsqrt_ps(v217);
            v581 = v217;
            *(__m128 *)(v80 + 8 * v210 + 16) = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmple_ps(v217, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v218, v217), v218)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v218))),
                                                 v214);
            v208 = *(unsigned __int16 *)(v206 + 2 * v207);
            if ( v207 >= v209 )
              goto LABEL_124;
          }
        }
        goto LABEL_126;
      }
      v232 = (__int64)v480;
      if ( v160 > 0 )
      {
        v233 = v480[3];
        retaddr = 0i64;
        boneWeightsInOut = (char *)v160;
        v234 = (__m128 *)v479;
        v235 = v480 + 2;
        do
        {
          if ( v233 >= v63 )
            break;
          v236 = 6i64 * *(v235 - 2);
          v237 = 6i64 * *(v235 - 1);
          v238 = 6i64 * *v235;
          v239 = 3i64 * v233;
          v240 = p[3 * *v235 + 1];
          v241 = _mm_shuffle_ps(v234[3 * *(v235 - 2) + 1], v234[3 * *(v235 - 1) + 1], 68);
          v242 = _mm_shuffle_ps(v234[3 * *v235 + 1], v234[v239 + 1], 68);
          v243 = (__m128i)_mm_shuffle_ps(v241, v242, 221);
          v244 = (__m128i)_mm_shuffle_ps(v241, v242, 136);
          v245 = (__m128i)_mm_shuffle_ps(
                            _mm_shuffle_ps(v234[3 * *(v235 - 2) + 1], v234[3 * *(v235 - 1) + 1], 238),
                            _mm_shuffle_ps(v234[3 * *v235 + 1], v234[v239 + 1], 238),
                            136);
          v246 = _mm_slli_epi32(v244, 1u);
          v247 = (__m128)v244;
          v248 = _mm_shuffle_ps((__m128)v244, (__m128)v243, 238);
          v249 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v243, 1u), 1u);
          v250 = _mm_shuffle_ps(v247, (__m128)v243, 68);
          v251 = _mm_shuffle_ps(p[3 * *(v235 - 2) + 1], p[3 * *(v235 - 1) + 1], 68);
          v252 = _mm_shuffle_ps(p[3 * *(v235 - 2) + 1], p[3 * *(v235 - 1) + 1], 238);
          v253 = _mm_sub_ps(
                   query.m_quad,
                   _mm_add_ps(
                     _mm_add_ps((__m128)_mm_srli_epi32(v246, 1u), v249),
                     (__m128)_mm_srli_epi32(_mm_slli_epi32(v245, 1u), 1u)));
          v254 = _mm_cmplt_ps(v253, query.m_quad);
          v255 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v254, query.m_quad), _mm_and_ps(v254, v253)));
          v256 = _mm_shuffle_ps((__m128)v245, v255, 68);
          v257 = _mm_shuffle_ps((__m128)v245, v255, 238);
          v258 = _mm_shuffle_ps(v250, v256, 136);
          v478 = _mm_shuffle_ps(v250, v256, 221);
          v486 = _mm_shuffle_ps(v248, v257, 136);
          v259 = _mm_shuffle_ps(v240, p[v239 + 1], 68);
          v260 = _mm_shuffle_ps(v240, p[v239 + 1], 238);
          v477 = _mm_shuffle_ps(v248, v257, 221);
          v261 = (__m128i)_mm_shuffle_ps(v251, v259, 136);
          v262 = (__m128i)_mm_shuffle_ps(v251, v259, 221);
          v263 = (__m128i)_mm_shuffle_ps(v252, v260, 136);
          v264 = _mm_shuffle_ps((__m128)v261, (__m128)v262, 68);
          v265 = _mm_sub_ps(
                   query.m_quad,
                   _mm_add_ps(
                     _mm_add_ps(
                       (__m128)_mm_srli_epi32(_mm_slli_epi32(v261, 1u), 1u),
                       (__m128)_mm_srli_epi32(_mm_slli_epi32(v262, 1u), 1u)),
                     (__m128)_mm_srli_epi32(_mm_slli_epi32(v263, 1u), 1u)));
          v266 = _mm_cmplt_ps(v265, query.m_quad);
          v267 = _mm_shuffle_ps((__m128)v261, (__m128)v262, 238);
          v268 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v266, query.m_quad), _mm_and_ps(v266, v265)));
          v269 = _mm_shuffle_ps((__m128)v263, v268, 68);
          v270 = _mm_shuffle_ps((__m128)v263, v268, 238);
          v271 = _mm_shuffle_ps(v264, v269, 136);
          v272 = _mm_shuffle_ps(v264, v269, 221);
          v485 = _mm_shuffle_ps(v267, v270, 221);
          v273 = _mm_mul_ps(v485, v477);
          v274 = _mm_shuffle_ps(v267, v270, 136);
          v275 = _mm_mul_ps(v271, v258);
          v276 = _mm_mul_ps(v272, v478);
          v277 = _mm_mul_ps(v274, v486);
          v278 = _mm_shuffle_ps(v275, v276, 238);
          v279 = _mm_shuffle_ps(v275, v276, 68);
          v280 = _mm_shuffle_ps(v277, v273, 238);
          v281 = _mm_shuffle_ps(v277, v273, 68);
          v282 = _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               (__m128i)_mm_cmplt_ps(
                                          _mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v278, v280, 221), _mm_shuffle_ps(v278, v280, 136)),
                                            _mm_add_ps(_mm_shuffle_ps(v279, v281, 221), _mm_shuffle_ps(v279, v281, 136))),
                                          (__m128)0i64),
                               0x1Fu),
                             0x1Fu),
                   v498);
          v283 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v282, v282, 0), v271), _mm_mul_ps(v494, v258));
          v284 = _mm_mul_ps(v283, v283);
          v285 = _mm_add_ps(_mm_shuffle_ps(v284, v284, 78), v284);
          v286 = _mm_add_ps(_mm_shuffle_ps(v285, v285, 177), v285);
          v287 = _mm_rsqrt_ps(v286);
          v575 = v286;
          v288 = _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v287, v286), v287)),
                   _mm_mul_ps(*(__m128 *)_xmm, v287));
          v289 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v282, v282, 85), v272), _mm_mul_ps(v494, v478));
          v290 = _mm_mul_ps(v289, v289);
          v291 = _mm_add_ps(_mm_shuffle_ps(v290, v290, 78), v290);
          v292 = _mm_add_ps(_mm_shuffle_ps(v291, v291, 177), v291);
          v293 = _mm_rsqrt_ps(v292);
          v569 = v292;
          v294 = _mm_cmple_ps(v292, (__m128)0i64);
          v295 = _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v293, v292), v293)),
                   _mm_mul_ps(*(__m128 *)_xmm, v293));
          v296 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v282, v282, 170), v274), _mm_mul_ps(v494, v486));
          v297 = _mm_mul_ps(v296, v296);
          v298 = _mm_add_ps(_mm_shuffle_ps(v297, v297, 78), v297);
          v299 = _mm_add_ps(_mm_shuffle_ps(v298, v298, 177), v298);
          v300 = _mm_rsqrt_ps(v299);
          v557 = v299;
          v301 = _mm_cmple_ps(v299, (__m128)0i64);
          v302 = _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v300, v299), v300)),
                   _mm_mul_ps(*(__m128 *)_xmm, v300));
          v490 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v282, v282, 255), v485), _mm_mul_ps(v494, v477));
          v303 = _mm_mul_ps(v490, v490);
          v304 = _mm_add_ps(_mm_shuffle_ps(v303, v303, 78), v303);
          v305 = _mm_add_ps(_mm_shuffle_ps(v304, v304, 177), v304);
          v306 = _mm_rsqrt_ps(v305);
          v558 = v305;
          v235 += 4;
          *(__m128 *)(v80 + 8 * v236 + 16) = _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v286, (__m128)0i64), v288), v283);
          *(__m128 *)(v80 + 8 * v237 + 16) = _mm_mul_ps(_mm_andnot_ps(v294, v295), v289);
          v159 = (_DWORD)refFloats + 4;
          LODWORD(refFloats) = (_DWORD)refFloats + 4;
          *(__m128 *)(v80 + 8 * v238 + 16) = _mm_mul_ps(_mm_andnot_ps(v301, v302), v296);
          retaddr += 4i64;
          *(__m128 *)(v80 + 4 * v239 + 16) = _mm_mul_ps(
                                               _mm_andnot_ps(
                                                 _mm_cmple_ps(v305, (__m128)0i64),
                                                 _mm_mul_ps(
                                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v306, v305), v306)),
                                                   _mm_mul_ps(*(__m128 *)_xmm, v306))),
                                               v490);
          v233 = v235[1];
        }
        while ( retaddr < (__int64)boneWeightsInOut );
        v25 = v498;
        v27 = v494;
        m_cur = v484;
      }
      v307 = (char *)v479;
      v308 = v159;
      v309 = *(unsigned __int16 *)(v232 + 2i64 * v159);
      v310 = v158 - 1;
      if ( v308 < v310 )
      {
        while ( v309 < v63 )
        {
          v311 = 6i64 * v309;
          v312 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)&v307[8 * v311 + 16], 1u), 1u);
          v313 = _mm_sub_ps(
                   query.m_quad,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v312, v312, 85), _mm_shuffle_ps(v312, v312, 0)),
                     _mm_shuffle_ps(v312, v312, 170)));
          v314 = _mm_cmplt_ps(v313, query.m_quad);
          v315 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v313, v314), _mm_andnot_ps(v314, query.m_quad)));
          v316 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)p[(unsigned __int64)v311 / 2 + 1], 1u), 1u);
          v317 = _mm_shuffle_ps(
                   *(__m128 *)&v307[8 * v311 + 16],
                   _mm_unpackhi_ps(*(__m128 *)&v307[8 * v311 + 16], v315),
                   196);
          v318 = _mm_sub_ps(
                   query.m_quad,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v316, v316, 85), _mm_shuffle_ps(v316, v316, 0)),
                     _mm_shuffle_ps(v316, v316, 170)));
          v319 = _mm_cmplt_ps(v318, query.m_quad);
          v320 = _mm_shuffle_ps(
                   p[(unsigned __int64)v311 / 2 + 1],
                   _mm_unpackhi_ps(
                     p[(unsigned __int64)v311 / 2 + 1],
                     _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v318, v319), _mm_andnot_ps(v319, query.m_quad)))),
                   196);
          v321 = _mm_mul_ps(v320, v317);
          v322 = _mm_add_ps(_mm_shuffle_ps(v321, v321, 78), v321);
          v323 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32(
                                   (__m128i)_mm_cmplt_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v322, v322, 177), v322),
                                              (__m128)0i64),
                                   0x1Fu),
                                 0x1Fu),
                       v25),
                     v320),
                   _mm_mul_ps(v27, v317));
          v324 = _mm_mul_ps(v323, v323);
          v325 = _mm_add_ps(_mm_shuffle_ps(v324, v324, 78), v324);
          v326 = _mm_add_ps(_mm_shuffle_ps(v325, v325, 177), v325);
          v327 = _mm_rsqrt_ps(v326);
          v560 = v326;
          ++v308;
          *(__m128 *)(v80 + 8 * v311 + 16) = _mm_mul_ps(
                                               _mm_andnot_ps(
                                                 _mm_cmple_ps(v326, (__m128)0i64),
                                                 _mm_mul_ps(
                                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v327, v326), v327)),
                                                   _mm_mul_ps(*(__m128 *)_xmm, v327))),
                                               v323);
          v309 = *(unsigned __int16 *)(v232 + 2 * v308);
          if ( v308 >= v310 )
            goto LABEL_140;
        }
        goto LABEL_126;
      }
LABEL_140:
      if ( v309 >= v63 )
      {
LABEL_126:
        v228 = p;
        goto LABEL_127;
      }
      v228 = p;
      v328 = 6i64 * v309;
      v329 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)&v307[8 * v328 + 16], 1u), 1u);
      v330 = _mm_sub_ps(
               query.m_quad,
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v329, v329, 85), _mm_shuffle_ps(v329, v329, 0)),
                 _mm_shuffle_ps(v329, v329, 170)));
      v331 = _mm_cmplt_ps(v330, query.m_quad);
      v332 = _mm_or_ps(_mm_andnot_ps(v331, query.m_quad), _mm_and_ps(v330, v331));
      v333 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)p[(unsigned __int64)v328 / 2 + 1], 1u), 1u);
      v334 = _mm_shuffle_ps(
               *(__m128 *)&v307[8 * v328 + 16],
               _mm_unpackhi_ps(*(__m128 *)&v307[8 * v328 + 16], _mm_max_ps((__m128)0i64, v332)),
               196);
      v335 = _mm_sub_ps(
               query.m_quad,
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v333, v333, 85), _mm_shuffle_ps(v333, v333, 0)),
                 _mm_shuffle_ps(v333, v333, 170)));
      v336 = _mm_cmplt_ps(v335, query.m_quad);
      v337 = _mm_shuffle_ps(
               p[(unsigned __int64)v328 / 2 + 1],
               _mm_unpackhi_ps(
                 p[(unsigned __int64)v328 / 2 + 1],
                 _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v335, v336), _mm_andnot_ps(v336, query.m_quad)))),
               196);
      v338 = _mm_mul_ps(v337, v334);
      v339 = _mm_add_ps(_mm_shuffle_ps(v338, v338, 78), v338);
      v340 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               (__m128i)_mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v339, v339, 177), v339), (__m128)0i64),
                               0x1Fu),
                             0x1Fu),
                   v25),
                 v337),
               _mm_mul_ps(v27, v334));
      v341 = _mm_mul_ps(v340, v340);
      v342 = _mm_add_ps(_mm_shuffle_ps(v341, v341, 78), v341);
      v562 = _mm_add_ps(_mm_shuffle_ps(v342, v342, 177), v342);
      v343 = _mm_rsqrt_ps(v562);
      *(__m128 *)(v80 + 8 * v328 + 16) = _mm_mul_ps(
                                           _mm_andnot_ps(
                                             _mm_cmple_ps(v562, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v343, v562), v343)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v343))),
                                           v340);
    }
LABEL_127:
    v229 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v230 = (int)floatsOut;
    v231 = ((_DWORD)floatsOut + 15) & 0xFFFFFFF0;
    if ( (int)floatsOut > v229->m_slabSize || (char *)v228 + v231 != v229->m_cur || v229->m_firstNonLifoEnd == v228 )
      hkLifoAllocator::slowBlockFree(v229, v228, v231);
    else
      v229->m_cur = v228;
    v344 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v230 > v344->m_slabSize || (char *)v479 + v231 != v344->m_cur || v344->m_firstNonLifoEnd == v479 )
      hkLifoAllocator::slowBlockFree(v344, v479, v231);
    else
      v344->m_cur = v479;
    LODWORD(v54) = numBones;
    v13 = (const char *)end;
  }
  v345 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v346 = (_QWORD *)v345[1];
  if ( (unsigned __int64)v346 < v345[3] )
  {
    *v346 = "StCopyReferencePoseF";
    v347 = __rdtsc();
    v348 = v346 + 2;
    *((_DWORD *)v348 - 2) = v347;
    v345[1] = v348;
  }
  v349 = refBones;
  v350 = bonesOut;
  if ( (int)v54 > 0 )
  {
    v351 = (unsigned int)v54;
    v352 = (char *)bonesOut - (char *)refBones;
    do
    {
      v353 = v349->m_translation.m_quad.m128_i32[0];
      v349 = (hkQsTransformf *)((char *)v349 + 4);
      *(int *)((char *)&v349->m_translation.m_quad.m128_i32[-1] + v352) = v353;
      --v351;
    }
    while ( v351 );
  }
  v354 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v355 = (_QWORD *)v354[1];
  if ( (unsigned __int64)v355 < v354[3] )
  {
    *v355 = "StCopyStaticTracksF";
    v356 = __rdtsc();
    v357 = v355 + 2;
    *((_DWORD *)v357 - 2) = v356;
    v354[1] = v357;
  }
  v358 = v12->m_intData.m_data;
  v359 = v12->m_intArrayOffsets[7];
  v360 = &v358[v359];
  v361 = v12->m_intArrayOffsets[8] - v359;
  retaddr = (__int64)&v358[v12->m_intArrayOffsets[5]];
  if ( v361 > 0 )
  {
    v362 = *v360;
    v363 = v483;
    v364 = 0i64;
    v365 = v361 - 1;
    v366 = v365;
    if ( v365 <= 0 )
    {
LABEL_161:
      if ( v362 < (int)v54 )
        v350->m_translation.m_quad.m128_i32[v362] = *v363;
    }
    else
    {
      while ( v362 < (int)v54 )
      {
        v367 = *v363;
        ++v364;
        ++v363;
        v350->m_translation.m_quad.m128_i32[v362] = v367;
        v362 = v360[v364];
        if ( v364 >= v366 )
          goto LABEL_161;
      }
    }
  }
  v368 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v369 = (_QWORD *)v368[1];
  if ( (unsigned __int64)v369 < v368[3] )
  {
    *v369 = "StCopyDynamicTracksF";
    v370 = __rdtsc();
    v371 = v369 + 2;
    *((_DWORD *)v371 - 2) = v370;
    v368[1] = v371;
  }
  if ( v492 != v501 )
  {
    m_firstFloatBlockScaleAndOffsetIndex = v12->m_firstFloatBlockScaleAndOffsetIndex;
    v373 = v12->m_floatData.m_data;
    v13 = v501;
    v29 = (int *)&v373[m_firstFloatBlockScaleAndOffsetIndex + v12->m_floatArrayOffsets[1]];
    v31 = (__int64)&v373[m_firstFloatBlockScaleAndOffsetIndex + v12->m_floatArrayOffsets[2]];
    v481 = &v12->m_intData.m_data[v12->m_intArrayOffsets[3]
                                + ((__int64)(v12->m_intArrayOffsets[5] - v12->m_intArrayOffsets[4]) >> 4)];
  }
  v374 = v12->m_intArrayOffsets[5];
  v375 = v12->m_intArrayOffsets[6] - v374;
  v376 = (v374 - v12->m_intArrayOffsets[4]) & 0x8000000F;
  LODWORD(refFloats) = v375;
  v585 = v376;
  if ( v376 < 0 )
  {
    v376 = (((_BYTE)v376 - 1) | 0xFFFFFFF0) + 1;
    v585 = v376;
  }
  v377 = v375;
  if ( 16 - v376 < v375 )
    v377 = 16 - v376;
  if ( v377 <= 0 )
  {
    v416 = retaddr;
    goto LABEL_211;
  }
  if ( v492 != v501 )
  {
    v378 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v379 = v378[1];
    if ( v379 < v378[3] )
    {
      *(_QWORD *)v379 = "LtloadDynamic";
      *(_QWORD *)(v379 + 16) = "StDecompress";
      v380 = __rdtsc();
      *(_DWORD *)(v379 + 8) = v380;
      v378[1] = v379 + 24;
    }
    if ( v474 )
      v381 = hkaPredictiveBlockCompression::decodeSingleFrame(v13, (int)start, frameData->m128i_i16);
    else
      v381 = hkaPredictiveBlockCompression::decodeAdjacentFrames(v13, (int)start, frameData->m128i_i16);
    v13 = v381;
    v382 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v383 = (_QWORD *)v382[1];
    if ( (unsigned __int64)v383 < v382[3] )
    {
      *v383 = "StDequantize";
      v384 = __rdtsc();
      v385 = v383 + 2;
      *((_DWORD *)v385 - 2) = v384;
      v382[1] = v385;
    }
    v386 = 0i64;
    LODWORD(end) = 956302336;
    v387 = *v481;
    v388 = 0i64;
    ++v481;
    v389 = 4i64;
    do
    {
      if ( (v387 & 1) != 0 )
      {
        v477.m128_i32[v386] = 956302336;
        v478.m128_i32[v386] = 0;
      }
      else
      {
        v390 = *v29++;
        v31 += 4i64;
        v477.m128_i32[v388] = v390;
        v478.m128_i32[v388] = *(_DWORD *)(v31 - 4);
      }
      v387 >>= 1;
      ++v386;
      ++v388;
      --v389;
    }
    while ( v389 );
    v391 = v477;
    v392 = v478;
    v393 = 0i64;
    v394 = 0i64;
    v395 = 4i64;
    v552 = v477;
    v532 = v478;
    do
    {
      if ( (v387 & 1) != 0 )
      {
        v477.m128_i32[v393] = 956302336;
        v478.m128_i32[v393] = 0;
      }
      else
      {
        v396 = *v29++;
        v31 += 4i64;
        v477.m128_i32[v394] = v396;
        v478.m128_i32[v394] = *(_DWORD *)(v31 - 4);
      }
      v387 >>= 1;
      ++v393;
      ++v394;
      --v395;
    }
    while ( v395 );
    v397 = v477;
    v398 = v478;
    v399 = 0i64;
    v400 = 0i64;
    v401 = 4i64;
    v544 = v477;
    v534 = v478;
    do
    {
      if ( (v387 & 1) != 0 )
      {
        v477.m128_i32[v399] = 956302336;
        v478.m128_i32[v399] = 0;
      }
      else
      {
        v402 = *v29++;
        v31 += 4i64;
        v477.m128_i32[v400] = v402;
        v478.m128_i32[v400] = *(_DWORD *)(v31 - 4);
      }
      v387 >>= 1;
      ++v399;
      ++v400;
      --v401;
    }
    while ( v401 );
    v403 = v477;
    v404 = v478;
    v405 = 0i64;
    v406 = 0i64;
    v407 = 4i64;
    v550 = v477;
    v536 = v478;
    do
    {
      if ( (v387 & 1) != 0 )
      {
        v477.m128_i32[v405] = 956302336;
        v478.m128_i32[v405] = 0;
      }
      else
      {
        v408 = *v29++;
        v31 += 4i64;
        v477.m128_i32[v406] = v408;
        v478.m128_i32[v406] = *(_DWORD *)(v31 - 4);
      }
      v387 >>= 1;
      ++v405;
      ++v406;
      --v407;
    }
    while ( v407 );
    v546 = v477;
    v538 = v478;
    v564 = _mm_load_si128(frameData);
    v409 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v564, (__m128i)0i64), 0x10u), 0x10u)),
               v391),
             v392);
    v499 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v564, (__m128i)0i64), 0x10u), 0x10u)),
               v397),
             v398);
    v540 = v409;
    v566 = _mm_load_si128(frameData + 1);
    v495 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v566, (__m128i)0i64), 0x10u), 0x10u)),
               v403),
             v404);
    v503 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v566, (__m128i)0i64), 0x10u), 0x10u)),
               v477),
             v478);
    if ( v474 )
    {
      m_cur[8] = v409;
      m_cur[9] = v499;
      m_cur[10] = v495;
      v410 = v503;
    }
    else
    {
      *m_cur = v409;
      m_cur[1] = v499;
      m_cur[2] = v495;
      m_cur[3] = v503;
      v568 = _mm_load_si128(frameData + 2);
      v513 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v568, (__m128i)0i64), 0x10u), 0x10u)),
                 v544),
               v534);
      v554 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v568, (__m128i)0i64), 0x10u), 0x10u)),
                 v552),
               v532);
      v570 = _mm_load_si128(frameData + 3);
      v507 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v570, (__m128i)0i64), 0x10u), 0x10u)),
                 v550),
               v536);
      v508 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v570, (__m128i)0i64), 0x10u), 0x10u)),
                 v546),
               v538);
      m_cur[4] = v554;
      m_cur[5] = v513;
      m_cur[6] = v507;
      m_cur[7] = v508;
      v572 = _mm_add_ps(_mm_mul_ps(v25, v554), _mm_mul_ps(v27, v540));
      v548 = _mm_add_ps(_mm_mul_ps(v25, v513), _mm_mul_ps(v27, v499));
      v542 = _mm_add_ps(_mm_mul_ps(v25, v507), _mm_mul_ps(v27, v495));
      v530 = _mm_add_ps(_mm_mul_ps(v25, v508), _mm_mul_ps(v27, v503));
      m_cur[8] = v572;
      m_cur[9] = v548;
      m_cur[10] = v542;
      v410 = v530;
    }
    m_cur[11] = v410;
    v411 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v375 = (int)refFloats;
    v412 = (_QWORD *)v411[1];
    v413 = v411;
    if ( (unsigned __int64)v412 < v411[3] )
    {
      *v412 = "lt";
      v414 = __rdtsc();
      v415 = v412 + 2;
      *((_DWORD *)v415 - 2) = v414;
      v413[1] = v415;
    }
  }
  v416 = retaddr;
  v417 = (int)v585;
  v418 = *(unsigned __int16 *)retaddr;
  v419 = 0;
  v420 = 0i64;
  if ( v377 - 1 <= 0 )
  {
LABEL_208:
    v421 = numBones;
    if ( v418 >= numBones )
      goto LABEL_212;
    v350->m_translation.m_quad.m128_i32[v418] = m_cur[8].m128_i32[v417 + v419];
LABEL_211:
    v421 = numBones;
    goto LABEL_212;
  }
  while ( 1 )
  {
    v421 = numBones;
    if ( v418 >= numBones )
      break;
    v422 = v417 + v420++;
    ++v419;
    v350->m_translation.m_quad.m128_i32[v418] = m_cur[8].m128_i32[v422];
    v418 = *(unsigned __int16 *)(retaddr + 2 * v420);
    if ( v420 >= v377 - 1 )
      goto LABEL_208;
  }
LABEL_212:
  if ( v377 < v375 )
  {
    v423 = v377;
    for ( end = v375; v423 < end; v416 = retaddr )
    {
      v424 = *(unsigned __int16 *)(v416 + 2 * v423);
      if ( v424 >= v421 )
        break;
      v425 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v426 = v425[1];
      if ( v426 < v425[3] )
      {
        *(_QWORD *)v426 = "LtloadDynamic";
        *(_QWORD *)(v426 + 16) = "StDecompress";
        v427 = __rdtsc();
        *(_DWORD *)(v426 + 8) = v427;
        v425[1] = v426 + 24;
      }
      if ( v474 )
        v428 = hkaPredictiveBlockCompression::decodeSingleFrame(v13, (int)start, frameData->m128i_i16);
      else
        v428 = hkaPredictiveBlockCompression::decodeAdjacentFrames(v13, (int)start, frameData->m128i_i16);
      v13 = v428;
      v429 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v430 = (_QWORD *)v429[1];
      if ( (unsigned __int64)v430 < v429[3] )
      {
        *v430 = "StDequantize";
        v431 = __rdtsc();
        v432 = v430 + 2;
        *((_DWORD *)v432 - 2) = v431;
        v429[1] = v432;
      }
      v433 = 0i64;
      v585 = 956302336;
      v434 = *v481;
      v435 = 0i64;
      ++v481;
      v436 = 4i64;
      do
      {
        if ( (v434 & 1) != 0 )
        {
          v477.m128_i32[v433] = 956302336;
          v478.m128_i32[v433] = 0;
        }
        else
        {
          v437 = *v29++;
          v31 += 4i64;
          v477.m128_i32[v435] = v437;
          v478.m128_i32[v435] = *(_DWORD *)(v31 - 4);
        }
        v434 >>= 1;
        ++v433;
        ++v435;
        --v436;
      }
      while ( v436 );
      v438 = v477;
      v439 = v478;
      v440 = 0i64;
      v441 = 0i64;
      v442 = 4i64;
      v531 = v477;
      v533 = v478;
      do
      {
        if ( (v434 & 1) != 0 )
        {
          v486.m128_i32[v440] = 956302336;
          v485.m128_i32[v440] = 0;
        }
        else
        {
          v443 = *v29++;
          v31 += 4i64;
          v486.m128_i32[v441] = v443;
          v485.m128_i32[v441] = *(_DWORD *)(v31 - 4);
        }
        v434 >>= 1;
        ++v440;
        ++v441;
        --v442;
      }
      while ( v442 );
      v444 = v486;
      v445 = v485;
      v446 = 0i64;
      v447 = 0i64;
      v448 = 4i64;
      v535 = v486;
      v537 = v485;
      do
      {
        if ( (v434 & 1) != 0 )
        {
          v488.m128_i32[v446] = 956302336;
          v491.m128_i32[v446] = 0;
        }
        else
        {
          v449 = *v29++;
          v31 += 4i64;
          v488.m128_i32[v447] = v449;
          v491.m128_i32[v447] = *(_DWORD *)(v31 - 4);
        }
        v434 >>= 1;
        ++v446;
        ++v447;
        --v448;
      }
      while ( v448 );
      v450 = v488;
      v451 = v491;
      v452 = 0i64;
      v453 = 0i64;
      v454 = 4i64;
      v539 = v488;
      v541 = v491;
      do
      {
        if ( (v434 & 1) != 0 )
        {
          v493.m128_i32[v452] = 956302336;
          v489.m128_i32[v452] = 0;
        }
        else
        {
          v455 = *v29++;
          v31 += 4i64;
          v493.m128_i32[v453] = v455;
          v489.m128_i32[v453] = *(_DWORD *)(v31 - 4);
        }
        v434 >>= 1;
        ++v452;
        ++v453;
        --v454;
      }
      while ( v454 );
      v516 = v493;
      v518 = v489;
      v574 = _mm_load_si128(frameData);
      v456 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v574, (__m128i)0i64), 0x10u), 0x10u)),
                 v438),
               v439);
      v496 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v574, (__m128i)0i64), 0x10u), 0x10u)),
                 v444),
               v445);
      v522 = v456;
      v576 = _mm_load_si128(frameData + 1);
      v497 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v576, (__m128i)0i64), 0x10u), 0x10u)),
                 v450),
               v451);
      v505 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v576, (__m128i)0i64), 0x10u), 0x10u)),
                 v493),
               v489);
      if ( v474 )
      {
        m_cur[8] = v456;
        m_cur[9] = v496;
        m_cur[10] = v497;
        v457 = v505;
      }
      else
      {
        *m_cur = v456;
        m_cur[1] = v496;
        m_cur[2] = v497;
        m_cur[3] = v505;
        v578 = _mm_load_si128(frameData + 2);
        v510 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v578, (__m128i)0i64), 0x10u), 0x10u)),
                   v535),
                 v537);
        v520 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v578, (__m128i)0i64), 0x10u), 0x10u)),
                   v531),
                 v533);
        v580 = _mm_load_si128(frameData + 3);
        v512 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v580, (__m128i)0i64), 0x10u), 0x10u)),
                   v539),
                 v541);
        v514 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v580, (__m128i)0i64), 0x10u), 0x10u)),
                   v516),
                 v518);
        m_cur[4] = v520;
        m_cur[5] = v510;
        m_cur[6] = v512;
        m_cur[7] = v514;
        v582 = _mm_add_ps(_mm_mul_ps(v25, v520), _mm_mul_ps(v27, v522));
        v524 = _mm_add_ps(_mm_mul_ps(v25, v510), _mm_mul_ps(v27, v496));
        v526 = _mm_add_ps(_mm_mul_ps(v25, v512), _mm_mul_ps(v27, v497));
        v528 = _mm_add_ps(_mm_mul_ps(v25, v514), _mm_mul_ps(v27, v505));
        m_cur[8] = v582;
        m_cur[9] = v524;
        m_cur[10] = v526;
        v457 = v528;
      }
      m_cur[11] = v457;
      v458 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v459 = (_QWORD *)v458[1];
      if ( (unsigned __int64)v459 < v458[3] )
      {
        *v459 = "lt";
        v460 = __rdtsc();
        v461 = v459 + 2;
        *((_DWORD *)v461 - 2) = v460;
        v458[1] = v461;
      }
      v462 = (int)refFloats;
      v463 = bonesOut;
      v464 = 0i64;
      if ( v377 + 16 < (int)refFloats )
        v462 = v377 + 16;
      v465 = v462 - 1;
      if ( v423 >= v465 )
      {
LABEL_253:
        v421 = numBones;
        if ( v424 < numBones )
        {
          ++v377;
          v463->m_translation.m_quad.m128_i32[v424] = m_cur[8].m128_i32[v464];
          v421 = numBones;
          ++v423;
        }
      }
      else
      {
        v466 = m_cur + 8;
        while ( 1 )
        {
          v421 = numBones;
          if ( v424 >= numBones )
            break;
          v467 = v466->m128_i32[0];
          ++v423;
          ++v377;
          ++v464;
          v466 = (__m128 *)((char *)v466 + 4);
          v463->m_translation.m_quad.m128_i32[v424] = v467;
          v424 = *(unsigned __int16 *)(retaddr + 2 * v423);
          if ( v423 >= v465 )
            goto LABEL_253;
        }
      }
    }
  }
  v468 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v468->m_slabSize < 256 || &m_cur[16] != v468->m_cur || v468->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v468, m_cur, 256);
  else
    v468->m_cur = m_cur;
  v469 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v469->m_slabSize < 128 || &frameData[8] != v469->m_cur || v469->m_firstNonLifoEnd == frameData )
    hkLifoAllocator::slowBlockFree(v469, frameData, 128);
  else
    v469->m_cur = frameData;
  v470 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v471 = (_QWORD *)v470[1];
  if ( (unsigned __int64)v471 < v470[3] )
  {
    *v471 = "lt";
    v472 = __rdtsc();
    v473 = v471 + 2;
    *((_DWORD *)v473 - 2) = v472;
    v470[1] = v473;
  }
}= _mm_add_ps(_mm_mul_ps(v25, v514), _mm_mul_ps(v27, v505));
        m_cur[8] = v582;
        m_cur[9] = v524;
        m_cur[10] = v526;
        v457 = v528;
      }
      m_cur[11] = v457;
      v458 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v459 = (_QWORD *)v458[1];
      if ( (unsigned __int64)v459 < v458[3] )
      {
        *v459 = "lt";
        v460 = __rdtsc();
        v461 = v459 + 2;
        *((_DWORD *)v461 - 2) = v460;
        v458[1] = v461;
      }
      v462 = (int)refFloats;
      v463 = bonesOut;
      v464 = 0i64;
      if ( v377 + 16 < (int)refFloats )
        v462 = v377 + 16;
      v465 = v462 - 1;
      if ( v423 >= v465 )
      {
LABEL_253:
        v421 = numBones;
        if ( v424 < numBones )
        {
          ++v377;
          v463->m_translation.m_quad.m128_i32[v424] = m_cur[8].m128_i32[v464];
          v421 = numBones;
          ++v423;
        }
      }
      else
      {
        v466 = m_cur + 8;
        while ( 1 )
        {
          v421 = numBones;
          if ( v424 >= numBones )
            break;
      

// File Line: 849
// RVA: 0xB2F690
__int64 __fastcall hkaPredictiveCompressedAnimation::getNumDataChunks(
        hkaPredictiveCompressedAnimation *this,
        unsigned int frame,
        float delta)
{
  return 4i64;
}

// File Line: 854
// RVA: 0xB2F810
void __fastcall hkaPredictiveCompressedAnimation::recoverChunkData(
        hkaPredictiveCompressedAnimation *this,
        hkaAnimation::DataChunk *ch,
        int numChunks)
{
  int m_size; // r8d
  char *m_data; // rax
  int v6; // ecx
  int v7; // ecx

  m_size = ch[1].m_size;
  m_data = (char *)ch[1].m_data;
  this->m_compressedData.m_size = m_size;
  this->m_compressedData.m_data = m_data;
  this->m_compressedData.m_capacityAndFlags = m_size | 0x80000000;
  v6 = ch[2].m_size >> 1;
  this->m_intData.m_data = (unsigned __int16 *)ch[2].m_data;
  this->m_intData.m_size = v6;
  this->m_intData.m_capacityAndFlags = v6 | 0x80000000;
  v7 = ch[3].m_size >> 2;
  this->m_floatData.m_data = (float *)ch[3].m_data;
  this->m_floatData.m_size = v7;
  this->m_floatData.m_capacityAndFlags = v7 | 0x80000000;
}

// File Line: 863
// RVA: 0xB2F6A0
void __fastcall hkaPredictiveCompressedAnimation::getDataChunks(
        hkaPredictiveCompressedAnimation *this,
        unsigned int frame,
        float delta,
        hkaAnimation::DataChunk *ch)
{
  unsigned int v6; // edx
  float *v7; // rcx
  int m_size; // edx
  unsigned __int16 *m_data; // rax
  int v10; // eax
  unsigned int start; // [rsp+30h] [rbp+8h] BYREF
  unsigned int end; // [rsp+48h] [rbp+20h] BYREF

  ch->m_data = (const char *)this;
  ch->m_size = 192;
  hkaPredictiveCompressedAnimation::getCompressedDataOffset(this, frame, &start, &end);
  v6 = start;
  v7 = 0i64;
  ch[1].m_data = &this->m_compressedData.m_data[start];
  ch[1].m_size = end - v6;
  m_size = this->m_intData.m_size;
  m_data = 0i64;
  if ( m_size )
    m_data = this->m_intData.m_data;
  ch[2].m_data = (const char *)m_data;
  ch[2].m_size = 2 * m_size;
  v10 = this->m_floatData.m_size;
  if ( v10 )
    v7 = this->m_floatData.m_data;
  ch[3].m_data = (const char *)v7;
  ch[3].m_size = 4 * v10;
}

// File Line: 874
// RVA: 0xB2F730
unsigned __int64 __fastcall hkaPredictiveCompressedAnimation::getMaxSizeOfCombinedDataChunks(
        hkaPredictiveCompressedAnimation *this)
{
  return ((4i64 * (unsigned int)this->m_floatData.m_size + 15) & 0xFFFFFFFFFFFFFFF0ui64)
       + ((this->m_maxCompressedBytesPerFrame + 31) & 0xFFFFFFF0)
       + ((2i64 * (unsigned int)this->m_intData.m_size + 15) & 0xFFFFFFFFFFFFFFF0ui64)
       + 192;
}

// File Line: 884
// RVA: 0xB2F780
__int64 __fastcall hkaPredictiveCompressedAnimation::getMaxDecompressionTempBytes(
        hkaPredictiveCompressedAnimation *this)
{
  hkaSkeleton *m_skeleton; // rax
  unsigned int v2; // r9d

  m_skeleton = this->m_skeleton;
  v2 = (m_skeleton->m_bones.m_size + 3) & 0xFFFFFFFC;
  return ((v2 + 15) & 0xFFFFFFF0)
       + ((((m_skeleton->m_floatSlots.m_size + 3) & 0xFFFFFFFC) + 15) & 0xFFFFFFF0)
       + 4 * (((m_skeleton->m_floatSlots.m_size + 3) & 0xFFFFFFFC) + 4 * (v2 + 2 * (v2 + 8)))
       + 96i64 * v2;
}

// File Line: 910
// RVA: 0xB32220
void __fastcall hkaPredictiveCompressedAnimation::samplePartialWithDataChunks(
        unsigned int frameIndex,
        float frameDelta,
        int numTransformTracks,
        int numFloatTracks,
        hkQsTransformf *referenceBones,
        const float *referenceFloats,
        hkaAnimation::DataChunk *chunks,
        int numChunks,
        hkQsTransformf *transformTracksOut,
        float *floatTracksOut)
{
  hkaPredictiveCompressedAnimation *m_data; // r13
  __int64 numBones; // r15
  __int64 v14; // r12
  hkLifoAllocator *Value; // rax
  int v16; // edx
  char *v17; // rcx
  hkLifoAllocator *v18; // rax
  float *floatsOut; // rsi
  int v20; // edx
  char *v21; // rcx
  hkLifoAllocator *v22; // rax
  char *boneWeightsInOut; // rbp
  int v24; // edx
  char *v25; // rcx
  hkLifoAllocator *v26; // rax
  char *floatWeightsInOut; // rdi
  int v28; // edx
  char *v29; // rcx
  int v30; // edx
  int v31; // r9d
  __int64 v32; // r8
  hkVector4f *p_m_scale; // rcx
  hkQsTransformf *v35; // rax
  __int64 v37; // r8
  float *v38; // r9
  int v39; // ebx
  hkLifoAllocator *v40; // rax
  int v41; // r8d
  int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // r8d
  int v45; // ebx
  hkLifoAllocator *v46; // rax
  int v47; // r8d
  int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // r8d
  __int64 numFloats; // [rsp+38h] [rbp-80h]
  hkQsTransformf *bonesOut; // [rsp+70h] [rbp-48h]

  m_data = (hkaPredictiveCompressedAnimation *)chunks->m_data;
  numBones = *((int *)chunks->m_data + 39);
  v14 = *((int *)chunks->m_data + 40);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesOut = (hkQsTransformf *)Value->m_cur;
  v16 = (48 * ((numBones + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v17 = (char *)bonesOut + v16;
  if ( v16 > Value->m_slabSize || v17 > Value->m_end )
    bonesOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v16);
  else
    Value->m_cur = v17;
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  floatsOut = (float *)v18->m_cur;
  v20 = (4 * ((v14 + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v21 = (char *)floatsOut + v20;
  if ( v20 > v18->m_slabSize || v21 > v18->m_end )
    floatsOut = (float *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
  else
    v18->m_cur = v21;
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  boneWeightsInOut = (char *)v22->m_cur;
  v24 = (((numBones + 15) & 0xFFFFFFF0) + 127) & 0xFFFFFF80;
  v25 = &boneWeightsInOut[v24];
  if ( v24 > v22->m_slabSize || v25 > v22->m_end )
    boneWeightsInOut = (char *)hkLifoAllocator::allocateFromNewSlab(v22, v24);
  else
    v22->m_cur = v25;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  floatWeightsInOut = (char *)v26->m_cur;
  v28 = (((v14 + 15) & 0xFFFFFFF0) + 127) & 0xFFFFFF80;
  v29 = &floatWeightsInOut[v28];
  if ( v28 > v26->m_slabSize || v29 > v26->m_end )
    floatWeightsInOut = (char *)hkLifoAllocator::allocateFromNewSlab(v26, v28);
  else
    v26->m_cur = v29;
  hkString::memSet(boneWeightsInOut, 255, numBones);
  hkString::memSet(floatWeightsInOut, 255, v14);
  LODWORD(numFloats) = v14;
  hkaPredictiveCompressedAnimation::sampleFullPose(
    m_data,
    frameIndex,
    frameDelta,
    chunks[1].m_data,
    referenceBones,
    referenceFloats,
    numBones,
    numFloats,
    bonesOut,
    floatsOut,
    boneWeightsInOut,
    floatWeightsInOut);
  v30 = 0;
  v31 = 0;
  v32 = 0i64;
  if ( (int)numBones > 0 )
  {
    p_m_scale = &bonesOut->m_scale;
    do
    {
      if ( v31 >= numTransformTracks )
        break;
      if ( boneWeightsInOut[v32] )
      {
        v35 = transformTracksOut++;
        v35->m_translation = (hkVector4f)p_m_scale[-2].m_quad;
        ++v31;
        v35->m_rotation.m_vec = (hkVector4f)p_m_scale[-1].m_quad;
        v35->m_scale = (hkVector4f)p_m_scale->m_quad;
      }
      ++v32;
      p_m_scale += 3;
    }
    while ( v32 < numBones );
  }
  v37 = 0i64;
  if ( v14 < 4 )
  {
LABEL_38:
    while ( v37 < v14 )
    {
      if ( v30 >= numFloatTracks )
        break;
      if ( floatWeightsInOut[v37] )
      {
        ++floatTracksOut;
        ++v30;
        *(floatTracksOut - 1) = floatsOut[v37];
      }
      ++v37;
    }
  }
  else
  {
    v38 = floatsOut + 2;
    while ( v30 < numFloatTracks )
    {
      if ( floatWeightsInOut[v37] )
      {
        ++floatTracksOut;
        ++v30;
        *(floatTracksOut - 1) = *(v38 - 2);
      }
      if ( v30 >= numFloatTracks )
        break;
      if ( floatWeightsInOut[v37 + 1] )
      {
        ++floatTracksOut;
        ++v30;
        *(floatTracksOut - 1) = *(v38 - 1);
      }
      if ( v30 >= numFloatTracks )
        break;
      if ( floatWeightsInOut[v37 + 2] )
      {
        ++floatTracksOut;
        ++v30;
        *(floatTracksOut - 1) = *v38;
      }
      if ( v30 >= numFloatTracks )
        break;
      if ( floatWeightsInOut[v37 + 3] )
      {
        ++floatTracksOut;
        ++v30;
        *(floatTracksOut - 1) = v38[1];
      }
      v37 += 4i64;
      v38 += 4;
      if ( v37 >= v14 - 3 )
        goto LABEL_38;
    }
  }
  v39 = (((v14 + 15) & 0xFFFFFFF0) + 127) & 0xFFFFFF80;
  v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v41 = (v39 + 15) & 0xFFFFFFF0;
  if ( v39 > v40->m_slabSize || &floatWeightsInOut[v41] != v40->m_cur || v40->m_firstNonLifoEnd == floatWeightsInOut )
    hkLifoAllocator::slowBlockFree(v40, floatWeightsInOut, v41);
  else
    v40->m_cur = floatWeightsInOut;
  v42 = (((numBones + 15) & 0xFFFFFFF0) + 127) & 0xFFFFFF80;
  v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v44 = (v42 + 15) & 0xFFFFFFF0;
  if ( v42 > v43->m_slabSize || &boneWeightsInOut[v44] != v43->m_cur || v43->m_firstNonLifoEnd == boneWeightsInOut )
    hkLifoAllocator::slowBlockFree(v43, boneWeightsInOut, v44);
  else
    v43->m_cur = boneWeightsInOut;
  v45 = (4 * ((v14 + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v47 = (v45 + 15) & 0xFFFFFFF0;
  if ( v45 > v46->m_slabSize || (char *)floatsOut + v47 != v46->m_cur || v46->m_firstNonLifoEnd == floatsOut )
    hkLifoAllocator::slowBlockFree(v46, floatsOut, v47);
  else
    v46->m_cur = floatsOut;
  v48 = (48 * ((numBones + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v50 = (v48 + 15) & 0xFFFFFFF0;
  if ( v48 > v49->m_slabSize || (char *)bonesOut + v50 != v49->m_cur || v49->m_firstNonLifoEnd == bonesOut )
    hkLifoAllocator::slowBlockFree(v49, bonesOut, v50);
  else
    v49->m_cur = bonesOut;
}

// File Line: 964
// RVA: 0xB2F1B0
void __fastcall hkaPredictiveCompressedAnimation::sampleTracks(
        hkaPredictiveCompressedAnimation *this,
        float time,
        hkQsTransformf *transformTracksOut,
        float *floatTracksOut)
{
  hkaSkeleton *m_skeleton; // rdx
  int numBones; // r12d
  int m_size; // edi
  hkLifoAllocator *Value; // rax
  hkQsTransformf *bonesOut; // r13
  int v11; // r15d
  char *v12; // rcx
  hkLifoAllocator *v13; // rax
  float *floatsOut; // r14
  int v15; // ecx
  char *v16; // rdx
  hkLifoAllocator *v17; // rax
  char *boneWeightsInOut; // rbp
  int v19; // ecx
  char *v20; // rdx
  hkLifoAllocator *v21; // rcx
  int v22; // eax
  char *floatWeightsInOut; // rdi
  int v24; // eax
  char *v25; // rdx
  int v26; // eax
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  unsigned int v30; // eax
  __m128i v31; // xmm5
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  unsigned int v35; // edx
  float v36; // xmm6_4
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __int64 v39; // rcx
  __int64 v40; // r8
  hkVector4f *p_m_scale; // rdx
  hkQsTransformf *v42; // rax
  float *v43; // rdx
  hkLifoAllocator *v44; // rax
  int v45; // r8d
  hkLifoAllocator *v46; // rax
  int v47; // r8d
  hkLifoAllocator *v48; // rax
  int v49; // r8d
  hkLifoAllocator *v50; // rax
  int v51; // r8d
  int v53; // [rsp+68h] [rbp-60h]
  int v54; // [rsp+6Ch] [rbp-5Ch]
  int v55; // [rsp+70h] [rbp-58h]
  int n; // [rsp+D8h] [rbp+10h]

  m_skeleton = this->m_skeleton;
  numBones = m_skeleton->m_referencePose.m_size;
  m_size = m_skeleton->m_referenceFloats.m_size;
  if ( this->m_numBones < numBones )
    numBones = this->m_numBones;
  if ( this->m_numFloatSlots < m_size )
    m_size = this->m_numFloatSlots;
  n = m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesOut = (hkQsTransformf *)Value->m_cur;
  v11 = (48 * numBones + 127) & 0xFFFFFF80;
  v12 = (char *)bonesOut + v11;
  if ( v11 > Value->m_slabSize || v12 > Value->m_end )
    bonesOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
  else
    Value->m_cur = v12;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  floatsOut = (float *)v13->m_cur;
  v15 = (4 * m_size + 127) & 0xFFFFFF80;
  v55 = v15;
  v16 = (char *)floatsOut + v15;
  if ( v15 > v13->m_slabSize || v16 > v13->m_end )
    floatsOut = (float *)hkLifoAllocator::allocateFromNewSlab(v13, v15);
  else
    v13->m_cur = v16;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  boneWeightsInOut = (char *)v17->m_cur;
  v19 = (numBones + 127) & 0xFFFFFF80;
  v54 = v19;
  v20 = &boneWeightsInOut[v19];
  if ( v19 > v17->m_slabSize || v20 > v17->m_end )
    boneWeightsInOut = (char *)hkLifoAllocator::allocateFromNewSlab(v17, v19);
  else
    v17->m_cur = v20;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = m_size + 127;
  floatWeightsInOut = (char *)v21->m_cur;
  v24 = v22 & 0xFFFFFF80;
  v53 = v24;
  v25 = &floatWeightsInOut[v24];
  if ( v24 > v21->m_slabSize || v25 > v21->m_end )
    floatWeightsInOut = (char *)hkLifoAllocator::allocateFromNewSlab(v21, v24);
  else
    v21->m_cur = v25;
  hkString::memSet(boneWeightsInOut, 255, numBones);
  hkString::memSet(floatWeightsInOut, 255, n);
  v26 = ((__int64 (__fastcall *)(hkaPredictiveCompressedAnimation *))this->vfptr[4].__vecDelDtor)(this) - 1;
  v27 = 0i64;
  v28 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  v29 = _mm_rcp_ps(v28);
  v27.m128_f32[0] = (float)v26;
  v30 = v26 - 1;
  v31 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(v27, v27, 0),
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v29)), v29),
                       _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0))),
                   _mm_cmplt_ps((__m128)0i64, v28));
  v32 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v31, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v33 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v31, 1u), 1u));
  v34 = _mm_or_ps(
          _mm_andnot_ps(v33, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v31, v32)), v32)),
          _mm_and_ps((__m128)v31, v33));
  v35 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v34));
  if ( v35 <= v30 )
  {
    v37 = _mm_sub_ps((__m128)v31, v34);
    v38 = _mm_cmplt_ps(v37, query.m_quad);
    v36 = fmax(0.0, COERCE_FLOAT(_mm_andnot_ps(v38, query.m_quad).m128_u32[0] | v37.m128_i32[0] & v38.m128_i32[0]));
  }
  else
  {
    v36 = *(float *)&FLOAT_1_0;
    v35 = v30;
  }
  hkaPredictiveCompressedAnimation::sampleFullPose(
    this,
    v35,
    v36,
    0i64,
    this->m_skeleton->m_referencePose.m_data,
    this->m_skeleton->m_referenceFloats.m_data,
    numBones,
    n,
    bonesOut,
    floatsOut,
    boneWeightsInOut,
    floatWeightsInOut);
  v39 = 0i64;
  v40 = 0i64;
  if ( numBones > 0 )
  {
    p_m_scale = &bonesOut->m_scale;
    do
    {
      if ( boneWeightsInOut[v40] )
      {
        v42 = transformTracksOut++;
        v42->m_translation = (hkVector4f)p_m_scale[-2].m_quad;
        v42->m_rotation.m_vec = (hkVector4f)p_m_scale[-1].m_quad;
        v42->m_scale = (hkVector4f)p_m_scale->m_quad;
      }
      ++v40;
      p_m_scale += 3;
    }
    while ( v40 < numBones );
  }
  if ( n >= 4i64 )
  {
    v43 = floatsOut + 2;
    do
    {
      if ( floatWeightsInOut[v39] )
        *floatTracksOut++ = *(v43 - 2);
      if ( floatWeightsInOut[v39 + 1] )
        *floatTracksOut++ = *(v43 - 1);
      if ( floatWeightsInOut[v39 + 2] )
        *floatTracksOut++ = *v43;
      if ( floatWeightsInOut[v39 + 3] )
        *floatTracksOut++ = v43[1];
      v39 += 4i64;
      v43 += 4;
    }
    while ( v39 < n - 3i64 );
  }
  for ( ; v39 < n; ++v39 )
  {
    if ( floatWeightsInOut[v39] )
      *floatTracksOut++ = floatsOut[v39];
  }
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v45 = (v53 + 15) & 0xFFFFFFF0;
  if ( v53 > v44->m_slabSize || &floatWeightsInOut[v45] != v44->m_cur || v44->m_firstNonLifoEnd == floatWeightsInOut )
    hkLifoAllocator::slowBlockFree(v44, floatWeightsInOut, v45);
  else
    v44->m_cur = floatWeightsInOut;
  v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v47 = (v54 + 15) & 0xFFFFFFF0;
  if ( v54 > v46->m_slabSize || &boneWeightsInOut[v47] != v46->m_cur || v46->m_firstNonLifoEnd == boneWeightsInOut )
    hkLifoAllocator::slowBlockFree(v46, boneWeightsInOut, v47);
  else
    v46->m_cur = boneWeightsInOut;
  v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v49 = (v55 + 15) & 0xFFFFFFF0;
  if ( v55 > v48->m_slabSize || (char *)floatsOut + v49 != v48->m_cur || v48->m_firstNonLifoEnd == floatsOut )
    hkLifoAllocator::slowBlockFree(v48, floatsOut, v49);
  else
    v48->m_cur = floatsOut;
  v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v51 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v50->m_slabSize || (char *)bonesOut + v51 != v50->m_cur || v50->m_firstNonLifoEnd == bonesOut )
    hkLifoAllocator::slowBlockFree(v50, bonesOut, v51);
  else
    v50->m_cur = bonesOut;
}

// File Line: 1019
// RVA: 0xB2F670
void __fastcall hkaPredictiveCompressedAnimation::sampleIndividualFloatTracks(
        hkaPredictiveCompressedAnimation *this,
        float time,
        const __int16 *tracks,
        unsigned int numTracks)
{
  ;
}

// File Line: 1023
// RVA: 0xB2F660
void __fastcall hkaPredictiveCompressedAnimation::sampleIndividualTransformTracks(
        hkaPredictiveCompressedAnimation *this,
        float time,
        const __int16 *tracks,
        unsigned int numTracks)
{
  ;
}

// File Line: 1027
// RVA: 0xB2F680
__int64 __fastcall hkaPredictiveCompressedAnimation::getNumOriginalFrames(hkaPredictiveCompressedAnimation *this)
{
  return (unsigned int)this->m_numFrames;
}

// File Line: 1032
// RVA: 0xB2F880
void __fastcall hkaPredictiveCompressedAnimation::sampleFullPose(
        hkaPredictiveCompressedAnimation *this,
        hkQsTransformf *bonesOut,
        float *floatsOut,
        float time)
{
  int v7; // eax
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  unsigned int v10; // eax
  __m128 v11; // xmm1
  __m128i v12; // xmm5
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm4
  unsigned int v16; // edx
  float v17; // xmm6_4
  __m128 v18; // xmm5
  __m128 v19; // xmm1

  v7 = ((__int64 (__fastcall *)(hkaPredictiveCompressedAnimation *))this->vfptr[4].__vecDelDtor)(this) - 1;
  v8 = 0i64;
  v9 = _mm_shuffle_ps((__m128)LODWORD(this->m_duration), (__m128)LODWORD(this->m_duration), 0);
  v8.m128_f32[0] = (float)v7;
  v10 = v7 - 1;
  v11 = _mm_rcp_ps(v9);
  v12 = (__m128i)_mm_and_ps(
                   _mm_cmplt_ps((__m128)0i64, v9),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v11)), v11),
                       _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0)),
                     _mm_shuffle_ps(v8, v8, 0)));
  v13 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v12, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v14 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v12, 1u), 1u));
  v15 = _mm_or_ps(
          _mm_andnot_ps(v14, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v12, v13)), v13)),
          _mm_and_ps(v14, (__m128)v12));
  v16 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v15));
  if ( v16 <= v10 )
  {
    v18 = _mm_sub_ps((__m128)v12, v15);
    v19 = _mm_cmplt_ps(v18, query.m_quad);
    v17 = fmax(0.0, COERCE_FLOAT(v18.m128_i32[0] & v19.m128_i32[0] | _mm_andnot_ps(v19, query.m_quad).m128_u32[0]));
  }
  else
  {
    v17 = *(float *)&FLOAT_1_0;
    v16 = v10;
  }
  hkaPredictiveCompressedAnimation::sampleFullPose(
    this,
    v16,
    v17,
    0i64,
    this->m_skeleton->m_referencePose.m_data,
    this->m_skeleton->m_referenceFloats.m_data,
    this->m_numBones,
    this->m_numFloatSlots,
    bonesOut,
    floatsOut,
    0i64,
    0i64);
}

// File Line: 1046
// RVA: 0xB32200
__int64 __fastcall hkaPredictiveCompressedAnimation::getSizeInBytes(hkaPredictiveCompressedAnimation *this)
{
  return (unsigned int)this->m_compressedData.m_size
       + 2 * ((unsigned int)this->m_intData.m_size + 2 * ((unsigned int)this->m_floatData.m_size + 48i64));
}

// File Line: 1051
// RVA: 0xB2F7E0
char __fastcall hkaPredictiveCompressedAnimation::requiresSkeleton(hkaPredictiveCompressedAnimation *this)
{
  return 1;
}

// File Line: 1056
// RVA: 0xB2F7F0
hkaSkeleton *__fastcall hkaPredictiveCompressedAnimation::getSkeleton(hkaPredictiveCompressedAnimation *this)
{
  return this->m_skeleton;
}

// File Line: 1061
// RVA: 0xB2F800
void __fastcall hkaPredictiveCompressedAnimation::setSkeleton(
        hkaPredictiveCompressedAnimation *this,
        hkaSkeleton *skeleton)
{
  this->m_skeleton = skeleton;
}

