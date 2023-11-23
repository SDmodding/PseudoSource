// File Line: 29
// RVA: 0xAD6090
void __fastcall CAkGustManager::CAkGustManager(CAkGustManager *this)
{
  *(_QWORD *)&this->m_fGustTarget = 0i64;
  *(_QWORD *)&this->m_fGustCurrent = 0i64;
  this->m_TrianglePDFRand.m_uLCGState = rand();
}

// File Line: 40
// RVA: 0xAD60C0
float __fastcall CAkGustManager::ComputeInstantVelocity(
        CAkGustManager *this,
        const float in_fAverageVelocity,
        const float in_fVariability,
        const float in_fGustiness,
        float in_fBufferTime)
{
  float v6; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  bool v10; // cf
  signed int v11; // eax
  float v12; // xmm4_4
  signed int v13; // eax
  float v14; // xmm3_4
  signed int v15; // eax
  float v16; // xmm0_4
  signed int v17; // eax
  float v18; // xmm6_4
  __m128 v19; // xmm0
  float v20; // xmm6_4
  float v21; // xmm6_4
  __m128 v22; // xmm1
  int v23; // ecx
  float v24; // xmm1_4

  v6 = 13.5 - (float)(in_fGustiness * 9.0);
  v8 = powf(2.0, this->m_fExponentReference - v6) * this->m_fGustIncrement;
  this->m_fGustIncrement = v8;
  v9 = v8 + this->m_fGustCurrent;
  if ( v8 != 0.0 )
  {
    v10 = v8 < 0.0;
    if ( v8 <= 0.0 )
    {
LABEL_5:
      if ( !v10 || v9 > this->m_fGustTarget )
        goto LABEL_11;
      goto LABEL_7;
    }
    if ( v9 < this->m_fGustTarget )
    {
      v10 = v8 < 0.0;
      goto LABEL_5;
    }
  }
LABEL_7:
  v11 = 214013 * this->m_TrianglePDFRand.m_uLCGState + 2531011;
  v12 = (float)v11;
  v13 = 214013 * v11 + 2531011;
  this->m_TrianglePDFRand.m_uLCGState = v13;
  v14 = (float)v13;
  this->m_fExponentReference = v6;
  v15 = 214013 * this->m_TrianglePDFRand.m_uLCGState + 2531011;
  v16 = (float)v15;
  v17 = 214013 * v15 + 2531011;
  this->m_TrianglePDFRand.m_uLCGState = v17;
  v18 = (float)((float)v17 * 2.3283064e-10) + (float)(v16 * 2.3283064e-10);
  v19 = (__m128)LODWORD(FLOAT_2_0);
  v20 = (float)((float)(v18 * 0.5) * 2.0) - 1.0;
  this->m_fGustTarget = v20;
  v21 = v20 - this->m_fGustCurrent;
  v19.m128_f32[0] = powf(
                      2.0,
                      (float)((float)((float)((float)(v14 * 2.3283064e-10) + (float)(v12 * 2.3283064e-10)) * 0.5) + v6)
                    - 0.5);
  v22 = v19;
  v22.m128_f32[0] = (float)(v19.m128_f32[0] * 0.001) / in_fBufferTime;
  v23 = (int)v22.m128_f32[0];
  if ( (int)v22.m128_f32[0] != 0x80000000 && (float)v23 != v22.m128_f32[0] )
    v22.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v22, v22)) & 1) + v23);
  this->m_fGustIncrement = v21 / v22.m128_f32[0];
LABEL_11:
  v24 = this->m_fGustCurrent + this->m_fGustIncrement;
  this->m_fGustCurrent = v24;
  return powf(2.0, v24 * in_fVariability) * in_fAverageVelocity;
}

