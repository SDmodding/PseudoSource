// File Line: 62
// RVA: 0xAEAE40
void __fastcall AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories(AK::DSP::MultiChannelBiquadFilter<8>::Memories *this)
{
  *(_QWORD *)&this->fFFwd1 = 0i64;
  *(_QWORD *)&this->fFFbk1 = 0i64;
}

// File Line: 89
// RVA: 0xAEAE50
void __fastcall AK::DSP::MultiChannelBiquadFilter<8>::ComputeCoefs(AK::DSP::MultiChannelBiquadFilter<8> *this, AK::DSP::MultiChannelBiquadFilter<8>::FilterType in_eFilterType, unsigned int in_uSampleRate, float in_fFreq, float in_fGain, float in_fQ)
{
  AK::DSP::MultiChannelBiquadFilter<8> *v6; // rbx
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
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm12_4
  float v52; // [rsp+D8h] [rbp+10h]

  v6 = this;
  v7 = (float)(signed int)in_uSampleRate;
  v8 = in_fFreq;
  if ( in_fFreq >= (float)((float)((float)(signed int)in_uSampleRate * 0.5) * 0.89999998) )
    v8 = (float)((float)(signed int)in_uSampleRate * 0.5) * 0.89999998;
  v9 = _xmm[0];
  switch ( 0x40000000 )
  {
    case 0:
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
      v31 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v26)) * (float)(v28 * 0.5)) * (float)(fsqrt(v25) * 2.0);
      v17 = v30 + v31;
      v13 = (float)(v29 + v31) * v25;
      *(float *)&v19 = (float)(v29 - v31) * v25;
      v20 = v30 - v31;
      break;
    case 1:
      v41 = (float)(v8 * 6.2831855) / v7;
      v52 = cosf(v41);
      v42 = powf(10.0, in_fGain * 0.025);
      v11 = *(float *)&FLOAT_1_0;
      v43 = sinf(v41) / (float)(in_fQ * 2.0);
      v14 = v52 * -2.0;
      v44 = v43;
      v45 = v43 / v42;
      v46 = v44 * v42;
      v15 = v52 * -2.0;
      *(float *)&v19 = 1.0 - v46;
      v13 = v46 + 1.0;
      v20 = 1.0 - v45;
      v17 = v45 + 1.0;
      break;
    case 2:
      v32 = (float)(v8 * 6.2831855) / v7;
      v33 = powf(10.0, in_fGain * 0.025);
      v11 = *(float *)&FLOAT_1_0;
      v34 = (__m128)(unsigned int)FLOAT_1_0;
      v35 = cosf(v32);
      v34.m128_f32[0] = (float)((float)((float)(1.0 / v33) + v33) * 0.0) + 2.0;
      v36 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v34)) * (float)(sinf(v32) * 0.5)) * (float)(fsqrt(v33) * 2.0);
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
    case 4:
      v10 = tanf((float)(v8 * 3.1415927) / v7);
      v11 = *(float *)&FLOAT_1_0;
      v12 = (float)((float)(v10 * v10) + 1.0) - (float)(v10 * 1.4142135);
      v13 = 1.0 / (float)((float)((float)(v10 * v10) + 1.0) + (float)(v10 * 1.4142135));
      v14 = v13 * -2.0;
      LODWORD(v15) = COERCE_UNSIGNED_INT((float)((float)(v10 * v10) - 1.0) * (float)(v13 * -2.0)) ^ _xmm[0];
      goto LABEL_11;
    case 5:
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
    case 6:
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
      v11 = *(float *)&FLOAT_1_0;
      v47 = 1.0 / tanf((float)(v8 * 3.1415927) / v7);
      v48 = v47;
      v49 = v47 * v47;
      v50 = v48 * 1.4142135;
      v12 = (float)(v49 + 1.0) - v50;
      v13 = 1.0 / (float)((float)(v49 + 1.0) + v50);
      v14 = v13 * 2.0;
      v15 = (float)(1.0 - v49) * (float)(v13 * 2.0);
LABEL_11:
      v20 = v12 * v13;
      v17 = v11;
      *(float *)&v19 = v13;
      break;
  }
  v51 = v11 / v17;
  v6->m_Coefficients.fB1 = v51 * v14;
  v6->m_Coefficients.fB0 = v51 * v13;
  LODWORD(v6->m_Coefficients.fA2) = COERCE_UNSIGNED_INT(v51 * v20) ^ v9;
  v6->m_Coefficients.fB2 = v51 * *(float *)&v19;
  LODWORD(v6->m_Coefficients.fA1) = COERCE_UNSIGNED_INT(v51 * v15) ^ v9;
}

// File Line: 256
// RVA: 0xAEC200
void __fastcall AK::DSP::MultiChannelBiquadFilter<8>::ProcessChannel(AK::DSP::MultiChannelBiquadFilter<8> *this, float *io_pfBuffer, unsigned int in_uNumframes, unsigned int in_uChannelIndex)
{
  float *v4; // r10
  float *v5; // r11
  float v6; // xmm8_4
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm5_4
  float v10; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm11_4
  float v13; // xmm13_4
  float v14; // xmm12_4
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
  v6 = this->m_Memories[in_uChannelIndex].fFFwd1;
  v7 = this->m_Memories[in_uChannelIndex].fFFwd2;
  v8 = this->m_Memories[in_uChannelIndex].fFFbk1;
  v9 = this->m_Memories[in_uChannelIndex].fFFbk2;
  if ( io_pfBuffer < v5 )
  {
    if ( (4i64 * in_uNumframes + 3) / 4 >= 4 )
    {
      v10 = this->m_Coefficients.fB2;
      v11 = this->m_Coefficients.fB0;
      v12 = this->m_Coefficients.fB1;
      v13 = this->m_Coefficients.fA1;
      v14 = this->m_Coefficients.fA2;
      do
      {
        v15 = *v4;
        v16 = v4[1];
        v17 = v12 * v6;
        v4 += 4;
        v18 = (float)(v11 * v15) + (float)(v7 * v10);
        v7 = *(v4 - 2);
        v19 = (float)(v11 * v16) + (float)(v6 * v10);
        v6 = *(v4 - 1);
        v20 = (float)((float)(v18 + v17) + (float)(v9 * v14)) + (float)(v13 * v8);
        *(v4 - 4) = v20;
        v21 = (float)((float)(v19 + (float)(v12 * v15)) + (float)(v8 * v14)) + (float)(v13 * v20);
        *(v4 - 3) = v21;
        v9 = (float)((float)((float)((float)(v11 * v7) + (float)(v15 * v10)) + (float)(v12 * v16)) + (float)(v20 * v14))
           + (float)(v13 * v21);
        *(v4 - 2) = v9;
        v8 = (float)((float)((float)((float)(v11 * v6) + (float)(v16 * v10)) + (float)(v12 * v7)) + (float)(v21 * v14))
           + (float)(v13 * v9);
        *(v4 - 1) = v8;
      }
      while ( (signed __int64)v4 < (signed __int64)(v5 - 3) );
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
        v27 = *v4;
        ++v4;
        v28 = (float)(v23 * v27) + (float)(v7 * v22);
        v7 = v6;
        v29 = v24 * v6;
        v6 = v27;
        v30 = (float)(v28 + v29) + (float)(v9 * v25);
        v9 = v8;
        v31 = v30 + (float)(v26 * v8);
        *(v4 - 1) = v31;
        v8 = v31;
      }
      while ( v4 < v5 );
    }
  }
  this->m_Memories[in_uChannelIndex].fFFwd1 = v6;
  this->m_Memories[in_uChannelIndex].fFFwd2 = v7;
  this->m_Memories[in_uChannelIndex].fFFbk1 = v8;
  this->m_Memories[in_uChannelIndex].fFFbk2 = v9;
}

