// File Line: 29
// RVA: 0xB19410
void __fastcall DSP::AkDownMix(AkAudioBuffer *in_pBuffer, AkAudioBuffer *out_pDownMixBuffer, float in_fPrevInputCenterLevel, float in_fInputCenterLevel, float in_fPrevInputLFELevel, float in_fInputLFELevel)
{
  unsigned int v6; // edi
  __int64 v7; // r15
  float v8; // xmm0_4
  AkAudioBuffer *v9; // rbp
  AkAudioBuffer *v10; // r11
  unsigned int v11; // er9
  unsigned int i; // er8
  signed int v13; // ebx
  signed __int64 v14; // r12
  unsigned int v15; // er8
  unsigned int j; // ecx
  size_t v17; // rdi
  __int64 v18; // rbx
  signed int v19; // edx
  unsigned int v20; // ecx
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
  __int64 v33; // r14
  float *v34; // r10
  float *v35; // r11
  signed __int64 v36; // rbp
  signed __int64 v37; // r14
  __int64 v38; // rsi
  float *v39; // rcx
  float *v40; // rdx
  float v41; // xmm2_4
  unsigned int v42; // er9
  unsigned int v43; // eax
  __int64 v44; // r8
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm1_4
  signed __int64 v53; // rdx
  __int64 v54; // r8
  float v55; // xmm0_4
  float *v56; // r10
  signed __int64 v57; // rsi
  signed __int64 v58; // r11
  signed __int64 v59; // rdx
  float *v60; // rcx
  float v61; // xmm1_4
  unsigned int v62; // er9
  unsigned int v63; // eax
  __int64 v64; // r8
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm0_4
  signed __int64 v70; // rdx
  __int64 v71; // r8
  float v72; // xmm0_4
  float *v73; // rsi
  __int64 v74; // r14
  char *v75; // r12
  unsigned int v76; // er13
  unsigned int v77; // er10
  float *v78; // r11
  signed __int64 v79; // rbp
  float v80; // xmm1_4
  unsigned int v81; // er9
  float *v82; // rdx
  float *v83; // rcx
  unsigned int v84; // eax
  __int64 v85; // r8
  float v86; // xmm0_4
  float v87; // xmm1_4
  float v88; // xmm0_4
  float v89; // xmm1_4
  float v90; // xmm0_4
  signed __int64 v91; // rdx
  __int64 v92; // r8
  float v93; // xmm0_4
  unsigned int v94; // er9
  float v95; // xmm1_4
  unsigned int v96; // er10
  float *v97; // rdx
  float *v98; // rcx
  unsigned int v99; // eax
  __int64 v100; // r8
  float v101; // xmm0_4
  float v102; // xmm1_4
  float v103; // xmm0_4
  float v104; // xmm1_4
  float v105; // xmm0_4
  signed __int64 v106; // rdx
  __int64 v107; // r8
  float v108; // xmm0_4
  __int64 v109; // rsi
  float *v110; // rdi
  signed __int64 v111; // rbp
  float *v112; // rax
  float *v113; // rdx
  unsigned int v114; // ecx
  float v115; // xmm1_4
  float *v116; // r8
  unsigned int v117; // ecx
  __int64 v118; // rax
  float v119; // xmm0_4
  float v120; // xmm1_4
  float v121; // xmm0_4
  float v122; // xmm1_4
  float v123; // xmm0_4
  char *v124; // r8
  __int64 v125; // rcx
  float v126; // xmm0_4
  unsigned int v127; // [rsp+24h] [rbp-84h]
  AkAudioBuffer *v128; // [rsp+B0h] [rbp+8h]
  AkAudioBuffer *v129; // [rsp+B8h] [rbp+10h]

  v129 = out_pDownMixBuffer;
  v128 = in_pBuffer;
  v6 = in_pBuffer->uChannelMask;
  v7 = 0i64;
  v8 = in_fInputCenterLevel;
  v9 = out_pDownMixBuffer;
  v10 = in_pBuffer;
  v11 = 0;
  for ( i = in_pBuffer->uChannelMask & 0xFFFFFFF7; i; i &= i - 1 )
    ++v11;
  v13 = in_pBuffer->uValidFrames;
  v14 = 2i64;
  v15 = 2;
  if ( v11 < 2 )
    v15 = v11;
  v127 = v15;
  if ( (v6 - 3) & 0xFFFFFFFA || v6 == 7 )
  {
    v19 = 0;
    v20 = in_pBuffer->uChannelMask & 0x33;
    if ( v6 & 0x33 )
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
    if ( v6 & 4 )
    {
      if ( (v6 & 7) == 7 )
      {
        v24 = in_fPrevInputCenterLevel * in_fPrevInputCenterLevel;
        v22 = v8 * v8;
      }
      else
      {
        v23 = v23 + 1.0;
      }
    }
    if ( v6 & 8 )
    {
      v26 = in_fPrevInputLFELevel * in_fPrevInputLFELevel;
      v25 = in_fInputLFELevel * in_fInputLFELevel;
    }
    v27 = (__m128)(unsigned int)FLOAT_1_0;
    v27.m128_f32[0] = 1.0 / (float)((float)(v24 + v23) + v26);
    LODWORD(v28) = (unsigned __int128)_mm_sqrt_ps(v27);
    v29 = 1.0 / (float)v13;
    v21.m128_f32[0] = 1.0 / (float)((float)(v22 + v23) + v25);
    v30 = (float)(v22 - v24) * v29;
    v31 = (float)(v25 - v26) * v29;
    v32 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v21)) - v28) * v29;
    if ( v15 )
    {
      v33 = v10->uMaxFrames;
      v34 = (float *)v129->pData;
      v35 = (float *)v10->pData;
      v36 = 4i64 * v9->uMaxFrames;
      v37 = 4 * v33;
      v38 = v15;
      do
      {
        v39 = v35;
        v40 = v34;
        v41 = v28;
        v42 = 0;
        if ( v13 >= 4 )
        {
          v43 = ((unsigned int)(v13 - 4) >> 2) + 1;
          v44 = v43;
          v42 = 4 * v43;
          do
          {
            v45 = v41;
            v46 = v41 + v32;
            v40 += 4;
            v39 += 4;
            v47 = v46;
            v48 = v46 + v32;
            v49 = v47 * *(v39 - 3);
            *(v40 - 4) = v45 * *(v39 - 4);
            v50 = v48 * *(v39 - 2);
            *(v40 - 3) = v49;
            v51 = v48 + v32;
            v41 = (float)(v48 + v32) + v32;
            v52 = v51 * *(v39 - 1);
            *(v40 - 2) = v50;
            *(v40 - 1) = v52;
            --v44;
          }
          while ( v44 );
        }
        if ( v42 < v13 )
        {
          v53 = (char *)v40 - (char *)v39;
          v54 = v13 - v42;
          do
          {
            v55 = v41;
            ++v39;
            v41 = v41 + v32;
            *(float *)((char *)v39 + v53 - 4) = v55 * *(v39 - 1);
            --v54;
          }
          while ( v54 );
        }
        v35 = (float *)((char *)v35 + v37);
        v34 = (float *)((char *)v34 + v36);
        --v38;
      }
      while ( v38 );
      v9 = v129;
      v10 = v128;
    }
    if ( (v6 & 7) == 7 )
    {
      v56 = (float *)v9->pData;
      v57 = (signed __int64)v10->pData + 8 * v10->uMaxFrames;
      v58 = 4i64 * v9->uMaxFrames;
      do
      {
        v59 = v57;
        v60 = v56;
        v61 = v24;
        v62 = 0;
        if ( v13 >= 4 )
        {
          v63 = ((unsigned int)(v13 - 4) >> 2) + 1;
          v64 = v63;
          v62 = 4 * v63;
          do
          {
            v65 = v61;
            v66 = v61 + v30;
            v60 += 4;
            v59 += 16i64;
            *(v60 - 4) = (float)(v65 * *(float *)(v59 - 16)) + *(v60 - 4);
            v67 = v66;
            v68 = v66 + v30;
            *(v60 - 3) = (float)(v67 * *(float *)(v59 - 12)) + *(v60 - 3);
            *(v60 - 2) = (float)(v68 * *(float *)(v59 - 8)) + *(v60 - 2);
            v69 = v68 + v30;
            v61 = (float)(v68 + v30) + v30;
            *(v60 - 1) = (float)(v69 * *(float *)(v59 - 4)) + *(v60 - 1);
            --v64;
          }
          while ( v64 );
        }
        if ( v62 < v13 )
        {
          v70 = v59 - (_QWORD)v60;
          v71 = v13 - v62;
          do
          {
            v72 = v61;
            ++v60;
            v61 = v61 + v30;
            *(v60 - 1) = (float)(v72 * *(float *)((char *)v60 + v70 - 4)) + *(v60 - 1);
            --v71;
          }
          while ( v71 );
        }
        v56 = (float *)((char *)v56 + v58);
        --v14;
      }
      while ( v14 );
    }
    if ( v6 & 0x30 )
    {
      v73 = (float *)v9->pData;
      v74 = v128->uMaxFrames;
      v75 = (char *)v128->pData;
      v76 = (v6 & 4 | 8) >> 2;
      v77 = 0;
      v78 = (float *)v9->pData;
      v79 = 4i64 * v9->uMaxFrames;
      do
      {
        v80 = v28;
        v81 = 0;
        v82 = (float *)&v75[4 * v74 * (v77 + v76)];
        v83 = v78;
        if ( v13 >= 4 )
        {
          v84 = ((unsigned int)(v13 - 4) >> 2) + 1;
          v85 = v84;
          v81 = 4 * v84;
          do
          {
            v86 = v80;
            v87 = v80 + v32;
            v83 += 4;
            v82 += 4;
            *(v83 - 4) = (float)(v86 * *(v82 - 4)) + *(v83 - 4);
            v88 = v87;
            v89 = v87 + v32;
            *(v83 - 3) = (float)(v88 * *(v82 - 3)) + *(v83 - 3);
            *(v83 - 2) = (float)(v89 * *(v82 - 2)) + *(v83 - 2);
            v90 = v89 + v32;
            v80 = (float)(v89 + v32) + v32;
            *(v83 - 1) = (float)(v90 * *(v82 - 1)) + *(v83 - 1);
            --v85;
          }
          while ( v85 );
        }
        if ( v81 < v13 )
        {
          v91 = (char *)v82 - (char *)v83;
          v92 = v13 - v81;
          do
          {
            v93 = v80;
            ++v83;
            v80 = v80 + v32;
            *(v83 - 1) = (float)(v93 * *(float *)((char *)v83 + v91 - 4)) + *(v83 - 1);
            --v92;
          }
          while ( v92 );
        }
        ++v77;
        v78 = (float *)((char *)v78 + v79);
      }
      while ( v77 < 2 );
      if ( v6 & 0x600 )
      {
        v94 = 0;
        do
        {
          v95 = v28;
          v96 = 0;
          v97 = (float *)&v75[4 * v74 * (v94 + v76 + 2)];
          v98 = v73;
          if ( v13 >= 4 )
          {
            v99 = ((unsigned int)(v13 - 4) >> 2) + 1;
            v100 = v99;
            v96 = 4 * v99;
            do
            {
              v101 = v95;
              v102 = v95 + v32;
              v98 += 4;
              v97 += 4;
              *(v98 - 4) = (float)(v101 * *(v97 - 4)) + *(v98 - 4);
              v103 = v102;
              v104 = v102 + v32;
              *(v98 - 3) = (float)(v103 * *(v97 - 3)) + *(v98 - 3);
              *(v98 - 2) = (float)(v104 * *(v97 - 2)) + *(v98 - 2);
              v105 = v104 + v32;
              v95 = (float)(v104 + v32) + v32;
              *(v98 - 1) = (float)(v105 * *(v97 - 1)) + *(v98 - 1);
              --v100;
            }
            while ( v100 );
          }
          if ( v96 < v13 )
          {
            v106 = (char *)v97 - (char *)v98;
            v107 = v13 - v96;
            do
            {
              v108 = v95;
              ++v98;
              v95 = v95 + v32;
              *(v98 - 1) = (float)(v108 * *(float *)((char *)v98 + v106 - 4)) + *(v98 - 1);
              --v107;
            }
            while ( v107 );
          }
          ++v94;
          v73 = (float *)((char *)v73 + v79);
        }
        while ( v94 < 2 );
      }
    }
    if ( v6 & 8 && v127 )
    {
      v109 = v127;
      v110 = (float *)v129->pData;
      v111 = 4i64 * v129->uMaxFrames;
      do
      {
        v112 = AkAudioBuffer::GetLFE(v128);
        v113 = v110;
        v114 = 0;
        v115 = v26;
        v116 = v112;
        if ( v13 >= 4 )
        {
          v117 = ((unsigned int)(v13 - 4) >> 2) + 1;
          v118 = v117;
          v114 = 4 * v117;
          do
          {
            v119 = v115;
            v120 = v115 + v31;
            v113 += 4;
            v116 += 4;
            *(v113 - 4) = (float)(v119 * *(v116 - 4)) + *(v113 - 4);
            v121 = v120;
            v122 = v120 + v31;
            *(v113 - 3) = (float)(v121 * *(v116 - 3)) + *(v113 - 3);
            *(v113 - 2) = (float)(v122 * *(v116 - 2)) + *(v113 - 2);
            v123 = v122 + v31;
            v115 = (float)(v122 + v31) + v31;
            *(v113 - 1) = (float)(v123 * *(v116 - 1)) + *(v113 - 1);
            --v118;
          }
          while ( v118 );
        }
        if ( v114 < v13 )
        {
          v124 = (char *)((char *)v116 - (char *)v113);
          v125 = v13 - v114;
          do
          {
            v126 = v115;
            ++v113;
            v115 = v115 + v31;
            *(v113 - 1) = (float)(v126 * *(float *)((char *)v113 + (_QWORD)v124 - 4)) + *(v113 - 1);
            --v125;
          }
          while ( v125 );
        }
        v110 = (float *)((char *)v110 + v111);
        --v109;
      }
      while ( v109 );
    }
  }
  else
  {
    for ( j = 0; v6; v6 &= v6 - 1 )
      ++j;
    if ( j )
    {
      v17 = (unsigned int)(4 * v13);
      v18 = j;
      do
      {
        memmove((char *)v9->pData + 4 * v7 * v9->uMaxFrames, (char *)v10->pData + 4 * v7 * v10->uMaxFrames, v17);
        v10 = v128;
        ++v7;
        --v18;
      }
      while ( v18 );
    }
  }
}

