// File Line: 52
// RVA: 0xA9D160
signed __int64 __fastcall Bypass_Native_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // eax
  unsigned int v5; // er15
  AkAudioBuffer *v6; // r13
  unsigned int v7; // edx
  unsigned int v8; // esi
  AkAudioBuffer *v9; // r14
  unsigned int v10; // ecx
  AkInternalPitchState *v11; // rdi
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

  v4 = io_pInBuffer->uValidFrames;
  v5 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  v6 = io_pOutBuffer;
  v7 = io_pInBuffer->uChannelMask;
  v8 = v4;
  v9 = io_pInBuffer;
  if ( v5 < v4 )
    v8 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  v10 = 0;
  v11 = io_pPitchState;
  v21 = v4;
  v20 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  for ( i = v8; v7; v7 &= v7 - 1 )
    ++v10;
  v12 = 0i64;
  if ( v10 )
  {
    v13 = 4 * v8;
    v14 = 0i64;
    v15 = v10;
    v16 = (signed int)(v8 - 1);
    v19 = v13;
    do
    {
      v17 = (char *)v9->pData + 4 * (v11->uInFrameOffset + v12 * v9->uMaxFrames);
      memmove((char *)v6->pData + 4 * (v11->uOutFrameOffset + v14 * v6->uMaxFrames), v17, v13);
      v13 = v19;
      v11->fLastValue[v12++] = *(float *)&v17[4 * v16];
      ++v14;
      --v15;
    }
    while ( v15 );
    v8 = i;
    v5 = v20;
  }
  v9->uValidFrames -= v8;
  v6->uValidFrames = LOWORD(v11->uOutFrameOffset) + v8;
  v11->uFloatIndex = 0x10000;
  if ( v8 == v21 )
    v11->uInFrameOffset = 0;
  else
    v11->uInFrameOffset += v8;
  if ( v8 == v5 )
    return 45i64;
  v11->uOutFrameOffset += v8;
  return 43i64;
}

// File Line: 74
// RVA: 0xA9D430
signed __int64 __fastcall Fixed_I16_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // edi
  AkInternalPitchState *v5; // r15
  __int64 v6; // r11
  unsigned int v7; // er10
  unsigned int v8; // er14
  unsigned int v9; // er8
  AkAudioBuffer *v10; // r9
  unsigned int v11; // ecx
  unsigned int v12; // ebp
  __int64 v13; // rbx
  char *v14; // rax
  _DWORD *v15; // r12
  unsigned int v16; // esi
  unsigned __int64 v17; // rcx
  unsigned int v18; // er9
  signed __int64 v19; // r13
  unsigned int v20; // ecx
  int v21; // edx
  int v22; // er12
  AkInternalPitchState *v23; // r13
  signed __int64 v24; // rax
  unsigned int v25; // er15
  int v26; // ebp
  unsigned int v27; // er8
  unsigned int v28; // er9
  char *v29; // r12
  unsigned int v30; // edx
  int v31; // ecx
  int v32; // edx
  unsigned int i; // ecx
  unsigned __int64 v34; // r8
  unsigned int v35; // ecx
  int v36; // edx
  int v37; // er11
  int v38; // edx
  int v39; // eax
  unsigned int v40; // edi
  unsigned int j; // er11
  __int64 v42; // rcx
  int v43; // edx
  int v44; // eax
  unsigned int v45; // er8
  unsigned int v46; // edx
  __int64 v47; // rax
  int v48; // ecx
  unsigned int v50; // [rsp+0h] [rbp-A8h]
  int v51; // [rsp+4h] [rbp-A4h]
  unsigned int v52; // [rsp+8h] [rbp-A0h]
  unsigned int v53; // [rsp+10h] [rbp-98h]
  unsigned int v54; // [rsp+14h] [rbp-94h]
  unsigned int v55; // [rsp+18h] [rbp-90h]
  int v56; // [rsp+1Ch] [rbp-8Ch]
  unsigned int v57; // [rsp+20h] [rbp-88h]
  signed __int64 v58; // [rsp+28h] [rbp-80h]
  signed __int64 v59; // [rsp+30h] [rbp-78h]
  signed __int64 v60; // [rsp+38h] [rbp-70h]
  unsigned int *v61; // [rsp+40h] [rbp-68h]
  __int64 v62; // [rsp+48h] [rbp-60h]
  unsigned int *v63; // [rsp+50h] [rbp-58h]
  AkAudioBuffer *v64; // [rsp+B0h] [rbp+8h]
  AkAudioBuffer *v65; // [rsp+B8h] [rbp+10h]
  unsigned int v66; // [rsp+C0h] [rbp+18h]
  AkInternalPitchState *v67; // [rsp+C8h] [rbp+20h]

  v67 = io_pPitchState;
  v65 = io_pOutBuffer;
  v64 = io_pInBuffer;
  v4 = io_pInBuffer->uChannelMask;
  v5 = io_pPitchState;
  v6 = io_pPitchState->uOutFrameOffset;
  v7 = io_pPitchState->uFloatIndex;
  v8 = io_pPitchState->uCurrentFrameSkip;
  v50 = io_pInBuffer->uValidFrames;
  v63 = &io_pPitchState->uOutFrameOffset;
  v9 = uRequestedSize - v6;
  v61 = &io_pPitchState->uFloatIndex;
  v10 = io_pInBuffer;
  v52 = v9;
  v55 = io_pInBuffer->uChannelMask;
  v11 = io_pInBuffer->uChannelMask;
  v12 = (v8 - v7 + 0xFFFF) / v8;
  if ( v9 < v12 )
    v12 = v9;
  v13 = 0i64;
  v66 = v12;
  if ( v4 )
  {
    do
    {
      v13 = (unsigned int)(v13 + 1);
      v11 &= v11 - 1;
    }
    while ( v11 );
  }
  v14 = (char *)v10->pData;
  v15 = &v5->uInFrameOffset;
  v16 = 0;
  v17 = (unsigned int)(v13 * v5->uInFrameOffset) - (unsigned __int64)(unsigned int)v13;
  v59 = (signed __int64)&v5->uInFrameOffset;
  v18 = v7;
  v19 = (signed __int64)&v14[2 * v17];
  v53 = v7;
  v58 = (signed __int64)&v14[2 * v17];
  if ( (_DWORD)v13 )
  {
    v20 = v7 >> 16;
    v21 = v4 & 8;
    v22 = (unsigned __int16)v7;
    v23 = v5;
    v57 = v9 - v12;
    v54 = v7 >> 16;
    v24 = v58 - (_QWORD)v5;
    v51 = (unsigned __int16)v7;
    v56 = v4 & 8;
    v62 = v6;
    v25 = v12;
    v60 = v24;
    while ( 1 )
    {
      v7 = v18;
      v26 = v22;
      v27 = v16;
      v28 = v20;
      v29 = (char *)v23 + v24;
      if ( v21 )
      {
        v30 = 0;
        v31 = v4 & 7;
        if ( v4 & 7 )
        {
          do
          {
            ++v30;
            v31 &= v31 - 1;
          }
          while ( v31 );
        }
        if ( v16 == v30 )
        {
          v32 = 0;
          for ( i = v4; i; i &= i - 1 )
            ++v32;
          v27 = v32 - 1;
        }
        else if ( v16 > v30 )
        {
          v27 = v16 - 1;
        }
      }
      v34 = (unsigned __int64)v65->pData + 4 * (v6 + v65->uMaxFrames * (unsigned __int64)v27);
      v35 = v25;
      if ( v25 )
      {
        v36 = v23->iLastValue[0];
        v37 = *(signed __int16 *)&v29[2 * v13] - v36;
        v38 = v36 << 16;
        do
        {
          v7 += v8;
          v34 += 4i64;
          v39 = v38 + v26 * v37;
          v28 = v7 >> 16;
          v26 = (unsigned __int16)v7;
          *(float *)(v34 - 4) = (float)v39 * 4.6566129e-10;
          --v35;
        }
        while ( v35 );
      }
      v40 = (v8 + (v50 << 16) - v7 - 1) / v8;
      if ( v57 < v40 )
        v40 = v57;
      for ( j = v40; j; --j )
      {
        v7 += v8;
        v34 += 4i64;
        v42 = v28 * (unsigned int)v13;
        v43 = *(signed __int16 *)&v29[2 * v42];
        v28 = v7 >> 16;
        v44 = v26 * (*(signed __int16 *)&v29[2 * (unsigned int)(v13 + v42)] - v43);
        v26 = (unsigned __int16)v7;
        *(float *)(v34 - 4) = (float)((v43 << 16) + v44) * 4.6566129e-10;
      }
      v20 = v54;
      v21 = v56;
      v24 = v60;
      v18 = v53;
      v22 = v51;
      v6 = v62;
      ++v16;
      v23 = (AkInternalPitchState *)((char *)v23 + 2);
      if ( v16 >= (unsigned int)v13 )
        break;
      v4 = v55;
    }
    v5 = v67;
    v12 = v66;
    v15 = (_DWORD *)v59;
    v19 = v58;
  }
  else
  {
    v40 = v12;
  }
  v45 = v50;
  if ( v7 >> 16 < v50 )
    v45 = v7 >> 16;
  if ( v45 )
  {
    v46 = 0;
    if ( (_DWORD)v13 )
    {
      do
      {
        v47 = v45 * (_DWORD)v13 + v46++;
        v5 = (AkInternalPitchState *)((char *)v5 + 2);
        HIWORD(v5[-1].uRequestedFrames) = *(_WORD *)(v19 + 2 * v47);
      }
      while ( v46 < (unsigned int)v13 );
    }
  }
  v48 = v40 + v12;
  *v61 = v7 - (v45 << 16);
  v64->uValidFrames -= v45;
  v65->uValidFrames = *(_WORD *)v63 + v40 + v12;
  if ( v45 == v50 )
    *v15 = 0;
  else
    *v15 += v45;
  if ( v48 == v52 )
    return 45i64;
  *v63 += v48;
  return 43i64;
}

// File Line: 123
// RVA: 0xA9D770
signed __int64 __fastcall Fixed_Native_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // er12
  AkInternalPitchState *v5; // r11
  __int64 v6; // r9
  unsigned int v7; // edi
  unsigned int v8; // er10
  unsigned int v9; // er8
  AkAudioBuffer *v10; // rsi
  AkAudioBuffer *v11; // r14
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // ebp
  unsigned int v15; // edx
  unsigned int v16; // er15
  signed int v17; // ebx
  float *v18; // r12
  int v19; // ecx
  char *v20; // rax
  __int64 v21; // rsi
  signed __int64 v22; // r13
  unsigned int v23; // er11
  signed __int64 v24; // rsi
  __int64 v25; // rax
  unsigned int v26; // ebp
  float v27; // xmm2_4
  unsigned int v28; // er8
  signed __int64 v29; // r9
  unsigned int v30; // ecx
  float v31; // xmm1_4
  signed int v32; // eax
  unsigned int v33; // er15
  unsigned int i; // edx
  __int64 v35; // rax
  __int64 v36; // rcx
  float v37; // xmm1_4
  unsigned int v38; // er9
  unsigned int v39; // esi
  __int64 v40; // r8
  signed __int64 v41; // rdi
  signed __int64 v42; // rbx
  unsigned int v43; // eax
  __int64 v44; // r13
  __int64 v45; // rax
  signed __int64 v46; // rcx
  __int64 v47; // rdx
  __int64 v48; // rax
  int v49; // ecx
  unsigned int v51; // [rsp+0h] [rbp-88h]
  unsigned int v52; // [rsp+4h] [rbp-84h]
  unsigned int v53; // [rsp+8h] [rbp-80h]
  signed int v54; // [rsp+Ch] [rbp-7Ch]
  unsigned int v55; // [rsp+10h] [rbp-78h]
  unsigned int v56; // [rsp+14h] [rbp-74h]
  __int64 v57; // [rsp+20h] [rbp-68h]
  signed __int64 v58; // [rsp+28h] [rbp-60h]
  signed __int64 v59; // [rsp+30h] [rbp-58h]
  AkAudioBuffer *v60; // [rsp+90h] [rbp+8h]
  AkAudioBuffer *v61; // [rsp+98h] [rbp+10h]
  unsigned int v62; // [rsp+A0h] [rbp+18h]
  AkInternalPitchState *v63; // [rsp+A8h] [rbp+20h]

  v63 = io_pPitchState;
  v61 = io_pOutBuffer;
  v60 = io_pInBuffer;
  v4 = io_pInBuffer->uValidFrames;
  v5 = io_pPitchState;
  v6 = io_pPitchState->uOutFrameOffset;
  v7 = v5->uCurrentFrameSkip;
  v8 = v5->uFloatIndex;
  v9 = uRequestedSize - v6;
  v10 = io_pOutBuffer;
  v11 = io_pInBuffer;
  v12 = io_pInBuffer->uChannelMask;
  v52 = v4;
  v55 = v9;
  v13 = (v5->uCurrentFrameSkip - v8 + 0xFFFF) / v7;
  if ( v9 < v13 )
    v13 = v9;
  v14 = 0;
  v51 = 0;
  v62 = v13;
  if ( v12 )
  {
    do
    {
      ++v14;
      v12 &= v12 - 1;
    }
    while ( v12 );
    v51 = v14;
  }
  v15 = v5->uFloatIndex;
  v53 = v5->uFloatIndex;
  if ( v14 )
  {
    v16 = v4 << 16;
    v17 = (unsigned __int16)v8;
    v18 = (float *)v5;
    v19 = v9 - v13;
    v54 = (unsigned __int16)v8;
    v56 = v16;
    v59 = 4i64 * v11->uMaxFrames;
    v58 = 4i64 * v10->uMaxFrames;
    v20 = (char *)v10->pData;
    v21 = v5->uInFrameOffset;
    v22 = (signed __int64)&v20[4 * v6];
    v23 = v19;
    v24 = (signed __int64)v11->pData + 4 * v21 - 4;
    v25 = v14;
    v26 = v8 >> 16;
    v57 = v25;
    while ( 1 )
    {
      v27 = *v18;
      v8 = v15;
      v28 = v26;
      v29 = v22;
      v30 = v62;
      if ( v62 )
      {
        v31 = *(float *)(v24 + 4) - v27;
        do
        {
          v32 = v17;
          v8 += v7;
          v29 += 4i64;
          v17 = (unsigned __int16)v8;
          v28 = v8 >> 16;
          *(float *)(v29 - 4) = (float)((float)((float)v32 * 0.000015258789) * v31) + v27;
          --v30;
        }
        while ( v30 );
      }
      v33 = (v7 + v16 - v8 - 1) / v7;
      if ( v23 < v33 )
        v33 = v23;
      for ( i = v33; i; --i )
      {
        v35 = v28 + 1;
        v36 = v28;
        v8 += v7;
        v29 += 4i64;
        v28 = v8 >> 16;
        v37 = *(float *)(v24 + 4 * v35);
        LODWORD(v35) = v17;
        v17 = (unsigned __int16)v8;
        *(float *)(v29 - 4) = (float)((float)(v37 - *(float *)(v24 + 4 * v36))
                                    * (float)((float)(signed int)v35 * 0.000015258789))
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
    v5 = v63;
    v14 = v51;
    v11 = v60;
    v4 = v52;
  }
  else
  {
    v33 = v13;
  }
  v38 = v4;
  if ( v8 >> 16 < v4 )
    v38 = v8 >> 16;
  if ( v38 )
  {
    v39 = 0;
    v40 = 0i64;
    if ( (signed int)v14 >= 4 )
    {
      v41 = 2i64;
      v42 = (signed __int64)&v5->uLastValue[8];
      v43 = ((v14 - 4) >> 2) + 1;
      v44 = v43;
      v39 = 4 * v43;
      do
      {
        v42 += 16i64;
        v45 = v38 + v40 * v11->uMaxFrames;
        v40 += 4i64;
        *(_DWORD *)(v42 - 24) = *((_DWORD *)v11->pData + v45 + v5->uInFrameOffset - 1);
        *(_DWORD *)(v42 - 20) = *((_DWORD *)v11->pData + v38 + (v41 - 1) * v11->uMaxFrames + v5->uInFrameOffset - 1);
        *(_DWORD *)(v42 - 16) = *((_DWORD *)v11->pData + v38 + v41 * v11->uMaxFrames + v5->uInFrameOffset - 1);
        v46 = v41 + 1;
        v41 += 4i64;
        *(_DWORD *)(v42 - 12) = *((_DWORD *)v11->pData + v38 + v46 * v11->uMaxFrames + v5->uInFrameOffset - 1);
        --v44;
      }
      while ( v44 );
      v4 = v52;
    }
    if ( v39 < v14 )
    {
      v47 = v14 - v39;
      do
      {
        v48 = v40++ * v11->uMaxFrames;
        v5->fLastValue[v40 - 1] = *((float *)v11->pData + v38 + v48 + v5->uInFrameOffset - 1);
        --v47;
      }
      while ( v47 );
    }
  }
  v49 = v33 + v62;
  v5->uFloatIndex = v8 - (v38 << 16);
  v11->uValidFrames -= v38;
  v61->uValidFrames = LOWORD(v5->uOutFrameOffset) + v33 + v62;
  if ( v38 == v4 )
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
signed __int64 __fastcall Interpolating_I16_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  __int64 v4; // r10
  unsigned int v5; // esi
  unsigned int v6; // ebx
  AkAudioBuffer *v7; // r11
  unsigned int v8; // ecx
  unsigned int *v9; // rax
  unsigned int v10; // edi
  AkInternalPitchState *v11; // r12
  unsigned int v12; // er9
  __int64 v13; // r14
  unsigned int v14; // er8
  unsigned int v15; // er13
  __int64 v16; // r15
  unsigned __int64 v17; // rax
  unsigned int v18; // edx
  int v19; // er8
  unsigned int v20; // ecx
  int v21; // ebp
  unsigned int v22; // esi
  unsigned int v23; // er11
  unsigned int v24; // ebx
  unsigned int v25; // er8
  unsigned int v26; // edx
  int v27; // ecx
  int v28; // edx
  unsigned int j; // ecx
  __int16 v30; // bp
  float *v31; // r10
  signed __int64 v32; // r9
  signed __int64 v33; // r8
  unsigned int v34; // edx
  int v35; // eax
  __m128i v36; // xmm0
  signed __int64 v37; // r9
  unsigned int v38; // er8
  int v39; // er15
  int v40; // eax
  __int64 v41; // rcx
  int v42; // edx
  int v43; // eax
  __m128i v44; // xmm0
  unsigned int v45; // er8
  unsigned int v46; // edx
  __int64 v47; // rax
  signed __int64 v48; // r10
  int v50; // [rsp+0h] [rbp-C8h]
  int v51; // [rsp+4h] [rbp-C4h]
  int v52; // [rsp+8h] [rbp-C0h]
  unsigned int v53; // [rsp+Ch] [rbp-BCh]
  int v54; // [rsp+10h] [rbp-B8h]
  int v55; // [rsp+14h] [rbp-B4h]
  int v56; // [rsp+18h] [rbp-B0h]
  unsigned int v57; // [rsp+1Ch] [rbp-ACh]
  unsigned int v58; // [rsp+20h] [rbp-A8h]
  unsigned int v59; // [rsp+24h] [rbp-A4h]
  unsigned int v60; // [rsp+28h] [rbp-A0h]
  unsigned __int64 v61; // [rsp+30h] [rbp-98h]
  signed __int64 v62; // [rsp+38h] [rbp-90h]
  unsigned int *v63; // [rsp+40h] [rbp-88h]
  char *v64; // [rsp+48h] [rbp-80h]
  float *v65; // [rsp+58h] [rbp-70h]
  __int64 i; // [rsp+60h] [rbp-68h]
  unsigned int *v67; // [rsp+68h] [rbp-60h]
  __int64 v68; // [rsp+70h] [rbp-58h]
  unsigned int *v69; // [rsp+78h] [rbp-50h]
  AkAudioBuffer *v70; // [rsp+D0h] [rbp+8h]
  AkAudioBuffer *v71; // [rsp+D8h] [rbp+10h]
  unsigned int v72; // [rsp+E0h] [rbp+18h]
  AkInternalPitchState *v73; // [rsp+E8h] [rbp+20h]

  v73 = io_pPitchState;
  v71 = io_pOutBuffer;
  v70 = io_pInBuffer;
  v4 = io_pPitchState->uOutFrameOffset;
  v5 = io_pInBuffer->uValidFrames;
  v6 = io_pPitchState->uFloatIndex;
  v7 = io_pInBuffer;
  v8 = io_pPitchState->uCurrentFrameSkip;
  v69 = &io_pPitchState->uOutFrameOffset;
  v9 = &io_pPitchState->uFloatIndex;
  v10 = uRequestedSize - v4;
  v11 = io_pPitchState;
  v12 = v7->uChannelMask;
  v13 = 0i64;
  v59 = v6;
  v58 = v5;
  v54 = uRequestedSize - v4;
  v67 = v9;
  v60 = v12;
  v14 = v7->uChannelMask;
  if ( v12 )
  {
    do
    {
      v13 = (unsigned int)(v13 + 1);
      v14 &= v14 - 1;
    }
    while ( v14 );
  }
  v15 = v11->uInterpolationRampInc;
  v53 = v8 << 10;
  v52 = v11->uTargetFrameSkip - v8;
  v16 = 0i64;
  v63 = &v11->uInFrameOffset;
  v17 = (unsigned __int64)v7->pData
      + 2 * ((unsigned int)(v13 * v11->uInFrameOffset) - (unsigned __int64)(unsigned int)v13);
  v18 = v6 >> 16;
  v64 = (char *)v71->pData;
  v19 = (unsigned __int16)v6;
  v20 = v5 - 1;
  v21 = v7->uChannelMask & 8;
  v61 = (unsigned __int64)v7->pData
      + 2 * ((unsigned int)(v13 * v11->uInFrameOffset) - (unsigned __int64)(unsigned int)v13);
  v50 = 0;
  v57 = v6 >> 16;
  v72 = v5 - 1;
  v56 = (unsigned __int16)v6;
  v55 = v7->uChannelMask & 8;
  v68 = v71->uMaxFrames;
  for ( i = v4; ; v4 = i )
  {
    v22 = v11->uInterpolationRampCount;
    v23 = v6;
    v51 = v19;
    v24 = v18;
    v62 = v17 + 2 * v16;
    v25 = v16;
    if ( v21 )
    {
      v26 = 0;
      v27 = v12 & 7;
      if ( v12 & 7 )
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
        for ( j = v12; j; j &= j - 1 )
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
    v31 = (float *)&v64[4 * (v4 + v68 * v25)];
    v32 = (signed __int64)&v31[v10];
    v65 = v31;
    v33 = 4i64 * v10 >> 2;
    if ( (unsigned int)v33 >= (1024 - v22) / v15 )
      LODWORD(v33) = (1024 - v22) / v15;
    if ( !v24 )
    {
      v34 = v53 + v22 * v52;
      do
      {
        v35 = v33;
        LODWORD(v33) = v33 - 1;
        if ( !v35 )
          break;
        v34 += v15 * v52;
        ++v31;
        v22 += v15;
        v23 += v34 >> 10;
        v36 = _mm_cvtsi32_si128(((signed int)v30 << 16) + v51 * (*(signed __int16 *)(v62 + 2 * v13) - (signed int)v30));
        v24 = v23 >> 16;
        v51 = (unsigned __int16)v23;
        *(v31 - 1) = COERCE_FLOAT(_mm_cvtepi32_ps(v36)) * 4.6566129e-10;
      }
      while ( !(v23 >> 16) );
      LODWORD(v16) = v50;
      v11 = v73;
      v20 = v72;
    }
    v37 = (v32 - (signed __int64)v31) >> 2;
    if ( (unsigned int)v37 >= (1024 - v22) / v15 )
      LODWORD(v37) = (1024 - v22) / v15;
    if ( v24 <= v20 )
    {
      v38 = v53 + v22 * v52;
      v39 = v51;
      do
      {
        v40 = v37;
        LODWORD(v37) = v37 - 1;
        if ( !v40 )
          break;
        v38 += v15 * v52;
        ++v31;
        v22 += v15;
        v41 = v24 * (unsigned int)v13;
        v42 = *(signed __int16 *)(v62 + 2 * v41);
        v43 = *(signed __int16 *)(v62 + 2i64 * (unsigned int)(v13 + v41));
        v20 = v72;
        v44 = _mm_cvtsi32_si128((v42 << 16) + v39 * (v43 - v42));
        v23 += v38 >> 10;
        v39 = (unsigned __int16)v23;
        v24 = v23 >> 16;
        *(v31 - 1) = COERCE_FLOAT(_mm_cvtepi32_ps(v44)) * 4.6566129e-10;
      }
      while ( v23 >> 16 <= v72 );
      LODWORD(v16) = v50;
      v11 = v73;
    }
    v12 = v60;
    v17 = v61;
    v6 = v59;
    v18 = v57;
    v21 = v55;
    v19 = v56;
    v16 = (unsigned int)(v16 + 1);
    v50 = v16;
    if ( (unsigned int)v16 >= (unsigned int)v13 )
      break;
  }
  v11->uInterpolationRampCount = v22;
  v45 = v58;
  if ( v23 >> 16 < v58 )
    v45 = v23 >> 16;
  if ( v45 )
  {
    v46 = 0;
    if ( (_DWORD)v13 )
    {
      do
      {
        v47 = v45 * (_DWORD)v13 + v46++;
        v11 = (AkInternalPitchState *)((char *)v11 + 2);
        HIWORD(v11[-1].uRequestedFrames) = *(_WORD *)(v61 + 2 * v47);
      }
      while ( v46 < (unsigned int)v13 );
    }
  }
  v48 = v31 - v65;
  *v67 = v23 - (v45 << 16);
  v70->uValidFrames -= v45;
  v71->uValidFrames = *(_WORD *)v69 + v48;
  if ( v45 == v58 )
    *v63 = 0;
  else
    *v63 += v45;
  if ( (_DWORD)v48 == v54 )
    return 45i64;
  *v69 += v48;
  return 43i64;
}

// File Line: 229
// RVA: 0xA9E0B0
signed __int64 __fastcall Interpolating_Native_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer, unsigned int uRequestedSize, AkInternalPitchState *io_pPitchState)
{
  unsigned int v4; // er11
  unsigned int v5; // edx
  unsigned int v6; // er13
  unsigned int v7; // er10
  __int64 v8; // r8
  unsigned int v9; // er14
  unsigned int v10; // ebp
  unsigned int v11; // edx
  signed int v12; // er15
  unsigned int v13; // edi
  unsigned int v14; // esi
  float v15; // xmm2_4
  unsigned int v16; // ebx
  unsigned int v17; // er11
  signed int v18; // er12
  float *v19; // r15
  unsigned __int64 v20; // r10
  signed __int64 v21; // r8
  signed __int64 v22; // rcx
  int v23; // ebp
  unsigned int v24; // edx
  int v25; // eax
  float v26; // xmm0_4
  signed __int64 v27; // r8
  int v28; // ebp
  unsigned int v29; // edx
  int v30; // eax
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  unsigned int v34; // esi
  unsigned int v35; // ebp
  unsigned int v36; // er12
  __int64 v37; // r8
  signed __int64 v38; // rsi
  char *v39; // r11
  unsigned int v40; // eax
  __int64 v41; // r15
  __int64 v42; // rax
  signed __int64 v43; // rcx
  __int64 v44; // rdx
  __int64 v45; // rax
  signed __int64 v46; // r10
  unsigned int v48; // [rsp+0h] [rbp-88h]
  unsigned int v49; // [rsp+4h] [rbp-84h]
  unsigned int v50; // [rsp+8h] [rbp-80h]
  signed int v51; // [rsp+Ch] [rbp-7Ch]
  unsigned __int64 v52; // [rsp+10h] [rbp-78h]
  unsigned int v53; // [rsp+18h] [rbp-70h]
  int i; // [rsp+1Ch] [rbp-6Ch]
  __int64 v55; // [rsp+20h] [rbp-68h]
  __int64 v56; // [rsp+28h] [rbp-60h]
  char *v57; // [rsp+30h] [rbp-58h]
  __int64 v58; // [rsp+38h] [rbp-50h]
  AkAudioBuffer *v59; // [rsp+90h] [rbp+8h]
  AkAudioBuffer *v60; // [rsp+98h] [rbp+10h]
  unsigned int v61; // [rsp+A0h] [rbp+18h]
  AkInternalPitchState *v62; // [rsp+A8h] [rbp+20h]

  v62 = io_pPitchState;
  v60 = io_pOutBuffer;
  v59 = io_pInBuffer;
  v4 = io_pPitchState->uFloatIndex;
  v5 = io_pPitchState->uCurrentFrameSkip;
  v6 = 0;
  v7 = io_pInBuffer->uChannelMask;
  v8 = uRequestedSize - io_pPitchState->uOutFrameOffset;
  v50 = io_pInBuffer->uValidFrames;
  for ( i = v8; v7; v7 &= v7 - 1 )
    ++v6;
  v9 = io_pPitchState->uInterpolationRampInc;
  v10 = io_pPitchState->uTargetFrameSkip - v5;
  v55 = io_pInBuffer->uMaxFrames;
  v49 = v5 << 10;
  v57 = (char *)io_pInBuffer->pData;
  v11 = v4 >> 16;
  v12 = (unsigned __int16)v4;
  v61 = v10;
  v13 = 0;
  v48 = io_pInBuffer->uValidFrames - 1;
  v53 = v4 >> 16;
  v51 = (unsigned __int16)v4;
  v56 = io_pPitchState->uOutFrameOffset;
  v58 = v8;
  do
  {
    v14 = io_pPitchState->uInterpolationRampCount;
    v15 = io_pPitchState->fLastValue[v13];
    v16 = v4;
    v17 = v11;
    v18 = v12;
    v19 = (float *)&v57[4 * (io_pPitchState->uInFrameOffset + v55 * v13)];
    v20 = (unsigned __int64)v60->pData + 4 * (v56 + v13 * (unsigned __int64)v60->uMaxFrames);
    v21 = v20 + 4 * v8;
    v52 = (unsigned __int64)v60->pData + 4 * (v56 + v13 * (unsigned __int64)v60->uMaxFrames);
    v22 = (signed __int64)(v21 - v20) >> 2;
    if ( (unsigned int)v22 >= (1024 - v14) / v9 )
      LODWORD(v22) = (1024 - v14) / v9;
    if ( !v11 )
    {
      v23 = v9 * v10;
      v24 = v49 + v14 * v61;
      do
      {
        v25 = v22;
        LODWORD(v22) = v22 - 1;
        if ( !v25 )
          break;
        v26 = (float)v18;
        v24 += v23;
        v20 += 4i64;
        v14 += v9;
        v16 += v24 >> 10;
        v18 = (unsigned __int16)v16;
        v17 = v16 >> 16;
        *(float *)(v20 - 4) = (float)((float)(*v19 - v15) * (float)(v26 * 0.000015258789)) + v15;
      }
      while ( !(v16 >> 16) );
      v10 = v61;
    }
    v27 = (signed __int64)(v21 - v20) >> 2;
    if ( (unsigned int)v27 >= (1024 - v14) / v9 )
      LODWORD(v27) = (1024 - v14) / v9;
    if ( v17 <= v48 )
    {
      v28 = v9 * v10;
      v29 = v49 + v14 * v61;
      do
      {
        v30 = v27;
        LODWORD(v27) = v27 - 1;
        if ( !v30 )
          break;
        v29 += v28;
        v20 += 4i64;
        v14 += v9;
        v31 = v19[v17 - 1];
        v32 = v19[v17];
        v33 = (float)v18;
        v16 += v29 >> 10;
        v18 = (unsigned __int16)v16;
        v17 = v16 >> 16;
        *(float *)(v20 - 4) = (float)((float)(v32 - v31) * (float)(v33 * 0.000015258789)) + v31;
      }
      while ( v16 >> 16 <= v48 );
      io_pPitchState = v62;
    }
    v10 = v61;
    v4 = io_pPitchState->uFloatIndex;
    v11 = v53;
    v12 = v51;
    v8 = v58;
    ++v13;
  }
  while ( v13 < v6 );
  io_pPitchState->uInterpolationRampCount = v14;
  v34 = v50;
  v35 = v50;
  if ( v16 >> 16 < v50 )
    v35 = v16 >> 16;
  if ( v35 )
  {
    v36 = 0;
    v37 = 0i64;
    if ( (signed int)v6 >= 4 )
    {
      v38 = 2i64;
      v39 = &io_pPitchState->uLastValue[8];
      v40 = ((v6 - 4) >> 2) + 1;
      v41 = v40;
      v36 = 4 * v40;
      do
      {
        v39 += 16;
        v42 = v35 + v37 * v59->uMaxFrames;
        v37 += 4i64;
        *((_DWORD *)v39 - 6) = *((_DWORD *)v59->pData + v42 + io_pPitchState->uInFrameOffset - 1);
        *((_DWORD *)v39 - 5) = *((_DWORD *)v59->pData
                               + v35
                               + (v38 - 1) * v59->uMaxFrames
                               + io_pPitchState->uInFrameOffset
                               - 1);
        *((_DWORD *)v39 - 4) = *((_DWORD *)v59->pData + v35 + v38 * v59->uMaxFrames + io_pPitchState->uInFrameOffset - 1);
        v43 = v38 + 1;
        v38 += 4i64;
        *((_DWORD *)v39 - 3) = *((_DWORD *)v59->pData + v35 + v43 * v59->uMaxFrames + io_pPitchState->uInFrameOffset - 1);
        --v41;
      }
      while ( v41 );
      v34 = v50;
    }
    if ( v36 < v6 )
    {
      v44 = v6 - v36;
      do
      {
        v45 = v37++ * v59->uMaxFrames;
        io_pPitchState->fLastValue[v37 - 1] = *((float *)v59->pData + v35 + v45 + io_pPitchState->uInFrameOffset - 1);
        --v44;
      }
      while ( v44 );
    }
  }
  v46 = (signed __int64)(v20 - v52) >> 2;
  io_pPitchState->uFloatIndex = v16 - (v35 << 16);
  v59->uValidFrames -= v35;
  v60->uValidFrames = LOWORD(io_pPitchState->uOutFrameOffset) + v46;
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
  unsigned int v2; // esi
  signed int v3; // ebp
  unsigned int v4; // ebx
  unsigned int i; // er8
  unsigned int v6; // er10
  int *v7; // rdi
  char *v8; // r12
  __int64 v9; // r15
  int *v10; // rcx
  unsigned int v11; // er9
  unsigned int v12; // er8
  int v13; // edx
  int v14; // er8
  unsigned int j; // edx
  unsigned int v16; // er11
  char *v17; // rdx
  signed __int64 v18; // r8
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

  v2 = io_pInBuffer->uChannelMask;
  v3 = io_pOutBuffer->uValidFrames;
  v4 = 0;
  for ( i = v2; i; i &= i - 1 )
    ++v4;
  v6 = 0;
  if ( v4 )
  {
    v7 = (int *)io_pInBuffer->pData;
    v8 = (char *)io_pOutBuffer->pData;
    v9 = io_pOutBuffer->uMaxFrames;
    do
    {
      v10 = v7;
      v11 = v6;
      if ( v2 & 8 )
      {
        v12 = 0;
        v13 = v2 & 7;
        if ( v2 & 7 )
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
          for ( j = v2; j; j &= j - 1 )
            ++v14;
          v11 = v14 - 1;
        }
        else if ( v6 > v12 )
        {
          v11 = v6 - 1;
        }
      }
      v16 = 0;
      v17 = &v8[4 * v9 * v11];
      if ( v3 >= 4 )
      {
        v18 = v4;
        v19 = ((unsigned int)(v3 - 4) >> 2) + 1;
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
      if ( v16 < v3 )
      {
        v28 = v3 - v16;
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
      ++v7;
    }
    while ( v6 < v4 );
  }
}

// File Line: 303
// RVA: 0xA9DB50
void __fastcall Interleave_Native_NChan(AkAudioBuffer *io_pInBuffer, AkAudioBuffer *io_pOutBuffer)
{
  unsigned int v2; // edi
  signed int v3; // ebp
  unsigned int v4; // ebx
  unsigned int i; // er8
  unsigned int v6; // er10
  _DWORD *v7; // rsi
  char *v8; // r12
  __int64 v9; // r15
  unsigned int v10; // er8
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // edx
  unsigned int j; // ecx
  unsigned int v15; // er11
  _DWORD *v16; // rcx
  char *v17; // rdx
  signed __int64 v18; // r8
  unsigned int v19; // eax
  __int64 v20; // r9
  int v21; // eax
  _DWORD *v22; // rcx
  _DWORD *v23; // rcx
  _DWORD *v24; // rcx
  __int64 v25; // r8
  int v26; // eax

  v2 = io_pInBuffer->uChannelMask;
  v3 = io_pOutBuffer->uValidFrames;
  v4 = 0;
  for ( i = v2; i; i &= i - 1 )
    ++v4;
  v6 = 0;
  if ( v4 )
  {
    v7 = io_pOutBuffer->pData;
    v8 = (char *)io_pInBuffer->pData;
    v9 = io_pInBuffer->uMaxFrames;
    do
    {
      v10 = v6;
      if ( v2 & 8 )
      {
        v11 = 0;
        v12 = v2 & 7;
        if ( v2 & 7 )
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
          for ( j = v2; j; j &= j - 1 )
            ++v13;
          v10 = v13 - 1;
        }
        else if ( v6 > v11 )
        {
          v10 = v6 - 1;
        }
      }
      v15 = 0;
      v16 = v7;
      v17 = &v8[4 * v9 * v10];
      if ( v3 >= 4 )
      {
        v18 = v4;
        v19 = ((unsigned int)(v3 - 4) >> 2) + 1;
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
      if ( v15 < v3 )
      {
        v25 = v3 - v15;
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
      ++v7;
    }
    while ( v6 < v4 );
  }
}

