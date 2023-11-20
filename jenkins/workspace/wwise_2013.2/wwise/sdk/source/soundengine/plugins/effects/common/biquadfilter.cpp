// File Line: 25
// RVA: 0xAE62F0
void __fastcall DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(DSP::BiquadFilter<DSP::SingleChannelPolicy> *this, DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType in_eFilterType, const float in_fSampleRate, const float in_fFreq, const float in_fGain, const float in_fQ)
{
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *v6; // rbx
  float v7; // xmm12_4
  float v8; // xmm11_4
  float v9; // xmm7_4
  float v10; // xmm5_4
  float v11; // xmm9_4
  float v12; // xmm15_4
  float v13; // xmm14_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm11_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm11_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  __m128 v25; // xmm14
  float v26; // xmm1_4
  signed int v27; // ecx
  signed int v28; // eax
  float v29; // xmm11_4
  __m128 v30; // xmm1
  float v31; // xmm7_4
  float v32; // xmm9_4
  float v33; // xmm10_4
  float v34; // xmm8_4
  float v35; // xmm0_4
  float v36; // xmm5_4
  float v37; // xmm14_4
  float v38; // xmm12_4
  float v39; // xmm8_4
  __m128 v40; // xmm9
  float v41; // xmm1_4
  signed int v42; // ecx
  float v43; // xmm11_4
  __m128 v44; // xmm1
  float v45; // xmm6_4
  float v46; // xmm8_4
  float v47; // xmm14_4
  float v48; // xmm12_4
  float v49; // xmm0_4
  float v50; // xmm11_4
  float v51; // xmm8_4
  float v52; // xmm6_4
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm0_4
  float v57; // xmm2_4
  int v58; // [rsp+E8h] [rbp+10h]
  float v59; // [rsp+E8h] [rbp+10h]
  float v60; // [rsp+E8h] [rbp+10h]

  v6 = this;
  v7 = 0.0;
  v8 = in_fFreq;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0.0;
  v12 = 0.0;
  v13 = 0.0;
  if ( (float)((float)(in_fSampleRate * 0.5) * 0.89999998) < in_fFreq )
    v8 = (float)(in_fSampleRate * 0.5) * 0.89999998;
  switch ( in_eFilterType )
  {
    case 3:
      v11 = *(float *)&FLOAT_1_0;
      v14 = 1.0 / tanf((float)(v8 * 3.1415927) / in_fSampleRate);
      v15 = v14;
      v16 = v14 * v14;
      v17 = v15 * 1.4142135;
      v9 = 1.0 / (float)((float)(v16 + 1.0) + v17);
      v13 = (float)((float)(v16 + 1.0) - v17) * v9;
      v10 = 1.0 / (float)((float)(v16 + 1.0) + v17);
      v7 = v9 * 2.0;
      v12 = (float)(1.0 - v16) * (float)(v9 * 2.0);
      break;
    case 4:
      v18 = tanf((float)(v8 * 3.1415927) / in_fSampleRate);
      v11 = *(float *)&FLOAT_1_0;
      v9 = 1.0 / (float)((float)((float)(v18 * v18) + 1.0) + (float)(v18 * 1.4142135));
      v13 = (float)((float)((float)(v18 * v18) + 1.0) - (float)(v18 * 1.4142135)) * v9;
      v10 = 1.0 / (float)((float)((float)(v18 * v18) + 1.0) + (float)(v18 * 1.4142135));
      v7 = v9 * -2.0;
      LODWORD(v12) = COERCE_UNSIGNED_INT((float)((float)(v18 * v18) - 1.0) * (float)(v9 * -2.0)) ^ _xmm[0];
      break;
    case 5:
      v19 = (float)(v8 * 6.2831855) / in_fSampleRate;
      v20 = sinf(v19) / (float)(in_fQ * 2.0);
      v9 = v20;
      v11 = v20 + 1.0;
      v58 = LODWORD(v20) ^ _xmm[0];
      v21 = cosf(v19);
      v10 = *(float *)&v58;
      v13 = 1.0 - v9;
      v12 = v21 * -2.0;
      break;
    case 6:
      v22 = (float)(v8 * 6.2831855) / in_fSampleRate;
      v9 = *(float *)&FLOAT_1_0;
      v23 = sinf(v22) / (float)(in_fQ * 2.0);
      v24 = cosf(v22);
      v10 = *(float *)&FLOAT_1_0;
      v11 = v23 + 1.0;
      v13 = 1.0 - v23;
      v7 = v24 * -2.0;
      v12 = v24 * -2.0;
      break;
    default:
      if ( in_eFilterType )
      {
        if ( in_eFilterType == 2 )
        {
          if ( (float)(in_fGain * 0.025) >= -37.0 )
          {
            if ( `AkMath::FastPow10::`4::`local static guard & 1 )
            {
              v41 = *(float *)&`AkMath::FastPow10::`4::SCALE;
            }
            else
            {
              v41 = FLOAT_2_7866352e7;
              `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              `AkMath::FastPow10::`4::`local static guard |= 1u;
            }
            v42 = (signed int)(float)((float)((float)(in_fGain * 0.025) * v41) + 1065353200.0);
            LODWORD(v60) = (v42 & 0x7FFFFF) + 1065353216;
            v40 = (__m128)LODWORD(v60);
            v40.m128_f32[0] = (float)((float)((float)((float)(v60 * 0.32518977) + 0.020805772) * v60) + 0.65304345)
                            * COERCE_FLOAT(v42 & 0xFF800000);
          }
          else
          {
            v40 = 0i64;
          }
          v43 = (float)(v8 * 6.2831855) / in_fSampleRate;
          v44 = (__m128)(unsigned int)FLOAT_1_0;
          v45 = cosf(v43);
          v44.m128_f32[0] = (float)((float)((float)(1.0 / v40.m128_f32[0]) + v40.m128_f32[0]) * 0.0) + 2.0;
          v46 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v44)) * (float)(sinf(v43) * 0.5))
              * (float)(COERCE_FLOAT(_mm_sqrt_ps(v40)) * 2.0);
          v47 = (float)(v40.m128_f32[0] + 1.0) - (float)((float)(v40.m128_f32[0] - 1.0) * v45);
          v44.m128_f32[0] = (float)(v40.m128_f32[0] + 1.0) * v45;
          v10 = (float)((float)((float)((float)(v40.m128_f32[0] - 1.0) * v45) + (float)(v40.m128_f32[0] + 1.0)) - v46)
              * v40.m128_f32[0];
          v48 = v44.m128_f32[0] + (float)(v40.m128_f32[0] - 1.0);
          v49 = v40.m128_f32[0];
          v12 = (float)((float)(v40.m128_f32[0] - 1.0) - v44.m128_f32[0]) * 2.0;
          v9 = (float)((float)((float)((float)(v40.m128_f32[0] - 1.0) * v45) + (float)(v40.m128_f32[0] + 1.0)) + v46)
             * v40.m128_f32[0];
          v11 = v47 + v46;
          v13 = v47 - v46;
          v7 = v48 * (float)(v49 * -2.0);
        }
        else if ( in_eFilterType == 1 )
        {
          v50 = (float)(v8 * 6.2831855) / in_fSampleRate;
          v51 = cosf(v50);
          if ( (float)(in_fGain * 0.025) >= -37.0 )
          {
            if ( `AkMath::FastPow10::`4::`local static guard & 1 )
            {
              v53 = *(float *)&`AkMath::FastPow10::`4::SCALE;
            }
            else
            {
              v53 = FLOAT_2_7866352e7;
              `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              `AkMath::FastPow10::`4::`local static guard |= 1u;
            }
            v52 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                    ((signed int)(float)((float)((float)(in_fGain * 0.025) * v53)
                                                                       + 1065353200.0) & 0x7FFFFF)
                                                  + 1065353216)
                                                * 0.32518977)
                                        + 0.020805772)
                                * COERCE_FLOAT(
                                    ((signed int)(float)((float)((float)(in_fGain * 0.025) * v53) + 1065353200.0) & 0x7FFFFF)
                                  + 1065353216))
                        + 0.65304345)
                * COERCE_FLOAT((signed int)(float)((float)((float)(in_fGain * 0.025) * v53) + 1065353200.0) & 0xFF800000);
          }
          else
          {
            v52 = 0.0;
          }
          v7 = v51 * -2.0;
          v12 = v51 * -2.0;
          v54 = sinf(v50) / (float)(in_fQ * 2.0);
          v55 = v54;
          v56 = v54 / v52;
          v57 = v55 * v52;
          v13 = 1.0 - v56;
          v11 = v56 + 1.0;
          v10 = 1.0 - v57;
          v9 = v57 + 1.0;
        }
      }
      else
      {
        if ( (float)(in_fGain * 0.025) >= -37.0 )
        {
          if ( `AkMath::FastPow10::`4::`local static guard & 1 )
          {
            v26 = *(float *)&`AkMath::FastPow10::`4::SCALE;
          }
          else
          {
            v26 = FLOAT_2_7866352e7;
            `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
            `AkMath::FastPow10::`4::`local static guard |= 1u;
          }
          v27 = (signed int)(float)((float)((float)(in_fGain * 0.025) * v26) + 1065353200.0);
          v28 = v27;
          v27 &= 0x7FFFFFu;
          v25 = (__m128)(unsigned int)(v27 + 1065353216);
          v25.m128_f32[0] = (float)((float)((float)((float)(COERCE_FLOAT(v27 + 1065353216) * 0.32518977) + 0.020805772)
                                          * COERCE_FLOAT(v27 + 1065353216))
                                  + 0.65304345)
                          * COERCE_FLOAT(v28 & 0xFF800000);
        }
        else
        {
          v25 = 0i64;
        }
        v59 = v25.m128_f32[0];
        v29 = (float)(v8 * 6.2831855) / in_fSampleRate;
        v30 = (__m128)(unsigned int)FLOAT_1_0;
        v31 = cosf(v29);
        v32 = v25.m128_f32[0] + 1.0;
        v33 = v25.m128_f32[0] - 1.0;
        v30.m128_f32[0] = (float)((float)((float)(1.0 / v25.m128_f32[0]) + v25.m128_f32[0]) * 0.0) + 2.0;
        LODWORD(v34) = (unsigned __int128)_mm_sqrt_ps(v30);
        v35 = sinf(v29);
        v30.m128_i32[0] = (unsigned __int128)_mm_sqrt_ps(v25);
        v36 = (float)(v25.m128_f32[0] + 1.0) - (float)((float)(v25.m128_f32[0] - 1.0) * v31);
        v37 = (float)((float)(v25.m128_f32[0] - 1.0) * v31) + (float)(v25.m128_f32[0] + 1.0);
        v38 = v33 - (float)(v32 * v31);
        v12 = (float)((float)(v32 * v31) + v33) * -2.0;
        v39 = (float)(v34 * (float)(v35 * 0.5)) * (float)(v30.m128_f32[0] * 2.0);
        v11 = v37 + v39;
        v9 = (float)(v36 + v39) * v59;
        v10 = (float)(v36 - v39) * v59;
        v13 = v37 - v39;
        v7 = v38 * (float)(v59 * 2.0);
      }
      break;
  }
  DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
    v6,
    (float)(1.0 / v11) * v9,
    (float)(1.0 / v11) * v7,
    (float)(1.0 / v11) * v10,
    (float)(1.0 / v11) * v12,
    (float)(1.0 / v11) * v13);
}

// File Line: 248
// RVA: 0xADE0A0
void __fastcall DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(DSP::BiquadFilter<DSP::SingleChannelPolicy> *this, float *io_pBuffer, unsigned int in_uNumframes, unsigned int in_iChannel)
{
  DSP::BiquadFilter<DSP::SingleChannelPolicy> *v4; // rdi
  unsigned int v5; // er14
  unsigned int v6; // ebp
  float *v7; // rsi
  __int64 v8; // rbx
  unsigned int v9; // eax
  int v10; // er8
  __m128 v11; // xmm7
  __m128 v12; // xmm6
  __m128 v13; // xmm8
  unsigned __int64 v14; // rcx
  __m128 v15; // xmm5
  __m128 v16; // xmm9
  __m128 v17; // xmm10
  __m128 v18; // xmm11
  __m128 v19; // xmm12
  __m128 v20; // xmm13
  __m128 v21; // xmm14
  __m128 v22; // xmm15
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  float v27; // [rsp+20h] [rbp-E8h]
  float v28; // [rsp+30h] [rbp-D8h]
  float v29; // [rsp+40h] [rbp-C8h]
  float v30; // [rsp+50h] [rbp-B8h]

  v4 = this;
  v5 = in_iChannel;
  v6 = in_uNumframes;
  v7 = io_pBuffer;
  if ( (unsigned __int8)io_pBuffer & 0xF )
  {
    v8 = in_uNumframes;
    v9 = (16 - ((unsigned __int8)io_pBuffer & 0xFu)) >> 2;
    if ( v9 < in_uNumframes )
      v8 = v9;
    DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(this, io_pBuffer, v8, in_iChannel);
    v7 += v8;
    v6 -= v8;
  }
  v10 = v6 & 3;
  v11 = _mm_shuffle_ps(
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFwd1),
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFwd1),
          0);
  v12 = _mm_shuffle_ps(
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFwd2),
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFwd2),
          0);
  v13 = _mm_shuffle_ps(
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFbk1),
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFbk1),
          0);
  v14 = (unsigned __int64)&v7[v6 - v10];
  v27 = v11.m128_f32[0];
  v28 = v12.m128_f32[0];
  v29 = v13.m128_f32[0];
  v15 = _mm_shuffle_ps(
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFbk2),
          (__m128)LODWORD(v4->m_Memories.m_Memories.fFFbk2),
          0);
  v30 = v15.m128_f32[0];
  if ( (unsigned __int64)v7 < v14 )
  {
    v16 = v4->m_Coefficients.vXPrev1;
    v17 = v4->m_Coefficients.vXPrev2;
    v18 = v4->m_Coefficients.vYPrev2;
    v19 = v4->m_Coefficients.vYPrev1;
    v20 = v4->m_Coefficients.vSecond;
    v21 = v4->m_Coefficients.vFirst;
    v22 = v4->m_Coefficients.vThird;
    do
    {
      v23 = *(__m128 *)v7;
      v7 += 4;
      v24 = _mm_mul_ps(v17, v12);
      v12 = _mm_shuffle_ps(v23, v23, 170);
      v25 = _mm_add_ps(v24, _mm_mul_ps(v16, v11));
      v11 = _mm_shuffle_ps(v23, v23, 255);
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, v18), _mm_mul_ps(v19, v13)), _mm_mul_ps(v20, v12)),
                _mm_add_ps(_mm_mul_ps(v21, v23), v25)),
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v4->m_Coefficients.vFourth),
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v22)));
      *((__m128 *)v7 - 1) = v26;
      v13 = _mm_shuffle_ps(v26, v26, 255);
      v15 = _mm_shuffle_ps(v26, v26, 170);
    }
    while ( (unsigned __int64)v7 < v14 );
    v30 = v15.m128_f32[0];
    v28 = v12.m128_f32[0];
    v27 = v11.m128_f32[0];
    v29 = v13.m128_f32[0];
  }
  v4->m_Memories.m_Memories.fFFwd1 = v27;
  v4->m_Memories.m_Memories.fFFwd2 = v28;
  v4->m_Memories.m_Memories.fFFbk1 = v29;
  v4->m_Memories.m_Memories.fFFbk2 = v30;
  if ( v6 & 3 )
    DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(v4, v7, v10, v5);
}

// File Line: 348
// RVA: 0xA90E20
void __fastcall DSP::BiquadFilter<DSP::MultiChannelPolicy>::ProcessBufferScalar(DSP::BiquadFilter<DSP::MultiChannelPolicy> *this, float *io_pBuffer, unsigned int in_uNumframes, unsigned int in_iChannel)
{
  __int64 v4; // rax
  signed __int64 v5; // r8
  DSP::Memories *v6; // r9
  signed __int64 v7; // r8
  float *v8; // r11
  float *v9; // r10
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm5_4
  float v14; // xmm9_4
  float v15; // xmm10_4
  float v16; // xmm11_4
  float v17; // xmm13_4
  float v18; // xmm12_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  float v27; // xmm5_4
  float v28; // xmm3_4
  float v29; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm9_4
  float v33; // xmm10_4
  float v34; // xmm11_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm2_4
  float v39; // xmm2_4

  v4 = in_uNumframes;
  v5 = in_iChannel;
  v6 = this->m_Memories.m_pMemories;
  v7 = v5;
  v8 = &io_pBuffer[v4];
  v9 = io_pBuffer;
  v10 = v6[v7].fFFwd1;
  v11 = v6[v7].fFFwd2;
  v12 = v6[v7].fFFbk1;
  v13 = v6[v7].fFFbk2;
  if ( io_pBuffer < v8 )
  {
    if ( (4 * v4 + 3) / 4 >= 4 )
    {
      v14 = this->m_Coefficients.fB2;
      v15 = this->m_Coefficients.fB0;
      v16 = this->m_Coefficients.fB1;
      v17 = this->m_Coefficients.fA1;
      v18 = this->m_Coefficients.fA2;
      do
      {
        v19 = *v9;
        v20 = v9[1];
        v21 = v16 * v10;
        v22 = *v9;
        v23 = v9[1];
        v9 += 4;
        v24 = (float)(v22 * v15) + (float)(v11 * v14);
        v11 = *(v9 - 2);
        v25 = (float)(v23 * v15) + (float)(v10 * v14);
        v10 = *(v9 - 1);
        v26 = (float)(v24 + v21) + (float)(v13 * v18);
        v27 = *(v9 - 2);
        v28 = v26 + (float)(v17 * v12);
        *(v9 - 4) = v28;
        v29 = (float)((float)(v25 + (float)(v16 * v19)) + (float)(v12 * v18)) + (float)(v17 * v28);
        *(v9 - 3) = v29;
        v13 = (float)((float)((float)((float)(v27 * v15) + (float)(v19 * v14)) + (float)(v16 * v20)) + (float)(v28 * v18))
            + (float)(v17 * v29);
        *(v9 - 2) = v13;
        v12 = (float)((float)((float)((float)(v10 * v15) + (float)(v20 * v14)) + (float)(v16 * v11)) + (float)(v29 * v18))
            + (float)(v17 * v13);
        *(v9 - 1) = v12;
      }
      while ( (signed __int64)v9 < (signed __int64)(v8 - 3) );
    }
    if ( v9 < v8 )
    {
      v30 = this->m_Coefficients.fB2;
      v31 = this->m_Coefficients.fB0;
      v32 = this->m_Coefficients.fB1;
      v33 = this->m_Coefficients.fA2;
      v34 = this->m_Coefficients.fA1;
      do
      {
        v35 = *v9;
        v36 = v32 * v10;
        ++v9;
        v37 = (float)(v35 * v31) + (float)(v11 * v30);
        v11 = v10;
        v10 = v35;
        v38 = (float)(v37 + v36) + (float)(v13 * v33);
        v13 = v12;
        v39 = v38 + (float)(v34 * v12);
        *(v9 - 1) = v39;
        v12 = v39;
      }
      while ( v9 < v8 );
    }
  }
  v6[v7].fFFwd1 = v10;
  v6[v7].fFFwd2 = v11;
  v6[v7].fFFbk1 = v12;
  v6[v7].fFFbk2 = v13;
}

