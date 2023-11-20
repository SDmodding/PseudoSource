// File Line: 36
// RVA: 0xAE9820
void __usercall DSP::Mix3Interp(float *in_pfInput1@<rcx>, float *in_pfInput2@<rdx>, float *in_pfInput3@<r8>, float *out_pfOutput@<r9>, __m128 a5@<xmm2>, float in_fCurrentGain1, float in_fTargetGain1, float in_fCurrentGain2, float in_fTargetGain2, float in_fCurrentGain3, float in_fTargetGain3, unsigned int in_uNumFrames)
{
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float *v15; // r10
  float *v16; // r11
  __m128 v17; // xmm2
  __m128 v18; // xmm5
  float *v19; // rcx
  __m128 v20; // xmm4
  signed __int64 v21; // r11
  signed __int64 v22; // r8
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  float *v25; // rcx
  float v26; // xmm1_4
  float v27; // xmm8_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm3_4
  float v46; // xmm2_4
  float v47; // xmm5_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm3_4
  float v53; // xmm2_4
  float v54; // xmm5_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  signed __int64 v61; // r11
  signed __int64 v62; // r10
  float v63; // xmm2_4
  float v64; // xmm0_4
  float v65; // xmm1_4

  v12 = in_fCurrentGain1;
  v13 = in_fCurrentGain3;
  v14 = in_fCurrentGain2;
  v15 = in_pfInput2;
  v16 = in_pfInput1;
  if ( in_fTargetGain1 != in_fCurrentGain1 || in_fTargetGain2 != in_fCurrentGain2 || in_fTargetGain3 != in_fCurrentGain3 )
  {
    v25 = &out_pfOutput[in_uNumFrames];
    v26 = 1.0 / (float)(signed int)in_uNumFrames;
    v27 = (float)(in_fTargetGain1 - in_fCurrentGain1) * v26;
    v28 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v26;
    v29 = (float)(in_fTargetGain3 - in_fCurrentGain3) * v26;
    if ( out_pfOutput < v25 )
    {
      if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v30 = v12;
          v31 = v14;
          v32 = v13;
          v33 = v12 + v27;
          v34 = v14 + v28;
          v35 = v13 + v29;
          out_pfOutput += 4;
          v36 = v30 * *v16;
          v37 = v31 * *v15;
          v38 = v32 * *in_pfInput3;
          v16 += 4;
          v15 += 4;
          in_pfInput3 += 4;
          v39 = v36 + v37;
          v40 = v34;
          v41 = v39 + v38;
          v42 = v34 + v28;
          v43 = v40 * *(v15 - 3);
          v44 = v35 * *(in_pfInput3 - 3);
          *(out_pfOutput - 4) = v41;
          v45 = v35 + v29;
          v46 = v33 * *(v16 - 3);
          v47 = v33 + v27;
          v48 = v46 + v43;
          v49 = v42 * *(v15 - 2);
          v50 = v48 + v44;
          v51 = v45;
          *(out_pfOutput - 3) = v50;
          v52 = v45 + v29;
          v53 = v47 * *(v16 - 2);
          v54 = v47 + v27;
          v55 = v53 + v49;
          v56 = v42 + v28;
          v57 = v55 + (float)(v51 * *(in_pfInput3 - 2));
          v14 = (float)(v42 + v28) + v28;
          v58 = v56 * *(v15 - 1);
          v59 = v52 * *(in_pfInput3 - 1);
          *(out_pfOutput - 2) = v57;
          v13 = v52 + v29;
          v60 = v54 * *(v16 - 1);
          v12 = v54 + v27;
          *(out_pfOutput - 1) = (float)(v60 + v58) + v59;
        }
        while ( (signed __int64)out_pfOutput < (signed __int64)(v25 - 3) );
      }
      if ( out_pfOutput < v25 )
      {
        v61 = (char *)v16 - (char *)in_pfInput3;
        v62 = (char *)v15 - (char *)in_pfInput3;
        do
        {
          v63 = v14;
          v64 = v12;
          v65 = v13;
          ++out_pfOutput;
          ++in_pfInput3;
          v12 = v12 + v27;
          v14 = v14 + v28;
          v13 = v13 + v29;
          *(out_pfOutput - 1) = (float)((float)(v63 * *(float *)((char *)in_pfInput3 + v62 - 4))
                                      + (float)(v64 * *(float *)((char *)in_pfInput3 + v61 - 4)))
                              + (float)(v65 * *(in_pfInput3 - 1));
        }
        while ( out_pfOutput < v25 );
      }
    }
  }
  else
  {
    a5.m128_f32[0] = in_fCurrentGain1;
    v17 = _mm_shuffle_ps(a5, a5, 0);
    v18 = _mm_shuffle_ps((__m128)LODWORD(in_fCurrentGain2), (__m128)LODWORD(in_fCurrentGain2), 0);
    v19 = &out_pfOutput[in_uNumFrames];
    v20 = _mm_shuffle_ps((__m128)LODWORD(in_fCurrentGain3), (__m128)LODWORD(in_fCurrentGain3), 0);
    if ( out_pfOutput < v19 )
    {
      v21 = (char *)v16 - (char *)in_pfInput2;
      v22 = (char *)in_pfInput3 - (char *)in_pfInput2;
      do
      {
        v23 = *(__m128 *)((char *)v15 + v21);
        v24 = *(__m128 *)v15;
        out_pfOutput += 4;
        v15 += 4;
        *((__m128 *)out_pfOutput - 1) = _mm_add_ps(
                                          _mm_add_ps(_mm_mul_ps(v23, v17), _mm_mul_ps(v24, v18)),
                                          _mm_mul_ps(*(__m128 *)((char *)v15 + v22 - 16), v20));
      }
      while ( out_pfOutput < v19 );
    }
  }
}

// File Line: 125
// RVA: 0xAE9AC0
void __usercall DSP::Mix3Interp(float *io_pfIn1Out@<rcx>, float *in_pfInput2@<rdx>, float *in_pfInput3@<r8>, __int128 in_fCurrentGain1@<xmm3>, __m128 a5@<xmm2>, float in_fTargetGain1, float in_fCurrentGain2, float in_fTargetGain2, float in_fCurrentGain3, float in_fTargetGain3, unsigned int in_uNumFrames)
{
  float v11; // xmm4_4
  float v12; // xmm5_4
  float *v13; // r10
  float *v14; // r9
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  float *v17; // rcx
  __m128 v18; // xmm5
  char *v19; // r10
  char *v20; // r8
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  float *v23; // rcx
  float v24; // xmm1_4
  float v25; // xmm8_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm5_4
  float v46; // xmm2_4
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm4_4
  float v51; // xmm2_4
  float v52; // xmm5_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  signed __int64 v59; // r10
  float v60; // xmm2_4
  float v61; // xmm0_4
  float v62; // xmm1_4

  v11 = in_fCurrentGain3;
  v12 = in_fCurrentGain2;
  v13 = in_pfInput2;
  v14 = io_pfIn1Out;
  if ( in_fTargetGain1 != *(float *)&in_fCurrentGain1
    || in_fTargetGain2 != in_fCurrentGain2
    || in_fTargetGain3 != in_fCurrentGain3 )
  {
    v23 = &io_pfIn1Out[in_uNumFrames];
    v24 = 1.0 / (float)(signed int)in_uNumFrames;
    v25 = (float)(in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v24;
    v26 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v24;
    v27 = (float)(in_fTargetGain3 - in_fCurrentGain3) * v24;
    if ( v14 < v23 )
    {
      if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v28 = *(float *)&in_fCurrentGain1;
          v29 = v12;
          v30 = v11;
          v31 = *(float *)&in_fCurrentGain1 + v25;
          v32 = v12 + v26;
          v33 = v11 + v27;
          v34 = v28 * *v14;
          v35 = v29 * *v13;
          v36 = v30 * *in_pfInput3;
          v14 += 4;
          v13 += 4;
          in_pfInput3 += 4;
          v37 = v34 + v35;
          v38 = v31;
          v39 = v37 + v36;
          v40 = v31 + v25;
          v41 = v38 * *(v14 - 3);
          v42 = v33 * *(in_pfInput3 - 3);
          *(v14 - 4) = v39;
          v43 = v33 + v27;
          v44 = v32 * *(v13 - 3);
          v45 = v32 + v26;
          v46 = v44 + v41;
          v47 = v40 * *(v14 - 2);
          v48 = v46 + v42;
          v49 = v43;
          *(v14 - 3) = v48;
          v50 = v43 + v27;
          v51 = v45 * *(v13 - 2);
          v52 = v45 + v26;
          v53 = v51 + v47;
          v54 = v40 + v25;
          v55 = v53 + (float)(v49 * *(in_pfInput3 - 2));
          *(float *)&in_fCurrentGain1 = (float)(v40 + v25) + v25;
          v56 = v54 * *(v14 - 1);
          v57 = v50 * *(in_pfInput3 - 1);
          *(v14 - 2) = v55;
          v11 = v50 + v27;
          v58 = v52 * *(v13 - 1);
          v12 = v52 + v26;
          *(v14 - 1) = (float)(v58 + v56) + v57;
        }
        while ( (signed __int64)v14 < (signed __int64)(v23 - 3) );
      }
      if ( v14 < v23 )
      {
        v59 = (char *)v13 - (char *)in_pfInput3;
        do
        {
          v60 = v12;
          v61 = *(float *)&in_fCurrentGain1;
          v62 = v11;
          ++v14;
          ++in_pfInput3;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v25;
          v12 = v12 + v26;
          v11 = v11 + v27;
          *(v14 - 1) = (float)((float)(v60 * *(float *)((char *)in_pfInput3 + v59 - 4)) + (float)(v61 * *(v14 - 1)))
                     + (float)(v62 * *(in_pfInput3 - 1));
        }
        while ( v14 < v23 );
      }
    }
  }
  else
  {
    a5.m128_f32[0] = *(float *)&in_fCurrentGain1;
    *(float *)&in_fCurrentGain1 = in_fCurrentGain2;
    v15 = _mm_shuffle_ps(a5, a5, 0);
    v16 = _mm_shuffle_ps((__m128)in_fCurrentGain1, (__m128)in_fCurrentGain1, 0);
    v17 = &io_pfIn1Out[in_uNumFrames];
    v18 = _mm_shuffle_ps((__m128)LODWORD(in_fCurrentGain3), (__m128)LODWORD(in_fCurrentGain3), 0);
    if ( v14 < v17 )
    {
      v19 = (char *)((char *)in_pfInput2 - (char *)v14);
      v20 = (char *)((char *)in_pfInput3 - (char *)v14);
      do
      {
        v21 = *(__m128 *)v14;
        v22 = *(__m128 *)((char *)v14 + (_QWORD)v19);
        v14 += 4;
        *((__m128 *)v14 - 1) = _mm_add_ps(
                                 _mm_add_ps(_mm_mul_ps(v22, v16), _mm_mul_ps(v21, v15)),
                                 _mm_mul_ps(*(__m128 *)((char *)v14 + (_QWORD)v20 - 16), v18));
      }
      while ( v14 < v17 );
    }
  }
}

