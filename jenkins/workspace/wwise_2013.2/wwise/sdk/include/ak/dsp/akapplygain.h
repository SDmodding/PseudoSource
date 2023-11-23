// File Line: 32
// RVA: 0xB04880
// local variable allocation has failed, the output may be wrong!
void __fastcall AK::DSP::ApplyGainRamp_5(
        __m128 *io_pfBuffer,
        float in_fCurGain,
        double in_fTargetGain,
        unsigned int in_uNumFrames)
{
  float v4; // xmm3_4
  float *v5; // r8
  __m128 v6; // xmm4
  __m128 v7; // xmm2
  float *m128_f32; // rdx
  __m128 v9; // xmm5
  __m128 v10; // xmm5
  __m128 i; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm0
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  __m128 v18; // [rsp+0h] [rbp-18h]

  v4 = in_fCurGain;
  v6 = *(__m128 *)&in_fTargetGain;
  v5 = &io_pfBuffer->m128_f32[in_uNumFrames];
  v18.m128_f32[0] = in_fCurGain;
  v6.m128_f32[0] = *(float *)&in_fTargetGain - in_fCurGain;
  v7 = v6;
  m128_f32 = io_pfBuffer[in_uNumFrames >> 2].m128_f32;
  v7.m128_f32[0] = v6.m128_f32[0] / (float)(int)(4 * (in_uNumFrames >> 2));
  v9 = v7;
  v9.m128_f32[0] = v7.m128_f32[0] * 4.0;
  v18.m128_f32[1] = v7.m128_f32[0] + in_fCurGain;
  v10 = _mm_shuffle_ps(v9, v9, 0);
  v18.m128_f32[2] = (float)(v7.m128_f32[0] + in_fCurGain) + v7.m128_f32[0];
  v18.m128_f32[3] = v18.m128_f32[2] + v7.m128_f32[0];
  for ( i = v18; io_pfBuffer < (__m128 *)m128_f32; io_pfBuffer[-1] = v13 )
  {
    v12 = *io_pfBuffer++;
    v13 = _mm_mul_ps(v12, i);
    i = _mm_add_ps(i, v10);
  }
  if ( io_pfBuffer < (__m128 *)v5 )
  {
    v14 = v6.m128_f32[0] / (float)(int)in_uNumFrames;
    if ( ((char *)v5 - (char *)io_pfBuffer + 3) / 4 >= 4 )
    {
      do
      {
        ++io_pfBuffer;
        io_pfBuffer[-1].m128_f32[0] = v4 * io_pfBuffer[-1].m128_f32[0];
        io_pfBuffer[-1].m128_f32[1] = (float)(v4 + v14) * io_pfBuffer[-1].m128_f32[1];
        v15 = (float)(v4 + v14) + v14;
        io_pfBuffer[-1].m128_f32[2] = v15 * io_pfBuffer[-1].m128_f32[2];
        v16 = v15 + v14;
        v4 = v16 + v14;
        io_pfBuffer[-1].m128_f32[3] = v16 * io_pfBuffer[-1].m128_f32[3];
      }
      while ( (__int64)io_pfBuffer < (__int64)(v5 - 3) );
    }
    for ( ; io_pfBuffer < (__m128 *)v5; io_pfBuffer[-1].m128_f32[3] = v17 * io_pfBuffer[-1].m128_f32[3] )
    {
      v17 = v4;
      io_pfBuffer = (__m128 *)((char *)io_pfBuffer + 4);
      v4 = v4 + v14;
    }
  }
}

// File Line: 160
// RVA: 0xB187D0
// local variable allocation has failed, the output may be wrong!
void __fastcall AK::DSP::ApplyGain_14(__m128 *io_pfBuffer, double in_fGain, unsigned int in_uNumFrames)
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
    v4 = &io_pfBuffer->m128_f32[in_uNumFrames & 0xFFFFFFFC];
    v5 = &io_pfBuffer->m128_f32[in_uNumFrames];
    for ( i = _mm_shuffle_ps(*(__m128 *)&in_fGain, *(__m128 *)&in_fGain, 0);
          io_pfBuffer < (__m128 *)v4;
          io_pfBuffer[-1] = _mm_mul_ps(v7, i) )
    {
      v7 = *io_pfBuffer++;
    }
    if ( io_pfBuffer < (__m128 *)v5 )
    {
      if ( ((char *)v5 - (char *)io_pfBuffer + 3) / 4 >= 4 )
      {
        do
        {
          ++io_pfBuffer;
          v8 = v3 * io_pfBuffer[-1].m128_f32[1];
          io_pfBuffer[-1].m128_f32[0] = v3 * io_pfBuffer[-1].m128_f32[0];
          io_pfBuffer[-1].m128_f32[1] = v8;
          v9 = v3 * io_pfBuffer[-1].m128_f32[3];
          io_pfBuffer[-1].m128_f32[2] = v3 * io_pfBuffer[-1].m128_f32[2];
          io_pfBuffer[-1].m128_f32[3] = v9;
        }
        while ( (__int64)io_pfBuffer < (__int64)(v5 - 3) );
      }
      for ( ; io_pfBuffer < (__m128 *)v5; io_pfBuffer[-1].m128_f32[3] = v3 * io_pfBuffer[-1].m128_f32[3] )
        io_pfBuffer = (__m128 *)((char *)io_pfBuffer + 4);
    }
  }
}

// File Line: 291
// RVA: 0xB04AA0
void __fastcall AK::DSP::ApplyGain_13(
        __m128 *io_pfBuffer,
        double in_fCurGain,
        double in_fTargetGain,
        unsigned int in_uNumFrames)
{
  if ( *(float *)&in_fTargetGain == *(float *)&in_fCurGain )
    AK::DSP::ApplyGain_12(io_pfBuffer, in_fCurGain, in_uNumFrames);
  else
    AK::DSP::ApplyGainRamp_5(io_pfBuffer, *(float *)&in_fCurGain, in_fTargetGain, in_uNumFrames);
}

// File Line: 319
// RVA: 0xAF6940
void __fastcall AK::DSP::ApplyGain_9(
        AkAudioBuffer *io_pBuffer,
        double in_fCurGain,
        double in_fTargetGain,
        bool in_bProcessLFE)
{
  __int64 v4; // r10
  AkAudioBuffer *v5; // r11
  unsigned int uChannelMask; // ecx
  unsigned int v7; // r8d
  unsigned int i; // edx
  unsigned int uValidFrames; // edi
  __int64 v10; // rbx
  __int64 v11; // r10
  __int64 v12; // rbx
  __int64 v13; // r10

  v4 = 0i64;
  v5 = io_pBuffer;
  uChannelMask = io_pBuffer->uChannelMask;
  v7 = uChannelMask;
  for ( i = 0; v7; v7 &= v7 - 1 )
    ++i;
  if ( !in_bProcessLFE && (uChannelMask & 8) != 0 )
    --i;
  uValidFrames = v5->uValidFrames;
  if ( *(float *)&in_fTargetGain == *(float *)&in_fCurGain )
  {
    if ( i )
    {
      v10 = i;
      do
      {
        AK::DSP::ApplyGain_8((__m128 *)((char *)v5->pData + 4 * v4 * v5->uMaxFrames), in_fCurGain, uValidFrames);
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
      AK::DSP::ApplyGainRamp_3(
        (__m128 *)((char *)v5->pData + 4 * v4 * v5->uMaxFrames),
        *(float *)&in_fCurGain,
        in_fTargetGain,
        uValidFrames);
      v4 = v13 + 1;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 349
// RVA: 0xAF6A20
void __fastcall AK::DSP::ApplyGainLFE(AkAudioBuffer *io_pBuffer, double in_fCurGain, double in_fTargetGain)
{
  unsigned int uChannelMask; // edx
  int i; // r9d
  unsigned int uValidFrames; // edx
  __m128 *v6; // rcx

  uChannelMask = io_pBuffer->uChannelMask;
  if ( (uChannelMask & 8) != 0 )
  {
    for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
      ++i;
    uValidFrames = io_pBuffer->uValidFrames;
    v6 = (__m128 *)((char *)io_pBuffer->pData + 4 * io_pBuffer->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1));
    if ( *(float *)&in_fTargetGain == *(float *)&in_fCurGain )
      AK::DSP::ApplyGain_8(v6, in_fCurGain, uValidFrames);
    else
      AK::DSP::ApplyGainRamp_3(v6, *(float *)&in_fCurGain, in_fTargetGain, uValidFrames);
  }
}

