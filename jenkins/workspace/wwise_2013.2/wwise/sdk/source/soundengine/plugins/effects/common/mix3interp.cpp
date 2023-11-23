// File Line: 36
// RVA: 0xAE9820
void __fastcall DSP::Mix3Interp(
        float *in_pfInput1,
        float *in_pfInput2,
        float *in_pfInput3,
        __m128 *out_pfOutput,
        float in_fCurrentGain1,
        float in_fTargetGain1,
        float in_fCurrentGain2,
        float in_fTargetGain2,
        float in_fCurrentGain3,
        float in_fTargetGain3,
        signed int in_uNumFrames)
{
  __m128 v11; // xmm2
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float *v15; // r10
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
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm5_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm4_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm5_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  signed __int64 v57; // r11
  signed __int64 v58; // r10
  float v59; // xmm2_4
  float v60; // xmm0_4
  float v61; // xmm1_4

  v12 = in_fCurrentGain1;
  v13 = in_fCurrentGain3;
  v14 = in_fCurrentGain2;
  v15 = in_pfInput2;
  if ( in_fTargetGain1 == in_fCurrentGain1 && in_fTargetGain2 == in_fCurrentGain2 && in_fTargetGain3 == in_fCurrentGain3 )
  {
    v11.m128_f32[0] = in_fCurrentGain1;
    v17 = _mm_shuffle_ps(v11, v11, 0);
    v18 = _mm_shuffle_ps((__m128)LODWORD(in_fCurrentGain2), (__m128)LODWORD(in_fCurrentGain2), 0);
    v19 = &out_pfOutput->m128_f32[in_uNumFrames];
    v20 = _mm_shuffle_ps((__m128)LODWORD(in_fCurrentGain3), (__m128)LODWORD(in_fCurrentGain3), 0);
    if ( out_pfOutput < (__m128 *)v19 )
    {
      v21 = (char *)in_pfInput1 - (char *)in_pfInput2;
      v22 = (char *)in_pfInput3 - (char *)in_pfInput2;
      do
      {
        v23 = *(__m128 *)((char *)v15 + v21);
        v24 = *(__m128 *)v15;
        ++out_pfOutput;
        v15 += 4;
        out_pfOutput[-1] = _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(v23, v17), _mm_mul_ps(v24, v18)),
                             _mm_mul_ps(*(__m128 *)((char *)v15 + v22 - 16), v20));
      }
      while ( out_pfOutput < (__m128 *)v19 );
    }
  }
  else
  {
    v25 = &out_pfOutput->m128_f32[in_uNumFrames];
    v26 = 1.0 / (float)in_uNumFrames;
    v27 = (float)(in_fTargetGain1 - in_fCurrentGain1) * v26;
    v28 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v26;
    v29 = (float)(in_fTargetGain3 - in_fCurrentGain3) * v26;
    if ( out_pfOutput < (__m128 *)v25 )
    {
      if ( (4i64 * (unsigned int)in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v30 = v12;
          v31 = v13;
          v32 = v12 + v27;
          v33 = v13 + v29;
          ++out_pfOutput;
          v34 = v30 * *in_pfInput1;
          v35 = v14 * *v15;
          v36 = v31 * *in_pfInput3;
          in_pfInput1 += 4;
          v15 += 4;
          in_pfInput3 += 4;
          v37 = (float)(v34 + v35) + v36;
          v38 = (float)(v14 + v28) * *(v15 - 3);
          v39 = v33 * *(in_pfInput3 - 3);
          out_pfOutput[-1].m128_f32[0] = v37;
          v40 = v32 * *(in_pfInput1 - 3);
          v41 = v32 + v27;
          v42 = v40 + v38;
          v43 = (float)(v14 + v28) + v28;
          v44 = v43 + v28;
          v45 = v43 * *(v15 - 2);
          v46 = v42 + v39;
          v47 = v33 + v29;
          out_pfOutput[-1].m128_f32[1] = v46;
          v48 = (float)(v33 + v29) + v29;
          v49 = v41 * *(in_pfInput1 - 2);
          v50 = v41 + v27;
          v51 = v49 + v45;
          v52 = v44;
          v53 = v51 + (float)(v47 * *(in_pfInput3 - 2));
          v14 = v44 + v28;
          v54 = v52 * *(v15 - 1);
          v55 = v48 * *(in_pfInput3 - 1);
          out_pfOutput[-1].m128_f32[2] = v53;
          v13 = v48 + v29;
          v56 = v50 * *(in_pfInput1 - 1);
          v12 = v50 + v27;
          out_pfOutput[-1].m128_f32[3] = (float)(v56 + v54) + v55;
        }
        while ( (__int64)out_pfOutput < (__int64)(v25 - 3) );
      }
      if ( out_pfOutput < (__m128 *)v25 )
      {
        v57 = (char *)in_pfInput1 - (char *)in_pfInput3;
        v58 = (char *)v15 - (char *)in_pfInput3;
        do
        {
          v59 = v14;
          v60 = v12;
          v61 = v13;
          out_pfOutput = (__m128 *)((char *)out_pfOutput + 4);
          ++in_pfInput3;
          v12 = v12 + v27;
          v14 = v14 + v28;
          v13 = v13 + v29;
          out_pfOutput[-1].m128_f32[3] = (float)((float)(v59 * *(float *)((char *)in_pfInput3 + v58 - 4))
                                               + (float)(v60 * *(float *)((char *)in_pfInput3 + v57 - 4)))
                                       + (float)(v61 * *(in_pfInput3 - 1));
        }
        while ( out_pfOutput < (__m128 *)v25 );
      }
    }
  }
}

// File Line: 125
// RVA: 0xAE9AC0
// local variable allocation has failed, the output may be wrong!
void __fastcall DSP::Mix3Interp(
        float *io_pfIn1Out,
        float *in_pfInput2,
        float *in_pfInput3,
        double in_fCurrentGain1,
        float in_fTargetGain1,
        float in_fCurrentGain2,
        float in_fTargetGain2,
        float in_fCurrentGain3,
        float in_fTargetGain3,
        signed int in_uNumFrames)
{
  __m128 v10; // xmm2
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
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float v42; // xmm3_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm5_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  signed __int64 v55; // r10
  float v56; // xmm2_4
  float v57; // xmm0_4
  float v58; // xmm1_4

  v11 = in_fCurrentGain3;
  v12 = in_fCurrentGain2;
  v13 = in_pfInput2;
  v14 = io_pfIn1Out;
  if ( in_fTargetGain1 == *(float *)&in_fCurrentGain1
    && in_fTargetGain2 == in_fCurrentGain2
    && in_fTargetGain3 == in_fCurrentGain3 )
  {
    v10.m128_f32[0] = *(float *)&in_fCurrentGain1;
    *(float *)&in_fCurrentGain1 = in_fCurrentGain2;
    v15 = _mm_shuffle_ps(v10, v10, 0);
    v16 = _mm_shuffle_ps(*(__m128 *)&in_fCurrentGain1, *(__m128 *)&in_fCurrentGain1, 0);
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
  else
  {
    v23 = &io_pfIn1Out[in_uNumFrames];
    v24 = 1.0 / (float)in_uNumFrames;
    v25 = (float)(in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v24;
    v26 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v24;
    v27 = (float)(in_fTargetGain3 - in_fCurrentGain3) * v24;
    if ( v14 < v23 )
    {
      if ( (4i64 * (unsigned int)in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v28 = v12;
          v29 = v11;
          v30 = v12 + v26;
          v31 = v11 + v27;
          v32 = *(float *)&in_fCurrentGain1 * *v14;
          v33 = v28 * *v13;
          v34 = v29 * *in_pfInput3;
          v14 += 4;
          v13 += 4;
          in_pfInput3 += 4;
          v35 = (float)(v32 + v33) + v34;
          v36 = (float)(*(float *)&in_fCurrentGain1 + v25) * *(v14 - 3);
          v37 = v31 * *(in_pfInput3 - 3);
          *(v14 - 4) = v35;
          v38 = v30 * *(v13 - 3);
          v39 = v30 + v26;
          v40 = v38 + v36;
          v41 = (float)(*(float *)&in_fCurrentGain1 + v25) + v25;
          v42 = v41 + v25;
          v43 = v41 * *(v14 - 2);
          v44 = v40 + v37;
          v45 = v31 + v27;
          *(v14 - 3) = v44;
          v46 = (float)(v31 + v27) + v27;
          v47 = v39 * *(v13 - 2);
          v48 = v39 + v26;
          v49 = v47 + v43;
          v50 = v42;
          v51 = v49 + (float)(v45 * *(in_pfInput3 - 2));
          *(float *)&in_fCurrentGain1 = v42 + v25;
          v52 = v50 * *(v14 - 1);
          v53 = v46 * *(in_pfInput3 - 1);
          *(v14 - 2) = v51;
          v11 = v46 + v27;
          v54 = v48 * *(v13 - 1);
          v12 = v48 + v26;
          *(v14 - 1) = (float)(v54 + v52) + v53;
        }
        while ( (__int64)v14 < (__int64)(v23 - 3) );
      }
      if ( v14 < v23 )
      {
        v55 = (char *)v13 - (char *)in_pfInput3;
        do
        {
          v56 = v12;
          v57 = *(float *)&in_fCurrentGain1;
          v58 = v11;
          ++v14;
          ++in_pfInput3;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v25;
          v12 = v12 + v26;
          v11 = v11 + v27;
          *(v14 - 1) = (float)((float)(v56 * *(float *)((char *)in_pfInput3 + v55 - 4)) + (float)(v57 * *(v14 - 1)))
                     + (float)(v58 * *(in_pfInput3 - 1));
        }
        while ( v14 < v23 );
      }
    }
  }
}

