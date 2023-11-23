// File Line: 34
// RVA: 0xB09F30
// local variable allocation has failed, the output may be wrong!
void __fastcall McDSP::Mix2Interp(
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
  float *v9; // r9
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
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  char *v33; // r10
  float v34; // xmm1_4
  float v35; // xmm0_4

  v8 = in_fCurrentGain2;
  v9 = in_pfInput2;
  if ( in_fTargetGain1 == *(float *)&in_fCurrentGain1 && in_fTargetGain2 == in_fCurrentGain2 )
  {
    *(float *)&in_fCurrentGain1 = in_fTargetGain2;
    v11 = _mm_shuffle_ps((__m128)LODWORD(in_fTargetGain1), (__m128)LODWORD(in_fTargetGain1), 0);
    v12 = _mm_shuffle_ps(*(__m128 *)&in_fCurrentGain1, *(__m128 *)&in_fCurrentGain1, 0);
    v13 = &out_pfOutput->m128_f32[in_uNumFrames];
    if ( out_pfOutput < (__m128 *)v13 )
    {
      v14 = (char *)in_pfInput2 - (char *)in_pfInput1;
      v15 = (char *)in_pfInput1 - (char *)out_pfOutput;
      do
      {
        v16 = *(__m128 *)((char *)out_pfOutput + v15);
        v17 = (char *)out_pfOutput++ + v15;
        out_pfOutput[-1] = _mm_add_ps(_mm_mul_ps(*(__m128 *)&v17[v14], v12), _mm_mul_ps(v16, v11));
      }
      while ( out_pfOutput < (__m128 *)v13 );
    }
  }
  else
  {
    v18 = &out_pfOutput->m128_f32[in_uNumFrames];
    v19 = 1.0 / (float)in_uNumFrames;
    v20 = (float)(in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v19;
    v21 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v19;
    if ( out_pfOutput < (__m128 *)v18 )
    {
      if ( (4i64 * (unsigned int)in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          ++out_pfOutput;
          in_pfInput1 += 4;
          v22 = v8 * *v9;
          v9 += 4;
          out_pfOutput[-1].m128_f32[0] = v22 + (float)(*(float *)&in_fCurrentGain1 * *(in_pfInput1 - 4));
          v23 = (float)((float)(*(float *)&in_fCurrentGain1 + v20) * *(in_pfInput1 - 3))
              + (float)((float)(v8 + v21) * *(v9 - 3));
          v24 = (float)(v8 + v21) + v21;
          v25 = v24 + v21;
          v26 = v24 * *(v9 - 2);
          out_pfOutput[-1].m128_f32[1] = v23;
          v27 = (float)(*(float *)&in_fCurrentGain1 + v20) + v20;
          v28 = v27 + v20;
          v29 = (float)(v27 * *(in_pfInput1 - 2)) + v26;
          v30 = v25;
          v8 = v25 + v21;
          v31 = v30 * *(v9 - 1);
          out_pfOutput[-1].m128_f32[2] = v29;
          v32 = v28;
          *(float *)&in_fCurrentGain1 = v28 + v20;
          out_pfOutput[-1].m128_f32[3] = (float)(v32 * *(in_pfInput1 - 1)) + v31;
        }
        while ( (__int64)out_pfOutput < (__int64)(v18 - 3) );
      }
      if ( out_pfOutput < (__m128 *)v18 )
      {
        v33 = (char *)((char *)in_pfInput1 - (char *)v9);
        do
        {
          v34 = *(float *)&in_fCurrentGain1;
          v35 = v8;
          out_pfOutput = (__m128 *)((char *)out_pfOutput + 4);
          ++v9;
          *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v20;
          v8 = v8 + v21;
          out_pfOutput[-1].m128_f32[3] = (float)(v34 * *(float *)((char *)v9 + (_QWORD)v33 - 4))
                                       + (float)(v35 * *(v9 - 1));
        }
        while ( out_pfOutput < (__m128 *)v18 );
      }
    }
  }
}

// File Line: 84
// RVA: 0xB0A0F0
// local variable allocation has failed, the output may be wrong!
void __fastcall McDSP::Mix2Interp(
        float *io_pfIn1Out,
        float *in_pfInput2,
        double in_fCurrentGain1,
        double in_fTargetGain1,
        float in_fCurrentGain2,
        float in_fTargetGain2,
        signed int in_uNumFrames)
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
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm0_4

  v7 = in_fCurrentGain2;
  v8 = in_pfInput2;
  v9 = io_pfIn1Out;
  if ( *(float *)&in_fTargetGain1 == *(float *)&in_fCurrentGain1 && in_fTargetGain2 == in_fCurrentGain2 )
  {
    *(float *)&in_fCurrentGain1 = *(float *)&in_fTargetGain1;
    *(float *)&in_fTargetGain1 = in_fTargetGain2;
    v10 = _mm_shuffle_ps(*(__m128 *)&in_fCurrentGain1, *(__m128 *)&in_fCurrentGain1, 0);
    v11 = _mm_shuffle_ps(*(__m128 *)&in_fTargetGain1, *(__m128 *)&in_fTargetGain1, 0);
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
  else
  {
    v16 = &io_pfIn1Out[in_uNumFrames];
    v17 = 1.0 / (float)in_uNumFrames;
    v18 = (float)(*(float *)&in_fTargetGain1 - *(float *)&in_fCurrentGain1) * v17;
    v19 = (float)(in_fTargetGain2 - in_fCurrentGain2) * v17;
    if ( v9 < v16 )
    {
      if ( (4i64 * (unsigned int)in_uNumFrames + 3) / 4 >= 4 )
      {
        do
        {
          v9 += 4;
          v8 += 4;
          *(v9 - 4) = (float)(*(float *)&in_fCurrentGain1 * *(v9 - 4)) + (float)(v7 * *(v8 - 4));
          v20 = (float)((float)(v7 + v19) * *(v8 - 3)) + (float)((float)(*(float *)&in_fCurrentGain1 + v18) * *(v9 - 3));
          v21 = (float)(*(float *)&in_fCurrentGain1 + v18) + v18;
          v22 = v21 + v18;
          v23 = v21 * *(v9 - 2);
          *(v9 - 3) = v20;
          v24 = (float)(v7 + v19) + v19;
          v25 = v24 + v19;
          v26 = (float)(v24 * *(v8 - 2)) + v23;
          v27 = v22;
          *(float *)&in_fCurrentGain1 = v22 + v18;
          v28 = v27 * *(v9 - 1);
          *(v9 - 2) = v26;
          v29 = v25;
          v7 = v25 + v19;
          *(v9 - 1) = (float)(v29 * *(v8 - 1)) + v28;
        }
        while ( (__int64)v9 < (__int64)(v16 - 3) );
      }
      for ( ; v9 < v16; *(v9 - 1) = (float)(v30 * *(v9 - 1)) + (float)(v31 * *(v8 - 1)) )
      {
        v30 = *(float *)&in_fCurrentGain1;
        v31 = v7;
        ++v9;
        ++v8;
        *(float *)&in_fCurrentGain1 = *(float *)&in_fCurrentGain1 + v18;
        v7 = v7 + v19;
      }
    }
  }
}

