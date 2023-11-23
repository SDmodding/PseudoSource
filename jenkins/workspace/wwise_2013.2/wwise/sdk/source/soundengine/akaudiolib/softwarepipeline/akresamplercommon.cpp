// File Line: 52
// RVA: 0xA9D160
__int64 __fastcall Bypass_Native_NChan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uValidFrames; // eax
  unsigned int v5; // r15d
  unsigned int uChannelMask; // edx
  unsigned int v8; // esi
  unsigned int v10; // ecx
  __int64 v12; // rbp
  size_t v13; // rdx
  __int64 v14; // r12
  __int64 v15; // r15
  __int64 v16; // rsi
  char *v17; // rbx
  size_t v19; // [rsp+20h] [rbp-58h]
  unsigned int v20; // [rsp+80h] [rbp+8h]
  unsigned int v21; // [rsp+88h] [rbp+10h]
  unsigned int i; // [rsp+90h] [rbp+18h]

  uValidFrames = io_pInBuffer->uValidFrames;
  v5 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  uChannelMask = io_pInBuffer->uChannelMask;
  v8 = uValidFrames;
  if ( v5 < uValidFrames )
    v8 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  v10 = 0;
  v21 = uValidFrames;
  v20 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  for ( i = v8; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++v10;
  v12 = 0i64;
  if ( v10 )
  {
    v13 = 4 * v8;
    v14 = 0i64;
    v15 = v10;
    v16 = (int)(v8 - 1);
    v19 = v13;
    do
    {
      v17 = (char *)io_pInBuffer->pData + 4 * io_pPitchState->uInFrameOffset + 4 * v12 * io_pInBuffer->uMaxFrames;
      memmove(
        (char *)io_pOutBuffer->pData + 4 * io_pPitchState->uOutFrameOffset + 4 * v14 * io_pOutBuffer->uMaxFrames,
        v17,
        v13);
      v13 = v19;
      io_pPitchState->fLastValue[v12++] = *(float *)&v17[4 * v16];
      ++v14;
      --v15;
    }
    while ( v15 );
    v8 = i;
    v5 = v20;
  }
  io_pInBuffer->uValidFrames -= v8;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v8;
  io_pPitchState->uFloatIndex = 0x10000;
  if ( v8 == v21 )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v8;
  if ( v8 == v5 )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v8;
  return 43i64;
}

// File Line: 74
// RVA: 0xA9D430
__int64 __fastcall Fixed_I16_NChan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uChannelMask; // edi
  AkInternalPitchState *v5; // r15
  __int64 uOutFrameOffset; // r11
  unsigned int uFloatIndex; // r10d
  unsigned int uCurrentFrameSkip; // r14d
  unsigned int v9; // r8d
  unsigned int v11; // ecx
  unsigned int v12; // ebp
  __int64 v13; // rbx
  char *pData; // rax
  unsigned int *p_uInFrameOffset; // r12
  unsigned int v16; // esi
  unsigned int v17; // r9d
  char *v18; // r13
  unsigned int v19; // ecx
  int v20; // edx
  int v21; // r12d
  AkInternalPitchState *v22; // r13
  __int64 v23; // rax
  unsigned int v24; // r15d
  int v25; // ebp
  unsigned int v26; // r8d
  unsigned int v27; // r9d
  char *v28; // r12
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // edx
  unsigned int i; // ecx
  float *v33; // r8
  unsigned int v34; // ecx
  int v35; // edx
  int v36; // r11d
  int v37; // edx
  int v38; // eax
  unsigned int v39; // edi
  unsigned int j; // r11d
  __int64 v41; // rcx
  int v42; // edx
  int v43; // eax
  unsigned int v44; // r8d
  unsigned int k; // edx
  __int64 v46; // rax
  unsigned int v47; // ecx
  unsigned int uValidFrames; // [rsp+0h] [rbp-A8h]
  int v50; // [rsp+4h] [rbp-A4h]
  unsigned int v51; // [rsp+8h] [rbp-A0h]
  unsigned int v52; // [rsp+10h] [rbp-98h]
  unsigned int v53; // [rsp+14h] [rbp-94h]
  unsigned int v54; // [rsp+18h] [rbp-90h]
  int v55; // [rsp+1Ch] [rbp-8Ch]
  unsigned int v56; // [rsp+20h] [rbp-88h]
  char *v57; // [rsp+28h] [rbp-80h]
  unsigned int *v58; // [rsp+30h] [rbp-78h]
  __int64 v59; // [rsp+38h] [rbp-70h]
  unsigned int *p_uFloatIndex; // [rsp+40h] [rbp-68h]
  __int64 v61; // [rsp+48h] [rbp-60h]
  unsigned int *p_uOutFrameOffset; // [rsp+50h] [rbp-58h]
  unsigned int v65; // [rsp+C0h] [rbp+18h]

  uChannelMask = io_pInBuffer->uChannelMask;
  v5 = io_pPitchState;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  uValidFrames = io_pInBuffer->uValidFrames;
  p_uOutFrameOffset = &io_pPitchState->uOutFrameOffset;
  v9 = uRequestedSize - uOutFrameOffset;
  p_uFloatIndex = &io_pPitchState->uFloatIndex;
  v51 = v9;
  v54 = uChannelMask;
  v11 = uChannelMask;
  v12 = (uCurrentFrameSkip - uFloatIndex + 0xFFFF) / uCurrentFrameSkip;
  if ( v9 < v12 )
    v12 = v9;
  v13 = 0i64;
  v65 = v12;
  if ( uChannelMask )
  {
    do
    {
      v13 = (unsigned int)(v13 + 1);
      v11 &= v11 - 1;
    }
    while ( v11 );
  }
  pData = (char *)io_pInBuffer->pData;
  p_uInFrameOffset = &v5->uInFrameOffset;
  v16 = 0;
  v58 = &v5->uInFrameOffset;
  v17 = uFloatIndex;
  v18 = &pData[2 * ((unsigned int)(v13 * v5->uInFrameOffset) - (unsigned __int64)(unsigned int)v13)];
  v52 = uFloatIndex;
  v57 = v18;
  if ( (_DWORD)v13 )
  {
    v19 = HIWORD(uFloatIndex);
    v20 = uChannelMask & 8;
    v21 = (unsigned __int16)uFloatIndex;
    v22 = v5;
    v56 = v9 - v12;
    v53 = HIWORD(uFloatIndex);
    v23 = v57 - (char *)v5;
    v50 = (unsigned __int16)uFloatIndex;
    v55 = v20;
    v61 = uOutFrameOffset;
    v24 = v12;
    v59 = v23;
    while ( 1 )
    {
      uFloatIndex = v17;
      v25 = v21;
      v26 = v16;
      v27 = v19;
      v28 = (char *)v22 + v23;
      if ( v20 )
      {
        v29 = 0;
        v30 = uChannelMask & 7;
        if ( (uChannelMask & 7) != 0 )
        {
          do
          {
            ++v29;
            v30 &= v30 - 1;
          }
          while ( v30 );
        }
        if ( v16 == v29 )
        {
          v31 = 0;
          for ( i = uChannelMask; i; i &= i - 1 )
            ++v31;
          v26 = v31 - 1;
        }
        else if ( v16 > v29 )
        {
          v26 = v16 - 1;
        }
      }
      v33 = (float *)((char *)io_pOutBuffer->pData
                    + 4 * uOutFrameOffset
                    + 4 * io_pOutBuffer->uMaxFrames * (unsigned __int64)v26);
      v34 = v24;
      if ( v24 )
      {
        v35 = v22->iLastValue[0];
        v36 = *(__int16 *)&v28[2 * v13] - v35;
        v37 = v35 << 16;
        do
        {
          uFloatIndex += uCurrentFrameSkip;
          ++v33;
          v38 = v37 + v25 * v36;
          v27 = HIWORD(uFloatIndex);
          v25 = (unsigned __int16)uFloatIndex;
          *(v33 - 1) = (float)v38 * 4.6566129e-10;
          --v34;
        }
        while ( v34 );
      }
      v39 = (uCurrentFrameSkip + (uValidFrames << 16) - uFloatIndex - 1) / uCurrentFrameSkip;
      if ( v56 < v39 )
        v39 = v56;
      for ( j = v39; j; --j )
      {
        uFloatIndex += uCurrentFrameSkip;
        ++v33;
        v41 = v27 * (unsigned int)v13;
        v42 = *(__int16 *)&v28[2 * v41];
        v27 = HIWORD(uFloatIndex);
        v43 = v25 * (*(__int16 *)&v28[2 * (unsigned int)(v13 + v41)] - v42);
        v25 = (unsigned __int16)uFloatIndex;
        *(v33 - 1) = (float)((v42 << 16) + v43) * 4.6566129e-10;
      }
      v19 = v53;
      v20 = v55;
      v23 = v59;
      v17 = v52;
      v21 = v50;
      uOutFrameOffset = v61;
      ++v16;
      v22 = (AkInternalPitchState *)((char *)v22 + 2);
      if ( v16 >= (unsigned int)v13 )
        break;
      uChannelMask = v54;
    }
    v5 = io_pPitchState;
    v12 = v65;
    p_uInFrameOffset = v58;
    v18 = v57;
  }
  else
  {
    v39 = v12;
  }
  v44 = uValidFrames;
  if ( HIWORD(uFloatIndex) < uValidFrames )
    v44 = HIWORD(uFloatIndex);
  if ( v44 )
  {
    for ( k = 0; k < (unsigned int)v13; HIWORD(v5[-1].uRequestedFrames) = *(_WORD *)&v18[2 * v46] )
    {
      v46 = v44 * (_DWORD)v13 + k++;
      v5 = (AkInternalPitchState *)((char *)v5 + 2);
    }
  }
  v47 = v39 + v12;
  *p_uFloatIndex = uFloatIndex - (v44 << 16);
  io_pInBuffer->uValidFrames -= v44;
  io_pOutBuffer->uValidFrames = *(_WORD *)p_uOutFrameOffset + v39 + v12;
  if ( v44 == uValidFrames )
    *p_uInFrameOffset = 0;
  else
    *p_uInFrameOffset += v44;
  if ( v47 == v51 )
    return 45i64;
  *p_uOutFrameOffset += v47;
  return 43i64;
}

// File Line: 123
// RVA: 0xA9D770
__int64 __fastcall Fixed_Native_NChan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uValidFrames; // r12d
  AkInternalPitchState *v5; // r11
  __int64 uOutFrameOffset; // r9
  unsigned int uCurrentFrameSkip; // edi
  unsigned int uFloatIndex; // r10d
  unsigned int v9; // r8d
  AkAudioBuffer *v11; // r14
  unsigned int uChannelMask; // ecx
  unsigned int v13; // eax
  int v14; // ebp
  unsigned int v15; // edx
  unsigned int v16; // r15d
  int v17; // ebx
  float *v18; // r12
  unsigned int v19; // ecx
  char *pData; // rax
  __int64 uInFrameOffset; // rsi
  char *v22; // r13
  unsigned int v23; // r11d
  __int64 v24; // rsi
  __int64 v25; // rax
  unsigned int v26; // ebp
  float v27; // xmm2_4
  unsigned int v28; // r8d
  float *v29; // r9
  unsigned int v30; // ecx
  float v31; // xmm1_4
  int v32; // eax
  unsigned int v33; // r15d
  unsigned int i; // edx
  __int64 v35; // rax
  __int64 v36; // rcx
  float v37; // xmm1_4
  unsigned int v38; // r9d
  unsigned int v39; // esi
  __int64 v40; // r8
  __int64 v41; // rdi
  char *v42; // rbx
  unsigned int v43; // eax
  __int64 v44; // r13
  __int64 v45; // rax
  __int64 v46; // rcx
  __int64 v47; // rdx
  __int64 v48; // rax
  unsigned int v49; // ecx
  int v51; // [rsp+0h] [rbp-88h]
  unsigned int v52; // [rsp+4h] [rbp-84h]
  unsigned int v53; // [rsp+8h] [rbp-80h]
  int v54; // [rsp+Ch] [rbp-7Ch]
  unsigned int v55; // [rsp+10h] [rbp-78h]
  unsigned int v56; // [rsp+14h] [rbp-74h]
  __int64 v57; // [rsp+20h] [rbp-68h]
  __int64 v58; // [rsp+28h] [rbp-60h]
  __int64 v59; // [rsp+30h] [rbp-58h]
  unsigned int v62; // [rsp+A0h] [rbp+18h]

  uValidFrames = io_pInBuffer->uValidFrames;
  v5 = io_pPitchState;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uCurrentFrameSkip = v5->uCurrentFrameSkip;
  uFloatIndex = v5->uFloatIndex;
  v9 = uRequestedSize - uOutFrameOffset;
  v11 = io_pInBuffer;
  uChannelMask = io_pInBuffer->uChannelMask;
  v52 = uValidFrames;
  v55 = v9;
  v13 = (uCurrentFrameSkip - uFloatIndex + 0xFFFF) / uCurrentFrameSkip;
  if ( v9 < v13 )
    v13 = v9;
  v14 = 0;
  v51 = 0;
  v62 = v13;
  if ( uChannelMask )
  {
    do
    {
      ++v14;
      uChannelMask &= uChannelMask - 1;
    }
    while ( uChannelMask );
    v51 = v14;
  }
  v15 = v5->uFloatIndex;
  v53 = v15;
  if ( v14 )
  {
    v16 = uValidFrames << 16;
    v17 = (unsigned __int16)uFloatIndex;
    v18 = (float *)v5;
    v19 = v9 - v13;
    v54 = (unsigned __int16)uFloatIndex;
    v56 = v16;
    v59 = 4i64 * v11->uMaxFrames;
    v58 = 4i64 * io_pOutBuffer->uMaxFrames;
    pData = (char *)io_pOutBuffer->pData;
    uInFrameOffset = v5->uInFrameOffset;
    v22 = &pData[4 * uOutFrameOffset];
    v23 = v19;
    v24 = (__int64)v11->pData + 4 * uInFrameOffset - 4;
    v25 = (unsigned int)v14;
    v26 = HIWORD(uFloatIndex);
    v57 = v25;
    while ( 1 )
    {
      v27 = *v18;
      uFloatIndex = v15;
      v28 = v26;
      v29 = (float *)v22;
      v30 = v62;
      if ( v62 )
      {
        v31 = *(float *)(v24 + 4) - v27;
        do
        {
          v32 = v17;
          uFloatIndex += uCurrentFrameSkip;
          ++v29;
          v17 = (unsigned __int16)uFloatIndex;
          v28 = HIWORD(uFloatIndex);
          *(v29 - 1) = (float)((float)((float)v32 * 0.000015258789) * v31) + v27;
          --v30;
        }
        while ( v30 );
      }
      v33 = (uCurrentFrameSkip + v16 - uFloatIndex - 1) / uCurrentFrameSkip;
      if ( v23 < v33 )
        v33 = v23;
      for ( i = v33; i; --i )
      {
        v35 = v28 + 1;
        v36 = v28;
        uFloatIndex += uCurrentFrameSkip;
        ++v29;
        v28 = HIWORD(uFloatIndex);
        v37 = *(float *)(v24 + 4 * v35);
        LODWORD(v35) = v17;
        v17 = (unsigned __int16)uFloatIndex;
        *(v29 - 1) = (float)((float)(v37 - *(float *)(v24 + 4 * v36)) * (float)((float)(int)v35 * 0.000015258789))
                   + *(float *)(v24 + 4 * v36);
      }
      v22 += v58;
      v24 += v59;
      v15 = v53;
      v17 = v54;
      ++v18;
      if ( !--v57 )
        break;
      v16 = v56;
    }
    v5 = io_pPitchState;
    v14 = v51;
    v11 = io_pInBuffer;
    uValidFrames = v52;
  }
  else
  {
    v33 = v13;
  }
  v38 = uValidFrames;
  if ( HIWORD(uFloatIndex) < uValidFrames )
    v38 = HIWORD(uFloatIndex);
  if ( v38 )
  {
    v39 = 0;
    v40 = 0i64;
    if ( v14 >= 4 )
    {
      v41 = 2i64;
      v42 = &v5->uLastValue[8];
      v43 = ((unsigned int)(v14 - 4) >> 2) + 1;
      v44 = v43;
      v39 = 4 * v43;
      do
      {
        v42 += 16;
        v45 = v38 + v40 * v11->uMaxFrames;
        v40 += 4i64;
        *((_DWORD *)v42 - 6) = *((_DWORD *)v11->pData + v45 + v5->uInFrameOffset - 1);
        *((_DWORD *)v42 - 5) = *((_DWORD *)v11->pData + v38 + (v41 - 1) * v11->uMaxFrames + v5->uInFrameOffset - 1);
        *((_DWORD *)v42 - 4) = *((_DWORD *)v11->pData + v38 + v41 * v11->uMaxFrames + v5->uInFrameOffset - 1);
        v46 = v41 + 1;
        v41 += 4i64;
        *((_DWORD *)v42 - 3) = *((_DWORD *)v11->pData + v38 + v46 * v11->uMaxFrames + v5->uInFrameOffset - 1);
        --v44;
      }
      while ( v44 );
      uValidFrames = v52;
    }
    if ( v39 < v14 )
    {
      v47 = v14 - v39;
      do
      {
        v48 = v40 * v11->uMaxFrames;
        v5->fLastValue[v40++] = *((float *)v11->pData + v38 + v48 + v5->uInFrameOffset - 1);
        --v47;
      }
      while ( v47 );
    }
  }
  v49 = v33 + v62;
  v5->uFloatIndex = uFloatIndex - (v38 << 16);
  v11->uValidFrames -= v38;
  io_pOutBuffer->uValidFrames = LOWORD(v5->uOutFrameOffset) + v33 + v62;
  if ( v38 == uValidFrames )
    v5->uInFrameOffset = 0;
  else
    v5->uInFrameOffset += v38;
  if ( v49 == v55 )
    return 45i64;
  v5->uOutFrameOffset += v49;
  return 43i64;
}

// File Line: 170
// RVA: 0xA9DCA0
__int64 __fastcall Interpolating_I16_NChan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  __int64 uOutFrameOffset; // r10
  unsigned int uValidFrames; // esi
  unsigned int uFloatIndex; // ebx
  unsigned int uCurrentFrameSkip; // ecx
  unsigned int *p_uFloatIndex; // rax
  unsigned int v10; // edi
  AkInternalPitchState *v11; // r12
  unsigned int uChannelMask; // r9d
  __int64 v13; // r14
  unsigned int i; // r8d
  unsigned int uInterpolationRampInc; // r13d
  __int64 v16; // r15
  char *v17; // rax
  unsigned int v18; // edx
  int v19; // r8d
  unsigned int v20; // ecx
  int v21; // ebp
  unsigned int uInterpolationRampCount; // esi
  unsigned int v23; // r11d
  unsigned int v24; // ebx
  unsigned int v25; // r8d
  unsigned int v26; // edx
  int v27; // ecx
  int v28; // edx
  unsigned int k; // ecx
  __int16 v30; // bp
  float *v31; // r10
  char *v32; // r9
  __int64 v33; // r8
  unsigned int v34; // edx
  int v35; // eax
  __m128i v36; // xmm0
  __int64 v37; // r9
  unsigned int v38; // r8d
  int v39; // r15d
  int v40; // eax
  __int64 v41; // rcx
  int v42; // edx
  int v43; // eax
  __m128i v44; // xmm0
  unsigned int v45; // r8d
  unsigned int m; // edx
  __int64 v47; // rax
  __int64 v48; // r10
  int v50; // [rsp+0h] [rbp-C8h]
  int v51; // [rsp+4h] [rbp-C4h]
  unsigned int v52; // [rsp+8h] [rbp-C0h]
  unsigned int v53; // [rsp+Ch] [rbp-BCh]
  int v54; // [rsp+10h] [rbp-B8h]
  int v55; // [rsp+14h] [rbp-B4h]
  int v56; // [rsp+18h] [rbp-B0h]
  unsigned int v57; // [rsp+1Ch] [rbp-ACh]
  unsigned int v58; // [rsp+20h] [rbp-A8h]
  unsigned int v59; // [rsp+24h] [rbp-A4h]
  unsigned int v60; // [rsp+28h] [rbp-A0h]
  char *v61; // [rsp+30h] [rbp-98h]
  char *v62; // [rsp+38h] [rbp-90h]
  unsigned int *p_uInFrameOffset; // [rsp+40h] [rbp-88h]
  char *pData; // [rsp+48h] [rbp-80h]
  float *v65; // [rsp+58h] [rbp-70h]
  __int64 j; // [rsp+60h] [rbp-68h]
  unsigned int *v67; // [rsp+68h] [rbp-60h]
  __int64 uMaxFrames; // [rsp+70h] [rbp-58h]
  unsigned int *p_uOutFrameOffset; // [rsp+78h] [rbp-50h]
  unsigned int v72; // [rsp+E0h] [rbp+18h]

  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  uValidFrames = io_pInBuffer->uValidFrames;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  p_uOutFrameOffset = &io_pPitchState->uOutFrameOffset;
  p_uFloatIndex = &io_pPitchState->uFloatIndex;
  v10 = uRequestedSize - uOutFrameOffset;
  v11 = io_pPitchState;
  uChannelMask = io_pInBuffer->uChannelMask;
  v13 = 0i64;
  v59 = uFloatIndex;
  v58 = uValidFrames;
  v54 = uRequestedSize - uOutFrameOffset;
  v67 = p_uFloatIndex;
  v60 = uChannelMask;
  for ( i = uChannelMask; i; i &= i - 1 )
    v13 = (unsigned int)(v13 + 1);
  uInterpolationRampInc = v11->uInterpolationRampInc;
  v53 = uCurrentFrameSkip << 10;
  v52 = v11->uTargetFrameSkip - uCurrentFrameSkip;
  v16 = 0i64;
  p_uInFrameOffset = &v11->uInFrameOffset;
  v17 = (char *)io_pInBuffer->pData
      + 2 * ((unsigned int)(v13 * v11->uInFrameOffset) - (unsigned __int64)(unsigned int)v13);
  v18 = HIWORD(uFloatIndex);
  pData = (char *)io_pOutBuffer->pData;
  v19 = (unsigned __int16)uFloatIndex;
  v20 = uValidFrames - 1;
  v21 = uChannelMask & 8;
  v61 = v17;
  v50 = 0;
  v57 = HIWORD(uFloatIndex);
  v72 = uValidFrames - 1;
  v56 = (unsigned __int16)uFloatIndex;
  v55 = v21;
  uMaxFrames = io_pOutBuffer->uMaxFrames;
  for ( j = uOutFrameOffset; ; uOutFrameOffset = j )
  {
    uInterpolationRampCount = v11->uInterpolationRampCount;
    v23 = uFloatIndex;
    v51 = v19;
    v24 = v18;
    v62 = &v17[2 * v16];
    v25 = v16;
    if ( v21 )
    {
      v26 = 0;
      v27 = uChannelMask & 7;
      if ( (uChannelMask & 7) != 0 )
      {
        do
        {
          ++v26;
          v27 &= v27 - 1;
        }
        while ( v27 );
      }
      if ( (_DWORD)v16 == v26 )
      {
        v28 = 0;
        for ( k = uChannelMask; k; k &= k - 1 )
          ++v28;
        v25 = v28 - 1;
      }
      else if ( (unsigned int)v16 > v26 )
      {
        v25 = v16 - 1;
      }
      v20 = v72;
    }
    v30 = v11->iLastValue[v16];
    v31 = (float *)&pData[4 * uOutFrameOffset + 4 * uMaxFrames * v25];
    v32 = (char *)&v31[v10];
    v65 = v31;
    v33 = (4i64 * v10) >> 2;
    if ( (unsigned int)v33 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
      LODWORD(v33) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
    if ( !v24 )
    {
      v34 = v53 + uInterpolationRampCount * v52;
      do
      {
        v35 = v33;
        LODWORD(v33) = v33 - 1;
        if ( !v35 )
          break;
        v34 += uInterpolationRampInc * v52;
        ++v31;
        uInterpolationRampCount += uInterpolationRampInc;
        v23 += v34 >> 10;
        v36 = _mm_cvtsi32_si128((v30 << 16) + v51 * (*(__int16 *)&v62[2 * v13] - v30));
        v24 = HIWORD(v23);
        v51 = (unsigned __int16)v23;
        *(v31 - 1) = _mm_cvtepi32_ps(v36).m128_f32[0] * 4.6566129e-10;
      }
      while ( !HIWORD(v23) );
      LODWORD(v16) = v50;
      v11 = io_pPitchState;
      v20 = v72;
    }
    v37 = (v32 - (char *)v31) >> 2;
    if ( (unsigned int)v37 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
      LODWORD(v37) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
    if ( v24 <= v20 )
    {
      v38 = v53 + uInterpolationRampCount * v52;
      v39 = v51;
      do
      {
        v40 = v37;
        LODWORD(v37) = v37 - 1;
        if ( !v40 )
          break;
        v38 += uInterpolationRampInc * v52;
        ++v31;
        uInterpolationRampCount += uInterpolationRampInc;
        v41 = v24 * (unsigned int)v13;
        v42 = *(__int16 *)&v62[2 * v41];
        v43 = *(__int16 *)&v62[2 * (unsigned int)(v13 + v41)];
        v20 = v72;
        v44 = _mm_cvtsi32_si128((v42 << 16) + v39 * (v43 - v42));
        v23 += v38 >> 10;
        v39 = (unsigned __int16)v23;
        v24 = HIWORD(v23);
        *(v31 - 1) = _mm_cvtepi32_ps(v44).m128_f32[0] * 4.6566129e-10;
      }
      while ( HIWORD(v23) <= v72 );
      LODWORD(v16) = v50;
      v11 = io_pPitchState;
    }
    uChannelMask = v60;
    v17 = v61;
    uFloatIndex = v59;
    v18 = v57;
    v21 = v55;
    v19 = v56;
    v16 = (unsigned int)(v16 + 1);
    v50 = v16;
    if ( (unsigned int)v16 >= (unsigned int)v13 )
      break;
  }
  v11->uInterpolationRampCount = uInterpolationRampCount;
  v45 = v58;
  if ( HIWORD(v23) < v58 )
    v45 = HIWORD(v23);
  if ( v45 )
  {
    for ( m = 0; m < (unsigned int)v13; HIWORD(v11[-1].uRequestedFrames) = *(_WORD *)&v61[2 * v47] )
    {
      v47 = v45 * (_DWORD)v13 + m++;
      v11 = (AkInternalPitchState *)((char *)v11 + 2);
    }
  }
  v48 = v31 - v65;
  *v67 = v23 - (v45 << 16);
  io_pInBuffer->uValidFrames -= v45;
  io_pOutBuffer->uValidFrames = *(_WORD *)p_uOutFrameOffset + v48;
  if ( v45 == v58 )
    *p_uInFrameOffset = 0;
  else
    *p_uInFrameOffset += v45;
  if ( (_DWORD)v48 == v54 )
    return 45i64;
  *p_uOutFrameOffset += v48;
  return 43i64;
}

// File Line: 229
// RVA: 0xA9E0B0
__int64 __fastcall Interpolating_Native_NChan(
        AkAudioBuffer *io_pInBuffer,
        AkAudioBuffer *io_pOutBuffer,
        unsigned int uRequestedSize,
        AkInternalPitchState *io_pPitchState)
{
  unsigned int uFloatIndex; // r11d
  unsigned int uCurrentFrameSkip; // edx
  int v6; // r13d
  unsigned int uChannelMask; // r10d
  __int64 v8; // r8
  unsigned int uInterpolationRampInc; // r14d
  unsigned int v10; // ebp
  unsigned int v11; // edx
  int v12; // r15d
  unsigned int v13; // edi
  unsigned int uInterpolationRampCount; // esi
  float v15; // xmm2_4
  unsigned int v16; // ebx
  unsigned int v17; // r11d
  int v18; // r12d
  float *v19; // r15
  float *v20; // r10
  char *v21; // r8
  __int64 v22; // rcx
  int v23; // ebp
  unsigned int v24; // edx
  int v25; // eax
  float v26; // xmm0_4
  __int64 v27; // r8
  int v28; // ebp
  unsigned int v29; // edx
  int v30; // eax
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  unsigned int v34; // esi
  unsigned int v35; // ebp
  unsigned int v36; // r12d
  __int64 v37; // r8
  __int64 v38; // rsi
  char *v39; // r11
  unsigned int v40; // eax
  __int64 v41; // r15
  __int64 v42; // rax
  __int64 v43; // rcx
  __int64 v44; // rdx
  __int64 v45; // rax
  __int64 v46; // r10
  unsigned int v48; // [rsp+0h] [rbp-88h]
  unsigned int v49; // [rsp+4h] [rbp-84h]
  unsigned int uValidFrames; // [rsp+8h] [rbp-80h]
  int v51; // [rsp+Ch] [rbp-7Ch]
  float *v52; // [rsp+10h] [rbp-78h]
  unsigned int v53; // [rsp+18h] [rbp-70h]
  int i; // [rsp+1Ch] [rbp-6Ch]
  __int64 uMaxFrames; // [rsp+20h] [rbp-68h]
  __int64 uOutFrameOffset; // [rsp+28h] [rbp-60h]
  char *pData; // [rsp+30h] [rbp-58h]
  __int64 v58; // [rsp+38h] [rbp-50h]
  unsigned int v61; // [rsp+A0h] [rbp+18h]
  AkInternalPitchState *v62; // [rsp+A8h] [rbp+20h]

  v62 = io_pPitchState;
  uFloatIndex = io_pPitchState->uFloatIndex;
  uCurrentFrameSkip = io_pPitchState->uCurrentFrameSkip;
  v6 = 0;
  uChannelMask = io_pInBuffer->uChannelMask;
  v8 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  uValidFrames = io_pInBuffer->uValidFrames;
  for ( i = v8; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++v6;
  uInterpolationRampInc = io_pPitchState->uInterpolationRampInc;
  v10 = io_pPitchState->uTargetFrameSkip - uCurrentFrameSkip;
  uMaxFrames = io_pInBuffer->uMaxFrames;
  v49 = uCurrentFrameSkip << 10;
  pData = (char *)io_pInBuffer->pData;
  v11 = HIWORD(uFloatIndex);
  v12 = (unsigned __int16)uFloatIndex;
  v61 = v10;
  v13 = 0;
  v48 = io_pInBuffer->uValidFrames - 1;
  v53 = HIWORD(uFloatIndex);
  v51 = (unsigned __int16)uFloatIndex;
  uOutFrameOffset = io_pPitchState->uOutFrameOffset;
  v58 = v8;
  do
  {
    uInterpolationRampCount = io_pPitchState->uInterpolationRampCount;
    v15 = io_pPitchState->fLastValue[v13];
    v16 = uFloatIndex;
    v17 = v11;
    v18 = v12;
    v19 = (float *)&pData[4 * io_pPitchState->uInFrameOffset + 4 * uMaxFrames * v13];
    v20 = (float *)((char *)io_pOutBuffer->pData
                  + 4 * uOutFrameOffset
                  + 4 * v13 * (unsigned __int64)io_pOutBuffer->uMaxFrames);
    v21 = (char *)&v20[v8];
    v52 = v20;
    v22 = (v21 - (char *)v20) >> 2;
    if ( (unsigned int)v22 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
      LODWORD(v22) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
    if ( !v11 )
    {
      v23 = uInterpolationRampInc * v10;
      v24 = v49 + uInterpolationRampCount * v61;
      do
      {
        v25 = v22;
        LODWORD(v22) = v22 - 1;
        if ( !v25 )
          break;
        v26 = (float)v18;
        v24 += v23;
        ++v20;
        uInterpolationRampCount += uInterpolationRampInc;
        v16 += v24 >> 10;
        v18 = (unsigned __int16)v16;
        v17 = HIWORD(v16);
        *(v20 - 1) = (float)((float)(*v19 - v15) * (float)(v26 * 0.000015258789)) + v15;
      }
      while ( !HIWORD(v16) );
      v10 = v61;
    }
    v27 = (v21 - (char *)v20) >> 2;
    if ( (unsigned int)v27 >= (1024 - uInterpolationRampCount) / uInterpolationRampInc )
      LODWORD(v27) = (1024 - uInterpolationRampCount) / uInterpolationRampInc;
    if ( v17 <= v48 )
    {
      v28 = uInterpolationRampInc * v10;
      v29 = v49 + uInterpolationRampCount * v61;
      do
      {
        v30 = v27;
        LODWORD(v27) = v27 - 1;
        if ( !v30 )
          break;
        v29 += v28;
        ++v20;
        uInterpolationRampCount += uInterpolationRampInc;
        v31 = v19[v17 - 1];
        v32 = v19[v17];
        v33 = (float)v18;
        v16 += v29 >> 10;
        v18 = (unsigned __int16)v16;
        v17 = HIWORD(v16);
        *(v20 - 1) = (float)((float)(v32 - v31) * (float)(v33 * 0.000015258789)) + v31;
      }
      while ( HIWORD(v16) <= v48 );
      io_pPitchState = v62;
    }
    v10 = v61;
    uFloatIndex = io_pPitchState->uFloatIndex;
    v11 = v53;
    v12 = v51;
    v8 = v58;
    ++v13;
  }
  while ( v13 < v6 );
  io_pPitchState->uInterpolationRampCount = uInterpolationRampCount;
  v34 = uValidFrames;
  v35 = uValidFrames;
  if ( HIWORD(v16) < uValidFrames )
    v35 = HIWORD(v16);
  if ( v35 )
  {
    v36 = 0;
    v37 = 0i64;
    if ( v6 >= 4 )
    {
      v38 = 2i64;
      v39 = &io_pPitchState->uLastValue[8];
      v40 = ((unsigned int)(v6 - 4) >> 2) + 1;
      v41 = v40;
      v36 = 4 * v40;
      do
      {
        v39 += 16;
        v42 = v35 + v37 * io_pInBuffer->uMaxFrames;
        v37 += 4i64;
        *((_DWORD *)v39 - 6) = *((_DWORD *)io_pInBuffer->pData + v42 + io_pPitchState->uInFrameOffset - 1);
        *((_DWORD *)v39 - 5) = *((_DWORD *)io_pInBuffer->pData
                               + v35
                               + (v38 - 1) * io_pInBuffer->uMaxFrames
                               + io_pPitchState->uInFrameOffset
                               - 1);
        *((_DWORD *)v39 - 4) = *((_DWORD *)io_pInBuffer->pData
                               + v35
                               + v38 * io_pInBuffer->uMaxFrames
                               + io_pPitchState->uInFrameOffset
                               - 1);
        v43 = v38 + 1;
        v38 += 4i64;
        *((_DWORD *)v39 - 3) = *((_DWORD *)io_pInBuffer->pData
                               + v35
                               + v43 * io_pInBuffer->uMaxFrames
                               + io_pPitchState->uInFrameOffset
                               - 1);
        --v41;
      }
      while ( v41 );
      v34 = uValidFrames;
    }
    if ( v36 < v6 )
    {
      v44 = v6 - v36;
      do
      {
        v45 = v37 * io_pInBuffer->uMaxFrames;
        io_pPitchState->fLastValue[v37++] = *((float *)io_pInBuffer->pData
                                            + v35
                                            + v45
                                            + io_pPitchState->uInFrameOffset
                                            - 1);
        --v44;
      }
      while ( v44 );
    }
  }
  v46 = v20 - v52;
  io_pPitchState->uFloatIndex = v16 - (v35 << 16);
  io_pInBuffer->uValidFrames -= v35;
  io_pOutBuffer->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v46;
  if ( v35 == v34 )
    io_pPitchState->uInFrameOffset = 0;
  else
    io_pPitchState->uInFrameOffset += v35;
  if ( (_DWORD)v46 == i )
    return 45i64;
  io_pPitchState->uOutFrameOffset += v46;
  return 43i64;
}

// File Line: 285
// RVA: 0xA9D2D0
void __fastcall Deinterleave_Native_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer)
{
  unsigned int uChannelMask; // esi
  int uValidFrames; // ebp
  unsigned int v4; // ebx
  unsigned int i; // r8d
  unsigned int v6; // r10d
  int *pData; // rdi
  char *v8; // r12
  __int64 uMaxFrames; // r15
  int *v10; // rcx
  unsigned int v11; // r9d
  unsigned int v12; // r8d
  int v13; // edx
  int v14; // r8d
  unsigned int j; // edx
  unsigned int v16; // r11d
  char *v17; // rdx
  __int64 v18; // r8
  unsigned int v19; // eax
  __int64 v20; // r9
  int v21; // eax
  int *v22; // rcx
  int v23; // eax
  int *v24; // rcx
  int v25; // eax
  int *v26; // rcx
  int v27; // eax
  __int64 v28; // r8
  int v29; // eax

  uChannelMask = io_pInBuffer->uChannelMask;
  uValidFrames = io_pOutBuffer->uValidFrames;
  v4 = 0;
  for ( i = uChannelMask; i; i &= i - 1 )
    ++v4;
  v6 = 0;
  if ( v4 )
  {
    pData = (int *)io_pInBuffer->pData;
    v8 = (char *)io_pOutBuffer->pData;
    uMaxFrames = io_pOutBuffer->uMaxFrames;
    do
    {
      v10 = pData;
      v11 = v6;
      if ( (uChannelMask & 8) != 0 )
      {
        v12 = 0;
        v13 = uChannelMask & 7;
        if ( (uChannelMask & 7) != 0 )
        {
          do
          {
            ++v12;
            v13 &= v13 - 1;
          }
          while ( v13 );
        }
        if ( v6 == v12 )
        {
          v14 = 0;
          for ( j = uChannelMask; j; j &= j - 1 )
            ++v14;
          v11 = v14 - 1;
        }
        else if ( v6 > v12 )
        {
          v11 = v6 - 1;
        }
      }
      v16 = 0;
      v17 = &v8[4 * uMaxFrames * v11];
      if ( uValidFrames >= 4 )
      {
        v18 = v4;
        v19 = ((unsigned int)(uValidFrames - 4) >> 2) + 1;
        v20 = v19;
        v16 = 4 * v19;
        do
        {
          v21 = *v10;
          v22 = &v10[v18];
          v17 += 16;
          *((_DWORD *)v17 - 4) = v21;
          v23 = *v22;
          v24 = &v22[v18];
          *((_DWORD *)v17 - 3) = v23;
          v25 = *v24;
          v26 = &v24[v18];
          *((_DWORD *)v17 - 2) = v25;
          v27 = *v26;
          v10 = &v26[v18];
          *((_DWORD *)v17 - 1) = v27;
          --v20;
        }
        while ( v20 );
      }
      if ( v16 < uValidFrames )
      {
        v28 = uValidFrames - v16;
        do
        {
          v29 = *v10;
          v10 += v4;
          v17 += 4;
          *((_DWORD *)v17 - 1) = v29;
          --v28;
        }
        while ( v28 );
      }
      ++v6;
      ++pData;
    }
    while ( v6 < v4 );
  }
}

// File Line: 303
// RVA: 0xA9DB50
void __fastcall Interleave_Native_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer)
{
  unsigned int uChannelMask; // edi
  int uValidFrames; // ebp
  unsigned int v4; // ebx
  unsigned int i; // r8d
  unsigned int v6; // r10d
  _DWORD *pData; // rsi
  char *v8; // r12
  __int64 uMaxFrames; // r15
  unsigned int v10; // r8d
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // edx
  unsigned int j; // ecx
  unsigned int v15; // r11d
  _DWORD *v16; // rcx
  char *v17; // rdx
  __int64 v18; // r8
  unsigned int v19; // eax
  __int64 v20; // r9
  int v21; // eax
  _DWORD *v22; // rcx
  _DWORD *v23; // rcx
  _DWORD *v24; // rcx
  __int64 v25; // r8
  int v26; // eax

  uChannelMask = io_pInBuffer->uChannelMask;
  uValidFrames = io_pOutBuffer->uValidFrames;
  v4 = 0;
  for ( i = uChannelMask; i; i &= i - 1 )
    ++v4;
  v6 = 0;
  if ( v4 )
  {
    pData = io_pOutBuffer->pData;
    v8 = (char *)io_pInBuffer->pData;
    uMaxFrames = io_pInBuffer->uMaxFrames;
    do
    {
      v10 = v6;
      if ( (uChannelMask & 8) != 0 )
      {
        v11 = 0;
        v12 = uChannelMask & 7;
        if ( (uChannelMask & 7) != 0 )
        {
          do
          {
            ++v11;
            v12 &= v12 - 1;
          }
          while ( v12 );
        }
        if ( v6 == v11 )
        {
          v13 = 0;
          for ( j = uChannelMask; j; j &= j - 1 )
            ++v13;
          v10 = v13 - 1;
        }
        else if ( v6 > v11 )
        {
          v10 = v6 - 1;
        }
      }
      v15 = 0;
      v16 = pData;
      v17 = &v8[4 * uMaxFrames * v10];
      if ( uValidFrames >= 4 )
      {
        v18 = v4;
        v19 = ((unsigned int)(uValidFrames - 4) >> 2) + 1;
        v20 = v19;
        v15 = 4 * v19;
        do
        {
          v21 = *(_DWORD *)v17;
          v17 += 16;
          *v16 = v21;
          v22 = &v16[v18];
          *v22 = *((_DWORD *)v17 - 3);
          v23 = &v22[v18];
          *v23 = *((_DWORD *)v17 - 2);
          v24 = &v23[v18];
          *v24 = *((_DWORD *)v17 - 1);
          v16 = &v24[v18];
          --v20;
        }
        while ( v20 );
      }
      if ( v15 < uValidFrames )
      {
        v25 = uValidFrames - v15;
        do
        {
          v26 = *(_DWORD *)v17;
          v17 += 4;
          *v16 = v26;
          v16 += v4;
          --v25;
        }
        while ( v25 );
      }
      ++v6;
      ++pData;
    }
    while ( v6 < v4 );
  }
}

