// File Line: 25
// RVA: 0xADE6E0
void __fastcall DSP::OnePoleFilter::ProcessBuffer(DSP::OnePoleFilter *this, float *io_pfBuffer, unsigned int in_uNumFrames)
{
  float *v3; // r9
  float *v4; // r8
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4

  v3 = io_pfBuffer;
  v4 = &io_pfBuffer[in_uNumFrames];
  if ( io_pfBuffer < v4 )
  {
    if ( ((char *)v4 - (char *)io_pfBuffer + 3) / 4 >= 4 )
    {
      v5 = this->fB0;
      v6 = this->fA1;
      do
      {
        v3 += 4;
        v7 = v5 * *(v3 - 3);
        v8 = (float)(v5 * *(v3 - 4)) - (float)(v6 * this->fFFbk1);
        *(v3 - 4) = v8;
        v9 = v5 * *(v3 - 2);
        v10 = v7 - (float)(v6 * v8);
        *(v3 - 3) = v10;
        v11 = v5 * *(v3 - 1);
        v12 = v9 - (float)(v6 * v10);
        *(v3 - 2) = v12;
        v13 = v11 - (float)(v6 * v12);
        *(v3 - 1) = v13;
        this->fFFbk1 = v13;
      }
      while ( (signed __int64)v3 < (signed __int64)(v4 - 3) );
    }
    if ( v3 < v4 )
    {
      v14 = this->fB0;
      v15 = this->fA1;
      do
      {
        ++v3;
        v16 = (float)(v14 * *(v3 - 1)) - (float)(v15 * this->fFFbk1);
        *(v3 - 1) = v16;
        this->fFFbk1 = v16;
      }
      while ( v3 < v4 );
    }
  }
}

// File Line: 39
// RVA: 0xADE6B0
void __fastcall DSP::OnePoleFilter::SetCoefs(DSP::OnePoleFilter *this, DSP::OnePoleFilter::FilterType eType, float in_fFc, unsigned int in_uSr)
{
  DSP::OnePoleFilter::ComputeCoefs(eType, in_fFc, in_uSr, &this->fB0, &this->fA1);
}

// File Line: 44
// RVA: 0xADE5C0
void __fastcall DSP::OnePoleFilter::ComputeCoefs(DSP::OnePoleFilter::FilterType eType, float in_fFc, unsigned int in_uSr, float *out_fB0, float *out_fA1)
{
  float *v5; // rbx
  __int32 v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  float v12; // xmm0_4

  v5 = out_fB0;
  if ( eType )
  {
    v6 = eType - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        v7 = cosf((float)(in_fFc / (float)(signed int)in_uSr) * 6.2831855);
        v8 = (float)(v7 + 2.0) - fsqrt((float)((float)(v7 + 2.0) * (float)(v7 + 2.0)) - 1.0);
        *out_fA1 = v8;
        *v5 = 1.0 - v8;
      }
    }
    else
    {
      v9 = cosf((float)(in_fFc / (float)(signed int)in_uSr) * 6.2831855);
      v10 = (__m128)LODWORD(FLOAT_2_0);
      v10.m128_f32[0] = 2.0 - v9;
      v11 = v10;
      v11.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0]) - 1.0;
      v12 = COERCE_FLOAT(_mm_sqrt_ps(v11)) - (float)(2.0 - v9);
      *out_fA1 = v12;
      *v5 = v12 + 1.0;
    }
  }
  else
  {
    *out_fA1 = 0.0;
    *out_fB0 = 1.0;
  }
}

