// File Line: 38
// RVA: 0xAE9670
void __fastcall DSP::ConstantPowerChannelMixdown(AkAudioBuffer *in_pAudioBufferIn, unsigned int in_uNumFrames, unsigned int in_uFrameOffset, float *out_pfBufferOut, unsigned int in_uChannelMask, float in_fInCenterGain, float in_fInLFEGain)
{
  __m128 v7; // xmm1
  float *v8; // rsi
  __int64 v9; // rbp
  unsigned int v10; // edi
  AkAudioBuffer *v11; // r14
  float v12; // xmm8_4
  float v13; // xmm6_4
  unsigned int v14; // ebx
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm7_4
  unsigned int v19; // er11
  signed int v20; // er8
  float v21; // xmm0_4
  unsigned int v22; // er9
  float *v23; // rdx
  unsigned __int64 v24; // r10
  __m128 v25; // xmm0

  v7 = (__m128)(unsigned int)FLOAT_1_0;
  v8 = out_pfBufferOut;
  v9 = in_uFrameOffset;
  v10 = in_uNumFrames;
  v11 = in_pAudioBufferIn;
  v12 = in_fInLFEGain;
  if ( in_fInLFEGain > 1.0 )
    v12 = *(float *)&FLOAT_1_0;
  v13 = in_fInCenterGain;
  if ( in_fInCenterGain > v7.m128_f32[0] )
    v13 = *(float *)&FLOAT_1_0;
  v14 = in_uChannelMask;
  v15 = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  if ( in_uChannelMask & 1 )
    v15 = *(float *)&FLOAT_1_0;
  if ( in_uChannelMask & 2 )
    v15 = v15 + v7.m128_f32[0];
  if ( _bittest((const signed int *)&v14, 9u) )
    v15 = v15 + v7.m128_f32[0];
  if ( _bittest((const signed int *)&v14, 0xAu) )
    v15 = v15 + v7.m128_f32[0];
  if ( in_uChannelMask & 0x10 )
    v15 = v15 + v7.m128_f32[0];
  if ( in_uChannelMask & 0x20 )
    v15 = v15 + v7.m128_f32[0];
  if ( in_uChannelMask & 4 )
    v16 = v13 * v13;
  if ( in_uChannelMask & 8 )
    v17 = v12 * v12;
  v7.m128_f32[0] = 1.0 / (float)((float)(v16 + v15) + v17);
  LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v7);
  memset(out_pfBufferOut, 0, 4i64 * in_uNumFrames);
  v19 = 0;
  v20 = 1;
  if ( in_uChannelMask )
  {
    do
    {
      if ( v20 & v14 || v14 == 8 )
      {
        v21 = v18;
        if ( v20 & 4 )
          v21 = v18 * v13;
        if ( v14 == 8 )
        {
          v14 = 0;
          v21 = v21 * v12;
LABEL_29:
          v7.m128_f32[0] = v21;
          v22 = v10;
          v23 = v8;
          v7 = _mm_shuffle_ps(v7, v7, 0);
          if ( v10 )
          {
            v24 = (unsigned __int64)v11->pData + 4 * (v9 + v19 * (unsigned __int64)v11->uMaxFrames) - (_QWORD)v8;
            do
            {
              v25 = *(__m128 *)((char *)v23 + v24);
              v23 += 4;
              *((__m128 *)v23 - 1) = _mm_add_ps(_mm_mul_ps(v25, v7), *(__m128 *)((char *)v23 - 16));
              v22 -= 4;
            }
            while ( v22 );
          }
          v14 &= ~v20;
          ++v19;
          goto LABEL_33;
        }
        if ( !(v20 & 8) )
          goto LABEL_29;
      }
LABEL_33:
      v20 *= 2;
    }
    while ( v14 );
  }
}

