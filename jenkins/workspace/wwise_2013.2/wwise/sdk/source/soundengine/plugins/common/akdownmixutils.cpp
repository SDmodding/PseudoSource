// File Line: 29
// RVA: 0xB19410
void __fastcall DSP::AkDownMix(
        AkAudioBuffer *in_pBuffer,
        AkAudioBuffer *out_pDownMixBuffer,
        float in_fPrevInputCenterLevel,
        float in_fInputCenterLevel,
        float in_fPrevInputLFELevel,
        float in_fInputLFELevel)
{
  unsigned int uChannelMask; // edi
  __int64 v7; // r15
  AkAudioBuffer *v9; // rbp
  AkAudioBuffer *v10; // r11
  unsigned int v11; // r9d
  unsigned int v12; // r8d
  int uValidFrames; // ebx
  __int64 v14; // r12
  unsigned int v15; // r8d
  unsigned int j; // ecx
  size_t v17; // rdi
  __int64 v18; // rbx
  int v19; // edx
  int v20; // ecx
  __m128 v21; // xmm5
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm9_4
  __m128 v27; // xmm0
  float v28; // xmm8_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  float v31; // xmm6_4
  float v32; // xmm3_4
  __int64 uMaxFrames; // r14
  float *pData; // r10
  float *v35; // r11
  __int64 v36; // rbp
  __int64 v37; // r14
  __int64 v38; // rsi
  float *v39; // rcx
  float *v40; // rdx
  float v41; // xmm2_4
  unsigned int v42; // r9d
  unsigned int v43; // eax
  __int64 v44; // r8
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm1_4
  char *v52; // rdx
  __int64 v53; // r8
  float v54; // xmm0_4
  float *v55; // r10
  __int64 v56; // rsi
  __int64 v57; // r11
  __int64 v58; // rdx
  float *v59; // rcx
  float v60; // xmm1_4
  unsigned int v61; // r9d
  unsigned int v62; // eax
  __int64 v63; // r8
  float v64; // xmm0_4
  float v65; // xmm0_4
  __int64 v66; // rdx
  __int64 v67; // r8
  float v68; // xmm0_4
  float *v69; // rsi
  __int64 v70; // r14
  char *v71; // r12
  unsigned int v72; // r13d
  unsigned int v73; // r10d
  float *v74; // r11
  __int64 v75; // rbp
  float v76; // xmm1_4
  unsigned int v77; // r9d
  float *v78; // rdx
  float *v79; // rcx
  unsigned int v80; // eax
  __int64 v81; // r8
  float v82; // xmm0_4
  float v83; // xmm0_4
  char *v84; // rdx
  __int64 v85; // r8
  float v86; // xmm0_4
  unsigned int i; // r9d
  float v88; // xmm1_4
  unsigned int v89; // r10d
  float *v90; // rdx
  float *v91; // rcx
  unsigned int v92; // eax
  __int64 v93; // r8
  float v94; // xmm0_4
  float v95; // xmm0_4
  char *v96; // rdx
  __int64 v97; // r8
  float v98; // xmm0_4
  __int64 v99; // rsi
  float *v100; // rdi
  __int64 v101; // rbp
  float *LFE; // rax
  float *v103; // rdx
  unsigned int v104; // ecx
  float v105; // xmm1_4
  float *v106; // r8
  unsigned int v107; // ecx
  __int64 v108; // rax
  float v109; // xmm0_4
  float v110; // xmm0_4
  signed __int64 v111; // r8
  __int64 v112; // rcx
  float v113; // xmm0_4
  unsigned int v114; // [rsp+24h] [rbp-84h]

  uChannelMask = in_pBuffer->uChannelMask;
  v7 = 0i64;
  v9 = out_pDownMixBuffer;
  v10 = in_pBuffer;
  v11 = 0;
  v12 = uChannelMask & 0xFFFFFFF7;
  if ( (uChannelMask & 0xFFFFFFF7) != 0 )
  {
    do
    {
      ++v11;
      v12 &= v12 - 1;
    }
    while ( v12 );
  }
  uValidFrames = in_pBuffer->uValidFrames;
  v14 = 2i64;
  v15 = 2;
  if ( v11 < 2 )
    v15 = v11;
  v114 = v15;
  if ( ((uChannelMask - 3) & 0xFFFFFFFA) != 0 || uChannelMask == 7 )
  {
    v19 = 0;
    v20 = uChannelMask & 0x33;
    if ( (uChannelMask & 0x33) != 0 )
    {
      do
      {
        ++v19;
        v20 &= v20 - 1;
      }
      while ( v20 );
    }
    v21 = (__m128)(unsigned int)FLOAT_1_0;
    v22 = 0.0;
    v23 = (float)v19;
    v24 = 0.0;
    v25 = 0.0;
    v26 = 0.0;
    if ( (uChannelMask & 4) != 0 )
    {
      if ( (uChannelMask & 7) == 7 )
      {
        v24 = in_fPrevInputCenterLevel * in_fPrevInputCenterLevel;
        v22 = in_fInputCenterLevel * in_fInputCenterLevel;
      }
      else
      {
        v23 = v23 + 1.0;
      }
    }
    if ( (uChannelMask & 8) != 0 )
    {
      v26 = in_fPrevInputLFELevel * in_fPrevInputLFELevel;
      v25 = in_fInputLFELevel * in_fInputLFELevel;
    }
    v27 = (__m128)(unsigned int)FLOAT_1_0;
    v27.m128_f32[0] = 1.0 / (float)((float)(v24 + v23) + v26);
    v28 = _mm_sqrt_ps(v27).m128_f32[0];
    v29 = 1.0 / (float)uValidFrames;
    v21.m128_f32[0] = 1.0 / (float)((float)(v22 + v23) + v25);
    v30 = (float)(v22 - v24) * v29;
    v31 = (float)(v25 - v26) * v29;
    v32 = (float)(_mm_sqrt_ps(v21).m128_f32[0] - v28) * v29;
    if ( v15 )
    {
      uMaxFrames = v10->uMaxFrames;
      pData = (float *)out_pDownMixBuffer->pData;
      v35 = (float *)v10->pData;
      v36 = 4i64 * v9->uMaxFrames;
      v37 = 4 * uMaxFrames;
      v38 = v15;
      do
      {
        v39 = v35;
        v40 = pData;
        v41 = v28;
        v42 = 0;
        if ( uValidFrames >= 4 )
        {
          v43 = ((unsigned int)(uValidFrames - 4) >> 2) + 1;
          v44 = v43;
          v42 = 4 * v43;
          do
          {
            v45 = v41;
            v40 += 4;
            v39 += 4;
            v46 = v41 + v32;
            v47 = (float)(v41 + v32) + v32;
            v48 = v46 * *(v39 - 3);
            *(v40 - 4) = v45 * *(v39 - 4);
            v49 = v47 * *(v39 - 2);
            *(v40 - 3) = v48;
            v50 = v47 + v32;
            v41 = (float)(v47 + v32) + v32;
            v51 = v50 * *(v39 - 1);
            *(v40 - 2) = v49;
            *(v40 - 1) = v51;
            --v44;
          }
          while ( v44 );
        }
        if ( v42 < uValidFrames )
        {
          v52 = (char *)((char *)v40 - (char *)v39);
          v53 = uValidFrames - v42;
          do
          {
            v54 = v41;
            ++v39;
            v41 = v41 + v32;
            *(float *)((char *)v39 + (_QWORD)v52 - 4) = v54 * *(v39 - 1);
            --v53;
          }
          while ( v53 );
        }
        v35 = (float *)((char *)v35 + v37);
        pData = (float *)((char *)pData + v36);
        --v38;
      }
      while ( v38 );
      v9 = out_pDownMixBuffer;
      v10 = in_pBuffer;
    }
    if ( (uChannelMask & 7) == 7 )
    {
      v55 = (float *)v9->pData;
      v56 = (__int64)v10->pData + 8 * v10->uMaxFrames;
      v57 = 4i64 * v9->uMaxFrames;
      do
      {
        v58 = v56;
        v59 = v55;
        v60 = v24;
        v61 = 0;
        if ( uValidFrames >= 4 )
        {
          v62 = ((unsigned int)(uValidFrames - 4) >> 2) + 1;
          v63 = v62;
          v61 = 4 * v62;
          do
          {
            v59 += 4;
            v58 += 16i64;
            *(v59 - 4) = (float)(v60 * *(float *)(v58 - 16)) + *(v59 - 4);
            *(v59 - 3) = (float)((float)(v60 + v30) * *(float *)(v58 - 12)) + *(v59 - 3);
            v64 = (float)(v60 + v30) + v30;
            *(v59 - 2) = (float)(v64 * *(float *)(v58 - 8)) + *(v59 - 2);
            v65 = v64 + v30;
            v60 = v65 + v30;
            *(v59 - 1) = (float)(v65 * *(float *)(v58 - 4)) + *(v59 - 1);
            --v63;
          }
          while ( v63 );
        }
        if ( v61 < uValidFrames )
        {
          v66 = v58 - (_QWORD)v59;
          v67 = uValidFrames - v61;
          do
          {
            v68 = v60;
            ++v59;
            v60 = v60 + v30;
            *(v59 - 1) = (float)(v68 * *(float *)((char *)v59 + v66 - 4)) + *(v59 - 1);
            --v67;
          }
          while ( v67 );
        }
        v55 = (float *)((char *)v55 + v57);
        --v14;
      }
      while ( v14 );
    }
    if ( (uChannelMask & 0x30) != 0 )
    {
      v69 = (float *)v9->pData;
      v70 = in_pBuffer->uMaxFrames;
      v71 = (char *)in_pBuffer->pData;
      v72 = (uChannelMask & 4 | 8) >> 2;
      v73 = 0;
      v74 = (float *)v9->pData;
      v75 = 4i64 * v9->uMaxFrames;
      do
      {
        v76 = v28;
        v77 = 0;
        v78 = (float *)&v71[4 * v70 * (v73 + v72)];
        v79 = v74;
        if ( uValidFrames >= 4 )
        {
          v80 = ((unsigned int)(uValidFrames - 4) >> 2) + 1;
          v81 = v80;
          v77 = 4 * v80;
          do
          {
            v79 += 4;
            v78 += 4;
            *(v79 - 4) = (float)(v76 * *(v78 - 4)) + *(v79 - 4);
            *(v79 - 3) = (float)((float)(v76 + v32) * *(v78 - 3)) + *(v79 - 3);
            v82 = (float)(v76 + v32) + v32;
            *(v79 - 2) = (float)(v82 * *(v78 - 2)) + *(v79 - 2);
            v83 = v82 + v32;
            v76 = v83 + v32;
            *(v79 - 1) = (float)(v83 * *(v78 - 1)) + *(v79 - 1);
            --v81;
          }
          while ( v81 );
        }
        if ( v77 < uValidFrames )
        {
          v84 = (char *)((char *)v78 - (char *)v79);
          v85 = uValidFrames - v77;
          do
          {
            v86 = v76;
            ++v79;
            v76 = v76 + v32;
            *(v79 - 1) = (float)(v86 * *(float *)((char *)v79 + (_QWORD)v84 - 4)) + *(v79 - 1);
            --v85;
          }
          while ( v85 );
        }
        ++v73;
        v74 = (float *)((char *)v74 + v75);
      }
      while ( v73 < 2 );
      if ( (uChannelMask & 0x600) != 0 )
      {
        for ( i = 0; i < 2; ++i )
        {
          v88 = v28;
          v89 = 0;
          v90 = (float *)&v71[4 * v70 * (i + v72 + 2)];
          v91 = v69;
          if ( uValidFrames >= 4 )
          {
            v92 = ((unsigned int)(uValidFrames - 4) >> 2) + 1;
            v93 = v92;
            v89 = 4 * v92;
            do
            {
              v91 += 4;
              v90 += 4;
              *(v91 - 4) = (float)(v88 * *(v90 - 4)) + *(v91 - 4);
              *(v91 - 3) = (float)((float)(v88 + v32) * *(v90 - 3)) + *(v91 - 3);
              v94 = (float)(v88 + v32) + v32;
              *(v91 - 2) = (float)(v94 * *(v90 - 2)) + *(v91 - 2);
              v95 = v94 + v32;
              v88 = v95 + v32;
              *(v91 - 1) = (float)(v95 * *(v90 - 1)) + *(v91 - 1);
              --v93;
            }
            while ( v93 );
          }
          if ( v89 < uValidFrames )
          {
            v96 = (char *)((char *)v90 - (char *)v91);
            v97 = uValidFrames - v89;
            do
            {
              v98 = v88;
              ++v91;
              v88 = v88 + v32;
              *(v91 - 1) = (float)(v98 * *(float *)((char *)v91 + (_QWORD)v96 - 4)) + *(v91 - 1);
              --v97;
            }
            while ( v97 );
          }
          v69 = (float *)((char *)v69 + v75);
        }
      }
    }
    if ( (uChannelMask & 8) != 0 && v114 )
    {
      v99 = v114;
      v100 = (float *)out_pDownMixBuffer->pData;
      v101 = 4i64 * out_pDownMixBuffer->uMaxFrames;
      do
      {
        LFE = AkAudioBuffer::GetLFE(in_pBuffer);
        v103 = v100;
        v104 = 0;
        v105 = v26;
        v106 = LFE;
        if ( uValidFrames >= 4 )
        {
          v107 = ((unsigned int)(uValidFrames - 4) >> 2) + 1;
          v108 = v107;
          v104 = 4 * v107;
          do
          {
            v103 += 4;
            v106 += 4;
            *(v103 - 4) = (float)(v105 * *(v106 - 4)) + *(v103 - 4);
            *(v103 - 3) = (float)((float)(v105 + v31) * *(v106 - 3)) + *(v103 - 3);
            v109 = (float)(v105 + v31) + v31;
            *(v103 - 2) = (float)(v109 * *(v106 - 2)) + *(v103 - 2);
            v110 = v109 + v31;
            v105 = v110 + v31;
            *(v103 - 1) = (float)(v110 * *(v106 - 1)) + *(v103 - 1);
            --v108;
          }
          while ( v108 );
        }
        if ( v104 < uValidFrames )
        {
          v111 = (char *)v106 - (char *)v103;
          v112 = uValidFrames - v104;
          do
          {
            v113 = v105;
            ++v103;
            v105 = v105 + v31;
            *(v103 - 1) = (float)(v113 * *(float *)((char *)v103 + v111 - 4)) + *(v103 - 1);
            --v112;
          }
          while ( v112 );
        }
        v100 = (float *)((char *)v100 + v101);
        --v99;
      }
      while ( v99 );
    }
  }
  else
  {
    for ( j = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++j;
    if ( j )
    {
      v17 = (unsigned int)(4 * uValidFrames);
      v18 = j;
      do
      {
        memmove((char *)v9->pData + 4 * v7 * v9->uMaxFrames, (char *)v10->pData + 4 * v7 * v10->uMaxFrames, v17);
        v10 = in_pBuffer;
        ++v7;
        --v18;
      }
      while ( v18 );
    }
  }
}-v99;
      }
      while ( v99 );
    }
  }
  else
  {
    for ( j = 0; uChannelMas

