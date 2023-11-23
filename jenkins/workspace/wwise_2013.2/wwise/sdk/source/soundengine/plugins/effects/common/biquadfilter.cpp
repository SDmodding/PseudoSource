// File Line: 25
// RVA: 0xAE62F0
void __fastcall DSP::BiquadFilter<DSP::SingleChannelPolicy>::ComputeCoefs(
        DSP::BiquadFilter<DSP::SingleChannelPolicy> *this,
        DSP::BiquadFilter<DSP::SingleChannelPolicy>::FilterType in_eFilterType,
        const float in_fSampleRate,
        float in_fFreq,
        float in_fGain,
        float in_fQ)
{
  float v7; // xmm12_4
  float v8; // xmm11_4
  float v9; // xmm7_4
  float v10; // xmm5_4
  float v11; // xmm9_4
  float v12; // xmm15_4
  float v13; // xmm14_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm11_4
  float v19; // xmm0_4
  float v20; // xmm11_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  __m128 v23; // xmm14
  float v24; // xmm1_4
  int v25; // eax
  float v26; // xmm11_4
  __m128 v27; // xmm1
  float v28; // xmm7_4
  float v29; // xmm9_4
  float v30; // xmm10_4
  float v31; // xmm8_4
  float v32; // xmm0_4
  float v33; // xmm5_4
  float v34; // xmm14_4
  float v35; // xmm12_4
  float v36; // xmm8_4
  __m128 v37; // xmm9
  float v38; // xmm1_4
  int v39; // eax
  float v40; // xmm11_4
  __m128 v41; // xmm1
  float v42; // xmm6_4
  float v43; // xmm8_4
  float v44; // xmm14_4
  float v45; // xmm12_4
  float v46; // xmm0_4
  float v47; // xmm11_4
  float v48; // xmm8_4
  float v49; // xmm6_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // [rsp+E8h] [rbp+10h]

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
    case FilterType_LowPass:
      v14 = tanf((float)(v8 * 3.1415927) / in_fSampleRate);
      v11 = *(float *)&FLOAT_1_0;
      v15 = (float)(1.0 / v14) * (float)(1.0 / v14);
      v16 = (float)(1.0 / v14) * 1.4142135;
      v9 = 1.0 / (float)((float)(v15 + 1.0) + v16);
      v13 = (float)((float)(v15 + 1.0) - v16) * v9;
      v10 = v9;
      v7 = v9 * 2.0;
      v12 = (float)(1.0 - v15) * (float)(v9 * 2.0);
      break;
    case FilterType_HighPass:
      v17 = tanf((float)(v8 * 3.1415927) / in_fSampleRate);
      v11 = *(float *)&FLOAT_1_0;
      v9 = 1.0 / (float)((float)((float)(v17 * v17) + 1.0) + (float)(v17 * 1.4142135));
      v13 = (float)((float)((float)(v17 * v17) + 1.0) - (float)(v17 * 1.4142135)) * v9;
      v10 = v9;
      v7 = v9 * -2.0;
      LODWORD(v12) = COERCE_UNSIGNED_INT((float)((float)(v17 * v17) - 1.0) * (float)(v9 * -2.0)) ^ _xmm[0];
      break;
    case FilterType_BandPass:
      v18 = (float)(v8 * 6.2831855) / in_fSampleRate;
      v9 = sinf(v18) / (float)(in_fQ * 2.0);
      v11 = v9 + 1.0;
      v19 = cosf(v18);
      LODWORD(v10) = LODWORD(v9) ^ _xmm[0];
      v13 = 1.0 - v9;
      v12 = v19 * -2.0;
      break;
    case FilterType_Notch:
      v20 = (float)(v8 * 6.2831855) / in_fSampleRate;
      v9 = *(float *)&FLOAT_1_0;
      v21 = sinf(v20) / (float)(in_fQ * 2.0);
      v22 = cosf(v20);
      v10 = *(float *)&FLOAT_1_0;
      v11 = v21 + 1.0;
      v13 = 1.0 - v21;
      v7 = v22 * -2.0;
      v12 = v22 * -2.0;
      break;
    default:
      if ( in_eFilterType )
      {
        if ( in_eFilterType == FilterType_HighShelf )
        {
          if ( (float)(in_fGain * 0.025) >= -37.0 )
          {
            if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
            {
              v38 = *(float *)&`AkMath::FastPow10::`4::SCALE;
            }
            else
            {
              v38 = FLOAT_2_7866352e7;
              `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              `AkMath::FastPow10::`4::`local static guard |= 1u;
            }
            v39 = (int)(float)((float)((float)(in_fGain * 0.025) * v38) + 1065353200.0);
            v37 = (__m128)((v39 & 0x7FFFFFu) + 1065353216);
            v37.m128_f32[0] = (float)((float)((float)((float)(COERCE_FLOAT((v39 & 0x7FFFFF) + 1065353216) * 0.32518977)
                                                    + 0.020805772)
                                            * COERCE_FLOAT((v39 & 0x7FFFFF) + 1065353216))
                                    + 0.65304345)
                            * COERCE_FLOAT(v39 & 0xFF800000);
          }
          else
          {
            v37 = 0i64;
          }
          v40 = (float)(v8 * 6.2831855) / in_fSampleRate;
          v41 = (__m128)(unsigned int)FLOAT_1_0;
          v42 = cosf(v40);
          v41.m128_f32[0] = (float)((float)((float)(1.0 / v37.m128_f32[0]) + v37.m128_f32[0]) * 0.0) + 2.0;
          v43 = (float)(_mm_sqrt_ps(v41).m128_f32[0] * (float)(sinf(v40) * 0.5))
              * (float)(_mm_sqrt_ps(v37).m128_f32[0] * 2.0);
          v44 = (float)(v37.m128_f32[0] + 1.0) - (float)((float)(v37.m128_f32[0] - 1.0) * v42);
          v41.m128_f32[0] = (float)(v37.m128_f32[0] + 1.0) * v42;
          v10 = (float)((float)((float)((float)(v37.m128_f32[0] - 1.0) * v42) + (float)(v37.m128_f32[0] + 1.0)) - v43)
              * v37.m128_f32[0];
          v45 = v41.m128_f32[0] + (float)(v37.m128_f32[0] - 1.0);
          v46 = v37.m128_f32[0];
          v12 = (float)((float)(v37.m128_f32[0] - 1.0) - v41.m128_f32[0]) * 2.0;
          v9 = (float)((float)((float)((float)(v37.m128_f32[0] - 1.0) * v42) + (float)(v37.m128_f32[0] + 1.0)) + v43)
             * v37.m128_f32[0];
          v11 = v44 + v43;
          v13 = v44 - v43;
          v7 = v45 * (float)(v46 * -2.0);
        }
        else if ( in_eFilterType == FilterType_Peaking )
        {
          v47 = (float)(v8 * 6.2831855) / in_fSampleRate;
          v48 = cosf(v47);
          if ( (float)(in_fGain * 0.025) >= -37.0 )
          {
            if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
            {
              v50 = *(float *)&`AkMath::FastPow10::`4::SCALE;
            }
            else
            {
              v50 = FLOAT_2_7866352e7;
              `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
              `AkMath::FastPow10::`4::`local static guard |= 1u;
            }
            v49 = (float)((float)((float)((float)(COERCE_FLOAT(
                                                    ((int)(float)((float)((float)(in_fGain * 0.025) * v50) + 1065353200.0) & 0x7FFFFF)
                                                  + 1065353216)
                                                * 0.32518977)
                                        + 0.020805772)
                                * COERCE_FLOAT(
                                    ((int)(float)((float)((float)(in_fGain * 0.025) * v50) + 1065353200.0) & 0x7FFFFF)
                                  + 1065353216))
                        + 0.65304345)
                * COERCE_FLOAT((int)(float)((float)((float)(in_fGain * 0.025) * v50) + 1065353200.0) & 0xFF800000);
          }
          else
          {
            v49 = 0.0;
          }
          v7 = v48 * -2.0;
          v12 = v48 * -2.0;
          v51 = sinf(v47) / (float)(in_fQ * 2.0);
          v52 = v51 / v49;
          v53 = v51 * v49;
          v13 = 1.0 - v52;
          v11 = v52 + 1.0;
          v10 = 1.0 - v53;
          v9 = v53 + 1.0;
        }
      }
      else
      {
        if ( (float)(in_fGain * 0.025) >= -37.0 )
        {
          if ( (`AkMath::FastPow10::`4::`local static guard & 1) != 0 )
          {
            v24 = *(float *)&`AkMath::FastPow10::`4::SCALE;
          }
          else
          {
            v24 = FLOAT_2_7866352e7;
            `AkMath::FastPow10::`4::SCALE = LODWORD(FLOAT_2_7866352e7);
            `AkMath::FastPow10::`4::`local static guard |= 1u;
          }
          v25 = (int)(float)((float)((float)(in_fGain * 0.025) * v24) + 1065353200.0);
          v23 = (__m128)((v25 & 0x7FFFFFu) + 1065353216);
          v23.m128_f32[0] = (float)((float)((float)((float)(COERCE_FLOAT((v25 & 0x7FFFFF) + 1065353216) * 0.32518977)
                                                  + 0.020805772)
                                          * COERCE_FLOAT((v25 & 0x7FFFFF) + 1065353216))
                                  + 0.65304345)
                          * COERCE_FLOAT(v25 & 0xFF800000);
        }
        else
        {
          v23 = 0i64;
        }
        v54 = v23.m128_f32[0];
        v26 = (float)(v8 * 6.2831855) / in_fSampleRate;
        v27 = (__m128)(unsigned int)FLOAT_1_0;
        v28 = cosf(v26);
        v29 = v23.m128_f32[0] + 1.0;
        v30 = v23.m128_f32[0] - 1.0;
        v27.m128_f32[0] = (float)((float)((float)(1.0 / v23.m128_f32[0]) + v23.m128_f32[0]) * 0.0) + 2.0;
        v31 = _mm_sqrt_ps(v27).m128_f32[0];
        v32 = sinf(v26);
        v27.m128_f32[0] = _mm_sqrt_ps(v23).m128_f32[0];
        v33 = (float)(v23.m128_f32[0] + 1.0) - (float)((float)(v23.m128_f32[0] - 1.0) * v28);
        v34 = (float)((float)(v23.m128_f32[0] - 1.0) * v28) + (float)(v23.m128_f32[0] + 1.0);
        v35 = v30 - (float)(v29 * v28);
        v12 = (float)((float)(v29 * v28) + v30) * -2.0;
        v36 = (float)(v31 * (float)(v32 * 0.5)) * (float)(v27.m128_f32[0] * 2.0);
        v11 = v34 + v36;
        v9 = (float)(v33 + v36) * v54;
        v10 = (float)(v33 - v36) * v54;
        v13 = v34 - v36;
        v7 = v35 * (float)(v54 * 2.0);
      }
      break;
  }
  DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
    this,
    (float)(1.0 / v11) * v9,
    (float)(1.0 / v11) * v7,
    (float)(1.0 / v11) * v10,
    (float)(1.0 / v11) * v12,
    (float)(1.0 / v11) * v13);
}

// File Line: 248
// RVA: 0xADE0A0
void __fastcall DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBuffer(
        DSP::BiquadFilter<DSP::SingleChannelPolicy> *this,
        float *io_pBuffer,
        unsigned int in_uNumframes,
        unsigned int in_iChannel)
{
  unsigned int v6; // ebp
  float *v7; // rsi
  __int64 v8; // rbx
  unsigned int v9; // eax
  int v10; // r8d
  __m128 v11; // xmm7
  __m128 v12; // xmm6
  __m128 v13; // xmm8
  float *v14; // rcx
  __m128 v15; // xmm5
  __m128 vXPrev1; // xmm9
  __m128 vXPrev2; // xmm10
  __m128 vYPrev2; // xmm11
  __m128 vYPrev1; // xmm12
  __m128 vSecond; // xmm13
  __m128 vFirst; // xmm14
  __m128 vThird; // xmm15
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  float v27; // [rsp+20h] [rbp-E8h]
  float v28; // [rsp+30h] [rbp-D8h]
  float v29; // [rsp+40h] [rbp-C8h]
  float v30; // [rsp+50h] [rbp-B8h]

  v6 = in_uNumframes;
  v7 = io_pBuffer;
  if ( ((unsigned __int8)io_pBuffer & 0xF) != 0 )
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
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFwd1),
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFwd1),
          0);
  v12 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFwd2),
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFwd2),
          0);
  v13 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFbk1),
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFbk1),
          0);
  v14 = &v7[v6 - v10];
  v27 = v11.m128_f32[0];
  v28 = v12.m128_f32[0];
  v29 = v13.m128_f32[0];
  v15 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFbk2),
          (__m128)LODWORD(this->m_Memories.m_Memories.fFFbk2),
          0);
  v30 = v15.m128_f32[0];
  if ( v7 < v14 )
  {
    vXPrev1 = this->m_Coefficients.vXPrev1;
    vXPrev2 = this->m_Coefficients.vXPrev2;
    vYPrev2 = this->m_Coefficients.vYPrev2;
    vYPrev1 = this->m_Coefficients.vYPrev1;
    vSecond = this->m_Coefficients.vSecond;
    vFirst = this->m_Coefficients.vFirst;
    vThird = this->m_Coefficients.vThird;
    do
    {
      v23 = *(__m128 *)v7;
      v7 += 4;
      v24 = _mm_mul_ps(vXPrev2, v12);
      v12 = _mm_shuffle_ps(v23, v23, 170);
      v25 = _mm_add_ps(v24, _mm_mul_ps(vXPrev1, v11));
      v11 = _mm_shuffle_ps(v23, v23, 255);
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, vYPrev2), _mm_mul_ps(vYPrev1, v13)), _mm_mul_ps(vSecond, v12)),
                _mm_add_ps(_mm_mul_ps(vFirst, v23), v25)),
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), this->m_Coefficients.vFourth),
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), vThird)));
      *((__m128 *)v7 - 1) = v26;
      v13 = _mm_shuffle_ps(v26, v26, 255);
      v15 = _mm_shuffle_ps(v26, v26, 170);
    }
    while ( v7 < v14 );
    v30 = v15.m128_f32[0];
    v28 = v12.m128_f32[0];
    v27 = v11.m128_f32[0];
    v29 = v13.m128_f32[0];
  }
  this->m_Memories.m_Memories.fFFwd1 = v27;
  this->m_Memories.m_Memories.fFFwd2 = v28;
  this->m_Memories.m_Memories.fFFbk1 = v29;
  this->m_Memories.m_Memories.fFFbk2 = v30;
  if ( (v6 & 3) != 0 )
    DSP::BiquadFilter<DSP::SingleChannelPolicy>::ProcessBufferScalar(this, v7, v10, in_iChannel);
}

// File Line: 348
// RVA: 0xA90E20
void __fastcall DSP::BiquadFilter<DSP::MultiChannelPolicy>::ProcessBufferScalar(
        DSP::BiquadFilter<DSP::MultiChannelPolicy> *this,
        float *io_pBuffer,
        unsigned int in_uNumframes,
        unsigned int in_iChannel)
{
  __int64 v4; // rax
  __int64 v5; // r8
  DSP::Memories *m_pMemories; // r9
  __int64 v7; // r8
  float *v8; // r11
  float *v9; // r10
  float fFFwd1; // xmm8_4
  float fFFwd2; // xmm7_4
  float fFFbk1; // xmm6_4
  float fFFbk2; // xmm5_4
  float fB2; // xmm9_4
  float fB0; // xmm10_4
  float fB1; // xmm11_4
  float fA1; // xmm13_4
  float fA2; // xmm12_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm9_4
  float v30; // xmm10_4
  float v31; // xmm11_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm2_4
  float v36; // xmm2_4

  v4 = in_uNumframes;
  v5 = in_iChannel;
  m_pMemories = this->m_Memories.m_pMemories;
  v7 = v5;
  v8 = &io_pBuffer[v4];
  v9 = io_pBuffer;
  fFFwd1 = m_pMemories[v7].fFFwd1;
  fFFwd2 = m_pMemories[v7].fFFwd2;
  fFFbk1 = m_pMemories[v7].fFFbk1;
  fFFbk2 = m_pMemories[v7].fFFbk2;
  if ( io_pBuffer < v8 )
  {
    if ( (4 * v4 + 3) / 4 >= 4 )
    {
      fB2 = this->m_Coefficients.fB2;
      fB0 = this->m_Coefficients.fB0;
      fB1 = this->m_Coefficients.fB1;
      fA1 = this->m_Coefficients.fA1;
      fA2 = this->m_Coefficients.fA2;
      do
      {
        v19 = *v9;
        v20 = v9[1];
        v21 = fB1 * fFFwd1;
        v22 = *v9;
        v9 += 4;
        v23 = (float)(v22 * fB0) + (float)(fFFwd2 * fB2);
        fFFwd2 = *(v9 - 2);
        v24 = (float)(v20 * fB0) + (float)(fFFwd1 * fB2);
        fFFwd1 = *(v9 - 1);
        v25 = (float)((float)(v23 + v21) + (float)(fFFbk2 * fA2)) + (float)(fA1 * fFFbk1);
        *(v9 - 4) = v25;
        v26 = (float)((float)(v24 + (float)(fB1 * v19)) + (float)(fFFbk1 * fA2)) + (float)(fA1 * v25);
        *(v9 - 3) = v26;
        fFFbk2 = (float)((float)((float)((float)(fFFwd2 * fB0) + (float)(v19 * fB2)) + (float)(fB1 * v20))
                       + (float)(v25 * fA2))
               + (float)(fA1 * v26);
        *(v9 - 2) = fFFbk2;
        fFFbk1 = (float)((float)((float)((float)(fFFwd1 * fB0) + (float)(v20 * fB2)) + (float)(fB1 * fFFwd2))
                       + (float)(v26 * fA2))
               + (float)(fA1 * fFFbk2);
        *(v9 - 1) = fFFbk1;
      }
      while ( (__int64)v9 < (__int64)(v8 - 3) );
    }
    if ( v9 < v8 )
    {
      v27 = this->m_Coefficients.fB2;
      v28 = this->m_Coefficients.fB0;
      v29 = this->m_Coefficients.fB1;
      v30 = this->m_Coefficients.fA2;
      v31 = this->m_Coefficients.fA1;
      do
      {
        v32 = *v9;
        v33 = v29 * fFFwd1;
        ++v9;
        v34 = (float)(v32 * v28) + (float)(fFFwd2 * v27);
        fFFwd2 = fFFwd1;
        fFFwd1 = v32;
        v35 = (float)(v34 + v33) + (float)(fFFbk2 * v30);
        fFFbk2 = fFFbk1;
        v36 = v35 + (float)(v31 * fFFbk1);
        *(v9 - 1) = v36;
        fFFbk1 = v36;
      }
      while ( v9 < v8 );
    }
  }
  m_pMemories[v7].fFFwd1 = fFFwd1;
  m_pMemories[v7].fFFwd2 = fFFwd2;
  m_pMemories[v7].fFFbk1 = fFFbk1;
  m_pMemories[v7].fFFbk2 = fFFbk2;
}

