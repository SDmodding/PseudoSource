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
float __fastcall CAkGustManager::ComputeInstantVelocity(CAkGustManager *this, const float in_fAverageVelocity, const float in_fVariability, const float in_fGustiness, const float in_fBufferTime)
{
  CAkGustManager *v5; // rbx
  float v6; // xmm7_4
  float v7; // xmm10_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  bool v10; // cf
  int v11; // ecx
  int v12; // eax
  float v13; // xmm3_4
  int v14; // eax
  float v15; // xmm0_4
  int v16; // eax
  float v17; // xmm6_4
  __m128 v18; // xmm0
  float v19; // xmm6_4
  float v20; // xmm6_4
  __m128 v21; // xmm1
  signed int v22; // ecx
  float v23; // xmm1_4

  v5 = this;
  v6 = 13.5 - (float)(in_fGustiness * 9.0);
  v7 = in_fAverageVelocity;
  v8 = powf(2.0, this->m_fExponentReference - v6) * this->m_fGustIncrement;
  v5->m_fGustIncrement = v8;
  v9 = v8 + v5->m_fGustCurrent;
  if ( v8 != 0.0 )
  {
    v10 = v8 < 0.0;
    if ( v8 <= 0.0 )
    {
LABEL_5:
      if ( !v10 || v9 > v5->m_fGustTarget )
        goto LABEL_11;
      goto LABEL_7;
    }
    if ( v9 < v5->m_fGustTarget )
    {
      v10 = v8 < 0.0;
      goto LABEL_5;
    }
  }
LABEL_7:
  v11 = 214013 * v5->m_TrianglePDFRand.m_uLCGState + 2531011;
  v12 = 214013 * v11 + 2531011;
  v5->m_TrianglePDFRand.m_uLCGState = v12;
  v13 = (float)v12;
  v5->m_fExponentReference = v6;
  v14 = 214013 * v5->m_TrianglePDFRand.m_uLCGState + 2531011;
  v15 = (float)v14;
  v16 = 214013 * v14 + 2531011;
  v5->m_TrianglePDFRand.m_uLCGState = v16;
  v17 = (float)((float)v16 * 2.3283064e-10) + (float)(v15 * 2.3283064e-10);
  v18 = (__m128)LODWORD(FLOAT_2_0);
  v19 = (float)((float)(v17 * 0.5) * 2.0) - 1.0;
  v5->m_fGustTarget = v19;
  v20 = v19 - v5->m_fGustCurrent;
  v18.m128_f32[0] = powf(
                      2.0,
                      (float)((float)((float)((float)(v13 * 2.3283064e-10) + (float)((float)v11 * 2.3283064e-10)) * 0.5)
                            + v6)
                    - 0.5);
  v21 = v18;
  v21.m128_f32[0] = (float)(v18.m128_f32[0] * 0.001) / in_fBufferTime;
  v22 = (signed int)v21.m128_f32[0];
  if ( (signed int)v21.m128_f32[0] != 0x80000000 && (float)v22 != v21.m128_f32[0] )
    v21.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v21, v21)) & 1 ^ 1) + v22);
  v5->m_fGustIncrement = v20 / v21.m128_f32[0];
LABEL_11:
  v23 = v5->m_fGustCurrent + v5->m_fGustIncrement;
  v5->m_fGustCurrent = v23;
  return powf(2.0, v23 * in_fVariability) * v7;
}

