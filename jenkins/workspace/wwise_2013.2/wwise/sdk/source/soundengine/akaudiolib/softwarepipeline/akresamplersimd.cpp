// File Line: 151
// RVA: 0xA9BB20
signed __int64 __fastcall Bypass_I16_2ChanSSE2(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  __int64 v4; // r10
  unsigned int v5; // er12
  AkInternalPitchState *v6; // r11
  AkAudioBuffer *v7; // r14
  unsigned int v8; // esi
  const __m128i *v9; // r8
  unsigned int v10; // ebx
  AkAudioBuffer *v11; // r15
  __m128 *v12; // r9
  __int64 v13; // rcx
  __int64 v14; // r13
  unsigned int v15; // er10
  unsigned __int64 v16; // rdi
  int v17; // edx
  signed __int64 v18; // rbp
  signed __int64 v19; // rcx
  signed __int64 v20; // r10
  __m128i v21; // xmm1
  __m128 v22; // xmm0
  __m128i v23; // xmm1
  __m128 v24; // xmm0
  __m128i v25; // xmm1
  __m128 v26; // xmm0
  __m128i v27; // xmm1
  unsigned int v28; // eax
  __m128i v29; // xmm0
  signed int v30; // eax
  signed __int64 v32; // [rsp+0h] [rbp-48h]
  signed __int64 v33; // [rsp+50h] [rbp+8h]
  signed __int64 v34; // [rsp+58h] [rbp+10h]

  v4 = io_pPitchState->uOutFrameOffset;
  v5 = io_pInBuffer->uValidFrames;
  v6 = io_pPitchState;
  v7 = io_pInBuffer;
  v8 = uRequestedSize - v4;
  v9 = (const __m128i *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v10 = v5;
  if ( v8 < v5 )
    v10 = v8;
  v11 = io_pOutBuffer;
  v12 = (__m128 *)((char *)io_pOutBuffer->pData + 4 * v4);
  v13 = (signed int)(v10 - 1);
  v6->iLastValue[0] = *((_WORD *)v9->m128i_i64 + 2 * v13);
  v6->iLastValue[1] = *((_WORD *)v9->m128i_i64 + 2 * v13 + 1);
  v14 = io_pOutBuffer->uMaxFrames;
  v15 = (unsigned int)v14 >> 2;
  v16 = (unsigned __int64)&v9[4 * (v10 >> 4)];
  v17 = v10 - 16 * (v10 >> 4);
  if ( (unsigned __int64)v9 < v16 )
  {
    v18 = (char *)v12 - (char *)v9;
    v33 = (signed __int64)&v12[-1] + 16i64 * v15 - (_QWORD)v9;
    v34 = (signed __int64)&v12[-1] + 16i64 * (v15 + 1) - (_QWORD)v9;
    v19 = 16i64 * (v15 + 3);
    v20 = (signed __int64)&v12[-1] + 16i64 * (v15 + 2) - (_QWORD)v9;
    v32 = (signed __int64)&v12[-1] + v19 - (_QWORD)v9;
    do
    {
      v21 = _mm_loadu_si128(v9);
      v9 += 4;
      v12 += 4;
      v12[-4] = _mm_mul_ps(_mm_cvtepi32_ps(_mm_srai_epi32(_mm_slli_epi32(v21, 0x10u), 0x10u)), (__m128)_xmm);
      v22 = _mm_cvtepi32_ps(_mm_srai_epi32(v21, 0x10u));
      v23 = _mm_loadu_si128(v9 - 3);
      *(__m128 *)((char *)&v9[-3] + v33) = _mm_mul_ps(v22, (__m128)_xmm);
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
    while ( (unsigned __int64)v9 < v16 );
    v14 = v11->uMaxFrames;
  }
  if ( v10 != 16 * (v10 >> 4) )
  {
    do
    {
      v28 = SLOWORD(v9->m128i_i64[0]);
      v12 = (__m128 *)((char *)v12 + 4);
      v9 = (const __m128i *)((char *)v9 + 4);
      v29 = _mm_cvtsi32_si128(v28);
      v30 = v9[-1].m128i_i16[7];
      v12[-1].m128_f32[3] = COERCE_FLOAT(_mm_cvtepi32_ps(v29)) * 0.000030517578;
      *((float *)v12->m128_u64 + v14 - 1) = (float)v30 * 0.000030517578;
      --v17;
    }
    while ( v17 );
  }
  v7->uValidFrames -= v10;
  v11->uValidFrames = LOWORD(v6->uOutFrameOffset) + v10;
  v6->uFloatIndex = 0x10000;
  if ( v10 == v5 )
    v6->uInFrameOffset = 0;
  else
    v6->uInFrameOffset += v10;
  if ( v10 == v8 )
    return 45i64;
  v6->uOutFrameOffset += v10;
  return 43i64;
}

// File Line: 316
// RVA: 0xA9BDE0
signed __int64 __fastcall Bypass_I16_NChanVecSSE2(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // ebp
  unsigned int v5; // esi
  unsigned int v6; // er8
  unsigned int v7; // esi
  AkAudioBuffer *v8; // r15
  unsigned int v9; // edx
  unsigned int v10; // edi
  AkInternalPitchState *v11; // rbx
  unsigned int v12; // er10
  AkAudioBuffer *i; // r14
  const __m128i *v14; // rdx
  signed __int64 v15; // r9
  unsigned __int64 v16; // rcx
  unsigned int j; // er8
  __m128i v18; // xmm3
  __m128i v19; // xmm5
  __m128i v20; // xmm1
  __m128i v21; // xmm4
  signed int v22; // eax
  char *v23; // rdx

  v4 = io_pInBuffer->uValidFrames;
  v5 = uRequestedSize;
  v6 = io_pPitchState->uOutFrameOffset;
  v7 = v5 - v6;
  v8 = io_pOutBuffer;
  v9 = io_pInBuffer->uChannelMask;
  v10 = io_pInBuffer->uValidFrames;
  v11 = io_pPitchState;
  if ( v7 < v4 )
    v10 = v7;
  v12 = 0;
  for ( i = io_pInBuffer; v9; v9 &= v9 - 1 )
    ++v12;
  v14 = (const __m128i *)((char *)io_pInBuffer->pData + 2 * v12 * io_pPitchState->uInFrameOffset);
  v15 = (signed __int64)v8->pData + 4 * v12 * v6;
  v16 = (unsigned __int64)&v14[2 * (v10 * v12 >> 4)];
  for ( j = v10 * v12 - 16 * (v10 * v12 >> 4);
        (unsigned __int64)v14 < v16;
        *(__m128 *)(v15 - 16) = _mm_mul_ps(_mm_cvtepi32_ps(_mm_unpackhi_epi16(v19, v21)), (__m128)_xmm) )
  {
    v18 = _mm_loadu_si128(v14);
    v19 = _mm_loadu_si128(v14 + 1);
    v14 += 2;
    v15 += 64i64;
    v20 = _mm_cmpgt_epi16((__m128i)0i64, v18);
    v21 = _mm_cmpgt_epi16((__m128i)0i64, v19);
    *(__m128 *)(v15 - 64) = _mm_mul_ps(_mm_cvtepi32_ps(_mm_unpacklo_epi16(v18, v20)), (__m128)_xmm);
    *(__m128 *)(v15 - 48) = _mm_mul_ps(_mm_cvtepi32_ps(_mm_unpackhi_epi16(v18, v20)), (__m128)_xmm);
    *(__m128 *)(v15 - 32) = _mm_mul_ps(_mm_cvtepi32_ps(_mm_unpacklo_epi16(v19, v21)), (__m128)_xmm);
  }
  if ( v10 * v12 != 16 * (v10 * v12 >> 4) )
  {
    do
    {
      v22 = SLOWORD(v14->m128i_i64[0]);
      v14 = (const __m128i *)((char *)v14 + 2);
      v15 += 4i64;
      *(float *)(v15 - 4) = (float)v22 * 0.000030517578;
      --j;
    }
    while ( j );
  }
  v23 = (char *)v14->m128i_i64 - 2 * v12;
  if ( v12 )
    memmove(v11, v23, 2i64 * v12);
  i->uValidFrames -= v10;
  v8->uValidFrames = LOWORD(v11->uOutFrameOffset) + v10;
  v11->uFloatIndex = 0x10000;
  if ( v10 == v4 )
    v11->uInFrameOffset = 0;
  else
    v11->uInFrameOffset += v10;
  if ( v10 == v7 )
    return 45i64;
  v11->uOutFrameOffset += v10;
  return 43i64;
}

// File Line: 586
// RVA: 0xA9BFA0
signed __int64 __fastcall Fixed_I16_1Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // esi
  unsigned int v5; // er11
  __int64 v6; // r10
  unsigned int v7; // ebp
  AkInternalPitchState *v8; // rbx
  unsigned int v9; // er12
  unsigned int v10; // eax
  __int64 v11; // r9
  int v12; // edi
  signed __int16 *v13; // r14
  unsigned int v14; // er13
  float *v15; // r8
  unsigned int v16; // ecx
  int v17; // edx
  int v18; // er10
  int v19; // edx
  int v20; // eax
  unsigned int v21; // er15
  unsigned int i; // er10
  int v23; // edx
  int v24; // eax
  int v25; // eax
  __int64 v26; // rdx
  int v27; // ecx
  AkAudioBuffer *v29; // [rsp+38h] [rbp+8h]
  AkAudioBuffer *v30; // [rsp+40h] [rbp+10h]

  v30 = io_pOutBuffer;
  v29 = io_pInBuffer;
  v4 = io_pPitchState->uCurrentFrameSkip;
  v5 = io_pPitchState->uFloatIndex;
  v6 = io_pPitchState->uOutFrameOffset;
  v7 = io_pInBuffer->uValidFrames;
  v8 = io_pPitchState;
  v9 = uRequestedSize - v6;
  v10 = io_pPitchState->uCurrentFrameSkip;
  v11 = v5 >> 16;
  v12 = (unsigned __int16)v5;
  v13 = (signed __int16 *)((char *)io_pInBuffer->pData + 2 * v8->uInFrameOffset);
  v14 = (v10 - v5 + 0xFFFF) / v4;
  v15 = (float *)((char *)io_pOutBuffer->pData + 4 * v6);
  if ( v9 < v14 )
    v14 = v9;
  v16 = v14;
  if ( v14 )
  {
    v17 = v8->iLastValue[0];
    v18 = *v13 - v17;
    v19 = v17 << 16;
    do
    {
      v5 += v4;
      ++v15;
      v20 = v19 + v12 * v18;
      v11 = v5 >> 16;
      v12 = (unsigned __int16)v5;
      *(v15 - 1) = (float)v20 * 4.6566129e-10;
      --v16;
    }
    while ( v16 );
  }
  v21 = (v4 + (v7 << 16) - v5 - 1) / v4;
  if ( v9 - v14 < v21 )
    v21 = v9 - v14;
  for ( i = v21; i; --i )
  {
    v23 = v13[v11 - 1];
    v5 += v4;
    ++v15;
    v24 = v13[(unsigned int)(v11 + 1) - 1] - v23;
    v11 = v5 >> 16;
    v25 = v12 * v24;
    v12 = (unsigned __int16)v5;
    *(v15 - 1) = (float)((v23 << 16) + v25) * 4.6566129e-10;
  }
  v26 = v7;
  if ( (unsigned int)v11 < v7 )
    v26 = (unsigned int)v11;
  if ( (_DWORD)v26 )
    v8->iLastValue[0] = v13[v26 - 1];
  v27 = v21 + v14;
  v8->uFloatIndex = v5 - ((_DWORD)v26 << 16);
  v29->uValidFrames -= v26;
  v30->uValidFrames = LOWORD(v8->uOutFrameOffset) + v21 + v14;
  if ( (_DWORD)v26 == v7 )
    v8->uInFrameOffset = 0;
  else
    v8->uInFrameOffset += v26;
  if ( v27 == v9 )
    return 45i64;
  v8->uOutFrameOffset += v27;
  return 43i64;
}

// File Line: 628
// RVA: 0xA9C150
signed __int64 __fastcall Fixed_I16_2Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // ebp
  unsigned int v5; // er11
  unsigned int v6; // er13
  __int64 v7; // r10
  __int64 v8; // r12
  AkAudioBuffer *v9; // rdi
  unsigned int v10; // er8
  AkInternalPitchState *v11; // rbx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // er9
  int v15; // esi
  unsigned int v16; // eax
  signed __int16 *v17; // r14
  float *v18; // rdi
  unsigned int v19; // ecx
  int v20; // edx
  int v21; // er8
  int v22; // er10
  int v23; // edx
  int v24; // er15
  int v25; // er8
  __m128i v26; // xmm0
  int v27; // eax
  unsigned int v28; // er10
  unsigned int v29; // er15
  unsigned int v30; // er12
  __int64 v31; // rbx
  __int64 v32; // r10
  int v33; // edx
  float v34; // xmm0_4
  int v35; // eax
  unsigned int v36; // er8
  __int64 v37; // rdx
  __int16 v38; // ax
  int v39; // ecx
  unsigned int v41; // [rsp+0h] [rbp-58h]
  AkAudioBuffer *v42; // [rsp+60h] [rbp+8h]
  AkAudioBuffer *v43; // [rsp+68h] [rbp+10h]
  unsigned int v44; // [rsp+70h] [rbp+18h]
  AkInternalPitchState *v45; // [rsp+78h] [rbp+20h]

  v45 = io_pPitchState;
  v43 = io_pOutBuffer;
  v42 = io_pInBuffer;
  v4 = io_pPitchState->uCurrentFrameSkip;
  v5 = io_pPitchState->uFloatIndex;
  v6 = io_pInBuffer->uValidFrames;
  v7 = io_pPitchState->uOutFrameOffset;
  v8 = io_pOutBuffer->uMaxFrames;
  v9 = io_pInBuffer;
  v10 = uRequestedSize - v7;
  v11 = io_pPitchState;
  v12 = io_pPitchState->uCurrentFrameSkip;
  v13 = io_pPitchState->uInFrameOffset;
  v14 = v5 >> 16;
  v41 = v10;
  v15 = (unsigned __int16)v5;
  v16 = (v12 - v5 + 0xFFFF) / v4;
  v17 = (signed __int16 *)((char *)v9->pData + 4 * v13);
  if ( v10 < v16 )
    v16 = v10;
  v18 = (float *)((char *)io_pOutBuffer->pData + 4 * v7);
  v19 = v16;
  v44 = v16;
  if ( v16 )
  {
    v20 = v11->iLastValue[0];
    v21 = v11->iLastValue[1];
    v22 = *v17 - v20;
    v23 = v20 << 16;
    v24 = v17[1] - v21;
    v25 = v21 << 16;
    do
    {
      v5 += v4;
      ++v18;
      v14 = v5 >> 16;
      v26 = _mm_cvtsi32_si128(v23 + v15 * v22);
      v27 = v15 * v24;
      v15 = (unsigned __int16)v5;
      *(v18 - 1) = COERCE_FLOAT(_mm_cvtepi32_ps(v26)) * 4.6566129e-10;
      v18[v8 - 1] = (float)(v25 + v27) * 4.6566129e-10;
      --v19;
    }
    while ( v19 );
    v10 = v41;
  }
  v28 = v44;
  v29 = (v4 + (v6 << 16) - v5 - 1) / v4;
  if ( v10 - v44 < v29 )
    v29 = v10 - v44;
  v30 = v29;
  if ( v29 )
  {
    v31 = v43->uMaxFrames;
    do
    {
      v32 = 2 * v14;
      v5 += v4;
      ++v18;
      v33 = v17[(unsigned int)(v32 + 1) - 2] << 16;
      v14 = v5 >> 16;
      v34 = (float)((v17[v32 - 2] << 16) + v15 * (v17[(unsigned int)(v32 + 2) - 2] - v17[v32 - 2]));
      v35 = v15 * (v17[(unsigned int)(v32 + 3) - 2] - v17[(unsigned int)(v32 + 1) - 2]);
      v15 = (unsigned __int16)v5;
      *(v18 - 1) = v34 * 4.6566129e-10;
      v18[v31 - 1] = (float)(v33 + v35) * 4.6566129e-10;
      --v30;
    }
    while ( v30 );
    v11 = v45;
    v28 = v44;
  }
  v36 = v6;
  if ( v14 < v6 )
    v36 = v14;
  if ( v36 )
  {
    v37 = 2 * v36;
    v38 = v17[(unsigned int)(v37 + 1) - 2];
    v11->iLastValue[0] = v17[v37 - 2];
    v11->iLastValue[1] = v38;
  }
  v39 = v29 + v28;
  v11->uFloatIndex = v5 - (v36 << 16);
  v42->uValidFrames -= v36;
  v43->uValidFrames = LOWORD(v11->uOutFrameOffset) + v29 + v28;
  if ( v36 == v6 )
    v11->uInFrameOffset = 0;
  else
    v11->uInFrameOffset += v36;
  if ( v39 == v41 )
    return 45i64;
  v11->uOutFrameOffset += v39;
  return 43i64;
}

// File Line: 681
// RVA: 0xA9C3B0
signed __int64 __fastcall Fixed_Native_1Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // esi
  unsigned int v5; // er11
  __int64 v6; // r10
  unsigned int v7; // ebp
  AkInternalPitchState *v8; // rbx
  AkAudioBuffer *v9; // r13
  unsigned int v10; // er15
  float v11; // xmm2_4
  unsigned int v12; // eax
  signed int v13; // edi
  __int64 v14; // r9
  float *v15; // r14
  unsigned int v16; // er12
  float *v17; // r8
  unsigned int v18; // ecx
  float v19; // xmm1_4
  signed int v20; // eax
  unsigned int v21; // er10
  unsigned int i; // edx
  signed int v23; // eax
  float v24; // xmm1_4
  __int64 v25; // rdx
  int v26; // ecx
  AkAudioBuffer *v28; // [rsp+38h] [rbp+10h]

  v28 = io_pOutBuffer;
  v4 = io_pPitchState->uCurrentFrameSkip;
  v5 = io_pPitchState->uFloatIndex;
  v6 = io_pPitchState->uOutFrameOffset;
  v7 = io_pInBuffer->uValidFrames;
  v8 = io_pPitchState;
  v9 = io_pInBuffer;
  v10 = uRequestedSize - v6;
  v11 = io_pPitchState->fLastValue[0];
  v12 = io_pPitchState->uCurrentFrameSkip - v5;
  v13 = (unsigned __int16)v5;
  v14 = io_pPitchState->uFloatIndex >> 16;
  v15 = (float *)((char *)io_pInBuffer->pData + 4 * v8->uInFrameOffset);
  v16 = (v12 + 0xFFFF) / v4;
  v17 = (float *)((char *)io_pOutBuffer->pData + 4 * v6);
  if ( v10 < v16 )
    v16 = v10;
  v18 = v16;
  if ( v16 )
  {
    v19 = *v15 - v11;
    do
    {
      v20 = v13;
      v5 += v4;
      ++v17;
      v13 = (unsigned __int16)v5;
      v14 = v5 >> 16;
      *(v17 - 1) = (float)((float)((float)v20 * 0.000015258789) * v19) + v11;
      --v18;
    }
    while ( v18 );
  }
  v21 = (v4 + (v7 << 16) - v5 - 1) / v4;
  if ( v10 - v16 < v21 )
    v21 = v10 - v16;
  for ( i = v21; i; --i )
  {
    v5 += v4;
    ++v17;
    v23 = v13;
    v13 = (unsigned __int16)v5;
    v24 = (float)((float)(v15[(unsigned int)(v14 + 1) - 1] - v15[v14 - 1]) * (float)((float)v23 * 0.000015258789))
        + v15[v14 - 1];
    v14 = v5 >> 16;
    *(v17 - 1) = v24;
  }
  v25 = v7;
  if ( (unsigned int)v14 < v7 )
    v25 = (unsigned int)v14;
  if ( (_DWORD)v25 )
    v8->fLastValue[0] = v15[v25 - 1];
  v26 = v21 + v16;
  v8->uFloatIndex = v5 - ((_DWORD)v25 << 16);
  v9->uValidFrames -= v25;
  v28->uValidFrames = LOWORD(v8->uOutFrameOffset) + v21 + v16;
  if ( (_DWORD)v25 == v7 )
    v8->uInFrameOffset = 0;
  else
    v8->uInFrameOffset += v25;
  if ( v26 == v10 )
    return 45i64;
  v8->uOutFrameOffset += v26;
  return 43i64;
}

// File Line: 722
// RVA: 0xA9C560
signed __int64 __fastcall Fixed_Native_2Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // er11
  unsigned int v5; // esi
  unsigned int v6; // er12
  float v7; // xmm5_4
  float v8; // xmm6_4
  __int64 v9; // r10
  unsigned int v10; // er13
  __int64 v11; // r14
  __int64 v12; // rbx
  signed int v13; // ebp
  float *v14; // rdi
  unsigned int v15; // er15
  float *v16; // r8
  unsigned int v17; // edx
  float v18; // xmm3_4
  float v19; // xmm4_4
  signed int v20; // eax
  float v21; // xmm2_4
  unsigned int v22; // er10
  unsigned int i; // er15
  signed int v24; // eax
  __int64 v25; // rdx
  float v26; // xmm2_4
  float v27; // xmm0_4
  __int64 v28; // rdx
  float v29; // eax
  int v30; // ecx
  AkAudioBuffer *v32; // [rsp+70h] [rbp+8h]
  AkAudioBuffer *v33; // [rsp+78h] [rbp+10h]
  unsigned int v34; // [rsp+88h] [rbp+20h]

  v33 = io_pOutBuffer;
  v32 = io_pInBuffer;
  v4 = io_pPitchState->uFloatIndex;
  v5 = io_pPitchState->uCurrentFrameSkip;
  v6 = io_pInBuffer->uValidFrames;
  v7 = io_pPitchState->fLastValue[0];
  v8 = io_pPitchState->fLastValue[1];
  v9 = io_pPitchState->uOutFrameOffset;
  v10 = uRequestedSize - v9;
  v11 = io_pOutBuffer->uMaxFrames;
  v12 = v4 >> 16;
  v13 = (unsigned __int16)v4;
  v14 = (float *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v15 = (io_pPitchState->uCurrentFrameSkip - v4 + 0xFFFF) / v5;
  v16 = (float *)((char *)io_pOutBuffer->pData + 4 * v9);
  if ( v10 < v15 )
    v15 = v10;
  v34 = v15;
  v17 = v15;
  if ( v15 )
  {
    v18 = *v14 - v7;
    v19 = v14[(unsigned int)(v11 + 1) - 1] - v8;
    do
    {
      v20 = v13;
      v4 += v5;
      ++v16;
      v12 = v4 >> 16;
      v13 = (unsigned __int16)v4;
      v21 = (float)v20 * 0.000015258789;
      *(v16 - 1) = (float)(v21 * v18) + v7;
      v16[v11 - 1] = (float)(v19 * v21) + v8;
      --v17;
    }
    while ( v17 );
  }
  v22 = (v5 + (v6 << 16) - v4 - 1) / v5;
  if ( v10 - v15 < v22 )
    v22 = v10 - v15;
  for ( i = v22; i; --i )
  {
    v24 = v13;
    v25 = (unsigned int)(v11 + v12);
    v4 += v5;
    ++v16;
    v13 = (unsigned __int16)v4;
    v26 = (float)v24 * 0.000015258789;
    v27 = (float)((float)(v14[(unsigned int)(v12 + 1) - 1] - v14[v12 - 1]) * v26) + v14[v12 - 1];
    v12 = v4 >> 16;
    *(v16 - 1) = v27;
    v16[v11 - 1] = (float)((float)(v14[(unsigned int)(v25 + 1) - 1] - v14[v25 - 1]) * v26) + v14[v25 - 1];
  }
  v28 = v6;
  if ( (unsigned int)v12 < v6 )
    v28 = (unsigned int)v12;
  if ( (_DWORD)v28 )
  {
    v29 = v14[(unsigned int)(v28 + v11) - 1];
    io_pPitchState->fLastValue[0] = v14[v28 - 1];
    io_pPitchState->fLastValue[1] = v29;
  }
  v30 = v22 + v34;
  io_pPitchState->uFloatIndex = v4 - ((_DWORD)v28 << 16);
  v32->uValidFrames -= v28;
  v33->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v22 + v34;
  if ( (_DWORD)v28 == v6 )
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
signed __int64 __fastcall Interpolating_I16_1Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  AkInternalPitchState *v4; // rsi
  __int64 v5; // r10
  unsigned int v6; // er12
  unsigned int v7; // ebx
  unsigned int v8; // edi
  __int64 v9; // r9
  signed __int16 *v10; // r15
  unsigned int v11; // ecx
  float *v12; // r8
  unsigned int v13; // er10
  int v14; // edi
  unsigned int v15; // ecx
  signed __int64 v16; // r9
  __int64 v17; // r11
  int v18; // er14
  signed __int64 v19; // rbp
  unsigned int v20; // edx
  int v21; // eax
  int v22; // ecx
  unsigned int v23; // ecx
  signed __int64 v24; // r9
  unsigned int v25; // er13
  int v26; // ebp
  unsigned int v27; // edi
  int v28; // eax
  int v29; // edx
  __m128i v30; // xmm0
  __int64 v31; // rdx
  signed __int64 v32; // r8
  int v34; // [rsp+0h] [rbp-58h]
  float *v35; // [rsp+8h] [rbp-50h]
  AkAudioBuffer *v36; // [rsp+60h] [rbp+8h]
  AkAudioBuffer *v37; // [rsp+68h] [rbp+10h]
  unsigned int v38; // [rsp+70h] [rbp+18h]
  unsigned int v39; // [rsp+78h] [rbp+20h]

  v37 = io_pOutBuffer;
  v36 = io_pInBuffer;
  v4 = io_pPitchState;
  v5 = io_pPitchState->uOutFrameOffset;
  v6 = io_pPitchState->uInterpolationRampInc;
  v7 = io_pPitchState->uFloatIndex;
  v8 = io_pPitchState->uTargetFrameSkip;
  v38 = io_pInBuffer->uValidFrames;
  v9 = uRequestedSize - (unsigned int)v5;
  v10 = (signed __int16 *)((char *)io_pInBuffer->pData + 2 * v4->uInFrameOffset);
  v11 = v4->uCurrentFrameSkip;
  v12 = (float *)((char *)io_pOutBuffer->pData + 4 * v5);
  v13 = v4->uInterpolationRampCount;
  v14 = v8 - v11;
  v15 = v11 << 10;
  v34 = v9;
  v16 = (signed __int64)&v12[v9];
  v17 = v7 >> 16;
  v18 = (unsigned __int16)v7;
  v35 = v12;
  v19 = (v16 - (signed __int64)v12) >> 2;
  v39 = v15;
  if ( (unsigned int)v19 >= (1024 - v13) / v6 )
    LODWORD(v19) = (1024 - v13) / v6;
  if ( !(_DWORD)v17 )
  {
    v20 = v15 + v13 * v14;
    do
    {
      v21 = v19;
      LODWORD(v19) = v19 - 1;
      if ( !v21 )
        break;
      v20 += v6 * v14;
      ++v12;
      v13 += v6;
      v22 = (v4->iLastValue[0] << 16) + v18 * (*v10 - v4->iLastValue[0]);
      v7 += v20 >> 10;
      v18 = (unsigned __int16)v7;
      v17 = v7 >> 16;
      *(v12 - 1) = (float)v22 * 4.6566129e-10;
    }
    while ( !(_DWORD)v17 );
  }
  v23 = v38;
  v24 = (v16 - (signed __int64)v12) >> 2;
  v25 = v38 - 1;
  if ( (unsigned int)v24 >= (1024 - v13) / v6 )
    LODWORD(v24) = (1024 - v13) / v6;
  if ( (unsigned int)v17 <= v25 )
  {
    v26 = v6 * v14;
    v27 = v39 + v13 * v14;
    do
    {
      v28 = v24;
      LODWORD(v24) = v24 - 1;
      if ( !v28 )
        break;
      v29 = v10[v17 - 1];
      v27 += v26;
      ++v12;
      v13 += v6;
      v30 = _mm_cvtsi32_si128((v29 << 16) + v18 * (v10[(unsigned int)(v17 + 1) - 1] - v29));
      v7 += v27 >> 10;
      v18 = (unsigned __int16)v7;
      v17 = v7 >> 16;
      *(v12 - 1) = COERCE_FLOAT(_mm_cvtepi32_ps(v30)) * 4.6566129e-10;
    }
    while ( (unsigned int)v17 <= v25 );
  }
  v31 = v38;
  v4->uInterpolationRampCount = v13;
  if ( (unsigned int)v17 < v38 )
    v31 = (unsigned int)v17;
  if ( (_DWORD)v31 )
  {
    v4->iLastValue[0] = v10[v31 - 1];
    v23 = v38;
  }
  v32 = v12 - v35;
  v4->uFloatIndex = v7 - ((_DWORD)v31 << 16);
  v36->uValidFrames -= v31;
  v37->uValidFrames = LOWORD(v4->uOutFrameOffset) + v32;
  if ( (_DWORD)v31 == v23 )
    v4->uInFrameOffset = 0;
  else
    v4->uInFrameOffset += v31;
  if ( (_DWORD)v32 == v34 )
    return 45i64;
  v4->uOutFrameOffset += v32;
  return 43i64;
}

// File Line: 822
// RVA: 0xA9C990
signed __int64 __fastcall Interpolating_I16_2Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  __int64 v4; // r10
  unsigned int v5; // edi
  AkInternalPitchState *v6; // rsi
  unsigned int v7; // ebp
  unsigned int v8; // er13
  __int64 v9; // r8
  signed __int16 *v10; // r14
  unsigned int v11; // ecx
  float *v12; // r11
  unsigned int v13; // er15
  signed __int64 v14; // rbx
  unsigned int v15; // ecx
  unsigned int v16; // er9
  signed __int64 v17; // r8
  int v18; // er12
  unsigned int v19; // edx
  int v20; // eax
  float v21; // xmm0_4
  int v22; // ecx
  unsigned int v23; // er10
  signed __int64 v24; // rbx
  unsigned int v25; // eax
  unsigned int v26; // er15
  int v27; // esi
  int v28; // eax
  __int64 v29; // r10
  int v30; // er9
  __m128i v31; // xmm0
  __int64 v32; // rax
  unsigned int v33; // er8
  __int64 v34; // rdx
  __int16 v35; // ax
  signed __int64 v36; // r11
  __int16 v38; // [rsp+0h] [rbp-78h]
  int v39; // [rsp+4h] [rbp-74h]
  unsigned int v40; // [rsp+8h] [rbp-70h]
  unsigned int v41; // [rsp+10h] [rbp-68h]
  int v42; // [rsp+14h] [rbp-64h]
  char *v43; // [rsp+20h] [rbp-58h]
  AkAudioBuffer *v44; // [rsp+80h] [rbp+8h]
  AkAudioBuffer *v45; // [rsp+88h] [rbp+10h]
  __int16 v46; // [rsp+90h] [rbp+18h]
  AkInternalPitchState *v47; // [rsp+98h] [rbp+20h]

  v47 = io_pPitchState;
  v45 = io_pOutBuffer;
  v44 = io_pInBuffer;
  v4 = io_pPitchState->uOutFrameOffset;
  v5 = io_pPitchState->uFloatIndex;
  v40 = io_pInBuffer->uValidFrames;
  v6 = io_pPitchState;
  v7 = io_pPitchState->uInterpolationRampCount;
  v8 = io_pPitchState->uInterpolationRampInc;
  v39 = io_pOutBuffer->uMaxFrames;
  v9 = uRequestedSize - (unsigned int)v4;
  v42 = v9;
  v10 = (signed __int16 *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v11 = io_pPitchState->uCurrentFrameSkip;
  v12 = (float *)((char *)io_pOutBuffer->pData + 4 * v4);
  v13 = io_pPitchState->uTargetFrameSkip - v11;
  v46 = io_pPitchState->iLastValue[0];
  v14 = (signed __int64)&v12[v9];
  v38 = io_pPitchState->iLastValue[1];
  v15 = v11 << 10;
  v16 = v5 >> 16;
  v17 = 4 * v9 >> 2;
  v18 = (unsigned __int16)v5;
  v43 = (char *)io_pOutBuffer->pData + 4 * v4;
  if ( (unsigned int)v17 >= (1024 - v7) / v8 )
    LODWORD(v17) = (1024 - v7) / v8;
  v41 = v15;
  if ( !v16 )
  {
    v19 = v15 + v7 * v13;
    do
    {
      v20 = v17;
      LODWORD(v17) = v17 - 1;
      if ( !v20 )
        break;
      v19 += v8 * v13;
      ++v12;
      v7 += v8;
      v21 = (float)((v46 << 16) + v18 * (*v10 - v46));
      v22 = (v38 << 16) + v18 * (v10[1] - v38);
      v5 += v19 >> 10;
      v18 = (unsigned __int16)v5;
      v16 = v5 >> 16;
      *(v12 - 1) = v21 * 4.6566129e-10;
      v12[v39 - 1] = (float)v22 * 4.6566129e-10;
    }
    while ( !(v5 >> 16) );
    v6 = v47;
  }
  v23 = v40;
  v24 = (v14 - (signed __int64)v12) >> 2;
  if ( (unsigned int)v24 >= (1024 - v7) / v8 )
    LODWORD(v24) = (1024 - v7) / v8;
  if ( v16 <= v40 - 1 )
  {
    v25 = v13;
    v26 = v41 + v7 * v13;
    v27 = v8 * v25;
    do
    {
      v28 = v24;
      LODWORD(v24) = v24 - 1;
      if ( !v28 )
        break;
      v29 = 2 * v16;
      v26 += v27;
      ++v12;
      v7 += v8;
      v30 = v10[(unsigned int)(v29 + 1) - 2];
      v31 = _mm_cvtsi32_si128(((signed int)v10[v29 - 2] << 16) + v18
                                                               * (v10[(unsigned int)(v29 + 2) - 2]
                                                                - (signed int)v10[v29 - 2]));
      v32 = (unsigned int)(v29 + 3);
      v23 = v40;
      LODWORD(v32) = (v30 << 16) + v18 * (v10[v32 - 2] - v30);
      *(v12 - 1) = COERCE_FLOAT(_mm_cvtepi32_ps(v31)) * 4.6566129e-10;
      v12[v39 - 1] = (float)(signed int)v32 * 4.6566129e-10;
      v5 += v26 >> 10;
      v18 = (unsigned __int16)v5;
      v16 = v5 >> 16;
    }
    while ( v5 >> 16 <= v40 - 1 );
    v6 = v47;
  }
  v33 = v23;
  v6->uInterpolationRampCount = v7;
  if ( v16 < v23 )
    v33 = v16;
  if ( v33 )
  {
    v34 = 2 * v33;
    v35 = v10[(unsigned int)(v34 + 1) - 2];
    v6->iLastValue[0] = v10[v34 - 2];
    v6->iLastValue[1] = v35;
  }
  v36 = ((char *)v12 - v43) >> 2;
  v6->uFloatIndex = v5 - (v33 << 16);
  v44->uValidFrames -= v33;
  v45->uValidFrames = LOWORD(v6->uOutFrameOffset) + v36;
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
signed __int64 __fastcall Interpolating_Native_1Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // er13
  AkInternalPitchState *v5; // rsi
  __int64 v6; // r10
  float v7; // xmm2_4
  unsigned int v8; // er12
  unsigned int v9; // ebx
  float *v10; // r15
  __int64 v11; // r9
  float *v12; // r8
  unsigned int v13; // eax
  unsigned int v14; // er10
  int v15; // edi
  signed __int64 v16; // r9
  __int64 v17; // r11
  signed int v18; // er14
  signed __int64 v19; // rbp
  unsigned int v20; // ecx
  int v21; // eax
  float v22; // xmm0_4
  signed __int64 v23; // r9
  unsigned int v24; // ebp
  int v25; // edx
  unsigned int v26; // edi
  int v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  __int64 v30; // rdx
  signed __int64 v31; // r8
  float *v33; // [rsp+0h] [rbp-58h]
  AkAudioBuffer *v34; // [rsp+60h] [rbp+8h]
  AkAudioBuffer *v35; // [rsp+68h] [rbp+10h]
  unsigned int v36; // [rsp+70h] [rbp+18h]
  int v37; // [rsp+78h] [rbp+20h]

  v35 = io_pOutBuffer;
  v34 = io_pInBuffer;
  v4 = io_pInBuffer->uValidFrames;
  v5 = io_pPitchState;
  v6 = io_pPitchState->uOutFrameOffset;
  v7 = io_pPitchState->fLastValue[0];
  v8 = io_pPitchState->uInterpolationRampInc;
  v9 = io_pPitchState->uFloatIndex;
  v10 = (float *)((char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset);
  v11 = uRequestedSize - (unsigned int)v6;
  v12 = (float *)((char *)io_pOutBuffer->pData + 4 * v6);
  v13 = v5->uCurrentFrameSkip;
  v14 = v5->uInterpolationRampCount;
  v15 = v5->uTargetFrameSkip - v13;
  v36 = v13 << 10;
  v37 = v11;
  v16 = (signed __int64)&v12[v11];
  v17 = v9 >> 16;
  v18 = (unsigned __int16)v9;
  v33 = v12;
  v19 = (v16 - (signed __int64)v12) >> 2;
  if ( (unsigned int)v19 >= (1024 - v14) / v8 )
    LODWORD(v19) = (1024 - v14) / v8;
  if ( !(_DWORD)v17 )
  {
    v20 = v36 + v14 * v15;
    do
    {
      v21 = v19;
      LODWORD(v19) = v19 - 1;
      if ( !v21 )
        break;
      v22 = (float)v18;
      v20 += v8 * v15;
      ++v12;
      v14 += v8;
      v9 += v20 >> 10;
      v18 = (unsigned __int16)v9;
      v17 = v9 >> 16;
      *(v12 - 1) = (float)((float)(*v10 - v7) * (float)(v22 * 0.000015258789)) + v7;
    }
    while ( !(_DWORD)v17 );
  }
  v23 = (v16 - (signed __int64)v12) >> 2;
  v24 = v4 - 1;
  if ( (unsigned int)v23 >= (1024 - v14) / v8 )
    LODWORD(v23) = (1024 - v14) / v8;
  if ( (unsigned int)v17 <= v24 )
  {
    v25 = v8 * v15;
    v26 = v36 + v14 * v15;
    do
    {
      v27 = v23;
      LODWORD(v23) = v23 - 1;
      if ( !v27 )
        break;
      v26 += v25;
      ++v12;
      v14 += v8;
      v28 = (float)v18;
      v9 += v26 >> 10;
      v18 = (unsigned __int16)v9;
      v29 = (float)((float)(v10[(unsigned int)(v17 + 1) - 1] - v10[v17 - 1]) * (float)(v28 * 0.000015258789))
          + v10[v17 - 1];
      v17 = v9 >> 16;
      *(v12 - 1) = v29;
    }
    while ( (unsigned int)v17 <= v24 );
  }
  v30 = v4;
  v5->uInterpolationRampCount = v14;
  if ( (unsigned int)v17 < v4 )
    v30 = (unsigned int)v17;
  if ( (_DWORD)v30 )
    v5->fLastValue[0] = v10[v30 - 1];
  v31 = v12 - v33;
  v5->uFloatIndex = v9 - ((_DWORD)v30 << 16);
  v34->uValidFrames -= v30;
  v35->uValidFrames = LOWORD(v5->uOutFrameOffset) + v31;
  if ( (_DWORD)v30 == v4 )
    v5->uInFrameOffset = 0;
  else
    v5->uInFrameOffset += v30;
  if ( (_DWORD)v31 == v37 )
    return 45i64;
  v5->uOutFrameOffset += v31;
  return 43i64;
}

// File Line: 930
// RVA: 0xA9CEB0
signed __int64 __fastcall Interpolating_Native_2Chan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  AkInternalPitchState *v4; // rdi
  __int64 v5; // r10
  unsigned int v6; // ebp
  unsigned int v7; // er12
  float v8; // xmm2_4
  float v9; // xmm3_4
  unsigned int v10; // ebx
  unsigned int v11; // er14
  __int64 v12; // r15
  __int64 v13; // r9
  float *v14; // rsi
  unsigned int v15; // ecx
  float *v16; // r8
  int v17; // er14
  unsigned int v18; // ecx
  signed __int64 v19; // r9
  __int64 v20; // r11
  signed int v21; // er13
  signed __int64 v22; // r10
  unsigned int v23; // edx
  signed int v24; // ecx
  int v25; // eax
  float v26; // xmm1_4
  signed __int64 v27; // r9
  unsigned int v28; // ecx
  int v29; // er10
  unsigned int v30; // er14
  int v31; // eax
  __int64 v32; // rdx
  float v33; // xmm2_4
  __int64 v34; // rdx
  float v35; // eax
  signed __int64 v36; // r8
  unsigned int v38; // [rsp+0h] [rbp-68h]
  unsigned int v39; // [rsp+4h] [rbp-64h]
  int v40; // [rsp+8h] [rbp-60h]
  float *v41; // [rsp+10h] [rbp-58h]
  AkAudioBuffer *v42; // [rsp+70h] [rbp+8h]
  AkAudioBuffer *v43; // [rsp+78h] [rbp+10h]
  AkInternalPitchState *v44; // [rsp+88h] [rbp+20h]

  v44 = io_pPitchState;
  v43 = io_pOutBuffer;
  v42 = io_pInBuffer;
  v4 = io_pPitchState;
  v5 = io_pPitchState->uOutFrameOffset;
  v6 = io_pPitchState->uInterpolationRampCount;
  v7 = io_pPitchState->uInterpolationRampInc;
  v8 = io_pPitchState->fLastValue[0];
  v9 = io_pPitchState->fLastValue[1];
  v10 = io_pPitchState->uFloatIndex;
  v11 = io_pPitchState->uTargetFrameSkip;
  v38 = io_pInBuffer->uValidFrames;
  v12 = io_pOutBuffer->uMaxFrames;
  v13 = uRequestedSize - (unsigned int)v5;
  v14 = (float *)((char *)io_pInBuffer->pData + 4 * v4->uInFrameOffset);
  v15 = v4->uCurrentFrameSkip;
  v16 = (float *)((char *)io_pOutBuffer->pData + 4 * v5);
  v17 = v11 - v15;
  v18 = v15 << 10;
  v40 = v13;
  v19 = (signed __int64)&v16[v13];
  v20 = v10 >> 16;
  v21 = (unsigned __int16)v10;
  v22 = (v19 - (signed __int64)v16) >> 2;
  v41 = v16;
  v39 = v18;
  if ( (unsigned int)v22 >= (1024 - v6) / v7 )
    LODWORD(v22) = (1024 - v6) / v7;
  if ( !(_DWORD)v20 )
  {
    v23 = v18 + v6 * v17;
    v24 = (unsigned __int16)v10;
    do
    {
      v25 = v22;
      LODWORD(v22) = v22 - 1;
      if ( !v25 )
        break;
      v23 += v7 * v17;
      ++v16;
      v6 += v7;
      v26 = (float)v24 * 0.000015258789;
      *(v16 - 1) = (float)((float)(*v14 - v8) * v26) + v8;
      v10 += v23 >> 10;
      v24 = (unsigned __int16)v10;
      v20 = v10 >> 16;
      v16[v12 - 1] = (float)((float)(v14[(unsigned int)(v12 + 1) - 1] - v9) * v26) + v9;
    }
    while ( !(_DWORD)v20 );
    v21 = v24;
  }
  v27 = (v19 - (signed __int64)v16) >> 2;
  v28 = v38 - 1;
  if ( (unsigned int)v27 >= (1024 - v6) / v7 )
    LODWORD(v27) = (1024 - v6) / v7;
  if ( (unsigned int)v20 <= v28 )
  {
    v29 = v7 * v17;
    v30 = v39 + v6 * v17;
    do
    {
      v31 = v27;
      LODWORD(v27) = v27 - 1;
      if ( !v31 )
        break;
      v32 = (unsigned int)(v12 + v20);
      v30 += v29;
      ++v16;
      v6 += v7;
      v33 = (float)v21 * 0.000015258789;
      *(v16 - 1) = (float)((float)(v14[(unsigned int)(v20 + 1) - 1] - v14[v20 - 1]) * v33) + v14[v20 - 1];
      v10 += v30 >> 10;
      v21 = (unsigned __int16)v10;
      v20 = v10 >> 16;
      v16[v12 - 1] = (float)((float)(v14[(unsigned int)(v32 + 1) - 1] - v14[v32 - 1]) * v33) + v14[v32 - 1];
    }
    while ( (unsigned int)v20 <= v28 );
    v4 = v44;
  }
  v4->uInterpolationRampCount = v6;
  v34 = v38;
  if ( (unsigned int)v20 < v38 )
    v34 = (unsigned int)v20;
  if ( (_DWORD)v34 )
  {
    v35 = v14[(unsigned int)(v34 + v12) - 1];
    v4->fLastValue[0] = v14[v34 - 1];
    v4->fLastValue[1] = v35;
  }
  v36 = v16 - v41;
  v4->uFloatIndex = v10 - ((_DWORD)v34 << 16);
  v42->uValidFrames -= v34;
  v43->uValidFrames = LOWORD(v4->uOutFrameOffset) + v36;
  if ( (_DWORD)v34 == v38 )
    v4->uInFrameOffset = 0;
  else
    v4->uInFrameOffset += v34;
  if ( (_DWORD)v36 == v40 )
    return 45i64;
  v4->uOutFrameOffset += v36;
  return 43i64;
}

