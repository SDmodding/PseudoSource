// File Line: 26
// RVA: 0xB04B20
void __fastcall McDSP::CAkWhiteNoise::CAkWhiteNoise(McDSP::CAkWhiteNoise *this)
{
  this->m_uLCGState = 784329;
}

// File Line: 33
// RVA: 0xB04B30
void __fastcall McDSP::CAkWhiteNoise::GenerateBuffer(McDSP::CAkWhiteNoise *this, float *out_pfBuffer, unsigned int in_uNumFrames)
{
  float *v3; // r9
  float *v4; // r8
  float v5; // xmm1_4
  unsigned int v6; // eax
  __m128i v7; // xmm0
  unsigned int v8; // eax
  __m128i v9; // xmm0
  unsigned int v10; // eax
  __m128i v11; // xmm0
  signed int v12; // eax
  signed int v13; // eax

  v3 = out_pfBuffer;
  v4 = &out_pfBuffer[in_uNumFrames];
  if ( out_pfBuffer < v4 )
  {
    v5 = AKNOISE_LCG_ONEOVERMAXRANDVAL_8;
    if ( ((char *)v4 - (char *)out_pfBuffer + 3) / 4 >= 4 )
    {
      do
      {
        v3 += 4;
        v6 = 214013 * this->m_uLCGState + 2531011;
        v7 = _mm_cvtsi32_si128(v6);
        v8 = 214013 * v6 + 2531011;
        *(v3 - 4) = COERCE_FLOAT(_mm_cvtepi32_ps(v7)) * v5;
        v9 = _mm_cvtsi32_si128(v8);
        v10 = 214013 * v8 + 2531011;
        *(v3 - 3) = COERCE_FLOAT(_mm_cvtepi32_ps(v9)) * v5;
        v11 = _mm_cvtsi32_si128(v10);
        v12 = 214013 * v10 + 2531011;
        this->m_uLCGState = v12;
        *(v3 - 2) = COERCE_FLOAT(_mm_cvtepi32_ps(v11)) * v5;
        *(v3 - 1) = (float)v12 * v5;
      }
      while ( (signed __int64)v3 < (signed __int64)(v4 - 3) );
    }
    for ( ; v3 < v4; *(v3 - 1) = (float)v13 * v5 )
    {
      ++v3;
      v13 = 214013 * this->m_uLCGState + 2531011;
      this->m_uLCGState = v13;
    }
  }
}

