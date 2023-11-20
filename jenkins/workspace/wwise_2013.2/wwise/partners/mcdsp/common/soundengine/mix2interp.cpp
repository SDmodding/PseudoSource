// File Line: 34
// RVA: 0xB09F30
int McDSP::Mix2Interp(...)
{
  float v8; // xmm2_4
  float *v9; // r9
  float *v10; // r10
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  float *v13; // rcx
  signed __int64 v14; // r9
  signed __int64 v15; // r10
  __m128 v16; // xmm0
  char *v17; // rax
  float *v18; // rcx
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  signed __int64 v38; // r10
  float v39; // xmm1_4
  float v40; // xmm0_4

  v8 = in_fCurrentGain2;
  v9 = in_pfInput2;
  v10 = in_pfInput1;
  if ( in_fTargetGain1 != *(float *)&in_fCurrentGain1 || in_fTargetGain2 != in_fCurrentGain2 )
  {
    v18 = &out_pfOutput[in_uNumFrames];
    v19 = 1.0 / (float)(signed int)in_uNumFrames;
    v20 = (float)(in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v19;
    v21 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v19;
    if ( out_pfOutput < v18 )
    {
      if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v22 = v8;
          v23 = *(float *)&in_fCurrentGain1;
          v24 = *(float *)&in_fCurrentGain1 + v20;
          v25 = v8 + v21;
          out_pfOutput += 4;
          v10 += 4;
          v26 = v22 * *v9;
          v9 += 4;
          v27 = v26 + (float)(v23 * *(v10 - 4));
          v28 = v25;
          *(out_pfOutput - 4) = v27;
          v29 = v25 + v21;
          v30 = v24;
          v31 = v24 + v20;
          v32 = (float)(v30 * *(v10 - 3)) + (float)(v28 * *(v9 - 3));
          v33 = v29 * *(v9 - 2);
          *(out_pfOutput - 3) = v32;
          v34 = (float)(v31 * *(v10 - 2)) + v33;
          v35 = v29 + v21;
          v8 = (float)(v29 + v21) + v21;
          v36 = v35 * *(v9 - 1);
          *(out_pfOutput - 2) = v34;
          v37 = v31 + v20;
          *(float *)&in_fCurrentGain1 = (float)(v31 + v20) + v20;
          *(out_pfOutput - 1) = (float)(v37 * *(v10 - 1)) + v36;
        }
        while ( (signed __int64)out_pfOutput < (signed __int64)(v18 - 3) );
      }
      if ( out_pfOutput < v18 )
      {
        v38 = (char *)v10 - (char *)v9;
        do
        {
          v39 = *(float *)&in_fCurrentGain1;
          v40 = v8;
          ++out_pfOutput;
          ++v9;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v20;
          v8 = v8 + v21;
          *(out_pfOutput - 1) = (float)(v39 * *(float *)((char *)v9 + v38 - 4)) + (float)(v40 * *(v9 - 1));
        }
        while ( out_pfOutput < v18 );
      }
    }
  }
  else
  {
    *(float *)&in_fCurrentGain1 = in_fTargetGain2;
    v11 = _mm_shuffle_ps((__m128)LODWORD(in_fTargetGain1), (__m128)LODWORD(in_fTargetGain1), 0);
    v12 = _mm_shuffle_ps((__m128)in_fCurrentGain1, (__m128)in_fCurrentGain1, 0);
    v13 = &out_pfOutput[in_uNumFrames];
    if ( out_pfOutput < v13 )
    {
      v14 = (char *)in_pfInput2 - (char *)v10;
      v15 = (char *)v10 - (char *)out_pfOutput;
      do
      {
        v16 = *(__m128 *)((char *)out_pfOutput + v15);
        v17 = (char *)out_pfOutput + v15;
        out_pfOutput += 4;
        *((__m128 *)out_pfOutput - 1) = _mm_add_ps(_mm_mul_ps(*(__m128 *)&v17[v14], v12), _mm_mul_ps(v16, v11));
      }
      while ( out_pfOutput < v13 );
    }
  }
}

// File Line: 84
// RVA: 0xB0A0F0
int McDSP::Mix2Interp(...)
{
  float v7; // xmm4_4
  float *v8; // r9
  float *v9; // r8
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  float *v12; // rcx
  char *v13; // r9
  __m128 v14; // xmm0
  __m128 v15; // xmm1
  float *v16; // rcx
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm0_4

  v7 = in_fCurrentGain2;
  v8 = in_pfInput2;
  v9 = io_pfIn1Out;
  if ( *(float *)&in_fTargetGain1 != *(float *)&in_fCurrentGain1 || in_fTargetGain2 != in_fCurrentGain2 )
  {
    v16 = &io_pfIn1Out[in_uNumFrames];
    v17 = 1.0 / (float)(signed int)in_uNumFrames;
    v18 = (float)(*(float *)&in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v17;
    v19 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v17;
    if ( v9 < v16 )
    {
      if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v20 = *(float *)&in_fCurrentGain1;
          v21 = v7;
          v22 = *(float *)&in_fCurrentGain1 + v18;
          v23 = v7 + v19;
          v9 += 4;
          v8 += 4;
          v24 = (float)(v20 * *(v9 - 4)) + (float)(v21 * *(v8 - 4));
          v25 = v22;
          *(v9 - 4) = v24;
          v26 = v22 + v18;
          v27 = v23;
          v28 = v23 + v19;
          v29 = (float)(v27 * *(v8 - 3)) + (float)(v25 * *(v9 - 3));
          v30 = v26 * *(v9 - 2);
          *(v9 - 3) = v29;
          v31 = (float)(v28 * *(v8 - 2)) + v30;
          v32 = v26 + v18;
          *(float *)&in_fCurrentGain1 = (float)(v26 + v18) + v18;
          v33 = v32 * *(v9 - 1);
          *(v9 - 2) = v31;
          v34 = v28 + v19;
          v7 = (float)(v28 + v19) + v19;
          *(v9 - 1) = (float)(v34 * *(v8 - 1)) + v33;
        }
        while ( (signed __int64)v9 < (signed __int64)(v16 - 3) );
      }
      for ( ; v9 < v16; *(v9 - 1) = (float)(v35 * *(v9 - 1)) + (float)(v36 * *(v8 - 1)) )
      {
        v35 = *(float *)&in_fCurrentGain1;
        v36 = v7;
        ++v9;
        ++v8;
        *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v18;
        v7 = v7 + v19;
      }
    }
  }
  else
  {
    *(float *)&in_fCurrentGain1 = *(float *)&in_fTargetGain1;
    *(float *)&in_fTargetGain1 = in_fTargetGain2;
    v10 = _mm_shuffle_ps((__m128)in_fCurrentGain1, (__m128)in_fCurrentGain1, 0);
    v11 = _mm_shuffle_ps((__m128)in_fTargetGain1, (__m128)in_fTargetGain1, 0);
    v12 = &io_pfIn1Out[in_uNumFrames];
    if ( v9 < v12 )
    {
      v13 = (char *)((char *)in_pfInput2 - (char *)v9);
      do
      {
        v14 = *(__m128 *)v9;
        v15 = *(__m128 *)((char *)v9 + (_QWORD)v13);
        v9 += 4;
        *((__m128 *)v9 - 1) = _mm_add_ps(_mm_mul_ps(v15, v11), _mm_mul_ps(v14, v10));
      }
      while ( v9 < v12 );
    }
  }
}

