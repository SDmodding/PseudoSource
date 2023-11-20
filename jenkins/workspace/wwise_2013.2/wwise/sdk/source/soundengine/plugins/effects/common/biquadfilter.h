// File Line: 208
// RVA: 0xA910F0
void __fastcall DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(DSP::BiquadFilter<DSP::SingleChannelPolicy> *this, float in_fB0, float in_fB1, float in_fB2, float in_fA1, float in_fA2)
{
  __m128 v6; // xmm0
  unsigned __int64 v7; // ST08_8
  unsigned __int64 v8; // ST00_8
  float v9; // xmm7_4
  int v10; // xmm9_4
  int v11; // xmm8_4
  float v12; // xmm3_4
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rax
  float v15; // xmm1_4

  v6 = (__m128)(unsigned int)_xmm[0];
  this->m_Coefficients.fB1 = in_fB1;
  LODWORD(v7) = 0;
  this->m_Coefficients.fB0 = in_fB0;
  this->m_Coefficients.vSecond.m128_u64[0] = 0i64;
  LODWORD(v8) = 0;
  v9 = in_fB2;
  this->m_Coefficients.fB2 = in_fB2;
  v10 = LODWORD(in_fA1) ^ _xmm[0];
  v11 = LODWORD(in_fA2) ^ _xmm[0];
  v6.m128_f32[0] = in_fB0;
  LODWORD(this->m_Coefficients.fA1) = LODWORD(in_fA1) ^ _xmm[0];
  LODWORD(this->m_Coefficients.fA2) = LODWORD(in_fA2) ^ _xmm[0];
  v12 = in_fB1 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]);
  this->m_Coefficients.vFirst = _mm_shuffle_ps(v6, v6, 0);
  *((float *)&v7 + 1) = (float)(in_fB0 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + in_fB1;
  v13 = v7;
  *(float *)&v7 = (float)(in_fB0 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + in_fB1;
  this->m_Coefficients.vSecond.m128_u64[1] = v13;
  *((float *)&v8 + 1) = (float)(in_fB0 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + in_fB1;
  this->m_Coefficients.vThird.m128_u64[0] = 0i64;
  *((float *)&v7 + 1) = (float)((float)(*((float *)&v7 + 1) * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + v9)
                      + (float)(in_fB0 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]));
  this->m_Coefficients.vThird.m128_u64[1] = v7;
  v14 = v8;
  LODWORD(v7) = HIDWORD(v7);
  *(float *)&v8 = in_fB1;
  this->m_Coefficients.vFourth.m128_u64[0] = v14;
  *((float *)&v7 + 1) = (float)((float)((float)(*(float *)&v10 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])) * in_fB0)
                              + (float)(*((float *)&v7 + 1) * *(float *)&v10))
                      + v12;
  this->m_Coefficients.vFourth.m128_u64[1] = v7;
  *((float *)&v8 + 1) = (float)(in_fB1 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + v9;
  this->m_Coefficients.vXPrev1.m128_u64[0] = v8;
  *(float *)&v8 = v9;
  *(float *)&v7 = (float)(*((float *)&v8 + 1) * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + v12;
  *((float *)&v7 + 1) = (float)((float)(*(float *)&v7 * *(float *)&v10)
                              + (float)(v9 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])))
                      + (float)(v12 * *(float *)&v10);
  this->m_Coefficients.vXPrev1.m128_u64[1] = v7;
  *((float *)&v8 + 1) = v9 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]);
  this->m_Coefficients.vXPrev2.m128_u64[0] = v8;
  LODWORD(v8) = LODWORD(in_fA1) ^ _xmm[0];
  v15 = (float)(v9 * *(float *)&v10) * *(float *)&v10;
  *(float *)&v7 = v15 + (float)(v9 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]));
  *((float *)&v7 + 1) = (float)((float)((float)(v9 * 2.0) * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])) + v15)
                      * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]);
  this->m_Coefficients.vXPrev2.m128_u64[1] = v7;
  *((float *)&v8 + 1) = (float)(*(float *)&v10 * *(float *)&v10) + COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]);
  this->m_Coefficients.vYPrev1.m128_u64[0] = v8;
  *((float *)&v8 + 1) = COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]);
  LODWORD(v8) = LODWORD(in_fA2) ^ _xmm[0];
  *(float *)&v7 = (float)((float)(COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]) * 2.0)
                        + (float)(*(float *)&v10 * *(float *)&v10))
                * *(float *)&v10;
  *((float *)&v7 + 1) = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]) * 3.0)
                                              + (float)(*(float *)&v10 * *(float *)&v10))
                                      * *(float *)&v10)
                              * *(float *)&v10)
                      + (float)(*(float *)&v11 * *(float *)&v11);
  this->m_Coefficients.vYPrev1.m128_u64[1] = v7;
  this->m_Coefficients.vYPrev2.m128_u64[0] = v8;
  this->m_Coefficients.vYPrev2.m128_u64[1] = __PAIR__(
                                               (float)((float)((float)(*(float *)&v11 * 2.0) * *(float *)&v11)
                                                     + (float)((float)(*(float *)&v10
                                                                     * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]))
                                                             * *(float *)&v10))
                                             * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]),
                                               (float)((float)((float)(*(float *)&v10
                                                                     * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]))
                                                             * *(float *)&v10)
                                                     + (float)(*(float *)&v11 * *(float *)&v11)));
}

