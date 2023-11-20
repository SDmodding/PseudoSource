// File Line: 32
// RVA: 0xADFA60
void __fastcall ScaleAndOutput(AkAudioBuffer *io_pOutBuffer, float *in_pInData, float in_fResTargetGain, float *in_fResCurrentGain, float in_fOutTargetGain, float *in_fOutCurrentGain, unsigned int in_uNumProcessedChannels)
{
  float *v7; // rbp
  float v8; // xmm7_4
  float v9; // xmm4_4
  float *v10; // r11
  signed int v11; // edi
  __int64 v12; // r15
  float v13; // xmm3_4
  __int64 v14; // r10
  __int64 v15; // rbx
  signed __int64 v16; // rsi
  float *v17; // rcx
  float *v18; // r8
  unsigned __int64 v19; // r9
  float v20; // xmm1_4
  float v21; // xmm1_4
  signed __int64 v22; // r8
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4

  v7 = in_fResCurrentGain;
  v8 = in_fResTargetGain;
  if ( in_uNumProcessedChannels )
  {
    v9 = *in_fResCurrentGain;
    v10 = (float *)io_pOutBuffer->pData;
    v11 = io_pOutBuffer->uMaxFrames;
    v12 = io_pOutBuffer->uValidFrames;
    v13 = *in_fOutCurrentGain;
    v14 = 0i64;
    v15 = in_uNumProcessedChannels;
    v16 = 4i64 * io_pOutBuffer->uMaxFrames;
    do
    {
      v17 = &in_pInData[v14];
      v18 = v10;
      v19 = (unsigned __int64)&v17[v12];
      if ( v8 != v9 || in_fOutTargetGain != v13 )
      {
        v23 = v9;
        v24 = (float)(v8 - v9) * (float)(1.0 / (float)v11);
        v25 = (float)(in_fOutTargetGain - v13) * (float)(1.0 / (float)v11);
        v26 = v13;
        if ( (unsigned __int64)v17 < v19 )
        {
          if ( (4 * v12 + 3) / 4 >= 4 )
          {
            do
            {
              v27 = v23 + v24;
              v28 = v26 + v25;
              v17 += 4;
              v18 += 4;
              v29 = v27;
              v30 = v27 + v24;
              v31 = (float)((float)(v29 * *(v18 - 4)) + *(v17 - 4)) * v28;
              v32 = v28 + v25;
              *(v18 - 4) = v31;
              v33 = v30;
              v34 = v30 + v24;
              v35 = (float)((float)(v33 * *(v18 - 3)) + *(v17 - 3)) * v32;
              v36 = v32 + v25;
              *(v18 - 3) = v35;
              v37 = v34;
              v23 = v34 + v24;
              v38 = (float)((float)(v37 * *(v18 - 2)) + *(v17 - 2)) * v36;
              v26 = v36 + v25;
              *(v18 - 2) = v38;
              *(v18 - 1) = (float)((float)(v23 * *(v18 - 1)) + *(v17 - 1)) * v26;
            }
            while ( (signed __int64)v17 < (signed __int64)(v19 - 12) );
          }
          for ( ; (unsigned __int64)v17 < v19; *(v18 - 1) = (float)((float)(v23 * *(v18 - 1)) + *(v17 - 1)) * v26 )
          {
            v23 = v23 + v24;
            v26 = v26 + v25;
            ++v17;
            ++v18;
          }
        }
      }
      else if ( (unsigned __int64)v17 < v19 )
      {
        if ( (4 * v12 + 3) / 4 >= 4 )
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
          while ( (signed __int64)v17 < (signed __int64)(v19 - 12) );
        }
        if ( (unsigned __int64)v17 < v19 )
        {
          v22 = (char *)v18 - (char *)v17;
          do
          {
            ++v17;
            *(float *)((char *)v17 + v22 - 4) = (float)((float)(v9 * *(float *)((char *)v17 + v22 - 4)) + *(v17 - 1))
                                              * v13;
          }
          while ( (unsigned __int64)v17 < v19 );
        }
      }
      v14 = (unsigned int)(v11 + v14);
      v10 = (float *)((char *)v10 + v16);
      --v15;
    }
    while ( v15 );
    *v7 = v8;
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
void __fastcall Process_0(AkAudioBuffer *in_pBuffer, void *const out_pBuffer, float *const in_pfCoefs, float *const io_pfMems, const unsigned int in_uNumProcessedChannels, const unsigned int in_uNumModes)
{
  unsigned int v6; // ebx
  float *v7; // r10
  char *v8; // r11
  unsigned int v9; // er15
  __int64 v10; // rbp
  int v11; // er14
  signed __int64 v12; // rsi
  char *v13; // r9
  __m128 *v14; // rax
  float *v15; // rdx
  __int64 v16; // r11
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  unsigned int *v19; // r8
  unsigned __int64 v20; // r10
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm7
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm2
  char *v29; // [rsp+68h] [rbp+10h]
  float *v30; // [rsp+70h] [rbp+18h]
  float *v31; // [rsp+78h] [rbp+20h]

  v31 = io_pfMems;
  v30 = in_pfCoefs;
  v29 = (char *)out_pBuffer;
  v6 = 0;
  v7 = io_pfMems;
  v8 = (char *)out_pBuffer;
  v9 = ((in_uNumModes + 3) & 0xFFFFFFFC) >> 2;
  if ( in_uNumProcessedChannels )
  {
    v10 = 0i64;
    v11 = 0;
    do
    {
      v12 = (signed __int64)&v8[4 * v6 * in_pBuffer->uMaxFrames];
      v13 = (char *)in_pBuffer->pData + 4 * v10 * in_pBuffer->uMaxFrames;
      v14 = (__m128 *)&v7[v11];
      if ( v9 )
      {
        v15 = in_pfCoefs + 8;
        v16 = v9;
        do
        {
          v17 = *v14;
          v18 = v14[1];
          v19 = (unsigned int *)v13;
          v20 = (unsigned __int64)&v13[4 * in_pBuffer->uValidFrames];
          v21 = *(__m128 *)((char *)v15 - 32);
          v22 = *(__m128 *)((char *)v15 - 16);
          v23 = *(__m128 *)v15;
          if ( (unsigned __int64)v13 < v20 )
          {
            do
            {
              v24 = (__m128)*v19;
              ++v19;
              v25 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, v18), _mm_shuffle_ps(v24, v24, 0)), _mm_mul_ps(v22, v17));
              v26 = _mm_mul_ps(v21, v18);
              v18 = v17;
              v27 = _mm_sub_ps(_mm_mul_ps(v25, v21), v26);
              v28 = _mm_add_ps(v27, _mm_movehl_ps(v27, v27));
              v17 = v25;
              *(float *)((char *)v19 + v12 - (_QWORD)v13 - 4) = *(float *)((char *)v19 + v12 - (_QWORD)v13 - 4)
                                                              + (float)(COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 85))
                                                                      + v28.m128_f32[0]);
            }
            while ( (unsigned __int64)v19 < v20 );
          }
          *v14 = v17;
          v14[1] = v18;
          v14 += 2;
          v15 += 12;
          --v16;
        }
        while ( v16 );
        in_pfCoefs = v30;
        v7 = v31;
        v8 = v29;
      }
      ++v6;
      ++v10;
      v11 += 2 * ((in_uNumModes + 3) & 0xFFFFFFFC);
    }
    while ( v6 < in_uNumProcessedChannels );
  }
}

