// File Line: 151
// RVA: 0xA9BB20
__int64 __fastcall Bypass_I16_2ChanSSE2(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  __int64 uOutFrameOffset; // r10
  unsigned int uValidFrames; // r12d
  unsigned int v8; // esi
  const __m128i *v9; // r8
  unsigned int v10; // ebx
  __m128 *v12; // r9
  __int64 v13; // rcx
  __int64 uMaxFrames; // r13
  unsigned int v15; // r10d
  const __m128i *v16; // rdi
  unsigned int v17; // edx
  signed __int64 v18; // rbp
  __int64 v19; // rcx
  __int64 v20; // r10
  __m128i v21; // xmm1
  __m128 v22; // xmm0
  __m128i v23; // xmm1
  __m128 v24; // xmm0
  __m128i v25; // xmm1
  __m128 v26; // xmm0
  __m128i v27; // xmm1
  unsigned int v28; // eax
  __m128i v29; // xmm0
  int v30; // eax
  __int64 v32; // [rsp+0h] [rbp-48h]
  char *v33; // [rsp+50h] [rbp+8h]
  __int64 v34; // [rsp+58h] [rbp+10h]

  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uValidFrames = io_pInBuffer->uValidFrames;
  v8 = uRequestedSize - uOutFrameOffset;
  v9 = (const __m128i *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v10 = uValidFrames;
  if ( v8 < uValidFrames )
    v10 = v8;
  v12 = (__m128 *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  v13 = (int)(v10 - 1);
  io_pPitchState->iLastValue[0] = v9->m128i_i16[2 * v13];
  io_pPitchState->iLastValue[1] = v9->m128i_i16[2 * v13 + 1];
  uMaxFrames = io_pOutBuffer->uMaxFrames;
  v15 = (unsigned int)uMaxFrames >> 2;
  v16 = &v9[4 * (v10 >> 4)];
  v17 = v10 - 16 * (v10 >> 4);
  if ( v9 < v16 )
  {
    v18 = (char *)v12 - (char *)v9;
    v33 = (char *)&v12[-1] + 16i64 * v15 - (_QWORD)v9;
    v34 = (__int64)&v12[-1] + 16i64 * (v15 + 1) - (_QWORD)v9;
    v19 = 16i64 * (v15 + 3);
    v20 = (__int64)&v12[-1] + 16i64 * (v15 + 2) - (_QWORD)v9;
    v32 = (__int64)&v12[-1] + v19 - (_QWORD)v9;
    do
    {
      v21 = _mm_loadu_si128(v9);
      v9 += 4;
      v12 += 4;
      v12[-4] = _mm_mul_ps(_mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(v21, 0x10u), 0x10u)), (__m128)_xmm);
      v22 = _mm_cvtepi32_ps(_mm_srai_epi32(v21, 0x10u));
      v23 = _mm_loadu_si128(v9 - 3);
      *(__m128 *)((char *)&v9[-3] + (_QWORD)v33) = _mm_mul_ps(v22, (__m128)_xmm);
      *(__m128 *)((char *)&v9[-3] + v18) = _mm_mul_ps(
                                             _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(v23, 0x10u), 0x10u)),
                                             (__m128)_xmm);
      v24 = _mm_cvtepi32_ps(_mm_srai_epi32(v23, 0x10u));
      v25 = _mm_loadu_si128(v9 - 2);
      *(__m128 *)((char *)&v9[-3] + v34) = _mm_mul_ps(v24, (__m128)_xmm);
      *(__m128 *)((char *)&v9[-2] + v18) = _mm_mul_ps(
                                             _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(v25, 0x10u), 0x10u)),
                                             (__m128)_xmm);
      v26 = _mm_cvtepi32_ps(_mm_srai_epi32(v25, 0x10u));
      v27 = _mm_loadu_si128(v9 - 1);
      *(__m128 *)((char *)&v9[-3] + v20) = _mm_mul_ps(v26, (__m128)_xmm);
      *(__m128 *)((char *)&v9[-1] + v18) = _mm_mul_ps(
                                             _mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(v27, 0x10u), 0x10u)),
                                             (__m128)_xmm);
      *(__m128 *)((char *)&v9[-3] + v32) = _mm_mul_ps(_mm_cvtepi32_ps(_mm_srai_epi32(v27, 0x10u)), (__m128)_xmm);
    }
    while ( v9 < v16 );
    uMaxFrames = io_pOutBuffer->uMaxFrames;
  }
  for ( ; v17; --v17 )
  {
    v28 = v9->m128i_i16[0];
    v12 = (__m128 *)((char *)v12 + 4);
    v9 = (const __m128i *)((char *)v9 + 4);
    v29 = _mm_cvtsi32_si128(v28);
    v30 = v9[-1].m128i_i16[7];
    v12[-1].m128_f32[3] = _mm_cvtepi32_ps(v29).m128_f32[0] * 0.000030517578;
    v12->m128_f32[uMaxFrames - 1] = (float)v30 * 0.000030517578;
  }
  io_pInBuffer->uValidFrames -= v10;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v10;
  io_pPitchState->uFloatIndex = 0x10000;
  if ( v10 == uValidFrames )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v10;
  if ( v10 == v8 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v10;
  return 43i64;
}

// File Line: 316
// RVA: 0xA9BDE0
__int64 __fastcall Bypass_I16_NChanVecSSE2(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uValidFrames; // ebp
  unsigned int uOutFrameOffset; // r8d
  unsigned int v7; // esi
  unsigned int uChannelMask; // edx
  unsigned int v10; // edi
  unsigned int i; // r10d
  const __m128i *v14; // rdx
  __m128 *v15; // r9
  unsigned int v16; // eax
  const __m128i *v17; // rcx
  int j; // r8d
  __m128i v19; // xmm3
  __m128i v20; // xmm5
  __m128i v21; // xmm1
  __m128i v22; // xmm4
  int v23; // eax
  char *v24; // rdx

  uValidFrames = io_pInBuffer->uValidFrames;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  v7 = uRequestedSize - uOutFrameOffset;
  uChannelMask = io_pInBuffer->uChannelMask;
  v10 = uValidFrames;
  if ( v7 < uValidFrames )
    v10 = v7;
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  v14 = (const __m128i *)((char *)io_pInBuffer->pData + 2 * i * io_pPitchState->uInFrameOffset);
  v15 = (__m128 *)((char *)io_pOutBuffer->pData + 4 * i * uOutFrameOffset);
  v16 = (v10 * i) >> 4;
  v17 = &v14[2 * v16];
  for ( j = v10 * i - 16 * v16; v14 < v17; v15[-1] = _mm_mul_ps(
                                                       _mm_cvtepi32_ps(_mm_unpackhi_epi16(v20, v22)),
                                                       (__m128)_xmm) )
  {
    v19 = _mm_loadu_si128(v14);
    v20 = _mm_loadu_si128(v14 + 1);
    v14 += 2;
    v15 += 4;
    v21 = _mm_cmpgt_epi16((__m128i)0i64, v19);
    v22 = _mm_cmpgt_epi16((__m128i)0i64, v20);
    v15[-4] = _mm_mul_ps(_mm_cvtepi32_ps(_mm_unpacklo_epi16(v19, v21)), (__m128)_xmm);
    v15[-3] = _mm_mul_ps(_mm_cvtepi32_ps(_mm_unpackhi_epi16(v19, v21)), (__m128)_xmm);
    v15[-2] = _mm_mul_ps(_mm_cvtepi32_ps(_mm_unpacklo_epi16(v20, v22)), (__m128)_xmm);
  }
  for ( ; j; --j )
  {
    v23 = v14->m128i_i16[0];
    v14 = (const __m128i *)((char *)v14 + 2);
    v15 = (__m128 *)((char *)v15 + 4);
    v15[-1].m128_f32[3] = (float)v23 * 0.000030517578;
  }
  v24 = &v14->m128i_i8[-2 * i];
  if ( i )
    memmove(io_pPitchState, v24, 2i64 * i);
  io_pInBuffer->uValidFrames -= v10;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v10;
  io_pPitchState->uFloatIndex = 0x10000;
  if ( v10 == uValidFrames )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v10;
  if ( v10 == v7 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v10;
  return 43i64;
}

// File Line: 586
// RVA: 0xA9BFA0
__int64 __fastcall Fixed_I16_1Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uCurrentFrameSkip; // esi
  unsigned int uFloatIndex; // r11d
  __int64 uOutFrameOffset; // r10
  unsigned int uValidFrames; // ebp
  unsigned int v9; // r12d
  __int64 v10; // r9
  int v11; // edi
  __int16 *v12; // r14
  unsigned int v13; // r13d
  float *v14; // r8
  unsigned int v15; // ecx
  int v16; // edx
  int v17; // r10d
  int v18; // edx
  int v19; // eax
  unsigned int v20; // r15d
  unsigned int i; // r10d
  int v22; // edx
  int v23; // eax
  int v24; // eax
  __int64 v25; // rdx
  unsigned int v26; // ecx

  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uValidFrames = io_pInBuffer->uValidFrames;
  v9 = uRequestedSize - uOutFrameOffset;
  v10 = HIWORD(uFloatIndex);
  v11 = (unsigned __int16)uFloatIndex;
  v12 = (__int16 *)((char *)io_pInBuffer->pData + 2 * io_pPitchState->uInFrameOffset);
  v13 = (uCurrentFrameSkip - uFloatIndex + 0xFFFF) / uCurrentFrameSkip;
  v14 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  if ( v9 < v13 )
    v13 = v9;
  v15 = v13;
  if ( v13 )
  {
    v16 = io_pPitchState->iLastValue[0];
    v17 = *v12 - v16;
    v18 = v16 << 16;
    do
    {
      uFloatIndex += uCurrentFrameSkip;
      ++v14;
      v19 = v18 + v11 * v17;
      v10 = HIWORD(uFloatIndex);
      v11 = (unsigned __int16)uFloatIndex;
      *(v14 - 1) = (float)v19 * 4.6566129e-10;
      --v15;
    }
    while ( v15 );
  }
  v20 = (uCurrentFrameSkip + (uValidFrames << 16) - uFloatIndex - 1) / uCurrentFrameSkip;
  if ( v9 - v13 < v20 )
    v20 = v9 - v13;
  for ( i = v20; i; --i )
  {
    v22 = v12[v10 - 1];
    uFloatIndex += uCurrentFrameSkip;
    ++v14;
    v23 = v12[(unsigned int)(v10 + 1) - 1] - v22;
    v10 = HIWORD(uFloatIndex);
    v24 = v11 * v23;
    v11 = (unsigned __int16)uFloatIndex;
    *(v14 - 1) = (float)((v22 << 16) + v24) * 4.6566129e-10;
  }
  v25 = uValidFrames;
  if ( (unsigned int)v10 < uValidFrames )
    v25 = (unsigned int)v10;
  if ( (_DWORD)v25 )
    io_pPitchState->iLastValue[0] = v12[v25 - 1];
  v26 = v20 + v13;
  io_pPitchState->uFloatIndex = uFloatIndex - ((_DWORD)v25 << 16);
  io_pInBuffer->uValidFrames -= v25;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v20 + v13;
  if ( (_DWORD)v25 == uValidFrames )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v25;
  if ( v26 == v9 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v26;
  return 43i64;
}

// File Line: 628
// RVA: 0xA9C150
__int64 __fastcall Fixed_I16_2Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uCurrentFrameSkip; // ebp
  unsigned int uFloatIndex; // r11d
  unsigned int uValidFrames; // r13d
  __int64 uOutFrameOffset; // r10
  __int64 uMaxFrames; // r12
  unsigned int v10; // r8d
  AkInternalPitchState *v11; // rbx
  unsigned int uInFrameOffset; // ecx
  unsigned int v13; // r9d
  int v14; // esi
  unsigned int v15; // eax
  __int16 *v16; // r14
  float *v17; // rdi
  unsigned int v18; // ecx
  int v19; // edx
  int v20; // r8d
  int v21; // r10d
  int v22; // edx
  int v23; // r15d
  int v24; // r8d
  __m128i v25; // xmm0
  int v26; // eax
  unsigned int v27; // r10d
  unsigned int v28; // r15d
  unsigned int v29; // r12d
  __int64 v30; // rbx
  __int64 v31; // r10
  int v32; // edx
  float v33; // xmm0_4
  int v34; // eax
  unsigned int v35; // r8d
  __int64 v36; // rdx
  __int16 v37; // ax
  unsigned int v38; // ecx
  unsigned int v40; // [rsp+0h] [rbp-58h]
  unsigned int v43; // [rsp+70h] [rbp+18h]

  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uValidFrames = io_pInBuffer->uValidFrames;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uMaxFrames = io_pOutBuffer->uMaxFrames;
  v10 = uRequestedSize - uOutFrameOffset;
  v11 = io_pPitchState;
  uInFrameOffset = io_pPitchState->uInFrameOffset;
  v13 = HIWORD(uFloatIndex);
  v40 = v10;
  v14 = (unsigned __int16)uFloatIndex;
  v15 = (uCurrentFrameSkip - uFloatIndex + 0xFFFF) / uCurrentFrameSkip;
  v16 = (__int16 *)((char *)io_pInBuffer->pData + 4 * uInFrameOffset);
  if ( v10 < v15 )
    v15 = v10;
  v17 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  v18 = v15;
  v43 = v15;
  if ( v15 )
  {
    v19 = v11->iLastValue[0];
    v20 = v11->iLastValue[1];
    v21 = *v16 - v19;
    v22 = v19 << 16;
    v23 = v16[1] - v20;
    v24 = v20 << 16;
    do
    {
      uFloatIndex += uCurrentFrameSkip;
      ++v17;
      v13 = HIWORD(uFloatIndex);
      v25 = _mm_cvtsi32_si128(v22 + v14 * v21);
      v26 = v14 * v23;
      v14 = (unsigned __int16)uFloatIndex;
      *(v17 - 1) = _mm_cvtepi32_ps(v25).m128_f32[0] * 4.6566129e-10;
      v17[uMaxFrames - 1] = (float)(v24 + v26) * 4.6566129e-10;
      --v18;
    }
    while ( v18 );
    v10 = v40;
  }
  v27 = v43;
  v28 = (uCurrentFrameSkip + (uValidFrames << 16) - uFloatIndex - 1) / uCurrentFrameSkip;
  if ( v10 - v43 < v28 )
    v28 = v10 - v43;
  v29 = v28;
  if ( v28 )
  {
    v30 = io_pOutBuffer->uMaxFrames;
    do
    {
      v31 = 2 * v13;
      uFloatIndex += uCurrentFrameSkip;
      ++v17;
      v32 = v16[(unsigned int)(v31 + 1) - 2] << 16;
      v13 = HIWORD(uFloatIndex);
      v33 = (float)((v16[v31 - 2] << 16) + v14 * (v16[(unsigned int)(v31 + 2) - 2] - v16[v31 - 2]));
      v34 = v14 * (v16[(unsigned int)(v31 + 3) - 2] - v16[(unsigned int)(v31 + 1) - 2]);
      v14 = (unsigned __int16)uFloatIndex;
      *(v17 - 1) = v33 * 4.6566129e-10;
      v17[v30 - 1] = (float)(v32 + v34) * 4.6566129e-10;
      --v29;
    }
    while ( v29 );
    v11 = io_pPitchState;
    v27 = v43;
  }
  v35 = uValidFrames;
  if ( v13 < uValidFrames )
    v35 = v13;
  if ( v35 )
  {
    v36 = 2 * v35;
    v37 = v16[(unsigned int)(v36 + 1) - 2];
    v11->iLastValue[0] = v16[v36 - 2];
    v11->iLastValue[1] = v37;
  }
  v38 = v28 + v27;
  v11->uFloatIndex = uFloatIndex - (v35 << 16);
  io_pInBuffer->uValidFrames -= v35;
  io_pOutBuffer->uValidFrames = LOWORD(v11->uOutFrameOffset) + v28 + v27;
  if ( v35 == uValidFrames )
    v11->uInFrameOffset = 0;
  else
    v11->uInFrameOffset += v35;
  if ( v38 == v40 )
    return 45i64;
  v11->uOutFrameOffset += v38;
  return 43i64;
}

// File Line: 681
// RVA: 0xA9C3B0
__int64 __fastcall Fixed_Native_1Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uCurrentFrameSkip; // esi
  unsigned int uFloatIndex; // r11d
  __int64 uOutFrameOffset; // r10
  unsigned int uValidFrames; // ebp
  unsigned int v10; // r15d
  float v11; // xmm2_4
  int v12; // edi
  __int64 v13; // r9
  float *v14; // r14
  unsigned int v15; // r12d
  float *v16; // r8
  unsigned int v17; // ecx
  float v18; // xmm1_4
  int v19; // eax
  unsigned int v20; // r10d
  unsigned int i; // edx
  int v22; // eax
  float v23; // xmm1_4
  __int64 v24; // rdx
  unsigned int v25; // ecx

  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uValidFrames = io_pInBuffer->uValidFrames;
  v10 = uRequestedSize - uOutFrameOffset;
  v11 = io_pPitchState->fLastValue[0];
  v12 = (unsigned __int16)uFloatIndex;
  v13 = HIWORD(uFloatIndex);
  v14 = (float *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v15 = (uCurrentFrameSkip - uFloatIndex + 0xFFFF) / uCurrentFrameSkip;
  v16 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  if ( v10 < v15 )
    v15 = v10;
  v17 = v15;
  if ( v15 )
  {
    v18 = *v14 - v11;
    do
    {
      v19 = v12;
      uFloatIndex += uCurrentFrameSkip;
      ++v16;
      v12 = (unsigned __int16)uFloatIndex;
      v13 = HIWORD(uFloatIndex);
      *(v16 - 1) = (float)((float)((float)v19 * 0.000015258789) * v18) + v11;
      --v17;
    }
    while ( v17 );
  }
  v20 = (uCurrentFrameSkip + (uValidFrames << 16) - uFloatIndex - 1) / uCurrentFrameSkip;
  if ( v10 - v15 < v20 )
    v20 = v10 - v15;
  for ( i = v20; i; --i )
  {
    uFloatIndex += uCurrentFrameSkip;
    ++v16;
    v22 = v12;
    v12 = (unsigned __int16)uFloatIndex;
    v23 = (float)((float)(v14[(unsigned int)(v13 + 1) - 1] - v14[v13 - 1]) * (float)((float)v22 * 0.000015258789))
        + v14[v13 - 1];
    v13 = HIWORD(uFloatIndex);
    *(v16 - 1) = v23;
  }
  v24 = uValidFrames;
  if ( (unsigned int)v13 < uValidFrames )
    v24 = (unsigned int)v13;
  if ( (_DWORD)v24 )
    io_pPitchState->fLastValue[0] = v14[v24 - 1];
  v25 = v20 + v15;
  io_pPitchState->uFloatIndex = uFloatIndex - ((_DWORD)v24 << 16);
  io_pInBuffer->uValidFrames -= v24;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v20 + v15;
  if ( (_DWORD)v24 == uValidFrames )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v24;
  if ( v25 == v10 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v25;
  return 43i64;
}

// File Line: 722
// RVA: 0xA9C560
__int64 __fastcall Fixed_Native_2Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uFloatIndex; // r11d
  unsigned int uCurrentFrameSkip; // esi
  unsigned int uValidFrames; // r12d
  float v7; // xmm5_4
  float v8; // xmm6_4
  __int64 uOutFrameOffset; // r10
  unsigned int v10; // r13d
  __int64 uMaxFrames; // r14
  __int64 v12; // rbx
  int v13; // ebp
  float *v14; // rdi
  unsigned int v15; // r15d
  float *v16; // r8
  unsigned int v17; // edx
  float v18; // xmm3_4
  float v19; // xmm4_4
  int v20; // eax
  float v21; // xmm2_4
  unsigned int v22; // r10d
  unsigned int i; // r15d
  int v24; // eax
  __int64 v25; // rdx
  float v26; // xmm2_4
  float v27; // xmm0_4
  __int64 v28; // rdx
  float v29; // eax
  unsigned int v30; // ecx
  unsigned int v34; // [rsp+88h] [rbp+20h]

  uFloatIndex = io_pPitchState->uFloatIndex;
  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  uValidFrames = io_pInBuffer->uValidFrames;
  v7 = io_pPitchState->fLastValue[0];
  v8 = io_pPitchState->fLastValue[1];
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  v10 = uRequestedSize - uOutFrameOffset;
  uMaxFrames = io_pOutBuffer->uMaxFrames;
  v12 = HIWORD(uFloatIndex);
  v13 = (unsigned __int16)uFloatIndex;
  v14 = (float *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v15 = (uCurrentFrameSkip - uFloatIndex + 0xFFFF) / uCurrentFrameSkip;
  v16 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  if ( v10 < v15 )
    v15 = v10;
  v34 = v15;
  v17 = v15;
  if ( v15 )
  {
    v18 = *v14 - v7;
    v19 = v14[(unsigned int)(uMaxFrames + 1) - 1] - v8;
    do
    {
      v20 = v13;
      uFloatIndex += uCurrentFrameSkip;
      ++v16;
      v12 = HIWORD(uFloatIndex);
      v13 = (unsigned __int16)uFloatIndex;
      v21 = (float)v20 * 0.000015258789;
      *(v16 - 1) = (float)(v21 * v18) + v7;
      v16[uMaxFrames - 1] = (float)(v19 * v21) + v8;
      --v17;
    }
    while ( v17 );
  }
  v22 = (uCurrentFrameSkip + (uValidFrames << 16) - uFloatIndex - 1) / uCurrentFrameSkip;
  if ( v10 - v15 < v22 )
    v22 = v10 - v15;
  for ( i = v22; i; --i )
  {
    v24 = v13;
    v25 = (unsigned int)(uMaxFrames + v12);
    uFloatIndex += uCurrentFrameSkip;
    ++v16;
    v13 = (unsigned __int16)uFloatIndex;
    v26 = (float)v24 * 0.000015258789;
    v27 = (float)((float)(v14[(unsigned int)(v12 + 1) - 1] - v14[v12 - 1]) * v26) + v14[v12 - 1];
    v12 = HIWORD(uFloatIndex);
    *(v16 - 1) = v27;
    v16[uMaxFrames - 1] = (float)((float)(v14[(unsigned int)(v25 + 1) - 1] - v14[v25 - 1]) * v26) + v14[v25 - 1];
  }
  v28 = uValidFrames;
  if ( (unsigned int)v12 < uValidFrames )
    v28 = (unsigned int)v12;
  if ( (_DWORD)v28 )
  {
    v29 = v14[(unsigned int)(v28 + uMaxFrames) - 1];
    io_pPitchState->fLastValue[0] = v14[v28 - 1];
    io_pPitchState->fLastValue[1] = v29;
  }
  v30 = v22 + v34;
  io_pPitchState->uFloatIndex = uFloatIndex - ((_DWORD)v28 << 16);
  io_pInBuffer->uValidFrames -= v28;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v22 + v34;
  if ( (_DWORD)v28 == uValidFrames )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v28;
  if ( v30 == v10 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v30;
  return 43i64;
}

// File Line: 775
// RVA: 0xA9C780
__int64 __fastcall Interpolating_I16_1Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  __int64 uOutFrameOffset; // r10
  unsigned int uInterpolationRampInc; // r12d
  unsigned int uFloatIndex; // ebx
  unsigned int uTargetFrameSkip; // edi
  __int64 v9; // r9
  __int16 *v10; // r15
  unsigned int uCurrentFrameSkip; // ecx
  float *v12; // r8
  unsigned int uInterpolationRampCount; // r10d
  unsigned int v14; // edi
  unsigned int v15; // ecx
  char *v16; // r9
  __int64 v17; // r11
  int v18; // r14d
  __int64 v19; // rbp
  unsigned int v20; // edx
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // ecx
  __int64 v24; // r9
  unsigned int v25; // r13d
  int v26; // ebp
  unsigned int v27; // edi
  int v28; // eax
  int v29; // edx
  __m128i v30; // xmm0
  __int64 v31; // rdx
  __int64 v32; // r8
  int v34; // [rsp+0h] [rbp-58h]
  float *v35; // [rsp+8h] [rbp-50h]
  unsigned int uValidFrames; // [rsp+70h] [rbp+18h]
  unsigned int v39; // [rsp+78h] [rbp+20h]

  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uInterpolationRampInc = io_pPitchState->uInterpolationRampInc;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uTargetFrameSkip = io_pPitchState->uTargetFrameSkip;
  uValidFrames = io_pInBuffer->uValidFrames;
  v9 = uRequestedSize - (unsigned int)uOutFrameOffset;
  v10 = (__int16 *)((char *)io_pInBuffer->pData + 2 * io_pPitchState->uInFrameOffset);
  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  v12 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  uInterpolationRampCount = io_pPitchState->uInterpolationRampCount;
  v14 = uTargetFrameSkip - uCurrentFrameSkip;
  v15 = uCurrentFrameSkip << 10;
  v34 = v9;
  v16 = (char *)&v12[v9];
  v17 = HIWORD(uFloatIndex);
  v18 = (unsigned __int16)uFloatIndex;
  v35 = v12;
  v19 = (v16 - (char *)v12) >> 2;
  v39 = v15;
  if ( (unsigned int)v19 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v19) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  if ( !(_DWORD)v17 )
  {
    v20 = v15 + uInterpolationRampCount * v14;
    do
    {
      v21 = v19;
      LODWORD(v19) = v19 - 1;
      if ( !v21 )
        break;
      v20 += uInterpolationRampInc * v14;
      ++v12;
      uInterpolationRampCount += uInterpolationRampInc;
      v22 = (io_pPitchState->iLastValue[0] << 16) + v18 * (*v10 - io_pPitchState->iLastValue[0]);
      uFloatIndex += v20 >> 10;
      v18 = (unsigned __int16)uFloatIndex;
      v17 = HIWORD(uFloatIndex);
      *(v12 - 1) = (float)v22 * 4.6566129e-10;
    }
    while ( !(_DWORD)v17 );
  }
  v23 = uValidFrames;
  v24 = (v16 - (char *)v12) >> 2;
  v25 = uValidFrames - 1;
  if ( (unsigned int)v24 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v24) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  if ( (unsigned int)v17 <= v25 )
  {
    v26 = uInterpolationRampInc * v14;
    v27 = v39 + uInterpolationRampCount * v14;
    do
    {
      v28 = v24;
      LODWORD(v24) = v24 - 1;
      if ( !v28 )
        break;
      v29 = v10[v17 - 1];
      v27 += v26;
      ++v12;
      uInterpolationRampCount += uInterpolationRampInc;
      v30 = _mm_cvtsi32_si128((v29 << 16) + v18 * (v10[(unsigned int)(v17 + 1) - 1] - v29));
      uFloatIndex += v27 >> 10;
      v18 = (unsigned __int16)uFloatIndex;
      v17 = HIWORD(uFloatIndex);
      *(v12 - 1) = _mm_cvtepi32_ps(v30).m128_f32[0] * 4.6566129e-10;
    }
    while ( (unsigned int)v17 <= v25 );
  }
  v31 = uValidFrames;
  io_pPitchState->uInterpolationRampCount = uInterpolationRampCount;
  if ( (unsigned int)v17 < uValidFrames )
    v31 = (unsigned int)v17;
  if ( (_DWORD)v31 )
  {
    io_pPitchState->iLastValue[0] = v10[v31 - 1];
    v23 = uValidFrames;
  }
  v32 = v12 - v35;
  io_pPitchState->uFloatIndex = uFloatIndex - ((_DWORD)v31 << 16);
  io_pInBuffer->uValidFrames -= v31;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v32;
  if ( (_DWORD)v31 == v23 )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v31;
  if ( (_DWORD)v32 == v34 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v32;
  return 43i64;
}

// File Line: 822
// RVA: 0xA9C990
__int64 __fastcall Interpolating_I16_2Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  __int64 uOutFrameOffset; // r10
  unsigned int uFloatIndex; // edi
  AkInternalPitchState *v6; // rsi
  unsigned int uInterpolationRampCount; // ebp
  unsigned int uInterpolationRampInc; // r13d
  __int64 v9; // r8
  __int16 *v10; // r14
  unsigned int uCurrentFrameSkip; // ecx
  float *v12; // r11
  unsigned int v13; // r15d
  char *v14; // rbx
  unsigned int v15; // ecx
  unsigned int v16; // r9d
  __int64 v17; // r8
  int v18; // r12d
  unsigned int v19; // edx
  int v20; // eax
  float v21; // xmm0_4
  int v22; // ecx
  unsigned int v23; // r10d
  __int64 v24; // rbx
  unsigned int v25; // eax
  unsigned int v26; // r15d
  int v27; // esi
  int v28; // eax
  __int64 v29; // r10
  int v30; // r9d
  __m128i v31; // xmm0
  __int64 v32; // rax
  unsigned int v33; // r8d
  __int64 v34; // rdx
  __int16 v35; // ax
  __int64 v36; // r11
  __int16 v38; // [rsp+0h] [rbp-78h]
  int uMaxFrames; // [rsp+4h] [rbp-74h]
  unsigned int uValidFrames; // [rsp+8h] [rbp-70h]
  unsigned int v41; // [rsp+10h] [rbp-68h]
  int v42; // [rsp+14h] [rbp-64h]
  float *v43; // [rsp+20h] [rbp-58h]
  __int16 v46; // [rsp+90h] [rbp+18h]

  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uValidFrames = io_pInBuffer->uValidFrames;
  v6 = io_pPitchState;
  uInterpolationRampCount = io_pPitchState->uInterpolationRampCount;
  uInterpolationRampInc = io_pPitchState->uInterpolationRampInc;
  uMaxFrames = io_pOutBuffer->uMaxFrames;
  v9 = uRequestedSize - (unsigned int)uOutFrameOffset;
  v42 = v9;
  v10 = (__int16 *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  v12 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  v13 = io_pPitchState->uTargetFrameSkip - uCurrentFrameSkip;
  v46 = io_pPitchState->iLastValue[0];
  v14 = (char *)&v12[v9];
  v38 = io_pPitchState->iLastValue[1];
  v15 = uCurrentFrameSkip << 10;
  v16 = HIWORD(uFloatIndex);
  v17 = (4 * v9) >> 2;
  v18 = (unsigned __int16)uFloatIndex;
  v43 = v12;
  if ( (unsigned int)v17 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v17) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  v41 = v15;
  if ( !v16 )
  {
    v19 = v15 + uInterpolationRampCount * v13;
    do
    {
      v20 = v17;
      LODWORD(v17) = v17 - 1;
      if ( !v20 )
        break;
      v19 += uInterpolationRampInc * v13;
      ++v12;
      uInterpolationRampCount += uInterpolationRampInc;
      v21 = (float)((v46 << 16) + v18 * (*v10 - v46));
      v22 = (v38 << 16) + v18 * (v10[1] - v38);
      uFloatIndex += v19 >> 10;
      v18 = (unsigned __int16)uFloatIndex;
      v16 = HIWORD(uFloatIndex);
      *(v12 - 1) = v21 * 4.6566129e-10;
      v12[uMaxFrames - 1] = (float)v22 * 4.6566129e-10;
    }
    while ( !HIWORD(uFloatIndex) );
    v6 = io_pPitchState;
  }
  v23 = uValidFrames;
  v24 = (v14 - (char *)v12) >> 2;
  if ( (unsigned int)v24 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v24) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  if ( v16 <= uValidFrames - 1 )
  {
    v25 = v13;
    v26 = v41 + uInterpolationRampCount * v13;
    v27 = uInterpolationRampInc * v25;
    do
    {
      v28 = v24;
      LODWORD(v24) = v24 - 1;
      if ( !v28 )
        break;
      v29 = 2 * v16;
      v26 += v27;
      ++v12;
      uInterpolationRampCount += uInterpolationRampInc;
      v30 = v10[(unsigned int)(v29 + 1) - 2];
      v31 = _mm_cvtsi32_si128((v10[v29 - 2] << 16) + v18 * (v10[(unsigned int)(v29 + 2) - 2] - v10[v29 - 2]));
      v32 = (unsigned int)(v29 + 3);
      v23 = uValidFrames;
      LODWORD(v32) = (v30 << 16) + v18 * (v10[v32 - 2] - v30);
      *(v12 - 1) = _mm_cvtepi32_ps(v31).m128_f32[0] * 4.6566129e-10;
      v12[uMaxFrames - 1] = (float)(int)v32 * 4.6566129e-10;
      uFloatIndex += v26 >> 10;
      v18 = (unsigned __int16)uFloatIndex;
      v16 = HIWORD(uFloatIndex);
    }
    while ( HIWORD(uFloatIndex) <= uValidFrames - 1 );
    v6 = io_pPitchState;
  }
  v33 = v23;
  v6->uInterpolationRampCount = uInterpolationRampCount;
  if ( v16 < v23 )
    v33 = v16;
  if ( v33 )
  {
    v34 = 2 * v33;
    v35 = v10[(unsigned int)(v34 + 1) - 2];
    v6->iLastValue[0] = v10[v34 - 2];
    v6->iLastValue[1] = v35;
  }
  v36 = v12 - v43;
  v6->uFloatIndex = uFloatIndex - (v33 << 16);
  io_pInBuffer->uValidFrames -= v33;
  io_pOutBuffer->uValidFrames = LOWORD(v6->uOutFrameOffset) + v36;
  if ( v33 == v23 )
    v6->uInFrameOffset = 0;
  else
    v6->uInFrameOffset += v33;
  if ( (_DWORD)v36 == v42 )
    return 45i64;
  v6->uOutFrameOffset += v36;
  return 43i64;
}

// File Line: 880
// RVA: 0xA9CCA0
__int64 __fastcall Interpolating_Native_1Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uValidFrames; // r13d
  __int64 uOutFrameOffset; // r10
  float v7; // xmm2_4
  unsigned int uInterpolationRampInc; // r12d
  unsigned int uFloatIndex; // ebx
  float *v10; // r15
  __int64 v11; // r9
  float *v12; // r8
  unsigned int uCurrentFrameSkip; // eax
  unsigned int uInterpolationRampCount; // r10d
  unsigned int v15; // edi
  char *v16; // r9
  __int64 v17; // r11
  int v18; // r14d
  __int64 v19; // rbp
  unsigned int v20; // ecx
  int v21; // eax
  float v22; // xmm0_4
  __int64 v23; // r9
  unsigned int v24; // ebp
  int v25; // edx
  unsigned int v26; // edi
  int v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  __int64 v30; // rdx
  __int64 v31; // r8
  float *v33; // [rsp+0h] [rbp-58h]
  unsigned int v36; // [rsp+70h] [rbp+18h]
  int v37; // [rsp+78h] [rbp+20h]

  uValidFrames = io_pInBuffer->uValidFrames;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  v7 = io_pPitchState->fLastValue[0];
  uInterpolationRampInc = io_pPitchState->uInterpolationRampInc;
  uFloatIndex = io_pPitchState->uFloatIndex;
  v10 = (float *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v11 = uRequestedSize - (unsigned int)uOutFrameOffset;
  v12 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  uInterpolationRampCount = io_pPitchState->uInterpolationRampCount;
  v15 = io_pPitchState->uTargetFrameSkip - uCurrentFrameSkip;
  v36 = uCurrentFrameSkip << 10;
  v37 = v11;
  v16 = (char *)&v12[v11];
  v17 = HIWORD(uFloatIndex);
  v18 = (unsigned __int16)uFloatIndex;
  v33 = v12;
  v19 = (v16 - (char *)v12) >> 2;
  if ( (unsigned int)v19 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v19) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  if ( !(_DWORD)v17 )
  {
    v20 = v36 + uInterpolationRampCount * v15;
    do
    {
      v21 = v19;
      LODWORD(v19) = v19 - 1;
      if ( !v21 )
        break;
      v22 = (float)v18;
      v20 += uInterpolationRampInc * v15;
      ++v12;
      uInterpolationRampCount += uInterpolationRampInc;
      uFloatIndex += v20 >> 10;
      v18 = (unsigned __int16)uFloatIndex;
      v17 = HIWORD(uFloatIndex);
      *(v12 - 1) = (float)((float)(*v10 - v7) * (float)(v22 * 0.000015258789)) + v7;
    }
    while ( !(_DWORD)v17 );
  }
  v23 = (v16 - (char *)v12) >> 2;
  v24 = uValidFrames - 1;
  if ( (unsigned int)v23 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v23) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  if ( (unsigned int)v17 <= v24 )
  {
    v25 = uInterpolationRampInc * v15;
    v26 = v36 + uInterpolationRampCount * v15;
    do
    {
      v27 = v23;
      LODWORD(v23) = v23 - 1;
      if ( !v27 )
        break;
      v26 += v25;
      ++v12;
      uInterpolationRampCount += uInterpolationRampInc;
      v28 = (float)v18;
      uFloatIndex += v26 >> 10;
      v18 = (unsigned __int16)uFloatIndex;
      v29 = (float)((float)(v10[(unsigned int)(v17 + 1) - 1] - v10[v17 - 1]) * (float)(v28 * 0.000015258789))
          + v10[v17 - 1];
      v17 = HIWORD(uFloatIndex);
      *(v12 - 1) = v29;
    }
    while ( (unsigned int)v17 <= v24 );
  }
  v30 = uValidFrames;
  io_pPitchState->uInterpolationRampCount = uInterpolationRampCount;
  if ( (unsigned int)v17 < uValidFrames )
    v30 = (unsigned int)v17;
  if ( (_DWORD)v30 )
    io_pPitchState->fLastValue[0] = v10[v30 - 1];
  v31 = v12 - v33;
  io_pPitchState->uFloatIndex = uFloatIndex - ((_DWORD)v30 << 16);
  io_pInBuffer->uValidFrames -= v30;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v31;
  if ( (_DWORD)v30 == uValidFrames )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v30;
  if ( (_DWORD)v31 == v37 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v31;
  return 43i64;
}set +=

// File Line: 930
// RVA: 0xA9CEB0
__int64 __fastcall Interpolating_Native_2Chan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  AkInternalPitchState *v4; // rdi
  __int64 uOutFrameOffset; // r10
  unsigned int uInterpolationRampCount; // ebp
  unsigned int uInterpolationRampInc; // r12d
  float v8; // xmm2_4
  float v9; // xmm3_4
  unsigned int uFloatIndex; // ebx
  unsigned int uTargetFrameSkip; // r14d
  __int64 uMaxFrames; // r15
  __int64 v13; // r9
  float *v14; // rsi
  unsigned int uCurrentFrameSkip; // ecx
  float *v16; // r8
  unsigned int v17; // r14d
  unsigned int v18; // ecx
  char *v19; // r9
  __int64 v20; // r11
  int v21; // r13d
  __int64 v22; // r10
  unsigned int v23; // edx
  int v24; // ecx
  int v25; // eax
  float v26; // xmm1_4
  __int64 v27; // r9
  unsigned int v28; // ecx
  int v29; // r10d
  unsigned int v30; // r14d
  int v31; // eax
  __int64 v32; // rdx
  float v33; // xmm2_4
  __int64 v34; // rdx
  float v35; // eax
  __int64 v36; // r8
  unsigned int uValidFrames; // [rsp+0h] [rbp-68h]
  unsigned int v39; // [rsp+4h] [rbp-64h]
  int v40; // [rsp+8h] [rbp-60h]
  float *v41; // [rsp+10h] [rbp-58h]

  v4 = io_pPitchState;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uInterpolationRampCount = io_pPitchState->uInterpolationRampCount;
  uInterpolationRampInc = io_pPitchState->uInterpolationRampInc;
  v8 = io_pPitchState->fLastValue[0];
  v9 = io_pPitchState->fLastValue[1];
  uFloatIndex = io_pPitchState->uFloatIndex;
  uTargetFrameSkip = io_pPitchState->uTargetFrameSkip;
  uValidFrames = io_pInBuffer->uValidFrames;
  uMaxFrames = io_pOutBuffer->uMaxFrames;
  v13 = uRequestedSize - (unsigned int)uOutFrameOffset;
  v14 = (float *)((char *)io_pInBuffer->pData + 4 * v4->uInFrameOffset);
  uCurrentFrameSkip = v4->uCurrentFrameSkip;
  v16 = (float *)((char *)io_pOutBuffer->pData + 4 * uOutFrameOffset);
  v17 = uTargetFrameSkip - uCurrentFrameSkip;
  v18 = uCurrentFrameSkip << 10;
  v40 = v13;
  v19 = (char *)&v16[v13];
  v20 = HIWORD(uFloatIndex);
  v21 = (unsigned __int16)uFloatIndex;
  v22 = (v19 - (char *)v16) >> 2;
  v41 = v16;
  v39 = v18;
  if ( (unsigned int)v22 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v22) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  if ( !(_DWORD)v20 )
  {
    v23 = v18 + uInterpolationRampCount * v17;
    v24 = (unsigned __int16)uFloatIndex;
    do
    {
      v25 = v22;
      LODWORD(v22) = v22 - 1;
      if ( !v25 )
        break;
      v23 += uInterpolationRampInc * v17;
      ++v16;
      uInterpolationRampCount += uInterpolationRampInc;
      v26 = (float)v24 * 0.000015258789;
      *(v16 - 1) = (float)((float)(*v14 - v8) * v26) + v8;
      uFloatIndex += v23 >> 10;
      v24 = (unsigned __int16)uFloatIndex;
      v20 = HIWORD(uFloatIndex);
      v16[uMaxFrames - 1] = (float)((float)(v14[(unsigned int)(uMaxFrames + 1) - 1] - v9) * v26) + v9;
    }
    while ( !(_DWORD)v20 );
    v21 = v24;
  }
  v27 = (v19 - (char *)v16) >> 2;
  v28 = uValidFrames - 1;
  if ( (unsigned int)v27 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
    LODWORD(v27) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
  if ( (unsigned int)v20 <= v28 )
  {
    v29 = uInterpolationRampInc * v17;
    v30 = v39 + uInterpolationRampCount * v17;
    do
    {
      v31 = v27;
      LODWORD(v27) = v27 - 1;
      if ( !v31 )
        break;
      v32 = (unsigned int)(uMaxFrames + v20);
      v30 += v29;
      ++v16;
      uInterpolationRampCount += uInterpolationRampInc;
      v33 = (float)v21 * 0.000015258789;
      *(v16 - 1) = (float)((float)(v14[(unsigned int)(v20 + 1) - 1] - v14[v20 - 1]) * v33) + v14[v20 - 1];
      uFloatIndex += v30 >> 10;
      v21 = (unsigned __int16)uFloatIndex;
      v20 = HIWORD(uFloatIndex);
      v16[uMaxFrames - 1] = (float)((float)(v14[(unsigned int)(v32 + 1) - 1] - v14[v32 - 1]) * v33) + v14[v32 - 1];
    }
    while ( (unsigned int)v20 <= v28 );
    v4 = io_pPitchState;
  }
  v4->uInterpolationRampCount = uInterpolationRampCount;
  v34 = uValidFrames;
  if ( (unsigned int)v20 < uValidFrames )
    v34 = (unsigned int)v20;
  if ( (_DWORD)v34 )
  {
    v35 = v14[(unsigned int)(v34 + uMaxFrames) - 1];
    v4->fLastValue[0] = v14[v34 - 1];
    v4->fLastValue[1] = v35;
  }
  v36 = v16 - v41;
  v4->uFloatIndex = uFloatIndex - ((_DWORD)v34 << 16);
  io_pInBuffer->uValidFrames -= v34;
  io_pOutBuffer->uValidFrames = LOWORD(v4->uOutFrameOffset) + v36;
  if ( (_DWORD)v34 == uValidFrames )
    v4->uInFrameOffset = 0;
  else
    v4->uInFrameOffset += v34;
  if ( (_DWORD)v36 == v40 )
    return 45i64;
  v4->uOutFrameOffset += v36;
  return 43i64;
}

