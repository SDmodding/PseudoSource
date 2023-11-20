// File Line: 32
// RVA: 0xB04880
int AK::DSP::ApplyGainRamp_5(...)
{
  float v4; // xmm3_4
  float *v5; // r8
  __m128 v6; // ST00_16
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  float *v9; // rdx
  __m128 v10; // xmm5
  __m128 v11; // xmm5
  __m128 i; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm0
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm0_4
  float v21; // xmm0_4

  v4 = in_fCurGain;
  v7 = (__m128)in_fTargetGain;
  v5 = &io_pfBuffer[in_uNumFrames];
  v6.m128_f32[0] = in_fCurGain;
  v7.m128_f32[0] = *(float *)&in_fTargetGain - in_fCurGain;
  v8 = v7;
  v9 = &io_pfBuffer[4 * (in_uNumFrames >> 2)];
  v8.m128_f32[0] = v7.m128_f32[0] / (float)(signed int)(4 * (in_uNumFrames >> 2));
  v10 = v8;
  v10.m128_f32[0] = v8.m128_f32[0] * 4.0;
  v6.m128_f32[1] = v8.m128_f32[0] + in_fCurGain;
  v11 = _mm_shuffle_ps(v10, v10, 0);
  v6.m128_f32[2] = (float)(v8.m128_f32[0] + in_fCurGain) + v8.m128_f32[0];
  v6.m128_f32[3] = v6.m128_f32[2] + v8.m128_f32[0];
  for ( i = v6; io_pfBuffer < v9; *((__m128 *)io_pfBuffer - 1) = v14 )
  {
    v13 = *(__m128 *)io_pfBuffer;
    io_pfBuffer += 4;
    v14 = _mm_mul_ps(v13, i);
    i = _mm_add_ps(i, v11);
  }
  if ( io_pfBuffer < v5 )
  {
    v15 = v7.m128_f32[0] / (float)(signed int)in_uNumFrames;
    if ( ((char *)v5 - (char *)io_pfBuffer + 3) / 4 >= 4 )
    {
      do
      {
        v16 = v4;
        v17 = v4 + v15;
        io_pfBuffer += 4;
        *(io_pfBuffer - 4) = v16 * *(io_pfBuffer - 4);
        v18 = v17;
        v19 = v17 + v15;
        *(io_pfBuffer - 3) = v18 * *(io_pfBuffer - 3);
        *(io_pfBuffer - 2) = v19 * *(io_pfBuffer - 2);
        v20 = v19 + v15;
        v4 = (float)(v19 + v15) + v15;
        *(io_pfBuffer - 1) = v20 * *(io_pfBuffer - 1);
      }
      while ( (signed __int64)io_pfBuffer < (signed __int64)(v5 - 3) );
    }
    for ( ; io_pfBuffer < v5; *(io_pfBuffer - 1) = v21 * *(io_pfBuffer - 1) )
    {
      v21 = v4;
      ++io_pfBuffer;
      v4 = v4 + v15;
    }
  }
}

// File Line: 160
// RVA: 0xB187D0
int AK::DSP::ApplyGain_14(...)
{
  float v3; // xmm2_4
  float *v4; // rdx
  float *v5; // r9
  __m128 i; // xmm1
  __m128 v7; // xmm0
  float v8; // xmm1_4
  float v9; // xmm1_4

  v3 = *(float *)&in_fGain;
  if ( *(float *)&in_fGain != 1.0 )
  {
    v4 = &io_pfBuffer[in_uNumFrames & 0xFFFFFFFC];
    v5 = &io_pfBuffer[in_uNumFrames];
    for ( i = _mm_shuffle_ps((__m128)in_fGain, (__m128)in_fGain, 0);
          io_pfBuffer < v4;
          *((__m128 *)io_pfBuffer - 1) = _mm_mul_ps(v7, i) )
    {
      v7 = *(__m128 *)io_pfBuffer;
      io_pfBuffer += 4;
    }
    if ( io_pfBuffer < v5 )
    {
      if ( ((char *)v5 - (char *)io_pfBuffer + 3) / 4 >= 4 )
      {
        do
        {
          io_pfBuffer += 4;
          v8 = v3 * *(io_pfBuffer - 3);
          *(io_pfBuffer - 4) = v3 * *(io_pfBuffer - 4);
          *(io_pfBuffer - 3) = v8;
          v9 = v3 * *(io_pfBuffer - 1);
          *(io_pfBuffer - 2) = v3 * *(io_pfBuffer - 2);
          *(io_pfBuffer - 1) = v9;
        }
        while ( (signed __int64)io_pfBuffer < (signed __int64)(v5 - 3) );
      }
      for ( ; io_pfBuffer < v5; *(io_pfBuffer - 1) = v3 * *(io_pfBuffer - 1) )
        ++io_pfBuffer;
    }
  }
}

// File Line: 291
// RVA: 0xB04AA0
void __fastcall AK::DSP::ApplyGain_13(float *io_pfBuffer, float in_fCurGain, float in_fTargetGain, unsigned int in_uNumFrames)
{
  if ( in_fTargetGain == in_fCurGain )
    AK::DSP::ApplyGain_12(io_pfBuffer, in_fCurGain, in_uNumFrames);
  else
    AK::DSP::ApplyGainRamp_5(io_pfBuffer, in_fCurGain, in_fTargetGain, in_uNumFrames);
}

// File Line: 319
// RVA: 0xAF6940
void __fastcall AK::DSP::ApplyGain_9(AkAudioBuffer *io_pBuffer, float in_fCurGain, float in_fTargetGain, bool in_bProcessLFE)
{
  signed __int64 v4; // r10
  AkAudioBuffer *v5; // r11
  unsigned int v6; // ecx
  unsigned int v7; // er8
  unsigned int i; // edx
  unsigned int v9; // edi
  __int64 v10; // rbx
  __int64 v11; // r10
  __int64 v12; // rbx
  __int64 v13; // r10

  v4 = 0i64;
  v5 = io_pBuffer;
  v6 = io_pBuffer->uChannelMask;
  v7 = v6;
  for ( i = 0; v7; v7 &= v7 - 1 )
    ++i;
  if ( !in_bProcessLFE && v6 & 8 )
    --i;
  v9 = v5->uValidFrames;
  if ( in_fTargetGain == in_fCurGain )
  {
    if ( i )
    {
      v10 = i;
      do
      {
        AK::DSP::ApplyGain_8((float *)v5->pData + v4 * v5->uMaxFrames, in_fCurGain, v9);
        v4 = v11 + 1;
        --v10;
      }
      while ( v10 );
    }
  }
  else if ( i )
  {
    v12 = i;
    do
    {
      AK::DSP::ApplyGainRamp_3((float *)v5->pData + v4 * v5->uMaxFrames, in_fCurGain, in_fTargetGain, v9);
      v4 = v13 + 1;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 349
// RVA: 0xAF6A20
void __fastcall AK::DSP::ApplyGainLFE(AkAudioBuffer *io_pBuffer, float in_fCurGain, float in_fTargetGain)
{
  unsigned int v3; // edx
  int i; // er9
  unsigned int v5; // edx
  float *v6; // rcx

  v3 = io_pBuffer->uChannelMask;
  if ( v3 & 8 )
  {
    for ( i = 0; v3; v3 &= v3 - 1 )
      ++i;
    v5 = io_pBuffer->uValidFrames;
    v6 = (float *)((char *)io_pBuffer->pData + 4 * io_pBuffer->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1));
    if ( in_fTargetGain == in_fCurGain )
      AK::DSP::ApplyGain_8(v6, in_fCurGain, v5);
    else
      AK::DSP::ApplyGainRamp_3(v6, in_fCurGain, in_fTargetGain, v5);
  }
}

