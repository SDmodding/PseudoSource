// File Line: 32
// RVA: 0xADFA60
void __fastcall ScaleAndOutput(
        AkAudioBuffer *io_pOutBuffer,
        float *in_pInData,
        float in_fResTargetGain,
        float *in_fResCurrentGain,
        float in_fOutTargetGain,
        float *in_fOutCurrentGain,
        unsigned int in_uNumProcessedChannels)
{
  float v9; // xmm4_4
  float *pData; // r11
  int uMaxFrames; // edi
  __int64 uValidFrames; // r15
  float v13; // xmm3_4
  __int64 v14; // r10
  __int64 v15; // rbx
  __int64 v16; // rsi
  float *v17; // rcx
  float *v18; // r8
  float *v19; // r9
  float v20; // xmm1_4
  float v21; // xmm1_4
  signed __int64 v22; // r8
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm0_4

  if ( in_uNumProcessedChannels )
  {
    v9 = *in_fResCurrentGain;
    pData = (float *)io_pOutBuffer->pData;
    uMaxFrames = io_pOutBuffer->uMaxFrames;
    uValidFrames = io_pOutBuffer->uValidFrames;
    v13 = *in_fOutCurrentGain;
    v14 = 0i64;
    v15 = in_uNumProcessedChannels;
    v16 = 4i64 * io_pOutBuffer->uMaxFrames;
    do
    {
      v17 = &in_pInData[v14];
      v18 = pData;
      v19 = &v17[uValidFrames];
      if ( in_fResTargetGain == v9 && in_fOutTargetGain == v13 )
      {
        if ( v17 < v19 )
        {
          if ( (4 * uValidFrames + 3) / 4 >= 4 )
          {
            do
            {
              v17 += 4;
              v18 += 4;
              v20 = (float)((float)(v9 * *(v18 - 3)) + *(v17 - 3)) * v13;
              *(v18 - 4) = (float)((float)(v9 * *(v18 - 4)) + *(v17 - 4)) * v13;
              *(v18 - 3) = v20;
              v21 = (float)(v9 * *(v18 - 1)) + *(v17 - 1);
              *(v18 - 2) = (float)((float)(v9 * *(v18 - 2)) + *(v17 - 2)) * v13;
              *(v18 - 1) = v21 * v13;
            }
            while ( (__int64)v17 < (__int64)(v19 - 3) );
          }
          if ( v17 < v19 )
          {
            v22 = (char *)v18 - (char *)v17;
            do
            {
              ++v17;
              *(float *)((char *)v17 + v22 - 4) = (float)((float)(v9 * *(float *)((char *)v17 + v22 - 4)) + *(v17 - 1))
                                                * v13;
            }
            while ( v17 < v19 );
          }
        }
      }
      else
      {
        v23 = v9;
        v24 = (float)(in_fResTargetGain - v9) * (float)(1.0 / (float)uMaxFrames);
        v25 = (float)(in_fOutTargetGain - v13) * (float)(1.0 / (float)uMaxFrames);
        v26 = v13;
        if ( v17 < v19 )
        {
          if ( (4 * uValidFrames + 3) / 4 >= 4 )
          {
            do
            {
              v27 = v26 + v25;
              v17 += 4;
              v18 += 4;
              v28 = (float)((float)((float)(v23 + v24) * *(v18 - 4)) + *(v17 - 4)) * v27;
              v29 = v27 + v25;
              *(v18 - 4) = v28;
              v30 = (float)(v23 + v24) + v24;
              v31 = v30 + v24;
              v32 = (float)((float)(v30 * *(v18 - 3)) + *(v17 - 3)) * v29;
              v33 = v29 + v25;
              *(v18 - 3) = v32;
              v34 = v31;
              v23 = v31 + v24;
              v35 = (float)((float)(v34 * *(v18 - 2)) + *(v17 - 2)) * v33;
              v26 = v33 + v25;
              *(v18 - 2) = v35;
              *(v18 - 1) = (float)((float)(v23 * *(v18 - 1)) + *(v17 - 1)) * v26;
            }
            while ( (__int64)v17 < (__int64)(v19 - 3) );
          }
          for ( ; v17 < v19; *(v18 - 1) = (float)((float)(v23 * *(v18 - 1)) + *(v17 - 1)) * v26 )
          {
            v23 = v23 + v24;
            v26 = v26 + v25;
            ++v17;
            ++v18;
          }
        }
      }
      v14 = (unsigned int)(uMaxFrames + v14);
      pData = (float *)((char *)pData + v16);
      --v15;
    }
    while ( v15 );
    *in_fResCurrentGain = in_fResTargetGain;
    *in_fOutCurrentGain = in_fOutTargetGain;
  }
  else
  {
    *in_fResCurrentGain = in_fResTargetGain;
    *in_fOutCurrentGain = in_fOutTargetGain;
  }
}

// File Line: 74
// RVA: 0xADFD80
void __fastcall Process_0(
        AkAudioBuffer *in_pBuffer,
        char *out_pBuffer,
        float *const in_pfCoefs,
        float *const io_pfMems,
        unsigned int in_uNumProcessedChannels,
        unsigned int in_uNumModes)
{
  unsigned int v6; // ebx
  float *v7; // r10
  char *v8; // r11
  unsigned int v10; // r15d
  __int64 v11; // rbp
  int v12; // r14d
  __int64 uMaxFrames; // rcx
  char *v14; // rsi
  char *v15; // r9
  __m128 *v16; // rax
  float *v17; // rdx
  __int64 v18; // r11
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  unsigned int *v21; // r8
  char *v22; // r10
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm7
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm2
  float *v32; // [rsp+70h] [rbp+18h]

  v32 = in_pfCoefs;
  v6 = 0;
  v7 = io_pfMems;
  v8 = out_pBuffer;
  v10 = ((in_uNumModes + 3) & 0xFFFFFFFC) >> 2;
  if ( in_uNumProcessedChannels )
  {
    v11 = 0i64;
    v12 = 0;
    do
    {
      uMaxFrames = in_pBuffer->uMaxFrames;
      v14 = &v8[4 * v6 * (unsigned int)uMaxFrames];
      v15 = (char *)in_pBuffer->pData + 4 * v11 * uMaxFrames;
      v16 = (__m128 *)&v7[v12];
      if ( v10 )
      {
        v17 = in_pfCoefs + 8;
        v18 = v10;
        do
        {
          v19 = *v16;
          v20 = v16[1];
          v21 = (unsigned int *)v15;
          v22 = &v15[4 * in_pBuffer->uValidFrames];
          v23 = *(__m128 *)(v17 - 8);
          v24 = *(__m128 *)(v17 - 4);
          v25 = *(__m128 *)v17;
          if ( v15 < v22 )
          {
            do
            {
              v26 = (__m128)*v21++;
              v27 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v25, v20), _mm_shuffle_ps(v26, v26, 0)), _mm_mul_ps(v24, v19));
              v28 = _mm_mul_ps(v23, v20);
              v20 = v19;
              v29 = _mm_sub_ps(_mm_mul_ps(v27, v23), v28);
              v30 = _mm_add_ps(v29, _mm_movehl_ps(v29, v29));
              v19 = v27;
              *(float *)((char *)v21 + v14 - v15 - 4) = *(float *)((char *)v21 + v14 - v15 - 4)
                                                      + (float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0]
                                                              + v30.m128_f32[0]);
            }
            while ( v21 < (unsigned int *)v22 );
          }
          *v16 = v19;
          v16[1] = v20;
          v16 += 2;
          v17 += 12;
          --v18;
        }
        while ( v18 );
        in_pfCoefs = v32;
        v7 = io_pfMems;
        v8 = out_pBuffer;
      }
      ++v6;
      ++v11;
      v12 += 2 * ((in_uNumModes + 3) & 0xFFFFFFFC);
    }
    while ( v6 < in_uNumProcessedChannels );
  }
}

