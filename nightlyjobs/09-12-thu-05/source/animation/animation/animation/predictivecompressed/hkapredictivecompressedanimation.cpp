// File Line: 25
// RVA: 0xB2EF60
void __fastcall hkaPredictiveCompressedAnimation::TrackCompressionParams::TrackCompressionParams(hkaPredictiveCompressedAnimation::TrackCompressionParams *this)
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
void __fastcall hkaPredictiveCompressedAnimation::CompressionParams::CompressionParams(hkaPredictiveCompressedAnimation::CompressionParams *this)
{
  hkaPredictiveCompressedAnimation::CompressionParams *v1; // rbx
  _DWORD *v2; // rax
  _DWORD *v3; // rdi
  _DWORD *v4; // rcx
  hkaPredictiveCompressedAnimation::TrackCompressionParams v5; // [rsp+20h] [rbp-28h]

  this->m_parameterPalette.m_capacityAndFlags = 2147483648;
  v1 = this;
  this->m_parameterPalette.m_data = 0i64;
  this->m_parameterPalette.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_data = 0i64;
  this->m_trackIndexToPaletteIndex.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_capacityAndFlags = 2147483648;
  this->m_floatTrackIndexToPaletteIndex.m_data = 0i64;
  this->m_floatTrackIndexToPaletteIndex.m_size = 0;
  this->m_floatTrackIndexToPaletteIndex.m_capacityAndFlags = 2147483648;
  hkaPredictiveCompressedAnimation::TrackCompressionParams::TrackCompressionParams(&v5);
  v3 = v2;
  if ( v1->m_parameterPalette.m_size == (v1->m_parameterPalette.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, 32);
  v4 = (_DWORD *)&v1->m_parameterPalette.m_data[v1->m_parameterPalette.m_size].m_staticTranslationTolerance;
  if ( v4 )
  {
    *v4 = *v3;
    v4[1] = v3[1];
    v4[2] = v3[2];
    v4[3] = v3[3];
    v4[4] = v3[4];
    v4[5] = v3[5];
    v4[6] = v3[6];
    v4[7] = v3[7];
  }
  ++v1->m_parameterPalette.m_size;
}

// File Line: 36
// RVA: 0xB2F060
void __fastcall hkaPredictiveCompressedAnimation::CompressionParams::CompressionParams(hkaPredictiveCompressedAnimation::CompressionParams *this, float staticTranslationTolerance, float staticRotationTolerance, float staticScaleTolerance, float staticFloatTolerance, float dynamicTranslationTolerance, float dynamicRotationTolerance, float dynamicScaleTolerance, float dynamicFloatTolerance)
{
  hkaPredictiveCompressedAnimation::CompressionParams *v9; // rbx
  float *v10; // rax
  hkaPredictiveCompressedAnimation::TrackCompressionParams v11; // [rsp+20h] [rbp-A8h]

  this->m_parameterPalette.m_capacityAndFlags = 2147483648;
  v9 = this;
  this->m_parameterPalette.m_data = 0i64;
  this->m_parameterPalette.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_data = 0i64;
  this->m_trackIndexToPaletteIndex.m_size = 0;
  this->m_trackIndexToPaletteIndex.m_capacityAndFlags = 2147483648;
  this->m_floatTrackIndexToPaletteIndex.m_data = 0i64;
  this->m_floatTrackIndexToPaletteIndex.m_size = 0;
  this->m_floatTrackIndexToPaletteIndex.m_capacityAndFlags = 2147483648;
  hkaPredictiveCompressedAnimation::TrackCompressionParams::TrackCompressionParams(&v11);
  if ( v9->m_parameterPalette.m_size == (v9->m_parameterPalette.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9, 32);
  v10 = &v9->m_parameterPalette.m_data[v9->m_parameterPalette.m_size].m_staticTranslationTolerance;
  if ( v10 )
  {
    *v10 = staticTranslationTolerance;
    v10[1] = staticRotationTolerance;
    v10[2] = staticScaleTolerance;
    v10[3] = staticFloatTolerance;
    v10[4] = dynamicTranslationTolerance;
    v10[5] = dynamicRotationTolerance;
    v10[6] = dynamicScaleTolerance;
    v10[7] = dynamicFloatTolerance;
  }
  ++v9->m_parameterPalette.m_size;
}

// File Line: 51
// RVA: 0xB326F0
__int64 __fastcall weightFromBit(int b)
{
  return (unsigned __int8)-(char)b;
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
                  _mm_cmpleps(v3, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v4, v3), v4)),
                    _mm_mul_ps(*(__m128 *)_xmm, v4))),
                q->m_quad);
}

// File Line: 70
// RVA: 0xB32760
void __fastcall applyWeights(const unsigned __int16 **bitmap, char *weights, int n)
{
  int v3; // er10
  __int64 v4; // r9
  char *v5; // rbx
  const unsigned __int16 **v6; // rdi
  __int64 v7; // r11
  int v8; // edx
  signed int v9; // eax
  __int64 v10; // r8
  char *v11; // rax
  char v12; // cl

  if ( weights )
  {
    v3 = n;
    v4 = 0i64;
    v5 = weights;
    v6 = bitmap;
    v7 = n;
    if ( n > 0 )
    {
      do
      {
        v8 = **v6;
        ++*v6;
        v9 = 16;
        if ( v3 < 16 )
          v9 = v3;
        v10 = v9;
        if ( v9 > 0 )
        {
          v11 = &v5[v4];
          do
          {
            v12 = v8;
            v8 >>= 1;
            ++v11;
            *(v11 - 1) &= -(v12 & 1);
            --v10;
          }
          while ( v10 );
        }
        v4 += 16i64;
        v3 -= 16;
      }
      while ( v4 < v7 );
    }
  }
}

// File Line: 90
// RVA: 0xB32810
void __fastcall dequantize8(const __int16 *quant, hkVector4f *f_leftscale, hkVector4f *f_rightscale, hkVector4f *f_leftoff, hkVector4f *f_rightoff, hkVector4f *out_left, hkVector4f *out_right)
{
  __m128i v7; // xmm0

  v7 = _mm_load_si128((const __m128i *)quant);
  out_left->m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v7, (__m128i)0i64), 0x10u), 0x10u)),
                         f_leftscale->m_quad),
                       f_leftoff->m_quad);
  out_right->m_quad = _mm_add_ps(
                        _mm_mul_ps(
                          _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v7, (__m128i)0i64), 0x10u), 0x10u)),
                          f_rightscale->m_quad),
                        f_rightoff->m_quad);
}

// File Line: 108
// RVA: 0xB32870
void __fastcall lerp(hkVector4f *a, hkSimdFloat32 *aw, hkVector4f *b, hkSimdFloat32 *bw, hkVector4f *out)
{
  hkVector4f v5; // xmm1

  v5.m_quad = _mm_mul_ps(a->m_quad, aw->m_real);
  *out = (hkVector4f)v5.m_quad;
  out->m_quad = _mm_add_ps(_mm_mul_ps(b->m_quad, bw->m_real), v5.m_quad);
}

// File Line: 168
// RVA: 0xB328A0
void __fastcall expandParams(unsigned __int16 *fixed, hkVector4f *scale, hkVector4f *offset, const float **scalePtr, const float **offsetPtr, hkSimdFloat32 *fixedScale, hkSimdFloat32 *fixedOffset)
{
  __int64 v7; // r10
  unsigned __int16 *v8; // r11
  signed __int64 v9; // rdi
  __int64 v10; // rbx
  __m128 v11; // xmm1
  const float *v12; // rcx
  const float *v13; // rcx
  hkVector4f v14; // xmm1
  hkVector4f v15; // [rsp+0h] [rbp-28h]
  __m128 v16; // [rsp+10h] [rbp-18h]

  v7 = 0i64;
  v8 = fixed;
  v9 = 4i64;
  v10 = 0i64;
  do
  {
    if ( *(_BYTE *)v8 & 1 )
    {
      v11 = fixedOffset->m_real;
      v15.m_quad.m128_i32[v7] = (int)*fixedScale;
      v16.m128_i32[v7] = v11.m128_i32[0];
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
    *v8 >>= 1;
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
void __fastcall loadDynamicData(const char **compressedData, const int frame, const bool singleFrame, const float **scalePtr, const float **offsetPtr, const unsigned __int16 **isFixedRange, __int16 *scratchSpace)
{
  const char **v7; // rdi
  const float **v8; // rbx
  bool v9; // r15
  int v10; // esi
  _QWORD *v11; // rcx
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rax
  const char *v14; // rcx
  const char *v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  __int64 v20; // r9
  signed __int64 v21; // rdi
  unsigned __int16 v22; // dx
  __int64 v23; // r10
  __int64 v24; // r11
  signed __int64 v25; // rsi
  const float *v26; // rcx
  int *v27; // rcx
  __m128 v28; // xmm8
  __int64 v29; // r10
  __int64 v30; // r11
  signed __int64 v31; // rsi
  const float *v32; // rcx
  int *v33; // rcx
  __m128 v34; // xmm6
  __m128 v35; // xmm7
  __int64 v36; // r10
  __int64 v37; // r11
  signed __int64 v38; // rsi
  const float *v39; // rcx
  int *v40; // rcx
  __m128 v41; // xmm4
  __m128 v42; // xmm5
  __int64 v43; // r10
  const float *v44; // rcx
  int *v45; // rcx
  __m128i v46; // xmm1
  __m128 v47; // xmm10
  __m128i v48; // xmm0
  __m128i v49; // xmm1
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
  signed __int64 v69; // rcx
  __m128 v70; // [rsp+18h] [rbp-79h]
  __m128 v71; // [rsp+28h] [rbp-69h]
  float retaddr; // [rsp+D8h] [rbp+47h]
  int **v73; // [rsp+E8h] [rbp+57h]
  unsigned __int16 **v74; // [rsp+F0h] [rbp+5Fh]
  __m128i *frameData; // [rsp+F8h] [rbp+67h]

  v7 = compressedData;
  v8 = scalePtr;
  v9 = singleFrame;
  v10 = frame;
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = v11[1];
  if ( v12 < v11[3] )
  {
    *(_QWORD *)v12 = "LtloadDynamic";
    *(_QWORD *)(v12 + 16) = "StDecompress";
    v13 = __rdtsc();
    *(_DWORD *)(v12 + 8) = v13;
    v11[1] = v12 + 24;
  }
  v14 = *v7;
  if ( v9 )
    v15 = hkaPredictiveBlockCompression::decodeSingleFrame(v14, v10, (__int16 *)frameData->m128i_i64);
  else
    v15 = hkaPredictiveBlockCompression::decodeAdjacentFrames(v14, v10, (__int16 *)frameData->m128i_i64);
  *v7 = v15;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "StDequantize";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
  retaddr = FLOAT_0_00012208521;
  v20 = 0i64;
  v21 = 4i64;
  v22 = **v74;
  v23 = 0i64;
  v24 = 0i64;
  ++*v74;
  v25 = 4i64;
  do
  {
    if ( v22 & 1 )
    {
      v71.m128_f32[v23] = FLOAT_0_00012208521;
      v70.m128_i32[v23 + 2] = 0;
    }
    else
    {
      v26 = *v8;
      v71.m128_f32[v24] = **v8;
      *v8 = v26 + 1;
      v27 = *v73;
      v70.m128_i32[v24 + 2] = **v73;
      *v73 = v27 + 1;
    }
    v22 >>= 1;
    ++v23;
    ++v24;
    --v25;
  }
  while ( v25 );
  v28 = v71;
  v29 = 0i64;
  v30 = 0i64;
  v31 = 4i64;
  do
  {
    if ( v22 & 1 )
    {
      v71.m128_f32[v29] = FLOAT_0_00012208521;
      v70.m128_i32[v29] = 0;
    }
    else
    {
      v32 = *v8;
      v71.m128_f32[v30] = **v8;
      *v8 = v32 + 1;
      v33 = *v73;
      v70.m128_i32[v30] = **v73;
      *v73 = v33 + 1;
    }
    v22 >>= 1;
    ++v29;
    ++v30;
    --v31;
  }
  while ( v31 );
  v34 = v71;
  v35 = v70;
  v36 = 0i64;
  v37 = 0i64;
  v38 = 4i64;
  do
  {
    if ( v22 & 1 )
    {
      v71.m128_f32[v36] = FLOAT_0_00012208521;
      v70.m128_i32[v36] = 0;
    }
    else
    {
      v39 = *v8;
      v71.m128_f32[v37] = **v8;
      *v8 = v39 + 1;
      v40 = *v73;
      v70.m128_i32[v37] = **v73;
      *v73 = v40 + 1;
    }
    v22 >>= 1;
    ++v36;
    ++v37;
    --v38;
  }
  while ( v38 );
  v41 = v71;
  v42 = v70;
  v43 = 0i64;
  do
  {
    if ( v22 & 1 )
    {
      v70.m128_f32[v20] = FLOAT_0_00012208521;
      v71.m128_i32[v20] = 0;
    }
    else
    {
      v44 = *v8;
      v70.m128_f32[v43] = **v8;
      *v8 = v44 + 1;
      v45 = *v73;
      v71.m128_i32[v43] = **v73;
      *v73 = v45 + 1;
    }
    v22 >>= 1;
    ++v20;
    ++v43;
    --v21;
  }
  while ( v21 );
  v46 = _mm_load_si128(frameData);
  v47 = _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v46, (__m128i)0i64), 0x10u), 0x10u));
  v48 = _mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v46, (__m128i)0i64), 0x10u), 0x10u);
  v49 = _mm_load_si128(frameData + 1);
  v50 = _mm_add_ps(_mm_mul_ps(v47, v34), v35);
  v51 = _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v48), v28), *(__m128 *)((char *)&v70 + 8));
  v52 = _mm_add_ps(
          _mm_mul_ps(
            _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v49, (__m128i)0i64), 0x10u), 0x10u)),
            v41),
          v42);
  v53 = _mm_add_ps(
          _mm_mul_ps(
            _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v49, (__m128i)0i64), 0x10u), 0x10u)),
            v70),
          v71);
  if ( v9 )
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
            *(__m128 *)((char *)&v70 + 8));
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
              v70),
            v71);
    *((__m128 *)offsetPtr + 6) = v58;
    *((__m128 *)offsetPtr + 7) = v59;
    v60 = *(__m128 *)isFixedRange;
    v61 = _mm_mul_ps(*(__m128 *)scratchSpace, v58);
    v62 = _mm_add_ps(_mm_mul_ps(*(__m128 *)scratchSpace, v56), _mm_mul_ps(*(__m128 *)isFixedRange, v51));
    v63 = _mm_mul_ps(*(__m128 *)isFixedRange, v50);
    v64 = _mm_mul_ps(*(__m128 *)scratchSpace, v57);
    v65 = _mm_mul_ps(*(__m128 *)scratchSpace, v59);
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
    v69 = (signed __int64)(v67 + 2);
    *(_DWORD *)(v69 - 8) = v68;
    v66[1] = v69;
  }
}

// File Line: 291
// RVA: 0xB32660
void __fastcall hkaPredictiveCompressedAnimation::getCompressedDataOffset(hkaPredictiveCompressedAnimation *this, unsigned int frame, unsigned int *start, unsigned int *end)
{
  __int64 v4; // r11

  *start = 0;
  v4 = frame / 0xF;
  if ( (_DWORD)v4 )
    *start = *(_DWORD *)&this->m_intData.m_data[2 * ((signed int)v4 - 1) + this->m_intArrayOffsets[0]];
  *end = *(_DWORD *)&this->m_intData.m_data[2 * v4 + this->m_intArrayOffsets[0]];
}

// File Line: 313
// RVA: 0xB2F9E0
void __fastcall hkaPredictiveCompressedAnimation::sampleFullPose(hkaPredictiveCompressedAnimation *this, unsigned int frameIndex, float frameDelta, const char *compressedData, hkQsTransformf *refBones, const float *refFloats, int numBones, int numFloats, hkQsTransformf *bonesOut, float *floatsOut, char *boneWeightsInOut, char *floatWeightsInOut)
{
  hkaPredictiveCompressedAnimation *v12; // r15
  const char *v13; // r12
  unsigned int v14; // ebx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rdx
  signed __int64 v20; // r8
  int v21; // er9
  __int64 v22; // rax
  unsigned int v23; // ebx
  char v24; // al
  __m128 v25; // xmm8
  __m128 *v26; // rax
  __m128 v27; // xmm9
  float *v28; // rcx
  float *v29; // rdi
  __int64 v30; // rax
  signed __int64 v31; // rsi
  __int64 v32; // rax
  signed __int64 v33; // rdx
  unsigned __int16 *v34; // rcx
  __int64 v35; // rax
  signed __int64 v36; // rdx
  __int64 v37; // rax
  hkLifoAllocator *v38; // rax
  unsigned __int64 v39; // rbx
  hkLifoAllocator *v40; // rax
  bool v41; // sf
  unsigned __int8 v42; // of
  _OWORD *v43; // r14
  unsigned __int64 v44; // rcx
  float *v45; // r13
  __int64 v46; // rbx
  unsigned __int16 *v47; // r9
  unsigned __int64 v48; // r10
  signed int v49; // er11
  int v50; // edx
  signed int v51; // eax
  __int64 v52; // r8
  float *v53; // rcx
  char v54; // al
  __int64 v55; // r13
  __int64 v56; // r10
  char *v57; // r14
  int v58; // er11
  int v59; // edx
  signed int v60; // eax
  __int64 v61; // r8
  char *v62; // rcx
  char v63; // al
  int v64; // er13
  unsigned int v65; // ebx
  hkLifoAllocator *v66; // rax
  char *v67; // r15
  int v68; // er12
  char *v69; // rcx
  hkLifoAllocator *v70; // rax
  __m128 *v71; // rbx
  char *v72; // rcx
  __int64 v73; // rdx
  signed __int64 v74; // rax
  _QWORD *v75; // rax
  _QWORD *v76; // rcx
  _QWORD *v77; // r8
  unsigned __int64 v78; // rax
  signed __int64 v79; // rcx
  __int64 v80; // r10
  __int64 v81; // r12
  __int64 v82; // rdx
  __int64 v83; // r8
  __int128 *v84; // rcx
  __int64 v85; // r9
  __int128 v86; // xmm0
  __int128 v87; // xmm1
  __int128 v88; // xmm2
  _QWORD *v89; // r8
  _QWORD *v90; // rcx
  unsigned __int64 v91; // rax
  signed __int64 v92; // rcx
  int v93; // er10
  char *v94; // r11
  int *v95; // rcx
  int v96; // er8
  signed __int64 v97; // rdx
  int v98; // xmm0_4
  __int64 v99; // rax
  int v100; // xmm0_4
  __int64 v101; // rax
  _QWORD *v102; // r8
  _QWORD *v103; // rcx
  unsigned __int64 v104; // rax
  signed __int64 v105; // rcx
  signed __int64 v106; // rbx
  int v107; // er15
  _QWORD *v108; // rax
  unsigned __int64 v109; // rcx
  _QWORD *v110; // r8
  unsigned __int64 v111; // rax
  const char *v112; // rax
  _QWORD *v113; // r8
  _QWORD *v114; // rcx
  unsigned __int64 v115; // rax
  signed __int64 v116; // rcx
  __int64 v117; // r8
  unsigned __int16 v118; // cx
  __int64 v119; // rdx
  signed __int64 v120; // r9
  int v121; // eax
  __m128 v122; // xmm12
  __m128 v123; // xmm13
  __int64 v124; // r8
  __int64 v125; // rdx
  signed __int64 v126; // r9
  int v127; // eax
  __m128 v128; // xmm10
  __m128 v129; // xmm11
  __int64 v130; // r8
  __int64 v131; // rdx
  signed __int64 v132; // r9
  int v133; // eax
  __m128 v134; // xmm6
  __m128 v135; // xmm7
  __int64 v136; // r8
  __int64 v137; // rdx
  signed __int64 v138; // r9
  int v139; // eax
  __m128 v140; // xmm2
  __m128 v141; // xmm3
  __m128i v142; // xmm0
  __m128 v143; // xmm5
  __m128i v144; // xmm0
  __m128i v145; // xmm1
  __m128 v146; // xmm2
  __m128i v147; // xmm1
  __m128 v148; // xmm1
  _QWORD *v149; // r8
  _QWORD *v150; // rcx
  unsigned __int64 v151; // rax
  signed __int64 v152; // rcx
  int v153; // ecx
  int v154; // er9
  __int64 v155; // r8
  signed __int64 v156; // r10
  _DWORD *v157; // rdi
  __int64 v158; // rsi
  _DWORD *v159; // rdx
  int v160; // xmm0_4
  int v161; // xmm1_4
  __int64 v162; // rcx
  int v163; // xmm0_4
  int v164; // xmm1_4
  __int64 v165; // rcx
  _QWORD *v166; // r8
  _QWORD *v167; // rcx
  unsigned __int64 v168; // rax
  signed __int64 v169; // rcx
  int v170; // er11
  int v171; // ecx
  signed int v172; // eax
  signed __int64 v173; // rbx
  int v174; // er9
  unsigned __int16 *v175; // r10
  signed __int64 v176; // r8
  signed __int64 v177; // rdx
  signed __int64 v178; // rcx
  signed __int64 v179; // r9
  __m128 v180; // xmm0
  __m128 v181; // xmm5
  __m128i v182; // xmm15
  __m128i v183; // xmm5
  __m128i v184; // xmm6
  __m128 v185; // xmm3
  __m128 v186; // xmm13
  __m128 v187; // xmm15
  __m128 v188; // xmm2
  __m128 v189; // xmm0
  __m128 v190; // xmm3
  __m128 v191; // xmm0
  __m128 v192; // xmm6
  __m128 v193; // xmm11
  __m128 v194; // xmm13
  __m128 v195; // xmm12
  __m128 v196; // xmm0
  __m128 v197; // xmm15
  __m128 v198; // xmm1
  __m128 v199; // xmm9
  __m128 v200; // xmm1
  __m128 v201; // xmm0
  __m128 v202; // xmm7
  __m128 v203; // xmm1
  __m128 v204; // xmm1
  __m128 v205; // xmm5
  __m128 v206; // xmm0
  __m128 v207; // xmm1
  __m128 v208; // xmm6
  __m128 v209; // xmm1
  __m128 v210; // xmm3
  __m128 v211; // xmm0
  __m128 v212; // xmm1
  __m128 v213; // xmm4
  __m128 v214; // xmm2
  __m128 v215; // xmm0
  __int64 v216; // r9
  __int64 v217; // rdx
  int v218; // ecx
  __int64 v219; // r8
  signed __int64 v220; // rcx
  __m128 v221; // xmm2
  __m128 v222; // xmm3
  __m128 v223; // xmm0
  __m128 v224; // xmm6
  __m128 v225; // xmm0
  __m128 v226; // xmm1
  __m128 v227; // xmm2
  __m128 v228; // xmm3
  signed __int64 v229; // rcx
  __m128 v230; // xmm1
  __m128 v231; // xmm3
  __m128 v232; // xmm0
  __m128 v233; // xmm6
  __m128 v234; // xmm0
  __m128 v235; // xmm1
  __m128 v236; // xmm2
  __m128 v237; // xmm3
  __m128 *v238; // r13
  hkLifoAllocator *v239; // rax
  int v240; // er12
  int v241; // ebx
  __int64 v242; // rbx
  int v243; // er9
  __m128 *v244; // r10
  unsigned __int16 *v245; // r14
  signed __int64 v246; // r8
  signed __int64 v247; // rcx
  signed __int64 v248; // rdx
  signed __int64 v249; // r9
  __m128 v250; // xmm4
  __m128 v251; // xmm8
  __m128 v252; // xmm12
  __m128 v253; // xmm0
  __m128i v254; // xmm4
  __m128i v255; // xmm12
  __m128i v256; // xmm7
  __m128i v257; // xmm3
  __m128 v258; // xmm13
  __m128 v259; // xmm12
  __m128 v260; // xmm0
  __m128 v261; // xmm13
  __m128 v262; // xmm4
  __m128 v263; // xmm11
  __m128 v264; // xmm10
  __m128 v265; // xmm2
  __m128 v266; // xmm1
  __m128 v267; // xmm2
  __m128 v268; // xmm0
  __m128 v269; // xmm7
  __m128 v270; // xmm13
  __m128 v271; // xmm10
  __m128 v272; // xmm0
  __m128 v273; // xmm0
  __m128 v274; // xmm8
  __m128i v275; // xmm15
  __m128i v276; // xmm4
  __m128i v277; // xmm11
  __m128 v278; // xmm3
  __m128 v279; // xmm7
  __m128 v280; // xmm15
  __m128 v281; // xmm7
  __m128 v282; // xmm2
  __m128 v283; // xmm1
  __m128 v284; // xmm2
  __m128 v285; // xmm0
  __m128 v286; // xmm11
  __m128 v287; // xmm6
  __m128 v288; // xmm7
  __m128 v289; // xmm1
  __m128 v290; // xmm5
  __m128 v291; // xmm12
  __m128 v292; // xmm4
  __m128 v293; // xmm0
  __m128 v294; // xmm3
  __m128 v295; // xmm2
  __m128 v296; // xmm5
  __m128 v297; // xmm4
  __m128 v298; // xmm3
  __m128 v299; // xmm2
  __m128 v300; // xmm3
  __m128 v301; // xmm15
  __m128 v302; // xmm0
  __m128 v303; // xmm1
  __m128 v304; // xmm13
  __m128 v305; // xmm1
  __m128 v306; // xmm9
  __m128 v307; // xmm10
  __m128 v308; // xmm0
  __m128 v309; // xmm1
  __m128 v310; // xmm2
  __m128 v311; // xmm1
  __m128 v312; // xmm8
  __m128 v313; // xmm6
  __m128 v314; // xmm7
  __m128 v315; // xmm0
  __m128 v316; // xmm1
  __m128 v317; // xmm2
  __m128 v318; // xmm1
  __m128 v319; // xmm5
  __m128 v320; // xmm4
  __m128 v321; // xmm0
  __m128 v322; // xmm1
  __m128 v323; // xmm2
  __m128 v324; // xmm1
  char *v325; // rdx
  __int64 v326; // r8
  int v327; // ecx
  __int64 v328; // r9
  signed __int64 v329; // rcx
  __m128 v330; // xmm2
  __m128 v331; // xmm2
  __m128 v332; // xmm0
  __m128 v333; // xmm0
  __m128 v334; // xmm2
  __m128 v335; // xmm7
  __m128 v336; // xmm2
  __m128 v337; // xmm0
  __m128 v338; // xmm4
  __m128 v339; // xmm0
  __m128 v340; // xmm1
  __m128 v341; // xmm5
  __m128 v342; // xmm0
  __m128 v343; // xmm1
  __m128 v344; // xmm2
  __m128 v345; // xmm3
  signed __int64 v346; // rcx
  __m128 v347; // xmm2
  __m128 v348; // xmm2
  __m128 v349; // xmm0
  __m128 v350; // xmm1
  __m128 v351; // xmm2
  __m128 v352; // xmm7
  __m128 v353; // xmm2
  __m128 v354; // xmm0
  __m128 v355; // xmm4
  __m128 v356; // xmm0
  __m128 v357; // xmm1
  __m128 v358; // xmm5
  __m128 v359; // xmm0
  __m128 v360; // xmm1
  __m128 v361; // xmm3
  hkLifoAllocator *v362; // r9
  _QWORD *v363; // r8
  _QWORD *v364; // rcx
  unsigned __int64 v365; // rax
  signed __int64 v366; // rcx
  hkQsTransformf *v367; // rcx
  hkQsTransformf *v368; // rbx
  __int64 v369; // rdx
  signed __int64 v370; // r8
  int v371; // eax
  _QWORD *v372; // r8
  _QWORD *v373; // rcx
  unsigned __int64 v374; // rax
  signed __int64 v375; // rcx
  unsigned __int16 *v376; // rdx
  __int64 v377; // rcx
  unsigned __int16 *v378; // r10
  int v379; // eax
  signed int v380; // ecx
  int *v381; // rdx
  __int64 v382; // r8
  int v383; // eax
  __int64 v384; // r9
  int v385; // eax
  _QWORD *v386; // r8
  _QWORD *v387; // rcx
  unsigned __int64 v388; // rax
  signed __int64 v389; // rcx
  __int64 v390; // rcx
  float *v391; // rdx
  int v392; // ecx
  int v393; // er10
  signed int v394; // ecx
  int v395; // er13
  _QWORD *v396; // r8
  unsigned __int64 v397; // rcx
  unsigned __int64 v398; // rax
  const char *v399; // rax
  _QWORD *v400; // r8
  _QWORD *v401; // rcx
  unsigned __int64 v402; // rax
  signed __int64 v403; // rcx
  __int64 v404; // r8
  unsigned __int16 v405; // cx
  __int64 v406; // rdx
  signed __int64 v407; // r9
  int v408; // eax
  __m128 v409; // xmm12
  __m128 v410; // xmm13
  __int64 v411; // r8
  __int64 v412; // rdx
  signed __int64 v413; // r9
  int v414; // eax
  __m128 v415; // xmm10
  __m128 v416; // xmm11
  __int64 v417; // r8
  __int64 v418; // rdx
  signed __int64 v419; // r9
  int v420; // eax
  __m128 v421; // xmm6
  __m128 v422; // xmm7
  __int64 v423; // r8
  __int64 v424; // rdx
  signed __int64 v425; // r9
  int v426; // eax
  __m128 v427; // xmm2
  __m128 v428; // xmm3
  __m128i v429; // xmm0
  __m128 v430; // xmm5
  __m128i v431; // xmm0
  __m128i v432; // xmm1
  __m128 v433; // xmm2
  __m128i v434; // xmm1
  __m128 v435; // xmm1
  _QWORD *v436; // rax
  _QWORD *v437; // rcx
  _QWORD *v438; // r8
  unsigned __int64 v439; // rax
  signed __int64 v440; // rcx
  signed __int64 v441; // r8
  __int64 v442; // r15
  int v443; // ecx
  int v444; // er9
  signed __int64 v445; // rdx
  int v446; // eax
  signed __int64 v447; // rax
  __int64 v448; // rbx
  int v449; // er15
  _QWORD *v450; // r8
  unsigned __int64 v451; // rcx
  unsigned __int64 v452; // rax
  const char *v453; // rax
  _QWORD *v454; // r8
  _QWORD *v455; // rcx
  unsigned __int64 v456; // rax
  signed __int64 v457; // rcx
  __int64 v458; // r8
  unsigned __int16 v459; // cx
  __int64 v460; // rdx
  signed __int64 v461; // r9
  int v462; // eax
  __m128 v463; // xmm12
  __m128 v464; // xmm13
  __int64 v465; // r8
  __int64 v466; // rdx
  signed __int64 v467; // r9
  int v468; // eax
  __m128 v469; // xmm10
  __m128 v470; // xmm11
  __int64 v471; // r8
  __int64 v472; // rdx
  signed __int64 v473; // r9
  int v474; // eax
  __m128 v475; // xmm6
  __m128 v476; // xmm7
  __int64 v477; // r8
  __int64 v478; // rdx
  signed __int64 v479; // r9
  int v480; // eax
  __m128 v481; // xmm2
  __m128 v482; // xmm3
  __m128i v483; // xmm0
  __m128 v484; // xmm5
  __m128i v485; // xmm0
  __m128i v486; // xmm1
  __m128 v487; // xmm2
  __m128i v488; // xmm1
  __m128 v489; // xmm1
  _QWORD *v490; // r8
  _QWORD *v491; // rcx
  unsigned __int64 v492; // rax
  signed __int64 v493; // rcx
  int v494; // ecx
  hkQsTransformf *v495; // r9
  __int64 v496; // r8
  __int64 v497; // r10
  int *v498; // rdx
  int v499; // eax
  hkLifoAllocator *v500; // rax
  hkLifoAllocator *v501; // r9
  _QWORD *v502; // r8
  _QWORD *v503; // rcx
  unsigned __int64 v504; // rax
  signed __int64 v505; // rcx
  char v506; // [rsp+20h] [rbp-D8h]
  __m128 *p; // [rsp+28h] [rbp-D0h]
  __m128i *frameData; // [rsp+30h] [rbp-C8h]
  __m128 v509; // [rsp+40h] [rbp-B8h]
  __m128 v510; // [rsp+50h] [rbp-A8h]
  void *v511; // [rsp+60h] [rbp-98h]
  unsigned __int16 *v512; // [rsp+68h] [rbp-90h]
  unsigned __int16 *v513; // [rsp+70h] [rbp-88h]
  float *v514; // [rsp+78h] [rbp-80h]
  int *v515; // [rsp+80h] [rbp-78h]
  _OWORD *v516; // [rsp+88h] [rbp-70h]
  __m128 v517; // [rsp+98h] [rbp-60h]
  __m128 v518; // [rsp+A8h] [rbp-50h]
  __int64 v519; // [rsp+B8h] [rbp-40h]
  __m128 v520; // [rsp+C8h] [rbp-30h]
  __m128 v521; // [rsp+D8h] [rbp-20h]
  __m128 v522; // [rsp+E8h] [rbp-10h]
  __m128 v523; // [rsp+F8h] [rbp+0h]
  const char *v524; // [rsp+108h] [rbp+10h]
  __m128 v525; // [rsp+118h] [rbp+20h]
  __m128 v526; // [rsp+128h] [rbp+30h]
  __m128 v527; // [rsp+138h] [rbp+40h]
  __m128 v528; // [rsp+148h] [rbp+50h]
  __m128 v529; // [rsp+158h] [rbp+60h]
  __m128 v530; // [rsp+168h] [rbp+70h]
  __m128 v531; // [rsp+178h] [rbp+80h]
  __m128 v532; // [rsp+188h] [rbp+90h]
  const char *v533; // [rsp+198h] [rbp+A0h]
  __m128 v534; // [rsp+1A8h] [rbp+B0h]
  __m128 v535; // [rsp+1B8h] [rbp+C0h]
  __m128 v536; // [rsp+1C8h] [rbp+D0h]
  __m128 v537; // [rsp+1D8h] [rbp+E0h]
  __m128 v538; // [rsp+1E8h] [rbp+F0h]
  __m128 v539; // [rsp+1F8h] [rbp+100h]
  __m128 v540; // [rsp+208h] [rbp+110h]
  __m128 v541; // [rsp+218h] [rbp+120h]
  __m128 v542; // [rsp+228h] [rbp+130h]
  __m128 v543; // [rsp+238h] [rbp+140h]
  __m128 v544; // [rsp+248h] [rbp+150h]
  __m128 v545; // [rsp+258h] [rbp+160h]
  __m128 v546; // [rsp+268h] [rbp+170h]
  __m128 v547; // [rsp+278h] [rbp+180h]
  __m128 v548; // [rsp+288h] [rbp+190h]
  __m128 v549; // [rsp+298h] [rbp+1A0h]
  __m128 v550; // [rsp+2A8h] [rbp+1B0h]
  __m128 v551; // [rsp+2B8h] [rbp+1C0h]
  __m128 v552; // [rsp+2C8h] [rbp+1D0h]
  __m128 v553; // [rsp+2D8h] [rbp+1E0h]
  __m128 v554; // [rsp+2E8h] [rbp+1F0h]
  __m128 v555; // [rsp+2F8h] [rbp+200h]
  __m128 v556; // [rsp+308h] [rbp+210h]
  __m128 v557; // [rsp+318h] [rbp+220h]
  __m128 v558; // [rsp+328h] [rbp+230h]
  __m128 v559; // [rsp+338h] [rbp+240h]
  __m128 v560; // [rsp+348h] [rbp+250h]
  __m128 v561; // [rsp+358h] [rbp+260h]
  __m128 v562; // [rsp+368h] [rbp+270h]
  __m128 v563; // [rsp+378h] [rbp+280h]
  __m128 v564; // [rsp+388h] [rbp+290h]
  __m128 v565; // [rsp+398h] [rbp+2A0h]
  __m128 v566; // [rsp+3A8h] [rbp+2B0h]
  __m128 v567; // [rsp+3B8h] [rbp+2C0h]
  __m128 v568; // [rsp+3C8h] [rbp+2D0h]
  __m128 v569; // [rsp+3D8h] [rbp+2E0h]
  __m128 v570; // [rsp+3E8h] [rbp+2F0h]
  __m128 v571; // [rsp+3F8h] [rbp+300h]
  __m128 v572; // [rsp+408h] [rbp+310h]
  __m128 v573; // [rsp+418h] [rbp+320h]
  __m128 v574; // [rsp+428h] [rbp+330h]
  __m128 v575; // [rsp+438h] [rbp+340h]
  __m128 v576; // [rsp+448h] [rbp+350h]
  __m128 v577; // [rsp+458h] [rbp+360h]
  __m128 v578; // [rsp+468h] [rbp+370h]
  __m128 v579; // [rsp+478h] [rbp+380h]
  __m128 v580; // [rsp+488h] [rbp+390h]
  __m128 v581; // [rsp+498h] [rbp+3A0h]
  __m128 v582; // [rsp+4A8h] [rbp+3B0h]
  __m128 v583; // [rsp+4B8h] [rbp+3C0h]
  __m128 v584; // [rsp+4C8h] [rbp+3D0h]
  __m128 v585; // [rsp+4D8h] [rbp+3E0h]
  __m128 v586; // [rsp+4E8h] [rbp+3F0h]
  __m128 v587; // [rsp+4F8h] [rbp+400h]
  __int128 v588; // [rsp+508h] [rbp+410h]
  __m128 v589; // [rsp+518h] [rbp+420h]
  __m128 v590; // [rsp+528h] [rbp+430h]
  __int128 v591; // [rsp+538h] [rbp+440h]
  __m128 v592; // [rsp+548h] [rbp+450h]
  __m128 v593; // [rsp+558h] [rbp+460h]
  __m128 v594; // [rsp+568h] [rbp+470h]
  __m128 v595; // [rsp+578h] [rbp+480h]
  __int128 v596; // [rsp+588h] [rbp+490h]
  __m128 v597; // [rsp+598h] [rbp+4A0h]
  __int128 v598; // [rsp+5A8h] [rbp+4B0h]
  __m128 v599; // [rsp+5B8h] [rbp+4C0h]
  __int128 v600; // [rsp+5C8h] [rbp+4D0h]
  __m128 v601; // [rsp+5D8h] [rbp+4E0h]
  __int128 v602; // [rsp+5E8h] [rbp+4F0h]
  __int128 v603; // [rsp+5F8h] [rbp+500h]
  __m128 v604; // [rsp+608h] [rbp+510h]
  __m128 v605; // [rsp+618h] [rbp+520h]
  __int128 v606; // [rsp+628h] [rbp+530h]
  __m128 v607; // [rsp+638h] [rbp+540h]
  __int128 v608; // [rsp+648h] [rbp+550h]
  __m128 v609; // [rsp+658h] [rbp+560h]
  __int128 v610; // [rsp+668h] [rbp+570h]
  __int128 v611; // [rsp+678h] [rbp+580h]
  __int128 v612; // [rsp+688h] [rbp+590h]
  __m128 v613; // [rsp+698h] [rbp+5A0h]
  __m128 v614; // [rsp+6A8h] [rbp+5B0h]
  signed __int64 retaddr; // [rsp+7A8h] [rbp+6B0h]
  hkaPredictiveCompressedAnimation *start; // [rsp+7B0h] [rbp+6B8h]
  unsigned int v617; // [rsp+7B8h] [rbp+6C0h]
  const char *end; // [rsp+7C0h] [rbp+6C8h]
  const char *v619; // [rsp+7C8h] [rbp+6D0h]

  v619 = compressedData;
  *(float *)&end = frameDelta;
  start = this;
  v12 = this;
  v13 = compressedData;
  v14 = frameIndex;
  v15 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v16 = v15[1];
  if ( v16 < v15[3] )
  {
    *(_QWORD *)v16 = "LtPredictiveSample";
    *(_QWORD *)(v16 + 16) = "StSetup";
    v17 = __rdtsc();
    *(_DWORD *)(v16 + 8) = v17;
    v15[1] = v16 + 24;
  }
  if ( !v13 )
  {
    hkaPredictiveCompressedAnimation::getCompressedDataOffset(v12, v14, (unsigned int *)&start, (unsigned int *)&end);
    v13 = &v12->m_compressedData.m_data[(unsigned int)start];
    end = &v12->m_compressedData.m_data[(unsigned int)start];
  }
  v18 = v12->m_intArrayOffsets[1];
  v524 = v13;
  v19 = v14 / 0xF;
  v20 = (signed __int64)&v12->m_intData.m_data[v18];
  v21 = *(unsigned __int16 *)(v20 + 4 * v19 + 2);
  v22 = *(unsigned __int16 *)(v20 + 4 * v19);
  v23 = v14 % 0xF;
  LODWORD(start) = v23;
  v533 = &v13[v22 | (unsigned int)(v21 << 16)];
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
  v506 = v24;
  v25 = _mm_shuffle_ps((__m128)v617, (__m128)v617, 0);
  v530 = v25;
  if ( v24 )
  {
    v585 = query.m_quad;
    v26 = &v585;
  }
  else
  {
    v26 = &v549;
    v549 = _mm_sub_ps(query.m_quad, v25);
  }
  v27 = *v26;
  v28 = v12->m_floatData.m_data;
  v29 = &v28[v12->m_floatArrayOffsets[1]];
  v30 = v12->m_floatArrayOffsets[2];
  v526 = v27;
  v31 = (signed __int64)&v28[v30];
  v32 = v12->m_floatArrayOffsets[0];
  v514 = v29;
  v33 = (signed __int64)&v28[v32];
  v34 = v12->m_intData.m_data;
  v35 = v12->m_intArrayOffsets[2];
  v515 = (int *)v33;
  v36 = (signed __int64)&v34[v35];
  v37 = v12->m_intArrayOffsets[3];
  v512 = (unsigned __int16 *)v36;
  v514 = (float *)v31;
  v513 = &v34[v37];
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  frameData = (__m128i *)v38->m_cur;
  v39 = (unsigned __int64)&frameData[8];
  if ( v38->m_slabSize < 128 || (void *)v39 > v38->m_end )
    frameData = (__m128i *)hkLifoAllocator::allocateFromNewSlab(v38, 128);
  else
    v38->m_cur = (void *)v39;
  v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v42 = __OFSUB__(v40->m_slabSize, 256);
  v41 = v40->m_slabSize - 256 < 0;
  v43 = v40->m_cur;
  v44 = (unsigned __int64)(v43 + 16);
  v516 = v40->m_cur;
  if ( v41 ^ v42 || (void *)v44 > v40->m_end )
  {
    v43 = hkLifoAllocator::allocateFromNewSlab(v40, 256);
    v516 = v43;
  }
  else
  {
    v40->m_cur = (void *)v44;
  }
  v45 = floatsOut;
  v46 = (signed int)refFloats;
  v47 = v512;
  if ( floatsOut )
  {
    v48 = 0i64;
    if ( (signed int)refFloats > 0i64 )
    {
      v49 = (signed int)refFloats;
      do
      {
        v50 = *v47;
        v51 = 16;
        ++v47;
        if ( v49 < 16 )
          v51 = v49;
        v52 = v51;
        if ( v51 > 0 )
        {
          v53 = &v45[v48];
          do
          {
            v54 = v50;
            v50 >>= 1;
            v53 = (float *)((char *)v53 + 1);
            *((_BYTE *)v53 - 1) &= -(v54 & 1);
            --v52;
          }
          while ( v52 );
        }
        v48 += 4i64;
        v49 -= 16;
      }
      while ( (signed __int64)(v48 * 4) < v46 );
      v29 = v514;
    }
  }
  v55 = numBones;
  if ( boneWeightsInOut )
  {
    v56 = 0i64;
    if ( numBones > 0 )
    {
      v57 = boneWeightsInOut;
      v58 = numBones;
      do
      {
        v59 = *v47;
        v60 = 16;
        ++v47;
        if ( v58 < 16 )
          v60 = v58;
        v61 = v60;
        if ( v60 > 0 )
        {
          v62 = &v57[v56];
          do
          {
            v63 = v59;
            v59 >>= 1;
            ++v62;
            *(v62 - 1) &= -(v63 & 1);
            --v61;
          }
          while ( v61 );
        }
        v56 += 16i64;
        v58 -= 16;
      }
      while ( v56 < v55 );
      v31 = (signed __int64)v514;
      v43 = v516;
    }
  }
  if ( (signed int)refFloats > 0 )
  {
    v64 = 12 * (_DWORD)refFloats;
    v65 = ((_DWORD)refFloats + 3) & 0xFFFFFFFC;
    v66 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v67 = (char *)v66->m_cur;
    v511 = v67;
    v68 = (48 * v65 + 127) & 0xFFFFFF80;
    LODWORD(floatsOut) = (48 * v65 + 127) & 0xFFFFFF80;
    v69 = &v67[v68];
    if ( v68 > v66->m_slabSize || v69 > v66->m_end )
    {
      v67 = (char *)hkLifoAllocator::allocateFromNewSlab(v66, v68);
      v511 = v67;
    }
    else
    {
      v66->m_cur = v69;
    }
    v70 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v71 = (__m128 *)v70->m_cur;
    v72 = (char *)v71 + v68;
    p = (__m128 *)v70->m_cur;
    if ( v68 > v70->m_slabSize || v72 > v70->m_end )
    {
      v71 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v70, v68);
      p = v71;
    }
    else
    {
      v70->m_cur = v72;
    }
    v73 = *(_QWORD *)(retaddr + 72);
    v519 = v73 + 2i64 * *(signed int *)(retaddr + 104);
    v74 = v73 + 2i64 * *(signed int *)(retaddr + 120);
    boneWeightsInOut = (char *)(v73 + 2i64 * *(signed int *)(retaddr + 112));
    v512 = (unsigned __int16 *)v74;
    v75 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v76 = (_QWORD *)v75[1];
    v77 = v75;
    if ( (unsigned __int64)v76 < v75[3] )
    {
      *v76 = "StCopyReferencePose";
      v78 = __rdtsc();
      v79 = (signed __int64)(v76 + 2);
      *(_DWORD *)(v79 - 8) = v78;
      v77[1] = v79;
    }
    v80 = (signed int)refFloats;
    v81 = *(_QWORD *)&numFloats;
    if ( (signed int)refFloats > 0i64 )
    {
      v82 = *(_QWORD *)&numFloats - (_QWORD)v619;
      v83 = v67 - v619;
      v84 = (__int128 *)(v619 + 32);
      v85 = (char *)v71 - v619;
      do
      {
        v86 = *(v84 - 2);
        v87 = *(v84 - 1);
        v88 = *v84;
        v84 += 3;
        *(__int128 *)((char *)v84 + v82 - 80) = v86;
        *(__int128 *)((char *)v84 + v82 - 64) = v87;
        *(__int128 *)((char *)v84 + v82 - 48) = v88;
        *(__int128 *)((char *)v84 + v83 - 80) = v86;
        *(__int128 *)((char *)v84 + v83 - 64) = v87;
        *(__int128 *)((char *)v84 + v83 - 48) = v88;
        *(__int128 *)((char *)v84 + v85 - 80) = v86;
        *(__int128 *)((char *)v84 + v85 - 64) = v87;
        *(__int128 *)((char *)v84 + v85 - 48) = v88;
        --v80;
      }
      while ( v80 );
    }
    v89 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v90 = (_QWORD *)v89[1];
    if ( (unsigned __int64)v90 < v89[3] )
    {
      *v90 = "StCopyStaticTracks";
      v91 = __rdtsc();
      v92 = (signed __int64)(v90 + 2);
      *(_DWORD *)(v92 - 8) = v91;
      v89[1] = v92;
    }
    v93 = *(_DWORD *)(retaddr + 116) - *(_DWORD *)(retaddr + 112);
    if ( v93 > 0 )
    {
      v94 = boneWeightsInOut;
      v95 = v515;
      v96 = *(unsigned __int16 *)boneWeightsInOut;
      v97 = 0i64;
      if ( v93 - 1 <= 0 )
      {
LABEL_61:
        if ( v96 < v64 )
        {
          v100 = *v95;
          v101 = v96;
          *(_DWORD *)(v81 + 4 * v101) = *v95;
          *(_DWORD *)&v67[4 * v101] = v100;
          *((_DWORD *)v71->m128_u64 + v101) = v100;
        }
      }
      else
      {
        while ( v96 < v64 )
        {
          v98 = *v95;
          v99 = v96;
          ++v97;
          *(_DWORD *)(v81 + 4 * v99) = *v95;
          *(_DWORD *)&v67[4 * v99] = v98;
          ++v95;
          *((_DWORD *)v71->m128_u64 + v99) = v98;
          v96 = *(unsigned __int16 *)&v94[2 * v97];
          if ( v97 >= v93 - 1 )
            goto LABEL_61;
        }
      }
      v515 += v93;
    }
    v102 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v103 = (_QWORD *)v102[1];
    if ( (unsigned __int64)v103 < v102[3] )
    {
      *v103 = "StCopyDynamicTracks";
      v104 = __rdtsc();
      v105 = (signed __int64)(v103 + 2);
      *(_DWORD *)(v105 - 8) = v104;
      v102[1] = v105;
    }
    v12 = (hkaPredictiveCompressedAnimation *)retaddr;
    v106 = 0i64;
    LODWORD(refFloats) = 0;
    LODWORD(boneWeightsInOut) = *(_DWORD *)(retaddr + 108) - *(_DWORD *)(retaddr + 104);
    v522.m128_u64[0] = (signed int)boneWeightsInOut;
    if ( (signed int)boneWeightsInOut > 0 )
    {
      do
      {
        v107 = *(unsigned __int16 *)(v519 + 2 * v106);
        if ( v107 >= v64 )
          break;
        v524 = end;
        v108 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v109 = v108[1];
        v110 = v108;
        if ( v109 < v108[3] )
        {
          *(_QWORD *)v109 = "LtloadDynamic";
          *(_QWORD *)(v109 + 16) = "StDecompress";
          v111 = __rdtsc();
          *(_DWORD *)(v109 + 8) = v111;
          v110[1] = v109 + 24;
        }
        if ( v506 )
          v112 = hkaPredictiveBlockCompression::decodeSingleFrame(end, (int)start, (__int16 *)frameData->m128i_i64);
        else
          v112 = hkaPredictiveBlockCompression::decodeAdjacentFrames(end, (int)start, (__int16 *)frameData->m128i_i64);
        end = v112;
        v113 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v114 = (_QWORD *)v113[1];
        if ( (unsigned __int64)v114 < v113[3] )
        {
          *v114 = "StDequantize";
          v115 = __rdtsc();
          v116 = (signed __int64)(v114 + 2);
          *(_DWORD *)(v116 - 8) = v115;
          v113[1] = v116;
        }
        v117 = 0i64;
        v617 = 956302336;
        v118 = *v513;
        v119 = 0i64;
        ++v513;
        v120 = 4i64;
        do
        {
          if ( v118 & 1 )
          {
            v521.m128_i32[v117] = 956302336;
            v525.m128_i32[v117] = 0;
          }
          else
          {
            v121 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v521.m128_i32[v119] = v121;
            v525.m128_i32[v119] = *(_DWORD *)(v31 - 4);
          }
          v118 >>= 1;
          ++v117;
          ++v119;
          --v120;
        }
        while ( v120 );
        v122 = v521;
        v123 = v525;
        v124 = 0i64;
        v125 = 0i64;
        v126 = 4i64;
        v575 = v521;
        v551 = v525;
        do
        {
          if ( v118 & 1 )
          {
            v523.m128_i32[v124] = 956302336;
            v520.m128_i32[v124] = 0;
          }
          else
          {
            v127 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v523.m128_i32[v125] = v127;
            v520.m128_i32[v125] = *(_DWORD *)(v31 - 4);
          }
          v118 >>= 1;
          ++v124;
          ++v125;
          --v126;
        }
        while ( v126 );
        v128 = v523;
        v129 = v520;
        v130 = 0i64;
        v131 = 0i64;
        v132 = 4i64;
        v577 = v523;
        v553 = v520;
        do
        {
          if ( v118 & 1 )
          {
            v517.m128_i32[v130] = 956302336;
            v518.m128_i32[v130] = 0;
          }
          else
          {
            v133 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v517.m128_i32[v131] = v133;
            v518.m128_i32[v131] = *(_DWORD *)(v31 - 4);
          }
          v118 >>= 1;
          ++v130;
          ++v131;
          --v132;
        }
        while ( v132 );
        v134 = v517;
        v135 = v518;
        v136 = 0i64;
        v137 = 0i64;
        v138 = 4i64;
        v579 = v517;
        v555 = v518;
        do
        {
          if ( v118 & 1 )
          {
            v510.m128_i32[v136] = 956302336;
            v509.m128_i32[v136] = 0;
          }
          else
          {
            v139 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v510.m128_i32[v137] = v139;
            v509.m128_i32[v137] = *(_DWORD *)(v31 - 4);
          }
          v118 >>= 1;
          ++v136;
          ++v137;
          --v138;
        }
        while ( v138 );
        v140 = v510;
        v141 = v509;
        v514 = v29;
        v581 = v510;
        v557 = v509;
        v142 = _mm_load_si128(frameData);
        _mm_store_si128((__m128i *)&v588, v142);
        v143 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v142, (__m128i)0i64), 0x10u), 0x10u)),
                   v122),
                 v123);
        v534 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v142, (__m128i)0i64), 0x10u), 0x10u)),
                   v128),
                 v129);
        v583 = v143;
        v144 = _mm_load_si128(frameData + 1);
        _mm_store_si128((__m128i *)&v611, v144);
        v532 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v144, (__m128i)0i64), 0x10u), 0x10u)),
                   v134),
                 v135);
        v536 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v144, (__m128i)0i64), 0x10u), 0x10u)),
                   v140),
                 v141);
        if ( v506 )
        {
          v43[8] = v143;
          v43[9] = v534;
          v43[10] = v532;
          v148 = v536;
        }
        else
        {
          *v43 = v143;
          v43[1] = v534;
          v43[2] = v532;
          v43[3] = v536;
          v145 = _mm_load_si128(frameData + 2);
          _mm_store_si128((__m128i *)&v591, v145);
          v146 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v145, (__m128i)0i64), 0x10u), 0x10u)),
                     v575),
                   v551);
          v538 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v145, (__m128i)0i64), 0x10u), 0x10u)),
                     v577),
                   v553);
          v559 = v146;
          v147 = _mm_load_si128(frameData + 3);
          _mm_store_si128((__m128i *)&v603, v147);
          v543 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v147, (__m128i)0i64), 0x10u), 0x10u)),
                     v579),
                   v555);
          v541 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v147, (__m128i)0i64), 0x10u), 0x10u)),
                     v581),
                   v557);
          v43[4] = v146;
          v43[5] = v538;
          v43[6] = v543;
          v43[7] = v541;
          v593 = _mm_add_ps(_mm_mul_ps(v27, v583), _mm_mul_ps(v559, v25));
          v547 = _mm_add_ps(_mm_mul_ps(v27, v534), _mm_mul_ps(v538, v25));
          v561 = _mm_add_ps(_mm_mul_ps(v27, v532), _mm_mul_ps(v543, v25));
          v587 = _mm_add_ps(_mm_mul_ps(v27, v536), _mm_mul_ps(v541, v25));
          v43[8] = v593;
          v43[9] = v547;
          v43[10] = v561;
          v148 = v587;
        }
        v43[11] = v148;
        v149 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v150 = (_QWORD *)v149[1];
        if ( (unsigned __int64)v150 < v149[3] )
        {
          *v150 = "lt";
          v151 = __rdtsc();
          v152 = (signed __int64)(v150 + 2);
          *(_DWORD *)(v152 - 8) = v151;
          v149[1] = v152;
        }
        v153 = (signed int)boneWeightsInOut;
        v154 = (signed int)refFloats;
        v155 = 0i64;
        if ( (signed int)refFloats + 16 < (signed int)boneWeightsInOut )
          v153 = (_DWORD)refFloats + 16;
        v156 = v153 - 1;
        if ( v106 < v156 )
        {
          v157 = v511;
          v158 = v519;
          v159 = v43 + 8;
          do
          {
            if ( (unsigned __int16)v107 >= v64 )
              break;
            v160 = *(v159 - 32);
            v161 = *(v159 - 16);
            v162 = (unsigned __int16)v107;
            ++v106;
            ++v154;
            *(_DWORD *)(v81 + 4 * v162) = *v159;
            ++v155;
            ++v159;
            v157[v162] = v160;
            *((_DWORD *)p->m128_u64 + v162) = v161;
            LOWORD(v107) = *(_WORD *)(v158 + 2 * v106);
          }
          while ( v106 < v156 );
          v29 = v514;
          v31 = (signed __int64)v514;
          v43 = v516;
          LODWORD(refFloats) = v154;
        }
        if ( (unsigned __int16)v107 < v64 )
        {
          v163 = *((_DWORD *)v43 + v155);
          v164 = *((_DWORD *)v43 + v155 + 16);
          v165 = (unsigned __int16)v107;
          ++v106;
          *(_DWORD *)(v81 + 4 * v165) = *((_DWORD *)v43 + v155 + 32);
          LODWORD(refFloats) = v154 + 1;
          *((_DWORD *)v511 + v165) = v163;
          *((_DWORD *)p->m128_u64 + v165) = v164;
        }
      }
      while ( v106 < (signed __int64)v522.m128_u64[0] );
      v12 = (hkaPredictiveCompressedAnimation *)retaddr;
    }
    v166 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v167 = (_QWORD *)v166[1];
    if ( (unsigned __int64)v167 < v166[3] )
    {
      *v167 = "StInterpolateQuaternions";
      v168 = __rdtsc();
      v169 = (signed __int64)(v167 + 2);
      *(_DWORD *)(v169 - 8) = v168;
      v166[1] = v169;
    }
    v170 = v12->m_intData.m_size - v12->m_intArrayOffsets[8] - 8;
    if ( v170 <= 0 )
    {
      v238 = p;
    }
    else
    {
      v171 = 0;
      LODWORD(refFloats) = 0;
      v172 = (v170 & 0xFFFFFFFC) - 4;
      if ( v506 )
      {
        if ( v172 > 0 )
        {
          v173 = 0i64;
          v174 = v512[3];
          retaddr = v172;
          if ( v172 > 0i64 )
          {
            v175 = v512 + 2;
            do
            {
              if ( v174 >= v64 )
                break;
              v176 = 6i64 * *(v175 - 2);
              v177 = 6i64 * *v175;
              v178 = 6i64 * *(v175 - 1);
              v179 = 6i64 * v174;
              v180 = _mm_shuffle_ps(*(__m128 *)(v81 + 48i64 * *v175 + 16), *(__m128 *)(v81 + 8 * v179 + 16), 68);
              v181 = _mm_shuffle_ps(
                       *(__m128 *)(v81 + 48i64 * *(v175 - 2) + 16),
                       *(__m128 *)(v81 + 48i64 * *(v175 - 1) + 16),
                       68);
              v182 = (__m128i)_mm_shuffle_ps(v181, v180, 136);
              v183 = (__m128i)_mm_shuffle_ps(v181, v180, 221);
              v184 = (__m128i)_mm_shuffle_ps(
                                _mm_shuffle_ps(
                                  *(__m128 *)(v81 + 48i64 * *(v175 - 2) + 16),
                                  *(__m128 *)(v81 + 48i64 * *(v175 - 1) + 16),
                                  238),
                                _mm_shuffle_ps(
                                  *(__m128 *)(v81 + 48i64 * *v175 + 16),
                                  *(__m128 *)(v81 + 8 * v179 + 16),
                                  238),
                                136);
              v185 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v182, 1u), 1u);
              v186 = _mm_shuffle_ps((__m128)v182, (__m128)v183, 68);
              v187 = _mm_shuffle_ps((__m128)v182, (__m128)v183, 238);
              v188 = _mm_sub_ps(
                       query.m_quad,
                       _mm_add_ps(
                         _mm_add_ps(v185, (__m128)_mm_srli_epi32(_mm_slli_epi32(v183, 1u), 1u)),
                         (__m128)_mm_srli_epi32(_mm_slli_epi32(v184, 1u), 1u)));
              v189 = _mm_cmpltps(v188, query.m_quad);
              v190 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v189, query.m_quad), _mm_and_ps(v188, v189)));
              v191 = _mm_shuffle_ps((__m128)v184, v190, 68);
              v192 = _mm_shuffle_ps((__m128)v184, v190, 238);
              v193 = _mm_shuffle_ps(v186, v191, 136);
              v194 = _mm_shuffle_ps(v186, v191, 221);
              v195 = _mm_shuffle_ps(v187, v192, 136);
              v196 = _mm_mul_ps(v193, v193);
              v197 = _mm_shuffle_ps(v187, v192, 221);
              v198 = _mm_add_ps(_mm_shuffle_ps(v196, v196, 78), v196);
              v199 = _mm_add_ps(_mm_shuffle_ps(v198, v198, 177), v198);
              v200 = _mm_rsqrt_ps(v199);
              v609 = v199;
              v201 = _mm_mul_ps(v194, v194);
              v202 = _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v200, v199), v200)),
                       _mm_mul_ps(v200, *(__m128 *)_xmm));
              v175 += 4;
              v203 = _mm_add_ps(_mm_shuffle_ps(v201, v201, 78), v201);
              v173 += 4i64;
              v595 = _mm_add_ps(_mm_shuffle_ps(v203, v203, 177), v203);
              v204 = _mm_rsqrt_ps(v595);
              v205 = _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v204, v595), v204)),
                       _mm_mul_ps(v204, *(__m128 *)_xmm));
              v206 = _mm_mul_ps(v195, v195);
              v207 = _mm_add_ps(_mm_shuffle_ps(v206, v206, 78), v206);
              v208 = _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v595, (__m128)0i64), v205), v194);
              v605 = _mm_add_ps(_mm_shuffle_ps(v207, v207, 177), v207);
              v209 = _mm_rsqrt_ps(v605);
              v210 = _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v209, v605), v209)),
                       _mm_mul_ps(v209, *(__m128 *)_xmm));
              v211 = _mm_mul_ps(v197, v197);
              v212 = _mm_add_ps(_mm_shuffle_ps(v211, v211, 78), v211);
              v213 = _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v605, (__m128)0i64), v210), v195);
              v214 = _mm_add_ps(_mm_shuffle_ps(v212, v212, 177), v212);
              v597 = v214;
              v215 = _mm_rsqrt_ps(v214);
              *(__m128 *)(v81 + 8 * v176 + 16) = _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v199, (__m128)0i64), v202), v193);
              *(__m128 *)(v81 + 8 * v178 + 16) = v208;
              *(__m128 *)(v81 + 8 * v177 + 16) = v213;
              v171 = (_DWORD)refFloats + 4;
              LODWORD(refFloats) = (_DWORD)refFloats + 4;
              *(__m128 *)(v81 + 8 * v179 + 16) = _mm_mul_ps(
                                                   _mm_andnot_ps(
                                                     _mm_cmpleps(v214, (__m128)0i64),
                                                     _mm_mul_ps(
                                                       _mm_sub_ps(
                                                         (__m128)_xmm,
                                                         _mm_mul_ps(_mm_mul_ps(v214, v215), v215)),
                                                       _mm_mul_ps(*(__m128 *)_xmm, v215))),
                                                   v197);
              v174 = v175[1];
            }
            while ( v173 < retaddr );
            v25 = v530;
            v27 = v526;
          }
        }
        v216 = (__int64)v512;
        v217 = v171;
        v218 = v512[v171];
        v219 = v170 - 1;
        if ( v217 >= v219 )
        {
LABEL_124:
          if ( v218 < v64 )
          {
            v229 = 6i64 * v218;
            v230 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)(v81 + 8 * v229 + 16), 1u), 1u);
            v231 = _mm_sub_ps(
                     query.m_quad,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v230, v230, 85), _mm_shuffle_ps(v230, v230, 0)),
                       _mm_shuffle_ps(v230, v230, 170)));
            v232 = _mm_cmpltps(v231, query.m_quad);
            v233 = _mm_shuffle_ps(
                     *(__m128 *)(v81 + 8 * v229 + 16),
                     _mm_unpackhi_ps(
                       *(__m128 *)(v81 + 8 * v229 + 16),
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v231, v232), _mm_andnot_ps(v232, query.m_quad)))),
                     196);
            v234 = _mm_mul_ps(v233, v233);
            v235 = _mm_add_ps(_mm_shuffle_ps(v234, v234, 78), v234);
            v236 = _mm_add_ps(_mm_shuffle_ps(v235, v235, 177), v235);
            v237 = _mm_rsqrt_ps(v236);
            v599 = v236;
            *(__m128 *)(v81 + 8 * v229 + 16) = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmpleps(v236, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v237, v236), v237)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v237))),
                                                 v233);
          }
        }
        else
        {
          while ( v218 < v64 )
          {
            ++v217;
            v220 = 6i64 * v218;
            v221 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)(v81 + 8 * v220 + 16), 1u), 1u);
            v222 = _mm_sub_ps(
                     query.m_quad,
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v221, v221, 0), _mm_shuffle_ps(v221, v221, 85)),
                       _mm_shuffle_ps(v221, v221, 170)));
            v223 = _mm_cmpltps(v222, query.m_quad);
            v224 = _mm_shuffle_ps(
                     *(__m128 *)(v81 + 8 * v220 + 16),
                     _mm_unpackhi_ps(
                       *(__m128 *)(v81 + 8 * v220 + 16),
                       _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v223, query.m_quad), _mm_and_ps(v222, v223)))),
                     196);
            v225 = _mm_mul_ps(v224, v224);
            v226 = _mm_add_ps(_mm_shuffle_ps(v225, v225, 78), v225);
            v227 = _mm_add_ps(_mm_shuffle_ps(v226, v226, 177), v226);
            v228 = _mm_rsqrt_ps(v227);
            v613 = v227;
            *(__m128 *)(v81 + 8 * v220 + 16) = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmpleps(v227, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v228, v227), v228)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v228))),
                                                 v224);
            v218 = *(unsigned __int16 *)(v216 + 2 * v217);
            if ( v217 >= v219 )
              goto LABEL_124;
          }
        }
        goto LABEL_126;
      }
      v242 = (__int64)v512;
      if ( v172 > 0 )
      {
        v243 = v512[3];
        retaddr = 0i64;
        boneWeightsInOut = (char *)v172;
        if ( v172 > 0i64 )
        {
          v244 = (__m128 *)v511;
          v245 = v512 + 2;
          do
          {
            if ( v243 >= v64 )
              break;
            v246 = 6i64 * *(v245 - 2);
            v247 = 6i64 * *(v245 - 1);
            v248 = 6i64 * *v245;
            v249 = 3i64 * v243;
            v250 = _mm_shuffle_ps(v244[3 * *(v245 - 2) + 1], v244[3 * *(v245 - 1) + 1], 68);
            v251 = p[3 * *v245 + 1];
            v252 = v250;
            v253 = _mm_shuffle_ps(v244[3 * *v245 + 1], v244[v249 + 1], 68);
            v254 = (__m128i)_mm_shuffle_ps(v250, v253, 221);
            v255 = (__m128i)_mm_shuffle_ps(v252, v253, 136);
            v256 = (__m128i)_mm_shuffle_ps(
                              _mm_shuffle_ps(v244[3 * *(v245 - 2) + 1], v244[3 * *(v245 - 1) + 1], 238),
                              _mm_shuffle_ps(v244[3 * *v245 + 1], v244[v249 + 1], 238),
                              136);
            v257 = _mm_slli_epi32(v255, 1u);
            v258 = (__m128)v255;
            v259 = _mm_shuffle_ps((__m128)v255, (__m128)v254, 238);
            v260 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v254, 1u), 1u);
            v261 = _mm_shuffle_ps(v258, (__m128)v254, 68);
            v262 = _mm_shuffle_ps(p[3 * *(v245 - 2) + 1], p[3 * *(v245 - 1) + 1], 68);
            v263 = _mm_shuffle_ps(p[3 * *(v245 - 2) + 1], p[3 * *(v245 - 1) + 1], 238);
            v264 = v261;
            v265 = _mm_sub_ps(
                     query.m_quad,
                     _mm_add_ps(
                       _mm_add_ps((__m128)_mm_srli_epi32(v257, 1u), v260),
                       (__m128)_mm_srli_epi32(_mm_slli_epi32(v256, 1u), 1u)));
            v266 = _mm_cmpltps(v265, query.m_quad);
            v267 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v266, query.m_quad), _mm_and_ps(v266, v265)));
            v268 = _mm_shuffle_ps((__m128)v256, v267, 68);
            v269 = _mm_shuffle_ps((__m128)v256, v267, 238);
            v270 = _mm_shuffle_ps(v261, v268, 221);
            v271 = _mm_shuffle_ps(v264, v268, 136);
            v272 = p[3 * *v245 + 1];
            v510 = v270;
            v518 = _mm_shuffle_ps(v259, v269, 136);
            v273 = _mm_shuffle_ps(v272, p[v249 + 1], 68);
            v274 = _mm_shuffle_ps(v251, p[v249 + 1], 238);
            v509 = _mm_shuffle_ps(v259, v269, 221);
            v275 = (__m128i)_mm_shuffle_ps(v262, v273, 136);
            v276 = (__m128i)_mm_shuffle_ps(v262, v273, 221);
            v277 = (__m128i)_mm_shuffle_ps(v263, v274, 136);
            v278 = _mm_add_ps(
                     (__m128)_mm_srli_epi32(_mm_slli_epi32(v275, 1u), 1u),
                     (__m128)_mm_srli_epi32(_mm_slli_epi32(v276, 1u), 1u));
            v279 = (__m128)v275;
            v280 = _mm_shuffle_ps((__m128)v275, (__m128)v276, 238);
            v281 = _mm_shuffle_ps(v279, (__m128)v276, 68);
            v282 = _mm_sub_ps(query.m_quad, _mm_add_ps(v278, (__m128)_mm_srli_epi32(_mm_slli_epi32(v277, 1u), 1u)));
            v283 = _mm_cmpltps(v282, query.m_quad);
            v284 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v283, query.m_quad), _mm_and_ps(v283, v282)));
            v285 = _mm_shuffle_ps((__m128)v277, v284, 68);
            v286 = _mm_shuffle_ps((__m128)v277, v284, 238);
            v287 = _mm_shuffle_ps(v281, v285, 136);
            v288 = _mm_shuffle_ps(v281, v285, 221);
            v517 = _mm_shuffle_ps(v280, v286, 221);
            v289 = _mm_mul_ps(v517, v509);
            v290 = _mm_mul_ps(v287, v271);
            v291 = _mm_shuffle_ps(v280, v286, 136);
            v292 = v290;
            v293 = _mm_mul_ps(v288, v270);
            v294 = _mm_mul_ps(v291, v518);
            v295 = v294;
            v296 = _mm_shuffle_ps(v290, v293, 238);
            v297 = _mm_shuffle_ps(v292, v293, 68);
            v298 = _mm_shuffle_ps(v294, v289, 238);
            v299 = _mm_shuffle_ps(v295, v289, 68);
            v300 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_cmpltps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_shuffle_ps(v296, v298, 221),
                                                _mm_shuffle_ps(v296, v298, 136)),
                                              _mm_add_ps(
                                                _mm_shuffle_ps(v297, v299, 221),
                                                _mm_shuffle_ps(v297, v299, 136))),
                                            (__m128)0i64),
                                 0x1Fu),
                               0x1Fu),
                     v530);
            v301 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v300, v300, 0), v287), _mm_mul_ps(v526, v271));
            v302 = _mm_mul_ps(v301, v301);
            v303 = _mm_add_ps(_mm_shuffle_ps(v302, v302, 78), v302);
            v304 = _mm_add_ps(_mm_shuffle_ps(v303, v303, 177), v303);
            v305 = _mm_rsqrt_ps(v304);
            v607 = v304;
            v306 = _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v305, v304), v305)),
                     _mm_mul_ps(*(__m128 *)_xmm, v305));
            v307 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v300, v300, 85), v288), _mm_mul_ps(v526, v510));
            v308 = _mm_mul_ps(v307, v307);
            v309 = _mm_add_ps(_mm_shuffle_ps(v308, v308, 78), v308);
            v310 = _mm_add_ps(_mm_shuffle_ps(v309, v309, 177), v309);
            v311 = _mm_rsqrt_ps(v310);
            v601 = v310;
            v312 = _mm_cmpleps(v310, (__m128)0i64);
            v313 = _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v311, v310), v311)),
                     _mm_mul_ps(*(__m128 *)_xmm, v311));
            v314 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v300, v300, 170), v291), _mm_mul_ps(v526, v518));
            v315 = _mm_mul_ps(v314, v314);
            v316 = _mm_add_ps(_mm_shuffle_ps(v315, v315, 78), v315);
            v317 = _mm_add_ps(_mm_shuffle_ps(v316, v316, 177), v316);
            v318 = _mm_rsqrt_ps(v317);
            v589 = v317;
            v319 = _mm_cmpleps(v317, (__m128)0i64);
            v320 = _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v318, v317), v318)),
                     _mm_mul_ps(*(__m128 *)_xmm, v318));
            v522 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v300, v300, 255), v517), _mm_mul_ps(v526, v509));
            v321 = _mm_mul_ps(v522, v522);
            v322 = _mm_add_ps(_mm_shuffle_ps(v321, v321, 78), v321);
            v323 = _mm_add_ps(_mm_shuffle_ps(v322, v322, 177), v322);
            v324 = _mm_rsqrt_ps(v323);
            v590 = v323;
            v245 += 4;
            *(__m128 *)(v81 + 8 * v246 + 16) = _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v304, (__m128)0i64), v306), v301);
            *(__m128 *)(v81 + 8 * v247 + 16) = _mm_mul_ps(_mm_andnot_ps(v312, v313), v307);
            v171 = (_DWORD)refFloats + 4;
            LODWORD(refFloats) = (_DWORD)refFloats + 4;
            *(__m128 *)(v81 + 8 * v248 + 16) = _mm_mul_ps(_mm_andnot_ps(v319, v320), v314);
            retaddr += 4i64;
            *(__m128 *)(v81 + 4 * v249 + 16) = _mm_mul_ps(
                                                 _mm_andnot_ps(
                                                   _mm_cmpleps(v323, (__m128)0i64),
                                                   _mm_mul_ps(
                                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v324, v323), v324)),
                                                     _mm_mul_ps(*(__m128 *)_xmm, v324))),
                                                 v522);
            v243 = v245[1];
          }
          while ( retaddr < (signed __int64)boneWeightsInOut );
          v25 = v530;
          v27 = v526;
          v43 = v516;
        }
      }
      v325 = (char *)v511;
      v326 = v171;
      v327 = *(unsigned __int16 *)(v242 + 2i64 * v171);
      v328 = v170 - 1;
      if ( v326 < v328 )
      {
        while ( v327 < v64 )
        {
          v329 = 6i64 * v327;
          v330 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)&v325[8 * v329 + 16], 1u), 1u);
          v331 = _mm_sub_ps(
                   query.m_quad,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v330, v330, 85), _mm_shuffle_ps(v330, v330, 0)),
                     _mm_shuffle_ps(v330, v330, 170)));
          v332 = _mm_cmpltps(v331, query.m_quad);
          v333 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v331, v332), _mm_andnot_ps(v332, query.m_quad)));
          v334 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)p[(unsigned __int64)v329 / 2 + 1], 1u), 1u);
          v335 = _mm_shuffle_ps(
                   *(__m128 *)&v325[8 * v329 + 16],
                   _mm_unpackhi_ps(*(__m128 *)&v325[8 * v329 + 16], v333),
                   196);
          v336 = _mm_sub_ps(
                   query.m_quad,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v334, v334, 85), _mm_shuffle_ps(v334, v334, 0)),
                     _mm_shuffle_ps(v334, v334, 170)));
          v337 = _mm_cmpltps(v336, query.m_quad);
          v338 = _mm_shuffle_ps(
                   p[(unsigned __int64)v329 / 2 + 1],
                   _mm_unpackhi_ps(
                     p[(unsigned __int64)v329 / 2 + 1],
                     _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v336, v337), _mm_andnot_ps(v337, query.m_quad)))),
                   196);
          v339 = _mm_mul_ps(v338, v335);
          v340 = _mm_add_ps(_mm_shuffle_ps(v339, v339, 78), v339);
          v341 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_xor_ps(
                       (__m128)_mm_slli_epi32(
                                 _mm_srli_epi32(
                                   (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v340, v340, 177), v340), (__m128)0i64),
                                   0x1Fu),
                                 0x1Fu),
                       v25),
                     v338),
                   _mm_mul_ps(v27, v335));
          v342 = _mm_mul_ps(v341, v341);
          v343 = _mm_add_ps(_mm_shuffle_ps(v342, v342, 78), v342);
          v344 = _mm_add_ps(_mm_shuffle_ps(v343, v343, 177), v343);
          v345 = _mm_rsqrt_ps(v344);
          v592 = v344;
          ++v326;
          *(__m128 *)(v81 + 8 * v329 + 16) = _mm_mul_ps(
                                               _mm_andnot_ps(
                                                 _mm_cmpleps(v344, (__m128)0i64),
                                                 _mm_mul_ps(
                                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v345, v344), v345)),
                                                   _mm_mul_ps(*(__m128 *)_xmm, v345))),
                                               v341);
          v327 = *(unsigned __int16 *)(v242 + 2 * v326);
          if ( v326 >= v328 )
            goto LABEL_140;
        }
        goto LABEL_126;
      }
LABEL_140:
      if ( v327 >= v64 )
      {
LABEL_126:
        v238 = p;
        goto LABEL_127;
      }
      v238 = p;
      v346 = 6i64 * v327;
      v347 = (__m128)_mm_srli_epi32(_mm_slli_epi32(*(__m128i *)&v325[8 * v346 + 16], 1u), 1u);
      v348 = _mm_sub_ps(
               query.m_quad,
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v347, v347, 85), _mm_shuffle_ps(v347, v347, 0)),
                 _mm_shuffle_ps(v347, v347, 170)));
      v349 = _mm_cmpltps(v348, query.m_quad);
      v350 = _mm_or_ps(_mm_andnot_ps(v349, query.m_quad), _mm_and_ps(v348, v349));
      v351 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)p[(unsigned __int64)v346 / 2 + 1], 1u), 1u);
      v352 = _mm_shuffle_ps(
               *(__m128 *)&v325[8 * v346 + 16],
               _mm_unpackhi_ps(*(__m128 *)&v325[8 * v346 + 16], _mm_max_ps((__m128)0i64, v350)),
               196);
      v353 = _mm_sub_ps(
               query.m_quad,
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v351, v351, 85), _mm_shuffle_ps(v351, v351, 0)),
                 _mm_shuffle_ps(v351, v351, 170)));
      v354 = _mm_cmpltps(v353, query.m_quad);
      v355 = _mm_shuffle_ps(
               p[(unsigned __int64)v346 / 2 + 1],
               _mm_unpackhi_ps(
                 p[(unsigned __int64)v346 / 2 + 1],
                 _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v353, v354), _mm_andnot_ps(v354, query.m_quad)))),
               196);
      v356 = _mm_mul_ps(v355, v352);
      v357 = _mm_add_ps(_mm_shuffle_ps(v356, v356, 78), v356);
      v358 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_xor_ps(
                   (__m128)_mm_slli_epi32(
                             _mm_srli_epi32(
                               (__m128i)_mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(v357, v357, 177), v357), (__m128)0i64),
                               0x1Fu),
                             0x1Fu),
                   v25),
                 v355),
               _mm_mul_ps(v27, v352));
      v359 = _mm_mul_ps(v358, v358);
      v360 = _mm_add_ps(_mm_shuffle_ps(v359, v359, 78), v359);
      v594 = _mm_add_ps(_mm_shuffle_ps(v360, v360, 177), v360);
      v361 = _mm_rsqrt_ps(v594);
      *(__m128 *)(v81 + 8 * v346 + 16) = _mm_mul_ps(
                                           _mm_andnot_ps(
                                             _mm_cmpleps(v594, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v361, v594), v361)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v361))),
                                           v358);
    }
LABEL_127:
    v239 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v240 = (signed int)floatsOut;
    v241 = ((_DWORD)floatsOut + 15) & 0xFFFFFFF0;
    if ( (signed int)floatsOut > v239->m_slabSize
      || (char *)v238 + v241 != v239->m_cur
      || v239->m_firstNonLifoEnd == v238 )
    {
      hkLifoAllocator::slowBlockFree(v239, v238, v241);
    }
    else
    {
      v239->m_cur = v238;
    }
    v362 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    if ( v240 > v362->m_slabSize || (char *)v511 + v241 != v362->m_cur || v362->m_firstNonLifoEnd == v511 )
      hkLifoAllocator::slowBlockFree(v362, v511, v241);
    else
      v362->m_cur = v511;
    LODWORD(v55) = numBones;
    v13 = end;
  }
  v363 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v364 = (_QWORD *)v363[1];
  if ( (unsigned __int64)v364 < v363[3] )
  {
    *v364 = "StCopyReferencePoseF";
    v365 = __rdtsc();
    v366 = (signed __int64)(v364 + 2);
    *(_DWORD *)(v366 - 8) = v365;
    v363[1] = v366;
  }
  v367 = refBones;
  v368 = bonesOut;
  if ( (signed int)v55 > 0 )
  {
    v369 = (unsigned int)v55;
    v370 = (char *)bonesOut - (char *)refBones;
    do
    {
      v371 = v367->m_translation.m_quad.m128_i32[0];
      v367 = (hkQsTransformf *)((char *)v367 + 4);
      *(int *)((char *)&v367->m_translation.m_quad.m128_i32[-1] + v370) = v371;
      --v369;
    }
    while ( v369 );
  }
  v372 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v373 = (_QWORD *)v372[1];
  if ( (unsigned __int64)v373 < v372[3] )
  {
    *v373 = "StCopyStaticTracksF";
    v374 = __rdtsc();
    v375 = (signed __int64)(v373 + 2);
    *(_DWORD *)(v375 - 8) = v374;
    v372[1] = v375;
  }
  v376 = v12->m_intData.m_data;
  v377 = v12->m_intArrayOffsets[7];
  v378 = &v376[v377];
  v379 = v12->m_intArrayOffsets[8] - v377;
  retaddr = (signed __int64)&v376[v12->m_intArrayOffsets[5]];
  if ( v379 > 0 )
  {
    v380 = *v378;
    v381 = v515;
    v382 = 0i64;
    v383 = v379 - 1;
    v384 = v383;
    if ( v383 <= 0 )
    {
LABEL_161:
      if ( v380 < (signed int)v55 )
        v368->m_translation.m_quad.m128_i32[v380] = *v381;
    }
    else
    {
      while ( v380 < (signed int)v55 )
      {
        v385 = *v381;
        ++v382;
        ++v381;
        v368->m_translation.m_quad.m128_i32[v380] = v385;
        v380 = v378[v382];
        if ( v382 >= v384 )
          goto LABEL_161;
      }
    }
  }
  v386 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v387 = (_QWORD *)v386[1];
  if ( (unsigned __int64)v387 < v386[3] )
  {
    *v387 = "StCopyDynamicTracksF";
    v388 = __rdtsc();
    v389 = (signed __int64)(v387 + 2);
    *(_DWORD *)(v389 - 8) = v388;
    v386[1] = v389;
  }
  if ( v524 != v533 )
  {
    v390 = v12->m_firstFloatBlockScaleAndOffsetIndex;
    v391 = v12->m_floatData.m_data;
    v13 = v533;
    v29 = &v391[v390 + v12->m_floatArrayOffsets[1]];
    v31 = (signed __int64)&v391[v390 + v12->m_floatArrayOffsets[2]];
    v513 = &v12->m_intData.m_data[v12->m_intArrayOffsets[3]
                                + ((signed __int64)(v12->m_intArrayOffsets[5] - v12->m_intArrayOffsets[4]) >> 4)];
  }
  v392 = v12->m_intArrayOffsets[5];
  v393 = v12->m_intArrayOffsets[6] - v392;
  v394 = (v392 - v12->m_intArrayOffsets[4]) & 0x8000000F;
  LODWORD(refFloats) = v393;
  v617 = v394;
  if ( v394 < 0 )
  {
    v394 = (((_BYTE)v394 - 1) | 0xFFFFFFF0) + 1;
    v617 = v394;
  }
  v395 = v393;
  if ( 16 - v394 < v393 )
    v395 = 16 - v394;
  if ( v395 <= 0 )
  {
    v441 = retaddr;
    goto LABEL_211;
  }
  if ( v524 != v533 )
  {
    v396 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v397 = v396[1];
    if ( v397 < v396[3] )
    {
      *(_QWORD *)v397 = "LtloadDynamic";
      *(_QWORD *)(v397 + 16) = "StDecompress";
      v398 = __rdtsc();
      *(_DWORD *)(v397 + 8) = v398;
      v396[1] = v397 + 24;
    }
    if ( v506 )
      v399 = hkaPredictiveBlockCompression::decodeSingleFrame(v13, (int)start, (__int16 *)frameData->m128i_i64);
    else
      v399 = hkaPredictiveBlockCompression::decodeAdjacentFrames(v13, (int)start, (__int16 *)frameData->m128i_i64);
    v13 = v399;
    v400 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v401 = (_QWORD *)v400[1];
    if ( (unsigned __int64)v401 < v400[3] )
    {
      *v401 = "StDequantize";
      v402 = __rdtsc();
      v403 = (signed __int64)(v401 + 2);
      *(_DWORD *)(v403 - 8) = v402;
      v400[1] = v403;
    }
    v404 = 0i64;
    LODWORD(end) = 956302336;
    v405 = *v513;
    v406 = 0i64;
    ++v513;
    v407 = 4i64;
    do
    {
      if ( v405 & 1 )
      {
        v509.m128_i32[v404] = 956302336;
        v510.m128_i32[v404] = 0;
      }
      else
      {
        v408 = *(_DWORD *)v29;
        ++v29;
        v31 += 4i64;
        v509.m128_i32[v406] = v408;
        v510.m128_i32[v406] = *(_DWORD *)(v31 - 4);
      }
      v405 >>= 1;
      ++v404;
      ++v406;
      --v407;
    }
    while ( v407 );
    v409 = v509;
    v410 = v510;
    v411 = 0i64;
    v412 = 0i64;
    v413 = 4i64;
    v584 = v509;
    v564 = v510;
    do
    {
      if ( v405 & 1 )
      {
        v509.m128_i32[v411] = 956302336;
        v510.m128_i32[v411] = 0;
      }
      else
      {
        v414 = *(_DWORD *)v29;
        ++v29;
        v31 += 4i64;
        v509.m128_i32[v412] = v414;
        v510.m128_i32[v412] = *(_DWORD *)(v31 - 4);
      }
      v405 >>= 1;
      ++v411;
      ++v412;
      --v413;
    }
    while ( v413 );
    v415 = v509;
    v416 = v510;
    v417 = 0i64;
    v418 = 0i64;
    v419 = 4i64;
    v576 = v509;
    v566 = v510;
    do
    {
      if ( v405 & 1 )
      {
        v509.m128_i32[v417] = 956302336;
        v510.m128_i32[v417] = 0;
      }
      else
      {
        v420 = *(_DWORD *)v29;
        ++v29;
        v31 += 4i64;
        v509.m128_i32[v418] = v420;
        v510.m128_i32[v418] = *(_DWORD *)(v31 - 4);
      }
      v405 >>= 1;
      ++v417;
      ++v418;
      --v419;
    }
    while ( v419 );
    v421 = v509;
    v422 = v510;
    v423 = 0i64;
    v424 = 0i64;
    v425 = 4i64;
    v582 = v509;
    v568 = v510;
    do
    {
      if ( v405 & 1 )
      {
        v509.m128_i32[v423] = 956302336;
        v510.m128_i32[v423] = 0;
      }
      else
      {
        v426 = *(_DWORD *)v29;
        ++v29;
        v31 += 4i64;
        v509.m128_i32[v424] = v426;
        v510.m128_i32[v424] = *(_DWORD *)(v31 - 4);
      }
      v405 >>= 1;
      ++v423;
      ++v424;
      --v425;
    }
    while ( v425 );
    v427 = v509;
    v428 = v510;
    v578 = v509;
    v570 = v510;
    v429 = _mm_load_si128(frameData);
    _mm_store_si128((__m128i *)&v596, v429);
    v430 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v429, (__m128i)0i64), 0x10u), 0x10u)),
               v409),
             v410);
    v531 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v429, (__m128i)0i64), 0x10u), 0x10u)),
               v415),
             v416);
    v572 = v430;
    v431 = _mm_load_si128(frameData + 1);
    _mm_store_si128((__m128i *)&v598, v431);
    v527 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v431, (__m128i)0i64), 0x10u), 0x10u)),
               v421),
             v422);
    v535 = _mm_add_ps(
             _mm_mul_ps(
               _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v431, (__m128i)0i64), 0x10u), 0x10u)),
               v427),
             v428);
    if ( v506 )
    {
      v43[8] = v430;
      v43[9] = v531;
      v43[10] = v527;
      v435 = v535;
    }
    else
    {
      *v43 = v430;
      v43[1] = v531;
      v43[2] = v527;
      v43[3] = v535;
      v432 = _mm_load_si128(frameData + 2);
      _mm_store_si128((__m128i *)&v600, v432);
      v433 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v432, (__m128i)0i64), 0x10u), 0x10u)),
                 v584),
               v564);
      v545 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v432, (__m128i)0i64), 0x10u), 0x10u)),
                 v576),
               v566);
      v586 = v433;
      v434 = _mm_load_si128(frameData + 3);
      _mm_store_si128((__m128i *)&v602, v434);
      v539 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v434, (__m128i)0i64), 0x10u), 0x10u)),
                 v582),
               v568);
      v540 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v434, (__m128i)0i64), 0x10u), 0x10u)),
                 v578),
               v570);
      v43[4] = v433;
      v43[5] = v545;
      v43[6] = v539;
      v43[7] = v540;
      v604 = _mm_add_ps(_mm_mul_ps(v25, v586), _mm_mul_ps(v27, v572));
      v580 = _mm_add_ps(_mm_mul_ps(v25, v545), _mm_mul_ps(v27, v531));
      v574 = _mm_add_ps(_mm_mul_ps(v25, v539), _mm_mul_ps(v27, v527));
      v562 = _mm_add_ps(_mm_mul_ps(v25, v540), _mm_mul_ps(v27, v535));
      v43[8] = v604;
      v43[9] = v580;
      v43[10] = v574;
      v435 = v562;
    }
    v43[11] = v435;
    v436 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v393 = (signed int)refFloats;
    v437 = (_QWORD *)v436[1];
    v438 = v436;
    if ( (unsigned __int64)v437 < v436[3] )
    {
      *v437 = "lt";
      v439 = __rdtsc();
      v440 = (signed __int64)(v437 + 2);
      *(_DWORD *)(v440 - 8) = v439;
      v438[1] = v440;
    }
  }
  v441 = retaddr;
  v442 = (signed int)v617;
  v443 = *(unsigned __int16 *)retaddr;
  v444 = 0;
  v445 = 0i64;
  if ( v395 - 1 <= 0 )
  {
LABEL_208:
    v446 = numBones;
    if ( v443 >= numBones )
      goto LABEL_212;
    v368->m_translation.m_quad.m128_i32[v443] = *((_DWORD *)v43 + v442 + v444 + 32);
LABEL_211:
    v446 = numBones;
    goto LABEL_212;
  }
  while ( 1 )
  {
    v446 = numBones;
    if ( v443 >= numBones )
      break;
    v447 = v442 + v445++;
    ++v444;
    v368->m_translation.m_quad.m128_i32[v443] = *((_DWORD *)v43 + v447 + 32);
    v443 = *(unsigned __int16 *)(retaddr + 2 * v445);
    if ( v445 >= v395 - 1 )
      goto LABEL_208;
  }
LABEL_212:
  if ( v395 < v393 )
  {
    v448 = v395;
    end = (const char *)v393;
    if ( v395 < (signed __int64)v393 )
    {
      do
      {
        v449 = *(unsigned __int16 *)(v441 + 2 * v448);
        if ( v449 >= v446 )
          break;
        v450 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v451 = v450[1];
        if ( v451 < v450[3] )
        {
          *(_QWORD *)v451 = "LtloadDynamic";
          *(_QWORD *)(v451 + 16) = "StDecompress";
          v452 = __rdtsc();
          *(_DWORD *)(v451 + 8) = v452;
          v450[1] = v451 + 24;
        }
        if ( v506 )
          v453 = hkaPredictiveBlockCompression::decodeSingleFrame(v13, (int)start, (__int16 *)frameData->m128i_i64);
        else
          v453 = hkaPredictiveBlockCompression::decodeAdjacentFrames(v13, (int)start, (__int16 *)frameData->m128i_i64);
        v13 = v453;
        v454 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v455 = (_QWORD *)v454[1];
        if ( (unsigned __int64)v455 < v454[3] )
        {
          *v455 = "StDequantize";
          v456 = __rdtsc();
          v457 = (signed __int64)(v455 + 2);
          *(_DWORD *)(v457 - 8) = v456;
          v454[1] = v457;
        }
        v458 = 0i64;
        v617 = 956302336;
        v459 = *v513;
        v460 = 0i64;
        ++v513;
        v461 = 4i64;
        do
        {
          if ( v459 & 1 )
          {
            v509.m128_i32[v458] = 956302336;
            v510.m128_i32[v458] = 0;
          }
          else
          {
            v462 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v509.m128_i32[v460] = v462;
            v510.m128_i32[v460] = *(_DWORD *)(v31 - 4);
          }
          v459 >>= 1;
          ++v458;
          ++v460;
          --v461;
        }
        while ( v461 );
        v463 = v509;
        v464 = v510;
        v465 = 0i64;
        v466 = 0i64;
        v467 = 4i64;
        v563 = v509;
        v565 = v510;
        do
        {
          if ( v459 & 1 )
          {
            v518.m128_i32[v465] = 956302336;
            v517.m128_i32[v465] = 0;
          }
          else
          {
            v468 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v518.m128_i32[v466] = v468;
            v517.m128_i32[v466] = *(_DWORD *)(v31 - 4);
          }
          v459 >>= 1;
          ++v465;
          ++v466;
          --v467;
        }
        while ( v467 );
        v469 = v518;
        v470 = v517;
        v471 = 0i64;
        v472 = 0i64;
        v473 = 4i64;
        v567 = v518;
        v569 = v517;
        do
        {
          if ( v459 & 1 )
          {
            v520.m128_i32[v471] = 956302336;
            v523.m128_i32[v471] = 0;
          }
          else
          {
            v474 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v520.m128_i32[v472] = v474;
            v523.m128_i32[v472] = *(_DWORD *)(v31 - 4);
          }
          v459 >>= 1;
          ++v471;
          ++v472;
          --v473;
        }
        while ( v473 );
        v475 = v520;
        v476 = v523;
        v477 = 0i64;
        v478 = 0i64;
        v479 = 4i64;
        v571 = v520;
        v573 = v523;
        do
        {
          if ( v459 & 1 )
          {
            v525.m128_i32[v477] = 956302336;
            v521.m128_i32[v477] = 0;
          }
          else
          {
            v480 = *(_DWORD *)v29;
            ++v29;
            v31 += 4i64;
            v525.m128_i32[v478] = v480;
            v521.m128_i32[v478] = *(_DWORD *)(v31 - 4);
          }
          v459 >>= 1;
          ++v477;
          ++v478;
          --v479;
        }
        while ( v479 );
        v481 = v525;
        v482 = v521;
        v548 = v525;
        v550 = v521;
        v483 = _mm_load_si128(frameData);
        _mm_store_si128((__m128i *)&v606, v483);
        v484 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v483, (__m128i)0i64), 0x10u), 0x10u)),
                   v463),
                 v464);
        v528 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v483, (__m128i)0i64), 0x10u), 0x10u)),
                   v469),
                 v470);
        v554 = v484;
        v485 = _mm_load_si128(frameData + 1);
        _mm_store_si128((__m128i *)&v608, v485);
        v529 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v485, (__m128i)0i64), 0x10u), 0x10u)),
                   v475),
                 v476);
        v537 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v485, (__m128i)0i64), 0x10u), 0x10u)),
                   v481),
                 v482);
        if ( v506 )
        {
          v43[8] = v484;
          v43[9] = v528;
          v43[10] = v529;
          v489 = v537;
        }
        else
        {
          *v43 = v484;
          v43[1] = v528;
          v43[2] = v529;
          v43[3] = v537;
          v486 = _mm_load_si128(frameData + 2);
          _mm_store_si128((__m128i *)&v610, v486);
          v487 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v486, (__m128i)0i64), 0x10u), 0x10u)),
                     v563),
                   v565);
          v542 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v486, (__m128i)0i64), 0x10u), 0x10u)),
                     v567),
                   v569);
          v552 = v487;
          v488 = _mm_load_si128(frameData + 3);
          _mm_store_si128((__m128i *)&v612, v488);
          v544 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpacklo_epi16(v488, (__m128i)0i64), 0x10u), 0x10u)),
                     v571),
                   v573);
          v546 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(_mm_unpackhi_epi16(v488, (__m128i)0i64), 0x10u), 0x10u)),
                     v548),
                   v550);
          v43[4] = v487;
          v43[5] = v542;
          v43[6] = v544;
          v43[7] = v546;
          v614 = _mm_add_ps(_mm_mul_ps(v25, v552), _mm_mul_ps(v27, v554));
          v556 = _mm_add_ps(_mm_mul_ps(v25, v542), _mm_mul_ps(v27, v528));
          v558 = _mm_add_ps(_mm_mul_ps(v25, v544), _mm_mul_ps(v27, v529));
          v560 = _mm_add_ps(_mm_mul_ps(v25, v546), _mm_mul_ps(v27, v537));
          v43[8] = v614;
          v43[9] = v556;
          v43[10] = v558;
          v489 = v560;
        }
        v43[11] = v489;
        v490 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v491 = (_QWORD *)v490[1];
        if ( (unsigned __int64)v491 < v490[3] )
        {
          *v491 = "lt";
          v492 = __rdtsc();
          v493 = (signed __int64)(v491 + 2);
          *(_DWORD *)(v493 - 8) = v492;
          v490[1] = v493;
        }
        v494 = (signed int)refFloats;
        v495 = bonesOut;
        v496 = 0i64;
        if ( v395 + 16 < (signed int)refFloats )
          v494 = v395 + 16;
        v497 = v494 - 1;
        if ( v448 >= v497 )
        {
LABEL_253:
          v446 = numBones;
          if ( v449 < numBones )
          {
            ++v395;
            v495->m_translation.m_quad.m128_i32[v449] = *((_DWORD *)v43 + v496 + 32);
            v446 = numBones;
            ++v448;
          }
        }
        else
        {
          v498 = (int *)(v43 + 8);
          while ( 1 )
          {
            v446 = numBones;
            if ( v449 >= numBones )
              break;
            v499 = *v498;
            ++v448;
            ++v395;
            ++v496;
            ++v498;
            v495->m_translation.m_quad.m128_i32[v449] = v499;
            v449 = *(unsigned __int16 *)(retaddr + 2 * v448);
            if ( v448 >= v497 )
              goto LABEL_253;
          }
        }
        v441 = retaddr;
      }
      while ( v448 < (signed __int64)end );
    }
  }
  v500 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v500->m_slabSize < 256 || v43 + 16 != v500->m_cur || v500->m_firstNonLifoEnd == v43 )
    hkLifoAllocator::slowBlockFree(v500, v43, 256);
  else
    v500->m_cur = v43;
  v501 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v501->m_slabSize < 128 || &frameData[8] != v501->m_cur || v501->m_firstNonLifoEnd == frameData )
    hkLifoAllocator::slowBlockFree(v501, frameData, 128);
  else
    v501->m_cur = frameData;
  v502 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v503 = (_QWORD *)v502[1];
  if ( (unsigned __int64)v503 < v502[3] )
  {
    *v503 = "lt";
    v504 = __rdtsc();
    v505 = (signed __int64)(v503 + 2);
    *(_DWORD *)(v505 - 8) = v504;
    v502[1] = v505;
  }
}= v556;
          v43[10] = v558;
          v489 = v560;
        }
        v43[11] = v489;
        v490 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v491 = (_QWORD *)v490[1];
        if ( (unsigned __int64)v491 < v490[3] )
        {
          *v491 = "lt";
          v492 = __rdtsc();
          v493 = (signed __int64)(v491 + 2);
          *(_DWORD *)(v493 - 8) = v492;
          v490[1] = v493;
        }
        v494 = (signed int)refFloats;
        v495 = bonesOut;
        v496 = 0i64;
        if ( v395 + 16 < (signed int)refFloats )
          v494 = v395 + 16;
        v497 = v494 - 1;
        if ( v448 >= v497 )
        {
LABEL_253:
          v446 = numBones;
          if ( v449 < numBones )
          {
            ++v395;
            v495->m_translation.m_quad.m128_i32[v449] = *((_DWORD *)v43 + v496 + 32);
            v446 = numBones;
            ++v448;
          }
        }
        else
        {
          v498 = (int *)(v43 + 8);
          while ( 1 )
          {
            v446 = numBones;
            if ( v449 >= numBones )
              break;
    

// File Line: 849
// RVA: 0xB2F690
signed __int64 __fastcall hkaPredictiveCompressedAnimation::getNumDataChunks(hkaPredictiveCompressedAnimation *this, unsigned int frame, float delta)
{
  return 4i64;
}

// File Line: 854
// RVA: 0xB2F810
void __fastcall hkaPredictiveCompressedAnimation::recoverChunkData(hkaPredictiveCompressedAnimation *this, hkaAnimation::DataChunk *ch, int numChunks)
{
  int v3; // er8
  char *v4; // rax
  hkaPredictiveCompressedAnimation *v5; // r9
  unsigned int v6; // ecx
  unsigned int v7; // ecx

  v3 = ch[1].m_size;
  v4 = (char *)ch[1].m_data;
  v5 = this;
  this->m_compressedData.m_size = v3;
  this->m_compressedData.m_data = v4;
  this->m_compressedData.m_capacityAndFlags = v3 | 0x80000000;
  v6 = ch[2].m_size >> 1;
  v5->m_intData.m_data = (unsigned __int16 *)ch[2].m_data;
  v5->m_intData.m_size = v6;
  v5->m_intData.m_capacityAndFlags = v6 | 0x80000000;
  v7 = ch[3].m_size >> 2;
  v5->m_floatData.m_data = (float *)ch[3].m_data;
  v5->m_floatData.m_size = v7;
  v5->m_floatData.m_capacityAndFlags = v7 | 0x80000000;
}

// File Line: 863
// RVA: 0xB2F6A0
void __fastcall hkaPredictiveCompressedAnimation::getDataChunks(hkaPredictiveCompressedAnimation *this, unsigned int frame, float delta, hkaAnimation::DataChunk *ch)
{
  hkaAnimation::DataChunk *v4; // rbx
  hkaPredictiveCompressedAnimation *v5; // rdi
  unsigned int v6; // edx
  float *v7; // rcx
  int v8; // edx
  unsigned __int16 *v9; // rax
  int v10; // eax
  unsigned int start; // [rsp+30h] [rbp+8h]
  unsigned int end; // [rsp+48h] [rbp+20h]

  v4 = ch;
  ch->m_data = (const char *)this;
  ch->m_size = 192;
  v5 = this;
  hkaPredictiveCompressedAnimation::getCompressedDataOffset(this, frame, &start, &end);
  v6 = start;
  v7 = 0i64;
  v4[1].m_data = &v5->m_compressedData.m_data[start];
  v4[1].m_size = end - v6;
  v8 = v5->m_intData.m_size;
  v9 = 0i64;
  if ( v8 )
    v9 = v5->m_intData.m_data;
  v4[2].m_data = (const char *)v9;
  v4[2].m_size = 2 * v8;
  v10 = v5->m_floatData.m_size;
  if ( v10 )
    v7 = v5->m_floatData.m_data;
  v4[3].m_data = (const char *)v7;
  v4[3].m_size = 4 * v10;
}

// File Line: 874
// RVA: 0xB2F730
unsigned __int64 __fastcall hkaPredictiveCompressedAnimation::getMaxSizeOfCombinedDataChunks(hkaPredictiveCompressedAnimation *this)
{
  return ((4i64 * (unsigned int)this->m_floatData.m_size + 15) & 0xFFFFFFFFFFFFFFF0ui64)
       + ((this->m_maxCompressedBytesPerFrame + 31) & 0xFFFFFFF0)
       + ((2i64 * (unsigned int)this->m_intData.m_size + 15) & 0xFFFFFFFFFFFFFFF0ui64)
       + 192;
}

// File Line: 884
// RVA: 0xB2F780
signed __int64 __fastcall hkaPredictiveCompressedAnimation::getMaxDecompressionTempBytes(hkaPredictiveCompressedAnimation *this)
{
  hkaSkeleton *v1; // rax
  unsigned int v2; // er9

  v1 = this->m_skeleton;
  v2 = (v1->m_bones.m_size + 3) & 0xFFFFFFFC;
  return ((v2 + 15) & 0xFFFFFFF0)
       + ((((v1->m_floatSlots.m_size + 3) & 0xFFFFFFFC) + 15) & 0xFFFFFFF0)
       + 4 * (((v1->m_floatSlots.m_size + 3) & 0xFFFFFFFC) + 4 * (v2 + 2 * (v2 + 8)))
       + 96i64 * v2;
}

// File Line: 910
// RVA: 0xB32220
void __fastcall hkaPredictiveCompressedAnimation::samplePartialWithDataChunks(int frameIndex, float frameDelta, int numTransformTracks, int numFloatTracks, hkQsTransformf *referenceBones, const float *referenceFloats, hkaAnimation::DataChunk *chunks, int numChunks, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  hkaPredictiveCompressedAnimation *v10; // r13
  int v11; // ebx
  int v12; // er14
  __int64 numBones; // r15
  signed __int64 numFloats; // r12
  hkLifoAllocator *v15; // rax
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
  int v31; // er9
  __int64 v32; // r8
  hkQsTransformf *v33; // r10
  hkVector4f *v34; // rcx
  hkQsTransformf *v35; // rax
  float *v36; // rcx
  signed __int64 v37; // r8
  float *v38; // r9
  int v39; // ebx
  hkLifoAllocator *v40; // rax
  int v41; // er8
  int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // er8
  int v45; // ebx
  hkLifoAllocator *v46; // rax
  int v47; // er8
  int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // er8
  hkQsTransformf *bonesOut; // [rsp+70h] [rbp-48h]
  int frameIndexa; // [rsp+C0h] [rbp+8h]

  frameIndexa = frameIndex;
  v10 = (hkaPredictiveCompressedAnimation *)chunks->m_data;
  v11 = numFloatTracks;
  v12 = numTransformTracks;
  numBones = *((signed int *)chunks->m_data + 39);
  numFloats = *((signed int *)chunks->m_data + 40);
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesOut = (hkQsTransformf *)v15->m_cur;
  v16 = (48 * ((numBones + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v17 = (char *)bonesOut + v16;
  if ( v16 > v15->m_slabSize || v17 > v15->m_end )
    bonesOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v15, v16);
  else
    v15->m_cur = v17;
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  floatsOut = (float *)v18->m_cur;
  v20 = (4 * ((numFloats + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
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
  v28 = (((numFloats + 15) & 0xFFFFFFF0) + 127) & 0xFFFFFF80;
  v29 = &floatWeightsInOut[v28];
  if ( v28 > v26->m_slabSize || v29 > v26->m_end )
    floatWeightsInOut = (char *)hkLifoAllocator::allocateFromNewSlab(v26, v28);
  else
    v26->m_cur = v29;
  hkString::memSet(boneWeightsInOut, 255, numBones);
  hkString::memSet(floatWeightsInOut, 255, numFloats);
  hkaPredictiveCompressedAnimation::sampleFullPose(
    v10,
    frameIndexa,
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
  if ( (signed int)numBones > 0 )
  {
    v33 = transformTracksOut;
    v34 = &bonesOut->m_scale;
    do
    {
      if ( v31 >= v12 )
        break;
      if ( (unsigned __int8)boneWeightsInOut[v32] > 0u )
      {
        v35 = v33;
        ++v33;
        v35->m_translation = (hkVector4f)v34[-2].m_quad;
        ++v31;
        v35->m_rotation.m_vec = (hkVector4f)v34[-1].m_quad;
        v35->m_scale = (hkVector4f)v34->m_quad;
      }
      ++v32;
      v34 += 3;
    }
    while ( v32 < numBones );
  }
  v36 = floatTracksOut;
  v37 = 0i64;
  if ( numFloats < 4 )
  {
LABEL_38:
    while ( v37 < numFloats )
    {
      if ( v30 >= v11 )
        break;
      if ( floatWeightsInOut[v37] )
      {
        ++v36;
        ++v30;
        *(v36 - 1) = floatsOut[v37];
      }
      ++v37;
    }
  }
  else
  {
    v38 = floatsOut + 2;
    while ( v30 < v11 )
    {
      if ( floatWeightsInOut[v37] )
      {
        ++v36;
        ++v30;
        *(v36 - 1) = *(v38 - 2);
      }
      if ( v30 >= v11 )
        break;
      if ( floatWeightsInOut[v37 + 1] )
      {
        ++v36;
        ++v30;
        *(v36 - 1) = *(v38 - 1);
      }
      if ( v30 >= v11 )
        break;
      if ( floatWeightsInOut[v37 + 2] )
      {
        ++v36;
        ++v30;
        *(v36 - 1) = *v38;
      }
      if ( v30 >= v11 )
        break;
      if ( floatWeightsInOut[v37 + 3] )
      {
        ++v36;
        ++v30;
        *(v36 - 1) = v38[1];
      }
      v37 += 4i64;
      v38 += 4;
      if ( v37 >= numFloats - 3 )
        goto LABEL_38;
    }
  }
  v39 = (((numFloats + 15) & 0xFFFFFFF0) + 127) & 0xFFFFFF80;
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
  v45 = (4 * ((numFloats + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
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
void __fastcall hkaPredictiveCompressedAnimation::sampleTracks(hkaPredictiveCompressedAnimation *this, float time, hkQsTransformf *transformTracksOut, float *floatTracksOut)
{
  hkaSkeleton *v4; // rdx
  int numBones; // er12
  int v6; // edi
  float *v7; // rbx
  hkQsTransformf *v8; // rsi
  hkLifoAllocator *v9; // rax
  hkQsTransformf *bonesOut; // r13
  int v11; // er15
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
  float v26; // ST60_4
  signed int v27; // eax
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  unsigned int v31; // eax
  __m128i v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  unsigned int v36; // edx
  float v37; // xmm6_4
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  signed __int64 v40; // rcx
  signed __int64 v41; // r8
  hkVector4f *v42; // rdx
  hkQsTransformf *v43; // rax
  float *v44; // rdx
  hkLifoAllocator *v45; // rax
  int v46; // er8
  hkLifoAllocator *v47; // rax
  int v48; // er8
  hkLifoAllocator *v49; // rax
  int v50; // er8
  hkLifoAllocator *v51; // rax
  int v52; // er8
  int v53; // [rsp+68h] [rbp-60h]
  signed int v54; // [rsp+6Ch] [rbp-5Ch]
  signed int v55; // [rsp+70h] [rbp-58h]
  hkaPredictiveCompressedAnimation *v56; // [rsp+D0h] [rbp+8h]
  int n; // [rsp+D8h] [rbp+10h]

  v56 = this;
  v4 = this->m_skeleton;
  numBones = v4->m_referencePose.m_size;
  v6 = v4->m_referenceFloats.m_size;
  v7 = floatTracksOut;
  v8 = transformTracksOut;
  if ( this->m_numBones < numBones )
    numBones = this->m_numBones;
  if ( this->m_numFloatSlots < v6 )
    v6 = this->m_numFloatSlots;
  n = v6;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  bonesOut = (hkQsTransformf *)v9->m_cur;
  v11 = (48 * numBones + 127) & 0xFFFFFF80;
  v12 = (char *)bonesOut + v11;
  if ( v11 > v9->m_slabSize || v12 > v9->m_end )
    bonesOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
  else
    v9->m_cur = v12;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  floatsOut = (float *)v13->m_cur;
  v15 = (4 * v6 + 127) & 0xFFFFFF80;
  v55 = (4 * v6 + 127) & 0xFFFFFF80;
  v16 = (char *)floatsOut + v15;
  if ( v15 > v13->m_slabSize || v16 > v13->m_end )
    floatsOut = (float *)hkLifoAllocator::allocateFromNewSlab(v13, v15);
  else
    v13->m_cur = v16;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  boneWeightsInOut = (char *)v17->m_cur;
  v19 = (numBones + 127) & 0xFFFFFF80;
  v54 = (numBones + 127) & 0xFFFFFF80;
  v20 = &boneWeightsInOut[v19];
  if ( v19 > v17->m_slabSize || v20 > v17->m_end )
    boneWeightsInOut = (char *)hkLifoAllocator::allocateFromNewSlab(v17, v19);
  else
    v17->m_cur = v20;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = v6 + 127;
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
  v26 = time;
  v27 = (unsigned __int64)((__int64 (*)(void))v56->vfptr[4].__vecDelDtor)() - 1;
  v28 = 0i64;
  v29 = _mm_shuffle_ps((__m128)LODWORD(v56->m_duration), (__m128)LODWORD(v56->m_duration), 0);
  v30 = _mm_rcp_ps(v29);
  v28.m128_f32[0] = (float)v27;
  v31 = v27 - 1;
  v32 = (__m128i)_mm_and_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(v28, v28, 0),
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v30)), v30),
                       _mm_shuffle_ps((__m128)LODWORD(v26), (__m128)LODWORD(v26), 0))),
                   _mm_cmpltps((__m128)0i64, v29));
  v33 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v32, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v34 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v32, 1u), 1u));
  v35 = _mm_or_ps(
          _mm_andnot_ps(v34, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v32, v33)), v33)),
          _mm_and_ps((__m128)v32, v34));
  v36 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v35));
  if ( v36 <= v31 )
  {
    v38 = _mm_sub_ps((__m128)v32, v35);
    v39 = _mm_cmpltps(v38, query.m_quad);
    v37 = fmax(
            0.0,
            COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(v39, query.m_quad) | v38.m128_i32[0] & v39.m128_i32[0]));
  }
  else
  {
    v37 = *(float *)&FLOAT_1_0;
    v36 = v31;
  }
  hkaPredictiveCompressedAnimation::sampleFullPose(
    v56,
    v36,
    v37,
    0i64,
    v56->m_skeleton->m_referencePose.m_data,
    v56->m_skeleton->m_referenceFloats.m_data,
    numBones,
    n,
    bonesOut,
    floatsOut,
    boneWeightsInOut,
    floatWeightsInOut);
  v40 = 0i64;
  v41 = 0i64;
  if ( numBones > 0 )
  {
    v42 = &bonesOut->m_scale;
    do
    {
      if ( boneWeightsInOut[v41] )
      {
        v43 = v8;
        ++v8;
        v43->m_translation = (hkVector4f)v42[-2].m_quad;
        v43->m_rotation.m_vec = (hkVector4f)v42[-1].m_quad;
        v43->m_scale = (hkVector4f)v42->m_quad;
      }
      ++v41;
      v42 += 3;
    }
    while ( v41 < numBones );
  }
  if ( n >= 4i64 )
  {
    v44 = floatsOut + 2;
    do
    {
      if ( floatWeightsInOut[v40] )
      {
        ++v7;
        *(v7 - 1) = *(v44 - 2);
      }
      if ( floatWeightsInOut[v40 + 1] )
      {
        ++v7;
        *(v7 - 1) = *(v44 - 1);
      }
      if ( floatWeightsInOut[v40 + 2] )
      {
        ++v7;
        *(v7 - 1) = *v44;
      }
      if ( floatWeightsInOut[v40 + 3] )
      {
        ++v7;
        *(v7 - 1) = v44[1];
      }
      v40 += 4i64;
      v44 += 4;
    }
    while ( v40 < n - 3i64 );
  }
  for ( ; v40 < n; ++v40 )
  {
    if ( floatWeightsInOut[v40] )
    {
      ++v7;
      *(v7 - 1) = floatsOut[v40];
    }
  }
  v45 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v46 = (v53 + 15) & 0xFFFFFFF0;
  if ( v53 > v45->m_slabSize || &floatWeightsInOut[v46] != v45->m_cur || v45->m_firstNonLifoEnd == floatWeightsInOut )
    hkLifoAllocator::slowBlockFree(v45, floatWeightsInOut, v46);
  else
    v45->m_cur = floatWeightsInOut;
  v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v48 = (v54 + 15) & 0xFFFFFFF0;
  if ( v54 > v47->m_slabSize || &boneWeightsInOut[v48] != v47->m_cur || v47->m_firstNonLifoEnd == boneWeightsInOut )
    hkLifoAllocator::slowBlockFree(v47, boneWeightsInOut, v48);
  else
    v47->m_cur = boneWeightsInOut;
  v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v50 = (v55 + 15) & 0xFFFFFFF0;
  if ( v55 > v49->m_slabSize || (char *)floatsOut + v50 != v49->m_cur || v49->m_firstNonLifoEnd == floatsOut )
    hkLifoAllocator::slowBlockFree(v49, floatsOut, v50);
  else
    v49->m_cur = floatsOut;
  v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v52 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v51->m_slabSize || (char *)bonesOut + v52 != v51->m_cur || v51->m_firstNonLifoEnd == bonesOut )
    hkLifoAllocator::slowBlockFree(v51, bonesOut, v52);
  else
    v51->m_cur = bonesOut;
}

// File Line: 1019
// RVA: 0xB2F670
void __fastcall hkaPredictiveCompressedAnimation::sampleIndividualFloatTracks(hkaPredictiveCompressedAnimation *this, float time, const __int16 *tracks, unsigned int numTracks)
{
  ;
}

// File Line: 1023
// RVA: 0xB2F660
void __fastcall hkaPredictiveCompressedAnimation::sampleIndividualTransformTracks(hkaPredictiveCompressedAnimation *this, float time, const __int16 *tracks, unsigned int numTracks)
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
void __fastcall hkaPredictiveCompressedAnimation::sampleFullPose(hkaPredictiveCompressedAnimation *this, hkQsTransformf *bonesOut, float *floatsOut, float time)
{
  float *v4; // rdi
  hkQsTransformf *v5; // rsi
  hkaPredictiveCompressedAnimation *v6; // rbx
  signed int v7; // eax
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  unsigned int v10; // eax
  __m128 v11; // xmm1
  __m128i v12; // xmm5
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  unsigned int v16; // edx
  float v17; // xmm6_4
  __m128 v18; // xmm5
  __m128 v19; // xmm1
  float v20; // [rsp+98h] [rbp+20h]

  v20 = time;
  v4 = floatsOut;
  v5 = bonesOut;
  v6 = this;
  v7 = (unsigned __int64)((__int64 (*)(void))this->vfptr[4].__vecDelDtor)() - 1;
  v8 = 0i64;
  v9 = _mm_shuffle_ps((__m128)LODWORD(v6->m_duration), (__m128)LODWORD(v6->m_duration), 0);
  v8.m128_f32[0] = (float)v7;
  v10 = v7 - 1;
  v11 = _mm_rcp_ps(v9);
  v12 = (__m128i)_mm_and_ps(
                   _mm_cmpltps((__m128)0i64, v9),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v11)), v11),
                       _mm_shuffle_ps((__m128)LODWORD(v20), (__m128)LODWORD(v20), 0)),
                     _mm_shuffle_ps(v8, v8, 0)));
  v13 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v12, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v14 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v12, 1u), 1u));
  v15 = _mm_or_ps(
          _mm_andnot_ps(v14, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v12, v13)), v13)),
          _mm_and_ps(v14, (__m128)v12));
  v16 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v15));
  if ( v16 <= v10 )
  {
    v18 = _mm_sub_ps((__m128)v12, v15);
    v19 = _mm_cmpltps(v18, query.m_quad);
    v17 = fmax(
            0.0,
            COERCE_FLOAT(v18.m128_i32[0] & v19.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v19, query.m_quad)));
  }
  else
  {
    v17 = *(float *)&FLOAT_1_0;
    v16 = v10;
  }
  hkaPredictiveCompressedAnimation::sampleFullPose(
    v6,
    v16,
    v17,
    0i64,
    v6->m_skeleton->m_referencePose.m_data,
    v6->m_skeleton->m_referenceFloats.m_data,
    v6->m_numBones,
    v6->m_numFloatSlots,
    v5,
    v4,
    0i64,
    0i64);
}

// File Line: 1046
// RVA: 0xB32200
signed __int64 __fastcall hkaPredictiveCompressedAnimation::getSizeInBytes(hkaPredictiveCompressedAnimation *this)
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
void __fastcall hkaPredictiveCompressedAnimation::setSkeleton(hkaPredictiveCompressedAnimation *this, hkaSkeleton *skeleton)
{
  this->m_skeleton = skeleton;
}

