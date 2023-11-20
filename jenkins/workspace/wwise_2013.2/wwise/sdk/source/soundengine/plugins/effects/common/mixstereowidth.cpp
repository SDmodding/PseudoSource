// File Line: 50
// RVA: 0xB18B50
void __fastcall DSP::MixStereoWidth(float *io_pfIn1Out, float *io_pfIn2Out, unsigned int in_uNumFrames, float in_fPrevStereoWidth, float in_fStereoWidth)
{
  float *v5; // r9
  float v6; // xmm6_4
  float v7; // xmm4_4
  __m128 v8; // xmm2
  float v9; // xmm7_4
  float v10; // xmm5_4
  __m128 v11; // xmm2
  float *v12; // r8
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  signed __int64 v28; // r9
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float *v32; // r8
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm3_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm4_4
  float v43; // xmm7_4
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm4_4
  float v51; // xmm3_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm7_4
  float v57; // xmm0_4
  float v58; // xmm4_4
  float v59; // xmm3_4
  float v60; // xmm2_4
  float v61; // xmm3_4
  float v62; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm7_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm3_4
  float v68; // xmm3_4
  float v69; // xmm2_4
  float v70; // xmm0_4
  float v71; // xmm3_4
  float v72; // xmm1_4
  float v73; // xmm0_4
  float v74; // xmm2_4

  v5 = io_pfIn2Out;
  v6 = 0.0;
  v8 = (__m128)(unsigned int)FLOAT_1_0;
  v7 = (float)((float)(in_fPrevStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v8.m128_f32[0] = 1.0 - (float)(v7 * v7);
  if ( v8.m128_f32[0] <= 0.0 )
    v9 = 0.0;
  else
    LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v8);
  v11 = (__m128)(unsigned int)FLOAT_1_0;
  v10 = (float)((float)(in_fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v11.m128_f32[0] = 1.0 - (float)(v10 * v10);
  if ( v11.m128_f32[0] > 0.0 )
    LODWORD(v6) = (unsigned __int128)_mm_sqrt_ps(v11);
  if ( v10 != v7 || v6 != v9 )
  {
    v31 = (float)(signed int)in_uNumFrames;
    v32 = &io_pfIn1Out[in_uNumFrames];
    v33 = (float)(v10 - v7) * (float)(1.0 / v31);
    v34 = (float)(v6 - v9) * (float)(1.0 / v31);
    if ( io_pfIn1Out < v32 )
    {
      if ( ((char *)v32 - (char *)io_pfIn1Out + 3) / 4 >= 4 )
      {
        do
        {
          v35 = *io_pfIn1Out;
          v36 = *v5;
          io_pfIn1Out += 4;
          v5 += 4;
          v37 = v35;
          v38 = v35 * v9;
          v39 = v36 * v9;
          v40 = v36 * v7;
          v41 = v37 * v7;
          v42 = v7 + v33;
          v43 = v9 + v34;
          v44 = v38 + v40;
          v45 = *(v5 - 3);
          *(v5 - 4) = v44;
          v46 = *(io_pfIn1Out - 3);
          *(io_pfIn1Out - 4) = v39 + v41;
          v47 = v45;
          v48 = v45 * v42;
          v49 = v46 * v42;
          v50 = v42 + v33;
          v51 = (float)(v46 * v43) + v48;
          v52 = *(v5 - 2);
          *(v5 - 3) = v51;
          v53 = *(io_pfIn1Out - 2);
          *(io_pfIn1Out - 3) = (float)(v47 * v43) + v49;
          v54 = v52;
          v55 = v52 * v50;
          v56 = v43 + v34;
          v57 = v53 * v50;
          v58 = v50 + v33;
          v59 = (float)(v53 * v56) + v55;
          v60 = *(v5 - 1);
          *(v5 - 2) = v59;
          v61 = *(io_pfIn1Out - 1);
          *(io_pfIn1Out - 2) = (float)(v54 * v56) + v57;
          v62 = v60;
          v63 = v60 * v58;
          v64 = v56 + v34;
          v65 = v61 * v58;
          v7 = v58 + v33;
          v66 = (float)(v62 * v64) + v65;
          v67 = (float)(v61 * v64) + v63;
          v9 = v64 + v34;
          *(io_pfIn1Out - 1) = v66;
          *(v5 - 1) = v67;
        }
        while ( (signed __int64)io_pfIn1Out < (signed __int64)(v32 - 3) );
      }
      for ( ; io_pfIn1Out < v32; *(v5 - 1) = v71 + v74 )
      {
        v68 = *io_pfIn1Out;
        v69 = *v5;
        ++io_pfIn1Out;
        ++v5;
        v70 = v68;
        v71 = v68 * v9;
        v72 = v69 * v9;
        v73 = v70 * v7;
        v74 = v69 * v7;
        v7 = v7 + v33;
        v9 = v9 + v34;
        *(io_pfIn1Out - 1) = v72 + v73;
      }
    }
  }
  else
  {
    v12 = &io_pfIn1Out[in_uNumFrames];
    if ( io_pfIn1Out < v12 )
    {
      if ( ((char *)v12 - (char *)io_pfIn1Out + 3) / 4 >= 4 )
      {
        do
        {
          v13 = *io_pfIn1Out;
          v14 = *v5;
          v15 = io_pfIn1Out[1];
          io_pfIn1Out += 4;
          v5 += 4;
          v16 = (float)(v14 * v6) + (float)(v13 * v10);
          v17 = (float)(v13 * v6) + (float)(v14 * v10);
          v18 = *(v5 - 3);
          *(io_pfIn1Out - 4) = v16;
          *(v5 - 4) = v17;
          v19 = *(io_pfIn1Out - 2);
          v20 = (float)(v18 * v6) + (float)(v15 * v10);
          v21 = (float)(v15 * v6) + (float)(v18 * v10);
          v22 = *(v5 - 2);
          v23 = *(io_pfIn1Out - 2) * v10;
          *(io_pfIn1Out - 3) = v20;
          *(v5 - 3) = v21;
          v24 = *(io_pfIn1Out - 1);
          v25 = v22;
          v26 = (float)(v19 * v6) + (float)(v22 * v10);
          v27 = *(v5 - 1);
          *(v5 - 2) = v26;
          *(io_pfIn1Out - 2) = (float)(v25 * v6) + v23;
          *(v5 - 1) = (float)(v24 * v6) + (float)(v27 * v10);
          *(io_pfIn1Out - 1) = (float)(v27 * v6) + (float)(v24 * v10);
        }
        while ( (signed __int64)io_pfIn1Out < (signed __int64)(v12 - 3) );
      }
      if ( io_pfIn1Out < v12 )
      {
        v28 = (char *)v5 - (char *)io_pfIn1Out;
        do
        {
          v29 = *io_pfIn1Out;
          v30 = *(float *)((char *)io_pfIn1Out + v28);
          ++io_pfIn1Out;
          *(io_pfIn1Out - 1) = (float)(v30 * v6) + (float)(v29 * v10);
          *(float *)((char *)io_pfIn1Out + v28 - 4) = (float)(v29 * v6) + (float)(v30 * v10);
        }
        while ( io_pfIn1Out < v12 );
      }
    }
  }
}

// File Line: 97
// RVA: 0xB18F10
void __fastcall DSP::MixStereoWidth(float *in_pfIn1, float *in_pfIn2, float *out_pfOut1, float *out_pfOut2, unsigned int in_uNumFrames, float in_fPrevStereoWidth, float in_fStereoWidth)
{
  float v7; // xmm6_4
  float *v8; // r11
  float *v9; // r10
  float v10; // xmm4_4
  __m128 v11; // xmm2
  float v12; // xmm7_4
  float v13; // xmm5_4
  __m128 v14; // xmm2
  float *v15; // rcx
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  signed __int64 v31; // r11
  char *v32; // r8
  char *v33; // r9
  float v34; // xmm3_4
  float v35; // xmm2_4
  float *v36; // rcx
  float v37; // xmm1_4
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm4_4
  float v48; // xmm7_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm4_4
  float v56; // xmm3_4
  float v57; // xmm2_4
  float v58; // xmm3_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm7_4
  float v62; // xmm0_4
  float v63; // xmm4_4
  float v64; // xmm3_4
  float v65; // xmm2_4
  float v66; // xmm3_4
  float v67; // xmm1_4
  float v68; // xmm2_4
  float v69; // xmm7_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm3_4
  signed __int64 v73; // r11
  signed __int64 v74; // r9
  float v75; // xmm3_4
  float v76; // xmm2_4
  float v77; // xmm0_4
  float v78; // xmm1_4
  float v79; // xmm3_4
  float v80; // xmm2_4
  float v81; // xmm1_4
  float v82; // xmm0_4

  v7 = 0.0;
  v8 = in_pfIn2;
  v11 = (__m128)(unsigned int)FLOAT_1_0;
  v9 = in_pfIn1;
  v10 = (float)((float)(in_fPrevStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v11.m128_f32[0] = 1.0 - (float)(v10 * v10);
  if ( v11.m128_f32[0] <= 0.0 )
    v12 = 0.0;
  else
    LODWORD(v12) = (unsigned __int128)_mm_sqrt_ps(v11);
  v14 = (__m128)(unsigned int)FLOAT_1_0;
  v13 = (float)((float)(in_fStereoWidth * 0.0055555557) * 0.29289401) + 0.70710599;
  v14.m128_f32[0] = 1.0 - (float)(v13 * v13);
  if ( v14.m128_f32[0] > 0.0 )
    LODWORD(v7) = (unsigned __int128)_mm_sqrt_ps(v14);
  if ( v13 != v10 || v7 != v12 )
  {
    v36 = &in_pfIn1[in_uNumFrames];
    v37 = 1.0 / (float)(signed int)in_uNumFrames;
    v38 = (float)(v13 - v10) * v37;
    v39 = (float)(v7 - v12) * v37;
    if ( v9 < v36 )
    {
      if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v40 = *v9;
          v41 = *v8;
          v9 += 4;
          out_pfOut1 += 4;
          v8 += 4;
          out_pfOut2 += 4;
          v42 = v40;
          v43 = v40 * v12;
          v44 = v41 * v12;
          v45 = v41 * v10;
          v46 = v42 * v10;
          v47 = v10 + v38;
          v48 = v12 + v39;
          v49 = v43 + v45;
          v50 = *(v8 - 3);
          *(out_pfOut2 - 4) = v49;
          v51 = *(v9 - 3);
          *(out_pfOut1 - 4) = v44 + v46;
          v52 = v50;
          v53 = v50 * v47;
          v54 = v51 * v47;
          v55 = v47 + v38;
          v56 = (float)(v51 * v48) + v53;
          v57 = *(v8 - 2);
          *(out_pfOut2 - 3) = v56;
          v58 = *(v9 - 2);
          *(out_pfOut1 - 3) = (float)(v52 * v48) + v54;
          v59 = v57;
          v60 = v57 * v55;
          v61 = v48 + v39;
          v62 = v58 * v55;
          v63 = v55 + v38;
          v64 = (float)(v58 * v61) + v60;
          v65 = *(v8 - 1);
          *(out_pfOut2 - 2) = v64;
          v66 = *(v9 - 1);
          *(out_pfOut1 - 2) = (float)(v59 * v61) + v62;
          v67 = v65;
          v68 = v65 * v63;
          v69 = v61 + v39;
          v70 = v66 * v63;
          v10 = v63 + v38;
          v71 = (float)(v67 * v69) + v70;
          v72 = (float)(v66 * v69) + v68;
          v12 = v69 + v39;
          *(out_pfOut1 - 1) = v71;
          *(out_pfOut2 - 1) = v72;
        }
        while ( (signed __int64)v9 < (signed __int64)(v36 - 3) );
      }
      if ( v9 < v36 )
      {
        v73 = (char *)v8 - (char *)out_pfOut1;
        v74 = (char *)out_pfOut2 - (char *)out_pfOut1;
        do
        {
          v75 = *v9;
          v76 = *(float *)((char *)out_pfOut1 + v73);
          ++v9;
          ++out_pfOut1;
          v77 = v75;
          v78 = v76;
          v79 = v75 * v12;
          v80 = v76 * v10;
          v81 = v78 * v12;
          v82 = v77 * v10;
          v10 = v10 + v38;
          v12 = v12 + v39;
          *(out_pfOut1 - 1) = v81 + v82;
          *(float *)((char *)out_pfOut1 + v74 - 4) = v79 + v80;
        }
        while ( v9 < v36 );
      }
    }
  }
  else
  {
    v15 = &in_pfIn1[in_uNumFrames];
    if ( v9 < v15 )
    {
      if ( ((char *)v15 - (char *)v9 + 3) / 4 >= 4 )
      {
        do
        {
          v16 = *v9;
          v17 = *v8;
          v18 = v9[1];
          v9 += 4;
          out_pfOut1 += 4;
          v8 += 4;
          out_pfOut2 += 4;
          v19 = (float)(v17 * v7) + (float)(v16 * v13);
          v20 = (float)(v16 * v7) + (float)(v17 * v13);
          v21 = *(v8 - 3);
          *(out_pfOut1 - 4) = v19;
          *(out_pfOut2 - 4) = v20;
          v22 = *(v9 - 2);
          v23 = (float)(v21 * v7) + (float)(v18 * v13);
          v24 = (float)(v18 * v7) + (float)(v21 * v13);
          v25 = *(v8 - 2);
          v26 = *(v9 - 2) * v13;
          *(out_pfOut1 - 3) = v23;
          *(out_pfOut2 - 3) = v24;
          v27 = *(v9 - 1);
          v28 = v25;
          v29 = (float)(v22 * v7) + (float)(v25 * v13);
          v30 = *(v8 - 1);
          *(out_pfOut2 - 2) = v29;
          *(out_pfOut1 - 2) = (float)(v28 * v7) + v26;
          *(out_pfOut2 - 1) = (float)(v27 * v7) + (float)(v30 * v13);
          *(out_pfOut1 - 1) = (float)(v30 * v7) + (float)(v27 * v13);
        }
        while ( (signed __int64)v9 < (signed __int64)(v15 - 3) );
      }
      if ( v9 < v15 )
      {
        v31 = (char *)v8 - (char *)v9;
        v32 = (char *)((char *)out_pfOut1 - (char *)v9);
        v33 = (char *)((char *)out_pfOut2 - (char *)v9);
        do
        {
          v34 = *v9;
          v35 = *(float *)((char *)v9 + v31);
          ++v9;
          *(float *)((char *)v9 + (_QWORD)v32 - 4) = (float)(v35 * v7) + (float)(v34 * v13);
          *(float *)((char *)v9 + (_QWORD)v33 - 4) = (float)(v34 * v7) + (float)(v35 * v13);
        }
        while ( v9 < v15 );
      }
    }
  }
}

// File Line: 136
// RVA: 0xB19310
void __fastcall DSP::MixStereoWidth(AkAudioBuffer *io_pBuffer, float in_fPrevStereoWidth, float in_fStereoWidth)
{
  unsigned int v3; // edi
  unsigned int v4; // esi
  AkAudioBuffer *v5; // rbx
  unsigned int v6; // ebp

  v3 = io_pBuffer->uChannelMask;
  v4 = io_pBuffer->uValidFrames;
  v5 = io_pBuffer;
  if ( v3 & 3 )
    DSP::MixStereoWidth(
      (float *)io_pBuffer->pData,
      (float *)io_pBuffer->pData + io_pBuffer->uMaxFrames,
      v4,
      in_fPrevStereoWidth,
      in_fStereoWidth);
  if ( v3 & 0x30 )
  {
    v6 = 2;
    if ( v3 & 4 )
      v6 = 3;
    DSP::MixStereoWidth(
      (float *)v5->pData + v5->uMaxFrames * (unsigned __int64)v6,
      (float *)v5->pData + v5->uMaxFrames * (unsigned __int64)(v6 + 1),
      v4,
      in_fPrevStereoWidth,
      in_fStereoWidth);
    if ( v3 & 0x600 )
      DSP::MixStereoWidth(
        (float *)v5->pData + v5->uMaxFrames * (unsigned __int64)(v6 + 2),
        (float *)v5->pData + v5->uMaxFrames * (unsigned __int64)(v6 + 3),
        v4,
        in_fPrevStereoWidth,
        in_fStereoWidth);
  }
}

