// File Line: 208
// RVA: 0xA910F0
void __fastcall DSP::BiquadFilter<DSP::SingleChannelPolicy>::SetCoefs(
        DSP::BiquadFilter<DSP::SingleChannelPolicy> *this,
        float in_fB0,
        float in_fB1,
        float in_fB2,
        float in_fA1,
        float in_fA2)
{
  __m128 v6; // xmm0
  int v8; // xmm9_4
  float v9; // xmm3_4
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  float v12; // xmm1_4
  unsigned __int64 v13; // [rsp+0h] [rbp-50h]
  unsigned __int64 v14; // [rsp+8h] [rbp-48h]

  v6 = (__m128)(unsigned int)_xmm[0];
  this->m_Coefficients.fB1 = in_fB1;
  LODWORD(v14) = 0;
  this->m_Coefficients.fB0 = in_fB0;
  this->m_Coefficients.vSecond.m128_u64[0] = 0i64;
  LODWORD(v13) = 0;
  this->m_Coefficients.fB2 = in_fB2;
  v8 = LODWORD(in_fA1) ^ _xmm[0];
  v6.m128_f32[0] = in_fB0;
  LODWORD(this->m_Coefficients.fA1) = LODWORD(in_fA1) ^ _xmm[0];
  LODWORD(this->m_Coefficients.fA2) = LODWORD(in_fA2) ^ _xmm[0];
  v9 = in_fB1 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]);
  this->m_Coefficients.vFirst = _mm_shuffle_ps(v6, v6, 0);
  *((float *)&v14 + 1) = (float)(in_fB0 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + in_fB1;
  v10 = v14;
  *(float *)&v14 = *((float *)&v14 + 1);
  this->m_Coefficients.vSecond.m128_u64[1] = v10;
  *((float *)&v13 + 1) = *((float *)&v14 + 1);
  this->m_Coefficients.vThird.m128_u64[0] = 0i64;
  *((float *)&v14 + 1) = (float)((float)(*((float *)&v14 + 1) * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + in_fB2)
                       + (float)(in_fB0 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]));
  this->m_Coefficients.vThird.m128_u64[1] = v14;
  v11 = v13;
  LODWORD(v14) = HIDWORD(v14);
  *(float *)&v13 = in_fB1;
  this->m_Coefficients.vFourth.m128_u64[0] = v11;
  *((float *)&v14 + 1) = (float)((float)((float)(*(float *)&v8 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])) * in_fB0)
                               + (float)(*((float *)&v14 + 1) * *(float *)&v8))
                       + v9;
  this->m_Coefficients.vFourth.m128_u64[1] = v14;
  *((float *)&v13 + 1) = (float)(in_fB1 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + in_fB2;
  this->m_Coefficients.vXPrev1.m128_u64[0] = v13;
  *(float *)&v13 = in_fB2;
  *(float *)&v14 = (float)(*((float *)&v13 + 1) * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])) + v9;
  *((float *)&v14 + 1) = (float)((float)(*(float *)&v14 * *(float *)&v8)
                               + (float)(in_fB2 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])))
                       + (float)(v9 * *(float *)&v8);
  this->m_Coefficients.vXPrev1.m128_u64[1] = v14;
  *((float *)&v13 + 1) = in_fB2 * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]);
  this->m_Coefficients.vXPrev2.m128_u64[0] = v13;
  LODWORD(v13) = LODWORD(in_fA1) ^ _xmm[0];
  v12 = (float)(in_fB2 * *(float *)&v8) * *(float *)&v8;
  *(float *)&v14 = v12 + (float)(in_fB2 * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]));
  *((float *)&v14 + 1) = (float)((float)((float)(in_fB2 * 2.0) * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])) + v12)
                       * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]);
  this->m_Coefficients.vXPrev2.m128_u64[1] = v14;
  *((float *)&v13 + 1) = (float)(*(float *)&v8 * *(float *)&v8) + COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]);
  this->m_Coefficients.vYPrev1.m128_u64[0] = v13;
  *((float *)&v13 + 1) = COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]);
  LODWORD(v13) = LODWORD(in_fA2) ^ _xmm[0];
  *(float *)&v14 = (float)((float)(COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]) * 2.0)
                         + (float)(*(float *)&v8 * *(float *)&v8))
                 * *(float *)&v8;
  *((float *)&v14 + 1) = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]) * 3.0)
                                               + (float)(*(float *)&v8 * *(float *)&v8))
                                       * *(float *)&v8)
                               * *(float *)&v8)
                       + (float)(COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]));
  this->m_Coefficients.vYPrev1.m128_u64[1] = v14;
  this->m_Coefficients.vYPrev2.m128_u64[0] = v13;
  this->m_Coefficients.vYPrev2.m128_u64[1] = __PAIR64__(
                                               (float)((float)((float)(COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]) * 2.0)
                                                             * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0]))
                                                     + (float)(*((float *)&v13 + 1)
                                                             * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0])))
                                             * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]),
                                               (float)(*((float *)&v13 + 1) * COERCE_FLOAT(LODWORD(in_fA1) ^ _xmm[0]))
                                             + (float)(COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])
                                                     * COERCE_FLOAT(LODWORD(in_fA2) ^ _xmm[0])));
}

