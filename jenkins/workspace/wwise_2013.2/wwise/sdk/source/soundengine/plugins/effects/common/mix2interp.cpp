// File Line: 71
// RVA: 0xAEC480
// local variable allocation has failed, the output may be wrong!
void __fastcall DSP::Mix2Interp(
        float *in_pfInput1,
        float *in_pfInput2,
        __m128 *out_pfOutput,
        double in_fCurrentGain1,
        float in_fTargetGain1,
        float in_fCurrentGain2,
        float in_fTargetGain2,
        signed int in_uNumFrames)
{
  float v8; // xmm2_4
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
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  signed __int64 v45; // r10
  float v46; // xmm1_4
  float v47; // xmm0_4

  v8 = in_fCurrentGain2;
  if ( in_fTargetGain1 == *(float *)&in_fCurrentGain1 && in_fTargetGain2 == in_fCurrentGain2 )
  {
    *(float *)&in_fCurrentGain1 = in_fTargetGain2;
    v11 = _mm_shuffle_ps((__m128)LODWORD(in_fTargetGain1), (__m128)LODWORD(in_fTargetGain1), 0);
    v12 = _mm_shuffle_ps(*(__m128 *)&in_fCurrentGain1, *(__m128 *)&in_fCurrentGain1, 0);
    for ( i = &out_pfOutput->m128_f32[in_uNumFrames];
          out_pfOutput < (__m128 *)i;
          out_pfOutput[-1] = _mm_add_ps(_mm_mul_ps(*(__m128 *)(in_pfInput2 - 4), v12), v29) )
    {
      v14 = *(__m128 *)in_pfInput2;
      v15 = *(__m128 *)in_pfInput1;
      out_pfOutput += 8;
      in_pfInput1 += 32;
      in_pfInput2 += 32;
      v16 = _mm_add_ps(_mm_mul_ps(v14, v12), _mm_mul_ps(v15, v11));
      v17 = _mm_mul_ps(*(__m128 *)(in_pfInput1 - 28), v11);
      out_pfOutput[-8] = v16;
      v18 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(in_pfInput2 - 28), v12), v17);
      v19 = _mm_mul_ps(*(__m128 *)(in_pfInput1 - 24), v11);
      out_pfOutput[-7] = v18;
      v20 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(in_pfInput2 - 24), v12), v19);
      v21 = _mm_mul_ps(*(__m128 *)(in_pfInput1 - 20), v11);
      out_pfOutput[-6] = v20;
      v22 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(in_pfInput2 - 20), v12), v21);
      v23 = _mm_mul_ps(*(__m128 *)(in_pfInput1 - 16), v11);
      out_pfOutput[-5] = v22;
      v24 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(in_pfInput2 - 16), v12), v23);
      v25 = _mm_mul_ps(*(__m128 *)(in_pfInput1 - 12), v11);
      out_pfOutput[-4] = v24;
      v26 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(in_pfInput2 - 12), v12), v25);
      v27 = _mm_mul_ps(*(__m128 *)(in_pfInput1 - 8), v11);
      out_pfOutput[-3] = v26;
      v28 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(in_pfInput2 - 8), v12), v27);
      v29 = _mm_mul_ps(*(__m128 *)(in_pfInput1 - 4), v11);
      out_pfOutput[-2] = v28;
    }
  }
  else
  {
    v30 = &out_pfOutput->m128_f32[in_uNumFrames];
    v31 = 1.0 / (float)in_uNumFrames;
    v32 = (float)(in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v31;
    v33 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v31;
    if ( out_pfOutput < (__m128 *)v30 )
    {
      if ( (4i64 * (unsigned int)in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          ++out_pfOutput;
          in_pfInput1 += 4;
          v34 = v8 * *in_pfInput2;
          in_pfInput2 += 4;
          out_pfOutput[-1].m128_f32[0] = v34 + (float)(*(float *)&in_fCurrentGain1 * *(in_pfInput1 - 4));
          v35 = (float)((float)(*(float *)&in_fCurrentGain1 + v32) * *(in_pfInput1 - 3))
              + (float)((float)(v8 + v33) * *(in_pfInput2 - 3));
          v36 = (float)(v8 + v33) + v33;
          v37 = v36 + v33;
          v38 = v36 * *(in_pfInput2 - 2);
          out_pfOutput[-1].m128_f32[1] = v35;
          v39 = (float)(*(float *)&in_fCurrentGain1 + v32) + v32;
          v40 = v39 + v32;
          v41 = (float)(v39 * *(in_pfInput1 - 2)) + v38;
          v42 = v37;
          v8 = v37 + v33;
          v43 = v42 * *(in_pfInput2 - 1);
          out_pfOutput[-1].m128_f32[2] = v41;
          v44 = v40;
          *(float *)&in_fCurrentGain1 = v40 + v32;
          out_pfOutput[-1].m128_f32[3] = (float)(v44 * *(in_pfInput1 - 1)) + v43;
        }
        while ( (__int64)out_pfOutput < (__int64)(v30 - 3) );
      }
      if ( out_pfOutput < (__m128 *)v30 )
      {
        v45 = (char *)in_pfInput1 - (char *)in_pfInput2;
        do
        {
          v46 = *(float *)&in_fCurrentGain1;
          v47 = v8;
          out_pfOutput = (__m128 *)((char *)out_pfOutput + 4);
          ++in_pfInput2;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v32;
          v8 = v8 + v33;
          out_pfOutput[-1].m128_f32[3] = (float)(v46 * *(float *)((char *)in_pfInput2 + v45 - 4))
                                       + (float)(v47 * *(in_pfInput2 - 1));
        }
        while ( out_pfOutput < (__m128 *)v30 );
      }
    }
  }
}

// File Line: 146
// RVA: 0xAEC6F0
// local variable allocation has failed, the output may be wrong!
void __fastcall DSP::Mix2Interp(
        float *io_pfIn1Out,
        float *in_pfInput2,
        double in_fCurrentGain1,
        double in_fTargetGain1,
        float in_fCurrentGain2,
        float in_fTargetGain2,
        signed int in_uNumFrames)
{
  float v7; // xmm4_4
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
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  char *v29; // r9
  float v30; // xmm1_4
  float v31; // xmm0_4

  v7 = in_fCurrentGain2;
  v9 = io_pfIn1Out;
  if ( *(float *)&in_fTargetGain1 == *(float *)&in_fCurrentGain1 && in_fTargetGain2 == in_fCurrentGain2 )
  {
    *(float *)&in_fCurrentGain1 = *(float *)&in_fTargetGain1;
    *(float *)&in_fTargetGain1 = in_fTargetGain2;
    v10 = _mm_shuffle_ps(*(__m128 *)&in_fCurrentGain1, *(__m128 *)&in_fCurrentGain1, 0);
    v11 = _mm_shuffle_ps(*(__m128 *)&in_fTargetGain1, *(__m128 *)&in_fTargetGain1, 0);
    for ( i = &io_pfIn1Out[in_uNumFrames];
          v9 < i;
          *((__m128 *)v9 - 1) = _mm_add_ps(
                                  _mm_mul_ps(*(__m128 *)(in_pfInput2 - 4), v11),
                                  _mm_mul_ps(*(__m128 *)(v9 - 4), v10)) )
    {
      v13 = *(__m128 *)v9;
      v14 = *(__m128 *)in_pfInput2;
      v9 += 32;
      in_pfInput2 += 32;
      *((__m128 *)v9 - 8) = _mm_add_ps(_mm_mul_ps(v14, v11), _mm_mul_ps(v13, v10));
      *((__m128 *)v9 - 7) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)(in_pfInput2 - 28), v11),
                              _mm_mul_ps(*(__m128 *)(v9 - 28), v10));
      *((__m128 *)v9 - 6) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)(in_pfInput2 - 24), v11),
                              _mm_mul_ps(*(__m128 *)(v9 - 24), v10));
      *((__m128 *)v9 - 5) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)(in_pfInput2 - 20), v11),
                              _mm_mul_ps(*(__m128 *)(v9 - 20), v10));
      *((__m128 *)v9 - 4) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)(in_pfInput2 - 16), v11),
                              _mm_mul_ps(*(__m128 *)(v9 - 16), v10));
      *((__m128 *)v9 - 3) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)(in_pfInput2 - 12), v11),
                              _mm_mul_ps(*(__m128 *)(v9 - 12), v10));
      *((__m128 *)v9 - 2) = _mm_add_ps(
                              _mm_mul_ps(*(__m128 *)(in_pfInput2 - 8), v11),
                              _mm_mul_ps(*(__m128 *)(v9 - 8), v10));
    }
  }
  else
  {
    v15 = &io_pfIn1Out[in_uNumFrames];
    v16 = 1.0 / (float)in_uNumFrames;
    v17 = (float)(*(float *)&in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v16;
    v18 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v16;
    if ( v9 < v15 )
    {
      if ( (4i64 * (unsigned int)in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v9 += 4;
          in_pfInput2 += 4;
          *(v9 - 4) = (float)(*(float *)&in_fCurrentGain1 * *(v9 - 4)) + (float)(v7 * *(in_pfInput2 - 4));
          v19 = (float)((float)(v7 + v18) * *(in_pfInput2 - 3))
              + (float)((float)(*(float *)&in_fCurrentGain1 + v17) * *(v9 - 3));
          v20 = (float)(*(float *)&in_fCurrentGain1 + v17) + v17;
          v21 = v20 + v17;
          v22 = v20 * *(v9 - 2);
          *(v9 - 3) = v19;
          v23 = (float)(v7 + v18) + v18;
          v24 = v23 + v18;
          v25 = (float)(v23 * *(in_pfInput2 - 2)) + v22;
          v26 = v21;
          *(float *)&in_fCurrentGain1 = v21 + v17;
          v27 = v26 * *(v9 - 1);
          *(v9 - 2) = v25;
          v28 = v24;
          v7 = v24 + v18;
          *(v9 - 1) = (float)(v28 * *(in_pfInput2 - 1)) + v27;
        }
        while ( (__int64)v9 < (__int64)(v15 - 3) );
      }
      if ( v9 < v15 )
      {
        v29 = (char *)((char *)in_pfInput2 - (char *)v9);
        do
        {
          v30 = v7;
          v31 = *(float *)&in_fCurrentGain1;
          ++v9;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v17;
          v7 = v7 + v18;
          *(v9 - 1) = (float)(v30 * *(float *)((char *)v9 + (_QWORD)v29 - 4)) + (float)(v31 * *(v9 - 1));
        }
        while ( v9 < v15 );
      }
    }
  }
}

// File Line: 218
// RVA: 0xAEC950
void __fastcall DSP::Mix2Interp(
        float *io_pfIn1Out,
        float *in_pfInput2,
        const float in_fGain1,
        const float in_fGain2,
        unsigned int in_uNumFrames)
{
  float *v7; // r9
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  signed __int64 v11; // r8

  v7 = &io_pfIn1Out[in_uNumFrames];
  if ( io_pfIn1Out < v7 )
  {
    if ( (4i64 * in_uNumFrames + 3) / 4 >= 4 )
    {
      do
      {
        io_pfIn1Out += 4;
        in_pfInput2 += 4;
        v8 = in_fGain2 * *(in_pfInput2 - 3);
        *(io_pfIn1Out - 4) = (float)(in_fGain1 * *(io_pfIn1Out - 4)) + (float)(in_fGain2 * *(in_pfInput2 - 4));
        v9 = in_fGain2 * *(in_pfInput2 - 2);
        *(io_pfIn1Out - 3) = v8 + (float)(in_fGain1 * *(io_pfIn1Out - 3));
        v10 = in_fGain2 * *(in_pfInput2 - 1);
        *(io_pfIn1Out - 2) = v9 + (float)(in_fGain1 * *(io_pfIn1Out - 2));
        *(io_pfIn1Out - 1) = v10 + (float)(in_fGain1 * *(io_pfIn1Out - 1));
      }
      while ( (__int64)io_pfIn1Out < (__int64)(v7 - 3) );
    }
    if ( io_pfIn1Out < v7 )
    {
      v11 = (char *)in_pfInput2 - (char *)io_pfIn1Out;
      do
      {
        ++io_pfIn1Out;
        *(io_pfIn1Out - 1) = (float)(in_fGain2 * *(float *)((char *)io_pfIn1Out + v11 - 4))
                           + (float)(in_fGain1 * *(io_pfIn1Out - 1));
      }
      while ( io_pfIn1Out < v7 );
    }
  }
}

