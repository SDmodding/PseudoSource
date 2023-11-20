// File Line: 71
// RVA: 0xAEC480
int DSP::Mix2Interp(...)
{
  float v8; // xmm2_4
  float *v9; // r9
  float *v10; // r10
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  float *i; // rcx
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm0
  float *v30; // rcx
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  float v34; // xmm1_4
  float v35; // xmm0_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  signed __int64 v50; // r10
  float v51; // xmm1_4
  float v52; // xmm0_4

  v8 = in_fCurrentGain2;
  v9 = in_pfInput2;
  v10 = in_pfInput1;
  if ( in_fTargetGain1 != *(float *)&in_fCurrentGain1 || in_fTargetGain2 != in_fCurrentGain2 )
  {
    v30 = &out_pfOutput[in_uNumFrames];
    v31 = 1.0 / (float)(signed int)in_uNumFrames;
    v32 = (float)(in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v31;
    v33 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v31;
    if ( out_pfOutput < v30 )
    {
      if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v34 = v8;
          v35 = *(float *)&in_fCurrentGain1;
          v36 = *(float *)&in_fCurrentGain1 + v32;
          v37 = v8 + v33;
          out_pfOutput += 4;
          v10 += 4;
          v38 = v34 * *v9;
          v9 += 4;
          v39 = v38 + (float)(v35 * *(v10 - 4));
          v40 = v37;
          *(out_pfOutput - 4) = v39;
          v41 = v37 + v33;
          v42 = v36;
          v43 = v36 + v32;
          v44 = (float)(v42 * *(v10 - 3)) + (float)(v40 * *(v9 - 3));
          v45 = v41 * *(v9 - 2);
          *(out_pfOutput - 3) = v44;
          v46 = (float)(v43 * *(v10 - 2)) + v45;
          v47 = v41 + v33;
          v8 = (float)(v41 + v33) + v33;
          v48 = v47 * *(v9 - 1);
          *(out_pfOutput - 2) = v46;
          v49 = v43 + v32;
          *(float *)&in_fCurrentGain1 = (float)(v43 + v32) + v32;
          *(out_pfOutput - 1) = (float)(v49 * *(v10 - 1)) + v48;
        }
        while ( (signed __int64)out_pfOutput < (signed __int64)(v30 - 3) );
      }
      if ( out_pfOutput < v30 )
      {
        v50 = (char *)v10 - (char *)v9;
        do
        {
          v51 = *(float *)&in_fCurrentGain1;
          v52 = v8;
          ++out_pfOutput;
          ++v9;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v32;
          v8 = v8 + v33;
          *(out_pfOutput - 1) = (float)(v51 * *(float *)((char *)v9 + v50 - 4)) + (float)(v52 * *(v9 - 1));
        }
        while ( out_pfOutput < v30 );
      }
    }
  }
  else
  {
    *(float *)&in_fCurrentGain1 = in_fTargetGain2;
    v11 = _mm_shuffle_ps((__m128)LODWORD(in_fTargetGain1), (__m128)LODWORD(in_fTargetGain1), 0);
    v12 = _mm_shuffle_ps((__m128)in_fCurrentGain1, (__m128)in_fCurrentGain1, 0);
    for ( i = &out_pfOutput[in_uNumFrames];
          out_pfOutput < i;
          *((__m128 *)out_pfOutput - 1) = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)v9 - 16), v12), v29) )
    {
      v14 = *(__m128 *)v9;
      v15 = *(__m128 *)v10;
      out_pfOutput += 32;
      v10 += 32;
      v9 += 32;
      v16 = _mm_add_ps(_mm_mul_ps(v14, v12), _mm_mul_ps(v15, v11));
      v17 = _mm_mul_ps(*(__m128 *)((char *)v10 - 112), v11);
      *((__m128 *)out_pfOutput - 8) = v16;
      v18 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)v9 - 112), v12), v17);
      v19 = _mm_mul_ps(*(__m128 *)((char *)v10 - 96), v11);
      *((__m128 *)out_pfOutput - 7) = v18;
      v20 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)v9 - 96), v12), v19);
      v21 = _mm_mul_ps(*(__m128 *)((char *)v10 - 80), v11);
      *((__m128 *)out_pfOutput - 6) = v20;
      v22 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)v9 - 80), v12), v21);
      v23 = _mm_mul_ps(*(__m128 *)((char *)v10 - 64), v11);
      *((__m128 *)out_pfOutput - 5) = v22;
      v24 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)v9 - 64), v12), v23);
      v25 = _mm_mul_ps(*(__m128 *)((char *)v10 - 48), v11);
      *((__m128 *)out_pfOutput - 4) = v24;
      v26 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)v9 - 48), v12), v25);
      v27 = _mm_mul_ps(*(__m128 *)((char *)v10 - 32), v11);
      *((__m128 *)out_pfOutput - 3) = v26;
      v28 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)v9 - 32), v12), v27);
      v29 = _mm_mul_ps(*(__m128 *)((char *)v10 - 16), v11);
      *((__m128 *)out_pfOutput - 2) = v28;
    }
  }
}

// File Line: 146
// RVA: 0xAEC6F0
int DSP::Mix2Interp(...)
{
  float v7; // xmm4_4
  float *v8; // r9
  float *v9; // r8
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  float *i; // rcx
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  float *v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm5_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  signed __int64 v34; // r9
  float v35; // xmm1_4
  float v36; // xmm0_4

  v7 = in_fCurrentGain2;
  v8 = in_pfInput2;
  v9 = io_pfIn1Out;
  if ( *(float *)&in_fTargetGain1 != *(float *)&in_fCurrentGain1 || in_fTargetGain2 != in_fCurrentGain2 )
  {
    v15 = &io_pfIn1Out[in_uNumFrames];
    v16 = 1.0 / (float)(signed int)in_uNumFrames;
    v17 = (float)(*(float *)&in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v16;
    v18 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v16;
    if ( v9 < v15 )
    {
      if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v19 = *(float *)&in_fCurrentGain1;
          v20 = v7;
          v21 = *(float *)&in_fCurrentGain1 + v17;
          v22 = v7 + v18;
          v9 += 4;
          v8 += 4;
          v23 = (float)(v19 * *(v9 - 4)) + (float)(v20 * *(v8 - 4));
          v24 = v21;
          *(v9 - 4) = v23;
          v25 = v21 + v17;
          v26 = v22;
          v27 = v22 + v18;
          v28 = (float)(v26 * *(v8 - 3)) + (float)(v24 * *(v9 - 3));
          v29 = v25 * *(v9 - 2);
          *(v9 - 3) = v28;
          v30 = (float)(v27 * *(v8 - 2)) + v29;
          v31 = v25 + v17;
          *(float *)&in_fCurrentGain1 = (float)(v25 + v17) + v17;
          v32 = v31 * *(v9 - 1);
          *(v9 - 2) = v30;
          v33 = v27 + v18;
          v7 = (float)(v27 + v18) + v18;
          *(v9 - 1) = (float)(v33 * *(v8 - 1)) + v32;
        }
        while ( (signed __int64)v9 < (signed __int64)(v15 - 3) );
      }
      if ( v9 < v15 )
      {
        v34 = (char *)v8 - (char *)v9;
        do
        {
          v35 = v7;
          v36 = *(float *)&in_fCurrentGain1;
          ++v9;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v17;
          v7 = v7 + v18;
          *(v9 - 1) = (float)(v35 * *(float *)((char *)v9 + v34 - 4)) + (float)(v36 * *(v9 - 1));
        }
        while ( v9 < v15 );
      }
    }
  }
  else
  {
    *(float *)&in_fCurrentGain1 = *(float *)&in_fTargetGain1;
    *(float *)&in_fTargetGain1 = in_fTargetGain2;
    v10 = _mm_shuffle_ps((__m128)in_fCurrentGain1, (__m128)in_fCurrentGain1, 0);
    v11 = _mm_shuffle_ps((__m128)in_fTargetGain1, (__m128)in_fTargetGain1, 0);
    for ( i = &io_pfIn1Out[in_uNumFrames];
          v9 < i;
          *((__m128 *)v9 - 1) = _mm_add_ps(
                                  _mm_mul_ps(*(__m128 *)((char *)v8 - 16), v11),
                                  _mm_mul_ps(*(__m128 *)((char *)v9 - 16), v10)) )
    {
      v13 = *(__m128 *)v9;
      v14 = *(__m128 *)v8;
      v9 += 32;
      v8 += 32;
      *((__m128 *)v9 - 8) = _mm_add_ps(_mm_mul_ps(v14, v11), _mm_mul_ps(v13, v10));
      *((__m128 *)v9 - 7) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)((char *)v8 - 112), v11),
                              _mm_mul_ps(*(__m128 *)((char *)v9 - 112), v10));
      *((__m128 *)v9 - 6) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)((char *)v8 - 96), v11),
                              _mm_mul_ps(*(__m128 *)((char *)v9 - 96), v10));
      *((__m128 *)v9 - 5) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)((char *)v8 - 80), v11),
                              _mm_mul_ps(*(__m128 *)((char *)v9 - 80), v10));
      *((__m128 *)v9 - 4) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)((char *)v8 - 64), v11),
                              _mm_mul_ps(*(__m128 *)((char *)v9 - 64), v10));
      *((__m128 *)v9 - 3) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)((char *)v8 - 48), v11),
                              _mm_mul_ps(*(__m128 *)((char *)v9 - 48), v10));
      *((__m128 *)v9 - 2) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)((char *)v8 - 32), v11),
                              _mm_mul_ps(*(__m128 *)((char *)v9 - 32), v10));
    }
  }
}

// File Line: 218
// RVA: 0xAEC950
void __fastcall DSP::Mix2Interp(float *io_pfIn1Out, float *in_pfInput2, const float in_fGain1, const float in_fGain2, unsigned int in_uNumFrames)
{
  float v5; // xmm4_4
  float *v6; // r8
  float *v7; // r9
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  signed __int64 v11; // r8

  v5 = in_fGain1;
  v6 = in_pfInput2;
  v7 = &io_pfIn1Out[in_uNumFrames];
  if ( io_pfIn1Out < v7 )
  {
    if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
    {
      do
      {
        io_pfIn1Out += 4;
        v6 += 4;
        v8 = in_fGain2 * *(v6 - 3);
        *(io_pfIn1Out - 4) = (float)(v5 * *(io_pfIn1Out - 4)) + (float)(in_fGain2 * *(v6 - 4));
        v9 = in_fGain2 * *(v6 - 2);
        *(io_pfIn1Out - 3) = v8 + (float)(v5 * *(io_pfIn1Out - 3));
        v10 = in_fGain2 * *(v6 - 1);
        *(io_pfIn1Out - 2) = v9 + (float)(v5 * *(io_pfIn1Out - 2));
        *(io_pfIn1Out - 1) = v10 + (float)(v5 * *(io_pfIn1Out - 1));
      }
      while ( (signed __int64)io_pfIn1Out < (signed __int64)(v7 - 3) );
    }
    if ( io_pfIn1Out < v7 )
    {
      v11 = (char *)v6 - (char *)io_pfIn1Out;
      do
      {
        ++io_pfIn1Out;
        *(io_pfIn1Out - 1) = (float)(in_fGain2 * *(float *)((char *)io_pfIn1Out + v11 - 4))
                           + (float)(v5 * *(io_pfIn1Out - 1));
      }
      while ( io_pfIn1Out < v7 );
    }
  }
}

