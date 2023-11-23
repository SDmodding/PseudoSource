// File Line: 62
// RVA: 0xAEAE40
void __fastcall AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories(
        AK::DSP::MultiChannelBiquadFilter<8>::Memories *this)
{
  *(_QWORD *)&this->fFFwd1 = 0i64;
  *(_QWORD *)&this->fFFbk1 = 0i64;
}

// File Line: 89
// RVA: 0xAEAE50
void __fastcall AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(
        AK::DSP::MultiChannelBiquadFilter<8> *this,
        AK::DSP::MultiChannelBiquadFilter<8>::FilterType in_eFilterType,
        int in_uSampleRate,
        float in_fFreq,
        float in_fGain,
        float in_fQ)
{
  float v7; // xmm6_4
  float v8; // xmm13_4
  int v9; // xmm10_4
  float v10; // xmm0_4
  float v11; // xmm12_4
  float v12; // xmm14_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  float v15; // xmm15_4
  float v16; // xmm13_4
  float v17; // xmm9_4
  float v18; // xmm0_4
  int v19; // xmm4_4
  float v20; // xmm14_4
  float v21; // xmm13_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm13_4
  float v25; // xmm11_4
  __m128 v26; // xmm2
  float v27; // xmm7_4
  float v28; // xmm0_4
  float v29; // xmm4_4
  float v30; // xmm14_4
  float v31; // xmm8_4
  float v32; // xmm13_4
  float v33; // xmm9_4
  __m128 v34; // xmm2
  float v35; // xmm6_4
  float v36; // xmm8_4
  float v37; // xmm14_4
  float v38; // xmm1_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm13_4
  float v42; // xmm6_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm12_4
  float v50; // [rsp+D8h] [rbp+10h]

  v7 = (float)in_uSampleRate;
  v8 = in_fFreq;
  if ( in_fFreq >= (float)((float)((float)in_uSampleRate * 0.5) * 0.89999998) )
    v8 = (float)((float)in_uSampleRate * 0.5) * 0.89999998;
  v9 = _xmm[0];
  switch ( in_eFilterType )
  {
    case FilterType_LowShelf:
      v24 = (float)(v8 * 6.2831855) / v7;
      v25 = powf(10.0, in_fGain * 0.025);
      v11 = *(float *)&FLOAT_1_0;
      v26 = (__m128)(unsigned int)FLOAT_1_0;
      v27 = cosf(v24);
      v26.m128_f32[0] = (float)((float)((float)(1.0 / v25) + v25) * 0.0) + 2.0;
      v28 = sinf(v24);
      v29 = (float)(v25 + 1.0) - (float)((float)(v25 - 1.0) * v27);
      v30 = (float)((float)(v25 - 1.0) * v27) + (float)(v25 + 1.0);
      v9 = _xmm[0];
      v15 = (float)((float)((float)(v25 + 1.0) * v27) + (float)(v25 - 1.0)) * -2.0;
      v14 = (float)((float)(v25 - 1.0) - (float)((float)(v25 + 1.0) * v27)) * (float)(v25 * 2.0);
      v31 = (float)(_mm_sqrt_ps(v26).m128_f32[0] * (float)(v28 * 0.5)) * (float)(fsqrt(v25) * 2.0);
      v17 = v30 + v31;
      v13 = (float)(v29 + v31) * v25;
      *(float *)&v19 = (float)(v29 - v31) * v25;
      v20 = v30 - v31;
      break;
    case FilterType_Peaking:
      v41 = (float)(v8 * 6.2831855) / v7;
      v50 = cosf(v41);
      v42 = powf(10.0, in_fGain * 0.025);
      v11 = *(float *)&FLOAT_1_0;
      v14 = v50 * -2.0;
      v43 = sinf(v41) / (float)(in_fQ * 2.0);
      v44 = v43 / v42;
      v45 = v43 * v42;
      v15 = v50 * -2.0;
      *(float *)&v19 = 1.0 - v45;
      v13 = v45 + 1.0;
      v20 = 1.0 - v44;
      v17 = v44 + 1.0;
      break;
    case FilterType_HighShelf:
      v32 = (float)(v8 * 6.2831855) / v7;
      v33 = powf(10.0, in_fGain * 0.025);
      v11 = *(float *)&FLOAT_1_0;
      v34 = (__m128)(unsigned int)FLOAT_1_0;
      v35 = cosf(v32);
      v34.m128_f32[0] = (float)((float)((float)(1.0 / v33) + v33) * 0.0) + 2.0;
      v36 = (float)(_mm_sqrt_ps(v34).m128_f32[0] * (float)(sinf(v32) * 0.5)) * (float)(fsqrt(v33) * 2.0);
      v37 = (float)(v33 + 1.0) - (float)((float)(v33 - 1.0) * v35);
      v38 = (float)(v33 + 1.0) * v35;
      *(float *)&v19 = (float)((float)((float)((float)(v33 - 1.0) * v35) + (float)(v33 + 1.0)) - v36) * v33;
      v39 = v38 + (float)(v33 - 1.0);
      v40 = v33;
      v15 = (float)((float)(v33 - 1.0) - v38) * 2.0;
      v13 = (float)((float)((float)((float)(v33 - 1.0) * v35) + (float)(v33 + 1.0)) + v36) * v33;
      v17 = v37 + v36;
      v20 = v37 - v36;
      v14 = v39 * (float)(v40 * -2.0);
      break;
    case FilterType_HighPass:
      v10 = tanf((float)(v8 * 3.1415927) / v7);
      v11 = *(float *)&FLOAT_1_0;
      v12 = (float)((float)(v10 * v10) + 1.0) - (float)(v10 * 1.4142135);
      v13 = 1.0 / (float)((float)((float)(v10 * v10) + 1.0) + (float)(v10 * 1.4142135));
      v14 = v13 * -2.0;
      LODWORD(v15) = COERCE_UNSIGNED_INT((float)((float)(v10 * v10) - 1.0) * (float)(v13 * -2.0)) ^ _xmm[0];
      goto LABEL_11;
    case FilterType_BandPass:
      v16 = (float)(v8 * 6.2831855) / v7;
      v11 = *(float *)&FLOAT_1_0;
      v13 = sinf(v16) / (float)(in_fQ * 2.0);
      v17 = v13 + 1.0;
      v18 = cosf(v16);
      v19 = LODWORD(v13) ^ _xmm[0];
      v14 = 0.0;
      v20 = 1.0 - v13;
      v15 = v18 * -2.0;
      break;
    case FilterType_Notch:
      v21 = (float)(v8 * 6.2831855) / v7;
      v11 = *(float *)&FLOAT_1_0;
      v13 = *(float *)&FLOAT_1_0;
      v22 = sinf(v21) / (float)(in_fQ * 2.0);
      v23 = cosf(v21);
      v19 = (int)FLOAT_1_0;
      v17 = v22 + 1.0;
      v20 = 1.0 - v22;
      v14 = v23 * -2.0;
      v15 = v23 * -2.0;
      break;
    default:
      v46 = tanf((float)(v8 * 3.1415927) / v7);
      v11 = *(float *)&FLOAT_1_0;
      v47 = (float)(1.0 / v46) * (float)(1.0 / v46);
      v48 = (float)(1.0 / v46) * 1.4142135;
      v12 = (float)(v47 + 1.0) - v48;
      v13 = 1.0 / (float)((float)(v47 + 1.0) + v48);
      v14 = v13 * 2.0;
      v15 = (float)(1.0 - v47) * (float)(v13 * 2.0);
LABEL_11:
      v20 = v12 * v13;
      v17 = v11;
      *(float *)&v19 = v13;
      break;
  }
  v49 = v11 / v17;
  this->m_Coefficients.fB1 = v49 * v14;
  this->m_Coefficients.fB0 = v49 * v13;
  LODWORD(this->m_Coefficients.fA2) = COERCE_UNSIGNED_INT(v49 * v20) ^ v9;
  this->m_Coefficients.fB2 = v49 * *(float *)&v19;
  LODWORD(this->m_Coefficients.fA1) = COERCE_UNSIGNED_INT(v49 * v15) ^ v9;
}

// File Line: 256
// RVA: 0xAEC200
void __fastcall AK::DSP::MultiChannelBiquadFilter<8>::ProcessChannel(
        AK::DSP::MultiChannelBiquadFilter<8> *this,
        float *io_pfBuffer,
        unsigned int in_uNumframes,
        unsigned int in_uChannelIndex)
{
  float *v4; // r10
  float *v5; // r11
  float fFFwd1; // xmm8_4
  float fFFwd2; // xmm7_4
  float fFFbk1; // xmm6_4
  float fFFbk2; // xmm5_4
  float fB2; // xmm9_4
  float fB0; // xmm10_4
  float fB1; // xmm11_4
  float fA1; // xmm13_4
  float fA2; // xmm12_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm9_4
  float v25; // xmm10_4
  float v26; // xmm11_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm2_4

  v4 = io_pfBuffer;
  v5 = &io_pfBuffer[in_uNumframes];
  fFFwd1 = this->m_Memories[in_uChannelIndex].fFFwd1;
  fFFwd2 = this->m_Memories[in_uChannelIndex].fFFwd2;
  fFFbk1 = this->m_Memories[in_uChannelIndex].fFFbk1;
  fFFbk2 = this->m_Memories[in_uChannelIndex].fFFbk2;
  if ( io_pfBuffer < v5 )
  {
    if ( (4i64 * in_uNumframes + 3) / 4 >= 4 )
    {
      fB2 = this->m_Coefficients.fB2;
      fB0 = this->m_Coefficients.fB0;
      fB1 = this->m_Coefficients.fB1;
      fA1 = this->m_Coefficients.fA1;
      fA2 = this->m_Coefficients.fA2;
      do
      {
        v15 = *v4;
        v16 = v4[1];
        v17 = fB1 * fFFwd1;
        v4 += 4;
        v18 = (float)(fB0 * v15) + (float)(fFFwd2 * fB2);
        fFFwd2 = *(v4 - 2);
        v19 = (float)(fB0 * v16) + (float)(fFFwd1 * fB2);
        fFFwd1 = *(v4 - 1);
        v20 = (float)((float)(v18 + v17) + (float)(fFFbk2 * fA2)) + (float)(fA1 * fFFbk1);
        *(v4 - 4) = v20;
        v21 = (float)((float)(v19 + (float)(fB1 * v15)) + (float)(fFFbk1 * fA2)) + (float)(fA1 * v20);
        *(v4 - 3) = v21;
        fFFbk2 = (float)((float)((float)((float)(fB0 * fFFwd2) + (float)(v15 * fB2)) + (float)(fB1 * v16))
                       + (float)(v20 * fA2))
               + (float)(fA1 * v21);
        *(v4 - 2) = fFFbk2;
        fFFbk1 = (float)((float)((float)((float)(fB0 * fFFwd1) + (float)(v16 * fB2)) + (float)(fB1 * fFFwd2))
                       + (float)(v21 * fA2))
               + (float)(fA1 * fFFbk2);
        *(v4 - 1) = fFFbk1;
      }
      while ( (__int64)v4 < (__int64)(v5 - 3) );
    }
    if ( v4 < v5 )
    {
      v22 = this->m_Coefficients.fB2;
      v23 = this->m_Coefficients.fB0;
      v24 = this->m_Coefficients.fB1;
      v25 = this->m_Coefficients.fA2;
      v26 = this->m_Coefficients.fA1;
      do
      {
        v27 = *v4++;
        v28 = (float)(v23 * v27) + (float)(fFFwd2 * v22);
        fFFwd2 = fFFwd1;
        v29 = v24 * fFFwd1;
        fFFwd1 = v27;
        v30 = (float)(v28 + v29) + (float)(fFFbk2 * v25);
        fFFbk2 = fFFbk1;
        v31 = v30 + (float)(v26 * fFFbk1);
        *(v4 - 1) = v31;
        fFFbk1 = v31;
      }
      while ( v4 < v5 );
    }
  }
  this->m_Memories[in_uChannelIndex].fFFwd1 = fFFwd1;
  this->m_Memories[in_uChannelIndex].fFFwd2 = fFFwd2;
  this->m_Memories[in_uChannelIndex].fFFbk1 = fFFbk1;
  this->m_Memories[in_uChannelIndex].fFFbk2 = fFFbk2;
}

